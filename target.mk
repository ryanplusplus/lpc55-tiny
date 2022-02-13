include tools/setup.mk

TARGET = target
BUILD_DIR ?= ./build

CPU := cortex-m33
LINKER_SCRIPT := linker.ld

DEVICE := LPC55S16

SDK := SDK_2.8.2_LPCXpresso55S16
SVD := lib/nxp/$(SDK)/devices/$(DEVICE)/$(DEVICE).xml

DEBUG_ADAPTER ?= jlink
JLINK_DEVICE := $(DEVICE)
OPENOCD_CFG_DIR := openocd
BLACK_MAGIC_PORT ?= /dev/ttyACM0
BLACK_MAGIC_POWER_TARGET ?= N

DEFINES := \
  CPU_LPC55S16JBD100 \
  __NO_SYSTEM_INIT \
  __STARTUP_CLEAR_BSS \
  __START=main \
  NDEBUG \

include tools/defaults.mk

CPPFLAGS += \
  -Wno-pedantic \
  -mfloat-abi=hard \
  -mfpu=fpv5-sp-d16 \
  -flto \
  -fwhole-program \

INC_DIRS := \
  lib/nxp/$(SDK)/CMSIS/Include \

SRC_FILES := \
  lib/nxp/$(SDK)/devices/$(DEVICE)/system_$(DEVICE).c \

SRC_DIRS := \
  src \
  src/hardware \

include lib_fsl.mk
include lib/tiny/lib_tiny.mk

include tools/tools.mk

.PHONY: watch
watch:
	@rerun "$(MAKE) --no-print-directory -f $(firstword $(MAKEFILE_LIST))"
