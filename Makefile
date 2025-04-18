.SILENT:

MAKEFLAGS += --no-print-directory

QMK_USERSPACE := $(patsubst %/,%,$(dir $(shell realpath "$(lastword $(MAKEFILE_LIST))")))
ifeq ($(QMK_USERSPACE),)
    QMK_USERSPACE := $(shell pwd)
endif

QMK_FIRMWARE_ROOT = $(shell qmk config -ro user.qmk_home | cut -d= -f2 | sed -e 's@^None$$@@g')
ifeq ($(QMK_FIRMWARE_ROOT),)
    $(error Cannot determine qmk_firmware location. `qmk config -ro user.qmk_home` is not set)
endif

# Custom targets.
max:
	+$(MAKE) -C $(QMK_FIRMWARE_ROOT) keychron/q1_max/ansi_encoder:bjornorri QMK_USERSPACE=$(QMK_USERSPACE)
pro:
	+$(MAKE) -C $(QMK_FIRMWARE_ROOT) keychron/q1_pro/ansi_knob:bjornorri QMK_USERSPACE=$(QMK_USERSPACE)

all: max pro

# Generic passthrough
%:
	+$(MAKE) -C $(QMK_FIRMWARE_ROOT) $(MAKECMDGOALS) QMK_USERSPACE=$(QMK_USERSPACE)
