/**
 ******************************************************************************
 *
 * @file wurx.h
 *
 * @brief Wake-Up Receiver
 *
 * Copyright (C) Atmosic 2019-2021
 *
 *
 ******************************************************************************
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>

/**
 * @defgroup WURX WURX
 * @ingroup DRIVERS
 * @brief Driver to configure wake-up receiver from NVDS
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/// WURX state
extern bool wurx0_enabled, wurx1_enabled;

/**
 * @brief Configure wake-up receiver
 * @param[in]  pseq_boot_status  PSEQ status collected by ROM at boot
 */
void wurx_init(uint32_t pseq_boot_status);

/**
 * @brief set WURX0 config state
 *
 */
static inline void set_wurx0_enabled(bool enable)
{
    wurx0_enabled = enable;
}

/**
 * @brief set WURX1 config state
 */
static inline void set_wurx1_enabled(bool enable)
{
    wurx1_enabled = enable;
}

/**
 * @brief Enable WURX0 and WURX1
 */
static inline void wurx_enable(void)
{
    wurx0_enabled = wurx1_enabled = true;
}

/**
 * @brief Disable WURX0 and WURX1
 */
void wurx_disable(void);

#ifdef __cplusplus
}
#endif

/// @} WURX

