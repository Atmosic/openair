/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <string.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>
#include "at_cmd.h"
#include "at_cmd_event.h"
#include "at_cmd_set_common.h"

LOG_MODULE_REGISTER(evtblegattnoti, CONFIG_AT_CMD_SET_LOG_LEVEL);

#define EVT_NAME    "BLEGATTNOTI"
#define EVT_RSP_FMT "B,W,A(0~" STRINGIFY(CONFIG_AT_CMD_GATT_CLIENT_RD_MAX_LEN) ")"
#define EVT_RSP_NUM 3

typedef struct {
	uint8_t conidx;
	uint16_t handle;
	uint16_t data_len;
	uint8_t data[];
} gattc_noti_evt_t;

static void noti_handler(uint8_t ch, void const *evt_data, uint16_t evt_data_len)
{
	if (evt_data_len < sizeof(gattc_noti_evt_t)) {
		LOG_ERR("noti_handler: invalid length %u", evt_data_len);
		return;
	}

	const gattc_noti_evt_t *evt = evt_data;
	const at_cmd_t *evt_cmd = AT_CMD_EVT_DEF(EVT_NAME, EVT_RSP_FMT, EVT_RSP_NUM);

	at_cmd_resp(ch, at_all, evt_cmd, 0, EVT_RSP_NUM, evt->conidx, evt->handle, evt->data,
		    evt->data_len);
}

void at_cmd_evt_blegattnoti(uint8_t ch, uint8_t conidx, uint16_t handle, const uint8_t *data,
			    uint16_t len)
{
	uint16_t capped = MIN(len, (uint16_t)CONFIG_AT_CMD_GATT_CLIENT_RD_MAX_LEN);
	size_t evt_size = sizeof(gattc_noti_evt_t) + capped;
	gattc_noti_evt_t *evt = k_malloc(evt_size);

	if (!evt) {
		LOG_ERR("at_cmd_evt_blegattnoti: failed to allocate buffer");
		return;
	}

	evt->conidx = conidx;
	evt->handle = handle;
	evt->data_len = capped;
	if (capped && data) {
		memcpy(evt->data, data, capped);
	}

	at_cmd_evt_submit(noti_handler, ch, evt, (uint16_t)evt_size);
	k_free(evt);
}
