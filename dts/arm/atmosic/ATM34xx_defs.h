/**
 *******************************************************************************
 *
 * @file ATM34xx_defs.h
 *
 * @brief Atmosic ATM34 system definitions
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#ifndef _ATMOSIC_ATM_ATM34XX_DEFS_H_
#define _ATMOSIC_ATM_ATM34XX_DEFS_H_

#define RUN_APP_NORMAL         0
#define RUN_APP_IN_FLASH       1
#define RUN_APP_IN_FLASH_SPLIT 2

#ifdef ATM_APP_FLASH_XIP
// if user application is to run in flash XIP, select the split image option
// ONLY
#define RUN_IN_FLASH RUN_APP_IN_FLASH_SPLIT
#elif ATM_APP_FLASH_XIP_NO_SPLIT
// internal testing only, no fastcode split
#define RUN_IN_FLASH RUN_APP_IN_FLASH
#endif

#endif // _ATMOSIC_ATM_ATM34XX_DEFS_H_
