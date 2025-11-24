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
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
#include <zephyr/bluetooth/cs.h>
#endif

LOG_MODULE_DECLARE(fmdn, CONFIG_ATM_FMDN_LOG_LEVEL);

/* Ranging callback handlers */
static fp_fmdn_ranging_handler_t const *ranging_handlers;

/* Unified static buffers to reduce stack usage */
static union {
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
	ranging_cap_de_uwb_t uwb_cap;
#endif
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
	ranging_cap_de_cs_t cs_cap;
#endif
} cap_buffer;

static union {
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
	ranging_conf_de_uwb_t uwb_conf;
#endif
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
	ranging_conf_de_cs_t cs_conf;
#endif
} cfg_buffer;

#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
/* Work structures for CS operations */
struct fp_fmdn_cs_default_settings_work {
	struct k_work work;
	struct bt_conn *conn;
};

/* CS state management removed - not required for BLE CS functionality */
static void fp_fmdn_cs_default_settings_work_handler(struct k_work *work);

/* Forward declarations for CS core functions */
static void fp_fmdn_ranging_cs_set_default(struct bt_conn *conn);
#endif /* CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN */

/* Technology support lookup table for optimization */
static const bool tech_support_table[] = {
	[RT_TECH_ID_UWB] = IS_ENABLED(CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN),
	[RT_TECH_ID_CS] = IS_ENABLED(CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN),
};

#define IS_TECH_SUPPORTED(id) ((id) < ARRAY_SIZE(tech_support_table) && tech_support_table[id])

/* Macro for consistent security checking across ranging handlers */
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
#define RANGING_SECURITY_CHECK(conn)                                                               \
	do {                                                                                       \
		if (!is_ranging_connection_secure(conn)) {                                         \
			LOG_ERR("BCNA RC: Insecure connection");                                   \
			return BT_GATT_ERR(BT_ATT_ERR_INSUFFICIENT_ENCRYPTION);                    \
		}                                                                                  \
	} while (0)
/* Forward declaration for security check function */
static bool is_ranging_connection_secure(const struct bt_conn *conn);
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

/**
 * @brief Check if connection meets ranging security requirements
 * @param conn Bluetooth connection
 * @return true if secure enough for ranging
 */
bool fp_fhpf_gatt_is_ranging_connection_secure(struct bt_conn *conn)
{
	return is_ranging_connection_secure(conn);
}

/**
 * @brief Decode CS configuration data element
 */
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

#endif /* CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN */

#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
/**
 * @brief Decode UWB configuration data element
 */
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
#endif /* CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN */

/* ========================================================================
 * Multi-Technology Abstraction Framework
 * ======================================================================== */

/* Technology-specific implementations */
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
static int fp_fmdn_uwb_apply_config(void *conf_buf, bool start_immediately)
{
	if (ranging_handlers && ranging_handlers->config_cb) {
		LOG_INF("UWB: Configuration completed");
		int ret = ranging_handlers->config_cb(RT_TECH_ID_UWB, conf_buf, start_immediately);
		if (ret) {
			LOG_ERR("Failed to apply UWB config: %d", ret);
			return ret;
		}
	}
	return 0;
}
#endif

#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
static int fp_fmdn_cs_apply_config(void *conf_buf, bool start_immediately)
{
	// For CS responder: BT stack handles configuration automatically
	LOG_INF("CS: Configuration completed");

	if (start_immediately) {
		LOG_INF("CS: Start immediately requested");
	}

	// CS config_cb to application is just to reflect the start status
	if (ranging_handlers && ranging_handlers->config_cb) {
		int ret = ranging_handlers->config_cb(RT_TECH_ID_CS, conf_buf, start_immediately);
		if (ret) {
			LOG_ERR("Failed to reflect application start status: %d", ret);
		}
	}
	return 0;
}
#endif

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

	if (ranging_handlers && ranging_handlers->capability_cb) {
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
		if (resp_tech_bf & RT_TECH_BF_UWB) {
			LOG_INF("Get UWB capabilities");
			// Use static buffer to reduce stack usage
			int ret = ranging_handlers->capability_cb(RT_TECH_ID_UWB,
								  &cap_buffer.uwb_cap);
			if (ret) {
				LOG_ERR("Failed to get UWB capabilities: %d", ret);
			} else {
				// Copy RC OOB response data to addition_data field
				FP_UTIL_MEMCPY_SHIFT(dst_ptr, &cap_buffer.uwb_cap,
						     sizeof(ranging_cap_de_uwb_t), *resp_len);
			}
		}
#endif /* CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN */
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
		if (resp_tech_bf & RT_TECH_BF_CS) {
			// Use static buffer to reduce stack usage
			LOG_INF("Get CS capabilities");
			int ret =
				ranging_handlers->capability_cb(RT_TECH_ID_CS, &cap_buffer.cs_cap);
			if (ret) {
				LOG_ERR("Failed to get CS capabilities: %d", ret);
			} else {
				struct bt_conn_info info;
				int ret = bt_conn_get_info(conn, &info);
				if (ret) {
					LOG_WRN("Failed to get connection info: %d", ret);
				} else {
					/* Convert identity address to big-endian format */
					sys_memcpy_swap(cap_buffer.cs_cap.addr, info.le.src->a.val,
							BT_ADDR_SIZE);
				}
				// Copy RC OOB response data to addition_data field
				LOG_INF("CS capabilities: id=0x%02x, size=0x%02x, sec_type=%d, "
					"addr=0x%02x%02x%02x%02x%02x%02x, appearance=0x%04x, "
					"flags=0x%02x",
					cap_buffer.cs_cap.id, cap_buffer.cs_cap.size,
					cap_buffer.cs_cap.sec_type, cap_buffer.cs_cap.addr[0],
					cap_buffer.cs_cap.addr[1], cap_buffer.cs_cap.addr[2],
					cap_buffer.cs_cap.addr[3], cap_buffer.cs_cap.addr[4],
					cap_buffer.cs_cap.addr[5], cap_buffer.cs_cap.appearance,
					cap_buffer.cs_cap.flags);
				FP_UTIL_MEMCPY_SHIFT(dst_ptr, &cap_buffer.cs_cap,
						     sizeof(ranging_cap_de_cs_t), *resp_len);
			}
		}
#endif /* CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN */
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

			if (IS_TECH_SUPPORTED(tech_id)) {
				if (add_data_len != tech_size) {
					LOG_ERR("BCNA RC Config: Invalid Ranging configuration "
						"data");
					return BT_GATT_ERR(BCNA_ERR_INVALID_VALUE);
				}

				bool start_immediately =
					(tech_bf & (1 << tech_id)) && (start_bf & (1 << tech_id));
				LOG_DBG("BCNA RC Config: start_immediately: %s",
					start_immediately ? "true" : "false");

				/* Direct configuration processing using #ifdef optimization */
				int ret = -ENOTSUP;

#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
				if (tech_id == RT_TECH_ID_UWB) {
					// Decode UWB configuration
					ret = fp_fmdn_ranging_oob_de_decode_conf_uwb(
						ptr, add_data_len, &cfg_buffer.uwb_conf);
					if (ret) {
						LOG_ERR("BCNA RC Config: Failed to decode UWB "
							"config: %d",
							ret);
						return BT_GATT_ERR(BCNA_ERR_INVALID_VALUE);
					}

					// Apply UWB configuration
					ret = fp_fmdn_uwb_apply_config(&cfg_buffer.uwb_conf,
								       start_immediately);
					if (ret) {
						LOG_ERR("BCNA RC Config: Failed to apply UWB "
							"configuration: %d",
							ret);
					} else if (start_immediately) {
						status_bitmap |= (1 << tech_id);
					}
				} else
#endif
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
					if (tech_id == RT_TECH_ID_CS) {
					if (start_immediately) {
						RANGING_SECURITY_CHECK(conn);
					}
					// Decode CS configuration
					ret = fp_fmdn_ranging_oob_de_decode_conf_cs(
						ptr, add_data_len, &cfg_buffer.cs_conf);
					if (ret) {
						LOG_ERR("BCNA RC Config: Failed to decode CS :"
							"config: %d",
							ret);
						return BT_GATT_ERR(BCNA_ERR_INVALID_VALUE);
					}

					// Apply CS configuration
					ret = fp_fmdn_cs_apply_config(&cfg_buffer.cs_conf,
								      start_immediately);
					if (ret) {
						LOG_ERR("BCNA RC Config: Failed to apply CS "
							"configuration: %d",
							ret);
					} else if (start_immediately) {
						status_bitmap |= (1 << tech_id);
					}
				} else
#endif
				{
					LOG_ERR("BCNA RC Config: Unsupported ranging technology ID:"
						" 0x%02x",
						tech_id);
					return BT_GATT_ERR(BCNA_ERR_INVALID_VALUE);
				}
			}
			// Move to next technology configuration data
			ptr += tech_size;
			add_data_len -= tech_size;
		}
	} else {
		// Start/Stop: Process each supported technology using direct #ifdef optimization
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
		if (tech_bf & RT_TECH_BF_UWB) {
			// UWB technology handling
			int ret = 0;
			if (operation_callback) {
				ret = operation_callback(RT_TECH_ID_UWB);
			}
			if (!ret) {
				status_bitmap |= RT_TECH_BF_UWB;
				LOG_INF("%s UWB ranging", operation_name);
			} else {
				LOG_ERR("Failed to %s UWB ranging: %d", operation_name, ret);
			}
		}
#endif

#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
		if (tech_bf & RT_TECH_BF_CS) {
			RANGING_SECURITY_CHECK(conn);
			// CS technology handling
			int ret = 0;
			if (operation_callback) {
				ret = operation_callback(RT_TECH_ID_CS);
			}
			if (!ret) {
				status_bitmap |= RT_TECH_BF_CS;
				LOG_INF("%s CS ranging", operation_name);
			} else {
				LOG_ERR("Failed to %s CS ranging: %d", operation_name, ret);
			}
		}
#endif
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

// CS ranging core functions
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
