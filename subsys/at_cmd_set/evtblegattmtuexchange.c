/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/init.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"
#include "at_cmd_event.h"

#define CMD_NAME    "EVTBLEGATTMTUEXCHANGE"
#define EVT_RSP_FMT "B,W"
#define EVT_RSP_NUM 2

LOG_MODULE_REGISTER(evtblegattmtuexchange, CONFIG_AT_CMD_SET_LOG_LEVEL);

typedef struct {
	uint8_t idx;
	uint16_t mtu;
} at_cmd_mtu_exchange_evt_t;

static void mtu_exchange_evt_handler(uint8_t ch, void const *evt_data, uint16_t evt_data_len)
{
	if (evt_data_len < sizeof(at_cmd_mtu_exchange_evt_t)) {
		LOG_ERR("Invalid event data length");
		return;
	}

	const at_cmd_mtu_exchange_evt_t *evt = evt_data;
	const at_cmd_t *evt_cmd = AT_CMD_EVT_DEF(CMD_NAME, EVT_RSP_FMT, EVT_RSP_NUM);

	at_cmd_resp(ch, at_all, evt_cmd, 0, EVT_RSP_NUM, evt->idx, evt->mtu);
}

void at_cmd_evt_mtu_exchange(uint8_t ch, uint8_t idx, uint16_t mtu)
{
	at_cmd_mtu_exchange_evt_t evt = {
		.idx = idx,
		.mtu = mtu,
	};

	at_cmd_evt_submit(mtu_exchange_evt_handler, ch, &evt, sizeof(evt));
}

static void at_cmd_gatt_mtu_updated(struct bt_conn *conn, uint16_t tx, uint16_t rx)
{
	ARG_UNUSED(rx);

	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	if (!ctx || (ctx->ch == AT_CMD_INVALID_CH)) {
		return;
	}

	for (uint8_t i = 0; i < ctx->conn_count; i++) {
		if (ctx->conns[i] == conn) {
			at_cmd_evt_mtu_exchange(ctx->ch, i, tx);
			return;
		}
	}

	LOG_DBG("conn not found in tracking array, MTU update ignored");
}

static struct bt_gatt_cb at_cmd_gatt_cb = {
	.att_mtu_updated = at_cmd_gatt_mtu_updated,
};

static int evtblegattmtuexchange_init(void)
{
	bt_gatt_cb_register(&at_cmd_gatt_cb);
	return 0;
}

SYS_INIT(evtblegattmtuexchange_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
