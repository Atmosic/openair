/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <string.h>

#include <zephyr/devicetree.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/util.h>
#include <zephyr/ztest.h>

#include "atm_adc.h"

#define ADC_NODE DT_NODELABEL(adc)

#define TEST_CH_IF_PRESENT(prop)                                                                   \
	COND_CODE_1(DT_NODE_HAS_PROP(ADC_NODE, prop), (DT_PROP(ADC_NODE, prop),), ())

/* clang-format off */
static const uint8_t test_channels[] = {
	TEST_CH_IF_PRESENT(ch_cell)
	TEST_CH_IF_PRESENT(ch_store)
	TEST_CH_IF_PRESENT(ch_core)
	TEST_CH_IF_PRESENT(ch_temp)
	TEST_CH_IF_PRESENT(ch_p1diff)
	TEST_CH_IF_PRESENT(ch_p0diff)
	TEST_CH_IF_PRESENT(ch_p1single0)
	TEST_CH_IF_PRESENT(ch_p1single1)
	TEST_CH_IF_PRESENT(ch_p0single0)
	TEST_CH_IF_PRESENT(ch_p0single1)
	TEST_CH_IF_PRESENT(ch_batt)
	TEST_CH_IF_PRESENT(ch_p2single)
	TEST_CH_IF_PRESENT(ch_p3single)
	TEST_CH_IF_PRESENT(ch_p4single)
};
/* clang-format on */

BUILD_ASSERT(ARRAY_SIZE(test_channels) > 0, "&adc node has no ch-* properties; nothing to sweep");

ZTEST(adc_basic, test_atm_adc_test_all_channels_100x)
{
#define STRESS_ITER 100U
	for (unsigned int iter = 0; iter < STRESS_ITER; iter++) {
		for (size_t i = 0; i < ARRAY_SIZE(test_channels); i++) {
			uint8_t ch = test_channels[i];
			int16_t raw;

			int rc = atm_adc_test_raw_samples(ch, &raw, 1);

			zassert_ok(rc, "iter=%u ch=%u: atm_adc_test_raw_samples failed (%d)", iter,
				   ch, rc);
		}
	}
}

ZTEST(adc_basic, test_atm_adc_test_bit_sampling_statistics)
{
	for (size_t i = 0; i < ARRAY_SIZE(test_channels); i++) {
		uint8_t ch = test_channels[i];
#define TEST_ITER 10U
		int16_t raw[TEST_ITER * BITS_PER_BYTE];
		uint8_t samples[TEST_ITER];
		uint8_t min = UINT8_MAX;
		uint8_t max = 0U;
		uint16_t sum = 0U;
		uint16_t bits = 0U;
		uint8_t unique = 0U;

		int rc = atm_adc_test_raw_samples(ch, raw, ARRAY_SIZE(raw));

		zassert_ok(rc, "ch=%u: atm_adc_test_raw_samples failed (%d)", ch, rc);

		for (unsigned int j = 0; j < TEST_ITER; j++) {
			uint8_t byte = 0U;

			for (unsigned int k = 0; k < BITS_PER_BYTE; k++) {
				byte = (byte << 1) | !!(raw[j * BITS_PER_BYTE + k] &
							CONFIG_TEST_RAW_SAMPLE_BIT_MASK);
			}
			samples[j] = byte;
		}

		char line[16U + TEST_ITER * 5U + 64U];
		size_t pos = 0;

		pos += snprintk(line + pos, sizeof(line) - pos, "ch=%02u samples=", ch);
		for (unsigned int j = 0; j < TEST_ITER; j++) {
			uint8_t v = samples[j];

			pos += snprintk(line + pos, sizeof(line) - pos, " 0x%02x", v);

			if (v < min) {
				min = v;
			}
			if (v > max) {
				max = v;
			}
			sum += v;
			bits += __builtin_popcount(v);

			bool seen = false;
			for (unsigned int k = 0; k < j; k++) {
				if (samples[k] == v) {
					seen = true;
					break;
				}
			}
			if (!seen) {
				unique++;
			}
		}

		uint16_t mean_x10 = (sum * 10U + TEST_ITER / 2U) / TEST_ITER;
		uint16_t bits_x10 = (bits * 10U + TEST_ITER / 2U) / TEST_ITER;

		snprintk(line + pos, sizeof(line) - pos,
			 " | min=0x%02x max=0x%02x mean=%u.%u unique=%u/%u avg_bits=%u.%u", min,
			 max, mean_x10 / 10U, mean_x10 % 10U, unique, TEST_ITER, bits_x10 / 10U,
			 bits_x10 % 10U);

		TC_PRINT("%s\n", line);

		zassert_true(min != max || min == 0U || min == UINT8_MAX,
			     "ch=%u: all %u samples identical (0x%02x); GADC may be stuck", ch,
			     TEST_ITER, min);
	}
}

#if defined(CONFIG_ATM_ADC_CAL_RELOAD)

#define CAL_BUF_SIZE 128U /* covers any gcal layout */

ZTEST(adc_basic, test_atm_adc_reload_cal_idempotent)
{
	static uint8_t before[CAL_BUF_SIZE];
	static uint8_t merged[CAL_BUF_SIZE];
	static uint8_t replaced[CAL_BUF_SIZE];
	uint16_t before_len, merged_len, replaced_len;

	zassert_ok(atm_adc_test_get_cal(before, sizeof(before), &before_len),
		   "atm_adc_test_get_cal failed");

	atm_adc_reload_cal(false);
	zassert_ok(atm_adc_test_get_cal(merged, sizeof(merged), &merged_len),
		   "atm_adc_test_get_cal failed");

	atm_adc_reload_cal(true);
	zassert_ok(atm_adc_test_get_cal(replaced, sizeof(replaced), &replaced_len),
		   "atm_adc_test_get_cal failed");

	/* Trailing offset compensation is re-computed during measurements. */
	uint16_t cmp_len = MIN(before_len, atm_adc_test_cal_stable_len);

	zassert_equal(merged_len, before_len,
		      "atm_adc_reload_cal(false) changed the cal length: %u -> %u", before_len,
		      merged_len);
	zassert_mem_equal(merged, before, cmp_len,
			  "atm_adc_reload_cal(false) changed the cached calibration");

	zassert_equal(replaced_len, before_len,
		      "atm_adc_reload_cal(true) changed the cal length: %u -> %u", before_len,
		      replaced_len);
	zassert_mem_equal(replaced, before, cmp_len,
			  "atm_adc_reload_cal(true) changed the cached calibration");
}

#if defined(CONFIG_ATM_ADC_CAL_TEST_HOOKS)

ZTEST(adc_basic, test_atm_adc_reload_cal_refetches)
{
	static uint8_t before[CAL_BUF_SIZE];
	static uint8_t invalid[CAL_BUF_SIZE];
	static uint8_t merged[CAL_BUF_SIZE];
	static uint8_t replaced[CAL_BUF_SIZE];
	uint16_t before_len, invalid_len, merged_len, replaced_len;

	zassert_ok(atm_adc_test_get_cal(before, sizeof(before), &before_len),
		   "atm_adc_test_get_cal failed");
	if (!before_len) {
		/* No GADC_CAL tag provisioned; invalidation could not be undone. */
		ztest_test_skip();
	}

	atm_adc_test_invalidate_cal();
	int invalid_rc = atm_adc_test_get_cal(invalid, sizeof(invalid), &invalid_len);

	atm_adc_reload_cal(false);
	int merged_rc = atm_adc_test_get_cal(merged, sizeof(merged), &merged_len);

	atm_adc_test_invalidate_cal();
	atm_adc_reload_cal(true);
	int replaced_rc = atm_adc_test_get_cal(replaced, sizeof(replaced), &replaced_len);

	uint16_t cmp_len = MIN(before_len, atm_adc_test_cal_stable_len);

	zassert_ok(invalid_rc, "atm_adc_test_get_cal failed");
	zassert_ok(merged_rc, "atm_adc_test_get_cal failed");
	zassert_ok(replaced_rc, "atm_adc_test_get_cal failed");

	zassert_equal(invalid_len, 0, "invalidated cache still reports a length: %u", invalid_len);
	zassert_true(memcmp(invalid, before, cmp_len) != 0,
		     "invalidation left the cache unchanged");

	zassert_equal(merged_len, before_len,
		      "atm_adc_reload_cal(false) did not restore the cal length: %u -> %u",
		      before_len, merged_len);
	zassert_mem_equal(merged, before, cmp_len,
			  "atm_adc_reload_cal(false) did not re-read the journal");

	zassert_equal(replaced_len, before_len,
		      "atm_adc_reload_cal(true) did not restore the cal length: %u -> %u",
		      before_len, replaced_len);
	zassert_mem_equal(replaced, before, cmp_len,
			  "atm_adc_reload_cal(true) did not re-read the journal");
}

ZTEST(adc_basic, test_atm_adc_reload_cal_tag_absent)
{
	static uint8_t before[CAL_BUF_SIZE];
	static uint8_t kept[CAL_BUF_SIZE];
	static uint8_t dropped[CAL_BUF_SIZE];
	static uint8_t restored[CAL_BUF_SIZE];
	uint16_t before_len, kept_len, dropped_len, restored_len;

	zassert_ok(atm_adc_test_get_cal(before, sizeof(before), &before_len),
		   "atm_adc_test_get_cal failed");
	if (!before_len) {
		ztest_test_skip();
	}

	atm_adc_test_set_cal_missing(true);

	atm_adc_reload_cal(false);
	int kept_rc = atm_adc_test_get_cal(kept, sizeof(kept), &kept_len);

	atm_adc_reload_cal(true);
	int dropped_rc = atm_adc_test_get_cal(dropped, sizeof(dropped), &dropped_len);

	/* Restore before asserting so a failure cannot leak into later tests. */
	atm_adc_test_set_cal_missing(false);
	atm_adc_reload_cal(true);
	int restored_rc = atm_adc_test_get_cal(restored, sizeof(restored), &restored_len);

	uint16_t cmp_len = MIN(before_len, atm_adc_test_cal_stable_len);

	zassert_ok(kept_rc, "atm_adc_test_get_cal failed");
	zassert_ok(dropped_rc, "atm_adc_test_get_cal failed");
	zassert_ok(restored_rc, "atm_adc_test_get_cal failed");

	zassert_equal(kept_len, before_len,
		      "atm_adc_reload_cal(false) dropped the cal length: %u -> %u", before_len,
		      kept_len);
	zassert_mem_equal(kept, before, cmp_len,
			  "atm_adc_reload_cal(false) discarded the cached calibration");

	zassert_equal(dropped_len, 0, "atm_adc_reload_cal(true) kept the cal length: %u",
		      dropped_len);

	zassert_equal(restored_len, before_len, "cal length not restored: %u -> %u", before_len,
		      restored_len);
	zassert_mem_equal(restored, before, cmp_len, "cached calibration not restored");
}

#endif /* CONFIG_ATM_ADC_CAL_TEST_HOOKS */

#endif /* CONFIG_ATM_ADC_CAL_RELOAD */
