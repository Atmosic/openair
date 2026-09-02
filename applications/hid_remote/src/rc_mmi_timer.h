/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <zephyr/kernel.h>

/** @brief Callback type for MMI timer expiry. */
typedef void (*mmi_timer_cb_t)(void);

/**
 * @brief Register handlers for the MMI timers.
 *
 * @param fn_idle       Handler for the idle timer.
 * @param fn_hib        Handler for the hibernate timer.
 * @param fn_slave_lat  Handler for the slave latency timer.
 */
void rc_mmi_timer_init(mmi_timer_cb_t fn_idle, mmi_timer_cb_t fn_hib);

/**
 * @brief Set the idle timer.
 *
 * @param centisec  Timeout value in centiseconds.
 */
void rc_mmi_timer_idle_set(uint32_t centisec);

/**
 * @brief Clear the idle timer.
 */
void rc_mmi_timer_idle_clear(void);

/**
 * @brief Set the hibernate timer.
 *
 * @param centisec  Timeout value in centiseconds.
 */
void rc_mmi_timer_hib_set(uint32_t centisec);

/**
 * @brief Clear the hibernate timer.
 */
void rc_mmi_timer_hib_clear(void);

/**
 * @brief Clear all MMI timers.
 */
void rc_mmi_timer_clear_all(void);
