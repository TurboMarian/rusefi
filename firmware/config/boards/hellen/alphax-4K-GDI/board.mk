

# Target ECU board design
BOARDCPPSRC = $(BOARD_DIR)/board_configuration.cpp

DDEFS += -DEFI_MC33816=TRUE
DDEFS += -DBOARD_TLE9104_COUNT=4

DDEFS += -DSTM32_ICU_USE_TIM1=TRUE -DSTM32_PWM_USE_TIM1=FALSE
DDEFS += -DEFI_SENT_SUPPORT=TRUE

# we have hellen board id BOARD_ID_GDI4CHAN_A

DDEFS += -DHW_HELLEN_4K_GDI=1
DDEFS += -DLUA_STM32_STANDBY=1

include $(BOARDS_DIR)/hellen/hellen-common-mega144.mk

