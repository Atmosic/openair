/**
 *******************************************************************************
 *
 * @file atm_sha2.h
 *
 * @brief Atmosic SHA256 driver
 *
 * Copyright (C) Atmosic 2022-2024
 *
 *******************************************************************************
 */

#pragma once

/**
 *******************************************************************************
 * @defgroup ATM_SHA256 SHA 256
 * @ingroup DRIVERS
 * @brief ATM SHA256 driver
 *
 * This module contains the necessary functions to compute SHA256.
 *
 * @{
 *******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "compiler.h"
#define SHA_SINGLE_CTXT 1
#define SHA_MULTI_CTXT 2

// By default the single context API is available.
// Multi-context APIs have to be explicitly enabled.
#if !defined(ATM_SHA2_API)
#define ATM_SHA2_API SHA_SINGLE_CTXT
#endif

#if ((ATM_SHA2_API != SHA_SINGLE_CTXT) && (ATM_SHA2_API != SHA_MULTI_CTXT))
#error "SHA2 API supports only SHA_SINGLE_CTXT or SHA_MULTI_CTXT"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/// digest length in bytes
#define SHA256_DIG_LEN 32
/// digest length in words
#define SHA256_DIG_WORDS (SHA256_DIG_LEN / sizeof(uint32_t))
/// HMAC key length in bytes
#define HMAC_KEY_LEN 32
/// HMAC key length in words
#define HMAC_KEY_WORDS (HMAC_KEY_LEN / sizeof(uint32_t))
/// SHA256 block size in bytes
#define SHA256_BLK_SIZE_BYTES 64
/// SHA256 block size in bits (512)
#define SHA256_BLK_SIZE_BITS (SHA256_BLK_SIZE_BYTES * 8)

typedef enum {
    /// Success
    ATM_SHA256_RES_SUCCESS,
    /// Error reading SHA_ID
    ATM_SHA256_RES_SHA_ID_ERR,
    /// Error on input values
    ATM_SHA256_RES_INVALID_INPUT_ERR,
    /// Error from DMA engine
    ATM_SHA256_RES_DMA_ERR,
    /// invalid context
    ATM_SHA256_RES_INVALID_CTXT,
    /// inconsistency in context
    ATM_SHA256_RES_ERR_CTXT,
    /// Deferred processing
    ATM_SHA256_RES_DEFER_PROC,
} atm_sha256_res_t;

typedef enum {
    /// compute little endian, do not enable HW swizzle
    ATM_SHA256_ENDIANESS_LITTLE,
    /// compute big endian, enable HW swizzle
    ATM_SHA256_ENDIANESS_BIG,
} atm_sha256_endianess_t;

typedef enum {
    /// compute SHA256
    ATM_SHA256_SHA_MODE,
    /// compute HMAC
    ATM_SHA256_HMAC_MODE,
    ATM_SHA256_MAX_MODE,
} atm_sha256_mode_t;

typedef struct {
    /// sha256 or hmac mode
    atm_sha256_mode_t mode;
    /// set hw byte swizzle
    atm_sha256_endianess_t byte_endianess;
    /// set hw digest swizzle.
    atm_sha256_endianess_t digest_endianess;
    /// key if in hmac mode
    uint8_t const *key;
} atm_sha256_params_t;

#if (ATM_SHA2_API == SHA_SINGLE_CTXT)
/**
 * @brief Initialize SHA2 module
 *
 * @param[in] params parameters for initializing sha/hmac hardware
 * @return atm_sha256_res_t result
 */
__NONNULL_ALL
atm_sha256_res_t atm_sha256_init(atm_sha256_params_t const *params);


/**
 * @brief Disable SHA2
 * @note this will clear the digest registers, you must call
 * atm_sha256_final() before this function to get the output.
 * Should be called when the operation completes successfully or with an error.
 */
void atm_sha256_disable(void);

/**
 * @brief Stream more input data for an on-going SHA-256 calculation
 *
 * @note While this can be called an arbitrary amount of times, SHA256
 *       algorithm has a max data limit equal to (2^64)-1 bits. If total
 *       accumulated data exceeds that, result is unpredictable
 *
 * @note If all of data is available in a contiguous buffer in memory,
 *       use atm_sha256_digest() instead.
 *
 * @param[in] input Pointer to the data the hash shall be calculated on
 * @param[in] num_bytes Length of the input data, in bytes.
 * @return atm_sha256_res_t result
 */
__NONNULL(1)
atm_sha256_res_t atm_sha256_update(void const *input, uint32_t num_bytes);

/**
 * @brief Identical to atm_sha256_update but doesn't use dma
 *
 * @param[in] input Pointer to the data the hash shall be calculated on
 * @param[in] num_bytes Length of the input data, in bytes.
 * @return atm_sha256_res_t result
 */
__NONNULL(1)
atm_sha256_res_t atm_sha256_update_pio(void const *input,
    uint32_t num_bytes);

/**
 * @brief Get final digest
 *
 * @param[out] digest digest of SHA256 calculation
 * @return uint8_t* pointer to the first element of passed digest
 */
uint8_t *atm_sha256_final(uint8_t digest[SHA256_DIG_LEN]);

/**
 * @brief Perform SHA-256 calculation on single contiguous memory chunk using
 * DMA
 *
 * @param[in] params parameters for initializing sha/hmac hardware
 * @param[in] input Pointer to the data the hash shall be calculated on
 * @param[in] num_bytes Length of the input data, in bytes
 * @param[out] digest digest of SHA256 calculation
 * @return atm_sha256_res_t result
 */
__NONNULL(1,2)
atm_sha256_res_t atm_sha256_digest(atm_sha256_params_t const *params,
    void const *input, uint32_t num_bytes, uint8_t digest[SHA256_DIG_LEN]);

/**
 * @brief Perform SHA-256 calculation on single contiguous memory chunk using
 * PIO mode
 *
 * @param[in] params parameters for initializing sha/hmac hardware
 * @param[in] input Pointer to the data the hash shall be calculated on
 * @param[in] num_bytes Length of the input data, in bytes
 * @param[out] digest digest of SHA256 calculation
 * @return atm_sha256_res_t result
 */
atm_sha256_res_t atm_sha256_digest_pio(atm_sha256_params_t const *params,
    void const *input, uint32_t num_bytes, uint8_t digest[SHA256_DIG_LEN]);

#endif // ATM_SHA2_SINGLE_CTXT_API

#if (ATM_SHA2_API == SHA_MULTI_CTXT)

typedef struct {
    /// context init magic
    uint32_t magic;
    /// flags
    uint32_t flags;
    /// saved control value
    uint32_t control;
    /// saved total message length in bits
    uint64_t msg_len_bits;
    /// saved total message length in bytes
    uint32_t msg_len_bytes;
    /// saved progress for SHA in bits
    uint64_t sha_txcount_bits;
    /// saved progress for HMAC in bits
    uint64_t txcount_bits;
    /// saved intermediate digest
    uint32_t int_digest[SHA256_DIG_WORDS];
    /// partial block length
    uint32_t partial_len;
    /// saved partial block that needs to be replayed
    uint8_t partial_block[SHA256_BLK_SIZE_BYTES];
    /// parameters for this context
    atm_sha256_params_t const *params;
} atm_sha2_ctxt_t;

// context has started
#define SHA2_CTXT_FLAGS_STARTED (1 << 0)
// context has finalized
#define SHA2_CTXT_FLAGS_FINI (1 << 1)

/**
 * @brief Initialize SHA2 module
 *
 * @param[in] params parameters for initializing sha/hmac hardware
 * @param[out] ctxt context
 * @return atm_sha256_res_t result
 */
__NONNULL_ALL
atm_sha256_res_t atm_sha256_init_ctxt(atm_sha256_params_t const *params,
    atm_sha2_ctxt_t *ctxt);

/**
 * @brief Disable SHA2
 * @param[in,out] ctxt context
 * @return atm_sha256_res_t result
 * @note this will clear the digest registers, you must call
 * atm_sha256_final_ctxt() before this function to get the output.
 * Should be called when the operation completes successfully or with an error.
 */
__NONNULL_ALL
atm_sha256_res_t atm_sha256_disable_ctxt(atm_sha2_ctxt_t *ctxt);

/**
 * @brief Stream more input data for an on-going SHA-256 calculation
 *
 * @note While this can be called an arbitrary amount of times, SHA256
 *       algorithm has a max data limit equal to (2^64)-1 bits. If total
 *       accumulated data exceeds that, result is unpredictable
 *
 * @param[in,out] ctxt context
 * @param[in] input Pointer to the data the hash shall be calculated on
 * @param[in] num_bytes Length of the input data, in bytes.
 * @return atm_sha256_res_t result
 */
__NONNULL(1, 2)
atm_sha256_res_t atm_sha256_update_ctxt(atm_sha2_ctxt_t *ctxt,
    void const *input, uint32_t num_bytes);

/**
 * @brief Identical to atm_sha256_update but doesn't use dma
 *
 * @param[in,out] ctxt context
 * @param[in] input Pointer to the data the hash shall be calculated on
 * @param[in] num_bytes Length of the input data, in bytes.
 * @return atm_sha256_res_t result
 */
__NONNULL(1, 2)
atm_sha256_res_t atm_sha256_update_pio_ctxt(atm_sha2_ctxt_t *ctxt,
    void const *input, uint32_t num_bytes);

/**
 * @brief Get final digest
 *
 * @param[in,out] ctxt context
 * @param[out] digest digest of SHA256 calculation
 * @return atm_sha256_res_t result
 */
__NONNULL(1)
atm_sha256_res_t atm_sha256_final_ctxt(atm_sha2_ctxt_t *ctxt,
    uint8_t digest[SHA256_DIG_LEN]);

#endif // (ATM_SHA2_API == SHA_MULTI_CTXT)

#ifdef __cplusplus
}
#endif

///@}
