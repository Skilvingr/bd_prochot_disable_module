# bd_prochot_disable_module
A simple module for the Linux kernel which disables the BD_PROCHOT functionality

# Install System Requirements (for Arch)
  ## For the module (required)
    pacman -S base-devel linux-headers
  
  ## For dkms (optional)
    pacman -S dkms

# Build and test
    make
    make test

# Use dkms
    make install
    dkms autoinstall
The module should work fine, even after a kernel update.
