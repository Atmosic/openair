/**
 ******************************************************************************
 *
 * @file atm_debug_auth.h
 *
 * @brief Secure Debug Authentication Library
 *
 * Copyright (C) Atmosic 2023-2024
 *
 ******************************************************************************
 */

#pragma once
#include <stdbool.h>
#include <stdint.h>
#include "arch.h"

/**
 * @defgroup DEBUG_AUTH Secure debug authentication
 * @ingroup ATM_SEC
 * @brief Secure debug authentication library
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    /// Authentication has succedded
    ATM_DEBUG_AUTH_RESULT_AUTHENTICATED,
    /// Command has succeeded
    ATM_DEBUG_AUTH_RESULT_OK,
    /// Command was invalid
    ATM_DEBUG_AUTH_RESULT_INVALID,
    /// Authentication not successful
    ATM_DEBUG_AUTH_RESULT_FAILURE,
    /// Internal failure
    ATM_DEBUG_AUTH_RESULT_INTERNAL_FAILURE,
} atm_debug_auth_result_t;

typedef void (*debug_write_t)(char const *, size_t);
#ifndef DEBUG_AUTH_STATIC_CHALLENGE
typedef uint32_t (*debug_trng_get_t)(void);
#endif

/**
 * @brief Initialize the authentication library
 *
 * @param[in] key Uncompressed ECDSA P256 public key
 * @param[in] write_cb Write callback for responses
 * @param[in] trng_get_cb TRNG get entropy callback
 *
 * @note if NOT using static challenge, function assumes trng is initialized.
 *
 * @return
 */
__NONNULL_ALL
void atm_debug_auth_init(uint8_t const *key, debug_write_t write_cb
#ifndef DEBUG_AUTH_STATIC_CHALLENGE
    , debug_trng_get_t trng_get_cb
#endif
);

/**
 * @brief Parse an authentication message
 *
 * @param[in] command character string command to process
 * @param[in] length size of command string
 *
 * @return Returns the result of the command
 */
__NONNULL(1)
atm_debug_auth_result_t atm_debug_auth_parse(char const *command,
    size_t length);

#ifdef __cplusplus
}
#endif

/// @}
