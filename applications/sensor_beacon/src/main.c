/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025 Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/watchdog.h>
#include <zephyr/logging/log.h>
#include <zephyr/pm/pm.h>

#include "sensor_beacon.h"
#include <inttypes.h>

LOG_MODULE_REGISTER(main, CONFIG_SENSOR_BEACON_LOG_LEVEL);

#define SLEEP_TIME        K_SECONDS(3)
#define WDT_MIN_WINDOW_MS 0
#define WDT_MAX_WINDOW_MS 5000

static const struct device *const wdog_dev = DEVICE_DT_GET(DT_NODELABEL(wdog0));
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

int main(void)
{
	LOG_INF("Starting Sensor Beacon Application");

	/* Initialize watchdog */
	struct wdt_timeout_cfg wdt_config = {
		.flags = WDT_FLAG_RESET_SOC,
		.window.min = WDT_MIN_WINDOW_MS,
		.window.max = WDT_MAX_WINDOW_MS,
		.callback = NULL,
	};

	wdt_channel_id = wdt_install_timeout(wdog_dev, &wdt_config);
	if (wdt_channel_id < 0) {
		LOG_ERR("Watchdog install error: %" PRId32, wdt_channel_id);
		return 1;
	}

	/* Initialize sensor beacon */
	int ret = sensor_beacon_init();
	if (ret) {
		LOG_ERR("Sensor beacon init failed: %" PRId32, ret);
		return ret;
	}

	/* Start sensor beacon operation */
	ret = sensor_beacon_start();
	if (ret) {
		LOG_ERR("Sensor beacon start failed: %" PRId32, ret);
		return ret;
	}

	LOG_INF("Sensor beacon started successfully");

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
