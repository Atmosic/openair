/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Callback to restore the LED to the current MMI-state-appropriate mode.
 *
 * Provided by rc_mmi.c and called by the combo engine when a combo is
 * cancelled so the LED reverts to whatever the state machine dictates.
 */
typedef void (*rc_input_led_restore_cb_t)(void);

/**
 * @brief Initialise the input/combo subsystem.
 *
 * Must be called once after rc_led_init().
 * The INPUT_CALLBACK_DEFINE listener is registered at build time; this call
 * only initialises the combo work items.
 *
 * @param led_restore_cb  Callback invoked when an active combo is cancelled.
 */
void rc_input_init(rc_input_led_restore_cb_t led_restore_cb);

/**
 * @brief Dispatch a decoded key event into the input pipeline.
 *
 * Handles IR, combo detection, PM locks, key buffering, and HID reports.
 * Called from the INPUT_CALLBACK_DEFINE listener inside rc_input.c.
 * Also exposed so rc_mmi.c can replay buffered keys on reconnect without
 * duplicating the HID send logic.
 *
 * @param row      Matrix row of the key.
 * @param col      Matrix column of the key.
 * @param pressed  true = pressed, false = released.
 */
void rc_input_handle_key(uint32_t row, uint32_t col, bool pressed);

/**
 * @brief Flush buffered key events accumulated before HID was ready.
 *
 * Called by rc_mmi.c when transitioning to MMI_S_HID_READY.
 */
void rc_input_flush_keybuf(void);

/**
 * @brief Return true if any buffered keys are pending.
 */
bool rc_input_keybuf_pending(void);

/**
 * @brief Update the "state reconnected" flag used when flushing the keybuf.
 *
 * Set to true on CONNECTED, cleared after flush.
 */
void rc_input_set_reconnected(bool reconnected);
