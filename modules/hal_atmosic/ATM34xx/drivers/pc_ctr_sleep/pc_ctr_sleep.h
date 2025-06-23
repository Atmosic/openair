/**
 *******************************************************************************
 *
 * @file pc_ctr_sleep.h
 *
 * @brief Link layer controller sleep
 *
 * Copyright (C) Atmosic 2023-2025
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup PC_CTR_SLEEP PC_CTR_SLEEP
 * @ingroup DRIVERS
 * @brief Link layer controller sleep
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#define PC_CTR_MIN_SLEEP_US 100

enum pc_ctr_sleep_e {
    PC_CTR_ACTIVE = 0,
    PC_CTR_CPU_REST,
    PC_CTR_CPU_SLEEP,
    PC_CTR_ATLC_WAKING,
    PC_CTR_ATLC_WAKING_SOON,
    PC_CTR_ATLC_TO_SLEEP,
    PC_CTR_ATLC_WAS_ASLEEP,
};

typedef enum pc_ctr_sleep_e (*pc_ctr_lpc_cal_fn_t)(uint64_t next_us);

/**
 * @brief Prevent ATLC from going to sleep by incrementing a lock counter.
 * Should be symmetrically paired with a call to unlock when the requirement
 * has cleared.  Internal operation is thread and interrupt safe.
 * @return true when count makes 0->1 transition.
 */
bool pc_ctr_sleep_lock(void);

/**
 * @brief Decrement lock counter.  Permits ATLC to sleep when counter reaches
 * zero.  Internal operation is thread and interrupt safe.
 * @return true when count makes 1->0 transition.
 */
bool pc_ctr_sleep_unlock(void);

/**
 * @brief Check if controller is ready for sleep.  Call from main event loop
 * with global interrupts disabled.
 * @param[out] sleep_duration  Remaining sleep time in LPC ticks.
 * @param[in]  disable_deep_sleep  Prevent deep sleep
 * @return     Sleep status of controller.
 */
enum pc_ctr_sleep_e pc_ctr_sleep(int32_t *sleep_duration,
    bool disable_deep_sleep);

/**
 * @brief Returned from sleep.  Call from main event loop with global
 * interrupts disabled.
 */
void pc_ctr_awake(void);

/**
 * @brief Recompute ATLC wakeup timing registers
 */
void pc_ctr_sleep_recompute_lpcycles(void);

/**
 * @brief Configure a maximum timed duration for ATLC sleep
 *
 * @param[in] max_sleep_lpc  Duration in LPC cycles, or 0 to disable
 * @param[in] fn  LPC RCOS measurement function
 */
void pc_ctr_sleep_set_max_sleep_lpc(uint32_t max_sleep_lpc,
    pc_ctr_lpc_cal_fn_t fn);

/**
 * @brief Fetch LP clock frequency from previous pc_ctr_sleep_set_lp_hz()
 *
 * @return Value in Hz, or 0 when using a xtal
 */
uint32_t pc_ctr_sleep_get_lp_hz(void);

/**
 * @brief Report measured LP clock frequency
 *
 * @param[in] lp_hz         Value in Hz, or 0 when using a xtal
 * @param[in] force_update  True to force update to LP clock frequency
 */
void pc_ctr_sleep_set_lp_hz(uint32_t lp_hz, bool force_update);

/**
 * @brief Initialize driver.
 */
void pc_ctr_sleep_init(void);

#ifdef __cplusplus
}
#endif

/// @}
