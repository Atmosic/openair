/*
 * SPDX-License-Identifier: LicenseRef-Atmosic
 * Copyright (c) 2021-2026 Atmosic
 */

#pragma once

#include <zephyr/kernel.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief AT command GATT RX handler callback type
 *
 * @param data Received data buffer
 * @param len Length of received data
 */
typedef void (*at_gatt_rx_hdlr_t)(uint8_t const *data, uint16_t len);

/**
 * @brief Register AT command GATT RX handler
 *
 * @param rx_cb RX callback function
 */
void at_gatt_hdlr_reg(at_gatt_rx_hdlr_t rx_cb);

/**
 * @brief Send AT command response via GATT notification
 *
 * @param data Response data buffer
 * @param len Length of response data
 */
void at_gatt_notify(uint8_t const *data, uint16_t len);

#ifdef __cplusplus
}
#endif
