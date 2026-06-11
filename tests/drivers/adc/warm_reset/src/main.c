/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <limits.h>
#include <stdint.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/kernel.h>
#include <zephyr/linker/section_tags.h>
#include <zephyr/sys/reboot.h>
#include <zephyr/ztest.h>

#include "reset.h"

#define INVALID_ADC_SAMPLE INT32_MIN

#define RESET_TEST_MAGIC 0xADC0A11U

static const struct adc_dt_spec adc_channel = ADC_DT_SPEC_GET_BY_IDX(DT_PATH(zephyr_user), 0);

static uint32_t __noinit reset_magic;
static uint8_t __noinit reset_phase;

static void run_adc_read(void)
{
	int32_t sample[1] = {INVALID_ADC_SAMPLE};
	struct adc_sequence sequence = {
		.buffer = sample,
		.buffer_size = sizeof(sample),
	};
	int ret;

	zassert_true(adc_is_ready_dt(&adc_channel), "ADC device is not ready");

	ret = adc_channel_setup_dt(&adc_channel);
	zassert_equal(ret, 0, "adc_channel_setup_dt() failed: %d", ret);

	(void)adc_sequence_init_dt(&adc_channel, &sequence);
	ret = adc_read_dt(&adc_channel, &sequence);
	zassert_equal(ret, 0, "adc_read_dt() failed: %d", ret);
	zassert_not_equal(sample[0], INVALID_ADC_SAMPLE, "ADC sample buffer was not updated");

	TC_PRINT("ADC read succeeded after %s boot\n",
		 is_boot_type(TYPE_RESET) ? "reset" : "initial");
}

static void *adc_warm_reset_setup(void)
{
	if (is_boot_uninit()) {
		reset_magic = 0U;
		reset_phase = 0U;
	}

	return NULL;
}

ZTEST(adc_warm_reset, test_adc_warm_reset)
{
	run_adc_read();

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

ZTEST_SUITE(adc_warm_reset, NULL, adc_warm_reset_setup, NULL, NULL, NULL);
