/**
 ******************************************************************************
 *
 * @file rram.h
 *
 * @brief RRAM register access
 *
 * Copyright (C) Atmosic 2020-2023
 *
 ******************************************************************************
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "at_ahb_prrf_regs_core_macro.h"
#include "at_apb_wrpr_pins_regs_core_macro.h"

typedef enum {
    RRAM_R_TEST		= 0x00,
    RRAM_R_CLK_INFO	= 0x16,
    RRAM_R_WRITE_ADJ	= 0x18,
    RRAM_R_CMD2YE	= 0x1c,
} RRAM_R_Enum;

#define RRAM_R_BASE_ADDR	0x00090000U

#define RRAM_R_TEST__TEST_MODE__SHIFT		0
#define RRAM_R_TEST__TEST_MODE__MASK		0x0000000001ULL

#define RRAM_R_CLK_INFO__LVEN_READ_CYC__SHIFT	26
#define RRAM_R_CLK_INFO__LVEN_READ_CYC__MASK	0x003c000000ULL
#define RRAM_R_CLK_INFO__MARGIN_READ_CYC__SHIFT	18
#define RRAM_R_CLK_INFO__MARGIN_READ_CYC__MASK	0x0003fc0000ULL
#define RRAM_R_CLK_INFO__READ_CYC__SHIFT	14
#define RRAM_R_CLK_INFO__READ_CYC__MASK		0x000003c000ULL
#define RRAM_R_CLK_INFO__US_UNIT__SHIFT		0
#define RRAM_R_CLK_INFO__US_UNIT__MASK		0x00000003ffULL
#define RRAM_R_CLK_INFO__NS100_UNIT__SHIFT	10
#define RRAM_R_CLK_INFO__NS100_UNIT__MASK	0x0000003c00ULL

#define RRAM_R_WRITE_ADJ__SU_AD_YE__SHIFT	0
#define RRAM_R_WRITE_ADJ__SU_AD_YE__MASK	0x000000007FULL

#define RRAM_READ_NS		58
#define RRAM_LVEN_READ_NS	63
#define RRAM_SU_CMD_YE		5000

#ifndef __RRAM_STATIC_INLINE
#define __RRAM_STATIC_INLINE __STATIC_INLINE
#endif

__RRAM_STATIC_INLINE uint64_t
rram_reg_read(RRAM_R_Enum reg)
{
    *(volatile uint32_t *)(RRAM_R_BASE_ADDR + (reg << 1));
    uint32_t lo = CMSDK_AT_PRRF_NONSECURE->RRAM_READ_CONFIG_LO;
    uint32_t hi = CMSDK_AT_PRRF_NONSECURE->RRAM_READ_CONFIG_HI;
    return ((((uint64_t)hi) << 32) | lo);
}

__RRAM_STATIC_INLINE void
rram_reg_write(RRAM_R_Enum reg, uint64_t val)
{
    CMSDK_AT_PRRF_NONSECURE->RRAM_WRT_CONFIG_LO = val & 0xffffffff;
    CMSDK_AT_PRRF_NONSECURE->RRAM_WRT_CONFIG_HI = val >> 32;
    *(volatile uint32_t *)(RRAM_R_BASE_ADDR + (reg << 1)) = 0;
}

__RRAM_STATIC_INLINE uint32_t
rram_calc_cmd2ye(uint16_t us_unit)
{
    uint32_t r_write_adj = rram_reg_read(RRAM_R_WRITE_ADJ) &
	RRAM_R_WRITE_ADJ__SU_AD_YE__MASK;
    return ((RRAM_SU_CMD_YE * us_unit) / 1000) - (3 + r_write_adj) + 1;
}

__RRAM_STATIC_INLINE void
rram_adjust_timing(uint16_t us_unit)
{
    // Adjust RRAM timing
    uint8_t ns100_unit = ((us_unit - 1) / 10) + 1;
    if (ns100_unit < 2) {
	ns100_unit = 2;
    }
    uint8_t read_cyc = ((us_unit * RRAM_READ_NS) - 1) / 1000;
    uint8_t lven_cyc = ((us_unit * RRAM_LVEN_READ_NS) - 1) / 1000;
    uint8_t margin_cyc = (lven_cyc < 4) ? 4 : lven_cyc;
    uint32_t r_cmd2ye = rram_calc_cmd2ye(us_unit);

    uint64_t r_clk_info = rram_reg_read(RRAM_R_CLK_INFO);
    r_clk_info = (r_clk_info &
	~(RRAM_R_CLK_INFO__LVEN_READ_CYC__MASK |
	  RRAM_R_CLK_INFO__MARGIN_READ_CYC__MASK |
	  RRAM_R_CLK_INFO__READ_CYC__MASK |
	  RRAM_R_CLK_INFO__NS100_UNIT__MASK | RRAM_R_CLK_INFO__US_UNIT__MASK))
	| (((uint64_t)lven_cyc) << RRAM_R_CLK_INFO__LVEN_READ_CYC__SHIFT)
	| (((uint64_t)margin_cyc) << RRAM_R_CLK_INFO__MARGIN_READ_CYC__SHIFT)
	| (((uint64_t)read_cyc) << RRAM_R_CLK_INFO__READ_CYC__SHIFT)
	| (((uint64_t)ns100_unit) << RRAM_R_CLK_INFO__NS100_UNIT__SHIFT)
	| (((uint64_t)us_unit) << RRAM_R_CLK_INFO__US_UNIT__SHIFT);

    // Unlock test mode registers
    rram_reg_write(RRAM_R_TEST, RRAM_R_TEST__TEST_MODE__MASK);
    {
	rram_reg_write(RRAM_R_CLK_INFO, r_clk_info);
	rram_reg_write(RRAM_R_CMD2YE, r_cmd2ye);
    }
    // Lock test mode registers
    rram_reg_write(RRAM_R_TEST, 0);
}

__RRAM_STATIC_INLINE void
rram_enable_cache(void)
{
    CMSDK_AT_PRRF_NONSECURE->RRAM_CACHE_CONFIG =
	AT_PRRF_RRAM_CACHE_CONFIG__INVALIDATE_CACHE__MASK;
    CMSDK_AT_PRRF_NONSECURE->RRAM_CACHE_CONFIG =
	AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_CACHE__MASK |
	AT_PRRF_RRAM_CACHE_CONFIG__CACHE_MODE__MASK;
}

__RRAM_STATIC_INLINE void
rram_disable_cache(void)
{
    CMSDK_AT_PRRF_NONSECURE->RRAM_CACHE_CONFIG =
	AT_PRRF_RRAM_CACHE_CONFIG__CACHE_MODE__MASK;
    // don't worry about invalidate; that's done by rram_enale_cache
}
