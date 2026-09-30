/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/**
 * @file ras_test.h
 * @brief Test accessor interface for the RAS (Ranging Service) internals.
 *
 * Only compiled when CONFIG_BT_RAS_TEST=y (implies CONFIG_ZTEST=y).
 * Provides wrappers around static buffer-management and filter functions
 * so unit tests can exercise them without modifying the core logic.
 */

#pragma once

#ifdef CONFIG_BT_RAS_TEST

#include <stdint.h>
#include <stdbool.h>
#include <zephyr/kernel.h>
#include <zephyr/bluetooth/conn.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Reset all ranging-data buffers to the FREE state.
 *
 * Call this in test setup / teardown to ensure a clean slate.
 */
void ras_test_rdbuf_reset_all(void);

/**
 * @brief Allocate a buffer slot and mark it as DONE with the given
 *        ranging counter.
 *
 * Wraps ras_rdbuf_get_new() and sets status = RAS_BUF_DONE.
 *
 * @param ranging_cnt Ranging counter to assign to the buffer.
 * @return true if a free slot was found and allocated, false if all slots
 *         are occupied.
 */
bool ras_test_rdbuf_alloc(uint16_t ranging_cnt);

/**
 * @brief Check whether a buffer with the given ranging counter exists
 *        (i.e. is not FREE).
 *
 * Wraps ras_rdbuf_get_buf().
 *
 * @param ranging_cnt Ranging counter to search for.
 * @return true if found, false otherwise.
 */
bool ras_test_rdbuf_exists(uint16_t ranging_cnt);

/**
 * @brief Free the buffer identified by @p ranging_cnt.
 *
 * Wraps ras_rdbuf_free_buf().
 *
 * @param ranging_cnt Ranging counter of the buffer to release.
 * @return true if the buffer was found and freed, false if not found.
 */
bool ras_test_rdbuf_free(uint16_t ranging_cnt);

/**
 * @brief Count the number of currently FREE buffer slots.
 *
 * @return Number of free slots in [0, CONFIG_RAS_RD_BUFFER_NUM].
 */
uint8_t ras_test_rdbuf_count_free(void);

/**
 * @brief Invoke ras_rdbuf_free_one_buf() - evict the oldest non-free buffer.
 *
 * Wraps the internal eviction helper used by ras_cs_subevent_result_cb when
 * all slots are occupied and a new subevent must overwrite the oldest record.
 * Calling it when every slot is already FREE exercises the
 * LOG_ERR("No buffer can be free") error path.
 *
 * @param out_ranging_cnt Receives the evicted buffer's ranging counter on
 *                        success; unchanged when no buffer was evicted.
 * @return true  if a buffer was evicted (normal overwrite path).
 * @return false if all buffers are already FREE (error path).
 */
bool ras_test_rdbuf_free_one_buf(uint16_t *out_ranging_cnt);

/* ---- curr_conn state accessor ------------------------------------- */

/** @brief Read ras.curr_conn (for test assertions). */
struct bt_conn *ras_test_get_curr_conn(void);

/* ---- timeout work test API --------------------------------------- */

/**
 * @defgroup ras_test_timeout_evt Timeout event values for ras_test_timeout_evt_work_put
 * @{
 */
/** Schedule a WAIT_ACK timer: fires and clears the ranging buffer if the
 *  client does not acknowledge (ACK_RD) within @p delay. */
#define RAS_TEST_TIMEOUT_EVT_WAIT_ACK 0U
/** Triggers the default (unexpected-event) error branch in the handler. */
#define RAS_TEST_TIMEOUT_EVT_INVALID  1U
/** @} */

/**
 * @brief Invoke the internal ras_timeout_evt_work_put() for testing.
 *
 * Schedules the deferred timeout work with @p evt and @p rd_cnt.  The work
 * fires after @p delay unless cancelled (e.g. via ACK_RD or RD_OVRWRT).
 * Use a short delay (e.g. K_MSEC(10)) in tests so they complete quickly.
 *
 * @param evt    Timeout event; one of RAS_TEST_TIMEOUT_EVT_WAIT_ACK or
 *               RAS_TEST_TIMEOUT_EVT_INVALID.
 * @param rd_cnt Ranging counter associated with the timer.
 * @param delay  Zephyr timeout before the handler executes.
 */
void ras_test_timeout_evt_work_put(uint8_t evt, uint16_t rd_cnt, k_timeout_t delay);

/* ---- CP indication completion callback test API ------------------- */

/**
 * @brief Invoke ras_cp_ind_cmp_cb() directly for testing.
 *
 * Exercises the GATT indication completion callback that is normally triggered
 * only when bt_gatt_indicate() succeeds and the remote peer ACKs — unreachable
 * on a fake connection.
 *
 * @param conn Connection handle passed to the callback (may be NULL).
 * @param err  Indication error code (0 = success, non-zero = failure).
 */
void ras_test_cp_ind_cmp_cb(struct bt_conn *conn, uint8_t err);

/* ---- RD segment notify/indicate completion callback test APIs ------ */

/**
 * @brief Invoke ras_rd_seg_notify_cmp_cb() directly for testing.
 *
 * Called when an RD segment bt_gatt_notify_cb() transmission completes.
 * Unreachable on a fake connection (no ATT bearer).
 *
 * @param conn Connection handle (may be NULL).
 */
void ras_test_rd_seg_notify_cmp_cb(struct bt_conn *conn);

/**
 * @brief Invoke ras_rd_seg_ind_cmp_cb() directly for testing.
 *
 * Called when an RD segment bt_gatt_indicate() transmission completes.
 * Unreachable on a fake connection (no ATT bearer).
 *
 * @param conn Connection handle (may be NULL).
 * @param err  Indication error code (0 = success, non-zero = failure).
 */
void ras_test_rd_seg_ind_cmp_cb(struct bt_conn *conn, uint8_t err);

/* ---- RD status notify/indicate completion callback test APIs ------- */

/**
 * @brief Invoke ras_rd_sts_notify_cmp_cb() directly for testing.
 *
 * Called when an RD status bt_gatt_notify_cb() transmission completes.
 * Unreachable on a fake connection (no ATT bearer).
 *
 * @param conn Connection handle (may be NULL).
 */
void ras_test_rd_sts_notify_cmp_cb(struct bt_conn *conn);

/**
 * @brief Invoke ras_rd_sts_ind_cmp_cb() directly for testing.
 *
 * Called when an RD status bt_gatt_indicate() transmission completes.
 * Unreachable on a fake connection (no ATT bearer).
 *
 * @param conn Connection handle (may be NULL).
 * @param err  Indication error code (0 = success, non-zero = failure).
 */
void ras_test_rd_sts_ind_cmp_cb(struct bt_conn *conn, uint8_t err);

#ifdef CONFIG_RAS_FILTER_RD
/**
 * @brief Invoke the internal ras_filter_step_data() function.
 *
 * Uses the mask stored in ras.filter[mode] (set via SET_FILTER CP write).
 *
 * @param mode    Step mode.
 * @param dst     Output buffer.
 * @param src     Input step-data buffer.
 * @param src_len Length of @p src in bytes.
 * @return Number of bytes written to @p dst, or 0 on error.
 */
uint16_t ras_test_filter_step_data(uint8_t mode, uint8_t *dst, const uint8_t *src,
				   uint16_t src_len);
#endif /* CONFIG_RAS_FILTER_RD */

#ifdef __cplusplus
}
#endif

#endif /* CONFIG_BT_RAS_TEST */
