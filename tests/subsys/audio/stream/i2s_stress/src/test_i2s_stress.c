/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/ztest.h>
#include <zephyr/ztress.h>
#include <zephyr/drivers/i2s.h>
#include <zephyr/random/random.h>
#include <zephyr/audio/audio_stream.h>
#include <zephyr/sys/atomic.h>
#include "wf_test_pattern_1.h"
#include "wf_test_pattern_2.h"
#include "wf_test_pattern_3.h"

#define TIMER_BUSY_WAIT_US  511
#define THREAD_BUSY_WAIT_US 4095
#define LOG_ITER_NUM        1000

static atomic_t test_last = ATOMIC_INIT(0);

static int64_t timer_last_time;

static bool timer_busy_loop(void *user_data, uint32_t iter_cnt, bool last, int prio)
{
	int64_t now = k_uptime_get();
	int64_t interval = now - timer_last_time;
	timer_last_time = now;

	k_busy_wait(TIMER_BUSY_WAIT_US);
	atomic_val_t tl = atomic_get(&test_last);

	if (iter_cnt % LOG_ITER_NUM == 0) {
		TC_PRINT("timer_busy: iter=%" PRIu32 " interval=%" PRId64 "ms\n", iter_cnt,
			 interval);
	}
	if (last || tl) {
		TC_PRINT("timer_busy: iter=%" PRIu32 " last=%d test_last=%ld\n", iter_cnt, last,
			 tl);
	}
	return !last && !tl;
}

static bool thread_busy_loop(void *user_data, uint32_t iter_cnt, bool last, int prio)
{
	k_busy_wait(THREAD_BUSY_WAIT_US);
	atomic_val_t tl = atomic_get(&test_last);
	if (iter_cnt % LOG_ITER_NUM == 0) {
		TC_PRINT("thread_busy: iter=%" PRIu32 "\n", iter_cnt);
	}
	if (last || tl) {
		TC_PRINT("thread_busy: iter=%" PRIu32 " last=%d test_last=%ld\n", iter_cnt, last,
			 tl);
	}
	return !last && !tl;
}

static bool audio_play_direct(void *user_data, uint32_t iter_cnt, bool last, int prio)
{
	const void *buf[] = {bufout_1, bufout_2, bufout_3};
	uint32_t bufsize[] = {sizeof(bufout_1), sizeof(bufout_2), sizeof(bufout_3)};

	TC_PRINT("play direct iter=%" PRIu32 " START\n", iter_cnt);
	audio_stream_start();
	for (int i = 0; i < ARRAY_SIZE(buf); i++) {
		zassert_equal(0, audio_stream_write(buf[i], bufsize[i], AUDIO_PLAYBACK_MODE_NORMAL),
			"audio_stream_write failed");
	}
	audio_stream_stop();
	TC_PRINT("play direct iter=%" PRIu32 " END last=%d, setting test_last=%d\n", iter_cnt, last,
		 last ? 1 : 0);
	atomic_set(&test_last, last ? 1 : 0);
	return !last;
}

static bool audio_play_chunked(void *user_data, uint32_t iter_cnt, bool last, int prio)
{
	const void *buf[] = {bufout_1, bufout_2, bufout_3};
	uint32_t bufsize[] = {sizeof(bufout_1), sizeof(bufout_2), sizeof(bufout_3)};

	TC_PRINT("play chunked iter=%" PRIu32 " START\n", iter_cnt);
	audio_stream_start();

	int i = iter_cnt % ARRAY_SIZE(buf);
	zassert_equal(0, audio_stream_write(buf[i], bufsize[i], AUDIO_PLAYBACK_MODE_PADDED_SAMPLE),
		      "audio_stream_write failed");

	audio_stream_stop();
	TC_PRINT("play chunked iter=%" PRIu32 " END last=%d, setting test_last=%d\n", iter_cnt,
		 last, last ? 1 : 0);
	atomic_set(&test_last, last ? 1 : 0);
	return !last;
}

ZTEST_USER(i2s_stress, test_play_audio_direct_with_loading)
{
	atomic_set(&test_last, 0);
	timer_last_time = k_uptime_get();
	ztress_set_timeout(K_MSEC(40000));
	ZTRESS_EXECUTE(ZTRESS_TIMER(timer_busy_loop, NULL, 0, K_MSEC(50)),
		       ZTRESS_THREAD(audio_play_direct, NULL, 10, 0, Z_TIMEOUT_TICKS(20)),
		       ZTRESS_THREAD(thread_busy_loop, NULL, 0, 0, Z_TIMEOUT_TICKS(20)));
}

ZTEST_USER(i2s_stress, test_play_audio_chunked_with_loading)
{
	atomic_set(&test_last, 0);
	timer_last_time = k_uptime_get();
	ztress_set_timeout(K_MSEC(30000));
	ZTRESS_EXECUTE(ZTRESS_TIMER(timer_busy_loop, NULL, 0, K_MSEC(50)),
		       ZTRESS_THREAD(audio_play_chunked, NULL, 30, 0, Z_TIMEOUT_TICKS(20)),
		       ZTRESS_THREAD(thread_busy_loop, NULL, 0, 0, Z_TIMEOUT_TICKS(20)));
}
