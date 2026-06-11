/**
 *******************************************************************************
 *
 * @file psa_sha256.c
 *
 * @brief PSA Crypto driver glue for Atmosic SHA256 hardware
 *
 * Intercepts the built-in PSA hash entry points via the linker's --wrap
 * facility. SHA-256 operations are dispatched to the Atmosic SHA-2 hardware;
 * other algorithms fall through to the original Mbed TLS software
 * implementation via __real_mbedtls_psa_hash_*.
 *
 * Copyright (C) Atmosic 2023-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include <stdbool.h>
#include <string.h>

#include <psa/crypto.h>

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/printk.h>

#include "atm_sha2.h"

LOG_MODULE_REGISTER(atm_sha2_psa, CONFIG_ATM_SHA2_PSA_LOG_LEVEL);

/*
 * Forward declarations for the Mbed TLS software PSA hash entry points and
 * their linker-wrapped aliases. The signatures match those declared in the
 * private header
 * modules/crypto/tf-psa-crypto/drivers/builtin/src/psa_crypto_hash.h.
 */
psa_status_t
__real_mbedtls_psa_hash_setup(mbedtls_psa_hash_operation_t *operation,
    psa_algorithm_t alg);
psa_status_t
__real_mbedtls_psa_hash_update(mbedtls_psa_hash_operation_t *operation,
    const uint8_t *input, size_t input_length);
psa_status_t
__real_mbedtls_psa_hash_finish(mbedtls_psa_hash_operation_t *operation,
    uint8_t *hash, size_t hash_size, size_t *hash_length);
psa_status_t __real_mbedtls_psa_hash_abort(
    mbedtls_psa_hash_operation_t *operation);
psa_status_t __real_mbedtls_psa_hash_clone(const mbedtls_psa_hash_operation_t
					       *source_operation,
    mbedtls_psa_hash_operation_t *target_operation);
psa_status_t __real_mbedtls_psa_hash_compute(psa_algorithm_t alg,
    const uint8_t *input, size_t input_length, uint8_t *hash, size_t hash_size,
    size_t *hash_length);

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

/*
 * PSA returns SHA-256 digests in standard SHA-256 byte order (big-endian per
 * 32-bit word). Configure the HW digest swizzle accordingly so the bytes land
 * in the output buffer in the correct order without further post-processing.
 */
static atm_sha256_params_t const sha256_params = {
    .mode = ATM_SHA256_SHA_MODE,
    .byte_endianess = ATM_SHA256_ENDIANESS_BIG,
    .digest_endianess = ATM_SHA256_ENDIANESS_BIG,
};

#if (ATM_SHA2_API == SHA_MULTI_CTXT)
/*
 * Multi-context mode: the per-operation HW state (atm_sha2_ctxt_t) does not
 * fit in the union inside mbedtls_psa_hash_operation_t, so allocate it from a
 * small static pool and reference it via the operation pointer.
 */
static struct {
    mbedtls_psa_hash_operation_t *owner;
    atm_sha2_ctxt_t ctxt;
} hw_pool[CONFIG_ATM_SHA2_HW_MAX_CONTEXTS];

static atm_sha2_ctxt_t *hw_pool_alloc(mbedtls_psa_hash_operation_t *op)
{
    for (size_t i = 0; i < CONFIG_ATM_SHA2_HW_MAX_CONTEXTS; i++) {
	if (!hw_pool[i].owner) {
	    hw_pool[i].owner = op;
	    memset(&hw_pool[i].ctxt, 0, sizeof(hw_pool[i].ctxt));
	    return &hw_pool[i].ctxt;
	}
    }
    return NULL;
}

static atm_sha2_ctxt_t *hw_pool_lookup(const mbedtls_psa_hash_operation_t *op)
{
    for (size_t i = 0; i < CONFIG_ATM_SHA2_HW_MAX_CONTEXTS; i++) {
	if (hw_pool[i].owner == op) {
	    return &hw_pool[i].ctxt;
	}
    }
    return NULL;
}

static void hw_pool_free(const mbedtls_psa_hash_operation_t *op)
{
    for (size_t i = 0; i < CONFIG_ATM_SHA2_HW_MAX_CONTEXTS; i++) {
	if (hw_pool[i].owner == op) {
	    hw_pool[i].owner = NULL;
	    memset(&hw_pool[i].ctxt, 0, sizeof(hw_pool[i].ctxt));
	    return;
	}
    }
}
#else /* SHA_SINGLE_CTXT */
/*
 * Single-context mode: only one in-flight SHA-256 operation can use the HW
 * at a time. Track ownership via a pointer so a stray second setup fails
 * cleanly rather than silently corrupting the first operation.
 *
 * Clone is unsupported by design here (cloning creates a second
 * in-flight context, which is the definition of multi-context mode);
 * see the __wrap_mbedtls_psa_hash_clone comment.
 */
static mbedtls_psa_hash_operation_t *hw_owner;

#ifdef CONFIG_ATM_SHA2_HW_VERIFY_WITH_SW
/*
 * HW/SW shadow (diagnostic). For every HW-backed PSA hash operation,
 * run a parallel SW SHA-256 through the __real_mbedtls_psa_hash_*
 * entry points and compare digests at finish. Gated by Kconfig because
 * it ruins per-op cost; intended for diagnosing HW-vs-SW divergences,
 * not normal use.
 */
static mbedtls_psa_hash_operation_t hw_shadow_sw_op;
static bool hw_shadow_active;
static unsigned int stat_shadow_mismatches;
#endif
#endif // SHA_SINGLE_CTXT

/*
 * Returns true if this operation is currently backed by the Atmosic HW.
 * Multi-part wrappers dispatch on this rather than on the operation's
 * algorithm so that operations whose setup fell back to the software
 * implementation continue to be serviced by software.
 */
static bool psa_sha256_owns(const mbedtls_psa_hash_operation_t *operation)
{
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    return hw_pool_lookup(operation);
#else
    return hw_owner == operation;
#endif
}

static psa_status_t psa_sha256_setup(mbedtls_psa_hash_operation_t *operation)
{
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    atm_sha2_ctxt_t *ctxt = hw_pool_alloc(operation);
    if (!ctxt) {
	return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
    if (atm_sha256_init_ctxt(&sha256_params, ctxt) != ATM_SHA256_RES_SUCCESS) {
	hw_pool_free(operation);
	return PSA_ERROR_HARDWARE_FAILURE;
    }
#else // SHA_MULTI_CTXT
    if (hw_owner) {
	return PSA_ERROR_INSUFFICIENT_MEMORY;
    }
    if (atm_sha256_init(&sha256_params) != ATM_SHA256_RES_SUCCESS) {
	return PSA_ERROR_HARDWARE_FAILURE;
    }
    hw_owner = operation;
#ifdef CONFIG_ATM_SHA2_HW_VERIFY_WITH_SW
    (void) __real_mbedtls_psa_hash_abort(&hw_shadow_sw_op);
    hw_shadow_active = (__real_mbedtls_psa_hash_setup(&hw_shadow_sw_op,
	    PSA_ALG_SHA_256) == PSA_SUCCESS);
#endif
#endif // SHA_MULTI_CTXT
    operation->MBEDTLS_PRIVATE(alg) = PSA_ALG_SHA_256;
    return PSA_SUCCESS;
}

static psa_status_t psa_sha256_update(mbedtls_psa_hash_operation_t *operation,
    const uint8_t *input, size_t input_length)
{
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    atm_sha2_ctxt_t *ctxt = hw_pool_lookup(operation);
    if (!ctxt) {
	return PSA_ERROR_BAD_STATE;
    }
#ifdef CONFIG_ATM_SHA2_HW_DATA_PATH_DMA
    if (atm_sha256_update_ctxt(ctxt, input, input_length) !=
	ATM_SHA256_RES_SUCCESS) {
#else
    if (atm_sha256_update_pio_ctxt(ctxt, input, input_length) !=
	ATM_SHA256_RES_SUCCESS) {
#endif
	return PSA_ERROR_HARDWARE_FAILURE;
    }
#else // SHA_MULTI_CTXT
    if (hw_owner != operation) {
	return PSA_ERROR_BAD_STATE;
    }
#ifdef CONFIG_ATM_SHA2_HW_DATA_PATH_DMA
    if (atm_sha256_update(input, input_length) != ATM_SHA256_RES_SUCCESS) {
#else
    if (atm_sha256_update_pio(input, input_length) != ATM_SHA256_RES_SUCCESS) {
#endif
	return PSA_ERROR_HARDWARE_FAILURE;
    }
#ifdef CONFIG_ATM_SHA2_HW_VERIFY_WITH_SW
    if (hw_shadow_active) {
	(void) __real_mbedtls_psa_hash_update(&hw_shadow_sw_op, input,
	    input_length);
    }
#endif
#endif // SHA_MULTI_CTXT
    return PSA_SUCCESS;
}

static psa_status_t psa_sha256_finish(mbedtls_psa_hash_operation_t *operation,
    uint8_t *hash, size_t hash_size, size_t *hash_length)
{
    if (hash_size < PSA_HASH_LENGTH(PSA_ALG_SHA_256)) {
	return PSA_ERROR_BUFFER_TOO_SMALL;
    }
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    atm_sha2_ctxt_t *ctxt = hw_pool_lookup(operation);
    if (!ctxt) {
	return PSA_ERROR_BAD_STATE;
    }
    // atm_sha256_final_ctxt() releases the clock-enable refcount taken
    // in setup on both success and failure paths, so the pool slot is
    // all that needs explicit cleanup here.
    atm_sha256_res_t final_res = atm_sha256_final_ctxt(ctxt, hash);
    hw_pool_free(operation);
    if (final_res != ATM_SHA256_RES_SUCCESS) {
	return PSA_ERROR_HARDWARE_FAILURE;
    }
#else // SHA_MULTI_CTXT
    if (hw_owner != operation) {
	return PSA_ERROR_BAD_STATE;
    }
    atm_sha256_final(hash);
    atm_sha256_disable();
    hw_owner = NULL;
#ifdef CONFIG_ATM_SHA2_HW_VERIFY_WITH_SW
    if (hw_shadow_active) {
	uint8_t sw_hash[PSA_HASH_LENGTH(PSA_ALG_SHA_256)];
	size_t sw_len = 0;
	psa_status_t sw_st = __real_mbedtls_psa_hash_finish(
	    &hw_shadow_sw_op, sw_hash, sizeof(sw_hash), &sw_len);
	if (sw_st == PSA_SUCCESS && sw_len == sizeof(sw_hash) &&
	    memcmp(hash, sw_hash, sizeof(sw_hash)) != 0) {
	    stat_shadow_mismatches++;
	    printk("atm_sha2_psa: HW/SW MISMATCH #%u op=%p\n"
		   "  HW=%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x"
		   "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x\n"
		   "  SW=%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x"
		   "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x\n",
		stat_shadow_mismatches, (void *) operation,
		hash[0],hash[1],hash[2],hash[3],hash[4],hash[5],hash[6],hash[7],
		hash[8],hash[9],hash[10],hash[11],hash[12],hash[13],hash[14],hash[15],
		hash[16],hash[17],hash[18],hash[19],hash[20],hash[21],hash[22],hash[23],
		hash[24],hash[25],hash[26],hash[27],hash[28],hash[29],hash[30],hash[31],
		sw_hash[0],sw_hash[1],sw_hash[2],sw_hash[3],sw_hash[4],sw_hash[5],sw_hash[6],sw_hash[7],
		sw_hash[8],sw_hash[9],sw_hash[10],sw_hash[11],sw_hash[12],sw_hash[13],sw_hash[14],sw_hash[15],
		sw_hash[16],sw_hash[17],sw_hash[18],sw_hash[19],sw_hash[20],sw_hash[21],sw_hash[22],sw_hash[23],
		sw_hash[24],sw_hash[25],sw_hash[26],sw_hash[27],sw_hash[28],sw_hash[29],sw_hash[30],sw_hash[31]);
	}
	hw_shadow_active = false;
    }
#endif
#endif // SHA_MULTI_CTXT
    *hash_length = PSA_HASH_LENGTH(PSA_ALG_SHA_256);
    operation->MBEDTLS_PRIVATE(alg) = 0;
    return PSA_SUCCESS;
}

static psa_status_t psa_sha256_abort(mbedtls_psa_hash_operation_t *operation)
{
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    atm_sha2_ctxt_t *ctxt = hw_pool_lookup(operation);
    if (ctxt) {
	// Balance the init_ctxt from setup (or clone). Skipping the
	// pool_free side when the slot is absent keeps abort on a
	// never-set-up or SW-fallback operation as a no-op.
	(void) atm_sha256_disable_ctxt(ctxt);
	hw_pool_free(operation);
    }
#else // SHA_MULTI_CTXT
    if (hw_owner == operation) {
	atm_sha256_disable();
	hw_owner = NULL;
    }
#ifdef CONFIG_ATM_SHA2_HW_VERIFY_WITH_SW
    if (hw_shadow_active) {
	(void) __real_mbedtls_psa_hash_abort(&hw_shadow_sw_op);
	hw_shadow_active = false;
    }
#endif
#endif // SHA_MULTI_CTXT
    operation->MBEDTLS_PRIVATE(alg) = 0;
    return PSA_SUCCESS;
}

/*
 * Synchronization for the multi-context HW backend. The hw_pool table, the
 * SHA HW engine registers, and the HAL's internal sha2_clk_en_ref refcount
 * are all shared between operations; protect them with a single mutex so an
 * in-flight wrapper call appears atomic relative to other wrapper calls.
 * Single-context mode and non-threaded builds compile the helpers to
 * no-ops, so the lock calls in the wrappers are free in those configs.
 */
#if (ATM_SHA2_API == SHA_MULTI_CTXT) && defined(CONFIG_MULTITHREADING)
static K_MUTEX_DEFINE(atm_sha2_hw_lock);
static inline void atm_sha2_lock(void)
{
    k_mutex_lock(&atm_sha2_hw_lock, K_FOREVER);
}
static inline void atm_sha2_unlock(void)
{
    k_mutex_unlock(&atm_sha2_hw_lock);
}
#else
static inline void atm_sha2_lock(void) {}
static inline void atm_sha2_unlock(void) {}
#endif

PSA_WRAP_FN(mbedtls_psa_hash_setup, mbedtls_psa_hash_operation_t *operation,
    psa_algorithm_t alg)
{
    if (alg == PSA_ALG_SHA_256) {
	if (operation->MBEDTLS_PRIVATE(alg)) {
	    return PSA_ERROR_BAD_STATE;
	}
	atm_sha2_lock();
	psa_status_t status = psa_sha256_setup(operation);
	atm_sha2_unlock();
#ifdef CONFIG_ATM_SHA2_HW_FALLBACK_ON_EXHAUSTION
	if (status == PSA_ERROR_INSUFFICIENT_MEMORY) {
	    return __real_mbedtls_psa_hash_setup(operation, alg);
	}
#endif
	return status;
    }
    return __real_mbedtls_psa_hash_setup(operation, alg);
}

PSA_WRAP_FN(mbedtls_psa_hash_update, mbedtls_psa_hash_operation_t *operation,
    const uint8_t *input, size_t input_length)
{
    atm_sha2_lock();
    if (psa_sha256_owns(operation)) {
	psa_status_t status = psa_sha256_update(operation, input, input_length);
	atm_sha2_unlock();
	return status;
    }
    atm_sha2_unlock();
    return __real_mbedtls_psa_hash_update(operation, input, input_length);
}

PSA_WRAP_FN(mbedtls_psa_hash_finish, mbedtls_psa_hash_operation_t *operation,
    uint8_t *hash, size_t hash_size, size_t *hash_length)
{
    atm_sha2_lock();
    if (psa_sha256_owns(operation)) {
	psa_status_t status = psa_sha256_finish(operation, hash, hash_size,
	    hash_length);
	atm_sha2_unlock();
	return status;
    }
    atm_sha2_unlock();
    return __real_mbedtls_psa_hash_finish(operation, hash, hash_size,
	hash_length);
}

PSA_WRAP_FN(mbedtls_psa_hash_abort, mbedtls_psa_hash_operation_t *operation)
{
    atm_sha2_lock();
    if (psa_sha256_owns(operation)) {
	psa_status_t status = psa_sha256_abort(operation);
	atm_sha2_unlock();
	return status;
    }
    atm_sha2_unlock();
    return __real_mbedtls_psa_hash_abort(operation);
}

PSA_WRAP_FN(mbedtls_psa_hash_clone,
    const mbedtls_psa_hash_operation_t *source_operation,
    mbedtls_psa_hash_operation_t *target_operation)
{
    /*
     * Cloning a hash operation creates a second in-flight context. In
     * multi-context mode we allocate a fresh pool slot for the target
     * and memcpy the source's atm_sha2_ctxt_t into it: the per-op state
     * is fully self-contained in that struct (save/restore happens
     * across HW touches), so a flat copy is sufficient. Single-context
     * mode rejects with PSA_ERROR_NOT_SUPPORTED — an application that
     * needs clone (e.g. PSA HMAC multipart, Matter
     * Hash_SHA256_stream::GetDigest, TLS handshake transcripts) must be
     * built with ATM_SHA2_API_MULTI. Operations whose setup fell back
     * to software are forwarded to the real clone.
     */
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    atm_sha2_lock();
    atm_sha2_ctxt_t *src_ctxt = hw_pool_lookup(source_operation);
    if (src_ctxt) {
	psa_status_t status;
	if (target_operation->MBEDTLS_PRIVATE(alg) != 0) {
	    status = PSA_ERROR_BAD_STATE;
	} else {
	    atm_sha2_ctxt_t *dst_ctxt = hw_pool_alloc(target_operation);
	    if (!dst_ctxt) {
		status = PSA_ERROR_INSUFFICIENT_MEMORY;
	    } else if (atm_sha256_clone_ctxt(src_ctxt, dst_ctxt) !=
		ATM_SHA256_RES_SUCCESS) {
		hw_pool_free(target_operation);
		status = PSA_ERROR_HARDWARE_FAILURE;
	    } else {
		target_operation->MBEDTLS_PRIVATE(alg) = PSA_ALG_SHA_256;
		status = PSA_SUCCESS;
	    }
	}
	atm_sha2_unlock();
	return status;
    }
    atm_sha2_unlock();
#else
    if (hw_owner == source_operation) {
	LOG_ERR("HW clone unsupported (alg=0x%08lx, src=%p)",
	    (unsigned long)source_operation->MBEDTLS_PRIVATE(alg),
	    (const void *)source_operation);
	return PSA_ERROR_NOT_SUPPORTED;
    }
#endif
    return __real_mbedtls_psa_hash_clone(source_operation, target_operation);
}

PSA_WRAP_FN(mbedtls_psa_hash_compute, psa_algorithm_t alg, const uint8_t *input,
    size_t input_length, uint8_t *hash, size_t hash_size, size_t *hash_length)
{
    if (alg == PSA_ALG_SHA_256) {
	if (hash_size < PSA_HASH_LENGTH(PSA_ALG_SHA_256)) {
	    return PSA_ERROR_BUFFER_TOO_SMALL;
	}
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
	atm_sha2_ctxt_t ctxt;
	memset(&ctxt, 0, sizeof(ctxt));
	// Hold the HW lock across the whole init/update/final sequence. The
	// stack-local ctxt isn't shared, but the SHA engine, clock refcount,
	// and pool state are; releasing between phases just churns the mutex.
	atm_sha2_lock();
	atm_sha256_res_t res = atm_sha256_init_ctxt(&sha256_params, &ctxt);
	if (res != ATM_SHA256_RES_SUCCESS) {
	    atm_sha2_unlock();
	    return PSA_ERROR_HARDWARE_FAILURE;
	}
	// atm_sha256_update_*_ctxt rejects zero-length input outright, but
	// PSA permits hashing the empty message. Skip the update call in
	// that case; final_ctxt drives sha2_load_context with input==NULL,
	// which produces the SHA-256("") digest directly.
	if (input_length != 0) {
#ifdef CONFIG_ATM_SHA2_HW_DATA_PATH_DMA
	    res = atm_sha256_update_ctxt(&ctxt, input, input_length);
#else
	    res = atm_sha256_update_pio_ctxt(&ctxt, input, input_length);
#endif
	    if (res != ATM_SHA256_RES_SUCCESS) {
		// Release the init_ctxt clock-enable refcount; final_ctxt
		// would normally do this for us but didn't run on this path.
		(void) atm_sha256_disable_ctxt(&ctxt);
		atm_sha2_unlock();
		return PSA_ERROR_HARDWARE_FAILURE;
	    }
	}
	// final_ctxt releases the clock-enable refcount itself.
	res = atm_sha256_final_ctxt(&ctxt, hash);
	atm_sha2_unlock();
	if (res != ATM_SHA256_RES_SUCCESS) {
	    return PSA_ERROR_HARDWARE_FAILURE;
	}
#else // SHA_MULTI_CTXT
	if (hw_owner) {
#ifdef CONFIG_ATM_SHA2_HW_FALLBACK_ON_EXHAUSTION
	    return __real_mbedtls_psa_hash_compute(alg, input, input_length,
		hash, hash_size, hash_length);
#else
	    return PSA_ERROR_INSUFFICIENT_MEMORY;
#endif
	}
#ifdef CONFIG_ATM_SHA2_HW_DATA_PATH_DMA
	if (atm_sha256_digest(&sha256_params, input, input_length, hash) !=
	    ATM_SHA256_RES_SUCCESS) {
#else
	if (atm_sha256_digest_pio(&sha256_params, input, input_length, hash) !=
	    ATM_SHA256_RES_SUCCESS) {
#endif
	    return PSA_ERROR_HARDWARE_FAILURE;
	}
#endif // SHA_MULTI_CTXT
	*hash_length = PSA_HASH_LENGTH(PSA_ALG_SHA_256);
	return PSA_SUCCESS;
    }
    return __real_mbedtls_psa_hash_compute(alg, input, input_length, hash,
	hash_size, hash_length);
}
