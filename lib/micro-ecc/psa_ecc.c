/**
 *******************************************************************************
 *
 * @file psa_ecc.c
 *
 * @brief PSA Crypto driver glue for the Atmosic uECC implementation
 *
 * Intercepts the built-in PSA ECDSA, ECDH and ECC keygen entry points via
 * the linker's --wrap facility. Sign / verify / key-agreement / keygen on
 * short-Weierstrass curves supported by uECC (secp192r1 / secp224r1 /
 * secp256r1 / secp256k1) are dispatched to the uECC library. By default
 * everything else (other curves, deterministic ECDSA on sign) falls through
 * to the original Mbed TLS software implementation via __real_*. With
 * CONFIG_ATM_UECC_PSA_NO_FALLBACK those cases instead return
 * PSA_ERROR_NOT_SUPPORTED, and the link omits the software backend.
 *
 * Copyright (C) Atmosic 2023-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <zephyr/kernel.h>
#include <zephyr/random/random.h>

#include <psa/crypto.h>

/*
 * uECC needs an RNG callback before uECC_sign() can be used. Provide one
 * backed by Zephyr's CSPRNG and let uECC.c install it as the default via
 * its default_RNG_defined hook (see uECC.c around line 191). uECC.c is
 * #include'd below so the macro is visible at its definition point.
 */
static int default_RNG(uint8_t *dest, unsigned size)
{
	return !sys_csrand_get(dest, size);
}
#define default_RNG_defined 1

#ifdef CONCAT
#undef CONCAT
#endif
#ifdef EMPTY
#undef EMPTY
#endif
#define uECC_OPTIMIZATION_LEVEL 4
/*
 * When this translation unit is selected for gcov instrumentation,
 * CONFIG_COVERAGE forces it to -O0 (see openair/cmake/common.cmake), which
 * provokes register-pressure failures in uECC.c's inline assembly. Keep the
 * #include'd uECC.c optimized across the coverage build; the surrounding glue
 * stays at the translation unit's default so its line coverage is accurate.
 */
#ifdef CONFIG_COVERAGE
#pragma GCC push_options
#pragma GCC optimize("Os")
#endif
#include "uECC.c"
#ifdef CONFIG_COVERAGE
#pragma GCC pop_options
#endif

/*
 * Forward declarations for the Mbed TLS software PSA ECDSA entry points and
 * their linker-wrapped aliases. The signatures match those declared in the
 * private header
 * modules/crypto/tf-psa-crypto/drivers/builtin/src/psa_crypto_ecp.h.
 *
 * Under CONFIG_ATM_UECC_PSA_NO_FALLBACK these prototypes (and the calls that
 * use them) are omitted so the link contains no reference to __real_*; the
 * original mbedtls_psa_ecdsa_* objects then become unreferenced and the
 * linker drops them along with their bignum / ecp dependencies.
 */
#ifndef CONFIG_ATM_UECC_PSA_NO_FALLBACK
psa_status_t __real_mbedtls_psa_ecdsa_sign_hash(const psa_key_attributes_t *attributes,
						const uint8_t *key_buffer, size_t key_buffer_size,
						psa_algorithm_t alg, const uint8_t *hash,
						size_t hash_length, uint8_t *signature,
						size_t signature_size, size_t *signature_length);
psa_status_t __real_mbedtls_psa_ecdsa_verify_hash(const psa_key_attributes_t *attributes,
						  const uint8_t *key_buffer, size_t key_buffer_size,
						  psa_algorithm_t alg, const uint8_t *hash,
						  size_t hash_length, const uint8_t *signature,
						  size_t signature_length);
psa_status_t __real_mbedtls_psa_key_agreement_ecdh(
	const psa_key_attributes_t *attributes, const uint8_t *key_buffer, size_t key_buffer_size,
	psa_algorithm_t alg, const uint8_t *peer_key, size_t peer_key_length,
	uint8_t *shared_secret, size_t shared_secret_size, size_t *shared_secret_length);
#endif

/*
 * In NO_FALLBACK builds, return PSA_ERROR_NOT_SUPPORTED for any case the
 * uECC path cannot handle. In default builds, delegate to the Mbed TLS
 * software entry point via the linker's __real_ alias.
 */
#ifdef CONFIG_ATM_UECC_PSA_NO_FALLBACK
#define ECDSA_SIGN_FALLBACK(...)   PSA_ERROR_NOT_SUPPORTED
#define ECDSA_VERIFY_FALLBACK(...) PSA_ERROR_NOT_SUPPORTED
#define ECDH_FALLBACK(...)         PSA_ERROR_NOT_SUPPORTED
#else
#define ECDSA_SIGN_FALLBACK(...)   __real_mbedtls_psa_ecdsa_sign_hash(__VA_ARGS__)
#define ECDSA_VERIFY_FALLBACK(...) __real_mbedtls_psa_ecdsa_verify_hash(__VA_ARGS__)
#define ECDH_FALLBACK(...)         __real_mbedtls_psa_key_agreement_ecdh(__VA_ARGS__)
#endif

/*
 * gcovr (run by twister to build the coverage report) drops any function whose
 * name begins with "__", treating it as a compiler-internal symbol; the linker
 * --wrap entry points are named __wrap_* and would be excluded from coverage.
 * Under CONFIG_COVERAGE, define each wrapper body under a single-underscore
 * name that gcovr keeps and expose the __wrap_ symbol the linker needs as an
 * alias of it.
 */
#ifdef CONFIG_COVERAGE
#define PSA_WRAP_FN(name, ...)                                                                     \
	psa_status_t __wrap_##name(__VA_ARGS__) __attribute__((alias("_wrap_" #name)));            \
	psa_status_t _wrap_##name(__VA_ARGS__)
#else
#define PSA_WRAP_FN(name, ...) psa_status_t __wrap_##name(__VA_ARGS__)
#endif

/*
 * Map a PSA (ECC family, key bit-size) pair to the matching uECC curve.
 * Returns NULL for anything uECC does not support so the caller can fall
 * through to the software path.
 */
static uECC_Curve psa_to_uecc_curve(psa_ecc_family_t family, size_t key_bits)
{
	if (family == PSA_ECC_FAMILY_SECP_R1) {
		switch (key_bits) {
#if uECC_SUPPORTS_secp192r1
		case 192:
			return uECC_secp192r1();
#endif
#if uECC_SUPPORTS_secp224r1
		case 224:
			return uECC_secp224r1();
#endif
#if uECC_SUPPORTS_secp256r1
		case 256:
			return uECC_secp256r1();
#endif
		}
	} else if (family == PSA_ECC_FAMILY_SECP_K1) {
#if uECC_SUPPORTS_secp256k1
		if (key_bits == 256) {
			return uECC_secp256k1();
		}
#endif
	}
	return NULL;
}

PSA_WRAP_FN(mbedtls_psa_ecdsa_sign_hash, const psa_key_attributes_t *attributes,
	    const uint8_t *key_buffer, size_t key_buffer_size, psa_algorithm_t alg,
	    const uint8_t *hash, size_t hash_length, uint8_t *signature, size_t signature_size,
	    size_t *signature_length)
{
	psa_key_type_t key_type = psa_get_key_type(attributes);
	size_t key_bits = psa_get_key_bits(attributes);

	/*
	 * uECC produces randomized ECDSA only. RFC 6979 deterministic ECDSA
	 * needs an HMAC-DRBG over the secret, which uECC does via a separate
	 * uECC_sign_deterministic() variant whose API does not match the
	 * single-RNG path; just let software handle it.
	 */
	if (!PSA_KEY_TYPE_IS_ECC_KEY_PAIR(key_type) || !PSA_ALG_IS_RANDOMIZED_ECDSA(alg)) {
		return ECDSA_SIGN_FALLBACK(attributes, key_buffer, key_buffer_size, alg, hash,
					   hash_length, signature, signature_size,
					   signature_length);
	}

	uECC_Curve curve = psa_to_uecc_curve(PSA_KEY_TYPE_ECC_GET_FAMILY(key_type), key_bits);
	if (!curve) {
		return ECDSA_SIGN_FALLBACK(attributes, key_buffer, key_buffer_size, alg, hash,
					   hash_length, signature, signature_size,
					   signature_length);
	}

	size_t curve_bytes = (size_t)uECC_curve_private_key_size(curve);
	/*
	 * PSA ECC private keys are stored as the raw scalar in big-endian,
	 * exactly the format uECC_sign() expects (same byte order, same
	 * length).
	 */
	if (key_buffer_size < curve_bytes || signature_size < 2 * curve_bytes) {
		return PSA_ERROR_BUFFER_TOO_SMALL;
	}

	if (!uECC_sign(key_buffer, hash, hash_length, signature, curve)) {
		return PSA_ERROR_HARDWARE_FAILURE;
	}
	*signature_length = 2 * curve_bytes;
	return PSA_SUCCESS;
}

PSA_WRAP_FN(mbedtls_psa_ecdsa_verify_hash, const psa_key_attributes_t *attributes,
	    const uint8_t *key_buffer, size_t key_buffer_size, psa_algorithm_t alg,
	    const uint8_t *hash, size_t hash_length, const uint8_t *signature,
	    size_t signature_length)
{
	psa_key_type_t key_type = psa_get_key_type(attributes);
	size_t key_bits = psa_get_key_bits(attributes);

	/*
	 * uECC_verify() does not depend on the RFC 6979 nonce, so deterministic
	 * and randomized ECDSA both verify with the same operation.
	 */
	if (!PSA_ALG_IS_ECDSA(alg)) {
		return ECDSA_VERIFY_FALLBACK(attributes, key_buffer, key_buffer_size, alg, hash,
					     hash_length, signature, signature_length);
	}

	uECC_Curve curve = psa_to_uecc_curve(PSA_KEY_TYPE_ECC_GET_FAMILY(key_type), key_bits);
	if (!curve) {
		return ECDSA_VERIFY_FALLBACK(attributes, key_buffer, key_buffer_size, alg, hash,
					     hash_length, signature, signature_length);
	}

	size_t curve_bytes = (size_t)uECC_curve_private_key_size(curve);
	if (signature_length != 2 * curve_bytes) {
		return PSA_ERROR_INVALID_SIGNATURE;
	}

	/*
	 * PSA stores ECC public keys in SEC1 uncompressed form (0x04 || X || Y);
	 * uECC wants the bare X || Y concatenation. Key pairs are stored as a
	 * raw scalar with no public part, so a verify on a key-pair input means
	 * the caller intends to derive Q on-the-fly. uECC has no
	 * private->public derivation that returns the affine point alone, so
	 * delegate that case to software.
	 */
	const uint8_t *pubkey;
	if (PSA_KEY_TYPE_IS_ECC_PUBLIC_KEY(key_type)) {
		if (key_buffer_size != 1 + 2 * curve_bytes || key_buffer[0] != 0x04) {
			return PSA_ERROR_INVALID_ARGUMENT;
		}
		pubkey = key_buffer + 1;
	} else {
		return ECDSA_VERIFY_FALLBACK(attributes, key_buffer, key_buffer_size, alg, hash,
					     hash_length, signature, signature_length);
	}

	if (!uECC_verify(pubkey, hash, hash_length, signature, curve)) {
		return PSA_ERROR_INVALID_SIGNATURE;
	}
	return PSA_SUCCESS;
}

/*
 * No wrap for mbedtls_psa_ecp_generate_key: the software path only
 * generates the random scalar via mbedtls_ecp_gen_privkey() (rejection
 * sampling against the curve order, no point arithmetic) because PSA
 * stores ECC key pairs as the bare scalar and defers Q = d*G to
 * psa_export_public_key() / psa_raw_key_agreement(). uECC_make_key()
 * always computes Q in addition, so routing keygen through it would do a
 * scalar mult per call -- and Q would still be recomputed by the software
 * load path the next time the key is used. The acceleration target for
 * keygen-then-export workflows is mbedtls_psa_ecp_export_public_key()
 * (uECC_compute_public_key()), not keygen itself.
 */

PSA_WRAP_FN(mbedtls_psa_key_agreement_ecdh, const psa_key_attributes_t *attributes,
	    const uint8_t *key_buffer, size_t key_buffer_size, psa_algorithm_t alg,
	    const uint8_t *peer_key, size_t peer_key_length, uint8_t *shared_secret,
	    size_t shared_secret_size, size_t *shared_secret_length)
{
	psa_key_type_t key_type = psa_get_key_type(attributes);
	size_t key_bits = psa_get_key_bits(attributes);

	if (!PSA_KEY_TYPE_IS_ECC_KEY_PAIR(key_type) || !PSA_ALG_IS_ECDH(alg)) {
		return ECDH_FALLBACK(attributes, key_buffer, key_buffer_size, alg, peer_key,
				     peer_key_length, shared_secret, shared_secret_size,
				     shared_secret_length);
	}

	uECC_Curve curve = psa_to_uecc_curve(PSA_KEY_TYPE_ECC_GET_FAMILY(key_type), key_bits);
	if (!curve) {
		return ECDH_FALLBACK(attributes, key_buffer, key_buffer_size, alg, peer_key,
				     peer_key_length, shared_secret, shared_secret_size,
				     shared_secret_length);
	}

	size_t curve_bytes = (size_t)uECC_curve_private_key_size(curve);
	if (key_buffer_size < curve_bytes) {
		return PSA_ERROR_INVALID_ARGUMENT;
	}
	if (peer_key_length != 1 + 2 * curve_bytes || peer_key[0] != 0x04) {
		return PSA_ERROR_INVALID_ARGUMENT;
	}
	if (shared_secret_size < curve_bytes) {
		return PSA_ERROR_BUFFER_TOO_SMALL;
	}

	if (!uECC_shared_secret(peer_key + 1, key_buffer, shared_secret, curve)) {
		return PSA_ERROR_INVALID_ARGUMENT;
	}
	*shared_secret_length = curve_bytes;
	return PSA_SUCCESS;
}

#ifdef CONFIG_ATM_UECC_PSA_NO_FALLBACK
/*
 * Lightweight replacement for mbedtls_psa_ecp_import_key. The PSA driver
 * import_key entry point normally parses the input through
 * mbedtls_psa_ecp_load_representation(), which validates the public point
 * lies on the curve via mbedtls_ecp_point_read_binary() -- dragging in the
 * entire software ecp / bignum / ecp_curves stack (~14 KB) just to copy
 * bytes whose import format already matches PSA's storage format.
 *
 * In NO_FALLBACK mode the on-curve check is intentionally skipped: a
 * malformed public key will simply yield PSA_ERROR_INVALID_SIGNATURE the
 * first time uECC_verify() is run against it, which is the only operation
 * a NO_FALLBACK build can do with such a key. Format and length are still
 * checked here so that import errors are reported up front.
 *
 * For PSA short-Weierstrass keys the encodings are:
 *   - public key:  uncompressed SEC1 (0x04 || X || Y), 1 + 2*curve_bytes
 *   - key pair:    big-endian raw scalar, curve_bytes
 * Both are 1:1 copies into the storage buffer.
 */
PSA_WRAP_FN(mbedtls_psa_ecp_import_key, const psa_key_attributes_t *attributes, const uint8_t *data,
	    size_t data_length, uint8_t *key_buffer, size_t key_buffer_size,
	    size_t *key_buffer_length, size_t *bits)
{
	psa_key_type_t key_type = psa_get_key_type(attributes);
	psa_ecc_family_t family = PSA_KEY_TYPE_ECC_GET_FAMILY(key_type);
	size_t curve_bytes;

	if (PSA_KEY_TYPE_IS_ECC_PUBLIC_KEY(key_type)) {
		if (data_length < 1 || data[0] != 0x04 || (data_length & 1) == 0) {
			return PSA_ERROR_INVALID_ARGUMENT;
		}
		curve_bytes = (data_length - 1) / 2;
	} else if (PSA_KEY_TYPE_IS_ECC_KEY_PAIR(key_type)) {
		curve_bytes = data_length;
	} else {
		return PSA_ERROR_NOT_SUPPORTED;
	}

	uECC_Curve curve = psa_to_uecc_curve(family, curve_bytes * 8);
	if (!curve || (size_t)uECC_curve_private_key_size(curve) != curve_bytes) {
		return PSA_ERROR_NOT_SUPPORTED;
	}

	if (key_buffer_size < data_length) {
		return PSA_ERROR_BUFFER_TOO_SMALL;
	}

	memcpy(key_buffer, data, data_length);
	*key_buffer_length = data_length;
	*bits = curve_bytes * 8;
	return PSA_SUCCESS;
}
#endif /* CONFIG_ATM_UECC_PSA_NO_FALLBACK */
