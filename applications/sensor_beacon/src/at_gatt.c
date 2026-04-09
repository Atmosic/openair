/*
 * SPDX-License-Identifier: LicenseRef-Atmosic
 * Copyright (c) 2021-2026 Atmosic
 */

#include <zephyr/bluetooth/gatt.h>
#include <zephyr/logging/log.h>
#include <string.h>

#include "at_gatt.h"
#include <inttypes.h>

LOG_MODULE_REGISTER(at_gatt, CONFIG_SENSOR_BEACON_LOG_LEVEL);

#define BT_UUID_DECLARE_REVERSE_128(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13,    \
				    a14, a15)                                                      \
	BT_UUID_DECLARE_128(a15, a14, a13, a12, a11, a10, a9, a8, a7, a6, a5, a4, a3, a2, a1, a0)

/* Sensor beacon GATT service UUIDs */
#define BT_UUID_SENSOR_BEACON                                                                      \
	BT_UUID_DECLARE_REVERSE_128('A', 't', 'm', 'o', 's', 'i', 'c', 'S', 'B', '-', 'b', 'e',    \
				    'a', 'c', 'o', 'n')

#define BT_UUID_SENSOR_BEACON_TXRX                                                                 \
	BT_UUID_DECLARE_128('A', 't', 'm', 'o', 's', 'i', 'c', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
			    0x00, 0x00, 0x01)

#define AT_CMD_INFO_SIZE 256 /* Match AT_CMD_BUFFER_SIZE to support long commands */
static uint8_t at_cmd_info[AT_CMD_INFO_SIZE];
static at_gatt_rx_hdlr_t at_gatt_rx_handler;

static ssize_t write_at_cmd_info(struct bt_conn *conn, const struct bt_gatt_attr *attr,
				 const void *buf, uint16_t len, uint16_t offset, uint8_t flags)
{
	LOG_HEXDUMP_DBG(buf, len, "AT GATT write");
	uint8_t *value = attr->user_data;

	if (offset + len > AT_CMD_INFO_SIZE) {
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
	}

	memcpy(value + offset, buf, len);

	if (at_gatt_rx_handler) {
		at_gatt_rx_handler(buf, len);
	}

	return len;
}

static void at_cmd_ccc_changed(const struct bt_gatt_attr *attr, uint16_t value)
{
	ARG_UNUSED(attr);

	bool notif_enabled = (value == BT_GATT_CCC_NOTIFY);

	LOG_INF("AT command notifications %s", notif_enabled ? "enabled" : "disabled");
}

void at_gatt_hdlr_reg(at_gatt_rx_hdlr_t rx_cb)
{
	at_gatt_rx_handler = rx_cb;
}

BT_GATT_SERVICE_DEFINE(sensor_beacon_svc, BT_GATT_PRIMARY_SERVICE(BT_UUID_SENSOR_BEACON),
		       BT_GATT_CHARACTERISTIC(BT_UUID_SENSOR_BEACON_TXRX,
					      BT_GATT_CHRC_WRITE | BT_GATT_CHRC_NOTIFY,
					      BT_GATT_PERM_WRITE, NULL, write_at_cmd_info,
					      at_cmd_info),
		       BT_GATT_CCC(at_cmd_ccc_changed, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE), );

void at_gatt_notify(uint8_t const *data, uint16_t len)
{
	if (len > AT_CMD_INFO_SIZE) {
		LOG_WRN("AT response too long (%" PRId32 " bytes), truncating to %d", len,
			(int)AT_CMD_INFO_SIZE);
		len = AT_CMD_INFO_SIZE;
	}

	memcpy(at_cmd_info, data, len);
	bt_gatt_notify(NULL, &sensor_beacon_svc.attrs[1], at_cmd_info, len);
}
