/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"
#include "at_cmd_gatt.h"

#define CMD_NAME      "BLEGATTDFTCHAR2"
#define CMD_PARM_FMT  "A(2~2),A(16~16)"
#define CMD_PARM_DESC "<sec_prop>,<uuid>"
#define CMD_PARM_NUM  2
#define CMD_RSP_FMT   "A(2~2),A(16~16)"
#define CMD_RSP_NUM   2

LOG_MODULE_REGISTER(blegattdftchar2, CONFIG_AT_CMD_SET_LOG_LEVEL);

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type == at_cmd_type_exec) {
		/* Parse sec_prop (MSB-first, 2 bytes) */
		uint8_t *sec_prop_be = AT_PASR_GET_PARAM(param, array, 0);
		uint16_t sec_prop = sys_get_be16(sec_prop_be);

		if (!at_cmd_gatt_is_valid_perm(sec_prop)) {
			LOG_ERR("Invalid sec_prop: 0x%04X", sec_prop);
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID, param);
			return;
		}

		/* Parse UUID (BT_UUID_SIZE_128 bytes) */
		uint8_t *uuid = AT_PASR_GET_PARAM(param, array, 1);
		if (AT_PASR_GET_PARAM_LEN(param, 1) != BT_UUID_SIZE_128) {
			LOG_ERR("Invalid UUID length");
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID, param);
			return;
		}

		/* Save to context and Settings */
		at_cmd_result_t result = at_cmd_gatt_dft_char2_set(sec_prop, uuid);
		if (result.err || result.app_err) {
			AT_CMD_RESULT_TO_PARAM(result, param);
		}

	} else if (param->type == at_cmd_type_query) {
		uint16_t sec_prop;
		uint8_t uuid[BT_UUID_SIZE_128];

		at_cmd_result_t result = at_cmd_gatt_dft_char2_get(&sec_prop, uuid);
		if (result.err || result.app_err) {
			AT_CMD_RESULT_TO_PARAM(result, param);
			return;
		}

		/* Return as MSB-first */
		uint8_t sec_prop_be[2];
		sys_put_be16(sec_prop, sec_prop_be);

		at_cmd_resp(param->ch, at_all, param->cmd, 0, 2, sec_prop_be, 2, uuid,
			    BT_UUID_SIZE_128);
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, CMD_RSP_FMT,
	   CMD_RSP_NUM);
