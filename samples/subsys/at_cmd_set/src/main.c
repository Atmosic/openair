/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/settings/settings.h>
#include <ctype.h>
#include <string.h>

#include "at_cmd_set.h"
#include "at_cmd.h"

#define AT_CMD_HDR              "AT+"
#define AT_CMD_HDR_LEN          (sizeof(AT_CMD_HDR) - 1)
#define AT_CMD_UART_RX_BUF_SIZE 256

/* UART device */
static const struct device *uart_dev;

/* Command buffer - double buffered for ISR/work queue */
static char cmd_buf[AT_CMD_UART_RX_BUF_SIZE];
static uint16_t cmd_buf_idx;

/* Process buffer for work queue */
static char proc_buf[AT_CMD_UART_RX_BUF_SIZE];
static uint16_t proc_buf_len;

/* AT command channel */
static at_cmd_ch_t uart_ch = AT_CMD_INVALID_CH;

/* Work queue for processing AT commands outside ISR context */
static struct k_work at_cmd_work;

/**
 * @brief Work handler for processing AT commands
 */
static void at_cmd_work_handler(struct k_work *work)
{
	ARG_UNUSED(work);

	if (proc_buf_len) {
		at_cmd_proc(uart_ch, proc_buf, proc_buf_len);
		proc_buf_len = 0;
	}
}

/**
 * @brief Send response back via UART
 */
static void uart_resp_cb(at_cmd_ch_t ch, void const *data, uint16_t len)
{
	ARG_UNUSED(ch);

	if (!uart_dev || !device_is_ready(uart_dev)) {
		return;
	}

	const uint8_t *buf = data;
	for (uint16_t i = 0; i < len; i++) {
		uart_poll_out(uart_dev, buf[i]);
	}
}

/**
 * @brief Process a received byte
 *
 * Called from ISR context. When UART raw bridge is active, bytes are
 * forwarded directly to the BLE channel. Otherwise they are buffered
 * for AT command parsing.
 */
static void uart_rx_byte(uint8_t byte)
{
#ifdef CONFIG_AT_CMD_SYSUARTRAW
	if (at_cmd_sysuartraw_is_active()) {
		at_cmd_sysuartraw_rx_byte(byte);
		return;
	}
#endif /* CONFIG_AT_CMD_SYSUARTRAW */

	/* Convert to uppercase */
	uint8_t ch = toupper(byte);

	if (cmd_buf_idx < AT_CMD_HDR_LEN) {
		/* Looking for AT+ prefix */
		if (ch != AT_CMD_HDR[cmd_buf_idx]) {
			cmd_buf_idx = 0;
			memset(cmd_buf, 0, sizeof(cmd_buf));
		} else {
			cmd_buf[cmd_buf_idx++] = ch;
		}
	} else if (ch == '\r' || ch == '\n') {
		/* End of command - copy to process buffer and submit work */
		if (cmd_buf_idx > AT_CMD_HDR_LEN) {
			cmd_buf[cmd_buf_idx] = '\0';
			/* Copy to process buffer for work queue */
			memcpy(proc_buf, cmd_buf, cmd_buf_idx + 1);
			proc_buf_len = cmd_buf_idx;
			k_work_submit(&at_cmd_work);
		}
		cmd_buf_idx = 0;
		memset(cmd_buf, 0, sizeof(cmd_buf));
	} else if (cmd_buf_idx < AT_CMD_UART_RX_BUF_SIZE - 1) {
		/* Add to buffer */
		cmd_buf[cmd_buf_idx++] = ch;
	}
}

/**
 * @brief UART IRQ callback
 */
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

/**
 * @brief Initialize UART for AT commands
 */
static int uart_at_cmd_init(void)
{
	/* Get UART device - use uart0 for AT commands */
	uart_dev = DEVICE_DT_GET(DT_NODELABEL(uart0));
	if (!device_is_ready(uart_dev)) {
		printk("ERROR: UART device not ready\n");
		return -ENODEV;
	}

	/* Allocate AT command channel */
	at_cmd_alloc_ctx_t at_ctx = {
		.xfer = AT_CMD_DFT_XFER_UART,
		.resp = uart_resp_cb,
	};

	uart_ch = at_cmd_alloc(&at_ctx);
	if (uart_ch == AT_CMD_INVALID_CH) {
		printk("ERROR: Failed to allocate AT command channel\n");
		return -ENOMEM;
	}

	// Set AT command channel
	at_cmd_set_channel(uart_ch);

	/* Initialize work queue for AT command processing */
	k_work_init(&at_cmd_work, at_cmd_work_handler);

	/* Set up UART IRQ */
	uart_irq_callback_set(uart_dev, uart_isr_cb);
	uart_irq_rx_enable(uart_dev);

	return 0;
}

/*
 * Main function
 */
int main(void)
{
	int err;

	printk("\nBLE AT Command Sample\n");

	/* Initialize Bluetooth */
	err = bt_enable(NULL);
	if (err) {
		printk("ERROR: Bluetooth init failed (err %d)\n", err);
		return err;
	}

	/* Load settings to restore persistent BT identities */
	settings_load();
	printk("Bluetooth initialized\n");

	/* Initialize AT command context */
	at_cmd_ctx_init();

	/* Initialize UART for AT commands */
	err = uart_at_cmd_init();
	if (err) {
		printk("ERROR: UART AT command init failed (err %d)\n", err);
		return err;
	}

	printk("Ready for AT commands (use AT+LISTCMDS? to list commands)\n");

	/* Main loop - everything is handled by callbacks */
	while (1) {
		k_sleep(K_FOREVER);
	}

	return 0;
}
