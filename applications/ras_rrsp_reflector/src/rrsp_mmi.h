/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
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
	RRSP_MMI_EVT_CS_SEC_EN,
	RRSP_MMI_EVT_CS_PROC_EN,
	RRSP_MMI_EVT_CS_PROC_DIS,
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

#ifdef CONFIG_BTN_ON_OFF
/**
 * @brief Register PM notification for application off check
 *
 * This function register PM notification
 */
//void rrsp_mmi_pm_register(void);
void rrsp_mmi_off_thread_init(void);

/**
 * @brief Unlock sleep to enter soft off state
 *
 * This function unlock the soft off to enter sleep state
 */
void rrsp_mmi_unlock_sleep(void);
#endif
