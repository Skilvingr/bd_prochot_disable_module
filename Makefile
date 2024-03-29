MOD = intel_msr
MOD_VER = 1.0
KERNELDIR?=/lib/modules/$(shell uname -r)/build
MOD_SOURCE_PATH := /usr/src/intel_msr-1.0/
DKMS_MOD_PATH := /var/lib/dkms/intel_msr
PWD := $(shell pwd)
obj-m = $(MOD).o

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean

insmod: all
	sudo rmmod $(MOD).ko; true
	sudo insmod $(MOD).ko

install:
	mkdir -p $(MOD_SOURCE_PATH)
	cp -R * $(MOD_SOURCE_PATH)
	mkdir -p $(DKMS_MOD_PATH)/$(MOD_VER)
	ln -s $(MOD_SOURCE_PATH) $(DKMS_MOD_PATH)/$(MOD_VER)/source

uninstall:
	dkms uninstall intel_msr/1.0
	rm -rf $(MOD_SOURCE_PATH)
	rm -rf $(DKMS_MOD_PATH)

