/**
 ******************************************************************************
 *
 * @file rom_prot.h
 *
 * @brief ROM Protection Driver
 *
 * Copyright (C) Atmosic 2025
 *
 ******************************************************************************
 */

#pragma once

/**
 * @defgroup NV_MEM_PROT ROM Protection
 * @ingroup DRIVERS
 * @brief ROM Protection Driver
 * @{
 */
#include <zephyr/devicetree.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ROM_PROT_NODE DT_NODELABEL(sec_rom_prot)

/// ROM protection granularity
#define ROM_PROT_BLOCK_SIZE DT_PROP(ROM_PROT_NODE, blk_size)

/// Maximium ROM sticky read protection size
#define ROM_STICKY_READ_PROTECT_SIZE DT_PROP(ROM_PROT_NODE, read_prot_size)

/// Convert ROM memory address to ROM relative offset
#define ROM_ADDR_TO_OFFSET(addr) (((uint32_t)(addr)) - CMSDK_FLASH_BASE)

/// Convert a size to a multiple of the protection size (rounding up)
#define ROM_PROT_SIZE_RNDUP(size)                                                                  \
	((((size) + ROM_PROT_BLOCK_SIZE - 1) / ROM_PROT_BLOCK_SIZE) * ROM_PROT_BLOCK_SIZE)

/**
 * @brief Sticky read disable a ROM region.
 *
 * @note Must be block aligned to ROM_PROT_BLOCK_SIZE
 *
 * @param[in] offset offset of region from the start of ROM
 * @param[in] length length of region
 * @return true on success
 */
bool rom_prot_sticky_read_disable(uint32_t offset, uint32_t length);

#ifdef __cplusplus
}
#endif

/// @}
