/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <errno.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#ifdef CONFIG_AT_CMD_TAG_SET
#include <zephyr/settings/settings.h>
#endif
#ifdef CONFIG_MCUMGR_GRP_IMG_STATUS_HOOKS
#include <zephyr/mgmt/mcumgr/mgmt/callbacks.h>
#endif
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
#include "platform.h"
#include "platform_ctrl_led.h"
#include "platform_ctrl_wdt.h"
#include "reset.h"
#ifdef CONFIG_AT_CMD_TAG_SET
#include "at_cmd_uart.h"
#include "at_cmd_event.h"
#include "at_cmd_tag.h"
#endif

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
static tag_event_t tag_states[TAG_TYPE_MAX];
static bool tag_initialized[TAG_TYPE_MAX];
static uint8_t selected_mode_mask;

#ifdef CONFIG_AT_CMD_TAG_SET
#define TAG_MODE_SETTINGS_ROOT "platform_tag"
#define TAG_MODE_SETTINGS_NAME "mode"
#define TAG_MODE_SETTINGS_KEY  TAG_MODE_SETTINGS_ROOT "/" TAG_MODE_SETTINGS_NAME

static uint8_t persisted_mode_mask;
static bool persisted_mode_mask_valid;
static bool tag_mode_locked;
static bool tag_process_active;
#endif

#define BUTTON0 DT_ALIAS(sw0)
#if DT_NODE_EXISTS(BUTTON0)
#else
BUILD_ASSERT("DT_NODE_EXISTS BUTTON0");
#endif

static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET_OR(BUTTON0, gpios, {0});

uint8_t platform_tag_supported_mode_mask_get(void)
{
	uint8_t mask = 0;

#ifdef CONFIG_FMNA_TAG
	mask |= platform_tag_type_to_mode(TAG_TYPE_FMNA);
#endif
#ifdef CONFIG_FHN_TAG
	mask |= platform_tag_type_to_mode(TAG_TYPE_FP);
#endif
#ifdef CONFIG_STF_TAG
	mask |= platform_tag_type_to_mode(TAG_TYPE_STF);
#endif

	return mask;
}

static bool platform_tag_mode_enabled(uint8_t type)
{
	return (selected_mode_mask & platform_tag_type_to_mode(type)) != 0U;
}

#ifdef CONFIG_AT_CMD_TAG_SET

static int platform_tag_settings_set(char const *name, size_t len, settings_read_cb read_cb,
				     void *cb_arg)
{
	char const *next;

	if (!settings_name_steq(name, TAG_MODE_SETTINGS_NAME, &next) || next) {
		return -ENOENT;
	}

	if (len != sizeof(persisted_mode_mask)) {
		LOG_ERR("Invalid tag mode settings size: %zu", len);
		at_cmd_evt_tag_error(at_cmd_set_uart_ch_get(),
				     platform_tag_supported_mode_mask_get(),
				     AT_CMD_TAG_ERR_INVALID_PARAM);
		return -EINVAL;
	}

	int rc = read_cb(cb_arg, &persisted_mode_mask, sizeof(persisted_mode_mask));
	if (rc < 0) {
		LOG_ERR("Failed to read tag mode settings: %d", rc);
		at_cmd_evt_tag_error(at_cmd_set_uart_ch_get(),
				     platform_tag_supported_mode_mask_get(),
				     AT_CMD_TAG_ERR_INTERNAL);
		return rc;
	}

	persisted_mode_mask_valid = true;
	LOG_INF("Loaded tag mode mask 0x%02X", persisted_mode_mask);
	return 0;
}

SETTINGS_STATIC_HANDLER_DEFINE(platform_tag_mode, TAG_MODE_SETTINGS_ROOT, NULL,
			       platform_tag_settings_set, NULL, NULL);

static uint8_t platform_tag_initial_mode_mask_get(void)
{
	uint8_t supported_mask = platform_tag_supported_mode_mask_get();

	if (!persisted_mode_mask_valid) {
		return supported_mask;
	}

	uint8_t mode = persisted_mode_mask & supported_mask;
	if (!mode) {
		LOG_WRN("Stored tag mode mask 0x%02X invalid for current build, fallback 0x%02X",
			persisted_mode_mask, supported_mask);
		return supported_mask;
	}

	return mode;
}

static int platform_tag_mode_save(uint8_t mode)
{
	int err = settings_save_one(TAG_MODE_SETTINGS_KEY, &mode, sizeof(mode));

	if (err) {
		LOG_ERR("Failed to save tag mode mask 0x%02X: %d", mode, err);
		at_cmd_evt_tag_error(at_cmd_set_uart_ch_get(),
				     platform_tag_supported_mode_mask_get(),
				     AT_CMD_TAG_ERR_INTERNAL);
		return err;
	}

	persisted_mode_mask = mode;
	persisted_mode_mask_valid = true;
	return 0;
}

static void platform_tag_mode_clear(void)
{
	int err = settings_delete(TAG_MODE_SETTINGS_KEY);

	if (err && (err != -ENOENT)) {
		LOG_ERR("Failed to clear tag mode settings: %d", err);
		at_cmd_evt_tag_error(at_cmd_set_uart_ch_get(),
				     platform_tag_supported_mode_mask_get(),
				     AT_CMD_TAG_ERR_INTERNAL);
		return;
	}

	persisted_mode_mask = 0U;
	persisted_mode_mask_valid = false;
	selected_mode_mask = platform_tag_supported_mode_mask_get();
	LOG_INF("Cleared persisted tag mode, fallback to default 0x%02X", selected_mode_mask);
}

#endif /* CONFIG_AT_CMD_TAG_SET */

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
		if (!platform_tag_mode_enabled(i) || !tag_initialized[i]) {
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
		if (!platform_tag_mode_enabled(i) || !tag_initialized[i]) {
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
#ifdef CONFIG_AT_CMD_TAG_SET
	platform_tag_mode_clear();
#endif

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
	platform_indicate_state(TAG_IND_STATE_POWER_OFF, platform_tag_supported_mode_mask_get());

#ifdef CONFIG_PM
	// stop wdt feed timer to prevent unnecessary wakeup
	platform_ctrl_wdt_feed_timer_stop();
	pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
#endif
}

static K_WORK_DELAYABLE_DEFINE(pairing_shutdown_timeout_work, pairing_shutdown_timeout_cb);

#ifdef CONFIG_MCUMGR_GRP_IMG_STATUS_HOOKS
static enum mgmt_cb_return mcumgr_dfu_callback(uint32_t event, enum mgmt_cb_return prev_status,
					       int32_t *rc, uint16_t *group, bool *abort_more,
					       void *data, size_t data_size)
{
	/* Cancel shutdown timeout when DFU is in progress */
	k_work_cancel_delayable(&pairing_shutdown_timeout_work);
	LOG_INF("DFU started, shutdown timeout cancelled");
	return MGMT_CB_OK;
}

static struct mgmt_callback mcumgr_dfu_mgmt_callback = {
	.callback = mcumgr_dfu_callback,
	.event_id = MGMT_EVT_OP_IMG_MGMT_DFU_STARTED,
};
#endif /* CONFIG_MCUMGR_GRP_IMG_STATUS_HOOKS */
#endif /* CONFIG_TAG_SOC_OFF_TIMEOUT > 0 */

static void platform_mode_notify(tag_event_t st, uint8_t type)
{
	if (type < TAG_TYPE_MAX) {
		tag_states[type] = st;
	}

	LOG_INF("%s state [%s]", tag_type_str[type], tag_state_str[st]);

	switch (st) {
	case TAG_EVENT_INIT_DONE:
		platform_indicate_state(TAG_IND_STATE_INIT_DONE, type);
		if (!platform_is_any_type_paired()) {
			if (tag_hdlrs[type].start) {
				tag_hdlrs[type].start();
			}
			platform_indicate_state(TAG_IND_STATE_PAIRING, type);
#if (CONFIG_TAG_SOC_OFF_TIMEOUT > 0)
			k_work_reschedule(&pairing_shutdown_timeout_work,
					  K_SECONDS(CONFIG_TAG_SOC_OFF_TIMEOUT));
#endif
		} else {
			platform_indicate_state(TAG_IND_STATE_PAIRED, type);
#if (CONFIG_TAG_SOC_OFF_TIMEOUT > 0)
			k_work_cancel_delayable(&pairing_shutdown_timeout_work);
#endif
		}
		break;
	case TAG_EVENT_UNPAIRED:
		platform_indicate_state(TAG_IND_STATE_UNPAIRED, type);
		if (!platform_is_any_type_paired()) {
			platform_start_all_other_types(type);
			platform_indicate_state(TAG_IND_STATE_PAIRING, type);
#if (CONFIG_TAG_SOC_OFF_TIMEOUT > 0)
			k_work_reschedule(&pairing_shutdown_timeout_work,
					  K_SECONDS(CONFIG_TAG_SOC_OFF_TIMEOUT));
#endif
		}
		break;
	case TAG_EVENT_PAIRING:
		platform_stop_all_other_types(type);
#if (CONFIG_TAG_SOC_OFF_TIMEOUT > 0)
		k_work_cancel_delayable(&pairing_shutdown_timeout_work);
#endif
		break;
	case TAG_EVENT_PAIRED:
		platform_indicate_state(TAG_IND_STATE_PAIRED, type);
#if (CONFIG_TAG_SOC_OFF_TIMEOUT > 0)
		k_work_cancel_delayable(&pairing_shutdown_timeout_work);
#endif
		break;
	case TAG_EVENT_INVALID:
		break;
	}
}

#ifdef CONFIG_AT_CMD_TAG_SET

int platform_tag_mode_get(uint8_t *mode)
{
	if (!mode) {
		return -EINVAL;
	}

	*mode = selected_mode_mask;
	return 0;
}

int platform_tag_mode_set(uint8_t mode)
{
	uint8_t supported_mask = platform_tag_supported_mode_mask_get();
	int err;

	if (!mode || ((mode & supported_mask) != mode)) {
		return -ENOTSUP;
	}

	if (tag_mode_locked) {
		return -EPERM;
	}

	if (platform_is_any_type_paired()) {
		LOG_WRN("Tag mode change rejected: device is bonded");
		return -EPERM;
	}

	err = platform_tag_mode_save(mode);
	if (err) {
		return err;
	}

	selected_mode_mask = mode;
	LOG_INF("Selected tag mode mask 0x%02X", selected_mode_mask);
	return 0;
}

int platform_tag_start(void)
{
	if (!selected_mode_mask) {
		return -ENOTSUP;
	}

	if (tag_process_active) {
		return 0;
	}

	tag_mode_locked = true;
	for (uint8_t i = 0; i < TAG_TYPE_MAX; i++) {
		if (!platform_tag_mode_enabled(i)) {
			continue;
		}

		if (!tag_initialized[i]) {
			if (tag_hdlrs[i].init) {
				LOG_INF("Init %s", tag_type_str[i]);
				tag_hdlrs[i].init(platform_mode_notify);
				tag_initialized[i] = true;
			}
		}
	}

	tag_process_active = true;
	return 0;
}

int platform_tag_state_get(uint8_t *state)
{
	if (!state) {
		return -EINVAL;
	}

	*state = tag_process_active ? 0x01U : 0x00U;
	return 0;
}

#endif /* CONFIG_AT_CMD_TAG_SET */

void platform_init(void)
{
#if (CONFIG_TAG_SOC_OFF_TIMEOUT > 0) && defined(CONFIG_MCUMGR_GRP_IMG_STATUS_HOOKS)
	/* Register MCUmgr callback to prevent SOC OFF during DFU */
	mgmt_callback_register(&mcumgr_dfu_mgmt_callback);
	LOG_INF("MCUmgr DFU callback registered");
#endif
	memset(&tag_hdlrs, 0, sizeof(tag_hdlrs_t) * TAG_TYPE_MAX);
	memset(&tag_states, TAG_EVENT_INVALID, sizeof(tag_states));
	memset(&tag_initialized, 0, sizeof(tag_initialized));
	selected_mode_mask = platform_tag_supported_mode_mask_get();
#ifdef CONFIG_AT_CMD_TAG_SET
	selected_mode_mask = platform_tag_initial_mode_mask_get();
	tag_mode_locked = false;
	tag_process_active = false;
#endif
#ifdef CONFIG_FMNA_TAG
	fmna_tag_platform_hdlrs_get(&tag_hdlrs[TAG_TYPE_FMNA]);
#endif
#ifdef CONFIG_FHN_TAG
	fp_tag_platform_hdlrs_get(&tag_hdlrs[TAG_TYPE_FP]);
#endif
#ifdef CONFIG_STF_TAG
	stf_tag_platform_hdlrs_get(&tag_hdlrs[TAG_TYPE_STF]);
#endif

#if defined(CONFIG_TAG_BUTTON) && !defined(CONFIG_TAG_BTN_FACTORY_RESET)
	platform_reset_detect();
#endif

#ifndef CONFIG_AT_CMD_TAG_SET
	for (uint8_t i = 0; i < TAG_TYPE_MAX; i++) {
		if (tag_hdlrs[i].init) {
			tag_initialized[i] = true;
			tag_hdlrs[i].init(platform_mode_notify);
		}
	}
#endif

#ifdef CONFIG_ATM_CS
	atm_cs_rrsp_init();
	atm_cs_rrsp_start_adv();
#endif
}
