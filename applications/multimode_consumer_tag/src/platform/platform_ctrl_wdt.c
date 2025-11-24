/**
 *******************************************************************************
 *
 * @file platform_ctrl_wdt.c
 *
 * @brief Platform control wdt For Multimode Consumer Tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/watchdog.h>
#include <zephyr/device.h>
#include <zephyr/logging/log.h>
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#include "platform_ctrl_wdt.h"

LOG_MODULE_DECLARE(multimode_consumer_tag, CONFIG_MULTIMODE_CONSUMER_TAG_LOG_LEVEL);

#define WDT_MIN_WINDOW_MS 0
#define WDT_MAX_WINDOW_MS 10000
#define WDT_FEED_INTERVAL K_SECONDS(8)

static struct device const *wdog_dev = DEVICE_DT_GET(DT_NODELABEL(wdog0));
static int wdt_channel_id;

static void wdt_feed_timer_handler(struct k_timer *timer)
{
	wdt_feed(wdog_dev, wdt_channel_id);
}

K_TIMER_DEFINE(wdt_feed_timer, wdt_feed_timer_handler, NULL);

#ifdef CONFIG_PM
static void pm_state_exit(enum pm_state state)
{
	// feed wdt and reset wdt feed timer, reduce timer event
	wdt_feed(wdog_dev, wdt_channel_id);
	k_timer_start(&wdt_feed_timer, WDT_FEED_INTERVAL, WDT_FEED_INTERVAL);
}

static struct pm_notifier notifier = {
	.state_exit = pm_state_exit,
};
#endif

int platform_ctrl_wdt_init(void)
{
	if (!device_is_ready(wdog_dev)) {
		LOG_ERR("wdog0 not ready");
		return -ENODEV;
	}

	struct wdt_timeout_cfg wdt_config = {
		.flags = WDT_FLAG_RESET_SOC,
		.window =
			{
				.min = WDT_MIN_WINDOW_MS,
				.max = WDT_MAX_WINDOW_MS,
			},
		.callback = NULL,
	};

	wdt_channel_id = wdt_install_timeout(wdog_dev, &wdt_config);
	if (wdt_channel_id < 0) {
		LOG_ERR("Watchdog install error: %d", wdt_channel_id);
		return -EIO;
	}

	int ret = wdt_setup(wdog_dev, 0);
	if (ret < 0) {
		LOG_ERR("Watchdog setup error: %d", ret);
		return -EIO;
	}

	return 0;
}

void platform_ctrl_wdt_feed_timer_start(void)
{
#ifdef CONFIG_PM
	pm_notifier_register(&notifier);
#endif
	k_timer_start(&wdt_feed_timer, WDT_FEED_INTERVAL, WDT_FEED_INTERVAL);
}

void platform_ctrl_wdt_feed_timer_stop(void)
{
#ifdef CONFIG_PM
	pm_notifier_unregister(&notifier);
#endif
	k_timer_stop(&wdt_feed_timer);
}
