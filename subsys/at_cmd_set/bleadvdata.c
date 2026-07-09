/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <string.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME          "BLEADVDATA"
#define CMD_PARM_FMT      "B(0~1),A(~" AT_CMD_MAX_ADV_DATA_LEN_STR ")"
#define CMD_PARM_DESC     "<act_idx>,<advertising data>"
#define CMD_PARM_NUM      2
#define RSP_PARM_PAIR_FMT "B,A(~" AT_CMD_MAX_ADV_DATA_LEN_STR ")"
#define RSP_PARM_PAIR_NUM 2
#define RSP_PARM_FMT      AT_CMD_RSP_FMT_REPEAT(RSP_PARM_PAIR_FMT)
#define RSP_PARM_NUM      AT_CMD_RSP_PARM_NUM_REPEAT(RSP_PARM_PAIR_NUM)

LOG_MODULE_REGISTER(bleadvdata, CONFIG_AT_CMD_SET_LOG_LEVEL);

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

		uint16_t arr_len = AT_PASR_GET_PARAM_LEN(param, 1);
		uint8_t *arr = AT_PASR_GET_PARAM(param, array, 1);

		if (arr_len > AT_CMD_MAX_ADV_DATA_LEN) {
			LOG_ERR("Adv data too long: %u, max %u", arr_len, AT_CMD_MAX_ADV_DATA_LEN);
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_ADV_DATA_TOO_LONG, param);
			return;
		}

		memcpy(ctx->adv_data[idx], arr, arr_len);
		ctx->adv_data_len[idx] = arr_len;
		LOG_DBG("Set adv data idx=%u, len=%u", idx, arr_len);
		if (ctx->adv_enabled[idx]) {
			at_cmd_result_t result = at_cmd_adv_update_data(ctx, idx);
			AT_CMD_RESULT_TO_PARAM(result, param);
			if (param->err) {
				return;
			}
			LOG_DBG("update adv data on instance %u", idx);
		} else {
			LOG_DBG("Advertising not enabled on instance %u, data will be applied when"
				" advertising is started",
				idx);
		}
	} else if (param->type == at_cmd_type_query) {
		for (uint8_t i = 0; i < AT_CMD_ADV_MAX_INST; i++) {
			AT_CMD_RSP_REPEAT(param->ch, param->cmd, i, AT_CMD_ADV_MAX_INST, 2, i,
					  ctx->adv_data[i], ctx->adv_data_len[i]);
		}
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
