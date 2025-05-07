/**
 *******************************************************************************
 *
 * @file sha256_alt.h
 *
 * @brief mbedtls glue for Atmosic SHA256 driver
 *
 * Copyright (C) Atmosic 2023
 *
 *******************************************************************************
 */

#pragma once

typedef enum {
    MBEDTLS_SHA256_ALT_UNINIT = 0,
    MBEDTLS_SHA256_ALT_INIT,
    MBEDTLS_SHA256_ALT_FREE,
    MBEDTLS_SHA256_ALT_ACTIVE,
    MBEDTLS_SHA256_ALT_ABORT,
} sha256_alt_state_t;

typedef struct mbedtls_sha256_context {
    sha256_alt_state_t MBEDTLS_PRIVATE(state);
} mbedtls_sha256_context;
