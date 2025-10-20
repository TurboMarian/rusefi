/**
 * @file boards/KRYPTON/board_configuration.cpp
 * @brief Configuration defaults for the KRYPTON board (standalone)
 * @details This file contains default configurations for the KRYPTON board.
 * It initializes various pins, sensors, and communication settings.
 *
 * @author Turbo Marian, 2023
 */

#include "pch.h"

/* --- Injectors & Ignition --- */

static void setInjectorPins() {
	engineConfiguration->injectionPinMode = OM_DEFAULT;

	engineConfiguration->injectionPins[0] = Gpio::D2;
	engineConfiguration->injectionPins[1] = Gpio::C12;
	engineConfiguration->injectionPins[2] = Gpio::C8;
	engineConfiguration->injectionPins[3] = Gpio::C7;
	engineConfiguration->injectionPins[4] = Gpio::C6;
	engineConfiguration->injectionPins[5] = Gpio::D15;
	engineConfiguration->injectionPins[6] = Gpio::D14;
	engineConfiguration->injectionPins[7] = Gpio::D13;
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
	engineConfiguration->etbIo[0].directionPin1 = Gpio::B0;
	engineConfiguration->etbIo[0].disablePin    = Gpio::B1;
	engineConfiguration->etbIo[0].directionPin2 = Gpio::Unassigned;

	// Throttle #2
	engineConfiguration->etbIo[1].controlPin    = Gpio::Unassigned;
	engineConfiguration->etbIo[1].directionPin1 = Gpio::Unassigned;
	engineConfiguration->etbIo[1].disablePin    = Gpio::Unassigned;
	engineConfiguration->etbIo[1].directionPin2 = Gpio::Unassigned;

	engineConfiguration->etb_use_two_wires = false;

	// I2C Baro
	engineConfiguration->lps25BaroSensorScl = Gpio::A8;
	engineConfiguration->lps25BaroSensorSda = Gpio::C9;

	engineConfiguration->clt.config.bias_resistor = 2490;
	engineConfiguration->iat.config.bias_resistor = 2490;

	engineConfiguration->baroSensor.hwChannel = EFI_ADC_NONE;
}

/* --- CAN --- */

static void setupCan() {
	// CAN 1
	engineConfiguration->canTxPin = Gpio::D1;
	engineConfiguration->canRxPin = Gpio::D0;

	// CAN 2
	engineConfiguration->can2RxPin = Gpio::B5;
	engineConfiguration->can2TxPin = Gpio::B6;
}

/* --- Vbatt sensing --- */

static void setupVbatt() {
	engineConfiguration->analogInputDividerCoefficient = 1.56f;
	engineConfiguration->vbattDividerCoeff = (6.34f + 1.0f) / 1.0f;
	engineConfiguration->vbattAdcChannel = EFI_ADC_0;
	engineConfiguration->adcVcc = 3.3f;
}

/* --- LEDs --- */

Gpio getCommsLedPin()   { return Gpio::B8; }
Gpio getRunningLedPin() { return Gpio::B7; }
Gpio getWarningLedPin() { return Gpio::E1; }

/* --- Default sensors & SPI setup --- */

static void setupSpiAndSensors() {
	// SPI1 - EGT
	engineConfiguration->is_enabled_spi_1 = true;
	engineConfiguration->max31855spiDevice = SPI_DEVICE_1;
	engineConfiguration->spi1mosiPin = Gpio::Unassigned;
	engineConfiguration->spi1misoPin = Gpio::B4;
	engineConfiguration->spi1sckPin  = Gpio::B3;
	engineConfiguration->max31855_cs[0] = Gpio::A15;
	engineConfiguration->max31855_cs[1] = Gpio::A14;

	// SPI2 - SD card
	engineConfiguration->is_enabled_spi_2 = true;
	engineConfiguration->sdCardSpiDevice = SPI_DEVICE_2;
	engineConfiguration->spi2mosiPin = Gpio::B15;
	engineConfiguration->spi2misoPin = Gpio::B14;
	engineConfiguration->spi2sckPin  = Gpio::B13;
	engineConfiguration->sdCardCsPin = Gpio::A10;
	engineConfiguration->sdCardLogFrequency = 20;

	// CLT & IAT
	engineConfiguration->clt.adcChannel = EFI_ADC_2;
	engineConfiguration->useLinearCltSensor = true;
	engineConfiguration->iat.adcChannel = EFI_ADC_3;
	engineConfiguration->useLinearIatSensor = true;

	// MAP
	engineConfiguration->map.sensor.hwChannel = EFI_ADC_10;
	engineConfiguration->map.sensor.type = MT_MPXH6400;

	// TPS
	engineConfiguration->tps1_1AdcChannel = EFI_ADC_5;

	// Trigger inputs
	engineConfiguration->triggerInputPins[0] = Gpio::E5;
	engineConfiguration->camInputs[0] = Gpio::Unassigned;
}

/* --- Engine configuration --- */

static void setupEngineConfig() {
	engineConfiguration->cylindersCount = 6;
	engineConfiguration->firingOrder = FO_1_5_3_6_2_4;

	engineConfiguration->ignitionMode = IM_INDIVIDUAL_COILS;
	engineConfiguration->crankingInjectionMode = IM_SIMULTANEOUS;
	engineConfiguration->injectionMode = IM_SEQUENTIAL;

	engineConfiguration->rpmHardLimit = 5000;

	engineConfiguration->boostControlPin = Gpio::D11;
	engineConfiguration->fuelPumpPin     = Gpio::D12;
	engineConfiguration->fanPin          = Gpio::D10;
	engineConfiguration->tachOutputPin   = Gpio::D9;
}

/* --- Main override and default configuration --- */

static void Krypton_ConfigOverrides() {
	setupVbatt();
	setEtbConfig();
	setupCan();
	setupSpiAndSensors();
	setupEngineConfig();
}

static void Krypton_DefaultConfiguration() {
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
	Krypton_ConfigOverrides();
	Krypton_DefaultConfiguration();
}
