/**
 ******************************************************************************
 *
 * @file at_clkrstgen.h
 *
 * @brief System clock
 *
 * Copyright (C) Atmosic 2020-2023
 *
 ******************************************************************************
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "base_addr.h"
#include "at_apb_clkrstgen_regs_core_macro.h"
#include "at_wrpr.h"
#include "at_apb_pseq_regs_core_macro.h"

#define CLUSTER_SEL__SLOW	1
#define CLUSTER_SEL__DOUBLER	2
#define CLUSTER_SEL__PLL	4
#define CLUSTER_SEL__PLL_DIV2	8

#ifndef __CLKRSTGEN_GET_STATIC_INLINE
#define __CLKRSTGEN_GET_STATIC_INLINE __STATIC_INLINE
#endif

__CLKRSTGEN_GET_STATIC_INLINE uint32_t
at_clkrstgen_pll_freq(void)
{
    uint32_t pll = CMSDK_CLKRSTGEN_NONSECURE->PLL_CTRL;
    if (!CLKRSTGEN_PLL_CTRL__PLL_ENABLE__READ(pll)) {
	return (16000000);
    }

    uint32_t pseq_pll;
    WRPR_CTRL_PUSH(CMSDK_PSEQ_NONSECURE, WRPR_CTRL__CLK_ENABLE) {
	pseq_pll = CMSDK_PSEQ_NONSECURE->PLL;
    } WRPR_CTRL_POP();
    return ((16000000 * PSEQ_PLL__DIVFB__READ(pseq_pll)) >>
	PSEQ_PLL__DIV2OUT__READ(pseq_pll));
}

__CLKRSTGEN_GET_STATIC_INLINE uint32_t
at_clkrstgen_slow_freq(uint32_t bp_ctrl)
{
    uint8_t slow = CLKRSTGEN_CLK_BP_CTRL__SLOW_CLUSTER_SEL__READ(bp_ctrl);
    switch (slow) {
	case 1: return (8000000);
	case 3: return (4000000);
	case 2: return (2000000);
	case 6: return (1000000);
	case 7: return (500000);
	default: break;
    }
    return (16000000);
}

__CLKRSTGEN_GET_STATIC_INLINE uint32_t
at_clkrstgen_bp_from_ctrl(void)
{
    uint32_t bp_ctrl = CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL;
    uint8_t cluster = CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__READ(bp_ctrl);
    if (!cluster) {		// clk16x
	goto sixteen_mhz;
    }
    if (cluster & CLUSTER_SEL__SLOW) {
	return (at_clkrstgen_slow_freq(bp_ctrl));
    }
    if (cluster & CLUSTER_SEL__DOUBLER) {
	if (!CLKRSTGEN_CLK_BP_CTRL__DOUBLER_CLUSTER_SEL__READ(bp_ctrl)) {
	    goto sixteen_mhz;
	}
	return (32000000);
    }
    if (cluster & CLUSTER_SEL__PLL) {
	if (!CLKRSTGEN_CLK_BP_CTRL__PLL_CLUSTER_SEL__READ(bp_ctrl)) {
	    goto sixteen_mhz;
	}
	return (at_clkrstgen_pll_freq());
    }
    if (cluster & CLUSTER_SEL__PLL_DIV2) {
	if (!CLKRSTGEN_CLK_BP_CTRL__PLL_DIV2_CLUSTER_SEL__READ(bp_ctrl)) {
	    goto sixteen_mhz;
	}
	uint32_t freq = at_clkrstgen_pll_freq() / 2;
	return ((freq == 32000000) ? 32000001 : freq);
    }

sixteen_mhz:
    return (16000000);
}

__CLKRSTGEN_GET_STATIC_INLINE uint32_t
at_clkrstgen_fpga_bp_from_ctrl(uint32_t index)
{
    uint32_t bp_ctrl = CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL;
    uint8_t cluster = CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__READ(bp_ctrl);
    uint32_t pll_freq = (index == 5) ? 16000000 : 48000000;
    if (!cluster) {		// clk16x
	goto sixteen_mhz;
    }
    if (cluster & CLUSTER_SEL__SLOW) {
	return (at_clkrstgen_slow_freq(bp_ctrl));
    }
    if (cluster & CLUSTER_SEL__DOUBLER) {
	if (!CLKRSTGEN_CLK_BP_CTRL__DOUBLER_CLUSTER_SEL__READ(bp_ctrl)) {
	    goto sixteen_mhz;
	}
	return (32000000);
    }
    if (cluster & CLUSTER_SEL__PLL) {
	if (!CLKRSTGEN_CLK_BP_CTRL__PLL_CLUSTER_SEL__READ(bp_ctrl)) {
	    goto sixteen_mhz;
	}
	return (pll_freq);
    }
    if (cluster & CLUSTER_SEL__PLL_DIV2) {
	if (!CLKRSTGEN_CLK_BP_CTRL__PLL_DIV2_CLUSTER_SEL__READ(bp_ctrl)) {
	    goto sixteen_mhz;
	}
	return (pll_freq / 2);
    }

sixteen_mhz:
    return (16000000);
}

__CLKRSTGEN_GET_STATIC_INLINE uint32_t
at_clkrstgen_get_bp(void)
{
    uint32_t config = CMSDK_CLKRSTGEN_NONSECURE->CONFIGURATION;
    uint32_t index = CLKRSTGEN_CONFIGURATION__INDEX__READ(config);
    switch (index) {
	case 0: return (at_clkrstgen_bp_from_ctrl());
	case 1:
	case 3:
	case 5: return (at_clkrstgen_fpga_bp_from_ctrl(index));
	default: break;
    }
    return (16000000);
}

#ifndef __CLKRSTGEN_SET_STATIC_INLINE
#define __CLKRSTGEN_SET_STATIC_INLINE __STATIC_INLINE
#endif

__CLKRSTGEN_SET_STATIC_INLINE void
at_clkrstgen_set_clk16x(bool commit)
{
    if (!commit) {
	return;
    }

    // Sequence designed to avoid BP glitches and dropouts
    CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL &=
	CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__MASK;
    while (CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL_STAT &
	~CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__MASK) {
	__ASM volatile ("yield");
    }
    CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL = 0;
}

__CLKRSTGEN_SET_STATIC_INLINE void
at_clkrstgen_set_slow(uint8_t sel, bool set, bool commit)
{
    if (set) {
	// Get off SLOW before changing it
	at_clkrstgen_set_clk16x(CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__READ(
	    CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL) & CLUSTER_SEL__SLOW);

	CLKRSTGEN_CLK_BP_CTRL__SLOW_CLUSTER_SEL__MODIFY(
	    CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL, sel);
    }
    if (!commit) {
	return;
    }

    // To prevent multiple bit transitions, take everything back to zero
    at_clkrstgen_set_clk16x(CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL_STAT);

    CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL =
	CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__WRITE(CLUSTER_SEL__SLOW) |
	CLKRSTGEN_CLK_BP_CTRL__SLOW_CLUSTER_SEL__WRITE(sel);
}

__CLKRSTGEN_SET_STATIC_INLINE uint32_t
at_clkrstgen_get_lpc(void)
{
    uint32_t rt = CMSDK_PSEQ_NONSECURE->CURRENT_REAL_TIME;
    for (;;) {
	uint32_t rt1 = CMSDK_PSEQ_NONSECURE->CURRENT_REAL_TIME;
	if (rt == rt1) {
	    break;
	}
	rt = rt1;
    }

    return (rt);
}

__CLKRSTGEN_SET_STATIC_INLINE void
at_clkrstgen_set_doubler(bool set, bool commit)
{
    if (CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__READ(
	CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL) & CLUSTER_SEL__DOUBLER) {
	// Already running off doubler
	return;
    }

    if (set) {
	WRPR_CTRL_PUSH(CMSDK_PSEQ_NONSECURE, WRPR_CTRL__CLK_ENABLE) {
	    // Make sure xtal is stable
	    while (!PSEQ_RADIO_STATUS__XTAL_STABLE__READ(
		CMSDK_PSEQ_NONSECURE->RADIO_STATUS)) {
		__ASM volatile ("yield");
	    }

	    // Enable HPC
	    PSEQ_XTAL_BITS1__CLKHPC_EN__SET(CMSDK_PSEQ_NONSECURE->XTAL_BITS1);

	    // Stash HPC_EN time for split set/commit invocations
	    CMSDK_WRPR0_NONSECURE->SCRATCHPAD_A = at_clkrstgen_get_lpc();
	} WRPR_CTRL_POP();
    }
    if (!commit) {
	return;
    }

    // To prevent multiple bit transitions, take everything back to zero
    at_clkrstgen_set_clk16x(CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL_STAT);

    WRPR_CTRL_PUSH(CMSDK_PSEQ_NONSECURE, WRPR_CTRL__CLK_ENABLE) {
	uint32_t then = CMSDK_WRPR0_NONSECURE->SCRATCHPAD_A;
	while (at_clkrstgen_get_lpc() - then < 2) {
	    __ASM volatile ("yield");
	}
    } WRPR_CTRL_POP();

    // Then select doubler
    CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL =
	CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__WRITE(CLUSTER_SEL__DOUBLER) |
	CLKRSTGEN_CLK_BP_CTRL__DOUBLER_CLUSTER_SEL__MASK;
}

__CLKRSTGEN_SET_STATIC_INLINE void
at_clkrstgen_enable_pll(uint8_t sel, bool div2, bool set, bool commit)
{
    if (set) {
	// Get off PLL before changing it
	at_clkrstgen_set_clk16x(CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__READ(
	    CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL) & (CLUSTER_SEL__PLL |
	    CLUSTER_SEL__PLL_DIV2));

	if (CMSDK_CLKRSTGEN_NONSECURE->CLKSYNC) {
	    CLKRSTGEN_CLKSYNC__CLK16_SRC__MODIFY(
		CMSDK_CLKRSTGEN_NONSECURE->CLKSYNC, 0);
	    CMSDK_CLKRSTGEN_NONSECURE->PLL_CTRL = 0;
	    CMSDK_CLKRSTGEN_NONSECURE->CLKSYNC = 0;
	}

	WRPR_CTRL_PUSH(CMSDK_PSEQ_NONSECURE, WRPR_CTRL__CLK_ENABLE) {
	    // Make sure xtal is stable
	    while (!PSEQ_RADIO_STATUS__XTAL_STABLE__READ(
		CMSDK_PSEQ_NONSECURE->RADIO_STATUS)) {
		__ASM volatile ("yield");
	    }

	    // Configure PLL
	    uint32_t pll = CMSDK_PSEQ_NONSECURE->PLL;
	    PSEQ_PLL__DIVACCESS__SET(pll);
	    PSEQ_PLL__DIVREF__MODIFY(pll, 1);
	    PSEQ_PLL__DIVFB__MODIFY(pll, sel);
	    PSEQ_PLL__DIVOUT__MODIFY(pll, 1);
	    PSEQ_PLL__DIV2OUT__MODIFY(pll, div2 ? 1 : 0);
	    CMSDK_PSEQ_NONSECURE->PLL = pll;
	} WRPR_CTRL_POP();

	// Enable PLL
	CMSDK_CLKRSTGEN_NONSECURE->PLL_CTRL =
	    CLKRSTGEN_PLL_CTRL__PLL_ENABLE__MASK;
    }
    if (!commit) {
	return;
    }

    while (!CLKRSTGEN_CONFIGURATION__PLL_READY__READ(
	CMSDK_CLKRSTGEN_NONSECURE->CONFIGURATION)) {
	__ASM volatile ("yield");
    }

    CMSDK_CLKRSTGEN_NONSECURE->CLKSYNC =
	CLKRSTGEN_CLKSYNC__DIV_VAL__WRITE(sel >> (div2 ? 1 : 0)) |
	CLKRSTGEN_CLKSYNC__CLK16_SRC__MASK;
}

#ifdef UNSUPPORTED_64_DIV_2
__CLKRSTGEN_SET_STATIC_INLINE void
at_clkrstgen_set_pll_div2(uint8_t sel, bool set, bool commit)
{
    at_clkrstgen_enable_pll(sel, false, set, commit);
    if (!commit) {
	return;
    }

    // To prevent multiple bit transitions, take everything back to zero
    at_clkrstgen_set_clk16x(CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL_STAT);

    // Then select PLL/2
    CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL =
	CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__WRITE(CLUSTER_SEL__PLL_DIV2) |
	CLKRSTGEN_CLK_BP_CTRL__PLL_DIV2_CLUSTER_SEL__MASK;
}
#endif

__CLKRSTGEN_SET_STATIC_INLINE void
at_clkrstgen_set_pll(uint8_t sel, bool set, bool commit)
{
    at_clkrstgen_enable_pll(sel, false, set, commit);
    if (!commit) {
	return;
    }

    // To prevent multiple bit transitions, take everything back to zero
    at_clkrstgen_set_clk16x(CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL_STAT);

    // Then select PLL
    CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL =
	CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__WRITE(CLUSTER_SEL__PLL) |
	CLKRSTGEN_CLK_BP_CTRL__PLL_CLUSTER_SEL__MASK;
}

__CLKRSTGEN_SET_STATIC_INLINE void
at_clkrstgen_set_div2_pll(uint8_t sel, bool set, bool commit)
{
    at_clkrstgen_enable_pll(sel, true, set, commit);
    if (!commit) {
	return;
    }

    // To prevent multiple bit transitions, take everything back to zero
    at_clkrstgen_set_clk16x(CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL_STAT);

    // Then select PLL
    CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL =
	CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__WRITE(CLUSTER_SEL__PLL) |
	CLKRSTGEN_CLK_BP_CTRL__PLL_CLUSTER_SEL__MASK;
}

__CLKRSTGEN_SET_STATIC_INLINE void
at_clkrstgen_asic_set_bp_hint(uint32_t freq, bool set, bool commit)
{
#ifdef __ICCARM__
    if (freq <= 500000) {
	at_clkrstgen_set_slow(7, set, commit);
    } else if (freq <= 1000000) {
	at_clkrstgen_set_slow(6, set, commit);
    } else if (freq <= 2000000) {
	at_clkrstgen_set_slow(2, set, commit);
    } else if (freq <= 4000000) {
	at_clkrstgen_set_slow(3, set, commit);
    } else if (freq <= 8000000) {
	at_clkrstgen_set_slow(1, set, commit);
    } else if (freq <= 16000000) {
	at_clkrstgen_set_clk16x(commit);
    } else if (freq <= 32000000) {
	at_clkrstgen_set_div2_pll(4, set, commit);
#ifdef UNSUPPORTED_64_DIV_2
    } else if (freq == 32000001) {
	at_clkrstgen_set_pll_div2(4, set, commit);
#endif
    } else if (freq <= 48000000) {
	at_clkrstgen_set_pll(3, set, commit);
    } else /* 64MHz */ {
	at_clkrstgen_set_pll(4, set, commit);
    }
#else // __ICCARM__
    switch (freq) {
	case 0 ... 500000: at_clkrstgen_set_slow(7, set, commit); break;
	case 500001 ... 1000000: at_clkrstgen_set_slow(6, set, commit); break;
	case 1000001 ... 2000000: at_clkrstgen_set_slow(2, set, commit); break;
	case 2000001 ... 4000000: at_clkrstgen_set_slow(3, set, commit); break;
	case 4000001 ... 8000000: at_clkrstgen_set_slow(1, set, commit); break;
	case 8000001 ... 16000000: at_clkrstgen_set_clk16x(commit); break;
	case 16000001 ... 32000000: at_clkrstgen_set_div2_pll(4, set, commit); break;
	case 32000001:
#ifdef UNSUPPORTED_64_DIV_2
	    at_clkrstgen_set_pll_div2(4, set, commit); break;
#endif
	case 32000002 ... 48000000: at_clkrstgen_set_pll(3, set, commit); break;
	default: /* 64MHz */ at_clkrstgen_set_pll(4, set, commit); break;
    }
#endif // __ICCARM__

    if (!commit) {
	return;
    }

    uint32_t clk_bp_ctrl = CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL;

    // Disable PLL when not needed
    if (!(CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__READ(clk_bp_ctrl) &
	(CLUSTER_SEL__PLL | CLUSTER_SEL__PLL_DIV2))) {
	CLKRSTGEN_CLKSYNC__CLK16_SRC__MODIFY(
	    CMSDK_CLKRSTGEN_NONSECURE->CLKSYNC, 0);
	CMSDK_CLKRSTGEN_NONSECURE->PLL_CTRL = 0;
	CMSDK_CLKRSTGEN_NONSECURE->CLKSYNC = 0;
    }

    // Disable HPC when not needed
    if (!CLKRSTGEN_CLK_BP_CTRL__DOUBLER_CLUSTER_SEL__READ(clk_bp_ctrl)) {
	WRPR_CTRL_PUSH(CMSDK_PSEQ_NONSECURE, WRPR_CTRL__CLK_ENABLE) {
	    PSEQ_XTAL_BITS1__CLKHPC_EN__CLR(CMSDK_PSEQ_NONSECURE->XTAL_BITS1);
	} WRPR_CTRL_POP();
    }
}

__CLKRSTGEN_SET_STATIC_INLINE void
at_clkrstgen_fpga_set_bp(uint32_t index, uint32_t freq, bool set, bool commit)
{
#ifdef __ICCARM__
    if (freq <= 500000) {
	at_clkrstgen_set_slow(7, set, commit);
    } else if (freq <= 1000000) {
	at_clkrstgen_set_slow(6, set, commit);
    } else if (freq <= 2000000) {
	at_clkrstgen_set_slow(2, set, commit);
    } else if (freq <= 4000000) {
	at_clkrstgen_set_slow(3, set, commit);
    } else if (freq <= 8000000) {
	at_clkrstgen_set_slow(1, set, commit);
    } else if (freq <= 16000000) {
	at_clkrstgen_set_clk16x(commit);
    } else if (freq <= 32000000) {
	at_clkrstgen_set_doubler(set, commit);
    } else /* 48MHz */ {
	if (index != 5) {
	    at_clkrstgen_set_pll(0, set, commit);
	} else {
	    at_clkrstgen_set_doubler(set, commit);
	}
    }
#else
    switch (freq) {
	case 0 ... 500000: at_clkrstgen_set_slow(7, set, commit); break;
	case 500001 ... 1000000: at_clkrstgen_set_slow(6, set, commit); break;
	case 1000001 ... 2000000: at_clkrstgen_set_slow(2, set, commit); break;
	case 2000001 ... 4000000: at_clkrstgen_set_slow(3, set, commit); break;
	case 4000001 ... 8000000: at_clkrstgen_set_slow(1, set, commit); break;
	case 8000001 ... 16000000: at_clkrstgen_set_clk16x(commit); break;
	default: /* 48MHz */
	    if (index != 5) {
		at_clkrstgen_set_pll(0, set, commit);
		break;
	    }
	    // Fall through
	case 16000001 ... 32000000:
	    at_clkrstgen_set_doubler(set, commit); break;
    }
#endif
}

__CLKRSTGEN_SET_STATIC_INLINE void
at_clkrstgen_set_bp_hint(uint32_t freq, bool set, bool commit)
{
    uint32_t config = CMSDK_CLKRSTGEN_NONSECURE->CONFIGURATION;
    uint32_t index = CLKRSTGEN_CONFIGURATION__INDEX__READ(config);
    switch (index) {
	case 0: at_clkrstgen_asic_set_bp_hint(freq, set, commit); break;
	case 1:
	case 3:
	case 5: at_clkrstgen_fpga_set_bp(index, freq, set, commit); break;
	default: break;
    }
}

__CLKRSTGEN_SET_STATIC_INLINE void
at_clkrstgen_set_bp(uint32_t freq)
{
    at_clkrstgen_set_bp_hint(freq, true, true);
}
