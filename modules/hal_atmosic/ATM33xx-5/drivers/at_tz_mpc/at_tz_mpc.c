/**
 *******************************************************************************
 *
 * @file at_tz_mpc.c
 *
 * @brief Memory Protection Controller (MPC) driver
 *
 * Copyright (C) Atmosic 2022-2024
 *
 *******************************************************************************
 */

#include "arch.h"
#include <inttypes.h>
#include "at_tz_mpc.h"

// Strip off IDAU bit to get physical address
#define GET_PHYS_ADDR(addr) ((addr) & ~0x10000000)
// Physical flash base address
#define PHYS_FLASH_BASE GET_PHYS_ADDR(CMSDK_FLASH_BASE)
// Physical RAM base address
#define PHYS_SRAM_BASE GET_PHYS_ADDR(CMSDK_SRAM_BASE)
// Base address for external flash
#define PHYS_EXT_FLASH_BASE CMSDK_EXT_FLASH_NONSECURE_BASE
// MPC only covers lower 128K of ext flash
#define AT_TZ_MPC_EXT_FLASH_LIMIT (PHYS_EXT_FLASH_BASE + AT_TZ_MPC_EXT_FLASH_MPC_SIZE)

// Normalize address to an offset from base (by type)
#define NORMALIZE_ADDR(addr, type) ((addr) - \
    (((type) == AT_TZ_MPC_DEV_FLASH) ? PHYS_FLASH_BASE : PHYS_SRAM_BASE))

// MPC_FLS->BLK_MAX is incorrect. correct value is 34 due to size constraints
#define MAX_MPC_FLS_LUT_IDX 34
#define BLOCKS_PER_MPC(type) (1 + \
    (((type) == AT_TZ_MPC_DEV_RAM) ? MPC_RAM0->BLK_MAX : MAX_MPC_FLS_LUT_IDX))

#define LUT_IDX_FROM_BLOCK(block, type) ((block) % BLOCKS_PER_MPC(type))

/*
 * The flash mpc covers an address range that is a superset of
 * valid addresses, only allow MPC control if in following range:
 *  - ROM+RRAM (0x00000 - 0x90000)
 *  - RRAM control registers (0x90000 - 0x90800)
 *  - AT_PRRF registers (0x1FF800 - 0x200000)
 *  - External flash (0x200000 - 0x220000)
 *
 * The RAM mpc simply covers the entire RAM range
 */
static at_tz_mpc_id_t at_tz_mpc_dev_from_addr(uint32_t phys_address)
{
    if (((phys_address >= PHYS_FLASH_BASE) &&
	(phys_address < PHYS_FLASH_BASE + ROM_RRAM_SIZE +
	    at_tz_mpc_get_block_size(AT_TZ_MPC_DEV_FLASH))) ||
	((phys_address >= PHYS_EXT_FLASH_BASE -
	    at_tz_mpc_get_block_size(AT_TZ_MPC_DEV_FLASH)) &&
	(phys_address < AT_TZ_MPC_EXT_FLASH_LIMIT))) {
	return AT_TZ_MPC_DEV_FLASH;
    } else if ((phys_address >= PHYS_SRAM_BASE) &&
	(phys_address < PHYS_SRAM_BASE + RAM_SIZE)) {
	return AT_TZ_MPC_DEV_RAM;
    }
    return AT_TZ_MPC_DEV_INVALID;
}

static at_tz_mpc_ret_t at_tz_mpc_from_block_word(uint32_t block_word,
    at_tz_mpc_id_t mpc_type, MPC_TypeDef **current_mpc,
    uint32_t *mpc_ctrl_restore)
{
    if (mpc_type == AT_TZ_MPC_DEV_FLASH) {
	*current_mpc = MPC_FLS;
	return AT_TZ_MPC_RET_OK;
    }
    // Assumes all RAM MPCs have the same number of blocks
    uint32_t mpc_idx = block_word / BLOCKS_PER_MPC(mpc_type);
    MPC_TypeDef *new_mpc = NULL;
    switch (mpc_idx) {
	case 0:
	    new_mpc = MPC_RAM0;
	    break;
	case 1:
	    new_mpc = MPC_RAM1;
	    break;
	case 2:
	    new_mpc = MPC_RAM2;
	    break;
	case 3:
	    new_mpc = MPC_RAM3;
	    break;
	default:
	    return AT_TZ_MPC_RET_BLK_IDX_TOO_HIGH;
    }
    // Crossed a boundary to a new mpc. Need to restore ctrl register
    // and save a new ctrl register
    if (mpc_ctrl_restore && (new_mpc != *current_mpc)) {
	(*current_mpc)->CTRL = *mpc_ctrl_restore;
	*mpc_ctrl_restore = new_mpc->CTRL;
	new_mpc->CTRL &= ~MPC_CTRL_AUTO_INCREMENT_Msk;
    }
    *current_mpc = new_mpc;
    return AT_TZ_MPC_RET_OK;
}

static at_tz_mpc_ret_t at_tz_mpc_check_bound(uint32_t limit_word,
    at_tz_mpc_id_t mpc_start_type)
{
    if (mpc_start_type == AT_TZ_MPC_DEV_FLASH) {
	if (limit_word < MAX_MPC_FLS_LUT_IDX) {
	    return AT_TZ_MPC_RET_OK;
	}
	return AT_TZ_MPC_RET_BLK_IDX_TOO_HIGH;
    }
    if (mpc_start_type == AT_TZ_MPC_DEV_RAM) {
	// Assumes that all MPC_RAM[0-3] have the same block count and size
	if (limit_word < ((MPC_RAM0->BLK_MAX + 1) * 4)) {
	    return AT_TZ_MPC_RET_OK;
	}
	return AT_TZ_MPC_RET_BLK_IDX_TOO_HIGH;
    }
    return AT_TZ_MPC_RET_INVALID_TYPE;
}

at_tz_mpc_ret_t at_tz_mpc_config_region(uint32_t base, uint32_t limit,
    at_tz_mpc_attr_t attr)
{
    uint32_t phys_base = GET_PHYS_ADDR(base);
    uint32_t phys_limit = GET_PHYS_ADDR(limit);

    if (phys_limit <= phys_base) {
	return AT_TZ_MPC_RET_BAD_BOUNDS;
    }
    // if address range is in flash, it will only use one MPC to cover range,
    // if address range is in RAM, 4 MPCs are used to cover entire range
    at_tz_mpc_id_t mpc_start_type = at_tz_mpc_dev_from_addr(phys_base);

    if (mpc_start_type == AT_TZ_MPC_DEV_INVALID) {
	// base address not covered by MPC
	return AT_TZ_MPC_RET_BAD_BOUNDS;
    }
    at_tz_mpc_id_t mpc_end_type = at_tz_mpc_dev_from_addr(phys_limit);
    if (mpc_start_type != mpc_end_type) {
	// limit address not covered by MPC or base and limit exist in
	// different MPC types
	return AT_TZ_MPC_RET_BAD_BOUNDS;
    }
    uint32_t block_size = at_tz_mpc_get_block_size(mpc_start_type);

    // this assumes all MPCs for RAM have the same block size
    if (phys_base & (block_size - 1)) {
	return AT_TZ_MPC_RET_BAD_BOUNDS;
    }
    // limit is inclusive, so it must be just before block size boundary
    if ((phys_limit + 1) & (block_size - 1)) {
	return AT_TZ_MPC_RET_BAD_BOUNDS;
    }

    // Get a normalized address that is an offset from the beginning
    // of the lowest range controlled by the MPC
    uint32_t norm_base = NORMALIZE_ADDR(phys_base, mpc_start_type);
    uint32_t norm_limit = NORMALIZE_ADDR(phys_limit, mpc_start_type);
    uint32_t block_start_idx = norm_base / block_size;
    uint32_t block_start_word = block_start_idx / 32;
    uint32_t block_end_idx = norm_limit / block_size;
    uint32_t block_end_word = block_end_idx / 32;
    // Sanity check that word limit fits in bounds covered by MPC
    if (at_tz_mpc_check_bound(block_end_word, mpc_start_type)) {
	return AT_TZ_MPC_RET_BLK_IDX_TOO_HIGH;
    }

    // Get masks for "incomplete" blocks, all remaining LUTs are the same mask
    uint32_t block_start_mask = ~((1 << (block_start_idx % 32)) - 1);
    uint32_t block_end_mask = (1 << ((block_end_idx + 1) % 32)) - 1;

    // If block_end_mask is 0, it means that the limit touched block index is
    // the limit in its word, so the limit word mask has all its bits selected
    if (block_end_mask == 0) {
	block_end_mask = 0xFFFFFFFF;
    }
    // If the blocks to configure are all packed in one word, only touch this
    // word. Only bits that are the same in both masks are valid
    if (block_start_word == block_end_word) {
	uint32_t joined_mask = ~(block_start_mask ^ block_end_mask);
	block_start_mask = joined_mask;
	// this should not be used
	block_end_mask = joined_mask;
    }

    // Starts changing actual configuration so issue DMB to ensure every
    // transaction has completed by now
    __DMB();

    MPC_TypeDef *current_mpc = NULL;
    // get current_mpc to check block size before continuing.
    at_tz_mpc_ret_t ret = at_tz_mpc_from_block_word(block_start_word,
	mpc_start_type, &current_mpc, NULL);
    if ((ret != AT_TZ_MPC_RET_OK) || (current_mpc == NULL)) {
	return ret;
    }
    // at_tz_mpc_from_block_word() restores previous MPC when necessary.
    uint32_t ctrl_bkup = current_mpc->CTRL;
    current_mpc->CTRL &= ~MPC_CTRL_AUTO_INCREMENT_Msk;
    uint32_t lut_idx = LUT_IDX_FROM_BLOCK(block_start_word, mpc_start_type);

    // Handle first bit mask
    current_mpc->BLK_IDX = lut_idx;
    if (attr == AT_TZ_MPC_ATTR_NONSECURE) {
	current_mpc->BLK_LUT |= block_start_mask;
    } else {
	current_mpc->BLK_LUT &= ~block_start_mask;
    }

    // short circuit if we are only modifying a single block
    if (block_start_word == block_end_word) {
	goto at_tz_mpc_config_done;
    }

    // Handle body
    for (uint32_t bword = block_start_word + 1; bword < block_end_word;
	 bword++) {
	// update MPC to next mpc if we overflow into the next one.
	at_tz_mpc_from_block_word(bword, mpc_start_type, &current_mpc,
	    &ctrl_bkup);
	lut_idx = LUT_IDX_FROM_BLOCK(bword, mpc_start_type);
	current_mpc->BLK_IDX = lut_idx;
	if (attr == AT_TZ_MPC_ATTR_NONSECURE) {
	    current_mpc->BLK_LUT = 0xFFFFFFFF;
	} else {
	    current_mpc->BLK_LUT = 0x00000000;
	}
    }

    // Handle final LUT
    at_tz_mpc_from_block_word(block_end_word, mpc_start_type, &current_mpc,
	&ctrl_bkup);
    lut_idx = LUT_IDX_FROM_BLOCK(block_end_word, mpc_start_type);
    current_mpc->BLK_IDX = lut_idx;
    if (attr == AT_TZ_MPC_ATTR_NONSECURE) {
	current_mpc->BLK_LUT |= block_end_mask;
    } else {
	current_mpc->BLK_LUT &= ~block_end_mask;
    }
    // Restore previous configuration
    current_mpc->CTRL = ctrl_bkup;

at_tz_mpc_config_done:
    /* Changes complete, issue sync barrier to commit config */
    __DSB();
    __ISB();

    return AT_TZ_MPC_RET_OK;
}
