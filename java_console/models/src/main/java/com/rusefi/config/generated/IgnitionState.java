package com.rusefi.config.generated;

// this file was generated automatically by rusEFI tool config_definition_base-all.jar based on (unknown script) controllers/algo/ignition/ignition_state.txt

// by class com.rusefi.output.FileJavaFieldsConsumer
import com.rusefi.config.*;

public class IgnitionState {
	public static final int BANKS_COUNT = 2;
	public static final int BOOST_BLEND_COUNT = 2;
	public static final int CAM_INPUTS_COUNT = 4;
	public static final int CAMS_PER_BANK = 2;
	public static final int EGT_CHANNEL_COUNT = 8;
	public static final String GAUGE_CATEGORY_BOOST_CONTROL = "Boost Control";
	public static final String GAUGE_CATEGORY_ETB = "ETB more";
	public static final String GAUGE_CATEGORY_FUEL_MATH = "Fuel: math";
	public static final String GAUGE_CATEGORY_SENT = "Sensors - SENT";
	public static final String GAUGE_CATEGORY_SYNC = "Sync";
	public static final String GAUGE_CATEGORY_TIMING = "Timing";
	public static final String GAUGE_COIL_DWELL_TIME = "Ignition: coil charge time";
	public static final String GAUGE_NAME_AC_PRESSURE = "A/C pressure";
	public static final String GAUGE_NAME_ACCEL_LAT = "Accel: Lateral";
	public static final String GAUGE_NAME_ACCEL_LON = "Accel: Longitudinal";
	public static final String GAUGE_NAME_ACCEL_VERT = "Accel: Vertical";
	public static final String GAUGE_NAME_ADJUSTED_TIMING = "Timing: ignition";
	public static final String GAUGE_NAME_AFR = "Air/Fuel Ratio";
	public static final String GAUGE_NAME_AFR2 = "Air/Fuel Ratio 2";
	public static final String GAUGE_NAME_AFR2_GAS_SCALE = "Air/Fuel Ratio 2 (Gas Scale)";
	public static final String GAUGE_NAME_AFR_GAS_SCALE = "Air/Fuel Ratio (Gas Scale)";
	public static final String GAUGE_NAME_AIR_FLOW_ESTIMATE = "Air: Flow estimate";
	public static final String GAUGE_NAME_AIR_FLOW_MEASURED = "MAF";
	public static final String GAUGE_NAME_AIR_FLOW_MEASURED_2 = "MAF #2";
	public static final String GAUGE_NAME_AIR_MASS = "Air: Cylinder airmass";
	public static final String GAUGE_NAME_AUX_LINEAR_1 = "Aux linear #1";
	public static final String GAUGE_NAME_AUX_LINEAR_2 = "Aux linear #2";
	public static final String GAUGE_NAME_AUX_LINEAR_3 = "Aux linear #3";
	public static final String GAUGE_NAME_AUX_LINEAR_4 = "Aux linear #4";
	public static final String GAUGE_NAME_AUX_TEMP1 = "Aux temp 1";
	public static final String GAUGE_NAME_AUX_TEMP2 = "Aux temp 2";
	public static final String GAUGE_NAME_BARO_PRESSURE = "Barometric pressure";
	public static final String GAUGE_NAME_BOOST_CLOSED_LOOP = "Boost: Closed loop";
	public static final String GAUGE_NAME_BOOST_OPEN_LOOP = "Boost: Open loop";
	public static final String GAUGE_NAME_BOOST_OUTPUT = "Boost: Output";
	public static final String GAUGE_NAME_BOOST_TARGET = "Boost: Target";
	public static final String GAUGE_NAME_CAN_READ_OK = "CAN: Rx";
	public static final String GAUGE_NAME_CAN_WRITE_ERR = "CAN: Tx err";
	public static final String GAUGE_NAME_CAN_WRITE_OK = "CAN: Tx OK";
	public static final String GAUGE_NAME_CLT = "CLT";
	public static final String GAUGE_NAME_CPU_TEMP = "CPU Temperature";
	public static final String GAUGE_NAME_CURRENT_GEAR = "TCU: Current Gear";
	public static final String GAUGE_NAME_DEBUG_F1 = "debug f1";
	public static final String GAUGE_NAME_DEBUG_F2 = "debug f2: iTerm";
	public static final String GAUGE_NAME_DEBUG_F3 = "debug f3: prevError";
	public static final String GAUGE_NAME_DEBUG_F4 = "debug f4: iParam";
	public static final String GAUGE_NAME_DEBUG_F5 = "debug f5: dParam";
	public static final String GAUGE_NAME_DEBUG_F6 = "debug f6: dTerm";
	public static final String GAUGE_NAME_DEBUG_F7 = "debug f7";
	public static final String GAUGE_NAME_DEBUG_I1 = "debug i1: pParam";
	public static final String GAUGE_NAME_DEBUG_I2 = "debug i2: offset";
	public static final String GAUGE_NAME_DEBUG_I3 = "debug i3";
	public static final String GAUGE_NAME_DEBUG_I4 = "debug i4";
	public static final String GAUGE_NAME_DEBUG_I5 = "debug i5";
	public static final String GAUGE_NAME_DESIRED_GEAR = "TCU: Desired Gear";
	public static final String GAUGE_NAME_DETECTED_GEAR = "Detected Gear";
	public static final String GAUGE_NAME_DWELL_DUTY = "Ignition: coil duty cycle";
	public static final String GAUGE_NAME_ECU_TEMPERATURE = "ECU temperature";
	public static final String GAUGE_NAME_ENGINE_CRC16 = "Engine CRC16";
	public static final String GAUGE_NAME_ETB_DUTY = "ETB: Duty";
	public static final String GAUGE_NAME_ETB_ERROR = "ETB: position error";
	public static final String GAUGE_NAME_ETB_TARGET = "ETB: position target";
	public static final String GAUGE_NAME_FLEX = "Flex Ethanol %";
	public static final String GAUGE_NAME_FUEL_BARO_CORR = "Fuel: Barometric pressure mult";
	public static final String GAUGE_NAME_FUEL_BASE = "Fuel: base cycle mass";
	public static final String GAUGE_NAME_FUEL_CHARGE_TEMP = "Fuel: Estimated charge temperature";
	public static final String GAUGE_NAME_FUEL_CLT_CORR = "Fuel: CLT correction";
	public static final String GAUGE_NAME_FUEL_CONSUMPTION = "Fuel: Total consumed";
	public static final String GAUGE_NAME_FUEL_CRANKING = "Fuel: cranking";
	public static final String GAUGE_NAME_FUEL_FLOW = "Fuel: Flow rate";
	public static final String GAUGE_NAME_FUEL_IAT_CORR = "Fuel: IAT correction";
	public static final String GAUGE_NAME_FUEL_INJ_DUTY = "Fuel: injector duty cycle";
	public static final String GAUGE_NAME_FUEL_INJ_DUTY_STAGE_2 = "Fuel: injector duty cycle stage 2";
	public static final String GAUGE_NAME_FUEL_INJECTION_TIMING = "Fuel: Injection timing SOI";
	public static final String GAUGE_NAME_FUEL_LAST_INJECTION = "Fuel: Last inj pulse width";
	public static final String GAUGE_NAME_FUEL_LAST_INJECTION_STAGE_2 = "Fuel: Last inj pulse width stg 2";
	public static final String GAUGE_NAME_FUEL_LEVEL = "Fuel level";
	public static final String GAUGE_NAME_FUEL_LOAD = "Fuel: Load";
	public static final String GAUGE_NAME_FUEL_PRESSURE_HIGH = "Fuel pressure (high)";
	public static final String GAUGE_NAME_FUEL_PRESSURE_HIGH_UNITS = "bar";
	public static final String GAUGE_NAME_FUEL_PRESSURE_LOW = "Fuel pressure (low)";
	public static final String GAUGE_NAME_FUEL_PRESSURE_LOW_UNITS = "kPa";
	public static final String GAUGE_NAME_FUEL_RUNNING = "Fuel: running";
	public static final String GAUGE_NAME_FUEL_TEMPERATURE = "Fuel Temperature";
	public static final String GAUGE_NAME_FUEL_TPS_EXTRA = "Fuel: TPS AE add fuel ms";
	public static final String GAUGE_NAME_FUEL_TRIM = "Fuel: fuel trim";
	public static final String GAUGE_NAME_FUEL_TRIM_2 = "Fuel: fuel trim 2";
	public static final String GAUGE_NAME_FUEL_VE = "Fuel: VE";
	public static final String GAUGE_NAME_FUEL_WALL_AMOUNT = "Fuel: wall amount";
	public static final String GAUGE_NAME_FUEL_WALL_CORRECTION = "Fuel: wall correction";
	public static final String GAUGE_NAME_FW_VERSION = "ECU Software Version";
	public static final String GAUGE_NAME_GEAR_RATIO = "Gearbox Ratio";
	public static final String GAUGE_NAME_GYRO_YAW = "Gyro: Yaw rate";
	public static final String GAUGE_NAME_IAC = "Idle: Position";
	public static final String GAUGE_NAME_IAT = "IAT";
	public static final String GAUGE_NAME_IDLE_POSITION = "Idle: Position sensor";
	public static final String GAUGE_NAME_IGNITION_LOAD = "Ignition: load";
	public static final String GAUGE_NAME_IGNITION_MODE = "Ignition: Mode";
	public static final String GAUGE_NAME_INJECTION_MODE = "Fuel: Injection mode";
	public static final String GAUGE_NAME_INJECTOR_LAG = "Fuel: injector lag";
	public static final String GAUGE_NAME_ISS = "TCU: Input Shaft Speed";
	public static final String GAUGE_NAME_KNOCK_COUNTER = "Knock: Count";
	public static final String GAUGE_NAME_KNOCK_FREQ = "knock: frequency";
	public static final String GAUGE_NAME_KNOCK_LEVEL = "Knock: Current level";
	public static final String GAUGE_NAME_KNOCK_RETARD = "Knock: Retard";
	public static final String GAUGE_NAME_LAMBDA = "Lambda";
	public static final String GAUGE_NAME_LAMBDA2 = "Lambda 2";
	public static final String GAUGE_NAME_LAST_ERROR = "Warning: last";
	public static final String GAUGE_NAME_MAF = "MAF";
	public static final String GAUGE_NAME_MAP = "MAP";
	public static final String GAUGE_NAME_OIL_PRESSURE = "Oil Pressure";
	public static final String GAUGE_NAME_OIL_PRESSURE_UNITS = "kPa";
	public static final String GAUGE_NAME_RAW_FUEL_PRESSURE_HIGH = "Fuel pressure raw (high)";
	public static final String GAUGE_NAME_RAW_FUEL_PRESSURE_LOW = "Fuel pressure raw (low)";
	public static final String GAUGE_NAME_RPM = "RPM";
	public static final String GAUGE_NAME_TARGET_AFR = "Fuel: target AFR";
	public static final String GAUGE_NAME_TARGET_LAMBDA = "Fuel: target lambda";
	public static final String GAUGE_NAME_TC_RATIO = "TCU: Torque Converter Ratio";
	public static final String GAUGE_NAME_TCHARGE = "Air: SD tCharge";
	public static final String GAUGE_NAME_THROTTLE_PEDAL = "Throttle pedal position";
	public static final String GAUGE_NAME_TIME = "Time";
	public static final String GAUGE_NAME_TIMING_ADVANCE = "Timing: base ignition";
	public static final String GAUGE_NAME_TPS = "TPS";
	public static final String GAUGE_NAME_TPS2 = "TPS2";
	public static final String GAUGE_NAME_TRG_ERR = "Trigger Error Counter";
	public static final String GAUGE_NAME_TRG_GAP = "Sync: Trigger Latest Ratio";
	public static final String GAUGE_NAME_TUNE_CRC16 = "Tune CRC16";
	public static final String GAUGE_NAME_TURBO_SPEED = "Turbocharger Speed";
	public static final String GAUGE_NAME_UPTIME = "Uptime";
	public static final String GAUGE_NAME_VBAT = "VBatt";
	public static final String GAUGE_NAME_VERSION = "firmware";
	public static final String GAUGE_NAME_VVS = "Vehicle Speed";
	public static final String GAUGE_NAME_VVT_B1E = "VVT: bank 1 exhaust";
	public static final String GAUGE_NAME_VVT_B1I = "VVT: bank 1 intake";
	public static final String GAUGE_NAME_VVT_B2E = "VVT: bank 2 exhaust";
	public static final String GAUGE_NAME_VVT_B2I = "VVT: bank 2 intake";
	public static final String GAUGE_NAME_VVT_TARGET_B1E = "VVT: bank 1 exhaust target";
	public static final String GAUGE_NAME_VVT_TARGET_B1I = "VVT: bank 1 intake target";
	public static final String GAUGE_NAME_VVT_TARGET_B2E = "VVT: bank 2 exhaust target";
	public static final String GAUGE_NAME_VVT_TARGET_B2I = "VVT: bank 2 intake target";
	public static final String GAUGE_NAME_WARNING_COUNTER = "Warning: counter";
	public static final String GAUGE_NAME_WARNING_LAST = "Warning: last";
	public static final String GAUGE_NAME_WG_POSITION = "Wastegate position sensor";
	public static final int HW_EVENT_TYPES = 4;
	public static final int IGN_BLEND_COUNT = 4;
	public static final String INDICATOR_NAME_AC_SWITCH = "AC switch";
	public static final String INDICATOR_NAME_BRAKE_DOWN = "Brake switch";
	public static final String INDICATOR_NAME_CLUTCH_DOWN = "Clutch: down";
	public static final String INDICATOR_NAME_CLUTCH_UP = "Clutch: up";
	public static final int LUA_ANALOG_INPUT_COUNT = 8;
	public static final int LUA_GAUGE_COUNT = 8;
	public static final int MAX_CYLINDER_COUNT = 12;
	public static final int PACK_ADD_TEMPERATURE = 40;
	public static final int PACK_MULT_AFR = 1000;
	public static final int PACK_MULT_AFR_CFG = 10;
	public static final int PACK_MULT_ANGLE = 50;
	public static final int PACK_MULT_EGTEMPERATURE = 4;
	public static final int PACK_MULT_FLEX = 2;
	public static final int PACK_MULT_FUEL_FLOW = 200;
	public static final int PACK_MULT_FUEL_MASS = 100;
	public static final int PACK_MULT_HIGH_PRESSURE = 10;
	public static final int PACK_MULT_LAMBDA = 10000;
	public static final int PACK_MULT_LAMBDA_CFG = 147;
	public static final int PACK_MULT_MASS_FLOW = 10;
	public static final int PACK_MULT_MS = 300;
	public static final int PACK_MULT_PERCENT = 100;
	public static final int PACK_MULT_PRESSURE = 30;
	public static final int PACK_MULT_TEMPERATURE = 100;
	public static final int PACK_MULT_VOLTAGE = 1000;
	public static final int PACK_MULT_VSS = 100;
	public static final int STFT_BANK_COUNT = 2;
	public static final int TARGET_AFR_BLEND_COUNT = 2;
	public static final int TCU_GEAR_COUNT = 10;
	public static final int TPS_2_BYTE_PACKING_MULT = 100;
	public static final int VE_BLEND_COUNT = 4;
	public static final Field BASEDWELL = Field.create("BASEDWELL", 0, FieldType.FLOAT).setBaseOffset(908);
	public static final Field SPARKDWELL = Field.create("SPARKDWELL", 4, FieldType.FLOAT).setBaseOffset(908);
	public static final Field DWELLDURATIONANGLE = Field.create("DWELLDURATIONANGLE", 8, FieldType.FLOAT).setBaseOffset(908);
	public static final Field CLTTIMINGCORRECTION = Field.create("CLTTIMINGCORRECTION", 12, FieldType.INT16).setScale(0.01).setBaseOffset(908);
	public static final Field TIMINGIATCORRECTION = Field.create("TIMINGIATCORRECTION", 14, FieldType.INT16).setScale(0.01).setBaseOffset(908);
	public static final Field TIMINGPIDCORRECTION = Field.create("TIMINGPIDCORRECTION", 16, FieldType.INT16).setScale(0.01).setBaseOffset(908);
	public static final Field DFCOTIMINGRETARD = Field.create("DFCOTIMINGRETARD", 18, FieldType.INT16).setScale(0.01).setBaseOffset(908);
	public static final Field BASEIGNITIONADVANCE = Field.create("BASEIGNITIONADVANCE", 20, FieldType.INT16).setScale(0.02).setBaseOffset(908);
	public static final Field CORRECTEDIGNITIONADVANCE = Field.create("CORRECTEDIGNITIONADVANCE", 22, FieldType.INT16).setScale(0.02).setBaseOffset(908);
	public static final Field TRACTIONADVANCEDROP = Field.create("TRACTIONADVANCEDROP", 24, FieldType.INT16).setScale(0.02).setBaseOffset(908);
	public static final Field ALIGNMENTFILL_AT_26 = Field.create("ALIGNMENTFILL_AT_26", 26, FieldType.INT8).setScale(1.0).setBaseOffset(908);
	public static final Field DWELLVOLTAGECORRECTION = Field.create("DWELLVOLTAGECORRECTION", 28, FieldType.FLOAT).setBaseOffset(908);
	public static final Field LUATIMINGADD = Field.create("LUATIMINGADD", 32, FieldType.FLOAT).setBaseOffset(908);
	public static final Field LUATIMINGMULT = Field.create("LUATIMINGMULT", 36, FieldType.FLOAT).setBaseOffset(908);
	public static final Field LUAIGNITIONSKIP = Field.create("LUAIGNITIONSKIP", 40, FieldType.BIT, 0).setBaseOffset(908);
	public static final Field TRAILINGSPARKANGLE = Field.create("TRAILINGSPARKANGLE", 44, FieldType.INT16).setScale(0.01).setBaseOffset(908);
	public static final Field ALIGNMENTFILL_AT_46 = Field.create("ALIGNMENTFILL_AT_46", 46, FieldType.INT8).setScale(1.0).setBaseOffset(908);
	public static final Field[] VALUES = {
	BASEDWELL,
	SPARKDWELL,
	DWELLDURATIONANGLE,
	CLTTIMINGCORRECTION,
	TIMINGIATCORRECTION,
	TIMINGPIDCORRECTION,
	DFCOTIMINGRETARD,
	BASEIGNITIONADVANCE,
	CORRECTEDIGNITIONADVANCE,
	TRACTIONADVANCEDROP,
	ALIGNMENTFILL_AT_26,
	DWELLVOLTAGECORRECTION,
	LUATIMINGADD,
	LUATIMINGMULT,
	LUAIGNITIONSKIP,
	TRAILINGSPARKANGLE,
	ALIGNMENTFILL_AT_46,
	};
}
