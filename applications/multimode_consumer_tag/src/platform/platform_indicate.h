/**
 *******************************************************************************
 *
 * @file platform_indicate.h
 *
 * @brief Platform tag indication for Multimode Consumer Tag
 *
 * Copyright (C) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#pragma once

#include "platform_ctrl_led.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Tag indication states
typedef enum {
	TAG_IND_STATE_BOOTED,    /**< Tag booted */
	TAG_IND_STATE_POWER_ON,  /**< Tag powered on */
	TAG_IND_STATE_POWER_OFF, /**< Tag powered off */
	TAG_IND_STATE_INIT_DONE, /**< Tag initialized, ready for pairing */
	TAG_IND_STATE_UNPAIRED,  /**< Tag unpaired */
	TAG_IND_STATE_PAIRING,   /**< Tag in pairing mode */
	TAG_IND_STATE_PAIRED,    /**< Tag successfully paired with host */
#ifdef CONFIG_TAG_OTA_MODE
	TAG_IND_STATE_OTA_IN_PROGRESS = 0x60, /**< OTA transfer in progress, advertising started */
	TAG_IND_STATE_OTA_COMPLETE,  /**< OTA transfer complete, pending image confirmation */
	TAG_IND_STATE_OTA_CONFIRMED, /**< OTA image confirmed, update complete */
#endif
	TAG_IND_STATE_INVALID = 0xFF, /**< Invalid state */
} tag_indication_state_t;

/**
 * @brief Indicate tag system state change
 *
 * @param[in] st System state from #tag_indication_state_t enum
 * @param[in] type Tag type mask
 */
void platform_indicate_state(tag_indication_state_t st, uint8_t type);

#if defined(CONFIG_TAG_BUZZER) || defined(CONFIG_AT_EVT_TAGBUZZER)

/**
 * @brief Buzzer event types for platform_indicate_buzzer()
 */
typedef enum {
	TAG_BUZZER_EVT_FACTORY_RESET, /**< Factory reset audio feedback (fixed tone) */
	TAG_BUZZER_EVT_POWER_OFF,     /**< Power-off sound effect (STF SOUND_ITEM_OFF) */
	TAG_BUZZER_EVT_GFP_RING_ON,   /**< GFP/FMDN ring start */
	TAG_BUZZER_EVT_GFP_RING_OFF,  /**< GFP/FMDN ring stop */
	TAG_BUZZER_EVT_FMNA_RING_ON,  /**< FMNA ring start */
	TAG_BUZZER_EVT_FMNA_RING_OFF, /**< FMNA ring stop */
	TAG_BUZZER_EVT_STF_SOUND_ON,  /**< TagSDK-internal sound started (ringtone/item) */
	TAG_BUZZER_EVT_STF_SOUND_OFF, /**< TagSDK-internal sound stopped */
} tag_buzzer_evt_t;

/**
 * @brief GFP ring parameters
 */
typedef struct {
	uint8_t ring_op;      /**< GFP ring operation (ATM_GFP_RING_OP_*) */
	uint8_t ring_vol;     /**< GFP ring volume level */
	uint16_t duration_ds; /**< Ring timeout in deciseconds */
} tag_gfp_ring_params_t;

/**
 * @brief STF sound parameters
 */
typedef struct {
	uint8_t volume; /**< Sound volume level (SoundVolume_t) */
} tag_stf_sound_params_t;

/**
 * @brief Centralized buzzer event handler
 *
 * Drives hardware buzzer (CONFIG_TAG_BUZZER) and/or sends +EVTTAGBUZZER AT
 * event (CONFIG_AT_EVT_TAGBUZZER) depending on configuration.
 *
 * @param[in] evt    Buzzer event from #tag_buzzer_evt_t
 * @param[in] params Event-specific parameters, or NULL:
 *                   - #TAG_BUZZER_EVT_GFP_RING_ON:  const #tag_gfp_ring_params_t *
 *                   - #TAG_BUZZER_EVT_STF_SOUND_ON: const #tag_stf_sound_params_t *
 *                   - all other events:              NULL
 */
void platform_indicate_buzzer(tag_buzzer_evt_t evt, const void *params);

#endif

#ifdef CONFIG_AT_EVT_TAGMOTIONCTL
/**
 * @brief Motion control indication handler
 *
 * @param[in] enable true = motion detection enabled, false = disabled
 */
void platform_indicate_motion_ctl(bool enable);
#endif

#ifdef CONFIG_TAG_LED_IND
/**
 * @brief Centralized LED event handler
 *
 * Drives the LED for one-shot events (battery report, factory reset, power on/off).
 *
 * @param[in] evt LED event type from #led_event_t
 */
void platform_indicate_led_evt(led_event_t evt);

#endif

#ifdef __cplusplus
}
#endif
