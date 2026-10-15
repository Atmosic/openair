/**
 *******************************************************************************
 *
 * @file esls_test_internal.h
 *
 * @brief Atmosic eletronic shelf label service
 *
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#pragma once

#ifdef CONFIG_ZTEST

/** @brief Test accessor: returns esls_is_configured_char() */
bool esls_test_is_configured_char(void);

/** @brief Test accessor: sets the internal esls.config_flag to @p flag */
void esls_test_set_config_flag(uint8_t flag);

/** @brief Test accessor: returns ESLS_FLAG_ALL_SET as seen by esls.c */
uint8_t esls_test_get_all_flags(void);

#if CONFIG_BT_ESLS_LED_NUM > 0
/** @brief Test accessor: wraps esls_find_msb_set() */
unsigned int esls_test_find_msb_set(uint64_t data, unsigned int bit_size);
#endif /* CONFIG_BT_ESLS_LED_NUM > 0 */

/**
 * @brief Test accessor: wraps esls_cmd_parser().
 *
 * @p rsp_data_out must point to a buffer of at least 48 bytes.
 * @p rsp_len_out  receives the filled response length.
 *
 * @return true  if a response should be sent, false otherwise.
 */
bool esls_test_cmd_parser(const uint8_t *cmd, uint16_t len, bool is_pawr, uint8_t *rsp_data_out,
			  uint8_t *rsp_len_out);

/**
 * @brief Test accessor: wraps esls_prepare_rsp_buf().
 *
 * Sets up a TLV with @p opcode and calls the internal formatter.
 * @p rsp_data_out must point to a buffer of at least 48 bytes.
 */
void esls_test_prepare_rsp_buf(uint8_t opcode, uint8_t *rsp_data_out, uint8_t *rsp_len_out);

/** @brief Test accessor: sets esls.esl_addr */
void esls_test_set_esl_addr(uint16_t addr);

/** @brief Test accessor: returns esls.basic_state */
uint16_t esls_test_get_basic_state(void);

/** @brief Test accessor: sets esls.basic_state */
void esls_test_set_basic_state(uint16_t state);

/** @brief Test accessor: sets SMF current state to @p state without running entry callbacks */
void esls_test_set_smf_state(enum esls_state state);

/** @brief Test accessor: clears SMF current state (sets to NULL) */
void esls_test_clear_smf_state(void);

/** @brief Test accessor: returns esls_get_abs_time() */
uint32_t esls_test_get_abs_time(void);

/** @brief Test accessor: calls esls_update_abs_time_anchor(@p abs_time) */
void esls_test_update_abs_time_anchor(uint32_t abs_time);

/** @brief Test accessor: returns esls.curr_conn */
struct bt_conn *esls_test_get_curr_conn(void);

/** @brief Test accessor: returns esls.config_flag */
uint8_t esls_test_get_config_flag(void);

/** @brief Test accessor: returns esls.is_boned */
bool esls_test_get_is_boned(void);

/** @brief Test accessor: sets esls.is_boned */
void esls_test_set_is_boned(bool boned);

/** @brief Returns the fake per-adv-sync sentinel used by trigger_synced/recv. */
struct bt_le_per_adv_sync *esls_test_get_fake_sync(void);

/**
 * @brief Calls esls_synced() with the fake sync handle.
 *
 * Sets esls.pawr_sync and dispatches ESLS_EVT_PAST_SYNCED.
 * Must be called while in CONFIGURING state (after CONN_CB_CONNECTED +
 * CONN_CB_SECURITY_CHANGED) to transition into SYNCHRONIZED.
 */
void esls_test_trigger_synced(void);

/** @brief Calls esls_term() on the current pawr_sync — covers PA_SYNC_TERM. */
void esls_test_trigger_term(void);

/**
 * @brief Unified esls_recv() trigger.
 *
 * Calls esls_recv() with the given @p sync handle and optional payload.
 * Pass NULL @p data (or @p len == 0) for an empty buffer.
 * Pass non-NULL @p data with @p len > 0 to fill the buffer before dispatch.
 *
 * Typical usage:
 *   esls_test_trigger_recv(esls_test_get_fake_sync(), NULL, 0);       // empty buf
 *   esls_test_trigger_recv(WRONG_SYNC, NULL, 0);                      // wrong handle
 *   esls_test_trigger_recv(esls_test_get_fake_sync(), data, len);     // data buf
 */
void esls_test_trigger_recv(struct bt_le_per_adv_sync *sync, const uint8_t *data, uint16_t len);

/** @brief Calls pairing_complete(esls.curr_conn, @p bonded) */
void esls_test_call_pairing_complete(bool bonded);

/** @brief Calls bond_deleted(BT_ID_DEFAULT, BT_ADDR_LE_ANY) */
void esls_test_call_bond_deleted(void);

/** @brief Calls esls_adv_sent_cb(esls.adv_set, dummy_info) */
void esls_test_call_adv_sent_cb(void);

/** @brief Calls esls_timer_expire() — fires ESLS_EVT_STATE_TIMEOUT */
void esls_test_trigger_timer_expire(void);

/** @brief Calls esls_found_bond() with a dummy bond record. */
void esls_test_call_found_bond(void);

#ifdef CONFIG_PSA_WANT_ALG_CCM
/**
 * @brief Calls esls_encrypt() with a zeroed response buffer.
 *
 * Exercises the PSA AEAD encrypt path (success or graceful failure).
 */
int esls_test_call_encrypt(void);

#endif /* CONFIG_PSA_WANT_ALG_CCM */

/* ── Direct-coverage helpers: state-machine bypass ──────────────────────── */

/** @brief Test accessor: sets esls.pawr_sync to @p sync */
void esls_test_set_pawr_sync(struct bt_le_per_adv_sync *sync);

/** @brief Test accessor: calls esls_notify_cmp_cb(NULL, NULL) directly */
void esls_test_call_notify_cmp_cb(void);

/** @brief Test accessor: fires @p evt in the current SMF state */
void esls_test_run_evt(enum esls_evt evt);

/* ── Decrypt bypass + large-buffer recv ─────────────────────────────────── */

/**
 * @brief Inject pre-computed plaintext so the CONFIG_ZTEST hook inside
 *        esls_recv() skips real crypto and treats decryption as successful.
 *
 * Call before esls_test_trigger_recv().  @p data must remain valid
 * until esls_test_clear_decrypt_bypass() is called.
 */
void esls_test_set_decrypt_bypass(const uint8_t *data, uint8_t len);

/** @brief Remove the decrypt bypass — restores normal crypto behaviour. */
void esls_test_clear_decrypt_bypass(void);

/**
 * @brief Calls esls_cp_ccc_changed(NULL, 0) directly.
 *
 * The GATT write path does not invoke the CCC changed callback in the
 * simulated-connection test environment.  Covers lines 1537, 1539, 1540.
 */
void esls_test_call_cp_ccc_changed(void);

/**
 * @brief Atomically sets esls.pawr_sync to a non-NULL sentinel and calls
 *        esls_stop_pawr_sync() — covers the function body (lines 562, 569).
 */
void esls_test_force_stop_pawr_sync(void);

#if defined(CONFIG_AUTO_TEST) || !defined(CONFIG_PM)
/** @brief Calls test_end_check() — covers its function body */
bool test_end_check(void);
#endif

/* ── LED helpers ─────────────────────────────────────────────────────────── */
#if CONFIG_BT_ESLS_LED_NUM > 0
/** @brief Set the LED control callback (replaces bt_esls_init path). */
void esls_test_set_led_control_cb(int (*fn)(uint8_t led_idx, bool on_off,
					    uint8_t color_brightness));
/** @brief Configure a LED work item directly (bypasses bt_esls_init). */
void esls_test_set_led_work(uint8_t idx, uint8_t led_idx, uint16_t repeat_dur_info,
			    const uint8_t pattern7[7], bool led_active, uint8_t pattern_start_idx,
			    uint32_t repeat_stop_abs_time);
/** @brief Run the LED handler synchronously for the given LED index. */
void esls_test_run_led_handler(uint8_t idx);
/** @brief Return the led_active field for the given LED work item. */
bool esls_test_get_led_active(uint8_t idx);
#endif /* CONFIG_BT_ESLS_LED_NUM > 0 */

/* ── Image/OTS helpers ───────────────────────────────────────────────────── */
#if CONFIG_BT_ESLS_IMAGE_NUM > 0
/** @brief Set image callbacks (replaces bt_esls_init path). */
void esls_test_set_image_cbs(int (*write_fn)(uint8_t idx, uint8_t *data, uint16_t len),
			     int (*read_fn)(uint8_t idx, uint8_t *buf, uint16_t offset,
					    uint16_t len),
			     int (*size_fn)(uint8_t idx, uint16_t *size),
			     int (*name_fn)(uint8_t idx, char **name), int (*del_fn)(void));
/** @brief Call esls_obj_write() directly (ots/conn unused → NULL safe). */
ssize_t esls_test_call_obj_write(uint64_t id, const void *data, size_t len, off_t offset,
				 size_t rem);
#endif /* CONFIG_BT_ESLS_IMAGE_NUM > 0 */

#endif /* CONFIG_ZTEST */
