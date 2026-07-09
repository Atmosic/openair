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

LOG_MODULE_REGISTER(evttagbuzzer, CONFIG_AT_CMD_SET_LOG_LEVEL);

/*
Event:
  +EVTTAGBUZZER=<evt>,<ring_vol>,<duration_ds>
Parameters:
  evt        : Buzzer event type (see tag_buzzer_evt_t in platform_indicate.h)
  ring_vol   : Ring volume level (relevant for GFP ring events and STF sound events, 0 otherwise)
  duration_ds: Ring duration in deciseconds (relevant for GFP ring events only, 0 otherwise)
*/

#define EVT_NAME    "EVTTAGBUZZER"
#define EVT_RSP_FMT "B,B,W"
#define EVT_RSP_NUM 3

/**
 * @brief TAG buzzer event data structure
 */
typedef struct {
	uint8_t evt;          /**< Buzzer event type */
	uint8_t ring_vol;     /**< Ring volume level */
	uint16_t duration_ds; /**< Ring duration in deciseconds */
} tag_buzzer_evt_data_t;

static void evt_tag_buzzer_handler(uint8_t ch, void const *evt_data, uint16_t evt_data_len)
{
	const tag_buzzer_evt_data_t *evt = evt_data;
	const at_cmd_t *evt_cmd = AT_CMD_EVT_DEF(EVT_NAME, EVT_RSP_FMT, EVT_RSP_NUM);

	if (evt_data_len < sizeof(tag_buzzer_evt_data_t)) {
		LOG_ERR("Invalid event data length");
		return;
	}

	LOG_INF("Event: evt=%u ring_vol=%u duration_ds=%u", evt->evt, evt->ring_vol,
		evt->duration_ds);
	at_cmd_resp(ch, at_all, evt_cmd, 0, EVT_RSP_NUM, evt->evt, evt->ring_vol, evt->duration_ds);
}

void at_cmd_evt_buzzer_action(uint8_t ch, uint8_t evt, uint8_t ring_vol, uint16_t duration_ds)
{
	tag_buzzer_evt_data_t const data = {
		.evt = evt,
		.ring_vol = ring_vol,
		.duration_ds = duration_ds,
	};
	at_cmd_evt_submit(evt_tag_buzzer_handler, ch, &data, sizeof(data));
}
