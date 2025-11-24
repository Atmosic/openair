/**
 *******************************************************************************
 *
 * @file platform_ctrl_led.h
 *
 * @brief Platform control led For Multimode Consumer Tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#include "platform_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/// LED state
typedef enum {
	LED_STATE_PAIRING,
	LED_STATE_PAIRED,
	LED_STATE_OTA_MODE,
	LED_STATE_POWER_OFF,
} led_state_t;

/// LED evt
typedef enum {
	LED_EVT_POWER_ON,
	LED_EVT_BATT_FULL,
	LED_EVT_BATT_HIGH,
	LED_EVT_BATT_MEDIUM,
	LED_EVT_BATT_LOW,
	LED_EVT_BATT_CRITICAL,
	LED_EVT_POWER_OFF,
	LED_EVT_FACTORY_RESET,
} led_event_t;

/**
 * @brief Platform control led update
 * @param[in] state led state
 */
void platform_ctrl_led_state_update(led_state_t state);

/**
 * @brief Platform control led update
 * @param[in] event led event
 */
void platform_ctrl_led_event_indicate(led_event_t event);

#ifdef __cplusplus
}
#endif

///@}
