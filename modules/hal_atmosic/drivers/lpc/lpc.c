/**
 *******************************************************************************
 *
 * @file lpc.c
 *
 * @brief Low Power (crystal) Clock
 *
 * Copyright (C) Atmosic 2022-2024
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#endif

#include "arch.h"
#include "calibration.h"
#if defined(CFG_BLE_EMB) || defined(CFG_BLE_HOST)
#include "ke_timer.h"
#include "rwip_task.h"
#endif
#include "at_wrpr.h"

#if !(defined(CFG_BLE_EMB) || defined(CFG_BLE_HOST)) && \
    defined(CONFIG_SOC_FAMILY_ATM)
static void lpc_timer_expire(struct k_work *work)
{
    // Wake ble_thread in case ATLC can now go to sleep
    NVIC_SetPendingIRQ(SW_2_IRQn);
}

static K_WORK_DELAYABLE_DEFINE(lpc_work, lpc_timer_expire);
#endif

static rep_vec_err_t lpc_prevent_ble_sleep(bool *prevent)
{
    if (CMSDK_WRPR0_NONSECURE->CHIPREV &
	WRPRPINS_CHIPREV__RUNNING_OFF_32KHZ_XTAL__MASK) {
	return (RV_NEXT);
    }

    *prevent = true;
#if defined(CFG_BLE_EMB) || defined(CFG_BLE_HOST)
    // Wake up CPU in 500ms to try again
    if (!ke_timer_active(TASK_FIRST_MSG(TASK_ID_USER2), TASK_USER1)) {
	ke_timer_set(TASK_FIRST_MSG(TASK_ID_USER2), TASK_USER1, 500);
    }
#elif CONFIG_SOC_FAMILY_ATM
    if (!k_work_delayable_is_pending(&lpc_work)) {
	k_work_reschedule(&lpc_work, K_MSEC(500));
    }
#else
#error "Missing timer implementation for 500ms delay"
#endif
    return (RV_DONE);
}

#ifndef CONFIG_SOC_FAMILY_ATM
__attribute__((constructor))
#endif
static void lpc_init(void)
{
    if (!CAL_PRESENT(cust_cfg, cust) || !(cust_cfg.cust &
	(CUST_CAL__CUST_NO_32KHZ_XTAL_ON_BOARD__MASK |
	 CUST_CAL__CUST_IGNORE_32KHZ_XTAL_CHECK__MASK))) {
	// 32KHz xtal present.  Only permit BLE sleep when xtal is ready.
	RV_PREVENT_BLE_SLEEP_ADD(lpc_prevent_ble_sleep);
    }
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int lpc_sys_init(void)
{
    lpc_init();
    return 0;
}

SYS_INIT(lpc_sys_init, PRE_KERNEL_2, 10);
#endif
