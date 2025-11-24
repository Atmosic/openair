/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025 Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/watchdog.h>
#include <zephyr/logging/log.h>
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>

#include "sensor_beacon.h"
#include "led_button_ctrl.h"
#include "reset.h"

#ifdef CONFIG_PM
#include "power.h"
#endif

#ifdef CONFIG_WURX
#include <zephyr/logging/log_ctrl.h>
#include "wurx.h"
#ifdef CONFIG_SENSOR_BEACON_BUTTON_POWER_CONTROL
STATIC_ASSERT(
	false,
	"CONFIG_WURX and CONFIG_SENSOR_BEACON_BUTTON_POWER_CONTROL cannot both be set together.");
#endif
#endif

LOG_MODULE_REGISTER(main, CONFIG_SENSOR_BEACON_LOG_LEVEL);

#define SLEEP_TIME        K_SECONDS(3)
#define WDT_MIN_WINDOW_MS 0
#define WDT_MAX_WINDOW_MS 5000

static const struct device *const wdog_dev = DEVICE_DT_GET(DT_NODELABEL(wdog0));
static int wdt_channel_id;

#ifdef CONFIG_WURX
static const struct device *wurx_dev = NULL;
static struct k_timer wurx_adv_timer;
static struct k_work hibernate_work;
#endif

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

#ifdef CONFIG_WURX
static void hibernate_work_handler(struct k_work *work)
{
	LOG_INF("Stopping sensor beacon before entering hibernation");

	/* Stop sensor beacon synchronously */
	int ret = sensor_beacon_stop();
	if (ret) {
		LOG_ERR("Failed to stop sensor beacon: %d", ret);
	}

#ifdef CONFIG_PM
	LOG_INF("Entering hibernation");
	LOG_INF("Waiting for WuRx wake-up signal...");

	/* Enter hibernation - device will wake up on WURX signal */
	sensor_beacon_unlock_soft_off_state();
#endif
}

static void wurx_adv_timer_handler(struct k_timer *timer)
{
	LOG_INF("Initial advertising period complete");

	/* Submit work to stop beacon and enter hibernation from thread context */
	k_work_submit(&hibernate_work);
}
#endif

int main(void)
{
	LOG_INF("Starting Sensor Beacon Application: %#x", boot_status());

#ifdef CONFIG_SENSOR_BEACON_BUTTON_POWER_CONTROL
	// Check if device should power on (button power control enabled)
	if (!led_button_ctrl_check_power_on()) {
		LOG_INF("Device will go into SOC-OFF state");
#ifdef CONFIG_PM
		// Enable GPIO wakeup source for SOC_OFF
		atm_socoff_wakeup_gpio_set(true);
		// Unlock SOC_OFF state to allow PM subsystem to enter it
		sensor_beacon_unlock_soft_off_state();
#endif
		return 0;
	}

	// Device is powering on - continue with initialization
	LOG_INF("Button power control check passed - proceeding with initialization");
#else
	// No button power control, proceed directly to normal initialization
	LOG_DBG("No button power control");
#endif

	/* Initialize watchdog */
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

#ifdef CONFIG_WURX
	/* Get WURX device */
	wurx_dev = DEVICE_DT_GET(DT_NODELABEL(wurx));
	if (!device_is_ready(wurx_dev)) {
		LOG_ERR("WuRx device not ready");
		return -ENODEV;
	}

	LOG_INF("WuRx device initialized");
#endif

	/* Initialize sensor beacon */
	ret = sensor_beacon_init();
	if (ret) {
		LOG_ERR("Sensor beacon init failed: %d", ret);
		return ret;
	}

#ifdef CONFIG_PM
	sensor_beacon_unlock_soft_off_state();
#endif

	/* Set the device to ON state */
	led_button_ctrl_set_device_state(DEVICE_STATE_ON);

#ifdef CONFIG_WURX
	LOG_INF("WURX mode enabled - advertising for %d ms before hibernation",
		CONFIG_SENSOR_BEACON_WURX_ACTIVE_ADV_TIME_MS);

	/* Initialize work item for hibernation */
	k_work_init(&hibernate_work, hibernate_work_handler);

	/* Initialize timer for initial advertising period */
	k_timer_init(&wurx_adv_timer, wurx_adv_timer_handler, NULL);

	/* Start timer for initial advertising period */
	k_timer_start(&wurx_adv_timer, K_MSEC(CONFIG_SENSOR_BEACON_WURX_ACTIVE_ADV_TIME_MS),
		      K_NO_WAIT);
#endif /* CONFIG_WURX */

#ifdef CONFIG_PM
	pm_notifier_register(&notifier);
#else
	/* Main loop for non-PM builds */
	while (true) {
		k_sleep(SLEEP_TIME);
		wdt_feed(wdog_dev, wdt_channel_id);
	}
#endif

	return 0;
}
