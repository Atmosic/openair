/*****************************************************************************************
*
* @file workarounds.h
*
* @brief ROM initialization workarounds
*
* Copyright (C) Atmosic 2018-2019
*
*
*****************************************************************************************/

#ifndef __WORKAROUNDS_H__
#define __WORKAROUNDS_H__

/**
 * @defgroup WORKAROUNDS WORKAROUNDS
 * @ingroup DRIVERS
 * @brief ROM driver for OTP-based register workarounds
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Apply manufacturing hardware workarounds.
 *
 * Normally called during late ROM init.
 * User applications that never return to the ROM (and third party OSes)
 * must call this during initialization.
 */
void workarounds_init(void);

#ifdef __cplusplus
}
#endif

/// @} WORKAROUNDS

#endif // __WORKAROUNDS_H__
