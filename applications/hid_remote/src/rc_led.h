/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

/** @brief LED operating modes. */
enum rc_led_mode {
	RC_LED_OFF,          /**< LED off (connected / idle / stopped) */
	RC_LED_ON,           /**< LED solid on (combo key hold indication) */
	RC_LED_PAIRING,      /**< 100 ms blink — pairing advertising */
	RC_LED_RECONNECTING, /**< 250 ms blink — reconnect advertising */
	RC_LED_FMP_MILD,     /**< 500 ms blink — FMP mild alert */
	RC_LED_FMP_HIGH,     /**< 125 ms blink — FMP high alert */
};

/** @brief Initialise the LED GPIO and blink work queue item. */
void rc_led_init(void);

/**
 * @brief Set the LED to the given mode.
 * @param mode One of the @ref rc_led_mode values.
 */
void rc_led_set(enum rc_led_mode mode);
