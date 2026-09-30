/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <inttypes.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>
#include <zephyr/logging/log_ctrl.h>
#include "at_cmd.h"
#include "at_cmd_set.h"
#include "at_cmd_set_common.h"
#include "power.h"

#define CMD_NAME      "SYSPM"
#define CMD_PARM_FMT  "B(1~1),B,B(0~1)"
#define CMD_PARM_DESC "<mode>,<io>,<wakeup_level>"
#define CMD_PARM_NUM  3
#define RSP_PARM_FMT  "B,B,B"
#define RSP_PARM_NUM  3

/* <mode> values */
#define SYSPM_MODE_HIBERNATE 1U

/* <wakeup_level> values */
#define WAKEUP_LOW  0U
#define WAKEUP_HIGH 1U

LOG_MODULE_REGISTER(syspm, CONFIG_AT_CMD_SET_LOG_LEVEL);

/* Stored state for query response */
static uint8_t g_mode;
static uint8_t g_io;
static uint8_t g_wakeup_level;

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type == at_cmd_type_query) {
		at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, g_mode, g_io,
			    g_wakeup_level);
		return;
	}

	if (param->type != at_cmd_type_exec) {
		return;
	}

	uint8_t mode = AT_PASR_GET_PARAM(param, u8, 0);
	uint8_t io = AT_PASR_GET_PARAM(param, u8, 1);
	uint8_t wakeup_level = AT_PASR_GET_PARAM(param, u8, 2);

	/* Only hibernation mode is currently supported (enforced by parser range B(1~1)) */
	if (mode != SYSPM_MODE_HIBERNATE) {
		LOG_ERR("Unsupported power mode: %" PRIu8, mode);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID, param);
		return;
	}

	const struct device *gpio_dev = DEVICE_DT_GET(DT_NODELABEL(gpio0));

	if (!device_is_ready(gpio_dev)) {
		LOG_ERR("GPIO device not ready");
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_GPIO_NOT_READY, param);
		return;
	}

	/* Configure GPIO as input for wakeup */
	int ret = gpio_pin_configure(gpio_dev, io, GPIO_INPUT);

	if (ret) {
		LOG_ERR("gpio_pin_configure P%" PRIu8 " failed: %d", io, ret);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_GPIO_CONFIG, param);
		return;
	}

	/* Set wakeup polarity via GPIO interrupt configuration.
	 * PSEQ reads GPIO INTENSET / INTPOLSET to build the hibernate wake mask.
	 */
	gpio_flags_t wake_flags =
		(wakeup_level == WAKEUP_LOW) ? GPIO_INT_LEVEL_LOW : GPIO_INT_LEVEL_HIGH;

	ret = gpio_pin_interrupt_configure(gpio_dev, io, wake_flags);
	if (ret) {
		LOG_ERR("gpio_pin_interrupt_configure P%" PRIu8 " failed: %d", io, ret);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_GPIO_CONFIG, param);
		return;
	}

	g_mode = mode;
	g_io = io;
	g_wakeup_level = wakeup_level;

	LOG_INF("Entering hibernation, wakeup on P%" PRIu8 " level=%" PRIu8, io, wakeup_level);
	log_flush();

	/* Enter hibernation — does not return; device resets on wakeup */
	atm_pseq_hibernate(0, ATM_PD_URGENCY_GRACEFUL);
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
