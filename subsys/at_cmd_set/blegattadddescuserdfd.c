/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/bluetooth/uuid.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"
#include "at_cmd_gatt_dyn.h"

#define CMD_NAME      "BLEGATTADDDESCUSERDFD"
#define CMD_PARM_FMT  "A(2~2),A(16~16),W(1~1024)"
#define CMD_PARM_DESC "<sec_prop>,<uuid>,<max_size>"
#define CMD_PARM_NUM  3

LOG_MODULE_REGISTER(blegattadddescuserdfd, CONFIG_AT_CMD_SET_LOG_LEVEL);

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type != at_cmd_type_exec) {
		return;
	}

	uint8_t *sec_prop_be = AT_PASR_GET_PARAM(param, array, 0);
	uint16_t sec_prop = sys_get_be16(sec_prop_be);

	uint8_t *uuid = AT_PASR_GET_PARAM(param, array, 1);

	if (AT_PASR_GET_PARAM_LEN(param, 1) != BT_UUID_SIZE_128) {
		LOG_ERR("Invalid UUID length");
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID, param);
		return;
	}

	uint16_t max_size = AT_PASR_GET_PARAM(param, u16, 2);

	at_cmd_result_t result = at_cmd_gatt_dyn_add_userdfd(sec_prop, uuid, max_size);

	if (result.err || result.app_err) {
		AT_CMD_RESULT_TO_PARAM(result, param);
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, "", 0);
