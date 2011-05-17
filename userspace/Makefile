
# Most of the sub makefiles require some variables that used to be
# in the auto-generated ../Makedefs (when software was in svn).
# So let's add all of the needed variables here (environment can override)

LINUX ?= $(WRDEV_DIR)/software/rubi-repos/linux-wr
ARCH ?= arm
CROSS_COMPILE ?= $(CROSS_COMPILE_ARM_PATH)$(CROSS_COMPILE_ARM_PREFIX)
CROSS_COMPILE_ARM ?= $(CROSS_COMPILE)

# Installation of all of this stuff goes to images/wr in the output dir
WR_INSTALL_ROOT ?= $(WRS_OUTPUT_DIR)/images/wr
WRDEV_DIR ?= $(WRS_BASE_DIR)/..

# all variables are exported
export

all:
	$(MAKE) -C 3rdparty all
#	$(MAKE) -C rubi-repos/ptp-noposix all
	$(MAKE) -C libswitchhw all
	$(MAKE) -C wrsw_hal all
#	$(MAKE) -C wrsw_rtud all
#	$(MAKE) -C tests/rtu_stat TARGET=ARM all

clean:
	$(MAKE) -C 3rdparty clean
#	$(MAKE) -C rubi-repos/ptp-noposix clean
	$(MAKE) -C libswitchhw clean
	$(MAKE) -C wrsw_hal clean
#	$(MAKE) -C wrsw_rtud clean
#	$(MAKE) -C tests/wr_mon clean
#	$(MAKE) -C tests/rtu_stat clean

install: all
	$(MAKE) -C 3rdparty install
	$(MAKE) -C libswitchhw install
	$(MAKE) -C wrsw_hal install
#	$(MAKE) -C wrsw_rtud deploy
#	$(MAKE) -C tests/rtu_stat TARGET=ARM deploy
#	./rubi-repos/deploy.sh $(WR_INSTALL_ROOT)

#rootfs: install
#	mkdir -p $(WR_INSTALL_ROOT)/firmware
#	cp $(WRDEV_DIR)/hdl/bin/*.bin $(WR_INSTALL_ROOT)/firmware
#	../scripts/build_rootfs.sh