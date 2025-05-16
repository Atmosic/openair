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

#ifdef CONFIG_FLASH_ATM_RUID
#define TEST_AREA_DEVICE	FIXED_PARTITION_DEVICE(storage_partition)
static const struct device *const flash_dev = TEST_AREA_DEVICE;
#include <zephyr/drivers/flash/atm_flash_api_extensions.h>

ZTEST(flash_driver, test_flash_ruid)
{
	struct flash_atm_ex_op_uid_out uid_out;
	int ret = flash_ex_op(flash_dev, FLASH_ATM_EX_OP_RUID, (uintptr_t)NULL, &uid_out);

	if (!ret) {
		TC_PRINT("uid32:\n");
		for (int i = 0; i < ARRAY_SIZE(uid_out.uid); i++) {
			TC_PRINT("0x%08" PRIx32"\n", uid_out.uid[i]);
		}
		TC_PRINT("uid8:\n");
		for (int i = 0; i < ARRAY_SIZE(uid_out.uid8); i++) {
			TC_PRINT("%02" PRIx8, uid_out.uid8[i]);
		}
		TC_PRINT("\n");
		return;
	}

	if (ret == -ENOTSUP) {
		TC_PRINT("Only support GIGA and PUYA\n");
		ztest_test_skip();
		return;
	}

	ztest_test_fail();
}
#endif
