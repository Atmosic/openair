/**
 ******************************************************************************
 *
 * @file hw_cfg.h
 *
 * @brief Hardware Configuration
 *
 * Copyright (C) Atmosic 2021-2022
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

#ifdef __cplusplus
extern "C" {
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

typedef void (*hw_cfg_dynamic_rf_mode_t)(bool);

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
