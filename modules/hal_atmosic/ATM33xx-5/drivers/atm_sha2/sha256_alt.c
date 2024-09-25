/**
 *******************************************************************************
 *
 * @file sha256_alt.c
 *
 * @brief mbedtls glue for Atmosic SHA256 driver
 *
 * Copyright (C) Atmosic 2023
 *
 *******************************************************************************
 */

#include "arch.h"
#include <string.h>
#include "atm_sha2.h"

#define MBEDTLS_ALLOW_PRIVATE_ACCESS

#include "mbedtls/sha256.h"
#include "mbedtls/error.h"

static mbedtls_sha256_context *hw_ctx;

void mbedtls_sha256_init(mbedtls_sha256_context *ctx)
{
    if (hw_ctx == ctx) {
	hw_ctx = NULL;
    }

    ctx->state = MBEDTLS_SHA256_ALT_INIT;
}

void mbedtls_sha256_free(mbedtls_sha256_context *ctx)
{
    if (!ctx) {
	return;
    }

    if (hw_ctx == ctx) {
	hw_ctx = NULL;
    }

    ctx->state = MBEDTLS_SHA256_ALT_FREE;
}

int mbedtls_sha256_starts(mbedtls_sha256_context *ctx, int is224)
{
    if (is224) {
	return MBEDTLS_ERR_SHA256_BAD_INPUT_DATA;
    }

    hw_ctx = ctx;
    ctx->state = MBEDTLS_SHA256_ALT_ACTIVE;

    atm_sha256_params_t const sha256_params = {
	.mode = ATM_SHA256_SHA_MODE,
	.byte_endianess = ATM_SHA256_ENDIANESS_BIG,
	.digest_endianess = ATM_SHA256_ENDIANESS_BIG,
    };

    if (atm_sha256_init(&sha256_params) != ATM_SHA256_RES_SUCCESS) {
	return MBEDTLS_ERR_PLATFORM_HW_ACCEL_FAILED;
    }

    return 0;
}

int mbedtls_sha256_update(mbedtls_sha256_context *ctx,
    const unsigned char *input, size_t ilen)
{
    if (hw_ctx != ctx) {
	ctx->state = MBEDTLS_SHA256_ALT_ABORT;
	return MBEDTLS_ERR_ERROR_CORRUPTION_DETECTED;
    }
    if (ctx->state != MBEDTLS_SHA256_ALT_ACTIVE) {
	return MBEDTLS_ERR_ERROR_GENERIC_ERROR;
    }

    atm_sha256_res_t res = atm_sha256_update(input, ilen);
    if (res == ATM_SHA256_RES_DMA_ERR) {
	return MBEDTLS_ERR_PLATFORM_HW_ACCEL_FAILED;
    }

    return 0;
}

int mbedtls_sha256_finish(mbedtls_sha256_context *ctx, unsigned char *output)
{
    if (hw_ctx != ctx) {
	ctx->state = MBEDTLS_SHA256_ALT_ABORT;
	return MBEDTLS_ERR_ERROR_CORRUPTION_DETECTED;
    }
    if (ctx->state != MBEDTLS_SHA256_ALT_ACTIVE) {
	return MBEDTLS_ERR_ERROR_GENERIC_ERROR;
    }

    atm_sha256_final(output);

    return 0;
}
