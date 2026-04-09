/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/**
 * @file fast_code_test.c
 * @brief Test functions for fast_code linker demonstration
 */

#include <zephyr/sys/printk.h>

void fast_code_test_1(void)
{
	printk("Address of %s %p\n", __func__, &fast_code_test_1);
}

void fast_code_test_2(void)
{
	printk("Address of %s %p\n", __func__, &fast_code_test_2);
}
