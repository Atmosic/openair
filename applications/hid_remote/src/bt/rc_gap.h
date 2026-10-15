/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>

/**
 * @file rc_gap.h
 * @brief RC application GAP module.
 */

/** @brief Initialise Bluetooth and register GAP callbacks. */
void rc_gap_init(void);

/** @brief Start or stop discoverable advertising.
 * @param enable True to start advertising, false to stop.
 */
void rc_gap_discoverable(bool enable);

/** @brief Disconnect the current BLE link. */
void rc_gap_disconnect(void);

/** @brief Remove all bond slots and start fresh pairing. */
void rc_gap_remove_all_bond(void);

/** @brief Force undirected pairing advertising until the next cold boot. */
void rc_gap_set_force_pairing(void);

/** @brief Remove the current bond slot and reboot for fresh pairing. */
void rc_gap_remove_current_bond(void);

/** @brief Store the current BT identity index to SETTINGS.
 *  @param bt_id Identity index to store.
 *  @return 0 on success, non-zero on failure.
 */
int rc_gap_settings_store_bt_id(uint32_t bt_id);

/** @brief Update BLE connection parameters.
 *
 *  Sends an LL_CONNECTION_PARAM_REQ to the central.
 *  @param low_latency  true  → latency=0, fast interval (audio / time-critical)
 *                      false → latency=99, interval=10 ms (power-save after HID ready)
 */
void rc_gap_param_update(bool low_latency);
