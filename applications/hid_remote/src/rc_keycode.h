/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <zephyr/usb/class/hid.h>

/*
 *   - HID_KEY_*  : USB HID Keyboard usage page (0x07)
 *   - HID_CSM_*  : USB HID Consumer Control usage page (0x0C)
 *   - IR_*       : NEC IR address and command codes (ATMRC_3330e_HSC)
 */

/* ── Keyboard usage IDs not defined in <zephyr/usb/class/hid.h> ─────────── */

#define HID_KEY_NONE       0x00
#define HID_KEY_MUTE       0x7F
#define HID_KEY_VOLUMEUP   0x80
#define HID_KEY_VOLUMEDOWN 0x81

/* Modifier keycodes (usage page 0x07, range 0xe0–0xe7) */
#define HID_KEY_LEFTCTRL   0xe0
#define HID_KEY_LEFTSHIFT  0xe1
#define HID_KEY_LEFTALT    0xe2
#define HID_KEY_LEFTMETA   0xe3
#define HID_KEY_RIGHTCTRL  0xe4
#define HID_KEY_RIGHTSHIFT 0xe5
#define HID_KEY_RIGHTALT   0xe6
#define HID_KEY_RIGHTMETA  0xe7

/* ── HID Consumer Control usage IDs (Usage Page 0x0C) ───────────────────── */

#define HID_CSM_POWER      0x0030
#define HID_CSM_PLAY_PAUSE 0x00CD
#define HID_CSM_BW         0x00B6 /* Scan Previous Track  — BT_BW   */
#define HID_CSM_FW         0x00B5 /* Scan Next Track      — BT_FW   */
#define HID_CSM_MUTE       0x00E2 /*                      — BT_MUTE */
#define HID_CSM_VOLUMEUP   0x00E9 /*                      — BT_VOLU */
#define HID_CSM_VOLUMEDOWN 0x00EA /*                      — BT_VOLD */
#define HID_CSM_MIC        0x0221 /* AC Search            — BT_MIC / BT_ASST */
#define HID_CSM_HOME       0x0223 /*                      — BT_HOME */
#define HID_CSM_BACK       0x0224 /*                      — BT_BACK */
#define HID_CSM_INPUT      0x01BB /* AC Select Input      — BT_INPUT */
#define HID_CSM_OK         0x0041 /*                      — BT_OK / BT_CENTER */
#define HID_CSM_UP         0x0042 /*                      — BT_UP   */
#define HID_CSM_DOWN       0x0043 /*                      — BT_DOWN */
#define HID_CSM_LEFT       0x0044 /*                      — BT_LEFT */
#define HID_CSM_RIGHT      0x0045 /*                      — BT_RIGHT */
#define HID_CSM_SETT       0x0096 /* AL Consumer Ctrl Cfg — BT_SETT */
#define HID_CSM_GUIDE      0x008D /* AL Media Select Home — BT_GUIDE */
#define HID_CSM_LIVE       0x0089 /* AL Media Select TV   — BT_LIVE */
#define HID_CSM_CNLU       0x009C /* Channel Up           — BT_CNLU */
#define HID_CSM_CNLD       0x009D /* Channel Down         — BT_CNLD */
#define HID_CSM_YOUTUBE    0x0077 /*                      — BT_YOUTUBE */
#define HID_CSM_NETFLIX    0x0078 /*                      — BT_NETFLIX */
#define HID_CSM_APP03      0x0079 /*                      — BT_APP03 */
#define HID_CSM_APP04      0x007A /*                      — BT_APP04 */

/* ── HID Keyboard usage IDs (Usage Page 0x07) ───────────────────────────── */

#define HID_KEY_MENU 0x76 /* Application          — BT_MENU  */

/* ── NEC IR codes (default board, addr = 0x80) ──────────────────────────── */

#ifdef CONFIG_IR_NEC
#define IR_ADDR  0x80
#define IR_POWER 0x46
#define IR_UP    0x52
#define IR_LEFT  0x06
#define IR_OK    0x0F
#define IR_RIGHT 0x1A
#define IR_MENU  0x07
#define IR_DOWN  0x13
#define IR_BACK  0x1B
#define IR_HOME  0x17
#define IR_VOLU  0x16
#define IR_VOLD  0x15
#endif /* CONFIG_IR_NEC */
