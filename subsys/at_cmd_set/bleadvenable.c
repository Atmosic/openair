/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <string.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME          "BLEADVENABLE"
#define CMD_PARM_FMT      "B(0~1),S(2~3)"
#define CMD_PARM_DESC     "<act_idx>,<ON|OFF>"
#define CMD_PARM_NUM      2
#define RSP_PARM_PAIR_FMT "B,B"
#define RSP_PARM_PAIR_NUM 2
#define RSP_PARM_FMT      AT_CMD_RSP_FMT_REPEAT(RSP_PARM_PAIR_FMT)
#define RSP_PARM_NUM      AT_CMD_RSP_PARM_NUM_REPEAT(RSP_PARM_PAIR_NUM)

#define PARAM_ADV_ON  "ON"
#define PARAM_ADV_OFF "OFF"

LOG_MODULE_REGISTER(bleadvenable, CONFIG_AT_CMD_SET_LOG_LEVEL);

/**
 * AT COMMAND HANDLER
 *******************************************************************************
 */
static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	if (param->type == at_cmd_type_exec) {
		uint8_t idx = AT_PASR_GET_PARAM(param, u8, 0);
		if (idx >= AT_CMD_ADV_MAX_INST) {
			LOG_ERR("Invalid advertising index %u, max %u", idx, AT_CMD_ADV_MAX_INST);
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_ADV_INVALID_INDEX, param);
			return;
		}

		bool action = false;
		uint8_t on_len = strlen(PARAM_ADV_ON);
		uint8_t off_len = strlen(PARAM_ADV_OFF);
		if ((on_len == AT_PASR_GET_PARAM_LEN(param, 1)) &&
		    !memcmp(AT_PASR_GET_PARAM(param, string, 1), PARAM_ADV_ON, on_len)) {
			action = true;
		} else if ((off_len == AT_PASR_GET_PARAM_LEN(param, 1)) &&
			   !memcmp(AT_PASR_GET_PARAM(param, string, 1), PARAM_ADV_OFF, off_len)) {
			action = false;
		} else {
			LOG_ERR("Invalid action \"%.*s\", allowed: ON|OFF",
				AT_PASR_GET_PARAM_LEN(param, 1),
				AT_PASR_GET_PARAM(param, string, 1));
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID, param);
			return;
		}

		at_cmd_result_t result = at_cmd_adv_enable(idx, action);
		AT_CMD_RESULT_TO_PARAM(result, param);
	} else if (param->type == at_cmd_type_query) {
		for (uint8_t i = 0; i < AT_CMD_ADV_MAX_INST; i++) {
			AT_CMD_RSP_REPEAT(param->ch, param->cmd, i, AT_CMD_ADV_MAX_INST, 2, i,
					  ctx->adv_enabled[i] ? 1 : 0);
		}
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
