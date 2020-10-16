TARGET = tiny
BUILD_DIR ?= ./build

OPENOCD_CFG := openocd
LINKER_CFG := linker.ld

DEFINES := \
  CPU_LPC55S16JBD100 \
  __NO_SYSTEM_INIT \
  __STARTUP_CLEAR_BSS \
  __START=main \

SRC_FILES := \

SRC_DIRS := \
  lib/nxp/LPC55S16 \
  src \
  src/hardware \

LIB_FILES := \

LIB_DIRS := \
  lib/tiny/src \

INC_DIRS := \
  lib/CMSIS/Include \
  lib/tiny/include \
  lib/tiny/include/hal \

include target-worker.mk

.PHONY: watch
watch:
	@rerun "$(MAKE) --no-print-directory -f $(firstword $(MAKEFILE_LIST))"
