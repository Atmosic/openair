/**
 *******************************************************************************
 *
 * @file app_batt.h
 *
 * @brief battery procedure for application layer.
 *
 * Copyright (C) Atmosic 2022-2024
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup APP_BATT_PROC Battery free procedure for application layer.
 * @ingroup ATM_BTFM_PROC
 * @brief Battery free procedure that control HSC and booster.
 * @{
 */

#include "arch.h"
#ifndef CONFIG_SOC_FAMILY_ATM
#include "gadc.h"
#endif
#include "batt_model.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Bit definition for hiberation restart.
#define APP_BATT_HIB_RESTART_BIT (1 << 0)
/// Bit definition for auto timer
#define APP_BATT_AUTO_TIMER_BIT (1 << 1)
/// Bit definition for LPC wakeup for DEV_SOCOFF state.
#define APP_BATT_LPC_WAKEUP_BIT (1 << 2)


#ifndef CFG_APP_BATT_FEATURE
#define CFG_APP_BATT_FEATURE (APP_BATT_HIB_RESTART_BIT |\
    APP_BATT_AUTO_TIMER_BIT | APP_BATT_LPC_WAKEUP_BIT)
#endif

#if (CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT)
/// The low battery percentage boundary.
#define APP_BATT_LOW_BATTERY_PERCENTAGE 30
/// Time to poll capacity while battery is low.
#ifndef APP_BATT_LOW_POLL_TIME_CS
#define APP_BATT_LOW_POLL_TIME_CS 10000
#endif
/// Time to poll capacity while battery is high.
#ifndef APP_BATT_HIGH_POLL_TIME_CS
#define APP_BATT_HIGH_POLL_TIME_CS 60000
#endif
#endif

#if (CFG_APP_BATT_FEATURE & APP_BATT_HIB_RESTART_BIT)
/// Time to check while low battery in hibernation
#define APP_BATT_HIB_TIME_CS 60000
#endif

/// Callback functions to application.
typedef struct {
    /// Start application.
    void (*app_start)(void (*done)(void));
    /// Stop application.
    void (*app_stop)(void (*done)(void));
    /// Update battery level.
    void (*level_update)(uint8_t);
#ifdef CFG_CABLE_CHARGE
    /// Cable status report
    bool (*cable)(bool, uint8_t);
#endif
} app_batt_cbs_t;

/**
 *******************************************************************************
 * @brief Start application battery procedure.
 * @param[in] cbs Callback to application.
 *******************************************************************************
 */
void app_batt_start(app_batt_cbs_t const *cbs);

#if (CFG_APP_BATT_FEATURE & APP_BATT_AUTO_TIMER_BIT)
/**
 *******************************************************************************
 * @brief Stop application battery procedure.
 *******************************************************************************
 */
void app_batt_stop(void);
#else
/**
 *******************************************************************************
 * @brief Get the battery level.
 * @return False if another operation is onging.
 * @note The result will pass to level_update callback function.
 *******************************************************************************
 */
bool app_batt_get_level(void);
#endif
#ifdef __cplusplus
}
#endif

/// @} APP_BATT_PROC
