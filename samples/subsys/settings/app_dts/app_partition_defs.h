/**
 *******************************************************************************
 *
 * @file app_partition_defs.h
 *
 * @brief Atmosic application partition definitions, only to be included by
 * device tree files as DTS overlays for partition layouts.
 *
 * Copyright (C) Atmosic 2024-2025
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 *******************************************************************************
 */

#ifndef _ATMOSIC_ATM_APP_PARTITION_DEFS_H_
#define _ATMOSIC_ATM_APP_PARTITION_DEFS_H_

#ifndef ATM_FACTORY_SIZE
#define ATM_FACTORY_SIZE 0x2000
#else
#error "ATM_FACTORY_SIZE redefinition conflict occurs"
#endif

#ifndef ATM_STORAGE_SIZE
#define ATM_STORAGE_SIZE 0x4000
#else
#error "ATM_STORAGE_SIZE redefinition conflict occurs"
#endif

#endif // _ATMOSIC_ATM_APP_PARTITION_DEFS_H_
