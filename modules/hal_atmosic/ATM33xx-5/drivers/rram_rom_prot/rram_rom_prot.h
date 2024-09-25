/**
 ******************************************************************************
 *
 * @file rram_rom_prot.h
 *
 * @brief RRAM and ROM Protection Driver
 *
 * Copyright (C) Atmosic 2022-2023
 *
 ******************************************************************************
 */

#pragma once

/**
 * @defgroup RRAM_ROM_PROT RRAM and ROM Protection
 * @ingroup DRIVERS
 * @brief RRAM and ROM Protection Driver
 * @{
 */

#include "atm_bp_clock.h"
#include "ARMv8MBL.h"
#include <inttypes.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RRAM_WRITE_MAX_BP_CLOCK 16000000U

/// RRAM and ROM protection granularity
#define RRAM_ROM_PROT_BLOCK_SIZE 2048

/// Maximum RRAM write protection size
#define RRAM_WRITE_PROTECT_SIZE 0x80000

/// Maximum RRAM sticky write protection size
#define RRAM_STICKY_WRITE_PROTECT_SIZE RRAM_WRITE_PROTECT_SIZE

/// Maximum RRAM sticky read protection size
#define RRAM_READ_PROTECT_SIZE 0x10000

/// Maximium ROM sticky read protection size
#define ROM_READ_PROTECT_SIZE 0x10000

/// Convert RRAM memory address to RRAM relative offset
#define RRAM_ADDR_TO_OFFSET(addr) ((uint32_t)(addr) - RRAM_BASE)

/// Convert ROM memory address to ROM relative offset
#define ROM_ADDR_TO_OFFSET(addr) ((uint32_t)(addr) - CMSDK_FLASH_BASE)

/// Convert a size to a multiple of the protection size (rounding up)
#define RRAM_ROM_PROT_SIZE_RNDUP(size) \
    ((((size) + RRAM_ROM_PROT_BLOCK_SIZE - 1) / RRAM_ROM_PROT_BLOCK_SIZE) * \
	RRAM_ROM_PROT_BLOCK_SIZE)

/**
 * @brief Enable writes to a RRAM region.
 *
 * @note The RRAM region that is enabled may cover one or more
 * RRAM_ROM_PROT_BLOCK_SIZE blocks that spans the region.
 *
 * @param[in] offset offset of region from the start of RRAM
 * @param[in] length length of region
 * @return true on success
 */
bool rram_prot_write_enable(uint32_t offset, uint32_t length);

/**
 * @brief Disable writes to a RRAM region.
 *
 * @note The RRAM region that is disabled may cover one or more
 * RRAM_ROM_PROT_BLOCK_SIZE blocks that spans the region.
 *
 * @param[in] offset offset of region from the start of RRAM
 * @param[in] length length of region
 * @return true on success
 */
bool rram_prot_write_disable(uint32_t offset, uint32_t length);

/**
 * @brief Disable writes to all of RRAM.
 *
 * @note Shortcut to disable all RRAM writes
 *
 * @return true on success
 */
static inline bool rram_prot_write_disable_all(void)
{
    return rram_prot_write_disable(0, RRAM_WRITE_PROTECT_SIZE);
}

/**
 * @brief Sticky write disable a RRAM region.
 *
 * @note Must be block aligned to RRAM_ROM_PROT_BLOCK_SIZE
 *
 * @param[in] offset offset of region from the start of RRAM
 * @param[in] length length of region
 * @return true on success
 */
bool rram_prot_sticky_write_disable(uint32_t offset, uint32_t length);

/**
 * @brief Sticky read disable a RRAM region.
 *
 * @note Must be block aligned to RRAM_ROM_PROT_BLOCK_SIZE
 *
 * @param[in] offset offset of region from the start of RRAM
 * @param[in] length length of region
 * @return true on success
 */
bool rram_prot_sticky_read_disable(uint32_t offset, uint32_t length);

/**
 * @brief Sticky read disable a ROM region.
 *
 * @note Must be block aligned to RRAM_ROM_PROT_BLOCK_SIZE
 *
 * @param[in] offset offset of region from the start of ROM
 * @param[in] length length of region
 * @return true on success
 */
bool rom_prot_sticky_read_disable(uint32_t offset, uint32_t length);

/**
 * @brief Check if entering an rram write section is safe
 *
 * @note Should be called before ENTER_RRAM_WRITE_SECTION if bp_throttle needs
 * to be checked
 *
 * @return true if an rram write section can be enabled safely
 */
bool rram_write_section_allowed(void);

#ifdef CFG_NO_RRAM_WRITE_CRIT_SECTION
#define ENTER_RRAM_WRITE_SECTION() do {} while(0)
#define LEAVE_RRAM_WRITE_SECTION() do {} while(0)
#else
#define ENTER_RRAM_WRITE_SECTION() \
    ATM_BP_CLOCK_ENTER_CRITICAL_SECTION(RRAM_WRITE_MAX_BP_CLOCK)

#define LEAVE_RRAM_WRITE_SECTION() ATM_BP_CLOCK_LEAVE_CRITICAL_SECTION()
#endif

/**
 * @brief Get the sticky lock mask register
 * @param[in] index index of register
 * @param[out] value value of register
 *
 * @return true on success
 */
__NONNULL(2)
bool rram_prot_sticky_write_get_mask(uint8_t index, uint32_t *value);

#ifdef __cplusplus
}
#endif

/// @}
