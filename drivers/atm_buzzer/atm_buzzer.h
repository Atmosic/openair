/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include "arch.h"
#include <zephyr/kernel.h>
#include <zephyr/drivers/pwm.h>

/**
 * @defgroup ATM_BUZZER
 * @ingroup DRIVERS
 * @brief Atmosic Pulse-Width Modulation Buzzer module
 *
 * This module implements to control buzzer by PWM signal.
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	BUZ_NO_ERROR,
	BUZ_PARAM_INCORRECT,
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
 * @brief ATM buzzer configuration
 */
typedef struct atm_buzzer_s {
	/** PWM device, channel, flags */
	struct pwm_dt_spec pwm_dt;
	/** Default pulse width (in usec or nsec depending on driver) */
	uint32_t pulse;
	/** Max frequency supported by this buzzer */
	uint32_t max_frequency;
	/** Min frequency supported by this buzzer */
	uint32_t min_frequency;
#ifdef CONFIG_ATM_BUZZER_TIMEOUT
	/** Internal delayed work for auto-stop */
	struct k_work_delayable stop_work;
	/** Timer expire callback function */
	void (*stop_cb)(struct atm_buzzer_s *buzzer);
	/** User data for the callback function */
	void *context;
#endif
	/** Status flag */
	bool active;
} atm_buzzer_t;

/**
 * @brief Buzzer on/off
 *
 * @param[in] buzzer atm buzzer configuration
 * @param[in] action_on true for buzzer on, otherwise buzzer off
 * @return 0 on success, non-zero on failure.
 */
atm_buzzer_error_t atm_buzzer_onoff(atm_buzzer_t *buzzer, bool action_on);


/**
 * @brief Buzzer configuration without play
 *
 * @param[in] buzzer atm buzzer configuration
 * @param[in] freq_hz specific frequency, unit: hz
 * @param[in] duty_cycle pwm signal high percentage
 * @return 0 on success, non-zero on failure.
 */
atm_buzzer_error_t atm_buzzer_configure(atm_buzzer_t *buzzer, uint32_t freq_hz, uint32_t duty_cycle);

/**
 * @brief Buzzer play tone till buzzer off
 *
 * @param[in] buzzer atm buzzer configuration
 * @param[in] freq_hz specific frequency, unit: hz
 * @param[in] duty_cycle pwm signal high percentage
 * @return 0 on success, non-zero on failure.
 */
atm_buzzer_error_t atm_buzzer_beep(atm_buzzer_t *buzzer, uint32_t freq_hz, uint32_t duty_cycle);

#ifdef CONFIG_ATM_BUZZER_TIMEOUT
/**
 * @brief Buzzer play tone till buzzer off
 *
 * @param[in] buzzer atm buzzer configuration
 * @param[in] freq_hz specific frequency, unit: hz
 * @param[in] duty_cycle pwm signal high percentage
 * @param[in] duration_ms duration in milliseconds to play the tone
 * @return 0 on success, non-zero on failure.
 */
atm_buzzer_error_t atm_buzzer_beep_time(atm_buzzer_t *buzzer, uint32_t freq_hz, uint8_t duty_percent, uint32_t duration_ms);

/**
 * @brief Register a callback function to be called when the buzzer stops
 *
 * This function registers a callback function that will be invoked when the buzzer stops.
 *
 * @param[in] buzzer atm buzzer configuration
 * @return 0 on success, non-zero on failure.
 */
atm_buzzer_error_t atm_buzzer_cb_reg(atm_buzzer_t *buzzer);
#endif

#ifdef __cplusplus
}
#endif

/// @} ATM_BUZZER
