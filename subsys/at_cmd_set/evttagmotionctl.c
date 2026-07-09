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

LOG_MODULE_REGISTER(evttagmotionctl, CONFIG_AT_CMD_SET_LOG_LEVEL);

/*
Event:
  +EVTTAGMOTIONCTL=<enable>
Parameters:
  enable : 0 = disable motion sensor
           1 = enable motion sensor
*/

#define EVT_NAME    "EVTTAGMOTIONCTL"
#define EVT_RSP_FMT "B"
#define EVT_RSP_NUM 1

/**
 * @brief TAG motion control event data structure
 */
typedef struct {
	uint8_t enable; /**< 0 = disable, 1 = enable */
} tag_motionctl_evt_data_t;

static void evt_tag_motionctl_handler(uint8_t ch, void const *evt_data, uint16_t evt_data_len)
{
	const tag_motionctl_evt_data_t *evt = evt_data;
	const at_cmd_t *evt_cmd = AT_CMD_EVT_DEF(EVT_NAME, EVT_RSP_FMT, EVT_RSP_NUM);

	if (evt_data_len < sizeof(tag_motionctl_evt_data_t)) {
		LOG_ERR("Invalid event data length");
		return;
	}

	LOG_INF("Event: enable=%u", evt->enable);
	at_cmd_resp(ch, at_all, evt_cmd, 0, EVT_RSP_NUM, evt->enable);
}

void at_cmd_evt_motionctl(uint8_t ch, uint8_t enable)
{
	tag_motionctl_evt_data_t const data = {
		.enable = enable,
	};
	at_cmd_evt_submit(evt_tag_motionctl_handler, ch, &data, sizeof(data));
}
