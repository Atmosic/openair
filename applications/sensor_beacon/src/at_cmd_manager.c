/*
 * SPDX-License-Identifier: LicenseRef-Atmosic
 * Copyright (c) 2025-2026 Atmosic
 */

#include <zephyr/logging/log.h>
#include <zephyr/logging/log_ctrl.h>
#include <zephyr/sys/reboot.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/gap.h>
#include <zephyr/bluetooth/hci_types.h>
#include <zephyr/settings/settings.h>
#include <string.h>

#include "at_cmd.h"
#include "at_cmd_manager.h"
#include "at_cmd_callbacks.h"
#include "at_gatt.h"
#include "beacon_adv.h"
#include "beacon_adv_at_cmd.h"
#include <inttypes.h>

LOG_MODULE_REGISTER(at_cmd_manager, CONFIG_SENSOR_BEACON_LOG_LEVEL);

/* AT Command Buffer Configuration */
/**
 * @brief AT command buffer size
 *
 * This buffer size is designed to accommodate the longest possible AT command
 * including parameters. Based on AT command specification and typical usage:
 * - Command prefix: "AT+" (3 bytes)
 * - Command name: up to 20 bytes
 * - Parameters: up to 200 bytes (e.g., device names, hex data)
 * - Null terminator: 1 byte
 * - Safety margin: ~30 bytes
 * Total: 256 bytes provides adequate buffer space for all supported commands.
 */
#define AT_CMD_BUFFER_SIZE 256

#define AT_CMD_ADV_INTERVAL_MIN 400   /* 250ms in 0.625ms units */
#define AT_CMD_ADV_INTERVAL_MAX 16384 /* 10.24s in 0.625ms units */

static at_cmd_ch_t at_cmd_ch;
static char cmd_buf[AT_CMD_BUFFER_SIZE];
static int update_lock_ind = LOCK_UPD; /* Device starts locked */

static void at_gatt_tx_cb(at_cmd_ch_t ch, void const *resp, uint16_t len)
{
	at_gatt_notify(resp, len);
}

static void at_gatt_rx_cb(uint8_t const *data, uint16_t size)
{
	static uint16_t cmd_buf_idx;
	static atcmd_st_t atcmd_st = ATCMD_ST_IDLE;

	for (uint16_t idx = 0; idx < size; idx++) {
		if (atcmd_st == ATCMD_ST_IDLE) {
			if (!cmd_buf_idx && ((data[idx] & 0xDF) == 'A')) {
				cmd_buf[cmd_buf_idx++] = (data[idx] & 0xDF);
			} else if ((cmd_buf_idx == 1) && ((data[idx] & 0xDF) == 'T')) {
				cmd_buf[cmd_buf_idx++] = (data[idx] & 0xDF);
			} else if ((cmd_buf_idx == 2) && (data[idx] == '+')) {
				cmd_buf[cmd_buf_idx++] = data[idx];
				atcmd_st = ATCMD_ST_IN;
			} else {
				cmd_buf_idx = 0;
				atcmd_st = ATCMD_ST_IDLE;
			}
		} else if (atcmd_st == ATCMD_ST_IN) {
			cmd_buf[cmd_buf_idx++] = data[idx];
		}
	}

	atcmd_st = ATCMD_ST_PROCESSING;
	cmd_buf[cmd_buf_idx++] = 0x00;
	at_cmd_proc(at_cmd_ch, cmd_buf, strlen(cmd_buf));
	cmd_buf_idx = 0;
	atcmd_st = ATCMD_ST_IDLE;
}

int at_cmd_manager_init(void)
{
	/* Load settings early in AT command initialization */
	if (IS_ENABLED(CONFIG_SETTINGS)) {
		int ret = settings_load();
		if (ret) {
			LOG_ERR("Settings load failed: %d", ret);
			return ret;
		}
		LOG_INF("Settings loaded");
	}

	at_cmd_alloc_ctx_t const at_ctx = {
		.xfer = AT_CMD_DFT_XFER_UART,
		.resp = at_gatt_tx_cb,
	};
	at_cmd_ch = at_cmd_alloc(&at_ctx);

	at_gatt_hdlr_reg(at_gatt_rx_cb);

	/* Initialize unlock state - device starts locked */
	at_cmd_unlock_init();

	/* Initialize AT command extension callbacks */
	at_cmd_extension_callbacks_t callbacks = {
		.set_device_name = at_cmd_set_device_name,
		.set_adv_interval = at_cmd_set_adv_interval,
		.set_adv_data = at_cmd_set_adv_data,
		.reset_device = at_cmd_reset_device,
		.unlock_update_proc = at_cmd_unlock_update_proc,
		.check_unlock_state = at_cmd_check_unlock_state,
	};

	int ret = at_cmd_extension_init(&callbacks);
	if (ret != 0) {
		LOG_ERR("Failed to initialize AT command extension callbacks: %d", ret);
		return ret;
	}

	LOG_INF("AT command manager initialized");
	return 0;
}

at_cmd_ext_err_t at_cmd_set_device_name(const uint8_t *name, uint16_t len)
{
	/* Check unlock state first */
	at_cmd_ext_err_t unlock_err = at_cmd_check_unlock_state();
	if (unlock_err != AT_CMD_EXT_ERR_SUCCESS) {
		return unlock_err;
	}

	if (!name || !len || len > CONFIG_BT_DEVICE_NAME_MAX) {
		LOG_ERR("Invalid device name parameters");
		return AT_CMD_EXT_ERR_INVALID_PARAM;
	}

	char device_name[CONFIG_BT_DEVICE_NAME_MAX + 1];
	memcpy(device_name, name, len);
	device_name[len] = '\0';

	int err = bt_set_name(device_name);
	if (err) {
		LOG_ERR("Failed to set device name: %" PRId32, err);
		return AT_CMD_EXT_ERR_WRITE_FAILED;
	}

	/* Update advertising data with new device name */
	int adv_err = beacon_adv_set_device_name(device_name);
	if (adv_err) {
		LOG_ERR("Failed to update advertising data with new device name: %" PRId32,
			adv_err);
		return AT_CMD_EXT_ERR_WRITE_FAILED;
	}

	LOG_INF("Device name set to: %s", device_name);
	return AT_CMD_EXT_ERR_SUCCESS;
}

at_cmd_ext_err_t at_cmd_set_adv_interval(uint32_t interval)
{
	/* Check unlock state first */
	at_cmd_ext_err_t unlock_err = at_cmd_check_unlock_state();
	if (unlock_err != AT_CMD_EXT_ERR_SUCCESS) {
		return unlock_err;
	}

	if (interval < AT_CMD_ADV_INTERVAL_MIN || interval > AT_CMD_ADV_INTERVAL_MAX) {
		LOG_ERR("Invalid advertising interval: %" PRIu32 " (valid range: %d-%d)", interval,
			AT_CMD_ADV_INTERVAL_MIN, AT_CMD_ADV_INTERVAL_MAX);
		return AT_CMD_EXT_ERR_INVALID_PARAM;
	}

	int err = beacon_adv_set_interval(interval);
	if (err) {
		LOG_ERR("Failed to set advertising interval: %" PRId32, err);
		return AT_CMD_EXT_ERR_WRITE_FAILED;
	}

	LOG_INF("Advertising interval set to: %" PRIu32, interval);
	return AT_CMD_EXT_ERR_SUCCESS;
}

at_cmd_ext_err_t at_cmd_set_adv_data(const uint8_t *data, uint16_t len)
{
	LOG_WRN("AT+ADVDATA command is not supported");
	return AT_CMD_EXT_ERR_INVALID_PARAM;
}

at_cmd_ext_err_t at_cmd_reset_device(void)
{
	/* Check unlock state first */
	at_cmd_ext_err_t unlock_err = at_cmd_check_unlock_state();
	if (unlock_err != AT_CMD_EXT_ERR_SUCCESS) {
		return unlock_err;
	}

	LOG_INF("Resetting device...");
	log_flush(); /* Ensure all log messages are written before reboot */
	sys_reboot(SYS_REBOOT_COLD);
	return AT_CMD_EXT_ERR_SUCCESS;
}

at_cmd_ext_err_t at_cmd_unlock_update_proc(const uint8_t *key, uint16_t len)
{
	static const char expected_key[] = "atm1atm123";

	LOG_HEXDUMP_DBG(key, len, "Unlock password");

	if (!key || len != (sizeof(expected_key) - 1)) {
		LOG_ERR("Invalid unlock key length");
		return AT_CMD_EXT_ERR_INVALID_PASSWORD;
	}

	update_lock_ind = memcmp(key, expected_key, len);
	if (update_lock_ind != 0) {
		LOG_ERR("Invalid unlock key");
		return AT_CMD_EXT_ERR_INVALID_PASSWORD;
	}

	LOG_INF("Update procedure unlocked");
	return AT_CMD_EXT_ERR_SUCCESS;
}

at_cmd_ext_err_t at_cmd_check_unlock_state(void)
{
	if (update_lock_ind != 0) {
		LOG_WRN("Device is locked - unlock required for AT command operations");
		return AT_CMD_EXT_ERR_UNLOCK_REQUIRED;
	}
	return AT_CMD_EXT_ERR_SUCCESS;
}

void at_cmd_unlock_init(void)
{
	update_lock_ind = LOCK_UPD;
	LOG_INF("Device unlock state initialized (locked)");
}

void at_cmd_connection_event(bool connected)
{
	if (connected) {
		/* Lock device when connection is established */
		update_lock_ind = LOCK_UPD;
		LOG_INF("Device locked due to connection event");
	}
}
