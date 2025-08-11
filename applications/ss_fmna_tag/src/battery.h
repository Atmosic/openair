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
 * @brief Battery get level
 * @return Battery level
 */
fmna_bat_state_level_t battery_level_get(void);

#ifdef __cplusplus
}
#endif
