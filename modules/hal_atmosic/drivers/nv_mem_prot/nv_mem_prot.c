/**
 ******************************************************************************
 *
 * @file nv_mem_prot.c
 *
 * @brief NV mem protection driver helper/common APIs
 *
 * Copyright (C) Atmosic 2025
 *
 ******************************************************************************
 */

#include <zephyr/kernel.h>
#include <stdint.h>
#include <inttypes.h>
#include "at_wrpr.h"
#include "at_apb_clkrstgen_regs_core_macro.h"
#define NV_MEM_PROT_INTERNAL_GUARD
#include "nv_mem_prot_internal.h"

#ifdef NVM_MEM_PROT_DEBUG
#define DEBUG_MEM_PROT printk
#else
#define DEBUG_MEM_PROT(s, ...)                                                                     \
	do {                                                                                       \
	} while (0)
#endif

bool nv_mem_prot_range_check(uint32_t offset, uint32_t length, uint32_t max_size, bool force_align,
			     uint32_t block_size)
{
	DEBUG_MEM_PROT("Check range offset: 0x%" PRIx32 " len:%" PRIu32 "\n", offset, length);

	if (force_align && ((offset % block_size) || (length % block_size))) {
		DEBUG_MEM_PROT("Check offset: 0x%" PRIx32 " length:%" PRIu32
			       " mis-aligned! blk_size:%" PRIu32 "\n",
			       offset, length, block_size);
		return false;
	}

	uint64_t end = (uint64_t)offset + (uint64_t)length;

	if (!length || (end > max_size)) {
		DEBUG_MEM_PROT("Check offset: 0x%" PRIx32 " length:%" PRIu32 " invalid!\n", offset,
			       length);
		return false;
	}
	return true;
}

void nv_mem_prot_set_clr_bits(uint32_t volatile *rreg, uint32_t offset, uint32_t length, bool set,
			      bool sticky, uint32_t block_size)
{
	DEBUG_MEM_PROT("Reg base (%p) off: 0x%" PRIx32 " len: %" PRIu32 " blk_sz: %" PRIu32 "\n",
		       rreg, offset, length, block_size);

	uint32_t bit_offset = offset / block_size;

	// compute starting register and starting bit
	uint32_t reg_offset = bit_offset / 32;
	uint32_t start_bit = bit_offset % 32;
	rreg = &rreg[reg_offset];

	// compute the span of bits
	uint32_t bit_offset_end = (offset + length) / block_size;
	bit_offset_end += ((offset + length) % block_size) ? 1 : 0;
	uint32_t num_bits = bit_offset_end - bit_offset;

	DEBUG_MEM_PROT("Reg start (%p) idx:%" PRIu32 ", startb:%" PRIu32 " bits:%" PRIu32 "\n",
		       rreg, reg_offset, start_bit, num_bits);

	while (num_bits) {
		uint32_t reg_bits = 32 - start_bit;
		if (reg_bits > num_bits) {
			reg_bits = num_bits;
		}
		uint32_t bitmask = (1 << reg_bits) - 1;
		bitmask <<= start_bit;
		if (set) {
			*rreg |= bitmask;
		} else {
#if defined(WRPRPINS_RRAM_REMAP0__BLK0__MASK) ||                                                   \
	defined(__WRPRPINS_QSPI_STICKY_WRITE_PROTECTION0_MACRO__)
			__ASSERT(!sticky, "Cannot clr sticky reg: %p, offset: %" PRIu32, rreg,
				 offset);
#endif
			*rreg &= ~bitmask;
		}
#if defined(WRPRPINS_RRAM_REMAP0__BLK0__MASK) ||                                                   \
	defined(__WRPRPINS_QSPI_STICKY_WRITE_PROTECTION0_MACRO__)
		if (sticky) {
			// sticky lock registers are not auto-clearing
			*rreg = 0;
		}
#endif
		start_bit = 0;
		num_bits -= reg_bits;
		rreg++;
	}
}

void nv_mem_prot_sticky_clock_control(uint32_t enable)
{
	WRPR_CTRL_PUSH(CMSDK_CLKRSTGEN_NONSECURE, WRPR_CTRL__CLK_ENABLE)
	{
		CLKRSTGEN_USER_CLK_GATE_CTRL__STICKY_CLK__MODIFY(
			CMSDK_CLKRSTGEN_NONSECURE->USER_CLK_GATE_CTRL, enable);
	}
	WRPR_CTRL_POP();
}
