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
#include "uart_polling.h"

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

/**
 * @brief Initialize the authentication library
 *
 * @param[in] key Uncompressed ECDSA P256 public key
 * @param[in] write_cb Write callback for responses
 *
 * @return
 */
__NONNULL_ALL
void atm_debug_auth_init(uint8_t const *key, debug_write_t write_cb);

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
