/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/settings/settings.h>

#include "at_cmd_set.h"

/*
 * Main function
 */
int main(void)
{
	int err;

	printk("\nBLE AT Command Sample\n");
	printk("AT_CMD_SET APP_VER=" CONFIG_AT_CMD_SET_SAMPLE_APP_VERSION "\n");

	/* Initialize Bluetooth */
	err = bt_enable(NULL);
	if (err) {
		printk("ERROR: Bluetooth init failed (err %d)\n", err);
		return err;
	}

	/* Load settings to restore persistent BT identities */
	settings_load();
	printk("Bluetooth initialized\n");

	/* Initialize AT command system with UART transport */
	err = at_cmd_set_uart_ch_init(DEVICE_DT_GET(DT_NODELABEL(uart0)));
	if (err) {
		printk("ERROR: AT command UART init failed (err %d)\n", err);
		return err;
	}

	printk("Ready for AT commands (use AT+LISTCMDS? to list commands)\n");

	/* Main loop - everything is handled by callbacks */
	while (1) {
		k_sleep(K_FOREVER);
	}

	return 0;
}
