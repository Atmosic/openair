/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <string.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set.h"
#include "at_cmd_set_common.h"

#define CMD_NAME           "BLEADVLEGACYPARM"
#define CMD_PARM_FMT       "B(0~1),W(32~16384),W(32~16384),W(0~65535)"
#define CMD_PARM_DESC      "<adv_idx>,<interval_min>,<interval_max>,<duration>"
#define CMD_PARM_NUM       4
#define RSP_PARM_GROUP_FMT "B,W,W,W"
#define RSP_PARM_PAIR_NUM  4
#define RSP_PARM_FMT       AT_CMD_RSP_FMT_REPEAT(RSP_PARM_GROUP_FMT)
#define RSP_PARM_NUM       AT_CMD_RSP_PARM_NUM_REPEAT(RSP_PARM_PAIR_NUM)

LOG_MODULE_REGISTER(bleadvlegacyparm, CONFIG_AT_CMD_SET_LOG_LEVEL);

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

		uint16_t intv_min = AT_PASR_GET_PARAM(param, u16, 1);
		uint16_t intv_max = AT_PASR_GET_PARAM(param, u16, 2);
		uint16_t duration = AT_PASR_GET_PARAM(param, u16, 3);

		ctx->adv_intv_min[idx] = intv_min;
		ctx->adv_intv_max[idx] = intv_max;
		ctx->adv_duration[idx] = duration;
#ifdef CONFIG_AT_CMD_BLEADVENABLE
		if (ctx->adv_enabled[idx]) {
			at_cmd_result_t result = at_cmd_adv_restart(idx);
			AT_CMD_RESULT_TO_PARAM(result, param);
			if (param->err) {
				return;
			}
		}
#endif

#ifdef CONFIG_AT_CMD_BLEADVLEGACYPARM_CB
		if (ctx->callbacks.advlegacyparm_set_cb) {
			ctx->callbacks.advlegacyparm_set_cb(idx, intv_min, intv_max, duration);
		}
#endif
	} else if (param->type == at_cmd_type_query) {
		for (uint8_t i = 0; i < AT_CMD_ADV_MAX_INST; i++) {
			AT_CMD_RSP_REPEAT(param->ch, param->cmd, i, AT_CMD_ADV_MAX_INST, 4, i,
					  ctx->adv_intv_min[i], ctx->adv_intv_max[i],
					  ctx->adv_duration[i]);
		}
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
