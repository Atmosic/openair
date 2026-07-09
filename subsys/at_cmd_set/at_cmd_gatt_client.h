/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <zephyr/bluetooth/gatt.h>
#include "at_cmd_set_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Discovery command type stored in connection context so the shared
 *        discover callback can emit the correct AT event name.
 */
typedef enum {
	AT_GATTC_DISC_SVC,   /**< AT+BLEGATTDISCSVC  — discover service by UUID */
	AT_GATTC_DISC_SVCS,  /**< AT+BLEGATTDISCSVCS — discover all primary services */
	AT_GATTC_DISC_CHAR,  /**< AT+BLEGATTDISCCHAR  — discover characteristic by UUID */
	AT_GATTC_DISC_CHARS, /**< AT+BLEGATTDISCCHARS — discover all characteristics */
	AT_GATTC_DISC_DESCS, /**< AT+BLEGATTDISCDESCS — discover all descriptors */
} at_cmd_gattc_disc_type_t;

/**
 * @brief Subscribe slot: one bt_gatt_subscribe_params plus housekeeping.
 *
 * Allocated from a static pool of size
 * CONFIG_BT_MAX_CONN * CONFIG_AT_CMD_GATT_CLIENT_SUBS_MAX.
 */
typedef struct {
	struct bt_gatt_subscribe_params params; /**< Zephyr subscribe params (must be first) */
	bool in_use;                            /**< true when this slot is active */
	uint8_t conidx;                         /**< owning connection index */
} at_cmd_gatt_sub_slot_t;

/**
 * @brief Per-connection GATT client in-flight state.
 *
 * One instance per connection, indexed by AT connection slot (ctx->conns[] position).
 * All params live in a static array; no heap allocation is required.
 */
typedef struct {
	struct bt_gatt_discover_params disc; /**< Discovery params for bt_gatt_discover() */
	struct bt_gatt_read_params rd;       /**< Read params for bt_gatt_read() */
	struct bt_gatt_write_params wr;      /**< Write params for bt_gatt_write() */

	/** Write data copy — must outlive the write callback */
	uint8_t wr_buf[CONFIG_AT_CMD_GATT_CLIENT_RD_MAX_LEN];

	/** UUID storage for discovery params (union covers 16-bit and 128-bit) */
	union {
		struct bt_uuid base;
		struct bt_uuid_16 u16;
		struct bt_uuid_128 u128;
	} disc_uuid;

	at_cmd_gattc_disc_type_t disc_cmd; /**< Which disc command triggered this operation */

	uint8_t disc_max;   /**< Max discovery results to report (0 = unlimited) */
	uint8_t disc_count; /**< Running count of results in current discovery */

	bool disc_busy; /**< true while bt_gatt_discover() is in progress */
	bool rd_busy;   /**< true while bt_gatt_read() is in progress */
	bool wr_busy;   /**< true while bt_gatt_write() is in progress */
} at_cmd_gatt_client_conn_t;

/**
 * @brief Get the per-connection GATT client context.
 *
 * @param conidx Connection index (0 .. CONFIG_BT_MAX_CONN - 1)
 * @return Pointer to context, or NULL if conidx is out of range.
 */
at_cmd_gatt_client_conn_t *at_cmd_gatt_client_conn_get(uint8_t conidx);

/**
 * @brief Allocate a subscribe slot for a connection.
 *
 * @param conidx Connection index
 * @return Pointer to a free at_cmd_gatt_sub_slot_t, or NULL if pool is full.
 */
at_cmd_gatt_sub_slot_t *at_cmd_gatt_client_sub_alloc(uint8_t conidx);

/**
 * @brief Find an active subscribe slot by connection index and value handle.
 *
 * @param conidx       Connection index
 * @param value_handle Characteristic value handle
 * @return Pointer to matching slot, or NULL if not found.
 */
at_cmd_gatt_sub_slot_t *at_cmd_gatt_client_sub_find(uint8_t conidx, uint16_t value_handle);

/**
 * @brief Free a subscribe slot.
 *
 * @param slot Slot previously returned by at_cmd_gatt_client_sub_alloc().
 */
void at_cmd_gatt_client_sub_free(at_cmd_gatt_sub_slot_t *slot);

/**
 * @brief Convert AT MSB-first UUID bytes to Zephyr LE UUID stored in ctx->disc_uuid.
 *
 * Sets ctx->disc.uuid = &ctx->disc_uuid.base after conversion.
 *
 * @param ctx      Connection context
 * @param uuid_bytes AT-format UUID bytes (MSB-first), length 2 or 16
 * @param uuid_len   2 for 16-bit UUID, 16 for 128-bit UUID
 * @return 0 on success, -EINVAL if uuid_len is not 2 or BT_UUID_SIZE_128.
 */
int at_cmd_gatt_client_uuid_set(at_cmd_gatt_client_conn_t *ctx, const uint8_t *uuid_bytes,
				uint16_t uuid_len);

/**
 * @brief Start a GATT discovery using the parameters already set on @p ctx.
 *
 * Sets ctx->disc.func and calls bt_gatt_discover(). Sets ctx->disc_busy on
 * success.
 *
 * @param conn Active connection.
 * @param ctx  Connection context with disc params populated by the caller.
 * @return 0 on success, negative errno on failure.
 */
int at_cmd_gatt_client_discover(struct bt_conn *conn, at_cmd_gatt_client_conn_t *ctx);

/**
 * @brief Start a GATT read using the parameters already set on @p ctx.
 *
 * Sets ctx->rd.func and calls bt_gatt_read(). Sets ctx->rd_busy on success.
 *
 * @param conn Active connection.
 * @param ctx  Connection context with rd params populated by the caller.
 * @return 0 on success, negative errno on failure.
 */
int at_cmd_gatt_client_read(struct bt_conn *conn, at_cmd_gatt_client_conn_t *ctx);

/**
 * @brief Start a GATT write using the parameters already set on @p ctx.
 *
 * Sets ctx->wr.func and calls bt_gatt_write(). Sets ctx->wr_busy on success.
 *
 * @param conn Active connection.
 * @param ctx  Connection context with wr params populated by the caller.
 * @return 0 on success, negative errno on failure.
 */
int at_cmd_gatt_client_write(struct bt_conn *conn, at_cmd_gatt_client_conn_t *ctx);

/**
 * @brief Write without response wrapper (mockable in test mode).
 *
 * @param conn   Active connection.
 * @param handle Attribute handle.
 * @param data   Data to write.
 * @param length Data length.
 * @return 0 on success, negative errno on failure.
 */
int at_cmd_gatt_client_write_without_response(struct bt_conn *conn, uint16_t handle,
					      const void *data, uint16_t length);

/**
 * @brief Subscribe wrapper (mockable in test mode).
 *
 * @param conn Active connection.
 * @param slot Subscribe slot with params already populated.
 * @return 0 on success, -EALREADY if already subscribed, negative errno on failure.
 */
int at_cmd_gatt_client_subscribe(struct bt_conn *conn, at_cmd_gatt_sub_slot_t *slot);

/**
 * @brief Unsubscribe wrapper (mockable in test mode).
 *
 * @param conn Active connection.
 * @param slot Active subscribe slot to release.
 * @return 0 on success, negative errno on failure.
 */
int at_cmd_gatt_client_unsubscribe(struct bt_conn *conn, at_cmd_gatt_sub_slot_t *slot);

/**
 * @brief Reset all GATT client state for a dropped connection.
 *
 * Clears busy flags and releases all subscribe slots owned by @p conidx.
 * Internal helper; prefer at_cmd_gatt_client_on_conn_removed() when calling
 * from at_cmd_set_disconnected() so that s_conns[] stays aligned with the
 * connection tracking array.
 *
 * @param conidx Connection index of the dropped connection.
 */
void at_cmd_gatt_client_on_disconnected(uint8_t conidx);

/**
 * @brief Handle a connection slot removal and keep all GATT client state consistent.
 *
 * Must be called from at_cmd_set_disconnected() BEFORE memmove()-ing ctx->conns[].
 * This function:
 *   1. Frees the GATT client context and subscribe slots for @p removed_idx.
 *   2. memmove()-s s_conns[] to mirror the upcoming shift in ctx->conns[].
 *   3. Decrements the conidx stored in every active sub_pool slot that belonged
 *      to a connection whose tracking index shifted down.
 *
 * @param removed_idx AT tracking index of the connection being removed.
 * @param tail        Number of connections after @p removed_idx (same as the
 *                    @c tail variable computed in at_cmd_set_disconnected()).
 */
void at_cmd_gatt_client_on_conn_removed(uint8_t removed_idx, uint8_t tail);

/**
 * @defgroup at_cmd_gatt_client_result_callbacks GATT Client Result Callbacks
 * @brief Callbacks implemented in individual command files and called by at_cmd_gatt_client.c
 *
 * Each callback formats and sends the AT response for its corresponding command.
 * These are called from the Zephyr GATT callbacks (gattc_disc_cb, gattc_read_cb, gattc_write_cb).
 * @{
 */

#if defined(CONFIG_AT_CMD_BLEGATTDISCSVCS) || defined(CONFIG_AT_CMD_BLEGATTDISCSVC)
/**
 * @brief GATT service discovery result callback for BLEGATTDISCSVCS
 * @param ch AT command channel
 * @param conidx Connection index
 * @param start_handle Service start handle
 * @param end_handle Service end handle
 * @param uuid UUID bytes (MSB first)
 * @param uuid_len UUID length (2 or 16)
 */
void blegattdiscsvcs_result_cb(uint8_t ch, uint8_t conidx, uint16_t start_handle,
			       uint16_t end_handle, const uint8_t *uuid, uint8_t uuid_len);

/**
 * @brief GATT service discovery result callback for BLEGATTDISCSVC
 * @param ch AT command channel
 * @param conidx Connection index
 * @param start_handle Service start handle
 * @param end_handle Service end handle
 * @param uuid UUID bytes (MSB first)
 * @param uuid_len UUID length (2 or 16)
 */
void blegattdiscsvc_result_cb(uint8_t ch, uint8_t conidx, uint16_t start_handle,
			      uint16_t end_handle, const uint8_t *uuid, uint8_t uuid_len);
#endif

#if defined(CONFIG_AT_CMD_BLEGATTDISCCHARS) || defined(CONFIG_AT_CMD_BLEGATTDISCCHAR)
/**
 * @brief GATT characteristic discovery result callback for BLEGATTDISCCHARS
 * @param ch AT command channel
 * @param conidx Connection index
 * @param decl_handle Characteristic declaration handle
 * @param val_handle Characteristic value handle
 * @param props Characteristic properties
 * @param uuid UUID bytes (MSB first)
 * @param uuid_len UUID length (2 or 16)
 */
void blegattdiscchars_result_cb(uint8_t ch, uint8_t conidx, uint16_t decl_handle,
				uint16_t val_handle, uint8_t props, const uint8_t *uuid,
				uint8_t uuid_len);

/**
 * @brief GATT characteristic discovery result callback for BLEGATTDISCCHAR
 * @param ch AT command channel
 * @param conidx Connection index
 * @param decl_handle Characteristic declaration handle
 * @param val_handle Characteristic value handle
 * @param props Characteristic properties
 * @param uuid UUID bytes (MSB first)
 * @param uuid_len UUID length (2 or 16)
 */
void blegattdiscchar_result_cb(uint8_t ch, uint8_t conidx, uint16_t decl_handle,
			       uint16_t val_handle, uint8_t props, const uint8_t *uuid,
			       uint8_t uuid_len);
#endif

#ifdef CONFIG_AT_CMD_BLEGATTDISCDESCS
/**
 * @brief GATT descriptor discovery result callback
 * @param ch AT command channel
 * @param conidx Connection index
 * @param handle Descriptor handle
 * @param uuid UUID bytes (MSB first)
 * @param uuid_len UUID length (2 or 16)
 */
void blegattdiscdescs_result_cb(uint8_t ch, uint8_t conidx, uint16_t handle, const uint8_t *uuid,
				uint8_t uuid_len);
#endif

#ifdef CONFIG_AT_CMD_BLEGATTRD
/**
 * @brief GATT read result callback
 * @param ch AT command channel
 * @param conidx Connection index
 * @param handle Attribute handle
 * @param data Read data (NULL on error)
 * @param len Data length (0 on error)
 */
void blegattrd_result_cb(uint8_t ch, uint8_t conidx, uint16_t handle, const uint8_t *data,
			 uint16_t len);
#endif

#ifdef CONFIG_AT_CMD_BLEGATTWR
/**
 * @brief GATT write result callback
 * @param ch AT command channel
 * @param conidx Connection index
 * @param handle Attribute handle
 * @param att_err ATT error code (0 = success)
 */
void blegattwr_result_cb(uint8_t ch, uint8_t conidx, uint16_t handle, uint8_t att_err);
#endif

/** @} */ /* end of at_cmd_gatt_client_result_callbacks */

#ifdef CONFIG_ZTEST
/** Test hook: drive the discover callback directly (bypasses BT stack). */
uint8_t at_cmd_gatt_client_test_disc_cb(struct bt_conn *conn, const struct bt_gatt_attr *attr,
					struct bt_gatt_discover_params *params);

/** Test hook: drive the read callback directly. */
uint8_t at_cmd_gatt_client_test_read_cb(struct bt_conn *conn, uint8_t att_err,
					struct bt_gatt_read_params *params, const void *data,
					uint16_t length);

/** Test hook: drive the write callback directly. */
void at_cmd_gatt_client_test_write_cb(struct bt_conn *conn, uint8_t att_err,
				      struct bt_gatt_write_params *params);

/** Test hook: drive the notify/indicate callback directly. */
uint8_t at_cmd_gatt_client_test_notify_cb(struct bt_conn *conn,
					  struct bt_gatt_subscribe_params *params, const void *data,
					  uint16_t length);

/**
 * @brief Enable/disable BT GATT mock mode for command handler tests.
 *
 * When enabled, at_cmd_gatt_client_discover/read/write return the configured
 * values instead of calling the real BT stack.  This allows testing every
 * branch of the AT command handlers without a live BLE connection.
 *
 * @param enable true to activate mock, false to use real BT calls.
 */
void at_cmd_gatt_client_test_enable_bt_mock(bool enable);

/**
 * @brief Set the return values used by the BT GATT mock.
 *
 * @param discover_ret Value returned by at_cmd_gatt_client_discover().
 * @param read_ret     Value returned by at_cmd_gatt_client_read().
 * @param write_ret    Value returned by at_cmd_gatt_client_write().
 */
void at_cmd_gatt_client_test_set_bt_ret(int discover_ret, int read_ret, int write_ret);

/**
 * @brief Set return value for write-without-response mock.
 *
 * @param ret Value returned by at_cmd_gatt_client_write_without_response().
 */
void at_cmd_gatt_client_test_set_wrwo_ret(int ret);

/**
 * @brief Set return values for subscribe/unsubscribe mock.
 *
 * @param subscribe_ret   Value returned by at_cmd_gatt_client_subscribe().
 * @param unsubscribe_ret Value returned by at_cmd_gatt_client_unsubscribe().
 */
void at_cmd_gatt_client_test_set_sub_ret(int subscribe_ret, int unsubscribe_ret);
#endif /* CONFIG_ZTEST */

#ifdef __cplusplus
}
#endif
