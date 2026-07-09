/**
 *******************************************************************************
 *
 * @file psa_aes.c
 *
 * @brief PSA Crypto driver glue for Atmosic AES hardware
 *
 * Intercepts the built-in PSA cipher one-shot entry points via the linker's
 * --wrap facility. AES-ECB (128/256) and AES-CTR (128) operations are
 * dispatched to the Atmosic AES hardware; everything else falls through to
 * the original Mbed TLS software implementation via __real_mbedtls_psa_*.
 *
 * Multi-part PSA cipher operations (encrypt_setup / set_iv / update / finish)
 * are intentionally not wrapped. The Atmosic AES block has no save/restore
 * context, so multi-part operations are best handled by the software path.
 *
 * Copyright (C) Atmosic 2023-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include <stdbool.h>
#include <stdint.h>

#include <psa/crypto.h>

#include "atm_aes.h"

/*
 * Forward declarations for the Mbed TLS software PSA cipher entry points and
 * their linker-wrapped aliases. The signatures match those declared in the
 * private header
 * modules/crypto/tf-psa-crypto/drivers/builtin/src/psa_crypto_cipher.h.
 */
psa_status_t
__real_mbedtls_psa_cipher_encrypt(const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size, psa_algorithm_t alg,
    const uint8_t *iv, size_t iv_length, const uint8_t *input,
    size_t input_length, uint8_t *output, size_t output_size,
    size_t *output_length);
psa_status_t
__real_mbedtls_psa_cipher_decrypt(const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size, psa_algorithm_t alg,
    const uint8_t *input, size_t input_length, uint8_t *output,
    size_t output_size, size_t *output_length);

/*
 * gcovr (run by twister to build the coverage report) drops any function whose
 * name begins with "__", treating it as a compiler-internal symbol; the linker
 * --wrap entry points are named __wrap_* and would be excluded from coverage.
 * Under CONFIG_COVERAGE, define each wrapper body under a single-underscore
 * name that gcovr keeps and expose the __wrap_ symbol the linker needs as an
 * alias of it.
 */
#ifdef CONFIG_COVERAGE
#define PSA_WRAP_FN(name, ...) \
    psa_status_t __wrap_##name(__VA_ARGS__) \
	__attribute__((alias("_wrap_" #name))); \
    psa_status_t _wrap_##name(__VA_ARGS__)
#else
#define PSA_WRAP_FN(name, ...) psa_status_t __wrap_##name(__VA_ARGS__)
#endif

static bool psa_aes_hw_supports(psa_key_type_t key_type, psa_algorithm_t alg,
    size_t key_bits)
{
    if (key_type != PSA_KEY_TYPE_AES) {
	return false;
    }
    if (alg == PSA_ALG_ECB_NO_PADDING) {
	return key_bits == 128 || key_bits == 256;
    }
    if (alg == PSA_ALG_CTR) {
	return key_bits == 128;
    }
    return false;
}

/*
 * Run a single HW-accelerated cipher operation. iv may be NULL for ECB; for
 * CTR it must be a 16-byte initial counter block. Returns:
 *   PSA_SUCCESS                 - HW completed the op
 *   PSA_ERROR_NOT_SUPPORTED     - inputs not handled by HW; caller should
 *                                 forward to __real_*
 *   PSA_ERROR_INSUFFICIENT_MEMORY - HW mutex contended; caller may forward
 *                                   to __real_* under
 *                                   CONFIG_ATM_AES_HW_FALLBACK_ON_EXHAUSTION
 *   other PSA errors            - hard failure, propagate to caller
 */
static psa_status_t psa_aes_hw_run(bool encrypt,
    const psa_key_attributes_t *attributes, const uint8_t *key_buffer,
    size_t key_buffer_size, psa_algorithm_t alg, const uint8_t *iv,
    size_t iv_length, const uint8_t *input, size_t input_length,
    uint8_t *output, size_t output_size, size_t *output_length)
{
    psa_key_type_t key_type = psa_get_key_type(attributes);
    size_t key_bits = psa_get_key_bits(attributes);

    if (!psa_aes_hw_supports(key_type, alg, key_bits)) {
	return PSA_ERROR_NOT_SUPPORTED;
    }
    if (key_buffer_size < (key_bits / 8)) {
	return PSA_ERROR_INVALID_ARGUMENT;
    }

    atm_aes_mode_t mode;
    size_t expected_iv_len;
    bool require_block_aligned;

    switch (alg) {
	case PSA_ALG_ECB_NO_PADDING:
	    mode = ATM_AES_MODE_ECB;
	    expected_iv_len = 0;
	    require_block_aligned = true;
	    break;
	case PSA_ALG_CTR:
	    mode = ATM_AES_MODE_CTR;
	    expected_iv_len = ATM_AES_IV_LEN_BYTES;
	    require_block_aligned = false;
	    break;
	default:
	    return PSA_ERROR_NOT_SUPPORTED;
    }

    if (iv_length != expected_iv_len) {
	return PSA_ERROR_INVALID_ARGUMENT;
    }
    if (require_block_aligned && (input_length % ATM_AES_BLOCK_LEN_BYTES)) {
	return PSA_ERROR_INVALID_ARGUMENT;
    }
    if (output_size < input_length) {
	return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    atm_aes_params_t params = {
	.mode = mode,
	.key_len =
	    (key_bits == 128) ? ATM_AES_KEY_LEN_128 : ATM_AES_KEY_LEN_256,
	.encrypt = encrypt,
	.key = key_buffer,
	.iv = (mode == ATM_AES_MODE_ECB) ? NULL : iv,
    };

    /*
     * input_length == 0 is permitted by PSA (no-op). atm_aes_op() would lock
     * the HW for nothing, so short-circuit it.
     */
    if (input_length) {
	atm_aes_res_t res = atm_aes_op(output, input, input_length, &params);
	if (res == ATM_AES_RES_INTERNAL_ERR) {
	    /* HW mutex contention or engine error during data phase. Treat
	     * as resource exhaustion so the wrapper can optionally fall back
	     * to the software implementation. */
	    return PSA_ERROR_INSUFFICIENT_MEMORY;
	}
	if (res != ATM_AES_RES_SUCCESS) {
	    return PSA_ERROR_HARDWARE_FAILURE;
	}
    }

    *output_length = input_length;
    return PSA_SUCCESS;
}

PSA_WRAP_FN(mbedtls_psa_cipher_encrypt, const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size, psa_algorithm_t alg,
    const uint8_t *iv, size_t iv_length, const uint8_t *input,
    size_t input_length, uint8_t *output, size_t output_size,
    size_t *output_length)
{
    psa_status_t status =
	psa_aes_hw_run(true, attributes, key_buffer, key_buffer_size, alg, iv,
	    iv_length, input, input_length, output, output_size, output_length);
    if (status == PSA_ERROR_NOT_SUPPORTED) {
	return __real_mbedtls_psa_cipher_encrypt(attributes, key_buffer,
	    key_buffer_size, alg, iv, iv_length, input, input_length, output,
	    output_size, output_length);
    }
#ifdef CONFIG_ATM_AES_HW_FALLBACK_ON_EXHAUSTION
    if (status == PSA_ERROR_INSUFFICIENT_MEMORY) {
	return __real_mbedtls_psa_cipher_encrypt(attributes, key_buffer,
	    key_buffer_size, alg, iv, iv_length, input, input_length, output,
	    output_size, output_length);
    }
#endif
    return status;
}

PSA_WRAP_FN(mbedtls_psa_cipher_decrypt, const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size, psa_algorithm_t alg,
    const uint8_t *input, size_t input_length, uint8_t *output,
    size_t output_size, size_t *output_length)
{
    /*
     * The decrypt entry point receives the IV prepended to the ciphertext
     * (input = iv || ciphertext). Split it off before handing the data
     * portion to the HW path. ECB has no IV, so input is pure ciphertext.
     */
    size_t iv_length;
    switch (alg) {
	case PSA_ALG_ECB_NO_PADDING:
	    iv_length = 0;
	    break;
	case PSA_ALG_CTR:
	    iv_length = ATM_AES_IV_LEN_BYTES;
	    break;
	default:
	    return __real_mbedtls_psa_cipher_decrypt(attributes, key_buffer,
		key_buffer_size, alg, input, input_length, output, output_size,
		output_length);
    }

    if (input_length < iv_length) {
	return __real_mbedtls_psa_cipher_decrypt(attributes, key_buffer,
	    key_buffer_size, alg, input, input_length, output, output_size,
	    output_length);
    }

    psa_status_t status = psa_aes_hw_run(false, attributes, key_buffer,
	key_buffer_size, alg, input, iv_length, input + iv_length,
	input_length - iv_length, output, output_size, output_length);
    if (status == PSA_ERROR_NOT_SUPPORTED) {
	return __real_mbedtls_psa_cipher_decrypt(attributes, key_buffer,
	    key_buffer_size, alg, input, input_length, output, output_size,
	    output_length);
    }
#ifdef CONFIG_ATM_AES_HW_FALLBACK_ON_EXHAUSTION
    if (status == PSA_ERROR_INSUFFICIENT_MEMORY) {
	return __real_mbedtls_psa_cipher_decrypt(attributes, key_buffer,
	    key_buffer_size, alg, input, input_length, output, output_size,
	    output_length);
    }
#endif
    return status;
}
