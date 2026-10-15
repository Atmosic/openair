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
 *
 * UART transport and SYSDFU byte passthrough are handled by the shared
 * at_cmd_uart_transport library and subsys/at_cmd_set respectively.
 */

#include <zephyr/device.h>
#include <zephyr/sys/printk.h>
#include "at_cmd_set.h"

int main(void)
{
	printk("AT_CMD_DFU_TEST IMG_VER=" CONFIG_AT_CMD_DFU_TEST_APP_VERSION "\n");

	int err = at_cmd_set_uart_ch_init(DEVICE_DT_GET(DT_NODELABEL(uart0)));

	if (err) {
		printk("AT UART init failed: %d\n", err);
		return err;
	}

	printk("DFU_READY\n");
	return 0;
}
