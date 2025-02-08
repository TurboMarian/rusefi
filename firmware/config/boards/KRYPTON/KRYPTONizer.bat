@echo off
cd ../../../

rem Clean the project
make clean -j8 PROJECT_BOARD=KRYPTON

rem Build the project
make -j8 PROJECT_BOARD=KRYPTON PROJECT_CPU=ARCH_STM32F4

rem Generate configuration file
gen_config_board.sh config/boards/KRYPTON KRYPTON rusefi_KRYPTON.ini

pause




