/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
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

#define BUZZER_NODE     DT_NODELABEL(pwm_buzzer0)
#define BUZZER_PWM_NODE DT_PHANDLE(BUZZER_NODE, pwms)
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

static void rrsp_buzzer_beep_end(struct atm_buzzer_s *buzz_cfg)
{
	LOG_DBG("buzzer end");
	rrsp_buzzer_lock_sleep(false);
}

static atm_buzzer_t buzzer_cfg = {
	.pwm_dt = PWM_DT_SPEC_GET(BUZZER_NODE),
	.pulse = DT_PROP(BUZZER_NODE, pulse),
	.min_frequency = DT_PROP(BUZZER_PWM_NODE, min_frequency),
	.max_frequency = DT_PROP(BUZZER_PWM_NODE, max_frequency),
	.stop_cb = rrsp_buzzer_beep_end,
};

static int rrsp_buzzer_init(void)
{
	LOG_DBG("buzzer init:period:%u, pulse:%u", buzzer_cfg.pwm_dt.period, buzzer_cfg.pulse);

	atm_buzzer_cb_reg(&buzzer_cfg);

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
	if (atm_buzzer_beep_time(&buzzer_cfg, RRSP_BUZZER_FREQ_HZ, RRSP_BUZZER_DUTY_CYCLE, duration_ms)) {
		LOG_ERR("Set buzzer failed");
		return;
	}
	rrsp_buzzer_lock_sleep(true);
#endif
}
