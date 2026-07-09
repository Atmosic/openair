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

#define CMD_NAME    "EVTBLEGAPDISCONN"
#define EVT_RSP_FMT "B,B"
#define EVT_RSP_NUM 2

LOG_MODULE_REGISTER(evtblegapdisconn, CONFIG_AT_CMD_SET_LOG_LEVEL);

typedef struct {
	uint8_t idx;
	uint8_t reason;
} at_cmd_disconn_evt_t;

static void disconn_evt_handler(uint8_t ch, void const *evt_data, uint16_t evt_data_len)
{
	if (evt_data_len < sizeof(at_cmd_disconn_evt_t)) {
		LOG_ERR("Invalid event data length");
		return;
	}

	const at_cmd_disconn_evt_t *evt = evt_data;
	const at_cmd_t *evt_cmd = AT_CMD_EVT_DEF(CMD_NAME, EVT_RSP_FMT, EVT_RSP_NUM);

	at_cmd_resp(ch, at_all, evt_cmd, 0, EVT_RSP_NUM, evt->idx, evt->reason);
}

void at_cmd_evt_disconn(uint8_t ch, uint8_t idx, uint8_t reason)
{
	at_cmd_disconn_evt_t evt = {
		.idx = idx,
		.reason = reason,
	};

	at_cmd_evt_submit(disconn_evt_handler, ch, &evt, sizeof(evt));
}
