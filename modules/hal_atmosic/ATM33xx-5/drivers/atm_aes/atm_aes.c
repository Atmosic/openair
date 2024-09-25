/**
 *******************************************************************************
 *
 * @file atm_aes.c
 *
 * @brief Atmosic AES driver
 *
 * Copyright (C) Atmosic 2022
 *
 *******************************************************************************
 */

#include "atm_aes.h"
#include "arch.h"
#include "at_wrpr.h"
#include "at_apb_aes_regs_core_macro.h"
#include "atm_utils_reg.h"
#ifdef SECURE_MODE
#include "key_sideload.h"
#endif

#define AES_ID 0x414553
#define BYTES_PER_WORD sizeof(uint32_t)
#define KEY_WORDS_128 (ATM_AES_128_KEY_LEN_BYTES / BYTES_PER_WORD)
#define KEY_WORDS_256 (ATM_AES_256_KEY_LEN_BYTES / BYTES_PER_WORD)
#define BLOCK_WORDS (ATM_AES_BLOCK_LEN_BYTES / BYTES_PER_WORD)

atm_aes_res_t atm_aes_init(atm_aes_params_t const *params)
{
    if (!params->key) {
	return ATM_AES_RES_INVALID_INPUT_ERR;
    }
    if (params->mode >= ATM_AES_MODE_COUNT) {
	return ATM_AES_RES_INVALID_INPUT_ERR;
    }
    if (params->key_len != ATM_AES_KEY_LEN_128 &&
	params->key_len != ATM_AES_KEY_LEN_256) {
	return ATM_AES_RES_INVALID_INPUT_ERR;
    }
    if (params->mode != ATM_AES_MODE_ECB && !params->iv) {
	return ATM_AES_RES_INVALID_INPUT_ERR;
    }
    WRPR_CTRL_SET(CMSDK_AES, WRPR_CTRL__CLK_ENABLE);
    if (CMSDK_AES->ID != AES_ID) {
	return ATM_AES_RES_AES_ID_ERR;
    }
    uint32_t ctrl = 0;
    // Note: mode and key_len are 1-hot encoded
    ctrl |= 1 << (params->mode + AES_CTRL_SHADOWED__MODE__SHIFT);
    ctrl |= 1 << (params->key_len + AES_CTRL_SHADOWED__KEY_LEN__SHIFT);
    if (!params->encrypt) {
	ctrl |= 1 << AES_CTRL_SHADOWED__OPERATION__SHIFT;
    }
    // CTRL must be written now even if we are sideloading
    CMSDK_AES->CTRL_SHADOWED = ctrl;
    CMSDK_AES->CTRL_SHADOWED = ctrl;
    // wait for idle bit in status
    while (!(CMSDK_AES->STATUS & AES_STATUS__IDLE__MASK)) {
	YIELD();
    }
    size_t const key_bytes = (params->key_len == ATM_AES_KEY_LEN_128) ?
        ATM_AES_128_KEY_LEN_BYTES : ATM_AES_256_KEY_LEN_BYTES;
#ifdef SECURE_MODE
    if (key_sideload_address_valid(params->key)) {
	if (key_sideload_slot_size_valid_aes(params->key, key_bytes)) {
	    // sideload must be complete before CTRL is written
	    ctrl |= AES_CTRL_SHADOWED__SIDELOAD__WRITE(1);

	    CMSDK_AES->SIDELOAD_CTRL =
		AES_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__WRITE(1);
	    key_sideload_slot_load(params->key);
	    CMSDK_AES->SIDELOAD_CTRL =
		AES_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__WRITE(0) |
		AES_SIDELOAD_CTRL__SIDELOAD_VAL__WRITE(1);
	    // rewrite CTRL register with sideload bit
	    CMSDK_AES->CTRL_SHADOWED = ctrl;
	    CMSDK_AES->CTRL_SHADOWED = ctrl;
	    // wait for idle bit in status
	    while (!(CMSDK_AES->STATUS & AES_STATUS__IDLE__MASK)) {
		YIELD();
	    }
	} else {
	    return ATM_AES_RES_INVALID_INPUT_ERR;
	}
    } else
#endif
    {
	uint32_t volatile *key_reg = &(CMSDK_AES->KEY_SHARE0_0);
	atm_reg_write_multiple(&(CMSDK_AES->KEY_SHARE0_0), params->key,
	    key_bytes);
	// load remaining words with 0s
	for (size_t i = key_bytes / sizeof(uint32_t); i < KEY_WORDS_256; i++) {
	    key_reg[i] = 0;
	}
	// load keyshare 1 with 0s
	key_reg = &(CMSDK_AES->KEY_SHARE1_0);
	for (size_t i = 0; i < KEY_WORDS_256; i++) {
	    key_reg[i] = 0;
	}
    }
    if (params->mode != ATM_AES_MODE_ECB) {
	atm_reg_write_multiple(&(CMSDK_AES->IV_0), params->iv,
	    ATM_AES_IV_LEN_BYTES);
    }
    return ATM_AES_RES_SUCCESS;
}

atm_aes_res_t atm_aes_update(uint8_t *dest, uint8_t const *src,
    size_t num_bytes)
{
    // for all modes that aren't CFB or CTR, input must be an exact number of
    // blocks
    if (AES_CTRL_SHADOWED__MODE__READ(CMSDK_AES->CTRL_SHADOWED) !=
	    (1 << ATM_AES_MODE_CFB) &&
	AES_CTRL_SHADOWED__MODE__READ(CMSDK_AES->CTRL_SHADOWED) !=
	    (1 << ATM_AES_MODE_CTR)) {
	if (num_bytes % ATM_AES_BLOCK_LEN_BYTES) {
	    return ATM_AES_RES_INVALID_INPUT_ERR;
	}
    }

    if (!(CMSDK_AES->STATUS & AES_STATUS__INPUT_READY__MASK)) {
	return ATM_AES_RES_INTERNAL_ERR;
    }
    // first process full blocks
    for (size_t j = 0; j < num_bytes / ATM_AES_BLOCK_LEN_BYTES; j++) {
	atm_reg_write_multiple(&(CMSDK_AES->DATA_IN_0), src,
	    ATM_AES_BLOCK_LEN_BYTES);
	src += ATM_AES_BLOCK_LEN_BYTES;
	while (!(CMSDK_AES->STATUS & AES_STATUS__OUTPUT_VALID__MASK)) {
	    YIELD();
	}
	atm_reg_read_multiple(&(CMSDK_AES->DATA_OUT_0), dest,
	    ATM_AES_BLOCK_LEN_BYTES);
	dest += ATM_AES_BLOCK_LEN_BYTES;
    }
    if (num_bytes % ATM_AES_BLOCK_LEN_BYTES) {
	// handle incomplete blocks for CTR and CFB modes
	size_t remaining_bytes = num_bytes % ATM_AES_BLOCK_LEN_BYTES;
	atm_reg_write_multiple(&(CMSDK_AES->DATA_IN_0), src, remaining_bytes);
	// write remaining words to zero, if needed
	size_t zero_words = (ATM_AES_BLOCK_LEN_BYTES - remaining_bytes) / 4;
	for (size_t i = BLOCK_WORDS - zero_words; i < BLOCK_WORDS; i++) {
	    uint32_t volatile *data_in_reg = &(CMSDK_AES->DATA_IN_0);
	    data_in_reg[i] = 0;
	}
	while (!(CMSDK_AES->STATUS & AES_STATUS__OUTPUT_VALID__MASK)) {
	    YIELD();
	}
	atm_reg_read_multiple(&(CMSDK_AES->DATA_OUT_0), dest, remaining_bytes);
	// read remaining words to leave engine in a good state
	uint32_t const volatile *data_out_reg = &(CMSDK_AES->DATA_OUT_0);
	for (size_t i = 0; i < BLOCK_WORDS; i++) {
	    data_out_reg[i];
	}
    }

    return ATM_AES_RES_SUCCESS;
}

void atm_aes_disable(void)
{
    CMSDK_AES->CTRL_SHADOWED = AES_CTRL_SHADOWED__MANUAL_OPERATION__MASK;
    CMSDK_AES->CTRL_SHADOWED = AES_CTRL_SHADOWED__MANUAL_OPERATION__MASK;
    CMSDK_AES->TRIGGER = AES_TRIGGER__KEY_IV_DATA_IN_CLEAR__MASK |
	AES_TRIGGER__DATA_OUT_CLEAR__MASK;

    // disable clocks
    WRPR_CTRL_SET(CMSDK_AES, 0);
}
