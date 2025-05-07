/**
 *******************************************************************************
 *
 * @file atm_gfp.c
 *
 * @brief Library For Goole Fast Pair
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include <errno.h>
#include <zephyr/logging/log.h>
#include "atm_gfp.h"
#ifdef CONFIG_ATM_DULT
#include "app_work_q.h"
#include "dult.h"
#endif
#include "gfps.h"
#include "fp_common.h"
#include "fp_gatt.h"
#ifdef CONFIG_FAST_PAIR_FMDN
#include "fp_fmdn.h"
#endif
#include "fp_storage.h"

LOG_MODULE_REGISTER(atm_gfp, CONFIG_ATM_GFP_LOG_LEVEL);

static atm_gfp_hdlrs_t const *atm_gfp_hdlrs;

static uint8_t atm_gfp_battery_status(void)
{
	if (atm_gfp_hdlrs->battery_status_cb) {
		return atm_gfp_hdlrs->battery_status_cb();
	}
	return 0;
}

static void atm_gfp_sound_action(bool action)
{
	if (atm_gfp_hdlrs->sound_action_cb) {
		return atm_gfp_hdlrs->sound_action_cb(action);
	}
}

#ifdef CONFIG_FAST_PAIR_FMDN
static void fp_tag_utp_mode_switch(fp_fmdn_utp_mode_t mode)
{
	LOG_DBG("UTP mode switch to %u", mode);
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
	dult_enable((mode == FP_FMDN_UTP_MODE_ON));
#endif
}
#endif // CONFIG_FAST_PAIR_FMDN

#ifdef CONFIG_FAST_PAIR_FMDN_DULT
static void fp_tag_utp_owner_disconn_timeout_handler(struct k_work *work)
{
	LOG_INF("DULT Owner Disconnected");
#ifndef FP_FMDN_VALIDATOR_TEST
	dult_mode_update(DULT_NO_MODE_SEPERATED);
#endif
}

K_WORK_DELAYABLE_DEFINE(fp_tag_utp_owner_disconn_timer_id,
			fp_tag_utp_owner_disconn_timeout_handler);

typedef struct {
	uint8_t id[DULT_DATA_LEN];
	uint8_t id_len;
} dult_id_t;
static dult_id_t dult_id;
static void fp_tag_update_dult_id(uint8_t *id, uint8_t id_len)
{
	memcpy(dult_id.id, id, id_len);
	dult_id.id_len = id_len;
}

static void fp_tag_utp_owner_conn(bool connected)
{
	if (!fp_mode_is_provisioned()) {
		return;
	}
	if (connected) {
		LOG_INF("DULT Owner Connected");
		k_work_cancel_delayable(&fp_tag_utp_owner_disconn_timer_id);
		dult_mode_update(DULT_NO_MODE_NEAR_OWNER);
	} else {
#define DULT_DISCONN_TIMEOUT_MIN 30
		LOG_INF("Detect owner been disconnected for %d minutes", DULT_DISCONN_TIMEOUT_MIN);
		atm_work_reschedule_for_app_work_q(&fp_tag_utp_owner_disconn_timer_id,
						   K_MINUTES(DULT_DISCONN_TIMEOUT_MIN));
	}
}
#endif // CONFIG_FAST_PAIR_FMDN_DULT

static int fp_tag_gfps_init(void)
{
#ifdef CONFIG_FAST_PAIR_FMDN
	static gfps_hdlrs_t const hdlrs = {
		.utp_mode_cb = fp_tag_utp_mode_switch,
		.ring_action_cb = atm_gfp_sound_action,
		.battery_status_cb = atm_gfp_battery_status,
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
		.update_id_cb = fp_tag_update_dult_id,
		.utp_owner_conn_cb = fp_tag_utp_owner_conn,
#endif
#endif // CONFIG_FAST_PAIR_FMDN
	};
	gfps_handlers_register(&hdlrs);

	return gfps_init();
}

#if defined(CONFIG_FAST_PAIR_FMDN) && defined(CONFIG_FAST_PAIR_FMDN_DULT)
static uint8_t fp_tag_dult_get_id(uint8_t *id)
{
	memcpy(id, dult_id.id, dult_id.id_len);
	return dult_id.id_len;
}

static void fp_tag_dult_user_info(dult_user_info_t *user_info)
{
	uint8_t const model_id[] = {FP_APP_MODEL_ID};
	memcpy(user_info->model_id, model_id, sizeof(model_id));
	user_info->model_id_len = sizeof(model_id);
}

static int fp_tag_dult_init(void)
{
	static dult_hdlrs_t const hdlrs = {
		.dult_get_id_cb = fp_tag_dult_get_id,
		.battery_status_cb = atm_gfp_battery_status,
		.sound_action_cb = atm_gfp_sound_action,
	};

	static dult_user_info_t user_info;
	fp_tag_dult_user_info(&user_info);

	dult_handlers_register(&hdlrs, &user_info, fp_storage_bt_id_base_get() + FP_DULT_ADV_BT_ID);
	return dult_init();
}
#endif // CONFIG_FAST_PAIR_FMDN && CONFIG_FAST_PAIR_FMDN_DULT

static void atm_gfp_provision_timeout_handler(struct k_work *work)
{
	LOG_INF("Provision Timeout");
	atm_gfp_reset();
}
K_WORK_DELAYABLE_DEFINE(fp_tag_provision_timer_id, atm_gfp_provision_timeout_handler);

static void atm_gfp_provision_timer_en(bool en)
{
	if (en) {
#define FP_FMDN_PROVISION_TIMEOUT_MIN 5
		LOG_INF("Provision must be done in %d minutes", FP_FMDN_PROVISION_TIMEOUT_MIN);
		atm_work_reschedule_for_app_work_q(&fp_tag_provision_timer_id,
						   K_MINUTES(FP_FMDN_PROVISION_TIMEOUT_MIN));
	} else {
		k_work_cancel_delayable(&fp_tag_provision_timer_id);
	}
}

static void atm_gfp_mode_switch(fp_mode_t mode)
{
	LOG_INF("Mode switched to %u", mode);
	switch (mode) {
	case FP_MODE_NONE:
		LOG_INF("Perform Reset");
		atm_gfp_reset();
		break;
	case FP_MODE_PAIRING_PROCESSING:
		break;
	case FP_MODE_PAIRED:
		atm_gfp_provision_timer_en(true);
		break;
	case FP_MODE_PROVISIONED:
		atm_gfp_provision_timer_en(false);
		break;
	default:
		LOG_DBG("mode %u do nothing", mode);
		break;
	}
#ifdef CONFIG_ATM_GFP_MUTLIMODE_TAG
	if (atm_gfp_hdlrs->mode_state_cb) {
		atm_gfp_hdlrs->mode_state_cb(mode);
	}
#endif
}

static void atm_gfp_service_init(void)
{
	fp_tag_gfps_init();
	fp_mode_t mode = fp_mode_get();
#if defined(CONFIG_FAST_PAIR_FMDN) && defined(CONFIG_FAST_PAIR_FMDN_DULT)
	fp_tag_dult_init();
	if (mode == FP_MODE_PROVISIONED) {
		dult_mode_update(DULT_NO_MODE_SEPERATED);
	}
#endif
	if (mode == FP_MODE_NONE) {
#ifdef CONFIG_ATM_GFP_MUTLIMODE_TAG
		if (atm_gfp_hdlrs->mode_state_cb) {
			LOG_INF("Update FP_MODE_NONE");
			atm_gfp_hdlrs->mode_state_cb(FP_MODE_NONE);
		}
#else
		LOG_INF("Press button to start paring");
#endif
	}
}

void atm_gfp_init(atm_gfp_hdlrs_t const *hdlrs)
{
	atm_gfp_hdlrs = hdlrs;
	fp_mode_switch_reg(atm_gfp_mode_switch);
	atm_gfp_service_init();
}

void atm_gfp_reset(void)
{
	atm_gfp_provision_timer_en(false);
	gfps_reset();
#if defined(CONFIG_FAST_PAIR_FMDN) && defined(CONFIG_FAST_PAIR_FMDN_DULT)
	k_work_cancel_delayable(&fp_tag_utp_owner_disconn_timer_id);
	dult_reset();
#endif
	atm_gfp_service_init();
}

void atm_gfp_button_notify(void)
{
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
	dult_read_id_enable();
#endif
	gfps_button_notify();
}

#ifdef CONFIG_ATM_GFP_MUTLIMODE_TAG
void atm_gfp_stop(void)
{
	atm_gfp_reset();
}

void atm_gfp_start(void)
{
	gfps_fp_pairing_adv();
}

bool atm_gfp_is_provisioned(void)
{
	return gfps_fp_is_provisioned();
}
#endif
