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
#include <zephyr/drivers/hwinfo.h>
#include "arch.h"
#include "power.h"
#include "platform.h"
#include "platform_ctrl_led.h"
#include "platform_common.h"
#include "platform_ctrl_battery.h"
#include "platform_ctrl_wdt.h"
#ifdef CONFIG_FHN_TAG
#include "atm_gfp.h"
#endif
#if APP_STF_MULTI_MODE
#include "TagBtnCallback.h"
#include "TagSoundPlayer.h"
#endif
#ifdef CONFIG_TAG_AUDIO_FEEDBACK
#include "platform_ctrl_buzzer.h"
#endif
#ifdef CONFIG_ATM_CS
#include "atm_cs.h"
#endif
#ifdef CONFIG_TAG_BTN_OTA_MODE
#include "platform_ctrl_ota.h"
#endif

LOG_MODULE_DECLARE(multimode_consumer_tag, CONFIG_MULTIMODE_CONSUMER_TAG_LOG_LEVEL);

/* Button timing constants */
#define BUTTON_POWERON_TIMEOUT_MS       2000
#define BUTTON_SHUTDOWN_TIMEOUT_MS      2000
#define BUTTON_SHORT_PRESS_MS           1800
#define BUTTON_CTS_TAP_TIMEOUT_MS       750
#define BUTTON_FACTORY_RESET_MS         10000
#define BUTTON_POLL_INTERVAL_MS         100
#define BUTTON_SHUTDOWN_POLL_MS         500
#define BATTERY_REPORT_TAP_COUNT        5
#define FACTORY_RESET_AUDIO_DURATION_MS 1000
#ifdef CONFIG_TAG_BTN_OTA_MODE
#define OTA_MODE_TAP_COUNT 10
#endif
#ifdef CONFIG_FHN_TAG
#define FP_TAP_COUNT 1
#endif
#ifdef CONFIG_ATM_CS
#define CS_UNPAIR_TAP_COUNT 7
#endif
#ifdef CONFIG_TAG_BTN_LOG_FMNA_MFI_TOKEN
extern void fmna_log_mfi_token(void);
#define BUTTON_LOG_MFI_TOKEN_TAP_COUNT 8
#endif
#if APP_STF_MULTI_MODE
#define BUTTON_STF_SINGLE_TAP_COUNT      1
#define BUTTON_STF_DOUBLE_TAP_COUNT      2
#define BUTTON_STF_LONG_PRESS_TIMEOUT_MS 1900
#endif

#ifdef CONFIG_TAG_BTN_BATT_REPORT
static void battery_report_handler(void);
#endif

#ifdef CONFIG_TAG_BTN_OTA_MODE
static void ota_mode_enter_handler(void);
#endif

#if APP_STF_MULTI_MODE
static void stf_single_tap_action(void);
static void stf_double_tap_action(void);
#endif

struct button_action {
	void (*action)(void);
	uint8_t tap_count;
};

static const struct button_action button_actions[] = {
#ifdef CONFIG_FHN_TAG
	{atm_gfp_button_notify, FP_TAP_COUNT},
#endif
#ifdef CONFIG_TAG_BTN_BATT_REPORT
	{battery_report_handler, BATTERY_REPORT_TAP_COUNT},
#endif
#ifdef CONFIG_TAG_BTN_OTA_MODE
	{ota_mode_enter_handler, OTA_MODE_TAP_COUNT},
#endif
#ifdef CONFIG_ATM_CS
	{atm_cs_rrsp_unpair, CS_UNPAIR_TAP_COUNT},
#endif
#ifdef CONFIG_TAG_BTN_LOG_FMNA_MFI_TOKEN
	{fmna_log_mfi_token, BUTTON_LOG_MFI_TOKEN_TAP_COUNT},
#endif
#if APP_STF_MULTI_MODE
	{stf_single_tap_action, BUTTON_STF_SINGLE_TAP_COUNT},
	{stf_double_tap_action, BUTTON_STF_DOUBLE_TAP_COUNT},
#endif
};

static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(DT_ALIAS(sw0), gpios);
static struct gpio_callback button_cb_data;

static uint8_t cts_press = 0;
static struct k_work_delayable cts_tap_timeout_work;

static int64_t button_press_time;

#if APP_STF_MULTI_MODE
static void stf_single_tap_action(void)
{
	SystemButtonEventCallback(EVENT_BUTTON_PUSHED);
}

static void stf_double_tap_action(void)
{
	SystemButtonEventCallback(EVENT_BUTTON_DOUBLE_PUSHED);
}
#endif

#ifdef CONFIG_TAG_BTN_BATT_REPORT
static void battery_report_handler(void)
{
	uint8_t batt_percentage = platform_ctrl_batt_status_get();
	cts_press = 0;
	LOG_INF("Battery report: %d%%", batt_percentage);

#ifdef CONFIG_TAG_LED_IND
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

#ifdef CONFIG_TAG_BTN_OTA_MODE
static void ota_mode_enter_handler(void)
{
	LOG_INF("Entering OTA mode (%d taps detected)", OTA_MODE_TAP_COUNT);
	// Enter OTA mode (will reboot)
	platform_ctrl_ota_enter();
}
#endif

static void cts_tap_timeout_handler(struct k_work *work)
{
	LOG_INF("short pressed count %d", cts_press);

	for (int i = 0; i < ARRAY_SIZE(button_actions); i++) {
		if (cts_press == button_actions[i].tap_count) {
			button_actions[i].action();
		}
	}
	cts_press = 0;
}

#ifdef CONFIG_TAG_BTN_FACTORY_RESET
static void factory_reset_handler(void)
{
#ifdef CONFIG_TAG_AUDIO_FEEDBACK
	LOG_INF("Play audio feedback");
	platform_ctrl_buzzer_action(true);
	k_sleep(K_MSEC(FACTORY_RESET_AUDIO_DURATION_MS));
	platform_ctrl_buzzer_action(false);
#endif

#ifdef CONFIG_TAG_LED_IND
	platform_ctrl_led_event_indicate(LED_EVT_FACTORY_RESET);
#endif
	platform_factory_reset();
}
#endif

#ifdef CONFIG_TAG_BTN_POWER_CTRL
static void shutdown_timeout_cb(struct k_work *work)
{
	LOG_INF("shutdown timeout");
#if APP_STF_MULTI_MODE
	TagSoundPlayItem(SOUND_ITEM_OFF);
#endif
	platform_ctrl_led_state_update(LED_STATE_POWER_OFF);
	platform_ctrl_led_event_indicate(LED_EVT_POWER_OFF);

#ifdef CONFIG_TAG_BTN_FACTORY_RESET
	bool factory_reset = false;
#endif

	// Wait for button release
	while (gpio_pin_get_dt(&button)) {
		k_sleep(K_MSEC(BUTTON_SHUTDOWN_POLL_MS));
#ifdef CONFIG_TAG_BTN_FACTORY_RESET
		if (!factory_reset &&
		    (k_uptime_get() - button_press_time > BUTTON_FACTORY_RESET_MS)) {
			LOG_INF("factory reset timeout");
			factory_reset = true;
			factory_reset_handler();
		}
#endif
	}
	// stop wdt feed timer to prevent unnecessary wakeup
	platform_ctrl_wdt_feed_timer_stop();
	pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
}

static K_WORK_DELAYABLE_DEFINE(shutdown_timeout_work, shutdown_timeout_cb);
#endif

#if APP_STF_MULTI_MODE
static void stf_long_press_cb(struct k_work *work)
{
	SystemButtonEventCallback(EVENT_BUTTON_LONG_HOLD);
}
static K_WORK_DELAYABLE_DEFINE(stf_long_press_work, stf_long_press_cb);
#endif

static void button_cb(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
	if (gpio_pin_get_dt(&button)) {
		LOG_DBG("Button Pressed");
		button_press_time = k_uptime_get();
		// Cancel CTS timeout when button is pressed (new tap event)
		k_work_cancel_delayable(&cts_tap_timeout_work);
#ifdef CONFIG_TAG_BTN_POWER_CTRL
		k_work_reschedule(&shutdown_timeout_work, K_MSEC(BUTTON_SHUTDOWN_TIMEOUT_MS));
#endif
#if APP_STF_MULTI_MODE
		k_work_reschedule(&stf_long_press_work, K_MSEC(BUTTON_STF_LONG_PRESS_TIMEOUT_MS));
#endif
	} else {
		LOG_DBG("Button Released");
		if (!button_press_time) {
			return;
		}

		int64_t press_duration = k_uptime_get() - button_press_time;
		button_press_time = 0;

		if (press_duration < BUTTON_SHORT_PRESS_MS) {
			// Short press - handle button work
			cts_press++;
			k_work_reschedule(&cts_tap_timeout_work, K_MSEC(BUTTON_CTS_TAP_TIMEOUT_MS));
		} else {
			// Long press - cancel CTS timeout
			cts_press = 0;
			k_work_cancel_delayable(&cts_tap_timeout_work);
		}
#ifdef CONFIG_TAG_BTN_POWER_CTRL
		// Cancel shutdown timeout when button is released
		k_work_cancel_delayable(&shutdown_timeout_work);
#endif
#if APP_STF_MULTI_MODE
		// Cancel STF long press timeout when button is released
		k_work_cancel_delayable(&stf_long_press_work);
#endif
	}
}

bool platform_ctrl_button_init(void)
{
#ifdef CONFIG_PM
	atm_socoff_wakeup_gpio_set(true);
#endif
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

	uint32_t reset_cause;
	hwinfo_get_reset_cause(&reset_cause);
	LOG_INF("reset_cause: %#x", reset_cause);

#ifdef CONFIG_TAG_BTN_POWER_CTRL
	if (reset_cause & (RESET_SOFTWARE | RESET_WATCHDOG) || (reset_cause == RESET_HARDWARE)) {
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
#else
	if ((reset_cause & RESET_LOW_POWER_WAKE) && !(reset_cause & RESET_PIN)) {
		LOG_INF("wakeup from socoff/hibernation without button press");
		LOG_INF("just go to sleep");
		return false;
	}
#endif
	LOG_INF("power on");

	// Initialize work items
	k_work_init_delayable(&cts_tap_timeout_work, cts_tap_timeout_handler);
	gpio_init_callback(&button_cb_data, button_cb, BIT(button.pin));
	gpio_add_callback(button.port, &button_cb_data);
	LOG_INF("Set up button at %s pin %u", button.port->name, button.pin);
	return true;
}
