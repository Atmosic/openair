/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <stdint.h>
#include "rc_keycode.h"

/** @brief Key matrix dimensions. */
#define RC_VKEY_ROWS 4
#define RC_VKEY_COLS 4

/**
 * @brief Look up the HID keyboard usage ID for (row, col).
 *
 * Most keys use Consumer Control usage page and return HID_KEY_NONE here.
 * VK_MENU (row 1, col 3) is the only KBD-page key: BT_MENU = KBD(0x76).
 *
 * @param row   Matrix row (0-based).
 * @param col   Matrix column (0-based).
 * @return HID keyboard usage ID, or HID_KEY_NONE for Consumer Control keys.
 */
static inline uint8_t rc_vkey_get_keycode(uint32_t row, uint32_t col)
{
	if (row >= RC_VKEY_ROWS || col >= RC_VKEY_COLS) {
		return HID_KEY_NONE;
	}

	static const uint8_t keycode_map[RC_VKEY_ROWS][RC_VKEY_COLS] = {
		/* col:      0              1              2              3          */
		/* row 0 */ {HID_KEY_NONE, HID_KEY_NONE, HID_KEY_NONE, HID_KEY_NONE},
		/* row 1 */ {HID_KEY_NONE, HID_KEY_NONE, HID_KEY_NONE, HID_KEY_MENU}, /* VK_MENU */
		/* row 2 */ {HID_KEY_NONE, HID_KEY_NONE, HID_KEY_NONE, HID_KEY_NONE},
		/* row 3 */ {HID_KEY_NONE, HID_KEY_NONE, HID_KEY_NONE, HID_KEY_NONE},
	};

	return keycode_map[row][col];
}

/**
 * @brief Look up the HID Consumer Control usage ID for (row, col).
 * @param row   Matrix row (0-based).
 * @param col   Matrix column (0-based).
 * @return HID Consumer Control usage ID, or 0 for unmapped or KBD-page keys.
 * Returns 0 for unmapped or KBD-page keys.
 */
static inline uint16_t rc_vkey_get_consumer_code(uint32_t row, uint32_t col)
{
	if (row >= RC_VKEY_ROWS || col >= RC_VKEY_COLS) {
		return 0;
	}

	static const uint16_t consumer_map[RC_VKEY_ROWS][RC_VKEY_COLS] = {
		/* col:      0               1               2               3           */
		/* row 0 */ {HID_CSM_POWER, HID_CSM_MIC, HID_CSM_UP, HID_CSM_RIGHT},
		/* row 1 */ {HID_CSM_LEFT, HID_CSM_BACK, HID_CSM_HOME, 0}, /* col3=MENU(KBD) */
		/* row 2 */ {HID_CSM_OK, 0, HID_CSM_PLAY_PAUSE, HID_CSM_VOLUMEUP},
		/* row 3 */ {HID_CSM_DOWN, HID_CSM_BW, HID_CSM_FW, HID_CSM_VOLUMEDOWN},
	};

	return consumer_map[row][col];
}

#ifdef CONFIG_IR_NEC
/**
 * @brief Look up the NEC IR address and command for (row, col).
 * @param row    Matrix row (0-based).
 * @param col    Matrix column (0-based).
 * @param addr   Output: NEC device address.
 * @param cmd    Output: NEC command byte.
 * @return true if an IR code is mapped for this key, false otherwise.
 */
static inline bool rc_vkey_get_ir_code(uint32_t row, uint32_t col, uint16_t *addr, uint8_t *cmd)
{
	static const uint8_t ir_cmd_map[RC_VKEY_ROWS][RC_VKEY_COLS] = {
		/* col:      0          1          2          3      */
		/* row 0 */ {IR_POWER, 0, IR_UP, IR_RIGHT},       /* POWER MIC(no IR) UP RIGHT */
		/* row 1 */ {IR_LEFT, IR_BACK, IR_HOME, IR_MENU}, /* LEFT BACK HOME MENU */
		/* row 2 */ {IR_OK, 0, 0, IR_VOLU},   /* OK RICE(no IR) PLAY(no IR) VOLUP */
		/* row 3 */ {IR_DOWN, 0, 0, IR_VOLD}, /* DOWN BW(no IR) FW(no IR) VOLDN */
	};

	if (row >= RC_VKEY_ROWS || col >= RC_VKEY_COLS || ir_cmd_map[row][col] == 0) {
		return false;
	}
	*addr = IR_ADDR;
	*cmd = ir_cmd_map[row][col];
	return true;
}
#endif /* CONFIG_IR_NEC */
