/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <string.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME           "BLEEXTADVPARM"
#define CMD_PARM_FMT       "B,W(32~16384),W(32~16384),W(0~65535),B(1~4)"
#define CMD_PARM_DESC      "<adv_idx>,<interval_min>,<interval_max>,<duration>,<primary_phy>"
#define CMD_PARM_NUM       5
#define RSP_PARM_GROUP_FMT "B,W,W,W,B"
#define RSP_PARM_PAIR_NUM  5
#define RSP_PARM_FMT       AT_CMD_RSP_FMT_REPEAT(RSP_PARM_GROUP_FMT)
#define RSP_PARM_NUM       AT_CMD_RSP_PARM_NUM_REPEAT(RSP_PARM_PAIR_NUM)

/* PHY values: 1=1M, 2=2M, 4=Coded */
#define PHY_1M    1
#define PHY_2M    2
#define PHY_CODED 4

LOG_MODULE_REGISTER(bleextadvparm, CONFIG_AT_CMD_SET_LOG_LEVEL);

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
		uint8_t primary_phy = AT_PASR_GET_PARAM(param, u8, 4);
		/* Validate PHY values: only 1M and Coded allowed as primary PHY (BT spec) */
		if ((primary_phy != PHY_1M) && (primary_phy != PHY_CODED)) {
			LOG_ERR("Invalid primary PHY %u, allowed: %u (1M) or %u (Coded)",
				primary_phy, PHY_1M, PHY_CODED);
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_ADV_INVALID_PARAM, param);
			return;
		}

		ctx->adv_intv_min[idx] = intv_min;
		ctx->adv_intv_max[idx] = intv_max;
		ctx->adv_duration[idx] = duration;
		ctx->adv_primary_phy[idx] = primary_phy;
		LOG_DBG("Set adv parameters idx=%u", idx);
		if (ctx->adv_set[idx]) {
			at_cmd_result_t result = at_cmd_adv_update_param(ctx, idx);
			AT_CMD_RESULT_TO_PARAM(result, param);
			if (param->err) {
				return;
			}
			LOG_DBG("update adv parameters on instance %u", idx);
		} else {
			LOG_DBG("Advertising set %u not created, parameters will be applied when "
				"set is created",
				idx);
		}
	} else if (param->type == at_cmd_type_query) {
		for (uint8_t i = 0; i < AT_CMD_ADV_MAX_INST; i++) {
			AT_CMD_RSP_REPEAT(param->ch, param->cmd, i, AT_CMD_ADV_MAX_INST, 5, i,
					  ctx->adv_intv_min[i], ctx->adv_intv_max[i],
					  ctx->adv_duration[i], ctx->adv_primary_phy[i]);
		}
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
