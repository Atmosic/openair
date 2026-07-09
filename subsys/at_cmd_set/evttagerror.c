/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set.h"
#include "at_cmd_event.h"

LOG_MODULE_REGISTER(evttagerror, CONFIG_AT_CMD_SET_LOG_LEVEL);

/*
Event:
  +EVTTAGERROR=<protocol>,<error_code>
Parameters:
  protocol : Supported Tag protocols
  error_code : Tag error code
*/

#define EVT_NAME    "EVTTAGERROR"
#define EVT_RSP_FMT "B,B"
#define EVT_RSP_NUM 2

/**
 * @brief TAG error event data structure
 */
typedef struct {
	uint8_t protocol;   /**< TAG protocol */
	uint8_t error_code; /**< TAG error code */
} tag_error_evt_t;

static void evt_tag_error_handler(uint8_t ch, void const *evt_data, uint16_t evt_data_len)
{
	const tag_error_evt_t *evt = evt_data;
	const at_cmd_t *evt_cmd = AT_CMD_EVT_DEF(EVT_NAME, EVT_RSP_FMT, EVT_RSP_NUM);

	if (evt_data_len < sizeof(tag_error_evt_t)) {
		LOG_ERR("Invalid event data length");
		return;
	}

	LOG_INF("Event: protocol=%d, error_code=%d", evt->protocol, evt->error_code);
	at_cmd_resp(ch, at_all, evt_cmd, 0, EVT_RSP_NUM, evt->protocol, evt->error_code);
}

void at_cmd_evt_tag_error(uint8_t ch, uint8_t protocol, uint8_t error_code)
{
	tag_error_evt_t const evt = {
		.protocol = protocol,
		.error_code = error_code,
	};
	at_cmd_evt_submit(evt_tag_error_handler, ch, &evt, sizeof(evt));
}
