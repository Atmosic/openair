/**
 ******************************************************************************
 *
 * @file hw_cfg.c
 *
 * @brief Hardware Configuration
 *
 * Copyright (C) Atmosic 2022-2024
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
#include <string.h>
#include "sec_jrnl.h"
#include "calibration.h"
#include "workarounds.h"
#include "reset.h"
#include "hw_cfg.h"
#define HW_CFG_INTERNAL_GUARD
#include "hw_cfg_internal.h"

#include "at_wrpr.h"
#include "pmu_cfg.h"
#include "pmu.h"

struct chip_info_s chip_info;
sec_jrnl_tag_len_t chip_info_len;
struct misc_cal_s misc_cal;
sec_jrnl_tag_len_t misc_cal_len;
struct cust_cfg_s cust_cfg;
sec_jrnl_tag_len_t cust_cfg_len;
uint8_t cal_pub_addr[6];
sec_jrnl_tag_len_t cal_pub_addr_len;

static void hw_cfg_cal(void)
{
    // Fetch calibration data
    chip_info_len = sizeof(chip_info);
    if (nsc_sec_jrnl_get(ATM_TAG_CHIP_INFO, &chip_info_len,
	(uint8_t *)&chip_info) != SEC_JRNL_OK) {
	chip_info_len = 0;
    }

    misc_cal_len = sizeof(misc_cal);
    if (nsc_sec_jrnl_get(ATM_TAG_MISC_CAL, &misc_cal_len,
	(uint8_t *)&misc_cal) != SEC_JRNL_OK) {
	misc_cal_len = 0;
    }

    cust_cfg_len = sizeof(cust_cfg);
    if (nsc_sec_jrnl_get(ATM_TAG_CUST_CFG, &cust_cfg_len,
	(uint8_t *)&cust_cfg) != SEC_JRNL_OK) {
	cust_cfg_len = 0;
    }

    hw_cfg_core_cal();

    // Only try to transfer pub addr immediately after power on
    if (is_boot_type(TYPE_POWER_ON)) {
	cal_pub_addr_len = sizeof(cal_pub_addr);
	if (nsc_sec_jrnl_get(ATM_TAG_BD_ADDRESS, &cal_pub_addr_len,
		cal_pub_addr) != SEC_JRNL_OK) {
	    cal_pub_addr_len = 0;
	}
    }
}

#if !defined(CONFIG_SOC_FAMILY_ATM) || defined(CONFIG_BT)
static rep_vec_err_t hw_cfg_appm_init(void)
{
    // BLE is completely initialized now, so radio will be powered on
    WRPR_CTRL_SET(CMSDK_RADIO, WRPR_CTRL__SRESET);
    hw_cfg_radio_init();

    return (RV_NEXT);
}

static rep_vec_err_t hw_cfg_rf_wake(void)
{
    hw_cfg_radio_init();

    return (RV_NEXT);
}
#endif

#ifndef CONFIG_SOC_FAMILY_ATM
__CONSTRUCTOR_PRIO(CONSTRUCTOR_HW_CFG)
#endif
static void hw_cfg_init(void)
{
    hw_cfg_cal();

    hw_cfg_core_param param = {
	.vddpa_src = VDDPA_SRC,
	.force_lpc_rcos =
#ifdef FORCE_LPC_RCOS
	    1,
#else
	    0,
#endif
    };

    if (!hw_cfg_core_init(&param)) {
	return;
    }

    workarounds_init();

#if !defined(CONFIG_SOC_FAMILY_ATM) || defined(CONFIG_BT)
    RV_APPM_INIT_ADD(hw_cfg_appm_init);
    RV_RF_WAKE_ADD(hw_cfg_rf_wake);
#endif
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int hw_cfg_sys_init(void)
{
    hw_cfg_init();
    return 0;
}

SYS_INIT(hw_cfg_sys_init, PRE_KERNEL_2, 5);
#endif
