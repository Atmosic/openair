/**
 ******************************************************************************
 *
 * @file radio_hal_ble.c
 *
 * @brief BLE HAL processing
 *
 * Copyright (C) Atmosic 2022-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 ******************************************************************************
 */

#include "arch.h"
#include "radio_hal_ble.h"

#if defined(CONFIG_ATM_RADIO_HAL_BLE_LOG_STATISTICS_MS) && \
    (CONFIG_ATM_RADIO_HAL_BLE_LOG_STATISTICS_MS > 0)

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#define NUM_BLE_STATUSES (ATM_MAC_BLE_STATUS_CS_SEQ_FAILED + 1)
// Keep track of packet statuses based on the types in radio_status.h
static uint32_t packet_status_count[ATM_MAC_BLE_STATUS_CS_SEQ_FAILED + 1];
static uint32_t rx_callbacks;
static uint32_t tx_callbacks;
// Second-level callbacks to use to the application, after intercepting the main
// callback to track statistics
static atm_mac_ble_tx_cpl_cb tx_callback;
static atm_mac_ble_rx_cpl_cb rx_callback;

static void atm_mac_ble_tx_complete_default(atm_mac_status_t status)
{
    if (status <= ATM_MAC_BLE_STATUS_CS_SEQ_FAILED) {
	packet_status_count[status]++;
    }
    tx_callbacks++;
    tx_callback(status);
}

static void atm_mac_ble_rx_complete_default(atm_mac_status_t status,
    uint32_t start_offset, int8_t rssi)
{
    if (status <= ATM_MAC_BLE_STATUS_CS_SEQ_FAILED) {
	packet_status_count[status]++;
    }
    rx_callbacks++;
    rx_callback(status, start_offset, rssi);
}
#else
// Assert on BLE TX completion if no handler set
static void atm_mac_ble_tx_complete_default(atm_mac_status_t status)
{
    ASSERT_ERR(0);
}

// Assert on BLE RX completion if no handler set
static void atm_mac_ble_rx_complete_default(atm_mac_status_t status,
    uint32_t start_offset, int8_t rssi)
{
    ASSERT_ERR(0);
}
#endif

// BLE driver callbacks
atm_mac_ble_tx_cpl_cb atm_mac_ble_tx_complete_callback =
    atm_mac_ble_tx_complete_default;
atm_mac_ble_rx_cpl_cb atm_mac_ble_rx_complete_callback =
    atm_mac_ble_rx_complete_default;

void atm_mac_ble_register_tx_cpl_cb(atm_mac_ble_tx_cpl_cb tx_cpl_cb)
{
#if defined(CONFIG_ATM_RADIO_HAL_BLE_LOG_STATISTICS_MS) && \
    (CONFIG_ATM_RADIO_HAL_BLE_LOG_STATISTICS_MS > 0)
    tx_callback = tx_cpl_cb;
#else
    atm_mac_ble_tx_complete_callback = tx_cpl_cb;
#endif
}

void atm_mac_ble_register_rx_cpl_cb(atm_mac_ble_rx_cpl_cb rx_cpl_cb)
{
#if defined(CONFIG_ATM_RADIO_HAL_BLE_LOG_STATISTICS_MS) && \
    (CONFIG_ATM_RADIO_HAL_BLE_LOG_STATISTICS_MS > 0)
    rx_callback = rx_cpl_cb;
#else
    atm_mac_ble_rx_complete_callback = rx_cpl_cb;
#endif
}

bool atm_mac_ble_antenna_switching_by_id(void)
{
#ifdef CONFIG_ANT_SWITCH_BY_ID
    return true;
#else
    return false;
#endif
}

#if defined(CONFIG_ATM_RADIO_HAL_BLE_LOG_STATISTICS_MS) && \
    (CONFIG_ATM_RADIO_HAL_BLE_LOG_STATISTICS_MS > 0)
LOG_MODULE_REGISTER(radio_hal_ble, LOG_LEVEL_INF);

static void atm_mac_ble_log(struct k_work *work);
static K_WORK_DELAYABLE_DEFINE(atm_mac_ble_log_trigger, atm_mac_ble_log);

static int atm_mac_ble_schedule_logging(void)
{
    k_work_schedule(&atm_mac_ble_log_trigger,
	K_MSEC(CONFIG_ATM_RADIO_HAL_BLE_LOG_STATISTICS_MS));

    return 0;
}

static void atm_mac_ble_log(struct k_work *work)
{
    ARG_UNUSED(work);
    LOG_INF("BLE TX: %u, RX: %u, Success: %u, Fail: %u %u %u %u %u %u %u %u %u",
	tx_callbacks, rx_callbacks, packet_status_count[0],
	packet_status_count[1], packet_status_count[2], packet_status_count[3],
	packet_status_count[4], packet_status_count[5], packet_status_count[6],
	packet_status_count[7], packet_status_count[8], packet_status_count[9]);

    atm_mac_ble_schedule_logging();
}

SYS_INIT(atm_mac_ble_schedule_logging, APPLICATION, 0);
#endif
