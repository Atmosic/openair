/**
 *******************************************************************************
 *
 * @file sec_hw_cfg.h
 *
 * @brief Early and secure hardware configuration
 *
 * Copyright (C) Atmosic 2022-2024
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

/// ROM version
typedef enum {
    /// ROM version on A0
    ROM_VER_A0 = '1',
    /// ROM version on A1
    ROM_VER_A1 = '2',
    /// ROM version on B0
    ROM_VER_B0 = '3',
} rom_version_t;

#if (defined(SECURE_MODE) || defined(CFG_NO_SPE))
/**
 * @brief Apply hardware configuration
 * @note  Called before bss and data sections are initialized
 */
void sec_hw_cfg_init(void);

/**
 * @brief Return the ROM version
 *
 * @return ROM version
 */
rom_version_t sec_hw_cfg_rom_version(void);
#endif

/**
 * @brief Return the ROM version (NS-callable)
 *
 * @return ROM version
 */
rom_version_t nsc_sec_hw_cfg_rom_version(void);

#ifdef __cplusplus
}
#endif

/// @} SEC_HW_CFG
