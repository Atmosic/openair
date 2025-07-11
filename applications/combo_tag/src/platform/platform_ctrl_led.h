/**
 *******************************************************************************
 *
 * @file platform_ctrl_led.h
 *
 * @brief Platform control led For FMNA and FMDN Combo Tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#include "platform_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Platform control led init
 */
void platform_ctrl_led_init(void);

/**
 * @brief Platform control led update
 * @param[in] st tag state
 */
void platform_ctrl_led_update(tag_state_t st);

#ifdef __cplusplus
}
#endif

///@}
