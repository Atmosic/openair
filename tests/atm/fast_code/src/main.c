/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/ztest.h>
#include <zephyr/sys/printk.h>
#include <zephyr/devicetree.h>

/* Declare external functions from fast_code_test.c */
extern void fast_code_test_1(void);
extern void fast_code_test_2(void);

#if !DT_NODE_EXISTS(DT_NODELABEL(fast_code_partition))
#error "Fast code partition not found in device tree"
#endif

#ifdef CONFIG_BOOTLOADER_MCUBOOT
// partition is nested in slot0
#define PART_FAST_CODE_ADDR()                                                                      \
	(DT_REG_ADDR(DT_MTD_FROM_FIXED_PARTITION(DT_NODELABEL(slot0_partition))) +                 \
	 DT_REG_ADDR(DT_NODELABEL(fast_code_partition)))
#else
#define PART_FAST_CODE_ADDR()                                                                      \
	(DT_REG_ADDR(DT_MTD_FROM_FIXED_PARTITION(DT_NODELABEL(fast_code_partition))) +             \
	 DT_REG_ADDR(DT_NODELABEL(fast_code_partition)))
#endif // CONFIG_BOOTLOADER_MCUBOOT

#define PART_FAST_CODE_SIZE() DT_REG_SIZE(DT_NODELABEL(fast_code_partition))

/* Helper macro to check if a function is in fast_code section */
#define IS_IN_FAST_CODE(func) \
	(PART_FAST_CODE_ADDR() <= (uintptr_t)(func) && \
	(uintptr_t)(func) < PART_FAST_CODE_ADDR() + PART_FAST_CODE_SIZE())

#define ASSERT_IN_FAST_CODE(func) zassert_true(IS_IN_FAST_CODE(func), #func " not in fast_code section")

/**
 * @brief Test fast_code section setup and range verification
 *
 * This test verifies that the fast_code section is properly configured
 * and displays the memory range information.
 */
ZTEST(fast_code, test_fast_code_range)
{
	printk("Fast Code Test\n");

	/* Print the range of fast_code */
	printk("Fast code range: 0x%08x - 0x%08x\n", (unsigned int)PART_FAST_CODE_ADDR(),
	       (unsigned int)PART_FAST_CODE_ADDR() + (unsigned int)PART_FAST_CODE_SIZE() - 1);

	/* Verify fast_code section is valid */
	zassert_not_equal(PART_FAST_CODE_ADDR(), 0, "Fast code address should not be zero");
	zassert_not_equal(PART_FAST_CODE_SIZE(), 0, "Fast code size should not be zero");
}

/**
 * @brief Test that fast_code_test_1 function is placed in fast_code section
 *
 * This test calls fast_code_test_1 and verifies that it is located
 * within the fast_code memory range (RRAM).
 */
ZTEST(fast_code, test_fast_code_test_1_placement)
{
	/* Call and display function address */
	fast_code_test_1();

	/* Verify function is in fast_code section */
	ASSERT_IN_FAST_CODE(fast_code_test_1);

	printk("fast_code_test_1 successfully verified in fast_code section\n");
}

/**
 * @brief Test that fast_code_test_2 function is placed in fast_code section
 *
 * This test calls fast_code_test_2 and verifies that it is located
 * within the fast_code memory range (RRAM).
 */
ZTEST(fast_code, test_fast_code_test_2_placement)
{
	/* Call and display function address */
	fast_code_test_2();

	/* Verify function is in fast_code section */
	ASSERT_IN_FAST_CODE(fast_code_test_2);

	printk("fast_code_test_2 successfully verified in fast_code section\n");
}

/* ZTEST suite definition */
ZTEST_SUITE(fast_code, NULL, NULL, NULL, NULL, NULL);
