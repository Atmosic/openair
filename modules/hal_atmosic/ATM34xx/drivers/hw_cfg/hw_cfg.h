/**
 ******************************************************************************
 *
 * @file hw_cfg.h
 *
 * @brief Hardware Configuration
 *
 * Copyright (C) Atmosic 2022-2025
 *
 ******************************************************************************
 */

#pragma once

/**
 * @defgroup HWCFG HWCFG
 * @ingroup DRIVERS
 * @brief User driver to apply hardware configuration
 * @{
 */

#include "sec_hw_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

struct hw_cfg_scan_params {
    uint32_t agctime2;
    uint32_t agcpwr2;
};

/**
 * @brief Return the ROM version
 *
 * @return ROM version
 */
rom_version_t hw_cfg_rom_version(void);

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
 * @brief Enable/Disable analog LDO
 * @param[in] enable true/false
 */
void hw_cfg_set_ldo(bool enable);

/**
 * @brief Run VCO calibration
 * @param[in] cal_cmd VCO_CAL_CMD_START / VCO_CAL_CMD_STOP
 */
typedef enum {
    VCO_CAL_CMD_START,
    VCO_CAL_CMD_STOP,
} vco_cal_cmd_t;
void hw_cfg_run_vco_cal(vco_cal_cmd_t cal_cmd);

/**
 * @brief HW configuration when CS is enabled
 * @param[in] enable true/false
 * @param[in] is_initiator true/false
 */
void hw_cfg_cs_enable(bool enable, bool is_initiator);

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

extern rom_version_t rom_version;

__INLINE void hw_cfg_optimize_scan_params(bool active_scan,
    struct hw_cfg_scan_params *params)
{
}

__INLINE void hw_cfg_restore_scan_params(struct hw_cfg_scan_params *params)
{
}

__INLINE void hw_cfg_max_interference_perf(void)
{
}

__INLINE void hw_cfg_max_range_perf(void)
{
}

__INLINE void hw_cfg_single_link_dynamic_rf_mode_ctrl(bool enable)
{
}

__INLINE void hw_cfg_dynamic_rf_mode_ctrl_reg(hw_cfg_dynamic_rf_mode_t cb)
{
}

__INLINE void hw_cfg_optimize_rx_scan(scan_cfg_id_t scan_cfg_id)
{
}

__INLINE void hw_cfg_restore_rx_scan(scan_cfg_id_t scan_cfg_id)
{
}

#ifdef __cplusplus
}
#endif

/// @} HWCFG
