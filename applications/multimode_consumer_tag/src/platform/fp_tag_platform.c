/**
 *******************************************************************************
 *
 * @file fp_tag_platform.c
 *
 * @brief Platform For fp tag
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/reboot.h>
#if defined(CONFIG_BOOTLOADER_MCUBOOT) && defined(CONFIG_MCUBOOT_IMG_MANAGER)
#include <zephyr/dfu/mcuboot.h>
#endif
#include "app_work_q.h"
#include "atm_gfp.h"
#include "fp_mode.h"
#include "fp_tag_platform.h"
#ifdef CONFIG_FMDN_PRECISION_FINDING
#include "fp_tag_platform_ranging.h"
#endif
#include "platform_ctrl_battery.h"
#include "platform_ctrl_buzzer.h"

LOG_MODULE_DECLARE(multimode_consumer_tag, CONFIG_MULTIMODE_CONSUMER_TAG_LOG_LEVEL);

static tag_state_notify_cb fp_tag_state_notify;
static tag_state_t gfp_st = TAG_STATE_INVALID;

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
#ifdef CONFIG_ATM_GFP_MUTLIMODE_TAG
		atm_gfp_start();
#else
		LOG_INF("Press button to start pairing");
#endif
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
		if (gfp_st == TAG_STATE_PAIRED) {
			LOG_INF("Unprovisioned");
		} else if (gfp_st == TAG_STATE_PAIRING) {
			LOG_INF("Pairing failed");
		}
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
	if (gfp_st == TAG_STATE_UNPAIRED) {
		LOG_WRN("Cleanup: extra reset may be required");
	}
	if (fp_tag_state_notify) {
		fp_tag_state_notify(gfp_st, TAG_TYPE_FP);
	}
	if (gfp_st == TAG_STATE_UNPAIRED) {
		fp_tag_platform_start();
	}
}

static void fp_tag_platform_buzzer_action(bool action, atm_gfp_ring_op_t ring_op,
					  atm_gfp_ring_vol_t ring_vol)
{
	LOG_DBG("action: %s", action ? "ON" : "OFF");
	if (action) {
		LOG_DBG("ring_op: %s (%u), ring_vol: %s (%u)", atm_gfp_ring_op_to_string(ring_op),
			ring_op, atm_gfp_ring_vol_to_string(ring_vol), ring_vol);
	}
	platform_ctrl_buzzer_action(action);
}

#if (defined(CONFIG_FAST_PAIR_FMDN_V2) && defined(CONFIG_FMDN_REVERSE_RINGING))
/**
 * @brief Reverse ringing event handler
 *
 * Per FHN v2 spec line 263: "The tag may use indication confirmation to provide
 * feedback to the user (a specific LED pattern or beep) on successful operation"
 *
 * This callback provides simple feedback events:
 * - STARTED: Request sent successfully → Show LED/beep
 * - STOPPED: Ringing stopped (any reason) → Turn off LED/beep
 *
 * @param event Reverse ringing event type
 */
static void fp_tag_platform_reverse_ringing_event(atm_gfp_reverse_ringing_event_t event)
{
	switch (event) {
	case ATM_GFP_RR_EVENT_STARTED:
		LOG_INF("RR: Request sent successfully");
		/* TODO: Show LED pattern or beep to indicate request was sent
		 * Per spec: "feedback on successful operation"
		 * Example: Turn on LED, play short beep
		 */
		break;

	case ATM_GFP_RR_EVENT_STOPPED:
		LOG_INF("RR: Ringing stopped");
		/* TODO: Turn off LED or stop beep
		 * Example: Turn off LED
		 */
		break;

	default:
		LOG_WRN("RR: Unknown event %d", event);
		break;
	}
}
#endif

static bool fp_tag_platform_is_abnormal(void)
{
	return false;
}
/**
 * @brief Firmware version callback for DIS service
 *
 * Application provides firmware version string dynamically.
 * This allows the version to be retrieved from various sources
 * (NVM, runtime data, build info, etc.).
 */
static const char *fp_tag_get_fw_version(void)
{
#if defined(CONFIG_BOOTLOADER_MCUBOOT) && defined(CONFIG_MCUBOOT_IMG_MANAGER)
	// check if firmware update is in progress
	if (!boot_is_img_confirmed()) {
		return "status-updating";
	}
#endif
	// check if device is in abnormal state
	if (fp_tag_platform_is_abnormal()) {
		return "status-abnormal";
	}
	/* Firmware version is configured via Kconfig */
	return CONFIG_FHN_FW_VERSION;
}

static void fp_tag_platform_init(tag_state_notify_cb fn_cb)
{
	fp_tag_state_notify = fn_cb;
#ifdef CONFIG_FMDN_PRECISION_FINDING
	/// Platform ranging handler structure
	static const atm_gfp_ranging_handler_t ranging_handler = {
		.capability_cb = fp_platform_ranging_capability_cb,
		.config_cb = fp_platform_ranging_config_cb,
		.start_cb = fp_platform_ranging_start_cb,
		.stop_cb = fp_platform_ranging_stop_cb,
	};
#endif
	static atm_gfp_hdlrs_t const hdlrs = {
		.battery_status_cb = platform_ctrl_batt_status_get,
		.sound_action_cb = fp_tag_platform_buzzer_action,
		.mode_state_cb = fp_tag_mode_state,
		/* Application provides firmware version callback*/
		.fw_version_cb = fp_tag_get_fw_version,
#ifdef CONFIG_FMDN_PRECISION_FINDING
		.ranging_handlers = &ranging_handler,
#endif
#if (defined(CONFIG_FAST_PAIR_FMDN_V2) && defined(CONFIG_FMDN_REVERSE_RINGING))
		.reverse_ringing_event_cb = fp_tag_platform_reverse_ringing_event,
#endif
	};
	atm_gfp_init(&hdlrs);
}

void fp_tag_platform_hdlrs_get(tag_hdlrs_t *hdlrs)
{
	hdlrs->init = fp_tag_platform_init;
	hdlrs->reset = fp_tag_platform_reset;
	hdlrs->start = fp_tag_platform_start;
	hdlrs->stop = fp_tag_platform_stop;
	hdlrs->is_paired = fp_tag_platform_is_paired;
}
