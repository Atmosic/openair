/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/bluetooth/bluetooth.h>
#ifdef CONFIG_BATT_FACTORY_RESET
#include <zephyr/settings/settings.h>
#endif
#ifdef CONFIG_BTN_ON_OFF
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#include "compiler.h"
#include "reset.h"
#endif
#include "rrsp_mmi.h"
#include "app_work_q.h"
#ifdef CONFIG_BTN_BATT_REPORT
#include "rrsp_batt.h"
#endif
#ifdef CONFIG_RRSP_LED_IND
#include "rrsp_led.h"
#endif

LOG_MODULE_REGISTER(rrsp_btn, CONFIG_RRSP_BTN_LOG_LEVEL);

#define SW0_NODE DT_ALIAS(sw0)
static const struct gpio_dt_spec rrsp_btn0 = GPIO_DT_SPEC_GET(SW0_NODE, gpios);
static struct gpio_callback rrsp_button_cb;
static struct k_work rrsp_button_work;

#if !defined(CONFIG_BTN_ON_OFF) || defined(CONFIG_BATT_FACTORY_RESET)
static void rrsp_button_factory_reset_handler(void)
{
	LOG_INF("unpair button");
	bt_unpair(BT_ID_DEFAULT, BT_ADDR_LE_ANY);
}
#endif

#ifdef CONFIG_BATT_FACTORY_RESET
static uint8_t batt_insert_times;

static int rrsp_buttons_batt_insert_save(void)
{
	int err =
		settings_save_one("rrsp_app/insert", &batt_insert_times, sizeof(batt_insert_times));
	if (err) {
		LOG_ERR("save batt insert times error %d", err);
	}

	return err;
}

static int rrsp_buttons_batt_insert_read(const char *name, size_t len, settings_read_cb read_cb,
					 void *cb_arg)
{
	if (name || len > sizeof(batt_insert_times)) {
		LOG_ERR("unexpected name:%s len:%u", name, len);
		batt_insert_times = 0;
		return 0;
	}

	int rc = read_cb(cb_arg, &batt_insert_times, sizeof(batt_insert_times));
	if (rc < 0) {
		LOG_ERR("failed to read batt_insert_times: %d", rc);
		batt_insert_times = 0;
		return rc;
	}

	LOG_INF("Read batt_insert_times:%u", batt_insert_times);

	return 0;
}

SETTINGS_STATIC_HANDLER_DEFINE(rrsp_app, "rrsp_app/insert", NULL, rrsp_buttons_batt_insert_read,
			       NULL, NULL);

static void rrsp_buttons_batt_insert_reset(void)
{
	batt_insert_times = 0;
	rrsp_buttons_batt_insert_save();
}

static void rrsp_button_bt_ready(int err)
{
	if (IS_ENABLED(CONFIG_SETTINGS)) {
		settings_load();
	}

	if (err) {
		LOG_ERR("BT initial fail: %d", err);
	}
	rrsp_button_factory_reset_handler();
}
#endif

#ifdef CONFIG_BTN_ON_OFF
#define BTN_LONG_PRESS_MS 2000
static struct k_work_delayable rrsp_button_longpress_work;
static int64_t hit_time;
static uint32_t hit_mask;
static bool btn_lock;
#ifdef CONFIG_BTN_BATT_REPORT
#define BTN_CTS_TAP_MS     3000
#define BTN_BATT_TAP_TIMES 5
static struct k_work_delayable rrsp_button_cts_tap_timeout_work;
static uint8_t cts_press;

static void rrsp_button_cts_tap_timeout_handler(struct k_work *work)
{
	LOG_INF("CTS Tap timeout Triggered:%d", cts_press);
	cts_press = 0;
}

static void rrsp_button_batt_rpt_handler(void)
{
	int32_t batt_mv = rrsp_batt_status_get();
	cts_press = 0;
	LOG_INF("Key:Battery report:%d", batt_mv);

#ifdef CONFIG_RRSP_LED_IND

#define BATT_VOL_MV_THRESH1 3000
#define BATT_VOL_MV_THRESH2 2900
#define BATT_VOL_MV_THRESH3 2800
#define BATT_VOL_MV_THRESH4 2600

	int32_t batt_thresh[] = {BATT_VOL_MV_THRESH1, BATT_VOL_MV_THRESH2, BATT_VOL_MV_THRESH3,
				 BATT_VOL_MV_THRESH4};

	for (uint8_t i = 0; i < ARRAY_SIZE(batt_thresh); i++) {
		if (batt_mv > batt_thresh[i]) {
			rrsp_led_update((RRSP_LED_PAT_EVT_BAT_LVL + i), true);
			return;
		}
	}
	rrsp_led_update(RRSP_LED_PAT_EVT_BAT1, true);
#endif // CONFIG_RRSP_LED_IND
}
#endif // CONFIG_BTN_BATT_REPORT

static void rrsp_button_poweron_handler(void)
{
	LOG_INF("Key:Power on");
#ifdef CONFIG_RRSP_LED_IND
	rrsp_led_update(RRSP_LED_PAT_EVT_PWRON, true);
#endif
#ifdef CONFIG_BATT_FACTORY_RESET
	rrsp_buttons_batt_insert_reset();
#endif
	rrsp_mmi_init();
}

static void rrsp_button_poweroff_handler(void)
{
	LOG_INF("Key:Power off - wait release");
#ifdef CONFIG_RRSP_LED_IND
	rrsp_led_update(RRSP_LED_PAT_EVT_PWROFF, true);
#endif
	rrsp_mmi_off();
}

static void rrsp_button_longpress_handler(struct k_work *work)
{
	if (rrsp_mmi_get_state() == RRSP_MMI_STATE_IDX_MAX) {
		rrsp_button_poweron_handler();
	} else {
		rrsp_button_poweroff_handler();
	}
}

static void rrsp_button_lock_sleep(bool lock)
{
	LOG_DBG("button lock:%d", lock);

	if (btn_lock == lock) {
		return;
	}
	if (lock) {
		pm_policy_state_lock_get(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	} else {
		pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	}
	btn_lock = lock;
}
#endif

static void rrsp_button_work_handler(struct k_work *work)
{
#ifdef CONFIG_BTN_ON_OFF
	// Release detect
	if (!hit_mask) {
		if (hit_time < BTN_LONG_PRESS_MS) {
			LOG_DBG("Short Tap");
			if (rrsp_mmi_get_state() == RRSP_MMI_STATE_IDX_MAX) {
				LOG_DBG("OFF: Button press less than 2s");
				rrsp_mmi_unlock_sleep();
				return;
			}
			if (rrsp_mmi_get_state() == RRSP_MMI_STATE_OFF) {
				LOG_WRN("Invalid Tap Key in off state");
				return;
			}
#ifdef CONFIG_BTN_BATT_REPORT
			if (!cts_press) {
				// First tap
				atm_work_reschedule_for_app_work_q(
					&rrsp_button_cts_tap_timeout_work, K_MSEC(BTN_CTS_TAP_MS));
			}
			cts_press += 1;
			if (cts_press == BTN_BATT_TAP_TIMES) {
				k_work_cancel_delayable(&rrsp_button_cts_tap_timeout_work);
				rrsp_button_batt_rpt_handler();
			}
#endif // CONFIG_BTN_BATT_REPORT
		} else {
			LOG_DBG("Long Press Release");
			if (rrsp_mmi_get_state() == RRSP_MMI_STATE_OFF) {
				LOG_DBG("OFF: key released");
			}
#ifdef CONFIG_BTN_BATT_REPORT
			k_work_cancel_delayable(&rrsp_button_cts_tap_timeout_work);
			cts_press = 0;
#endif // CONFIG_BTN_BATT_REPORT
		}
	}
#else
	rrsp_button_factory_reset_handler();
#endif
}

static void rrsp_buttons_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
#ifdef CONFIG_BTN_ON_OFF
	if (gpio_pin_get_dt(&rrsp_btn0)) {
		hit_time = k_uptime_get();
		hit_mask |= pins;
		k_work_reschedule(&rrsp_button_longpress_work, K_MSEC(BTN_LONG_PRESS_MS));
		LOG_DBG("Button Pressed");
		rrsp_button_lock_sleep(true);
	} else {
		k_work_cancel_delayable(&rrsp_button_longpress_work);
		hit_time = k_uptime_delta(&hit_time);
		hit_mask &= (~pins);
		LOG_DBG("Button Released");
		rrsp_button_lock_sleep(false);
	}
#endif
	atm_work_submit_to_app_work_q(&rrsp_button_work);
}

static bool rrsp_buttons_configure_irq(const struct gpio_dt_spec btn)
{
	if (!gpio_is_ready_dt(&btn)) {
		LOG_ERR("button device is not ready");
		return false;
	}
	int err = gpio_pin_configure_dt(&btn, GPIO_INPUT);
	if (err) {
		LOG_ERR("Failed to configure %s pin %u err:%d", btn.port->name, btn.pin, err);
		return false;
	}
	err = gpio_pin_interrupt_configure_dt(&btn, GPIO_INT_EDGE_BOTH);
	if (err) {
		LOG_ERR("Failed to configure interrupt on %s pin %u err:%d", btn.port->name,
			btn.pin, err);
		return false;
	}
#ifdef CONFIG_BTN_ON_OFF
	if (!is_boot_uninit()) {
		LOG_INF("skip power on (boot type)");
		return false;
	}

	if (!gpio_pin_get_dt(&btn)) {
		LOG_INF("Button is not pressed");
#ifdef CONFIG_BATT_FACTORY_RESET
#define RRSP_BTN_BATT_INSERT_TIMES 5
		if (is_boot_type(TYPE_POWER_ON)) {
			err = settings_load_subtree("rrsp_app");
			if (err) {
				LOG_ERR("rrsp_app load_subtree failed %d", err);
			}
			batt_insert_times += 1;
			if (batt_insert_times >= RRSP_BTN_BATT_INSERT_TIMES) {
				bt_enable(rrsp_button_bt_ready);
				batt_insert_times = 0;
			}
			rrsp_buttons_batt_insert_save();
		}
#endif
		return false;
	}

	hit_time = k_uptime_get();
	hit_mask = BIT(btn.pin);
	rrsp_button_lock_sleep(true);
	k_work_init_delayable(&rrsp_button_longpress_work, rrsp_button_longpress_handler);
	k_work_reschedule(&rrsp_button_longpress_work, K_MSEC(BTN_LONG_PRESS_MS));
#endif
	gpio_init_callback(&rrsp_button_cb, rrsp_buttons_pressed, BIT(btn.pin));
	gpio_add_callback(btn.port, &rrsp_button_cb);
	LOG_INF("Set up button at %s pin %u", btn.port->name, btn.pin);
#ifdef CONFIG_BTN_BATT_REPORT
	k_work_init_delayable(&rrsp_button_cts_tap_timeout_work,
			      rrsp_button_cts_tap_timeout_handler);
#endif
	return true;
}

bool rrsp_buttons_init(void)
{
	bool sts = true;
	if (!rrsp_buttons_configure_irq(rrsp_btn0)) {
		sts = false;
	} else {
		k_work_init(&rrsp_button_work, rrsp_button_work_handler);
	}
#ifndef CONFIG_BTN_ON_OFF
	rrsp_mmi_init();
#endif
	return sts;
}
