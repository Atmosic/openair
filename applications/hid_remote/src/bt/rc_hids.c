/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include <string.h>

#include "hogp.h"
#include "rc_hids.h"
#include "rc_keycode.h"
#include "rc_vkey.h"
#include "rc_mmi.h"
#include "rc_mmi_timer.h"

LOG_MODULE_REGISTER(rc_hids, CONFIG_HID_REMOTE_LOG_LEVEL);

/*
 * Local shadow of the keyboard report state so key-press/release logic can
 * track which keys are currently held without touching hogp internals.
 */
static struct hogp_kbd_report kbd_report;

/* ── HOGP state callback ─────────────────────────────────────────────────── */

static void hogp_state_changed(hogp_state_t state)
{
	LOG_INF("HOGP state: %d", state);
	if (state == HOGP_STATE_READY) {
		rc_mmi_run_event(MMI_OP_HID_READY);
	}
}

/* ── Public API ──────────────────────────────────────────────────────────── */

void rc_hids_init(void)
{
	hogp_init(hogp_state_changed, NULL);
}

rc_hids_state_t rc_hids_get_state(void)
{
	return (rc_hids_state_t)hogp_get_state();
}

static void send_kbd_report(void)
{
	rc_mmi_timer_idle_set(CONFIG_RC_IDLE_TIMEOUT_CS);
	hogp_send_kbd_report(&kbd_report);
}

void rc_hogp_send_key_report(uint32_t row, uint32_t col, bool pressed)
{
	LOG_INF("key r%u/c%u %s", row, col, pressed ? "dn" : "up");
	uint8_t keycode = rc_vkey_get_keycode(row, col);

	if (keycode >= HID_KEY_LEFTCTRL && keycode <= HID_KEY_RIGHTMETA) {
		uint8_t mod = (uint8_t)(1U << (keycode - HID_KEY_LEFTCTRL));
		uint8_t last = kbd_report.modifier_keys;
		kbd_report.modifier_keys = pressed ? last | mod : last & ~mod;
		if (kbd_report.modifier_keys != last) {
			send_kbd_report();
		}
		return;
	}

	if (pressed) {
		for (int i = 0; i < HOGP_KEY_ARRAY_SIZE; i++) {
			if (kbd_report.keys[i] == HID_KEY_NONE) {
				kbd_report.keys[i] = keycode;
				send_kbd_report();
				return;
			} else if (kbd_report.keys[i] == keycode) {
				return; /* duplicate */
			}
		}
		return; /* rollover */
	}

	bool found = false;
	int i;

	for (i = 0; i < HOGP_KEY_ARRAY_SIZE; i++) {
		if (found) {
			if (kbd_report.keys[i - 1] != HID_KEY_NONE) {
				kbd_report.keys[i - 1] = kbd_report.keys[i];
				continue;
			}
			send_kbd_report();
			return;
		}
		if (kbd_report.keys[i] == keycode) {
			found = true;
			continue;
		}
		if (kbd_report.keys[i] == HID_KEY_NONE) {
			return;
		}
	}
	if (found) {
		kbd_report.keys[i - 1] = HID_KEY_NONE;
		send_kbd_report();
	}
}

void rc_hogp_send_consumer_report(uint16_t keycode)
{
	LOG_INF("consumer 0x%04x", keycode);
	rc_mmi_timer_idle_set(CONFIG_RC_IDLE_TIMEOUT_CS);
	hogp_send_consumer_report(keycode, 0);
}

void rc_hogp_send_release_all(void)
{
	memset(&kbd_report, 0, sizeof(kbd_report));
	hogp_send_kbd_release_all();
}
