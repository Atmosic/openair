/**
 *******************************************************************************
 *
 * @file fp_fmdn_sba_gatt.h
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) v2
 * Secure Beacon Actions GATT Characteristic
 *
 * Copyright (C) Atmosic 2026
 *
 *******************************************************************************
 */

#pragma once

#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include "compiler.h"

/**
 * @addtogroup ATM_BTFMDN Google Fast Pair Find My Device Network v2 Extension
 * @brief Secure Beacon Actions GATT Characteristic for FHN v2
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/// Handle the read operation on the Secure Beacon Actions characteristic
ssize_t fp_fmdn_sba_read(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf,
			 uint16_t len, uint16_t offset);

/// Handle the write operation on the Secure Beacon Actions characteristic
ssize_t fp_fmdn_sba_write(struct bt_conn *conn, const struct bt_gatt_attr *attr, const void *buf,
			  uint16_t len, uint16_t offset, uint8_t flags);

/// Handle CCC descriptor changes for Secure Beacon Actions characteristic
void fp_fmdn_sba_ccc_cfg_changed(const struct bt_gatt_attr *attr, uint16_t value);

/// Secure Beacon Actions Characteristic UUID value (FHN v2)
#define FP_FMDN_UUID_SECURE_BEACON_ACTIONS_VAL                                                     \
	BT_UUID_128_ENCODE(0xFE2C1240, 0x8366, 0x4814, 0x8EB0, 0x01DE32100BEA)

/// Secure Beacon Actions Characteristic UUID (FHN v2)
#define FP_FMDN_UUID_SECURE_BEACON_ACTIONS                                                         \
	BT_UUID_DECLARE_128(FP_FMDN_UUID_SECURE_BEACON_ACTIONS_VAL)

/// Secure Beacon Actions Data IDs (FHN v2)
#ifdef CONFIG_FMDN_PERSISTENT_CONNECTION
#define SBA_DATA_ID_PERSISTENT_CONNECTION 0x10
#endif
#ifdef CONFIG_FMDN_REVERSE_RINGING
#define SBA_DATA_ID_REVERSE_RINGING_CONFIG 0x11
#define SBA_DATA_ID_REVERSE_RINGING        0x12
#endif

/// Secure Beacon Actions GATT Characteristic definition for Fast Pair service (v2)
/// Requires ACL encryption - only available when bonded
#define FP_FMDN_SECURE_BEACON_ACTIONS_CHARACTERISTIC                                               \
	BT_GATT_CHARACTERISTIC(FP_FMDN_UUID_SECURE_BEACON_ACTIONS,                                 \
			       BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE | BT_GATT_CHRC_NOTIFY |      \
				       BT_GATT_CHRC_INDICATE,                                      \
			       BT_GATT_PERM_READ_ENCRYPT | BT_GATT_PERM_WRITE_ENCRYPT,             \
			       fp_fmdn_sba_read, fp_fmdn_sba_write, NULL),                         \
		BT_GATT_CCC(fp_fmdn_sba_ccc_cfg_changed, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE)

/// Initialize Secure Beacon Actions GATT characteristic
__NONNULL_ALL
void fp_fmdn_sba_gatt_init(struct bt_gatt_attr *attr);

/// Deinitialize Secure Beacon Actions GATT characteristic
void fp_fmdn_sba_gatt_deinit(void);

/// Get the SBA characteristic attribute pointer for spontaneous indications
/// @return Pointer to SBA characteristic attribute, or NULL if not initialized
const struct bt_gatt_attr *fp_fmdn_sba_gatt_get_attr(void);

#ifdef __cplusplus
}
#endif

///@}
