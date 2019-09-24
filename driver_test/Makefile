KERNEL_DIR ?= /usr/src/linux-headers-4.13.0-36-generic/
PWD := $(shell pwd)
obj-m := globalchardev.o

modules:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
clean:
	rm -rf *.o *.ko  

