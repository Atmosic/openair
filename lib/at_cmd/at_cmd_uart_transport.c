/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <ctype.h>
#include <string.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_uart_transport.h"

#ifdef CONFIG_AT_CMD_SET
#include "at_cmd_set.h"
#endif

LOG_MODULE_REGISTER(at_cmd_uart, CONFIG_AT_CMD_LOG_LEVEL);

static const struct device *g_uart_dev;
static char cmd_buf[CONFIG_AT_CMD_UART_RX_BUF_SIZE];
static uint16_t cmd_buf_idx;
static bool cmd_has_params;
static char proc_buf[CONFIG_AT_CMD_UART_RX_BUF_SIZE];
static uint16_t proc_buf_len;
static at_cmd_ch_t uart_ch = AT_CMD_INVALID_CH;
static struct k_work at_cmd_work;

static void reset_cmd_buf(void)
{
	cmd_buf_idx = 0;
	cmd_has_params = false;
	memset(cmd_buf, 0, sizeof(cmd_buf));
}

static void at_cmd_work_handler(struct k_work *work)
{
	ARG_UNUSED(work);

	if (proc_buf_len) {
		LOG_INF("AT proc: %s", proc_buf);
		at_cmd_proc(uart_ch, proc_buf, proc_buf_len);
		proc_buf_len = 0;
	}
}

static void uart_resp_cb(at_cmd_ch_t ch, void const *data, uint16_t len)
{
	ARG_UNUSED(ch);

	if (!g_uart_dev || !device_is_ready(g_uart_dev)) {
		return;
	}

	const uint8_t *buf = data;

	for (uint16_t i = 0; i < len; i++) {
		uart_poll_out(g_uart_dev, buf[i]);
	}
}

static void uart_rx_byte(uint8_t byte)
{
#ifdef CONFIG_AT_CMD_SET
	if (at_cmd_set_uart_rx_passthrough(byte)) {
		return;
	}
#endif

	char ch = (char)byte;

	if (cmd_buf_idx < AT_CMD_PREFIX_LEN) {
		if (toupper((unsigned char)ch) != CONFIG_AT_CMD_PREFIX[cmd_buf_idx]) {
			reset_cmd_buf();
		} else {
			cmd_buf[cmd_buf_idx] = CONFIG_AT_CMD_PREFIX[cmd_buf_idx];
			cmd_buf_idx++;
		}
		return;
	}

	if (ch == '\r' || ch == '\n') {
		if (cmd_buf_idx > AT_CMD_PREFIX_LEN) {
			cmd_buf[cmd_buf_idx] = '\0';
			memcpy(proc_buf, cmd_buf, cmd_buf_idx + 1);
			proc_buf_len = cmd_buf_idx;
			k_work_submit(&at_cmd_work);
		}
		reset_cmd_buf();
		return;
	}

	if (cmd_buf_idx >= (CONFIG_AT_CMD_UART_RX_BUF_SIZE - 1)) {
		reset_cmd_buf();
		return;
	}

	if (ch == '=') {
		cmd_has_params = true;
	}

	if (!cmd_has_params) {
		ch = (char)toupper((unsigned char)ch);
	}

	cmd_buf[cmd_buf_idx++] = ch;
}

static void uart_isr_cb(const struct device *dev, void *user_data)
{
	ARG_UNUSED(user_data);

	if (!uart_irq_update(dev)) {
		return;
	}

	while (uart_irq_rx_ready(dev)) {
		uint8_t byte;

		if (uart_fifo_read(dev, &byte, 1) == 1) {
			uart_rx_byte(byte);
		}
	}
}

at_cmd_ch_t at_cmd_uart_ch_get(void)
{
	return uart_ch;
}

at_cmd_ch_t at_cmd_uart_init(const struct device *uart_dev)
{
	if (!device_is_ready(uart_dev)) {
		LOG_ERR("AT command UART device not ready");
		return AT_CMD_INVALID_CH;
	}

	at_cmd_alloc_ctx_t at_ctx = {
		.xfer = AT_CMD_DFT_XFER_UART,
		.resp = uart_resp_cb,
	};

	uart_ch = at_cmd_alloc(&at_ctx);
	if (uart_ch == AT_CMD_INVALID_CH) {
		LOG_ERR("Failed to allocate AT command channel");
		return AT_CMD_INVALID_CH;
	}

	g_uart_dev = uart_dev;
	k_work_init(&at_cmd_work, at_cmd_work_handler);
	reset_cmd_buf();
	proc_buf_len = 0;

	uart_irq_callback_set(uart_dev, uart_isr_cb);
	uart_irq_rx_enable(uart_dev);

	LOG_INF("AT command UART ready on %s", uart_dev->name);
	return uart_ch;
}

#ifdef CONFIG_ZTEST
void at_cmd_uart_test_clear_dev(void)
{
	g_uart_dev = NULL;
}

void at_cmd_uart_test_call_resp_cb(at_cmd_ch_t ch, const void *data, uint16_t len)
{
	uart_resp_cb(ch, data, len);
}

void at_cmd_uart_test_rx_bytes(const uint8_t *data, uint16_t len)
{
	for (uint16_t i = 0; i < len; i++) {
		uart_rx_byte(data[i]);
	}
}

void at_cmd_uart_test_set_ch(at_cmd_ch_t ch)
{
	uart_ch = ch;
}

void at_cmd_uart_test_init_work(void)
{
	k_work_init(&at_cmd_work, at_cmd_work_handler);
	reset_cmd_buf();
	proc_buf_len = 0;
}
#endif /* CONFIG_ZTEST */
