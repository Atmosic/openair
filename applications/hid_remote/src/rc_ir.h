/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <stdint.h>

/** @brief Verify the IR blaster device is ready.  Call once at boot. */
void rc_ir_init(void);

/**
 * @brief Begin transmitting NEC frames for the given address/command.
 *
 * Sends one full NEC frame then repeats every 110 ms until rc_ir_stop() is
 * called.  If the blaster is already busy the call is silently ignored.
 *
 * @param addr NEC device address (8-bit standard or 16-bit extended).
 * @param cmd  NEC command byte.
 */
void rc_ir_send(uint16_t addr, uint8_t cmd);

/** @brief Stop an ongoing NEC repeat sequence. */
void rc_ir_stop(void);
