/**
 *******************************************************************************
 *
 * @file atm_otp.h
 *
 * @brief Atmosic OTP driver
 *
 * Copyright (C) Atmosic 2022
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

typedef uint64_t atm_otp_t;

#define OTP_MASK(_start, _size) ((atm_otp_t)((1ull << (_size)) - 1) << (_start))

#define ATM_OTP_MASK_NABG_TRIM_LATCH OTP_MASK(0, 9)
#define ATM_OTP_MASK_USE_LDO_LATCH OTP_MASK(9, 1)
#define ATM_OTP_MASK_DISABLE_CHPU_LATCH OTP_MASK(10, 1)
#define ATM_OTP_MASK_HARV_DISABLED_LATCH OTP_MASK(11, 1)
#define ATM_OTP_MASK_RECT_CTUNE_LATCH OTP_MASK(12, 3)
#define ATM_OTP_MASK_INTERNAL_SPARE_LATCH OTP_MASK(15, 4)
#define ATM_OTP_MASK_DISABLE_XTAL32K_LATCH OTP_MASK(19, 1)
#define ATM_OTP_MASK_NOIND_LATCH OTP_MASK(20, 1)
#define ATM_OTP_MASK_DISABLE_VDDIOGEN_LATCH OTP_MASK(21, 1)
#define ATM_OTP_MASK_DISABLE_VDDGEN_LATCH OTP_MASK(22, 1)
#define ATM_OTP_MASK_DISABLE_5V_LATCH OTP_MASK(23, 1)
#define ATM_OTP_MASK_VBATT_LEVEL_LATCH OTP_MASK(24, 1)
#define ATM_OTP_MASK_BATT_TYPE_LATCH OTP_MASK(25, 2)
#define ATM_OTP_MASK_VBATT_GOOD_LATCH OTP_MASK(27, 3)
#define ATM_OTP_MASK_VBATT_BROWNOUT_LATCH OTP_MASK(30, 7)
#define ATM_OTP_MASK_MPPT_TYPE_LATCH OTP_MASK(37, 2)
#define ATM_OTP_MASK_DISABLE_RFHARV_LATCH OTP_MASK(39, 1)
#define ATM_OTP_MASK_VHARV_START_LATCH OTP_MASK(40, 2)
#define ATM_OTP_MASK_VSTORE_GOOD_LATCH OTP_MASK(42, 2)
#define ATM_OTP_MASK_VSTORE_MAX_LATCH OTP_MASK(44, 3)
#define ATM_OTP_MASK_RRAM_WRITE_LOCK OTP_MASK(48, 7)
#define ATM_OTP_MASK_SEC_DBG_CONFIG OTP_MASK(60, 2)
#define ATM_OTP_MASK_RRAM_JTAG_BYPASS OTP_MASK(62, 1)

#define ATM_OTP_MASK_RRAM_WRITE_LOCK_BOOT_BLOCK_0 OTP_MASK(48, 1)
#define ATM_OTP_MASK_RRAM_WRITE_LOCK_BOOT_BLOCK_1 OTP_MASK(49, 1)
#define ATM_OTP_MASK_RRAM_WRITE_LOCK_BOOT_BLOCK_2 OTP_MASK(50, 1)
#define ATM_OTP_MASK_RRAM_WRITE_LOCK_BOOT_BLOCK_3 OTP_MASK(51, 1)
#define ATM_OTP_MASK_RRAM_WRITE_LOCK_PROTECTED_DATA OTP_MASK(52, 1)
#define ATM_OTP_MASK_RRAM_WRITE_LOCK_SECURE_COUNTERS OTP_MASK(53, 1)
#define ATM_OTP_MASK_RRAM_WRITE_LOCK_PRIVATE_KEY_STORAGE OTP_MASK(54, 1)
#define ATM_OTP_MASK_SEC_DBG_DEBUG_DISABLED OTP_MASK(60, 1)
#define ATM_OTP_MASK_SEC_DBG_DEBUG_SECURED OTP_MASK(61, 1)

#if (defined(SECURE_MODE) || defined(CFG_NO_SPE))
/**
 * @brief Read the specified bits from otp
 *
 * @param[out] otp_value pointer to write results
 */
__NONNULL(1) bool atm_otp_read(atm_otp_t *otp_value);
#endif

/**
 * @brief NS-callable function of atm_otp_read
 */
__NONNULL(1) bool nsc_atm_otp_read(atm_otp_t *otp_value);

#ifdef __cplusplus
}
#endif

///@}
