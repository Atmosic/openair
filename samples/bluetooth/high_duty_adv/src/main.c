/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/gap.h>
#include <zephyr/logging/log.h>
#include <zephyr/random/random.h>

LOG_MODULE_REGISTER(high_duty_adv, LOG_LEVEL_INF);

/* Target address for directed advertising - will be generated at runtime */
static bt_addr_le_t target_addr;

static void bt_ready(int err)
{
	if (err) {
		LOG_ERR("Bluetooth init failed (err %d)", err);
		return;
	}

	LOG_INF("Bluetooth initialized");

	size_t count = 1;
	bt_addr_le_t addr = {0};
	char addr_s[BT_ADDR_LE_STR_LEN];
	/* Get and print the local Bluetooth address */
	bt_id_get(&addr, &count);
	bt_addr_le_to_str(&addr, addr_s, sizeof(addr_s));
	LOG_INF("Self BD address: %s", addr_s);

	/* Generate a random target address for directed advertising */
	target_addr.type = BT_ADDR_LE_RANDOM;
	sys_rand_get(target_addr.a.val, sizeof(target_addr.a.val));

	/* Ensure it's a valid random static address */
	BT_ADDR_SET_STATIC(&target_addr.a);

	char target_addr_s[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(&target_addr, target_addr_s, sizeof(target_addr_s));
	LOG_INF("Target BD address: %s", target_addr_s);

	/* Start high duty cycle directed advertising */
	err = bt_le_adv_start(BT_LE_ADV_CONN_DIR(&target_addr), NULL, 0, NULL, 0);
	if (err) {
		LOG_ERR("Directed advertising failed to start (err %d)", err);
		return;
	}

	LOG_INF("High duty cycle directed advertising started successfully");
}

int main(void)
{
	int err;

	LOG_INF("Starting High Duty Cycle Advertising");

	/* Initialize the Bluetooth Subsystem */
	err = bt_enable(bt_ready);
	if (err) {
		LOG_ERR("Bluetooth init failed (err %d)", err);
		return err;
	}

	return 0;
}
