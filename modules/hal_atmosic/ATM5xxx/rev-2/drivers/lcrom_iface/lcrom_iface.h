/**
 *******************************************************************************
 *
 * @file lcrom_iface.h
 *
 * @brief Interface file for the LCROM
 *
 * The confidential and proprietary information contained in this file may
 * only be used by a person authorised under and to the extent permitted
 * by a subsisting licensing agreement from Atmosic.
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 * This entire notice must be reproduced on all copies of this file
 * and copies of this file may only be made by a person if such person is
 * permitted to do so under the terms of a subsisting license agreement
 * from Atmosic.
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup LCROM_IFACE LCROM interface
 * @ingroup DRIVERS
 * @brief LCROM initialization
 * @{
 */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * This module defines the interface between the Link Controller ROM image
 * (LCROM) and the main application. The accompanying C file must be built
 * into the LCROM only.
 */

typedef struct {
    uint32_t addr;
    uint32_t abs;
} lcrom_abs_t;

/**
 * @brief Initialize the LCROM interface
 *
 * This function is called from the main image into the LCROM in order to
 * set up all of the pointers that are needed.
 */
void lcrom_iface_init(lcrom_abs_t const *abs);

#ifdef __cplusplus
}
#endif

/// @} LCROM_IFACE
