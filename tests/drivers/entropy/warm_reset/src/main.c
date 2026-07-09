/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <zephyr/drivers/entropy.h>
#include <zephyr/kernel.h>
#include <zephyr/linker/section_tags.h>
#include <zephyr/sys/reboot.h>
#include <zephyr/ztest.h>

#include "reset.h"

#define RESET_TEST_MAGIC 0xE1710A11U

static const struct device *entropy_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_entropy));

static uint32_t __noinit reset_magic;
static uint8_t __noinit reset_phase;

static void run_entropy_get(void)
{
	uint8_t buf[4] = {0};

	zassert_true(device_is_ready(entropy_dev), "Entropy device is not ready");

	int ret = entropy_get_entropy(entropy_dev, buf, sizeof(buf));

	zassert_equal(ret, 0, "entropy_get_entropy() failed: %d", ret);

	TC_PRINT("Entropy read succeeded after %s boot: 0x%02x%02x%02x%02x\n",
		 is_boot_type(TYPE_RESET) ? "reset" : "initial", buf[0], buf[1], buf[2], buf[3]);
}

static void *entropy_warm_reset_setup(void)
{
	if (is_boot_uninit()) {
		reset_magic = 0U;
		reset_phase = 0U;
	}

	return NULL;
}

ZTEST(entropy_warm_reset, test_entropy_warm_reset)
{
	run_entropy_get();

	if ((reset_magic == RESET_TEST_MAGIC) && (reset_phase == 1U)) {
		zassert_true(is_boot_type(TYPE_RESET), "Expected reset boot type after warm reset");
		zassert_true(is_boot_reason(BOOT_STATUS_RESET_SW) ||
				     is_boot_reason(BOOT_STATUS_RESET_SYS),
			     "Expected warm reset boot reason");
		reset_magic = 0U;
		reset_phase = 0U;
		return;
	}

	reset_magic = RESET_TEST_MAGIC;
	reset_phase = 1U;
	TC_PRINT("Triggering warm reset\n");
	sys_reboot(SYS_REBOOT_WARM);
	zassert_unreachable("sys_reboot() returned unexpectedly");
}

ZTEST_SUITE(entropy_warm_reset, NULL, entropy_warm_reset_setup, NULL, NULL, NULL);
