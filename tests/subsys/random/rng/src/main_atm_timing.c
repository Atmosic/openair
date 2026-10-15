/*
 * Copyright (c) 2026 Atmosic
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <inttypes.h>
#include <stdlib.h>

#include <zephyr/devicetree.h>
#include <zephyr/kernel.h>
#include <zephyr/random/random.h>
#include <zephyr/sys/time_units.h>
#include <zephyr/ztest.h>

#define ATM_SYS_CSRAND_TIMING_CALLS 200U

#if !defined(CONFIG_ENTROPY_ATM_TRNG)
#error "This timing test requires the Atmosic TRNG"
#endif
#if !DT_NODE_HAS_COMPAT(DT_CHOSEN(zephyr_entropy), atmosic_atm_trng)
#error "Zephyr's chosen entropy device must be the Atmosic TRNG"
#endif

#if defined(CONFIG_PSA_CSPRNG_GENERATOR)
#define ATM_SYS_CSRAND_GENERATOR "PSA"
#elif defined(CONFIG_HARDWARE_DEVICE_CS_GENERATOR)
#define ATM_SYS_CSRAND_GENERATOR "hardware entropy device"
#elif defined(CONFIG_CTR_DRBG_CSPRNG_GENERATOR)
#define ATM_SYS_CSRAND_GENERATOR "CTR-DRBG"
#else
#define ATM_SYS_CSRAND_GENERATOR "other"
#endif

static const size_t atm_sys_csrand_lengths[] = {4U, 8U, 16U, 32U, 64U};
static uint32_t atm_sys_csrand_latency_cycles[ATM_SYS_CSRAND_TIMING_CALLS];

static int atm_rng_compare_cycles(const void *left, const void *right)
{
	uint32_t left_cycles = *(const uint32_t *)left;
	uint32_t right_cycles = *(const uint32_t *)right;

	if (left_cycles < right_cycles) {
		return -1;
	}
	if (left_cycles > right_cycles) {
		return 1;
	}
	return 0;
}

static size_t atm_rng_percentile_index(uint32_t percentile)
{
	return (ATM_SYS_CSRAND_TIMING_CALLS * percentile + 99U) / 100U - 1U;
}

ZTEST(rng_common, test_atm_sys_csrand_get_latency_by_length)
{
	uint8_t output[64];
	size_t length_count = sizeof(atm_sys_csrand_lengths) / sizeof(atm_sys_csrand_lengths[0]);

	for (size_t length_index = 0; length_index < length_count; length_index++) {
		size_t output_size = atm_sys_csrand_lengths[length_index];
		uint32_t min_cycles = UINT32_MAX;
		uint32_t max_cycles = 0;
		uint64_t total_call_cycles = 0;

		for (uint32_t i = 0; i < ATM_SYS_CSRAND_TIMING_CALLS; i++) {
			uint32_t call_start = k_cycle_get_32();
			int ret = sys_csrand_get(output, output_size);
			uint32_t elapsed_cycles = k_cycle_get_32() - call_start;

			zassert_equal(ret, 0, "sys_csrand_get len=%u call %" PRIu32 " failed (%d)",
				      (unsigned int)output_size, i, ret);
			atm_sys_csrand_latency_cycles[i] = elapsed_cycles;
			total_call_cycles += elapsed_cycles;
			if (elapsed_cycles < min_cycles) {
				min_cycles = elapsed_cycles;
			}
			if (elapsed_cycles > max_cycles) {
				max_cycles = elapsed_cycles;
			}
		}

		uint64_t mean_cycles = total_call_cycles / ATM_SYS_CSRAND_TIMING_CALLS;

		qsort(atm_sys_csrand_latency_cycles, ATM_SYS_CSRAND_TIMING_CALLS,
		      sizeof(atm_sys_csrand_latency_cycles[0]), atm_rng_compare_cycles);
		uint64_t median_cycles =
			((uint64_t)atm_sys_csrand_latency_cycles[ATM_SYS_CSRAND_TIMING_CALLS / 2U -
								 1U] +
			 atm_sys_csrand_latency_cycles[ATM_SYS_CSRAND_TIMING_CALLS / 2U]) /
			2U;
		size_t p90_index = atm_rng_percentile_index(90U);
		size_t p95_index = atm_rng_percentile_index(95U);
		size_t p99_index = atm_rng_percentile_index(99U);
		uint32_t p90_cycles = atm_sys_csrand_latency_cycles[p90_index];
		uint32_t p95_cycles = atm_sys_csrand_latency_cycles[p95_index];
		uint32_t p99_cycles = atm_sys_csrand_latency_cycles[p99_index];

		TC_PRINT("sys_csrand_get %u x %u B (%s), latency_us: min=%" PRIu64 ", mean=%" PRIu64
			 ", median=%" PRIu64 ", p90=%" PRIu64 ", p95=%" PRIu64 ", p99=%" PRIu64
			 ", max=%" PRIu64 "\n",
			 (unsigned int)ATM_SYS_CSRAND_TIMING_CALLS, (unsigned int)output_size,
			 ATM_SYS_CSRAND_GENERATOR, k_cyc_to_us_floor64(min_cycles),
			 k_cyc_to_us_floor64(mean_cycles), k_cyc_to_us_floor64(median_cycles),
			 k_cyc_to_us_floor64(p90_cycles), k_cyc_to_us_floor64(p95_cycles),
			 k_cyc_to_us_floor64(p99_cycles), k_cyc_to_us_floor64(max_cycles));
	}
}
