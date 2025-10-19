# List of all the board related files.
BOARDCPPSRC =  $(BOARD_DIR)/board_configuration.cpp

# Override DEFAULT_ENGINE_TYPE
DDEFS += -DSTM32F407xx
DDEFS += -DFIRMWARE_ID=\"BB_V3\"
DDEFS += -DLED_CRITICAL_ERROR_BRAIN_PIN=Gpio::Unassigned
DDEFS += -DHAL_TRIGGER_USE_PAL=TRUE
DDEFS += -DHAL_VSS_USE_PAL=TRUE

# Define the flash size for the board (This board has 512K STM32F407)
DDEFS += -DMIN_FLASH_SIZE=512

# Enable specific features for the board
DDEFS += -DSTM32_ADC_USE_ADC3=TRUE
DDEFS += -DEFI_SOFTWARE_KNOCK=TRUE

# reduce memory usage monitoring
DDEFS += -DRAM_UNUSED_SIZE=100

# Lua size
DDEFS += -DLUA_USER_HEAP=32000
