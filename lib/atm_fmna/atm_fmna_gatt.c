/**
 *******************************************************************************
 *
 * @file atm_fmna_gatt.c
 *
 * @brief FMNA GATT service descriptor tables for the FMN, AIS and UARP
 * services. Wires the characteristic UUIDs and callbacks exported by
 * fmna_gatt_api.h and registers the resulting service pointers back to the
 * FMNA library at SYS_INIT/APPLICATION priority.
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#include <zephyr/init.h>
#include <zephyr/kernel.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/uuid.h>

#include "fmna_gatt_api.h"

/* Find My Network service */
BT_GATT_SERVICE_DEFINE(
	fmn_service, BT_GATT_PRIMARY_SERVICE(BT_UUID_DECLARE_16(FMNA_GATT_FINDMY_SERVICE_UUID)),

	BT_GATT_CHARACTERISTIC(&fmn_pairing_ctrl_uuid.uuid,
			       BT_GATT_CHRC_INDICATE | BT_GATT_CHRC_WRITE, BT_GATT_PERM_WRITE, NULL,
			       fmna_gatt_pairing_ctrl_write, NULL),
	BT_GATT_CCC(NULL, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),

	BT_GATT_CHARACTERISTIC(&fmn_cfg_ctrl_uuid.uuid, BT_GATT_CHRC_INDICATE | BT_GATT_CHRC_WRITE,
			       BT_GATT_PERM_WRITE_ENCRYPT, NULL, fmna_gatt_cfg_ctrl_write, NULL),
	BT_GATT_CCC(NULL, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE_ENCRYPT),

	BT_GATT_CHARACTERISTIC(&fmn_non_owner_ctrl_uuid.uuid,
			       BT_GATT_CHRC_INDICATE | BT_GATT_CHRC_WRITE, BT_GATT_PERM_WRITE, NULL,
			       fmna_gatt_non_owner_ctrl_write, NULL),
	BT_GATT_CCC(NULL, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),

	BT_GATT_CHARACTERISTIC(&fmn_owner_info_ctrl_uuid.uuid,
			       BT_GATT_CHRC_INDICATE | BT_GATT_CHRC_WRITE, BT_GATT_PERM_WRITE, NULL,
			       fmna_gatt_owner_info_ctrl_write, NULL),
	BT_GATT_CCC(NULL, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),

	BT_GATT_CHARACTERISTIC(&fmn_debug_ctrl_uuid.uuid,
			       BT_GATT_CHRC_INDICATE | BT_GATT_CHRC_WRITE, BT_GATT_PERM_WRITE, NULL,
			       fmna_gatt_debug_ctrl_write, NULL),
	BT_GATT_CCC(NULL, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE), );

/* Accessory Information service (read-only, no CCC needed) */
BT_GATT_SERVICE_DEFINE(
	ais_service, BT_GATT_PRIMARY_SERVICE(&ais_uuid),

	BT_GATT_CHARACTERISTIC(&ais_product_uuid.uuid, BT_GATT_CHRC_READ, BT_GATT_PERM_READ,
			       fmna_gatt_ais_product_read, NULL, NULL),
	BT_GATT_CHARACTERISTIC(&ais_manu_uuid.uuid, BT_GATT_CHRC_READ, BT_GATT_PERM_READ,
			       fmna_gatt_ais_manu_read, NULL, NULL),
	BT_GATT_CHARACTERISTIC(&ais_model_uuid.uuid, BT_GATT_CHRC_READ, BT_GATT_PERM_READ,
			       fmna_gatt_ais_model_read, NULL, NULL),
	BT_GATT_CHARACTERISTIC(&ais_category_uuid.uuid, BT_GATT_CHRC_READ, BT_GATT_PERM_READ,
			       fmna_gatt_ais_category_read, NULL, NULL),
	BT_GATT_CHARACTERISTIC(&ais_cap_uuid.uuid, BT_GATT_CHRC_READ, BT_GATT_PERM_READ,
			       fmna_gatt_ais_cap_read, NULL, NULL),
	BT_GATT_CHARACTERISTIC(&ais_fw_ver_uuid.uuid, BT_GATT_CHRC_READ, BT_GATT_PERM_READ,
			       fmna_gatt_ais_fw_ver_read, NULL, NULL),
	BT_GATT_CHARACTERISTIC(&ais_findmy_ver_uuid.uuid, BT_GATT_CHRC_READ, BT_GATT_PERM_READ,
			       fmna_gatt_ais_findmy_ver_read, NULL, NULL),
	BT_GATT_CHARACTERISTIC(&ais_batt_type_uuid.uuid, BT_GATT_CHRC_READ, BT_GATT_PERM_READ,
			       fmna_gatt_ais_batt_type_read, NULL, NULL),
	BT_GATT_CHARACTERISTIC(&ais_batt_lvl_uuid.uuid, BT_GATT_CHRC_READ, BT_GATT_PERM_READ,
			       fmna_gatt_ais_batt_lvl_read, NULL, NULL), );

#ifdef CONFIG_USE_UARP
/* UARP service */
BT_GATT_SERVICE_DEFINE(
	uarp_service, BT_GATT_PRIMARY_SERVICE(BT_UUID_DECLARE_16(FMNA_GATT_UARP_SERVICE_UUID)),

	BT_GATT_CHARACTERISTIC(&uarp_data_uuid.uuid, BT_GATT_CHRC_INDICATE | BT_GATT_CHRC_WRITE,
			       BT_GATT_PERM_WRITE, NULL, fmna_gatt_uarp_data_write, NULL),
	BT_GATT_CCC(NULL, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE), );
#endif

static int atm_fmna_gatt_init(void)
{
	fmna_gatt_register_services(&fmn_service, &ais_service,
#ifdef CONFIG_USE_UARP
				    &uarp_service
#else
				    NULL
#endif
	);
	return 0;
}

SYS_INIT(atm_fmna_gatt_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
