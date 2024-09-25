/**
 *******************************************************************************
 *
 * @file aes_alt.c
 *
 * @brief mbedtls glue for Atmosic AES driver
 *
 * Copyright (C) Atmosic 2023
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#endif

#include "arch.h"
#include <string.h>
#include "atm_aes.h"

#define MBEDTLS_ALLOW_PRIVATE_ACCESS

#include "mbedtls/aes.h"
#include "mbedtls/error.h"

#ifdef CONFIG_SOC_FAMILY_ATM
static K_MUTEX_DEFINE(aes_hw_mutex);
#endif

int mbedtls_aes_setkey_enc(mbedtls_aes_context *ctx, const unsigned char *key,
    unsigned int keybits)
{
    switch (keybits) {
	case 128:
	    ctx->nr = ATM_AES_KEY_LEN_128;
	    break;
	case 192:
	    return MBEDTLS_ERR_PLATFORM_FEATURE_UNSUPPORTED;
	case 256:
	    ctx->nr = ATM_AES_KEY_LEN_256;
	    break;
	default:
	    return MBEDTLS_ERR_AES_INVALID_KEY_LENGTH;
    }
    ctx->rk_offset = 0;
    memcpy(ctx->buf + ctx->rk_offset, key, keybits >> 3);
    return 0;
}

int mbedtls_aes_setkey_dec(mbedtls_aes_context *ctx, const unsigned char *key,
    unsigned int keybits)
{
    switch (keybits) {
	case 128:
	    ctx->nr = ATM_AES_KEY_LEN_128;
	    break;
	case 192:
	    return MBEDTLS_ERR_PLATFORM_FEATURE_UNSUPPORTED;
	case 256:
	    ctx->nr = ATM_AES_KEY_LEN_256;
	    break;
	default:
	    return MBEDTLS_ERR_AES_INVALID_KEY_LENGTH;
    }
    ctx->rk_offset = 0;
    memcpy(ctx->buf + ctx->rk_offset, key, keybits >> 3);
    return 0;
}

int mbedtls_internal_aes_encrypt(mbedtls_aes_context *ctx,
    const unsigned char input[16], unsigned char output[16])
{
    atm_aes_params_t params = {
	.mode = ATM_AES_MODE_ECB,
	.key_len = ctx->nr,
	.encrypt = true,
	.key = (uint8_t *)(ctx->buf + ctx->rk_offset),
    };

#ifdef CONFIG_SOC_FAMILY_ATM
    if (k_mutex_lock(&aes_hw_mutex, K_MSEC(100))) {
	return MBEDTLS_ERR_PLATFORM_HW_ACCEL_FAILED;
    }
#endif

    atm_aes_res_t res = atm_aes_init(&params);
    if (res != ATM_AES_RES_SUCCESS) {
#ifdef CONFIG_SOC_FAMILY_ATM
	k_mutex_unlock(&aes_hw_mutex);
#endif
	return MBEDTLS_ERR_PLATFORM_HW_ACCEL_FAILED;
    }

    res = atm_aes_update(output, input, 16);
#ifdef CONFIG_SOC_FAMILY_ATM
    k_mutex_unlock(&aes_hw_mutex);
#endif
    if (res != ATM_AES_RES_SUCCESS) {
	return MBEDTLS_ERR_PLATFORM_HW_ACCEL_FAILED;
    }

    return 0;
}

int mbedtls_internal_aes_decrypt(mbedtls_aes_context *ctx,
    const unsigned char input[16], unsigned char output[16])
{
    atm_aes_params_t params = {
	.mode = ATM_AES_MODE_ECB,
	.key_len = ctx->nr,
	.encrypt = false,
	.key = (uint8_t *)(ctx->buf + ctx->rk_offset),
    };

#ifdef CONFIG_SOC_FAMILY_ATM
    if (k_mutex_lock(&aes_hw_mutex, K_MSEC(100))) {
	return MBEDTLS_ERR_PLATFORM_HW_ACCEL_FAILED;
    }
#endif

    atm_aes_res_t res = atm_aes_init(&params);
    if (res != ATM_AES_RES_SUCCESS) {
#ifdef CONFIG_SOC_FAMILY_ATM
	k_mutex_unlock(&aes_hw_mutex);
#endif
	return MBEDTLS_ERR_PLATFORM_HW_ACCEL_FAILED;
    }

    res = atm_aes_update(output, input, 16);
#ifdef CONFIG_SOC_FAMILY_ATM
    k_mutex_unlock(&aes_hw_mutex);
#endif
    if (res != ATM_AES_RES_SUCCESS) {
	return MBEDTLS_ERR_PLATFORM_HW_ACCEL_FAILED;
    }

    return 0;
}
