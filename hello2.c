// SPDX-License-Identifier: GPL-2.0

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include "hello1.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mariia Kolomiiets");
MODULE_DESCRIPTION("hello2 module calling print_hello()");

static uint count = 1;
module_param(count, uint, 0444);
MODULE_PARM_DESC(count, "Number of hello calls");

extern void print_hello(void);

static int __init hello2_init(void)
{
    int i;

    if (count == 0 || (count >= 5 && count <= 10))
        pr_warn("hello2: unusual count value: %u\n", count);

    if (count > 10) {
        pr_err("hello2: count too large (%u)\n", count);
        return -EINVAL;
    }

    for (i = 0; i < count; i++)
        print_hello();

    pr_info("hello2 loaded\n");
    return 0;
}

static void __exit hello2_exit(void)
{
    pr_info("hello2 unloaded\n");
}

module_init(hello2_init);
module_exit(hello2_exit);
