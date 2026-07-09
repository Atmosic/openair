/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <inttypes.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"
#include "at_cmd_event.h"

#define CMD_NAME    "EVTBLESMPNUMCOMPIND"
#define EVT_RSP_FMT "B,D"
#define EVT_RSP_NUM 2

LOG_MODULE_REGISTER(evtblesmpnumcompind, CONFIG_AT_CMD_SET_LOG_LEVEL);

typedef struct {
	uint8_t idx;
	uint32_t passkey;
} at_cmd_smp_numcomp_evt_t;

static void smp_numcomp_evt_handler(uint8_t ch, void const *evt_data, uint16_t evt_data_len)
{
	if (evt_data_len < sizeof(at_cmd_smp_numcomp_evt_t)) {
		LOG_ERR("Invalid event data length");
		return;
	}

	const at_cmd_smp_numcomp_evt_t *evt = evt_data;
	const at_cmd_t *evt_cmd = AT_CMD_EVT_DEF(CMD_NAME, EVT_RSP_FMT, EVT_RSP_NUM);

	at_cmd_resp(ch, at_all, evt_cmd, 0, EVT_RSP_NUM, evt->idx, evt->passkey);
}

void at_cmd_evt_smp_numcompind(uint8_t ch, uint8_t idx, uint32_t passkey)
{
	at_cmd_smp_numcomp_evt_t evt = {
		.idx = idx,
		.passkey = passkey,
	};

	at_cmd_evt_submit(smp_numcomp_evt_handler, ch, &evt, sizeof(evt));
}
