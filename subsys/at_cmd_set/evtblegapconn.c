/*
 * Copyright (c) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <inttypes.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"
#include "at_cmd_event.h"

#define CMD_NAME    "EVTBLEGAPCONN"
#define EVT_RSP_FMT "B,B,A(6~6)"
#define EVT_RSP_NUM 3

LOG_MODULE_REGISTER(evtblegapconn, CONFIG_AT_CMD_SET_LOG_LEVEL);

typedef struct {
	uint8_t idx;
	uint8_t addr_type;
	uint8_t addr[6]; /* MSB-first for display */
} at_cmd_conn_evt_t;

static void conn_evt_handler(uint8_t ch, void const *evt_data, uint16_t evt_data_len)
{
	if (evt_data_len < sizeof(at_cmd_conn_evt_t)) {
		LOG_ERR("Invalid event data length");
		return;
	}

	const at_cmd_conn_evt_t *evt = evt_data;
	const at_cmd_t *evt_cmd = AT_CMD_EVT_DEF(CMD_NAME, EVT_RSP_FMT, EVT_RSP_NUM);

	at_cmd_resp(ch, at_all, evt_cmd, 0, EVT_RSP_NUM, evt->idx, evt->addr_type, evt->addr,
		    (uint16_t)sizeof(evt->addr));
}

void at_cmd_evt_conn(uint8_t ch, uint8_t idx, const struct bt_conn_info *info)
{
	at_cmd_conn_evt_t evt = {
		.idx = idx,
		.addr_type = info->le.remote->type,
	};

	for (uint8_t i = 0; i < sizeof(evt.addr); i++) {
		evt.addr[i] = info->le.remote->a.val[BT_ADDR_SIZE - 1 - i];
	}

	at_cmd_evt_submit(conn_evt_handler, ch, &evt, sizeof(evt));
}
