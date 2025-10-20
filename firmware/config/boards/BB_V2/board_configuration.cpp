/**
 * @file boards/BB_V2/board_configuration.cpp
 * @brief Configuration defaults for the BB V2 board (standalone)
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
	engineConfiguration->injectionPins[4] = Gpio::E9;
	engineConfiguration->injectionPins[5] = Gpio::E11;
	engineConfiguration->injectionPins[6] = Gpio::E14;
	engineConfiguration->injectionPins[7] = Gpio::E13;
}

static void setIgnitionPins() {
	engineConfiguration->ignitionPinMode = OM_DEFAULT;

	engineConfiguration->ignitionPins[0] = Gpio::D7;
	engineConfiguration->ignitionPins[1] = Gpio::B9;
	engineConfiguration->ignitionPins[2] = Gpio::A8;
	engineConfiguration->ignitionPins[3] = Gpio::D10;
	engineConfiguration->ignitionPins[4] = Gpio::D9;
	engineConfiguration->ignitionPins[5] = Gpio::D11;
	engineConfiguration->ignitionPins[6] = Gpio::D8;
	engineConfiguration->ignitionPins[7] = Gpio::E8;
}

/* --- ETB --- */

static void setEtbConfig() {
	// Throttle #1
	engineConfiguration->etbIo[0].controlPin    = Gpio::B14;
	engineConfiguration->etbIo[0].directionPin1 = Gpio::D5;
	engineConfiguration->etbIo[0].disablePin    = Gpio::E4;
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

/* --- Sensor Defaults --- */

static void setupSensorInputs() {
	engineConfiguration->afr.hwChannel = EFI_ADC_14;
	setEgoSensor(ES_14Point7_Free);

	engineConfiguration->baroSensor.hwChannel = EFI_ADC_NONE;
	engineConfiguration->clt.config.bias_resistor = 2490;
	engineConfiguration->iat.config.bias_resistor = 2490;
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

/* --- LEDs --- */

Gpio getCommsLedPin()   { return Gpio::Unassigned; }
Gpio getRunningLedPin() { return Gpio::Unassigned; }
Gpio getWarningLedPin() { return Gpio::Unassigned; }

/* --- Main override and default configuration --- */

static void BBV2_ConfigOverrides() {
	setupVbatt();
	setEtbConfig();
	setupSensorInputs();
	setupCan();
}

static void BBV2_DefaultConfiguration() {
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
	BBV2_ConfigOverrides();
	BBV2_DefaultConfiguration();
}
