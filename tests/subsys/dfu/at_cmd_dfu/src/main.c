/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/*
 * Minimal AT command DFU test application.
 *
 * Console (uart1) prints a version banner at boot so the pytest harness can
 * detect post-swap reboots.  AT commands are served on uart0 (the same UART
 * that the host uses to drive the DFU).
 *
 * Supported AT commands (via CONFIG_AT_CMD_SET / CONFIG_AT_CMD_SYSDFU):
 *   AT+SYSDFU=0,<len>,<crc_en>   - begin serial DFU transfer
 *   AT+SYSSWITCHBANK              - request MCUboot upgrade and reboot
 *   AT+SYSMKBANKGOOD              - confirm running image (prevent revert)
 */

#include <ctype.h>
#include <string.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include "at_cmd.h"
#include "at_cmd_set.h"
#include "at_cmd_sysdfu_proc.h"

#define AT_CMD_HDR     "AT+"
#define AT_CMD_HDR_LEN (sizeof(AT_CMD_HDR) - 1)
#define RX_BUF_SIZE    256

static const struct device *const at_uart = DEVICE_DT_GET(DT_NODELABEL(uart0));

static char cmd_buf[RX_BUF_SIZE];
static uint16_t cmd_buf_idx;
static bool cmd_has_params;

static char proc_buf[RX_BUF_SIZE];
static uint16_t proc_buf_len;

static at_cmd_ch_t at_ch = AT_CMD_INVALID_CH;
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
		at_cmd_proc(at_ch, proc_buf, proc_buf_len);
		proc_buf_len = 0;
	}
}

static void uart_resp_cb(at_cmd_ch_t ch, void const *data, uint16_t len)
{
	ARG_UNUSED(ch);
	const uint8_t *buf = data;

	for (uint16_t i = 0; i < len; i++) {
		uart_poll_out(at_uart, buf[i]);
	}
}

static void uart_rx_byte(uint8_t byte)
{
	if (at_cmd_sysdfu_is_active()) {
		at_cmd_sysdfu_feed_byte(byte);
		return;
	}

	char ch = (char)byte;

	if (cmd_buf_idx < AT_CMD_HDR_LEN) {
		if (toupper((unsigned char)ch) != AT_CMD_HDR[cmd_buf_idx]) {
			reset_cmd_buf();
		} else {
			cmd_buf[cmd_buf_idx] = AT_CMD_HDR[cmd_buf_idx];
			cmd_buf_idx++;
		}
		return;
	}

	if (ch == '\r' || ch == '\n') {
		if (cmd_buf_idx > AT_CMD_HDR_LEN) {
			cmd_buf[cmd_buf_idx] = '\0';
			memcpy(proc_buf, cmd_buf, cmd_buf_idx + 1);
			proc_buf_len = cmd_buf_idx;
			k_work_submit(&at_cmd_work);
		}
		reset_cmd_buf();
		return;
	}

	if (cmd_buf_idx >= (RX_BUF_SIZE - 1)) {
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
		uint8_t b;

		if (uart_fifo_read(dev, &b, 1) == 1) {
			uart_rx_byte(b);
		}
	}
}

int main(void)
{
	printk("AT_CMD_DFU_TEST IMG_VER=" CONFIG_AT_CMD_DFU_TEST_APP_VERSION "\n");

	if (!device_is_ready(at_uart)) {
		printk("AT UART not ready\n");
		return -1;
	}

	at_cmd_ctx_init();

	at_cmd_alloc_ctx_t at_ctx = {
		.xfer = AT_CMD_DFT_XFER_UART,
		.resp = uart_resp_cb,
	};
	at_ch = at_cmd_alloc(&at_ctx);
	if (at_ch == AT_CMD_INVALID_CH) {
		printk("Failed to allocate AT channel\n");
		return -1;
	}

	at_cmd_set_channel(at_ch);
	k_work_init(&at_cmd_work, at_cmd_work_handler);
	reset_cmd_buf();
	proc_buf_len = 0;

	uart_irq_callback_set(at_uart, uart_isr_cb);
	uart_irq_rx_enable(at_uart);

	printk("DFU_READY\n");
	return 0;
}
