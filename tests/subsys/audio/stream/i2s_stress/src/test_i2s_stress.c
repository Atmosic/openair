/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/ztest.h>
#include <zephyr/ztress.h>
#include <zephyr/drivers/i2s.h>
#include <zephyr/random/random.h>
#include <zephyr/audio/audio_stream.h>
#include "wf_test_pattern_1.h"
#include "wf_test_pattern_2.h"
#include "wf_test_pattern_3.h"

static bool test_last;

static bool timer_busy_loop(void *user_data, uint32_t iter_cnt, bool last, int prio)
{
	k_busy_wait(0xfff);
	return !last && !test_last;
}

static bool thread_busy_loop(void *user_data, uint32_t iter_cnt, bool last, int prio)
{
	k_busy_wait(0xfff);
	return !last && !test_last;
}

static bool audio_play_direct(void *user_data, uint32_t iter_cnt, bool last, int prio)
{
	const void *buf[] = {bufout_1, bufout_2, bufout_3};
	uint32_t bufsize[] = {sizeof(bufout_1), sizeof(bufout_2), sizeof(bufout_3)};

	audio_stream_start();
	for (int i = 0; i < ARRAY_SIZE(buf); i++) {
		zassert_equal(0, audio_stream_write(buf[i], bufsize[i], AUDIO_PLAYBACK_MODE_NORMAL),
			"audio_stream_write failed");
	}
	audio_stream_stop();
	TC_PRINT("play direct %" PRId32 "\n", iter_cnt);
	test_last = last;
	return !last;
}

static bool audio_play_chunked(void *user_data, uint32_t iter_cnt, bool last, int prio)
{
	const void *buf[] = {bufout_1, bufout_2, bufout_3};
	uint32_t bufsize[] = {sizeof(bufout_1), sizeof(bufout_2), sizeof(bufout_3)};

	audio_stream_start();
	for (int i = 0; i < ARRAY_SIZE(buf); i++) {
		zassert_equal(0, audio_stream_write(buf[i], bufsize[i], AUDIO_PLAYBACK_MODE_PADDED_SAMPLE),
			"audio_stream_write failed");
	}
	audio_stream_stop();
	TC_PRINT("play chunked %" PRId32 "\n", iter_cnt);
	test_last = last;
	return !last;
}

ZTEST_USER(i2s_stress, test_play_audio_direct_with_loading)
{
    test_last = false;
    ztress_set_timeout(K_MSEC(40000));
    ZTRESS_EXECUTE(ZTRESS_TIMER(timer_busy_loop, NULL, 0, K_MSEC(50)),
	ZTRESS_THREAD(audio_play_direct, NULL, 10, 0, Z_TIMEOUT_TICKS(20)),
	ZTRESS_THREAD(thread_busy_loop, NULL, 0, 0, Z_TIMEOUT_TICKS(20))
    );
}

ZTEST_USER(i2s_stress, test_play_audio_chunked_with_loading)
{
    test_last = false;
    ztress_set_timeout(K_MSEC(30000));
    ZTRESS_EXECUTE(ZTRESS_TIMER(timer_busy_loop, NULL, 0, K_MSEC(50)),
	ZTRESS_THREAD(audio_play_chunked, NULL, 10, 0, Z_TIMEOUT_TICKS(20)),
	ZTRESS_THREAD(thread_busy_loop, NULL, 0, 0, Z_TIMEOUT_TICKS(20))
    );
}
