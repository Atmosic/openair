/**
 *******************************************************************************
 *
 * @file platform_ctrl_buzzer.c
 *
 * @brief Platform control buzzer For Multimode Consumer Tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/device.h>
#include <zephyr/logging/log.h>
#include "platform_ctrl_buzzer.h"

LOG_MODULE_DECLARE(multimode_consumer_tag, CONFIG_MULTIMODE_CONSUMER_TAG_LOG_LEVEL);

#ifdef CONFIG_ATM_BUZZER
#include <zephyr/drivers/pwm.h>
#include "atm_buzzer.h"

#define BUZZER_NODE     DT_NODELABEL(buzzer)
#define BUZZER_PWM_NODE DT_PHANDLE(BUZZER_NODE, pwms)
BUILD_ASSERT(DT_NODE_EXISTS(BUZZER_NODE), "BUZZER_NODE does not exist in the Device Tree!");

static atm_buzzer_t buzzer_cfg = {
	.pwm_dt = PWM_DT_SPEC_GET(BUZZER_NODE),
	.pulse = DT_PROP(BUZZER_NODE, pulse),
	.min_frequency = DT_PROP(BUZZER_PWM_NODE, min_frequency),
	.max_frequency = DT_PROP(BUZZER_PWM_NODE, max_frequency),
};
#endif

void platform_ctrl_buzzer_action(bool action)
{
	LOG_DBG("buzzer action %u", action);
#ifdef CONFIG_ATM_BUZZER
	atm_buzzer_onoff(&buzzer_cfg, action);
#endif
}

void platform_ctrl_buzzer_init(void)
{
	// todo something here
}
