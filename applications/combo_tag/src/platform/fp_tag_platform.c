/**
 *******************************************************************************
 *
 * @file fp_tag_platform.c
 *
 * @brief Platform For fp tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/reboot.h>
#include "app_work_q.h"
#include "atm_gfp.h"
#include "fp_mode.h"
#include "fp_tag_platform.h"
#include "platform_ctrl_battery.h"
#include "platform_ctrl_buzzer.h"

LOG_MODULE_DECLARE(combo_tag, CONFIG_COMBO_TAG_LOG_LEVEL);

#define BUTTON0 DT_ALIAS(sw0)
#if DT_NODE_EXISTS(BUTTON0)
#else
BUILD_ASSERT("DT_NODE_EXISTS BUTTON0");
#endif

static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET_OR(BUTTON0, gpios, {0});
static struct gpio_callback button_cb_data;
static tag_state_notify_cb fp_tag_state_notify;
static tag_state_t gfp_st = TAG_STATE_INVALID;

static void fp_tag_button_invoke_notify(struct k_work *work);
K_WORK_DEFINE(fp_tag_button_notify, fp_tag_button_invoke_notify);

static void fp_tag_button_invoke_notify(struct k_work *work)
{
	LOG_INF("Button Perform Notify");
	atm_gfp_button_notify();
}

static void fp_tag_button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
	LOG_DBG("Button pressed at %" PRIu32, pins);
	atm_work_submit_to_app_work_q(&fp_tag_button_notify);
}

static void fp_tag_platform_button_monitor(void)
{
	int err = gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_TO_ACTIVE);
	if (err) {
		LOG_ERR("Error %d: failed to configure interrupt on %s pin %u", err,
			button.port->name, button.pin);
		return;
	}

	gpio_init_callback(&button_cb_data, fp_tag_button_pressed, BIT(button.pin));
	gpio_add_callback(button.port, &button_cb_data);
	LOG_DBG("Set up button at %s pin %u", button.port->name, button.pin);
}

static void fp_tag_platform_reset(void)
{
	LOG_INF("Button Perform Reset");
	atm_gfp_reset();
}

static void fp_tag_platform_stop(void)
{
	if (gfp_st < TAG_STATE_PAIRED) {
		atm_gfp_stop();
	}
}

static void fp_tag_platform_start(void)
{
	if (gfp_st < TAG_STATE_PAIRED) {
		atm_gfp_start();
	}
}

static bool fp_tag_platform_is_paired(void)
{
	return atm_gfp_is_provisioned();
}

static void fp_tag_mode_state(fp_mode_t mode)
{
	tag_state_t tag_st;
	if ((gfp_st == TAG_STATE_INVALID) && (mode == FP_MODE_NONE)) {
		tag_st = TAG_STATE_INIT_DONE;
	} else if ((gfp_st > TAG_STATE_UNPAIRED) && (mode == FP_MODE_NONE)) {
		tag_st = TAG_STATE_UNPAIRED;
	} else if (mode == FP_MODE_PAIRING_PROCESSING) {
		tag_st = TAG_STATE_PAIRING;
	} else if (mode == FP_MODE_PROVISIONED) {
		tag_st = TAG_STATE_PAIRED;
	} else {
		LOG_DBG("ignore fp mode %u", mode);
		return;
	}
	if (gfp_st == tag_st) {
		return;
	}
	LOG_DBG("gfp_st %u, tag_st %u, fp_mode %u", gfp_st, tag_st, mode);
	gfp_st = tag_st;
	if (fp_tag_state_notify) {
		fp_tag_state_notify(gfp_st, TAG_TYPE_FP);
	}
	if (gfp_st == TAG_STATE_UNPAIRED) {
		fp_tag_platform_start();
	}
}

static void fp_tag_platform_init(tag_state_notify_cb fn_cb)
{
	fp_tag_state_notify = fn_cb;
	static atm_gfp_hdlrs_t const hdlrs = {
		.battery_status_cb = platform_ctrl_batt_status_get,
		.sound_action_cb = platform_ctrl_buzzer_action,
		.mode_state_cb = fp_tag_mode_state,
	};
	atm_gfp_init(&hdlrs);
	fp_tag_platform_button_monitor();
}

void fp_tag_platform_hdlrs_get(tag_hdlrs_t *hdlrs)
{
	hdlrs->init = fp_tag_platform_init;
	hdlrs->reset = fp_tag_platform_reset;
	hdlrs->start = fp_tag_platform_start;
	hdlrs->stop = fp_tag_platform_stop;
	hdlrs->is_paired = fp_tag_platform_is_paired;
}
