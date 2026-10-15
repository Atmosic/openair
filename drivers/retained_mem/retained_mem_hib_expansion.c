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
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include <zephyr/logging/log.h>

#include "arch.h"
#include "at_apb_pseq_regs_core_macro.h"

// enabled on platforms without SHUB
#ifndef __PSEQ_SENSOR_HUB_CONTROL_MACRO__

#include "at_wrpr.h"
#include "retained_mem_hib_backend.h"

LOG_MODULE_DECLARE(retained_mem_hib, CONFIG_RETAINED_MEM_LOG_LEVEL);

/* Persistent expansion size constant for internal use */
#define PERSISTENT_EXPANSION_BYTES RETAINED_MEM_BACKEND_CAPACITY
#define PERSISTENT_EXPANSION_WORDS (RETAINED_MEM_BACKEND_CAPACITY / sizeof(uint32_t))

#ifdef __PSEQ_PERSISTENT_EXPANSION_WDATA_MACRO__
#define UNROLL_WORDS 4 // Number of 32 bit words to write in one loop

// clang-format off
#define WRITE_PERSISTENT(ctrl, align_src) do {                                 \
	/* setup address first, then write data after */                       \
	CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL = ctrl;                          \
	ctrl += 1 << PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_ADDR__SHIFT;       \
	CMSDK_PSEQ->PERSISTENT_EXPANSION_WDATA = *align_src++;                 \
} while(0)

#define READ_PERSISTENT(ctrl, align_dst) do {                                  \
	/* setup address first, then write data after */                       \
	CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL = ctrl;                          \
	ctrl += 1 << PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_ADDR__SHIFT;       \
	*align_dst++ = CMSDK_PSEQ->PERSISTENT_EXPANSION_RDATA;                   \
} while(0)
// clang-format on
#endif

void retained_mem_backend_save(const uint8_t *src, uint32_t len)
{
	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		uint32_t ctrl = 0;
#ifdef __PSEQ_PERSISTENT_EXPANSION_WDATA_MACRO__
		__ASSERT(IS_ALIGNED(src, sizeof(uint32_t)), "src is not aligned!");
		__ASSERT(IS_ALIGNED(len, sizeof(uint32_t)), "length is not aligned!");
		__ASSERT(len <= PERSISTENT_EXPANSION_BYTES,
			 "length is larger than retained mem size!");
		uint32_t *align_src = (uint32_t *)src;

		// enable clock and enable writes
		ctrl = CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL;
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_CLKEN__SET(ctrl);
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_WRITE__SET(ctrl);
		CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL = ctrl;
		// Start writes at 0
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_ADDR__MODIFY(ctrl, 0);

		len /= sizeof(uint32_t);
		uint32_t unrolled_count = len / UNROLL_WORDS;
		uint32_t word_remainder = len - (unrolled_count * UNROLL_WORDS);

		while (unrolled_count > 0) {
			WRITE_PERSISTENT(ctrl, align_src);
			WRITE_PERSISTENT(ctrl, align_src);
			WRITE_PERSISTENT(ctrl, align_src);
			WRITE_PERSISTENT(ctrl, align_src);
			unrolled_count--;
		}
		while (word_remainder > 0) {
			WRITE_PERSISTENT(ctrl, align_src);
			word_remainder--;
		}
#else
		/* Write data byte-by-byte using expansion interface */
		for (uint8_t addr = 0; len && (addr < PERSISTENT_EXPANSION_BYTES);
		     addr++, src++, len--) {
			/* Set write data (bits 0-7) */
			ctrl = PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_WDATA__WRITE(*src);

			/* Set address (bits 8-13) */
			ctrl |= PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_ADDR__WRITE(addr);

			/* Set write enable (bit 16) */
			ctrl |= PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_WRITE__MASK;

			/* Set clock enable (bit 17) */
			ctrl |= PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_CLKEN__MASK;

			/* Write to control register to trigger the write */
			CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL = ctrl;
		}
#endif
		// make sure clock is gated and write enable cleared
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_CLKEN__CLR(ctrl);
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_WRITE__CLR(ctrl);
		CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL = ctrl;
	}
	WRPR_CTRL_POP();
}

void retained_mem_backend_restore(uint8_t *dst, uint32_t len)
{
	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		uint32_t ctrl = 0;
#ifdef __PSEQ_PERSISTENT_EXPANSION_WDATA_MACRO__
		__ASSERT(IS_ALIGNED(dst, sizeof(uint32_t)), "dst is not aligned!");
		__ASSERT(IS_ALIGNED(len, sizeof(uint32_t)), "length is not aligned!");
		__ASSERT(len <= PERSISTENT_EXPANSION_BYTES,
			 "length is larger than retained mem size!");
		uint32_t *align_dst = (uint32_t *)dst;

		// enable clock and make sure write enable is cleared
		ctrl = CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL;
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_CLKEN__SET(ctrl);
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_WRITE__CLR(ctrl);
		CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL = ctrl;
		// Start reads at 0
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_ADDR__MODIFY(ctrl, 0);

		len /= sizeof(uint32_t);
		uint32_t unrolled_count = len / UNROLL_WORDS;
		uint32_t word_remainder = len - (unrolled_count * UNROLL_WORDS);

		while (unrolled_count > 0) {
			READ_PERSISTENT(ctrl, align_dst);
			READ_PERSISTENT(ctrl, align_dst);
			READ_PERSISTENT(ctrl, align_dst);
			READ_PERSISTENT(ctrl, align_dst);
			unrolled_count--;
		}
		while (word_remainder > 0) {
			READ_PERSISTENT(ctrl, align_dst);
			word_remainder--;
		}
#else
		/* Read data byte-by-byte using expansion interface */
		for (uint8_t addr = 0; len && (addr < PERSISTENT_EXPANSION_BYTES);
		     addr++, dst++, len--) {
			/* Set address (bits 8-13) */
			ctrl = PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_ADDR__WRITE(addr);

			/* Clear write enable for read mode (bit 16 = 0) */
			/* Set clock enable (bit 17) */
			ctrl |= PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_CLKEN__MASK;

			/* Write to control register to set read address */
			CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL = ctrl;

			/* Read data from read data register (bits 0-7) */
			*dst = (uint8_t)PSEQ_PERSISTENT_EXPANSION_RDATA__PEXPAN_RDATA__READ(
				CMSDK_PSEQ->PERSISTENT_EXPANSION_RDATA);
		}
#endif
		// make sure clock is gated
		PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_CLKEN__CLR(ctrl);
		CMSDK_PSEQ->PERSISTENT_EXPANSION_CTRL = ctrl;
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

#endif /* !__PSEQ_SENSOR_HUB_CONTROL_MACRO__ */
