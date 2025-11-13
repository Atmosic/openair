/**
 *******************************************************************************
 *
 * @file fp_fhpf_gatt.h
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN)
 *        Find Hub Precision Finding (FHPF) header
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#ifndef FP_FHPF_GATT_H_
#define FP_FHPF_GATT_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_FMDN_PRECISION_FINDING
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include "ranging_oob_de.h"

/**
 * @brief Callback for ranging capability events
 * @param id Technology ID
 * @param capability Capability structure
 * @return 0 on success, negative on error
 */
typedef int (*fp_fmdn_ranging_capability_cb)(rt_id_t id, void *capability);

/**
 * @brief Callback for ranging configuration events
 * @param id Technology ID
 * @param config Configuration data
 * @param start_immediately Whether to start immediately
 * @return 0 on success, negative on error
 */
typedef int (*fp_fmdn_ranging_config_cb)(rt_id_t id, void *config, bool start_immediately);

/**
 * @brief Callback for ranging start events
 * @param id Technology ID
 * @return 0 on success, negative on error
 */
typedef int (*fp_fmdn_ranging_start_cb)(rt_id_t id);

/**
 * @brief Callback for ranging stop events
 * @param id Technology ID
 * @return 0 on success, negative on error
 */
typedef int (*fp_fmdn_ranging_stop_cb)(rt_id_t id);

/**
 * @brief FMDN ranging callback handler structure
 * Contains callbacks for ranging operations. NULL callbacks are ignored.
 */
typedef struct {
	fp_fmdn_ranging_capability_cb capability_cb; ///< Capability events
	fp_fmdn_ranging_config_cb config_cb;         ///< Configuration events
	fp_fmdn_ranging_start_cb start_cb;           ///< Start events
	fp_fmdn_ranging_stop_cb stop_cb;             ///< Stop events
} fp_fmdn_ranging_handler_t;

#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
/**
 * @brief Check if connection meets ranging security requirements
 *
 * @param conn Bluetooth connection
 * @return true if secure enough for ranging, false otherwise
 */
bool fp_fhpf_gatt_is_ranging_connection_secure(struct bt_conn *conn);

/**
 * @brief CS procedure enabled callback
 *
 * @param conn Bluetooth connection
 * @param status HCI status
 * @param params CS procedure enable complete parameters
 */
void fp_fhpf_gatt_cs_procedure_enabled_cb(struct bt_conn *conn, uint8_t status,
					  struct bt_conn_le_cs_procedure_enable_complete *params);

/**
 * @brief CS config created callback
 *
 * @param conn Bluetooth connection
 * @param status HCI status
 * @param config CS configuration
 */
void fp_fhpf_gatt_cs_config_created_cb(struct bt_conn *conn, uint8_t status,
				       struct bt_conn_le_cs_config *config);
#endif /* CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN */

/**
 * @brief Register ranging handler callbacks
 *
 * @param handler Pointer to ranging handler structure
 */
void fp_fhpf_gatt_ranging_handler_register(fp_fmdn_ranging_handler_t const *handler);

/**
 * @brief Handle ranging capability request
 *
 * @param conn Bluetooth connection
 * @param req BCNA request structure
 * @param resp_len Response length
 * @return 0 on success, negative error code on failure
 */
size_t fp_fhpf_gatt_bcna_ranging_cap_handle(const struct bt_conn *conn, uint8_t *addition_data,
					    uint8_t add_data_len, uint16_t *resp_len);

/**
 * @brief Handle ranging configuration request
 *
 * @param conn Bluetooth connection
 * @param req BCNA request structure
 * @param resp_len Response length
 * @return 0 on success, negative error code on failure
 */
size_t fp_fhpf_gatt_bcna_ranging_conf_handle(struct bt_conn *conn, uint8_t *addition_data,
					     uint8_t add_data_len, uint16_t *resp_len);

/**
 * @brief Handle ranging start request
 *
 * @param conn Bluetooth connection
 * @param req BCNA request structure
 * @param resp_len Response length
 * @return 0 on success, negative error code on failure
 */
size_t fp_fhpf_gatt_bcna_ranging_start_handle(struct bt_conn *conn, uint8_t *addition_data,
					      uint8_t add_data_len, uint16_t *resp_len);

/**
 * @brief Handle ranging stop request
 *
 * @param conn Bluetooth connection
 * @param req BCNA request structure
 * @param resp_len Response length
 * @return 0 on success, negative error code on failure
 */
size_t fp_fhpf_gatt_bcna_ranging_stop_handle(struct bt_conn *conn, uint8_t *addition_data,
					     uint8_t add_data_len, uint16_t *resp_len);

/**
 * @brief Handle connection events for precision finding
 *
 * @param conn Bluetooth connection
 * @param connected true if connected, false if disconnected
 */
void fp_fhpf_gatt_conn_event(struct bt_conn *conn, bool connected);

/**
 * @brief Handle security change events for precision finding
 *
 * @param conn Bluetooth connection
 * @param level Security level
 * @param err Security error
 */
void fp_fhpf_gatt_security_changed(struct bt_conn *conn, bt_security_t level,
				   enum bt_security_err err);

#endif /* CONFIG_FMDN_PRECISION_FINDING */

#ifdef __cplusplus
}
#endif

#endif /* FP_FHPF_GATT_H_ */
