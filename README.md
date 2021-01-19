# bd_prochot_disable_module
A simple module for the Linux kernel which disables the BD_PROCHOT functionality

# System Requirements (for Arch)
Run `pacman -S base-devel linux-headers` in order to install dependencies

#Build and test
Run `make`, then `insmod intel_msr.ko`. Running `dmesg` you should see if the module worked.

WIP
