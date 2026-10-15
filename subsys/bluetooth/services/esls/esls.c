/**
 *******************************************************************************
 *
 * @file esls.c
 *
 * @brief Atmosic eletronic shelf label service
 *
 * Copyright (c) 2024-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include <zephyr/settings/settings.h>
#include <zephyr/smf.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/ead.h>
#if CONFIG_BT_OTS
#include <zephyr/bluetooth/services/ots.h>
#endif
#ifdef CONFIG_PSA_WANT_ALG_CCM
#include <psa/crypto.h>
#endif // CONFIG_PSA_WANT_ALG_CCM

#include "esls.h"
#include "esls_internal.h"
#include "app_work_q.h"

LOG_MODULE_REGISTER(bt_esls, CONFIG_BT_ESLS_LOG_LEVEL);

// centisecond to millisecond
#define CS_TO_MS(cs) (cs * 10)

// flags
#define ESLS_FLAG_ESL_ADDR_SET             1
#define ESLS_FLAG_AP_SYNC_KEY_MATERIAL_SET 2
#define ESLS_FLAG_ESL_RSP_KEY_MATERIAL_SET 4
#define ESLS_FLAG_ESL_CURR_ABS_TIME_SET    8
#define ESLS_FLAG_ALL_SET                                                                          \
	(ESLS_FLAG_ESL_ADDR_SET | ESLS_FLAG_AP_SYNC_KEY_MATERIAL_SET |                             \
	 ESLS_FLAG_ESL_RSP_KEY_MATERIAL_SET | ESLS_FLAG_ESL_CURR_ABS_TIME_SET)

// opcode offset
#define ESLS_OPCODE_OFFSET           0
// ESL ID offset
#define ESLS_ESL_ID_OFFSET           1
// sensor index offset
#define ESLS_READ_SENSOR_DATA_OFFSET 2
// display index offset
#define ESLS_DISPLAY_INDEX_OFFSET    2
// image index offset
#define ESLS_IMAGE_INDEX_OFFSET      3
// absolute time offset
#define ESLS_ABS_TIME_OFFSET         4
// LED index offset
#define ESLS_LED_INDEX_OFFSET        2
// LED absolute time index offset
#define ESLS_LED_ABS_TIME_OFFSET     13
// parameter offset
#define ESLS_PARAM_OFFSET            1
// parameter 0 offset
#define ESLS_PARAM0_OFFSET           1
// parameter 1 offset
#define ESLS_PARAM1_OFFSET           2
// opcode: 1 byte + ESL_ID (or rsp param): 1 byte
#define ESLS_CMD_RSP_MIN_LEN         2
// ESL Tag value
#define ADV_TYPE_ESL                 0x34
// ADV header length
#define ADV_HEADER_LEN               2
// ADV length field offset
#define ADV_LEN_OFFSET               0
// ADV type field offset
#define ADV_TYPE_OFFSET              1
// ADV type field size
#define ADV_TYPE_SIZE                1

// LED Control Bit_Off_Period offset in flashing pattern
#define LED_CONTROL_BIT_OFF_PERIOD_OFFSET 5
// LED Control Bit_On_Period offset in flashing pattern
#define LED_CONTROL_BIT_ON_PERIOD_OFFSET  6
// LED Control flashing pattern bit length
#define LED_CONTROL_PATTERN_BIT_LEN       40
// LED Control the unit of the on/off period
#define LED_CONTROL_PATTERN_ONOFF_UNIT_MS 2

// LED Control Return Repeat Type
#define ESLS_LED_CTRL_REPEAT_TYPE(repeat_dur) (repeat_dur & 0x0001)
// LED Control Return Repeat Duration
#define ESLS_LED_CTRL_REPEAT_DUR(repeat_dur)  (repeat_dur & 0xFE)

// According to ESL profile 5.3.1
#define ESLS_MAX_PLAYLOAD_LEN 48
// EAD header + randomizer + ESL header + ESL playload + MIC
#define ESLS_MAX_RSP_LEN                                                                           \
	(ADV_HEADER_LEN + BT_EAD_RANDOMIZER_SIZE + ADV_HEADER_LEN + ESLS_MAX_PLAYLOAD_LEN +        \
	 BT_EAD_MIC_SIZE)
// Group ID
#define ESLS_GROUP_ID(esl_addr) ((esl_addr & ESL_ADDR_GROUP_ID_MASK) >> 8)

// sensor information length for size type 16 bits
#define SENSOR_INFO_16_BIT_PAIR_LEN 3
// sensor information length for size type 32 bits
#define SENSOR_INFO_32_BIT_PAIR_LEN 5

// direct adv start parameter
#define DIRECT_START_DURATION_CS   0
// undirect adv start parameter
#define UNDIRECT_START_DURATION_CS 0
// skip number after a successful receive
#define PAST_SYNC_SKIP             0
// timeout for the periodic advertising sync
#define PAST_SYNC_TIMEOUT_CS       2000
// maximum absolute time: 48 days = 48 * 24 * 60 * 60 * 1000
#define ESLS_MAX_ABS_TIME_MS       4147200000

#ifdef CONFIG_PSA_WANT_ALG_CCM
// nonce size
#define BT_EAD_NONCE_SIZE 13
// CCM algorithm with the BT EAD MIC size
#define ESLS_CCM_ALG      PSA_ALG_AEAD_WITH_SHORTENED_TAG(PSA_ALG_CCM, BT_EAD_MIC_SIZE)
#endif

// ESLS LED Control Repeat Type
enum esls_led_control_repeat_type {
	ESLS_LED_CTRL_REPEAT_TYPE_NUM_OF_TIMES,
	ESLS_LED_CTRL_REPEAT_TYPE_TIME_DURATION,
};

struct esls_ctrl {
	struct smf_ctx ctx;
	struct bt_esls_init_param init_param;
	struct bt_le_ext_adv *adv_set;
	struct bt_conn *curr_conn;
	struct bt_le_per_adv_sync *pawr_sync;
#if CONFIG_BT_OTS
	struct bt_ots *ots;
#endif
	int64_t abs_time_anchor;
	bt_addr_le_t ass_addr;
	uint32_t esl_curr_abs_time;
	uint8_t ap_sync_key_material[AP_SYNC_KEY_MATERIAL_LEN];
	uint8_t esl_rsp_key_material[ESL_RSP_KEY_MATERIAL_LEN];
	bt_gatt_complete_func_t func;
	uint16_t esl_addr;
	uint16_t basic_state;
	enum esls_evt evt;
	uint8_t config_flag;
	bool is_boned;
};

// TLV format
struct esls_rsp_tlv {
	uint8_t data[ESLS_MAX_PLAYLOAD_LEN];
	uint8_t len;
};

struct esls_start_adv_work_info {
	struct k_work work;
	bool is_bonded;
};

// PAwR response
struct esls_pawr_rsp {
	uint8_t ead_adv_len;
	uint8_t ead_adv_tag;
	uint8_t rand[BT_EAD_RANDOMIZER_SIZE];
	uint8_t esl_adv_len;
	uint8_t esl_adv_tag;
	uint8_t esl_playload[1];
} __packed;

// ESL payload offsert in PAwR response structure
#define ESLS_PAWR_HEADER_LEN offsetof(struct esls_pawr_rsp, esl_playload)

// prototype
static void esls_unassociated_entry(void *obj);
static enum smf_state_result esls_unassociated_run(void *obj);
static void esls_unassociated_exit(void *obj);
static void esls_configuring_entry(void *obj);
static enum smf_state_result esls_configuring_run(void *obj);
static void esls_configuring_exit(void *obj);
static void esls_synchronized_entry(void *obj);
static enum smf_state_result esls_synchronized_run(void *obj);
static void esls_synchronized_exit(void *obj);
static void esls_updating_entry(void *obj);
static enum smf_state_result esls_updating_run(void *obj);
static void esls_updating_exit(void *obj);
static void esls_unsynchronized_entry(void *obj);
static enum smf_state_result esls_unsynchronized_run(void *obj);
static void esls_unsynchronized_exit(void *obj);

static const struct smf_state esls_states[ESLS_STATE_IDX_MAX] = {
	[ESLS_STATE_UNASSOCIATED] = SMF_CREATE_STATE(esls_unassociated_entry, esls_unassociated_run,
						     esls_unassociated_exit, NULL, NULL),
	[ESLS_STATE_CONFIGURING] = SMF_CREATE_STATE(esls_configuring_entry, esls_configuring_run,
						    esls_configuring_exit, NULL, NULL),
	[ESLS_STATE_SYNCHRONIZED] = SMF_CREATE_STATE(esls_synchronized_entry, esls_synchronized_run,
						     esls_synchronized_exit, NULL, NULL),
	[ESLS_STATE_UPDATING] = SMF_CREATE_STATE(esls_updating_entry, esls_updating_run,
						 esls_updating_exit, NULL, NULL),
	[ESLS_STATE_UNSYNCHRONIZED] =
		SMF_CREATE_STATE(esls_unsynchronized_entry, esls_unsynchronized_run,
				 esls_unsynchronized_exit, NULL, NULL),
};

static const struct bt_data scan_data[] = {
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, BT_UUID_16_ENCODE(BT_UUID_ESLS_VAL)),
	BT_DATA_BYTES(BT_DATA_GAP_APPEARANCE, BT_UUID_16_ENCODE(CONFIG_BT_DEVICE_APPEARANCE)),
	BT_DATA(BT_DATA_NAME_COMPLETE, CONFIG_BT_DEVICE_NAME, sizeof(CONFIG_BT_DEVICE_NAME) - 1),
};

static struct bt_data adv_data[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, BT_UUID_16_ENCODE(BT_UUID_ESLS_VAL)),
#if CONFIG_BT_ESLS_ADV_MANU_DATA_MAX
	BT_DATA(BT_DATA_MANUFACTURER_DATA, NULL, 0),
#endif
};
static size_t ad_len = ARRAY_SIZE(adv_data);

#if CONFIG_BT_ESLS_IMAGE_NUM > 0
K_THREAD_STACK_DEFINE(esls_img_stack_area, CONFIG_ESLS_IMG_WQ_STACK_SIZE);
static struct k_work_q esls_image_wq;

static uint8_t created_obj_cnt;
#endif

#if CONFIG_BT_ESLS_LED_NUM > 0
K_THREAD_STACK_DEFINE(esls_led_stack_area, CONFIG_ESLS_LED_WQ_STACK_SIZE);
static struct k_work_q esls_led_wq;

static void esls_cancel_led_control(uint8_t led_idx);
static void esls_led_basic_state_update(void);
#endif

static struct k_work factory_reset_work;
static struct esls_ctrl esls;
static struct esls_start_adv_work_info esls_start_adv_work;
NET_BUF_SIMPLE_DEFINE_STATIC(esls_rsp_buf, ESLS_MAX_RSP_LEN);

#ifdef CONFIG_PSA_WANT_ALG_CCM
static uint8_t const bt_ead_aad = 0xEA;
static psa_key_id_t dec_key_id = PSA_KEY_ID_NULL;
static psa_key_id_t enc_key_id = PSA_KEY_ID_NULL;
// Pre-generated randomizer for the next PAwR response so the BLE RX thread
// never blocks on psa_generate_random() during PAwR event processing.
static uint8_t cached_rand[BT_EAD_RANDOMIZER_SIZE];
static bool cached_rand_valid;

static int esls_import_aes_key(psa_key_id_t *key_id, const uint8_t *key, psa_key_usage_t usage)
{
	if (*key_id != PSA_KEY_ID_NULL) {
		psa_destroy_key(*key_id);
		*key_id = PSA_KEY_ID_NULL;
	}
	psa_key_attributes_t attr = PSA_KEY_ATTRIBUTES_INIT;
	psa_set_key_type(&attr, PSA_KEY_TYPE_AES);
	psa_set_key_bits(&attr, BT_EAD_KEY_SIZE * 8);
	psa_set_key_usage_flags(&attr, usage);
	psa_set_key_lifetime(&attr, PSA_KEY_LIFETIME_VOLATILE);
	psa_set_key_algorithm(
		&attr, PSA_ALG_AEAD_WITH_AT_LEAST_THIS_LENGTH_TAG(PSA_ALG_CCM, BT_EAD_MIC_SIZE));
	psa_status_t status = psa_import_key(&attr, key, BT_EAD_KEY_SIZE, key_id);
	psa_reset_key_attributes(&attr);
	return (status == PSA_SUCCESS) ? 0 : -EIO;
}
#endif

#if defined(CONFIG_AUTO_TEST) || !defined(CONFIG_PM)
static bool is_test_end;

bool test_end_check(void)
{
	return is_test_end;
}

static void test_end_set(bool is_end)
{
	is_test_end = is_end;
}
#endif

static bool esl_service_needed_bit;

static void esls_run_state(enum esls_evt evt)
{
	esls.evt = evt;
	smf_run_state(SMF_CTX(&esls));
}

static void esls_timer_expire(struct k_work *work)
{
	LOG_INF("%s", __func__);

	esls_run_state(ESLS_EVT_STATE_TIMEOUT);
}

K_WORK_DELAYABLE_DEFINE(esls_idle_timer_work, esls_timer_expire);

static void esls_found_bond(struct bt_bond_info const *info, void *data)
{
	char addr[BT_ADDR_LE_STR_LEN];

	esls.is_boned = true;
	bt_addr_le_to_str(&info->addr, addr, sizeof(addr));
	LOG_INF("%s remote:%s", __func__, addr);
}

static void esls_update_bond_info(void)
{
	LOG_INF("%s", __func__);

	// restore bonding initialization state, set is_boned = false
	esls.is_boned = false;

	// check pairing or reconnecting
	bt_foreach_bond(BT_ID_DEFAULT, esls_found_bond, NULL);
}

static void esls_adv_sent_cb(struct bt_le_ext_adv *adv, struct bt_le_ext_adv_sent_info *info)
{
	LOG_INF("%s", __func__);
}

static struct bt_le_ext_adv_cb const adv_callbacks = {
	.sent = esls_adv_sent_cb,
};

#if CONFIG_BT_ESLS_ADV_MANU_DATA_MAX
static void esls_update_adv_manu_data(void)
{
	for (uint8_t i = 0; i < ARRAY_SIZE(adv_data); i++) {
		if (adv_data[i].type == BT_DATA_MANUFACTURER_DATA) {
			if (!esls.init_param.app_adv_data || !esls.init_param.app_adv_len) {
				ad_len = ARRAY_SIZE(adv_data) - 1;
				adv_data[i].data_len = 0;
				LOG_WRN("%s: Error - No app data in init_param", __func__);
			} else {
				ad_len = ARRAY_SIZE(adv_data);
				adv_data[i].data_len = esls.init_param.app_adv_len;
				adv_data[i].data = esls.init_param.app_adv_data;
			}
			return;
		}
	}
	LOG_ERR("%s: Error - no manufacure in adv data", __func__);
}
#endif

static int esls_set_adv_data(bool bonded)
{
	struct bt_data const *sd = bonded ? NULL : scan_data;
	size_t sd_len = bonded ? 0 : ARRAY_SIZE(scan_data);

	int err = bt_le_ext_adv_set_data(esls.adv_set, adv_data, ad_len, sd, sd_len);
	if (err) {
		LOG_ERR("Failed to set adv data:%d", err);
	}
	return err;
}

static int esls_create_adv(bool bonded)
{
	LOG_INF("create adv bonded:%u", bonded);

	int err;
	struct bt_le_adv_param adv_param;
#ifdef DIRECT_ADV_SUPPORT
	if (bonded) {
		adv_param = *BT_LE_ADV_CONN_DIR_LOW_DUTY(&esls.ass_addr);
	} else
#endif
	{
		adv_param = *BT_LE_ADV_CONN_FAST_2;
		adv_param.options |= BT_LE_ADV_OPT_SCANNABLE;
	}
	if (esls.adv_set) {
		err = bt_le_ext_adv_update_param(esls.adv_set, &adv_param);
	} else {
		err = bt_le_ext_adv_create(&adv_param, &adv_callbacks, &esls.adv_set);
	}
	if (err) {
		LOG_ERR("%s err:%d", __func__, err);
		return err;
	}
	return esls_set_adv_data(bonded);
}

static void esls_start_adv(bool bonded)
{
	if (!esls.adv_set) {
		LOG_ERR("%s null adv set", __func__);
	}
	struct bt_le_ext_adv_start_param ext_adv_start_param = {
		.timeout = bonded ? DIRECT_START_DURATION_CS : UNDIRECT_START_DURATION_CS,
	};

	int err = bt_le_ext_adv_start(esls.adv_set, &ext_adv_start_param);
	if (err) {
		LOG_ERR("Failed to start adv %d", err);
		return;
	}
#if defined(CONFIG_AUTO_TEST) || !defined(CONFIG_PM)
	test_end_set(true);
#endif
	LOG_INF("Adv Start");
#ifndef CONFIG_LOG
	printk("Adv Start\n");
#endif
}

static void esls_stop_adv(void)
{
	if (!esls.adv_set) {
		LOG_ERR("%s null adv set", __func__);
	}

	int err = bt_le_ext_adv_stop(esls.adv_set);
	if (err) {
		LOG_ERR("Failed to stop adv %d", err);
		return;
	}
}

static bool esls_is_configured_char(void)
{
	LOG_INF("%s: flags:%#x %#x %#x %#x %u", __func__, esls.config_flag, esls.esl_addr,
		esls.ap_sync_key_material[0], esls.esl_rsp_key_material[0], esls.esl_curr_abs_time);
	return (esls.config_flag == ESLS_FLAG_ALL_SET);
}

static bool esls_is_configured(void)
{
	return (esls_is_configured_char() && esls.is_boned);
}

static void esls_disconnect(void)
{
	if (!esls.curr_conn) {
		return;
	}
	bt_conn_disconnect(esls.curr_conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
}

static void esls_connected(struct bt_conn *conn, uint8_t err)
{
	char addr[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));
	if (err) {
		LOG_ERR("Failed to connect to %s (%u)", addr, err);
		esls_run_state(ESLS_EVT_DISCONNECTED);
		return;
	}
	LOG_INF("Connected %s", addr);
	esls.curr_conn = conn;
	int error = bt_conn_set_security(conn, BT_SECURITY_L2);
	if (error) {
		LOG_ERR("Failed to set security %d", error);
	}
}

static void esls_disconnected(struct bt_conn *conn, uint8_t reason)
{
	char addr[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));
	LOG_INF("Disconnected %s reason:%#x", addr, reason);
	esls.curr_conn = NULL;
	esls_update_bond_info();
	esls_run_state(ESLS_EVT_DISCONNECTED);
}

static void esls_security_changed(struct bt_conn *conn, bt_security_t level,
				  enum bt_security_err err)
{
	char addr[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	if (err || (level < BT_SECURITY_L2)) {
		LOG_ERR("Security failed:%s level:%u err:%d", addr, level, err);
		if (err == BT_SECURITY_ERR_PIN_OR_KEY_MISSING) {
			struct bt_conn_info info;
			bt_conn_get_info(conn, &info);
			bt_unpair(info.id, bt_conn_get_dst(conn));
		} else {
			esls_disconnect();
		}
		return;
	}
	esls_run_state(ESLS_EVT_ENCRYPTED);

	LOG_INF("Security changed:%s level:%u", addr, level);
}

static void esls_le_param_updated(struct bt_conn *conn, uint16_t interval, uint16_t latency,
				  uint16_t timeout)
{
	LOG_INF("interval:%u latency:%u timeout:%u", interval, latency, timeout);
}

BT_CONN_CB_DEFINE(conn_callbacks) = {
	.connected = esls_connected,
	.disconnected = esls_disconnected,
	.security_changed = esls_security_changed,
	.le_param_updated = esls_le_param_updated,
};

static bool esls_stop_pawr_sync(void)
{
	LOG_INF("%s", __func__);

	if (!esls.pawr_sync) {
		return false;
	}
	int err = bt_le_per_adv_sync_transfer_unsubscribe(NULL);
	if (err) {
		LOG_ERR("PAST unsub err:%d", err);
	}
	// avoid term callback
	struct bt_le_per_adv_sync *sync = esls.pawr_sync;
	esls.pawr_sync = NULL;
	err = bt_le_per_adv_sync_delete(sync);
	if (err) {
		LOG_ERR("PA sync del err:%d", err);
	}
	return true;
}

#if CONFIG_BT_ESLS_DISPLAY_NUM > 0
static struct esls_display_wrok_info {
	struct k_work_delayable work;
	uint32_t abs_time;
	uint8_t display_idx;
	uint8_t img_idx;
} esls_display_work[CONFIG_BT_ESLS_DISPLAY_NUM];
#endif

#if CONFIG_BT_ESLS_LED_NUM > 0
struct bt_esls_led_control_info {
	uint8_t led_idx;
	uint8_t color_brightness;
	uint8_t flashing_pattern[7];
	uint16_t repeat_dur_info;
	uint32_t abs_time;
} __packed;

static struct esls_led_wrok_info {
	struct k_work_delayable work;
	bool led_active;
	uint8_t pattern_start_idx;
	uint32_t repeat_stop_abs_time;
	struct bt_esls_led_control_info led_info;
} esls_led_work[CONFIG_BT_ESLS_LED_NUM];
#endif

static void esls_prepare_rsp_buf(struct esls_rsp_tlv *tlv)
{
	LOG_DBG("%s buf_len:%u", __func__, esls_rsp_buf.len);
	switch (tlv->data[ESLS_OPCODE_OFFSET]) {
	case ESLS_RSP_OPCODE_BASIC_STATE: {
		tlv->len = 3;
#if CONFIG_BT_ESLS_LED_NUM > 0
		esls_led_basic_state_update();
#endif
		memcpy(&tlv->data[ESLS_PARAM0_OFFSET], &esls.basic_state, sizeof(esls.basic_state));
	} break;
#if CONFIG_BT_ESLS_SENSOR_NUM > 0
	case ESLS_RSP_OPCODE_SENSOR_VALUE: {
		int err = esls.init_param.sensor_read_data(
			tlv->data[ESLS_PARAM0_OFFSET], &tlv->data[ESLS_PARAM1_OFFSET], &tlv->len);
		if (err) {
			tlv->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_ERROR;
			if (err == -EBUSY) {
				tlv->data[ESLS_PARAM0_OFFSET] = ESLS_ERR_RETRY;
			} else {
				tlv->data[ESLS_PARAM0_OFFSET] = ESLS_ERR_UNSPECIFIC;
			}
			tlv->len = ESLS_CMD_RSP_MIN_LEN;
			break;
		}
		tlv->data[ESLS_OPCODE_OFFSET] |= (tlv->len << 4);
		tlv->len += ESLS_CMD_RSP_MIN_LEN;
	} break;
#endif
#if CONFIG_BT_ESLS_IMAGE_NUM > 0
	case ESLS_RSP_OPCODE_DISPLAY_STATE: {
		tlv->len = 3;
	} break;
#endif
#if CONFIG_BT_ESLS_LED_NUM > 0
	case ESLS_RSP_OPCODE_LED_STATE: {
		tlv->len = 2;
	} break;
#endif
	default: {
		LOG_ERR("unexp opcode:%#x", tlv->data[ESLS_OPCODE_OFFSET]);
	} break;
	}
}

static void esls_notify_cmp_cb(struct bt_conn *conn, void *user_data)
{
	esls.func = NULL;
	bt_esls_unassociate();
	smf_set_state(SMF_CTX(&esls), &esls_states[ESLS_STATE_UNASSOCIATED]);
}

static uint32_t esls_get_abs_time(void)
{
	return (uint32_t)(k_uptime_get_32() - esls.abs_time_anchor);
}

static void esls_update_abs_time_anchor(uint32_t abs_time)
{
	esls.abs_time_anchor = k_uptime_get_32() - abs_time;
#ifdef CONFIG_ESL_PTS
	LOG_WRN("esls.abs_time_anchor: %" PRIu64 " abs_time: %" PRIu32, esls.abs_time_anchor,
		esls_get_abs_time());
#endif
}

#if CONFIG_BT_ESLS_DISPLAY_NUM > 0
static void esls_pending_display_update(void)
{
	for (uint8_t i = 0; i < CONFIG_BT_ESLS_DISPLAY_NUM; i++) {
		if (esls_display_work[i].abs_time) {
			return;
		}
	}
	esls.basic_state &= ~ESLS_BASIC_STATE_PENDING_DISPLAY_UPDATE;
}

static void esls_cancel_display(uint8_t display_idx)
{
	k_work_cancel_delayable(&esls_display_work[display_idx].work);
	esls_display_work[display_idx].abs_time = 0;
	esls_pending_display_update();
}
#endif

static bool esls_cmd_parser(const uint8_t *cmd, uint16_t len, bool is_pawr,
			    struct esls_rsp_tlv *rsp_buf)
{
	uint8_t esl_id = cmd[ESLS_ESL_ID_OFFSET];
	rsp_buf->len = 2;
	if ((esl_id != (esls.esl_addr & ESL_ADDR_ID_MASK)) &&
	    (esl_id != ESL_ADDR_ID_BROADCAST_ADDR)) {
		if (is_pawr) {
			rsp_buf->len = 0;
			// does not need response for unexpected ESL ID
			return false;
		}
		rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_ERROR;
		rsp_buf->data[ESLS_PARAM0_OFFSET] = ESLS_ERR_INVALID_PARAM;
		return true;
	}
	bool wo_rsp = (esl_id == ESL_ADDR_ID_BROADCAST_ADDR);

	uint8_t opcode = cmd[ESLS_OPCODE_OFFSET];
	LOG_DBG("%s cmd:%#x", __func__, opcode);
	// cmd handler
	switch (opcode) {
	case ESLS_OPCODE_PING: {
		LOG_INF("current time: %u", esls_get_abs_time());
		rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_BASIC_STATE;
	} break;
	case ESLS_OPCODE_UNASSOCIATE: {
		esls.func = esls_notify_cmp_cb;
		esls.basic_state &= ~ESLS_BASIC_STATE_SYNCHRONIZED;
		rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_BASIC_STATE;
	} break;
	case ESLS_OPCODE_SERVICE_RESET: {
		if (!esl_service_needed_bit) {
			esls.basic_state &= ~ESLS_BASIC_STATE_SERVICE_NEEDED;
		}
		rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_BASIC_STATE;
	} break;
	case ESLS_OPCODE_FACTORY_RESET: {
		if ((SMF_CTX(&esls)->current) == &esls_states[ESLS_STATE_SYNCHRONIZED]) {
			rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_ERROR;
			rsp_buf->data[ESLS_PARAM0_OFFSET] = ESLS_ERR_INVALID_STATE;
			break;
		}
		esls.basic_state = 0;
		bt_esls_service_needed_bit_set(esl_service_needed_bit);
		atm_work_submit_to_app_work_q(&factory_reset_work);
		return false;
	} break;
	case ESLS_OPCODE_UPDATE_COMPLETE: {
		if (!esls_is_configured_char()) {
			esls_disconnect();
			return false;
		}
		if ((SMF_CTX(&esls)->current) == &esls_states[ESLS_STATE_SYNCHRONIZED]) {
			return false;
		}
		esls_run_state(ESLS_EVT_UPDATE_COMPLETE);
		return false;
	} break;
#if CONFIG_BT_ESLS_SENSOR_NUM > 0
	case ESLS_OPCODE_READ_SENSOR_DATA: {
		uint8_t sensor_idx = cmd[ESLS_READ_SENSOR_DATA_OFFSET];
		if (sensor_idx >= CONFIG_BT_ESLS_SENSOR_NUM) {
			rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_ERROR;
			rsp_buf->data[ESLS_PARAM0_OFFSET] = ESLS_ERR_INVALID_PARAM;
			break;
		}
		rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_SENSOR_VALUE;
		rsp_buf->data[ESLS_PARAM0_OFFSET] = sensor_idx;
	} break;
#endif
#if CONFIG_BT_ESLS_IMAGE_NUM > 0
	case ESLS_OPCODE_DISPLAY_IMAGE:
	case ESLS_OPCODE_DISPLAY_TIMED_IMAGE: {
		uint8_t image_idx = cmd[ESLS_IMAGE_INDEX_OFFSET];
#ifdef CONFIG_ESL_PTS
		if (image_idx >= CONFIG_BT_ESLS_IMAGE_NUM) {
#else
		if (image_idx > CONFIG_BT_ESLS_IMAGE_NUM) {
#endif
			rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_ERROR;
			rsp_buf->data[ESLS_PARAM0_OFFSET] = ESLS_ERR_INVALID_IMAGE_IDX;
			break;
		}
		uint8_t display_idx = cmd[ESLS_DISPLAY_INDEX_OFFSET];
		if (display_idx >= CONFIG_BT_ESLS_DISPLAY_NUM) {
			rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_ERROR;
			rsp_buf->data[ESLS_PARAM0_OFFSET] = ESLS_ERR_INVALID_PARAM;
			break;
		}
		if (image_idx != CONFIG_BT_ESLS_IMAGE_NUM) {
			uint16_t img_size;
			esls.init_param.read_image_size(image_idx, &img_size);
			if (!img_size) {
				rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_ERROR;
				rsp_buf->data[ESLS_PARAM0_OFFSET] = ESLS_ERR_INVALID_IMAGE_IDX;
				break;
			}
		}
		uint32_t delay_time_ms;
		if (opcode == ESLS_OPCODE_DISPLAY_TIMED_IMAGE) {
			uint32_t abs_time = sys_get_le32(cmd + ESLS_ABS_TIME_OFFSET);
			if (!abs_time) {
				esls_cancel_display(display_idx);
				rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_DISPLAY_STATE;
				rsp_buf->data[ESLS_PARAM0_OFFSET] = display_idx;
				rsp_buf->data[ESLS_PARAM1_OFFSET] = image_idx;
				break;
			} else {
				delay_time_ms = abs_time - esls_get_abs_time();
				LOG_INF("current time: %u delay time: %u", esls_get_abs_time(),
					delay_time_ms);
				if (delay_time_ms > ESLS_MAX_ABS_TIME_MS) {
					rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_ERROR;
					rsp_buf->data[ESLS_PARAM0_OFFSET] = ESLS_IMPL_ABS_TIME;
					break;
				}
				if (esls_display_work[display_idx].abs_time == abs_time) {
					k_work_cancel_delayable(
						&esls_display_work[display_idx].work);
				} else if (esls_display_work[display_idx].abs_time) {
					rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_ERROR;
					rsp_buf->data[ESLS_PARAM0_OFFSET] = ESLS_ERR_QUEUE_FULL;
					break;
				}
				esls.basic_state |= ESLS_BASIC_STATE_PENDING_DISPLAY_UPDATE;
			}
			esls_display_work[display_idx].abs_time = abs_time;
		} else {
			delay_time_ms = 0;
		}
		esls_display_work[display_idx].img_idx = image_idx;
		rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_DISPLAY_STATE;
		rsp_buf->data[ESLS_PARAM0_OFFSET] = display_idx;
		rsp_buf->data[ESLS_PARAM1_OFFSET] = image_idx;
		k_work_reschedule_for_queue(&esls_image_wq, &esls_display_work[display_idx].work,
					    K_MSEC(delay_time_ms));
	} break;
	case ESLS_OPCODE_REFRESH_DISPLAY: {
		uint8_t display_idx = cmd[ESLS_DISPLAY_INDEX_OFFSET];
		if (display_idx >= CONFIG_BT_ESLS_DISPLAY_NUM) {
			rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_ERROR;
			rsp_buf->data[ESLS_PARAM0_OFFSET] = ESLS_ERR_INVALID_PARAM;
			break;
		}
#ifdef CONFIG_ESL_PTS
		if (esls_display_work[display_idx].img_idx == CONFIG_BT_ESLS_IMAGE_NUM) {
			// There is no image being displayed on the display
			rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_ERROR;
			rsp_buf->data[ESLS_PARAM0_OFFSET] = ESLS_ERR_INVALID_STATE;
			break;
		}
#endif
		rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_DISPLAY_STATE;
		rsp_buf->data[ESLS_PARAM0_OFFSET] = display_idx;
		rsp_buf->data[ESLS_PARAM1_OFFSET] = esls_display_work[display_idx].img_idx;
		k_work_reschedule_for_queue(&esls_image_wq, &esls_display_work[display_idx].work,
					    K_NO_WAIT);
	} break;
#endif
#if CONFIG_BT_ESLS_LED_NUM > 0
	case ESLS_OPCODE_LED_CONTROL:
	case ESLS_OPCODE_LED_TIMED_CONTROL: {
		uint8_t led_idx = cmd[ESLS_LED_INDEX_OFFSET];
		if (led_idx >= CONFIG_BT_ESLS_LED_NUM) {
			rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_ERROR;
			rsp_buf->data[ESLS_PARAM0_OFFSET] = ESLS_ERR_INVALID_PARAM;
			break;
		}
		rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_LED_STATE;
		rsp_buf->data[ESLS_PARAM0_OFFSET] = led_idx;

		uint32_t delay_time_ms;
		if (opcode == ESLS_OPCODE_LED_TIMED_CONTROL) {
			uint32_t abs_time = sys_get_le32(cmd + ESLS_LED_ABS_TIME_OFFSET);
			delay_time_ms = abs_time - esls_get_abs_time();
			LOG_INF("current time: %u delay time: %u", esls_get_abs_time(),
				delay_time_ms);

			if (!abs_time) {
				// The pending LED Timed Control command shall be deleted
				// update basic state
				esls_cancel_led_control(led_idx);
				break;
			} else {
				if (delay_time_ms > ESLS_MAX_ABS_TIME_MS) {
					rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_ERROR;
					rsp_buf->data[ESLS_PARAM0_OFFSET] = ESLS_IMPL_ABS_TIME;
					break;
				}
				if (esls_led_work[led_idx].led_info.abs_time == abs_time) {
					// The newly received command shall replace the old
					// pending command
					k_work_cancel_delayable(&esls_led_work[led_idx].work);
				} else if (esls_led_work[led_idx].led_info.abs_time) {
					// It is not permitted to have more than one LED Timed
					// Control command pending.
					rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_ERROR;
					rsp_buf->data[ESLS_PARAM0_OFFSET] = ESLS_ERR_QUEUE_FULL;
					break;
				}
			}
		} else {
			// The new command shall immediately supersede the previous
			// command, and the effect of the previous command related to
			// controlling the same LED shall then be terminated.
			esls_cancel_led_control(led_idx);
			delay_time_ms = 0;
		}

		esls_led_work[led_idx].repeat_stop_abs_time = 0;
		esls_led_work[led_idx].pattern_start_idx = 0;
		esls_led_work[led_idx].led_info.abs_time = 0;
		memcpy(&esls_led_work[led_idx].led_info, cmd + ESLS_LED_INDEX_OFFSET,
		       len - ESLS_LED_INDEX_OFFSET);

		k_work_reschedule_for_queue(&esls_led_wq, &esls_led_work[led_idx].work,
					    K_MSEC(delay_time_ms));
	} break;
#endif
	default: {
		LOG_WRN("unsupp opcode:%#x", opcode);
		rsp_buf->data[ESLS_OPCODE_OFFSET] = ESLS_RSP_OPCODE_ERROR;
		rsp_buf->data[ESLS_PARAM0_OFFSET] = ESLS_ERR_INVALID_OPCODE;
	} break;
	}
	if (wo_rsp) {
		LOG_INF("%s wo_rsp", __func__);
		return false;
	}
	esls_prepare_rsp_buf(rsp_buf);
	return true;
}

static void esls_synced(struct bt_le_per_adv_sync *sync,
			struct bt_le_per_adv_sync_synced_info *info)
{
	LOG_INF("%s", __func__);

#define NUM_SUBEVT 1
	uint8_t subevents[NUM_SUBEVT] = {ESLS_GROUP_ID(esls.esl_addr)};
	struct bt_le_per_adv_sync_subevent_params params;
	params.properties = 0;
	params.num_subevents = NUM_SUBEVT;
	params.subevents = subevents;
	int err = bt_le_per_adv_sync_subevent(sync, &params);
	if (err) {
		LOG_ERR("%s err:%d", __func__, err);
	}
	esls.pawr_sync = sync;
	esls_run_state(ESLS_EVT_PAST_SYNCED);
}

static void esls_term(struct bt_le_per_adv_sync *sync,
		      const struct bt_le_per_adv_sync_term_info *info)
{
	LOG_INF("%s", __func__);

	if (esls_stop_pawr_sync()) {
		esls_run_state(ESLS_EVT_PA_SYNC_TERM);
	}
}

static int esls_encrypt(struct esls_pawr_rsp *rsp, uint16_t esl_playload_len)
{
#ifdef CONFIG_PSA_WANT_ALG_CCM
	uint8_t nonce[BT_EAD_NONCE_SIZE];
	psa_status_t status;
	// Use the randomizer pre-generated at the end of the previous response to
	// skip psa_generate_random() on the critical path. Fall back to a
	// synchronous call only if the cache is empty (first encrypt, or a
	// previous prime failed).
	if (cached_rand_valid) {
		memcpy(nonce, cached_rand, BT_EAD_RANDOMIZER_SIZE);
		cached_rand_valid = false;
	} else {
		status = psa_generate_random(nonce, BT_EAD_RANDOMIZER_SIZE);
		if (status != PSA_SUCCESS) {
			LOG_ERR("rand %d", status);
			return -EIO;
		}
	}
// This value is used to set the directionBit of the CCM nonce to the MSB of the
// Randomizer field (see Supplement to the Bluetooth Core Specification v11,
// Part A 1.23.3)
#define BT_EAD_RANDOMIZER_DIRECTION_BIT 7
#define RAND_MSB_OFFSET                 4
	nonce[RAND_MSB_OFFSET] |= 1 << BT_EAD_RANDOMIZER_DIRECTION_BIT;
	memcpy(&nonce[BT_EAD_RANDOMIZER_SIZE], &esls.esl_rsp_key_material[BT_EAD_KEY_SIZE],
	       BT_EAD_IV_SIZE);
	size_t plaintext_len = ADV_HEADER_LEN + esl_playload_len;
	size_t output_len;
	status = psa_aead_encrypt(enc_key_id, ESLS_CCM_ALG, nonce, BT_EAD_NONCE_SIZE, &bt_ead_aad,
				  sizeof(bt_ead_aad), &rsp->esl_adv_len, plaintext_len,
				  &rsp->esl_adv_len, plaintext_len + BT_EAD_MIC_SIZE, &output_len);
	if (status != PSA_SUCCESS) {
		LOG_ERR("psa_aead_encrypt %d", status);
		return -EIO;
	}
	memcpy(rsp->rand, nonce, BT_EAD_RANDOMIZER_SIZE);
	return 0;
#else
	return bt_ead_encrypt(esls.esl_rsp_key_material,
			      &esls.esl_rsp_key_material[BT_EAD_KEY_SIZE], &rsp->esl_adv_len,
			      esl_playload_len + ADV_HEADER_LEN, rsp->rand);
#endif
}

static int esls_decrypt(struct net_buf_simple *buf, uint8_t *decrypted_text)
{
#ifdef CONFIG_PSA_WANT_ALG_CCM
	uint8_t nonce[BT_EAD_NONCE_SIZE];
	memcpy(nonce, &buf->data[ADV_HEADER_LEN], BT_EAD_RANDOMIZER_SIZE);
	memcpy(&nonce[BT_EAD_RANDOMIZER_SIZE], &esls.ap_sync_key_material[BT_EAD_KEY_SIZE],
	       BT_EAD_IV_SIZE);
#define ENCRYPT_DATA_SIZE(pawr_len)                                                                \
	(pawr_len - ADV_HEADER_LEN - BT_EAD_RANDOMIZER_SIZE - BT_EAD_MIC_SIZE)
	size_t encrypt_data_len = ENCRYPT_DATA_SIZE(buf->len);
	size_t output_len;
	psa_status_t status = psa_aead_decrypt(
		dec_key_id, ESLS_CCM_ALG, nonce, BT_EAD_NONCE_SIZE, &bt_ead_aad, sizeof(bt_ead_aad),
		&buf->data[ADV_HEADER_LEN + BT_EAD_RANDOMIZER_SIZE],
		encrypt_data_len + BT_EAD_MIC_SIZE, decrypted_text, encrypt_data_len, &output_len);
	if (status != PSA_SUCCESS) {
		return -EIO;
	}
	return 0;
#else
	return bt_ead_decrypt(
		esls.ap_sync_key_material, &esls.ap_sync_key_material[BT_EAD_KEY_SIZE],
		&buf->data[ADV_HEADER_LEN], buf->len - ADV_HEADER_LEN, decrypted_text);
#endif
}

static void esls_send_pawr_rsp(const struct bt_le_per_adv_sync_recv_info *info, uint8_t rsp_slot)
{
	LOG_DBG("%s cnt%u subevt:%u slot:%u len:%u", __func__, info->periodic_event_counter,
		info->subevent, rsp_slot, esls_rsp_buf.len);

	uint16_t esl_playload_len = esls_rsp_buf.len - ESLS_PAWR_HEADER_LEN;
	struct esls_pawr_rsp *rsp = (struct esls_pawr_rsp *)esls_rsp_buf.data;
	rsp->ead_adv_len = esls_rsp_buf.len + BT_EAD_MIC_SIZE - ADV_TYPE_SIZE;
	rsp->ead_adv_tag = BT_DATA_ENCRYPTED_AD_DATA;
	rsp->esl_adv_len = esl_playload_len + ADV_TYPE_SIZE;
	rsp->esl_adv_tag = ADV_TYPE_ESL;

	uint32_t s_time = k_cycle_get_32();
	int err = esls_encrypt(rsp, esl_playload_len);
	uint64_t delta = k_cycle_get_32() - s_time;
	delta = k_cyc_to_ns_floor64(delta);
	LOG_INF("encrypt: %" PRIu64 " ns for len:%u", delta, esl_playload_len + ADV_HEADER_LEN);
	if (err) {
		LOG_ERR("encrypt err:%d", err);
	}
	esls_rsp_buf.len += BT_EAD_MIC_SIZE;
	struct bt_le_per_adv_response_params params = {
		.request_event = info->periodic_event_counter,
		.request_subevent = info->subevent,
		.response_subevent = info->subevent,
		.response_slot = rsp_slot,
	};

	err = bt_le_per_adv_set_response_data(esls.pawr_sync, &params, &esls_rsp_buf);
	if (err) {
		LOG_ERR("pawr rsp err:%d", err);
	}
#ifdef CONFIG_PSA_WANT_ALG_CCM
	cached_rand_valid = (psa_generate_random(cached_rand, sizeof(cached_rand)) == PSA_SUCCESS);
#endif
}

static void esls_recv(struct bt_le_per_adv_sync *sync,
		      const struct bt_le_per_adv_sync_recv_info *info, struct net_buf_simple *buf)
{
	if (buf->len) {
		LOG_INF("%s len:%u", __func__, buf->len);
	}

	if (esls.pawr_sync != sync) {
		LOG_ERR("NOT SAME SYNC");
		return;
	}

	if ((SMF_CTX(&esls)->current) != &esls_states[ESLS_STATE_SYNCHRONIZED]) {
		LOG_INF("Ignore ESL sync data when not synchronized");
		return;
	}
#define ENCRTYPTED_DATA_MAX_LEN 59
	// |ADV payload                                                            |
	// |Len(1)|Type(1)|Encrypted Data                                          |
	//                |Rand(5)|Decrypted Data                           |MIC(4)|
	//                        |Len(1)|ESL Tag(1)|ESL Payload            |
	//                                          |G_ID/RFU(1)|TLV|TLV|.. |
	if (buf->len <= ADV_HEADER_LEN || buf->data[ADV_TYPE_OFFSET] != BT_DATA_ENCRYPTED_AD_DATA) {
		if (buf->len) {
			LOG_DBG("%s len:%u adv_type:%#x", __func__, buf->len,
				buf->data[ADV_TYPE_OFFSET]);
		}
		return;
	}
	LOG_DBG("%s len:%u data:%#x %#x", __func__, buf->len, buf->data[0], buf->data[1]);
	uint8_t decrypt_data[ENCRTYPTED_DATA_MAX_LEN];
	LOG_DBG("%#x %#x %#x %u", esls.ap_sync_key_material[0],
		esls.ap_sync_key_material[BT_EAD_KEY_SIZE], buf->data[ADV_HEADER_LEN],
		buf->len - ADV_HEADER_LEN);
	uint32_t s_time = k_cycle_get_32();
	int err = esls_decrypt(buf, decrypt_data);
	uint64_t delta = k_cycle_get_32() - s_time;
	delta = k_cyc_to_ns_floor64(delta);
	LOG_INF("decrypt: %" PRIu64 " ns for len:%u", delta, buf->len - ADV_HEADER_LEN);

#ifdef CONFIG_ZTEST
	/* Allow tests to inject pre-computed plaintext, bypassing real crypto. */
	extern const uint8_t *esls_test_mock_decrypt_data;
	extern uint8_t esls_test_mock_decrypt_len;
	if (esls_test_mock_decrypt_data) {
		err = 0;
		memcpy(decrypt_data, esls_test_mock_decrypt_data, esls_test_mock_decrypt_len);
	}
#endif
	if (err) {
		LOG_ERR("ead_decryt err:%d", err);
		return;
	}

	uint8_t decrypt_data_len = BT_EAD_DECRYPTED_PAYLOAD_SIZE(buf->len) - ADV_HEADER_LEN;
	if ((decrypt_data_len != (decrypt_data[ADV_LEN_OFFSET] + ADV_TYPE_SIZE)) ||
	    decrypt_data[ADV_TYPE_OFFSET] != ADV_TYPE_ESL) {
		LOG_ERR("invalid data %u %u %u", decrypt_data_len, decrypt_data[ADV_LEN_OFFSET],
			decrypt_data[ADV_TYPE_OFFSET]);
		return;
	}
	uint8_t idx = ADV_HEADER_LEN;
	if (decrypt_data[idx] != ESLS_GROUP_ID(esls.esl_addr)) {
		LOG_WRN("unexp group id %u %u", decrypt_data[idx], ESLS_GROUP_ID(esls.esl_addr));
		return;
	}
	// |ADV payload                                                            |
	// |Len(1)|Type(1)|Encrypted Data                                          |
	//                |Rand(5)|Decrypted Data                           |MIC(4)|
	//                        |Len(1)|ESL Tag(1)|ESL Payload            |
	//                                          |TLV|TLV|..             |
	net_buf_simple_reset(&esls_rsp_buf);
	net_buf_simple_add(&esls_rsp_buf, ADV_HEADER_LEN + ADV_HEADER_LEN + BT_EAD_RANDOMIZER_SIZE);
	idx++;
	uint16_t curr_ecp_len;
	uint8_t tlv_slot = 0;
	int8_t rsp_slot = -1;
	uint8_t esl_id;
	bool is_valid = false;
	uint8_t last_rsp_slot_len;
	struct esls_rsp_tlv rsp_buf;
#define ESLS_CMD_PARAM_LEN(cmd) (((cmd & 0xf0) >> 4) + ESLS_CMD_RSP_MIN_LEN)
	while (idx < decrypt_data_len) {
		esl_id = decrypt_data[idx + ESLS_ESL_ID_OFFSET];
		curr_ecp_len = ESLS_CMD_PARAM_LEN(decrypt_data[idx]);
		if (idx + curr_ecp_len > decrypt_data_len) {
			break;
		}
		rsp_buf.len = 0;
		if (esls_cmd_parser(&decrypt_data[idx], curr_ecp_len, true, &rsp_buf)) {
			if ((rsp_buf.len + esls_rsp_buf.len >
			     (ESLS_MAX_RSP_LEN - BT_EAD_MIC_SIZE)) &&
			    (rsp_slot >= 0)) {
				net_buf_simple_remove_mem(&esls_rsp_buf, last_rsp_slot_len);
				net_buf_simple_add_u8(&esls_rsp_buf, ESLS_RSP_OPCODE_ERROR);
				net_buf_simple_add_u8(&esls_rsp_buf, ESLS_ERR_CAPACITY_LIMIT);
				break;
			}
			last_rsp_slot_len = rsp_buf.len;
			net_buf_simple_add_mem(&esls_rsp_buf, rsp_buf.data, last_rsp_slot_len);
			rsp_slot = tlv_slot;
			is_valid = true;
		}
		if (decrypt_data[idx + ESLS_ESL_ID_OFFSET] == ESL_ADDR_ID_BROADCAST_ADDR) {
			is_valid = true;
		}
		idx += curr_ecp_len;
		tlv_slot++;
	}

	if (is_valid) {
		esls_run_state(ESLS_EVT_RCV_VALID_MSG);
	}

	if (rsp_slot >= 0) {
		esls_send_pawr_rsp(info, rsp_slot);
	}
	if (esls.func) {
		esls.func(NULL, NULL);
	}
}

static struct bt_le_per_adv_sync_cb esls_sync_cb = {
	.synced = esls_synced,
	.term = esls_term,
	.recv = esls_recv,
};

static void esls_create_pawr_sync(void)
{
	LOG_INF("%s", __func__);

	const struct bt_le_per_adv_sync_transfer_param past_param = {
		.skip = PAST_SYNC_SKIP,
		.timeout = PAST_SYNC_TIMEOUT_CS,
	};
	int err = bt_le_per_adv_sync_transfer_subscribe(esls.curr_conn, &past_param);
	if (err) {
		LOG_ERR("%s err %d", __func__, err);
		return;
	}
}

static void esls_unassociated_entry(void *obj)
{
	LOG_INF("%s", __func__);

	esls_start_adv_work.is_bonded = false;
	k_work_submit(&esls_start_adv_work.work);

#if UNDIRECT_START_DURATION_CS
	k_work_reschedule(&esls_idle_timer_work, K_MSEC(CS_TO_MS(UNDIRECT_START_DURATION_CS)));
#endif
}

static enum smf_state_result esls_unassociated_run(void *obj)
{
	LOG_INF("%s evt:%u", __func__, esls.evt);

	switch (esls.evt) {
	case ESLS_EVT_ENCRYPTED: {
		smf_set_state(SMF_CTX(&esls), &esls_states[ESLS_STATE_CONFIGURING]);
	} break;
	case ESLS_EVT_STATE_TIMEOUT:
	case ESLS_EVT_DISCONNECTED: {
		smf_set_state(SMF_CTX(&esls), &esls_states[ESLS_STATE_UNASSOCIATED]);
	} break;
	default: {
		// do nothing
	} break;
	}
	return SMF_EVENT_HANDLED;
}

static void esls_unassociated_exit(void *obj)
{
	LOG_INF("%s", __func__);
}

static void esls_configuring_entry(void *obj)
{
	LOG_INF("%s", __func__);

#ifdef CONFIG_ESL_PTS
#define ESLS_CONFIG_UNASS_STATE_TIMEOUT_SEC 30
#else
#define ESLS_CONFIG_UNASS_STATE_TIMEOUT_SEC 10
#endif
	k_work_reschedule(&esls_idle_timer_work, K_SECONDS(ESLS_CONFIG_UNASS_STATE_TIMEOUT_SEC));
}

static enum smf_state_result esls_configuring_run(void *obj)
{
	LOG_INF("%s evt:%u", __func__, esls.evt);

	switch (esls.evt) {
	case ESLS_EVT_UPDATE_COMPLETE: {
		esls_create_pawr_sync();
	} break;
	case ESLS_EVT_PAST_SYNCED: {
		smf_set_state(SMF_CTX(&esls), &esls_states[ESLS_STATE_SYNCHRONIZED]);
	} break;
	case ESLS_EVT_STATE_TIMEOUT: {
		esls_disconnect();
	} break;
	case ESLS_EVT_DISCONNECTED: {
		if (!esls_is_configured_char() || !esls.is_boned) {
			smf_set_state(SMF_CTX(&esls), &esls_states[ESLS_STATE_UNASSOCIATED]);
		} else {
			smf_set_state(SMF_CTX(&esls), &esls_states[ESLS_STATE_UNSYNCHRONIZED]);
		}
	} break;
	default: {
		// do nothing
	} break;
	}
	return SMF_EVENT_HANDLED;
}

static void esls_configuring_exit(void *obj)
{
	LOG_INF("%s", __func__);

	esls_disconnect();
}

static void esls_synchronized_entry(void *obj)
{
	LOG_INF("%s", __func__);

	esls.basic_state |= ESLS_BASIC_STATE_SYNCHRONIZED;

#ifdef CONFIG_BT_ESLS_SYNCHRONIZED_TIMEOUT_SEC
	k_work_reschedule(&esls_idle_timer_work,
			  K_SECONDS(CONFIG_BT_ESLS_SYNCHRONIZED_TIMEOUT_SEC));
#else
	k_work_cancel_delayable(&esls_idle_timer_work);
#endif
#ifdef CONFIG_PSA_WANT_ALG_CCM
	int err =
		esls_import_aes_key(&enc_key_id, esls.esl_rsp_key_material, PSA_KEY_USAGE_ENCRYPT);
	if (err) {
		LOG_ERR("setEncKey %d", err);
		return;
	}
	err = esls_import_aes_key(&dec_key_id, esls.ap_sync_key_material, PSA_KEY_USAGE_DECRYPT);
	if (err) {
		LOG_ERR("setDecKey %d", err);
		return;
	}
#endif
}

static enum smf_state_result esls_synchronized_run(void *obj)
{
	LOG_INF("%s evt:%u", __func__, esls.evt);

	switch (esls.evt) {
	case ESLS_EVT_PA_SYNC_TERM: {
		smf_set_state(SMF_CTX(&esls), &esls_states[ESLS_STATE_UNSYNCHRONIZED]);
	} break;
	case ESLS_EVT_STATE_TIMEOUT: {
		smf_set_state(SMF_CTX(&esls), &esls_states[ESLS_STATE_UNSYNCHRONIZED]);
	} break;
	case ESLS_EVT_ENCRYPTED: {
		smf_set_state(SMF_CTX(&esls), &esls_states[ESLS_STATE_UPDATING]);
	} break;
	case ESLS_EVT_RCV_VALID_MSG: {
		k_work_reschedule(&esls_idle_timer_work,
				  K_SECONDS(CONFIG_BT_ESLS_SYNCHRONIZED_TIMEOUT_SEC));
	} break;
	case ESLS_EVT_DISCONNECTED:
	default: {
		// do nothing
	} break;
	}
	return SMF_EVENT_HANDLED;
}

static void esls_synchronized_exit(void *obj)
{
	LOG_INF("%s", __func__);

	esls.basic_state &= ~ESLS_BASIC_STATE_SYNCHRONIZED;
	esls_stop_pawr_sync();
}

static void esls_updating_entry(void *obj)
{
	LOG_INF("%s", __func__);

#define ESLS_CONFIG_SYNC_STATE_TIMEOUT_SEC 60
	k_work_reschedule(&esls_idle_timer_work, K_SECONDS(ESLS_CONFIG_SYNC_STATE_TIMEOUT_SEC));
}

static enum smf_state_result esls_updating_run(void *obj)
{
	LOG_INF("%s evt:%u", __func__, esls.evt);

	switch (esls.evt) {
	case ESLS_EVT_UPDATE_COMPLETE: {
		esls_create_pawr_sync();
	} break;
	case ESLS_EVT_PAST_SYNCED: {
		smf_set_state(SMF_CTX(&esls), &esls_states[ESLS_STATE_SYNCHRONIZED]);
	} break;
	case ESLS_EVT_DISCONNECTED: {
		if (esls_is_configured()) {
			smf_set_state(SMF_CTX(&esls), &esls_states[ESLS_STATE_UNSYNCHRONIZED]);
		} else {
			smf_set_state(SMF_CTX(&esls), &esls_states[ESLS_STATE_UNASSOCIATED]);
		}
	} break;
	default: {
		// do nothing
	} break;
	}
	return SMF_EVENT_HANDLED;
}

static void esls_updating_exit(void *obj)
{
	LOG_INF("%s", __func__);

	k_work_cancel_delayable(&esls_idle_timer_work);
	esls_disconnect();
}

static void esls_unsynchronized_entry(void *obj)
{
	LOG_INF("%s", __func__);

	esls_start_adv_work.is_bonded = true;
	k_work_submit(&esls_start_adv_work.work);

#ifdef CONFIG_BT_ESLS_UNSYNCHRONIZED_TIMEOUT_SEC
	k_work_reschedule(&esls_idle_timer_work,
			  K_SECONDS(CONFIG_BT_ESLS_UNSYNCHRONIZED_TIMEOUT_SEC));
#else
	k_work_cancel_delayable(&esls_idle_timer_work);
#endif
}

static enum smf_state_result esls_unsynchronized_run(void *obj)
{
	LOG_INF("%s evt:%u", __func__, esls.evt);

	switch (esls.evt) {
	case ESLS_EVT_ENCRYPTED: {
		smf_set_state(SMF_CTX(&esls), &esls_states[ESLS_STATE_UPDATING]);
	} break;
	case ESLS_EVT_STATE_TIMEOUT: {
		bt_esls_unassociate();
		smf_set_state(SMF_CTX(&esls), &esls_states[ESLS_STATE_UNASSOCIATED]);
	} break;
	case ESLS_EVT_DISCONNECTED: {
		smf_set_state(SMF_CTX(&esls), &esls_states[ESLS_STATE_UNSYNCHRONIZED]);
	} break;
	default: {
		// do nothing
	} break;
	}
	return SMF_EVENT_HANDLED;
}

static void esls_unsynchronized_exit(void *obj)
{
	LOG_INF("%s", __func__);

	esls_stop_adv();
}

static ssize_t esls_write_esl_address(struct bt_conn *conn, struct bt_gatt_attr const *attr,
				      void const *buf, uint16_t len, uint16_t offset, uint8_t flags)
{
	LOG_INF("%s", __func__);

	if ((offset + len) != ESL_ADDR_LEN) {
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
	}

	uint16_t new_esl_addr = sys_get_le16(buf);
	if ((new_esl_addr & ESL_ADDR_ID_MASK) == ESL_ADDR_ID_BROADCAST_ADDR) {
		return BT_GATT_ERR(BT_ATT_ERR_VALUE_NOT_ALLOWED);
	}
	if (new_esl_addr & ESL_ADDR_RFU_MASK) {
		LOG_WRN("ignore rfu esl addr");
	}
	uint16_t *esl_addr = attr->user_data;
	*esl_addr = (new_esl_addr & ESL_ADDR_VALID_MASK);
	int err = settings_save_one("esls/esl_addr", esl_addr, ESL_ADDR_LEN);
	if (err) {
		LOG_ERR("save esl addr err %d", err);
	}
	esls.config_flag |= ESLS_FLAG_ESL_ADDR_SET;
	return ESL_ADDR_LEN;
}

static ssize_t esls_gatt_write_func(void *user_data, void const *buf, uint16_t len, uint16_t offset,
				    uint16_t exp_len, const char *name, uint8_t flag)
{
	if ((offset + len) != exp_len) {
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
	}
	memcpy(user_data, buf, exp_len);
	int err = settings_save_one(name, user_data, exp_len);
	if (err) {
		LOG_ERR("save %s err %d", name, err);
	}
	esls.config_flag |= flag;

	LOG_INF("%s %s", __func__, name);
	return exp_len;
}

static ssize_t esls_write_ap_sync_key_material(struct bt_conn *conn,
					       struct bt_gatt_attr const *attr, void const *buf,
					       uint16_t len, uint16_t offset, uint8_t flags)
{
	ssize_t size =
		esls_gatt_write_func(attr->user_data, buf, len, offset, AP_SYNC_KEY_MATERIAL_LEN,
				     "esls/ap_sync_key", ESLS_FLAG_AP_SYNC_KEY_MATERIAL_SET);
	sys_mem_swap(attr->user_data, BT_EAD_KEY_SIZE);
	return size;
}

static ssize_t esls_write_esl_rsp_key_material(struct bt_conn *conn,
					       struct bt_gatt_attr const *attr, void const *buf,
					       uint16_t len, uint16_t offset, uint8_t flags)
{
	ssize_t size =
		esls_gatt_write_func(attr->user_data, buf, len, offset, ESL_RSP_KEY_MATERIAL_LEN,
				     "esls/esl_rsp_key", ESLS_FLAG_ESL_RSP_KEY_MATERIAL_SET);
	sys_mem_swap(attr->user_data, BT_EAD_KEY_SIZE);
	return size;
}

static ssize_t esls_write_esl_curr_abs_time(struct bt_conn *conn, struct bt_gatt_attr const *attr,
					    void const *buf, uint16_t len, uint16_t offset,
					    uint8_t flags)
{
	ssize_t size =
		esls_gatt_write_func(attr->user_data, buf, len, offset, ESL_CURRENT_ABS_TIME_LEN,
				     "esls/esl_curr_abs_time", ESLS_FLAG_ESL_CURR_ABS_TIME_SET);
	if (size > 0) {
		esls_update_abs_time_anchor(sys_get_le32((uint8_t const *)buf));
	}
	return size;
}

struct esl_write_work_info {
	struct k_work work;
	struct bt_gatt_notify_params notify_param;
};
static struct esl_write_work_info esl_write_work;

static void esls_write_handler(struct k_work *work)
{
	struct esl_write_work_info *info = CONTAINER_OF(work, struct esl_write_work_info, work);
	struct bt_conn_info conn_info;

	bt_conn_get_info(esls.curr_conn, &conn_info);
	int err = bt_gatt_notify_cb(NULL, &info->notify_param);
	if (err) {
		LOG_ERR("%s err:%d", __func__, err);
	}
}

static ssize_t esls_write_esl_control_point(struct bt_conn *conn, struct bt_gatt_attr const *attr,
					    void const *buf, uint16_t len, uint16_t offset,
					    uint8_t flags)
{
	if (len < ESLS_CMD_RSP_MIN_LEN) {
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_ATTRIBUTE_LEN);
	}
	struct esls_rsp_tlv rsp_buf = {0};
	if (esls_cmd_parser(buf, len, false, &rsp_buf)) {
		esl_write_work.notify_param.data = rsp_buf.data;
		esl_write_work.notify_param.len = rsp_buf.len;
		esl_write_work.notify_param.func = esls.func;
		esl_write_work.notify_param.attr = attr;
		atm_work_submit_to_app_work_q(&esl_write_work.work);
	}
	return len;
}

static void esls_cp_ccc_changed(const struct bt_gatt_attr *attr, uint16_t value)
{
	LOG_INF("ccc:%u", value);
}

#if CONFIG_BT_ESLS_DISPLAY_NUM > 0
#define BT_ESLS_DISPLAY_INFO_SIZE sizeof(struct bt_esls_display_info) * CONFIG_BT_ESLS_DISPLAY_NUM

static ssize_t esls_read_esl_display_info(struct bt_conn *conn, const struct bt_gatt_attr *attr,
					  void *buf, uint16_t len, uint16_t offset)
{
	return bt_gatt_attr_read(conn, attr, buf, len, offset, esls.init_param.display_info,
				 BT_ESLS_DISPLAY_INFO_SIZE);
}
#endif

#if CONFIG_BT_ESLS_IMAGE_NUM > 0
static ssize_t esls_read_esl_image_info(struct bt_conn *conn, const struct bt_gatt_attr *attr,
					void *buf, uint16_t len, uint16_t offset)
{
	uint8_t image_max_idx = CONFIG_BT_ESLS_IMAGE_NUM - 1;
	return bt_gatt_attr_read(conn, attr, buf, len, offset, &image_max_idx,
				 sizeof(image_max_idx));
}
#endif

#if CONFIG_BT_ESLS_SENSOR_NUM > 0
static ssize_t esls_read_esl_sensor_info(struct bt_conn *conn, const struct bt_gatt_attr *attr,
					 void *buf, uint16_t len, uint16_t offset)
{
	uint16_t curr_idx = 0;
	uint8_t read_buf[sizeof(struct bt_esls_sensor_info) * CONFIG_BT_ESLS_SENSOR_NUM];
	for (uint8_t i = 0; i < CONFIG_BT_ESLS_SENSOR_NUM; i++) {
		if (esls.init_param.sensors_info[i].type == BT_ESLS_SIZE_TYPE_16_BITS) {
			memcpy(&read_buf[curr_idx], &esls.init_param.sensors_info[i],
			       SENSOR_INFO_16_BIT_PAIR_LEN);
			curr_idx += SENSOR_INFO_16_BIT_PAIR_LEN;
		} else if (esls.init_param.sensors_info[i].type == BT_ESLS_SIZE_TYPE_32_BITS) {
			memcpy(&read_buf[curr_idx], &esls.init_param.sensors_info[i],
			       SENSOR_INFO_32_BIT_PAIR_LEN);
			curr_idx += SENSOR_INFO_32_BIT_PAIR_LEN;
		} else {
			LOG_WRN("unexp sensor type:%u", esls.init_param.sensors_info[i].type);
		}
	}
	return bt_gatt_attr_read(conn, attr, buf, len, offset, read_buf, curr_idx);
}
#endif

#if CONFIG_BT_ESLS_LED_NUM > 0
static ssize_t esls_read_esl_led_info(struct bt_conn *conn, const struct bt_gatt_attr *attr,
				      void *buf, uint16_t len, uint16_t offset)
{
	uint8_t read_buf[CONFIG_BT_ESLS_LED_NUM];
	memcpy(read_buf, esls.init_param.led, CONFIG_BT_ESLS_LED_NUM);

	return bt_gatt_attr_read(conn, attr, buf, len, offset, read_buf, CONFIG_BT_ESLS_LED_NUM);
}
#endif

// Eletronic Shelf Label Service Declaration
BT_GATT_SERVICE_DEFINE(
	esls_svc, BT_GATT_PRIMARY_SERVICE(BT_UUID_ESLS),
	BT_GATT_CHARACTERISTIC(BT_UUID_ESL_ADDRESS, BT_GATT_CHRC_WRITE, BT_GATT_PERM_WRITE_ENCRYPT,
			       NULL, esls_write_esl_address, &esls.esl_addr),
	BT_GATT_CHARACTERISTIC(BT_UUID_AP_SYNC_KEY_MATERIAL, BT_GATT_CHRC_WRITE,
			       BT_GATT_PERM_WRITE_ENCRYPT, NULL, esls_write_ap_sync_key_material,
			       esls.ap_sync_key_material),
	BT_GATT_CHARACTERISTIC(BT_UUID_ESL_RSP_KEY_MATERIAL, BT_GATT_CHRC_WRITE,
			       BT_GATT_PERM_WRITE_ENCRYPT, NULL, esls_write_esl_rsp_key_material,
			       esls.esl_rsp_key_material),
	BT_GATT_CHARACTERISTIC(BT_UUID_ESL_CURRENT_ABSOLUTE_TIME, BT_GATT_CHRC_WRITE,
			       BT_GATT_PERM_WRITE_ENCRYPT, NULL, esls_write_esl_curr_abs_time,
			       &esls.esl_curr_abs_time),
#if CONFIG_BT_ESLS_DISPLAY_NUM > 0
	BT_GATT_CHARACTERISTIC(BT_UUID_ESL_DISPLAY_INFO, BT_GATT_CHRC_READ,
			       BT_GATT_PERM_READ_ENCRYPT, esls_read_esl_display_info, NULL, NULL),
#endif
#if CONFIG_BT_ESLS_IMAGE_NUM > 0
	BT_GATT_CHARACTERISTIC(BT_UUID_ESL_IMAGE_INFO, BT_GATT_CHRC_READ, BT_GATT_PERM_READ_ENCRYPT,
			       esls_read_esl_image_info, NULL, NULL),
#endif
#if CONFIG_BT_ESLS_SENSOR_NUM > 0
	BT_GATT_CHARACTERISTIC(BT_UUID_ESL_SENSOR_INFO, BT_GATT_CHRC_READ,
			       BT_GATT_PERM_READ_ENCRYPT, esls_read_esl_sensor_info, NULL, NULL),
#endif
#if CONFIG_BT_ESLS_LED_NUM > 0
	BT_GATT_CHARACTERISTIC(BT_UUID_ESL_LED, BT_GATT_CHRC_READ, BT_GATT_PERM_READ_ENCRYPT,
			       esls_read_esl_led_info, NULL, NULL),
#endif
	BT_GATT_CHARACTERISTIC(BT_UUID_ESL_CONTROL_POINT,
			       BT_GATT_CHRC_WRITE_WITHOUT_RESP | BT_GATT_CHRC_WRITE |
				       BT_GATT_CHRC_NOTIFY,
			       BT_GATT_PERM_WRITE_ENCRYPT, NULL, esls_write_esl_control_point,
			       NULL),
	BT_GATT_CCC(esls_cp_ccc_changed, BT_GATT_PERM_READ_ENCRYPT | BT_GATT_PERM_WRITE_ENCRYPT), );

#if CONFIG_BT_OTS
static struct esls_write_img_wrok_info {
	struct k_work work;
	uint16_t len;
	uint8_t obj_buf[CONFIG_BT_ESLS_IMAGE_MAX_SIZE];
	uint8_t img_idx;
} esls_write_img_work;

#define ESLS_OBJ_IDX(id) ((id - BT_OTS_OBJ_ID_MIN) % CONFIG_BT_OTS_MAX_OBJ_CNT)
static ssize_t esls_obj_write(struct bt_ots *ots, struct bt_conn *conn, uint64_t id,
			      const void *data, size_t len, off_t offset, size_t rem)
{
	char id_str[BT_OTS_OBJ_ID_STR_LEN];
	bt_ots_obj_id_to_str(id, id_str, sizeof(id_str));
	LOG_INF("wr ID:%s len:%u os:%lu rem:%u", id_str, len, offset, rem);
	if (len + offset > CONFIG_BT_ESLS_IMAGE_MAX_SIZE) {
		LOG_ERR("%s len:%u os:%lu", __func__, len, offset);
		return 0;
	}
	memcpy(&esls_write_img_work.obj_buf[offset], data, len);
	if (!rem) {
		esls_write_img_work.len = offset + len;
		esls_write_img_work.img_idx = ESLS_OBJ_IDX(id);
		k_work_submit_to_queue(&esls_image_wq, &esls_write_img_work.work);
	}
	return len;
}

static int esls_obj_created(struct bt_ots *ots, struct bt_conn *conn, uint64_t id,
			    const struct bt_ots_obj_add_param *add_param,
			    struct bt_ots_obj_created_desc *created_desc)
{
	char id_str[BT_OTS_OBJ_ID_STR_LEN];
	bt_ots_obj_id_to_str(id, id_str, sizeof(id_str));
	LOG_INF("%s ID created size:%u", id_str, add_param->size);

	if (created_obj_cnt >= CONFIG_BT_ESLS_IMAGE_NUM) {
		LOG_ERR("exceed obj cnt");
		return -ENOMEM;
	}
	created_obj_cnt++;
	created_desc->size.alloc = CONFIG_BT_ESLS_IMAGE_MAX_SIZE;
	uint16_t img_size;
	int err = esls.init_param.read_image_size(ESLS_OBJ_IDX(id), &img_size);
	if (err) {
		LOG_ERR("%s size err:%d", __func__, err);
		return err;
	}
	created_desc->size.cur = img_size;
	err = esls.init_param.get_image_name(ESLS_OBJ_IDX(id), &created_desc->name);
	if (err) {
		LOG_ERR("%s err:%d", __func__, err);
		return err;
	}
	LOG_INF("%s %s cur_sz:%u", __func__, created_desc->name, img_size);
	BT_OTS_OBJ_SET_PROP_WRITE(created_desc->props);
	BT_OTS_OBJ_SET_PROP_PATCH(created_desc->props);

	return 0;
}

#ifdef CONFIG_BT_OTS_OACP_CHECKSUM_SUPPORT
static int esls_obj_cal_checksum(struct bt_ots *ots, struct bt_conn *conn, uint64_t id,
				 off_t offset, size_t len, void **data)
{
	if (len + offset > CONFIG_BT_ESLS_IMAGE_MAX_SIZE) {
		LOG_ERR("%s len:%u os:%lu", __func__, len, offset);
		return -EINVAL;
	}
	int err = esls.init_param.read_image_data(
		ESLS_OBJ_IDX(id), (uint8_t *)esls_write_img_work.obj_buf, 0, len + offset);
	if (err) {
		LOG_ERR("%s err:%d", __func__, err);
		return err;
	}
	*data = &esls_write_img_work.obj_buf[offset];
	return 0;
}
#endif

static void esls_create_obj(void)
{
	int id;
	for (uint8_t i = 0; i < CONFIG_BT_ESLS_IMAGE_NUM; i++) {
		const struct bt_ots_obj_add_param param = {
			.size = CONFIG_BT_ESLS_IMAGE_MAX_SIZE,
			.type =
				{
					.uuid.type = BT_UUID_TYPE_16,
					.uuid_16.val = BT_UUID_OTS_TYPE_UNSPECIFIED_VAL,
				},
		};
		id = bt_ots_obj_add(esls.ots, &param);
		if (id < 0) {
			LOG_ERR("obj add err:%d", id);
		} else {
			LOG_INF("obj add id:%d", id);
		}
	}
}

static int esls_ots_init(void)
{
	esls.ots = bt_ots_free_instance_get();
	if (!esls.ots) {
		LOG_ERR("Retrieve OTS inst failed");
		return -ENOMEM;
	}
	struct bt_ots_init_param ots_init_param;
	memset(&ots_init_param, 0, sizeof(ots_init_param));
	BT_OTS_OACP_SET_FEAT_WRITE(ots_init_param.features.oacp);
	// replacing truncate feature with patch
	BT_OTS_OACP_SET_FEAT_PATCH(ots_init_param.features.oacp);
	// can not set the feature due to Zephyr bug, but it can still be used
	// if CONFIG_BT_OTS_OACP_CHECKSUM_SUPPORT is enabled
// #ifdef CONFIG_BT_OTS_OACP_CHECKSUM_SUPPORT
//     BT_OTS_OACP_SET_FEAT_CHECKSUM(ots_init_param.features.oacp);
// #endif
#if CONFIG_BT_ESLS_IMAGE_NUM > 1
	BT_OTS_OLCP_SET_FEAT_GO_TO(ots_init_param.features.olcp);
#endif

	static struct bt_ots_cb esls_ots_cbs = {
		.obj_created = esls_obj_created,
		.obj_write = esls_obj_write,
#ifdef CONFIG_BT_OTS_OACP_CHECKSUM_SUPPORT
		.obj_cal_checksum = esls_obj_cal_checksum,
#endif
	};
	ots_init_param.cb = &esls_ots_cbs;
	int err = bt_ots_init(esls.ots, &ots_init_param);
	if (err) {
		LOG_ERR("bt_ots_init err:%d", err);
		return err;
	}
	esls_create_obj();
	return err;
}
#endif // CONFIG_BT_OTS

static int esls_set(const char *name, size_t len, settings_read_cb read_cb, void *cb_arg)
{
	LOG_INF("%s config_flag %u", __func__, esls.config_flag);

	const char *next;
	ssize_t real_len = settings_name_next(name, &next);
	if (next) {
		LOG_WRN("unexpected next");
		return 0;
	}
	LOG_INF("%s %s %u", __func__, name, real_len);
	if (!strcmp(name, "ass_addr")) {
		if ((len != sizeof(bt_addr_le_t)) ||
		    (read_cb(cb_arg, &esls.ass_addr, sizeof(bt_addr_le_t)) !=
		     sizeof(bt_addr_le_t))) {
			return -EINVAL;
		}
		return 0;
	}
	if (!strcmp(name, "esl_addr")) {
		if ((len != ESL_ADDR_LEN) ||
		    (read_cb(cb_arg, &esls.esl_addr, ESL_ADDR_LEN) != ESL_ADDR_LEN)) {
			return -EINVAL;
		}
		esls.config_flag |= ESLS_FLAG_ESL_ADDR_SET;
		return 0;
	}
	if (!strcmp(name, "ap_sync_key")) {
		if ((len != AP_SYNC_KEY_MATERIAL_LEN) ||
		    (read_cb(cb_arg, &esls.ap_sync_key_material, AP_SYNC_KEY_MATERIAL_LEN) !=
		     AP_SYNC_KEY_MATERIAL_LEN)) {
			return -EINVAL;
		}
		esls.config_flag |= ESLS_FLAG_AP_SYNC_KEY_MATERIAL_SET;
		return 0;
	}
	if (!strcmp(name, "esl_rsp_key")) {
		if ((len != ESL_RSP_KEY_MATERIAL_LEN) ||
		    (read_cb(cb_arg, &esls.esl_rsp_key_material, ESL_RSP_KEY_MATERIAL_LEN) !=
		     ESL_RSP_KEY_MATERIAL_LEN)) {
			return -EINVAL;
		}
		esls.config_flag |= ESLS_FLAG_ESL_RSP_KEY_MATERIAL_SET;
		return 0;
	}
	if (!strcmp(name, "esl_curr_abs_time")) {
		if ((len != ESL_CURRENT_ABS_TIME_LEN) ||
		    (read_cb(cb_arg, &esls.esl_curr_abs_time, ESL_CURRENT_ABS_TIME_LEN) !=
		     ESL_CURRENT_ABS_TIME_LEN)) {
			return -EINVAL;
		}
		esls.config_flag |= ESLS_FLAG_ESL_CURR_ABS_TIME_SET;
		return 0;
	}
	return -ENOENT;
}

static int esls_setting_init(void)
{
	LOG_INF("%s", __func__);

	int err = settings_subsys_init();
	if (err) {
		LOG_ERR("settings_subsys_init failed %d", err);
		return err;
	}
	err = settings_load_subtree("esls");
	if (err) {
		LOG_ERR("settings_load_subtree failed %d", err);
	}
	return err;
}
SETTINGS_STATIC_HANDLER_DEFINE(esls, "esls", NULL, esls_set, NULL, NULL);

static void esls_unassociate_data(void)
{
	LOG_INF("%s", __func__);
	int err = settings_delete("esls/esl_addr");
	if (err) {
		LOG_ERR("delete esl_addr %d", err);
	}
	err = settings_delete("esls/ap_sync_key");
	if (err) {
		LOG_ERR("delete ap_sync_key %d", err);
	}
	err = settings_delete("esls/esl_rsp_key");
	if (err) {
		LOG_ERR("delete esl_rsp_key %d", err);
	}
	err = settings_delete("esls/esl_curr_abs_time");
	if (err) {
		LOG_ERR("delete esl_curr_abs_time %d", err);
	}
	esls.config_flag = 0;
}

int bt_esls_unassociate(void)
{
	esls_unassociate_data();
	bt_unpair(BT_ID_DEFAULT, BT_ADDR_LE_ANY);
	esls_update_bond_info();
	settings_load_subtree("esls");
#if CONFIG_BT_ESLS_DISPLAY_NUM > 0
	for (uint8_t idx = 0; idx < CONFIG_BT_ESLS_DISPLAY_NUM; idx++) {
		esls_cancel_display(idx);
	}
#endif
#if CONFIG_BT_ESLS_LED_NUM > 0
	for (uint8_t idx = 0; idx < CONFIG_BT_ESLS_LED_NUM; idx++) {
		esls_cancel_led_control(idx);
	}
#endif
	return 0;
}

#if CONFIG_BT_OTS
static void esls_write_img_handler(struct k_work *work)
{
	struct esls_write_img_wrok_info *info =
		CONTAINER_OF(work, struct esls_write_img_wrok_info, work);
	int err = esls.init_param.write_image_data(info->img_idx, (uint8_t *)info->obj_buf,
						   info->len);
	if (err) {
		LOG_ERR("%s err:%d", __func__, err);
	}
}
#endif

static void esls_factory_reset_handler(struct k_work *work)
{
#if CONFIG_BT_ESLS_IMAGE_NUM > 0
	esls.init_param.delete_image_data();
	for (uint8_t i = 0; i < created_obj_cnt; i++) {
		int err = bt_ots_obj_delete(esls.ots, i + BT_OTS_OBJ_ID_MIN);
		if (err) {
			LOG_ERR("delete obj:%d failed (err %d)", i, err);
		}
	}
	created_obj_cnt = 0;
	esls_create_obj();
#endif
	bt_esls_unassociate();
}

#if CONFIG_BT_ESLS_DISPLAY_NUM > 0
static void esls_display_handler(struct k_work *work)
{
	struct k_work_delayable *d_work = k_work_delayable_from_work(work);
	struct esls_display_wrok_info *info =
		CONTAINER_OF(d_work, struct esls_display_wrok_info, work);
	esls_display_work[info->display_idx].abs_time = 0;
	esls_pending_display_update();
	int err = esls.init_param.display_image(info->display_idx, info->img_idx);
	if (err) {
		LOG_ERR("%s err:%d", __func__, err);
	}
}
#endif

#if CONFIG_BT_ESLS_LED_NUM > 0
static void esls_led_basic_state_update(void)
{
	esls.basic_state &= ~ESLS_BASIC_STATE_ACTIVE_LED;
	esls.basic_state &= ~ESLS_BASIC_STATE_PENDING_LED_UPDATE;

	for (uint8_t i = 0; i < CONFIG_BT_ESLS_LED_NUM; i++) {
		if (esls_led_work[i].led_active) {
			esls.basic_state |= ESLS_BASIC_STATE_ACTIVE_LED;
		}

		if (esls_led_work[i].led_info.abs_time) {
			esls.basic_state |= ESLS_BASIC_STATE_PENDING_LED_UPDATE;
		}
	}
}

static unsigned int esls_find_msb_set(uint64_t data, unsigned int bit_size)
{
	if (!data) {
		return 0; // No bits are set
	}
	unsigned int leading_zeros = __builtin_clzll(data) - (64 - bit_size) + 1;
	return bit_size - leading_zeros;
}

static void esls_led_control_callback(uint8_t led_idx, bool on_off, uint8_t color_brightness_info)
{
	int err = esls.init_param.led_control(led_idx, on_off, color_brightness_info);
	if (err) {
		LOG_ERR("%s err:%d", __func__, err);
	}
}

static void esls_led_control_expired(uint8_t led_idx)
{
	esls_led_work[led_idx].led_active = false;
	esls_led_work[led_idx].led_info.abs_time = 0;
	esls_led_control_callback(led_idx, false, esls_led_work[led_idx].led_info.color_brightness);
}

static void esls_cancel_led_control(uint8_t led_idx)
{
	k_work_cancel_delayable(&esls_led_work[led_idx].work);
	esls_led_control_expired(led_idx);
}

static void esls_led_handler(struct k_work *work)
{
	struct k_work_delayable *d_work = k_work_delayable_from_work(work);
	struct esls_led_wrok_info *info = CONTAINER_OF(d_work, struct esls_led_wrok_info, work);
	uint64_t pattern;
	bool on_off;

	// check LED basic state
	if (info->led_info.abs_time) {
		// LED Timed Control Executed > reset the value
		info->led_info.abs_time = 0;
	}

	// Repeats_Duration = 0x00
	if (!ESLS_LED_CTRL_REPEAT_DUR(info->led_info.repeat_dur_info)) {
		// repeat_dur = 0x01 (Duration) LED shall be turned on continuously
		// repeat_dur = 0x00 (Times) LED shall be turned off continuously
		on_off = ESLS_LED_CTRL_REPEAT_TYPE(info->led_info.repeat_dur_info) ==
					 ESLS_LED_CTRL_REPEAT_TYPE_TIME_DURATION
				 ? true
				 : false;
		info->led_active = on_off;
		esls_led_control_callback(info->led_info.led_idx, on_off,
					  info->led_info.color_brightness);
		return;
	}

	// parsing flashing pattern
	pattern = sys_get_le40(info->led_info.flashing_pattern);

	if (!info->led_active) {
		info->led_active = true;
		// calculate the stop abs time
		if (ESLS_LED_CTRL_REPEAT_TYPE(info->led_info.repeat_dur_info) ==
		    ESLS_LED_CTRL_REPEAT_TYPE_TIME_DURATION) {
			info->repeat_stop_abs_time =
				esls_get_abs_time() +
				(MSEC_PER_SEC *
				 ESLS_LED_CTRL_REPEAT_DUR(info->led_info.repeat_dur_info));
		}
		info->pattern_start_idx = esls_find_msb_set(pattern, LED_CONTROL_PATTERN_BIT_LEN);
	}

	on_off = pattern & (1ULL << info->pattern_start_idx);
	esls_led_control_callback(info->led_info.led_idx, on_off, info->led_info.color_brightness);
	LOG_DBG("pattern_start_idx:%d, pattern=%" PRIx64 " ,on_dur=%d, off_dur=%d, "
		"repeat=%d, on_off=%d",
		info->pattern_start_idx, pattern,
		info->led_info.flashing_pattern[LED_CONTROL_BIT_ON_PERIOD_OFFSET],
		info->led_info.flashing_pattern[LED_CONTROL_BIT_OFF_PERIOD_OFFSET],
		info->repeat_stop_abs_time, on_off);

	// checnk the pattern should be repeated or not
	if (!info->pattern_start_idx) {
		if (ESLS_LED_CTRL_REPEAT_TYPE(info->led_info.repeat_dur_info) ==
		    ESLS_LED_CTRL_REPEAT_TYPE_NUM_OF_TIMES) {
			// Times
			info->repeat_stop_abs_time++;
			if (info->repeat_stop_abs_time >=
			    ESLS_LED_CTRL_REPEAT_DUR(info->led_info.repeat_dur_info)) {
				esls_led_control_expired(info->led_info.led_idx);
				return;
			}
		} else {
			// Duration
			LOG_DBG("curr:%" PRIx32 " ,stop:%" PRIx32, esls_get_abs_time(),
				info->repeat_stop_abs_time);
			if (esls_get_abs_time() > info->repeat_stop_abs_time) {
				esls_led_control_expired(info->led_info.led_idx);
				return;
			}
		}
		// repeat and re-calculating the pattern start index
		info->pattern_start_idx = esls_find_msb_set(pattern, LED_CONTROL_PATTERN_BIT_LEN);
	} else {
		info->pattern_start_idx--;
	}

	// calculate the delay time
	uint32_t delay_time_ms =
		on_off ? info->led_info.flashing_pattern[LED_CONTROL_BIT_ON_PERIOD_OFFSET]
		       : info->led_info.flashing_pattern[LED_CONTROL_BIT_OFF_PERIOD_OFFSET];
	delay_time_ms *= LED_CONTROL_PATTERN_ONOFF_UNIT_MS;
	LOG_DBG("delay_time_ms:%" PRIx32, delay_time_ms);

	k_work_reschedule_for_queue(&esls_led_wq, &esls_led_work[info->led_info.led_idx].work,
				    K_MSEC(delay_time_ms));
}
#endif

static void esls_start_adv_handler(struct k_work *work)
{
	struct esls_start_adv_work_info *info =
		CONTAINER_OF(work, struct esls_start_adv_work_info, work);

	int err = esls_create_adv(info->is_bonded);
	if (err) {
		return;
	}
	esls_start_adv(info->is_bonded);
}

void bt_esls_service_needed_bit_set(bool set)
{
	esl_service_needed_bit = set;
	if (set) {
		esls.basic_state |= ESLS_BASIC_STATE_SERVICE_NEEDED;
	}
}

static void pairing_complete(struct bt_conn *conn, bool bonded)
{
	if (bonded) {
		LOG_INF("Pairing bonded");
		esls.is_boned = true;
		esls_update_bond_info();
	}
}

void bond_deleted(uint8_t id, const bt_addr_le_t *peer)
{
	esls.is_boned = false;
	esls_update_bond_info();
}

static struct bt_conn_auth_info_cb conn_auth_info_callbacks = {
	.pairing_complete = pairing_complete,
	.bond_deleted = bond_deleted,
};

int bt_esls_init(struct bt_esls_init_param const *init_param)
{
	int err;
	err = bt_conn_auth_info_cb_register(&conn_auth_info_callbacks);
	if (err) {
		LOG_ERR("Failed to register bt_conn_auth_info_cb_register.");
		return err;
	}

#ifdef CONFIG_PSA_WANT_ALG_CCM
	// ensure PSA crypto is initialized before the PAwR path needs it
	if (psa_crypto_init() != PSA_SUCCESS) {
		return -EIO;
	}
	// Pre-generate the randomizer for the first PAwR response and prime the
	// TRNG ring so the first encrypt does not stall on hardware warm-up.
	cached_rand_valid = (psa_generate_random(cached_rand, sizeof(cached_rand)) == PSA_SUCCESS);
#endif
#if CONFIG_BT_ESLS_IMAGE_NUM > 0
	if (!init_param->get_image_name || !init_param->read_image_data ||
	    !init_param->read_image_size || !init_param->delete_image_data) {
		return -EINVAL;
	}
#endif
#if CONFIG_BT_ESLS_DISPLAY_NUM > 0
	if (!init_param->display_image) {
		return -EINVAL;
	}
#endif

#if CONFIG_BT_ESLS_LED_NUM > 0
	if (!init_param->led_control) {
		return -EINVAL;
	}
#endif

	err = esls_setting_init();
	if (err) {
		return err;
	}
	memcpy(&esls.init_param, init_param, sizeof(struct bt_esls_init_param));
#if CONFIG_BT_ESLS_IMAGE_NUM > 0
	/* RX thread */
	k_work_queue_init(&esls_image_wq);
	k_work_queue_start(&esls_image_wq, esls_img_stack_area,
			   K_THREAD_STACK_SIZEOF(esls_img_stack_area), CONFIG_ESLS_IMG_WQ_PRIO,
			   NULL);
	k_thread_name_set(&esls_image_wq.thread, "ESLS IMG WQ");
#endif

#if CONFIG_BT_ESLS_LED_NUM > 0
	k_work_queue_init(&esls_led_wq);
	k_work_queue_start(&esls_led_wq, esls_led_stack_area,
			   K_THREAD_STACK_SIZEOF(esls_led_stack_area), CONFIG_ESLS_LED_WQ_PRIO,
			   NULL);
	k_thread_name_set(&esls_led_wq.thread, "ESLS LED WQ");

	for (uint8_t idx = 0; idx < CONFIG_BT_ESLS_LED_NUM; idx++) {
		k_work_init_delayable(&esls_led_work[idx].work, esls_led_handler);
	}
#endif

#if CONFIG_BT_OTS
	err = esls_ots_init();
	if (err) {
		return err;
	}

	k_work_init(&esls_write_img_work.work, esls_write_img_handler);
#endif

#if CONFIG_BT_ESLS_DISPLAY_NUM > 0
	for (uint8_t idx = 0; idx < CONFIG_BT_ESLS_DISPLAY_NUM; idx++) {
		esls_display_work[idx].display_idx = idx;
#ifdef CONFIG_ESL_PTS
		esls_display_work[idx].img_idx = CONFIG_BT_ESLS_IMAGE_NUM;
#endif
		k_work_init_delayable(&esls_display_work[idx].work, esls_display_handler);
	}
#endif

	k_work_init(&factory_reset_work, esls_factory_reset_handler);
	k_work_init(&esl_write_work.work, esls_write_handler);

#if CONFIG_BT_ESLS_ADV_MANU_DATA_MAX
	esls_update_adv_manu_data();
#endif

	esls_update_bond_info();
	if (!esls.is_boned) {
		esls_unassociate_data();
	}
	bt_le_per_adv_sync_cb_register(&esls_sync_cb);
	k_work_init(&esls_start_adv_work.work, esls_start_adv_handler);

	if (esls_is_configured()) {
		smf_set_initial(SMF_CTX(&esls), &esls_states[ESLS_STATE_UNSYNCHRONIZED]);
		return 0;
	}
	smf_set_initial(SMF_CTX(&esls), &esls_states[ESLS_STATE_UNASSOCIATED]);
	return 0;
}

#ifdef CONFIG_ZTEST
#include "esls_test_internal.h"

bool esls_test_is_configured_char(void)
{
	return esls_is_configured_char();
}

void esls_test_set_config_flag(uint8_t flag)
{
	esls.config_flag = flag;
}

uint8_t esls_test_get_all_flags(void)
{
	return ESLS_FLAG_ALL_SET;
}

#if CONFIG_BT_ESLS_LED_NUM > 0
unsigned int esls_test_find_msb_set(uint64_t data, unsigned int bit_size)
{
	return esls_find_msb_set(data, bit_size);
}
#endif /* CONFIG_BT_ESLS_LED_NUM > 0 */

bool esls_test_cmd_parser(const uint8_t *cmd, uint16_t len, bool is_pawr, uint8_t *rsp_data_out,
			  uint8_t *rsp_len_out)
{
	struct esls_rsp_tlv rsp = {0};
	bool ret = esls_cmd_parser(cmd, len, is_pawr, &rsp);

	if (rsp_data_out) {
		memcpy(rsp_data_out, rsp.data, sizeof(rsp.data));
	}
	if (rsp_len_out) {
		*rsp_len_out = rsp.len;
	}
	return ret;
}

void esls_test_prepare_rsp_buf(uint8_t opcode, uint8_t *rsp_data_out, uint8_t *rsp_len_out)
{
	struct esls_rsp_tlv tlv = {0};

	tlv.data[ESLS_OPCODE_OFFSET] = opcode;
	esls_prepare_rsp_buf(&tlv);
	if (rsp_data_out) {
		memcpy(rsp_data_out, tlv.data, sizeof(tlv.data));
	}
	if (rsp_len_out) {
		*rsp_len_out = tlv.len;
	}
}

void esls_test_set_esl_addr(uint16_t addr)
{
	esls.esl_addr = addr;
}

uint16_t esls_test_get_basic_state(void)
{
	return esls.basic_state;
}

void esls_test_set_basic_state(uint16_t state)
{
	esls.basic_state = state;
}

void esls_test_set_smf_state(enum esls_state state)
{
	SMF_CTX(&esls)->current = &esls_states[state];
}

void esls_test_clear_smf_state(void)
{
	/* Reset to UNASSOCIATED so smf_run_state() has a valid current pointer.
	 * Setting current = NULL causes a bus fault (BFAR=0x4) when the next
	 * esls_run_state() call dereferences current->run (offset 4). */
	smf_set_initial(SMF_CTX(&esls), &esls_states[ESLS_STATE_UNASSOCIATED]);
}

uint32_t esls_test_get_abs_time(void)
{
	return esls_get_abs_time();
}

void esls_test_update_abs_time_anchor(uint32_t abs_time)
{
	esls_update_abs_time_anchor(abs_time);
}

struct bt_conn *esls_test_get_curr_conn(void)
{
	return esls.curr_conn;
}

uint8_t esls_test_get_config_flag(void)
{
	return esls.config_flag;
}

bool esls_test_get_is_boned(void)
{
	return esls.is_boned;
}

void esls_test_set_is_boned(bool boned)
{
	esls.is_boned = boned;
}

/* Trigger esls_synced() with the fake sync handle.
 * If bt_le_per_adv_sync_subevent is stubbed to succeed (or fail gracefully),
 * pawr_sync is set and ESLS_EVT_PAST_SYNCED is dispatched → SYNCHRONIZED. */
void esls_test_trigger_synced(void)
{
	static struct bt_le_per_adv_sync_synced_info dummy_info = {0};

	esls_synced(esls_test_get_fake_sync(), &dummy_info);
}

/* Trigger esls_term() on the current pawr_sync handle. */
void esls_test_trigger_term(void)
{
	static struct bt_le_per_adv_sync_term_info dummy_info = {0};

	esls_term(esls.pawr_sync, &dummy_info);
}

/* Unified esls_recv() trigger.  Pass the sync handle to use; NULL data → empty
 * buffer, non-NULL data/len → fill the buffer before calling esls_recv(). */
void esls_test_trigger_recv(struct bt_le_per_adv_sync *sync, const uint8_t *data, uint16_t len)
{
	NET_BUF_SIMPLE_DEFINE(buf, 64);
	static struct bt_le_per_adv_sync_recv_info dummy_info = {0};

	if (data && len) {
		net_buf_simple_add_mem(&buf, data, len);
	}
	esls_recv(sync, &dummy_info, &buf);
}

void esls_test_call_pairing_complete(bool bonded)
{
	pairing_complete(esls.curr_conn, bonded);
}

void esls_test_call_bond_deleted(void)
{
	bond_deleted(BT_ID_DEFAULT, BT_ADDR_LE_ANY);
}

void esls_test_call_adv_sent_cb(void)
{
	static struct bt_le_ext_adv_sent_info sent_info = {0};

	esls_adv_sent_cb(esls.adv_set, &sent_info);
}

void esls_test_trigger_timer_expire(void)
{
	esls_timer_expire(&esls_idle_timer_work.work);
}

/* Call esls_found_bond() with a dummy bond record to cover the callback body. */
void esls_test_call_found_bond(void)
{
	static struct bt_bond_info dummy_bond = {0};

	esls_found_bond(&dummy_bond, NULL);
}

#ifdef CONFIG_PSA_WANT_ALG_CCM
/* Directly exercise esls_encrypt() with a zeroed rsp buffer.
 * PSA operations run; success/failure both exercise the function body. */
int esls_test_call_encrypt(void)
{
	static struct esls_pawr_rsp dummy_rsp = {0};

	return esls_encrypt(&dummy_rsp, ESLS_CMD_RSP_MIN_LEN);
}

#endif /* CONFIG_PSA_WANT_ALG_CCM */

/* ── Direct-coverage helpers: state-machine bypass ──────────────────────── */

void esls_test_set_pawr_sync(struct bt_le_per_adv_sync *sync)
{
	esls.pawr_sync = sync;
}

void esls_test_call_notify_cmp_cb(void)
{
	esls_notify_cmp_cb(NULL, NULL);
}

void esls_test_run_evt(enum esls_evt evt)
{
	esls_run_state(evt);
}

/* ── Decrypt bypass (covers the post-decrypt section of esls_recv) ───────── */

/* Pointers read by the #ifdef CONFIG_ZTEST hook inside esls_recv.
 * Set them via esls_test_set_decrypt_bypass() before calling esls_recv;
 * clear with esls_test_clear_decrypt_bypass() afterwards. */
const uint8_t *esls_test_mock_decrypt_data = NULL;
uint8_t esls_test_mock_decrypt_len = 0;

void esls_test_set_decrypt_bypass(const uint8_t *data, uint8_t len)
{
	esls_test_mock_decrypt_data = data;
	esls_test_mock_decrypt_len = len;
}

void esls_test_clear_decrypt_bypass(void)
{
	esls_test_mock_decrypt_data = NULL;
	esls_test_mock_decrypt_len = 0;
}

/* Call esls_cp_ccc_changed() directly — the GATT write path does not invoke it
 * in the simulated-connection test environment. Covers lines 1537, 1539, 1540. */
void esls_test_call_cp_ccc_changed(void)
{
	esls_cp_ccc_changed(NULL, 0);
}

/* Atomically set pawr_sync to a non-NULL sentinel and call esls_stop_pawr_sync()
 * so that lines 562 and 569 (the function body after the NULL guard) are covered. */
void esls_test_force_stop_pawr_sync(void)
{
	static uint8_t dummy_sync[8] __aligned(8);

	esls.pawr_sync = (struct bt_le_per_adv_sync *)dummy_sync;
	esls_stop_pawr_sync();
}

/* ── LED work-queue and handler helpers ──────────────────────────────────── */
#if CONFIG_BT_ESLS_LED_NUM > 0

void esls_test_set_led_control_cb(int (*fn)(uint8_t led_idx, bool on_off, uint8_t color_brightness))
{
	esls.init_param.led_control = fn;
}

/* Set LED work item fields directly (bypasses bt_esls_init). */
void esls_test_set_led_work(uint8_t idx, uint8_t led_idx, uint16_t repeat_dur_info,
			    const uint8_t pattern7[7], bool led_active, uint8_t pattern_start_idx,
			    uint32_t repeat_stop_abs_time)
{
	if (idx >= CONFIG_BT_ESLS_LED_NUM) {
		return;
	}
	memset(&esls_led_work[idx].led_info, 0, sizeof(esls_led_work[idx].led_info));
	esls_led_work[idx].led_info.led_idx = led_idx;
	esls_led_work[idx].led_info.repeat_dur_info = repeat_dur_info;
	if (pattern7) {
		memcpy(esls_led_work[idx].led_info.flashing_pattern, pattern7, 7);
	}
	esls_led_work[idx].led_active = led_active;
	esls_led_work[idx].pattern_start_idx = pattern_start_idx;
	esls_led_work[idx].repeat_stop_abs_time = repeat_stop_abs_time;
}

/* Run the LED handler synchronously (bypasses k_work_reschedule). */
void esls_test_run_led_handler(uint8_t idx)
{
	if (idx < CONFIG_BT_ESLS_LED_NUM) {
		esls_led_handler(&esls_led_work[idx].work.work);
	}
}

bool esls_test_get_led_active(uint8_t idx)
{
	return (idx < CONFIG_BT_ESLS_LED_NUM) ? esls_led_work[idx].led_active : false;
}

#endif /* CONFIG_BT_ESLS_LED_NUM > 0 */

/* ── Image/OTS work-queue helpers ────────────────────────────────────────── */
#if CONFIG_BT_ESLS_IMAGE_NUM > 0

void esls_test_set_image_cbs(int (*write_fn)(uint8_t idx, uint8_t *data, uint16_t len),
			     int (*read_fn)(uint8_t idx, uint8_t *buf, uint16_t offset,
					    uint16_t len),
			     int (*size_fn)(uint8_t idx, uint16_t *size),
			     int (*name_fn)(uint8_t idx, char **name), int (*del_fn)(void))
{
	esls.init_param.write_image_data = write_fn;
	esls.init_param.read_image_data = read_fn;
	esls.init_param.read_image_size = size_fn;
	esls.init_param.get_image_name = name_fn;
	esls.init_param.delete_image_data = del_fn;
	/* Re-initialize the work item so handler is valid for obj_write submission. */
	k_work_init(&esls_write_img_work.work, esls_write_img_handler);
}

/* esls_obj_write does not dereference ots or conn; NULL is safe. */
ssize_t esls_test_call_obj_write(uint64_t id, const void *data, size_t len, off_t offset,
				 size_t rem)
{
	return esls_obj_write(NULL, NULL, id, data, len, offset, rem);
}

#endif /* CONFIG_BT_ESLS_IMAGE_NUM > 0 */

#endif /* CONFIG_ZTEST */
