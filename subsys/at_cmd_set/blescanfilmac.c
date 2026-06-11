/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <string.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME      "BLESCANFILMAC"
#define CMD_PARM_FMT  "S(2~3),B(0~1),A(6~6)"
#define CMD_PARM_DESC "<enable(" PARAM_ON "|" PARAM_OFF ")>,<addr_type(0=pub,1=rand)>,<addr>"
#define CMD_PARM_NUM  3
/* Query returns <enable(ON|OFF)>,<addr_type>,<addr> */
#define RSP_PARM_FMT  "S(2~3),B,A(6~6)"
#define RSP_PARM_NUM  3

LOG_MODULE_REGISTER(blescanfilmac, CONFIG_AT_CMD_SET_LOG_LEVEL);

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	if (param->type == at_cmd_type_exec) {
		if (ctx->scan_enabled) {
			LOG_WRN("Cannot set scan filter while scanning is active");
			AT_CMD_ERRNO_TO_PARAM(-EBUSY, param);
			return;
		}

		bool enable;
		size_t on_len = strlen(PARAM_ON);
		size_t off_len = strlen(PARAM_OFF);

		if ((on_len == AT_PASR_GET_PARAM_LEN(param, 0)) &&
		    (!memcmp(AT_PASR_GET_PARAM(param, string, 0), PARAM_ON, on_len))) {
			enable = true;
		} else if ((off_len == AT_PASR_GET_PARAM_LEN(param, 0)) &&
			   (!memcmp(AT_PASR_GET_PARAM(param, string, 0), PARAM_OFF, off_len))) {
			enable = false;
		} else {
			param->err = AT_CMD_ERR_WRONG_ARGU_CONTENT;
			return;
		}

		if (enable) {
			uint8_t addr_type = AT_PASR_GET_PARAM(param, u8, 1);
			uint8_t *addr_bytes = AT_PASR_GET_PARAM(param, array, 2);
			uint16_t addr_len = AT_PASR_GET_PARAM_LEN(param, 2);

			if (addr_len != BT_ADDR_SIZE) {
				param->err = AT_CMD_ERR_WRONG_ARGU_CONTENT;
				return;
			}

			/* Only clear the Filter Accept List if a previous entry exists;
			 * clearing an empty list returns -EIO on some controllers. */
			if (ctx->scan_mac_filter_enabled) {
				int err = bt_le_filter_accept_list_clear();

				if (err) {
					LOG_ERR("filter_accept_list_clear failed (err %d)", err);
					AT_CMD_ERRNO_TO_PARAM(err, param);
					return;
				}
			}

			bt_addr_le_t filter_addr = {
				.type = addr_type,
			};

			sys_memcpy_swap(filter_addr.a.val, addr_bytes, BT_ADDR_SIZE);
			int err = bt_le_filter_accept_list_add(&filter_addr);

			if (err) {
				LOG_ERR("filter_accept_list_add failed (err %d)", err);
				AT_CMD_ERRNO_TO_PARAM(err, param);
				return;
			}

			ctx->scan_filter_addr = filter_addr;
			/* MAC filter is now active. RSSI filter (AT+BLESCANFILRSSI) is
			 * mutually exclusive: it is automatically bypassed in the scan
			 * report handler while scan_mac_filter_enabled is true. */
			ctx->scan_mac_filter_enabled = true;
		} else {
			uint8_t addr_type = AT_PASR_GET_PARAM(param, u8, 1);
			uint8_t *addr_bytes = AT_PASR_GET_PARAM(param, array, 2);
			uint16_t addr_len = AT_PASR_GET_PARAM_LEN(param, 2);

			if (addr_len != BT_ADDR_SIZE) {
				param->err = AT_CMD_ERR_WRONG_ARGU_CONTENT;
				return;
			}

			if (ctx->scan_mac_filter_enabled) {
				int err = bt_le_filter_accept_list_clear();

				if (err) {
					LOG_ERR("filter_accept_list_clear failed (err %d)", err);
					AT_CMD_ERRNO_TO_PARAM(err, param);
					return;
				}

				/* MAC filter cleared. RSSI filter (AT+BLESCANFILRSSI) is
				 * automatically restored in the scan report handler now
				 * that scan_mac_filter_enabled is false. */
				ctx->scan_mac_filter_enabled = false;
			}

			/* Save addr even when disabling so the query response always
			 * reflects the last configured address. */
			bt_addr_le_t filter_addr = {
				.type = addr_type,
			};

			sys_memcpy_swap(filter_addr.a.val, addr_bytes, BT_ADDR_SIZE);
			ctx->scan_filter_addr = filter_addr;
		}
	} else if (param->type == at_cmd_type_query) {
		uint8_t display_addr[BT_ADDR_SIZE];

		sys_memcpy_swap(display_addr, ctx->scan_filter_addr.a.val, BT_ADDR_SIZE);
		const char *state = ctx->scan_mac_filter_enabled ? PARAM_ON : PARAM_OFF;

		at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, state,
			    ctx->scan_filter_addr.type, display_addr, (uint16_t)BT_ADDR_SIZE);
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
