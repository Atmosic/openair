/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/*
 * Pytest-mode entry point for the atm_vendor_dfu test image.
 *
 * Console (uart1) prints a banner including TEST_APP_VERSION at boot so the
 * pytest harness can detect post-swap reboots. A simple framed protocol on
 * the chosen zephyr,uart-mcumgr UART (uart0 on ATM34 EVK) drives the DFU
 * APIs end-to-end: feed image bytes via atm_vendor_dfu_write(), then trigger
 * atm_vendor_dfu_request_upgrade() and reboot.
 *
 * Frame layout (little-endian):
 *   host -> dev:  [magic 0xA1B2C3D4] [cmd:1] [len:4] [payload:len]
 *   dev  -> host: [magic 0xD4C3B2A1] [status:1] [len:4] [payload:len]
 *
 * Commands:
 *   0x01 PING  - no payload; OK with banner string
 *   0x02 RESET - calls atm_vendor_dfu_reset()
 *   0x03 WRITE - payload is image bytes; calls atm_vendor_dfu_write()
 *   0x04 GO    - calls atm_vendor_dfu_request_upgrade() then sys_reboot()
 */

#include <errno.h>
#include <string.h>

#include <zephyr/devicetree.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/reboot.h>

#include "atm_vendor_dfu.h"

#define DFU_MAGIC_REQ  0xA1B2C3D4U
#define DFU_MAGIC_RESP 0xD4C3B2A1U

#define DFU_CMD_PING  0x01U
#define DFU_CMD_RESET 0x02U
#define DFU_CMD_WRITE 0x03U
#define DFU_CMD_GO    0x04U

#define DFU_HDR_LEN   9U
#define DFU_MAX_CHUNK 1024U

static const struct device *const dfu_uart = DEVICE_DT_GET(DT_CHOSEN(zephyr_uart_mcumgr));

static uint8_t rx_buf[DFU_MAX_CHUNK];

static void uart_write_bytes(const uint8_t *buf, size_t len)
{
	for (size_t i = 0; i < len; i++) {
		uart_poll_out(dfu_uart, buf[i]);
	}
}

static int uart_read_bytes(uint8_t *buf, size_t len)
{
	size_t got = 0;

	while (got < len) {
		uint8_t b;
		int rc = uart_poll_in(dfu_uart, &b);

		if (!rc) {
			buf[got++] = b;
			continue;
		}
		if (rc != -1) {
			return rc;
		}
		k_msleep(1);
	}
	return 0;
}

static void send_resp(uint8_t status, const uint8_t *payload, uint32_t len)
{
	uint8_t hdr[DFU_HDR_LEN];
	uint32_t magic = DFU_MAGIC_RESP;

	memcpy(hdr, &magic, sizeof(magic));
	hdr[4] = status;
	memcpy(hdr + 5, &len, sizeof(len));
	uart_write_bytes(hdr, sizeof(hdr));
	if (len) {
		uart_write_bytes(payload, len);
	}
}

static int read_request(uint8_t *cmd, uint32_t *len)
{
	uint8_t hdr[DFU_HDR_LEN];
	uint32_t magic;

	int rc = uart_read_bytes(hdr, sizeof(hdr));

	if (rc) {
		return rc;
	}
	memcpy(&magic, hdr, sizeof(magic));
	if (magic != DFU_MAGIC_REQ) {
		printk("DFU: bad magic %#x\n", magic);
		return -EINVAL;
	}
	*cmd = hdr[4];
	memcpy(len, hdr + 5, sizeof(*len));
	if (*len > sizeof(rx_buf)) {
		printk("DFU: oversize len %u\n", *len);
		return -EMSGSIZE;
	}
	if (*len) {
		rc = uart_read_bytes(rx_buf, *len);
	}
	return rc;
}

static void handle_request(uint8_t cmd, uint32_t len)
{
	int rc;

	switch (cmd) {
	case DFU_CMD_PING: {
		const char *banner = "VENDOR_DFU IMG_VER=" CONFIG_ATM_VENDOR_DFU_TEST_APP_VERSION;

		send_resp(0, (const uint8_t *)banner, (uint32_t)strlen(banner));
		break;
	}
	case DFU_CMD_RESET:
		atm_vendor_dfu_reset();
		send_resp(0, NULL, 0);
		break;
	case DFU_CMD_WRITE:
		rc = atm_vendor_dfu_write(rx_buf, len);
		send_resp((uint8_t)(rc ? -rc : 0), NULL, 0);
		break;
	case DFU_CMD_GO:
		rc = atm_vendor_dfu_request_upgrade();
		printk("REQUEST_UPGRADE rc=%d\n", rc);
		send_resp((uint8_t)(rc ? -rc : 0), NULL, 0);
		k_msleep(50);
		sys_reboot(SYS_REBOOT_COLD);
		break;
	default:
		send_resp((uint8_t)EINVAL, NULL, 0);
		break;
	}
}

void dfu_test_app_run(void)
{
	printk("ATM_VENDOR_DFU_TEST IMG_VER=" CONFIG_ATM_VENDOR_DFU_TEST_APP_VERSION "\n");

	if (!device_is_ready(dfu_uart)) {
		printk("DFU UART not ready\n");
		return;
	}

	int rc = atm_vendor_dfu_init();

	printk("atm_vendor_dfu_init rc=%d\n", rc);
	atm_vendor_dfu_reset();
	printk("DFU_READY\n");

	while (true) {
		uint8_t cmd = 0;
		uint32_t len = 0;

		if (read_request(&cmd, &len)) {
			k_msleep(10);
			continue;
		}
		handle_request(cmd, len);
	}
}
