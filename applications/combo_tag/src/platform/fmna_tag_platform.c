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
#include "fmna_api.h"
#include "fmna_tag_platform.h"
#include "platform_ctrl_battery.h"
#include "platform_ctrl_buzzer.h"
#include "platform_ctrl_motion_detect.h"

LOG_MODULE_DECLARE(combo_tag, CONFIG_COMBO_TAG_LOG_LEVEL);

#ifdef CONFIG_FMNA_DEV_CUSTOM_BT_ADDR
#include <zephyr/bluetooth/bluetooth.h>
static bt_addr_le_t init_addr;
#endif
static tag_state_notify_cb fmna_tag_state_notify;

static void sound_start(void)
{
	platform_ctrl_buzzer_action(true);
	LOG_DBG("sound_start");
}

static void sound_stop(void)
{
	platform_ctrl_buzzer_action(false);
	LOG_DBG("sound_stop");
}

static void motion_init(void)
{
	platform_ctrl_motion_detect_init();
	LOG_DBG("motion_init");
}

static void motion_deinit(void)
{
	platform_ctrl_motion_detect_action(false);
	LOG_DBG("motion_deinit");
}

static bool motion_detected(void)
{
	platform_ctrl_motion_detect_action(true);
	LOG_DBG("motion_detected");
	return platform_ctrl_motion_detect_get_status();
}

static fmna_bat_state_level_t battery_level_get(void)
{
	uint8_t batt_percentage = platform_ctrl_batt_status_get();
	if (batt_percentage > 90) {
		return BAT_STATE_FULL;
	} else if (batt_percentage > 50) {
		return BAT_STATE_MEDIUM;
	} else if (batt_percentage > 20) {
		return BAT_STATE_LOW;
	} else {
		return BAT_STATE_CRITICALLY_LOW;
	}
}

static void state_notify(fmna_state_notify_t st)
{
	LOG_INF("FMNA current state %u", st);
	tag_state_t tag_st = TAG_STATE_INVALID;
	switch (st) {
	case FMNA_STATE_INIT_DONE:
		tag_st = TAG_STATE_INIT_DONE;
		break;
	case FMNA_STATE_UNPAIRED:
		tag_st = TAG_STATE_UNPAIRED;
		break;
	case FMNA_STATE_PAIRING:
		tag_st = TAG_STATE_PAIRING;
		break;
	case FMNA_STATE_PAIRED:
		tag_st = TAG_STATE_PAIRED;
		break;
	}
	if (fmna_tag_state_notify) {
		fmna_tag_state_notify(tag_st, TAG_TYPE_FMNA);
	}
}

static uint8_t product_data[8];
static struct fmna_init_params const fmna_init_params = {
#ifdef CONFIG_FMNA_DEV_CUSTOM_BT_ADDR
	.init_addr = init_addr.a.val,
#endif
	.acc_capability = CONFIG_FMNA_ACCESSORY_CAPABILITY,
	.acc_category = CONFIG_FMNA_ACCESSORY_CATEGORY,
	.batt_type = CONFIG_FMNA_BATTERY_TYPE,
	.pid = CONFIG_FMNA_PID,
	.product_data = product_data,
	.manufacturer_name = CONFIG_FMNA_MANUFACTURER_NAME,
	.model_name = CONFIG_FMNA_MODEL_NAME,
	.hardware_version = CONFIG_FMNA_HARDWARE_VERSION,
	.version_major = CONFIG_FMNA_VERSION_MAJOR,
	.version_minor = CONFIG_FMNA_VERSION_MINOR,
	.version_revision = CONFIG_FMNA_VERSION_REVISION,
	.sound_cb = {.sound_init = platform_ctrl_buzzer_init,
		     .sound_start = sound_start,
		     .sound_stop = sound_stop},
	.motion_cb = {.motion_init = motion_init,
		      .motion_deinit = motion_deinit,
		      .motion_detected = motion_detected},
	.battery_cb = {.battery_level_get = battery_level_get},
	.state_cb = {
		.state_notify = state_notify,
	}};

static void fmna_tag_platform_init(tag_state_notify_cb fn_cb)
{
	fmna_tag_state_notify = fn_cb;
#ifdef CONFIG_FMNA_DEV_CUSTOM_BT_ADDR
	int err = bt_addr_le_from_str(CONFIG_FMNA_DEV_CUSTOM_BT_ADDR_VALUE, "random", &init_addr);
	if (err) {
		LOG_ERR("Invalid Bluetooth address format");
		return;
	}
#endif
	hex2bin(CONFIG_FMNA_PRODUCT_DATA, strlen(CONFIG_FMNA_PRODUCT_DATA), product_data,
		sizeof(product_data));

	fmna_main_init(&fmna_init_params);
}

static void fmna_tag_platform_reset(void)
{
	fmna_main_reset_pairing_state();
}

static void fmna_tag_platform_stop(void)
{
	fmna_main_stop_pairing_adv();
}

static void fmna_tag_platform_start(void)
{
	fmna_main_start_pairing_adv();
}

static bool fmna_tag_platform_is_paired(void)
{
	return fmna_connection_is_fmna_paired();
}

void fmna_tag_platform_hdlrs_get(tag_hdlrs_t *hdlrs)
{
	hdlrs->init = fmna_tag_platform_init;
	hdlrs->reset = fmna_tag_platform_reset;
	hdlrs->start = fmna_tag_platform_start;
	hdlrs->stop = fmna_tag_platform_stop;
	hdlrs->is_paired = fmna_tag_platform_is_paired;
}
