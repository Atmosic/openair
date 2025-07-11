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
 * @brief battery status get
 *
 * @return battery status in mVolt
 */
int32_t rrsp_batt_status_get(void);

#ifdef __cplusplus
}
#endif

///@}
