/**
 *******************************************************************************
 *
 * @file platform_indicate.c
 *
 * @brief Platform tag indication for Multimode Consumer Tag
 *
 * Copyright (C) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "arch.h"
#include "platform_common.h"
#include "platform_indicate.h"
#include "platform_ctrl_led.h"

#ifdef CONFIG_TAG_BUZZER
#include "platform_ctrl_buzzer.h"
#endif

#ifdef CONFIG_STF_TAG
#include "TagSoundPlayer.h"
#endif

#ifdef CONFIG_AT_CMD_TAG_SET
#include "at_cmd_uart.h"
#include "at_cmd_event.h"
#include "at_cmd_tag.h"
#endif

LOG_MODULE_DECLARE(multimode_consumer_tag, CONFIG_MULTIMODE_CONSUMER_TAG_LOG_LEVEL);

#ifdef CONFIG_TAG_LED_IND
#define TAG_LED_STATE(s)     platform_ctrl_led_state_update(s)
#define TAG_LED_STATE_EVT(e) platform_ctrl_led_event_indicate(e)
#else
#define TAG_LED_STATE(s)     do {} while (0)
#define TAG_LED_STATE_EVT(e) do {} while (0)
#endif

#ifdef CONFIG_AT_CMD_TAG_SET
#define TAG_AT_STATE(type, state) \
	at_cmd_evt_tag_state(at_cmd_uart_ch_get(), (type), (state))
#else
#define TAG_AT_STATE(type, state) do {} while (0)
#endif

/* Buzzer hardware macros - active only when CONFIG_TAG_BUZZER=y */
#ifdef CONFIG_TAG_BUZZER
#define TAG_BUZZER_HW_ACTION(on) platform_ctrl_buzzer_action(on)
#ifdef CONFIG_STF_TAG
#define TAG_STF_SOUND(item)      TagSoundPlayItem(item)
#else
#define TAG_STF_SOUND(item)      do {} while (0)
#endif
#else
#define TAG_BUZZER_HW_ACTION(on) do {} while (0)
#define TAG_STF_SOUND(item)      do {} while (0)
#endif

#ifdef CONFIG_AT_EVT_TAGBUZZER
#define TAG_AT_BUZZER_EVT(evt, vol, dur) \
	at_cmd_evt_buzzer_action(at_cmd_uart_ch_get(), (uint8_t)(evt), (vol), (dur))
#else
#define TAG_AT_BUZZER_EVT(evt, vol, dur) do {} while (0)
#endif

#ifdef CONFIG_AT_EVT_TAGMOTIONCTL
#define TAG_AT_MOTION_CTL(en) at_cmd_evt_motionctl(at_cmd_uart_ch_get(), (en) ? 1 : 0)
#else
#define TAG_AT_MOTION_CTL(en) do {} while (0)
#endif

#define FACTORY_RESET_AUDIO_DURATION_MS 1000

void platform_indicate_state(tag_indication_state_t st, uint8_t type)
{
	TAG_AT_STATE(type, st);

	switch (st) {
	case TAG_IND_STATE_POWER_ON:
		TAG_LED_STATE_EVT(LED_EVT_POWER_ON);
		break;
	case TAG_IND_STATE_POWER_OFF:
#if defined(CONFIG_TAG_BUZZER) || defined(CONFIG_AT_EVT_TAGBUZZER)
		platform_indicate_buzzer(TAG_BUZZER_EVT_POWER_OFF, NULL);
#endif
		TAG_LED_STATE(LED_STATE_POWER_OFF);
		TAG_LED_STATE_EVT(LED_EVT_POWER_OFF);
		break;
	case TAG_IND_STATE_PAIRING:
		TAG_LED_STATE(LED_STATE_PAIRING);
		break;
	case TAG_IND_STATE_PAIRED:
		TAG_LED_STATE(LED_STATE_PAIRED);
		break;
#ifdef CONFIG_TAG_BTN_OTA_MODE
	case TAG_IND_STATE_OTA_IN_PROGRESS:
		TAG_LED_STATE(LED_STATE_OTA_MODE);
		break;
	case TAG_IND_STATE_OTA_COMPLETE:
	case TAG_IND_STATE_OTA_CONFIRMED:
#endif
	case TAG_IND_STATE_BOOTED:
	case TAG_IND_STATE_INIT_DONE:
	case TAG_IND_STATE_UNPAIRED:
	case TAG_IND_STATE_INVALID:
	default:
		break;
	}
}

#if defined(CONFIG_STF_TAG) && defined(CONFIG_AT_EVT_TAGBUZZER)
/**
 * Override the weak port_buzzer_sound_notify() from PortBuzzerControl.c.
 * Called when TagSDK internally opens/stops the buzzer (e.g. STF ringtone).
 * ON fires after PortBuzzerHwCtrlSetVolume() so the correct volume is known.
 * Forwards the event to platform_indicate_buzzer() so the host receives an
 * AT event.
 *
 * Consecutive OFF notifications (e.g. inter-note muting in multi-tone melodies)
 * are deduplicated: only the first OFF after an ON is forwarded to the host.
 */
void port_buzzer_sound_notify(bool on, SoundVolume_t volume)
{
	if (on) {
		tag_stf_sound_params_t params = {
			.volume = (uint8_t)volume,
		};
		platform_indicate_buzzer(TAG_BUZZER_EVT_STF_SOUND_ON, &params);
	} else {
		platform_indicate_buzzer(TAG_BUZZER_EVT_STF_SOUND_OFF, NULL);
	}
}
#endif

#if defined(CONFIG_TAG_BUZZER) || defined(CONFIG_AT_EVT_TAGBUZZER)

#define TAG_BUZZER_PARAM_IGNORE 0

void platform_indicate_buzzer(tag_buzzer_evt_t evt, const void *params)
{
	LOG_INF("buzzer evt %u", evt);

	switch (evt) {
	case TAG_BUZZER_EVT_FACTORY_RESET:
#ifdef CONFIG_TAG_AUDIO_FEEDBACK
		TAG_BUZZER_HW_ACTION(true);
		k_sleep(K_MSEC(FACTORY_RESET_AUDIO_DURATION_MS));
		TAG_BUZZER_HW_ACTION(false);
#endif
		break;

	case TAG_BUZZER_EVT_POWER_OFF:
		TAG_STF_SOUND(SOUND_ITEM_OFF);
		break;

	case TAG_BUZZER_EVT_GFP_RING_ON: {
		const tag_gfp_ring_params_t *gfp = params;
		__UNUSED uint8_t vol = gfp ? gfp->ring_vol : 0;
		__UNUSED uint16_t dur = gfp ? gfp->duration_ds : 0;
		TAG_BUZZER_HW_ACTION(true);
		TAG_AT_BUZZER_EVT(evt, vol, dur);
		break;
	}

	case TAG_BUZZER_EVT_FMNA_RING_ON:
		/* FMNA spec does not provide ring parameters */
		TAG_BUZZER_HW_ACTION(true);
		TAG_AT_BUZZER_EVT(evt, TAG_BUZZER_PARAM_IGNORE, TAG_BUZZER_PARAM_IGNORE);
		break;

	case TAG_BUZZER_EVT_GFP_RING_OFF:
	case TAG_BUZZER_EVT_FMNA_RING_OFF:
		TAG_BUZZER_HW_ACTION(false);
		TAG_AT_BUZZER_EVT(evt, TAG_BUZZER_PARAM_IGNORE, TAG_BUZZER_PARAM_IGNORE);
		break;

	case TAG_BUZZER_EVT_STF_SOUND_ON: {
		const tag_stf_sound_params_t *stf = params;
		__UNUSED uint8_t vol = stf ? stf->volume : 0;
		/* HW path is handled at the PortBuzzerControl layer.
		 * vol carries the volume set by PortBuzzerHwCtrlSetVolume(). */
		TAG_AT_BUZZER_EVT(evt, vol, TAG_BUZZER_PARAM_IGNORE);
		break;
	}

	case TAG_BUZZER_EVT_STF_SOUND_OFF:
		/* HW path is handled at the PortBuzzerControl layer. */
		TAG_AT_BUZZER_EVT(evt, TAG_BUZZER_PARAM_IGNORE, TAG_BUZZER_PARAM_IGNORE);
		break;

	default:
		break;
	}
}
#endif

#ifdef CONFIG_TAG_LED_IND
void platform_indicate_led_evt(led_event_t evt)
{
	platform_ctrl_led_event_indicate(evt);
}
#endif

#ifdef CONFIG_AT_EVT_TAGMOTIONCTL
void platform_indicate_motion_ctl(bool enable)
{
	LOG_DBG("motion_ctl ind %u", enable);
	TAG_AT_MOTION_CTL(enable);
}
#endif
