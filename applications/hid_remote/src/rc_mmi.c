/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/device.h>
#include <zephyr/smf.h>
#include <zephyr/bluetooth/services/bas.h>
#include <zephyr/logging/log.h>

#ifdef CONFIG_PM
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#endif

#ifdef CONFIG_APP_BATT
#include "app_batt.h"
#endif

#include "rc_mmi.h"
#include "rc_mmi_timer.h"
#include "rc_input.h"
#include "rc_gap.h"
#include "bt/rc_hids.h"
#ifdef CONFIG_IR_NEC
#include "rc_ir.h"
#endif
#ifdef CONFIG_RC_VOICE
#include "rc_audio.h"
#endif
#include "rc_led.h"
#ifdef CONFIG_BT_IAS
#include "rc_fmp.h"
#endif

LOG_MODULE_REGISTER(rc_mmi, CONFIG_HID_REMOTE_LOG_LEVEL);

struct mmi_ctx {
	struct smf_ctx ctx;
	mmi_op_t evt;
};

static struct mmi_ctx mmi_ctx;
static const struct smf_state mmi_states[MMI_S_NUM];

#ifdef CONFIG_RC_PDM_DEBUG
/* Debug: PDM-only test (no BLE). Set when streaming starts from IDLE. */
static bool streaming_from_idle;
#endif

#ifdef CONFIG_APP_BATT
static void (*app_batt_done_cb)(void);

static void rc_batt_level_update(uint16_t lvl_bp, int32_t mvolt)
{
	ARG_UNUSED(mvolt);
	bt_bas_set_battery_level((uint8_t)(lvl_bp / 100));
}

static void rc_batt_app_start(void (*done)(void))
{
	app_batt_done_cb = done;
	rc_gap_init();
	rc_mmi_timer_init(rc_mmi_idle_timer_expired, rc_mmi_hib_timer_expired);
}

static void rc_batt_app_stop(void (*done)(void))
{
	done();
}
#endif /* CONFIG_APP_BATT */

void rc_mmi_run_event(mmi_op_t op)
{
	mmi_ctx.evt = op;
	LOG_DBG("mmi evt=%d state=%d", op, rc_mmi_get_state());
	smf_run_state(SMF_CTX(&mmi_ctx));
}

static void rc_mmi_idle_timer_expired(void)
{
	if (rc_hids_get_state() == RC_HIDS_READY) {
		LOG_INF("idle timeout — disconnecting");
		rc_mmi_run_event(MMI_OP_DISCONNING);
	} else {
		rc_gap_discoverable(false);
	}
}

static void rc_mmi_hib_timer_expired(void)
{
	rc_mmi_timer_clear_all();
#if defined(CONFIG_PM) && !defined(CONFIG_APP_BATT)
	if (pm_policy_state_lock_is_active(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES)) {
		LOG_INF("pm_policy_state_lock_put");
		pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	}
#endif
}

int rc_mmi_get_state(void)
{
	return (int)(mmi_ctx.ctx.current - mmi_states);
}

/* ── LED restore callback for rc_input combo cancel ─────────────────────── */

static void mmi_led_restore(void)
{
	int state = rc_mmi_get_state();

	switch (state) {
	case MMI_S_PAIRING:
		rc_led_set(RC_LED_PAIRING);
		break;
	case MMI_S_RECONNING:
		rc_led_set(RC_LED_RECONNECTING);
		break;
	default:
		rc_led_set(RC_LED_OFF);
		break;
	}
}

/* MMI state machine entry functions. */

static void mmi_booted_entry(void *obj)
{
	LOG_DBG("mmi_s:MMI_S_BOOTED");
}

static void mmi_initing_entry(void *obj)
{
	LOG_DBG("mmi_s:MMI_S_INITING");
#if defined(CONFIG_PM) && !defined(CONFIG_APP_BATT)
	rc_mmi_timer_hib_clear();
#endif

	rc_led_init();
	rc_input_init(mmi_led_restore);
#ifdef CONFIG_IR_NEC
	rc_ir_init();
#endif
	rc_hids_init();
#ifdef CONFIG_RC_VOICE
	rc_audio_init();
#endif
#ifdef CONFIG_BT_IAS
	rc_fmp_init();
#endif

#ifdef CONFIG_APP_BATT
	static app_batt_cbs_t const cbs = {
		.app_start = rc_batt_app_start,
		.app_stop = rc_batt_app_stop,
		.level_update = rc_batt_level_update,
	};
	app_batt_start(&cbs);
	if (app_batt_done_cb) {
		app_batt_done_cb();
		app_batt_done_cb = NULL;
	}
#else
	rc_gap_init();
	rc_mmi_timer_init(rc_mmi_idle_timer_expired, rc_mmi_hib_timer_expired);
#endif
}

static void mmi_idle_entry(void *obj)
{
	LOG_DBG("mmi_s:MMI_S_IDLE");
#if defined(CONFIG_PM) && !defined(CONFIG_APP_BATT)
	rc_mmi_timer_hib_set(CONFIG_RC_HIB_DELAY_CS);
#endif
}

static void mmi_pairing_entry(void *obj)
{
	LOG_DBG("mmi_s:MMI_S_PAIRING");
#if defined(CONFIG_PM) && !defined(CONFIG_APP_BATT)
	rc_mmi_timer_hib_clear();
#endif
	rc_led_set(RC_LED_PAIRING);
#ifdef CONFIG_APP_BATT
	if (app_batt_done_cb) {
		app_batt_done_cb();
		app_batt_done_cb = NULL;
	}
#endif
}

static void mmi_reconning_entry(void *obj)
{
	LOG_DBG("mmi_s:MMI_S_RECONNING");
#if defined(CONFIG_PM) && !defined(CONFIG_APP_BATT)
	rc_mmi_timer_hib_clear();
#endif
	rc_led_set(RC_LED_RECONNECTING);
#ifdef CONFIG_APP_BATT
	if (app_batt_done_cb) {
		app_batt_done_cb();
		app_batt_done_cb = NULL;
	}
#endif
}

static void mmi_connected_entry(void *obj)
{
	LOG_DBG("mmi_s:MMI_S_CONNECTED");
#if defined(CONFIG_PM) && !defined(CONFIG_APP_BATT)
	rc_mmi_timer_hib_clear();
#endif
}

static void mmi_hid_ready_entry(void *obj)
{
	LOG_DBG("mmi_s:MMI_S_HID_READY");
#if defined(CONFIG_PM) && !defined(CONFIG_APP_BATT)
	rc_mmi_timer_hib_clear();
#endif
}

static void mmi_streaming_entry(void *obj)
{
	LOG_DBG("mmi_s:MMI_S_STREAMING");
#if defined(CONFIG_PM) && !defined(CONFIG_APP_BATT)
	rc_mmi_timer_hib_clear();
#endif
	/* Switch to low-latency params for audio transfer */
	rc_gap_param_update(true);
	rc_mmi_timer_idle_clear();
#ifdef CONFIG_RC_VOICE
	rc_audio_stream_start();
#endif
}

static void mmi_discing_entry(void *obj)
{
	LOG_DBG("mmi_s:MMI_S_DISCONNING");
#if defined(CONFIG_PM) && !defined(CONFIG_APP_BATT)
	rc_mmi_timer_hib_clear();
#endif
	rc_mmi_timer_idle_clear();
	rc_gap_disconnect();
}

static void mmi_rf_test_entry(void *obj)
{
	LOG_DBG("mmi_s:MMI_S_RF_TEST");
}

static void mmi_s_connected(void)
{
	rc_led_set(RC_LED_OFF);
	rc_mmi_timer_idle_set(CONFIG_RC_READY_TIMEOUT_CS);
	rc_input_set_reconnected(true);
}

static void mmi_s_reconnecting_fail(void)
{
	rc_led_set(RC_LED_OFF);
#ifdef CONFIG_APP_BATT
	app_batt_stop();
#endif
}

static void mmi_s_hid_ready(void)
{
	/* Request the configured power-save connection parameters. */
	rc_gap_param_update(false);
	rc_input_flush_keybuf();
	rc_mmi_timer_idle_set(CONFIG_RC_IDLE_TIMEOUT_CS);
}

static void mmi_s_streaming_stopped(void)
{
	LOG_INF("Audio streaming stopped");
#ifdef CONFIG_RC_VOICE
	rc_audio_stream_stop();
#endif
	rc_led_set(RC_LED_OFF);
#ifdef CONFIG_RC_PDM_DEBUG
	if (streaming_from_idle) {
		streaming_from_idle = false;
		return;
	}
#endif
	/* Restore power-save params after audio */
	rc_gap_param_update(false);
	rc_mmi_timer_idle_set(CONFIG_RC_IDLE_TIMEOUT_CS);
}

static void mmi_s_pairing_success_stopped(void)
{
	LOG_INF("Pairing succeeded");
	rc_led_set(RC_LED_OFF);
}

static void mmi_pairing_cleanup(void)
{
	rc_led_set(RC_LED_OFF);
#ifdef CONFIG_APP_BATT
	app_batt_stop();
#endif
}

static void mmi_s_pairing_auth_failed(void)
{
	LOG_WRN("Pairing failed: security/auth error");
	mmi_pairing_cleanup();
}

static void mmi_s_pairing_adv_timeout(void)
{
	LOG_INF("Pairing failed: ADV timeout (no host)");
	mmi_pairing_cleanup();
}

static void mmi_s_pairing_adv_stopped(void)
{
	LOG_INF("Pairing ADV stopped");
	mmi_pairing_cleanup();
}

static void mmi_s_disconnected(void)
{
	rc_led_set(RC_LED_OFF);
	rc_mmi_timer_clear_all();
#ifdef CONFIG_APP_BATT
	app_batt_stop();
#endif
}

static void mmi_s_disc_restart(void)
{
	rc_mmi_timer_clear_all();
	rc_gap_discoverable(true);
}

/* SMF state run functions. */

static enum smf_state_result mmi_booted_run(void *obj)
{
	switch (mmi_ctx.evt) {
	case MMI_OP_INITING:
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_INITING]);
		break;
	default:
		break;
	}
	return SMF_EVENT_PROPAGATE;
}

static enum smf_state_result mmi_initing_run(void *obj)
{
	switch (mmi_ctx.evt) {
	case MMI_OP_INIT_DONE:
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_IDLE]);
		break;
	case MMI_OP_RECONNING:
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_RECONNING]);
		break;
	case MMI_OP_PAIRING:
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_PAIRING]);
		break;
	default:
		break;
	}
	return SMF_EVENT_PROPAGATE;
}

static enum smf_state_result mmi_idle_run(void *obj)
{
	switch (mmi_ctx.evt) {
	case MMI_OP_RECONNING:
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_RECONNING]);
		break;
	case MMI_OP_PAIRING:
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_PAIRING]);
		break;
	case MMI_OP_DISCONNED:
		mmi_s_disconnected();
		break;
#ifdef CONFIG_RC_PDM_DEBUG
	case MMI_OP_OPEN_MIC:
		LOG_INF("DBG: MMI_OP_OPEN_MIC");
		/* Debug: start PDM streaming without BLE */
		streaming_from_idle = true;
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_STREAMING]);
		break;
#endif
	default:
		break;
	}
	return SMF_EVENT_PROPAGATE;
}

static enum smf_state_result mmi_reconning_run(void *obj)
{
	switch (mmi_ctx.evt) {
	case MMI_OP_CONNECTED:
		mmi_s_connected();
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_CONNECTED]);
		break;
	case MMI_OP_RECONN_FAIL:
		mmi_s_reconnecting_fail();
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_IDLE]);
		break;
	case MMI_OP_ADV_STOPPED:
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_IDLE]);
		break;
#ifdef CONFIG_RC_PDM_DEBUG
	case MMI_OP_OPEN_MIC:
		streaming_from_idle = true;
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_STREAMING]);
		break;
#endif
	default:
		break;
	}
	return SMF_EVENT_PROPAGATE;
}

static enum smf_state_result mmi_pairing_run(void *obj)
{
	switch (mmi_ctx.evt) {
	case MMI_OP_CONNECTED:
		/* Stay in PAIRING — wait for PAIR_SUCCESS/PAIR_FAIL */
		break;
	case MMI_OP_PAIR_SUCCESS:
		mmi_s_pairing_success_stopped();
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_CONNECTED]);
		break;
	case MMI_OP_PAIR_FAIL:
		mmi_s_pairing_auth_failed();
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_CONNECTED]);
		break;
	case MMI_OP_PAIR_FAIL_ADV_TOUT:
		mmi_s_pairing_adv_timeout();
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_IDLE]);
		break;
	case MMI_OP_ADV_STOPPED:
		mmi_s_pairing_adv_stopped();
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_IDLE]);
		break;
	case MMI_OP_DISCONNED:
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_IDLE]);
		mmi_s_disc_restart();
		break;
#ifdef CONFIG_RC_PDM_DEBUG
	case MMI_OP_OPEN_MIC:
		streaming_from_idle = true;
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_STREAMING]);
		break;
#endif
	default:
		break;
	}
	return SMF_EVENT_PROPAGATE;
}

static enum smf_state_result mmi_connected_run(void *obj)
{
	switch (mmi_ctx.evt) {
	case MMI_OP_PAIR_SUCCESS:
	case MMI_OP_PAIR_FAIL:
		/* Stay in CONNECTED — no action */
		break;
	case MMI_OP_HID_READY:
		mmi_s_hid_ready();
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_HID_READY]);
		break;
	case MMI_OP_DISCONNED:
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_IDLE]);
		mmi_s_disc_restart();
		break;
	case MMI_OP_DISCONNING:
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_DISCONNING]);
		break;
#ifdef CONFIG_RC_PDM_DEBUG
	case MMI_OP_OPEN_MIC:
		streaming_from_idle = true;
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_STREAMING]);
		break;
#endif
	default:
		break;
	}
	return SMF_EVENT_PROPAGATE;
}

static enum smf_state_result mmi_hid_ready_run(void *obj)
{
	switch (mmi_ctx.evt) {
	case MMI_OP_HID_READY:
	case MMI_OP_ATVV_READY:
		/* Self-transition — no action */
		break;
	case MMI_OP_HID_UNREADY:
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_CONNECTED]);
		break;
	case MMI_OP_OPEN_MIC:
#ifdef CONFIG_RC_PDM_DEBUG
		streaming_from_idle = true;
#endif
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_STREAMING]);
		break;
	case MMI_OP_DISCONNING:
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_DISCONNING]);
		break;
	case MMI_OP_DISCONNED:
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_IDLE]);
		mmi_s_disc_restart();
		break;
	default:
		break;
	}
	return SMF_EVENT_PROPAGATE;
}

static enum smf_state_result mmi_streaming_run(void *obj)
{
	switch (mmi_ctx.evt) {
	case MMI_OP_CLOSE_MIC:
	case MMI_OP_ATVV_UNREADY:
		mmi_s_streaming_stopped();
		smf_set_state(SMF_CTX(&mmi_ctx),
#ifdef CONFIG_RC_PDM_DEBUG
			      streaming_from_idle ? &mmi_states[MMI_S_IDLE] :
#endif
						  &mmi_states[MMI_S_HID_READY]);
		break;
	case MMI_OP_DISCONNED:
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_IDLE]);
		mmi_s_disc_restart();
		break;
	case MMI_OP_DISCONNING:
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_DISCONNING]);
		break;
	default:
		break;
	}
	return SMF_EVENT_PROPAGATE;
}

static enum smf_state_result mmi_discing_run(void *obj)
{
	switch (mmi_ctx.evt) {
	case MMI_OP_DISCONNED:
		smf_set_state(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_IDLE]);
		mmi_s_disc_restart();
		break;
	default:
		break;
	}
	return SMF_EVENT_PROPAGATE;
}

static enum smf_state_result mmi_rf_test_run(void *obj)
{
	/* RF_TEST + DISCONNED → RF_TEST (self, no state change) */
	return SMF_EVENT_PROPAGATE;
}

/* SMF state table. */

static const struct smf_state mmi_states[MMI_S_NUM] = {
	[MMI_S_BOOTED] = SMF_CREATE_STATE(mmi_booted_entry, mmi_booted_run, NULL, NULL, NULL),
	[MMI_S_INITING] = SMF_CREATE_STATE(mmi_initing_entry, mmi_initing_run, NULL, NULL, NULL),
	[MMI_S_IDLE] = SMF_CREATE_STATE(mmi_idle_entry, mmi_idle_run, NULL, NULL, NULL),
	[MMI_S_PAIRING] = SMF_CREATE_STATE(mmi_pairing_entry, mmi_pairing_run, NULL, NULL, NULL),
	[MMI_S_RECONNING] =
		SMF_CREATE_STATE(mmi_reconning_entry, mmi_reconning_run, NULL, NULL, NULL),
	[MMI_S_CONNECTED] =
		SMF_CREATE_STATE(mmi_connected_entry, mmi_connected_run, NULL, NULL, NULL),
	[MMI_S_HID_READY] =
		SMF_CREATE_STATE(mmi_hid_ready_entry, mmi_hid_ready_run, NULL, NULL, NULL),
	[MMI_S_STREAMING] =
		SMF_CREATE_STATE(mmi_streaming_entry, mmi_streaming_run, NULL, NULL, NULL),
	[MMI_S_DISCONNING] = SMF_CREATE_STATE(mmi_discing_entry, mmi_discing_run, NULL, NULL, NULL),
	[MMI_S_RF_TEST] = SMF_CREATE_STATE(mmi_rf_test_entry, mmi_rf_test_run, NULL, NULL, NULL),
};

void rc_mmi_init(void)
{
	smf_set_initial(SMF_CTX(&mmi_ctx), &mmi_states[MMI_S_BOOTED]);
	rc_mmi_run_event(MMI_OP_INITING);
}
