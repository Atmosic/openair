/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/types.h>
#include <zephyr/logging/log.h>
#include "sound.h"

#ifdef CONFIG_PWM_BUZZER
#include <zephyr/drivers/pwm.h>
#include <zephyr/device.h>
#include <zephyr/kernel.h>

static const struct pwm_dt_spec pwm_dt = PWM_DT_SPEC_GET(DT_NODELABEL(buzzer));
#endif
LOG_MODULE_REGISTER(sound, LOG_LEVEL_DBG);

void sound_init(void)
{
    // Initialize sound
    LOG_DBG("sound_init");
}

void sound_start(void)
{
#ifdef CONFIG_PWM_BUZZER
    int ret = pwm_set_pulse_dt(&pwm_dt, DT_PROP(DT_NODELABEL(buzzer), pulse));
    if (ret) {
	LOG_ERR("Failed to start PWM: %d", ret);
    }
#endif
    LOG_DBG("sound_start");
}

void sound_stop(void)
{
#ifdef CONFIG_PWM_BUZZER
    int ret = pwm_set_pulse_dt(&pwm_dt, 0);
    if (ret) {
	LOG_ERR("Failed to stop PWM: %d", ret);
    }
#endif
    LOG_DBG("sound_stop");
}
