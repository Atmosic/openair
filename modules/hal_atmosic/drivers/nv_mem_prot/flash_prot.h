/**
 ******************************************************************************
 *
 * @file flash_prot.h
 *
 * @brief FLASH Protection Driver
 *
 * Copyright (C) Atmosic 2025
 *
 ******************************************************************************
 */

#pragma once

/**
 * @defgroup NV_MEM_PROT FLASH Protection
 * @ingroup DRIVERS
 * @brief FLASH Protection Driver
 * @{
 */

#include <zephyr/devicetree.h>

#ifdef __cplusplus
extern "C" {
#endif

#define FLASH_PROT_NODE DT_NODELABEL(sec_flash_prot)

/// FLASH protection granularity
#define FLASH_PROT_BLOCK_SIZE DT_PROP(FLASH_PROT_NODE, blk_size)

/// Maximum FLASH sticky write protection size
#define FLASH_STICKY_WRITE_PROTECT_SIZE DT_PROP(FLASH_PROT_NODE, write_prot_size)

/// Maximum FLASH sticky read protection size
#define FLASH_STICKY_READ_PROTECT_SIZE DT_PROP(FLASH_PROT_NODE, read_prot_size)

/// Convert FLASH memory address to FLASH relative offset
#define FLASH_ADDR_TO_OFFSET(addr) (((uint32_t)(addr)) - EXT_FLASH_BASE)

/// Convert a size to a multiple of the protection size (rounding up)
#define FLASH_PROT_SIZE_RNDUP(size)                                                                \
	((((size) + FLASH_PROT_BLOCK_SIZE - 1) / FLASH_PROT_BLOCK_SIZE) * FLASH_PROT_BLOCK_SIZE)

/**
 * @brief Sticky write disable a FLASH region.
 *
 * @note Must be block aligned to FLASH_PROT_BLOCK_SIZE
 *
 * @param[in] offset offset of region from the start of FLASH
 * @param[in] length length of region
 * @return true on success
 */
bool flash_prot_sticky_write_disable(uint32_t offset, uint32_t length);

/**
 * @brief Sticky read disable a FLASH region.
 *
 * @note Must be block aligned to FLASH_PROT_BLOCK_SIZE
 *
 * @param[in] offset offset of region from the start of FLASH
 * @param[in] length length of region
 * @return true on success
 */
bool flash_prot_sticky_read_disable(uint32_t offset, uint32_t length);

/**
 * @brief Get the sticky lock mask register
 * @param[in] index index of register
 * @param[out] value value of register
 *
 * @return true on success
 */
__NONNULL(2)
bool flash_prot_sticky_write_get_mask(uint8_t index, uint32_t *value);

#ifdef __cplusplus
}
#endif

/// @}
