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
#include "fmna_main.h"
#include "reset.h"

LOG_MODULE_REGISTER(fmna, LOG_LEVEL_DBG);

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

    int err = gpio_pin_configure_dt(&button, GPIO_INPUT | GPIO_PULL_UP);
    if (err) {
	LOG_ERR("Error %d: failed to configure %s pin %u", err,
	    button.port->name, button.pin);
	return;
    }

    if (gpio_pin_get_dt(&button)) {
	return;
    }

    LOG_INF("Button pressed, perform FMNA unpair");
    // defer reset_pairing to app_work_q so the main stack size can be reduced.
    atm_work_submit_to_app_work_q(&fmna_reset_pairing_work);
}
#else
#warning "Check if User Button is correct for your target board."
#endif

static void fmna_init_work_handler(struct k_work *work)
{
    fmna_main_init();
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
