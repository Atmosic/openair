/**
 ******************************************************************************
 *
 * @file brwnout.h
 *
 * @brief Brownout Driver APIs
 *
 * Copyright (C) Atmosic 2022-2026
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

/**
 * @brief Brownout PMU interrupt handler
 *
 * Called by central PMU_Handler() when brownout interrupt fires.
 */
void brwnout_pmu_handler(void);

#ifdef __cplusplus
}
#endif

/**
 * @brief SW-defined bit in PSEQ PERSISTENT7 used as a falling-brownout flag.
 *
 * Set by brwnout.c before hibernation; checked and cleared by
 * sec_hw_cfg_core.c on the subsequent wakeup.
 */
#define PSEQ_PERSISTENT7_BROWNOUT_FALLING (1U << 0)

/// @} BRWNOUT
