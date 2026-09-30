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

#define EVT_NAME    "EVTTAGRANGINGCFGCS"
#define EVT_RSP_FMT "B,B"
#define EVT_RSP_NUM 2

LOG_MODULE_REGISTER(evttagrangingcfgcs, CONFIG_AT_CMD_SET_LOG_LEVEL);

typedef struct {
	uint8_t sec_type;
	uint8_t start_immediately;
} ranging_cfg_cs_evt_data_t;

static void ranging_cfg_cs_evt_handler(uint8_t ch, void const *evt_data, uint16_t evt_data_len)
{
	const ranging_cfg_cs_evt_data_t *evt = evt_data;
	const at_cmd_t *evt_cmd = AT_CMD_EVT_DEF(EVT_NAME, EVT_RSP_FMT, EVT_RSP_NUM);

	if (evt_data_len != sizeof(*evt)) {
		LOG_ERR("Invalid CS ranging event data length: %u", evt_data_len);
		return;
	}
	at_cmd_resp(ch, at_all, evt_cmd, 0, EVT_RSP_NUM, evt->sec_type, evt->start_immediately);
}

#ifdef CONFIG_ATM_AT_CMDTEST
void at_cmd_evt_tag_ranging_cfg_cs_test_invalid_len(uint8_t ch)
{
	uint8_t data = 0;

	ranging_cfg_cs_evt_handler(ch, &data, 0);
}
#endif

void at_cmd_evt_tag_ranging_cfg_cs(uint8_t ch, uint8_t sec_type, uint8_t start_immediately)
{
	ranging_cfg_cs_evt_data_t evt = {
		.sec_type = sec_type,
		.start_immediately = start_immediately,
	};
	int ret = at_cmd_evt_submit(ranging_cfg_cs_evt_handler, ch, &evt, sizeof(evt));
	if (ret < 0) {
		LOG_ERR("Failed to queue CS ranging event: %d", ret);
	}
}
