/**
 *******************************************************************************
 *
 * @file radio_hal_log.c
 *
 * @brief Mac log driver
 *
 * Copyright (C) Atmosic 2023-2025
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#endif

#include "arch.h"
#include <inttypes.h>
#include "atm_utils_c.h"
#include "radio_hal_log.h"

// Debugs - to enable, change undef to define
#undef DEBUG_ATM_MAC_STAT_NOISY

#ifndef ATM_MAC_LOG_154_STATS
#if !defined(CONFIG_SOC_FAMILY_ATM) || defined(CONFIG_IEEE802154_ATM34)
#define ATM_MAC_LOG_154_STATS 1
#else
#define ATM_MAC_LOG_154_STATS 0
#endif
#endif

atm_mac_stat_t mac_stat;
atm_mac_log_t mac_log;

#ifdef CFG_PLF_DEBUG

static atm_mac_stat_t last_stat;

// These strings are used to give a human-readable name to atm_mac_log_type_t.
// The length of this array should always be equal to ATM_MAC_LOG_TYPE_COUNT.
static char const * const atm_mac_log_types[] = {
    [BLE_IFS_INFO] = "BLE_IFS_INFO",
    [LATENCY_ATLC] = "LATENCY_ATLC",
    [LATENCY_154] = "LATENCY_154",
    [LATENCY_FRC] = "LATENCY_FRC",
    [LATENCY_WAKE] = "LATENCY_WAKE",
    [IRQ_154_ERR] = "IRQ_154_ERR",
    [BLE_TX_REQ_IN_TX_ERR] = "BLE_TX_REQ_IN_TX_ERR"
};

static rep_vec_err_t
atm_mac_schedule(void)
{
    static uint16_t last_log_seq_num;
    uint16_t log_num, curr_seq_num;

    GLOBAL_INT_DISABLE();
    // Read w_cnt and seq_num atomically to make sure drop count calculation
    // is correct
    log_num = mac_log.w_cnt;
    curr_seq_num = mac_log.seq_num;
    GLOBAL_INT_RESTORE();
    log_num -= mac_log.r_cnt;
#define CHECK_SIGNED_STAT(__p, __s) do { \
    if (last_stat.__p.__s != mac_stat.__p.__s) { \
        last_stat.__p.__s = mac_stat.__p.__s; \
        DEBUG_TRACE("mac_stat:"#__p"_"#__s " %" PRIi32, mac_stat.__p.__s); \
    } \
} while (0)
#ifdef DEBUG_ATM_MAC_STAT_NOISY
    CHECK_SIGNED_STAT(prof, min_cmd_mg);
    CHECK_SIGNED_STAT(prof, min_pkt_mg);
#endif
#undef CHECK_SIGNED_STAT

#define CHECK_STAT(__p, __s) do { \
    if (last_stat.__p.__s != mac_stat.__p.__s) { \
        last_stat.__p.__s = mac_stat.__p.__s; \
        DEBUG_TRACE("mac_stat:"#__p"_"#__s " %" PRIu32, mac_stat.__p.__s); \
    } \
} while (0)
#ifdef DEBUG_ATM_MAC_STAT_NOISY
    CHECK_STAT(ble, time_in_past);
    CHECK_STAT(ble, txuf);
    CHECK_STAT(ble, rxof);
#endif
    CHECK_STAT(ble, ifs_info);
#undef CHECK_STAT

#if ATM_MAC_LOG_154_STATS
#ifdef DEBUG_ATM_MAC_STAT_NOISY
    // For stat lists, assume 0 is the normal result, and only log it
    // when noisy debug is enabled
    int start = 0;
#else
    STATIC_ASSERT(ATM_MAC_154_RX_COMPLETE_STATUS_SUCCESS == 0,
	"Success case should be 0");
    STATIC_ASSERT(ATM_MAC_154_TX_COMPLETE_STATUS_SUCCESS == 0,
	"Success case should be 0");
    STATIC_ASSERT(ATM_MAC_154_FILTER_PASS == 0, "Success case should be 0");

    int start = 1;
#endif
#define CHECK_STAT_LIST(__p, __s) do { \
    for (int i = start; i < ARRAY_LEN(mac_stat.__p.__s); i++) { \
	if (last_stat.__p.__s[i] != mac_stat.__p.__s[i]) { \
	    last_stat.__p.__s[i] = mac_stat.__p.__s[i]; \
	    DEBUG_TRACE("mac_stat:"#__p"_"#__s "[%d] %" PRIu32, i, \
		mac_stat.__p.__s[i]); \
	} \
    } \
} while (0)
    CHECK_STAT_LIST(ieee154, status);
    CHECK_STAT_LIST(ieee154, filter_results);
#undef CHECK_STAT_LIST
#endif

    if (log_num) {
	last_log_seq_num += log_num;
	if (last_log_seq_num != curr_seq_num) {
	    DEBUG_TRACE("Drop %u mac_log", (uint16_t)(curr_seq_num -
		last_log_seq_num));
	    last_log_seq_num = curr_seq_num;
	}
    }
    while (log_num--) {
	atm_mac_log_entry_t const *entry = &mac_log.entry[mac_log.r_cnt %
	    ATM_MAC_LOG_DEPTH];
	if (entry->type < ATM_MAC_LOG_TYPE_COUNT) {
	    DEBUG_TRACE("mac_log: type:%s, param:%" PRIu32 ",%" PRIu32 ",%"
		PRIu32, atm_mac_log_types[entry->type], entry->param[0],
		entry->param[1], entry->param[2]);
	} else {
	    DEBUG_TRACE("mac_log: type:%u (INVALID), param:%" PRIu32 ",%"
		PRIu32 ",%" PRIu32, entry->type, entry->param[0],
		entry->param[1], entry->param[2]);
	}
	mac_log.r_cnt++;
    }
    return (RV_NEXT);
}

#ifndef CONFIG_SOC_FAMILY_ATM
__attribute__((constructor))
#endif
static void
atm_mac_log_init(void)
{
    mac_stat.prof.min_cmd_mg = INT32_MAX;
    mac_stat.prof.min_pkt_mg = INT32_MAX;
    last_stat.prof.min_cmd_mg = INT32_MAX;
    last_stat.prof.min_pkt_mg = INT32_MAX;
    RV_PLF_SCHEDULE_ADD(atm_mac_schedule);
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int atm_mac_log_sys_init(void)
{
    atm_mac_log_init();
    return 0;
}

SYS_INIT(atm_mac_log_sys_init, PRE_KERNEL_2, 10);
#endif
#endif
