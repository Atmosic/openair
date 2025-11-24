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
#include "fp_conn.h"
#include "fp_gatt.h"
#ifdef CONFIG_FAST_PAIR_FMDN
#include "fp_fmdn.h"
#ifdef CONFIG_FMDN_PRECISION_FINDING
#include "fp_fmdn_gatt.h"
#endif
#endif
#include "fp_storage.h"

LOG_MODULE_REGISTER(atm_gfp, CONFIG_ATM_GFP_LOG_LEVEL);

static atm_gfp_hdlrs_t const *atm_gfp_hdlrs;

#ifdef CONFIG_FMDN_PRECISION_FINDING
/// Stored ranging handlers for direct registration
static atm_gfp_ranging_handler_t const *atm_gfp_ranging_hdlrs;
#endif

/**
 * @brief Convert ATM GFP handlers to GFPS handlers
 *
 * This function creates a GFPS handlers structure from the ATM GFP handlers,
 * mapping the callback functions appropriately.
 *
 * @param atm_hdlrs ATM GFP handlers structure
 * @param gfps_hdlrs GFPS handlers structure to populate
 */
static void atm_gfp_convert_handlers(atm_gfp_hdlrs_t const *atm_hdlrs, gfps_hdlrs_t *gfps_hdlrs)
{
	if (!atm_hdlrs || !gfps_hdlrs) {
		return;
	}

	// Clear the structure
	memset(gfps_hdlrs, 0, sizeof(gfps_hdlrs_t));

	// Map basic handlers
	gfps_hdlrs->battery_status_cb = atm_hdlrs->battery_status_cb;
	gfps_hdlrs->ring_action_cb = atm_hdlrs->sound_action_cb;

	gfps_hdlrs->mode_switch_cb = atm_hdlrs->mode_state_cb;

#ifdef CONFIG_FMDN_PRECISION_FINDING
	// Use stored ranging handlers if available, otherwise use handlers from structure
	if (atm_gfp_ranging_hdlrs) {
		gfps_hdlrs->ranging_handlers = (fp_fmdn_ranging_handler_t *)atm_gfp_ranging_hdlrs;
	} else if (atm_hdlrs->ranging_handlers) {
		gfps_hdlrs->ranging_handlers =
			(fp_fmdn_ranging_handler_t *)atm_hdlrs->ranging_handlers;
	}
#endif
}

static uint8_t atm_gfp_battery_status(void)
{
	if (atm_gfp_hdlrs && atm_gfp_hdlrs->battery_status_cb) {
		return atm_gfp_hdlrs->battery_status_cb();
	}
	return 0;
}

static void atm_gfp_sound_action(bool action, uint8_t ring_op, uint8_t ring_vol)
{
	if (atm_gfp_hdlrs && atm_gfp_hdlrs->sound_action_cb) {
		return atm_gfp_hdlrs->sound_action_cb(action, ring_op, ring_vol);
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
	// when UTP is on, skip update DULT mode
	if (fp_storage_utp_mode_get() != FP_FMDN_UTP_MODE_ON) {
		dult_mode_update(DULT_NO_MODE_SEPERATED);
	}
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
		// when UTP is on, skip update DULT mode
		if (fp_storage_utp_mode_get() != FP_FMDN_UTP_MODE_ON) {
			dult_mode_update(DULT_NO_MODE_NEAR_OWNER);
		}
	} else {
#define DULT_DISCONN_TIMEOUT_MIN 30
		LOG_INF("Detect owner been disconnected for %d minutes", DULT_DISCONN_TIMEOUT_MIN);
		atm_work_reschedule_for_app_work_q(&fp_tag_utp_owner_disconn_timer_id,
						   K_MINUTES(DULT_DISCONN_TIMEOUT_MIN));
	}
}
#endif // CONFIG_FAST_PAIR_FMDN_DULT

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

static void atm_gfp_dult_sound_action(bool action)
{
	if (atm_gfp_hdlrs && atm_gfp_hdlrs->sound_action_cb) {
		// DULT does not define ring_op and ring_vol
		return atm_gfp_hdlrs->sound_action_cb(action, ATM_GFP_RING_OP_ALL,
						      ATM_GFP_RING_VOL_DEFAULT);
	}
}

static int fp_tag_dult_init(void)
{
	static dult_hdlrs_t const hdlrs = {
		.dult_get_id_cb = fp_tag_dult_get_id,
		.battery_status_cb = atm_gfp_battery_status,
		.sound_action_cb = atm_gfp_dult_sound_action,
	};

	static dult_user_info_t user_info;
	fp_tag_dult_user_info(&user_info);
	dult_handlers_register(&hdlrs, &user_info, fp_conn_get_bt_id(FP_DULT_ADV_BT_ID));
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
		dult_mode_update(DULT_NO_MODE_NEAR_OWNER);
		break;
	default:
		LOG_DBG("mode %u do nothing", mode);
		break;
	}
	if (atm_gfp_hdlrs && atm_gfp_hdlrs->mode_state_cb) {
		atm_gfp_hdlrs->mode_state_cb(mode);
	}
}

static void atm_gfp_service_init(void)
{
	gfps_init();
	fp_mode_t mode = fp_mode_get();
#if defined(CONFIG_FAST_PAIR_FMDN) && defined(CONFIG_FAST_PAIR_FMDN_DULT)
	fp_tag_dult_init();
	if (mode == FP_MODE_PROVISIONED) {
		// Enable DULT based on UTP mode (consistent with UTP mode switch logic)
		dult_enable(fp_storage_utp_mode_get() == FP_FMDN_UTP_MODE_ON);
	}
#endif
	if (mode == FP_MODE_NONE) {
		if (atm_gfp_hdlrs && atm_gfp_hdlrs->mode_state_cb) {
			LOG_INF("Update FP_MODE_NONE");
			atm_gfp_hdlrs->mode_state_cb(FP_MODE_NONE);
		}
	}
}

static void atm_gfp_do_bt_unpair(uint8_t bt_id)
{
	int err = bt_unpair(bt_id, NULL);
	if (err) {
		LOG_ERR("Failed to unpair BT ID %u (err %d)", bt_id, err);
		return;
	}
	LOG_DBG("Successfully unpaired BT ID %u", bt_id);
}

static void atm_gfp_bt_unpair(void)
{
#ifdef CONFIG_ATM_GFP_FORCE_UNPAIR_ALL_BT_ID
	// Clear bonds for all BT_IDs
	LOG_INF("Force Clearing bonds for all BT_IDs");
	bt_addr_le_t all_addr[CONFIG_BT_ID_MAX];
	size_t all_count = CONFIG_BT_ID_MAX;
	bt_id_get(all_addr, &all_count);
	for (uint8_t i = 0; i < all_count; i++) {
		atm_gfp_do_bt_unpair(i);
	}
#else
	/* Shared advertising: unpair all BT IDs for comprehensive cleanup */
	LOG_INF("Clearing bonds for Fast Pair BT_IDs");
	uint8_t id_list[FP_ADV_BT_ID_MAX];
	uint8_t id_num = atm_gfp_bt_id_list_get(id_list);
	__ASSERT(id_num <= FP_ADV_BT_ID_MAX, "id_num (%u) exceeds FP_ADV_BT_ID_MAX (%u)", id_num,
		 FP_ADV_BT_ID_MAX);
	/* Clamp to prevent buffer overflow */
	if (id_num > FP_ADV_BT_ID_MAX) {
		LOG_ERR("Too many BT IDs returned (%u), clamping to %u", id_num, FP_ADV_BT_ID_MAX);
		id_num = FP_ADV_BT_ID_MAX;
	}
	/* Unpair all Fast Pair BT IDs */
	for (uint8_t i = 0; i < id_num; i++) {
		atm_gfp_do_bt_unpair(id_list[i]);
	}
#endif // CONFIG_ATM_GFP_FORCE_UNPAIR_ALL_BT_ID
}

void atm_gfp_init(atm_gfp_hdlrs_t const *hdlrs)
{
	// Store the handlers for later use
	atm_gfp_hdlrs = hdlrs;

	// Convert ATM GFP handlers to GFPS handlers
	gfps_hdlrs_t gfps_hdlrs;
	atm_gfp_convert_handlers(hdlrs, &gfps_hdlrs);
#ifdef CONFIG_FAST_PAIR_FMDN
	gfps_hdlrs.utp_mode_cb = fp_tag_utp_mode_switch;
	gfps_hdlrs.ring_action_cb = atm_gfp_sound_action;
	gfps_hdlrs.battery_status_cb = atm_gfp_battery_status;
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
	gfps_hdlrs.update_id_cb = fp_tag_update_dult_id;
	gfps_hdlrs.utp_owner_conn_cb = fp_tag_utp_owner_conn;
#endif
#endif
	// Register handlers with GFPS
	gfps_handlers_register(&gfps_hdlrs);

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
	atm_gfp_bt_unpair();
}

void atm_gfp_button_notify(void)
{
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
	dult_read_id_enable();
#endif
	gfps_button_notify();
}

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

uint8_t atm_gfp_bt_id_list_get(uint8_t *id_list)
{
	uint8_t idx = 0;
	for (uint8_t i = FP_ADV_BT_ID; i < FP_ADV_BT_ID_MAX; i++) {
		id_list[idx++] = fp_conn_get_bt_id(i);
	}
	return idx;
}

const char *atm_gfp_ring_op_to_string(atm_gfp_ring_op_t ring_op)
{
	switch (ring_op) {
	case ATM_GFP_RING_OP_RIGHT:
		return "RIGHT";
	case ATM_GFP_RING_OP_LEFT:
		return "LEFT";
	case ATM_GFP_RING_OP_CASE:
		return "CASE";
	case ATM_GFP_RING_OP_ALL:
		return "ALL";
	default:
		__ASSERT(0, "Invalid ring_op: %d", ring_op);
		return NULL;
	}
}

const char *atm_gfp_ring_vol_to_string(atm_gfp_ring_vol_t ring_vol)
{
	switch (ring_vol) {
	case ATM_GFP_RING_VOL_DEFAULT:
		return "DEFAULT";
	case ATM_GFP_RING_VOL_LOW:
		return "LOW";
	case ATM_GFP_RING_VOL_MEDIUM:
		return "MEDIUM";
	case ATM_GFP_RING_VOL_HIGH:
		return "HIGH";
	default:
		__ASSERT(0, "Invalid ring_vol: %d", ring_vol);
		return NULL;
	}
}
fp_mode_t atm_gfp_fp_mode_get(void)
{
	return fp_mode_get();
}

#ifdef CONFIG_FMDN_PRECISION_FINDING
void atm_gfp_ranging_handler_register(atm_gfp_ranging_handler_t const *handler)
{
	LOG_DBG("Registering FMDN ranging handler");

	// Store the handler for later use
	atm_gfp_ranging_hdlrs = handler;

	LOG_DBG("FMDN ranging handler registered - capability: %s, config: %s, start: %s, stop: %s",
		handler->capability_cb ? "yes" : "no", handler->config_cb ? "yes" : "no",
		handler->start_cb ? "yes" : "no", handler->stop_cb ? "yes" : "no");

	// Convert and register with FMDN layer
	fp_fmdn_ranging_handler_t fmdn_handler = {.capability_cb = handler->capability_cb,
						  .config_cb = handler->config_cb,
						  .start_cb = handler->start_cb,
						  .stop_cb = handler->stop_cb};
	fp_fmdn_ranging_handler_register(&fmdn_handler);
}
#endif
