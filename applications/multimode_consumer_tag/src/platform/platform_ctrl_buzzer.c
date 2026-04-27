/**
 *******************************************************************************
 *
 * @file platform_ctrl_buzzer.c
 *
 * @brief Platform control buzzer For Multimode Consumer Tag
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
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

#define BUZZER_NODE DT_NODELABEL(pwm_buzzer0)
BUILD_ASSERT(DT_NODE_EXISTS(BUZZER_NODE), "BUZZER_NODE does not exist in the Device Tree!");

static const struct device *buzzer_dev;
#endif

void platform_ctrl_buzzer_action(bool action)
{
	LOG_DBG("buzzer action %u", action);
#ifdef CONFIG_ATM_BUZZER
	if (buzzer_dev) {
		atm_buzzer_onoff(buzzer_dev, action);
	}
#endif
}

void platform_ctrl_buzzer_init(void)
{
#ifdef CONFIG_ATM_BUZZER
	buzzer_dev = DEVICE_DT_GET(BUZZER_NODE);

	if (!device_is_ready(buzzer_dev)) {
		LOG_ERR("Buzzer device not ready");
		buzzer_dev = NULL;
		return;
	}

	LOG_DBG("buzzer initialized");
#endif
}
