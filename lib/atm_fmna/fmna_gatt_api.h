/* AUTO-POPULATED HEADER. DO NOT EDIT - changes will be overwritten. */
/**
 *******************************************************************************
 *
 * @file fmna_gatt_api.h
 *
 * @brief Public GATT interface exported by the FMNA library: characteristic
 * UUIDs, read/write callbacks and the service registration entry point used
 * by the application to hand back the constructed FMN / AIS / UARP service
 * pointers.
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup fmna_gatt
 * @ingroup fmna
 * @brief FMNA GATT public interface
 * @{
 */

#include <stdint.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/uuid.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Apple-assigned 16-bit UUIDs for FMN primary services. */
#define FMNA_GATT_FINDMY_SERVICE_UUID 0xFD44
#define FMNA_GATT_UARP_SERVICE_UUID   0xFD43

/* Find My Network service characteristic UUIDs */
extern struct bt_uuid_128 const fmn_pairing_ctrl_uuid;
extern struct bt_uuid_128 const fmn_cfg_ctrl_uuid;
extern struct bt_uuid_128 const fmn_non_owner_ctrl_uuid;
extern struct bt_uuid_128 const fmn_owner_info_ctrl_uuid;
extern struct bt_uuid_128 const fmn_debug_ctrl_uuid;

/* Accessory Information service UUIDs */
extern struct bt_uuid_128 const ais_uuid;
extern struct bt_uuid_128 const ais_product_uuid;
extern struct bt_uuid_128 const ais_manu_uuid;
extern struct bt_uuid_128 const ais_model_uuid;
extern struct bt_uuid_128 const ais_category_uuid;
extern struct bt_uuid_128 const ais_cap_uuid;
extern struct bt_uuid_128 const ais_fw_ver_uuid;
extern struct bt_uuid_128 const ais_findmy_ver_uuid;
extern struct bt_uuid_128 const ais_batt_type_uuid;
extern struct bt_uuid_128 const ais_batt_lvl_uuid;

#ifdef CONFIG_USE_UARP
/* UARP service UUID */
extern struct bt_uuid_128 const uarp_data_uuid;
#endif

/* FMN service write handlers (used as bt_gatt_attr.write callbacks) */
ssize_t fmna_gatt_pairing_ctrl_write(struct bt_conn *conn,
    struct bt_gatt_attr const *attr, void const *buf, uint16_t len,
    uint16_t offset, uint8_t flags);

ssize_t fmna_gatt_cfg_ctrl_write(struct bt_conn *conn,
    struct bt_gatt_attr const *attr, void const *buf, uint16_t len,
    uint16_t offset, uint8_t flags);

ssize_t fmna_gatt_non_owner_ctrl_write(struct bt_conn *conn,
    struct bt_gatt_attr const *attr, void const *buf, uint16_t len,
    uint16_t offset, uint8_t flags);

ssize_t fmna_gatt_owner_info_ctrl_write(struct bt_conn *conn,
    struct bt_gatt_attr const *attr, void const *buf, uint16_t len,
    uint16_t offset, uint8_t flags);

ssize_t fmna_gatt_debug_ctrl_write(struct bt_conn *conn,
    struct bt_gatt_attr const *attr, void const *buf, uint16_t len,
    uint16_t offset, uint8_t flags);

/* AIS read handlers */
ssize_t fmna_gatt_ais_product_read(struct bt_conn *conn,
    struct bt_gatt_attr const *attr, void *buf, uint16_t len, uint16_t offset);

ssize_t fmna_gatt_ais_manu_read(struct bt_conn *conn,
    struct bt_gatt_attr const *attr, void *buf, uint16_t len, uint16_t offset);

ssize_t fmna_gatt_ais_model_read(struct bt_conn *conn,
    struct bt_gatt_attr const *attr, void *buf, uint16_t len, uint16_t offset);

ssize_t fmna_gatt_ais_category_read(struct bt_conn *conn,
    struct bt_gatt_attr const *attr, void *buf, uint16_t len, uint16_t offset);

ssize_t fmna_gatt_ais_cap_read(struct bt_conn *conn,
    struct bt_gatt_attr const *attr, void *buf, uint16_t len, uint16_t offset);

ssize_t fmna_gatt_ais_fw_ver_read(struct bt_conn *conn,
    struct bt_gatt_attr const *attr, void *buf, uint16_t len, uint16_t offset);

ssize_t fmna_gatt_ais_findmy_ver_read(struct bt_conn *conn,
    struct bt_gatt_attr const *attr, void *buf, uint16_t len, uint16_t offset);

ssize_t fmna_gatt_ais_batt_type_read(struct bt_conn *conn,
    struct bt_gatt_attr const *attr, void *buf, uint16_t len, uint16_t offset);

ssize_t fmna_gatt_ais_batt_lvl_read(struct bt_conn *conn,
    struct bt_gatt_attr const *attr, void *buf, uint16_t len, uint16_t offset);

#ifdef CONFIG_USE_UARP
/* UARP write handler */
ssize_t fmna_gatt_uarp_data_write(struct bt_conn *conn,
    struct bt_gatt_attr const *attr, void const *buf, uint16_t len,
    uint16_t offset, uint8_t flags);
#endif

/**
 * @brief Register service descriptor pointers with the FMNA library.
 *
 * The library uses these pointers to look up indication target attributes
 * via bt_gatt_find_by_uuid(). Must be called before the first FMNA
 * indication is sent (before fmna_main_init() returns is sufficient).
 *
 * @param fmn   FMN service descriptor (required).
 * @param ais   AIS service descriptor (may be NULL, currently unused by lib).
 * @param uarp  UARP service descriptor (may be NULL when CONFIG_USE_UARP=n).
 */
void fmna_gatt_register_services(
    struct bt_gatt_service_static const *fmn,
    struct bt_gatt_service_static const *ais,
    struct bt_gatt_service_static const *uarp);

#ifdef __cplusplus
}
#endif

/// @}
