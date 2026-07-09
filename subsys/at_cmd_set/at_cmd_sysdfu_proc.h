/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "at_cmd.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Start a serial DFU session.
 *
 * Initialises the RDP reassembler and internal state.  After this call
 * all incoming UART bytes must be routed through at_cmd_sysdfu_feed_byte()
 * until at_cmd_sysdfu_is_active() returns false.
 *
 * @param ch        AT command channel (used to send RDP ACKs back to host).
 * @param total_len Total firmware bytes the host will transfer.
 * @param crc_en    true if each RDP packet carries a trailing CRC-8 byte.
 * @return 0 on success, negative errno on failure.
 */
int at_cmd_sysdfu_proc_start(at_cmd_ch_t ch, uint32_t total_len, bool crc_en);

/**
 * @brief Returns true while a DFU binary transfer is in progress.
 *
 * The application UART driver must check this and, when true, feed every
 * received byte to at_cmd_sysdfu_feed_byte() instead of the AT parser.
 */
bool at_cmd_sysdfu_is_active(void);

/**
 * @brief Returns true once the last RDP packet has been successfully received.
 *
 * AT+SYSSWITCHBANK is only permitted after this returns true.
 */
bool at_cmd_sysdfu_switch_bank_en(void);

/**
 * @brief Feed one raw UART byte into the RDP reassembler.
 *
 * Call only when at_cmd_sysdfu_is_active() is true.
 */
void at_cmd_sysdfu_feed_byte(uint8_t byte);

#ifdef __cplusplus
}
#endif
