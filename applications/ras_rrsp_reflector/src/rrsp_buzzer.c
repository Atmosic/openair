/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/init.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/logging/log.h>
#include "rrsp_buzzer.h"

LOG_MODULE_REGISTER(rrsp_buzzer, CONFIG_RRSP_BUZZER_LOG_LEVEL);

#ifdef CONFIG_ATM_BUZZER
#include <zephyr/drivers/pwm.h>
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#include "atm_buzzer.h"

#define BUZZER_NODE DT_NODELABEL(pwm_buzzer0)
BUILD_ASSERT(DT_NODE_EXISTS(BUZZER_NODE), "BUZZER_NODE does not exist in the Device Tree!");

static bool buzzer_lock;

static void rrsp_buzzer_lock_sleep(bool lock)
{
	LOG_DBG("buzzer lock:%d", lock);

	if (buzzer_lock == lock) {
		return;
	}

	if (lock) {
		pm_policy_state_lock_get(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	} else {
		pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	}
	buzzer_lock = lock;
}

static void rrsp_buzzer_beep_end(const struct device *dev)
{
	LOG_DBG("buzzer end");
	rrsp_buzzer_lock_sleep(false);
}

static int rrsp_buzzer_init(void)
{
	const struct device *buzzer = DEVICE_DT_GET(BUZZER_NODE);

	if (!device_is_ready(buzzer)) {
		LOG_ERR("Buzzer device not ready");
		return -ENODEV;
	}

	/* Set stop callback */
	atm_buzzer_set_stop_callback(buzzer, rrsp_buzzer_beep_end);

	LOG_DBG("buzzer initialized");
	return 0;
}
SYS_INIT(rrsp_buzzer_init, POST_KERNEL, CONFIG_APPLICATION_INIT_PRIORITY);
#endif

void rrsp_buzzer_beep(uint32_t duration_ms)
{
	LOG_INF("buzzer beep duration_ms:%d", duration_ms);
	if (!duration_ms) {
		return;
	}
#ifdef CONFIG_ATM_BUZZER
#define RRSP_BUZZER_FREQ_HZ    1000
#define RRSP_BUZZER_DUTY_CYCLE 50

	const struct device *buzzer = DEVICE_DT_GET(BUZZER_NODE);

	if (atm_buzzer_beep_time(buzzer, RRSP_BUZZER_FREQ_HZ, RRSP_BUZZER_DUTY_CYCLE,
				 duration_ms)) {
		LOG_ERR("Set buzzer failed");
		return;
	}
	rrsp_buzzer_lock_sleep(true);
#endif
}
