/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/watchdog.h>
#include <zephyr/logging/log.h>
#include <zephyr/pm/pm.h>
#include "rrsp_buttons.h"
#include "rrsp_mmi.h"

LOG_MODULE_REGISTER(rrsp, CONFIG_RRSP_LOG_LEVEL);

#define SLEEP_TIME        K_SECONDS(3)
#define WDT_MIN_WINDOW_MS 0
#define WDT_MAX_WINDOW_MS 5000

struct device const *wdog_dev = DEVICE_DT_GET(DT_NODELABEL(wdog0));
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
	struct wdt_timeout_cfg wdt_config = {
		.flags = WDT_FLAG_RESET_SOC,
		.window.min = WDT_MIN_WINDOW_MS,
		.window.max = WDT_MAX_WINDOW_MS,
		.callback = NULL,
	};

	wdt_channel_id = wdt_install_timeout(wdog_dev, &wdt_config);
	if (wdt_channel_id < 0) {
		LOG_INF("Watchdog install error");
		return 1;
	}
	/* Watchdog already enable by CONFIG_WDOG_CMSDK_APB_START_AT_BOOT */

	if (!rrsp_buttons_init()) {
#ifdef CONFIG_BTN_ON_OFF
		LOG_INF("skip power on");
		rrsp_mmi_unlock_sleep();
		return 1;
#endif
	}

#ifdef CONFIG_PM
	pm_notifier_register(&notifier);
#else
	while (true) {
		k_sleep(SLEEP_TIME);
		wdt_feed(wdog_dev, wdt_channel_id);
	}
#endif

	return 0;
}
