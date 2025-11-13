/**
 *******************************************************************************
 *
 * @file pc_ctr.h
 *
 * @brief Link layer controller
 *
 * Copyright (C) Atmosic 2022-2025
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup PC_CTR PC_CTR
 * @ingroup DRIVERS
 * @brief Link layer controller
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_ATM_LCROM_IFACE
/**
 * @brief Early (pre-MPU) initialization routine for link layer controller.
 */
void pc_ctr_early_init(void);
#endif

/**
 * @brief Initialization routine for link layer controller.
 */
void pc_ctr_main(void);

/**
 * @brief Process a unit of work for controller.  Call from main event loop.
 */
bool pc_ctr_schedule(void);

#ifdef __cplusplus
}
#endif

/// @}
