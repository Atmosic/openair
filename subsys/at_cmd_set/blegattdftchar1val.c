/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"
#include "at_cmd_gatt.h"

#define CMD_NAME      "BLEGATTDFTCHAR1VAL"
#define CMD_PARM_FMT  "A(0~512)"
#define CMD_PARM_DESC "<data>"
#define CMD_PARM_NUM  1
#define CMD_RSP_FMT   "A(0~512)"
#define CMD_RSP_NUM   1

LOG_MODULE_REGISTER(blegattdftchar1val, CONFIG_AT_CMD_SET_LOG_LEVEL);

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type == at_cmd_type_exec) {
		uint16_t len = AT_PASR_GET_PARAM_LEN(param, 0);
		uint8_t *data = AT_PASR_GET_PARAM(param, array, 0);

		at_cmd_result_t result = at_cmd_gatt_dft_char1_val_set(data, len);
		if (result.err || result.app_err) {
			AT_CMD_RESULT_TO_PARAM(result, param);
		}

	} else if (param->type == at_cmd_type_query) {
		uint8_t data[BT_ATT_MAX_ATTRIBUTE_LEN];
		uint16_t len;

		at_cmd_result_t result = at_cmd_gatt_dft_char1_val_get(data, &len);
		if (result.err || result.app_err) {
			AT_CMD_RESULT_TO_PARAM(result, param);
			return;
		}

		at_cmd_resp(param->ch, at_all, param->cmd, 0, CMD_RSP_NUM, data, len);
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, CMD_RSP_FMT,
	   CMD_RSP_NUM);
