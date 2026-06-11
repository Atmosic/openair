/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <inttypes.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/gap.h>
#include <zephyr/init.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"
#include "at_cmd_event.h"

#define CMD_NAME    "EVTBLEGAPADVRPT"
#define EVT_RSP_FMT "B,B,A(6~6),b,W,A(0~" AT_CMD_MAX_ADV_DATA_LEN_STR ")"
#define EVT_RSP_NUM 6

LOG_MODULE_REGISTER(evtblegapadvrpt, CONFIG_AT_CMD_SET_LOG_LEVEL);

typedef struct {
	uint8_t evt_type;
	uint8_t addr_type;
	uint8_t addr[BT_ADDR_SIZE]; /* MSB-first for display */
	uint8_t rssi;               /* int8_t encoded as uint8_t; interpret as signed */
	uint16_t data_len;
	uint8_t data[AT_CMD_MAX_ADV_DATA_LEN];
} at_cmd_adv_rpt_evt_t;

static void adv_rpt_evt_handler(uint8_t ch, void const *evt_data, uint16_t evt_data_len)
{
	if (evt_data_len < sizeof(at_cmd_adv_rpt_evt_t)) {
		LOG_ERR("Invalid event data length");
		return;
	}

	const at_cmd_adv_rpt_evt_t *evt = evt_data;
	const at_cmd_t *evt_cmd = AT_CMD_EVT_DEF(CMD_NAME, EVT_RSP_FMT, EVT_RSP_NUM);

	at_cmd_resp(ch, at_all, evt_cmd, 0, EVT_RSP_NUM, evt->evt_type, evt->addr_type, evt->addr,
		    (uint16_t)sizeof(evt->addr), evt->rssi, evt->data_len, evt->data,
		    evt->data_len);
}

void at_cmd_evt_adv_rpt(uint8_t ch, const struct bt_le_scan_recv_info *info,
			struct net_buf_simple *buf)
{
	if ((!info) || (!buf) || (!info->addr)) {
		return;
	}

	bool is_ext = !!(info->adv_props & BT_GAP_ADV_PROP_EXT_ADV);
	bool is_scan_rsp = !!(info->adv_props & BT_GAP_ADV_PROP_SCAN_RESPONSE);
	uint8_t evt_type;

	if (is_scan_rsp) {
		evt_type = is_ext ? AT_CMD_EVT_ADV_TYPE_EXT_SCAN_RSP
				  : AT_CMD_EVT_ADV_TYPE_LEGACY_SCAN_RSP;
	} else if (is_ext) {
		evt_type = AT_CMD_EVT_ADV_TYPE_EXT_ADV;
	} else {
		evt_type = AT_CMD_EVT_ADV_TYPE_LEGACY_ADV;
	}

	LOG_INF("evt_type %" PRIu8 ", addr_type = %" PRIu8 ", rssi = %" PRId8 ", addr: %02" PRIX8
		"%02" PRIX8 "%02" PRIX8 "%02" PRIX8 "%02" PRIX8 "%02" PRIX8,
		evt_type, info->addr->type, (int8_t)info->rssi, info->addr->a.val[0],
		info->addr->a.val[1], info->addr->a.val[2], info->addr->a.val[3],
		info->addr->a.val[4], info->addr->a.val[5]);

	at_cmd_adv_rpt_evt_t evt = {
		.evt_type = evt_type,
		.addr_type = info->addr->type,
		.rssi = (uint8_t)(int8_t)info->rssi,
		.data_len = MIN(buf->len, (uint16_t)sizeof(evt.data)),
	};

	for (uint8_t i = 0; i < sizeof(evt.addr); i++) {
		evt.addr[i] = info->addr->a.val[BT_ADDR_SIZE - 1 - i];
	}

	if (evt.data_len) {
		memcpy(evt.data, buf->data, evt.data_len);
	}

	at_cmd_evt_submit(adv_rpt_evt_handler, ch, &evt, sizeof(evt));
}

static void at_cmd_scan_recv(const struct bt_le_scan_recv_info *info, struct net_buf_simple *buf)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	if ((!info) || (!buf) || (!info->addr) || (ctx->ch == AT_CMD_INVALID_CH)) {
		return;
	}

#ifdef CONFIG_AT_CMD_BLESCANFILRSSI
	/* RSSI filter is mutually exclusive with the MAC filter: bypass it when
	 * the controller Filter Accept List (AT+BLESCANFILMAC) is active so that
	 * the targeted device's advertisement always reaches the host regardless
	 * of signal strength. */
#ifdef CONFIG_AT_CMD_BLESCANFILMAC
	if (!ctx->scan_mac_filter_enabled) {
#endif
		if (info->rssi < ctx->scan_rssi_threshold) {
			static uint32_t rssi_drop_count;
			static int64_t rssi_drop_window_ms;

			rssi_drop_count++;
			int64_t now = k_uptime_get();

			if (!rssi_drop_window_ms) {
				rssi_drop_window_ms = now;
			}

			if ((now - rssi_drop_window_ms) >=
			    CONFIG_AT_CMD_BLESCANFILRSSI_LOG_WINDOW_MS) {
				LOG_INF("RSSI drop count: %" PRIu32 "/s (threshold %" PRId8 " dBm)",
					rssi_drop_count, ctx->scan_rssi_threshold);
				rssi_drop_count = 0;
				rssi_drop_window_ms = now;
			}
			return;
		}
#ifdef CONFIG_AT_CMD_BLESCANFILMAC
	}
#endif
#endif

	at_cmd_evt_adv_rpt(ctx->ch, info, buf);
}

static int evtblegapadvrpt_init(void)
{
	static struct bt_le_scan_cb at_cmd_scan_callbacks = {
		.recv = at_cmd_scan_recv,
	};

	int err = bt_le_scan_cb_register(&at_cmd_scan_callbacks);

	if ((err) && (err != -EEXIST)) {
		LOG_ERR("bt_le_scan_cb_register failed (err %d)", err);
		return err;
	}

	return 0;
}

SYS_INIT(evtblegapadvrpt_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
