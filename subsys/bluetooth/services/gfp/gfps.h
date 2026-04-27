/**
 *******************************************************************************
 *
 * @file gfps.h
 *
 * @brief Google Fast Pair Service
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#pragma once

#include <zephyr/bluetooth/uuid.h>
#include "fp_common.h"
#ifdef CONFIG_FAST_PAIR_FMDN
#include "fp_fmdn_gatt.h"
#include "fp_fmdn_key.h"
#ifdef CONFIG_FMDN_REVERSE_RINGING
#include "fp_fmdn_reverse_ringing.h"
#endif
#endif
#include "fp_mode.h"
/**
 * @defgroup ATM_BTGFPS Google Fast Pair Service
 * @brief Google Fast Pair Service
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/// GFPS handlers
typedef struct gfps_hdlrs_s {
	/// FP mode switch callback function
	fp_mode_switch_cb mode_switch_cb;
#ifdef CONFIG_FAST_PAIR_FMDN
	/// FP FMDN utp mode callback function
	fp_fmdn_utp_mode_cb utp_mode_cb;
	/// FP FMDN ring action callback function
	fp_fmdn_ring_action_cb ring_action_cb;
	/// FP FMDN battery status callback function
	fp_fmdn_battery_cb battery_status_cb;
#ifdef CONFIG_FMDN_REVERSE_RINGING
	/// FP FMDN reverse ringing action callback function
	fp_fmdn_reverse_ringing_action_cb reverse_ringing_action_cb;
#endif
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
	/// FP FMDN utp owner connected callback function
	fp_fmdn_utp_owner_conn_cb utp_owner_conn_cb;
	/// FP FMDN update dult id callback function
	fp_fmdn_update_id_cb update_id_cb;
#endif
#ifdef CONFIG_FMDN_PRECISION_FINDING
	fp_fmdn_ranging_handler_t *ranging_handlers;
#endif // CONFIG_FMDN_PRECISION_FINDING
#endif // CONFIG_FAST_PAIR_FMDN
} gfps_hdlrs_t;

/**
 * @brief gfps handlers register
 * @param[in] hdlr gfps handlers structure
 */
__NONNULL_ALL
void gfps_handlers_register(gfps_hdlrs_t const *hdlrs);

/**
 * @brief GPFS fast button notify
 * @param[in] tap_type button tap type
 */
void gfps_button_notify(fp_tap_type_t tap_type);

/**
 * @brief GPFS init
 * @param fw_version Firmware version string to be used by the DIS service.
 * @return 0 if successful. Otherwise, a (negative) error code is returned.
 */
__NONNULL_ALL
int gfps_init(const char *fw_version);

/**
 * @brief GPFS deinit
 */
void gfps_deinit(void);

/**
 * @brief GPFS reset
 */
void gfps_reset(void);

/**
 * @brief GPFS enable fp pairing adv
 */
void gfps_fp_pairing_adv(void);

/**
 * @brief GPFS fp is provisioned from eik in storage directly
 *
 * @return true if provisioned.
 */
bool gfps_fp_is_provisioned(void);

#ifdef __cplusplus
}
#endif

///@}
