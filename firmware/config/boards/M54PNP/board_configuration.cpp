/**
 * @file boards/coreECU/board_configuration.cpp
 * @brief Configuration defaults for the coreECU board (standalone)
 * @details This file contains default configurations for the coreECU board.
 * It initializes various pins, sensors, and communication settings.
 *
 * @author Turbo Marian, 2023
 */

#include "pch.h"

/* --- Injectors & Ignition --- */

static void setInjectorPins() {
	engineConfiguration->injectionPinMode = OM_DEFAULT;

	engineConfiguration->injectionPins[0] = Gpio::D12;
	engineConfiguration->injectionPins[1] = Gpio::D13;
	engineConfiguration->injectionPins[2] = Gpio::D14;
	engineConfiguration->injectionPins[3] = Gpio::D15;
	engineConfiguration->injectionPins[4] = Gpio::C6;
	engineConfiguration->injectionPins[5] = Gpio::C7;
	engineConfiguration->injectionPins[6] = Gpio::C9;
	engineConfiguration->injectionPins[7] = Gpio::A8;
}

static void setIgnitionPins() {
	engineConfiguration->ignitionPinMode = OM_DEFAULT;

	engineConfiguration->ignitionPins[0] = Gpio::E15;
	engineConfiguration->ignitionPins[1] = Gpio::E14;
	engineConfiguration->ignitionPins[2] = Gpio::E13;
	engineConfiguration->ignitionPins[3] = Gpio::E12;
	engineConfiguration->ignitionPins[4] = Gpio::E11;
	engineConfiguration->ignitionPins[5] = Gpio::E10;
	engineConfiguration->ignitionPins[6] = Gpio::E9;
	engineConfiguration->ignitionPins[7] = Gpio::E8;
}

/* --- ETB --- */

static void setEtbConfig() {
	// Throttle #1
	engineConfiguration->etbIo[0].controlPin    = Gpio::E7;
	engineConfiguration->etbIo[0].directionPin1 = Gpio::B1;
	engineConfiguration->etbIo[0].disablePin    = Gpio::B0;
	engineConfiguration->etbIo[0].directionPin2 = Gpio::Unassigned;

	// Throttle #2
	engineConfiguration->etbIo[1].controlPin    = Gpio::Unassigned;
	engineConfiguration->etbIo[1].directionPin1 = Gpio::Unassigned;
	engineConfiguration->etbIo[1].disablePin    = Gpio::Unassigned;
	engineConfiguration->etbIo[1].directionPin2 = Gpio::Unassigned;

	engineConfiguration->etb_use_two_wires = false;

	engineConfiguration->clt.config.bias_resistor = 2490;
	engineConfiguration->iat.config.bias_resistor = 2490;

	engineConfiguration->baroSensor.hwChannel = EFI_ADC_NONE;

	engineConfiguration->lps25BaroSensorScl = Gpio::Unassigned;
	engineConfiguration->lps25BaroSensorSda = Gpio::Unassigned;

	// AFR (optional)
	// engineConfiguration->afr.hwChannel = EFI_ADC_6;
	// setEgoSensor(ES_14Point7_Free);
}

/* --- CAN --- */

static void setupCan() {
	// CAN 1
	engineConfiguration->canTxPin = Gpio::D1;
	engineConfiguration->canRxPin = Gpio::D0;

	// CAN 2
	engineConfiguration->can2RxPin = Gpio::Unassigned;
	engineConfiguration->can2TxPin = Gpio::Unassigned;
}

/* --- Vbatt sensing --- */

static void setupVbatt() {
	engineConfiguration->analogInputDividerCoefficient = 1.47f;
	engineConfiguration->vbattDividerCoeff = (6.34f / 1.0f);
	engineConfiguration->vbattAdcChannel = EFI_ADC_14;
	engineConfiguration->adcVcc = 3.3f;
}

/* --- LEDs --- */

Gpio getCommsLedPin()   { return Gpio::B8; }
Gpio getRunningLedPin() { return Gpio::B7; }
Gpio getWarningLedPin() { return Gpio::B6; }

/* --- Main override and default configuration --- */

static void CoreECU_ConfigOverrides() {
	setupVbatt();
	setEtbConfig();
	setupCan();
}

static void CoreECU_DefaultConfiguration() {
	setInjectorPins();
	setIgnitionPins();

	engineConfiguration->isSdCardEnabled = true;

	engineConfiguration->canWriteEnabled = true;
	engineConfiguration->canReadEnabled  = true;
	engineConfiguration->canSleepPeriodMs = 50;

	engineConfiguration->canBaudRate  = B1MBPS;
	engineConfiguration->can2BaudRate = B500KBPS;
}

/* --- Entry point expected by firmware --- */

void setup_custom_board_overrides(void) {
	CoreECU_ConfigOverrides();
	CoreECU_DefaultConfiguration();
}
