/**
 *******************************************************************************
 *
 * @file radio_hal_ble_cs.h
 *
 * @brief radio_hal_ble_cs header
 *
 * Copyright (C) Atmosic 2024-2025
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup RADIO_HAL_BLE_CS RADIO_HAL_BLE_CS
 * @ingroup DRIVERS
 * @brief Ble cs driver interface
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "radio_hal_ble.h"

/// Maxmum number of antenna path
#define MAX_N_AP 4
/// Invalid rssi value in CS
#define INVALID_CS_RSSI_VAL 0x7F

/// CS step complete callback function type
typedef bool (*atm_mac_ble_cs_step_comp_t)(uint8_t status, uint32_t start_ts);

/// Enumation CS mode
typedef enum {
    CS_MODE_0 = 0,
    CS_MODE_1,
    CS_MODE_2,
    CS_MODE_3,
    CS_MODE_STABLE,
    CS_MODE_NUM,
} cs_mode_t;

/// Structure of CS enable
typedef struct {
    atm_mac_ble_cs_step_comp_t step_cmpl_cb;
    uint16_t t_pm;
    bool enable;
    bool reset_cfo_info;
    bool is_initiator;
    atm_mac_ble_phy_t phy;
    uint8_t t_fcs;
    uint8_t t_ip1;
    uint8_t t_ip2;
    uint8_t n_ap;
    uint8_t seq_len;
    uint8_t t_sw;
} cs_enable_t;

/// Structure of CS step report
typedef struct {
    uint32_t t_dep_16m_clk;
    uint32_t t_arr_16m_clk;
    int32_t t_arr_adj;
    uint16_t t_sy_center_delta_us;
    int16_t cfo_sum;
    int16_t t_dep_adj;
    uint8_t rx_status;
    uint8_t mode;
    uint8_t ch_index;
    uint8_t seq_bit_err;
    uint8_t phs[MAX_N_AP + 1];
    int8_t rssi;
    int8_t rssi_tone[MAX_N_AP + 1];
    int8_t rssi_noise[MAX_N_AP + 1];
    bool itx_ext_prsnt;
    bool rtx_ext_prsnt;
} cs_step_rpt_type;

/**
 * @brief Set antenna swicth pattern and ext_slot_present info
 *
 * @param[in] sw_len number of switching pattern
 * @param[in] ant_id antenna id array
 * @param[in] itx_ext_prsnt initiator ext tx slot present
 * @param[in] rtx_ext_prsnt reflector ext tx slot present
 */
void atm_mac_ble_cs_set_ant_sw(uint8_t sw_len, uint8_t const *ant_id, bool
    itx_ext_prsnt, bool rtx_ext_prsnt);

/**
 * @brief CS preset cs mode right before kick CS step
 * @note Since t_tn used in this API, you shall call atm_mac_ble_cs_set_t_para()
 *	before calling this API if you want to update t_tn of the CS step
 * @param[in] cs_mode CS mode
 */
void atm_mac_ble_cs_set_mode(uint8_t cs_mode);

/**
 * @brief Set random/sounding sequence data
 *
 * @param[in] seq_len sequence length in byte
 * @param[in] itx_seq_data initator tx sequence data
 * @param[in] rtx_seq_data reflector tx sequence data
 */
void atm_mac_ble_cs_set_seq(uint8_t seq_len, uint8_t const *itx_seq_data,
    uint8_t const *rtx_seq_data);

/**
 * @brief Set sync word for initator and reflector
 *
 * @param[in] itx_sync_wrd initiator tx sync word
 * @param[in] rtx_sync_wrd reflector tx sync_word
 */
void atm_mac_ble_cs_set_sync_wrd(uint32_t itx_sync_wrd, uint32_t rtx_sync_wrd);

/**
 * @brief Kick CS step
 *
 * @param[in] due_time target anchor time
 */
void atm_mac_ble_cs_kick_step(uint32_t due_time);

/**
 * @brief Set CS channel index
 *
 * @param[in] index channel index
 */
void atm_mac_ble_cs_set_channel_index(uint8_t index);

/**
 * @brief Set CS timing related parameter
 *
 * @param[in] rx_to Rx timeout
 */
void atm_mac_ble_cs_set_t_para(uint32_t rx_to);

/**
 * @brief Get CS step report
 *
 * @param[out] rpt CS step report pointer
 */
__NONNULL(1)
void atm_mac_ble_cs_get_step_rpt(cs_step_rpt_type *rpt);

/**
 * @brief Set CS phy
 *
 * @param[in] phy target phy
 */
void atm_mac_ble_cs_set_phy(atm_mac_ble_phy_t phy);

/**
 * @brief Issue a scheduling command to enable the radio early
 *
 * @param[in] due_time target due time
 * @param[in] is_tx TX or RX command
 * @param[in] rx_to RX timeout value
 */
void atm_mac_ble_cs_set_ifs_early(uint32_t due_time, bool is_tx,
    uint32_t rx_to);

/**
 * @brief Cancel the previous scheduling command
 *
 */
void atm_mac_ble_cs_cancel_ifs(void);

/**
 * @brief Enable or disable channel sounding
 *
 * @param[in] param cs enable parameters
 */
void atm_mac_ble_cs_enable_cs(cs_enable_t *param);

/**
 * @brief Set timing critical parameter before radio on
 *
 * @param[in] mode channel sounding mode
 * @param[in] chan channel
 */
void atm_mac_ble_cs_set_critical_param(uint8_t mode, uint8_t chan);

/**
 * @brief Weak function which will be called before enabling and disabling
 *  channel sounding feature
 *
 * @param[in] enable channel sounding enable
 * @param[in] phy rate. 0 for 1M, 1 for 2M
 */
__attribute__((weak)) void atm_mac_ble_cs_enable(bool enable, uint8_t phy);

/**
 * @brief Weak function which will be called before setting channel idx
 *  channel sounding feature
 *
 * @param[in] ch channel index
 * @return true if HW channel idx update is needed
 */
__attribute__((weak)) bool atm_mac_ble_cs_set_channel(uint8_t ch);

/**
 * @brief Weak function which will be called before setting frac_cfo
 *  channel sounding feature
 *
 * @param[in] frac_cfo frac_cfo value
 * @return true if HW frac_cfo update is needed
 */
__attribute__((weak)) bool atm_mac_ble_cs_set_frac_cfo(uint32_t frac_cfo);

/**
 * @brief Enable BT 2.0 2M phy
 *
 * @param[in] enable enable BT 2.0 2M phy
 */
void atm_mac_ble_cs_enable_bt20(bool enable);

/**
 * @brief Configure additional RF DELAY
 *
 * return Additional delay, in units of 1/8 ns
 */
uint32_t atm_mac_ble_cs_get_rf_delay_one_eighth_ns(void);

/**
 * @brief Whether to enable antenna switching
 *
 * return True if feature should be enabled
 */
bool atm_mac_ble_cs_adjust_phase(void);

/**
 * @brief Enable LDO feature
 *
 * @param[in] enable True to enable, false to disable
 */
void atm_mac_ble_enable_cs_ldo(bool enable);

/**
 * @brief Turn on or off LDO feature
 *
 * @param[in] enable True to set, false to unset
 */
void atm_mac_ble_set_cs_ldo(bool enable);
#ifdef __cplusplus
}
#endif

/// @}
