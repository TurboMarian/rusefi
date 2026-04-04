/**
 * @file boards/apex/board_configuration.cpp
 * @brief Configuration defaults for the apex board (standalone)
 * @author Turbo Marian, 2025
 */

#include "pch.h"
#include "board_overrides.h"

/* --- Injectors & Ignition --- */

static void setInjectorPins() {
	engineConfiguration->injectionPinMode = OM_DEFAULT;

	engineConfiguration->injectionPins[0] = Gpio::G6;
	engineConfiguration->injectionPins[1] = Gpio::G5;
	engineConfiguration->injectionPins[2] = Gpio::G4;
	engineConfiguration->injectionPins[3] = Gpio::G3;
	engineConfiguration->injectionPins[4] = Gpio::G2;
	engineConfiguration->injectionPins[5] = Gpio::D15;
	engineConfiguration->injectionPins[6] = Gpio::Unassigned;
	engineConfiguration->injectionPins[7] = Gpio::Unassigned;
}

static void setIgnitionPins() {
	engineConfiguration->ignitionPinMode = OM_DEFAULT;

	engineConfiguration->ignitionPins[0] = Gpio::E15;
	engineConfiguration->ignitionPins[1] = Gpio::E14;
	engineConfiguration->ignitionPins[2] = Gpio::E13;
	engineConfiguration->ignitionPins[3] = Gpio::E12;
	engineConfiguration->ignitionPins[4] = Gpio::E11;
	engineConfiguration->ignitionPins[5] = Gpio::E10;
	engineConfiguration->ignitionPins[6] = Gpio::Unassigned;
	engineConfiguration->ignitionPins[7] = Gpio::Unassigned;
}

/* --- LEDs --- */

Gpio getCommsLedPin()   { return Gpio::B7; }
Gpio getRunningLedPin() { return Gpio::B8; }
Gpio getWarningLedPin() { return Gpio::B9; }

/* --- ETB --- */

static void setEtbConfig() {
	// Throttle #1
	engineConfiguration->etbIo[0].controlPin     = Gpio::E7;
	engineConfiguration->etbIo[0].directionPin1  = Gpio::G0;
	engineConfiguration->etbIo[0].disablePin     = Gpio::G1;
	engineConfiguration->etbIo[0].directionPin2  = Gpio::Unassigned;

	// Throttle #2
	engineConfiguration->etbIo[1].controlPin     = Gpio::F15;
	engineConfiguration->etbIo[1].directionPin1  = Gpio::F13;
	engineConfiguration->etbIo[1].disablePin     = Gpio::F14;
	engineConfiguration->etbIo[1].directionPin2  = Gpio::Unassigned;

	engineConfiguration->etb_use_two_wires = false;
}

/* --- Stepper Idle --- */

static void setStepperConfig() {
	engineConfiguration->idle.stepperDirectionPin = Gpio::Unassigned;
	engineConfiguration->idle.stepperStepPin      = Gpio::Unassigned;
	engineConfiguration->stepperEnablePin         = Gpio::Unassigned;
}

/* --- Vbatt sensing --- */

static void setupVbatt() {
	engineConfiguration->analogInputDividerCoefficient = 1.59f;
	engineConfiguration->vbattAdcChannel = EFI_ADC_0; // PA7
	engineConfiguration->adcVcc = 3.2f;
	engineConfiguration->vbattDividerCoeff = 7.5;
}

/* --- SD Card --- */

static void setupSdCard() {
	engineConfiguration->sdCardSpiDevice = SPI_DEVICE_2;
	engineConfiguration->is_enabled_spi_2 = true;
	engineConfiguration->spi2sckPin  = Gpio::B13;
	engineConfiguration->spi2misoPin = Gpio::B14;
	engineConfiguration->spi2mosiPin = Gpio::B15;
	engineConfiguration->sdCardCsPin = Gpio::G7;
}

/* --- EGT --- */

static void setupEGT() {
	engineConfiguration->spi1sckPin  = Gpio::B3;
	engineConfiguration->spi1misoPin = Gpio::B4;
	engineConfiguration->spi1mosiPin = Gpio::Unassigned;

	engineConfiguration->is_enabled_spi_1 = true;
	engineConfiguration->max31855spiDevice = SPI_DEVICE_1;
	engineConfiguration->max31855_cs[0] = Gpio::D2;
	engineConfiguration->max31855_cs[1] = Gpio::D3;
}

/* --- Sensor Defaults --- */

static void setupDefaultSensorInputs() {
	engineConfiguration->afr.hwChannel    = EFI_ADC_11; // PC1
	engineConfiguration->afr.hwChannel2   = EFI_ADC_10; // PC0
	setEgoSensor(ES_14Point7_Free);

	engineConfiguration->map.sensor.hwChannel = EFI_ADC_12; // PC2
	engineConfiguration->map.sensor.type = MT_MPXH6400;

	engineConfiguration->baroSensor.hwChannel = EFI_ADC_NONE;
}

/* --- Main override and default configuration --- */

static void customBoardConfigOverrides() {
	setupVbatt();
	setupSdCard();
	setEtbConfig();
	setStepperConfig();
	setupEGT();

	engineConfiguration->clt.config.bias_resistor = 2490;
	engineConfiguration->iat.config.bias_resistor = 2490;

	// Serial
	engineConfiguration->binarySerialTxPin = Gpio::D5;
	engineConfiguration->binarySerialRxPin = Gpio::D6;
	engineConfiguration->tunerStudioSerialSpeed = 230400;

	// CAN 1
	engineConfiguration->canRxPin = Gpio::D0;
	engineConfiguration->canTxPin = Gpio::D1;

	// CAN 2
	engineConfiguration->can2RxPin = Gpio::B5;
	engineConfiguration->can2TxPin = Gpio::B6;

	// Baro (I2C)
	engineConfiguration->lps25BaroSensorScl = Gpio::A8;
	engineConfiguration->lps25BaroSensorSda = Gpio::C9;
}

static void customBoardDefaultConfiguration() {
	setInjectorPins();
	setIgnitionPins();
	setupDefaultSensorInputs();

	engineConfiguration->canWriteEnabled = true;
	engineConfiguration->canReadEnabled  = true;
	engineConfiguration->canSleepPeriodMs = 50;

	engineConfiguration->canBaudRate  = B1MBPS;
	engineConfiguration->can2BaudRate = B500KBPS;
}

// Register the above board-specific configuration
void setup_custom_board_overrides() {
	custom_board_DefaultConfiguration = customBoardDefaultConfiguration;
	custom_board_ConfigOverrides = customBoardConfigOverrides;
}

#include "connectors/generated_outputs.h"

int getBoardMetaOutputsCount() {
	return efi::size(GENERATED_OUTPUTS);
}

int getBoardMetaLowSideOutputsCount() {
	return getBoardMetaOutputsCount();
}

Gpio* getBoardMetaOutputs() {
	return GENERATED_OUTPUTS;
}