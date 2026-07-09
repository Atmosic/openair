/**
 *******************************************************************************
 *
 * @file main_atm_aes.c
 *
 * @brief PSA cipher coverage for the Atmosic AES PSA wrapper
 *
 * Adds ZTEST cases to the upstream mbedtls_psa test suite that exercise the
 * one-shot PSA cipher entry points routed through
 * __wrap_mbedtls_psa_cipher_{encrypt,decrypt} in
 * openair/modules/hal_atmosic/drivers/atm_aes/psa_aes.c and the underlying
 * atm_aes.c HW driver.
 *
 * The upstream suite already covers AES-ECB-128 encryption; these cases add
 * the decrypt path, the AES-256 key path, the CTR mode (including a
 * non-block-aligned length to drive the partial-block handling in
 * atm_aes_update), and the software-fallback path taken when the HW wrapper
 * reports PSA_ERROR_NOT_SUPPORTED (CTR with a 256-bit key).
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

/* FIPS-197 AES-128-ECB known answer: key = 00..0f, single 0x05 block. */
static const uint8_t kKey128[16] = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7,
				    0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf};
static const uint8_t kKey256[32] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a,
	0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
	0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
};

static psa_key_id_t import_aes_key(const uint8_t *key, size_t key_len, psa_algorithm_t alg)
{
	psa_key_attributes_t attr = PSA_KEY_ATTRIBUTES_INIT;
	psa_key_id_t key_id = PSA_KEY_ID_NULL;

	psa_set_key_type(&attr, PSA_KEY_TYPE_AES);
	psa_set_key_algorithm(&attr, alg);
	psa_set_key_usage_flags(&attr, PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT);

	zassert_equal(psa_import_key(&attr, key, key_len, &key_id), PSA_SUCCESS);
	return key_id;
}

/* Encrypt then decrypt and confirm the plaintext round-trips. */
static void cipher_roundtrip(psa_key_id_t key_id, psa_algorithm_t alg, const uint8_t *pt,
			     size_t pt_len)
{
	uint8_t ct[64 + PSA_CIPHER_IV_MAX_SIZE];
	uint8_t rt[64];
	size_t ct_len = 0, rt_len = 0;

	zassert_true(pt_len <= sizeof(rt));
	zassert_equal(psa_cipher_encrypt(key_id, alg, pt, pt_len, ct, sizeof(ct), &ct_len),
		      PSA_SUCCESS);
	zassert_equal(psa_cipher_decrypt(key_id, alg, ct, ct_len, rt, sizeof(rt), &rt_len),
		      PSA_SUCCESS);
	zassert_equal(rt_len, pt_len, "round-trip length mismatch");
	zassert_mem_equal(rt, pt, pt_len, "round-trip plaintext mismatch");
}

ZTEST_USER(test_mbedtls_psa, test_atm_aes_ecb128_known_answer)
{
	uint8_t in_buf[16];
	uint8_t out_buf[16] = {0};
	const uint8_t out_ref[16] = {0xea, 0x5e, 0x61, 0xae, 0x81, 0x67, 0xca, 0xa0,
				     0x58, 0x63, 0x88, 0xeb, 0x9a, 0x7c, 0xb7, 0x55};
	uint8_t dec_buf[16] = {0};
	size_t out_len = 0, dec_len = 0;

	memset(in_buf, 0x5, sizeof(in_buf));
	psa_key_id_t key_id = import_aes_key(kKey128, sizeof(kKey128), PSA_ALG_ECB_NO_PADDING);

	zassert_equal(psa_cipher_encrypt(key_id, PSA_ALG_ECB_NO_PADDING, in_buf, sizeof(in_buf),
					 out_buf, sizeof(out_buf), &out_len),
		      PSA_SUCCESS);
	zassert_equal(out_len, sizeof(out_ref));
	zassert_mem_equal(out_buf, out_ref, sizeof(out_ref));

	/* ECB decrypt one-shot input is pure ciphertext (no IV). */
	zassert_equal(psa_cipher_decrypt(key_id, PSA_ALG_ECB_NO_PADDING, out_buf, out_len, dec_buf,
					 sizeof(dec_buf), &dec_len),
		      PSA_SUCCESS);
	zassert_equal(dec_len, sizeof(in_buf));
	zassert_mem_equal(dec_buf, in_buf, sizeof(in_buf));

	zassert_equal(psa_destroy_key(key_id), PSA_SUCCESS);
}

ZTEST_USER(test_mbedtls_psa, test_atm_aes_ecb256_roundtrip)
{
	/* Two AES blocks to drive the multi-block loop in atm_aes_update. */
	uint8_t pt[32];

	for (size_t i = 0; i < sizeof(pt); i++) {
		pt[i] = (uint8_t)(i * 7 + 1);
	}
	psa_key_id_t key_id = import_aes_key(kKey256, sizeof(kKey256), PSA_ALG_ECB_NO_PADDING);
	cipher_roundtrip(key_id, PSA_ALG_ECB_NO_PADDING, pt, sizeof(pt));
	zassert_equal(psa_destroy_key(key_id), PSA_SUCCESS);
}

#ifdef CONFIG_PSA_WANT_ALG_CTR

ZTEST_USER(test_mbedtls_psa, test_atm_aes_ctr128_roundtrip)
{
	/* 20 bytes = one full block plus a 4-byte partial, exercising the
	 * partial-block handling in atm_aes_update for the HW CTR path. */
	uint8_t pt[20];

	for (size_t i = 0; i < sizeof(pt); i++) {
		pt[i] = (uint8_t)(i * 13 + 5);
	}
	psa_key_id_t key_id = import_aes_key(kKey128, sizeof(kKey128), PSA_ALG_CTR);
	cipher_roundtrip(key_id, PSA_ALG_CTR, pt, sizeof(pt));
	zassert_equal(psa_destroy_key(key_id), PSA_SUCCESS);
}

ZTEST_USER(test_mbedtls_psa, test_atm_aes_ctr256_sw_fallback)
{
	/* CTR with a 256-bit key is not supported by the HW wrapper, so the
	 * operation must fall through to the Mbed TLS software implementation
	 * and still round-trip correctly. */
	uint8_t pt[20];

	for (size_t i = 0; i < sizeof(pt); i++) {
		pt[i] = (uint8_t)(0xA0 ^ (i * 3));
	}
	psa_key_id_t key_id = import_aes_key(kKey256, sizeof(kKey256), PSA_ALG_CTR);
	cipher_roundtrip(key_id, PSA_ALG_CTR, pt, sizeof(pt));
	zassert_equal(psa_destroy_key(key_id), PSA_SUCCESS);
}

#endif /* CONFIG_PSA_WANT_ALG_CTR */
