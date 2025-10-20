/**
 * @file boards/BB_V3/board_configuration.cpp
 * @brief Configuration defaults for the BB V3 board (standalone)
 * @details This file contains default configurations for the BB V3 board.
 * It initializes various pins, sensors, and communication settings.
 *
 * @author Turbo Marian, 2023
 */

#include "pch.h"

/* --- Injectors & Ignition --- */

static void setInjectorPins() {
	engineConfiguration->injectionPinMode = OM_DEFAULT;

	engineConfiguration->injectionPins[0] = Gpio::E5;
	engineConfiguration->injectionPins[1] = Gpio::E6;
	engineConfiguration->injectionPins[2] = Gpio::E0;
	engineConfiguration->injectionPins[3] = Gpio::C13;
	engineConfiguration->injectionPins[4] = Gpio::E1;
	engineConfiguration->injectionPins[5] = Gpio::A15;
	engineConfiguration->injectionPins[6] = Gpio::A7;
	engineConfiguration->injectionPins[7] = Gpio::B8;
}

static void setIgnitionPins() {
	engineConfiguration->ignitionPinMode = OM_DEFAULT;

	engineConfiguration->ignitionPins[0] = Gpio::B9;
	engineConfiguration->ignitionPins[1] = Gpio::B6;
	engineConfiguration->ignitionPins[2] = Gpio::B7;
	engineConfiguration->ignitionPins[3] = Gpio::B3;
	engineConfiguration->ignitionPins[4] = Gpio::B5;
	engineConfiguration->ignitionPins[5] = Gpio::D1;
	engineConfiguration->ignitionPins[6] = Gpio::D4;
	engineConfiguration->ignitionPins[7] = Gpio::D7;
}

/* --- ETB --- */

static void setEtbConfig() {
	// Throttle #1
	engineConfiguration->etbIo[0].controlPin    = Gpio::B14;
	engineConfiguration->etbIo[0].directionPin1 = Gpio::D0;
	engineConfiguration->etbIo[0].disablePin    = Gpio::D3;
	engineConfiguration->etbIo[0].directionPin2 = Gpio::Unassigned;

	// Throttle #2
	engineConfiguration->etbIo[1].controlPin    = Gpio::Unassigned;
	engineConfiguration->etbIo[1].directionPin1 = Gpio::Unassigned;
	engineConfiguration->etbIo[1].disablePin    = Gpio::Unassigned;
	engineConfiguration->etbIo[1].directionPin2 = Gpio::Unassigned;

	engineConfiguration->etb_use_two_wires = false;
}

/* --- Vbatt sensing --- */

static void setupVbatt() {
	engineConfiguration->analogInputDividerCoefficient = 1.47f;
	engineConfiguration->vbattDividerCoeff = (6.34f / 1.0f);
	engineConfiguration->vbattAdcChannel = EFI_ADC_15;
	engineConfiguration->adcVcc = 3.3f;
}

/* --- Sensors --- */

static void setupSensorInputs() {
	engineConfiguration->afr.hwChannel = EFI_ADC_14;
	setEgoSensor(ES_14Point7_Free);

	engineConfiguration->baroSensor.hwChannel = EFI_ADC_NONE;
	engineConfiguration->clt.config.bias_resistor = 2490;
	engineConfiguration->iat.config.bias_resistor = 2490;
}

/* --- CAN --- */

static void setupCan() {
	// CAN 1 bus overwrites
	engineConfiguration->canTxPin = Gpio::B13;
	engineConfiguration->canRxPin = Gpio::B12;

	// CAN 2 bus overwrites
	engineConfiguration->can2RxPin = Gpio::Unassigned;
	engineConfiguration->can2TxPin = Gpio::Unassigned;
}

/* --- LEDs --- */

Gpio getCommsLedPin()   { return Gpio::Unassigned; }
Gpio getRunningLedPin() { return Gpio::Unassigned; }
Gpio getWarningLedPin() { return Gpio::Unassigned; }

/* --- Main override and default configuration --- */

static void BBV3_ConfigOverrides() {
	setupVbatt();
	setEtbConfig();
	setupSensorInputs();
	setupCan();
}

static void BBV3_DefaultConfiguration() {
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
	BBV3_ConfigOverrides();
	BBV3_DefaultConfiguration();
}
