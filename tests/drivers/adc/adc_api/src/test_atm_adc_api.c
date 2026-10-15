/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <errno.h>
#include <string.h>

#include <zephyr/devicetree.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/util.h>
#include <zephyr/ztest.h>

#include "atm_adc.h"
#include "atm_adc_capture.h"

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

#if defined(CONFIG_ATM_ADC_CAPTURE)

/* Slowest and fastest the GADC can be driven; both are platform specific. */
#define CAPTURE_RATE_MIN_HZ ((uint32_t)CONFIG_TEST_CAPTURE_RATE_MIN_HZ)
#define CAPTURE_RATE_MAX_HZ ((uint32_t)CONFIG_TEST_CAPTURE_RATE_MAX_HZ)

#define CAPTURE_TEST_CH           test_channels[0]
#define CAPTURE_SAMPLE_TIMEOUT_MS 50U
#define CAPTURE_BURST_LEN         64U

/* What the drain has to sustain for the OPV receiver. */
#define CAPTURE_BURST_RATE_HZ ((uint32_t)CONFIG_TEST_CAPTURE_BURST_RATE_HZ)

/* Comfortably longer than the 16-deep FIFO takes to fill at any rate the
 * driver can program: 32us at the maximum, 2ms at the minimum. */
#define CAPTURE_OVERRUN_STALL_US 4000U

ZTEST(adc_basic, test_atm_adc_capture_arg_validation)
{
	struct atm_adc_capture_cfg cfg = {
		.channel = CAPTURE_TEST_CH,
		.sample_rate_hz = CAPTURE_RATE_MAX_HZ,
		.osr_sel = ATM_ADC_CAPTURE_OSR_AUTO,
	};
	int16_t buf[4];
	size_t n;

	zassert_equal(atm_adc_capture_start(NULL, NULL), -EINVAL, "NULL cfg accepted");

	struct atm_adc_capture_cfg bad = cfg;

	/* Channel 0 is VBATT on ATMx2; everywhere else it is the unused slot. */
	bad.channel = IS_ENABLED(CONFIG_ADC_ATMx2) ? UINT8_MAX : 0;
	zassert_equal(atm_adc_capture_start(&bad, NULL), -EINVAL, "invalid channel accepted");

	bad = cfg;
	bad.osr_sel = 4;
	zassert_equal(atm_adc_capture_start(&bad, NULL), -EINVAL, "osr_sel 4 accepted");

	bad = cfg;
	bad.sample_rate_hz = CAPTURE_RATE_MIN_HZ - 1U;
	zassert_equal(atm_adc_capture_start(&bad, NULL), -EINVAL, "unachievable rate accepted");

	/* No capture running yet */
	zassert_equal(atm_adc_capture_read(buf, ARRAY_SIZE(buf), &n, 0), -EPERM,
		      "read outside a capture accepted");
	zassert_equal(atm_adc_capture_stop(), -EPERM, "stop outside a capture accepted");

	zassert_ok(atm_adc_capture_start(&cfg, NULL), "capture start failed");
	zassert_equal(atm_adc_capture_start(&cfg, NULL), -EBUSY, "second capture start accepted");
	zassert_equal(atm_adc_capture_read(NULL, ARRAY_SIZE(buf), &n, 0), -EINVAL,
		      "NULL buf accepted");
	zassert_equal(atm_adc_capture_read(buf, 0, &n, 0), -EINVAL, "zero-length read accepted");
	zassert_equal(atm_adc_capture_read(buf, ARRAY_SIZE(buf), NULL, 0), -EINVAL,
		      "NULL out_n accepted");
	zassert_ok(atm_adc_capture_stop(), "capture stop failed");
}

ZTEST(adc_basic, test_atm_adc_capture_rate_selection)
{
	static const uint32_t want_hz[] = {
		CAPTURE_RATE_MAX_HZ, 250000U, 100000U, 31250U, CAPTURE_RATE_MIN_HZ,
	};

	for (size_t i = 0; i < ARRAY_SIZE(want_hz); i++) {
		struct atm_adc_capture_cfg cfg = {
			.channel = CAPTURE_TEST_CH,
			.sample_rate_hz = want_hz[i],
			.osr_sel = ATM_ADC_CAPTURE_OSR_AUTO,
		};
		uint32_t rate = 0;

		zassert_ok(atm_adc_capture_start(&cfg, &rate), "want=%u Hz: start failed",
			   want_hz[i]);
		zassert_ok(atm_adc_capture_stop(), "want=%u Hz: stop failed", want_hz[i]);

		TC_PRINT("want=%u Hz -> %u Hz\n", want_hz[i], rate);

		zassert_true(rate, "want=%u Hz: no rate reported", want_hz[i]);
		zassert_true(rate <= want_hz[i], "want=%u Hz: got %u Hz", want_hz[i], rate);
		zassert_true(rate >= CAPTURE_RATE_MIN_HZ, "want=%u Hz: got %u Hz below minimum",
			     want_hz[i], rate);
	}

	/* Every OSR_SEL must be reachable when asked for explicitly. */
	for (uint8_t osr_sel = 0; osr_sel < 4U; osr_sel++) {
		struct atm_adc_capture_cfg cfg = {
			.channel = CAPTURE_TEST_CH,
			.sample_rate_hz = CAPTURE_RATE_MAX_HZ,
			.osr_sel = osr_sel,
		};
		uint32_t rate = 0;

		zassert_ok(atm_adc_capture_start(&cfg, &rate), "osr_sel=%u: start failed", osr_sel);
		zassert_ok(atm_adc_capture_stop(), "osr_sel=%u: stop failed", osr_sel);

		TC_PRINT("osr_sel=%u -> %u Hz\n", osr_sel, rate);

		zassert_true(rate, "osr_sel=%u: no rate reported", osr_sel);
	}
}

/* Averaging exponents ATM34 accepts; each one halves the output rate. */
#define CAPTURE_AVG_NUM       8U
#define CAPTURE_AVG_TIMED_EXP 3U
#define CAPTURE_AVG_TIMED_LEN 64U

ZTEST(adc_basic, test_atm_adc_capture_averaging)
{
	struct atm_adc_capture_cfg cfg = {
		.channel = CAPTURE_TEST_CH,
		.sample_rate_hz = CAPTURE_RATE_MAX_HZ,
		.osr_sel = ATM_ADC_CAPTURE_OSR_AUTO,
		.avg_exp = CAPTURE_AVG_NUM,
	};
	uint32_t rate = 0;
	uint32_t base = 0;

	zassert_equal(atm_adc_capture_start(&cfg, NULL), -EINVAL, "avg_exp %u accepted",
		      CAPTURE_AVG_NUM);

	/* A request the unaveraged rates reach needs no averaging, so AUTO
	 * must land on the same rate as none. */
	cfg.avg_exp = 0;
	zassert_ok(atm_adc_capture_start(&cfg, &base), "avg_exp 0: start failed");
	zassert_ok(atm_adc_capture_stop(), "avg_exp 0: stop failed");
	cfg.avg_exp = ATM_ADC_CAPTURE_AVG_AUTO;
	zassert_ok(atm_adc_capture_start(&cfg, &rate), "AUTO: start failed");
	zassert_ok(atm_adc_capture_stop(), "AUTO: stop failed");
	zassert_equal(rate, base, "AUTO at %u Hz: got %u Hz, unaveraged %u Hz", CAPTURE_RATE_MAX_HZ,
		      rate, base);

	if (!IS_ENABLED(CONFIG_ADC_ATM34)) {
		/* Averaging already carries the decimation here */
		cfg.avg_exp = 1;
		zassert_equal(atm_adc_capture_start(&cfg, NULL), -EINVAL, "avg_exp 1 accepted");
		return;
	}

	for (uint8_t avg = 0; avg < CAPTURE_AVG_NUM; avg++) {
		/* Explicit: the fastest unaveraged rate divided by 2^avg */
		cfg.sample_rate_hz = CAPTURE_RATE_MAX_HZ;
		cfg.avg_exp = avg;
		zassert_ok(atm_adc_capture_start(&cfg, &rate), "avg_exp=%u: start failed", avg);
		zassert_ok(atm_adc_capture_stop(), "avg_exp=%u: stop failed", avg);
		TC_PRINT("avg_exp=%u -> %u Hz\n", avg, rate);
		zassert_equal(rate, CAPTURE_RATE_MAX_HZ >> avg, "avg_exp=%u: got %u Hz", avg, rate);

		/* AUTO: reaches below the unaveraged floor */
		cfg.sample_rate_hz = CAPTURE_RATE_MIN_HZ >> avg;
		cfg.avg_exp = ATM_ADC_CAPTURE_AVG_AUTO;
		zassert_ok(atm_adc_capture_start(&cfg, &rate), "AUTO want=%u Hz: start failed",
			   cfg.sample_rate_hz);
		zassert_ok(atm_adc_capture_stop(), "AUTO want=%u Hz: stop failed",
			   cfg.sample_rate_hz);
		TC_PRINT("AUTO want=%u Hz -> %u Hz\n", cfg.sample_rate_hz, rate);
		zassert_equal(rate, cfg.sample_rate_hz, "AUTO want=%u Hz: got %u Hz",
			      cfg.sample_rate_hz, rate);
	}

	cfg.sample_rate_hz = (CAPTURE_RATE_MIN_HZ >> (CAPTURE_AVG_NUM - 1U)) - 1U;
	zassert_equal(atm_adc_capture_start(&cfg, NULL), -EINVAL,
		      "AUTO below the averaged floor accepted");

	/* The hardware must actually divide the output rate, not just filter */
	static int16_t buf[CAPTURE_AVG_TIMED_LEN];
	size_t n = 0;

	cfg.sample_rate_hz = CAPTURE_RATE_MIN_HZ >> CAPTURE_AVG_TIMED_EXP;
	cfg.avg_exp = CAPTURE_AVG_TIMED_EXP;
	zassert_ok(atm_adc_capture_start(&cfg, &rate), "timed: start failed");
	int rc = atm_adc_capture_read(buf, 1, &n, CAPTURE_SAMPLE_TIMEOUT_MS);
	int64_t t0 = k_uptime_get();

	if (!rc) {
		rc = atm_adc_capture_read(buf, ARRAY_SIZE(buf), &n, CAPTURE_SAMPLE_TIMEOUT_MS);
	}
	int64_t dt_ms = k_uptime_get() - t0;

	zassert_ok(atm_adc_capture_stop(), "timed: stop failed");
	zassert_ok(rc, "timed: read failed (%d)", rc);
	zassert_equal(n, ARRAY_SIZE(buf), "timed: %u samples", (unsigned int)n);

	int64_t expect_ms = (int64_t)ARRAY_SIZE(buf) * 1000 / rate;

	TC_PRINT("timed: %u samples at %u Hz in %lld ms (expect %lld ms)\n", (unsigned int)n, rate,
		 dt_ms, expect_ms);
	zassert_within(dt_ms, expect_ms, (expect_ms / 5) + 2, "timed: %lld ms, expected %lld ms",
		       dt_ms, expect_ms);
}

ZTEST(adc_basic, test_atm_adc_capture_burst)
{
	for (size_t i = 0; i < ARRAY_SIZE(test_channels); i++) {
		uint8_t ch = test_channels[i];
		struct atm_adc_capture_cfg cfg = {
			.channel = ch,
			.sample_rate_hz = CAPTURE_BURST_RATE_HZ,
			.osr_sel = ATM_ADC_CAPTURE_OSR_AUTO,
		};
		static int16_t buf[CAPTURE_BURST_LEN];
		int16_t min = INT16_MAX;
		int16_t max = INT16_MIN;
		uint32_t rate = 0;
		size_t n = 0;

		zassert_ok(atm_adc_capture_start(&cfg, &rate), "ch=%u: start failed", ch);

		int rc = atm_adc_capture_read(buf, ARRAY_SIZE(buf), &n, CAPTURE_SAMPLE_TIMEOUT_MS);

		zassert_ok(atm_adc_capture_stop(), "ch=%u: stop failed", ch);

		/* -EIO here would mean the drain loop could not keep up with the
		 * converter, which is the gating question for the whole path. */
		zassert_ok(rc, "ch=%u: read failed (%d) after %zu samples", ch, rc, n);
		zassert_equal(n, ARRAY_SIZE(buf), "ch=%u: got %zu of %zu samples", ch, n,
			      ARRAY_SIZE(buf));

		for (size_t j = 0; j < n; j++) {
			min = MIN(min, buf[j]);
			max = MAX(max, buf[j]);
		}

		TC_PRINT("ch=%02u rate=%u Hz n=%zu min=%d max=%d\n", ch, rate, n, min, max);
	}
}

ZTEST(adc_basic, test_atm_adc_capture_read_nonblocking)
{
	struct atm_adc_capture_cfg cfg = {
		.channel = CAPTURE_TEST_CH,
		.sample_rate_hz = CAPTURE_RATE_MAX_HZ,
		.osr_sel = ATM_ADC_CAPTURE_OSR_AUTO,
	};
	int16_t buf[CAPTURE_BURST_LEN];
	size_t n = ARRAY_SIZE(buf);

	zassert_ok(atm_adc_capture_start(&cfg, NULL), "start failed");

	/* A zero budget drains whatever the FIFO holds without reporting a
	 * short read as an error. */
	int rc = atm_adc_capture_read(buf, ARRAY_SIZE(buf), &n, 0);

	zassert_ok(atm_adc_capture_stop(), "stop failed");

	zassert_ok(rc, "non-blocking read failed (%d)", rc);
	zassert_true(n <= ARRAY_SIZE(buf), "read reported %zu of %zu samples", n, ARRAY_SIZE(buf));

	TC_PRINT("non-blocking read drained %zu samples\n", n);
}

/* The FIFO drops samples rather than overwriting them, so a late drain loses
 * data silently unless the overrun flag is reported. Stalling long enough to
 * overrun is the only way to prove the driver surfaces it. */
ZTEST(adc_basic, test_atm_adc_capture_overrun_detected)
{
	struct atm_adc_capture_cfg cfg = {
		.channel = CAPTURE_TEST_CH,
		.sample_rate_hz = CAPTURE_RATE_MAX_HZ,
		.osr_sel = ATM_ADC_CAPTURE_OSR_AUTO,
	};
	int16_t buf[CAPTURE_BURST_LEN];
	size_t n = 0;

	zassert_ok(atm_adc_capture_start(&cfg, NULL), "start failed");
	k_busy_wait(CAPTURE_OVERRUN_STALL_US);

	int rc = atm_adc_capture_read(buf, ARRAY_SIZE(buf), &n, CAPTURE_SAMPLE_TIMEOUT_MS);

	zassert_ok(atm_adc_capture_stop(), "stop failed");
	zassert_equal(rc, -EIO, "overrun after a %u us stall not reported (rc=%d, n=%zu)",
		      CAPTURE_OVERRUN_STALL_US, rc, n);

	/* The flag is live rather than sticky, and stop() resets the block in
	 * any case, so a later capture has to come back clean. Restarted at a
	 * rate the drain is known to sustain, so only a stale flag can fail it. */
	cfg.sample_rate_hz = CAPTURE_BURST_RATE_HZ;
	zassert_ok(atm_adc_capture_start(&cfg, NULL), "restart after overrun failed");
	rc = atm_adc_capture_read(buf, ARRAY_SIZE(buf), &n, CAPTURE_SAMPLE_TIMEOUT_MS);
	zassert_ok(atm_adc_capture_stop(), "stop after restart failed");

	zassert_ok(rc, "overrun flag survived the restart (rc=%d)", rc);
}

ZTEST(adc_basic, test_atm_adc_capture_releases_lock)
{
	struct atm_adc_capture_cfg cfg = {
		.channel = CAPTURE_TEST_CH,
		.sample_rate_hz = CAPTURE_RATE_MAX_HZ,
		.osr_sel = ATM_ADC_CAPTURE_OSR_AUTO,
	};
	int16_t raw;

	zassert_ok(atm_adc_capture_start(&cfg, NULL), "start failed");
	zassert_ok(atm_adc_capture_stop(), "stop failed");

	/* Takes the same driver lock the capture held; would block forever if
	 * stop() failed to release it. */
	zassert_ok(atm_adc_test_raw_samples(CAPTURE_TEST_CH, &raw, 1),
		   "one-shot path blocked after the capture stopped");
}

#endif /* CONFIG_ATM_ADC_CAPTURE */
