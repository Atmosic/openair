/**
 *******************************************************************************
 *
 * @file fp_fmdn_gatt.h
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) extention
 * Gatt Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include "compiler.h" // __NONNULL_ALL inline functions
#include "fp_common.h"

/**
 * @addtogroup ATM_BTFMDN Google Fast Pair Find My Device Network Extention
 * @brief Gatt Middleware of Google Fast Pair Find My Device Network
 * Extention
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/// Handle the read operation on the Beacon Actions characteristic
ssize_t fp_fmdn_bcna_read(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf,
			  uint16_t len, uint16_t offset);

/// Handle the write operation on the Beacon Actions characteristic
ssize_t fp_fmdn_bcna_write(struct bt_conn *conn, const struct bt_gatt_attr *attr, const void *buf,
			   uint16_t len, uint16_t offset, uint8_t flags);

/// Handle the write operation on the CCC descriptor of the Beacon Actions characteristic.
void fp_fmdn_bcna_ccc_cfg_changed(const struct bt_gatt_attr *attr, uint16_t value);

/// Fast Pair Beacon Actions Characteristic UUID value (used in the FMDN extension)
#define FP_FMDN_UUID_BEACON_ACTIONS_VAL                                                            \
	BT_UUID_128_ENCODE(0xFE2C1238, 0x8366, 0x4814, 0x8EB0, 0x01DE32100BEA)

/// Fast Pair Beacon Actions Characteristic UUID (used in the FMDN extension)
#define FP_FMDN_UUID_BEACON_ACTIONS BT_UUID_DECLARE_128(FP_FMDN_UUID_BEACON_ACTIONS_VAL)

/// Beacon Actions GATT Characteristic definition for the Fast Pair service
#define FP_FMDN_BEACON_ACTIONS_CHARACTERISTIC                                                      \
	BT_GATT_CHARACTERISTIC(FP_FMDN_UUID_BEACON_ACTIONS,                                        \
			       BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE | BT_GATT_CHRC_NOTIFY,       \
			       BT_GATT_PERM_READ | BT_GATT_PERM_WRITE, fp_fmdn_bcna_read,          \
			       fp_fmdn_bcna_write, NULL),                                          \
		BT_GATT_CCC(fp_fmdn_bcna_ccc_cfg_changed, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE)

/**
 * @brief The callback function of utp mode notify
 * @param[in] mode fast paring itp mode
 */
typedef void (*fp_fmdn_utp_mode_cb)(fp_fmdn_utp_mode_t mode);

/**
 * @brief fmdn utp mode handler register
 * @param[in] hdlr utp mode handler structure
 */
__NONNULL_ALL
void fp_fmdn_gatt_utp_mode_reg(fp_fmdn_utp_mode_cb const hdlr);

/**
 * @brief The callback function of ring action
 * @param[in] action enable/disable ring action
 */
typedef void (*fp_fmdn_ring_action_cb)(bool action);

/**
 * @brief fmdn ring action handler register
 * @param[in] hdlr ring action handler structure
 */
__NONNULL_ALL
void fp_fmdn_gatt_ring_action_reg(fp_fmdn_ring_action_cb const hdlr);

#ifdef CONFIG_FAST_PAIR_FMDN_DULT
/**
 * @brief The callback function of fmdn update id handler register
 */
typedef void (*fp_fmdn_update_id_cb)(uint8_t *id, uint8_t id_len);

/**
 * @brief fmdn update id handler register
 * @param[in] hdlr update id handler structure
 */
__NONNULL_ALL
void fp_fmdn_gatt_update_id_reg(fp_fmdn_update_id_cb const hdlr);

/**
 * @brief The callback function of fmdn utp owner connected handler register
 */
typedef void (*fp_fmdn_utp_owner_conn_cb)(bool connected);

/**
 * @brief fmdn utp owner connected handler register
 * @param[in] hdlr utp owner connected handler structure
 */
__NONNULL_ALL
void fp_fmdn_gatt_utp_owner_conn_reg(fp_fmdn_utp_owner_conn_cb const hdlr);

#endif // CONFIG_FAST_PAIR_FMDN_DULT

/**
 * @brief fmdn gatt init
 * @param[in] attr fmdn bt_gatt_attr pointer
 */
__NONNULL_ALL
void fp_fmdn_gatt_init(struct bt_gatt_attr *attr);

/**
 * @brief fmdn gatt deinit
 */
void fp_fmdn_gatt_deinit(void);

/**
 * @brief fmdn gatt button notify
 */
void fp_fmdn_button_notify(void);

#ifdef __cplusplus
}
#endif

///@}
