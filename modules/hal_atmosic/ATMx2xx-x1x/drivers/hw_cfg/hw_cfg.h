/**
 ******************************************************************************
 *
 * @file hw_cfg.h
 *
 * @brief Hardware Configuration
 *
 * Copyright (C) Atmosic 2019-2021
 *
 *
 ******************************************************************************
 */

#ifndef __HW_CFG_H__
#define __HW_CFG_H__

/**
 * @defgroup HWCFG HWCFG
 * @ingroup DRIVERS
 * @brief User driver to apply hardware configuration
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * @brief HW scan parameters
 */
struct hw_cfg_scan_params {
    uint32_t agctime2;
    uint32_t agcpwr2;
};

/*
 * @brief xtal cap. value of tag ID-NVDS_TAG_MPR_XTAL_CAP
 */
struct hw_cfg_xtal_cap_params {
    uint8_t capout;
    uint8_t capin;
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

/**
 * @brief Configure PSEQ registers
 */
extern void hw_cfg_pseq_init(void);

/**
 * @brief Configure PMU registers
 */
extern void hw_cfg_pmu_init(void);

/**
 * @brief Configure RIF registers
 */
extern void hw_cfg_rif_init(void);

/**
 * @brief Configure MDM registers
 */
extern void hw_cfg_mdm_init(void);

/**
 * @brief Configure BLE RF registers
 */
extern void hw_cfg_ble_rf_init(void);

/**
 * @brief Optimize HW params for scan
 * @param[in] active_scan active or passive scan
 * @param[out] params  unchanged HW register settings for later restoration.
 */
extern void hw_cfg_optimize_scan_params(bool active_scan, struct hw_cfg_scan_params *params);

/**
 * @brief Restore HW params after scan
 * @param[in] params  HW register setting to be restored.
 */
extern void hw_cfg_restore_scan_params(struct hw_cfg_scan_params *params);

/**
 * @brief Configure all HW registers
 */
extern void hw_cfg_init(void);

/**
 * @brief Set the crystal tuning cap
 *
 * @param[in] capout value for xocapout
 * @param[in] capin value for xocapin
 */
void hw_cfg_set_xtal_cap(uint8_t capout, uint8_t capin);

/**
 * @brief Get the crystal tuning cap
 *
 * @param[in,out] capout get xocapout value
 * @param[in,out] capin get xocapin value
 */
__NONNULL_ALL
void hw_cfg_get_xtal_cap(uint8_t *capout, uint8_t *capin);

/**
 * @brief Configure max interference performance setting
 */
extern void hw_cfg_max_interference_perf(void);

/**
 * @brief Configure max range performance setting
 */
extern void hw_cfg_max_range_perf(void);

/**
 * @brief Enable/Disable dynamic rf mode control. After enabling this function,
 *  the driver will monitor the rf status and dynamically change the rf
 *  settings. This function can only be invoked when there is only one link
 *  connected and there is no other activity like adv, scan. The user should
 *  disable it when receiving a disconnection indication.
 * @param[in] enable Turn on/off dynamic rf mode control.
 */
extern void hw_cfg_single_link_dynamic_rf_mode_ctrl(bool enable);

/**
 * @brief Register dynamic rf mode control function
 * @param[in] cb Callback for dynamic rf mode control.
 */
extern void hw_cfg_dynamic_rf_mode_ctrl_reg(hw_cfg_dynamic_rf_mode_t cb);

/**
 * @brief Optimize HW RX scan parameters for assigned passive scan, active scan,
 *  advertising, and initiation identities. When only single passive scan
 *  activity wants to optimize HW RX scan, the optimized parameters determined
 *  by ‘active_scan = false’ will be set, and when other single and concurrent
 *  activities want to optimize HW RX scan, the optimized parameters determined
 *  by ‘active_scan = true’ will be set.
 * @param[in] scan_cfg_id Optimize HW RX scan identity
 */
extern void hw_cfg_optimize_rx_scan(scan_cfg_id_t scan_cfg_id);

/**
 * @brief Restore HW RX scan parameters for assigned passive scan, active scan,
 *  advertising, and initiation identities. When all activities want to restore
 *  HW RX scan, the restored parameters will be set.
 * @param[in] scan_cfg_id Restore HW RX scan identity
 */
extern void hw_cfg_restore_rx_scan(scan_cfg_id_t scan_cfg_id);

#ifdef __cplusplus
}
#endif

/// @} HWCFG

#endif // __HW_CFG_H__
