/**
 ******************************************************************************
 *
 * @file sec_dev_lockout.h
 *
 * @brief Secure device feature lockout driver
 *
 * Copyright (C) Atmosic 2022
 *
 ******************************************************************************
 */

#pragma once

/**
 * @defgroup SEC_DEV_LOCKOUT Secure device feature lockout driver
 * @ingroup DRIVERS
 * @brief Secure device feature lockout driver
 * @{
 */

#include "at_apb_wrpr_pins_regs_core_macro.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * This driver provides APIs to sticky-lock device features to improve
 * system security.  Once a feature is locked out a system reset is required
 * to restore functionality. A secure bootloader or SPE can enable lockouts
 * prior to jumping to the next image in the boot chain.
 * Lockouts that apply to configurations will only prevent altering the
 * configuration post lockdown.
 */

/// Device feature lockout type
typedef enum {
    /// lockout UART0 Transmitter (output is disabled)
    SEC_DEV_LOCKOUT_UART0_TX,
    /// lockout UART1 Transmitter (output is disabled)
    SEC_DEV_LOCKOUT_UART1_TX,
    /// lockout sensor hub usage
    SEC_DEV_LOCKOUT_SHUB_DISABLE,
    /// lockout sensor hub memory access configuration
    SEC_DEV_LOCKOUT_SHUB_ACCESS_CFG,
    /// lockout QSPI from APB cores (disables usage)
    SEC_DEV_LOCKOUT_QSPI_APB,
    /// lockout OTP writes (OTP reads are still valid)
    SEC_DEV_LOCKOUT_OTP_WR,
    /// lockout ROM patch controller configuration (freezes configuration)
    SEC_DEV_LOCKOUT_ROM_P_CFG,
    SEC_DEV_LOCKOUT_MAX,
} sec_device_lockout_type_t;

/**
 * @brief Shutdown the shub
 *
 * @note: This function is called by sec_device_set_lockout if the SHUB is
 * disabled.
 *
 * @return true on success
 */
bool sec_shutdown_shub(void);

/**
 * @brief Program device lockout settings
 *
 * @note: This function is called by sec_device_set_lockout
 *
 * @param[in] mask the lockout bit mask
 * @return true on success
 */
bool sec_device_pgm_lockout(uint32_t mask);


/**
 * @brief Get device lockout bit mask from type
 *
 * @note: This function is called by sec_device_set_lockout
 *
 * @param[in] type the lockout type
 * @return mask value
 */
static inline uint32_t sec_dev_lock_get_mask(sec_device_lockout_type_t type)
{
    switch (type) {
	case SEC_DEV_LOCKOUT_UART0_TX:
	    return WRPRPINS_PROT_BITS_SET1__UART0_LOCK_SET__MASK;
	case SEC_DEV_LOCKOUT_UART1_TX:
	    return WRPRPINS_PROT_BITS_SET1__UART1_LOCK_SET__MASK;
	case SEC_DEV_LOCKOUT_SHUB_DISABLE:
	case SEC_DEV_LOCKOUT_SHUB_ACCESS_CFG:
	    return WRPRPINS_PROT_BITS_SET1__APB_SHUB_LOCK_SET__MASK;
	case SEC_DEV_LOCKOUT_QSPI_APB:
	    return WRPRPINS_PROT_BITS_SET1__APB_QSPI_LOCK_SET__MASK;
	case SEC_DEV_LOCKOUT_OTP_WR:
	    return WRPRPINS_PROT_BITS_SET1__SUPPRESS_OTP_WRITES__MASK;
	case SEC_DEV_LOCKOUT_ROM_P_CFG:
	    return WRPRPINS_PROT_BITS_SET1__SUPPRESS_ROM_PATCH__MASK;
	case SEC_DEV_LOCKOUT_MAX:
	default:
	    return 0;
    }
}

/**
 * @brief Lockout a device feature
 *
 * @note: The device feature is locked out until system reset
 *
 * @param[in] type the type of device feature to lockout
 * @return true on success
 */
static inline bool sec_device_set_lockout(sec_device_lockout_type_t type)
{
    uint32_t mask = sec_dev_lock_get_mask(type);

    if (!mask) {
	return false;
    }

    if (!sec_device_pgm_lockout(mask)) {
	return false;
    }

    if (type == SEC_DEV_LOCKOUT_SHUB_DISABLE) {
	// we need to shutdown the shub at least once to pin the flash ctrl
	// registers to their isolation values
	return sec_shutdown_shub();
    }

    return true;
}

#ifdef __cplusplus
}
#endif

/// @}
