/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <stdint.h>
#include <zephyr/autoconf.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Decode and emit local (initiator) mode-2 IQ records for one procedure.
 *
 * Walks the raw HCI subevent step buffer using bt_le_cs_step_data_parse(),
 * decodes per-tone phase correction terms via bt_le_cs_parse_pct(), resolves
 * antenna paths via bt_le_cs_get_antenna_path(), and emits one DIQI line per
 * (mode-2 step, antenna path) tone. The step/channel/mode table is cached for
 * the subsequent peer-side walk.
 *
 * @param proc_counter Procedure counter for this snapshot.
 * @param n_ap         Number of antenna paths from the subevent header.
 * @param step_data    Pointer to the accumulated raw HCI step buffer.
 * @param len          Length of @p step_data in bytes.
 */
void cs_distance_dump_init(uint32_t proc_counter, uint8_t n_ap, const uint8_t *step_data,
			   uint16_t len);

/**
 * @brief Decode and emit peer (reflector) mode-2 IQ records for one procedure.
 *
 * Walks the RAS ranging-data step buffer (after the ranging header has been
 * stripped by bt_ras_client_ranging_data_parse()), iterating subevents and
 * their fixed-length step bodies. Mode-2 tones are decoded and emitted as DIQR
 * lines using the channel cached by the matching cs_distance_dump_init() call.
 *
 * @param proc_counter Procedure counter for this snapshot.
 * @param n_ap         Number of antenna paths from the subevent header.
 * @param step_data    Pointer to the peer step buffer (subevents back-to-back).
 * @param len          Length of @p step_data in bytes.
 */
void cs_distance_dump_peer(uint32_t proc_counter, uint8_t n_ap, const uint8_t *step_data,
			   uint16_t len);

#ifdef __cplusplus
}
#endif
