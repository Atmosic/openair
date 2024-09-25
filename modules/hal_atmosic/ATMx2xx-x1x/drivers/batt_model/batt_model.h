/**
 *******************************************************************************
 *
 * @file batt_model.h
 *
 * @brief Battery model common prototype
 *
 * Copyright (C) Atmosic 2022-2023
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup BATT_MODEL Battery model
 * @ingroup DRIVERS
 * @brief Driver for battery model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/// Device abstract state for battery model
typedef enum {
    /// Invalid state. Use to report error when get state.
    DEV_INVALID,
    /// Reset state. It represents system is booting and doesn't decide wether
    /// goes to normal function or not.
    DEV_RESET,
    /// Active state. System is in normal function.
    DEV_ACTV,
    /// Hibernate state. It represents system is going to hibernation or waking
    /// up from hibernation.
    DEV_HIB,
    /// Soc off state. It represents system is going to SOC off or waking up
    /// from SOC off.
    DEV_SOCOFF,
} dev_state_t;

/// Device state getter and setter.
typedef struct {
    /// Get current device state.
    dev_state_t (*get)(void);
    /// Set current device state.
    void (*set)(dev_state_t);
} dev_state_fns_t;

/// Hibernation flag getter and setter
typedef struct {
    /// Get hibernation flag
    bool (*get)(uint8_t);
    /// Set hibernation flag
    void (*set)(uint8_t, bool);
} hib_flag_fns_t;

/// Callback functions from batt_model
typedef struct {
    /// Device state getter and setter.
    dev_state_fns_t state;
    /// Hibernation getter and setter.
    hib_flag_fns_t flag;
#ifdef CFG_CABLE_CHARGE
    /// Charging with cable.
    bool (*cable)(bool, uint8_t);
#endif
#ifdef CFG_FORMULA_OVERWRITE
    /// Voltage to level.
    uint8_t (*volt_to_level)(float volt);
#endif
} batt_cbs;

/// Battery model virtual functions
typedef struct {
    /// Initialization of the battery model.
    void (*init)(batt_cbs const *);
    /// Issue a battery capacity sampling.
    bool (*sample)(void (*cb)(uint8_t level));
} batt_fns;

/**
 *******************************************************************************
 * @brief Retrieve the functions of battery model
 * return Battery model functions.
 *******************************************************************************
 */
batt_fns const *batt_model(void);
#ifdef __cplusplus
}
#endif

/// @} BATT_MODEL
