/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

/// rrsp MMI states
typedef enum rrsp_mmi_state_e {
	RRSP_MMI_STATE_INIT,
	RRSP_MMI_STATE_ADV,
	RRSP_MMI_STATE_CONNECTED,
	RRSP_MMI_STATE_CS_SETUP_CMP,
	RRSP_MMI_STATE_CS_PROC_EN,
	RRSP_MMI_STATE_OFF,

	RRSP_MMI_STATE_IDX_MAX
} rrsp_mmi_state_t;

/// rrsp MMI events
typedef enum rrsp_mmi_evt_e {
	RRSP_MMI_EVT_BT_READY,
	RRSP_MMI_EVT_BT_CONN,
	RRSP_MMI_EVT_BT_DISC,
	RRSP_MMI_EVT_CS_CFG_CREATED,
	RRSP_MMI_EVT_CS_SEC_EN,
	RRSP_MMI_EVT_CS_PROC_EN,
	RRSP_MMI_EVT_CS_PROC_DIS,
	RRSP_MMI_EVT_CS_CFG_RM,
	RRSP_MMI_EVT_CS_FORCE_OFF,
	RRSP_MMI_EVT_PWR_OFF,
	RRSP_MMI_EVT_ADV_OFF,

	RRSP_MMI_EVT_INVALID,
} rrsp_mmi_evt_t;

/**
 * @brief Initialize MMI states for rrsp application
 *
 * This function initializes the state for rrsp application.
 *
 */
void rrsp_mmi_init(void);

/**
 * @brief Get the MMI states of rrsp application
 *
 * @return current MMI state of rrsp application
 */
rrsp_mmi_state_t rrsp_mmi_get_state(void);

/**
 * @brief Power off for rrsp application
 *
 * This function power off the state for rrsp application.
 *
 */
void rrsp_mmi_off(void);

#ifdef CONFIG_BTN_FORCE_DISABLE_CS
/**
 * @brief Force disable or revert CS function for rrsp application
 *
 * This function triggers the state machine to disable or revert the CS
 * function. The sequence depends on the current state:
 * - RRSP_MMI_STATE_CS_PROC_EN: disable CS procedure first, wait for procedure
 *   disable complete event, then remove the CS configuration and wait for the
 *   configuration removed event, finally disable the reflector role.
 * - RRSP_MMI_STATE_CS_SETUP_CMP: remove the CS configuration directly, wait for
 *   the configuration removed event, then disable the reflector role.
 * - RRSP_MMI_STATE_CONNECTED: revert the CS reflector role by setting default
 *   settings with reflector role enabled.
 */
void rrsp_mmi_force_cs_off(void);
#endif

#ifdef CONFIG_BTN_ON_OFF
/**
 * @brief Register PM notification for application off check
 *
 * This function register PM notification
 */
// void rrsp_mmi_pm_register(void);
void rrsp_mmi_off_thread_init(void);

/**
 * @brief Unlock sleep to enter soft off state
 *
 * This function unlock the soft off to enter sleep state
 */
void rrsp_mmi_unlock_sleep(void);
#endif
