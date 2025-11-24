/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/bluetooth/bluetooth.h>

#include "dtm_mgr.h"

LOG_MODULE_REGISTER(dtm_2wire_main, CONFIG_DTM_2WIRE_LOG_LEVEL);

int main(void)
{
	int err;

	LOG_INF("Starting DTM 2-wire application");

	/* Initialize the Bluetooth Subsystem */
	err = bt_enable(NULL);
	if (err) {
		LOG_ERR("Bluetooth init failed (err %d)", err);
		return err;
	}

	LOG_INF("Bluetooth initialized");

	/* Initialize DTM manager */
	err = dtm_mgr_init();
	if (err) {
		LOG_ERR("DTM manager init failed (err %d)", err);
		return err;
	}

	LOG_INF("DTM 2-wire application started");

	return 0;
}
