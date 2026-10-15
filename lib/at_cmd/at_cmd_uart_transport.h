/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

/**
 * @internal
 * @defgroup ATM_AT_CMD_UART AT command UART transport
 * @ingroup ATM_BTFM_ATCORE
 * @brief Generic UART transport layer for AT commands
 *
 * @warning This is an internal header. Do not include it from application or
 *          subsystem code. Use at_cmd_set.h and at_cmd_set_uart_ch_get()
 *          instead.
 * @{
 */

#include <zephyr/device.h>
#include "at_cmd.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @internal
 * @brief Get the AT command channel allocated by at_cmd_uart_init()
 *
 * Private to the at_cmd_set subsystem. External callers must use
 * at_cmd_set_uart_ch_get() from at_cmd_set.h.
 *
 * @return Allocated AT command channel, or AT_CMD_INVALID_CH if not yet
 *         initialized
 */
at_cmd_ch_t at_cmd_uart_ch_get(void);

/**
 * @internal
 * @brief Initialize the generic AT command UART transport
 *
 * Sets up the UART IRQ handler, double-buffered RX parser, work queue for
 * command processing, and allocates an AT command channel.
 *
 * @param uart_dev UART device to use for AT command transport
 *
 * @return Allocated AT command channel on success, AT_CMD_INVALID_CH on failure
 */
at_cmd_ch_t at_cmd_uart_init(const struct device *uart_dev);

#ifdef CONFIG_ZTEST

void at_cmd_uart_test_clear_dev(void);
void at_cmd_uart_test_call_resp_cb(at_cmd_ch_t ch, const void *data, uint16_t len);
void at_cmd_uart_test_rx_bytes(const uint8_t *data, uint16_t len);
void at_cmd_uart_test_set_ch(at_cmd_ch_t ch);
void at_cmd_uart_test_init_work(void);

#endif /* CONFIG_ZTEST */

#ifdef __cplusplus
}
#endif

///@}
