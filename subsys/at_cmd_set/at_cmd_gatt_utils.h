/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <zephyr/bluetooth/gatt.h>
#include "at_cmd_set_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/** GATT action codes for +EVTBLEGATTFROMBLE events and AT+BLEGATTTOBLE requests */
typedef enum {
	AT_GATT_ACT_READ = 0x00,     /**< Client read (host-bound) */
	AT_GATT_ACT_WRITE = 0x01,    /**< Client write (host-bound) */
	AT_GATT_ACT_NOTIFY = 0x02,   /**< Server notification (device→peer) */
	AT_GATT_ACT_INDICATE = 0x03, /**< Server indication (device→peer) */
} at_cmd_gatt_act_t;

/* ---- sec_prop bitmask layout -------------------------------------------- */

/** Bits 9/10 extend sec_prop to carry CHRC notify/indicate capability */
#define AT_CMD_GATT_CHRC_NOTIFY_BIT   BIT(9)
#define AT_CMD_GATT_CHRC_INDICATE_BIT BIT(10)

/** Bits 0–8: BT_GATT_PERM_* passed to the ATT layer */
#define AT_GATT_ATT_PERM_MASK   (BT_GATT_PERM_WRITE_LESC | (BT_GATT_PERM_WRITE_LESC - 1))
/** Bits 9–10: NOTIFY/INDICATE extension (not passed to ATT layer) */
#define AT_GATT_CHRC_EXT_MASK   (AT_CMD_GATT_CHRC_NOTIFY_BIT | AT_CMD_GATT_CHRC_INDICATE_BIT)
/** All valid sec_prop bits */
#define AT_GATT_PERM_VALID_MASK (AT_GATT_ATT_PERM_MASK | AT_GATT_CHRC_EXT_MASK)

/** All read-family BT_GATT_PERM_* bits */
#define AT_GATT_PERM_READ_MASK                                                                     \
	(BT_GATT_PERM_READ | BT_GATT_PERM_READ_ENCRYPT | BT_GATT_PERM_READ_AUTHEN |                \
	 BT_GATT_PERM_READ_LESC)
/** All write-family BT_GATT_PERM_* bits */
#define AT_GATT_PERM_WRITE_MASK                                                                    \
	(BT_GATT_PERM_WRITE | BT_GATT_PERM_WRITE_ENCRYPT | BT_GATT_PERM_WRITE_AUTHEN |             \
	 BT_GATT_PERM_WRITE_LESC)
/** CCC descriptor: readable (query) + writable (enable/disable) */
#define AT_GATT_PERM_CCC (BT_GATT_PERM_READ | BT_GATT_PERM_WRITE)

/* ---- Shared utility functions ------------------------------------------- */

/** @return true if @p perm contains only valid BT_GATT_PERM_* bits */
bool at_cmd_gatt_is_valid_perm(uint16_t perm);

/**
 * @brief Derive BT_GATT_CHRC_* properties from AT command sec_prop.
 *
 * READ-family → CHRC_READ; WRITE-family → CHRC_WRITE_WITHOUT_RESP;
 * bit 9 → CHRC_NOTIFY; bit 10 → CHRC_INDICATE.
 */
uint8_t at_cmd_gatt_sec_prop_to_chrc_props(uint16_t sec_prop);

/**
 * @brief Send GATT notification or indication to a connected peer.
 *
 * Searches DFT service first, then DYN if not found.
 *
 * @param conidx AT connection slot (ctx->conns[] position, NOT bt_conn_index())
 * @param handle BT GATT attribute handle (attr->handle)
 * @param action AT_GATT_ACT_NOTIFY or AT_GATT_ACT_INDICATE
 */
at_cmd_result_t at_cmd_gatt_to_ble(uint8_t conidx, uint16_t handle, at_cmd_gatt_act_t action,
				   const uint8_t *data, uint16_t len);

/**
 * @brief Emit +EVTBLEGATTFROMBLE to the host.
 *
 * Used by both DFT and DYN GATT server callbacks.
 *
 * @param conidx AT connection slot (ctx->conns[] position, NOT bt_conn_index())
 * @param handle BT GATT attribute handle (attr->handle)
 * @param action AT_GATT_ACT_READ or AT_GATT_ACT_WRITE
 */
void at_cmd_evt_gatt_from_ble(uint8_t conidx, uint16_t handle, at_cmd_gatt_act_t action,
			      const uint8_t *data, uint16_t len);

#ifdef __cplusplus
}
#endif
