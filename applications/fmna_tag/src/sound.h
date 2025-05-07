/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize sound
 */
void sound_init(void);

/**
 * @brief Start sound
 */
void sound_start(void);

/**
 * @brief Stop sound
 */
void sound_stop(void);

#ifdef __cplusplus
}
#endif
