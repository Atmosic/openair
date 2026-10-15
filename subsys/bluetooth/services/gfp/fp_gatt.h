/**
 *******************************************************************************
 *
 * @file fp_gatt.h
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Gatt Middleware
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#pragma once

#include <zephyr/bluetooth/uuid.h>

/**
 * @addtogroup ATM_BTFMDN Google Fast Pair Service
 * @brief Gatt Middleware of Fast Pair Service
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief FP gatt init
 */
void fp_gatt_init(void);

/**
 * @brief FP gatt deinit
 */
void fp_gatt_deinit(void);

/**
 * @brief Get the loaded Model ID
 * @return Pointer to 3-byte Model ID array
 */
const uint8_t *fp_gatt_get_model_id(void);

#ifdef __cplusplus
}
#endif

#if defined(CONFIG_ZTEST)
#include <zephyr/bluetooth/conn.h>

void fp_gatt_test_disconnected(struct bt_conn *conn, uint8_t reason);
void fp_gatt_test_drop_keys(void);
void fp_gatt_test_read_model_id_pairing(void);
int fp_gatt_test_rsp_notify(void);
void fp_gatt_test_enable_account_key_write(void);
void fp_gatt_test_set_session_key(const uint8_t *key);
int fp_gatt_test_action_request(uint8_t flags, uint8_t group, uint8_t code, uint8_t depend);
int fp_gatt_test_handle_kbp_request(struct bt_conn *conn, uint8_t flags);
int fp_gatt_test_kbp_req_handler(struct bt_conn *conn, uint8_t type, uint8_t flags,
				 const uint8_t prov_addr[BT_ADDR_SIZE]);
bool fp_gatt_test_kbp_process(struct bt_conn *conn);
int fp_gatt_test_notify_device_name(struct bt_conn *conn);
void fp_gatt_test_kbp_work_null_conn(void);
#endif /* CONFIG_ZTEST */

///@}
