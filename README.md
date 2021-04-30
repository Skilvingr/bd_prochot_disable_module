# bd_prochot_disable_module
A simple module for the Linux kernel which turns off Intel's BD_PROCHOT.

<br/>

# Warning: do not try this module on machines with AMD CPU. It hasn't been tested and, as well as being probably useless, it might harm your hardware.
Clearly, even if you use this module with an Intel CPU, <b>I do not take any responsibility and I am not liable for any damage caused through use of this module.</b>

<br/>

<b>The commands below must be executed as root</b>
<br/>

## Install System Requirements (on Arch)
  ### For the module (required):
    pacman -S base-devel linux-headers
  
  ### For dkms (optional):
    pacman -S dkms

## Build and test
    make insmod
This will build and load the module. Running `dmesg`, its messages should be visible.

## Use dkms
    make install
    dkms autoinstall
    depmod
Now the module should become loadable through `modprobe intel_msr` and it should work fine, even after a kernel update (tested on Arch).
