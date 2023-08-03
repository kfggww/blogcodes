#include <linux/module.h>
#include <linux/printk.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("junan");

static int __init testko_init(void)
{
    pr_info("testko init done\n");
    return 0;
}

static void __exit testko_exit(void)
{
    pr_info("testko exit done\n");
}

module_init(testko_init);
module_exit(testko_exit);