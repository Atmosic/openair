/**
 *******************************************************************************
 *
 * @file sha256_alt.c
 *
 * @brief mbedtls glue for Atmosic SHA256 driver
 *
 * Copyright (C) Atmosic 2023-2025
 *
 *******************************************************************************
 */

#include "arch.h"
#include <string.h>
#include "atm_sha2.h"

#define MBEDTLS_ALLOW_PRIVATE_ACCESS

#include "mbedtls/sha256.h"
#include "mbedtls/error.h"

#if (ATM_SHA2_API != SHA_MULTI_CTXT)
static mbedtls_sha256_context *hw_ctx;
#endif

void mbedtls_sha256_init(mbedtls_sha256_context *ctx)
{
#if (ATM_SHA2_API != SHA_MULTI_CTXT)
    if (hw_ctx == ctx) {
	hw_ctx = NULL;
    }
#endif

    memset(ctx, 0, sizeof(mbedtls_sha256_context));
    ctx->state = MBEDTLS_SHA256_ALT_INIT;
}

void mbedtls_sha256_free(mbedtls_sha256_context *ctx)
{
    if (!ctx) {
	return;
    }

#if (ATM_SHA2_API != SHA_MULTI_CTXT)
    if (hw_ctx == ctx) {
	hw_ctx = NULL;
    }
#endif

    ctx->state = MBEDTLS_SHA256_ALT_FREE;
    memset(ctx, 0, sizeof(mbedtls_sha256_context));
}

int mbedtls_sha256_starts(mbedtls_sha256_context *ctx, int is224)
{
    atm_sha256_params_t const sha256_params = {
	.mode = ATM_SHA256_SHA_MODE,
	.byte_endianess = ATM_SHA256_ENDIANESS_BIG,
	.digest_endianess = ATM_SHA256_ENDIANESS_LITTLE,
    };

    if (is224) {
	return MBEDTLS_ERR_SHA256_BAD_INPUT_DATA;
    }

#if (ATM_SHA2_API != SHA_MULTI_CTXT)
    hw_ctx = ctx;
#endif

#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    if (atm_sha256_init_ctxt(&sha256_params, &ctx->hw_ctxt) != ATM_SHA256_RES_SUCCESS)
#else
    if (atm_sha256_init(&sha256_params) != ATM_SHA256_RES_SUCCESS)
#endif
    {
        return MBEDTLS_ERR_PLATFORM_HW_ACCEL_FAILED;
    }

    ctx->state = MBEDTLS_SHA256_ALT_ACTIVE;

    return 0;
}

int mbedtls_sha256_update(mbedtls_sha256_context *ctx,
    const unsigned char *input, size_t ilen)
{
#if (ATM_SHA2_API != SHA_MULTI_CTXT)
    if (hw_ctx != ctx) {
	ctx->state = MBEDTLS_SHA256_ALT_ABORT;
	return MBEDTLS_ERR_ERROR_CORRUPTION_DETECTED;
    }
#endif

    if (ctx->state != MBEDTLS_SHA256_ALT_ACTIVE) {
	return MBEDTLS_ERR_ERROR_GENERIC_ERROR;
    }

#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    if (atm_sha256_update_pio_ctxt(&ctx->hw_ctxt, input, ilen)
	!= ATM_SHA256_RES_SUCCESS)
#else
    if (atm_sha256_update_pio(input, ilen) != ATM_SHA256_RES_SUCCESS)
#endif
    {
        ctx->state = MBEDTLS_SHA256_ALT_ABORT;
        return MBEDTLS_ERR_PLATFORM_HW_ACCEL_FAILED;
    }

    return 0;
}

int mbedtls_sha256_finish(mbedtls_sha256_context *ctx, unsigned char *output)
{
#if (ATM_SHA2_API != SHA_MULTI_CTXT)
    if (hw_ctx != ctx) {
	ctx->state = MBEDTLS_SHA256_ALT_ABORT;
	return MBEDTLS_ERR_ERROR_CORRUPTION_DETECTED;
    }
#endif

    if (ctx->state != MBEDTLS_SHA256_ALT_ACTIVE) {
	return MBEDTLS_ERR_ERROR_GENERIC_ERROR;
    }

#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    if (atm_sha256_final_ctxt(&ctx->hw_ctxt, output) != ATM_SHA256_RES_SUCCESS) {
	ctx->state = MBEDTLS_SHA256_ALT_ABORT;
	return MBEDTLS_ERR_PLATFORM_HW_ACCEL_FAILED;
    }
#else
    atm_sha256_final(output);
#endif

    return 0;
}
