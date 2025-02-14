/**
 *******************************************************************************
 *
 * @file eui.h
 *
 * @brief Extended Unique Identifier (EUI) handling
 *
 * Copyright (C) Atmosic 2023-2025
 *
 *******************************************************************************
 */

#pragma once

#include "arch.h"

/**
 * @defgroup EUI EUI
 * @ingroup DRIVERS
 * @brief Extended Unique Identifier handling module
 *
 * This module implements retrieval of Extended Unique Identifiers (EUIs) used
 * to identify a specific chip.
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

enum atm_eui_tag {
    /// Local EUI-48 (compare NVDS_TAG_BD_ADDRESS and PARAM_ID_BD_ADDRESS)
    ATM_TAG_EUI48 = 0x01,
    /// Local EUI-64
    ATM_TAG_EUI64 = 0x03,
};

/** Number of bytes in an EUI-48 */
#define EUI48_LEN_BYTES 6
/** Number of bytes in an EUI-64 */
#define EUI64_LEN_BYTES 8

/**
 * @brief Gets the EUI-48 for this device
 *
 * This function is used to read the EUI-48 from the secure journal directly.
 * As a fallback, a random address is generated when EUI_ALLOW_RANDOM is set.
 * And this function will return false asserting when EUI48_ALLOW_BUILTIN is
 * set. Controller's code will then use the default address based on the return
 * value. This function will assert when there is no EUI-48 within the
 * secure journal if neither EUI_ALLOW_RANDOM nor EUI48_ALLOW_BUILTIN is set.
 *
 * @param[out] address A pointer to the bytes of the EUI-48 to be filed in.
 *   Must be 6 bytes in length
 * @return Return true if data was read.
 */
__NONNULL(1)
bool read_eui48(uint8_t *address);

/**
 * @brief Gets the EUI-64 for this device
 *
 * This function is used to read the EUI-64 from the secure journal, either
 * directly or as a conversion from an EUI-48. The converion routine is only
 * valid within MA-L allocations. As a fallback, a random address is generated
 * when EUI_ALLOW_RANDOM is set. This function will assert when there is no
 * EUI-64 or EUI-48 within the secure journal if EUI_ALLOW_RANDOM is not set.
 *
 * @param[out] address A pointer to the bytes of the EUI-64 to be filed in.
 *   Must be 8 bytes in length
 */
__NONNULL(1)
void read_eui64(uint8_t *address);

#ifdef __cplusplus
}
#endif

/// @} EUI
