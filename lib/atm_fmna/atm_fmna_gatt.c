/**
 *******************************************************************************
 *
 * @file atm_fmna_gatt.c
 *
 * @brief FMNA GATT service descriptor tables for the FMN, Non-Owner and UARP
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

	BT_GATT_CHARACTERISTIC(&fmn_owner_info_ctrl_uuid.uuid,
			       BT_GATT_CHRC_INDICATE | BT_GATT_CHRC_WRITE, BT_GATT_PERM_WRITE, NULL,
			       fmna_gatt_owner_info_ctrl_write, NULL),
	BT_GATT_CCC(NULL, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),

	BT_GATT_CHARACTERISTIC(&fmn_debug_ctrl_uuid.uuid,
			       BT_GATT_CHRC_INDICATE | BT_GATT_CHRC_WRITE, BT_GATT_PERM_WRITE, NULL,
			       fmna_gatt_debug_ctrl_write, NULL),
	BT_GATT_CCC(NULL, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE), );

/* R3: Accessory Non-Owner Service - single combined control-point characteristic. */
BT_GATT_SERVICE_DEFINE(nonowner_svc, BT_GATT_PRIMARY_SERVICE(&nonowner_svc_uuid),

		       BT_GATT_CHARACTERISTIC(&nonowner_ctrl_uuid.uuid,
					      BT_GATT_CHRC_INDICATE | BT_GATT_CHRC_WRITE,
					      BT_GATT_PERM_WRITE, NULL,
					      fmna_gatt_nonowner_ctrl_write, NULL),
		       BT_GATT_CCC(NULL, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE), );

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
	fmna_gatt_register_services(&fmn_service, &nonowner_svc,
#ifdef CONFIG_USE_UARP
				    &uarp_service
#else
				    NULL
#endif
	);
	return 0;
}

SYS_INIT(atm_fmna_gatt_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
