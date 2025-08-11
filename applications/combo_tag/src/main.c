/**
 *******************************************************************************
 *
 * @file main.c
 *
 * @brief FMNA and FMDN Combo Tag application
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <zephyr/settings/settings.h>
#include "app_work_q.h"
#include "platform.h"

LOG_MODULE_REGISTER(combo_tag, CONFIG_COMBO_TAG_LOG_LEVEL);

static void combo_tag_init_work_handler(struct k_work *work)
{
	platform_init();
}

K_WORK_DEFINE(combo_tag_init, combo_tag_init_work_handler);

static void combo_tag_bt_ready(void)
{
	if (!bt_is_ready()) {
		LOG_ERR("bt_is_ready is not ready");
	}

	// defer combo_tag_platform init to fp_work_q
	atm_work_submit_to_app_work_q(&combo_tag_init);
}

int main(void)
{

	platform_gpio_init();

	int err = bt_enable(NULL);
	if (err) {
		LOG_WRN("Bluetooth enabled failed (err %d)", err);
		return 0;
	}
	LOG_INF("Bluetooth initialized");

	if (IS_ENABLED(CONFIG_SETTINGS)) {
		settings_load();
	}

	combo_tag_bt_ready();

	return 0;
}
