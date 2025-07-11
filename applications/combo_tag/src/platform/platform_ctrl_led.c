/**
 *******************************************************************************
 *
 * @file platform_ctrl_led.c
 *
 * @brief Platform control led For FMNA and FMDN Combo Tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/logging/log.h>
#include "platform_ctrl_led.h"

LOG_MODULE_DECLARE(combo_tag, CONFIG_COMBO_TAG_LOG_LEVEL);

void platform_ctrl_led_init(void)
{
	// todo something here
}

void platform_ctrl_led_update(tag_state_t st)
{
	LOG_INF("Update LED for state [%s]", tag_state_str[st]);
}
