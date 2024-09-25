/**
 *******************************************************************************
 *
 * @file atm_aes.h
 *
 * @brief Atmosic AES driver
 *
 * Copyright (C) Atmosic 2022
 *
 *******************************************************************************
 */

#pragma once

/**
 *******************************************************************************
 * @defgroup ATM_AES AES
 * @ingroup DRIVERS
 * @brief ATM AES driver
 *
 * This module contains the necessary functions to perform AES encryption and
 * decryption.
 *
 * @{
 *******************************************************************************
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "compiler.h"

#define ATM_AES_IV_LEN_BYTES 16
#define ATM_AES_BLOCK_LEN_BYTES 16
#define ATM_AES_128_KEY_LEN_BYTES 16
#define ATM_AES_256_KEY_LEN_BYTES 32

typedef enum atm_aes_mode {
    /// AES-ECB mode
    ATM_AES_MODE_ECB,
    /// AES-CBC mode
    ATM_AES_MODE_CBC,
    /// AES-CFB mode
    ATM_AES_MODE_CFB,
    /// AES-OFB mode
    ATM_AES_MODE_OFB,
    /// AES-CTR mode
    ATM_AES_MODE_CTR,
    ATM_AES_MODE_COUNT,
} atm_aes_mode_t;

typedef enum atm_aes_key_len {
    /// 128-bit key length
    ATM_AES_KEY_LEN_128 = 0,
    // 192-bit key length is not supported
    // ATM_AES_KEY_LEN_192 = 1,
    /// 256-bit key length
    ATM_AES_KEY_LEN_256 = 2,
    ATM_AES_KEY_LEN_COUNT,
} atm_aes_key_len_t;

typedef enum atm_aes_res {
    /// Success
    ATM_AES_RES_SUCCESS,
    /// Error reading AES ID
    ATM_AES_RES_AES_ID_ERR,
    /// Error on input values
    ATM_AES_RES_INVALID_INPUT_ERR,
    /// Error in AES Engine
    ATM_AES_RES_INTERNAL_ERR,
} atm_aes_res_t;

typedef struct {
    atm_aes_mode_t mode;
    atm_aes_key_len_t key_len;
    bool encrypt;
    uint8_t const *key;
    /// initial value or initial counter. can be null for ECB mode.
    uint8_t const *iv;
} atm_aes_params_t;

/**
 * @brief Initialize AES module
 *
 * @param[in] params aes parameters
 * @return atm_aes_res_t result
 */
atm_aes_res_t atm_aes_init(atm_aes_params_t const *params);

/**
 * @brief Disable AES
 * @note this will clear the IV, KEY, and DATA_IN registers
 */
void atm_aes_disable(void);

/**
 * @brief Process more data through the AES engine
 *
 * @note len must be a multiple of 16 bytes for ECB, CBC, and CFB modes.
 *
 * @param[out] dest Pointer to write the data after processing
 * @param[in] src Pointer to the data to be processed
 * @param[in] num_bytes Length of the input data, in bytes.
 * @return atm_aes_res_t result
 */
__NONNULL(1, 2)
atm_aes_res_t atm_aes_update(uint8_t *dest, uint8_t const *src,
    size_t num_bytes);

#ifdef __cplusplus
}
#endif

///@}
