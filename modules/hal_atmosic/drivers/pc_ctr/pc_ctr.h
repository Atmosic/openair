/**
 *******************************************************************************
 *
 * @file pc_ctr.h
 *
 * @brief Link layer controller
 *
 * Copyright (C) Atmosic 2022-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
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

/**
 * @brief Allocate and return pointer to link layer heap.
 *
 * @return Pointer to the allocated heap buffer.
 */
uint8_t *pc_ctr_ll_heap_alloc(void);

/**
 * @brief Config bt version.
 *
 * @param[in] bt_ver The bt version.
 */
void pc_ctr_bt_ver_config(uint8_t bt_ver);

#ifndef CONFIG_SOC_ATM5XXX_2
/**
 * @brief Set DTM packet interval at runtime.
 *
 * @param[in] slots Packet interval in slots (0=no override, 1 slot=625us).
 */
void pc_ctr_set_dtm_pkt_interval(uint8_t slots);
#endif

#ifdef __cplusplus
}
#endif

/// @}
