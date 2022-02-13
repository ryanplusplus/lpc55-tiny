$(call create_lib_with_defaults,fsl)

INC_DIRS += \
  lib/nxp/$(SDK)/devices/$(DEVICE) \
  lib/nxp/$(SDK)/devices/$(DEVICE)/drivers \

fsl_DEFINES := $(DEFINES)

fsl_CPPFLAGS += \
  -DNDEBUG \
  -Wno-unused-parameter \
  -Wno-expansion-to-defined \
  -Wno-old-style-declaration \

INC_DIRS += \
  lib/nxp/$(SDK)/devices/$(DEVICE)/drivers \

fsl_INC_DIRS := \
  lib/nxp/$(SDK)/CMSIS/Include \
  lib/nxp/$(SDK)/devices/$(DEVICE) \

fsl_SYS_INC_DIRS := \

fsl_SRC_FILES := \

fsl_SRC_DIRS := \
  lib/nxp/$(SDK)/devices/$(DEVICE)/drivers \

LDLIBS += \
  lib/nxp/$(SDK)/devices/$(DEVICE)/gcc/libpower_hardabi_s.a
