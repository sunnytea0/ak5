// SPDX-License-Identifier: GPL-2.0
#ifndef HELLO1_H
#define HELLO1_H

#include <linux/list.h>
#include <linux/ktime.h>

void print_hello(void);

struct hello_entry {
    struct list_head list;
    ktime_t start_time;
    ktime_t end_time;
};

#endif
