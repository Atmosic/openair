/*
 * Copyright (c) 2026, Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Atmosic UART driver extended API
 *
 * This file provides Atmosic-specific UART driver APIs that extend
 * the standard Zephyr UART API.
 */

#ifndef ZEPHYR_INCLUDE_DRIVERS_UART_ATM_H_
#define ZEPHYR_INCLUDE_DRIVERS_UART_ATM_H_

#include <zephyr/device.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Callback type for UART RX idle detection
 *
 * This callback is invoked when the RX line transitions from low to high
 * (rising edge), indicating that a host has connected. At the time of
 * callback invocation, the driver has already switched the RX pin back
 * to UART function, so the application can begin host communication
 * immediately.
 *
 * @note This callback is invoked in ISR context. Keep processing minimal
 *       and defer lengthy operations to a thread context.
 *
 * @param dev UART device that triggered the callback
 */
typedef void (*uart_atm_rx_callback_t)(const struct device *dev);

/**
 * @brief Enter UART RX idle (host detection) mode
 *
 * This function switches the UART RX line to GPIO mode with interrupt
 * enabled for low -> high transition detection.
 *
 * When the RX line transitions from LOW to HIGH (rising edge):
 * 1. The driver switches the RX pin back to UART RX function
 * 2. The driver invokes the registered callback
 * 3. Application can begin host communication in the callback
 *
 * After communication is complete or on timeout, the application should
 * call this API again to re-enter idle (detection) mode.
 *
 * Usage assumptions:
 * - Power-on sequence assumes UART is connected. Application can enter
 *   RX GPIO idle state using this API when needed.
 * - If this API is called while physical UART lines are still connected,
 *   host communication would require disconnection/reconnection of physical
 *   UART lines (as driver monitors only low -> high transition).
 *
 * @param dev UART device instance
 * @param callback Callback function to invoke on host connection detection.
 *                 Must not be NULL.
 *
 * @retval 0 on success
 * @retval -ENOTSUP if the device does not support this feature (no rx-pin)
 * @retval -EINVAL if dev or callback is NULL
 * @retval -ENODEV if GPIO device is not ready
 */
int uart_atm_set_idle(const struct device *dev, uart_atm_rx_callback_t callback);

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_INCLUDE_DRIVERS_UART_ATM_H_ */
