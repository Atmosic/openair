/*
 * Copyright (c) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

/**
 * @file ir_nec.h
 * @brief NEC IR blaster driver API.
 *
 * Drives an ATM PWM channel in FIFO mode to generate NEC-protocol IR frames.
 * One complete frame (address + command) is sent per @ref ir_nec_send call.
 * The driver is not re-entrant; call @ref ir_nec_busy to poll before sending.
 */

#include <stdint.h>
#include <stdbool.h>
#include <zephyr/device.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Transmit a single NEC IR frame.
 *
 * Supports both standard and extended NEC protocol:
 * - Standard NEC (@p addr <= 0xFF): 32-bit frame = addr | ~addr | cmd | ~cmd
 * - Extended NEC (@p addr > 0xFF):  32-bit frame = addr_low | addr_high | cmd | ~cmd
 *
 * @param dev     IR NEC device instance.
 * @param addr    Device address: 8-bit for standard NEC, 16-bit for extended NEC.
 * @param cmd     8-bit NEC command.
 * @param done_cb Optional callback invoked (in ISR context) when TX completes.
 *                Pass NULL if not needed.
 * @return 0 on success, -EBUSY if a transmission is already in progress,
 *         or a negative errno from the underlying PWM FIFO driver.
 */
int ir_nec_send(const struct device *dev, uint16_t addr, uint8_t cmd, void (*done_cb)(void));

/**
 * @brief Transmit a NEC IR frame followed by repeat codes until stopped.
 *
 * Sends one full NEC frame then automatically sends NEC repeat codes every
 * 110 ms until @ref ir_nec_stop is called. @p done_cb is invoked (in system
 * work-queue context) once the sequence fully stops.
 *
 * @param dev     IR NEC device instance.
 * @param addr    Device address (see @ref ir_nec_send).
 * @param cmd     8-bit NEC command.
 * @param done_cb Optional callback invoked when the sequence stops.
 * @return 0 on success, -EBUSY if already transmitting.
 */
int ir_nec_send_repeat(const struct device *dev, uint16_t addr, uint8_t cmd, void (*done_cb)(void));

/**
 * @brief Stop an ongoing repeat sequence started by @ref ir_nec_send_repeat.
 *
 * Marks the sequence for termination. @p done_cb passed to
 * @ref ir_nec_send_repeat is called once the current transmission finishes.
 * A no-op if no repeat sequence is in progress.
 *
 * @param dev IR NEC device instance.
 */
void ir_nec_stop(const struct device *dev);

/**
 * @brief Check whether a transmission is in progress.
 *
 * @param dev IR NEC device instance.
 * @return true if busy, false if idle.
 */
bool ir_nec_busy(const struct device *dev);

#ifdef __cplusplus
}
#endif
