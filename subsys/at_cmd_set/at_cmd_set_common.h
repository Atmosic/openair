/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include "at_cmd_set.h"
#include <errno.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/sys/util.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Common ON/OFF string literals shared across all AT command descriptions. */
#define PARAM_ON  "ON"
#define PARAM_OFF "OFF"

/* Maximum connection index (0-based), derived from BT_MAX_CONN. */
#define CONN_IDX_MAX UTIL_DEC(CONFIG_BT_MAX_CONN)

/* Build a comma-separated format string repeated AT_CMD_ADV_MAX_INST times.
 * e.g. AT_CMD_RSP_FMT_REPEAT("%d") -> "%d" for N=1, "%d,%d" for N=2, etc.
 * Uses LISTIFY so no hardcoded limit or #error guard is needed.
 */
#define _AT_CMD_FMT_ITEM(i, x)         COND_CODE_0(i, (x), ("," x))
#define AT_CMD_RSP_FMT_REPEAT(x)       LISTIFY(AT_CMD_ADV_MAX_INST, _AT_CMD_FMT_ITEM, (), x)
#define AT_CMD_RSP_PARM_NUM_REPEAT(n)  (AT_CMD_ADV_MAX_INST * (n))
#define AT_CMD_RSP_REPEAT_OFFSET(i, n) ((i) * (n))
#define AT_CMD_RSP_REPEAT_FLAG(i, total)                                                           \
	((at_cmd_resp_flag_t)(at_data | (((i) == 0) ? at_prefix : 0) |                             \
			      (((i) == ((total)-1)) ? at_postfix : 0)))
#define AT_CMD_RSP_REPEAT(ch, cmd, i, total, n, ...)                                               \
	at_cmd_resp((ch), AT_CMD_RSP_REPEAT_FLAG((i), (total)), (cmd),                             \
		    AT_CMD_RSP_REPEAT_OFFSET((i), (n)), (n), __VA_ARGS__)

/**
 * @brief Return value for common API functions.
 * Use AT_CMD_RESULT_TO_PARAM() to propagate into an AT command handler param.
 */
typedef struct {
	int err; /**< Raw Zephyr errno (0 = success, negative = error, -1 = non-errno error) */
	uint16_t app_err; /**< Application-specific error code (0 = success) */
} at_cmd_result_t;

/**
 * @brief Helper to create a success result
 */
static inline at_cmd_result_t at_cmd_result_ok(void)
{
	return (at_cmd_result_t){.err = 0, .app_err = 0};
}

/**
 * @brief Map Zephyr errno to application error code
 * @param err Zephyr error code (negative errno value)
 * @return Application error code from at_cmd_app_err_t
 */
static inline uint16_t at_cmd_map_errno(int err)
{
	if (!err) {
		return AT_ERR_NONE;
	}

	/* Convert negative errno to positive for comparison */
	int abs_err = (err < 0) ? -err : err;

	switch (abs_err) {
	case EINVAL:
		return AT_ERR_BLE_EINVAL;
	case EBUSY:
		return AT_ERR_BLE_EBUSY;
	case ENOMEM:
		return AT_ERR_BLE_ENOMEM;
	case ENOTSUP:
		return AT_ERR_BLE_ENOTSUP;
	case EACCES:
		return AT_ERR_BLE_EACCES;
	case ENODEV:
		return AT_ERR_BLE_ENODEV;
	case ETIMEDOUT:
		return AT_ERR_BLE_ETIMEDOUT;
	case ECONNREFUSED:
		return AT_ERR_BLE_ECONNREFUSED;
	case ECONNRESET:
		return AT_ERR_BLE_ECONNRESET;
	case EPIPE:
		return AT_ERR_BLE_EPIPE;
	case EALREADY:
		return AT_ERR_BLE_EALREADY;
	default:
		return AT_ERR_BLE_UNKNOWN;
	}
}

/**
 * @brief Create error result from Zephyr errno (with automatic mapping)
 * @param err Zephyr error code (negative errno on failure, 0 on success)
 * @return Result structure with mapped application error code
 *
 * Use this when calling Zephyr APIs that return standard errno values.
 * The errno is automatically mapped to an appropriate application error code.
 * The errno is stored in result.err for logging/debugging purposes only.
 *
 * Example:
 *   err = bt_le_ext_adv_start(...);
 *   if (err) {
 *       return at_cmd_result_err_from_errno(err);  // Auto-maps errno
 *   }
 */
static inline at_cmd_result_t at_cmd_result_err_from_errno(int err)
{
	uint16_t app_err = 0;
	if (err) {
		app_err = at_cmd_map_errno(err);
	}
	return (at_cmd_result_t){.err = err, .app_err = app_err};
}

/**
 * @brief Create error result from application error code (no errno)
 * @param app_err Application error code from at_cmd_app_err_t
 * @return Result structure with application error code and err = -1
 *
 * Use this when rejecting a command for application-level reasons that have
 * no corresponding Zephyr errno (e.g., invalid index, state constraint).
 *
 * This is a constructor — it builds an at_cmd_result_t value. It is always
 * used in one of two ways:
 *
 * 1. In helper functions that return at_cmd_result_t:
 *      return at_cmd_result_err(AT_ERR_ADV_INVALID_INDEX);
 *
 * 2. In AT command handler callbacks (at_cmd_hdlr_t, which have param):
 *      AT_CMD_RESULT_TO_PARAM(at_cmd_result_err(AT_ERR_ADV_INVALID_INDEX), param);
 */
static inline at_cmd_result_t at_cmd_result_err(at_cmd_app_err_t app_err)
{
	return (at_cmd_result_t){.err = -1, .app_err = (uint16_t)app_err};
}

/**
 * @brief Propagate an at_cmd_result_t error into an AT command handler param.
 * @param result at_cmd_result_t value from a common API call
 * @param param  at_cmd_param_t pointer from the handler
 *
 * If result.app_err is non-zero, sets param->err = AT_CMD_ERR_SPECIFIC_ERR
 * and param->app_err = result.app_err; otherwise does nothing.
 */
#define AT_CMD_RESULT_TO_PARAM(result, param)                                                      \
	do {                                                                                       \
		if ((result).app_err) {                                                            \
			(param)->err = AT_CMD_ERR_SPECIFIC_ERR;                                    \
			(param)->app_err = (result).app_err;                                       \
		}                                                                                  \
	} while (0)

/**
 * @brief Shorthand: set param error from a direct application error code
 * @param app_err Application error code from at_cmd_app_err_t
 * @param param   The at_cmd_param_t pointer from the handler
 *
 * Equivalent to AT_CMD_RESULT_TO_PARAM(at_cmd_result_err(app_err), param).
 * Use when rejecting a command for a known domain reason (no errno involved).
 *
 * Example:
 *   AT_CMD_APP_ERR_TO_PARAM(AT_ERR_ADV_INVALID_PARAM, param);
 */
#define AT_CMD_APP_ERR_TO_PARAM(app_err, param)                                                    \
	AT_CMD_RESULT_TO_PARAM(at_cmd_result_err(app_err), param)

/**
 * @brief Shorthand: set param error from a Zephyr errno value
 * @param err   Zephyr error code (negative errno on failure, 0 on success)
 * @param param The at_cmd_param_t pointer from the handler
 *
 * Equivalent to AT_CMD_RESULT_TO_PARAM(at_cmd_result_err_from_errno(err), param).
 * Use after a Zephyr / BT API call that returns a standard errno.
 *
 * Example:
 *   AT_CMD_ERRNO_TO_PARAM(err, param);
 */
#define AT_CMD_ERRNO_TO_PARAM(err, param)                                                          \
	AT_CMD_RESULT_TO_PARAM(at_cmd_result_err_from_errno(err), param)

#ifdef CONFIG_AT_CMD_BLEADVENABLE
/**
 * @brief Start BLE advertising
 * @param idx Advertising instance index
 * @param enable true to start, false to stop
 * @return Operation result. See @ref at_cmd_result_t for details.
 */
at_cmd_result_t at_cmd_adv_enable(uint8_t idx, bool enable);

/**
 * @brief Check if advertising is enabled
 * @return true if advertising is enabled
 */
bool at_cmd_adv_is_enabled(void);

/**
 * @brief Restart advertising on an instance
 * @param idx Advertising instance index
 * @return Operation result. See @ref at_cmd_result_t for details.
 */
at_cmd_result_t at_cmd_adv_restart(int idx);

/**
 * @brief Apply current advertising and scan response data to an instance
 * @param ctx AT command context
 * @param idx Advertising instance index
 * @return Operation result. See @ref at_cmd_result_t for details.
 */
at_cmd_result_t at_cmd_adv_update_data(at_cmd_ctx_t *ctx, uint8_t idx);
#endif

#ifdef CONFIG_BT_EXT_ADV
/**
 * @brief Update advertising parameters
 * @param ctx AT command context
 * @param idx Advertising instance index
 *@return Operation result. See @ref at_cmd_result_t for details.
 */
at_cmd_result_t at_cmd_adv_update_param(at_cmd_ctx_t *ctx, uint8_t idx);
#endif

#ifdef CONFIG_AT_CMD_SET_CONN_TRACKING
/**
 * @brief Get connection pointer with index.
 * @param idx connection instance index
 * @return Connection pointer.
 */
struct bt_conn *at_cmd_conn_get(uint8_t idx);

/**
 * @brief Return the slot index of @p conn in the AT connection tracking array.
 *
 * @return 0-based slot index, or UINT8_MAX if not found.
 */
uint8_t at_cmd_conn_slot(const struct bt_conn *conn);

#endif

#ifdef CONFIG_AT_CMD_SET_SMP_AUTH
/**
 * @brief Get a pre-built SMP auth callback table for the given IO capability.
 * @param io_cap 0=NoInputNoOutput, 1=DisplayOnly, 2=DisplayYesNo,
 *               3=KeyboardOnly, 4=KeyboardDisplay
 * @return Pointer to the matching bt_conn_auth_cb, or NULL for invalid io_cap.
 */
const struct bt_conn_auth_cb *at_cmd_smp_get_auth_cb(uint8_t io_cap);

#ifdef CONFIG_ZTEST
/*
 * Test hooks: expose static pairing-result callbacks for unit-test coverage.
 * Only compiled in when CONFIG_ZTEST is set; not for production use.
 */
#ifdef CONFIG_AT_EVT_BLESMPPAIRENDIND
void at_cmd_smp_auth_test_pairing_complete(struct bt_conn *conn, bool bonded);
void at_cmd_smp_auth_test_pairing_failed(struct bt_conn *conn, enum bt_security_err reason);
#endif /* CONFIG_AT_EVT_BLESMPPAIRENDIND */
#endif /* CONFIG_ZTEST */

#endif /* CONFIG_AT_CMD_SET_SMP_AUTH */

#ifdef __cplusplus
}
#endif
