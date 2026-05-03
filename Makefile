KVERSION := `uname -r`
KDIR := /lib/modules/${KVERSION}/build

default: clean
	$(MAKE) -C $(KDIR) M=$$PWD

clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean

install: default
	$(MAKE) -C $(KDIR) M=$$PWD modules_install
	depmod -A

unload:
	rmmod hid_ltbhb_handbrake;

load:
	insmod hid_ltbhb_handbrake.ko
