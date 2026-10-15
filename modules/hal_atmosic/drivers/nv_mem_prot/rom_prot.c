/**
 ******************************************************************************
 *
 * @file rom_prot.c
 *
 * @brief ROM Protection Driver
 *
 * Copyright (C) Atmosic 2025
 *
 ******************************************************************************
 */

#include <zephyr/kernel.h>
#include "arch.h"
#define NV_MEM_PROT_INTERNAL_GUARD
#include "nv_mem_prot_internal.h"
#include "rom_prot.h"

bool rom_prot_sticky_read_disable(uint32_t offset, uint32_t length)
{
	if (!nv_mem_prot_range_check(offset, length, ROM_STICKY_READ_PROTECT_SIZE, true,
				     ROM_PROT_BLOCK_SIZE)) {
		return false;
	}

	nv_mem_prot_sticky_clock_control(1);

	// set bit to 1 to sticky disable reads
	nv_mem_prot_set_clr_bits(&CMSDK_WRPR0_NONSECURE->PROT_BITS_SET0, offset, length, true, true,
				 ROM_PROT_BLOCK_SIZE);

	nv_mem_prot_sticky_clock_control(0);

	return true;
}
