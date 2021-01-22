# bd_prochot_disable_module
A simple module for the Linux kernel which turns off Intel's BD_PROCHOT.

<br/>

# Warning: do not try this module on machines with AMD CPU, as it hasn't been tested and, as well as being probably useless, it might harm your hardware.
Clearly, even if you use this module with an Intel CPU, <b>I do not take any responsibility and I am not liable for any damage caused through use of this module.</b>

<br/>

# Warning for users with proprietary NVIDIA graphics card driver
It seems that this module can't work with the new nvidia `460` drivers (since release `460.32.03-1`). I only tried it on my system, so maybe this doesn't happen in other environments, but there are serious performance issues while running games with the module loaded into the kernel: games run at ~15 fps.

I will try with other systems and I'm working on it, but, you know... Nvidia... Closed-source... It's realy hard.
Anyway, if you encounter this kind of problem, please, downgrade your drivers to version `455.45.01-7`, which seems to be the latest working release.
As soon as I have news, I will update this README.

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
