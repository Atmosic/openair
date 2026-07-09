/**
 *******************************************************************************
 *
 * @file dult_ut.h
 *
 * @brief DULT Unwanted Tracking (UT) state machine — internal interface
 *
 * Copyright (C) Atmosic 2026
 *
 *******************************************************************************
 */

#pragma once

/**
 * @brief Internal interface between dult.c and dult_ut.c.
 *
 * Not part of the public DULT API — do not include outside the dult subsystem.
 */

#ifdef CONFIG_DULT_MOTION_DETECT

#include "dult.h"

/**
 * @brief Supply the registered handler table to the UT state machine.
 *
 * Must be called from dult_handlers_register() whenever a new handler table
 * is registered so the UT state machine can reach sound_action_cb,
 * motion_hw_enable_cb, and motion_raw_get_cb.
 *
 * @param hdlrs  Handler table registered by the application.
 */
void dult_ut_set_hdlrs(dult_hdlrs_t const *hdlrs);

/**
 * @brief Cancel all UT timers and disable the motion detector.
 *
 * Called by dult.c on deinit, near-owner mode, and before re-entering
 * separated mode.  Safe to call when UT is already idle.
 */
void dult_ut_reset(void);

/**
 * @brief Begin a new UT separated period.
 *
 * Resets existing UT state and arms the 8–24 h random timeout before motion
 * detection is enabled.  Called when the device enters separated mode.
 */
void dult_ut_enter_separated(void);

/**
 * @brief Query whether a GATT-initiated sound is currently playing.
 *
 * Implemented in dult.c; called by dult_ut.c to avoid starting a
 * motion-alert sound while a non-owner GATT sound is already active.
 *
 * @return true if the GATT sound play timer is running.
 */
bool dult_is_gatt_sound_active(void);

/**
 * @brief Query whether the device is currently in separated (near-owner absent) state.
 *
 * Implemented in dult.c; called by dult_ut.c to satisfy the spec requirement
 * that UT behavior MUST restart after T_(SEPARATED_UT_BACKOFF) only if the
 * accessory is still in separated state.
 *
 * @return true if the current mode is DULT_NO_MODE_SEPERATED.
 */
bool dult_is_separated(void);

#endif /* CONFIG_DULT_MOTION_DETECT */
