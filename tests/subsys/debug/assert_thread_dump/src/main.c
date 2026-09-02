/**
 *******************************************************************************
 *
 * @file main.c
 *
 * @brief Assert thread dump test
 *
 * Copyright (C) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include "arch.h"

static K_SEM_DEFINE(pend_sem, 0, 1);

static void pender_entry(void *p1, void *p2, void *p3)
{
	k_sem_take(&pend_sem, K_FOREVER);
}

static void sleeper_entry(void *p1, void *p2, void *p3)
{
	for (;;) {
		k_sleep(K_SECONDS(60));
	}
}

K_THREAD_DEFINE(pender, 1024, pender_entry, NULL, NULL, NULL, 5, 0, 0);
K_THREAD_DEFINE(sleeper, 1024, sleeper_entry, NULL, NULL, NULL, 6, 0, 0);

int main(void)
{
	// Let the helper threads start and block
	k_sleep(K_MSEC(100));

	printk("triggering fatal path\n");

#if defined(CONFIG_TEST_TRIGGER_K_PANIC)
	k_panic();
#elif defined(CONFIG_TEST_TRIGGER_ASSERT_INFO)
	ASSERT_INFO(0, 0x1234, 0x5678);
#else
	ASSERT_ERR(0);
#endif

	return 0;
}
