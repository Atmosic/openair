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

/* External references from main.c */
struct audio_stream_config *test_get_audio_config(void);
#define test_audio_config (*test_get_audio_config())

/* Test data */
static uint8_t test_pcm_data[256] = {0};

/* Helper function to ensure clean state before each test */
static void ensure_clean_state(void)
{
	/* Force stop any ongoing operations */
	audio_stream_stop();
	/* Deinitialize to reset to known state */
	audio_stream_deinit();
}

/**
 * @brief Test audio stream initialization with valid configuration
 */
ZTEST(audio_stream_state_machine, test_init_valid_config)
{
	/* Ensure clean state */
	ensure_clean_state();

	/* Skip test if I2S device is not available */
	if (!test_audio_config.i2s_dev) {
		ztest_test_skip();
		return;
	}

	/* Test successful initialization */
	int ret = audio_stream_init(&test_audio_config);
	zassert_equal(ret, 0, "audio_stream_init should succeed with valid config, got ret=%d",
		      ret);

	/* Clean up after test */
	ensure_clean_state();
}

/**
 * @brief Test audio stream initialization with invalid parameters
 */
ZTEST(audio_stream_state_machine, test_init_invalid_params)
{
	/* Ensure clean state */
	ensure_clean_state();

	/* Test NULL config */
	int ret = audio_stream_init(NULL);
	zassert_equal(ret, -EINVAL, "audio_stream_init should fail with NULL config, got ret=%d",
		      ret);

	/* Test NULL i2s_dev */
	struct audio_stream_config invalid_config = test_audio_config;
	invalid_config.i2s_dev = NULL;
	ret = audio_stream_init(&invalid_config);
	zassert_equal(ret, -EINVAL, "audio_stream_init should fail with NULL i2s_dev, got ret=%d",
		      ret);

	/* Test NULL i2s_cfg */
	invalid_config = test_audio_config;
	invalid_config.i2s_cfg = NULL;
	ret = audio_stream_init(&invalid_config);
	zassert_equal(ret, -EINVAL, "audio_stream_init should fail with NULL i2s_cfg, got ret=%d",
		      ret);

	/* Test unsupported direction */
	invalid_config = test_audio_config;
	invalid_config.direction = AUDIO_STREAM_INPUT;
	ret = audio_stream_init(&invalid_config);
	zassert_equal(ret, -ENOTSUP,
		      "audio_stream_init should fail with INPUT direction, got ret=%d", ret);
}

/**
 * @brief Test valid state transitions: IDLE -> READY -> BUSY -> READY -> IDLE
 */
ZTEST(audio_stream_state_machine, test_valid_state_transitions)
{
	/* Ensure clean state */
	ensure_clean_state();

	/* Skip test if I2S device is not available */
	if (!test_audio_config.i2s_dev) {
		ztest_test_skip();
		return;
	}

	/* Initialize audio stream (IDLE state) */
	int ret = audio_stream_init(&test_audio_config);
	zassert_equal(ret, 0, "audio_stream_init should succeed, got ret=%d", ret);

	/* Transition to READY state */
	ret = audio_stream_start();
	zassert_equal(ret, 0, "audio_stream_start should succeed from IDLE, got ret=%d", ret);

	/* Transition to BUSY state and back to READY */
	ret = audio_stream_write(test_pcm_data, sizeof(test_pcm_data), AUDIO_PLAYBACK_MODE_NORMAL);
	zassert_equal(ret, 0, "audio_stream_write should succeed from READY, got ret=%d", ret);

	/* Transition back to IDLE state */
	ret = audio_stream_stop();
	zassert_equal(ret, 0, "audio_stream_stop should succeed from READY, got ret=%d", ret);

	/* Clean up after test */
	ensure_clean_state();
}

/**
 * @brief Test invalid state transitions
 */
ZTEST(audio_stream_state_machine, test_invalid_state_transitions)
{
	/* Ensure clean state */
	ensure_clean_state();

	/* Skip test if I2S device is not available */
	if (!test_audio_config.i2s_dev) {
		ztest_test_skip();
		return;
	}

	/* Try to start without initialization */
	int ret = audio_stream_start();
	zassert_not_equal(ret, 0, "audio_stream_start should fail without init, got ret=%d", ret);

	/* Initialize first */
	ret = audio_stream_init(&test_audio_config);
	zassert_equal(ret, 0, "audio_stream_init should succeed, got ret=%d", ret);

	/* Try to write without starting */
	ret = audio_stream_write(test_pcm_data, sizeof(test_pcm_data), AUDIO_PLAYBACK_MODE_NORMAL);
	zassert_equal(ret, -EBUSY, "audio_stream_write should fail from IDLE, got ret=%d", ret);

	/* Start the stream */
	ret = audio_stream_start();
	zassert_equal(ret, 0, "audio_stream_start should succeed, got ret=%d", ret);

	/* Try to start again (should fail) */
	ret = audio_stream_start();
	zassert_equal(ret, -EINVAL, "audio_stream_start should fail from READY, got ret=%d", ret);

	/* Clean up after test */
	ensure_clean_state();
}

/**
 * @brief Test audio_stream_write with invalid parameters
 */
ZTEST(audio_stream_state_machine, test_write_invalid_params)
{
	/* Ensure clean state */
	ensure_clean_state();

	/* Skip test if I2S device is not available */
	if (!test_audio_config.i2s_dev) {
		ztest_test_skip();
		return;
	}

	/* Initialize and start */
	int ret = audio_stream_init(&test_audio_config);
	zassert_equal(ret, 0, "audio_stream_init should succeed, got ret=%d", ret);
	ret = audio_stream_start();
	zassert_equal(ret, 0, "audio_stream_start should succeed, got ret=%d", ret);

	/* Test NULL pcm_data */
	ret = audio_stream_write(NULL, sizeof(test_pcm_data), AUDIO_PLAYBACK_MODE_NORMAL);
	zassert_equal(ret, -EINVAL, "audio_stream_write should fail with NULL data, got ret=%d",
		      ret);

	/* Test zero size */
	ret = audio_stream_write(test_pcm_data, 0, AUDIO_PLAYBACK_MODE_NORMAL);
	zassert_equal(ret, -EINVAL, "audio_stream_write should fail with zero size, got ret=%d",
		      ret);

	/* Test invalid mode */
	ret = audio_stream_write(test_pcm_data, sizeof(test_pcm_data),
				 (enum audio_playback_mode)999);
	zassert_equal(ret, -EINVAL, "audio_stream_write should fail with invalid mode, got ret=%d",
		      ret);

	/* Clean up after test */
	ensure_clean_state();
}

/**
 * @brief Test both playback modes
 */
ZTEST(audio_stream_state_machine, test_playback_modes)
{
	/* Ensure clean state */
	ensure_clean_state();

	/* Skip test if I2S device is not available */
	if (!test_audio_config.i2s_dev) {
		ztest_test_skip();
		return;
	}

	/* Initialize and start */
	int ret = audio_stream_init(&test_audio_config);
	TC_PRINT("test_playback_modes: audio_stream_init returned %d\n", ret);
	zassert_equal(ret, 0, "audio_stream_init should succeed, got ret=%d", ret);
	ret = audio_stream_start();
	TC_PRINT("test_playback_modes: audio_stream_start returned %d\n", ret);
	zassert_equal(ret, 0, "audio_stream_start should succeed, got ret=%d", ret);

	/* Test normal mode */
	ret = audio_stream_write(test_pcm_data, sizeof(test_pcm_data), AUDIO_PLAYBACK_MODE_NORMAL);
	zassert_equal(ret, 0, "audio_stream_write should succeed with NORMAL mode, got ret=%d",
		      ret);

	/* Test padded sample mode */
	ret = audio_stream_write(test_pcm_data, sizeof(test_pcm_data),
				 AUDIO_PLAYBACK_MODE_PADDED_SAMPLE);
	zassert_equal(ret, 0,
		      "audio_stream_write should succeed with PADDED_SAMPLE mode, got ret=%d", ret);

	/* Clean up after test */
	ensure_clean_state();
}

/**
 * @brief Test stop operation from different states
 */
ZTEST(audio_stream_state_machine, test_stop_from_different_states)
{
	/* Ensure clean state */
	ensure_clean_state();

	/* Skip test if I2S device is not available */
	if (!test_audio_config.i2s_dev) {
		TC_PRINT("test_stop_from_different_states: Skipping - no I2S device\n");
		ztest_test_skip();
		return;
	}

	/* Test stop from IDLE (should succeed - already stopped) */
	int ret = audio_stream_stop();
	TC_PRINT("test_stop_from_different_states: audio_stream_stop from IDLE returned %d\n", ret);
	zassert_equal(ret, 0, "audio_stream_stop should succeed from IDLE, got ret=%d", ret);

	/* Initialize and test stop from READY */
	ret = audio_stream_init(&test_audio_config);
	TC_PRINT("test_stop_from_different_states: audio_stream_init returned %d\n", ret);
	zassert_equal(ret, 0, "audio_stream_init should succeed, got ret=%d", ret);
	ret = audio_stream_start();
	TC_PRINT("test_stop_from_different_states: audio_stream_start returned %d\n", ret);
	zassert_equal(ret, 0, "audio_stream_start should succeed, got ret=%d", ret);

	ret = audio_stream_stop();
	TC_PRINT("test_stop_from_different_states: audio_stream_stop from READY returned %d\n",
		 ret);
	zassert_equal(ret, 0, "audio_stream_stop should succeed from READY, got ret=%d", ret);

	/* Clean up after test */
	ensure_clean_state();
}

/**
 * @brief Test concurrent stop operation (SUPPORT-4473 scenario)
 * This tests the fix for the audio thread hang issue when stop is called
 * while audio is playing.
 */
ZTEST(audio_stream_state_machine, test_concurrent_stop_operation)
{
	/* Ensure clean state */
	ensure_clean_state();

	/* Skip test if I2S device is not available */
	if (!test_audio_config.i2s_dev) {
		ztest_test_skip();
		return;
	}

	/* Initialize and start */
	int ret = audio_stream_init(&test_audio_config);
	zassert_equal(ret, 0, "audio_stream_init should succeed, got ret=%d", ret);
	ret = audio_stream_start();
	zassert_equal(ret, 0, "audio_stream_start should succeed, got ret=%d", ret);

	/* Start a write operation that would normally take time */
	/* In a real scenario, this would be interrupted by stop */
	ret = audio_stream_write(test_pcm_data, sizeof(test_pcm_data),
				 AUDIO_PLAYBACK_MODE_PADDED_SAMPLE);
	zassert_equal(ret, 0, "audio_stream_write should succeed, got ret=%d", ret);

	/* Call stop - this should work even if called during playback */
	ret = audio_stream_stop();
	zassert_equal(ret, 0, "audio_stream_stop should succeed during/after playback, got ret=%d",
		      ret);

	/* Clean up after test */
	ensure_clean_state();
}

/**
 * @brief Test stop operation from IDLE state (should succeed - already stopped)
 */
ZTEST(audio_stream_state_machine, test_stop_from_idle)
{
	/* Test stop from IDLE (should succeed - already stopped) */
	int ret = audio_stream_stop();
	zassert_equal(ret, 0, "audio_stream_stop should succeed from IDLE, got ret=%d", ret);
}

/**
 * @brief Test deinitialize function
 */
ZTEST(audio_stream_state_machine, test_deinitialize)
{
	/* Test deinit without init (should fail) */
	int ret = audio_stream_deinit();
	zassert_equal(ret, -EINVAL, "audio_stream_deinit should fail without init, got ret=%d",
		      ret);

	/* Initialize and then deinitialize */
	ret = audio_stream_init(&test_audio_config);
	zassert_equal(ret, 0, "audio_stream_init should succeed, got ret=%d", ret);

	ret = audio_stream_deinit();
	zassert_equal(ret, 0, "audio_stream_deinit should succeed after init, got ret=%d", ret);

	/* Try to use after deinit (should fail) */
	ret = audio_stream_start();
	zassert_not_equal(ret, 0, "audio_stream_start should fail after deinit, got ret=%d", ret);
}

/**
 * @brief Test multiple consecutive operations
 */
ZTEST(audio_stream_state_machine, test_multiple_consecutive_operations)
{
	/* Skip test if I2S device is not available */
	if (!test_audio_config.i2s_dev) {
		TC_PRINT("test_multiple_consecutive_operations: Skipping - no I2S device\n");
		ztest_test_skip();
		return;
	}

	/* Initialize */
	int ret = audio_stream_init(&test_audio_config);
	TC_PRINT("test_multiple_consecutive_operations: audio_stream_init returned %d\n", ret);
	zassert_equal(ret, 0, "audio_stream_init should succeed, got ret=%d", ret);

	/* Multiple start/stop cycles */
	for (int i = 0; i < 3; i++) {
		TC_PRINT("test_multiple_consecutive_operations: Starting cycle %d\n", i);
		ret = audio_stream_start();
		TC_PRINT("test_multiple_consecutive_operations: audio_stream_start cycle %d "
			 "returned %d\n",
			 i, ret);
		zassert_equal(ret, 0, "audio_stream_start should succeed (cycle %d), got ret=%d", i,
			      ret);

		ret = audio_stream_write(test_pcm_data, sizeof(test_pcm_data),
					 AUDIO_PLAYBACK_MODE_NORMAL);
		TC_PRINT("test_multiple_consecutive_operations: audio_stream_write cycle %d "
			 "returned %d\n",
			 i, ret);
		zassert_equal(ret, 0, "audio_stream_write should succeed (cycle %d), got ret=%d", i,
			      ret);

		ret = audio_stream_stop();
		TC_PRINT("test_multiple_consecutive_operations: audio_stream_stop cycle %d "
			 "returned %d\n",
			 i, ret);
		zassert_equal(ret, 0, "audio_stream_stop should succeed (cycle %d), got ret=%d", i,
			      ret);
	}
}

/**
 * @brief Test rapid start/stop operations
 */
ZTEST(audio_stream_state_machine, test_rapid_start_stop)
{
	/* Skip test if I2S device is not available */
	if (!test_audio_config.i2s_dev) {
		ztest_test_skip();
		return;
	}

	/* Initialize */
	int ret = audio_stream_init(&test_audio_config);
	zassert_equal(ret, 0, "audio_stream_init should succeed, got ret=%d", ret);

	/* Rapid start/stop without write */
	for (int i = 0; i < 5; i++) {
		ret = audio_stream_start();
		zassert_equal(ret, 0, "audio_stream_start should succeed (rapid %d), got ret=%d", i,
			      ret);

		ret = audio_stream_stop();
		zassert_equal(ret, 0, "audio_stream_stop should succeed (rapid %d), got ret=%d", i,
			      ret);
	}
}

/**
 * @brief Test operation without codec (codec_dev = NULL)
 */
ZTEST(audio_stream_state_machine, test_operation_without_codec)
{
	struct audio_stream_config no_codec_config = test_audio_config;
	no_codec_config.codec_dev = NULL;

	/* Skip test if I2S device is not available */
	if (!test_audio_config.i2s_dev) {
		ztest_test_skip();
		return;
	}

	/* Initialize without codec */
	int ret = audio_stream_init(&no_codec_config);
	zassert_equal(ret, 0, "audio_stream_init should succeed without codec, got ret=%d", ret);

	/* Start should work without codec */
	ret = audio_stream_start();
	zassert_equal(ret, 0, "audio_stream_start should succeed without codec, got ret=%d", ret);

	/* Write should work without codec */
	ret = audio_stream_write(test_pcm_data, sizeof(test_pcm_data), AUDIO_PLAYBACK_MODE_NORMAL);
	zassert_equal(ret, 0, "audio_stream_write should succeed without codec, got ret=%d", ret);

	/* Stop should work without codec */
	ret = audio_stream_stop();
	zassert_equal(ret, 0, "audio_stream_stop should succeed without codec, got ret=%d", ret);
}

/**
 * @brief Test edge case: very small buffer
 */
ZTEST(audio_stream_state_machine, test_small_buffer)
{
	uint8_t small_buffer[4] = {0x01, 0x02, 0x03, 0x04};

	/* Skip test if I2S device is not available */
	if (!test_audio_config.i2s_dev) {
		ztest_test_skip();
		return;
	}

	/* Initialize and start */
	int ret = audio_stream_init(&test_audio_config);
	zassert_equal(ret, 0, "audio_stream_init should succeed, got ret=%d", ret);
	ret = audio_stream_start();
	zassert_equal(ret, 0, "audio_stream_start should succeed, got ret=%d", ret);

	/* Write small buffer */
	ret = audio_stream_write(small_buffer, sizeof(small_buffer), AUDIO_PLAYBACK_MODE_NORMAL);
	zassert_equal(ret, 0, "audio_stream_write should succeed with small buffer, got ret=%d",
		      ret);
}

/**
 * @brief Test edge case: large buffer
 */
ZTEST(audio_stream_state_machine, test_large_buffer)
{
	static uint8_t large_buffer[4096];

	/* Skip test if I2S device is not available */
	if (!test_audio_config.i2s_dev) {
		ztest_test_skip();
		return;
	}

	/* Initialize buffer with test pattern */
	for (int i = 0; i < sizeof(large_buffer); i++) {
		large_buffer[i] = i & 0xFF;
	}

	/* Initialize and start */
	int ret = audio_stream_init(&test_audio_config);
	zassert_equal(ret, 0, "audio_stream_init should succeed, got ret=%d", ret);
	ret = audio_stream_start();
	zassert_equal(ret, 0, "audio_stream_start should succeed, got ret=%d", ret);

	/* Write large buffer */
	ret = audio_stream_write(large_buffer, sizeof(large_buffer),
				 AUDIO_PLAYBACK_MODE_PADDED_SAMPLE);
	zassert_equal(ret, 0, "audio_stream_write should succeed with large buffer, got ret=%d",
		      ret);

	/* Clean up after test */
	ensure_clean_state();
}

/* Global variables for concurrent stop test */
static volatile bool write_in_progress = false;
static volatile bool stop_called = false;
static volatile int write_result = 0;
static struct k_work_delayable concurrent_stop_work;

/* Work handler to call audio_stream_stop() during blocking write */
static void concurrent_stop_work_handler(struct k_work *work)
{
	TC_PRINT("concurrent_stop_work_handler: Calling audio_stream_stop() during blocking "
		 "write\n");

	/* Wait a bit to ensure write has started */
	k_msleep(50);

	/* Call stop while write is in progress */
	int ret = audio_stream_stop();
	TC_PRINT("concurrent_stop_work_handler: audio_stream_stop() returned %d\n", ret);

	stop_called = true;
}

/**
 * @brief Test blocking write with concurrent stop operation (SUPPORT-4473 core test)
 * This test validates that calling audio_stream_stop() during a blocking
 * audio_stream_write() operation doesn't cause the thread to hang.
 */
ZTEST(audio_stream_state_machine, test_blocking_write_with_concurrent_stop)
{
	static uint8_t very_large_buffer[8192]; /* Large buffer for long blocking write */

	/* Ensure clean state */
	ensure_clean_state();

	/* Skip test if I2S device is not available */
	if (!test_audio_config.i2s_dev) {
		ztest_test_skip();
		return;
	}

	/* Initialize buffer with test pattern */
	for (int i = 0; i < sizeof(very_large_buffer); i++) {
		very_large_buffer[i] = (i * 7) & 0xFF; /* Varied pattern */
	}

	/* Initialize and start */
	int ret = audio_stream_init(&test_audio_config);
	zassert_equal(ret, 0, "audio_stream_init should succeed, got ret=%d", ret);
	ret = audio_stream_start();
	zassert_equal(ret, 0, "audio_stream_start should succeed, got ret=%d", ret);

	/* Initialize work queue for concurrent stop */
	k_work_init_delayable(&concurrent_stop_work, concurrent_stop_work_handler);

	/* Reset test flags */
	write_in_progress = false;
	stop_called = false;
	write_result = 0;

	TC_PRINT("test_blocking_write_with_concurrent_stop: Starting concurrent stop work\n");

	/* Schedule concurrent stop operation */
	k_work_schedule(&concurrent_stop_work, K_MSEC(100));

	TC_PRINT("test_blocking_write_with_concurrent_stop: Starting blocking write with large "
		 "buffer\n");
	write_in_progress = true;

	/* Start blocking write with PADDED_SAMPLE mode (most likely to block) */
	ret = audio_stream_write(very_large_buffer, sizeof(very_large_buffer),
				 AUDIO_PLAYBACK_MODE_PADDED_SAMPLE);

	write_in_progress = false;
	write_result = ret;

	TC_PRINT("test_blocking_write_with_concurrent_stop: Blocking write completed with ret=%d\n",
		 ret);

	/* Wait for concurrent stop to complete */
	k_msleep(200);

	/* Verify that stop was called */
	zassert_true(stop_called, "Concurrent stop should have been called");

	/* The write may succeed (0) or be interrupted (negative error code) */
	/* Both are acceptable as long as the system doesn't hang */
	TC_PRINT("test_blocking_write_with_concurrent_stop: Write result=%d, Stop called=%s\n",
		 write_result, stop_called ? "true" : "false");

	/* Key validation: We reached this point without hanging! */
	/* This proves the SUPPORT-4473 fix is working */

	/* Clean up after test */
	ensure_clean_state();
}
