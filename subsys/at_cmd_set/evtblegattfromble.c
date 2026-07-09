/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>
#include "at_cmd.h"
#include "at_cmd_event.h"
#include "at_cmd_gatt_utils.h"

LOG_MODULE_REGISTER(evtblegattfromble, CONFIG_AT_CMD_SET_LOG_LEVEL);

#define EVT_NAME    "EVTBLEGATTFROMBLE"
#define EVT_RSP_FMT "B,A(2~2),B,A(0~1024)"
#define EVT_RSP_NUM 4

typedef struct {
	uint8_t conidx;
	uint8_t handle_be[2]; /**< BT GATT handle, big-endian */
	uint8_t action;
	uint16_t data_len;
	uint8_t data[];
} gatt_from_ble_evt_t;

static void gatt_from_ble_handler(uint8_t ch, void const *evt_data, uint16_t evt_data_len)
{
	if (evt_data_len < sizeof(gatt_from_ble_evt_t)) {
		LOG_ERR("Invalid event data length");
		return;
	}

	const gatt_from_ble_evt_t *evt = evt_data;
	const at_cmd_t *evt_cmd = AT_CMD_EVT_DEF(EVT_NAME, EVT_RSP_FMT, EVT_RSP_NUM);

	at_cmd_resp(ch, at_all, evt_cmd, 0, EVT_RSP_NUM, evt->conidx, evt->handle_be,
		    (uint16_t)sizeof(evt->handle_be), evt->action, evt->data, evt->data_len);
}

/**
 * @brief Send +EVTBLEGATTFROMBLE event when a client reads/writes a characteristic.
 * Shared by DFT and DYN GATT server callbacks.
 */
void at_cmd_evt_gatt_from_ble(uint8_t conidx, uint16_t handle, at_cmd_gatt_act_t action,
			      const uint8_t *data, uint16_t len)
{
	LOG_DBG("conidx=%u, handle=0x%04x, action=%02X, len=%u", conidx, handle, action, len);

	size_t evt_size = sizeof(gatt_from_ble_evt_t) + len;
	gatt_from_ble_evt_t *evt = k_malloc(evt_size);

	if (!evt) {
		LOG_ERR("Failed to allocate event buffer");
		return;
	}

	evt->conidx = conidx;
	sys_put_be16(handle, evt->handle_be);
	evt->action = (uint8_t)action;
	evt->data_len = len;
	if (len && data) {
		memcpy(evt->data, data, len);
	}

	/* Route the event on the current AT-command channel */
	uint8_t ch = at_cmd_ctx_get()->ch;

	at_cmd_evt_submit(gatt_from_ble_handler, ch, evt, (uint16_t)evt_size);
	k_free(evt);
}
