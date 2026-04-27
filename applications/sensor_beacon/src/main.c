/*
 * SPDX-License-Identifier: LicenseRef-Atmosic
 * Copyright (c) 2025-2026 Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/watchdog.h>
#include <zephyr/logging/log.h>
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#include <zephyr/bluetooth/bluetooth.h>
#if defined(CONFIG_BT_MAX_CONN) && (CONFIG_BT_MAX_CONN > 1)
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/addr.h>
#include <zephyr/bluetooth/gatt.h>
#endif
#include "sensor_beacon.h"
#include "at_gatt.h"
#include "at_cmd_manager.h"
#include "led_button_ctrl.h"
#include "reset.h"
#ifdef CONFIG_PM
#include "power.h"
#endif

LOG_MODULE_REGISTER(main, CONFIG_SENSOR_BEACON_LOG_LEVEL);

#define SLEEP_TIME        K_SECONDS(3)
#define WDT_MIN_WINDOW_MS 0
#define WDT_MAX_WINDOW_MS 5000

static const struct device *const wdog_dev = DEVICE_DT_GET(DT_ALIAS(watchdog0));
static int wdt_channel_id;

#ifdef CONFIG_PM
static void wdog_poke(enum pm_state state)
{
	wdt_feed(wdog_dev, wdt_channel_id);
}

static struct pm_notifier notifier = {
	.state_entry = wdog_poke,
	.state_exit = wdog_poke,
};
#endif

/**
 * @brief MTU exchange completion callback
 */
static void mtu_exchange_cb(struct bt_conn *conn, uint8_t err,
			    struct bt_gatt_exchange_params *params)
{
	if (err) {
		LOG_WRN("MTU exchange failed (err 0x%02x)", err);
	} else {
		uint16_t mtu = bt_gatt_get_mtu(conn);
		LOG_INF("MTU exchange successful: %u bytes", mtu);
	}
}

static struct bt_gatt_exchange_params mtu_exchange_params = {.func = mtu_exchange_cb};

#if defined(CONFIG_BT_MAX_CONN) && (CONFIG_BT_MAX_CONN > 1)
/**
 * @brief Bluetooth connection callback
 *
 * Automatically locks device on new connections to prevent authentication bypass vulnerability.
 */
static void connected_cb(struct bt_conn *conn, uint8_t err)
{
	if (err) {
		LOG_ERR("BLE connection failed (err 0x%02x)", err);
		return;
	}

	char addr[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));
	LOG_INF("BLE connected: %s", addr);

	/* Initiate MTU exchange for AT commands */
	int ret = bt_gatt_exchange_mtu(conn, &mtu_exchange_params);
	if (ret) {
		LOG_WRN("MTU exchange request failed (err %d), using default MTU", ret);
	} else {
		LOG_INF("MTU exchange initiated (current: %u bytes)", bt_gatt_get_mtu(conn));
	}

	/* Force device to locked state on new connection */
	at_cmd_connection_event(true);
	LOG_INF("Device automatically locked for new BLE session");
}

/**
 * @brief Bluetooth disconnection callback
 */
static void disconnected_cb(struct bt_conn *conn, uint8_t reason)
{
	char addr[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));
	LOG_INF("BLE disconnected: %s (reason 0x%02x %s)", addr, reason, bt_hci_err_to_str(reason));
}

/**
 * @brief Bluetooth connection callbacks
 */
BT_CONN_CB_DEFINE(sensor_beacon_conn_cb) = {
	.connected = connected_cb,
	.disconnected = disconnected_cb,
};

#endif /* CONFIG_BT_MAX_CONN > 1 */

int main(void)
{
	LOG_INF("Starting Sensor Beacon Application: %#x", boot_status());

#ifdef CONFIG_SENSOR_BEACON_BUTTON_POWER_CONTROL
	// Check if device should power on (button power control enabled)
	if (!led_button_ctrl_check_power_on()) {
		LOG_INF("Device will go into SOC-OFF state");
#ifdef CONFIG_PM
		// Enable GPIO wakeup source for SOC_OFF
		atm_socoff_wakeup_gpio_set(true);
		// Unlock SOC_OFF state to allow PM subsystem to enter it
		sensor_beacon_unlock_soft_off_state();
#endif
		return 0;
	}

	// Device is powering on - continue with initialization
	LOG_INF("Button power control check passed - proceeding with initialization");
#else
	// No button power control, proceed directly to normal initialization
	LOG_DBG("No button power control");
#endif

	/* Initialize watchdog */
	struct wdt_timeout_cfg wdt_config = {
		.flags = WDT_FLAG_RESET_SOC,
		.window.min = WDT_MIN_WINDOW_MS,
		.window.max = WDT_MAX_WINDOW_MS,
		.callback = NULL,
	};

	wdt_channel_id = wdt_install_timeout(wdog_dev, &wdt_config);
	if (wdt_channel_id < 0) {
		LOG_ERR("Watchdog install error: %d", wdt_channel_id);
		return 1;
	}

	int ret = wdt_setup(wdog_dev, 0);
	if (ret < 0) {
		LOG_ERR("Watchdog setup error: %d", ret);
		return 1;
	}

	/* Initialize Bluetooth subsystem early */
	ret = bt_enable(NULL);
	if (ret) {
		LOG_ERR("Bluetooth init failed: %d", ret);
		return ret;
	}
	LOG_INF("Bluetooth initialized");

	/* Initialize AT command manager */
	ret = at_cmd_manager_init();
	if (ret) {
		LOG_ERR("AT command manager init failed: %" PRId32, ret);
		return ret;
	}
	LOG_INF("AT command support initialized");

	/* Initialize sensor beacon */
	ret = sensor_beacon_init();
	if (ret) {
		LOG_ERR("Sensor beacon init failed: %d", ret);
		return ret;
	}

#ifdef CONFIG_PM
	sensor_beacon_unlock_soft_off_state();
#endif

	/* Set the device to ON state */
	led_button_ctrl_set_device_state(DEVICE_STATE_ON);

#ifdef CONFIG_PM
	pm_notifier_register(&notifier);
#else
	/* Main loop for non-PM builds */
	while (true) {
		k_sleep(SLEEP_TIME);
		wdt_feed(wdog_dev, wdt_channel_id);
	}
#endif

	return 0;
}
