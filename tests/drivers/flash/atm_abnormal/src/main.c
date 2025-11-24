/*
 * Copyright (C) Atmosic 2025
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/ztest.h>
#include <zephyr/device.h>
#include <zephyr/drivers/flash.h>
#include <zephyr/devicetree.h>
#include <zephyr/storage/flash_map.h>
#include <zephyr/fs/nvs.h>
#include <zephyr/linker/section_tags.h>

#define RESET_TEST_MAGIC 0x5AA5C33C

static uint32_t __noinit reset_magic;
static uint8_t __noinit reset_flag;

ZTEST(flash_atm_abnormal, test_flash_abnormal)
{
	static struct nvs_fs nvs = {
		.flash_device = FIXED_PARTITION_DEVICE(t_storage0),
		.offset = FIXED_PARTITION_OFFSET(t_storage0),
	};

	/* Check if partition exist */
	if (!device_is_ready(FIXED_PARTITION_DEVICE(t_storage0))) {
		printk("Flash device %s is not ready\n", FIXED_PARTITION_DEVICE(t_storage0)->name);
		ztest_test_fail();
	}

	/* Mount t_storage0 partition */
	struct flash_pages_info info;
	int ret = flash_get_page_info_by_offs(FIXED_PARTITION_DEVICE(t_storage0),
					      FIXED_PARTITION_OFFSET(t_storage0), &info);
	if (ret) {
		printk("Unable to get page info, rc=%d\n", ret);
		ztest_test_fail();
	}

	nvs.sector_size = info.size;
	nvs.sector_count = FIXED_PARTITION_SIZE(t_storage0) / info.size;

	TC_PRINT("Doing nvs_mount\n");
	ret = nvs_mount(&nvs);
	if (ret) {
		printk("nvs_mount failed: %d\n", ret);
		ztest_test_fail();
	}

	/* Check if this is a reset after test started */
	if (reset_magic == RESET_TEST_MAGIC && reset_flag == 1) {
		/* Reset occurred - mark test as completed */
		TC_PRINT("nvs_mount success after reset\n");
		reset_flag = 0;
		return;
	}

	/* First run - set flag and trigger abnormal operation */
	reset_magic = RESET_TEST_MAGIC;
	reset_flag = 1;

	// Test abnormal operation - trigger reset during flash operation
	ret = nvs_clear(&nvs);
	if (ret) {
		printk("Failed to nvs_clear: %d\n", ret);
		ztest_test_fail();
	}
}

/* Test suite definition */
ZTEST_SUITE(flash_atm_abnormal, NULL, NULL, NULL, NULL, NULL);
