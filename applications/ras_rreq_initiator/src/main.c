/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/drivers/watchdog.h>
#include <zephyr/logging/log.h>

#include "app_work_q.h"
#include "rreq_smf.h"
#if defined(CONFIG_RREQ_USE_ARIAD) && defined(CONFIG_RREQ_USE_DISPLAY)
#include "cs_display.h"
#endif

LOG_MODULE_REGISTER(rreq, CONFIG_RREQ_LOG_LEVEL);

#define WDT_POKE_TIME     K_SECONDS(3)
#define WDT_MIN_WINDOW_MS 0
#define WDT_MAX_WINDOW_MS 5000

static struct device const *wdog_dev = DEVICE_DT_GET(DT_NODELABEL(wdog0));
static int wdt_channel_id;
static struct k_work_delayable wdt_poke_work;

static void wdt_poke_work_handler(struct k_work *work)
{
	wdt_feed(wdog_dev, wdt_channel_id);
	atm_work_schedule_for_app_work_q(&wdt_poke_work, WDT_POKE_TIME);
}

int main(void)
{
	const struct wdt_timeout_cfg wdt_config = {
		.flags = WDT_FLAG_RESET_SOC,
		.window.min = WDT_MIN_WINDOW_MS,
		.window.max = WDT_MAX_WINDOW_MS,
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

	k_work_init_delayable(&wdt_poke_work, wdt_poke_work_handler);
	atm_work_schedule_for_app_work_q(&wdt_poke_work, WDT_POKE_TIME);

#if defined(CONFIG_RREQ_USE_ARIAD) && defined(CONFIG_RREQ_USE_DISPLAY)
	cs_display_init();
#endif

	rreq_smf_init();

	return 0;
}
