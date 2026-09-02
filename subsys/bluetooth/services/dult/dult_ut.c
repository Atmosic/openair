/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/**
 *******************************************************************************
 *
 * @file dult_ut.c
 *
 * @brief DULT Unwanted Tracking (UT) state machine
 *
 *******************************************************************************
 */

#include <inttypes.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/random/random.h>
#include "app_work_q.h"
#include "dult_ut.h"

LOG_MODULE_DECLARE(dult, CONFIG_ATM_DULT_LOG_LEVEL);

/* UT timing constants */
#define DULT_UT_TIMEOUT_MIN_SEC   (8U * 3600U)  /* min wait before motion detect starts */
#define DULT_UT_TIMEOUT_MAX_SEC   (24U * 3600U) /* max wait before motion detect starts */
#define DULT_UT_BACKOFF_SEC       (6U * 3600U)  /* motion detector cooldown after alert limit */
#define DULT_UT_SOUND_DUR_MS      CONFIG_DULT_MOTION_DETECT_SOUND_DURATION_MS
#define DULT_UT_MAX_SOUNDS        10U           /* sounds allowed before entering backoff */
#define DULT_UT_MAX_MOTION_MS     (20U * 1000U) /* continuous motion limit before backoff */
#define DULT_MOTION_POLL_RATE1_MS (10U * 1000U) /* slow poll rate (no motion detected) */
#define DULT_MOTION_POLL_RATE2_MS 500U          /* fast poll rate (motion in progress) */
#define DULT_MOTION_THR_DEG       10U           /* orientation change threshold in degrees */

static dult_hdlrs_t const *dult_ut_hdlrs;

static bool dult_ut_detecting;
static uint8_t dult_ut_sound_count;
static bool dult_motion_fast_phase;

static void dult_ut_detect_start_handler(struct k_work *work);
static void dult_ut_backoff_handler(struct k_work *work);
static void dult_ut_fast_phase_handler(struct k_work *work);
static void dult_ut_motion_notify_handler(struct k_work *work);
static void dult_ut_motion_snd_stop_handler(struct k_work *work);
#ifndef CONFIG_DULT_MOTION_DETECT_TRIGGER
static void dult_motion_poll_handler(struct k_work *work);
#endif
/* detect_start_timer: initial wait before motion detection begins.
 * backoff_timer:      cooldown period; restarts full UT cycle if still separated.
 * fast_phase_timer:   fast-phase 20s duration limit — arms on first detected
 *                     motion in both poll and trigger modes.  On expiry the
 *                     detector backs off for DULT_UT_BACKOFF_SEC.
 * poll_work:          periodic motion sample work (poll mode only). */
K_WORK_DELAYABLE_DEFINE(dult_ut_detect_start_timer, dult_ut_detect_start_handler);
K_WORK_DELAYABLE_DEFINE(dult_ut_backoff_timer, dult_ut_backoff_handler);
K_WORK_DELAYABLE_DEFINE(dult_ut_fast_phase_timer, dult_ut_fast_phase_handler);
K_WORK_DELAYABLE_DEFINE(dult_ut_motion_snd_timer, dult_ut_motion_snd_stop_handler);
K_WORK_DEFINE(dult_ut_motion_notify_work, dult_ut_motion_notify_handler);
#ifndef CONFIG_DULT_MOTION_DETECT_TRIGGER
K_WORK_DELAYABLE_DEFINE(dult_motion_poll_work, dult_motion_poll_handler);
#endif

static uint32_t dult_ut_random_timeout_sec(void)
{
	uint32_t range = DULT_UT_TIMEOUT_MAX_SEC - DULT_UT_TIMEOUT_MIN_SEC;

	return DULT_UT_TIMEOUT_MIN_SEC + (sys_rand32_get() % range);
}

static void dult_ut_motion_disable(void)
{
	k_work_cancel_delayable(&dult_ut_fast_phase_timer);
	dult_motion_fast_phase = false;
#ifndef CONFIG_DULT_MOTION_DETECT_TRIGGER
	k_work_cancel_delayable(&dult_motion_poll_work);
#endif
	if (dult_ut_hdlrs && dult_ut_hdlrs->motion_hw_enable_cb) {
		dult_ut_hdlrs->motion_hw_enable_cb(false);
	}
}

static void dult_motion_start(void)
{
	dult_motion_fast_phase = false;
	if (dult_ut_hdlrs && dult_ut_hdlrs->motion_hw_enable_cb) {
		dult_ut_hdlrs->motion_hw_enable_cb(true);
	}
#ifndef CONFIG_DULT_MOTION_DETECT_TRIGGER
	if (dult_ut_hdlrs && dult_ut_hdlrs->motion_raw_get_cb) {
		atm_work_reschedule_for_app_work_q(&dult_motion_poll_work,
						   K_MSEC(DULT_MOTION_POLL_RATE1_MS));
	}
#endif
}

#ifndef CONFIG_DULT_MOTION_DETECT_TRIGGER
static void dult_motion_poll_handler(struct k_work *work)
{
	ARG_UNUSED(work);
	if (!dult_ut_hdlrs || !dult_ut_hdlrs->motion_raw_get_cb) {
		return;
	}
	uint8_t raw = dult_ut_hdlrs->motion_raw_get_cb();

	if (raw >= DULT_MOTION_THR_DEG) {
		/* Fast-phase timer + flag are armed inside dult_ut_motion_notify_handler
		 * so the 20s backoff cap is shared with trigger mode. */
		atm_work_submit_to_app_work_q(&dult_ut_motion_notify_work);
	}
	uint32_t poll_ms =
		dult_motion_fast_phase ? DULT_MOTION_POLL_RATE2_MS : DULT_MOTION_POLL_RATE1_MS;

	atm_work_reschedule_for_app_work_q(&dult_motion_poll_work, K_MSEC(poll_ms));
}
#endif /* CONFIG_DULT_MOTION_DETECT_TRIGGER */

static void dult_ut_enter_backoff(const char *reason)
{
	LOG_INF("UT: entering backoff (%s sounds=%" PRIu8 " timeout=%u sec)", reason,
		dult_ut_sound_count, DULT_UT_BACKOFF_SEC);
	dult_ut_detecting = false;
	dult_ut_motion_disable();
	atm_work_reschedule_for_app_work_q(&dult_ut_backoff_timer, K_SECONDS(DULT_UT_BACKOFF_SEC));
}

static void dult_ut_fast_phase_handler(struct k_work *work)
{
	ARG_UNUSED(work);
	/* Fast-phase 20s duration limit expired — enter backoff. */
	if (!dult_ut_detecting) {
		return;
	}
	LOG_INF("UT: 20s fast phase timeout expired");
	dult_ut_enter_backoff("20s timeout");
}

static void dult_ut_motion_snd_stop_handler(struct k_work *work)
{
	ARG_UNUSED(work);
	if (dult_ut_hdlrs && dult_ut_hdlrs->sound_action_cb) {
		dult_ut_hdlrs->sound_action_cb(false);
	}
	/* Enter backoff if sound limit reached. */
	LOG_DBG("UT: snd stop count=%" PRIu8 " max=%u", dult_ut_sound_count, DULT_UT_MAX_SOUNDS);
	if (dult_ut_sound_count >= DULT_UT_MAX_SOUNDS) {
		dult_ut_enter_backoff("10 sounds");
	}
}

static void dult_ut_detect_start_handler(struct k_work *work)
{
	ARG_UNUSED(work);
	if (!dult_is_separated()) {
		LOG_WRN("UT: detect start skipped — no longer separated");
		return;
	}
	LOG_INF("UT: enabling motion detector");
	dult_ut_sound_count = 0;
	dult_ut_detecting = true;
	dult_motion_start();
}

static void dult_ut_backoff_handler(struct k_work *work)
{
	ARG_UNUSED(work);
	/* Restart the full UT cycle if still separated, otherwise stop. */
	if (!dult_is_separated()) {
		LOG_DBG("UT: backoff ended — no longer separated, not restarting");
		return;
	}
	LOG_INF("UT: backoff ended, restarting UT cycle");
	dult_ut_enter_separated();
}

static void dult_ut_motion_notify_handler(struct k_work *work)
{
	ARG_UNUSED(work);
	if (!dult_ut_detecting) {
		LOG_DBG("UT: motion ignored (detector not active)");
		return;
	}
	if (dult_is_gatt_sound_active()) {
		LOG_WRN("UT: motion sound suppressed (GATT sound active)");
		return;
	}
	if (!dult_ut_hdlrs || !dult_ut_hdlrs->sound_action_cb) {
		return;
	}
	/* Arm the 20s fast-phase duration limit on the first detected motion.
	 * Applies to both poll and trigger modes — the timer forces a backoff
	 * (DULT_UT_BACKOFF_SEC) after 20s of continuous motion regardless of how
	 * motion events are delivered.  Rescheduled (not scheduled) so it is reset
	 * only on the very first event of a detecting period; subsequent events
	 * within the 20s window keep it running. */
	if (!dult_motion_fast_phase) {
		LOG_INF("UT: entering fast phase, 20s timer armed");
		dult_motion_fast_phase = true;
		atm_work_reschedule_for_app_work_q(&dult_ut_fast_phase_timer,
						   K_MSEC(DULT_UT_MAX_MOTION_MS));
	}
	dult_ut_sound_count++;
	LOG_INF("UT: playing motion sound (count=%" PRIu8 ")", dult_ut_sound_count);
	dult_ut_hdlrs->sound_action_cb(true);
	/* Use schedule (not reschedule): each sound gets its own configured window.
	 * The stop handler checks backoff conditions when the sound ends.        */
	atm_work_schedule_for_app_work_q(&dult_ut_motion_snd_timer, K_MSEC(DULT_UT_SOUND_DUR_MS));
}

/* ── Public interface ──────────────────────────────────────────────────── */

#ifdef CONFIG_DULT_MOTION_DETECT_TRIGGER
void dult_ut_motion_event(void)
{
	atm_work_submit_to_app_work_q(&dult_ut_motion_notify_work);
}
#endif /* CONFIG_DULT_MOTION_DETECT_TRIGGER */

void dult_ut_set_hdlrs(dult_hdlrs_t const *hdlrs)
{
	dult_ut_hdlrs = hdlrs;
}

void dult_ut_reset(void)
{
	LOG_DBG("UT: reset (detecting=%d sounds=%" PRIu8 " fast=%d)", dult_ut_detecting,
		dult_ut_sound_count, dult_motion_fast_phase);
	k_work_cancel_delayable(&dult_ut_detect_start_timer);
	k_work_cancel_delayable(&dult_ut_backoff_timer);
	k_work_cancel_delayable(&dult_ut_fast_phase_timer);
	/* Cancel the stop timer and immediately stop the sound.  Without this,
	 * a sound started by the notify handler would keep playing after reset
	 * because the stop timer (the only caller of sound_action_cb(false))
	 * is cancelled before it can fire.                                    */
	if (k_work_cancel_delayable(&dult_ut_motion_snd_timer) && dult_ut_hdlrs &&
	    dult_ut_hdlrs->sound_action_cb) {
		dult_ut_hdlrs->sound_action_cb(false);
	}
	k_work_cancel(&dult_ut_motion_notify_work);
	dult_ut_detecting = false;
	dult_ut_sound_count = 0;
	dult_ut_motion_disable();
}

void dult_ut_enter_separated(void)
{
	dult_ut_reset();
	uint32_t timeout_sec = dult_ut_random_timeout_sec();

	LOG_INF("UT: starting %" PRIu32 "s separated timeout before motion detect", timeout_sec);
	atm_work_reschedule_for_app_work_q(&dult_ut_detect_start_timer, K_SECONDS(timeout_sec));
}

#ifdef CONFIG_ZTEST
/* Test hooks: expose internal work handlers for unit test coverage */

#ifndef CONFIG_DULT_MOTION_DETECT_TRIGGER
void dult_test_motion_poll_handler(void)
{
	dult_motion_poll_handler(NULL);
}
#endif /* !CONFIG_DULT_MOTION_DETECT_TRIGGER */

void dult_test_ut_fast_phase_handler(void)
{
	dult_ut_fast_phase_handler(NULL);
}

void dult_test_ut_motion_snd_stop_handler(void)
{
	dult_ut_motion_snd_stop_handler(NULL);
}

void dult_test_ut_detect_start_handler(void)
{
	dult_ut_detect_start_handler(NULL);
}

void dult_test_ut_backoff_handler(void)
{
	dult_ut_backoff_handler(NULL);
}

void dult_test_ut_motion_notify_handler(void)
{
	dult_ut_motion_notify_handler(NULL);
}
#endif /* CONFIG_ZTEST */
