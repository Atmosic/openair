/**
 *******************************************************************************
 *
 * @file main_atm.c
 *
 * @brief PSA hash-clone coverage for the Atmosic SHA-2 PSA wrapper
 *
 * Adds ZTEST cases to the upstream mbedtls_psa test suite that exercise
 * mbedtls_psa_hash_clone routed through __wrap_mbedtls_psa_hash_clone
 * in openair/modules/hal_atmosic/drivers/atm_sha2/psa_sha256.c.
 *
 * In multi-context mode (CONFIG_ATM_SHA2_API_MULTI=y) the wrapper
 * allocates a fresh pool slot for the target and memcpys the source's
 * atm_sha2_ctxt_t. These tests confirm that the cloned operation
 * produces the same digest as the source when finished without further
 * input, and that subsequent divergent updates produce the expected
 * independent digests.
 *
 * In single-context mode the wrapper returns PSA_ERROR_NOT_SUPPORTED;
 * the tests assert that contract.
 *
 * Copyright (C) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include <string.h>

#include <zephyr/ztest.h>

#include <psa/crypto.h>

static const uint8_t kAbc[] = { 'a', 'b', 'c' };

#ifdef CONFIG_ATM_SHA2_API_MULTI
/* FIPS 180-4 SHA-256("abc") */
static const uint8_t kAbcDigest[PSA_HASH_LENGTH(PSA_ALG_SHA_256)] = {
	0xba, 0x78, 0x16, 0xbf, 0x8f, 0x01, 0xcf, 0xea, 0x41, 0x41, 0x40,
	0xde, 0x5d, 0xae, 0x22, 0x23, 0xb0, 0x03, 0x61, 0xa3, 0x96, 0x17,
	0x7a, 0x9c, 0xb4, 0x10, 0xff, 0x61, 0xf2, 0x00, 0x15, 0xad,
};

/* Compute SHA-256(msg) via the one-shot wrapper path. Used as ground
 * truth for divergence tests so we don't have to hard-code digests for
 * every input. */
static void atm_sha256(const uint8_t *msg, size_t len,
	uint8_t out[PSA_HASH_LENGTH(PSA_ALG_SHA_256)])
{
	size_t out_len = 0;
	psa_status_t s = psa_hash_compute(PSA_ALG_SHA_256, msg, len, out,
		PSA_HASH_LENGTH(PSA_ALG_SHA_256), &out_len);
	zassert_equal(s, PSA_SUCCESS, "psa_hash_compute failed (%d)", (int)s);
	zassert_equal(out_len, PSA_HASH_LENGTH(PSA_ALG_SHA_256));
}
#endif

ZTEST_USER(test_mbedtls_psa, test_atm_hash_clone_equal_digests)
{
	psa_hash_operation_t src = PSA_HASH_OPERATION_INIT;
	psa_hash_operation_t dst = PSA_HASH_OPERATION_INIT;

	zassert_equal(psa_hash_setup(&src, PSA_ALG_SHA_256), PSA_SUCCESS);
	zassert_equal(psa_hash_update(&src, kAbc, sizeof(kAbc)), PSA_SUCCESS);

	psa_status_t st = psa_hash_clone(&src, &dst);
#ifndef CONFIG_ATM_SHA2_API_MULTI
	/* Single-context mode: clone of HW source is unsupported. */
	zassert_equal(st, PSA_ERROR_NOT_SUPPORTED,
		"expected NOT_SUPPORTED, got %d", (int)st);
	zassert_equal(psa_hash_abort(&src), PSA_SUCCESS);
#else
	zassert_equal(st, PSA_SUCCESS, "clone failed (%d)", (int)st);

	uint8_t out_src[PSA_HASH_LENGTH(PSA_ALG_SHA_256)];
	uint8_t out_dst[PSA_HASH_LENGTH(PSA_ALG_SHA_256)];
	size_t len_src = 0, len_dst = 0;
	zassert_equal(psa_hash_finish(&src, out_src, sizeof(out_src), &len_src),
		PSA_SUCCESS);
	zassert_equal(psa_hash_finish(&dst, out_dst, sizeof(out_dst), &len_dst),
		PSA_SUCCESS);
	zassert_equal(len_src, sizeof(out_src));
	zassert_equal(len_dst, sizeof(out_dst));
	zassert_mem_equal(out_src, kAbcDigest, sizeof(kAbcDigest));
	zassert_mem_equal(out_dst, kAbcDigest, sizeof(kAbcDigest));
#endif
}

#ifdef CONFIG_ATM_SHA2_API_MULTI

ZTEST_USER(test_mbedtls_psa, test_atm_hash_clone_diverges_with_tails)
{
	psa_hash_operation_t src = PSA_HASH_OPERATION_INIT;
	psa_hash_operation_t dst = PSA_HASH_OPERATION_INIT;
	uint8_t out_src[PSA_HASH_LENGTH(PSA_ALG_SHA_256)];
	uint8_t out_dst[PSA_HASH_LENGTH(PSA_ALG_SHA_256)];
	size_t len_src = 0, len_dst = 0;

	/* "abc" + "d" vs "abc" + "e" — ground truth from one-shot path. */
	uint8_t expected_abcd[PSA_HASH_LENGTH(PSA_ALG_SHA_256)];
	uint8_t expected_abce[PSA_HASH_LENGTH(PSA_ALG_SHA_256)];
	atm_sha256((const uint8_t *)"abcd", 4, expected_abcd);
	atm_sha256((const uint8_t *)"abce", 4, expected_abce);

	zassert_equal(psa_hash_setup(&src, PSA_ALG_SHA_256), PSA_SUCCESS);
	zassert_equal(psa_hash_update(&src, kAbc, sizeof(kAbc)), PSA_SUCCESS);
	zassert_equal(psa_hash_clone(&src, &dst), PSA_SUCCESS);

	uint8_t tail_src = 'd', tail_dst = 'e';
	zassert_equal(psa_hash_update(&src, &tail_src, 1), PSA_SUCCESS);
	zassert_equal(psa_hash_update(&dst, &tail_dst, 1), PSA_SUCCESS);

	zassert_equal(psa_hash_finish(&src, out_src, sizeof(out_src), &len_src),
		PSA_SUCCESS);
	zassert_equal(psa_hash_finish(&dst, out_dst, sizeof(out_dst), &len_dst),
		PSA_SUCCESS);
	zassert_mem_equal(out_src, expected_abcd, sizeof(expected_abcd));
	zassert_mem_equal(out_dst, expected_abce, sizeof(expected_abce));
}

ZTEST_USER(test_mbedtls_psa, test_atm_hash_clone_preserves_partial_block)
{
	/* 70 bytes = one full 64-byte block plus a 6-byte residue. The
	 * clone must preserve the partial-block buffer alongside the
	 * intermediate digest. */
	uint8_t input[70];
	for (size_t i = 0; i < sizeof(input); i++) {
		input[i] = (uint8_t)(i * 31 + 7);
	}
	uint8_t suffix_src[8] = { 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x11, 0x22 };
	uint8_t suffix_dst[8] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xCA, 0xFE, 0xBA, 0xBE };

	uint8_t expected_src[PSA_HASH_LENGTH(PSA_ALG_SHA_256)];
	uint8_t expected_dst[PSA_HASH_LENGTH(PSA_ALG_SHA_256)];
	uint8_t concat_src[sizeof(input) + sizeof(suffix_src)];
	uint8_t concat_dst[sizeof(input) + sizeof(suffix_dst)];
	memcpy(concat_src, input, sizeof(input));
	memcpy(concat_src + sizeof(input), suffix_src, sizeof(suffix_src));
	memcpy(concat_dst, input, sizeof(input));
	memcpy(concat_dst + sizeof(input), suffix_dst, sizeof(suffix_dst));
	atm_sha256(concat_src, sizeof(concat_src), expected_src);
	atm_sha256(concat_dst, sizeof(concat_dst), expected_dst);

	psa_hash_operation_t src = PSA_HASH_OPERATION_INIT;
	psa_hash_operation_t dst = PSA_HASH_OPERATION_INIT;
	zassert_equal(psa_hash_setup(&src, PSA_ALG_SHA_256), PSA_SUCCESS);
	zassert_equal(psa_hash_update(&src, input, sizeof(input)), PSA_SUCCESS);
	zassert_equal(psa_hash_clone(&src, &dst), PSA_SUCCESS);
	zassert_equal(psa_hash_update(&src, suffix_src, sizeof(suffix_src)),
		PSA_SUCCESS);
	zassert_equal(psa_hash_update(&dst, suffix_dst, sizeof(suffix_dst)),
		PSA_SUCCESS);

	uint8_t out_src[PSA_HASH_LENGTH(PSA_ALG_SHA_256)];
	uint8_t out_dst[PSA_HASH_LENGTH(PSA_ALG_SHA_256)];
	size_t len_src = 0, len_dst = 0;
	zassert_equal(psa_hash_finish(&src, out_src, sizeof(out_src), &len_src),
		PSA_SUCCESS);
	zassert_equal(psa_hash_finish(&dst, out_dst, sizeof(out_dst), &len_dst),
		PSA_SUCCESS);
	zassert_mem_equal(out_src, expected_src, sizeof(expected_src));
	zassert_mem_equal(out_dst, expected_dst, sizeof(expected_dst));
}

ZTEST_USER(test_mbedtls_psa, test_atm_hash_clone_into_active_target_rejected)
{
	psa_hash_operation_t src = PSA_HASH_OPERATION_INIT;
	psa_hash_operation_t dst = PSA_HASH_OPERATION_INIT;

	zassert_equal(psa_hash_setup(&src, PSA_ALG_SHA_256), PSA_SUCCESS);
	zassert_equal(psa_hash_setup(&dst, PSA_ALG_SHA_256), PSA_SUCCESS);
	zassert_equal(psa_hash_clone(&src, &dst), PSA_ERROR_BAD_STATE);
	zassert_equal(psa_hash_abort(&src), PSA_SUCCESS);
	zassert_equal(psa_hash_abort(&dst), PSA_SUCCESS);
}

ZTEST_USER(test_mbedtls_psa, test_atm_hash_clone_after_finish_rejected)
{
	psa_hash_operation_t src = PSA_HASH_OPERATION_INIT;
	psa_hash_operation_t dst = PSA_HASH_OPERATION_INIT;
	uint8_t digest[PSA_HASH_LENGTH(PSA_ALG_SHA_256)];
	size_t digest_len = 0;

	zassert_equal(psa_hash_setup(&src, PSA_ALG_SHA_256), PSA_SUCCESS);
	zassert_equal(psa_hash_update(&src, kAbc, sizeof(kAbc)), PSA_SUCCESS);
	zassert_equal(psa_hash_finish(&src, digest, sizeof(digest), &digest_len),
		PSA_SUCCESS);
	/* src is now inactive; cloning from it should be rejected. */
	zassert_equal(psa_hash_clone(&src, &dst), PSA_ERROR_BAD_STATE);
}

ZTEST_USER(test_mbedtls_psa, test_atm_hash_clone_pool_exhaustion)
{
	psa_hash_operation_t ops[CONFIG_ATM_SHA2_HW_MAX_CONTEXTS];
	psa_hash_operation_t overflow = PSA_HASH_OPERATION_INIT;

	for (size_t i = 0; i < ARRAY_SIZE(ops); i++) {
		ops[i] = (psa_hash_operation_t)PSA_HASH_OPERATION_INIT;
		zassert_equal(psa_hash_setup(&ops[i], PSA_ALG_SHA_256),
			PSA_SUCCESS);
	}
	/* Pool is full; cloning into a fresh target must fail with
	 * INSUFFICIENT_MEMORY (the wrapper cannot route a HW source's
	 * state to an SW fallback target). */
	zassert_equal(psa_hash_clone(&ops[0], &overflow),
		PSA_ERROR_INSUFFICIENT_MEMORY);

	for (size_t i = 0; i < ARRAY_SIZE(ops); i++) {
		zassert_equal(psa_hash_abort(&ops[i]), PSA_SUCCESS);
	}
}

#endif /* CONFIG_ATM_SHA2_API_MULTI */
