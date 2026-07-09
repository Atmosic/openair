/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <string.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME          "BLESCANENABLE"
#define CMD_PARM_FMT      "S(2~3)"
#define CMD_PARM_DESC     "<" PARAM_ON "|" PARAM_OFF ">"
#define CMD_PARM_NUM      1
#define RSP_PARM_PAIR_FMT "S(2~3)"
#define RSP_PARM_NUM      1

LOG_MODULE_REGISTER(blescanenable, CONFIG_AT_CMD_SET_LOG_LEVEL);

/* bt_le_scan_start() automatically uses LE_Set_Extended_Scan_Parameters
 * when CONFIG_BT_EXT_ADV is enabled, receiving both legacy and extended
 * advertising reports. */
static int at_cmd_scan_start(void)
{
	struct bt_le_scan_param scan_param = {
		.type = BT_LE_SCAN_TYPE_ACTIVE,
		.options = BT_LE_SCAN_OPT_FILTER_DUPLICATE,
		.interval = BT_GAP_SCAN_FAST_INTERVAL,
		.window = BT_GAP_SCAN_FAST_WINDOW,
	};

#ifdef CONFIG_AT_CMD_BLESCANFILMAC
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();
	if (ctx->scan_mac_filter_enabled) {
		scan_param.options |= BT_LE_SCAN_OPT_FILTER_ACCEPT_LIST;
		/* With a single peer in the FAL the duplicate filter provides no
		 * benefit and its cache can persist across scan start/stop cycles
		 * on some controllers, suppressing the very first report.  Drop
		 * it so the first advertisement from the target is always visible. */
		scan_param.options &= ~BT_LE_SCAN_OPT_FILTER_DUPLICATE;
	}
#endif

	return bt_le_scan_start(&scan_param, NULL);
}

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	if (param->type == at_cmd_type_exec) {
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
			if (ctx->scan_enabled) {
				return;
			}

			int err = at_cmd_scan_start();

			if (err) {
				LOG_ERR("bt_le_scan_start failed (err %d)", err);
				AT_CMD_RESULT_TO_PARAM(at_cmd_result_err_from_errno(err), param);
				return;
			}

			ctx->scan_enabled = true;
		} else {
			if (!ctx->scan_enabled) {
				return;
			}

			int err = bt_le_scan_stop();

			if (err) {
				LOG_ERR("bt_le_scan_stop failed (err %d)", err);
				AT_CMD_RESULT_TO_PARAM(at_cmd_result_err_from_errno(err), param);
				return;
			}

			ctx->scan_enabled = false;
		}
	} else if (param->type == at_cmd_type_query) {
		const char *state = ctx->scan_enabled ? PARAM_ON : PARAM_OFF;

		at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, state);
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_PAIR_FMT,
	   RSP_PARM_NUM);
