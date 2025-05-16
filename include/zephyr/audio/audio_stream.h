/*
 * Copyright (C) Atmosic 2025
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @brief Audio stream interface for I2S + codec abstraction
 *
 * This module provides a unified interface output (playback) using I2S and audio codec devices.
 */

#pragma once

#include <zephyr/device.h>
#include <zephyr/drivers/i2s.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Audio stream direction */
enum audio_stream_direction {
	AUDIO_STREAM_OUTPUT,	/**< Playback (TX) */
	AUDIO_STREAM_INPUT,	/**< Capture (RX) */
};

/**
 * @brief Playback modes for audio_stream_write()
 */
enum audio_playback_mode {
	AUDIO_PLAYBACK_MODE_NORMAL,		/**< Play buffer directly */
	AUDIO_PLAYBACK_MODE_PADDED_SAMPLE,	/**< Insert sample itself between samples */
};

/**
 * @brief Audio stream configuration
 */
struct audio_stream_config {
	/** I2S device used for stream data transfer */
	const struct device *i2s_dev;

	/** Audio codec device (optional, can be NULL) */
	const struct device *codec_dev;

	/** I2S configuration settings */
	const struct i2s_config *i2s_cfg;

	/** Stream direction: input or output */
	enum audio_stream_direction direction;
};

/**
 * @brief Initialize the audio stream
 *
 * This function configures the I2S and optionally the codec device
 * for either input or output streaming, based on the provided direction.
 *
 * @param cfg Pointer to stream configuration structure
 *
 * @return 0 on success, negative error code on failure
 */
int audio_stream_init(const struct audio_stream_config *cfg);

/**
 * @brief Start the audio stream
 *
 * Starts the I2S data stream in the specified direction.
 *
 * @return 0 on success, negative error code on failure
 */
int audio_stream_start(void);

/**
 * @brief Start playing a PCM buffer
 *
 * @param pcm_data Pointer to raw PCM buffer
 * @param size_bytes Size of the PCM buffer in bytes
 * @param mode Playback mode (normal or zero-padded)
 *
 * @return 0 if success, negative errno code otherwise
 */
int audio_stream_write(const void *pcm_data, size_t size_bytes,
	enum audio_playback_mode mode);

/**
 * @brief Stop playback
 *
 * @return 0 if success, negative errno code otherwise
 */
int audio_stream_stop(void);

/**
 * @brief Deinitialize playback system
 *
 * @return 0 if success, negative errno code otherwise
 */
int audio_stream_deinit(void);

#ifdef __cplusplus
}
#endif
