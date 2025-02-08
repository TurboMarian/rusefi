@echo off
cd ../../../

rem Clean the project
make clean -j8 PROJECT_BOARD=BB_V3

rem Build the project
make -j8 PROJECT_BOARD=BB_V3 PROJECT_CPU=ARCH_STM32F4

rem Generate configuration file
gen_config_board.sh config/boards/BB_V3 BB_V3 rusefi_BB_V3.ini

pause




