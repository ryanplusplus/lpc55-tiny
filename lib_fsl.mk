LIBS := fsl $(LIBS)

INC_DIRS += \
  lib/nxp/$(SDK)/devices/$(DEVICE) \
  lib/nxp/$(SDK)/devices/$(DEVICE)/drivers \

fsl_LIB_ROOT := lib/nxp/$(SDK)

fsl_ASFLAGS := $(ASFLAGS)
fsl_CPPFLAGS := $(CPPFLAGS)
fsl_CFLAGS := $(CFLAGS)
fsl_CXXFLAGS := $(CXXFLAGS)

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

fsl_LIB_FILES := \

fsl_LIB_DIRS := \
  lib/nxp/$(SDK)/devices/$(DEVICE)/drivers \

LDLIBS += \
  lib/nxp/$(SDK)/devices/$(DEVICE)/gcc/libpower_hardabi_s.a