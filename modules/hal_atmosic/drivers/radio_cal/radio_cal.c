/**
 ******************************************************************************
 *
 * @file radio_cal.c
 *
 * @brief Radio Calibration
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 ******************************************************************************
 */

#include <zephyr/kernel.h>
#include "ble_driver.h"
#include "radio_hal_frc.h"
#include "radio_hal_mgr.h"
#define HW_CFG_INTERNAL_GUARD
#include "hw_cfg.ih"

// Forward declaration of calibration_work_trigger and calibration_work_run
// prevents circular references, as this file is a set of functions that chain
// into each other infinitely. Declare them both to keep the K_WORK structs
// organized together
static void calibration_work_trigger(struct k_work *work);
static void calibration_work_run(struct k_work *work);

static K_WORK_DELAYABLE_DEFINE(calibration_trigger, calibration_work_trigger);
static K_WORK_DEFINE(calibration_run, calibration_work_run);

static void calibration_work_trigger(struct k_work *work)
{
    ARG_UNUSED(work);

    atm_mac_lock_sync();

    uint32_t now_us = atm_mac_frc_get_current_time();
    atm_mac_mgr_priority_t priority = 0;
    PRIORITY_CRITICAL_SET(priority); // Do not interrupt once started
    PRIORITY_PROTOCOL_MODIFY(priority, ATM_MAC_MGR_PROT_CAL);
    atm_mac_mgr_op_data_t calibrate = {
	.start_time = now_us,
	// Allow maximum delay before starting (35 mins)
	.latest_start_time = now_us + 0x7FFFFFFF,
	.expected_duration = 2000, // Experimentally determined
	.priority = priority,
	.protocol = ATM_MAC_MGR_PROT_CAL,
    };
    atm_mac_mgr_schedule_op(atm_mac_mgr_get_iface(), &calibrate);

    // The manager will call calibration_start when calibration can run
}

static bool calibration_start(void)
{
    k_work_submit(&calibration_run);
    return true;

    // The system workqueue will call calibration_work_run ASAP
}

static void calibration_work_run(struct k_work *work)
{
    ARG_UNUSED(work);

    hw_cfg_core_attempt_calibration();

    atm_mac_mgr_complete_op(atm_mac_mgr_get_iface(), ATM_MAC_MGR_PROT_CAL);

    atm_mac_unlock();

    // Schedule next calibration
    k_work_schedule(&calibration_trigger,
	K_MSEC(CONFIG_ATM_RADIO_CAL_REPEAT_MS));

    // The system workqueue will call calibration_work_trigger after a delay
}

static int radio_cal_init(void)
{
    atm_mac_mgr_register_deferred_api(atm_mac_mgr_get_iface(),
	ATM_MAC_MGR_PROT_CAL, calibration_start);

    // Schedule first calibration
    k_work_schedule(&calibration_trigger,
	K_MSEC(CONFIG_ATM_RADIO_CAL_REPEAT_MS));

    return 0;
}

SYS_INIT(radio_cal_init, POST_KERNEL, CONFIG_APPLICATION_INIT_PRIORITY);
