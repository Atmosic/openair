/**
 ******************************************************************************
 *
 * @file flash_prot.c
 *
 * @brief FLASH Protection Driver
 *
 * Copyright (C) Atmosic 2025
 *
 ******************************************************************************
 */

#include <zephyr/kernel.h>
#include "arch.h"
#define NV_MEM_PROT_INTERNAL_GUARD
#include "nv_mem_prot_internal.h"
#include "flash_prot.h"

bool flash_prot_sticky_write_disable(uint32_t offset, uint32_t length)
{
	if (!nv_mem_prot_range_check(offset, length, FLASH_STICKY_WRITE_PROTECT_SIZE, true,
				     FLASH_PROT_BLOCK_SIZE)) {
		return false;
	}

	nv_mem_prot_sticky_clock_control(1);

	// set bit to 1 to sticky disable writes
	nv_mem_prot_set_clr_bits(&CMSDK_WRPR0_NONSECURE->QSPI_STICKY_WRITE_PROTECTION0, offset,
				 length, true, true, FLASH_PROT_BLOCK_SIZE);

	nv_mem_prot_sticky_clock_control(0);

	return true;
}

bool flash_prot_sticky_read_disable(uint32_t offset, uint32_t length)
{
	if (!nv_mem_prot_range_check(offset, length, FLASH_STICKY_READ_PROTECT_SIZE, true,
				     FLASH_PROT_BLOCK_SIZE)) {
		return false;
	}

	nv_mem_prot_sticky_clock_control(1);

	// set bit to 1 to sticky disable reads
	nv_mem_prot_set_clr_bits(&CMSDK_WRPR0_NONSECURE->QSPI_STICKY_READ_PROTECTION0, offset,
				 length, true, true, FLASH_PROT_BLOCK_SIZE);

	nv_mem_prot_sticky_clock_control(0);

	return true;
}

#define WR_PROT_STICKY_REG_COUNT                                                                   \
	NUM_MEM_PROT_REG_ROUND_UP(FLASH_STICKY_WRITE_PROTECT_SIZE / FLASH_PROT_BLOCK_SIZE)

bool flash_prot_sticky_write_get_mask(uint8_t index, uint32_t *value)
{
	if (index >= WR_PROT_STICKY_REG_COUNT) {
		return false;
	}
	uint32_t volatile const *ptr = &CMSDK_WRPR0_NONSECURE->QSPI_STICKY_WRITE_PROTECTION_STATUS0;
	nv_mem_prot_sticky_clock_control(1);
	*value = ptr[index];
	nv_mem_prot_sticky_clock_control(0);
	return true;
}
