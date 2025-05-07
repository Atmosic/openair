/**
 ******************************************************************************
 *
 * @file sec_assert.h
 *
 * @brief Secure Assert library
 *
 * Copyright (C) Atmosic 2022-2025
 *
 ******************************************************************************
 */

#pragma once

/**
 * @defgroup SEC_ASSERT Secure Assert
 * @ingroup ATM_UTILS
 * @brief Secure Assert library
 * @{
 */
#include <stdio.h>
#include "arch.h"

#if PLF_DEBUG
#define SEC_ASSERT(cond) \
    do { \
	if (!(cond)) { \
	    sec_assert(__MODULE__, __LINE__); \
	} \
    } while (0)
#else
#define SEC_ASSERT(cond) \
    do { \
	if (!(cond)) { \
	    sec_assert(NULL, 0); \
	} \
    } while (0)
#endif

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/devicetree.h>
#include "at_tz_ppc.h"

/**
 * @brief Change the security domain of the UART
 * @param secure make it secure
 */
static inline void sec_switch_uart_domain(bool secure)
{
#if !defined(CONFIG_MCUBOOT) && DT_HAS_CHOSEN(zephyr_console) && \
    DT_NODE_HAS_STATUS_OKAY(DT_CHOSEN(zephyr_console))
    at_tz_ppc_configure((void *)DT_REG_ADDR(DT_CHOSEN(zephyr_console)),
	secure ? ATM_PPC_SECURE : ATM_PPC_NONSECURE);
#endif
}

/**
 * @brief Switch the console to the secure side to allow console printks
 *
 * @note This assumes the PPC controller is not locked out
 */
static inline void sec_switch_console(void)
{
    sec_switch_uart_domain(true);
}

/**
 * @brief Switch the console to the non-secure side
 *
 * @note This assumes the PPC controller is not locked out
 *       Should only be used for testing.
 */
static inline void sec_switch_console_ns(void)
{
    sec_switch_uart_domain(false);
}

#endif // CONFIG_SOC_FAMILY_ATM

/**
 * @brief Print the sercure assertion error reason and halt execution to wait
 * for a watchdog reset.
 *
 * @param[in] file C string containing file where the assertion is located.
 * @param[in] line Line number in the file where the assertion is located.
 *
 * @note If we are in release mode no details will be emitted
 */
__NO_RETURN
void sec_assert(const char *file, int line);

/// @} SEC_ASSERT
