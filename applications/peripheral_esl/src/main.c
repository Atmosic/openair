/**
 *******************************************************************************
 *
 * @file main.c
 *
 * @brief Peripheral ESL application entry point
 *
 * Copyright (c) 2024-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/watchdog.h>
#include <zephyr/drivers/gpio.h>

#include <zephyr/logging/log.h>
#include <zephyr/settings/settings.h>

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/hci.h>
#include "esls.h"
#if CONFIG_BT_ESLS_SENSOR_NUM > 0
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>
#if CONFIG_ENS210_TEMPERATURE_SINGLE && CONFIG_ENS210_HUMIDITY_SINGLE
#define ENS210_SINGLE
#endif
#endif // CONFIG_BT_ESLS_SENSOR_NUM > 0
#ifdef CONFIG_PM
#include <zephyr/pm/pm.h>
#endif
#if CONFIG_BT_ESLS_IMAGE_NUM > 0
#include "esl_image.h"
#endif
#if CONFIG_BT_ESLS_DISPLAY_NUM > 0
#include "esl_display.h"
#endif
#include "app_work_q.h"
#ifdef CONFIG_ATM_VENDOR_API
#include "atm_vendor_api.h"
#endif

#if CONFIG_BT_ESLS_LED_NUM > 0
#include <zephyr/device.h>
#include <zephyr/drivers/led.h>
#endif

LOG_MODULE_REGISTER(main, LOG_LEVEL_WRN);

#define SLEEP_TIME        K_SECONDS(3)
#define WDT_MIN_WINDOW_MS 0
#define WDT_MAX_WINDOW_MS 5000

#define SW0_NODE DT_ALIAS(sw0)

static struct device const *wdog_dev = DEVICE_DT_GET(DT_ALIAS(watchdog0));
static int wdt_channel_id;

#ifdef CONFIG_PM
static void wdog_poke(enum pm_state state)
{
	wdt_feed(wdog_dev, wdt_channel_id);
}

static struct pm_notifier notifier = {
	.state_entry = wdog_poke,
	.state_exit = wdog_poke,
};
#endif

static void connected(struct bt_conn *conn, uint8_t err)
{
	if (err) {
		LOG_ERR("Connection failed err:%d", err);
		return;
	}
	LOG_INF("Connected");
#ifdef CONFIG_VND_API_SET_CON_TX_POWER
	{
		uint16_t conn_hdl;
		if (bt_hci_get_conn_handle(conn, &conn_hdl)) {
			LOG_ERR("Get con hdl fail");
			return;
		}
		if (atm_vendor_set_con_tx_power(conn_hdl, TX_POWER_0_DBM)) {
			LOG_ERR("Set con tx pwr fail");
		}
	}
#endif
}

static void disconnected(struct bt_conn *conn, uint8_t reason)
{
	LOG_INF("Disconnected reason:%#x", reason);
}

BT_CONN_CB_DEFINE(conn_callbacks) = {
	.connected = connected,
	.disconnected = disconnected,
};

#if CONFIG_BT_ESLS_SENSOR_NUM > 0
const struct device *dev;
#ifdef ENS210_SINGLE
#define CONFIG_SENSOR_WQ_STACK_SIZE 1024
static K_THREAD_STACK_DEFINE(sensor_stack_area, CONFIG_SENSOR_WQ_STACK_SIZE);
static struct k_work_q sensor_wq;
static struct sensor_value temperature;
static int sensor_status = -EBUSY;

static struct read_sensor_work_info {
	struct k_work work;
} read_sensor_work;

static void read_sensor_handler(struct k_work *work)
{
	int err = sensor_sample_fetch(dev);
	if (err) {
		sensor_status = err;
		LOG_ERR("%s sensor_status:%d", __func__, sensor_status);
		return;
	}
	sensor_status = sensor_channel_get(dev, SENSOR_CHAN_AMBIENT_TEMP, &temperature);
	if (sensor_status) {
		LOG_ERR("%s sensor_status:%d", __func__, sensor_status);
	}
}
#endif

static void sensor_init(void)
{
	dev = DEVICE_DT_GET_ANY(ams_ens210);
	if (!device_is_ready(dev)) {
		LOG_WRN("Device %s is not ready, connect JP25", dev->name);
	}

#ifdef ENS210_SINGLE
	k_work_queue_init(&sensor_wq);
	k_work_queue_start(&sensor_wq, sensor_stack_area, K_THREAD_STACK_SIZEOF(sensor_stack_area),
			   K_LOWEST_APPLICATION_THREAD_PRIO, NULL);
	k_thread_name_set(&sensor_wq.thread, "SENSOR WQ");

	k_work_init(&read_sensor_work.work, read_sensor_handler);
#endif
}

static int sensor_read_data(uint8_t sensor_idx, uint8_t *sensor_data, uint8_t *sensor_data_len)
{
	if (!dev) {
		return -ENOTSUP;
	}
	int err;
#ifdef ENS210_SINGLE
	if (sensor_status) {
		err = sensor_status;
		if (sensor_status == -EBUSY) {
			k_work_submit_to_queue(&sensor_wq, &read_sensor_work.work);
		} else {
			// reset sensor_status, let reading sensor next time
			sensor_status = -EBUSY;
		}
		return err;
	}
	// reset sensor_status, let reading sensor next time
	sensor_status = -EBUSY;
#else
	err = sensor_sample_fetch(dev);
	if (err) {
		LOG_ERR("sample err:%d", err);
		return err;
	}
	struct sensor_value temperature;
	err = sensor_channel_get(dev, SENSOR_CHAN_AMBIENT_TEMP, &temperature);
	if (err) {
		LOG_ERR("channel err:%d", err);
		return err;
	}
#endif
	*sensor_data_len = sizeof(temperature);
	memcpy(sensor_data, &temperature, *sensor_data_len);
	LOG_INF("Temperature: %d.%06d C", temperature.val1, temperature.val2);
	return 0;
}
#endif // CONFIG_BT_ESLS_SENSOR_NUM > 0

#if CONFIG_BT_ESLS_ADV_MANU_DATA_MAX
static uint8_t esl_adv_manu_data[CONFIG_BT_ESLS_ADV_MANU_DATA_MAX];
static uint8_t esl_adv_len;
static int factory_esl_manu_data_handle_set(char const *name, size_t len, settings_read_cb read_cb,
					    void *cb_arg)
{
	if (name) {
		LOG_ERR("%s unexpect name:%s len:%u", __func__, name, len);
		return 0;
	} else if (len > sizeof(esl_adv_manu_data)) {
		LOG_ERR("%s len:%u", __func__, len);
		return 0;
	}

	read_cb(cb_arg, esl_adv_manu_data, sizeof(esl_adv_manu_data));
	esl_adv_len = len;
	LOG_INF("%s esl_adv_len:%u data[0]:%x", __func__, esl_adv_len, esl_adv_manu_data[0]);

	return 0;
}

SETTINGS_STATIC_HANDLER_DEFINE(factory, "FACTORY/ESL_MANU", NULL, factory_esl_manu_data_handle_set,
			       NULL, NULL);
#endif

#if CONFIG_BT_ESLS_LED_NUM > 0
static const struct device *const led = DEVICE_DT_GET_ONE(gpio_leds);

static int esl_led_control(uint8_t led_idx, bool on_off, uint8_t color_brightness_info)
{
	uint8_t brightness = (ESLS_LED_CTRL_BRIGHTNESS(color_brightness_info) + 1) * 25;
	LOG_INF("led_idx=%d, on_off=%x, brightness=%x", led_idx, on_off, brightness);

	if (on_off) {
		led_set_brightness(led, led_idx, brightness);
	} else {
		led_off(led, led_idx);
	}

	return 0;
}
#endif

static void bt_ready(int err)
{
	LOG_INF("%s", __func__);

	if (IS_ENABLED(CONFIG_SETTINGS)) {
		settings_load();
	}

	struct bt_esls_init_param init_param = {
#if CONFIG_BT_ESLS_SENSOR_NUM > 0
#define PROPERTY_AMBIENT_TEMP 0x004F
		.sensors_info[0] =
			{
				.type = BT_ESLS_SIZE_TYPE_16_BITS,
				.property_id = PROPERTY_AMBIENT_TEMP,
			},
		.sensor_read_data = sensor_read_data,
#endif
	};

#if CONFIG_BT_ESLS_IMAGE_NUM > 0
	esl_img_init_img_info(&init_param);
#endif

#if CONFIG_BT_ESLS_DISPLAY_NUM > 0
	esl_display_init_dsp_info(&init_param);
#endif

#if CONFIG_BT_ESLS_ADV_MANU_DATA_MAX
	init_param.app_adv_data = esl_adv_manu_data;
	init_param.app_adv_len = esl_adv_len;
#endif

#if CONFIG_BT_ESLS_LED_NUM > 0
	init_param.led_control = esl_led_control;
	memset(&init_param.led, 0, sizeof(init_param.led));

	// Red LED
	ESLS_LED_INFO_LED_TYPE_SET(init_param.led[0], BT_ESLS_LED_TYPE_MONOCHROME);
	ESLS_LED_INFO_RED_SET(init_param.led[0], 0x03);

#if CONFIG_BT_ESLS_LED_NUM >= 2
	// Yellow LED
	ESLS_LED_INFO_LED_TYPE_SET(init_param.led[1], BT_ESLS_LED_TYPE_MONOCHROME);
	ESLS_LED_INFO_RED_SET(init_param.led[1], 0x03);
	ESLS_LED_INFO_GREEN_SET(init_param.led[1], 0x03);
#endif

#if CONFIG_BT_ESLS_LED_NUM >= 3
	// Blue LED
	ESLS_LED_INFO_LED_TYPE_SET(init_param.led[2], BT_ESLS_LED_TYPE_MONOCHROME);
	ESLS_LED_INFO_BLUE_SET(init_param.led[2], 0x03);
#endif

#endif // CONFIG_BT_ESLS_LED_NUM > 0

	err = bt_esls_init(&init_param);
	if (err) {
		LOG_ERR("%s %d", __func__, err);
		return;
	}
#ifdef CONFIG_VND_API_SET_ADV_TX_POWER
	if (atm_vendor_set_adv_tx_power(TX_POWER_0_DBM)) {
		LOG_ERR("Set adv tx pwr fail");
	}
#endif
}

#define BTN_DOUBLE_CLICK_DELAY_MS 500
static const struct gpio_dt_spec button0 = GPIO_DT_SPEC_GET_OR(SW0_NODE, gpios, {0});

static struct gpio_callback button_cb_data;
static struct k_work_delayable button_work;
static int click_count;
static bool service_needed;

static void button_work_handler(struct k_work *work)
{
	LOG_DBG("%s", __func__);
	int err = bt_esls_unassociate();
	if (err) {
		LOG_ERR("%s err:%d", __func__, err);
	}
	click_count = 0;
}

static void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
	if (!gpio_pin_get_dt(&button0)) {
		LOG_DBG("Button Released");
		return;
	}
	LOG_DBG("Button Pressed");

	if (!click_count) {
		click_count++;
		atm_work_schedule_for_app_work_q(&button_work, K_MSEC(BTN_DOUBLE_CLICK_DELAY_MS));
	} else {
		k_work_cancel_delayable(&button_work);
		service_needed = !service_needed;
		bt_esls_service_needed_bit_set(service_needed);
		click_count = 0;
		LOG_WRN("service_needed bit: %d", service_needed);
	}
}

static void configure_button_irq(const struct gpio_dt_spec btn)
{
	if (!gpio_is_ready_dt(&btn)) {
		LOG_ERR("button device %s is not ready", btn.port->name);
		return;
	}
	int err = gpio_pin_configure_dt(&btn, GPIO_INPUT);
	if (err) {
		LOG_ERR("Failed to configure %s pin %u err:%d", btn.port->name, btn.pin, err);
		return;
	}
	err = gpio_pin_interrupt_configure_dt(&btn, GPIO_INT_EDGE_BOTH);
	if (err) {
		LOG_ERR("Failed to configure interrupt on %s pin %u err:%d", btn.port->name,
			btn.pin, err);
		return;
	}
	button_cb_data.pin_mask |= BIT(btn.pin);
	gpio_add_callback(btn.port, &button_cb_data);
	LOG_INF("Set up button at %s pin %u", btn.port->name, btn.pin);
}

int main(void)
{
	struct wdt_timeout_cfg wdt_config = {
		.flags = WDT_FLAG_RESET_SOC,
		.window.min = WDT_MIN_WINDOW_MS,
		.window.max = WDT_MAX_WINDOW_MS,
		.callback = NULL,
	};

	wdt_channel_id = wdt_install_timeout(wdog_dev, &wdt_config);
	if (wdt_channel_id < 0) {
		LOG_ERR("Watchdog install error: %d", wdt_channel_id);
		return 1;
	}

	int ret = wdt_setup(wdog_dev, 0);
	if (ret < 0) {
		LOG_ERR("Watchdog setup error: %d", ret);
		return 1;
	}

	k_work_init_delayable(&button_work, button_work_handler);
	gpio_init_callback(&button_cb_data, button_pressed, BIT(button0.pin));
	configure_button_irq(button0);

#if CONFIG_BT_ESLS_SENSOR_NUM > 0
	sensor_init();
#endif

#if CONFIG_BT_ESLS_DISPLAY_NUM > 0
	esl_display_init();
#endif

#if CONFIG_BT_ESLS_LED_NUM > 0
	if (!device_is_ready(led)) {
		LOG_ERR("LED device is not ready\n");
		return 0;
	}
#endif

	int err = bt_enable(bt_ready);
	if (err) {
		LOG_ERR("Bluetooth init failed err:%d", err);
		return 0;
	}

#ifdef CONFIG_PM
	pm_notifier_register(&notifier);
#else
#if CONFIG_AUTO_TEST
	while (!test_end_check())
#else
	while (true)
#endif
	{
		k_sleep(SLEEP_TIME);
		wdt_feed(wdog_dev, wdt_channel_id);
	}
#endif
	return 0;
}
