/**
 *******************************************************************************
 *
 * @file main.c
 *
 * @brief Multimode Consumer Tag application
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/settings/settings.h>
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#include "app_work_q.h"
#include "platform.h"
#include "platform_ctrl_button.h"
#ifdef CONFIG_TAG_LED_IND
#include "platform_ctrl_led.h"
#endif
#ifdef CONFIG_TAG_BTN_OTA_MODE
#include "platform_ctrl_ota.h"
#endif
#include "platform_ctrl_wdt.h"
#ifdef CONFIG_STF_TAG
#include "TagSdk.h"
#endif

LOG_MODULE_REGISTER(multimode_consumer_tag, CONFIG_MULTIMODE_CONSUMER_TAG_LOG_LEVEL);

static void tag_init_work_handler(struct k_work *work)
{
	platform_init();
}

K_WORK_DEFINE(consumer_tag_init, tag_init_work_handler);

static void tag_bt_ready(void)
{
	if (!bt_is_ready()) {
		LOG_ERR("bt_is_ready is not ready");
	}

	/* defer platform_init to app_work_q */
	atm_work_submit_to_app_work_q(&consumer_tag_init);
}

int main(void)
{
	int err = platform_ctrl_wdt_init();
	if (err) {
		LOG_ERR("platform_ctrl_wdt_init failed (err %d)", err);
		return 0;
	}
	platform_ctrl_wdt_feed_timer_start();

	if (!platform_ctrl_button_init()) {
		LOG_INF("skip power on");
#ifdef CONFIG_PM
		// stop wdt feed timer to prevent unnecessary wakeup
		platform_ctrl_wdt_feed_timer_stop();
		pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
#endif
		return 0;
	}

#ifdef CONFIG_STF_TAG
	TagInit();
#endif
	err = bt_enable(NULL);
	if (err) {
		LOG_WRN("Bluetooth enabled failed (err %d)", err);
		return 0;
	}
	LOG_INF("Bluetooth initialized");

	if (IS_ENABLED(CONFIG_SETTINGS)) {
		settings_load();
	}

#ifdef CONFIG_TAG_BTN_OTA_MODE
	if (platform_ctrl_ota_init()) {
		LOG_INF("System is in OTA mode");
#ifdef CONFIG_TAG_LED_IND
		/* Set LED to OTA mode - red LED blinks every 1 second */
		platform_ctrl_led_state_update(LED_STATE_OTA_MODE);
#endif
		return 0;
	}
#endif // CONFIG_TAG_BTN_OTA_MODE

	tag_bt_ready();

	return 0;
}
