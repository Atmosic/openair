/**
 *******************************************************************************
 *
 * @file platform.h
 *
 * @brief Platform For FMNA and FMDN Combo Tag
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
 * @brief Platform init
 */
void platform_init(void);

/**
 * @brief Platform gpio init
 */
void platform_gpio_init(void);

/**
 * @brief Platform reset detect
 */
void platform_reset_detect(void);

#ifdef __cplusplus
}
#endif

///@}
