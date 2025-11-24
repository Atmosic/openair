/**
 *******************************************************************************
 *
 * @file platform_ctrl_led.c
 *
 * @brief Platform control led For Multimode Consumer Tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/logging/log.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/led.h>
#include <zephyr/kernel.h>
#include "platform_ctrl_led.h"
#include "app_work_q.h"

LOG_MODULE_DECLARE(multimode_consumer_tag, CONFIG_MULTIMODE_CONSUMER_TAG_LOG_LEVEL);

#ifdef CONFIG_TAG_LED_IND

typedef enum tag_led_index_e {
	LED_IDX_STS_GREEN,
	LED_IDX_STS_RED,
	LED_IDX_BAT_GREEN,
	LED_IDX_BAT_RED,

	LED_IDX_MAX
} tag_led_index_t;

#define LED_BLINK_PATTERN_MAX 4

struct led_blink_pattern {
	uint32_t led_idx;
	bool on;
	uint32_t duration_ms;
};

struct led_blink_param {
	uint32_t pattern_num;
	uint32_t pattern_idx;
	uint32_t count;
	struct led_blink_pattern pattern[LED_BLINK_PATTERN_MAX];
};

static const struct device *const led_dev = DEVICE_DT_GET_ONE(gpio_leds);
static struct led_blink_param background_param;
static struct led_blink_param event_param;

static void led_background_work_handler(struct k_work *work);
static void led_event_work_handler(struct k_work *work);

static K_WORK_DELAYABLE_DEFINE(led_background_work, led_background_work_handler);
static K_WORK_DELAYABLE_DEFINE(led_event_work, led_event_work_handler);

static void led_pattern_process(struct led_blink_param *param, struct k_work *work)
{
	struct k_work_delayable *timer_work = k_work_delayable_from_work(work);

	if (!device_is_ready(led_dev)) {
		return;
	}

	if (param->pattern_num == 0) {
		return;
	}

	if (param->pattern[param->pattern_idx].on) {
		led_on(led_dev, param->pattern[param->pattern_idx].led_idx);
	} else {
		led_off(led_dev, param->pattern[param->pattern_idx].led_idx);
	}

	if ((param->pattern_idx + 1) == param->pattern_num && param->count) {
		// If count is set, we are in event mode
		param->count--;
		if (param->count == 0) {
			// Event completed
			return;
		}
	}

	atm_work_reschedule_for_app_work_q(timer_work,
					   K_MSEC(param->pattern[param->pattern_idx].duration_ms));

	param->pattern_idx = (param->pattern_idx + 1) % param->pattern_num;
}

static void led_background_work_handler(struct k_work *work)
{
	led_pattern_process(&background_param, work);
}

static void led_event_work_handler(struct k_work *work)
{
	led_pattern_process(&event_param, work);
}

static void led_blink_background(struct led_blink_pattern *pattern, uint32_t pattern_num)
{
	if (pattern_num > LED_BLINK_PATTERN_MAX) {
		LOG_ERR("Pattern number:%d exceeds max:%d ", pattern_num, LED_BLINK_PATTERN_MAX);
		return;
	}
	background_param.pattern_num = pattern_num;
	background_param.pattern_idx = 0;
	background_param.count = 0; // continue indefinitely
	memcpy(background_param.pattern, pattern, pattern_num * sizeof(struct led_blink_pattern));
	atm_work_reschedule_for_app_work_q(&led_background_work, K_NO_WAIT);
}

static void led_blink_event(struct led_blink_pattern *pattern, uint32_t pattern_num, uint32_t count)
{
	if (pattern_num > LED_BLINK_PATTERN_MAX) {
		LOG_ERR("Pattern number:%d exceeds max:%d ", pattern_num, LED_BLINK_PATTERN_MAX);
		return;
	}
	event_param.pattern_num = pattern_num;
	event_param.pattern_idx = 0;
	event_param.count = count;
	memcpy(event_param.pattern, pattern, pattern_num * sizeof(struct led_blink_pattern));
	atm_work_reschedule_for_app_work_q(&led_event_work, K_NO_WAIT);
}

static void led_blink_blocking(struct led_blink_pattern *pattern, uint32_t pattern_num,
			       uint32_t count)
{
	if (!device_is_ready(led_dev)) {
		return;
	}

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < pattern_num; j++) {
			if (pattern[j].on) {
				led_on(led_dev, pattern[j].led_idx);
			} else {
				led_off(led_dev, pattern[j].led_idx);
			}
			k_sleep(K_MSEC(pattern[j].duration_ms));
		}
	}
}

static void led_blink_stop(void)
{
	k_work_cancel_delayable(&led_background_work);
	k_work_cancel_delayable(&led_event_work);
	background_param.pattern_num = 0;
	event_param.pattern_num = 0;
	if (!device_is_ready(led_dev)) {
		return;
	}
	for (int i = 0; i < LED_IDX_MAX; i++) {
		led_off(led_dev, i);
	}
}
#endif

void platform_ctrl_led_state_update(led_state_t state)
{
	LOG_INF("LED state update: %d", state);

#ifdef CONFIG_TAG_LED_IND
	switch (state) {
	case LED_STATE_PAIRING: {
		// Green->Red LED blinking every 5 seconds in pairing mode
		struct led_blink_pattern pattern[] = {
			{LED_IDX_STS_GREEN, true, 300},
			{LED_IDX_STS_GREEN, false, 0},
			{LED_IDX_STS_RED, true, 300},
			{LED_IDX_STS_RED, false, 4400},
		};
		led_blink_background(pattern, ARRAY_SIZE(pattern));
		break;
	}
	case LED_STATE_PAIRED: {
		// Green LED blinks every 20 seconds in operation mode
		struct led_blink_pattern pattern[] = {
			{LED_IDX_STS_GREEN, true, 300},
			{LED_IDX_STS_GREEN, false, 19700},
		};
		led_blink_background(pattern, ARRAY_SIZE(pattern));
		break;
	}
	case LED_STATE_OTA_MODE: {
		// Red LED blinks every 1 second in OTA mode
		struct led_blink_pattern pattern[] = {
			{LED_IDX_STS_RED, true, 100},
			{LED_IDX_STS_RED, false, 900},
		};
		led_blink_background(pattern, ARRAY_SIZE(pattern));
		break;
	}
	case LED_STATE_POWER_OFF:
		// No LED indication for invalid state
		led_blink_stop();
		break;
	default:
		break;
	}
#endif
}

void platform_ctrl_led_event_indicate(led_event_t event)
{
	LOG_INF("LED event indicate: %d", event);

#ifdef CONFIG_TAG_LED_IND
	struct led_blink_pattern batt_pattern[] = {
		{LED_IDX_BAT_GREEN, true, 250},
		{LED_IDX_BAT_GREEN, false, 250},
	};

	switch (event) {
	case LED_EVT_POWER_ON: {
		// Green LED blinks 3 times at 0.5s interval
		struct led_blink_pattern pattern[] = {
			{LED_IDX_STS_GREEN, true, 250},
			{LED_IDX_STS_GREEN, false, 250},
		};
		led_blink_blocking(pattern, ARRAY_SIZE(pattern), 3);
		break;
	}
	case LED_EVT_POWER_OFF: {
		// Red LED blinks 3 times at 0.5s interval
		struct led_blink_pattern pattern[] = {
			{LED_IDX_STS_RED, true, 250},
			{LED_IDX_STS_RED, false, 250},
		};
		led_blink_blocking(pattern, ARRAY_SIZE(pattern), 3);
		break;
	}
	case LED_EVT_FACTORY_RESET:
		break;
	case LED_EVT_BATT_FULL:
		// 5 blinks for >90%
		led_blink_event(batt_pattern, ARRAY_SIZE(batt_pattern), 5);
		break;
	case LED_EVT_BATT_HIGH:
		// 4 blinks for >60%
		led_blink_event(batt_pattern, ARRAY_SIZE(batt_pattern), 4);
		break;
	case LED_EVT_BATT_MEDIUM:
		// 3 blinks for >30%
		led_blink_event(batt_pattern, ARRAY_SIZE(batt_pattern), 3);
		break;
	case LED_EVT_BATT_LOW:
		// 2 blinks for >10%
		led_blink_event(batt_pattern, ARRAY_SIZE(batt_pattern), 2);
		break;
	case LED_EVT_BATT_CRITICAL:
		// 1 blink for <=10%
		led_blink_event(batt_pattern, ARRAY_SIZE(batt_pattern), 1);
		break;
	default:
		break;
	}
#endif
}
