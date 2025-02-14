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
#include "rwip.h"
#include "reg_ipcore.h"

#include "at_wrpr.h"
#include "at_apb_rcos_cal_regs_core_macro.h"
#include "at_apb_pseq_regs_core_macro.h"
#include "timer.h"


// Debugs - to enable, change undef to define
#undef DEBUG_LPC_RCOS
#undef DEBUG_LPC_RCOS_STAT_NOISY


#define CMSDK_RCOS_CAL CMSDK_RCOS_CAL_NONSECURE

#ifdef IS_FOR_SIM
#define LPC_RCOS_OFFSET 0
#else
#define LPC_RCOS_OFFSET 5
#endif

/// Need 4ms in deep sleep to measure LPC
#define LPC_RCOS_CAL_WAKEUP_US 4000

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
    uint32_t ble_asleep;
    uint32_t set_lphz;
    uint32_t valid;
    uint32_t upd;
    uint32_t null_dur;
} stat_t;

static stat_t stat;

static uint32_t
lpc_rcos_get_sys_time(void)
{
    return (atm_get_sys_time());
}

static uint32_t
lpc_rcos_valid(void)
{
    // RCOS previously measured?
    if (!lpc_rcos_actv.lp_hz) {
	return (0);
    }

    uint32_t tick = lpc_rcos_get_sys_time();
    uint32_t age = tick - lpc_rcos_last_valid;
    return ((age < LPC_RCOS_VALID) ? LPC_RCOS_VALID - age : 0);
}

#define RCOS_CAL_WRPR_CTRL (WRPR_CTRL__CLK_SEL | WRPR_CTRL__CLK_ENABLE)

static bool
lpc_rcos_cal(lpc_rcos_cal_t *cal, int32_t offset)
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

	lpc_rcos_last_valid = lpc_rcos_get_sys_time();
	uint32_t curr_lp_hz = (((PCLK_ALT_FREQ * SLOW_CLK_CNT) +
	    (FAST_CLK_CNT / 2)) / FAST_CLK_CNT) + offset;
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

static bool lpc_rcos_need_remeasure;

static rep_vec_err_t
lpc_rcos_prevent_ble_sleep(bool *prevent)
{
    uint32_t cycles = lpc_rcos_valid();
    if (cycles) {
	lpc_rcos_need_remeasure = false;
	uint32_t lp_hz = lpc_rcos_actv.lp_hz;
	rwip_set_lp_hz(lp_hz);
	stat.set_lphz++;
	return RV_NEXT;
    }

    lpc_rcos_need_remeasure = true;
    // Wakeup will be forced for remeasure, so extend wakeup time
    ip_enbpreset_pack(atm_us_to_lpc(LPC_RCOS_CAL_WAKEUP_US),
	atm_us_to_lpc(LPC_RCOS_CAL_WAKEUP_US), ip_enbpreset_twrm_getf());
    return RV_NEXT;
}

static rep_vec_err_t
lpc_rcos_to_deep_sleep(bool *pseq_sleep, uint32_t *int_set, bool ble_asleep,
    int32_t ble_sleep_duration)
{
    // Don't mess with retn if BLE didn't just enter deep sleep
    if (ble_asleep) {
	stat.ble_asleep++;
	return (RV_NEXT);
    }

    if (!ble_sleep_duration) {
	// Don't need to worry about clock correction
	return (RV_NEXT);
    }

    // Will cal be valid for wakeup?
    if (!lpc_rcos_need_remeasure) {
	stat.valid++;
	return (RV_NEXT);
    }

    // Wake up right away - recompute sleep durations
    // External wakeup must be enabled for WREQ to work
    ASSERT_ERR(!ip_deepslcntl_extwkupdsb_getf());
    // Assert WREQ signal
    WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE) {
	CMSDK_PSEQ->OVERRIDES5 |= PSEQ_OVERRIDES5__OVERRIDE_WREQ__MASK |
	    PSEQ_OVERRIDES5__OVERRIDE_WREQ_VAL__MASK;
    } WRPR_CTRL_POP();

#if PLF_DEBUG
    uint32_t start = lpc_rcos_get_sys_time();
#endif
    while (!lpc_rcos_cal(&lpc_rcos_actv, LPC_RCOS_OFFSET)) {
	ASSERT_ERR(!lpc_rcos_actv.no_high_prec);

	// Increase PARAM_ID_OSC_WAKEUP_TIME and
	// PARAM_ID_EXT_WAKEUP_TIME if this assert fires.
	ASSERT_INFO(ip_deepslcntl_deep_sleep_on_getf(), start,
	    lpc_rcos_get_sys_time());

	YIELD();
    }
    stat.upd++;

    // Clear WREQ signal
    WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE) {
	PSEQ_OVERRIDES5__OVERRIDE_WREQ__CLR(CMSDK_PSEQ->OVERRIDES5);
    } WRPR_CTRL_POP();

    // BLE waking up - don't involve the PSEQ
    return (RV_DONE);
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
    CHECK_STAT(ble_asleep);
    CHECK_STAT(set_lphz);
    CHECK_STAT(valid);
    CHECK_STAT(upd);
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
    rwip_set_twmin(LPC_RCOS_CAL_WAKEUP_US);

    RV_PREVENT_BLE_SLEEP_ADD(lpc_rcos_prevent_ble_sleep);
    RV_PLF_TO_DEEP_SLEEP_ADD(lpc_rcos_to_deep_sleep);

    RV_PLF_SCHEDULE_ADD(lpc_rcos_schedule);
}

uint32_t lpc_rcos_hz(void)
{
    uint32_t lp_hz = rwip_get_lp_hz();
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
