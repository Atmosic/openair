/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
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
#include "platform_indicate.h"
#if defined(CONFIG_FMDN_PRECISION_FINDING) || defined(CONFIG_DULT_MOTION_DETECT)
#include "platform_ctrl_motion_detect.h"
#ifdef CONFIG_AT_CMD_TAG_SET
#include "at_cmd_uart.h"
#include "at_cmd_event.h"
#endif
#endif

LOG_MODULE_DECLARE(multimode_consumer_tag, CONFIG_MULTIMODE_CONSUMER_TAG_LOG_LEVEL);

static tag_state_notify_cb fp_tag_state_notify;
static tag_event_t gfp_st = TAG_EVENT_INVALID;

static void fp_tag_platform_reset(void)
{
	LOG_INF("Button Perform Reset");
	atm_gfp_reset();
}

static void fp_tag_platform_stop(void)
{
	if (gfp_st < TAG_EVENT_PAIRED) {
		atm_gfp_stop();
	}
}

static void fp_tag_platform_start(void)
{
	if (gfp_st < TAG_EVENT_PAIRED) {
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
	tag_event_t tag_st;
	if ((gfp_st == TAG_EVENT_INVALID) && (mode == FP_MODE_NONE)) {
		tag_st = TAG_EVENT_INIT_DONE;
	} else if ((gfp_st > TAG_EVENT_UNPAIRED) && (mode == FP_MODE_NONE)) {
		tag_st = TAG_EVENT_UNPAIRED;
		if (gfp_st == TAG_EVENT_PAIRED) {
			LOG_INF("Unprovisioned");
		} else if (gfp_st == TAG_EVENT_PAIRING) {
			LOG_INF("Pairing failed");
		}
	} else if (mode == FP_MODE_PAIRING_PROCESSING) {
		tag_st = TAG_EVENT_PAIRING;
	} else if (mode == FP_MODE_PROVISIONED) {
		tag_st = TAG_EVENT_PAIRED;
	} else {
		LOG_DBG("ignore fp mode %u", mode);
		return;
	}
	if (gfp_st == tag_st) {
		return;
	}
	LOG_DBG("gfp_st %u, tag_st %u, fp_mode %u", gfp_st, tag_st, mode);
	gfp_st = tag_st;
	if (gfp_st == TAG_EVENT_UNPAIRED) {
		LOG_WRN("Cleanup: extra reset may be required");
	}
	if (fp_tag_state_notify) {
		fp_tag_state_notify(gfp_st, TAG_TYPE_FP);
	}
	if (gfp_st == TAG_EVENT_UNPAIRED) {
		fp_tag_platform_start();
	}
}

static uint16_t fp_tag_platform_buzzer_action(bool action, atm_gfp_ring_op_t ring_op,
					      atm_gfp_ring_vol_t ring_vol_lvl, uint16_t ring_to_ds)
{
	LOG_DBG("action: %s", action ? "ON" : "OFF");
	if (action) {
		LOG_DBG("ring_op: %s (%u), ring_vol_lvl: %s (%u), ring_to_ds: %u deciseconds",
			atm_gfp_ring_op_to_string(ring_op), ring_op,
			atm_gfp_ring_vol_to_string(ring_vol_lvl), ring_vol_lvl, ring_to_ds);
	}

#if defined(CONFIG_TAG_BUZZER) || defined(CONFIG_AT_EVT_TAGBUZZER)
	if (action) {
		tag_gfp_ring_params_t params = {
			.ring_op = (uint8_t)ring_op,
			.ring_vol = (uint8_t)ring_vol_lvl,
			.duration_ds = ring_to_ds,
		};
		platform_indicate_buzzer(TAG_BUZZER_EVT_GFP_RING_ON, &params);
	} else {
		platform_indicate_buzzer(TAG_BUZZER_EVT_GFP_RING_OFF, NULL);
	}
#endif
	return ring_to_ds;
}

#if (defined(CONFIG_FAST_PAIR_FMDN_V2) && defined(CONFIG_FMDN_REVERSE_RINGING))
/**
 * @brief Reverse ringing event handler
 *
 * @param event Reverse ringing event type
 */
static void fp_tag_platform_reverse_ringing_event(atm_gfp_reverse_ringing_event_t event)
{
	switch (event) {
	case ATM_GFP_RR_EVENT_ADV_STARTED:
		LOG_INF("RR: Advertisement started, waiting for phone to connect");
		/* TODO: Show searching feedback (e.g. slow LED blink) */
		break;
	case ATM_GFP_RR_EVENT_ADV_START_FAILED:
		LOG_INF("RR: Advertisement failed to start");
		/* TODO: Show start failed feedback (e.g. beep a error tone) */
		break;
	case ATM_GFP_RR_EVENT_ADV_TIMEOUT:
		LOG_INF("RR: ADV window timed out, phone never connected");
		/* TODO: Turn off searching feedback */
		break;
	case ATM_GFP_RR_EVENT_CONNECTED:
		LOG_INF("RR: Connected via RR advertisement, encryption enabled");
		/* TODO: Show active ringing feedback (e.g. LED on, beep) */
		break;
	case ATM_GFP_RR_EVENT_START_CONFIRMED:
		LOG_INF("RR: START indication ACKed (persistent fast feedback)");
		/* TODO: Show active ringing feedback immediately on persistent path */
		break;
	case ATM_GFP_RR_EVENT_STARTED:
		LOG_INF("RR: Ringing started");
		/* TODO: Show active ringing feedback (e.g. LED on, beep) */
		break;

	case ATM_GFP_RR_EVENT_STOP_CONFIRMED:
		LOG_INF("RR: STOP indication ACKed (persistent fast feedback)");
		/* TODO: Turn off ringing feedback immediately on persistent path */
		break;
	case ATM_GFP_RR_EVENT_STOPPED:
		LOG_INF("RR: Ringing stopped");
		/* TODO: Turn off LED or stop beep */
		break;

	case ATM_GFP_RR_EVENT_PHONE_FAILED:
		LOG_INF("RR: Phone failed to start ringing");
		/* TODO: Stop searching feedback and play error indication */
		break;

	case ATM_GFP_RR_EVENT_TIMEOUT_LOCAL:
		LOG_INF("RR: Provider ringing timeout");
		/* TODO: Stop searching feedback and play error indication */
		break;

	case ATM_GFP_RR_EVENT_PHONE_TIMEOUT:
		LOG_INF("RR: Phone ringing timed out");
		/* TODO: Turn off active ringing feedback */
		break;

	case ATM_GFP_RR_EVENT_PHONE_START_TIMEOUT:
		LOG_INF("RR: Persistent path ringing timed out (60s)");
		/* TODO: Stop active ringing feedback */
		break;

	case ATM_GFP_RR_EVENT_PHONE_STOPPED_DISCONNECTED:
		LOG_INF("RR: Connection dropped while phone was ringing");
		/* TODO: Stop active ringing feedback */
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

#if defined(CONFIG_FMDN_PRECISION_FINDING) || defined(CONFIG_DULT_MOTION_DETECT)
/* Reference count — tracks how many consumers (FMDN, DULT) have the sensor
 * enabled.  The hardware is started on the first enable and stopped only when
 * the last consumer releases it, so one consumer disabling never pulls the
 * sensor from under another.
 */
static uint8_t motion_use_count;

static void fp_platform_motion_hw_enable(bool enable)
{
	if (enable) {
		if (!motion_use_count) {
			int ret = platform_ctrl_motion_detect_init();

			if (ret) {
				LOG_ERR("Motion detect init failed: %d", ret);
				return;
			}
		}
		motion_use_count++;
	} else {
		if (motion_use_count && !--motion_use_count) {
			platform_ctrl_motion_detect_action(false);
		}
	}
}

#if defined(CONFIG_FMDN_PRECISION_FINDING) || !defined(CONFIG_DULT_MOTION_DETECT_TRIGGER)
static uint8_t fp_platform_motion_get_raw(void)
{
	return platform_ctrl_motion_detect_get_raw_data(MOTION_RAW_UNIT_DEG);
}
#endif
#endif /* CONFIG_FMDN_PRECISION_FINDING || CONFIG_DULT_MOTION_DETECT */

#if defined(CONFIG_LIS2DH_TRIGGER) || defined(CONFIG_AT_CMD_TAGMOTIONRPT)
static void fp_platform_motion_trigger_event(void)
{
	atm_gfp_motion_trigger_event();
}
#endif /* CONFIG_LIS2DH_TRIGGER || CONFIG_AT_CMD_TAGMOTIONRPT */

#if defined(CONFIG_DULT_MOTION_DETECT_TRIGGER) || defined(CONFIG_FMDN_OOB_MOTION_DETECT_TRIGGER)
static void fp_platform_motion_trigger_hw_enable(bool enable)
{
	fp_platform_motion_hw_enable(enable);
#if defined(CONFIG_LIS2DH_TRIGGER) || defined(CONFIG_AT_CMD_TAGMOTIONRPT)
	// Register on arm (not init) so the last consumer to arm owns the shared cb.
	if (enable) {
		platform_ctrl_motion_detect_set_event_cb(fp_platform_motion_trigger_event);
	}
	platform_ctrl_motion_detect_trigger_enable(enable);
#endif
}
#endif /* CONFIG_DULT_MOTION_DETECT */

#ifdef CONFIG_FMDN_PRECISION_FINDING
static int fp_platform_ranging_motion_cb(atm_gfp_motion_raw_get_t *get_raw)
{
	if (get_raw) {
#ifdef CONFIG_FMDN_OOB_MOTION_DETECT_TRIGGER
		fp_platform_motion_trigger_hw_enable(true);
#else
		fp_platform_motion_hw_enable(true);
#endif
		if (!motion_use_count) {
			/* init failed inside fp_platform_motion_hw_enable */
#ifdef CONFIG_AT_CMD_TAG_SET
			at_cmd_evt_tag_error(at_cmd_set_uart_ch_get(), AT_CMD_TAG_MODE_FHN,
					     AT_CMD_TAG_ERR_MOTION_SENSOR);
#endif
			return -ENODEV;
		}
		*get_raw = fp_platform_motion_get_raw;
	} else {
#ifdef CONFIG_FMDN_OOB_MOTION_DETECT_TRIGGER
		fp_platform_motion_trigger_hw_enable(false);
#else
		fp_platform_motion_hw_enable(false);
#endif
	}
	return 0;
}
#endif /* CONFIG_FMDN_PRECISION_FINDING */

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
		.motion_cb = fp_platform_ranging_motion_cb,
#endif
#ifdef CONFIG_DULT_MOTION_DETECT
#ifdef CONFIG_DULT_MOTION_DETECT_TRIGGER
		.dult_motion_hw_enable_cb = fp_platform_motion_trigger_hw_enable,
#else
		.dult_motion_hw_enable_cb = fp_platform_motion_hw_enable,
		/* Provide polling getter only when no HW trigger is available.
		 * With CONFIG_DULT_MOTION_DETECT_TRIGGER the platform uses the
		 * event-driven path (dult_ut_motion_event) and the poll loop is
		 * excluded from the build. */
		.dult_motion_raw_get_cb = fp_platform_motion_get_raw,
#endif
#endif /* CONFIG_DULT_MOTION_DETECT */
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
