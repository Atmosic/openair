/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set.h"
#include "at_cmd_set_common.h"
#include "at_cmd_event.h"

#define CMD_NAME      "SYSFUNCPIN"
#define CMD_PARM_FMT  "B,B(0~1),B(0~4)"
#define CMD_PARM_DESC "<io>,<direction>,<signal>"
#define CMD_PARM_NUM  3
#define RSP_PARM_FMT  "B,B,B"
#define RSP_PARM_NUM  3

/* <direction> values */
#define DIR_INPUT  0U
#define DIR_OUTPUT 1U

/* <signal> values */
#define SIG_LOW    0U
#define SIG_HIGH   1U
#define SIG_RISING 2U
#define SIG_FALL   3U
#define SIG_PULLUP 4U

LOG_MODULE_REGISTER(sysfuncpin, CONFIG_AT_CMD_SET_LOG_LEVEL);

/* Stored state for query response */
static uint8_t g_io;
static uint8_t g_direction;
static uint8_t g_signal;

/* GPIO callback and ISR-to-thread bridge */
static const struct device *g_gpio_dev;
static struct gpio_callback g_gpio_cb;
static struct k_work g_gpio_work;
static bool g_cb_registered;

/**
 * System work queue handler — deferred from GPIO ISR to thread context.
 * Calls at_cmd_evt_sysfuncpin() which is NOT safe from ISR (uses k_malloc).
 */
static void gpio_notify_work_handler(struct k_work *work)
{
	ARG_UNUSED(work);

	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	at_cmd_evt_sysfuncpin(ctx->ch, g_io);
}

/**
 * GPIO ISR callback — runs in ISR context.
 * Disables interrupt (prevents level-trigger re-fire) and defers to work queue.
 */
static void gpio_isr_cb(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
	ARG_UNUSED(dev);
	ARG_UNUSED(cb);
	ARG_UNUSED(pins);

	gpio_pin_interrupt_configure(g_gpio_dev, g_io, GPIO_INT_DISABLE);
	k_work_submit(&g_gpio_work);
}

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type == at_cmd_type_query) {
		at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, g_io, g_direction,
			    g_signal);
		return;
	}

	if (param->type != at_cmd_type_exec) {
		return;
	}

	uint8_t io = AT_PASR_GET_PARAM(param, u8, 0);
	uint8_t direction = AT_PASR_GET_PARAM(param, u8, 1);
	uint8_t signal = AT_PASR_GET_PARAM(param, u8, 2);

	/* Pull-up (signal=4) is input-only */
	if ((direction == DIR_OUTPUT) && (signal == SIG_PULLUP)) {
		LOG_ERR("Pull-up (signal=4) is input only");
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID, param);
		return;
	}

	const struct device *gpio_dev = DEVICE_DT_GET(DT_NODELABEL(gpio0));

	if (!device_is_ready(gpio_dev)) {
		LOG_ERR("GPIO device not ready");
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_GPIO_NOT_READY, param);
		return;
	}

	/* Remove previous interrupt callback and disable interrupt */
	if (g_cb_registered) {
		gpio_pin_interrupt_configure(g_gpio_dev, g_io, GPIO_INT_DISABLE);
		gpio_remove_callback(g_gpio_dev, &g_gpio_cb);
		g_cb_registered = false;
	}

	g_gpio_dev = gpio_dev;

	int ret;

	if (direction == DIR_INPUT) {
		gpio_flags_t pin_flags = GPIO_INPUT;

		if (signal == SIG_PULLUP) {
			pin_flags |= GPIO_PULL_UP;
		}

		ret = gpio_pin_configure(gpio_dev, io, pin_flags);
		if (ret) {
			LOG_ERR("gpio_pin_configure failed: %d", ret);
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_GPIO_CONFIG, param);
			return;
		}

		if (signal != SIG_PULLUP) {
			gpio_flags_t int_flags;

			switch (signal) {
			case SIG_LOW:
				int_flags = GPIO_INT_LEVEL_LOW;
				break;
			case SIG_HIGH:
				int_flags = GPIO_INT_LEVEL_HIGH;
				break;
			case SIG_RISING:
				int_flags = GPIO_INT_EDGE_RISING;
				break;
			case SIG_FALL:
			default:
				int_flags = GPIO_INT_EDGE_FALLING;
				break;
			}

			k_work_init(&g_gpio_work, gpio_notify_work_handler);
			gpio_init_callback(&g_gpio_cb, gpio_isr_cb, BIT(io));
			ret = gpio_add_callback(gpio_dev, &g_gpio_cb);
			if (ret) {
				LOG_ERR("gpio_add_callback failed: %d", ret);
				AT_CMD_APP_ERR_TO_PARAM(AT_ERR_GPIO_CONFIG, param);
				return;
			}
			g_cb_registered = true;

			ret = gpio_pin_interrupt_configure(gpio_dev, io, int_flags);
			if (ret) {
				LOG_ERR("gpio_pin_interrupt_configure failed: %d", ret);
				gpio_remove_callback(gpio_dev, &g_gpio_cb);
				g_cb_registered = false;
				AT_CMD_APP_ERR_TO_PARAM(AT_ERR_GPIO_CONFIG, param);
				return;
			}
		}
	} else {
		gpio_flags_t out_flags =
			(signal == SIG_LOW) ? GPIO_OUTPUT_INACTIVE : GPIO_OUTPUT_ACTIVE;

		ret = gpio_pin_configure(gpio_dev, io, out_flags);
		if (ret) {
			LOG_ERR("gpio_pin_configure output failed: %d", ret);
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_GPIO_CONFIG, param);
			return;
		}
	}

	g_io = io;
	g_direction = direction;
	g_signal = signal;
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
