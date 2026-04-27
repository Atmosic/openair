/**
 *******************************************************************************
 *
 * @file retained_mem_hib_expansion.c
 *
 * @brief Atmosic Retained Memory Driver - Persistent Expansion Backend
 *
 * This backend implementation uses the PSEQ Persistent Expansion mechanism
 * for retained memory storage. This is used on platforms without SHUB hardware
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 *******************************************************************************
 */

#include <zephyr/logging/log.h>

#include "arch.h"
#include "at_apb_pseq_regs_core_macro.h"
#include "at_wrpr.h"
#include "retained_mem_hib_backend.h"

LOG_MODULE_DECLARE(retained_mem_hib, CONFIG_RETAINED_MEM_LOG_LEVEL);

/* Persistent expansion size constant for internal use */
#define PERSISTENT_EXPANSION_SIZE RETAINED_MEM_BACKEND_CAPACITY

void retained_mem_backend_save(const uint8_t *src, uint32_t len)
{
	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
#ifdef __PSEQ_PERSISTENT_EXPANSION_WDATA_MACRO__
		__ASSERT(IS_ALIGNED(src, sizeof(uint32_t)), "src is not aligned!");
		__ASSERT(IS_ALIGNED(len, sizeof(uint32_t)), "length is not aligned!");
		uint32_t *align_src = (uint32_t *)src;

		// enable clock and enable writes
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_CLKEN__SET(
			CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL);
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_WRITE__SET(
			CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL);

		uint32_t ctrl = CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL;

		for (uint32_t exp_addr = 0; len && (exp_addr < (PERSISTENT_EXPANSION_SIZE / 4));
		     exp_addr++, align_src++, len -= sizeof(uint32_t)) {
			/* setup address */
			PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_ADDR__MODIFY(ctrl, exp_addr);
			CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL = ctrl;
			/* write data (must be done after address is updated first) */
			CMSDK_PSEQ->PERSISTENT_EXPANSION_WDATA = *align_src;
		}
#else
		/* Write data byte-by-byte using expansion interface */
		for (uint8_t addr = 0; (len && (addr < PERSISTENT_EXPANSION_SIZE));
		     addr++, src++, len--) {
			uint32_t ctrl_val = 0;

			/* Set write data (bits 0-7) */
			ctrl_val |= PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_WDATA__WRITE(*src);

			/* Set address (bits 8-13) */
			ctrl_val |= PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_ADDR__WRITE(addr);

			/* Set write enable (bit 16) */
			ctrl_val |= PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_WRITE__MASK;

			/* Set clock enable (bit 17) */
			ctrl_val |= PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_CLKEN__MASK;

			/* Write to control register to trigger the write */
			CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL = ctrl_val;
		}
#endif
		// make sure clock is gated and write enable cleared
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_CLKEN__CLR(
			CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL);
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_WRITE__CLR(
			CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL);
	}
	WRPR_CTRL_POP();

	/* Assert if we ran short on storage */
	ASSERT_ERR(!len);
}

void retained_mem_backend_restore(uint8_t *dst, uint32_t len)
{
	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
#ifdef __PSEQ_PERSISTENT_EXPANSION_WDATA_MACRO__
		__ASSERT(IS_ALIGNED(dst, sizeof(uint32_t)), "dst is not aligned!");
		__ASSERT(IS_ALIGNED(len, sizeof(uint32_t)), "length is not aligned!");
		uint32_t *align_dst = (uint32_t *)dst;

		// enable clock and make sure write enable is cleared
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_CLKEN__SET(
			CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL);
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_WRITE__CLR(
			CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL);

		uint32_t ctrl = CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL;

		for (uint32_t exp_addr = 0; len && (exp_addr < (PERSISTENT_EXPANSION_SIZE / 4));
		     exp_addr++, align_dst++, len -= sizeof(uint32_t)) {

			/* setup address */
			PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_ADDR__MODIFY(ctrl, exp_addr);
			CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL = ctrl;
			*align_dst = CMSDK_PSEQ->PERSISTENT_EXPANSION_RDATA;
		}
#else
		/* Read data byte-by-byte using expansion interface */
		for (uint8_t addr = 0; (len && (addr < PERSISTENT_EXPANSION_SIZE));
		     addr++, dst++, len--) {
			uint32_t ctrl_val = 0;

			/* Set address (bits 8-13) */
			ctrl_val |= PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_ADDR__WRITE(addr);

			/* Clear write enable for read mode (bit 16 = 0) */
			/* Set clock enable (bit 17) */
			ctrl_val |= PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_CLKEN__MASK;

			/* Write to control register to set read address */
			CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL = ctrl_val;

			/* Read data from read data register (bits 0-7) */
			*dst = (uint8_t)PSEQ_PERSISTENT_EXPANSION_RDATA__PEXPAN_RDATA__READ(
				CMSDK_PSEQ->PERSISTENT_EXPANSION_RDATA);
		}
#endif
		// make sure clock is gated
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_CLKEN__CLR(
			CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL);
	}
	WRPR_CTRL_POP();
}

int retained_mem_backend_init(const struct device *dev)
{
	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		// remove isolation and bring out of reset, keep clock gated
		// the order below must be maintained
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_VDDCUT__CLR(
			CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL);
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_ISO__CLR(
			CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL);
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_FRST__CLR(
			CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL);
	}
	WRPR_CTRL_POP();

	/*
	 * The expansion backend does not have a hardware reset pin, so the registers can power
	 * up with random/indeterminate values on cold boot.  Zero the storage now to provide
	 * the same known-zero guarantee that a reset pin would give, and to prevent the driver's
	 * internal read-modify-write from propagating garbage into bytes that the application
	 * has not yet written.
	 */
	uint8_t __aligned(4) temp_buffer[RETAINED_MEM_BACKEND_MAX_CAPACITY];
	memset(temp_buffer, 0, RETAINED_MEM_BACKEND_CAPACITY);
	retained_mem_backend_save(temp_buffer, RETAINED_MEM_BACKEND_CAPACITY);

	return 0;
}
