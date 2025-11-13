/**
 *******************************************************************************
 *
 * @file platform_ctrl_ota.c
 *
 * @brief Platform control OTA For Multimode Consumer Tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/logging/log_ctrl.h>
#include <zephyr/settings/settings.h>
#include <zephyr/sys/reboot.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/drivers/reset.h>
#include "platform_ctrl_ota.h"
#include "platform_ctrl_led.h"

LOG_MODULE_DECLARE(multimode_consumer_tag, CONFIG_MULTIMODE_CONSUMER_TAG_LOG_LEVEL);

/* Settings key for OTA mode flag */
#define OTA_SETTINGS_KEY "platform/ota_mode"

/* OTA advertising device name */
#define OTA_DEVICE_NAME     "Atmosic OTA"
#define OTA_DEVICE_NAME_LEN (sizeof(OTA_DEVICE_NAME) - 1)

/* OTA mode flag */
static bool ota_mode_active = false;

/* OTA advertising data */
static const struct bt_data ota_ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA(BT_DATA_NAME_COMPLETE, OTA_DEVICE_NAME, OTA_DEVICE_NAME_LEN),
};

/* Forward declaration */
static int ota_adv_start(void);

/* BLE connection callbacks for OTA mode */
static void ota_disconnected(struct bt_conn *conn, uint8_t reason)
{
	if (!ota_mode_active) {
		return;
	}

	LOG_INF("OTA disconnected (reason 0x%02x)", reason);

	/* Restart advertising after disconnection */
	int err = ota_adv_start();
	if (err) {
		LOG_ERR("Failed to restart OTA advertising after disconnect: %d", err);
	}
}

BT_CONN_CB_DEFINE(ota_conn_callbacks) = {
	.disconnected = ota_disconnected,
};

/* Settings handler for OTA mode */
static int ota_settings_set(const char *name, size_t len, settings_read_cb read_cb, void *cb_arg)
{
	const char *next;
	int rc;

	if (settings_name_steq(name, "ota_mode", &next) && !next) {
		if (len != sizeof(ota_mode_active)) {
			LOG_ERR("Invalid OTA mode flag size: %zu", len);
			return -EINVAL;
		}

		rc = read_cb(cb_arg, &ota_mode_active, sizeof(ota_mode_active));
		if (rc < 0) {
			LOG_ERR("Failed to read OTA mode flag: %d", rc);
			return rc;
		}

		LOG_INF("OTA mode flag loaded: %d", ota_mode_active);
		return 0;
	}

	return -ENOENT;
}

/* Settings handler structure */
SETTINGS_STATIC_HANDLER_DEFINE(platform_ota, "platform", NULL, ota_settings_set, NULL, NULL);

/* Start OTA advertising */
static int ota_adv_start(void)
{
	int err;

	/* Use legacy advertising with connectable and scannable */
	err = bt_le_adv_start(BT_LE_ADV_CONN_FAST_2, ota_ad, ARRAY_SIZE(ota_ad), NULL, 0);
	if (err) {
		LOG_ERR("OTA advertising failed to start (err %d)", err);
		return err;
	}

	LOG_INF("OTA advertising started with device name: %s", OTA_DEVICE_NAME);
	return 0;
}

bool platform_ctrl_ota_init(void)
{
	int err;

	/* Settings are already loaded by settings_load() in main() */
	/* Just check if OTA mode is active and start advertising if needed */

	if (!ota_mode_active) {
		LOG_DBG("OTA mode not active");
		return false;
	}

	/* Clear OTA mode flag for next boot */
	bool ota_mode_setting = false;
	err = settings_save_one(OTA_SETTINGS_KEY, &ota_mode_setting, sizeof(ota_mode_setting));
	if (err) {
		LOG_ERR("Failed to save OTA mode flag: %d", err);
		/* Clear the flag on failure */
		ota_mode_active = false;
		return false;
	}

	LOG_INF("OTA mode active, starting OTA advertising");

	/* Start OTA advertising */
	err = ota_adv_start();
	if (err) {
		LOG_ERR("Failed to start OTA advertising: %d", err);
		/* Clear the flag on failure */
		ota_mode_active = false;
		return false;
	}

	return true;
}

void platform_ctrl_ota_enter(void)
{
	int err;

	LOG_INF("Entering OTA mode");

	/* Set OTA mode flag for next boot */
	bool ota_mode_setting = true;
	err = settings_save_one(OTA_SETTINGS_KEY, &ota_mode_setting, sizeof(ota_mode_setting));
	if (err) {
		LOG_ERR("Failed to save OTA mode flag: %d", err);
		return;
	}

	/* Trigger system reboot */
	LOG_INF("Rebooting into OTA mode...");
	log_flush();
	sys_reboot(SYS_REBOOT_WARM);

	/* Should never reach here */
	CODE_UNREACHABLE;
}
