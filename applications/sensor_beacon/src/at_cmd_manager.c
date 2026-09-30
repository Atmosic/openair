/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/gap.h>
#include <zephyr/bluetooth/hci_types.h>
#include <zephyr/logging/log.h>
#include <zephyr/logging/log_ctrl.h>
#include <zephyr/settings/settings.h>
#include <zephyr/sys/reboot.h>

#include "at_cmd.h"
#include "at_cmd_set.h"
#include "at_cmd_manager.h"
#include "at_cmd_set.h"
#include "at_gatt.h"
#include "beacon_adv.h"
#include "beacon_adv_at_cmd.h"

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

static at_cmd_ch_t at_cmd_ch;
static char cmd_buf[AT_CMD_BUFFER_SIZE];

/* Work queue for processing AT commands asynchronously to avoid blocking GATT callback */
static struct k_work_delayable at_cmd_work;
static K_MUTEX_DEFINE(cmd_buf_mutex);
static char cmd_work_buf[AT_CMD_BUFFER_SIZE];
static uint16_t cmd_work_len;

static void at_gatt_tx_cb(at_cmd_ch_t ch, void const *resp, uint16_t len)
{
	at_gatt_notify(resp, len);
}

static void at_cmd_work_handler(struct k_work *work)
{
	ARG_UNUSED(work);

	k_mutex_lock(&cmd_buf_mutex, K_FOREVER);
	if (cmd_work_len > 0) {
		at_cmd_proc(at_cmd_ch, cmd_work_buf, cmd_work_len);
		cmd_work_len = 0;
	}
	k_mutex_unlock(&cmd_buf_mutex);
}

static void at_gatt_rx_cb(uint8_t const *data, uint16_t size)
{
	static uint16_t cmd_buf_idx;

	BUILD_ASSERT(AT_CMD_PREFIX_LEN < AT_CMD_BUFFER_SIZE,
		     "AT_CMD_PREFIX must fit in AT_CMD_BUFFER_SIZE");

	for (uint16_t i = 0; i < size; i++) {
		if (cmd_buf_idx >= (AT_CMD_BUFFER_SIZE - 1)) {
			LOG_WRN("AT GATT buffer overflow, resetting");
			cmd_buf_idx = 0;
			return;
		}

		if (cmd_buf_idx < AT_CMD_PREFIX_LEN) {
			/* Match prefix byte-by-byte (case-insensitive) */
			if (toupper((unsigned char)data[i]) ==
			    toupper((unsigned char)CONFIG_AT_CMD_PREFIX[cmd_buf_idx])) {
				cmd_buf[cmd_buf_idx] = CONFIG_AT_CMD_PREFIX[cmd_buf_idx];
				cmd_buf_idx++;
			} else {
				cmd_buf_idx = 0;
			}
		} else {
			/* Prefix matched — accumulate command body */
			cmd_buf[cmd_buf_idx++] = data[i];
		}
	}

	/* Process command asynchronously to avoid blocking the GATT callback */
	cmd_buf[cmd_buf_idx] = 0x00;
	k_mutex_lock(&cmd_buf_mutex, K_FOREVER);
	strncpy(cmd_work_buf, cmd_buf, sizeof(cmd_work_buf) - 1);
	cmd_work_buf[sizeof(cmd_work_buf) - 1] = '\0';
	cmd_work_len = strlen(cmd_work_buf);
	k_mutex_unlock(&cmd_buf_mutex);

	cmd_buf_idx = 0;

	/* Schedule work with small delay to ensure GATT write response is sent first */
	k_work_schedule(&at_cmd_work, K_MSEC(10));
}

#ifdef CONFIG_AT_CMD_BLEGAPDEVNAME_CB
static void at_cmd_devname_set_cb(const char *name)
{
	int err = beacon_adv_set_device_name(name);

	if (err) {
		LOG_ERR("Failed to update adv data with new device name: %d", err);
		return;
	}

	LOG_INF("Device name set to: %s", name);
}
#endif

#ifdef CONFIG_AT_CMD_BLEADVLEGACYPARM_CB
static void at_cmd_advlegacyparm_set_cb(uint8_t idx, uint16_t intv_min, uint16_t intv_max,
					uint16_t duration)
{
	int err = beacon_adv_set_interval(intv_min);

	if (err) {
		LOG_ERR("Failed to set advertising interval: %d", err);
		return;
	}

	LOG_INF("Adv interval set: idx=%u min=%u max=%u duration=%u", idx, intv_min, intv_max,
		duration);
}
#endif

#ifdef CONFIG_AT_CMD_BLEADVDATA_CB
static int at_cmd_advdata_set_cb(uint8_t idx, const uint8_t *data, uint16_t len)
{
	LOG_ERR("AT+BLEADVDATA: custom adv data not supported on sensor_beacon (idx=%u, len=%u)",
		idx, len);
	return -ENOTSUP;
}
#endif

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

	/* Initialize work queue for AT command processing */
	k_work_init_delayable(&at_cmd_work, at_cmd_work_handler);

	at_cmd_alloc_ctx_t const at_ctx = {
		.xfer = AT_CMD_DFT_XFER_UART,
		.resp = at_gatt_tx_cb,
	};
	at_cmd_ch = at_cmd_alloc(&at_ctx);

#ifdef CONFIG_AT_CMD_LOCK_SET
	/* Lock channel on startup — unlocked only via AT+SYSLOCK=OFF */
	at_cmd_lock(at_cmd_ch, true);
#endif

	at_gatt_hdlr_reg(at_gatt_rx_cb);

#ifdef CONFIG_AT_CMD_SET_CALLBACKS
	at_cmd_set_callbacks_t subsys_callbacks = {
#ifdef CONFIG_AT_CMD_BLEGAPDEVNAME_CB
		.devname_set_cb = at_cmd_devname_set_cb,
#endif
#ifdef CONFIG_AT_CMD_BLEADVLEGACYPARM_CB
		.advlegacyparm_set_cb = at_cmd_advlegacyparm_set_cb,
#endif
#ifdef CONFIG_AT_CMD_BLEADVDATA_CB
		.advdata_set_cb = at_cmd_advdata_set_cb,
#endif
	};
	at_cmd_set_callbacks_register(&subsys_callbacks);
#endif /* CONFIG_AT_CMD_SET_CALLBACKS */

	LOG_INF("AT command manager initialized");
	return 0;
}

#ifdef CONFIG_AT_CMD_LOCK_SET
void at_cmd_connection_event(bool connected)
{
	if (connected) {
		/* Re-lock channel on every new connection */
		at_cmd_lock(at_cmd_ch, true);
		LOG_INF("AT commands locked on connection");
	}
}
#endif
