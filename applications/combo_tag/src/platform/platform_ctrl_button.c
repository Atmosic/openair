/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#ifdef CONFIG_COMBO_TAG_BTN_POWER_CTRL
#include <zephyr/drivers/hwinfo.h>
#endif
#include "arch.h"
#include "power.h"
#include "platform.h"
#include "platform_ctrl_led.h"
#include "platform_ctrl_battery.h"
#include "atm_gfp.h"
#ifdef CONFIG_COMBO_TAG_AUDIO_FEEDBACK
#include "platform_ctrl_buzzer.h"
#endif

LOG_MODULE_DECLARE(combo_tag, CONFIG_COMBO_TAG_LOG_LEVEL);

/* Button timing constants */
#define BUTTON_POWERON_TIMEOUT_MS        2000
#define BUTTON_SHUTDOWN_TIMEOUT_MS       2000
#define BUTTON_SHORT_PRESS_MS            1800
#define BUTTON_CTS_TAP_TIMEOUT_MS        750
#define BUTTON_FACTORY_RESET_MS          10000
#define BUTTON_POLL_INTERVAL_MS          100
#define BUTTON_SHUTDOWN_POLL_MS          500
#define BATTERY_REPORT_TAP_COUNT         5
#define FACTORY_RESET_AUDIO_DURATION_MS  1000

static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(DT_ALIAS(sw0), gpios);
static struct gpio_callback button_cb_data;

static uint8_t cts_press = 0;
static struct k_work_delayable cts_tap_timeout_work;

static struct k_work fp_tag_button_notify;

static int64_t button_press_time;

#ifdef CONFIG_COMBO_TAG_BTN_BATT_REPORT
static void battery_report_handler(void)
{
	uint8_t batt_percentage = platform_ctrl_batt_status_get();
	cts_press = 0;
	LOG_INF("Battery report: %d%%", batt_percentage);

#ifdef CONFIG_COMBO_TAG_LED_IND
	// Battery level LED indication
	if (batt_percentage > 90) {
		// 5 blinks for >90%
		platform_ctrl_led_event_indicate(LED_EVT_BATT_FULL);
	} else if (batt_percentage > 60) {
		// 4 blinks for >60%
		platform_ctrl_led_event_indicate(LED_EVT_BATT_HIGH);
	} else if (batt_percentage > 30) {
		// 3 blinks for >30%
		platform_ctrl_led_event_indicate(LED_EVT_BATT_MEDIUM);
	} else if (batt_percentage > 10) {
		// 2 blinks for >10%
		platform_ctrl_led_event_indicate(LED_EVT_BATT_LOW);
	} else {
		// 1 blink for <=10%
		platform_ctrl_led_event_indicate(LED_EVT_BATT_CRITICAL);
	}
#endif
}
#endif

static void fp_tag_button_invoke_notify(struct k_work *work)
{
	LOG_INF("Button notify fp_tag");
	atm_gfp_button_notify();
}

static void cts_tap_timeout_handler(struct k_work *work)
{
	LOG_INF("short pressed times %d", cts_press);
#ifdef CONFIG_COMBO_TAG_BTN_BATT_REPORT
	// Handle battery report (BATTERY_REPORT_TAP_COUNT quick presses)
	if (cts_press >= BATTERY_REPORT_TAP_COUNT) {
		battery_report_handler();
	}
#endif
	cts_press = 0;
}

#ifdef CONFIG_COMBO_TAG_BTN_FACTORY_RESET
static void factory_reset_handler(void)
{
#ifdef CONFIG_COMBO_TAG_AUDIO_FEEDBACK
	LOG_INF("Play audio feedback");
	platform_ctrl_buzzer_action(true);
	k_sleep(K_MSEC(FACTORY_RESET_AUDIO_DURATION_MS));
	platform_ctrl_buzzer_action(false);
#endif

#ifdef CONFIG_COMBO_TAG_LED_IND
	platform_ctrl_led_event_indicate(LED_EVT_FACTORY_RESET);
#endif
	platform_factory_reset();
}
#endif

#ifdef CONFIG_COMBO_TAG_BTN_POWER_CTRL
static void shutdown_timeout_cb(struct k_work *work)
{
	LOG_INF("shutdown timeout");
	platform_ctrl_led_state_update(LED_STATE_POWER_OFF);
	platform_ctrl_led_event_indicate(LED_EVT_POWER_OFF);

#ifdef CONFIG_COMBO_TAG_BTN_FACTORY_RESET
	bool factory_reset = false;
#endif

	// Wait for button release
	while (gpio_pin_get_dt(&button)) {
		k_sleep(K_MSEC(BUTTON_SHUTDOWN_POLL_MS));
#ifdef CONFIG_COMBO_TAG_BTN_FACTORY_RESET
		if (!factory_reset && (k_uptime_get() - button_press_time > BUTTON_FACTORY_RESET_MS)) {
			LOG_INF("factory reset timeout");
			factory_reset = true;
			factory_reset_handler();
		}
#endif
	}
	pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
}

static K_WORK_DELAYABLE_DEFINE(shutdown_timeout_work, shutdown_timeout_cb);
#endif

static void button_cb(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
	if (gpio_pin_get_dt(&button)) {
		LOG_INF("Button Pressed");
		button_press_time = k_uptime_get();
		// Cancel CTS timeout when button is pressed (new tap event)
		k_work_cancel_delayable(&cts_tap_timeout_work);
#ifdef CONFIG_COMBO_TAG_BTN_POWER_CTRL
		k_work_reschedule(&shutdown_timeout_work, K_MSEC(BUTTON_SHUTDOWN_TIMEOUT_MS));
#endif
	} else {
		LOG_INF("Button Released");
		if (!button_press_time) {
			return;
		}

		int64_t press_duration = k_uptime_get() - button_press_time;
		button_press_time = 0;

		if (press_duration < BUTTON_SHORT_PRESS_MS) {
			// Short press - handle button work
			cts_press++;
			k_work_reschedule(&cts_tap_timeout_work, K_MSEC(BUTTON_CTS_TAP_TIMEOUT_MS));
			// Always notify fp_tag for button press
			k_work_submit(&fp_tag_button_notify);
		} else {
			// Long press - cancel CTS timeout
			cts_press = 0;
			k_work_cancel_delayable(&cts_tap_timeout_work);
		}
#ifdef CONFIG_COMBO_TAG_BTN_POWER_CTRL
		// Cancel shutdown timeout when button is released
		k_work_cancel_delayable(&shutdown_timeout_work);
#endif
	}
}

bool platform_ctrl_button_init(void)
{
	int err = gpio_pin_configure_dt(&button, GPIO_INPUT);
	if (err) {
		LOG_ERR("Error %d: failed to configure %s pin %u", err, button.port->name,
			button.pin);
		return false;
	}
	err = gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_BOTH);
	if (err) {
		LOG_ERR("Error %d: failed to configure interrupt on %s pin %u", err,
			button.port->name, button.pin);
		return false;
	}

#ifdef CONFIG_COMBO_TAG_BTN_POWER_CTRL
	uint32_t reset_cause;
	atm_socoff_wakeup_gpio_set(true);
	hwinfo_get_reset_cause(&reset_cause);
	LOG_INF("reset_cause: %#x", reset_cause);

	if (reset_cause & (RESET_SOFTWARE | RESET_WATCHDOG)
		|| (reset_cause == RESET_HARDWARE)) {
		LOG_INF("direct power on");
		goto direct_power_on;
	}

	int64_t timestamp = k_uptime_get();

	while (gpio_pin_get_dt(&button)) {
		k_sleep(K_MSEC(BUTTON_POLL_INTERVAL_MS));
		if (k_uptime_get() - timestamp > BUTTON_POWERON_TIMEOUT_MS) {
			platform_ctrl_led_event_indicate(LED_EVT_POWER_ON);
			break;
		}
	}

	if (k_uptime_delta(&timestamp) < BUTTON_POWERON_TIMEOUT_MS) {
		LOG_INF("pressed less than %dms", BUTTON_POWERON_TIMEOUT_MS);
		return false;
	}

	// Button Pressed Over BUTTON_POWERON_TIMEOUT_MS, Proceed to Power on
direct_power_on:
#endif
	LOG_INF("power on");

	// Initialize work items
	k_work_init(&fp_tag_button_notify, fp_tag_button_invoke_notify);
	k_work_init_delayable(&cts_tap_timeout_work, cts_tap_timeout_handler);
	gpio_init_callback(&button_cb_data, button_cb, BIT(button.pin));
	gpio_add_callback(button.port, &button_cb_data);
	LOG_INF("Set up button at %s pin %u", button.port->name, button.pin);
	return true;
}
