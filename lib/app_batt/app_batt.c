/**
 *******************************************************************************
 *
 * @file app_batt.c
 *
 * @brief battery procedure for application layer.
 *
 * Copyright (C) Atmosic 2022-2024
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#endif
#include "arch.h"
#include <inttypes.h>
#include "app_batt.h"
#include "at_wrpr.h"
#include "pmu.h"
#include "reset.h"

#ifdef CONFIG_SOC_FAMILY_ATM
#define BROWNOUT_SUPPORT IS_ENABLED(CONFIG_BROWNOUT)
#else
#ifndef NO_BROWNOUT
#define BROWNOUT_SUPPORT 1
#else
#define BROWNOUT_SUPPORT 0
#endif
#endif // CONFIG_SOC_FAMILY_ATM

#if BROWNOUT_SUPPORT
#include "brwnout.h"
#endif

#ifndef CONFIG_SOC_FAMILY_ATM
#include "atm_log.h"
#ifndef ATM_LOG_LVL_APP_BATT
#define ATM_LOG_LVL_APP_BATT W
#endif
ATM_LOG_LOCAL_SETTING("app_batt", ATM_LOG_LVL_APP_BATT);
#include "atm_pm.h"
#include "sw_timer.h"
#include "hw_cfg.h"
#include "pinmux.h"
#include "sw_event.h"
#else
LOG_MODULE_REGISTER(app_batt, LOG_LEVEL_INF);
#undef ATM_LOG
#define ATM_LOG(MSK, fmt, ...) LOG_INF(fmt, ##__VA_ARGS__)
#include "power.h"
#endif

#if (CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT)
#ifndef CONFIG_SOC_FAMILY_ATM
static sw_timer_id_t tid_batt;
static pm_lock_id_t lock_hib;
#else
static void batt_timer_expire(struct k_work *work);
static K_WORK_DELAYABLE_DEFINE(batt_timer_work, batt_timer_expire);
#endif // CONFIG_SOC_FAMILY_ATM
#endif // CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT

#if defined(CONFIG_SOC_FAMILY_ATM) && \
    (CFG_APP_BATT_FEATURE & APP_BATT_HIB_RESTART_BIT)
static uint32_t hib_restart_duration;
#ifdef CONFIG_PM
static void app_batt_notify_pm_state_enter(enum pm_state state)
{
    if (state == PM_STATE_SOFT_OFF) {
	atm_pseq_hibernate(k_ms_to_ticks_ceil32(hib_restart_duration/10));
    }
}

static struct pm_notifier notifier = {
    .state_entry = app_batt_notify_pm_state_enter,
    .state_exit = NULL,
};
#endif // CONFIG_PM
#endif // CFG_APP_BATT_FEATURE & APP_BATT_HIB_RESTART_BIT

static dev_state_t batt_state;
static app_batt_cbs_t const *param;

#define APP_BATT_PERSIST_TAG 0x1E3C0000


static dev_state_t app_batt_state_get(void)
{
    return batt_state;
}

static void app_done(void)
{
    ATM_LOG(V, "Battery state: %d", batt_state);
    switch (batt_state) {
	case DEV_HIB: {
#if (CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT)
#ifndef CONFIG_SOC_FAMILY_ATM
	    atm_pm_unlock(lock_hib);
#elif defined(CONFIG_PM)
	    pm_policy_state_lock_put(PM_STATE_SOFT_OFF, 0);
#endif // CONFIG_SOC_FAMILY_ATM
#endif // CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT
	} break;
	case DEV_SOCOFF: {
#if BROWNOUT_SUPPORT
#if ((CFG_APP_BATT_FEATURE & APP_BATT_LPC_WAKEUP_BIT) && defined(PIN_LPCOMP_IO))
	    ATM_LOG(V, "SOC off, LPC in P%d wake up", PIN_LPCOMP_IO);
#ifndef LPC_VOLT_LVL
// 14: 1525mV 13: 1425mV 12: 1325mV
#define LPC_VOLT_LVL 13
#endif
#if (CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT)
#ifndef CONFIG_SOC_FAMILY_ATM
	    atm_pm_unlock(lock_hib);
#elif defined(CONFIG_PM)
	    pm_policy_state_lock_put(PM_STATE_SOFT_OFF, 0);
#endif // CONFIG_SOC_FAMILY_ATM
#endif // CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT
	    pmu_socoff_wakeup_lpcomp(true, PIN_LPCOMP_IO, LPC_VOLT_LVL);
	    brwnout_force_socoff();
#endif // ((CFG_APP_BATT_FEATURE & APP_BATT_LPC_WAKEUP_BIT) && defined(PIN_LPCOMP_IO))
#else
	    ATM_LOG(E, "Invalid state, please check brownout support");
#endif // BROWNOUT_SUPPORT
	} break;
	case DEV_ACTV: {
#if (CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT)
#define QUICK_TIMER_CS 1
#ifndef CONFIG_SOC_FAMILY_ATM
	    sw_timer_set(tid_batt, QUICK_TIMER_CS);
#else
	    k_timeout_t duration = K_MSEC(QUICK_TIMER_CS * 10);
	    k_work_reschedule(&batt_timer_work, duration);
#endif // CONFIG_SOC_FAMILY_ATM
#undef QUICK_TIMER_CS
#endif  // CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT
	} break;
	case DEV_INVALID:
	case DEV_RESET:
	default: {
	    ASSERT_ERR(0);
	} break;
    }
}

static void app_batt_state_set(dev_state_t sts)
{
    switch (sts) {
	case DEV_ACTV: {
	    if (batt_state == sts) {
		break;
	    }
#if (CFG_APP_BATT_FEATURE & APP_BATT_HIB_RESTART_BIT)
	    if ((batt_state != DEV_SOCOFF) &&
		!is_boot_reason(BOOT_STATUS_HIB_WKUP_TIMER)) {
#else
	    if ((batt_state != DEV_SOCOFF)) {
#endif
		batt_state = sts;
		param->app_start(app_done);
		break;
	    } else {
		sts = DEV_HIB;
	    }
	} // no break;
	case DEV_HIB: {
#if (CFG_APP_BATT_FEATURE & APP_BATT_HIB_RESTART_BIT)
#ifndef CONFIG_SOC_FAMILY_ATM
	    atm_pm_set_hib_restart_time(APP_BATT_HIB_TIME_CS);
#else
	    hib_restart_duration = APP_BATT_HIB_TIME_CS;
#endif // CONFIG_SOC_FAMILY_ATM
#endif // CFG_APP_BATT_FEATURE & APP_BATT_HIB_RESTART_BIT
	} // no break here.
	case DEV_SOCOFF: {
	    if (batt_state != sts) {
		batt_state = sts;
	    }
#if (CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT)
#ifndef CONFIG_SOC_FAMILY_ATM
	    sw_timer_clear(tid_batt);
#else
	    k_work_cancel_delayable(&batt_timer_work);
#endif // CONFIG_SOC_FAMILY_ATM
#endif // CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT
	    param->app_stop(app_done);
	} break;
	case DEV_RESET:
	case DEV_INVALID:
	default: {
	    ASSERT_ERR(0);
	} break;
    }
}

#if (CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT)
static void app_batt_sample_cb_1st(uint16_t lvl, int32_t mvolt)
{
    ATM_LOG(V, "1st - lvl: %d%%, mvolt: %" PRId32, lvl / 100, mvolt);
}
#endif

static void app_batt_sample_cb(uint16_t lvl, int32_t mvolt)
{
    if (batt_state == DEV_ACTV) {
	param->level_update(lvl, mvolt);
#if (CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT)
#ifndef CONFIG_SOC_FAMILY_ATM
	sw_timer_set(tid_batt, (lvl > APP_BATT_LOW_BATTERY_PERCENTAGE ) ?
	    APP_BATT_HIGH_POLL_TIME_CS : APP_BATT_LOW_POLL_TIME_CS);
#else
	k_timeout_t duration = K_MSEC(((lvl > APP_BATT_LOW_BATTERY_PERCENTAGE) ?
            APP_BATT_HIGH_POLL_TIME_CS : APP_BATT_LOW_POLL_TIME_CS) * 10);
	k_work_reschedule(&batt_timer_work, duration);
#endif // CONFIG_SOC_FAMILY_ATM
#endif // CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT
    }
}

#if (CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT)
#ifndef CONFIG_SOC_FAMILY_ATM
static void batt_timer_msg_ind(sw_timer_id_t idx, void const *ctx)
{
#define RETRY_TIME_CS 100
    if (!batt_model()->sample(app_batt_sample_cb)) {
	sw_timer_set(tid_batt, RETRY_TIME_CS);
    }
#undef RETRY_TIME_CS
}
#else
static void batt_timer_expire(struct k_work *work)
{
#define RETRY_TIME_CS 100
    if (!batt_model()->sample(app_batt_sample_cb)) {
	k_timeout_t duration = K_MSEC(RETRY_TIME_CS * 10);
	k_work_reschedule(&batt_timer_work, duration);
    }
#undef RETRY_TIME_CS
}
#endif // CONFIG_SOC_FAMILY_ATM
#endif // (CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT)

static void app_batt_set_flag(uint8_t idx, bool value)
{
    ASSERT_INFO(idx < 16, idx, 16);

    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE);
    {
	if ((CMSDK_PSEQ->PERSISTENT0 & 0xFFFF0000) != APP_BATT_PERSIST_TAG) {
	    CMSDK_PSEQ->PERSISTENT0 = APP_BATT_PERSIST_TAG;
	}
	if (value) {
	    CMSDK_PSEQ->PERSISTENT0 |= (1 << idx);
	} else {
	    CMSDK_PSEQ->PERSISTENT0 &= ~(1 << idx);
	}
    }
    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_DISABLE);
}

static bool app_batt_get_flag(uint8_t idx)
{
    bool flag;
    ASSERT_INFO(idx < 16, idx, 16);
    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE);
    {
	if ((CMSDK_PSEQ->PERSISTENT0 & 0xFFFF0000) != APP_BATT_PERSIST_TAG) {
	    CMSDK_PSEQ->PERSISTENT0 = APP_BATT_PERSIST_TAG;
	}
	flag = !!(CMSDK_PSEQ->PERSISTENT0 & (1 << idx));
    }
    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_DISABLE);
    return flag;
}

#ifdef CFG_CABLE_CHARGE
static bool app_batt_cable(bool in, uint8_t level)
{
    if (param->cable) {
	return param->cable(in, level);
    }
    return false;
}
#endif

void app_batt_start(app_batt_cbs_t const *init)
{
    // boot or wakeup from HIB
    if (batt_state == DEV_INVALID) {
	batt_state = is_boot_type(TYPE_SOCOFF) ? DEV_SOCOFF :
	    ((is_boot_type(TYPE_RESET) || is_boot_type(TYPE_POWER_ON)) ?
	    DEV_RESET : DEV_HIB);
    }

    static batt_cbs const cbs = {
	.state = {
	    .get = app_batt_state_get,
	    .set = app_batt_state_set,
	},
	.flag = {
	    .set = app_batt_set_flag,
	    .get = app_batt_get_flag,
	},
#ifdef CFG_CABLE_CHARGE
	.cable = app_batt_cable,
#endif
    };

    param = init;
    batt_model()->init(&cbs);
#if (CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT)
#ifndef CONFIG_SOC_FAMILY_ATM
    tid_batt = sw_timer_alloc(batt_timer_msg_ind, NULL);
    lock_hib = atm_pm_alloc(PM_LOCK_HIBERNATE);
    atm_pm_lock(lock_hib);
#else
#ifdef CONFIG_PM
    pm_notifier_register(&notifier);
    pm_policy_state_lock_get(PM_STATE_SOFT_OFF, 0);
#endif // CONFIG_PM
#endif // CONFIG_SOC_FAMILY_ATM
    batt_model()->sample(app_batt_sample_cb_1st);
#endif // CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT
#if BROWNOUT_SUPPORT
#if ((CFG_APP_BATT_FEATURE & APP_BATT_LPC_WAKEUP_BIT) && defined(PIN_LPCOMP_IO))
    pmu_socoff_wakeup_lpcomp(false, PIN_LPCOMP_IO, LPC_VOLT_LVL);
#endif
#endif // BROWNOUT_SUPPORT
}

#if (CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT)
void app_batt_stop(void)
{
#if (CFG_APP_BATT_FEATURE & APP_BATT_HIB_RESTART_BIT)
#ifndef CONFIG_SOC_FAMILY_ATM
    atm_pm_set_hib_restart_time(APP_BATT_HIB_TIME_CS);
#else
    hib_restart_duration = APP_BATT_HIB_TIME_CS;
#endif // CONFIG_SOC_FAMILY_ATM
#endif // CFG_APP_BATT_FEATURE & APP_BATT_HIB_RESTART_BIT
#ifndef CONFIG_SOC_FAMILY_ATM
    sw_timer_clear(tid_batt);
    atm_pm_unlock(lock_hib);
#else
    k_work_cancel_delayable(&batt_timer_work);
#ifdef CONFIG_PM
    pm_policy_state_lock_put(PM_STATE_SOFT_OFF, 0);
#endif // CONFIG_PM
#endif // CONFIG_SOC_FAMILY_ATM
}
#else
bool app_batt_get_level(void)
{
    return batt_model()->sample(app_batt_sample_cb);
}
#endif // CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT
