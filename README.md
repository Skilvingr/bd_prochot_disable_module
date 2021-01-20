# bd_prochot_disable_module
A simple module for the Linux kernel which disables the BD_PROCHOT functionality

<b>The commands below must be executed as root</b>
<br/>

## Install System Requirements (for Arch)
  ### For the module (required):
    pacman -S base-devel linux-headers
  
  ### For dkms (optional):
    pacman -S dkms

## Build and test
    make insmod
This will build and load the module in the system. Running `dmesg`, its messages should be visible.

## Use dkms
    make install
    dkms autoinstall
Now the module can be loaded with `modprobe intel_msr` and it should work fine, even after a kernel update (tested on Arch).
