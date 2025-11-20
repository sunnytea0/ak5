// SPDX-License-Identifier: GPL-2.0

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/ktime.h>
#include <linux/errno.h>
#include "hello1.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mariia Kolomiiets");
MODULE_DESCRIPTION("hello1 module exporting print_hello");

static LIST_HEAD(hello_list);

void print_hello(void)
{
    struct hello_entry *entry;

    entry = kmalloc(sizeof(*entry), GFP_KERNEL);
    if (!entry) {
        pr_err("hello1: memory allocation failed\n");
        return;
    }

    entry->start_time = ktime_get();
    pr_info("Hello, world!\n");
    entry->end_time = ktime_get();

    list_add_tail(&entry->list, &hello_list);
}
EXPORT_SYMBOL(print_hello);

static int __init hello1_init(void)
{
    pr_info("hello1 loaded\n");
    return 0;
}

static void __exit hello1_exit(void)
{
    struct hello_entry *entry, *tmp;

    list_for_each_entry_safe(entry, tmp, &hello_list, list) {
        pr_info("print_hello time: %lld ns\n",
                ktime_to_ns(ktime_sub(entry->end_time, entry->start_time)));

        list_del(&entry->list);
        kfree(entry);
    }

    pr_info("hello1 unloaded\n");
}

module_init(hello1_init);
module_exit(hello1_exit);
