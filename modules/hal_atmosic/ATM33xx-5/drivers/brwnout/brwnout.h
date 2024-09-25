/**
 ******************************************************************************
 *
 * @file brwnout.h
 *
 * @brief Brownout Driver APIs
 *
 * Copyright (C) Atmosic 2022
 *
 ******************************************************************************
 */

#pragma once

/**
 * @defgroup BRWNOUT BRWNOUT
 * @ingroup DRIVERS
 * @brief Brownout Driver API: enable/disable brownout support
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enable Brownout Support
 */
extern void brwnout_enable(void);

/**
 * @brief Disable Brownout Support
 */
extern void brwnout_disable(void);

/**
 * @brief Brownout status
 *
 * @return True if brownout condition is statisfied.
 */
extern bool brwnout_status(void);

/**
 * @brief Force to soc off
 */
extern void brwnout_force_socoff(void);
#ifdef __cplusplus
}
#endif

/// @} BRWNOUT
