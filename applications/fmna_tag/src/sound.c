/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/types.h>
#include <zephyr/logging/log.h>
#include "sound.h"

#ifdef CONFIG_ATM_BUZZER
#include <zephyr/drivers/pwm.h>
#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include "atm_buzzer.h"

#define BUZZER_NODE DT_NODELABEL(buzzer)
#define BUZZER_PWM_NODE DT_PHANDLE(BUZZER_NODE, pwms)
BUILD_ASSERT(DT_NODE_EXISTS(BUZZER_NODE),
    "BUZZER_NODE does not exist in the Device Tree!");

static atm_buzzer_t buzzer_cfg = {
    .pwm_dt = PWM_DT_SPEC_GET(BUZZER_NODE),
    .pulse = DT_PROP(BUZZER_NODE, pulse),
    .min_frequency = DT_PROP(BUZZER_PWM_NODE, min_frequency),
    .max_frequency = DT_PROP(BUZZER_PWM_NODE, max_frequency),
};
#endif
LOG_MODULE_REGISTER(sound, LOG_LEVEL_DBG);

void sound_init(void)
{
    // Initialize sound
    LOG_DBG("sound_init");
}

void sound_start(void)
{
#ifdef CONFIG_ATM_BUZZER
    atm_buzzer_onoff(&buzzer_cfg, true);
#endif
    LOG_DBG("sound_start");
}

void sound_stop(void)
{
#ifdef CONFIG_ATM_BUZZER
    atm_buzzer_onoff(&buzzer_cfg, false);
#endif
    LOG_DBG("sound_stop");
}
