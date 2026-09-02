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

LOG_MODULE_REGISTER(evttaggfpreversering, CONFIG_AT_CMD_SET_LOG_LEVEL);

/*
Event:
  +EVTTAGGFPREVERSERING:<evt>
Parameters:
  evt: 0=CONNECTED    (phone ringing; tag connected via RR advertisement)
       1=STARTED      (phone confirmed ringing started via GATT)
       2=STOPPED      (phone stopped ringing; any reason)
       3=ADV_STARTED  (tag started advertising for adv-based reverse ringing)
       4=ADV_TIMEOUT  (ADV window expired; phone never connected, never rang)
       5=PHONE_FAILED    (phone reported it could not start ringing)
       6=TIMEOUT_LOCAL   (provider-side ringing timeout after seeker connected)
       7=PHONE_TIMEOUT   (phone's own ring session timed out)
       8=START_CONFIRMED          (START indication ACKed; persistent path fast feedback)
       9=STOP_CONFIRMED           (STOP indication ACKed; persistent path fast feedback)
      10=PHONE_STOPPED_DISCONNECTED (BLE connection dropped while phone was ringing)
      11=PHONE_START_TIMEOUT     (persistent path 60s timeout after START indication)
*/

#define EVT_NAME    "EVTTAGGFPREVERSERING"
#define EVT_RSP_FMT "B"
#define EVT_RSP_NUM 1

typedef struct {
	uint8_t evt;
} gfp_reverse_ring_evt_data_t;

static void evt_gfp_reverse_ring_handler(uint8_t ch, void const *evt_data, uint16_t evt_data_len)
{
	const gfp_reverse_ring_evt_data_t *evt = evt_data;
	const at_cmd_t *evt_cmd = AT_CMD_EVT_DEF(EVT_NAME, EVT_RSP_FMT, EVT_RSP_NUM);

	if (evt_data_len < sizeof(gfp_reverse_ring_evt_data_t)) {
		LOG_ERR("Invalid event data length");
		return;
	}

	LOG_INF("Event: evt=%u", evt->evt);
	at_cmd_resp(ch, at_all, evt_cmd, 0, EVT_RSP_NUM, evt->evt);
}

void at_cmd_evt_gfp_reverse_ring(uint8_t ch, uint8_t evt)
{
	gfp_reverse_ring_evt_data_t const data = {
		.evt = evt,
	};
	at_cmd_evt_submit(evt_gfp_reverse_ring_handler, ch, &data, sizeof(data));
}
