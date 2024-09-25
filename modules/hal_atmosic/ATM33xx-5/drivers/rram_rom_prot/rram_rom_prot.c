/**
 ******************************************************************************
 *
 * @file rram_rom_prot.c
 *
 * @brief RRAM and ROM Protection Driver
 *
 * Copyright (C) Atmosic 2022-2024
 *
 ******************************************************************************
 */

#include "arch.h"
#include <stdint.h>
#include <inttypes.h>
#include "rram_rom_prot.h"
#include "at_wrpr.h"
#include "at_apb_clkrstgen_regs_core_macro.h"
#ifndef SECURE_MODE
#include "rep_vec.h"
#include "atm_bp_clock.h"
#endif

#ifdef CFG_RRAM_PROT_DEBUG
#define RR_PROT_DEBUG 1
#else
#define RR_PROT_DEBUG 0
#endif

static bool prot_range_check(uint32_t offset, uint32_t length,
    uint32_t max_size, bool force_align)
{
    DEBUG_TRACE_COND(RR_PROT_DEBUG, "Check range offset: 0x%" PRIx32 " len:%"
	PRIu32, offset, length);

    if (force_align && ((offset % RRAM_ROM_PROT_BLOCK_SIZE) ||
	(length % RRAM_ROM_PROT_BLOCK_SIZE))) {
	DEBUG_TRACE_COND(RR_PROT_DEBUG, "Check offset: 0x%" PRIx32 " length:%" PRIu32
	    " mis-aligned!", offset, length);
	return false;
    }

    uint64_t end = (uint64_t)offset + (uint64_t)length;

    if (!length || (end > max_size)) {
	DEBUG_TRACE_COND(RR_PROT_DEBUG, "Check offset: 0x%" PRIx32 " length:%" PRIu32 " invalid!",
	    offset, length);
	return false;
    }
    return true;
}

static void set_clr_bits(uint32_t volatile *rreg, uint32_t offset,
    uint32_t length, bool set)
{
    DEBUG_TRACE_COND(RR_PROT_DEBUG, "Reg base (%p) off: 0x%" PRIx32 " len: %"
	PRIu32, rreg, offset, length);

    uint32_t bit_offset = offset / RRAM_ROM_PROT_BLOCK_SIZE;

    // compute starting register and starting bit
    uint32_t reg_offset = bit_offset / 32;
    uint32_t start_bit = bit_offset % 32;
    rreg = &rreg[reg_offset];

    // compute the span of bits
    uint32_t bit_offset_end = (offset + length) / RRAM_ROM_PROT_BLOCK_SIZE;
    bit_offset_end += ((offset + length) % RRAM_ROM_PROT_BLOCK_SIZE) ? 1 : 0;
    uint32_t num_bits = bit_offset_end - bit_offset;

    DEBUG_TRACE_COND(RR_PROT_DEBUG, "Reg start (%p) idx:%" PRIu32 ", startb:%"
	PRIu32 " bits:%" PRIu32, rreg, reg_offset, start_bit, num_bits);

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
	    *rreg &= ~bitmask;
	}
	start_bit = 0;
	num_bits -= reg_bits;
	rreg++;
    }
}

bool rram_prot_write_enable(uint32_t offset, uint32_t length)
{
    if (!prot_range_check(offset, length, RRAM_WRITE_PROTECT_SIZE, false)) {
	return false;
    }

    // set bit to 0 to enable writes
    set_clr_bits(&CMSDK_WRPR0_NONSECURE->RRAM_WRITE_PROTECTION0, offset, length,
	false);
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

    if (!prot_range_check(offset, length, RRAM_WRITE_PROTECT_SIZE, false)) {
	return false;
    }

    // set bit to 1 to disable writes
    set_clr_bits(&CMSDK_WRPR0_NONSECURE->RRAM_WRITE_PROTECTION0, offset, length,
	true);
    return true;
}

static void sticky_clock_control(uint32_t enable)
{
    WRPR_CTRL_PUSH(CMSDK_CLKRSTGEN_NONSECURE, WRPR_CTRL__CLK_ENABLE)
    {
	CLKRSTGEN_USER_CLK_GATE_CTRL__STICKY_CLK__MODIFY(
	    CMSDK_CLKRSTGEN_NONSECURE->USER_CLK_GATE_CTRL, enable);
    }
    WRPR_CTRL_POP();
}

bool rram_prot_sticky_write_disable(uint32_t offset, uint32_t length)
{
    if (!prot_range_check(offset, length, RRAM_STICKY_WRITE_PROTECT_SIZE,
	true)) {
	return false;
    }

    sticky_clock_control(1);

    // set bit to 1 to sticky disable writes
    set_clr_bits(&CMSDK_WRPR0_NONSECURE->RRAM_STICKY_WRITE_PROTECTION0, offset,
	length, true);

    sticky_clock_control(0);

    return true;
}

bool rram_prot_sticky_read_disable(uint32_t offset, uint32_t length)
{
    if (!prot_range_check(offset, length, RRAM_READ_PROTECT_SIZE, true)) {
	return false;
    }

    sticky_clock_control(1);

    // set bit to 1 to sticky disable reads
    set_clr_bits(&CMSDK_WRPR0_NONSECURE->RRAM_STICKY_READ_PROTECTION0, offset,
	length, true);

    // this register is not auto-clearing
    CMSDK_WRPR0_NONSECURE->RRAM_STICKY_READ_PROTECTION0 = 0;

    sticky_clock_control(0);

    return true;
}

bool rom_prot_sticky_read_disable(uint32_t offset, uint32_t length)
{
    if (!prot_range_check(offset, length, ROM_READ_PROTECT_SIZE, true)) {
	return false;
    }

    sticky_clock_control(1);

    // set bit to 1 to sticky disable reads
    set_clr_bits(&CMSDK_WRPR0_NONSECURE->PROT_BITS_SET0, offset, length, true);

    sticky_clock_control(0);

    return true;
}

bool rram_write_section_allowed(void)
{
    return atm_bp_clock_critical_section_allowed(RRAM_WRITE_MAX_BP_CLOCK);
}

#define STICK_REG_COUNT \
    (RRAM_STICKY_WRITE_PROTECT_SIZE / RRAM_ROM_PROT_BLOCK_SIZE / 32)

bool rram_prot_sticky_write_get_mask(uint8_t index, uint32_t *value)
{
    if (index >= STICK_REG_COUNT) {
	return false;
    }
    uint32_t volatile *ptr =
	&CMSDK_WRPR0_NONSECURE->RRAM_STICKY_WRITE_PROTECTION0;
    sticky_clock_control(1);
    *value = ptr[index];
    sticky_clock_control(0);
    return true;
}
