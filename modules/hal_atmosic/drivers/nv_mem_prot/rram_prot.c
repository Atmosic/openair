/**
 ******************************************************************************
 *
 * @file rram_prot.c
 *
 * @brief RRAM Protection Driver
 *
 * Copyright (C) Atmosic 2022-2025
 *
 ******************************************************************************
 */

#include <zephyr/kernel.h>
#include "arch.h"
#define NV_MEM_PROT_INTERNAL_GUARD
#include "nv_mem_prot_internal.h"
#include "rram_prot.h"

bool rram_prot_write_enable(uint32_t offset, uint32_t length)
{
	if (!nv_mem_prot_range_check(offset, length, RRAM_WRITE_PROTECT_SIZE, false,
				     RRAM_PROT_BLOCK_SIZE)) {
		return false;
	}

	// set bit to 0 to enable writes
	set_clr_bits(&CMSDK_WRPR0_NONSECURE->RRAM_WRITE_PROTECTION0, offset, length, false, false);
	return true;
}

bool rram_prot_write_disable(uint32_t offset, uint32_t length)
{
	// fast disable all of RRAM.
	if (!offset && (length == RRAM_WRITE_PROTECT_SIZE)) {
		CMSDK_WRPR0_NONSECURE->RRAM_WRITE_PROTECTION0 = 0xffffffff;
		CMSDK_WRPR0_NONSECURE->RRAM_WRITE_PROTECTION1 = 0xffffffff;
		CMSDK_WRPR0_NONSECURE->RRAM_WRITE_PROTECTION2 = 0xffffffff;
		CMSDK_WRPR0_NONSECURE->RRAM_WRITE_PROTECTION3 = 0xffffffff;
		CMSDK_WRPR0_NONSECURE->RRAM_WRITE_PROTECTION4 = 0xffffffff;
		CMSDK_WRPR0_NONSECURE->RRAM_WRITE_PROTECTION5 = 0xffffffff;
		CMSDK_WRPR0_NONSECURE->RRAM_WRITE_PROTECTION6 = 0xffffffff;
		CMSDK_WRPR0_NONSECURE->RRAM_WRITE_PROTECTION7 = 0xffffffff;
		return true;
	}

	if (!nv_mem_prot_range_check(offset, length, RRAM_WRITE_PROTECT_SIZE, false,
				     RRAM_PROT_BLOCK_SIZE)) {
		return false;
	}

	// set bit to 1 to disable writes
	nv_mem_prot_set_clr_bits(&CMSDK_WRPR0_NONSECURE->RRAM_WRITE_PROTECTION0, offset, length,
				 true, false, RRAM_PROT_BLOCK_SIZE);
	return true;
}

bool rram_prot_sticky_write_disable(uint32_t offset, uint32_t length)
{
	if (!nv_mem_prot_range_check(offset, length, RRAM_STICKY_WRITE_PROTECT_SIZE, true,
				     RRAM_PROT_BLOCK_SIZE)) {
		return false;
	}

	nv_mem_prot_sticky_clock_control(1);

	// set bit to 1 to sticky disable writes
	nv_mem_prot_set_clr_bits(&CMSDK_WRPR0_NONSECURE->RRAM_STICKY_WRITE_PROTECTION0, offset,
				 length, true, true, RRAM_PROT_BLOCK_SIZE);

	nv_mem_prot_sticky_clock_control(0);

	return true;
}

bool rram_prot_sticky_read_disable(uint32_t offset, uint32_t length)
{
	if (!nv_mem_prot_range_check(offset, length, RRAM_READ_PROTECT_SIZE, true,
				     RRAM_PROT_BLOCK_SIZE)) {
		return false;
	}

	nv_mem_prot_sticky_clock_control(1);

	// set bit to 1 to sticky disable reads
	nv_mem_prot_set_clr_bits(&CMSDK_WRPR0_NONSECURE->RRAM_STICKY_READ_PROTECTION0, offset,
				 length, true, true, RRAM_PROT_BLOCK_SIZE);

	nv_mem_prot_sticky_clock_control(0);

	return true;
}

#ifndef WRPRPINS_RRAM_REMAP0__BLK0__MASK
bool rram_write_section_allowed(void)
{
	return atm_bp_clock_critical_section_allowed(RRAM_WRITE_MAX_BP_CLOCK);
}
#endif

#define STICK_REG_COUNT                                                                            \
	NUM_MEM_PROT_REG_ROUND_UP(RRAM_STICKY_WRITE_PROTECT_SIZE / RRAM_ROM_PROT_BLOCK_SIZE)

bool rram_prot_sticky_write_get_mask(uint8_t index, uint32_t *value)
{
	if (index >= STICK_REG_COUNT) {
		return false;
	}
	uint32_t volatile const *ptr = &CMSDK_WRPR0_NONSECURE->RRAM_STICKY_WRITE_PROTECTION0;
	nv_mem_prot_sticky_clock_control(1);
	*value = ptr[index];
	nv_mem_prot_sticky_clock_control(0);
	return true;
}
