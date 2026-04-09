/**
 *******************************************************************************
 *
 * @file atm_gfp.c
 *
 * @brief Library For Goole Fast Pair
 *
 * Copyright (C) Atmosic 2025-2026
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
#ifdef CONFIG_FMDN_REVERSE_RINGING
#include "fp_fmdn_reverse_ringing.h"
#endif
#endif // CONFIG_FAST_PAIR_FMDN
#include "fp_storage.h"

LOG_MODULE_REGISTER(atm_gfp, CONFIG_ATM_GFP_LOG_LEVEL);

static atm_gfp_hdlrs_t const *atm_gfp_hdlrs;

#ifdef CONFIG_FMDN_PRECISION_FINDING
/* Ranging handlers registered via atm_gfp_ranging_handler_register().
 * This allows dynamic registration separate from atm_gfp_init().
 */
static atm_gfp_ranging_handler_t const *atm_gfp_ranging_hdlrs;
#endif

#ifdef CONFIG_FMDN_REVERSE_RINGING
/*
 * @brief Adapter for reverse ringing events
 *
 * Converts detailed module-level events to simplified application-level events.
 * Per FHN v2 spec line 263, application only needs to know:
 * - Request sent successfully (indication confirmed) → Show LED/beep
 * - Ringing stopped (any reason) → Turn off LED/beep
 *
 * @param event Module-level event
 */
static void atm_gfp_reverse_ringing_event_adapter(fp_fmdn_reverse_ringing_event_t event)
{
	if (!atm_gfp_hdlrs || !atm_gfp_hdlrs->reverse_ringing_event_cb) {
		return;
	}

	/* Convert detailed module events to simple application events */
	atm_gfp_reverse_ringing_event_t lib_event;
	switch (event) {
	case RR_EVENT_REQUEST_SENT:
		/* Indication confirmed - show feedback to user */
		lib_event = ATM_GFP_RR_EVENT_STARTED;
		break;

	case RR_EVENT_PHONE_STARTED:
	case RR_EVENT_PHONE_FAILED:
	case RR_EVENT_PHONE_STOPPED_TIMEOUT:
	case RR_EVENT_PHONE_STOPPED_USER:
	case RR_EVENT_PHONE_STOPPED_PROVIDER:
	case RR_EVENT_TIMEOUT_LOCAL:
		/* Any stop event - turn off feedback */
		lib_event = ATM_GFP_RR_EVENT_STOPPED;
		break;

	default:
		LOG_WRN("Unknown reverse ringing event: %d", event);
		return;
	}

	/* Call application callback with simplified event */
	atm_gfp_hdlrs->reverse_ringing_event_cb(lib_event);
}
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
	const uint8_t *model_id = fp_gatt_get_model_id();
	memcpy(user_info->model_id, model_id, FP_APP_MODEL_ID_LEN);
	user_info->model_id_len = FP_APP_MODEL_ID_LEN;
}

static void atm_gfp_dult_sound_action(bool action)
{
	if (atm_gfp_hdlrs && atm_gfp_hdlrs->sound_action_cb) {
		// DULT does not define ring_op and ring_vol
		return atm_gfp_hdlrs->sound_action_cb(action, ATM_GFP_RING_OP_ALL,
						      ATM_GFP_RING_VOL_HIGH);
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
	/* Initialize GFPS with application-provided firmware version string */
	gfps_init(atm_gfp_hdlrs->fw_version_cb());

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

#ifdef CONFIG_FMDN_PRECISION_FINDING
	/* Register ranging handlers if provided */
	if (hdlrs->ranging_handlers) {
		atm_gfp_ranging_handler_register(hdlrs->ranging_handlers);
	}
#endif

#ifdef CONFIG_FMDN_REVERSE_RINGING
	/* Register reverse ringing event handler if provided
	 * Use adapter function to convert between library and module event types
	 */
	if (hdlrs->reverse_ringing_event_cb) {
		fp_fmdn_reverse_ringing_event_reg(atm_gfp_reverse_ringing_event_adapter);
	}
#endif

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
	/* Skip service re-init if handlers are not registered yet.
	 * This happens when atm_gfp_reset() is triggered during early boot
	 * (e.g. button factory reset via platform_reset_detect()) before
	 * atm_gfp_init() has run. The storage/clock cleanup above is sufficient;
	 * atm_gfp_init() will perform the full service init shortly after.
	 */
	if (atm_gfp_hdlrs) {
		atm_gfp_service_init();
	}
	atm_gfp_bt_unpair();
}

void atm_gfp_button_notify(void)
{
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
	dult_read_id_enable();
#endif
	gfps_button_notify(FP_SINGLE_TAP);
}

#ifdef CONFIG_FMDN_REVERSE_RINGING
void atm_gfp_button_double_notify(void)
{
	gfps_button_notify(FP_DOUBLE_TAP);
}
#endif

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
/* Wrapper callbacks to forward FMDN ranging handler calls to ATM GFP handlers.
 * These wrappers provide validation and error handling while forwarding to registered callbacks.
 * The tech_id parameter determines which union member is valid.
 */

static int atm_gfp_ranging_capability_wrapper(rt_id_t tech_id, ranging_capability_t *capability)
{
	if (!capability) {
		LOG_ERR("Invalid capability pointer");
		return -EINVAL;
	}

	if (!atm_gfp_ranging_hdlrs->capability_cb) {
		LOG_DBG("Capability callback not available for tech_id: 0x%02x", tech_id);
		return -ENODEV;
	}

	return atm_gfp_ranging_hdlrs->capability_cb(tech_id, capability);
}

static int atm_gfp_ranging_config_wrapper(rt_id_t tech_id, ranging_config_t *config,
					  bool start_immediately)
{
	if (!config) {
		LOG_ERR("Invalid config pointer");
		return -EINVAL;
	}

	if (!atm_gfp_ranging_hdlrs->config_cb) {
		LOG_DBG("Config callback not available for tech_id: 0x%02x", tech_id);
		return -ENODEV;
	}

	return atm_gfp_ranging_hdlrs->config_cb(tech_id, config, start_immediately);
}

static int atm_gfp_ranging_start_wrapper(rt_id_t tech_id)
{
	if (!atm_gfp_ranging_hdlrs->start_cb) {
		LOG_DBG("Start callback not available for tech_id: 0x%02x", tech_id);
		return -ENODEV;
	}

	return atm_gfp_ranging_hdlrs->start_cb(tech_id);
}

static int atm_gfp_ranging_stop_wrapper(rt_id_t tech_id)
{
	if (!atm_gfp_ranging_hdlrs->stop_cb) {
		LOG_DBG("Stop callback not available for tech_id: 0x%02x", tech_id);
		return -ENODEV;
	}

	return atm_gfp_ranging_hdlrs->stop_cb(tech_id);
}

void atm_gfp_ranging_handler_register(atm_gfp_ranging_handler_t const *handler)
{
	LOG_DBG("Registering FMDN ranging handler - capability: %s, config: %s, start: %s, "
		"stop: %s",
		handler->capability_cb ? "yes" : "no", handler->config_cb ? "yes" : "no",
		handler->start_cb ? "yes" : "no", handler->stop_cb ? "yes" : "no");

	/* Store the handler for use by wrapper functions */
	atm_gfp_ranging_hdlrs = handler;

	/* Create FMDN handler with wrapper callbacks.
	 * Wrappers provide validation and error handling before forwarding to registered callbacks.
	 * Wrappers will return -ENODEV if specific callbacks are not available.
	 */
	static fp_fmdn_ranging_handler_t fmdn_handler = {
		.capability_cb = atm_gfp_ranging_capability_wrapper,
		.config_cb = atm_gfp_ranging_config_wrapper,
		.start_cb = atm_gfp_ranging_start_wrapper,
		.stop_cb = atm_gfp_ranging_stop_wrapper,
	};

	fp_fmdn_ranging_handler_register(&fmdn_handler);
}
#endif

#ifdef CONFIG_FAST_PAIR_FMDN
int atm_gfp_fmdn_clock_save(void)
{
	return fp_fmdn_clock_save();
}

void atm_gfp_fmdn_clock_reset(void)
{
	fp_fmdn_clock_reset();
}
#endif
