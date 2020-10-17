TARGET = tiny
BUILD_DIR ?= ./build

JLINK_DEVICE := LPC55S16

OPENOCD_CFG := openocd
LINKER_CFG := linker.ld

DEFINES := \
  CPU_LPC55S16JBD100 \
  __NO_SYSTEM_INIT \
  __STARTUP_CLEAR_BSS \
  __START=main \
  NDEBUG \

SRC_FILES := \

SRC_DIRS := \
  lib/nxp/LPC55S16 \
  lib/nxp/LPC55S16/drivers \
  src \
  src/hardware \

LIB_FILES := \

LIB_DIRS := \
  lib/tiny/src \

INC_DIRS := \
  lib/CMSIS/Include \
  lib/tiny/include \
  lib/tiny/include/hal \

LIBS := \
  lib/nxp/LPC55S16/gcc/libpower_hardabi_s.a

include target-worker.mk

.PHONY: watch
watch:
	@rerun "$(MAKE) --no-print-directory -f $(firstword $(MAKEFILE_LIST))"
