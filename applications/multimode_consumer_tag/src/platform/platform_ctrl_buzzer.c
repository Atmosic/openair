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
#ifdef CONFIG_AT_CMD_TAG_SET
#include "at_cmd_uart.h"
#include "at_cmd_event.h"
#include "at_cmd_tag.h"
#include "platform.h"
#endif

LOG_MODULE_DECLARE(multimode_consumer_tag, CONFIG_MULTIMODE_CONSUMER_TAG_LOG_LEVEL);

#ifdef CONFIG_ATM_BUZZER
#include <zephyr/drivers/pwm.h>
#include "atm_buzzer.h"

#define DEFAULT_BUZZER_FREQ_HZ      1000
#define DEFAULT_BUZZER_DUTY_PERCENT 50

static uint32_t buzzer_freq_hz = DEFAULT_BUZZER_FREQ_HZ;
static uint32_t buzzer_duty_percent = DEFAULT_BUZZER_DUTY_PERCENT;

#define BUZZER_NODE DT_NODELABEL(pwm_buzzer0)
BUILD_ASSERT(DT_NODE_EXISTS(BUZZER_NODE), "BUZZER_NODE does not exist in the Device Tree!");

static const struct device *buzzer_dev;
#endif

void platform_ctrl_buzzer_config(uint32_t freq_hz, uint32_t duty_percent)
{
#ifdef CONFIG_ATM_BUZZER
	buzzer_freq_hz = freq_hz;
	buzzer_duty_percent = duty_percent;
#endif
}

void platform_ctrl_buzzer_action(bool action)
{
	LOG_DBG("buzzer action %u", action);
#ifdef CONFIG_ATM_BUZZER
	if (buzzer_dev) {
		if (action) {
			atm_buzzer_configure(buzzer_dev, buzzer_freq_hz, buzzer_duty_percent);
		}
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
#ifdef CONFIG_AT_CMD_TAG_SET
		at_cmd_evt_tag_error(at_cmd_uart_ch_get(), platform_tag_supported_mode_mask_get(),
				     AT_CMD_TAG_ERR_BUZZER);
#endif
		buzzer_dev = NULL;
		return;
	}

	LOG_DBG("buzzer initialized");
#endif
}
