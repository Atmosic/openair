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

static void fp_tag_platform_buzzer_action(bool action, atm_gfp_ring_op_t ring_op,
					  atm_gfp_ring_vol_t ring_vol)
{
	LOG_DBG("fp buzzer action: %s, ring_op: %s (%u), ring_vol: %s (%u)", action ? "ON" : "OFF",
		atm_gfp_ring_op_to_string(ring_op), ring_op, atm_gfp_ring_vol_to_string(ring_vol),
		ring_vol);
	platform_ctrl_buzzer_action(action);
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
#ifdef CONFIG_FMDN_PRECISION_FINDING
		.ranging_handlers = &ranging_handler,
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
