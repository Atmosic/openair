/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME      "BLESCANFILRSSI"
#define RSSI_RANGE    STRINGIFY(AT_CMD_SCAN_RSSI_MIN) "~" STRINGIFY(AT_CMD_SCAN_RSSI_MAX)
#define CMD_PARM_FMT  "b(" RSSI_RANGE ")"
#define CMD_PARM_DESC "<rssi_threshold(" RSSI_RANGE "dBm)>"
#define CMD_PARM_NUM  1
/* Query returns <active(ON=active,OFF=bypassed_by_mac)>,<threshold> */
#define RSP_PARM_FMT  "S(2~3),b"
#define RSP_PARM_NUM  2

LOG_MODULE_REGISTER(blescanfilrssi, CONFIG_AT_CMD_SET_LOG_LEVEL);

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

		/* RSSI filter is the default mode. It is mutually exclusive with
		 * the MAC filter (AT+BLESCANFILMAC): enabling MAC automatically
		 * bypasses RSSI; disabling MAC automatically restores it. Only
		 * the threshold is stored here — the active/bypassed state is
		 * derived dynamically from scan_mac_filter_enabled at query time. */
		ctx->scan_rssi_threshold = AT_PASR_GET_PARAM(param, i8, 0);
	} else if (param->type == at_cmd_type_query) {
		/* ON  = RSSI filter is active (MAC filter is off).
		 * OFF = RSSI filter is bypassed (MAC filter is on). */
		const char *active = PARAM_ON;
#ifdef CONFIG_AT_CMD_BLESCANFILMAC
		active = ctx->scan_mac_filter_enabled ? PARAM_OFF : PARAM_ON;
#endif
		at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, active,
			    ctx->scan_rssi_threshold);
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
