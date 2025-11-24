/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/logging/log.h>
#ifdef CONFIG_LED
#include <zephyr/device.h>
#include <zephyr/drivers/led.h>
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#include "app_work_q.h"
#endif
#include "rrsp_led.h"

LOG_MODULE_REGISTER(rrsp_led, CONFIG_RRSP_LED_LOG_LEVEL);

#ifdef CONFIG_LED
typedef enum rrsp_led_index_e {
	RRSP_LED_IDX_STS_GREEN,
	RRSP_LED_IDX_STS_RED,
	RRSP_LED_IDX_BAT_GREEN,

	RRSP_LED_IDX_MAX
} rrsp_led_index_t;

#define RRSP_LED_MAX_SEQ 4
typedef struct rrsp_led_pattern_s {
	uint8_t led_mask;
	uint8_t valid_seq;
	// 0: infinite
	uint8_t repeat_times;
	uint8_t active_led[RRSP_LED_MAX_SEQ];
	uint16_t dur_ms[RRSP_LED_MAX_SEQ];
} rrsp_led_pattern_t;

typedef enum rrsp_led_work_e {
	RRSP_LED_WORK_EVT,
	RRSP_LED_WORK_BG,

	RRSP_LED_WORK_MAX
} rrsp_led_work_t;

#define LED_MASK(led_idx) (1 << led_idx)
static const rrsp_led_pattern_t rrsp_led_pattern[RRSP_LED_PAT_MAX] = {
	{LED_MASK(RRSP_LED_IDX_STS_GREEN),
	 2,
	 3,
	 {LED_MASK(RRSP_LED_IDX_STS_GREEN), 0, 0, 0},
	 {500, 500, 0, 0}},
	{LED_MASK(RRSP_LED_IDX_STS_RED),
	 2,
	 3,
	 {LED_MASK(RRSP_LED_IDX_STS_RED), 0, 0, 0},
	 {500, 500, 0, 0}},
	{LED_MASK(RRSP_LED_IDX_BAT_GREEN),
	 2,
	 5,
	 {LED_MASK(RRSP_LED_IDX_BAT_GREEN), 0, 0, 0},
	 {500, 500, 0, 0}},
	{LED_MASK(RRSP_LED_IDX_BAT_GREEN),
	 2,
	 4,
	 {LED_MASK(RRSP_LED_IDX_BAT_GREEN), 0, 0, 0},
	 {500, 500, 0, 0}},
	{LED_MASK(RRSP_LED_IDX_BAT_GREEN),
	 2,
	 3,
	 {LED_MASK(RRSP_LED_IDX_BAT_GREEN), 0, 0, 0},
	 {500, 500, 0, 0}},
	{LED_MASK(RRSP_LED_IDX_BAT_GREEN),
	 2,
	 2,
	 {LED_MASK(RRSP_LED_IDX_BAT_GREEN), 0, 0, 0},
	 {500, 500, 0, 0}},
	{LED_MASK(RRSP_LED_IDX_BAT_GREEN),
	 2,
	 1,
	 {LED_MASK(RRSP_LED_IDX_BAT_GREEN), 0, 0, 0},
	 {500, 500, 0, 0}},
	{(LED_MASK(RRSP_LED_IDX_STS_GREEN) | LED_MASK(RRSP_LED_IDX_STS_RED)),
	 3,
	 0,
	 {LED_MASK(RRSP_LED_IDX_STS_GREEN), LED_MASK(RRSP_LED_IDX_STS_RED), 0, 0},
	 {500, 500, 5000, 0}},
	{LED_MASK(RRSP_LED_IDX_STS_GREEN),
	 2,
	 0,
	 {LED_MASK(RRSP_LED_IDX_STS_GREEN), 0, 0, 0},
	 {500, 20000, 0, 0}},
	{LED_MASK(RRSP_LED_IDX_STS_GREEN),
	 2,
	 0,
	 {LED_MASK(RRSP_LED_IDX_STS_GREEN), 0, 0, 0},
	 {500, 1000, 0, 0}},
};

static struct rrsp_led_wrok_info {
	struct k_work_delayable work;
	uint8_t active_pattern;
	uint8_t repeat;
	uint8_t next_seq;
} rrsp_led_work[RRSP_LED_WORK_MAX];

static const struct device *const rrsp_led = DEVICE_DT_GET_ONE(gpio_leds);
static bool led_lock;
static bool rrsp_led_lock_sleep(bool lock)
{
	LOG_DBG("led lock:%d", lock);

	if (led_lock == lock) {
		return true;
	}
	if (lock) {
		// Check the event
		if (rrsp_led_work[RRSP_LED_WORK_EVT].active_pattern == RRSP_LED_PAT_INVALID &&
		    rrsp_led_work[RRSP_LED_WORK_BG].active_pattern == RRSP_LED_PAT_INVALID) {
			LOG_ERR("Unexpected lock:%u' %u",
				rrsp_led_work[RRSP_LED_WORK_EVT].active_pattern,
				rrsp_led_work[RRSP_LED_WORK_BG].active_pattern);
			return false;
		}
		pm_policy_state_lock_get(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	} else {
		// Check the event
		if (rrsp_led_work[RRSP_LED_WORK_EVT].active_pattern != RRSP_LED_PAT_INVALID ||
		    rrsp_led_work[RRSP_LED_WORK_BG].active_pattern != RRSP_LED_PAT_INVALID) {
			LOG_INF("Wait unlock:%u' %u",
				rrsp_led_work[RRSP_LED_WORK_EVT].active_pattern,
				rrsp_led_work[RRSP_LED_WORK_BG].active_pattern);
			return false;
		}
		pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	}

	led_lock = lock;
	return true;
}

static rrsp_led_work_t rrsp_led_get_workidx_by_pattern(rrsp_led_pattern_idx_t pattern)
{
	// Check LED pattern work according LED pattern
	if (pattern >= RRSP_LED_PAT_MAX) {
		LOG_ERR("Unexpected LED pattern-%u", pattern);
		return RRSP_LED_WORK_MAX;
	}
	if (pattern < RRSP_LED_PAT_MODE) {
		return RRSP_LED_WORK_EVT;
	}
	return RRSP_LED_WORK_BG;
}

static void rrsp_led_start_pattern(rrsp_led_pattern_idx_t pattern)
{
	uint8_t work_idx = rrsp_led_get_workidx_by_pattern(pattern);
	if (work_idx >= RRSP_LED_WORK_MAX) {
		return;
	}

	// Check the work is available or not
	if (rrsp_led_work[work_idx].active_pattern != RRSP_LED_PAT_INVALID) {
		LOG_ERR("Previous LED pattern:%u still active.",
			rrsp_led_work[work_idx].active_pattern);
		return;
	}

	rrsp_led_work[work_idx].active_pattern = pattern;
	rrsp_led_work[work_idx].repeat = 0;
	rrsp_led_work[work_idx].next_seq = 0;

	uint16_t delay_ms = 0;
	if (work_idx == RRSP_LED_WORK_BG &&
	    (rrsp_led_work[RRSP_LED_WORK_EVT].active_pattern != RRSP_LED_PAT_INVALID)) {
		// Check the LED pattern conflict. If yes, delay BG event
		uint8_t evt_pat = rrsp_led_work[RRSP_LED_WORK_EVT].active_pattern;
		if (rrsp_led_pattern[pattern].led_mask & rrsp_led_pattern[evt_pat].led_mask) {
			for (uint8_t seq = 0; seq < rrsp_led_pattern[evt_pat].valid_seq; seq++) {
				delay_ms += rrsp_led_pattern[evt_pat].dur_ms[seq];
			}
			delay_ms = delay_ms * rrsp_led_pattern[evt_pat].repeat_times;
			LOG_WRN("LED pattern conflict");
		}
	}

	atm_work_reschedule_for_app_work_q(&rrsp_led_work[work_idx].work, K_MSEC(delay_ms));
	// lock soc off
	rrsp_led_lock_sleep(true);
}

static void rrsp_led_cancel_pattern(rrsp_led_pattern_idx_t pattern)
{
	uint8_t work_idx = rrsp_led_get_workidx_by_pattern(pattern);
	if (work_idx >= RRSP_LED_WORK_MAX) {
		return;
	}

	// Check the work is available or not
	if (rrsp_led_work[work_idx].active_pattern != pattern) {
		LOG_ERR("The LED pattern-%u is not working, %u", pattern,
			rrsp_led_work[work_idx].active_pattern);
		return;
	}

	k_work_cancel_delayable(&rrsp_led_work[work_idx].work);
	rrsp_led_work[work_idx].active_pattern = RRSP_LED_PAT_INVALID;

	// turn off the related LED
	if (work_idx == RRSP_LED_WORK_BG) {
		const rrsp_led_pattern_t *curr_ptn = &rrsp_led_pattern[pattern];
		uint8_t evt_led_mask = 0;

		if (rrsp_led_work[RRSP_LED_WORK_EVT].active_pattern != RRSP_LED_PAT_INVALID) {
			evt_led_mask =
				rrsp_led_pattern[rrsp_led_work[RRSP_LED_WORK_EVT].active_pattern]
					.led_mask;
		}

		// Set LED
		for (uint8_t idx = 0; idx < RRSP_LED_IDX_MAX; idx++) {
			if (!(curr_ptn->led_mask & LED_MASK(idx)) ||
			    (evt_led_mask & LED_MASK(idx))) {
				continue;
			}
			led_off(rrsp_led, idx);
		}
	}
	// unlock soc off
	rrsp_led_lock_sleep(false);
}

static void rrsp_led_pattern_cmp(rrsp_led_pattern_idx_t pattern)
{
	LOG_DBG("Completed LED pattern-%u", pattern);

	uint8_t work_idx = rrsp_led_get_workidx_by_pattern(pattern);
	if (work_idx >= RRSP_LED_WORK_MAX) {
		return;
	}

	// Check the work is available or not
	if (rrsp_led_work[work_idx].active_pattern != pattern) {
		LOG_ERR("The LED pattern-%u is not active, %u", pattern,
			rrsp_led_work[work_idx].active_pattern);
		return;
	}

	rrsp_led_work[work_idx].active_pattern = RRSP_LED_PAT_INVALID;
	// Unlock soc off
	rrsp_led_lock_sleep(false);
}

static void rrsp_led_handler(struct k_work *work)
{
	struct k_work_delayable *d_work = k_work_delayable_from_work(work);
	struct rrsp_led_wrok_info *info = CONTAINER_OF(d_work, struct rrsp_led_wrok_info, work);

	if (info->active_pattern >= RRSP_LED_PAT_MAX) {
		LOG_ERR("Unexpected LED pattern-%u", info->active_pattern);
		info->active_pattern = RRSP_LED_PAT_INVALID;
	} else if (info->next_seq >= rrsp_led_pattern[info->active_pattern].valid_seq) {
		LOG_ERR("Unexpected Sequence-%u", info->active_pattern);
		info->active_pattern = RRSP_LED_PAT_INVALID;
	} else if (rrsp_led_pattern[info->active_pattern].repeat_times &&
		   (info->repeat >= rrsp_led_pattern[info->active_pattern].repeat_times)) {
		LOG_ERR("Unexpected repeat-%u", info->repeat);
		info->active_pattern = RRSP_LED_PAT_INVALID;
	}

	if (info->active_pattern == RRSP_LED_PAT_INVALID) {
		// Unlock soc off
		rrsp_led_lock_sleep(false);
		return;
	}

	const rrsp_led_pattern_t *curr_ptn = &rrsp_led_pattern[info->active_pattern];
	// Set LED
	for (uint8_t idx = 0; idx < RRSP_LED_IDX_MAX; idx++) {
		if (!(curr_ptn->led_mask & LED_MASK(idx))) {
			continue;
		}

		if (curr_ptn->active_led[info->next_seq] & LED_MASK(idx)) {
			// Set led on
			led_on(rrsp_led, idx);
		} else {
			// Set led off
			led_off(rrsp_led, idx);
		}
	}

	// Check the pattern finished
	if ((info->next_seq + 1) == curr_ptn->valid_seq) {
		info->repeat += 1;
		if (curr_ptn->repeat_times && (info->repeat == curr_ptn->repeat_times)) {
			// LED complete
			rrsp_led_pattern_cmp(info->active_pattern);
			return;
		}
	}
	// Set timer for next sequence
	atm_work_reschedule_for_app_work_q(d_work, K_MSEC(curr_ptn->dur_ms[info->next_seq]));
	info->next_seq += 1;

	if (info->next_seq == curr_ptn->valid_seq) {
		info->next_seq = 0;
	}
}

static int rrsp_led_init(void)
{
	if (!device_is_ready(rrsp_led)) {
		LOG_ERR("LED device is not ready\n");
		return -ENXIO;
	}

	k_work_init_delayable(&rrsp_led_work[RRSP_LED_WORK_EVT].work, rrsp_led_handler);
	k_work_init_delayable(&rrsp_led_work[RRSP_LED_WORK_BG].work, rrsp_led_handler);
	rrsp_led_work[RRSP_LED_WORK_EVT].active_pattern = RRSP_LED_PAT_INVALID;
	rrsp_led_work[RRSP_LED_WORK_BG].active_pattern = RRSP_LED_PAT_INVALID;

	return 0;
}

SYS_INIT(rrsp_led_init, POST_KERNEL, CONFIG_APPLICATION_INIT_PRIORITY);

void rrsp_led_cancel_all_bg(void)
{
	if (rrsp_led_work[RRSP_LED_WORK_BG].active_pattern == RRSP_LED_PAT_INVALID) {
		return;
	}
	LOG_WRN("Active LED pat:%u", rrsp_led_work[RRSP_LED_WORK_BG].active_pattern);
	k_work_cancel_delayable(&rrsp_led_work[RRSP_LED_WORK_BG].work);
	rrsp_led_work[RRSP_LED_WORK_BG].active_pattern = RRSP_LED_PAT_INVALID;
	// unlock soc off
	rrsp_led_lock_sleep(false);
}
#endif

void rrsp_led_update(rrsp_led_pattern_idx_t pattern, bool enable)
{
	LOG_INF("%s LED %u", enable ? "Enable" : "Disable", pattern);
#ifdef CONFIG_LED
	if (!device_is_ready(rrsp_led)) {
		LOG_ERR("LED device is not ready\n");
		return;
	}
	if (enable) {
		rrsp_led_start_pattern(pattern);
	} else {
		rrsp_led_cancel_pattern(pattern);
	}
#endif
}
