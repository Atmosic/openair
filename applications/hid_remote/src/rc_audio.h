/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <stdbool.h>

/** @brief Initialise the audio subsystem (ATVV + optional DMIC). */
void rc_audio_init(void);

/** @brief Start the audio capture and streaming pipeline. */
void rc_audio_stream_start(void);

/** @brief Stop the audio capture and streaming pipeline. */
void rc_audio_stream_stop(void);

/**
 * @brief Start voice search / streaming on Assistant (MIC) button press.
 *
 * Behaviour depends on CONFIG_RC_ATVV_ASST_MODEL:
 *   - On-request : sends ATVV_CTL_SEARCH_START; host replies with MIC_OPEN.
 *   - PTT / HTT  : remote itself sends AUDIO_START and begins streaming,
 *                  without waiting for MIC_OPEN (requires CONFIG_ATVV_SPEC_V1_0).
 * No-op if ATVV is not ready, or if a session is already active.
 */
void rc_audio_start_search(void);

/**
 * @brief Returns true if ATVV was successfully configured in a previous session.
 *
 * Persisted via Settings subsystem.
 * Use to skip CAPS negotiation on reconnect when host is known to support ATVV.
 */
bool rc_audio_atvv_was_configured(void);

/**
 * @brief Stop voice search on Assistant (MIC) button release.
 *
 * Behaviour depends on CONFIG_RC_ATVV_ASST_MODEL:
 *   - On-request : stops local capture and sends AUDIO_STOP (reason
 *                  ATVV_AUDIO_STOP_REASON_MIC_CLOSE on CONFIG_ATVV_SPEC_V1_0;
 *                  no payload on CONFIG_ATVV_SPEC_V0_4).
 *   - HTT        : stops local capture and sends AUDIO_STOP (reason
 *                  ATVV_AUDIO_STOP_REASON_HTT_RELEASE) immediately.
 *   - PTT        : stops local capture and sends AUDIO_STOP (reason
 *                  ATVV_AUDIO_STOP_REASON_OTHER) on button release.
 */
void rc_audio_stop_search(void);

/**
 * @brief Notify host of a D-pad select (OK button) during voice session.
 *
 * Sends ATVV_CTL_DPAD_SELECT to the host. Should be called on OK key press
 * when ATVV is in READY or streaming state.
 */
void rc_audio_dpad_select(void);
