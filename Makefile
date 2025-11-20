ifneq ($(KERNELRELEASE),)

ccflags-y += -I$(M)/inc

obj-m += hello1.o
obj-m += hello2.o

else

KDIR ?= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) M=$(PWD)

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

endif
