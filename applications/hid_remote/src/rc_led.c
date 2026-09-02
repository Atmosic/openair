/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/__assert.h>

#include "rc_led.h"

LOG_MODULE_REGISTER(rc_led, CONFIG_HID_REMOTE_LOG_LEVEL);

BUILD_ASSERT(DT_NODE_HAS_STATUS_OKAY(DT_ALIAS(led0)),
	     "CONFIG_RC_LED=y requires a led0 alias in the board devicetree");

/* ── LED hardware ───────────────────────────────────────────────────────── */

static const struct gpio_dt_spec rc_led = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);

/* ── Blink work ─────────────────────────────────────────────────────────── */

static struct k_work_delayable led_blink_work;
static int32_t led_period_ms;

static void led_blink_handler(struct k_work *work)
{
	struct k_work_delayable *dwork = k_work_delayable_from_work(work);

	gpio_pin_toggle_dt(&rc_led);
	k_work_reschedule(dwork, K_MSEC(led_period_ms));
}

static void led_blink_start(int32_t period_ms)
{
	k_work_cancel_delayable(&led_blink_work);
	led_period_ms = period_ms;
	k_work_reschedule(&led_blink_work, K_NO_WAIT);
}

static void led_blink_stop(void)
{
	k_work_cancel_delayable(&led_blink_work);
	gpio_pin_set_dt(&rc_led, 0);
}

/* ── Blink period table ──────────────────────────────────────────────────── */

/* Blink periods:
 *   Reconnecting: 10cs on/off = 100 ms (fast, urgent)
 *   Pairing:      25cs on/off = 250 ms (slower, discovery) */
static const int32_t led_period_table[] = {
	[RC_LED_OFF] = 0,
	[RC_LED_PAIRING] = 250,
	[RC_LED_RECONNECTING] = 100,
	[RC_LED_FMP_MILD] = 500,
	[RC_LED_FMP_HIGH] = 125,
	[RC_LED_ON] = 0,
};

/* ── Public API ─────────────────────────────────────────────────────────── */

void rc_led_init(void)
{
	if (!gpio_is_ready_dt(&rc_led)) {
		LOG_ERR("LED GPIO not ready");
		return;
	}
	gpio_pin_configure_dt(&rc_led, GPIO_OUTPUT_INACTIVE);
	k_work_init_delayable(&led_blink_work, led_blink_handler);
	LOG_INF("LED init OK");
}

void rc_led_set(enum rc_led_mode mode)
{
	if (mode == RC_LED_OFF) {
		LOG_DBG("LED: off");
		led_blink_stop();
	} else if (mode == RC_LED_ON) {
		LOG_DBG("LED: on");
		k_work_cancel_delayable(&led_blink_work);
		gpio_pin_set_dt(&rc_led, 1);
	} else {
		LOG_DBG("LED: mode %d (%d ms)", mode, led_period_table[mode]);
		led_blink_start(led_period_table[mode]);
	}
}
