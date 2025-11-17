/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025 Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/input/input.h>
#include <zephyr/logging/log.h>

#ifdef CONFIG_SENSOR_BEACON_BUTTON_POWER_CONTROL
#include <zephyr/drivers/hwinfo.h>
#endif

#include <inttypes.h>

#include "led_button_ctrl.h"

LOG_MODULE_REGISTER(led_button_ctrl, CONFIG_SENSOR_BEACON_LOG_LEVEL);

/* Device tree definitions */
#define SW0_NODE  DT_ALIAS(sw0)
#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)

/* Check if button and LEDs are available */
#if DT_NODE_EXISTS(SW0_NODE) && IS_ENABLED(CONFIG_SENSOR_BEACON_BUTTON_POWER_CONTROL)
static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(SW0_NODE, gpios);
#define HAS_BUTTON 1
#else
#define HAS_BUTTON 0
#endif

#if DT_NODE_EXISTS(LED0_NODE)
static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
#define HAS_LED0 1
#else
#define HAS_LED0 0
#endif

#if DT_NODE_EXISTS(LED1_NODE)
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
#define HAS_LED1 1
#else
#define HAS_LED1 0
#endif

#define HAS_LED (HAS_LED0 || HAS_LED1)

/* Configuration constants */
#define BUTTON_LONG_PRESS_MS      2000 /* 2 seconds for device ON/OFF */
#define LED_POWER_BLINK_COUNT     3    /* 3 blinks for power ON/OFF */
#define LED_POWER_BLINK_PERIOD    500  /* 0.5s interval */
#define LED_BEACON_BLINK_DURATION 100  /* 0.1s duration */
#define BEACON_COUNT_FOR_LED      10   /* Show LED every 10 beacon updates */

#ifdef CONFIG_SENSOR_BEACON_BUTTON_POWER_CONTROL
#define BUTTON_POLL_INTERVAL_MS 100 /* Button polling interval during power-on check */
#endif

/* LED types for direct control */
typedef enum {
	LED_TYPE_PRIMARY,
	LED_TYPE_SECONDARY
} led_type_t;

/* State variables */
static device_state_t current_state = DEVICE_STATE_INIT;
static struct k_spinlock state_lock;
static button_event_cb_t button_cb;
static device_state_cb_t state_cb;
static uint32_t beacon_count;

#if HAS_BUTTON
/* Button handling */
static struct gpio_callback button_cb_data;
static struct k_work_delayable button_work;
static int64_t button_press_time;
static bool button_pressed;
#endif

/* LED work items */
static struct k_work_delayable led_work;
static led_indication_t pending_indication;

/* Pending state change after LED indication completes */
static device_state_t pending_state_after_led = DEVICE_STATE_INIT;
static bool has_pending_state_change;

int led_button_ctrl_register_button_cb(button_event_cb_t cb)
{
	button_cb = cb;
	return 0;
}

int led_button_ctrl_register_state_cb(device_state_cb_t cb)
{
	state_cb = cb;
	return 0;
}

device_state_t led_button_ctrl_get_device_state(void)
{
	k_spinlock_key_t key = k_spin_lock(&state_lock);
	device_state_t state = current_state;
	k_spin_unlock(&state_lock, key);
	return state;
}

void led_button_ctrl_set_device_state(device_state_t state)
{
	k_spinlock_key_t key = k_spin_lock(&state_lock);

	if (current_state == state) {
		k_spin_unlock(&state_lock, key);
		return;
	}

	LOG_INF("Device state change: %d -> %d", current_state, state);

	current_state = state;

	k_spin_unlock(&state_lock, key);

	/* Call callback outside the lock to avoid potential deadlocks */
	if (state_cb) {
		state_cb(state);
	}
}

int led_button_ctrl_show_indication(led_indication_t indication)
{
#if HAS_LED
	pending_indication = indication;
	k_work_reschedule(&led_work, K_NO_WAIT);
	return 0;
#else
	LOG_DBG("LED indication requested but no LED available");
	return -ENODEV;
#endif
}

int led_button_ctrl_notify_beacon_tx(void)
{
	beacon_count++;

	if (beacon_count >= BEACON_COUNT_FOR_LED) {
		beacon_count = 0;
		return led_button_ctrl_show_indication(LED_IND_BEACON_STATUS);
	}

	return 0;
}

#if HAS_BUTTON
/* Button interrupt handler */
static void button_pressed_handler(const struct device *dev, struct gpio_callback *cb,
				   uint32_t pins)
{
	ARG_UNUSED(dev);
	ARG_UNUSED(cb);
	ARG_UNUSED(pins);

	bool current_pressed = gpio_pin_get_dt(&button);

	if (current_pressed && !button_pressed) {
		/* Button press detected */
		button_press_time = k_uptime_get();
		button_pressed = true;
		LOG_DBG("Button pressed");
	} else if (!current_pressed && button_pressed) {
		/* Button release detected */
		int64_t duration = k_uptime_get() - button_press_time;
		button_pressed = false;

		LOG_DBG("Button released after %" PRId64 "ms", duration);

		/* Schedule work to handle button event */
		k_work_reschedule(&button_work, K_MSEC(10));

		if (button_cb) {
			button_cb(false, (uint32_t)duration);
		}
	}
}
#endif

#if HAS_BUTTON
/* Button work handler - processes button events */
static void button_work_handler(struct k_work *work)
{
	ARG_UNUSED(work);

	int64_t duration = k_uptime_get() - button_press_time;

	if (duration >= BUTTON_LONG_PRESS_MS) {
		/* Long press detected - toggle device state */
		if (current_state == DEVICE_STATE_OFF) {
			/* Turn device ON - state change happens immediately, LED indication follows
			 */
			led_button_ctrl_set_device_state(DEVICE_STATE_ON);
			led_button_ctrl_show_indication(LED_IND_POWER_ON);
		} else {
			/* Turn device OFF - defer state change until after LED indication completes
			 */
			pending_state_after_led = DEVICE_STATE_OFF;
			has_pending_state_change = true;
			led_button_ctrl_show_indication(LED_IND_POWER_OFF);
		}
	}
}
#endif

/* Helper function to set LED state based on LED type */
static void set_led_state(led_type_t led_type, bool state)
{
#if HAS_LED
	const struct gpio_dt_spec *target_led = NULL;

	/* Select LED based on type and availability */
	switch (led_type) {
	case LED_TYPE_PRIMARY:
		/* Primary LED: led0 (Green on tag, Red on EVK) */
#if HAS_LED0
		target_led = &led0;
#endif
		break;

	case LED_TYPE_SECONDARY:
		/* Secondary LED: led1 (Red on tag, Yellow on EVK), fallback to led0 */
#if HAS_LED1
		target_led = &led1;
#elif HAS_LED0
		target_led = &led0; /* Fallback to primary LED */
#endif
		break;
	}

	/* Set the LED state */
	if (target_led) {
		gpio_pin_set_dt(target_led, state);
	}
#endif
}

/* Helper function to blink LED pattern */
static void blink_led_pattern(led_type_t led_type, int count, int period_ms)
{
#if HAS_LED
	for (int i = 0; i < count; i++) {
		set_led_state(led_type, true);
		k_msleep(period_ms / 2);
		set_led_state(led_type, false);
		if (i < count - 1) {
			k_msleep(period_ms / 2);
		}
	}
#endif
}

/* Show LED pattern based on indication type */
static void show_led_pattern(led_indication_t indication)
{
#if HAS_LED
	switch (indication) {
	case LED_IND_POWER_ON:
		LOG_INF("Showing power ON indication (Primary LED blinks 3 times)");
		/* Primary LED (led0) blinks 3 times at 0.5s interval */
		blink_led_pattern(LED_TYPE_PRIMARY, LED_POWER_BLINK_COUNT, LED_POWER_BLINK_PERIOD);
		break;

	case LED_IND_POWER_OFF:
		LOG_INF("Showing power OFF indication (Secondary LED blinks 3 times)");
		/* Secondary LED (led1) blinks 3 times at 0.5s interval, fallback to primary */
		blink_led_pattern(LED_TYPE_SECONDARY, LED_POWER_BLINK_COUNT,
				  LED_POWER_BLINK_PERIOD);
		break;

	case LED_IND_BEACON_STATUS:
		LOG_DBG("Showing beacon status indication (Primary LED blink)");
		/* Primary LED (led0) blinks once for 0.1s */
		set_led_state(LED_TYPE_PRIMARY, true);
		k_msleep(LED_BEACON_BLINK_DURATION);
		set_led_state(LED_TYPE_PRIMARY, false);
		break;

	default:
		LOG_WRN("Unknown LED indication: %d", indication);
		break;
	}
#else
	LOG_DBG("LED indication requested but no LED available");
#endif
}

/* LED work handler - shows LED patterns */
static void led_work_handler(struct k_work *work)
{
	ARG_UNUSED(work);

	/* Show the LED pattern (this blocks until pattern completes) */
	show_led_pattern(pending_indication);

	/* Apply pending state change after LED indication completes */
	if (has_pending_state_change) {
		has_pending_state_change = false;
		led_button_ctrl_set_device_state(pending_state_after_led);
		LOG_DBG("Applied pending state change to %d after LED indication",
			pending_state_after_led);
	}
}

int led_button_ctrl_gpio_init(void)
{
	int ret;

	static bool gpio_initialized;
	if (gpio_initialized) {
		return 0;
	}

	LOG_INF("Initializing button and LED GPIO");

#if HAS_BUTTON
	if (!gpio_is_ready_dt(&button)) {
		LOG_ERR("Button device not ready");
		return -ENODEV;
	}

	ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
	if (ret) {
		LOG_ERR("Failed to configure button GPIO: %d", ret);
		return ret;
	}

	ret = gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_BOTH);
	if (ret) {
		LOG_ERR("Failed to configure button interrupt: %d", ret);
		return ret;
	}

	LOG_INF("Button GPIO initialized on pin %d", button.pin);
#else
	LOG_DBG("No button available on this board");
#endif

#if HAS_LED0
	if (!gpio_is_ready_dt(&led0)) {
		LOG_ERR("LED0 GPIO device not ready");
		return -ENODEV;
	}

	ret = gpio_pin_configure_dt(&led0, GPIO_OUTPUT_INACTIVE);
	if (ret) {
		LOG_ERR("Failed to configure LED0 GPIO: %d", ret);
		return ret;
	}

	LOG_INF("LED0 (primary) initialized on pin %d", led0.pin);
#endif

#if HAS_LED1
	if (!gpio_is_ready_dt(&led1)) {
		LOG_ERR("LED1 GPIO device not ready");
		return -ENODEV;
	}

	ret = gpio_pin_configure_dt(&led1, GPIO_OUTPUT_INACTIVE);
	if (ret) {
		LOG_ERR("Failed to configure LED1 GPIO: %d", ret);
		return ret;
	}

	LOG_INF("LED1 (secondary) initialized on pin %d", led1.pin);
#endif

	gpio_initialized = true;
	return 0;
}

#ifdef CONFIG_SENSOR_BEACON_BUTTON_POWER_CONTROL

bool led_button_ctrl_check_power_on(void)
{
	int ret = led_button_ctrl_gpio_init();
	if (ret) {
		LOG_ERR("GPIO init failed: %d", ret);
		return false; // Fail-safe: stay off on error
	}

	uint32_t reset_cause;
	hwinfo_get_reset_cause(&reset_cause);

	if (reset_cause & (RESET_SOFTWARE | RESET_WATCHDOG) || (reset_cause == RESET_HARDWARE)) {
		LOG_INF("Direct power on (software/watchdog/hardware reset)");
		return true;
	}

	int64_t timestamp = k_uptime_get();
	while (gpio_pin_get_dt(&button)) {
		k_sleep(K_MSEC(BUTTON_POLL_INTERVAL_MS));
		if (k_uptime_get() - timestamp > BUTTON_LONG_PRESS_MS) {
			// Long press detected - show power ON LED indication
			show_led_pattern(LED_IND_POWER_ON);
			break;
		}
	}

	if (k_uptime_delta(&timestamp) < BUTTON_LONG_PRESS_MS) {
		LOG_INF("Waiting for button press longer than %dms - staying off",
			BUTTON_LONG_PRESS_MS);
		return false; // Stay off
	}

	LOG_INF("Device powering on");
	return true;
}

#endif /* CONFIG_SENSOR_BEACON_BUTTON_POWER_CONTROL */

int led_button_ctrl_init(void)
{
	int ret;

	LOG_INF("Initializing LED and button control");

	// Initialize GPIO if not already done
	ret = led_button_ctrl_gpio_init();
	if (ret) {
		return ret;
	}

#if HAS_BUTTON
	// Set up button callback and work items
	gpio_init_callback(&button_cb_data, button_pressed_handler, BIT(button.pin));
	gpio_add_callback(button.port, &button_cb_data);

	k_work_init_delayable(&button_work, button_work_handler);
	LOG_INF("Button callbacks and work items initialized");
#endif

#if HAS_LED
	k_work_init_delayable(&led_work, led_work_handler);
	LOG_INF("LED work items initialized");
#endif

	beacon_count = 0;
	LOG_INF("LED and button control initialized successfully");
	return 0;
}
