/**
 ******************************************************************************
 *
 * @file hw_cfg.c
 *
 * @brief Hardware Configuration
 *
 * Copyright (C) Atmosic 2022-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 ******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#endif

#include "arch.h"
#include "atm_bp_clock.h"
#include "calibration.h"
#include "hw_cfg.h"
#define HW_CFG_INTERNAL_GUARD
#include "hw_cfg.ih"

#include "sec_jrnl.h"

#define ASSERT_ON_CAL_FAIL true

struct chip_info_s chip_info;
uint16_t chip_info_len;
struct cust_cfg_s cust_cfg;
uint16_t cust_cfg_len;
struct gadc_cal_s gadc_cal;
uint16_t gadc_cal_len;
struct cs_cal_s cs_cal;
uint16_t cs_cal_len;

static void hw_cfg_cal(void)
{
    sec_jrnl_ret_status_t status;

    // Fetch calibration data
    chip_info_len = sizeof(chip_info);
    status = nsc_sec_jrnl_get(ATM_TAG_CHIP_INFO, &chip_info_len, (uint8_t *)&chip_info);
    if (status != SEC_JRNL_OK) {
	DEBUG_TRACE("CHIP_INFO tag not found: %#x", status);
	chip_info_len = 0;
    }

    cust_cfg_len = sizeof(cust_cfg);
    status = nsc_sec_jrnl_get(ATM_TAG_CUST_CFG, &cust_cfg_len, (uint8_t *)&cust_cfg);
    if (status != SEC_JRNL_OK) {
	DEBUG_TRACE("CUST_CFG tag not found: %#x", status);
	cust_cfg_len = 0;
    }

    // GADC calibration data
    gadc_cal_len = sizeof(gadc_cal);
    status = nsc_sec_jrnl_get(ATM_TAG_GADC_CAL, &gadc_cal_len, (uint8_t *)&gadc_cal);
    if (status != SEC_JRNL_OK) {
	DEBUG_TRACE("GADC_CAL tag not found: %#x", status);
	gadc_cal_len = 0;
    }

    // Channel sounding calibration data
    cs_cal_len = sizeof(cs_cal);
    status = nsc_sec_jrnl_get(ATM_TAG_CS_CAL, &cs_cal_len, (uint8_t *)&cs_cal);
    if (status != SEC_JRNL_OK) {
	DEBUG_TRACE("CS_CAL tag not found: %#x", status);
	cs_cal_len = 0;
    }

    hw_cfg_core_cal();
}

static rep_vec_err_t hw_cfg_rf_wake(void)
{
    hw_cfg_radio_init();

    return (RV_NEXT);
}

#ifndef CONFIG_SOC_FAMILY_ATM
__CONSTRUCTOR_PRIO(CONSTRUCTOR_HW_CFG)
#endif
static void hw_cfg_init(void)
{
    hw_cfg_rev_hash_check();

    DEBUG_TRACE("bp_freq is %" PRIu32, atm_bp_clock_get());

    hw_cfg_cal();

    hw_cfg_core_param param = {
	.force_lpc_rcos =
#ifdef FORCE_LPC_RCOS
	    true,
#else
	    false,
#endif
	.assert_on_cal_fail = ASSERT_ON_CAL_FAIL,
	.is_for_sim =
#ifdef IS_FOR_SIM
	    true,
#else
	    false,
#endif
	.max_tx_power = CONFIG_ATM_MAX_TX_POWER_DBM,
    };

    if (!hw_cfg_core_init(&param)) {
	return;
    }

    RV_RF_WAKE_ADD(hw_cfg_rf_wake);
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int hw_cfg_sys_init(void)
{
    hw_cfg_init();
#ifdef CONFIG_DTOP_BYPASS
    extern void dtop_bypass_init_public(void);
    dtop_bypass_init_public();
#endif

    return 0;
}

SYS_INIT(hw_cfg_sys_init, PRE_KERNEL_2, 5);
#endif // CONFIG_SOC_FAMILY_ATM
