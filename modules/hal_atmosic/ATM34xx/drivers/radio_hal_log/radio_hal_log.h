/**
 *******************************************************************************
 *
 * @file radio_hal_log.h
 *
 * @brief MAC log driver
 *
 * Copyright (C) Atmosic 2023-2025
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup RADIO_HAL_LOG RADIO_HAL_LOG
 * @ingroup DRIVERS
 * @brief Radio driver interface of log
 * @{
 */

#include "atm_utils_math.h"

#include "radio_status.h"

#ifdef __cplusplus
extern "C" {
#endif

// DEPTH should be power of 2
#define ATM_MAC_LOG_DEPTH 4
#define ATM_MAC_LOG_MAX_PARA_NUM 3

typedef enum atm_mac_log_type_e {
    BLE_IFS_INFO,
    LATENCY_ATLC,
    LATENCY_154,
    LATENCY_FRC,
    LATENCY_WAKE,
    IRQ_154_ERR,
    BLE_TX_REQ_IN_TX_ERR,
    ATM_MAC_LOG_TYPE_COUNT
} atm_mac_log_type_t;

typedef struct {
    uint32_t time_in_past;
    uint32_t txuf;
    uint32_t rxof;
    uint32_t ifs_info;
} ble_stat_t;

typedef struct {
    uint32_t status[ATM_MAC_STATUS_NUM];
    uint32_t filter_results[ATM_MAC_154_FILTER_NUM];
} ieee154_stat_t;

/**
 * @brief Margin profiling information
 *
 * Allocate a struct for margin result to measure
 */
typedef struct {
    int32_t min_cmd_mg; /*!< Minimum observed due time - set command time
	margin, in microseconds */
    int32_t min_pkt_mg; /*!< Minimum observed due time - set packet time
	margin, in microseconds */
} profiling_stat_t;

typedef struct {
    ble_stat_t ble;
    profiling_stat_t prof;
    ieee154_stat_t ieee154;
} atm_mac_stat_t;

typedef struct {
    uint16_t type;
    uint32_t param[ATM_MAC_LOG_MAX_PARA_NUM];
} atm_mac_log_entry_t;

typedef struct {
    /// updated exclusively in interrupt context
    uint16_t seq_num;
    /// updated exclusively in interrupt context
    uint16_t w_cnt;
    /// updated exclusively in non-interrupt context
    uint16_t r_cnt;
    atm_mac_log_entry_t entry[ATM_MAC_LOG_DEPTH];
} atm_mac_log_t;

extern atm_mac_stat_t mac_stat;
extern atm_mac_log_t mac_log;

#ifdef CFG_PLF_DEBUG

#define ATM_MAC_STAT_UPD(__p, __s) do { \
    mac_stat.__p.__s++; \
} while (0)

/**
 * @brief atm_mac_log api
 *
 * @param[in] type Atm mac log type
 * @param[in] param0 Parameter#0
 * @param[in] param1 Parameter#1
 * @param[in] param2 Parameter#2
 */
__STATIC_INLINE
void atm_mac_log(atm_mac_log_type_t type, uint32_t param0, uint32_t param1,
    uint32_t param2)
{
    if ((uint16_t)(mac_log.w_cnt - mac_log.r_cnt) < ATM_MAC_LOG_DEPTH) {
	atm_mac_log_entry_t *entry = &mac_log.entry[mac_log.w_cnt %
	    ATM_MAC_LOG_DEPTH];
	entry->type = type;
	entry->param[0] = param0;
	entry->param[1] = param1;
	entry->param[2] = param2;
	mac_log.w_cnt++;
    }
    mac_log.seq_num++;
}

/**
 * @brief record minimum
 *
 * @param[in] pMin pointer to current minimum
 * @param[in] value value compared to current minimum
 */
__STATIC_INLINE
void atm_mac_stat_min_margin_upd(int32_t* pMin, int32_t value)
{
    *pMin = ATM_MIN(*pMin, value);
}

#define ATM_MAC_LOG(type, param0, param1, param2) do { \
    atm_mac_log(type, param0, param1, param2); \
} while (0)

#define ATM_MAC_STAT_MIN_MARGIN_UPD(pMin, value) do { \
    atm_mac_stat_min_margin_upd(pMin, value); \
} while (0)
#else
#define ATM_MAC_STAT_UPD(__p, __s) do { \
} while (0)

#define ATM_MAC_STAT_MIN_MARGIN_UPD(pMin, value) do { \
} while (0)

#define ATM_MAC_LOG(type, param0, param1, param2) do { \
} while (0)
#endif // CFG_PLF_DEBUG

/**
 * @brief Get filter results for last receive operation
 * @return Pointer to array of counters for each
 * @ref atm_mac_154_filter_result_t
 */
__STATIC_INLINE uint32_t *atm_mac_154_get_filter_results(void)
{
    return mac_stat.ieee154.filter_results;
}

#ifdef __cplusplus
}
#endif

/// @}
