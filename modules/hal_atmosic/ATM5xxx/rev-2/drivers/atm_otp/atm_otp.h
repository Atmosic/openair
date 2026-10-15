/**
 *******************************************************************************
 *
 * @file atm_otp.h
 *
 * @brief Atmosic OTP driver
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#pragma once

/**
 *******************************************************************************
 * @defgroup ATM_OTP OTP
 * @ingroup DRIVERS
 * @brief ATM OTP driver
 *
 * This module contains the necessary functions to read OTP values.
 *
 * @{
 *******************************************************************************
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include "compiler.h"
#ifdef SECURE_MODE
#include "sec_assert.h"
#endif

typedef uint64_t atm_otp_t;

#define OTP_MASK(_start, _size) ((atm_otp_t)((1ull << (_size)) - 1) << (_start))

#define ATM_OTP_MASK_NABG_TRIM_LATCH            OTP_MASK(0, 9)
#define ATM_OTP_MASK_VDDIO_RANGE_LATCH          OTP_MASK(9, 1)
#define ATM_OTP_MASK_HARV_DISABLED              OTP_MASK(10, 1)
#define ATM_OTP_MASK_SEC_DBG_DEBUG_DISABLED     OTP_MASK(14, 1)
#define ATM_OTP_MASK_SEC_DBG_DEBUG_SECURED      OTP_MASK(15, 1)
#define ATM_OTP_MASK_SECURE_FLASH               OTP_MASK(48, 1)
#define ATM_OTP_MASK_FLASH_LOCK0                OTP_MASK(49, 1)
#define ATM_OTP_MASK_FLASH_LOCK1                OTP_MASK(50, 1)
#define ATM_OTP_MASK_FLASH_LOCK2                OTP_MASK(51, 1)
#define ATM_OTP_MASK_UART_RX1_DISABLE           OTP_MASK(56, 1)
#define ATM_OTP_MASK_DISABLE_UPPER_128KB_SYSRAM OTP_MASK(57, 1)
#define ATM_OTP_MASK_CS_CONFIG                  OTP_MASK(58, 1)

#ifdef SECURE_MODE
#define OTP_READ        atm_otp_read
#define OTP_READ_ASSERT SEC_ASSERT
#else
#define OTP_READ        nsc_atm_otp_read
#define OTP_READ_ASSERT ASSERT_ERR
#endif

#if (defined(SECURE_MODE) || defined(CFG_NO_SPE))
/**
 * @brief Read the specified bits from otp
 *
 * @param[out] otp_value pointer to write results
 *
 * @return true if otp is read successfully
 */
__NONNULL(1) bool atm_otp_read(atm_otp_t *otp_value);
/**
 * @brief Read data from a specified OTP address range.
 *
 *
 * @param[in] address The starting address in the OTP memory to read from.
 * @param[in] length The number of bytes to read.
 * @param[out] buf Pointer to the buffer where the read data will be stored.
 * @param[in] invertbit If true, each bit in the read data will be inverted.
 */
__NONNULL(3)
void atm_otp_read_address(uint32_t const address, uint32_t const length, uint8_t *buf,
			  bool invertbit);
#endif

/**
 * @brief NS-callable function of atm_otp_read
 */
__NONNULL(1) bool nsc_atm_otp_read(atm_otp_t *otp_value);

/**
 * @brief Determine if an OTP bit is set
 *
 * @param[in] otp_mask pointer to write results
 *
 * @return true if a bit set in otp_mask is set in otp
 */
__STATIC_FORCEINLINE bool atm_otp_check_bit(atm_otp_t otp_mask)
{
	atm_otp_t otp = 0;
	__UNUSED bool success = OTP_READ(&otp);
	OTP_READ_ASSERT(success);
	return (otp & otp_mask) != 0;
}

#ifdef __cplusplus
}
#endif

///@}
