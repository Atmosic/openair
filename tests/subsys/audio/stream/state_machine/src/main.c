/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/ztest.h>
#include <zephyr/device.h>
#include <zephyr/audio/audio_stream.h>
#include <zephyr/drivers/i2s.h>

#define TIMEOUT          2000
#define SAMPLE_BIT_WIDTH 16U
#define SAMPLE_FREQUENCY 48000

/* Device references */
#define I2S_DEV_NODE_TX DT_ALIAS(i2s_node0)
static const struct device *dev_i2s_tx = DEVICE_DT_GET_OR_NULL(I2S_DEV_NODE_TX);

#if DT_NODE_EXISTS(DT_NODELABEL(audio_codec))
static const struct device *const codec_dev = DEVICE_DT_GET(DT_NODELABEL(audio_codec));
#else
/* Testing without Codec */
static const struct device *const codec_dev = NULL;
#endif

/* Test configuration */
static struct i2s_config test_i2s_config = {
	.word_size = SAMPLE_BIT_WIDTH,
	.channels = 2U,
	.format = I2S_FMT_DATA_FORMAT_I2S,
	.frame_clk_freq = SAMPLE_FREQUENCY,
	.timeout = TIMEOUT,
	.options = I2S_OPT_FRAME_CLK_MASTER | I2S_OPT_BIT_CLK_MASTER,
};

static struct audio_stream_config test_audio_config = {.i2s_dev = NULL,   /* Will be set in setup */
						       .codec_dev = NULL, /* Will be set in setup */
						       .i2s_cfg = &test_i2s_config,
						       .direction = AUDIO_STREAM_OUTPUT};

struct audio_stream_config *test_get_audio_config(void)
{
	return &test_audio_config;
}

/* Test fixture setup and teardown */
static void *audio_stream_state_machine_setup(void)
{
	/* Set up device references */
	test_audio_config.i2s_dev = dev_i2s_tx;
	test_audio_config.codec_dev = codec_dev;

	/* Deinitialize audio stream to ensure clean state */
	audio_stream_deinit();

	return NULL;
}

static void audio_stream_state_machine_before(void *fixture)
{
	ARG_UNUSED(fixture);

	/* Ensure devices are set up */
	test_audio_config.i2s_dev = dev_i2s_tx;
	test_audio_config.codec_dev = codec_dev;

	/* Deinitialize audio stream to ensure clean state */
	audio_stream_deinit();
}

static void audio_stream_state_machine_after(void *fixture)
{
	ARG_UNUSED(fixture);

	/* Clean up after each test */
	audio_stream_deinit();
}

static void audio_stream_state_machine_teardown(void *fixture)
{
	ARG_UNUSED(fixture);

	/* Final cleanup */
	audio_stream_deinit();
}

ZTEST_SUITE(audio_stream_state_machine, NULL, audio_stream_state_machine_setup,
	    audio_stream_state_machine_before, audio_stream_state_machine_after,
	    audio_stream_state_machine_teardown);
