//DO NOT EDIT MANUALLY, let automation work hard.

// auto-generated by PinoutLogic.java based on config/boards/BB_V2/connectors/main.yaml
#include "pch.h"

// see comments at declaration in pin_repository.h
const char * getBoardSpecificPinName(brain_pin_e brainPin) {
	switch(brainPin) {
		case Gpio::A8: return "Ignition 3";
		case Gpio::B12: return "Low current output 1";
		case Gpio::B14: return "DBW_PWM";
		case Gpio::B9: return "Ignition 2";
		case Gpio::C13: return "Tacho output";
		case Gpio::C6: return "Boost controler";
		case Gpio::C7: return "Idle valve 1";
		case Gpio::D10: return "Ignition 4";
		case Gpio::D11: return "Ignition 6";
		case Gpio::D12: return "Injector 1";
		case Gpio::D13: return "Injector 2";
		case Gpio::D14: return "Injector 3";
		case Gpio::D15: return "Injector 4";
		case Gpio::D3: return "Low side output 1";
		case Gpio::D4: return "Digital input 1";
		case Gpio::D5: return "DBW_DIR";
		case Gpio::D6: return "Digital input 2";
		case Gpio::D7: return "Ignition 1";
		case Gpio::D8: return "Ignition 7";
		case Gpio::D9: return "Ignition 5";
		case Gpio::E0: return "Crankshaft Sensor";
		case Gpio::E1: return "Camshaft Sensor";
		case Gpio::E11: return "Injector 6";
		case Gpio::E12: return "VVT output";
		case Gpio::E13: return "Injector 8";
		case Gpio::E14: return "Injector 7";
		case Gpio::E3: return "Fuel pump output";
		case Gpio::E4: return "DBW_DIS";
		case Gpio::E6: return "Fan output";
		case Gpio::E8: return "Ignition 8";
		case Gpio::E9: return "Injector 5";
		default: return nullptr;
	}
	return nullptr;
}
