/**
 *******************************************************************************
 *
 * @file radio_hal_ble_cte.h
 *
 * @brief BLE CTE driver
 *
 * Copyright (C) Atmosic 2024-2025
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup RADIO_HAL_BLE_CTE RADIO_HAL_BLE_CTE
 * @ingroup DRIVERS
 * @brief Ble cte driver interface
 * @{
 */

#include "arch.h"
#include "at_lc_regs_core_macro.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __ATLC_LC_DF_CTRL0_MACRO__
#define REF_IQ_SAMPL_NUM 8

/**
 * @brief Enable CTE Tx functionality
 *
 * @param[in] is_conn True for connection packets, otherwise for connectionless
 */
void atm_mac_ble_cte_enable_tx(bool is_conn);

/**
 * @brief Enable CTE Rx functionality
 *
 * @param[in] slot_dur_is_2us True for 2us slot duration, otherwise 1us
 * @param[in] is_conn True for connection packets, otherwise for connectionless
 */
void atm_mac_ble_cte_enable_rx(bool slot_dur_is_2us, bool is_conn);

/**
 * @brief Disable CTE functionality
 */
void atm_mac_ble_cte_disable(void);

/**
 * @brief Get CTE IQ samples
 *
 * @param[out] smpl_num Return I/Q sample number
 * @param[out] i_buf I samples are copied to i_buf
 * @param[out] q_buf Q samples are copied to q_buf
 */
__NONNULL_ALL
void atm_mac_ble_cte_get_iq_samples(uint8_t *smpl_num, int8_t *i_buf, int8_t
    *q_buf);

/**
 * @brief Initialize CTE
 */
void atm_mac_ble_cte_init(void);

#ifdef __cplusplus
}
#endif
#endif
/// @}
