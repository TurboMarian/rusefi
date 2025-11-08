/*
 * @file antilag_system.cpp
 *
 *  @date 26. nov. 2022
 *      Author: Turbo Marian
 */

#include "pch.h"

#if EFI_ANTILAG_SYSTEM
#include "antilag_system.h"
#include "engine_state.h"
#include "fuel_math.h"

bool AntilagSystemBase::isInsideALSSwitchCondition() {
    isALSSwitchActivated = engineConfiguration->antiLagActivationMode == SWITCH_INPUT_ANTILAG;

    if (isALSSwitchActivated) {
        if (isBrainPinValid(engineConfiguration->ALSActivatePin)) {
#if EFI_PROD_CODE
            ALSActivatePinState = efiReadPin(engineConfiguration->ALSActivatePin, engineConfiguration->ALSActivatePinMode);
#else
            ALSActivatePinState = false;
#endif
        }
        return ALSActivatePinState;
    } else if (engineConfiguration->antiLagActivationMode == LUA_ANTILAG) {
        return luaAntilagState;
    } else if (engineConfiguration->antiLagActivationMode == ALWAYS_ON_ANTILAG) {
        return true;
    } else {
        criticalError("Unexpected antiLagActivationMode");
        return false;
    }
}

bool AntilagSystemBase::isALSMinRPMCondition(float rpm) const {
    return engineConfiguration->ALSMinRPM < rpm;
}

bool AntilagSystemBase::isALSMaxRPMCondition(float rpm) const {
    return (rpm > engineConfiguration->ALSMaxRPM - engineConfiguration->ALSHardCutDelay) &&
       (rpm < engineConfiguration->ALSMaxRPM + engineConfiguration->ALSHardCutDelay);

}

bool AntilagSystemBase::isALSMinCLTCondition() const {
    int clt = Sensor::getOrZero(SensorType::Clt);
    return engineConfiguration->ALSMinCLT < clt;
}

bool AntilagSystemBase::isALSMaxCLTCondition() const {
    int clt = Sensor::getOrZero(SensorType::Clt);
    return engineConfiguration->ALSMaxCLT > clt;
}

bool AntilagSystemBase::isALSMaxEGTCondition() const {
    int egt = Sensor::getOrZero(SensorType::EGT1);
    return engineConfiguration->ALSMaxEGT > egt;
}

bool AntilagSystemBase::isALSMaxThrottleIntentCondition() const {
    int throttleIntent = Sensor::getOrZero(SensorType::DriverThrottleIntent);
    return engineConfiguration->ALSMaxTPS > throttleIntent;
}

bool AntilagSystemBase::isInsideALSTimerCondition() {
    auto ALStime = ALStimer.getElapsedSeconds();
    return ALStime < engineConfiguration->ALSMaxDuration;
}

bool AntilagSystemBase::isAntilagConditionMet(float rpm) {
    ALSMinRPMCondition = isALSMinRPMCondition(rpm);
    ALSMaxRPMCondition = isALSMaxRPMCondition(rpm);
    ALSMinCLTCondition = isALSMinCLTCondition();
    ALSMaxCLTCondition = isALSMaxCLTCondition();
    ALSMaxEGTCondition = isALSMaxEGTCondition();
    ALSMaxThrottleIntentCondition = isALSMaxThrottleIntentCondition();
    ALSSwitchCondition = isInsideALSSwitchCondition();
    ALSTimerCondition = isInsideALSTimerCondition();

    return ALSMinRPMCondition &&
           ALSMaxRPMCondition &&
           ALSMinCLTCondition &&
           ALSMaxCLTCondition &&
           ALSMaxEGTCondition &&
           ALSMaxThrottleIntentCondition &&
           ALSSwitchCondition &&
           ALSTimerCondition;
}

void AntilagSystemBase::update() {
    float rpm = Sensor::getOrZero(SensorType::Rpm);
    isAntilagCondition = engineConfiguration->antiLagEnabled && isAntilagConditionMet(rpm);

    if (!ALSMaxRPMCondition) {
        ALStimer.reset();
    }

#if EFI_ANTILAG_SYSTEM
    fuelALSCorrection = getFuelALSCorrection(rpm);
#endif

}

bool AntilagSystemBase::isALSPreCutWindow(float rpm) const {
    const float maxRpm = (float)engineConfiguration->ALSMaxRPM;
    return (rpm >= (maxRpm - kAlsCutHysteresis)) && (rpm < maxRpm);
}

bool AntilagSystemBase::isALSHardCut(float rpm) const {
    if (!engineConfiguration->antiLagEnabled) {
        return false;
    }

    if (!isAntilagCondition) {
        return false;
    }

    const float maxRpm = (float)engineConfiguration->ALSMaxRPM;

    if (rpm >= maxRpm) {
        return true;
    }

    return false;
}

float AntilagSystemBase::getALSHardCutRatio(float rpm) const {
    return isALSHardCut(rpm) ? 1.0f : 0.0f;
}

#endif /* EFI_ANTILAG_SYSTEM */
