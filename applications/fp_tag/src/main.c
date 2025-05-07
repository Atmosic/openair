/**
 *******************************************************************************
 *
 * @file main.c
 *
 * @brief Google Find My Device Network Tag application
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/settings/settings.h>
#include "fp_tag_platform.h"
#include "app_work_q.h"
#include "gfps.h"

LOG_MODULE_REGISTER(fp_tag, CONFIG_FP_TAG_LOG_LEVEL);

static void fp_tag_init_work_handler(struct k_work *work)
{
	fp_tag_platform_init();
}

K_WORK_DEFINE(fp_tag_init, fp_tag_init_work_handler);

static void fp_tag_bt_ready(void)
{
	if (!bt_is_ready()) {
		LOG_ERR("bt_is_ready is not ready");
	}

	// defer fp_tag_platform init to fp_work_q
	atm_work_submit_to_app_work_q(&fp_tag_init);
}

int main(void)
{

	fp_tag_platform_gpio_init();
	fp_tag_platform_reset_detect();

	int err = bt_enable(NULL);
	if (err) {
		LOG_WRN("Bluetooth enabled failed (err %d)", err);
		return 0;
	}
	LOG_INF("Bluetooth initialized");

	if (IS_ENABLED(CONFIG_SETTINGS)) {
		settings_load();
	}

	fp_tag_bt_ready();

	return 0;
}
