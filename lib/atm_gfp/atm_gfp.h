/**
 *******************************************************************************
 *
 * @file atm_gfp.h
 *
 * @brief Library For Goole Fast Pair
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#include "compiler.h" // __NONNULL_ALL inline functions
#include "fp_mode.h"

#ifdef __cplusplus
extern "C" {
#endif

/// atm gfp Handlers
typedef struct atm_gfp_hdlrs_s {
	/// get battery status callback function
	uint8_t (*battery_status_cb)(void);
	/// play sound callback function
	void (*sound_action_cb)(bool action);
#ifdef CONFIG_ATM_GFP_MUTLIMODE_TAG
	/// pairing in progress callback function
	void (*mode_state_cb)(fp_mode_t mode);
#endif
} atm_gfp_hdlrs_t;

/**
 * @brief atm gfp init
 *
 * @param [in] hdlrs atm fp_tag handlers structure
 */
__NONNULL_ALL
void atm_gfp_init(atm_gfp_hdlrs_t const *hdlrs);

/**
 * @brief atm gfp deinit
 */
void atm_gfp_reset(void);

/**
 * @brief atm gfp button notify
 */
void atm_gfp_button_notify(void);

#ifdef CONFIG_ATM_GFP_MUTLIMODE_TAG
/**
 * @brief atm gfp pause
 */
void atm_gfp_stop(void);

/**
 * @brief atm gfp resume
 */
void atm_gfp_start(void);

/**
 * @brief atm gfp is provisioned from eik in storage directly
 *
 * @return true if provisioned.
 */
bool atm_gfp_is_provisioned(void);

#endif

#ifdef __cplusplus
}
#endif

///@}
