/**
 *******************************************************************************
 *
 * @file sec_hw_cfg.h
 *
 * @brief Early and secure hardware configuration
 *
 * Copyright (C) Atmosic 2022-2023
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup SEC_HW_CFG Secure hw_cfg
 * @ingroup DRIVERS
 * @brief Secure driver to apply hardware configuration
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Apply hardware configuration
 * @note  Called before bss and data sections are initialized
 */
void sec_hw_cfg_init(void);

#ifdef __cplusplus
}
#endif

/// @} SEC_HW_CFG
