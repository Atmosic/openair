/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/devicetree.h>
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
