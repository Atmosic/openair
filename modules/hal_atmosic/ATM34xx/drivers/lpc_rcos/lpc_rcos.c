/**
 ******************************************************************************
 *
 * @file lpc_rcos.c
 *
 * @brief Low Power Clock (RC Oscillator based)
 *
 * Copyright (C) Atmosic 2020-2025
 *
 ******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#endif

#include "arch.h"
#include <inttypes.h>
#include "calibration.h"

#include "at_wrpr.h"
#include "at_apb_rcos_cal_regs_core_macro.h"
#include "at_lc_regs_core_macro.h"
#include "at_lc_states.h"
#include "pc_ctr_sleep.h"
#include "timer.h"

// Debugs - to enable, change undef to define
#undef DEBUG_LPC_RCOS
#undef DEBUG_LPC_RCOS_STAT_NOISY


#define CMSDK_RCOS_CAL CMSDK_RCOS_CAL_NONSECURE

/// Duration for an RCOS measurement to remain valid in 32KHz cycles
#define LPC_RCOS_VALID	(5 * 32768)	// 5 seconds

#ifdef FORCE_LPC_RCOS
#define DEBUG_LPC_RCOS
#endif

static uint32_t lpc_rcos_last_valid;

typedef struct {
    uint32_t lp_hz;
    uint32_t prev_lp_hz;
    bool no_high_prec;
#ifdef FORCE_LPC_RCOS
    bool xtal;
#endif
} lpc_rcos_cal_t;

static lpc_rcos_cal_t lpc_rcos_actv;

typedef struct {
    uint32_t set_lphz;
    uint32_t null_dur;
} stat_t;

static stat_t stat;

static uint32_t
lpc_rcos_valid(void)
{
    // RCOS previously measured?
    if (!lpc_rcos_actv.lp_hz) {
	return (0);
    }

    uint32_t tick = atm_get_sys_time();
    uint32_t age = tick - lpc_rcos_last_valid;
    return ((age < LPC_RCOS_VALID) ? LPC_RCOS_VALID - age : 0);
}

#define RCOS_CAL_WRPR_CTRL (WRPR_CTRL__CLK_SEL | WRPR_CTRL__CLK_ENABLE)

static bool lpc_rcos_cal(lpc_rcos_cal_t *cal)
{
    // Perform new measurement
    bool cal_valid = false;

    do {
	if (WRPR_CTRL_GET(CMSDK_RCOS_CAL) != RCOS_CAL_WRPR_CTRL) {
	    WRPR_CTRL_SET(CMSDK_RCOS_CAL, RCOS_CAL_WRPR_CTRL);

	    // Go!
	    CMSDK_RCOS_CAL->CAL_CTRL = RCOS_CAL_CAL_CTRL__SW_CAL__MASK;
	}

	uint32_t STAT = CMSDK_RCOS_CAL->STAT;
	if (STAT & RCOS_CAL_STAT__RUNNING__MASK) {
	    // Keep RCOS_CAL enabled
	    return (false);
	}

	cal->no_high_prec = !(STAT & RCOS_CAL_STAT__HIGH_PRECISION_RUN__MASK);
	if (cal->no_high_prec) {
	    break;
	}

	uint32_t SLOW_CLK_CNT = CMSDK_RCOS_CAL->SLOW_CLK_CNT;
	uint32_t FAST_CLK_CNT = CMSDK_RCOS_CAL->FAST_CLK_CNT;

	lpc_rcos_last_valid = atm_get_sys_time();
	uint32_t curr_lp_hz =
	    ((PCLK_ALT_FREQ * SLOW_CLK_CNT) + (FAST_CLK_CNT / 2)) /
	    FAST_CLK_CNT;
	cal->lp_hz = cal->prev_lp_hz ? (cal->prev_lp_hz + curr_lp_hz) / 2 :
	curr_lp_hz;
	cal->prev_lp_hz = curr_lp_hz;
#ifdef FORCE_LPC_RCOS
	cal->xtal = WRPRPINS_CHIPREV__RUNNING_OFF_32KHZ_XTAL__READ(
	    CMSDK_WRPR0_NONSECURE->CHIPREV);
#endif
	cal_valid = true;
    } while (0);
    WRPR_CTRL_SET(CMSDK_RCOS_CAL, WRPR_CTRL__SRESET);

    return (cal_valid);
}

static enum pc_ctr_sleep_e lpc_rcos_measure(uint64_t next_us)
{
#ifndef IS_FOR_SIM // clk_align_check needs correction after every deep sleep
    if (next_us == UINT64_MAX) {
	// Don't need to worry about clock correction
	return PC_CTR_ATLC_TO_SLEEP;
    }
#endif

    uint32_t cycles = lpc_rcos_valid();
    if (cycles) {
	// No need to remeasure at this time
	return PC_CTR_ATLC_TO_SLEEP;
    }

    if (next_us < 5 * US_PER_MS) {
	// Next ATLC event too soon
	return PC_CTR_CPU_SLEEP;
    }

    __UNUSED uint32_t then = atm_get_sys_time();
    while (!lpc_rcos_cal(&lpc_rcos_actv)) {
	ASSERT_ERR(!lpc_rcos_actv.no_high_prec);

	YIELD();
	ASSERT_ERR(atm_get_sys_time() - then < 164); // 5ms
    }

    uint32_t lp_hz = lpc_rcos_actv.lp_hz;
    pc_ctr_sleep_set_lp_hz(lp_hz, false);
    stat.set_lphz++;

    // Even if lp_hz stayed the same value, the measurement took several ms
    // to complete, so sleep needs to be recomputed.
    return PC_CTR_ACTIVE;
}

static rep_vec_err_t
lpc_rcos_schedule(void)
{
#if PLF_DEBUG && defined(DEBUG_LPC_RCOS)
    static uint32_t last_actv_lp_hz;
    if (last_actv_lp_hz != lpc_rcos_actv.lp_hz) {
	last_actv_lp_hz = lpc_rcos_actv.lp_hz;
#ifdef FORCE_LPC_RCOS
	if (lpc_rcos_actv.xtal) {
	    DEBUG_TRACE("LPC xtal active %" PRIu32 "Hz", lpc_rcos_actv.lp_hz);
	} else
#endif
	{
	    DEBUG_TRACE("LPC active %" PRIu32 "Hz", lpc_rcos_actv.lp_hz);
	}
    }

    static stat_t last_stat;
#define CHECK_STAT(__s) do { \
    if (last_stat.__s != stat.__s) { \
	last_stat.__s = stat.__s; \
	DEBUG_TRACE(#__s " %" PRIu32, stat.__s); \
    } \
} while (0)
    CHECK_STAT(null_dur);
#ifdef DEBUG_LPC_RCOS_STAT_NOISY
    CHECK_STAT(set_lphz);
#endif
#undef CHECK_STAT
#endif // PLF_DEBUG && DEBUG_LPC_RCOS

    return (RV_NEXT);
}

#ifndef CONFIG_SOC_FAMILY_ATM
__attribute__((constructor))
#endif
static void
lpc_rcos_init(void)
{
#ifndef FORCE_LPC_RCOS
    if (!CAL_PRESENT(cust_cfg, cust) || !(cust_cfg.cust &
	CUST_CAL__CUST_NO_32KHZ_XTAL_ON_BOARD__MASK)) {
	return;
    }
#endif

    // No 32KHz xtal present
    REV_HASH_CHECK(CMSDK_RCOS_CAL, RCOS_CAL);

    pc_ctr_sleep_set_max_sleep_lpc(LPC_RCOS_VALID, lpc_rcos_measure);

    RV_PLF_SCHEDULE_ADD(lpc_rcos_schedule);
}

uint32_t lpc_rcos_hz(void)
{
    uint32_t lp_hz = pc_ctr_sleep_get_lp_hz();
    return lp_hz ? lp_hz : 32768;
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int lpc_rcos_sys_init(void)
{
    lpc_rcos_init();
    return 0;
}

SYS_INIT(lpc_rcos_sys_init, PRE_KERNEL_2, 10);
#endif
