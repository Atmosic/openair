/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
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
