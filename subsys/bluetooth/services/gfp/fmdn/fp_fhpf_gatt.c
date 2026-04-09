/**
 *******************************************************************************
 *
 * @file fp_fhpf_gatt.c
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN)
 *        Find Hub Precision Finding (FHPF) implementation
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/random/random.h>
#include <zephyr/bluetooth/att.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/sys/byteorder.h>
#include "app_work_q.h"
#include "atm_utils_c.h"
#include "fp_conn.h"
#include "fp_fhpf_gatt.h"
#include "fp_fmdn_internal.h"
#include "fp_fmdn_key.h"
#include "fp_common.h"
#include "fp_storage.h"
#include "ranging_oob_de.h"
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
#include <zephyr/bluetooth/cs.h>
#endif

LOG_MODULE_DECLARE(fmdn, CONFIG_ATM_FMDN_LOG_LEVEL);

/* Ranging callback handlers */
static fp_fmdn_ranging_handler_t const *ranging_handlers;

/* Unified static buffers to reduce stack usage */
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
static ranging_cap_de_uwb_t cap_buf_uwb_data;
#endif
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
static ranging_cap_de_cs_t cap_buf_cs_data;
#endif
static ranging_capability_t cap_buffer = {
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
	.uwb = &cap_buf_uwb_data,
#endif
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
	.cs = &cap_buf_cs_data,
#endif
};

#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
static ranging_conf_de_uwb_t cfg_buf_uwb_data;
#endif
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
static ranging_conf_de_cs_t cfg_buf_cs_data;
#endif
static ranging_config_t cfg_buffer = {
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
	.uwb = &cfg_buf_uwb_data,
#endif
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
	.cs = &cfg_buf_cs_data,
#endif
};

#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
/* Work structures for CS operations */
struct fp_fmdn_cs_default_settings_work {
	struct k_work work;
	struct bt_conn *conn;
};

#endif /* CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN */

/* Technology handler abstraction
 * Internal interface for technology-specific ranging operations.
 * Uses void* for config/capability buffers to maintain abstraction across different technologies.
 * Individual implementations (tech_uwb_*, tech_cs_*) use typed parameters for type safety.
 * Function pointers are cast to void* when assigned to support multiple technology types.
 * Callers ensure correct types are passed based on tech_id.
 */
typedef struct {
	rt_id_t tech_id;
	int (*decode_config)(const uint8_t *data, size_t data_len, ranging_config_t *conf_buf);
	int (*apply_config)(ranging_config_t *conf_buf, bool start_immediately);
	int (*start_op)(rt_id_t tech_id);
	int (*stop_op)(rt_id_t tech_id);
	int (*get_capability)(rt_id_t tech_id, ranging_capability_t *cap_buf);
	size_t config_size;
	size_t cap_size;
} tech_handler_t;

/* Technology-specific handler implementations
 * Defines the interface for ranging technology handlers (UWB, BLE CS).
 * Each handler implements: decode_config, apply_config, start, stop, and get_capability.
 * Implementations are defined inline before the handler registry to avoid forward declarations.
 */

/* UWB Technology Handler Implementation */
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
static int fp_fmdn_ranging_oob_de_decode_conf_uwb(const uint8_t *data, size_t data_len,
						  ranging_conf_de_uwb_t *uwb)
{

	size_t min_data_len = sizeof(ranging_conf_de_uwb_t) - sizeof(uwb->session_key.p_sts_data);
	if (!data || !uwb || data_len < min_data_len) {
		LOG_ERR("Invalid parameters for UWB config decode");
		return -EINVAL;
	}
	const uint8_t *ptr = data;

	uwb->id = *ptr++; // RT_TECH_ID_UWB
	uwb->size = *ptr++;

	// Decode UWB configuration parameters according to ranging_conf_de_uwb_t
	// Device UWB MAC Address (2 bytes)
	uwb->addr[0] = *ptr++;
	uwb->addr[1] = *ptr++;

	// Session ID (4 bytes)
	uint32_t session_id = (ptr[3] << 24) | (ptr[2] << 16) | (ptr[1] << 8) | ptr[0];
	uwb->session = session_id;
	ptr += 4;

	// Selected Config ID
	uwb->config_id = *ptr++;

	// Selected Channel
	uwb->channel = *ptr++;

	// Selected Preamble Index
	uwb->preamble_idx = *ptr++;

	// Selected Ranging Rate
	uwb->ranging_rate = (ptr[1] << 8) | ptr[0];
	ptr += 2;

	// Selected Slot Duration
	uwb->slot_dur = *ptr++;

	// Session Key Length
	uwb->session_key_len = *ptr++;

	// Session Key (variable length, up to 32 bytes)
	if (uwb->session_key_len > 32) {
		LOG_ERR("Invalid session key length: %d", uwb->session_key_len);
		return -EINVAL;
	}
	if (uwb->session_key_len == sizeof(s_sts_data_t)) {
		memcpy(&uwb->session_key.s_sts_data, ptr, sizeof(s_sts_data_t));
	} else {
		memcpy(&uwb->session_key.p_sts_data, ptr, uwb->session_key_len);
	}
	ptr += uwb->session_key_len;

	// Country Code (2 bytes)
	uwb->country_code = (ptr[1] << 8) | ptr[0];
	ptr += 2;

	// Device Role
	uwb->device_role = *ptr++;

	// Device Mode
	uwb->device_mode = *ptr++;

	LOG_DBG("Decoded UWB config: session_key_len=0x%02x, config_id=0x%02x, "
		"channel=0x%02x, role=0x%02x, mode=0x%02x",
		uwb->session_key_len, uwb->config_id, uwb->channel, uwb->device_role,
		uwb->device_mode);

	return 0;
}

static int tech_uwb_decode_config(const uint8_t *data, size_t data_len, ranging_config_t *conf_buf)
{
	/* Wrapper that calls the technology-specific UWB decode function */
	return fp_fmdn_ranging_oob_de_decode_conf_uwb(data, data_len, conf_buf->uwb);
}

static int tech_uwb_apply_config(ranging_config_t *conf_buf, bool start_immediately)
{
	if (ranging_handlers && ranging_handlers->config_cb) {
		LOG_INF("UWB: Configuration completed");
		return ranging_handlers->config_cb(RT_TECH_ID_UWB, conf_buf, start_immediately);
	}
	return -ENOTSUP;
}

static int tech_uwb_start(rt_id_t tech_id)
{
	if (ranging_handlers && ranging_handlers->start_cb) {
		return ranging_handlers->start_cb(tech_id);
	}
	return -ENOTSUP;
}

static int tech_uwb_stop(rt_id_t tech_id)
{
	if (ranging_handlers && ranging_handlers->stop_cb) {
		return ranging_handlers->stop_cb(tech_id);
	}
	return -ENOTSUP;
}

static int tech_uwb_get_capability(rt_id_t tech_id, ranging_capability_t *cap_buf)
{
	if (ranging_handlers && ranging_handlers->capability_cb) {
		return ranging_handlers->capability_cb(tech_id, cap_buf);
	}
	return -ENOTSUP;
}
#endif

/* BLE CS Technology Handler Implementation */
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
static int fp_fmdn_ranging_oob_de_decode_conf_cs(const uint8_t *data, size_t data_len,
						 ranging_conf_de_cs_t *cs)
{
	if (!data || !cs || data_len < sizeof(ranging_conf_de_cs_t)) {
		LOG_ERR("Invalid parameters for CS config decode");
		return -EINVAL;
	}

	const uint8_t *ptr = data;

	cs->id = *ptr++; // RT_TECH_ID_CS
	cs->size = *ptr++;
#ifdef CONFIG_RANGING_OOB_DE_TYPE_BLE_CS_CONFIG_SEC_TYPE
	// Decode CS configuration parameters
	cs->sec_type = (ranging_de_cs_sec_level_t)*ptr++;

	// Validate security type
	if (!IS_VALID_RANGING_RESP_DE_CS_SEC_LEVEL(cs->sec_type)) {
		LOG_ERR("Invalid CS security type: 0x%02x", cs->sec_type);
		return -EINVAL;
	}

	LOG_DBG("Decoded CS config: id=0x%02x, sec_type=0x%02x", cs->id, cs->sec_type);
#else
	LOG_DBG("Decoded CS config: id=0x%02x, size=0x%02x", cs->id, cs->size);
#endif
	return 0;
}

static int tech_cs_decode_config(const uint8_t *data, size_t data_len, ranging_config_t *conf_buf)
{
	/* Wrapper that calls the technology-specific CS decode function */
	return fp_fmdn_ranging_oob_de_decode_conf_cs(data, data_len, conf_buf->cs);
}

static int tech_cs_apply_config(ranging_config_t *conf_buf, bool start_immediately)
{
	// For CS responder: BT stack handles configuration automatically
	LOG_INF("CS: Configuration completed");

	if (start_immediately) {
		LOG_INF("CS: Start immediately requested");
	}

	// CS config_cb to application is just to reflect the start status
	if (ranging_handlers && ranging_handlers->config_cb) {
		return ranging_handlers->config_cb(RT_TECH_ID_CS, conf_buf, start_immediately);
	}
	return -ENOTSUP;
}

static int tech_cs_start(rt_id_t tech_id)
{
	if (ranging_handlers && ranging_handlers->start_cb) {
		return ranging_handlers->start_cb(tech_id);
	}
	return -ENOTSUP;
}

static int tech_cs_stop(rt_id_t tech_id)
{
	if (ranging_handlers && ranging_handlers->stop_cb) {
		return ranging_handlers->stop_cb(tech_id);
	}
	return -ENOTSUP;
}

static int tech_cs_get_capability(rt_id_t tech_id, ranging_capability_t *cap_buf)
{
	if (ranging_handlers && ranging_handlers->capability_cb) {
		return ranging_handlers->capability_cb(tech_id, cap_buf);
	}
	return -ENOTSUP;
}
#endif

/* Technology handler registry
 * Function pointers are cast to void* to support multiple technology types.
 * Each handler's implementation uses typed parameters for type safety.
 */
static const tech_handler_t tech_handlers[] = {
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
	{
		.tech_id = RT_TECH_ID_UWB,
		.decode_config = tech_uwb_decode_config,
		.apply_config = tech_uwb_apply_config,
		.start_op = tech_uwb_start,
		.stop_op = tech_uwb_stop,
		.get_capability = tech_uwb_get_capability,
		.config_size = sizeof(ranging_conf_de_uwb_t),
		.cap_size = sizeof(ranging_cap_de_uwb_t),
	},
#endif
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
	{
		.tech_id = RT_TECH_ID_CS,
		.decode_config = tech_cs_decode_config,
		.apply_config = tech_cs_apply_config,
		.start_op = tech_cs_start,
		.stop_op = tech_cs_stop,
		.get_capability = tech_cs_get_capability,
		.config_size = sizeof(ranging_conf_de_cs_t),
		.cap_size = sizeof(ranging_cap_de_cs_t),
	},
#endif
};

static const size_t tech_handlers_count = ARRAY_SIZE(tech_handlers);

/**
 * @brief Find technology handler by ID
 */
static const tech_handler_t *tech_handler_find(rt_id_t tech_id)
{
	for (size_t i = 0; i < tech_handlers_count; i++) {
		if (tech_handlers[i].tech_id == tech_id) {
			return &tech_handlers[i];
		}
	}
	return NULL;
}

#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
/**
 * @brief Internal security check function (used by macro)
 */
static bool is_ranging_connection_secure(const struct bt_conn *conn)
{
	if (!conn) {
		return false;
	}

	bt_security_t security_level = bt_conn_get_security(conn);
	LOG_DBG("BCNA Ranging: security_level %d", security_level);

	return (security_level >= CONFIG_FMDN_RANGING_CS_SECURITY_LEVEL);
}

/* Macro for consistent security checking across ranging handlers */
#define RANGING_SECURITY_CHECK(conn)                                                               \
	do {                                                                                       \
		if (!is_ranging_connection_secure(conn)) {                                         \
			LOG_ERR("BCNA RC: Insecure connection");                                   \
			return BT_GATT_ERR(BT_ATT_ERR_INSUFFICIENT_ENCRYPTION);                    \
		}                                                                                  \
	} while (0)
#else
#define RANGING_SECURITY_CHECK(conn)                                                               \
	do {                                                                                       \
	} while (0)
#endif

/**
 * @brief Inline function for ranging header decode and validation
 *
 * @param data Pointer to the data buffer
 * @param data_len Length of the data buffer
 * @param oob_header Pointer to store decoded header
 * @param exp_msg_id Expected message ID for validation
 * @return size_t Error code (0 on success, BT_GATT_ERR on failure)
 */
static inline size_t ranging_header_decode_check(const uint8_t *data, size_t data_len,
						 ranging_oob_de_header_t *oob_header,
						 ranging_msg_id_t exp_msg_id)
{
	if (data_len < sizeof(ranging_oob_de_header_t)) {
		LOG_ERR("BCNA RC: No version and msg_id for RC request");
		return BT_GATT_ERR(BCNA_ERR_INVALID_VALUE);
	}

	memcpy(oob_header, data, sizeof(ranging_oob_de_header_t));
	LOG_DBG("BCNA RC: Decoded request version: 0x%02x, msg_id: 0x%02x", oob_header->version,
		oob_header->msg_id);

	if (oob_header->msg_id != exp_msg_id) {
		LOG_ERR("BCNA RC: Invalid ranging message ID: 0x%02x", oob_header->msg_id);
		return BT_GATT_ERR(BCNA_ERR_INVALID_VALUE);
	}

	return 0;
}

/**
 * @brief Inline macro for common response building (flash optimized)
 */
#define BUILD_COMMON_RESPONSE(dst_ptr, resp_len, req_header, resp_msg_id, status_bitmap)           \
	do {                                                                                       \
		ranging_common_resp_de_t _de_resp = {                                              \
			.header.version = RANGING_OOB_DE_SUPPORT_VERSION((req_header)->version),   \
			.header.msg_id = (resp_msg_id),                                            \
			.status_bitmap = (status_bitmap)};                                         \
		FP_UTIL_MEMCPY_SHIFT((dst_ptr), &_de_resp, sizeof(ranging_common_resp_de_t),       \
				     *(resp_len));                                                 \
	} while (0)

#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
/**
 * @brief Check if connection meets ranging security requirements
 * @param conn Bluetooth connection
 * @return true if secure enough for ranging
 */
bool fp_fhpf_gatt_is_ranging_connection_secure(struct bt_conn *conn)
{
	return is_ranging_connection_secure(conn);
}
#endif /* CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN */

/* ========================================================================
 * Multi-Technology Abstraction Framework
 * ======================================================================== */

/**
 * @brief Handle ranging capability request
 */
size_t fp_fhpf_gatt_bcna_ranging_cap_handle(const struct bt_conn *conn, uint8_t *addition_data,
					    uint8_t add_data_len, uint16_t *resp_len)
{
	LOG_DBG("BCNA RC: Handling Ranging Capability Request");

	const uint8_t *ptr = addition_data;
	ranging_oob_de_header_t oob_header;
	size_t err =
		ranging_header_decode_check(ptr, add_data_len, &oob_header, RANGING_MSG_ID_CAP_REQ);
	if (err) {
		LOG_ERR("BCNA RC: Failed to decode ranging header");
		return err;
	}
	uint16_t tech_bf;
	memcpy(&tech_bf, ptr + sizeof(ranging_oob_de_header_t), sizeof(tech_bf));
	LOG_DBG("Ranging Capability Request tech_bf: 0x%04x", tech_bf);
	uint16_t resp_tech_bf = 0;
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
	if (tech_bf & RT_TECH_BF_UWB) {
		resp_tech_bf |= RT_TECH_BF_UWB;
	}
#endif
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
	if ((tech_bf & RT_TECH_BF_CS) ||
	    IS_ENABLED(CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_CAP_FORCE_EN)) {
		resp_tech_bf |= RT_TECH_BF_CS;
	}
#endif
	LOG_INF("Ranging Capability Response tech_bf: 0x%04x", resp_tech_bf);
	// Generate response
	uint8_t *dst_ptr = addition_data;
	oob_header.version = RANGING_OOB_DE_SUPPORT_VERSION(oob_header.version);
	oob_header.msg_id = RANGING_MSG_ID_CAP_RESP;
	FP_UTIL_MEMCPY_SHIFT(dst_ptr, &oob_header, sizeof(ranging_oob_de_header_t), *resp_len);
	FP_UTIL_MEMCPY_SHIFT(dst_ptr, &resp_tech_bf, sizeof(resp_tech_bf), *resp_len);

	/* Process capabilities for each supported technology */
	for (size_t i = 0; i < tech_handlers_count; i++) {
		const tech_handler_t *handler = &tech_handlers[i];
		uint16_t tech_bf = RT_ID_TO_BITFIELD(handler->tech_id);

		if (!(resp_tech_bf & tech_bf)) {
			continue;
		}

		LOG_INF("Get %s capabilities", handler->tech_id == RT_TECH_ID_UWB ? "UWB" : "CS");

		int ret = handler->get_capability(handler->tech_id, &cap_buffer);
		if (ret) {
			LOG_ERR("Failed to get %s capabilities: %d",
				handler->tech_id == RT_TECH_ID_UWB ? "UWB" : "CS", ret);
			continue;
		}

#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
		/* CS-specific: Add address information */
		if (handler->tech_id == RT_TECH_ID_CS) {
			struct bt_conn_info info;
			int ret = bt_conn_get_info(conn, &info);
			if (ret) {
				LOG_WRN("Failed to get connection info: %d", ret);
			} else {
				/* Convert identity address to big-endian format */
				sys_memcpy_swap(cap_buffer.cs->addr, info.le.src->a.val,
						BT_ADDR_SIZE);
			}
			LOG_INF("CS capabilities: id=0x%02x, size=0x%02x, sec_type=%d, "
				"appearance=0x%04x, flags=0x%02x",
				cap_buffer.cs->id, cap_buffer.cs->size, cap_buffer.cs->sec_type,
				cap_buffer.cs->appearance, cap_buffer.cs->flags);
			LOG_HEXDUMP_INF(cap_buffer.cs->addr, BT_ADDR_SIZE, "CS capabilities: addr");
		}
#endif

		/* Copy capability data to response */
		if (handler->tech_id == RT_TECH_ID_UWB) {
			FP_UTIL_MEMCPY_SHIFT(dst_ptr, cap_buffer.uwb, handler->cap_size, *resp_len);
		} else {
			FP_UTIL_MEMCPY_SHIFT(dst_ptr, cap_buffer.cs, handler->cap_size, *resp_len);
		}
	}
	LOG_HEXDUMP_DBG(addition_data, *resp_len, "BCNA RC: Response Ranging Capability DE:");
	return 0;
}

/**
 * @brief Unified ranging operation handler (flash optimized)
 * Handles configuration, start, and stop operations
 */
static size_t fp_fmdn_handle_ranging_operation(struct bt_conn *conn, uint8_t *addition_data,
					       uint8_t add_data_len, uint16_t *resp_len,
					       ranging_msg_id_t req_msg_id,
					       ranging_msg_id_t resp_msg_id,
					       const char *operation_name,
					       int (*operation_callback)(rt_id_t tech_id))
{
	LOG_DBG("BCNA RC: Handling Ranging %s Request", operation_name);

	if (!conn) {
		LOG_ERR("BCNA RC %s: NULL connection pointer", operation_name);
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_HANDLE);
	}

	/* Decode header */
	const uint8_t *ptr = addition_data;
	ranging_oob_de_header_t oob_header;
	size_t err = ranging_header_decode_check(ptr, add_data_len, &oob_header, req_msg_id);
	if (err) {
		LOG_ERR("BCNA RC %s: Failed to decode ranging header", operation_name);
		return err;
	}
	ptr += sizeof(ranging_oob_de_header_t);
	add_data_len -= sizeof(ranging_oob_de_header_t);

	/* Extract technology bitfield */
	uint16_t tech_bf;
	uint16_t start_bf = 0; // Only used for configuration
	memcpy(&tech_bf, ptr, sizeof(tech_bf));
	ptr += sizeof(tech_bf);
	add_data_len -= sizeof(tech_bf);

	/* For configuration requests, also extract start bitfield */
	if (req_msg_id == RANGING_MSG_ID_CONF) {
		memcpy(&start_bf, ptr, sizeof(start_bf));
		ptr += sizeof(start_bf);
		add_data_len -= sizeof(start_bf);
		LOG_DBG("BCNA RC %s: tech_bf: 0x%04x, start_bf: 0x%04x", operation_name, tech_bf,
			start_bf);
	} else {
		LOG_DBG("BCNA RC %s: tech_bf: 0x%04x", operation_name, tech_bf);
	}

	/* Process technologies based on operation type */
	uint16_t status_bitmap = 0x0000;

	if (req_msg_id == RANGING_MSG_ID_CONF) {
		/* Configuration: Process technology-specific data */
		while (add_data_len > 0) {
			uint8_t tech_id = ptr[0];
			uint8_t tech_size = ptr[1];

			if (add_data_len < tech_size) {
				LOG_ERR("BCNA RC Config: Invalid Ranging configuration data");
				return BT_GATT_ERR(BCNA_ERR_INVALID_VALUE);
			}

			const tech_handler_t *handler = tech_handler_find(tech_id);
			if (!handler) {
				LOG_WRN("BCNA RC Config: Unsupported ranging technology ID: "
					"0x%02x, skipping",
					tech_id);
				ptr += tech_size;
				add_data_len -= tech_size;
				continue;
			}

			bool start_immediately = (tech_bf & RT_ID_TO_BITFIELD(tech_id)) &&
						 (start_bf & RT_ID_TO_BITFIELD(tech_id));
			LOG_DBG("BCNA RC Config: start_immediately: %s",
				start_immediately ? "true" : "false");

			/* Security check for CS if starting immediately */
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
			if (tech_id == RT_TECH_ID_CS && start_immediately) {
				RANGING_SECURITY_CHECK(conn);
			}
#endif

			/* Decode configuration */
			int ret = handler->decode_config(ptr, tech_size, &cfg_buffer);
			if (ret) {
				LOG_ERR("BCNA RC Config: Failed to decode %s config: %d",
					tech_id == RT_TECH_ID_UWB ? "UWB" : "CS", ret);
				return BT_GATT_ERR(BCNA_ERR_INVALID_VALUE);
			}

			/* Apply configuration */
			ret = handler->apply_config(&cfg_buffer, start_immediately);
			if (ret) {
				LOG_ERR("BCNA RC Config: Failed to apply %s configuration: %d",
					tech_id == RT_TECH_ID_UWB ? "UWB" : "CS", ret);
			} else if (start_immediately) {
				status_bitmap |= RT_ID_TO_BITFIELD(tech_id);
			}

			/* Move to next technology configuration data */
			ptr += tech_size;
			add_data_len -= tech_size;
		}
	} else {
		/* Start/Stop: Process each supported technology */
		for (size_t i = 0; i < tech_handlers_count; i++) {
			const tech_handler_t *handler = &tech_handlers[i];
			uint16_t tech_bf_bit = RT_ID_TO_BITFIELD(handler->tech_id);

			if (!(tech_bf & tech_bf_bit)) {
				continue;
			}

#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
			/* Security check for CS */
			if (handler->tech_id == RT_TECH_ID_CS) {
				RANGING_SECURITY_CHECK(conn);
			}
#endif

			/* Call appropriate operation callback
			 * UWB: Requires actual hardware operation - missing callback is an error
			 * CS: Responder is passive (per BLE spec) - missing callback is expected,
			 *     just reflect status for UI/LED feedback
			 */
			int ret = 0;
			if (operation_callback) {
				ret = operation_callback(handler->tech_id);
			} else if (handler->tech_id == RT_TECH_ID_UWB) {
				LOG_WRN("No UWB ranging callback for %s", operation_name);
				continue;
			}

			if (!ret) {
				status_bitmap |= tech_bf_bit;
				LOG_INF("%s %s ranging", operation_name,
					handler->tech_id == RT_TECH_ID_UWB ? "UWB" : "CS");
			} else {
				LOG_ERR("Failed to %s %s ranging: %d", operation_name,
					handler->tech_id == RT_TECH_ID_UWB ? "UWB" : "CS", ret);
			}
		}
	}

	LOG_DBG("BCNA RC %s: status_bitmap: 0x%04x", operation_name, status_bitmap);

	/* Build response */
	uint8_t *dst_ptr = addition_data;
	BUILD_COMMON_RESPONSE(dst_ptr, resp_len, &oob_header, resp_msg_id, status_bitmap);

	LOG_HEXDUMP_DBG(addition_data, *resp_len, "BCNA RC: Response Ranging DE:");
	return 0;
}

/**
 * @brief Handle ranging configuration request
 */
size_t fp_fhpf_gatt_bcna_ranging_conf_handle(struct bt_conn *conn, uint8_t *addition_data,
					     uint8_t add_data_len, uint16_t *resp_len)
{
	return fp_fmdn_handle_ranging_operation(conn, addition_data, add_data_len, resp_len,
						RANGING_MSG_ID_CONF, RANGING_MSG_ID_CONF_RESP,
						"Configuration", NULL);
}

/**
 * @brief Handle ranging start request
 */
size_t fp_fhpf_gatt_bcna_ranging_start_handle(struct bt_conn *conn, uint8_t *addition_data,
					      uint8_t add_data_len, uint16_t *resp_len)
{
	return fp_fmdn_handle_ranging_operation(
		conn, addition_data, add_data_len, resp_len, RANGING_MSG_ID_START_RANGING,
		RANGING_MSG_ID_START_RANGING_RESP, "Start",
		ranging_handlers ? ranging_handlers->start_cb : NULL);
}

/**
 * @brief Handle ranging stop request
 */
size_t fp_fhpf_gatt_bcna_ranging_stop_handle(struct bt_conn *conn, uint8_t *addition_data,
					     uint8_t add_data_len, uint16_t *resp_len)
{
	return fp_fmdn_handle_ranging_operation(
		conn, addition_data, add_data_len, resp_len, RANGING_MSG_ID_STOP_RANGING,
		RANGING_MSG_ID_STOP_RANGING_RESP, "Stop",
		ranging_handlers ? ranging_handlers->stop_cb : NULL);
}

/**
 * @brief Register ranging handler callbacks
 */
void fp_fhpf_gatt_ranging_handler_register(fp_fmdn_ranging_handler_t const *handler)
{

	if (!handler) {
		ranging_handlers = NULL;
		LOG_DBG("FHPF: CS handler unregistered");
		return;
	}
	ranging_handlers = handler;
	LOG_DBG("FHPF: CS handler registered - capability: %s, config:%s, start:%s, stop:%s",
		handler->capability_cb ? "YES" : "NO", handler->config_cb ? "YES" : "NO",
		handler->start_cb ? "YES" : "NO", handler->stop_cb ? "YES" : "NO");
}

#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
/**
 * @brief CS procedure enabled callback
 */
void fp_fhpf_gatt_cs_procedure_enabled_cb(struct bt_conn *conn, uint8_t status,
					  struct bt_conn_le_cs_procedure_enable_complete *params);

/**
 * @brief CS config created callback
 */
void fp_fhpf_gatt_cs_config_created_cb(struct bt_conn *conn, uint8_t status,
				       struct bt_conn_le_cs_config *config);

/* CS ranging core functions */
static void fp_fmdn_ranging_cs_set_default(struct bt_conn *conn)
{
	const struct bt_le_cs_set_default_settings_param default_settings = {
		.enable_initiator_role = false,
		.enable_reflector_role = true,
		.cs_sync_antenna_selection = BT_LE_CS_ANTENNA_SELECTION_OPT_REPETITIVE,
		.max_tx_power = BT_HCI_OP_LE_CS_MAX_MAX_TX_POWER,
	};

	int err = bt_le_cs_set_default_settings(conn, &default_settings);
	if (err) {
		LOG_ERR("Failed to configure default CS settings (err %d)", err);
	}
	LOG_WRN("configure default CS settings");
}

static void fp_fmdn_cs_default_settings_work_handler(struct k_work *work)
{
	struct fp_fmdn_cs_default_settings_work *cs_work =
		CONTAINER_OF(work, struct fp_fmdn_cs_default_settings_work, work);

	if (cs_work->conn) {
		fp_fmdn_ranging_cs_set_default(cs_work->conn);
		LOG_INF("CS: Default settings completed for conn %p", (void *)cs_work->conn);
		bt_conn_unref(cs_work->conn);
	}
	k_free(cs_work);
}
#endif /* CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN */

/**
 * @brief Handle connection events for precision finding
 */
void fp_fhpf_gatt_conn_event(struct bt_conn *conn, bool connected)
{
	if (!conn) {
		return;
	}

	if (!connected) {
		LOG_DBG("FHPF: Connection disconnected");
		return;
	}

	LOG_DBG("FHPF: Connection established");

#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
	// Initialize CS state for this connection

	// Note: CS procedure state is created lazily when first CS operation occurs
	// Security check is performed only when ranging handlers are called

	// Schedule CS default settings configuration in work queue context
	struct fp_fmdn_cs_default_settings_work *cs_work = k_malloc(sizeof(*cs_work));
	if (!cs_work) {
		LOG_ERR("Failed to allocate memory for CS default settings work");
		return;
	}
	k_work_init(&cs_work->work, fp_fmdn_cs_default_settings_work_handler);
	cs_work->conn = bt_conn_ref(conn);

	int work_err = atm_work_submit_to_app_work_q(&cs_work->work);
	if (work_err < 0) {
		LOG_ERR("Failed to schedule CS default settings (err %d)", work_err);
		bt_conn_unref(cs_work->conn);
		k_free(cs_work);
	}
#endif
}

/**
 * @brief Handle security change events for precision finding
 */
void fp_fhpf_gatt_security_changed(struct bt_conn *conn, bt_security_t level,
				   enum bt_security_err err)
{
	if (!conn) {
		return;
	}

	if (err) {
		LOG_ERR("FHPF: Security failed: %d", err);
		return;
	}
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
	// Check if security level is sufficient for CS ranging
	if (level < CONFIG_FMDN_RANGING_CS_SECURITY_LEVEL) {
		LOG_WRN("Security level %u insufficient for CS ranging (need %u)", level,
			CONFIG_FMDN_RANGING_CS_SECURITY_LEVEL);
	} else {
		LOG_INF("CS ranging security requirements met: level:%u", level);
	}
#endif
}

#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
/**
 * @brief CS procedure enabled callback
 */
void fp_fhpf_gatt_cs_procedure_enabled_cb(struct bt_conn *conn, uint8_t status,
					  struct bt_conn_le_cs_procedure_enable_complete *params)
{
	if (!fp_conn_validate(conn)) {
		return;
	}

	if (status != BT_HCI_ERR_SUCCESS) {
		LOG_ERR("CS: Procedure enable failed for conn %p, status: %d", (void *)conn,
			status);
		return;
	}
	LOG_INF("CS: Procedures %s for conn %p",
		(params->state == BT_CONN_LE_CS_PROCEDURES_ENABLED) ? "enabled" : "disabled",
		(void *)conn);
}

/**
 * @brief CS config created callback
 */
void fp_fhpf_gatt_cs_config_created_cb(struct bt_conn *conn, uint8_t status,
				       struct bt_conn_le_cs_config *config)
{
	if (!fp_conn_validate(conn)) {
		return;
	}

	if (status != BT_HCI_ERR_SUCCESS) {
		LOG_ERR("CS: Config creation failed for conn %p, status: %d", (void *)conn, status);
		return;
	}

	LOG_INF("CS: Config created for conn %p, ID: %d", (void *)conn, config->id);
	// For CS responder: No action needed, BT stack handles everything automatically
}

#endif /* CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN */
