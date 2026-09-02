/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/reboot.h>
#include <zephyr/input/input.h>
#include <zephyr/device.h>
#include <zephyr/logging/log.h>

#ifdef CONFIG_PM
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#endif

#include "rc_input.h"
#include "rc_mmi.h"
#include "rc_vkey.h"
#include "bt/rc_gap.h"
#include "bt/rc_hids.h"
#include "rc_led.h"
#ifdef CONFIG_IR_NEC
#include "rc_ir.h"
#endif
#ifdef CONFIG_RC_VOICE
#include "rc_audio.h"
#endif

LOG_MODULE_REGISTER(rc_input, CONFIG_HID_REMOTE_LOG_LEVEL);

#define INPUT_KBD_MATRIX_NODE DT_NODELABEL(input_kbd_matrix)

#define KEY_BUF_SIZE 16
static struct {
	uint8_t row;
	uint8_t col;
	bool pressed;
} keybuf[KEY_BUF_SIZE];
static uint8_t keybuf_offset;
static bool state_reconnected;

/* Key positions from rc_vkey.h consumer_map */
#define COMBO_HOME_ROW 1
#define COMBO_HOME_COL 2
#define COMBO_BACK_ROW 1
#define COMBO_BACK_COL 1
#define COMBO_OK_ROW   2
#define COMBO_OK_COL   0
#define COMBO_VOLU_ROW 2
#define COMBO_VOLU_COL 3

enum combo_id {
	COMBO_PAIRING,  /* HOME + BACK — enter pairing mode */
	COMBO_DEL_BOND, /* OK + VOLU  — delete all bonds    */
	COMBO_NUM,
};

enum combo_key_slot {
	COMBO_KEY_A,
	COMBO_KEY_B,
	COMBO_KEY_COUNT,
};

#define KBD_KEY_ROW_CMP(row, key)       ((row) == (key))
#define KBD_KEY_COLUMN_CMP(column, key) ((column) == (key))
#define KBD_KEY_CMP(row, row_key, column, column_key)                                              \
	(KBD_KEY_ROW_CMP(row, row_key) && KBD_KEY_COLUMN_CMP(column, column_key))

/* Per-combo descriptor */
struct combo_desc {
	uint8_t row_a, col_a;
	uint8_t row_b, col_b;
	const char *name;
};

static const struct combo_desc combo_descs[COMBO_NUM] = {
	[COMBO_PAIRING] = {COMBO_HOME_ROW, COMBO_HOME_COL, COMBO_BACK_ROW, COMBO_BACK_COL,
			   "HOME+BACK"},
	[COMBO_DEL_BOND] = {COMBO_OK_ROW, COMBO_OK_COL, COMBO_VOLU_ROW, COMBO_VOLU_COL, "OK+VOLU"},
};

/* Per-key press state indexed by combo ID and key slot. */
static bool combo_key_state[COMBO_NUM][COMBO_KEY_COUNT];

/* One work item per combo so the action runs outside the input callback. */
static struct k_work_delayable combo_works[COMBO_NUM];
static bool combo_active[COMBO_NUM];

static rc_input_led_restore_cb_t led_restore_cb;

static void combo_action_exec(enum combo_id id)
{
	LOG_INF("Combo %s fired", combo_descs[id].name);
	rc_hogp_send_release_all();

	switch (id) {
	case COMBO_PAIRING:
		LOG_INF("Entering pairing mode until cold boot");
		rc_gap_set_force_pairing();
		return;
	case COMBO_DEL_BOND:
		rc_gap_remove_all_bond();
		break;
	default:
		break;
	}

	rc_led_set(RC_LED_OFF);
	k_sleep(K_MSEC(1000));
	sys_reboot(SYS_REBOOT_COLD);
}

/* Each combo has its own handler to avoid shared-variable race on cancel. */
static void combo_pairing_handler(struct k_work *work)
{
	combo_active[COMBO_PAIRING] = false;
	combo_action_exec(COMBO_PAIRING);
}

static void combo_del_bond_handler(struct k_work *work)
{
	combo_active[COMBO_DEL_BOND] = false;
	combo_action_exec(COMBO_DEL_BOND);
}

static k_work_handler_t const combo_handlers[COMBO_NUM] = {
	[COMBO_PAIRING] = combo_pairing_handler,
	[COMBO_DEL_BOND] = combo_del_bond_handler,
};

/* Returns true when at least one combo is currently active (both keys pressed),
 * meaning the caller should suppress normal HID processing for this key event.
 * A single combo key pressed alone is NOT suppressed — only the combination. */
static bool combo_key_update(uint32_t row, uint32_t col, bool pressed)
{
	/* Update press state for every key that belongs to any combo */
	bool relevant = false;

	for (int i = 0; i < COMBO_NUM; i++) {
		const struct combo_desc *d = &combo_descs[i];

		if (KBD_KEY_CMP(row, d->row_a, col, d->col_a)) {
			combo_key_state[i][COMBO_KEY_A] = pressed;
			relevant = true;
		} else if (KBD_KEY_CMP(row, d->row_b, col, d->col_b)) {
			combo_key_state[i][COMBO_KEY_B] = pressed;
			relevant = true;
		}
	}

	if (!relevant) {
		return false;
	}

	/* Activate / cancel each combo independently */
	bool any_active = false;

	for (int i = 0; i < COMBO_NUM; i++) {
		bool both = combo_key_state[i][COMBO_KEY_A] && combo_key_state[i][COMBO_KEY_B];

		if (!combo_active[i] && both) {
			combo_active[i] = true;
			LOG_INF("Combo detected: %s", combo_descs[i].name);
			k_work_reschedule(&combo_works[i], K_NO_WAIT);
		}

		if (combo_active[i]) {
			any_active = true;
		}
	}

	if (any_active) {
		rc_led_set(RC_LED_ON);
	} else if (led_restore_cb) {
		led_restore_cb();
	} else {
		rc_led_set(RC_LED_OFF);
	}

	/* Suppress HID once a combo is detected. */
	return any_active;
}

static void handle_key_hid_ready(uint32_t row, uint32_t col, bool pressed, int state)
{
	uint16_t csm = rc_vkey_get_consumer_code(row, col);

	if (!csm) {
		rc_hogp_send_key_report(row, col, pressed);
		return;
	}

	rc_hogp_send_consumer_report(pressed ? csm : 0);

#ifdef CONFIG_RC_VOICE
	if (csm == HID_CSM_MIC) {
		if (pressed && state == MMI_S_HID_READY) {
			rc_audio_start_search();
		} else if (!pressed && state == MMI_S_STREAMING) {
			rc_audio_stop_search();
		}
		return;
	}
	if (pressed && csm == HID_CSM_OK) {
		rc_audio_dpad_select();
	}
#endif /* CONFIG_RC_VOICE */
}

void rc_input_handle_key(uint32_t row, uint32_t col, bool pressed)
{
#ifdef CONFIG_IR_NEC
	/* IR is independent of BLE state — send/stop on any key event. */
	uint16_t ir_addr;
	uint8_t ir_cmd;

	if (rc_vkey_get_ir_code(row, col, &ir_addr, &ir_cmd)) {
		pressed ? rc_ir_send(ir_addr, ir_cmd) : rc_ir_stop();
	}
#endif

	/* Combo key detection (pairing / delete bond) — works in all states.
	 * combo_key_update() returns true if this key belongs to an active combo;
	 * in that case suppress the normal HID path so the host never sees
	 * the individual key events while the combo is being held. */
	if (combo_key_update(row, col, pressed)) {
		return;
	}

#if defined(CONFIG_PM) && !defined(CONFIG_APP_BATT)
	if (pressed) {
		pm_policy_state_lock_get(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	} else {
		if (pm_policy_state_lock_is_active(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES)) {
			pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
		}
	}
#endif

	int state = rc_mmi_get_state();

#ifdef CONFIG_RC_PDM_DEBUG
	/* Debug: row0/col1 toggles PDM streaming, bypassing ATVV/BLE.
	 * Intercept in all states except DISCONNING to avoid conflict. */
	if (row == 0 && col == 1 && state != MMI_S_DISCONNING) {
		if (pressed) {
			if (state != MMI_S_STREAMING) {
				LOG_INF("DBG: start PDM streaming (from state %d)", state);
				rc_mmi_run_event(MMI_OP_OPEN_MIC);
			} else {
				LOG_INF("DBG: stop PDM streaming");
				rc_mmi_run_event(MMI_OP_CLOSE_MIC);
			}
		}
		return;
	}
#endif

	if (state == MMI_S_IDLE) {
		rc_gap_discoverable(true);
	}

	if (state < MMI_S_HID_READY) {
		uint16_t csm = rc_vkey_get_consumer_code(row, col);

		if (csm == HID_CSM_MIC) {
			return;
		}
		if (keybuf_offset < KEY_BUF_SIZE) {
			keybuf[keybuf_offset].row = (uint8_t)row;
			keybuf[keybuf_offset].col = (uint8_t)col;
			keybuf[keybuf_offset].pressed = pressed;
			keybuf_offset++;
		} else {
			LOG_DBG("keybuf overflow");
		}
		return;
	}

	handle_key_hid_ready(row, col, pressed, state);
}

void rc_input_flush_keybuf(void)
{
	if (!state_reconnected) {
		keybuf_offset = 0;
		return;
	}

	for (uint8_t i = 0; i < keybuf_offset; i++) {
		uint32_t r = keybuf[i].row;
		uint32_t c = keybuf[i].col;
		bool pressed = keybuf[i].pressed;
		uint16_t csm = rc_vkey_get_consumer_code(r, c);

		if (csm) {
			rc_hogp_send_consumer_report(pressed ? csm : 0);
		} else {
			rc_hogp_send_key_report(r, c, pressed);
		}
	}
	state_reconnected = false;
	keybuf_offset = 0;
}

bool rc_input_keybuf_pending(void)
{
	return keybuf_offset > 0;
}

void rc_input_set_reconnected(bool reconnected)
{
	state_reconnected = reconnected;
}

static void input_callback(struct input_event *evt, void *user_data)
{
	static uint32_t row, col;

	switch (evt->code) {
	case INPUT_ABS_X:
		col = evt->value;
		break;
	case INPUT_ABS_Y:
		row = evt->value;
		break;
	case INPUT_BTN_TOUCH:
		if (evt->sync) {
			rc_input_handle_key(row, col, (bool)evt->value);
		}
		break;
	}
}

INPUT_CALLBACK_DEFINE(DEVICE_DT_GET(INPUT_KBD_MATRIX_NODE), input_callback, NULL);

void rc_input_init(rc_input_led_restore_cb_t cb)
{
	led_restore_cb = cb;
	for (int i = 0; i < COMBO_NUM; i++) {
		k_work_init_delayable(&combo_works[i], combo_handlers[i]);
	}
}
