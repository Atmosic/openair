/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <stdint.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/kernel.h>
#include <zephyr/linker/section_tags.h>
#include <zephyr/sys/reboot.h>
#include <zephyr/ztest.h>

#include "reset.h"

#define RESET_TEST_MAGIC 0x12C0A11U

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(i2c0))
static const struct device *i2c_dev = DEVICE_DT_GET(DT_NODELABEL(i2c0));
#elif DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(i2c1))
static const struct device *i2c_dev = DEVICE_DT_GET(DT_NODELABEL(i2c1));
#else
#error "No I2C device available for testing"
#endif

static uint32_t __noinit reset_magic;
static uint8_t __noinit reset_phase;

static void run_i2c_configure(void)
{
	zassert_true(device_is_ready(i2c_dev), "I2C device is not ready");

	int ret = i2c_configure(i2c_dev, I2C_SPEED_SET(I2C_SPEED_STANDARD) | I2C_MODE_CONTROLLER);

	zassert_equal(ret, 0, "i2c_configure() failed: %d", ret);

	TC_PRINT("I2C configure succeeded after %s boot\n",
		 is_boot_type(TYPE_RESET) ? "reset" : "initial");
}

static void *i2c_warm_reset_setup(void)
{
	if (is_boot_uninit()) {
		reset_magic = 0U;
		reset_phase = 0U;
	}

	return NULL;
}

ZTEST(i2c_warm_reset, test_i2c_warm_reset)
{
	run_i2c_configure();

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

ZTEST_SUITE(i2c_warm_reset, NULL, i2c_warm_reset_setup, NULL, NULL, NULL);
