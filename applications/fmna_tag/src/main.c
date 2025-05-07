/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <zephyr/sys/printk.h>
#include <zephyr/kernel.h>

#include <zephyr/logging/log.h>
#include <zephyr/settings/settings.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/drivers/gpio.h>

#include "arch.h"
#include "app_work_q.h"
#include "fmna_api.h"
#include "reset.h"
#include "sound.h"
#include "motion.h"
#include "battery.h"

LOG_MODULE_REGISTER(fmna_tag, CONFIG_FMNA_TAG_LOG_LEVEL);

static char const * const fmna_state_string[] = {
    "FMNA_STATE_INIT_DONE",
    "FMNA_STATE_UNPAIRED",
    "FMNA_STATE_PAIRING",
    "FMNA_STATE_PAIRED",
};

static void state_notify(fmna_state_notify_t state)
{
    LOG_INF("FMNA current state %s", fmna_state_string[state]);
    switch (state) {
	case FMNA_STATE_INIT_DONE:
	    if (!fmna_connection_is_fmna_paired()) {
		fmna_main_start_pairing_adv();
	    }
	    break;
	default:
	    break;
    }
}

#define BUTTON0 DT_ALIAS(sw0)
#if DT_NODE_EXISTS(BUTTON0)

static void fmna_reset_pairing_work_handler(struct k_work *work)
{
    fmna_main_reset_pairing_state();
}

K_WORK_DEFINE(fmna_reset_pairing_work, fmna_reset_pairing_work_handler);

static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(BUTTON0, gpios);
static void gpio_init_detect_unpair(void)
{
    LOG_INF("gpio_init_detect_unpair");

    if (!is_boot_type(TYPE_POWER_ON)) {
	return;
    }

    int err = gpio_pin_configure_dt(&button, GPIO_INPUT);
    if (err) {
	LOG_ERR("Error %d: failed to configure %s pin %u", err,
	    button.port->name, button.pin);
	return;
    }

    if (!gpio_pin_get_dt(&button)) {
	return;
    }

    LOG_INF("Button pressed, perform FMNA unpair");
    // defer reset_pairing to app_work_q so the main stack size can be reduced.
    atm_work_submit_to_app_work_q(&fmna_reset_pairing_work);
}
#else
#warning "Check if User Button is correct for your target board."
#endif

#ifdef CONFIG_FMNA_DEV_CUSTOM_BT_ADDR
static bt_addr_le_t init_addr;
#endif

static uint8_t product_data[8];
static struct fmna_init_params const fmna_init_params = {
#ifdef CONFIG_FMNA_DEV_CUSTOM_BT_ADDR
    .init_addr = init_addr.a.val,
#endif
    .acc_capability = CONFIG_FMNA_ACCESSORY_CAPABILITY,
    .acc_category = CONFIG_FMNA_ACCESSORY_CATEGORY,
    .batt_type = CONFIG_FMNA_BATTERY_TYPE,
    .pid = CONFIG_FMNA_PID,
    .product_data = product_data,
    .manufacturer_name = CONFIG_FMNA_MANUFACTURER_NAME,
    .model_name = CONFIG_FMNA_MODEL_NAME,
    .hardware_version = CONFIG_FMNA_HARDWARE_VERSION,
    .version_major = CONFIG_FMNA_VERSION_MAJOR,
    .version_minor = CONFIG_FMNA_VERSION_MINOR,
    .version_revision = CONFIG_FMNA_VERSION_REVISION,
    .sound_cb = {
	.sound_init = sound_init,
	.sound_start = sound_start,
	.sound_stop = sound_stop
    },
    .motion_cb = {
	.motion_init = motion_init,
	.motion_deinit = motion_deinit,
	.motion_detected = motion_detected
    },
    .battery_cb = {
	.battery_level_get = battery_level_get
    },
    .state_cb = {
	.state_notify = state_notify,
    }
};

static void fmna_init_work_handler(struct k_work *work)
{
#ifdef CONFIG_FMNA_DEV_CUSTOM_BT_ADDR
    int err = bt_addr_le_from_str(CONFIG_FMNA_DEV_CUSTOM_BT_ADDR_VALUE,
	"random", &init_addr);
    if (err) {
	LOG_ERR("Invalid Bluetooth address format");
	return;
    }
#endif
    hex2bin(CONFIG_FMNA_PRODUCT_DATA, strlen(CONFIG_FMNA_PRODUCT_DATA),
	product_data, sizeof(product_data));

    fmna_main_init(&fmna_init_params);
}

K_WORK_DEFINE(fmna_init_work, fmna_init_work_handler);

static void bt_ready(void)
{
    LOG_INF("Bluetooth initialized");

    int err = settings_load();
    if (err) {
	LOG_ERR("settings_load failed (err %d)", err);
	return;
    }
    LOG_INF("Check pairing status: %u", fmna_connection_is_fmna_paired());
    // defer fmna_init to app_work_q so the main stack size can be reduced.
    atm_work_submit_to_app_work_q(&fmna_init_work);
}

int main(void)
{
#if DT_NODE_EXISTS(BUTTON0)
    gpio_init_detect_unpair();
#endif

    int err = bt_enable(NULL);
    if (err) {
	LOG_ERR("Bluetooth init failed (err %d)", err);
	return 0;
    }

    bt_ready();

    return 0;
}
