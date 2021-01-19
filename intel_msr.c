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

static int __init intel_msr_init(void) {  
  rdmsrl_safe(0x1FC, &initialValue);

  currentValue = (initialValue & 0xFFFFE);
  
  printk(KERN_INFO "Writing value 0x%04llx on 0x1FC msr...", currentValue);

  wrmsrl(0x1FC, (initialValue & 0xFFFFE));

  rdmsrl_safe(0x1FC, &currentValue);
  
  printk(KERN_INFO "Done. New value is: 0x%04llx\n", currentValue);

  return 0;
}

static void __exit intel_msr_exit(void) {
  printk(KERN_INFO "Restoring old 0x1FC msr value...");
  
  wrmsrl(0x1FC, initialValue);
  
  rdmsrl_safe(0x1FC, &currentValue);
  
  printk(KERN_INFO "Done. New value is: 0x%04llx\n", currentValue);
}

module_init(intel_msr_init);
module_exit(intel_msr_exit);
