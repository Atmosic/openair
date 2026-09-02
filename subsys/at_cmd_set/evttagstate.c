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

LOG_MODULE_REGISTER(evttagstate, CONFIG_AT_CMD_SET_LOG_LEVEL);

/*
Event:
  +EVTTAGSTATE=<protocol>,<state>
Parameters:
  protocol : Supported Tag protocols
  state : Tag state
*/

#define EVT_NAME    "EVTTAGSTATE"
#define EVT_RSP_FMT "B,B"
#define EVT_RSP_NUM 2

/**
 * @brief TAG state event data (local structure)
 */
typedef struct {
	uint8_t protocol; /**< TAG protocol */
	uint8_t state;    /**< TAG state */
} tag_state_evt_t;

static void evt_tag_state_handler(uint8_t ch, void const *evt_data, uint16_t evt_data_len)
{
	const tag_state_evt_t *evt = evt_data;
	const at_cmd_t *evt_cmd = AT_CMD_EVT_DEF(EVT_NAME, EVT_RSP_FMT, EVT_RSP_NUM);

	if (evt_data_len < sizeof(tag_state_evt_t)) {
		LOG_ERR("Invalid event data length");
		return;
	}

	LOG_INF("Event: protocol=%d, state=%d", evt->protocol, evt->state);
	at_cmd_resp(ch, at_all, evt_cmd, 0, EVT_RSP_NUM, evt->protocol, evt->state);
}

void at_cmd_evt_tag_state(uint8_t ch, uint8_t protocol, uint8_t state)
{
	tag_state_evt_t const evt = {
		.protocol = protocol,
		.state = state,
	};
	at_cmd_evt_submit(evt_tag_state_handler, ch, &evt, sizeof(evt));
}
