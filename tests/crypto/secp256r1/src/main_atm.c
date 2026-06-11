/**
 *******************************************************************************
 *
 * @file main_atm.c
 *
 * @brief ECDSA sign + verify coverage for the Atmosic uECC PSA driver
 *
 * Adds a ZTEST case to the upstream secp256r1 test suite that exercises
 * mbedtls_psa_ecdsa_sign_hash, mbedtls_psa_ecp_import_key, and
 * mbedtls_psa_ecdsa_verify_hash -- the three PSA entry points routed to
 * uECC by openair/lib/micro-ecc/psa_ecc.c. Verifies a happy-path
 * sign/export/import/verify round trip and that a single-bit tamper of
 * the signature is rejected.
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

#define ATM_HASH_LEN 32
#define ATM_SIG_LEN  64
#define ATM_PUB_LEN  65

ZTEST_USER(test_fn, test_atm_ecdsa_sign_verify)
{
	psa_status_t status;
	psa_key_attributes_t kp_attr = PSA_KEY_ATTRIBUTES_INIT;
	psa_key_attributes_t pub_attr = PSA_KEY_ATTRIBUTES_INIT;
	mbedtls_svc_key_id_t kp_id = MBEDTLS_SVC_KEY_ID_INIT;
	mbedtls_svc_key_id_t pub_id = MBEDTLS_SVC_KEY_ID_INIT;
	uint8_t hash[ATM_HASH_LEN];
	uint8_t sig[ATM_SIG_LEN];
	uint8_t pub[ATM_PUB_LEN];
	size_t sig_len;
	size_t pub_len;

	/* Deterministic "hash" so the test does not also depend on a
	 * working SHA-256 path. */
	for (size_t i = 0; i < sizeof(hash); i++) {
		hash[i] = (uint8_t)i;
	}

	psa_set_key_type(&kp_attr, PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_SECP_R1));
	psa_set_key_bits(&kp_attr, 256);
	psa_set_key_usage_flags(&kp_attr, PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_EXPORT);
	psa_set_key_algorithm(&kp_attr, PSA_ALG_ECDSA(PSA_ALG_SHA_256));

	status = psa_generate_key(&kp_attr, &kp_id);
	zassert_equal(status, PSA_SUCCESS, "psa_generate_key (%d)", status);

	status = psa_sign_hash(kp_id, PSA_ALG_ECDSA(PSA_ALG_SHA_256), hash, sizeof(hash), sig,
			       sizeof(sig), &sig_len);
	zassert_equal(status, PSA_SUCCESS, "psa_sign_hash (%d)", status);
	zassert_equal(sig_len, ATM_SIG_LEN, "sig_len %zu", sig_len);

	status = psa_export_public_key(kp_id, pub, sizeof(pub), &pub_len);
	zassert_equal(status, PSA_SUCCESS, "psa_export_public_key (%d)", status);
	zassert_equal(pub_len, ATM_PUB_LEN, "pub_len %zu", pub_len);
	zassert_equal(pub[0], 0x04, "uncompressed prefix %02x", pub[0]);

	psa_set_key_type(&pub_attr, PSA_KEY_TYPE_ECC_PUBLIC_KEY(PSA_ECC_FAMILY_SECP_R1));
	psa_set_key_usage_flags(&pub_attr, PSA_KEY_USAGE_VERIFY_HASH);
	psa_set_key_algorithm(&pub_attr, PSA_ALG_ECDSA(PSA_ALG_SHA_256));

	status = psa_import_key(&pub_attr, pub, pub_len, &pub_id);
	zassert_equal(status, PSA_SUCCESS, "psa_import_key (%d)", status);

	status = psa_verify_hash(pub_id, PSA_ALG_ECDSA(PSA_ALG_SHA_256), hash, sizeof(hash), sig,
				 sig_len);
	zassert_equal(status, PSA_SUCCESS, "psa_verify_hash (%d)", status);

	/* Tamper the signature and confirm verify rejects. */
	sig[0] ^= 0xff;
	status = psa_verify_hash(pub_id, PSA_ALG_ECDSA(PSA_ALG_SHA_256), hash, sizeof(hash), sig,
				 sig_len);
	zassert_equal(status, PSA_ERROR_INVALID_SIGNATURE, "tampered verify accepted (%d)", status);

	(void)psa_destroy_key(kp_id);
	(void)psa_destroy_key(pub_id);
}
