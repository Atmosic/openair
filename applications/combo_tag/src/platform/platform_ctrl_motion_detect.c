/**
 *******************************************************************************
 *
 * @file platform_ctrl_motion_detect.c
 *
 * @brief Platform control motion detect For FMNA and FMDN Combo Tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/logging/log.h>
#include "platform_ctrl_motion_detect.h"

LOG_MODULE_DECLARE(combo_tag, CONFIG_COMBO_TAG_LOG_LEVEL);

void platform_ctrl_motion_detect_action(bool action)
{
	LOG_DBG("motion_detect action %u", action);
}

void platform_ctrl_motion_detect_init(void)
{
	// todo something here
}

bool platform_ctrl_motion_detect_get_status(void)
{
	return false;
}
