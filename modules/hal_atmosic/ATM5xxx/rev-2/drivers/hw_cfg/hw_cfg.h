/**
 ******************************************************************************
 *
 * @file hw_cfg.h
 *
 * @brief Hardware Configuration
 *
 * Copyright (C) Atmosic 2022-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 ******************************************************************************
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "ll.h"

#ifdef __cplusplus
extern "C" {
#endif

// Provide default maximum power for configuration
#ifndef CONFIG_ATM_MAX_TX_POWER_DBM
#define CONFIG_ATM_MAX_TX_POWER_DBM 8
#endif

struct hw_cfg_scan_params {
    uint32_t agctime2;
    uint32_t agcpwr2;
};

/*
 * @brief Scan set parameters identity
 */
typedef enum {
    SCAN_CFG_ID_PASSIVE_SCAN,
    SCAN_CFG_ID_ACTIVE_SCAN,
    SCAN_CFG_ID_ADV,
    SCAN_CFG_ID_INIT,
    SCAN_CFG_ID_MAX = 32,
} scan_cfg_id_t;

/**
 * @brief Run VCO calibration
 */
typedef enum {
    VCO_CAL_CMD_START,
    VCO_CAL_CMD_STOP,
} vco_cal_cmd_t;
/**
 * @brief HW configuration when CS is enabled
 * @param[in] enable true/false
 * @param[in] is_initiator true/false
 */
void hw_cfg_cs_enable(bool enable, bool is_initiator);

/**
 * @brief Run VCO calibration
 */
void hw_cfg_run_vco_cal(vco_cal_cmd_t cal_cmd);

/**
 * @brief Force OSDAC on via override registers when CS is enabled
 * @param[in] enable true/false
 */
void hw_cfg_set_osdac_ovr(bool enable);

/**
 * @brief Update CSPHS exclude time
 * @param[in] t_pm is phase measurement time. Valid: 10,20,40
 */
uint8_t hw_cfg_update_csphs_exclude_time(uint8_t t_pm);

typedef void (*hw_cfg_dynamic_rf_mode_t)(bool);

__STATIC_FORCEINLINE void hw_cfg_optimize_scan_params(bool active_scan,
    struct hw_cfg_scan_params *params)
{
}

__STATIC_FORCEINLINE void hw_cfg_restore_scan_params(struct hw_cfg_scan_params *params)
{
}

__STATIC_FORCEINLINE void hw_cfg_max_interference_perf(void)
{
}

__STATIC_FORCEINLINE void hw_cfg_max_range_perf(void)
{
}

__STATIC_FORCEINLINE void hw_cfg_single_link_dynamic_rf_mode_ctrl(bool enable)
{
}

__STATIC_FORCEINLINE void hw_cfg_dynamic_rf_mode_ctrl_reg(hw_cfg_dynamic_rf_mode_t cb)
{
}

__STATIC_FORCEINLINE void hw_cfg_optimize_rx_scan(scan_cfg_id_t scan_cfg_id)
{
}

__STATIC_FORCEINLINE void hw_cfg_restore_rx_scan(scan_cfg_id_t scan_cfg_id)
{
}

__STATIC_FORCEINLINE void hw_cfg_set_ldo(bool enable)
{
}

#ifdef __cplusplus
}
#endif
