/*
 * Copyright (C) Atmosic 2025
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/ztest.h>
#include <zephyr/drivers/flash.h>
#include <zephyr/devicetree.h>
#include <zephyr/storage/flash_map.h>
#include <zephyr/drivers/flash/atm_flash_api_extensions.h>

#ifdef CONFIG_FLASH_EX_OP_ENABLED

#define TEST_AREA_DEVICE	FIXED_PARTITION_DEVICE(storage_partition)
static struct device const * const flash_dev = TEST_AREA_DEVICE;

ZTEST(flash_driver, test_flash_latency_lock)
{
	struct flash_atm_ex_op_latency_lock_in ll_in;

	ll_in.get = true;
	int ret = flash_ex_op(flash_dev, FLASH_ATM_EX_OP_LATENCY_LOCK, (uintptr_t)&ll_in, NULL);
	if (ret) {
		ztest_test_fail();
	}
	TC_PRINT("Acquired latency lock\n");

	ll_in.get = false;
	ret = flash_ex_op(flash_dev, FLASH_ATM_EX_OP_LATENCY_LOCK, (uintptr_t)&ll_in, NULL);
	if (ret) {
		ztest_test_fail();
	}
	TC_PRINT("Released latency lock\n");
}

#endif // CONFIG_FLASH_EX_OP_ENABLED
