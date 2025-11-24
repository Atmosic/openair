/**
 *******************************************************************************
 *
 * @file platform_ctrl_wdt.h
 *
 * @brief Platform control wdt For Multimode Consumer Tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Platform control wdt init
 *
 * @return 0 if success, -errno if fail
 */
int platform_ctrl_wdt_init(void);

/**
 * @brief Platform control wdt feed timer start
 */
void platform_ctrl_wdt_feed_timer_start(void);

/**
 * @brief Platform control wdt feed timer stop
 */
void platform_ctrl_wdt_feed_timer_stop(void);

#ifdef __cplusplus
}
#endif

///@}
