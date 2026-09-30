/*
 * Copyright (c) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/sys/atomic.h>
#include <zephyr/sys/util.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/logging/log.h>

#include "atvv.h"

LOG_MODULE_REGISTER(atvv, CONFIG_ATVV_LOG_LEVEL);

/* -------------------------------------------------------------------------
 * ATVV 128-bit UUIDs
 *
 * Base: AB5Exxxx-5A21-4F05-BC7D-AF01F617B664
 * -----------------------------------------------------------------------*/

/* AB5E0001-5A21-4F05-BC7D-AF01F617B664 */
#define ATVV_UUID_SVC BT_UUID_128_ENCODE(0xAB5E0001, 0x5A21, 0x4F05, 0xBC7D, 0xAF01F617B664)

/* AB5E0002-5A21-4F05-BC7D-AF01F617B664 (host writes commands here) */
#define ATVV_UUID_TX BT_UUID_128_ENCODE(0xAB5E0002, 0x5A21, 0x4F05, 0xBC7D, 0xAF01F617B664)

/* AB5E0003-5A21-4F05-BC7D-AF01F617B664 (remote notifies audio here) */
#define ATVV_UUID_RX BT_UUID_128_ENCODE(0xAB5E0003, 0x5A21, 0x4F05, 0xBC7D, 0xAF01F617B664)

/* AB5E0004-5A21-4F05-BC7D-AF01F617B664 (remote notifies control here) */
#define ATVV_UUID_CTL BT_UUID_128_ENCODE(0xAB5E0004, 0x5A21, 0x4F05, 0xBC7D, 0xAF01F617B664)

static struct bt_uuid_128 uuid_svc = BT_UUID_INIT_128(ATVV_UUID_SVC);
static struct bt_uuid_128 uuid_tx = BT_UUID_INIT_128(ATVV_UUID_TX);
static struct bt_uuid_128 uuid_rx = BT_UUID_INIT_128(ATVV_UUID_RX);
static struct bt_uuid_128 uuid_ctl = BT_UUID_INIT_128(ATVV_UUID_CTL);

/* Leading command/code byte that prefixes TX writes and CTL notifications */
#define ATVV_CMD_HDR_LEN 1

/* -------------------------------------------------------------------------
 * Runtime state
 * -----------------------------------------------------------------------*/

static const atvv_cb_t *user_cb;
static atvv_state_t atvv_state = ATVV_STATE_IDLE;
static bool rx_notify_enabled;
static bool ctl_notify_enabled;
#if defined(CONFIG_ATVV_SPEC_V1_0)
static bool audio_mtu_ready;
#endif

/* Keep at most one logical audio frame in the ATT TX path. This mirrors the
 * bare-metal audio-buffer flow control and leaves ATT resources available for
 * CTL notifications such as AUDIO_STOP. */
#define ATVV_AUDIO_TX_WAIT_MS 100
static K_SEM_DEFINE(audio_tx_sem, 1, 1);
static atomic_t audio_notify_pending;

static void audio_notify_complete(struct bt_conn *conn, void *user_data)
{
	ARG_UNUSED(conn);
	ARG_UNUSED(user_data);
	if (atomic_get(&audio_notify_pending) <= 0) {
		return;
	}
	if (atomic_dec(&audio_notify_pending) == 1) {
		k_sem_give(&audio_tx_sem);
	}
}

static void reset_audio_tx_state(void)
{
	atomic_set(&audio_notify_pending, 0);
	k_sem_reset(&audio_tx_sem);
	k_sem_give(&audio_tx_sem);
}

static void update_state(void)
{
	atvv_state_t new_state;

	if (rx_notify_enabled && ctl_notify_enabled) {
		new_state = ATVV_STATE_READY;
	} else if (rx_notify_enabled || ctl_notify_enabled) {
		new_state = ATVV_STATE_ENABLED;
	} else {
		new_state = ATVV_STATE_IDLE;
	}

	if (new_state != atvv_state) {
		atvv_state = new_state;
		LOG_INF("state -> %d", atvv_state);
		if (user_cb && user_cb->state_changed) {
			user_cb->state_changed(atvv_state);
		}
	}
}

/* -------------------------------------------------------------------------
 * GATT callbacks
 * -----------------------------------------------------------------------*/

static ssize_t write_tx(struct bt_conn *conn, const struct bt_gatt_attr *attr, const void *buf,
			uint16_t len, uint16_t offset, uint8_t flags)
{
	if (len == 0) {
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_ATTRIBUTE_LEN);
	}

	const uint8_t *data = buf;
	uint8_t cmd = data[0];
	const uint8_t *params = (len > ATVV_CMD_HDR_LEN) ? &data[ATVV_CMD_HDR_LEN] : NULL;
	uint16_t params_len = (len > ATVV_CMD_HDR_LEN) ? (len - ATVV_CMD_HDR_LEN) : 0;

	LOG_DBG("TX cmd=0x%02x len=%u", cmd, params_len);

	if (user_cb && user_cb->tx_recv) {
		user_cb->tx_recv(cmd, params, params_len);
	}

	return len;
}

static ssize_t read_empty(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf,
			  uint16_t len, uint16_t offset)
{
	return bt_gatt_attr_read(conn, attr, buf, len, offset, NULL, 0);
}

static void rx_ccc_changed(const struct bt_gatt_attr *attr, uint16_t value)
{
	rx_notify_enabled = (value == BT_GATT_CCC_NOTIFY);
	LOG_INF("RX CCC: %u", value);
	update_state();
}

static void ctl_ccc_changed(const struct bt_gatt_attr *attr, uint16_t value)
{
	ctl_notify_enabled = (value == BT_GATT_CCC_NOTIFY);
	LOG_INF("CTL CCC: %u", value);
	update_state();
}

/* GATT service definition. */

BT_GATT_SERVICE_DEFINE(
	atvv_svc, BT_GATT_PRIMARY_SERVICE(&uuid_svc),

	/* TX: host writes commands (write-without-response for v1.0) */
	BT_GATT_CHARACTERISTIC(&uuid_tx.uuid, BT_GATT_CHRC_WRITE | BT_GATT_CHRC_WRITE_WITHOUT_RESP,
			       BT_GATT_PERM_WRITE, NULL, write_tx, NULL),

	/* RX: remote notifies audio frames */
	BT_GATT_CHARACTERISTIC(&uuid_rx.uuid, BT_GATT_CHRC_READ | BT_GATT_CHRC_NOTIFY,
			       BT_GATT_PERM_READ, read_empty, NULL, NULL),
	BT_GATT_CCC(rx_ccc_changed, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),

	/* CTL: remote notifies control messages */
	BT_GATT_CHARACTERISTIC(&uuid_ctl.uuid, BT_GATT_CHRC_READ | BT_GATT_CHRC_NOTIFY,
			       BT_GATT_PERM_READ, read_empty, NULL, NULL),
	BT_GATT_CCC(ctl_ccc_changed, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE), );

/* Attribute indices used as notification targets. */
#define ATVV_ATTR_IDX_RX_VAL  4
#define ATVV_ATTR_IDX_CTL_VAL 7

/* -------------------------------------------------------------------------
 * Public API
 * -----------------------------------------------------------------------*/

void atvv_init(const atvv_cb_t *cb)
{
	user_cb = cb;
	reset_audio_tx_state();
	LOG_INF("ATVV service registered");
}

int atvv_set_att_mtu(uint16_t mtu)
{
#if defined(CONFIG_ATVV_SPEC_V1_0)
	audio_mtu_ready = mtu >= (ATVV_AUDIO_DATA_SIZE + 3U);
	return audio_mtu_ready ? 0 : -EMSGSIZE;
#else
	ARG_UNUSED(mtu);
	return 0;
#endif
}

void atvv_reset_connection(void)
{
	rx_notify_enabled = false;
	ctl_notify_enabled = false;
#if defined(CONFIG_ATVV_SPEC_V1_0)
	audio_mtu_ready = false;
#endif
	reset_audio_tx_state();
	update_state();
}

int atvv_send_audio_frame(const struct atvv_audio_frame *frame)
{
	if (!rx_notify_enabled) {
		return -ENOTCONN;
	}

#if defined(CONFIG_ATVV_SPEC_V1_0)
	if (!audio_mtu_ready) {
		LOG_ERR("audio TX rejected: ATT MTU is too small");
		return -EMSGSIZE;
	}
#endif

	/* Wait until the previous logical frame has left the ATT TX path. The
	 * timeout prevents a stalled/disconnected link from blocking audio forever.
	 */
	int ret = k_sem_take(&audio_tx_sem, K_MSEC(ATVV_AUDIO_TX_WAIT_MS));
	if (ret) {
		LOG_WRN("audio TX busy, dropping frame (%d)", ret);
		return -EAGAIN;
	}

	const uint8_t *audio;
	size_t audio_len;

#if defined(CONFIG_ATVV_SPEC_V1_0)
	/* v1.0 sends only the pure ADPCM array; the metadata is not on RX. */
	audio = frame->val;
	audio_len = sizeof(frame->val);
#else
	/* v0.4 sends the complete logical packet, including its header. */
	audio = (const uint8_t *)frame;
	audio_len = sizeof(*frame);
#endif

	ret = 0;
#if defined(CONFIG_ATVV_SPEC_V1_0)
	/* v1.0 advertises a 128-byte frame and requests ATT DLE. */
	size_t notify_size = audio_len;
#else
	size_t notify_size = ATVV_BYTES_PER_CHAR;
#endif
	size_t notify_count = (audio_len + notify_size - 1) / notify_size;
	atomic_set(&audio_notify_pending, notify_count);
	size_t offset;
	for (offset = 0; offset < audio_len; offset += notify_size) {
		struct bt_gatt_notify_params params = {0};
		params.attr = &atvv_svc.attrs[ATVV_ATTR_IDX_RX_VAL];
		params.data = &audio[offset];
		params.len = MIN(notify_size, audio_len - offset);
		params.func = audio_notify_complete;

		ret = bt_gatt_notify_cb(NULL, &params);
		if (ret) {
			LOG_WRN("RX notify chunk %u/%u err %d",
				(unsigned)(offset / notify_size + 1),
				(unsigned)((audio_len + notify_size - 1) / notify_size), ret);
			break;
		}
	}

	if (ret) {
		/* No completion callback is generated for this failed chunk or any
		 * chunks after it. Remove those notifications from the pending count. */
		size_t sent_count = offset / notify_size;
		size_t unsent_count = notify_count - sent_count;
		if (atomic_sub(&audio_notify_pending, unsent_count) == unsent_count) {
			k_sem_give(&audio_tx_sem);
		}
	}

	return ret;
}

int atvv_send_ctl(uint8_t code, const uint8_t *data, uint8_t len)
{
	if (!ctl_notify_enabled) {
		return -ENOTCONN;
	}

	/* CTL value: [code | data...], max ATVV_CMD_HDR_LEN + len bytes */
	uint8_t buf[ATVV_CMD_HDR_LEN + len];
	buf[0] = code;
	if (data && len) {
		memcpy(&buf[ATVV_CMD_HDR_LEN], data, len);
	}

	struct bt_gatt_notify_params params = {0};
	params.attr = &atvv_svc.attrs[ATVV_ATTR_IDX_CTL_VAL];
	params.data = buf;
	params.len = ATVV_CMD_HDR_LEN + len;

	int ret = bt_gatt_notify_cb(NULL, &params);
	if (ret) {
		LOG_WRN("CTL notify err %d", ret);
	}
	return ret;
}

atvv_state_t atvv_get_state(void)
{
	return atvv_state;
}

int atvv_send_caps_resp(const struct atvv_caps_resp_params *params)
{
	uint8_t payload[8];

#if defined(CONFIG_ATVV_SPEC_V1_0)
	/*
	 * v1.0 CAPS_RESP payload (8 bytes following the CTL code byte):
	 *   [0-1] version                        (big-endian)
	 *   [2]   codecs_supported
	 *   [3]   assistant_interaction_model
	 *   [4-5] audio_frame_size               (big-endian)
	 *   [6]   extra_configuration (0x00: no DLE request)
	 *   [7]   reserved (0x00)
	 */
	sys_put_be16(params->version, &payload[0]);
	payload[2] = (uint8_t)params->codecs;
	payload[3] = params->asst_model;
	sys_put_be16(params->frame_size, &payload[4]);
	payload[6] = ATVV_EXTRA_CONFIGURATION;
	payload[7] = 0x00;

	LOG_INF("CAPS_RESP ver=0x%04x codec=0x%02x model=0x%02x frame=%u", params->version,
		params->codecs, params->asst_model, params->frame_size);
#else
	/*
	 * v0.4e CAPS_RESP payload (8 bytes following the CTL code byte):
	 *   [0-1] version             (big-endian)
	 *   [2-3] codecs_supported    (big-endian)
	 *   [4-5] bytes per frame     (big-endian)
	 *   [6-7] bytes per characteristic (big-endian)
	 */
	sys_put_be16(params->version, &payload[0]);
	sys_put_be16(params->codecs, &payload[2]);
	sys_put_be16(params->frame_size, &payload[4]);
	sys_put_be16(ATVV_BYTES_PER_CHAR, &payload[6]);

	LOG_INF("CAPS_RESP ver=0x%04x codec=0x%04x frame=%u", params->version, params->codecs,
		params->frame_size);
#endif

	return atvv_send_ctl(ATVV_CTL_CAPS_RESP, payload, sizeof(payload));
}

int atvv_send_audio_start(
#if defined(CONFIG_ATVV_SPEC_V1_0)
	uint8_t reason, uint8_t codec_used, uint8_t stream_id
#else
	void
#endif
)
{
#if defined(CONFIG_ATVV_SPEC_V1_0)
	/* v1.0 AUDIO_START payload: reason(1), codec_used(1), stream_id(1) */
	uint8_t payload[3] = {reason, codec_used, stream_id};

	LOG_INF("AUDIO_START reason=0x%02x codec=0x%02x stream=0x%02x", reason, codec_used,
		stream_id);
	return atvv_send_ctl(ATVV_CTL_AUDIO_START, payload, sizeof(payload));
#else
	/* v0.4e: AUDIO_START has no payload — just the CTL code byte */
	LOG_INF("AUDIO_START");
	return atvv_send_ctl(ATVV_CTL_AUDIO_START, NULL, 0);
#endif
}

int atvv_send_audio_stop(
#if defined(CONFIG_ATVV_SPEC_V1_0)
	uint8_t reason
#else
	void
#endif
)
{
#if defined(CONFIG_ATVV_SPEC_V1_0)
	/* v1.0 AUDIO_STOP payload: reason(1) */
	LOG_INF("AUDIO_STOP reason=0x%02x", reason);
	return atvv_send_ctl(ATVV_CTL_AUDIO_STOP, &reason, sizeof(reason));
#else
	/* v0.4e: AUDIO_STOP has no payload — just the CTL code byte */
	LOG_INF("AUDIO_STOP");
	return atvv_send_ctl(ATVV_CTL_AUDIO_STOP, NULL, 0);
#endif
}

int atvv_send_audio_sync(
#if defined(CONFIG_ATVV_SPEC_V1_0)
	uint8_t codec_used, uint16_t frame_no, int16_t pred_value, uint8_t step_index
#else
	uint16_t frame_no
#endif
)
{
#if defined(CONFIG_ATVV_SPEC_V1_0)
	/*
	 * v1.0 AUDIO_SYNC payload (6 bytes):
	 *   [0]   codec_used
	 *   [1-2] frame_no     (big-endian)
	 *   [3-4] pred_value   (big-endian)
	 *   [5]   step_index
	 */
	uint8_t payload[6];

	payload[0] = codec_used;
	sys_put_be16(frame_no, &payload[1]);
	sys_put_be16((uint16_t)pred_value, &payload[3]);
	payload[5] = step_index;

	LOG_DBG("AUDIO_SYNC codec=0x%02x frame=%u pred=%d idx=%u", codec_used, frame_no, pred_value,
		step_index);
	return atvv_send_ctl(ATVV_CTL_AUDIO_SYNC, payload, sizeof(payload));
#else
	uint8_t payload[2];
	sys_put_be16(frame_no, payload);
	LOG_DBG("AUDIO_SYNC frame=%u", frame_no);
	return atvv_send_ctl(ATVV_CTL_AUDIO_SYNC, payload, sizeof(payload));
#endif
}

int atvv_send_mic_open_error(uint16_t error_code)
{
	uint8_t payload[2];
	sys_put_be16(error_code, payload);
	LOG_INF("MIC_OPEN_ERROR code=0x%04x", error_code);
	return atvv_send_ctl(ATVV_CTL_MIC_OPEN_ERR, payload, sizeof(payload));
}

#ifdef CONFIG_ZTEST
void atvv_test_simulate_rx_ccc(uint16_t value)
{
	rx_ccc_changed(NULL, value);
}

void atvv_test_simulate_ctl_ccc(uint16_t value)
{
	ctl_ccc_changed(NULL, value);
}

ssize_t atvv_test_write_tx(const void *buf, uint16_t len)
{
	return write_tx(NULL, NULL, buf, len, 0, 0);
}

ssize_t atvv_test_read_empty(void *buf, uint16_t len)
{
	return read_empty(NULL, NULL, buf, len, 0);
}
#endif /* CONFIG_ZTEST */
