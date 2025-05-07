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
#include <zephyr/sys/reboot.h>
#include <zephyr/kernel.h>
#include "app_work_q.h"
#include "atm_gfp.h"
#include "fp_tag_platform.h"
#include "fp_tag_platform_ctrl.h"
#include "reset.h"

LOG_MODULE_DECLARE(fp_tag, CONFIG_FP_TAG_LOG_LEVEL);

#define BUTTON0 DT_ALIAS(sw0)
#if DT_NODE_EXISTS(BUTTON0)
#else
BUILD_ASSERT("DT_NODE_EXISTS BUTTON0");
#endif

static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET_OR(BUTTON0, gpios, {0});
static struct gpio_callback button_cb_data;

static void fp_tag_button_invoke_reset(struct k_work *work);
static void fp_tag_button_invoke_notify(struct k_work *work);
K_WORK_DEFINE(fp_tag_button_reset, fp_tag_button_invoke_reset);
K_WORK_DEFINE(fp_tag_button_notify, fp_tag_button_invoke_notify);

static void fp_tag_button_invoke_reset(struct k_work *work)
{
	LOG_INF("Button Perform Reset");
	atm_gfp_reset();
	fp_tag_platform_ctrl_reset();
	LOG_INF("Perform SYS_REBOOT_WARM");
	sys_reboot(SYS_REBOOT_WARM);
}

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

void fp_tag_platform_gpio_init(void)
{
	int err = gpio_pin_configure_dt(&button, GPIO_INPUT);
	if (err) {
		LOG_ERR("Error %d: failed to configure %s pin %u", err, button.port->name,
			button.pin);
		return;
	}
}

void fp_tag_platform_reset_detect(void)
{
	if (!is_boot_type(TYPE_POWER_ON)) {
		return;
	}

	if (!gpio_pin_get_dt(&button)) {
		return;
	}

	LOG_INF("Button pressed, perform FMDN unpair");
	atm_work_submit_to_app_work_q(&fp_tag_button_reset);
}

void fp_tag_platform_init(void)
{
	static atm_gfp_hdlrs_t const hdlrs = {
		.battery_status_cb = fp_tag_platform_battery_status_get,
		.sound_action_cb = fp_tag_platform_ctrl_buzzer_action,
	};
	fp_tag_platform_ctrl_init();
	atm_gfp_init(&hdlrs);
	fp_tag_platform_button_monitor();
}
