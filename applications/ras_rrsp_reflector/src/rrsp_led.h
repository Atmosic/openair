/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum rrsp_led_pattern_idx_e {
	RRSP_LED_PAT_EVT_PWRON,
	RRSP_LED_PAT_EVT_PWROFF,
	RRSP_LED_PAT_EVT_BAT_LVL,
	RRSP_LED_PAT_EVT_BAT5 = RRSP_LED_PAT_EVT_BAT_LVL,
	RRSP_LED_PAT_EVT_BAT4,
	RRSP_LED_PAT_EVT_BAT3,
	RRSP_LED_PAT_EVT_BAT2,
	RRSP_LED_PAT_EVT_BAT1,
	RRSP_LED_PAT_MODE,
	RRSP_LED_PAT_MODE_PAIR = RRSP_LED_PAT_MODE,
	RRSP_LED_PAT_MODE_OPR,
	RRSP_LED_PAT_MODE_CS,

	RRSP_LED_PAT_MAX,
	RRSP_LED_PAT_INVALID = 0xFF,
} rrsp_led_pattern_idx_t;

/**
 * @brief Update LED with specific pattern
 * @param[in] pattern led pattern
 * @param[in] enable enable or cancel
 */
void rrsp_led_update(rrsp_led_pattern_idx_t pattern, bool enable);

#ifdef CONFIG_LED
/**
 * @brief Update LED with specific pattern
 *
 * This function cancels the work for background led (pattern for mode)
 */
void rrsp_led_cancel_all_bg(void);
#endif

#ifdef __cplusplus
}
#endif

///@}
