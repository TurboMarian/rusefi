#pragma once

// Define the ADC for Knock
#define KNOCK_ADC ADCD3

// Knock sensor 1 settings - Pin PA2
#define KNOCK_ADC_CH1 ADC_CHANNEL_IN2
#define KNOCK_PIN_CH1 Gpio::A2

// Knock sensor 2 settings - Pin PA3
#define KNOCK_HAS_CH2 true
#define KNOCK_ADC_CH2 ADC_CHANNEL_IN3
#define KNOCK_PIN_CH2 Gpio::A3

// Set the sample rate & time (varies by MCU)
#define KNOCK_SAMPLE_TIME ADC_SAMPLE_84
#define KNOCK_SAMPLE_RATE (STM32_PCLK2 / (4 * (84 + 12)))
