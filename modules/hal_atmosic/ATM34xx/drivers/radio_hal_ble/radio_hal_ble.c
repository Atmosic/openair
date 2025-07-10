/**
 ******************************************************************************
 *
 * @file radio_hal_ble.c
 *
 * @brief BLE HAL processing
 *
 * Copyright (C) Atmosic 2022-2025
 *
 ******************************************************************************
 */

#include "arch.h"
#include "radio_hal_ble.h"

// Variables defining the state of driver.
static atm_mac_ble_tx_cpl_cb ble_tx_cpl_cb;
static atm_mac_ble_rx_cpl_cb ble_rx_cpl_cb;
atm_mac_ble_cs_cb ble_cs_cb;

void atm_mac_ble_tx_complete_callback(atm_mac_ble_status_t status)
{
    if (ble_tx_cpl_cb) {
	ble_tx_cpl_cb(status);
    }
}

void atm_mac_ble_rx_complete_callback(atm_mac_ble_status_t status,
    uint32_t start_offset, int8_t rssi)
{
    if (ble_rx_cpl_cb) {
	ble_rx_cpl_cb(status, start_offset, rssi);
    }
}

void atm_mac_ble_register_tx_cpl_cb(atm_mac_ble_tx_cpl_cb tx_cpl_cb)
{
    ble_tx_cpl_cb = tx_cpl_cb;
}

void atm_mac_ble_register_rx_cpl_cb(atm_mac_ble_rx_cpl_cb rx_cpl_cb)
{
    ble_rx_cpl_cb = rx_cpl_cb;
}

bool atm_mac_ble_antenna_switching_by_id(void)
{
#ifdef CONFIG_ANT_SWITCH_BY_ID
    return true;
#else
    return false;
#endif
}
