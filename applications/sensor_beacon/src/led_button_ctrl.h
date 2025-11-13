/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025 Atmosic
 */

#pragma once

#include <zephyr/kernel.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Device power states
 */
typedef enum {
	DEVICE_STATE_INIT,
	DEVICE_STATE_OFF, /**< Device is in SoC_off mode */
	DEVICE_STATE_ON,  /**< Device is on and beaconing */
} device_state_t;

/**
 * @brief LED indication types
 */
typedef enum {
	LED_IND_POWER_ON,      /* Green LED blinks 3 times at 0.5s interval */
	LED_IND_POWER_OFF,     /* Red LED blinks 3 times at 0.5s interval */
	LED_IND_BEACON_STATUS, /* Green LED blinks once for 0.1s */
} led_indication_t;

/**
 * @brief Button event callback function type
 *
 * @param pressed True if button is pressed, false if released
 * @param duration_ms Duration of button press in milliseconds
 */
typedef void (*button_event_cb_t)(bool pressed, uint32_t duration_ms);

/**
 * @brief Device state change callback function type
 *
 * @param new_state New device state
 */
typedef void (*device_state_cb_t)(device_state_t new_state);

/**
 * @brief Initialize LED and button control
 *
 * @return 0 on success, negative error code on failure
 */
int led_button_ctrl_init(void);

/**
 * @brief Register button event callback
 *
 * @param cb Callback function to be called on button events
 * @return 0 on success, negative error code on failure
 */
int led_button_ctrl_register_button_cb(button_event_cb_t cb);

/**
 * @brief Register device state change callback
 *
 * @param cb Callback function to be called on device state changes
 * @return 0 on success, negative error code on failure
 */
int led_button_ctrl_register_state_cb(device_state_cb_t cb);

/**
 * @brief Show LED indication
 *
 * @param indication Type of LED indication to show
 * @return 0 on success, negative error code on failure
 */
int led_button_ctrl_show_indication(led_indication_t indication);

/**
 * @brief Get current device state
 *
 * @return Current device state
 */
device_state_t led_button_ctrl_get_device_state(void);

/**
 * @brief Set device state (for EVK mode - immediate beaconing)
 *
 * @param state Device state to set
 */
void led_button_ctrl_set_device_state(device_state_t state);

/**
 * @brief Notify beacon transmission (for beacon status indication)
 *
 * This should be called every time a beacon is transmitted.
 * The module will automatically show LED indication every 10 beacons.
 *
 * @return 0 on success, negative error code on failure
 */
int led_button_ctrl_notify_beacon_tx(void);

#ifdef __cplusplus
}
#endif
