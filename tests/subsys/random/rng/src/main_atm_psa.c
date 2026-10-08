/*
 * Copyright (c) 2026 Atmosic
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <mbedtls/platform.h>
#include <zephyr/devicetree.h>
#include <zephyr/random/random.h>
#include <zephyr/sys/atomic.h>
#include <zephyr/ztest.h>

#include <psa/crypto.h>

#if !defined(CONFIG_MBEDTLS_PSA_DRIVER_GET_ENTROPY)
#error "Mbed TLS must obtain DRBG seed entropy through Zephyr's entropy driver"
#endif
#if !defined(CONFIG_ENTROPY_NEEDS_PRNG)
#error "Atmosic TRNG must be marked as needing a PRNG"
#endif
#if !defined(CONFIG_MBEDTLS_PSA_CRYPTO_LEGACY_RNG)
#error "PSA must use its internal RNG for the Atmosic TRNG"
#endif
#if !defined(CONFIG_MBEDTLS_CTR_DRBG_C)
#error "PSA's internal RNG must use CTR-DRBG"
#endif
#if !defined(CONFIG_PSA_CSPRNG_GENERATOR)
#error "PSA must provide Zephyr's cryptographic random generator"
#endif
#if defined(CONFIG_MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG)
#error "Atmosic TRNG must seed PSA's internal CTR-DRBG"
#endif
#if !DT_NODE_HAS_COMPAT(DT_CHOSEN(zephyr_entropy), atmosic_atm_trng)
#error "Zephyr's chosen entropy device must be the Atmosic TRNG"
#endif

enum atm_rng_route_event {
	ATM_RNG_ROUTE_PSA,
	ATM_RNG_ROUTE_CTR_DRBG,
};

static atomic_t atm_psa_random_calls;
static atomic_t atm_ctr_drbg_random_calls;
static atomic_t atm_entropy_bridge_calls;
static atomic_t atm_entropy_successful_reads;
static atomic_t atm_entropy_fallback_calls;
/* Keep bridge tracking scheduler-independent; PSA can request entropy at init. */
static atomic_t atm_entropy_bridge_depth;
static bool atm_rng_trace_enabled;
static bool atm_rng_trace_overflow;
static enum atm_rng_route_event atm_rng_trace[2];
static size_t atm_rng_trace_count;

extern psa_status_t __real_psa_generate_random(uint8_t *output, size_t output_size);
extern int __real_mbedtls_ctr_drbg_random(void *p_rng, unsigned char *output, size_t output_len);
extern int __real_mbedtls_platform_get_entropy(psa_driver_get_entropy_flags_t flags,
					       size_t *estimate_bits, unsigned char *output,
					       size_t output_size);
extern void __real_z_impl_sys_rand_get(void *dst, size_t len);

static void atm_rng_trace_record(enum atm_rng_route_event event)
{
	if (!atm_rng_trace_enabled) {
		return;
	}

	if (atm_rng_trace_count < ARRAY_SIZE(atm_rng_trace)) {
		atm_rng_trace[atm_rng_trace_count++] = event;
	} else {
		atm_rng_trace_overflow = true;
	}
}

psa_status_t __wrap_psa_generate_random(uint8_t *output, size_t output_size)
{
	atomic_inc(&atm_psa_random_calls);
	atm_rng_trace_record(ATM_RNG_ROUTE_PSA);

	return __real_psa_generate_random(output, output_size);
}

int __wrap_mbedtls_ctr_drbg_random(void *p_rng, unsigned char *output, size_t output_len)
{
	atomic_inc(&atm_ctr_drbg_random_calls);
	atm_rng_trace_record(ATM_RNG_ROUTE_CTR_DRBG);

	return __real_mbedtls_ctr_drbg_random(p_rng, output, output_len);
}

int __wrap_mbedtls_platform_get_entropy(psa_driver_get_entropy_flags_t flags, size_t *estimate_bits,
					unsigned char *output, size_t output_size)
{
	atomic_val_t fallback_calls = atomic_get(&atm_entropy_fallback_calls);

	atomic_inc(&atm_entropy_bridge_calls);
	atomic_inc(&atm_entropy_bridge_depth);
	int ret = __real_mbedtls_platform_get_entropy(flags, estimate_bits, output, output_size);
	atomic_dec(&atm_entropy_bridge_depth);

	if (!ret && atomic_get(&atm_entropy_fallback_calls) == fallback_calls) {
		atomic_inc(&atm_entropy_successful_reads);
	}

	return ret;
}

void __wrap_z_impl_sys_rand_get(void *dst, size_t len)
{
	if (atomic_get(&atm_entropy_bridge_depth)) {
		atomic_inc(&atm_entropy_fallback_calls);
	}

	__real_z_impl_sys_rand_get(dst, len);
}

ZTEST(rng_common, test_atm_sys_csrand_get_psa_ctr_drbg)
{
	uint8_t output[32];
	atomic_val_t psa_calls = atomic_get(&atm_psa_random_calls);
	atomic_val_t ctr_drbg_calls = atomic_get(&atm_ctr_drbg_random_calls);
	atm_rng_trace_count = 0;
	atm_rng_trace_overflow = false;
	atm_rng_trace_enabled = true;
	int ret = sys_csrand_get(output, sizeof(output));

	atm_rng_trace_enabled = false;

	zassert_equal(ret, 0, "sys_csrand_get failed (%d)", ret);
	zassert_equal(atomic_get(&atm_psa_random_calls), psa_calls + 1,
		      "sys_csrand_get did not call psa_generate_random exactly once");
	zassert_equal(atomic_get(&atm_ctr_drbg_random_calls), ctr_drbg_calls + 1,
		      "PSA did not generate output through CTR-DRBG exactly once");
	zassert_false(atm_rng_trace_overflow, "secure-random call trace overflowed");
	zassert_equal(atm_rng_trace_count, ARRAY_SIZE(atm_rng_trace),
		      "unexpected number of secure-random routing calls");
	zassert_equal(atm_rng_trace[0], ATM_RNG_ROUTE_PSA,
		      "sys_csrand_get did not enter PSA first");
	zassert_equal(atm_rng_trace[1], ATM_RNG_ROUTE_CTR_DRBG,
		      "PSA did not route random generation through CTR-DRBG");
	zassert_true(atomic_get(&atm_entropy_bridge_calls),
		     "PSA did not request seed entropy through the Mbed TLS entropy bridge");
	zassert_true(atomic_get(&atm_entropy_successful_reads),
		     "no successful entropy-driver read was observed for DRBG seeding");
	zassert_equal(atomic_get(&atm_entropy_fallback_calls), 0,
		      "Mbed TLS entropy bridge fell back to sys_rand_get");
}
