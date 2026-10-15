/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>

/** HIDS notification state */
typedef enum {
	RC_HIDS_SUSPEND, /* connected but CCC not yet enabled */
	RC_HIDS_READY,   /* CCC enabled — reports can be sent */
} rc_hids_state_t;

/** @brief Initialise the HOGP adapter and register state/LED callbacks. */
void rc_hids_init(void);

/** @brief Return the current HIDS notification state. */
rc_hids_state_t rc_hids_get_state(void);

/** @brief Send a keyboard key event (row/col → HID keycode lookup).
 * @param row     Matrix row (0-based).
 * @param col     Matrix column (0-based).
 * @param pressed True for key press, false for key release.
 */
void rc_hogp_send_key_report(uint32_t row, uint32_t col, bool pressed);

/** @brief Send a consumer-control key event.
 * @param keycode Consumer key code (0 = no key).
 */
void rc_hogp_send_consumer_report(uint16_t keycode);

/** @brief Release all held keys. */
void rc_hogp_send_release_all(void);
