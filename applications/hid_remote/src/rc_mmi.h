/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include "rc_gap.h"

/** RC MMI states */
typedef enum {
	MMI_S_BOOTED,     /* Power-on / just booted */
	MMI_S_INITING,    /* GAP + GATT services initialising */
	MMI_S_IDLE,       /* Idle; no BLE connection */
	MMI_S_PAIRING,    /* Advertising for new host pairing */
	MMI_S_RECONNING,  /* Directed advertising to bonded host */
	MMI_S_CONNECTED,  /* BLE connected; HOGP not yet ready */
	MMI_S_HID_READY,  /* HOGP ready; key reports can be sent */
	MMI_S_STREAMING,  /* ATVV audio streaming in progress */
	MMI_S_DISCONNING, /* Disconnecting */
	MMI_S_RF_TEST,    /* RF production test mode */
	MMI_S_NUM,
} mmi_state_t;

/** RC MMI operations (events that drive state transitions) */
typedef enum {
	MMI_OP_INITING,
	MMI_OP_INIT_DONE,
	MMI_OP_RECONNING,
	MMI_OP_PAIRING,
	MMI_OP_RECONN_FAIL,
	MMI_OP_PAIR_FAIL,
	MMI_OP_PAIR_FAIL_ADV_TOUT,
	MMI_OP_PAIR_SUCCESS,
	MMI_OP_CONNECTED,
	MMI_OP_DISCONNED,
	MMI_OP_HID_READY,
	MMI_OP_HID_UNREADY,
	MMI_OP_DISCONNING,
	MMI_OP_ADV_STOPPED,
	MMI_OP_ATVV_READY,   /* ATVV CCCs enabled by host */
	MMI_OP_ATVV_UNREADY, /* ATVV CCCs disabled or disconnected */
	MMI_OP_OPEN_MIC,     /* Host sent MIC_OPEN → start streaming */
	MMI_OP_CLOSE_MIC,    /* Host sent MIC_CLOSE → stop streaming */
	MMI_OP_NUM,
} mmi_op_t;

/**
 * @brief Initialise the RC MMI state machine.
 */
void rc_mmi_init(void);

/**
 * @brief Trigger a state transition from any context.
 *
 * @param op  Operation to dispatch.
 */
void rc_mmi_run_event(mmi_op_t op);

/**
 * @brief Return the current MMI state index.
 *
 * Used by rc_input.c to determine how to handle key events
 * without coupling the input layer to the SMF internals.
 */
int rc_mmi_get_state(void);
