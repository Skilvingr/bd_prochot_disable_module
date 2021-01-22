#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/msr.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Skilvingr");
MODULE_DESCRIPTION("A simple Linux module which disables Intel's BD_PROCHOT signal.");
MODULE_VERSION("0.01");

u64 initialValue = 0;
u64 currentValue = 0;
int retValue = 0;

static int __init intel_msr_init(void) {  
  if((retValue = rdmsrl_safe(0x1fc, &initialValue)) != 0){
    printk(KERN_ERR "intel_msr: Error while reading 0x1fc register. rdmsrl_safe() returned: %d", retValue);
    return -1;
  }

  
  currentValue = (initialValue & 0xfffffe);
  
  printk(KERN_INFO "intel_msr: Current value is: 0x%04llx. Writing new value 0x%04llx on 0x1fc msr...", initialValue, currentValue);

  wrmsrl(0x1fc, (initialValue & 0xfffffe));

  rdmsrl_safe(0x1fc, &currentValue);
  
  printk(KERN_INFO "intel_msr: Done. New value is: 0x%04llx\n", currentValue);

  return 0;
}

static void __exit intel_msr_exit(void) {
  printk(KERN_INFO "intel_msr: Restoring old 0x1fc msr value...");
  
  wrmsrl(0x1fc, initialValue);
  
  rdmsrl_safe(0x1fc, &currentValue);
  
  printk(KERN_INFO "intel_msr: Done. New value is: 0x%04llx\n", currentValue);
}

module_init(intel_msr_init);
module_exit(intel_msr_exit);
