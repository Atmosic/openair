/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set.h"
#include "at_cmd_event.h"
#include "at_cmd_tag.h"

#define EVT_NAME    "EVTTAGRANGINGCAP"
#define EVT_RSP_FMT "B"
#define EVT_RSP_NUM 1

LOG_MODULE_REGISTER(evttagrangingcap, CONFIG_AT_CMD_SET_LOG_LEVEL);

typedef struct {
	uint8_t tech_id;
} ranging_cap_evt_data_t;

static void ranging_cap_evt_handler(uint8_t ch, void const *evt_data, uint16_t evt_data_len)
{
	const ranging_cap_evt_data_t *evt = evt_data;
	const at_cmd_t *evt_cmd = AT_CMD_EVT_DEF(EVT_NAME, EVT_RSP_FMT, EVT_RSP_NUM);

	if (evt_data_len != sizeof(*evt)) {
		LOG_ERR("Invalid ranging capability event data length: %u", evt_data_len);
		return;
	}
	at_cmd_resp(ch, at_all, evt_cmd, 0, EVT_RSP_NUM, evt->tech_id);
}

#ifdef CONFIG_ATM_AT_CMDTEST
void at_cmd_evt_tag_ranging_cap_test_invalid_len(uint8_t ch)
{
	uint8_t data = 0;

	ranging_cap_evt_handler(ch, &data, 0);
}
#endif

void at_cmd_evt_tag_ranging_cap(uint8_t ch, uint8_t tech_id)
{
	ranging_cap_evt_data_t evt = {.tech_id = tech_id};
	int ret = at_cmd_evt_submit(ranging_cap_evt_handler, ch, &evt, sizeof(evt));
	if (ret < 0) {
		LOG_ERR("Failed to queue ranging capability event: %d", ret);
	}
}
