/**
 *******************************************************************************
 *
 * @file platform.c
 *
 * @brief Platform For Multimode Consumer Tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#include "app_work_q.h"
#ifdef CONFIG_ATM_CS
#include "atm_cs.h"
#endif
#include "compiler.h"
#ifdef CONFIG_FMNA_TAG
#include "fmna_tag_platform.h"
#endif
#ifdef CONFIG_FHN_TAG
#include "fp_tag_platform.h"
#endif
#ifdef CONFIG_STF_TAG
#include "stf_tag_platform.h"
#endif
#if APP_STF_MULTI_MODE
#include "TagSoundPlayer.h"
#endif
#include "platform_ctrl_led.h"
#include "platform_ctrl_wdt.h"
#include "reset.h"

LOG_MODULE_DECLARE(multimode_consumer_tag, CONFIG_MULTIMODE_CONSUMER_TAG_LOG_LEVEL);

static char const *const tag_type_str[] = {
	"FMNA_TAG",
	"FP_TAG",
	"STF_TAG",
	"Unknown TAG",
};

static char const *const tag_state_str[] = {
	"STATE_INIT_DONE", "STATE_UNPAIRED", "STATE_PAIRING", "STATE_PAIRED", "STATE_INVALID",
};

static tag_hdlrs_t tag_hdlrs[TAG_TYPE_MAX];

#define BUTTON0 DT_ALIAS(sw0)
#if DT_NODE_EXISTS(BUTTON0)
#else
BUILD_ASSERT("DT_NODE_EXISTS BUTTON0");
#endif

static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET_OR(BUTTON0, gpios, {0});

static bool platform_is_any_type_paired(void)
{
	for (uint8_t i = 0; i < TAG_TYPE_MAX; i++) {
		if (tag_hdlrs[i].is_paired && tag_hdlrs[i].is_paired()) {
			LOG_INF("%s has been paired", tag_type_str[i]);
			return true;
		}
	}
	return false;
}

static void platform_stop_all_other_types(uint8_t type)
{
	for (uint8_t i = 0; i < TAG_TYPE_MAX; i++) {
		if (type == i) {
			continue;
		}
		if (tag_hdlrs[i].stop) {
			LOG_INF("Stop %s", tag_type_str[i]);
			tag_hdlrs[i].stop();
		}
	}
	return;
}

static void platform_start_all_other_types(uint8_t type)
{
	for (uint8_t i = 0; i < TAG_TYPE_MAX; i++) {
		if (type == i) {
			continue;
		}
		if (tag_hdlrs[i].start) {
			LOG_INF("Start %s", tag_type_str[i]);
			tag_hdlrs[i].start();
		}
	}
	return;
}

void platform_factory_reset(void)
{
	for (uint8_t i = 0; i < TAG_TYPE_MAX; i++) {
		if (tag_hdlrs[i].is_paired && tag_hdlrs[i].is_paired()) {
			if (tag_hdlrs[i].reset) {
				LOG_INF("Reset %s", tag_type_str[i]);
				tag_hdlrs[i].reset();
			}
		}
	}
#ifdef CONFIG_ATM_CS
	atm_cs_rrsp_unpair();
#endif
	/* Unpair all bonds */
	size_t count = 0;
	bt_id_get(NULL, &count);
	for (size_t i = 0; i < count; i++) {
		bt_unpair(i, NULL);
	}
}

void platform_gpio_init(void)
{
	int err = gpio_pin_configure_dt(&button, GPIO_INPUT);
	if (err) {
		LOG_ERR("Error %d: failed to configure %s pin %u", err, button.port->name,
			button.pin);
		return;
	}
}

void platform_reset_detect(void)
{
	if (!is_boot_type(TYPE_POWER_ON)) {
		return;
	}

	if (!gpio_pin_get_dt(&button)) {
		return;
	}

	LOG_INF("**Button pressed during reboot, perform factory reset**");
	platform_factory_reset();
}

#if (CONFIG_TAG_SOC_OFF_TIMEOUT > 0)
static void pairing_shutdown_timeout_cb(struct k_work *work)
{
	LOG_INF("pairing shutdown timeout");
#if APP_STF_MULTI_MODE
	TagSoundPlayItem(SOUND_ITEM_OFF);
#endif
	platform_ctrl_led_state_update(LED_STATE_POWER_OFF);
	platform_ctrl_led_event_indicate(LED_EVT_POWER_OFF);

#ifdef CONFIG_PM
	// stop wdt feed timer to prevent unnecessary wakeup
	platform_ctrl_wdt_feed_timer_stop();
	pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
#endif
}

static K_WORK_DELAYABLE_DEFINE(pairing_shutdown_timeout_work, pairing_shutdown_timeout_cb);
#endif

static void platform_mode_notify(tag_state_t st, uint8_t type)
{
	LOG_INF("%s state [%s]", tag_type_str[type], tag_state_str[st]);
	switch (st) {
	case TAG_STATE_INIT_DONE:
		if (!platform_is_any_type_paired()) {
			if (tag_hdlrs[type].start) {
				tag_hdlrs[type].start();
			}
			platform_ctrl_led_state_update(LED_STATE_PAIRING);
#if (CONFIG_TAG_SOC_OFF_TIMEOUT > 0)
			k_work_reschedule(&pairing_shutdown_timeout_work,
					  K_SECONDS(CONFIG_TAG_SOC_OFF_TIMEOUT));
#endif
		} else {
			platform_ctrl_led_state_update(LED_STATE_PAIRED);
#if (CONFIG_TAG_SOC_OFF_TIMEOUT > 0)
			k_work_cancel_delayable(&pairing_shutdown_timeout_work);
#endif
		}
		break;
	case TAG_STATE_UNPAIRED:
		if (!platform_is_any_type_paired()) {
			platform_start_all_other_types(type);
			platform_ctrl_led_state_update(LED_STATE_PAIRING);
#if (CONFIG_TAG_SOC_OFF_TIMEOUT > 0)
			k_work_reschedule(&pairing_shutdown_timeout_work,
					  K_SECONDS(CONFIG_TAG_SOC_OFF_TIMEOUT));
#endif
		}
		break;
	case TAG_STATE_PAIRING:
		platform_stop_all_other_types(type);
#if (CONFIG_TAG_SOC_OFF_TIMEOUT > 0)
		k_work_cancel_delayable(&pairing_shutdown_timeout_work);
#endif
		break;
	case TAG_STATE_PAIRED:
		platform_ctrl_led_state_update(LED_STATE_PAIRED);
#if (CONFIG_TAG_SOC_OFF_TIMEOUT > 0)
		k_work_cancel_delayable(&pairing_shutdown_timeout_work);
#endif
		break;
	case TAG_STATE_INVALID:
		LOG_WRN("Invalid Status");
		break;
	}
}

void platform_init(void)
{
	memset(&tag_hdlrs, 0, sizeof(tag_hdlrs_t) * TAG_TYPE_MAX);
#ifdef CONFIG_FMNA_TAG
	fmna_tag_platform_hdlrs_get(&tag_hdlrs[TAG_TYPE_FMNA]);
#endif
#ifdef CONFIG_FHN_TAG
	fp_tag_platform_hdlrs_get(&tag_hdlrs[TAG_TYPE_FP]);
#endif
#ifdef CONFIG_STF_TAG
	stf_tag_platform_hdlrs_get(&tag_hdlrs[TAG_TYPE_STF]);
#endif

#ifndef CONFIG_TAG_BTN_FACTORY_RESET
	platform_reset_detect();
#endif

	for (uint8_t i = 0; i < TAG_TYPE_MAX; i++) {
		if (tag_hdlrs[i].init) {
			tag_hdlrs[i].init(platform_mode_notify);
		}
	}
#ifdef CONFIG_ATM_CS
	atm_cs_rrsp_init();
	atm_cs_rrsp_start_adv();
#endif
}
