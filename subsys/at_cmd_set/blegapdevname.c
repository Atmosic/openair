/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <errno.h>
#include <inttypes.h>
#include <string.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/util.h>
#include "at_cmd.h"
#include "at_cmd_set.h"
#include "at_cmd_set_common.h"

#define DEV_NAME_MAX  CONFIG_BT_DEVICE_NAME_MAX
#define CMD_NAME      "BLEGAPDEVNAME"
#define CMD_PARM_FMT  "S(~" STRINGIFY(DEV_NAME_MAX) ")"
#define CMD_PARM_DESC "<name>"
#define CMD_PARM_NUM  1
#define RSP_PARM_FMT  "S"
#define RSP_PARM_NUM  1

LOG_MODULE_REGISTER(blegapdevname, CONFIG_AT_CMD_SET_LOG_LEVEL);

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type == at_cmd_type_query) {
		const char *name = bt_get_name();

		at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, name ? name : "");
		return;
	}

	if (param->type != at_cmd_type_exec) {
		return;
	}

	uint8_t name_len = AT_PASR_GET_PARAM_LEN(param, 0);

	if (name_len > DEV_NAME_MAX) {
		LOG_ERR("Device name length %" PRIu8 " exceeds max %u", name_len, DEV_NAME_MAX);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID_LENGTH, param);
		return;
	}

	char name[DEV_NAME_MAX + 1U];

	if (name_len) {
		const uint8_t *name_param = AT_PASR_GET_PARAM(param, string, 0);

		memcpy(name, name_param, name_len);
	}
	name[name_len] = '\0';

	int ret = bt_set_name(name);

	if (ret) {
		LOG_ERR("bt_set_name(\"%s\") failed: %d", name, ret);
		AT_CMD_ERRNO_TO_PARAM(ret, param);
		return;
	}

#ifdef CONFIG_AT_CMD_BLEGAPDEVNAME_CB
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	if (ctx->callbacks.devname_set_cb) {
		ctx->callbacks.devname_set_cb(name);
	}
#endif
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
