/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include "arch.h"
#include "at_cmd.h"
#include "at_cmd_set.h"
#include "at_cmd_event.h"

LOG_MODULE_REGISTER(evttest, CONFIG_AT_CMD_SET_LOG_LEVEL);

#define EVT_NAME    "TESTEVENT"
#define EVT_RSP_FMT "B,A(0~32)"
#define EVT_RSP_NUM 2

typedef struct {
	uint16_t len;
	uint8_t data[32];
} evt_test_data_t;

static void evt_test_handler(uint8_t ch, void const *evt_data, uint16_t evt_data_len)
{
	const evt_test_data_t *evt = evt_data;
	const at_cmd_t *evt_cmd = AT_CMD_EVT_DEF(EVT_NAME, EVT_RSP_FMT, EVT_RSP_NUM);

	if (evt_data_len < sizeof(evt_test_data_t)) {
		LOG_ERR("Invalid event data length");
		return;
	}

	LOG_INF("Event: len=%d", evt->len);
	if (evt->len) {
		LOG_HEXDUMP_INF(evt->data, evt->len, "Data:");
	}
	at_cmd_resp(ch, at_all, evt_cmd, 0, EVT_RSP_NUM, 0, evt->data, evt->len);
}

void at_cmd_evt_test(uint8_t ch, uint8_t const *data, uint16_t len)
{
	evt_test_data_t evt = {
		.len = (len > sizeof(evt.data)) ? sizeof(evt.data) : len,
	};

	if (data && evt.len) {
		memcpy(evt.data, data, evt.len);
	}

	at_cmd_evt_submit(evt_test_handler, ch, &evt, sizeof(evt));
}
