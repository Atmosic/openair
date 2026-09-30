/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/**
 * @file ras_client_test.h
 * @brief Test accessor interface for ras_client.c and shell/ras_client.c.
 *
 * Only compiled when CONFIG_ZTEST=y.  Provides wrappers around static
 * functions and internal state so unit tests can exercise all code paths
 * without a live BT stack.
 */

#pragma once

#ifdef CONFIG_ZTEST

#include <stdint.h>
#include <stdbool.h>
#include <zephyr/kernel.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/cs.h>
#include <zephyr/net_buf.h>
#include "ras.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ── ras_client.c test accessors ─────────────────────────────────────────── */

/** @brief Map a RAS_CP_RSP_* response code to a negative errno value. */
int ras_test_rsp_code_to_err(uint8_t rsp_code);

/**
 * @brief Return the RAS_CHARC_* index for @p uuid, or RAS_CHARC_MAX_NUM if
 *        the UUID is not a known RAS characteristic UUID.
 */
uint8_t ras_test_get_handle_idx(const struct bt_uuid *uuid);

/* RAS_CHARC_* index values for ras_test_set_char_prop /
 * ras_test_get_subscribe_params (must match enum ras_char in ras_client.c). */
#define RAS_TEST_CHARC_RAS_FEATURES             0
#define RAS_TEST_CHARC_REALTIME_RANGING_DATA    1
#define RAS_TEST_CHARC_ONDEMAND_RANGING_DATA    2
#define RAS_TEST_CHARC_CP                       3
#define RAS_TEST_CHARC_RANGING_DATA_READY       4
#define RAS_TEST_CHARC_RANGING_DATA_OVERWRITTEN 5
#define RAS_TEST_CHARC_MAX_NUM                  6

/* ras_c_state numeric values for ras_test_init_fake_ras_c()
 * (must match enum ras_c_state in ras_client.c). */
#define RAS_TEST_STATE_NONE               0
#define RAS_TEST_STATE_DISCOVERY          1
#define RAS_TEST_STATE_READ_FEATURES_DONE 2
#define RAS_TEST_STATE_ON_DEMAND_MODE     3
#define RAS_TEST_STATE_GET_RANGING_DATA   4
#define RAS_TEST_STATE_REALTIME_MODE      5

/** @brief Initialise ras_c_list[0] with @p conn and @p state. */
void ras_test_init_fake_ras_c(struct bt_conn *conn, int state);

/** @brief Zero ras_c_list[0] to reset between tests. */
void ras_test_teardown_fake_ras_c(void);

/** @brief Direct access to ras_c_list[0] so tests can read/write fields. */
void *ras_test_get_fake_ras_c(void);

/** @brief Invoke ras_c_ondemand_rd_notify() directly. */
uint8_t ras_test_ondemand_rd_notify(struct bt_conn *conn, struct bt_gatt_subscribe_params *params,
				    const void *data, uint16_t length);

/** @brief Invoke ras_c_realtime_rd_notify() directly. */
uint8_t ras_test_realtime_rd_notify(struct bt_conn *conn, struct bt_gatt_subscribe_params *params,
				    const void *data, uint16_t length);

/** @brief Invoke ras_c_rd_ready_ow_notify() directly. */
uint8_t ras_test_rd_ready_ow_notify(struct bt_conn *conn, struct bt_gatt_subscribe_params *params,
				    const void *data, uint16_t length);

/** @brief Invoke ras_c_cp_notify() directly. */
uint8_t ras_test_cp_notify(struct bt_conn *conn, struct bt_gatt_subscribe_params *params,
			   const void *data, uint16_t length);

/** @brief Invoke ras_c_check_indicate() via ras_c_list[0]. */
int ras_test_check_indicate(struct bt_conn *conn, uint8_t char_idx,
			    enum bt_ras_client_subscribe_type sub_type);

/** @brief Invoke ras_c_gatt_read_cb() directly. */
uint8_t ras_test_gatt_read_cb(struct bt_conn *conn, uint8_t err, struct bt_gatt_read_params *params,
			      const void *data, uint16_t length);

/** @brief Invoke ras_c_discovery_cmpl() directly. */
void ras_test_discovery_cmpl(struct bt_conn *conn, int err);

/** @brief Invoke ras_c_disc_cb() directly. */
uint8_t ras_test_disc_cb(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			 struct bt_gatt_discover_params *params);

/** @brief Set ras_c_list[bt_conn_index(conn)].ondemand_buf_out. */
void ras_test_set_ondemand_buf(struct bt_conn *conn, struct net_buf_simple *buf);

/** @brief Set ras_c_list[...].realtime_buf_out. */
void ras_test_set_realtime_buf(struct bt_conn *conn, struct net_buf_simple *buf);

/** @brief Set ras_c_list[...].rd_ready_cb. */
void ras_test_set_rd_ready_cb(struct bt_conn *conn, bt_ras_client_ranging_data_ready_cb cb);

/** @brief Set ras_c_list[...].rd_overwritten_cb. */
void ras_test_set_rd_overwritten_cb(struct bt_conn *conn,
				    bt_ras_client_ranging_data_overwritten_cb cb);

/** @brief Set ras_c_list[...].get_rd_cmpl_cb. */
void ras_test_set_get_rd_cmpl_cb(struct bt_conn *conn, bt_ras_client_get_ranging_data_cmpl_cb cb);

/** @brief Set ras_c_list[...].char_prop[char_idx]. */
void ras_test_set_char_prop(struct bt_conn *conn, uint8_t char_idx, uint8_t prop);

/** @brief Set ras_c_list[...].next_seg_cnt. */
void ras_test_set_next_seg_cnt(struct bt_conn *conn, uint8_t cnt);

/** @brief Set ras_c_list[...].ranging_counter. */
void ras_test_set_ranging_counter(struct bt_conn *conn, uint16_t rc);

/** @brief Read ras_c_list[...].err_status. */
int ras_test_get_err_status(struct bt_conn *conn);

/** @brief Read ras_c_list[...].state. */
int ras_test_get_state(struct bt_conn *conn);

/** @brief Read ras_c_list[...].last_seg. */
bool ras_test_get_last_seg(struct bt_conn *conn);

/** @brief Read ras_c_list[...].cs_enabled. */
bool ras_test_get_cs_enabled(struct bt_conn *conn);

/** @brief Return pointer to ras_c_list[...].subscribe_params[char_idx]. */
struct bt_gatt_subscribe_params *ras_test_get_subscribe_params(struct bt_conn *conn,
							       uint8_t char_idx);

/** @brief Clear the registered client callback (set ras_c_cb to NULL). */
void ras_test_clear_cb(void);

/** @brief Override ras_features (test ENOTSUP paths). */
void ras_test_set_ras_features(struct bt_conn *conn, uint32_t features);

/** @brief Set ras_c->last_seg. */
void ras_test_set_last_seg(struct bt_conn *conn, bool last_seg);

/* ── shell/ras_client.c test accessors ───────────────────────────────────── */

/** @brief Invoke ras_discover_cb() directly. */
void ras_shell_test_discover_cb(int err);

/** @brief Invoke ras_ranging_data_overwritten_cb() directly. */
void ras_shell_test_rd_overwritten_cb(uint16_t ranging_counter);

/** @brief Invoke ras_get_ranging_data_cmpl_cb() directly. */
void ras_shell_test_get_rd_cmpl_cb(uint16_t ranging_counter, int err);

/** @brief Invoke ras_ranging_data_ready_cb() directly. */
void ras_shell_test_rd_ready_cb(struct bt_conn *conn, uint16_t ranging_counter, int err);

#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
/** @brief Invoke ras_get_realtime_ranging_data_cmpl_cb() directly. */
void ras_shell_test_realtime_cmpl_cb(int err);
#endif

#ifdef __cplusplus
}
#endif

#endif /* CONFIG_ZTEST */
