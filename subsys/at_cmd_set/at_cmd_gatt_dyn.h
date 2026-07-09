/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <zephyr/sys/slist.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/uuid.h>
#include <stdbool.h>
#include <stdint.h>
#include "at_cmd_set_common.h"
#include "at_cmd_gatt_utils.h"

/** Reason codes for AT+BLEGATTSVCACTIVE */
typedef enum {
	AT_GATT_DYN_SVC_REASON_APPLY = 0x00, /**< Apply (register) all staged services */
} at_cmd_gatt_dyn_svc_reason_t;

#ifdef __cplusplus
extern "C" {
#endif

/* ---- Data structures (heap-allocated per AT command) ---- */

/** Descriptor entry — allocated by ADDDESC or ADDDESCUSERDFD */
typedef struct at_cmd_gatt_dyn_desc {
	sys_snode_t node; /**< linked into at_cmd_gatt_dyn_char_t.descs */
	union {
		struct bt_uuid_128 u128; /**< ADDDESCUSERDFD: sys_memcpy_swap from A(16~16) */
		struct bt_uuid_16 u16;   /**< ADDDESC: sys_get_be16 from A(2~2) */
	} uuid;
	uint16_t sec_prop; /**< ADDDESC: BT_GATT_PERM_READ fixed; USERDFD: from param */
	uint8_t *val_buf;  /**< k_calloc(max_size); ADDDESC = NULL */
	uint16_t val_len;  /**< current written length */
	uint16_t max_size; /**< ADDDESC = 0; USERDFD = W(1~1024) */
	bool is_userdfd;   /**< false = ADDDESC, true = ADDDESCUSERDFD */
} at_cmd_gatt_dyn_desc_t;

/** Characteristic entry — allocated by ADDCHAR */
typedef struct at_cmd_gatt_dyn_char {
	sys_snode_t node;              /**< linked into svc.chars */
	struct bt_uuid_128 uuid128;    /**< Zephyr LE format (from sys_memcpy_swap) */
	struct bt_gatt_chrc chrc_decl; /**< filled at APPLY time */
	struct bt_gatt_ccc_managed_user_data ccc_data; /**< used when NOTIFY/INDICATE */
	uint16_t sec_prop;
	uint8_t *val_buf; /**< k_calloc(max_size) */
	uint16_t val_len;
	uint16_t max_size;
	sys_slist_t descs; /**< owned at_cmd_gatt_dyn_desc_t list */
} at_cmd_gatt_dyn_char_t;

/** Service entry — allocated by ADDSERVICE */
typedef struct at_cmd_gatt_dyn_svc {
	sys_snode_t node;           /**< linked into global s_svcs */
	struct bt_uuid_128 uuid128; /**< Zephyr LE format */
	uint16_t sec_prop;
	bool active;                   /**< true = bt_gatt_service_register called */
	struct bt_gatt_service bt_svc; /**< .attrs = k_calloc(attr_cnt) at APPLY */
	sys_slist_t chars;             /**< owned at_cmd_gatt_dyn_char_t list */
	uint8_t char_cnt;
} at_cmd_gatt_dyn_svc_t;

/* ---- Public API ---- */

/**
 * @brief Find a dynamic service attribute by its BT GATT handle.
 *
 * Searches all active dynamic services for an attribute whose handle matches
 * @p handle.  Only active (registered) services are searched.
 *
 * @param handle BT GATT attribute handle (attr->handle after service registration).
 * @return Pointer to the matching attribute, or NULL if not found.
 */
struct bt_gatt_attr *at_cmd_gatt_dyn_find_attr_by_handle(uint16_t handle);

/**
 * @brief Add a dynamic Primary Service (AT+BLEGATTADDSERVICE)
 *
 * @param sec_prop BT_GATT_PERM_* read bits only (WRITE bits rejected per BLE spec)
 * @param uuid_be16 16-byte UUID, MSB-first (from A(16~16))
 * @return at_cmd_result_t
 */
at_cmd_result_t at_cmd_gatt_dyn_add_service(uint16_t sec_prop, const uint8_t *uuid_be16);

/**
 * @brief Add a Characteristic to the current service (AT+BLEGATTADDCHAR)
 *
 * @param sec_prop BT_GATT_PERM_* + optional NOTIFY/INDICATE bits
 * @param uuid_be16 16-byte UUID, MSB-first
 * @param max_size Value buffer size 1–1024
 * @return at_cmd_result_t
 */
at_cmd_result_t at_cmd_gatt_dyn_add_char(uint16_t sec_prop, const uint8_t *uuid_be16,
					 uint16_t max_size);

/**
 * @brief Add a standard 16-bit Descriptor (AT+BLEGATTADDDESC)
 *
 * @param uuid16_be2 2-byte UUID, MSB-first (from A(2~2))
 * @return at_cmd_result_t
 */
at_cmd_result_t at_cmd_gatt_dyn_add_desc(const uint8_t *uuid16_be2);

/**
 * @brief Add a user-defined readable/writable Descriptor (AT+BLEGATTADDDESCUSERDFD)
 *
 * @param sec_prop BT_GATT_PERM_* bits (bits 9-10 rejected)
 * @param uuid_be16 16-byte UUID, MSB-first
 * @param max_size Value buffer size 1–1024
 * @return at_cmd_result_t
 */
at_cmd_result_t at_cmd_gatt_dyn_add_userdfd(uint16_t sec_prop, const uint8_t *uuid_be16,
					    uint16_t max_size);

/**
 * @brief Apply or deactivate staged services (AT+BLEGATTSVCACTIVE)
 *
 * @param reason at_cmd_gatt_dyn_svc_reason_t value
 * @return at_cmd_result_t
 */
at_cmd_result_t at_cmd_gatt_dyn_svc_activate(at_cmd_gatt_dyn_svc_reason_t reason);

/* ---- Ztest hooks ---- */
#ifdef CONFIG_ZTEST
ssize_t at_cmd_gatt_dyn_test_char_read(uint8_t conidx, at_cmd_gatt_dyn_char_t *ch, void *buf,
				       uint16_t len, uint16_t offset);
ssize_t at_cmd_gatt_dyn_test_char_write(uint8_t conidx, at_cmd_gatt_dyn_char_t *ch, const void *buf,
					uint16_t len, uint8_t flags);
ssize_t at_cmd_gatt_dyn_test_desc_read(uint8_t conidx, at_cmd_gatt_dyn_desc_t *desc, void *buf,
				       uint16_t len, uint16_t offset);
ssize_t at_cmd_gatt_dyn_test_desc_write(uint8_t conidx, at_cmd_gatt_dyn_desc_t *desc,
					const void *buf, uint16_t len, uint8_t flags);
uint8_t at_cmd_gatt_dyn_test_svc_cnt(void);
at_cmd_gatt_dyn_svc_t *at_cmd_gatt_dyn_test_curr_svc(void);
at_cmd_gatt_dyn_char_t *at_cmd_gatt_dyn_test_curr_char(void);
#endif /* CONFIG_ZTEST */

#ifdef __cplusplus
}
#endif
