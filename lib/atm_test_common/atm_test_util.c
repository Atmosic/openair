/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zephyr/sys/printk.h>

#include "arch.h"
#include "reset.h"
#include "atm_test_common.h"

#if CONFIG_ATM_TEST_AUTO_PASS
/* Define a kernel timer */
static struct k_timer auto_test_stop_timer;

/* Timer callback function */
static void timer_handler(struct k_timer *timer_id)
{
    ATM_TEST_PASSED();
}

static int auto_test_stop_init_function(void)
{
    k_timer_init(&auto_test_stop_timer, timer_handler, NULL);

    printk("Start auto pass timer\n");

    k_timer_start(&auto_test_stop_timer, K_MSEC(CONFIG_ATM_TEST_AUTO_PASS_TIME),
	K_NO_WAIT);

    return 0;
}

/* Register the function to run at the APPLICATION init level */
SYS_INIT(auto_test_stop_init_function, APPLICATION,
    CONFIG_APPLICATION_INIT_PRIORITY);

#endif

void atm_test_pass_if_socoff(void)
{
    if (is_boot_type(TYPE_SOCOFF)) {
	printk("boot from socoff\n");
	ATM_TEST_PASSED();
    }
}
