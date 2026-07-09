/**
 *******************************************************************************
 *
 * @file platform.h
 *
 * @brief Platform For Multimode Consumer Tag
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "platform_common.h"
#include "platform_indicate.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Platform init
 */
void platform_init(void);

/**
 * @brief Platform factory reset
 */
void platform_factory_reset(void);

/**
 * @brief Platform gpio init
 */
void platform_gpio_init(void);

/**
 * @brief Platform reset detect
 */
void platform_reset_detect(void);

/**
 * @brief Platform tag supported mode mask get
 * @return supported tag mode mask (OR of all enabled protocols)
 */
uint8_t platform_tag_supported_mode_mask_get(void);

#ifdef CONFIG_AT_CMD_TAG_SET

/**
 * @brief Platform tag mode get
 * @param[out] mode tag mode mask
 * @return 0 if success, negative error code otherwise
 */
int platform_tag_mode_get(uint8_t *mode);

/**
 * @brief Platform tag mode set
 * @param[in] mode tag mode mask
 * @return 0 if success, negative error code otherwise
 */
int platform_tag_mode_set(uint8_t mode);

/**
 * @brief Platform tag start
 * @return 0 if success, negative error code otherwise
 */
int platform_tag_start(void);

/**
 * @brief Platform tag state get
 * @param[out] state tag state
 * @return 0 if success, negative error code otherwise
 */
int platform_tag_state_get(uint8_t *state);

#endif

#ifdef __cplusplus
}
#endif
