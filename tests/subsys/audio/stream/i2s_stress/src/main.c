/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/ztest.h>
#include <zephyr/device.h>
#include <zephyr/audio/audio_stream.h>

#define TIMEOUT		2000
#define SAMPLE_BIT_WIDTH 16U
#define SAMPLE_FREQUENCY 48000

extern const struct device *dev_i2s_tx;
extern const struct device *const codec_dev;
#define I2S_DEV_NODE_TX DT_ALIAS(i2s_node0)

const struct device *dev_i2s_tx = DEVICE_DT_GET_OR_NULL(I2S_DEV_NODE_TX);
#if DT_NODE_EXISTS(DT_NODELABEL(audio_codec))
const struct device *const codec_dev = DEVICE_DT_GET(DT_NODELABEL(audio_codec));
#else
/* Testing without Codec */
const struct device *const codec_dev;
#endif

static struct i2s_config *get_config(const struct device *dev_i2s)
{
	static struct i2s_config i2s_cfg = {
		.word_size = SAMPLE_BIT_WIDTH,
		.channels = 2U,
		.format = I2S_FMT_DATA_FORMAT_I2S,
		.frame_clk_freq = SAMPLE_FREQUENCY,
		.timeout = TIMEOUT,
		.options = I2S_OPT_FRAME_CLK_MASTER | I2S_OPT_BIT_CLK_MASTER,
	};
	return &i2s_cfg;
}

static void before(void *fixture)
{
	ARG_UNUSED(fixture);
	struct audio_stream_config audio_cfg = {
		.i2s_dev = dev_i2s_tx,
		.codec_dev = codec_dev,
		.i2s_cfg = get_config(dev_i2s_tx),
		.direction = AUDIO_STREAM_OUTPUT
	};
	zassert_equal(audio_stream_init(&audio_cfg), 0, "audio_playback_init failed");
}


ZTEST_SUITE(i2s_stress, NULL, NULL, before, NULL, NULL);
