/*
 * @file antilag_system.h
 *
 * @date 26. nov. 2022
 *      Author: Turbo Marian
 */

#pragma once

#include <rusefi/timer.h>
#include "antilag_system_state_generated.h"

void initAntilagSystem();

class AntilagSystemBase : public antilag_system_state_s {
public:
    void update();

    bool isALSMinRPMCondition(float rpm) const;
    bool isALSMaxRPMCondition(float rpm) const;
    bool isALSMinCLTCondition() const;
    bool isALSMaxCLTCondition() const;
    bool isALSMaxEGTCondition() const;
    bool isALSMaxThrottleIntentCondition() const;
    bool isInsideALSSwitchCondition();
    bool isInsideALSTimerCondition();

    bool isAntilagConditionMet(float rpm);

    bool isALSHardCut(float rpm) const;

    float getALSHardCutRatio(float rpm) const;

private:
    Timer ALStimer;

    static constexpr float kAlsCutHysteresis = 500.0f;

    bool isALSPreCutWindow(float rpm) const;
};
