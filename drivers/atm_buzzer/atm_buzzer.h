/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>

/**
 * @defgroup ATM_BUZZER
 * @ingroup DRIVERS
 * @brief Atmosic Pulse-Width Modulation Buzzer module
 *
 * This module implements to control buzzer by PWM signal.
 * This is a Zephyr device driver - instances are defined in devicetree.
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	BUZ_NO_ERROR = 0,
	BUZ_PARAM_INCORRECT = -EINVAL,
} atm_buzzer_error_t;

/**
 * @brief Note frequencies in Hz
 *
 * This enum defines the frequencies of musical notes in the standard Western tuning system.
 * The frequencies are based on the A4 note being 440 Hz.
 */
typedef enum {
	// C3 (Octave 3)
	NOTE_C3 = 131,      // C3
	NOTE_CS3 = 139,     // C#3 / Db3
	NOTE_D3 = 147,      // D3
	NOTE_DS3 = 156,     // D#3 / Eb3
	NOTE_E3 = 165,      // E3
	NOTE_F3 = 175,      // F3
	NOTE_FS3 = 185,     // F#3 / Gb3
	NOTE_G3 = 196,      // G3
	NOTE_GS3 = 208,     // G#3 / Ab3
	NOTE_A3 = 220,      // A3
	NOTE_AS3 = 233,     // A#3 / Bb3
	NOTE_B3 = 247,      // B3
	// C4 (Octave 4 - Middle C)
	NOTE_C4 = 262,      // C4 (Middle C)
	NOTE_CS4 = 277,     // C#4 / Db4
	NOTE_D4 = 294,      // D4
	NOTE_DS4 = 311,     // D#4 / Eb4
	NOTE_E4 = 330,      // E4
	NOTE_F4 = 349,      // F4
	NOTE_FS4 = 370,     // F#4 / Gb4
	NOTE_G4 = 392,      // G4
	NOTE_GS4 = 415,     // G#4 / Ab4
	NOTE_A4 = 440,      // A4 (Standard Pitch A)
	NOTE_AS4 = 466,     // A#4 / Bb4
	NOTE_B4 = 494,      // B4
	// C5 (Octave 5)
	NOTE_C5 = 523,      // C5
	NOTE_CS5 = 554,     // C#5 / Db5
	NOTE_D5 = 587,      // D5
	NOTE_DS5 = 622,     // D#5 / Eb5
	NOTE_E5 = 659,      // E5
	NOTE_F5 = 698,      // F5
	NOTE_FS5 = 740,     // F#5 / Gb5
	NOTE_G5 = 784,      // G5
	NOTE_GS5 = 831,     // G#5 / Ab5
	NOTE_A5 = 880,      // A5
	NOTE_AS5 = 932,     // A#5 / Bb5
	NOTE_B5 = 988,      // B5
	// C6 (Octave 6)
	NOTE_C6 = 1047,     // C6
	NOTE_CS6 = 1109,    // C#6 / Db6
	NOTE_D6 = 1175,     // D6
	NOTE_DS6 = 1245,    // D#6 / Eb6
	NOTE_E6 = 1319,     // E6
	NOTE_F6 = 1397,     // F6
	NOTE_FS6 = 1480,    // F#6 / Gb6
	NOTE_G6 = 1568,     // G6
	NOTE_GS6 = 1661,    // G#6 / Ab6
	NOTE_A6 = 1760,     // A6
	NOTE_AS6 = 1865,    // A#6 / Bb6
	NOTE_B6 = 1976,     // B6

	// C7 (Octave 7 - Depending on the buzzer's performance, this octave might be difficult to produce clearly.)
	NOTE_C7 = 2093,     // C7
	NOTE_CS7 = 2217,    // C#7 / Db7
	NOTE_D7 = 2349,     // D7
	NOTE_DS7 = 2489,    // D#7 / Eb7
	NOTE_E7 = 2637,     // E7
	NOTE_F7 = 2794,     // F7
	NOTE_FS7 = 2960,    // F#7 / Gb7
	NOTE_G7 = 3136,     // G7
	NOTE_GS7 = 3322,    // G#7 / Ab7
	NOTE_A7 = 3520,     // A7
	NOTE_AS7 = 3729,    // A#7 / Bb7
	NOTE_B7 = 3951,     // B7
} note_freq_t;

/**
 * @brief Callback function type for buzzer stop event
 *
 * @param dev Pointer to the buzzer device
 */
typedef void (*atm_buzzer_stop_cb_t)(const struct device *dev);

/**
 * @brief ATM buzzer driver API
 *
 * This is the API structure that upper layers use to interact with the buzzer.
 */
__subsystem struct atm_buzzer_api {
	/**
	 * @brief Turn buzzer on or off
	 *
	 * @param dev Pointer to the buzzer device
	 * @param action_on true to turn on, false to turn off
	 * @return 0 on success, negative errno on failure
	 */
	atm_buzzer_error_t (*onoff)(const struct device *dev, bool action_on);

	/**
	 * @brief Configure buzzer frequency and duty cycle without playing
	 *
	 * @param dev Pointer to the buzzer device
	 * @param freq_hz Frequency in Hz
	 * @param duty_percent Duty cycle percentage (0-100)
	 * @return 0 on success, negative errno on failure
	 */
	atm_buzzer_error_t (*configure)(const struct device *dev, uint32_t freq_hz,
					uint32_t duty_percent);

	/**
	 * @brief Play a tone continuously until turned off
	 *
	 * @param dev Pointer to the buzzer device
	 * @param freq_hz Frequency in Hz
	 * @param duty_percent Duty cycle percentage (0-100)
	 * @return 0 on success, negative errno on failure
	 */
	atm_buzzer_error_t (*beep)(const struct device *dev, uint32_t freq_hz,
				   uint32_t duty_percent);

#ifdef CONFIG_ATM_BUZZER_TIMEOUT
	/**
	 * @brief Play a tone for a specified duration
	 *
	 * @param dev Pointer to the buzzer device
	 * @param freq_hz Frequency in Hz
	 * @param duty_percent Duty cycle percentage (0-100)
	 * @param duration_ms Duration in milliseconds
	 * @return 0 on success, negative errno on failure
	 */
	atm_buzzer_error_t (*beep_time)(const struct device *dev, uint32_t freq_hz,
					uint8_t duty_percent, uint32_t duration_ms);

	/**
	 * @brief Set callback function for stop event
	 *
	 * @param dev Pointer to the buzzer device
	 * @param callback Callback function to be called when buzzer stops
	 * @return 0 on success, negative errno on failure
	 */
	int (*set_stop_callback)(const struct device *dev, atm_buzzer_stop_cb_t callback);
#endif
};

/**
 * @brief Turn buzzer on or off
 *
 * @param dev Pointer to the buzzer device
 * @param action_on true to turn on, false to turn off
 * @return 0 on success, negative errno on failure
 */
static inline atm_buzzer_error_t atm_buzzer_onoff(const struct device *dev, bool action_on)
{
	const struct atm_buzzer_api *api = (const struct atm_buzzer_api *)dev->api;

	if (!api || !api->onoff) {
		return BUZ_PARAM_INCORRECT;
	}

	return api->onoff(dev, action_on);
}

/**
 * @brief Configure buzzer frequency and duty cycle without playing
 *
 * @param dev Pointer to the buzzer device
 * @param freq_hz Frequency in Hz
 * @param duty_percent Duty cycle percentage (0-100)
 * @return 0 on success, negative errno on failure
 */
static inline atm_buzzer_error_t atm_buzzer_configure(const struct device *dev, uint32_t freq_hz,
						      uint32_t duty_percent)
{
	const struct atm_buzzer_api *api = (const struct atm_buzzer_api *)dev->api;

	if (!api || !api->configure) {
		return BUZ_PARAM_INCORRECT;
	}

	return api->configure(dev, freq_hz, duty_percent);
}

/**
 * @brief Play a tone continuously until turned off
 *
 * @param dev Pointer to the buzzer device
 * @param freq_hz Frequency in Hz
 * @param duty_percent Duty cycle percentage (0-100)
 * @return 0 on success, negative errno on failure
 */
static inline atm_buzzer_error_t atm_buzzer_beep(const struct device *dev, uint32_t freq_hz,
						 uint32_t duty_percent)
{
	const struct atm_buzzer_api *api = (const struct atm_buzzer_api *)dev->api;

	if (!api || !api->beep) {
		return BUZ_PARAM_INCORRECT;
	}

	return api->beep(dev, freq_hz, duty_percent);
}

#ifdef CONFIG_ATM_BUZZER_TIMEOUT
/**
 * @brief Play a tone for a specified duration
 *
 * @param dev Pointer to the buzzer device
 * @param freq_hz Frequency in Hz
 * @param duty_percent Duty cycle percentage (0-100)
 * @param duration_ms Duration in milliseconds
 * @return 0 on success, negative errno on failure
 */
static inline atm_buzzer_error_t atm_buzzer_beep_time(const struct device *dev, uint32_t freq_hz,
						      uint8_t duty_percent, uint32_t duration_ms)
{
	const struct atm_buzzer_api *api = (const struct atm_buzzer_api *)dev->api;

	if (!api || !api->beep_time) {
		return BUZ_PARAM_INCORRECT;
	}

	return api->beep_time(dev, freq_hz, duty_percent, duration_ms);
}

/**
 * @brief Set callback function for stop event
 *
 * @param dev Pointer to the buzzer device
 * @param callback Callback function to be called when buzzer stops
 * @return 0 on success, negative errno on failure
 */
static inline int atm_buzzer_set_stop_callback(const struct device *dev,
					       atm_buzzer_stop_cb_t callback)
{
	const struct atm_buzzer_api *api = (const struct atm_buzzer_api *)dev->api;

	if (!api || !api->set_stop_callback) {
		return -ENOTSUP;
	}

	return api->set_stop_callback(dev, callback);
}
#endif

#ifdef __cplusplus
}
#endif

/// @} ATM_BUZZER
