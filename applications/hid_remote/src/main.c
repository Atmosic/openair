/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/watchdog.h>
#include <zephyr/logging/log.h>
#include <zephyr/pm/pm.h>

#include "rc_mmi.h"

LOG_MODULE_REGISTER(main, CONFIG_HID_REMOTE_LOG_LEVEL);

#define SLEEP_TIME        K_SECONDS(3)
#define WDT_MIN_WINDOW_MS 0
#define WDT_MAX_WINDOW_MS 5000
#define WDT_FEED_INTERVAL K_SECONDS(2)

struct device const *wdog_dev = DEVICE_DT_GET(DT_NODELABEL(wdog0));
static int wdt_channel_id;

/*
 * Feed the watchdog periodically, independent of PM state transitions. While
 * connected (e.g. during pairing) the SoC can stay awake for longer than the
 * watchdog window with no PM transition, so relying on PM notifiers alone
 * starves the watchdog and triggers a spurious SoC reset mid-pairing.
 */
static void wdog_feed_work_handler(struct k_work *work)
{
	struct k_work_delayable *dwork = k_work_delayable_from_work(work);

	wdt_feed(wdog_dev, wdt_channel_id);
	k_work_reschedule(dwork, WDT_FEED_INTERVAL);
}

static K_WORK_DELAYABLE_DEFINE(wdog_feed_work, wdog_feed_work_handler);

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
		LOG_ERR("Watchdog install error: %d", wdt_channel_id);
		return 1;
	}

	int ret = wdt_setup(wdog_dev, 0);
	if (ret < 0) {
		LOG_ERR("Watchdog setup error: %d", ret);
		return 1;
	}

	rc_mmi_init();

	/* Keep feeding the watchdog while awake, regardless of PM activity. */
	k_work_reschedule(&wdog_feed_work, WDT_FEED_INTERVAL);

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
