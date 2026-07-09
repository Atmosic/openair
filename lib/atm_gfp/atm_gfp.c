/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/**
 *******************************************************************************
 *
 * @file atm_gfp.c
 *
 * @brief Library For Google Fast Pair
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include <errno.h>
#include <zephyr/logging/log.h>
#include "app_work_q.h"
#include "atm_gfp.h"
#ifdef CONFIG_ATM_DULT
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
 *
 * For persistent connections the indication ACK is the fast-feedback trigger —
 * the application must not wait for the Seeker's write-back (RR_EVENT_PHONE_STARTED).
 * Once ATM_GFP_RR_EVENT_STARTED has been delivered via indication ACK, the
 * subsequent Seeker write is suppressed so the application callback fires
 * exactly once per session.
 *
 * For adv-based connections no START indication is sent, so RR_EVENT_PHONE_STARTED
 * remains the sole trigger for ATM_GFP_RR_EVENT_STARTED.
 *
 * @param event Module-level event
 */

/* true after indication ACK fires for persistent flow; reset on any stop event
 * or at the start of a new adv-based session.
 */
static bool rr_started_sent;

static void atm_gfp_reverse_ringing_event_adapter(fp_fmdn_reverse_ringing_event_t event)
{
	if (!atm_gfp_hdlrs || !atm_gfp_hdlrs->reverse_ringing_event_cb) {
		return;
	}

	/* Convert detailed module events to simple application events */
	atm_gfp_reverse_ringing_event_t lib_event;
	switch (event) {
	case RR_EVENT_RR_ADV_CONNECTED:
		/* Reset flag at the start of every new adv-based session */
		rr_started_sent = false;
		lib_event = ATM_GFP_RR_EVENT_CONNECTED;
		break;
	case RR_EVENT_START_INDICATION_CONFIRMED:
		/* Persistent flow: indication ACK is the fast-feedback trigger */
		rr_started_sent = true;
		lib_event = ATM_GFP_RR_EVENT_STARTED;
		break;
	case RR_EVENT_PHONE_STARTED:
		/* Adv flow: no indication ACK, Seeker write is the only trigger.
		 * Persistent flow: indication ACK already fired STARTED — suppress.
		 */
		if (rr_started_sent) {
			return;
		}
		lib_event = ATM_GFP_RR_EVENT_STARTED;
		break;
	case RR_EVENT_STOP_INDICATION_CONFIRMED:
	case RR_EVENT_PHONE_FAILED:
	case RR_EVENT_PHONE_STOPPED_TIMEOUT:
	case RR_EVENT_PHONE_STOPPED_USER:
	case RR_EVENT_PHONE_STOPPED_PROVIDER:
	case RR_EVENT_TIMEOUT_LOCAL:
		rr_started_sent = false;
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

static void atm_gfp_sound_action(bool action, uint8_t ring_op, uint8_t ring_vol_lvl,
				 uint16_t ring_to_ds)
{
	if (atm_gfp_hdlrs && atm_gfp_hdlrs->sound_action_cb) {
		return atm_gfp_hdlrs->sound_action_cb(action, ring_op, ring_vol_lvl, ring_to_ds);
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
						      ATM_GFP_RING_VOL_HIGH,
						      (DULT_PLAY_SOUND_DUR_SEC * 10));
	}
}

#ifdef CONFIG_FMDN_PRECISION_FINDING
/* Raw-degrees snapshot getter provided by the platform when hw is enabled.  */
static uint8_t (*motion_raw_getter)(void);
/* FMDN active flag — makes FMDN hw enable/disable idempotent.               */
static bool motion_fmdn_active;

static int atm_gfp_motion_hw_start(void)
{
	if (!atm_gfp_hdlrs || !atm_gfp_hdlrs->motion_cb) {
		return -ENODEV;
	}
	motion_raw_getter = NULL;
	return atm_gfp_hdlrs->motion_cb(&motion_raw_getter);
}

static void atm_gfp_motion_hw_stop(void)
{
	motion_raw_getter = NULL;
	atm_gfp_hdlrs->motion_cb(NULL);
}

/*
 * Enable or disable motion hw on behalf of FMDN ranging.
 * Idempotent: repeated calls with the same state are no-ops.
 */
static int atm_gfp_fmdn_motion_set(bool enable)
{
	if (enable == motion_fmdn_active) {
		return 0;
	}
	motion_fmdn_active = enable;
	if (enable) {
		return atm_gfp_motion_hw_start();
	}
	atm_gfp_motion_hw_stop();
	return 0;
}
#endif /* CONFIG_FMDN_PRECISION_FINDING */

static int fp_tag_dult_init(void)
{
	static dult_hdlrs_t hdlrs = {
		.dult_get_id_cb = fp_tag_dult_get_id,
		.battery_status_cb = atm_gfp_battery_status,
		.sound_action_cb = atm_gfp_dult_sound_action,
	};

#ifdef CONFIG_DULT_MOTION_DETECT
	if (atm_gfp_hdlrs) {
		hdlrs.motion_hw_enable_cb = atm_gfp_hdlrs->dult_motion_hw_enable_cb;
		hdlrs.motion_raw_get_cb = atm_gfp_hdlrs->dult_motion_raw_get_cb;
	}
#endif
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
		bool utp_mode = (fp_storage_utp_mode_get() == FP_FMDN_UTP_MODE_ON);
		if (utp_mode) {
			dult_enable(utp_mode);
		} else {
			dult_mode_update(DULT_NO_MODE_SEPERATED);
		}
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

const char *atm_gfp_ring_vol_to_string(atm_gfp_ring_vol_t ring_vol_lvl)
{
	switch (ring_vol_lvl) {
	case ATM_GFP_RING_VOL_DEFAULT:
		return "DEFAULT";
	case ATM_GFP_RING_VOL_LOW:
		return "LOW";
	case ATM_GFP_RING_VOL_MEDIUM:
		return "MEDIUM";
	case ATM_GFP_RING_VOL_HIGH:
		return "HIGH";
	default:
		__ASSERT(0, "Invalid ring_vol_lvl: %d", ring_vol_lvl);
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

static int atm_gfp_ranging_motion_wrapper(fp_fmdn_ranging_motion_get_status_t *get_status)
{
	if (get_status) {
		int ret = atm_gfp_fmdn_motion_set(true);

		if (ret) {
			return ret;
		}
		/* Provide the raw platform getter directly; fp_fhpf_gatt converts
		 * degrees to the 4-level enum and sends GATT notifications itself. */
		*get_status = motion_raw_getter;
	} else {
		atm_gfp_fmdn_motion_set(false);
	}
	return 0;
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
		.motion_cb = atm_gfp_ranging_motion_wrapper,
	};

	fp_fmdn_ranging_handler_register(&fmdn_handler);
}
#endif // CONFIG_FMDN_PRECISION_FINDING

#ifdef CONFIG_FAST_PAIR_FMDN
void atm_gfp_fmdn_clock_set(uint32_t clock_value)
{
	fp_fmdn_clock_set(clock_value);
}

uint32_t atm_gfp_fmdn_clock_get(void)
{
	return fp_fmdn_clock_get();
}

int atm_gfp_fmdn_clock_save(void)
{
	return fp_fmdn_clock_save();
}

void atm_gfp_fmdn_clock_reset(void)
{
	fp_fmdn_clock_reset();
}
#endif

int atm_gfp_get_adv_addr(bt_addr_le_t *addr)
{
	uint8_t fp_id = gfps_fp_is_provisioned() ? FP_FMDN_ADV_BT_ID : FP_ADV_BT_ID;
	uint8_t bt_id = fp_conn_get_bt_id(fp_id);

	bt_addr_le_t all_addr[CONFIG_BT_ID_MAX];
	size_t all_count = CONFIG_BT_ID_MAX;
	bt_id_get(all_addr, &all_count);

	if (bt_id >= all_count) {
		LOG_ERR("BT ID %u out of range (count: %u)", bt_id, (uint32_t)all_count);
		return -ENODEV;
	}

	LOG_INF("ADV addr from BT_ID [%u]", bt_id);
	bt_addr_le_copy(addr, &all_addr[bt_id]);
	return 0;
}

#ifdef CONFIG_ZTEST
/* Test hooks: expose internal static functions for unit test coverage */
void atm_gfp_test_set_hdlrs(atm_gfp_hdlrs_t const *hdlrs)
{
	atm_gfp_hdlrs = hdlrs;
}

void atm_gfp_test_service_init(void)
{
	atm_gfp_service_init();
}

#ifdef CONFIG_FAST_PAIR_FMDN
void atm_gfp_test_utp_mode_switch(fp_fmdn_utp_mode_t mode)
{
	fp_tag_utp_mode_switch(mode);
}
#endif /* CONFIG_FAST_PAIR_FMDN */

void atm_gfp_test_convert_handlers(atm_gfp_hdlrs_t const *atm_hdlrs, gfps_hdlrs_t *gfps_hdlrs)
{
	atm_gfp_convert_handlers(atm_hdlrs, gfps_hdlrs);
}

uint8_t atm_gfp_test_battery_status(void)
{
	return atm_gfp_battery_status();
}

void atm_gfp_test_sound_action(bool action, uint8_t ring_op, uint8_t ring_vol_lvl,
			       uint16_t ring_to_ds)
{
	atm_gfp_sound_action(action, ring_op, ring_vol_lvl, ring_to_ds);
}

void atm_gfp_test_mode_switch(fp_mode_t mode)
{
	atm_gfp_mode_switch(mode);
}

void atm_gfp_test_provision_timeout(void)
{
	atm_gfp_provision_timeout_handler(NULL);
}
#endif /* CONFIG_ZTEST */
