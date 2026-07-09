/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"
#include "at_cmd_event.h"

#define CMD_NAME    "EVTBLESMPPASSKEYREQIND"
#define EVT_RSP_FMT "B"
#define EVT_RSP_NUM 1

LOG_MODULE_REGISTER(evtblesmppasskeyreqind, CONFIG_AT_CMD_SET_LOG_LEVEL);

typedef struct {
	uint8_t idx;
} at_cmd_smp_passkeyreq_evt_t;

static void smp_passkeyreq_evt_handler(uint8_t ch, void const *evt_data, uint16_t evt_data_len)
{
	if (evt_data_len < sizeof(at_cmd_smp_passkeyreq_evt_t)) {
		LOG_ERR("Invalid event data length");
		return;
	}

	const at_cmd_smp_passkeyreq_evt_t *evt = evt_data;
	const at_cmd_t *evt_cmd = AT_CMD_EVT_DEF(CMD_NAME, EVT_RSP_FMT, EVT_RSP_NUM);

	at_cmd_resp(ch, at_all, evt_cmd, 0, EVT_RSP_NUM, evt->idx);
}

void at_cmd_evt_smp_passkeyreqind(uint8_t ch, uint8_t idx)
{
	at_cmd_smp_passkeyreq_evt_t evt = {
		.idx = idx,
	};

	at_cmd_evt_submit(smp_passkeyreq_evt_handler, ch, &evt, sizeof(evt));
}
