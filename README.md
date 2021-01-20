# bd_prochot_disable_module
A simple module for the Linux kernel which disables the BD_PROCHOT functionality

# System Requirements (for Arch)
  ## For the module (required)
  Run `pacman -S base-devel linux-headers` in order to install dependencies
  
  ## For dkms (optional)
  Run `pacman -S dkms`

# Build and test
  Run `make`, then `make test`.

# Use dkms
  Run `make install`, then `dkms autoinstall`. The module should work fine, even after a kernel update.
