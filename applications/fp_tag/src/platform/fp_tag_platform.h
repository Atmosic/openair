/**
 *******************************************************************************
 *
 * @file fp_tag_platform.h
 *
 * @brief Platform For fp tag
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
void fp_tag_platform_init(void);

/**
 * @brief Platform gpio init
 */
void fp_tag_platform_gpio_init(void);

/**
 * @brief Platform reset detect
 */
void fp_tag_platform_reset_detect(void);

#ifdef __cplusplus
}
#endif

///@}