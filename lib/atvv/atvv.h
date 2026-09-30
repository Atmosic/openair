/*
 * Copyright (c) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <stdint.h>
#include <zephyr/bluetooth/gatt.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Android TV Voice (ATVV) GATT service library. */

/** Audio packet sizes. */

#define ATVV_AUDIO_DATA_SIZE 128
#define ATVV_BYTES_PER_CHAR  20

#if defined(CONFIG_ATVV_SPEC_V1_0)
#define ATVV_FRAME_SIZE          ATVV_AUDIO_DATA_SIZE
#define ATVV_EXTRA_CONFIGURATION 0x01
#define ATVV_AUDIO_NOTIFY_COUNT  1
#else
/* v0.4e header: seqn (2) + padding (1) + predictor (2) + index (1). */
#define ATVV_FRAME_HEADER_SIZE  6
#define ATVV_FRAME_SIZE         (ATVV_FRAME_HEADER_SIZE + ATVV_AUDIO_DATA_SIZE)
#define ATVV_AUDIO_NOTIFY_COUNT ((ATVV_FRAME_SIZE + ATVV_BYTES_PER_CHAR - 1) / ATVV_BYTES_PER_CHAR)
#endif

/** Codec IDs reported in CAPS_RESP and MIC_OPEN/AUDIO_SYNC/AUDIO_START */
#define ATVV_CODEC_ADPCM_8K     BIT(0) /* 8 kHz, 16-bit PCM, ADPCM */
#define ATVV_CODEC_ADPCM_16K    BIT(1) /* 16 kHz, 16-bit PCM, ADPCM */
#define ATVV_CODEC_ADPCM_8K_16K (ATVV_CODEC_ADPCM_8K | ATVV_CODEC_ADPCM_16K)

/** CTL codes sent from remote to host */
#define ATVV_CTL_AUDIO_STOP   0x00
#define ATVV_CTL_AUDIO_START  0x04
#define ATVV_CTL_DPAD_SELECT  0x07
#define ATVV_CTL_SEARCH_START 0x08
#define ATVV_CTL_AUDIO_SYNC   0x0A
#define ATVV_CTL_CAPS_RESP    0x0B
#define ATVV_CTL_MIC_OPEN_ERR 0x0C

/** TX commands written by the host (appear in @ref atvv_cb_t.tx_recv) */
#define ATVV_TX_GET_CAPS   0x0A
#define ATVV_TX_MIC_OPEN   0x0C
#define ATVV_TX_MIC_CLOSE  0x0D
#define ATVV_TX_MIC_EXTEND 0x0E /* v1.0 only */

/** Protocol version wire values (big-endian u16: major.minor) */
#define ATVV_VERSION_V0_4 0x0004
#define ATVV_VERSION_V1_0 0x0100

/** MIC_OPEN_ERROR codes (shared by both spec versions) */
#define ATVV_ERR_INVALID_CODEC 0x0F01

/**
 * @brief Parameters for a CAPS_RESP message.
 *
 * The assistant interaction model is used by v1.0 and ignored by v0.4e.
 * The codec field is 8 bits on the v1.0 wire format and 16 bits on v0.4e;
 * callers should use the codec values defined by this header.
 */
struct atvv_caps_resp_params {
	uint16_t version;
	uint16_t codecs;
	uint8_t asst_model;
	uint16_t frame_size;
};

#if defined(CONFIG_ATVV_SPEC_V1_0)

/** v1.0 §4.5: assistant interaction model bitmask (GET_CAPS/CAPS_RESP) */
#define ATVV_ASST_MODEL_ON_REQUEST 0x00 /* On-request only (all remotes) */
#define ATVV_ASST_MODEL_PTT        0x01 /* + Press-to-Talk */
#define ATVV_ASST_MODEL_HTT        0x03 /* + Hold-to-Talk */

/** v1.0 §4.3.1: AUDIO_START reason codes */
#define ATVV_AUDIO_START_REASON_MIC_OPEN 0x00
#define ATVV_AUDIO_START_REASON_PTT      0x01
#define ATVV_AUDIO_START_REASON_HTT      0x03

/** v1.0 §4.3.1: AUDIO_STOP reason codes */
#define ATVV_AUDIO_STOP_REASON_MIC_CLOSE   0x00
#define ATVV_AUDIO_STOP_REASON_HTT_RELEASE 0x02
#define ATVV_AUDIO_STOP_REASON_AUDIO_START 0x04
#define ATVV_AUDIO_STOP_REASON_TIMEOUT     0x08
#define ATVV_AUDIO_STOP_REASON_NOTIFY_OFF  0x10
#define ATVV_AUDIO_STOP_REASON_OTHER       0x80

/** v1.0 §4.4: MIC_OPEN mic_mode values */
#define ATVV_MIC_MODE_PLAYBACK 0x00
#define ATVV_MIC_MODE_CAPTURE  0x01

/** v1.0 §4.4: stream_id well-known values */
#define ATVV_STREAM_ID_MIC_OPEN 0x00
#define ATVV_STREAM_ID_ANY      0xFF

/** v1.0 §4.4: extra MIC_OPEN_ERROR codes */
#define ATVV_ERR_REMOTE_NOT_ACTIVE 0x0F02
#define ATVV_ERR_AUDIO_NOTIFY_OFF  0x0F03
#define ATVV_ERR_PTT_HTT_ONGOING   0x0F80
#define ATVV_ERR_INTERNAL          0x0FFF

/**
 * v1.0 audio frame: raw ADPCM payload, no header (spec §4.2.2). Resync
 * uses AUDIO_SYNC (predictor + step index), not per-frame header fields.
 */
struct atvv_audio_frame {
	uint8_t val[ATVV_AUDIO_DATA_SIZE]; /* ADPCM payload */
} __packed;

#else /* CONFIG_ATVV_SPEC_V0_4 */

/** Full frame size including ATVV_FRAME_HEADER_SIZE bytes (header first, then data) */
/** v0.4e default bytes-per-characteristic reported in CAPS_RESP (20) */

/**
 * v0.4e audio frame layout (134 bytes, all multi-byte fields big-endian).
 *
 * Header (6 bytes) comes FIRST, then 128 bytes of ADPCM data:
 *   bytes 0-1: seqn  (sequence number, big-endian)
 *   byte  2:   0x00  (padding, always zero)
 *   bytes 3-4: prevp (ADPCM predictor, big-endian)
 *   byte  5:   idx   (ADPCM step-table index, 0–88)
 *   bytes 6-133: 128 bytes ADPCM-encoded audio (256 samples, high nibble first)
 */
struct atvv_audio_frame {
	uint16_t seqn;                     /* sequence number (big-endian) */
	uint8_t padding;                   /* always 0x00 */
	uint16_t prevp;                    /* ADPCM predictor (big-endian) */
	uint8_t idx;                       /* ADPCM step-table index (0–88) */
	uint8_t val[ATVV_AUDIO_DATA_SIZE]; /* ADPCM payload */
} __packed;

#endif /* CONFIG_ATVV_SPEC_V1_0 */

#if defined(CONFIG_ATVV_SPEC_V1_0)
BUILD_ASSERT(sizeof(struct atvv_audio_frame) == ATVV_AUDIO_DATA_SIZE,
	     "v1.0 audio payload size mismatch");
#else
BUILD_ASSERT(sizeof(struct atvv_audio_frame) == ATVV_FRAME_SIZE, "v0.4 audio frame size mismatch");
#endif

/** ATVV library state */
typedef enum {
	/** Disconnected or CCCs not yet enabled */
	ATVV_STATE_IDLE,
	/** Connected; CCCs not yet both enabled */
	ATVV_STATE_ENABLED,
	/** Both RX and CTL CCCs enabled; ready to stream */
	ATVV_STATE_READY,
} atvv_state_t;

/**
 * Application callbacks registered via @ref atvv_init.
 * Any field may be NULL to ignore the event.
 */
typedef struct {
	/**
	 * Called when the host writes a TX command (MIC_OPEN, MIC_CLOSE, …).
	 *
	 * @param cmd   TX command byte (ATVV_TX_MIC_OPEN etc.)
	 * @param data  Command parameters (may be NULL if len == 0)
	 * @param len   Length of @p data
	 */
	void (*tx_recv)(uint8_t cmd, const uint8_t *data, uint16_t len);

	/**
	 * Called when the ATVV state changes due to CCC writes or disconnection.
	 *
	 * @param state  New state
	 */
	void (*state_changed)(atvv_state_t state);
} atvv_cb_t;

/**
 * @brief Register application callbacks and prepare the ATVV service.
 *
 * Must be called before @c bt_enable().  Safe to call multiple times —
 * later calls replace the registered callbacks.
 *
 * @param cb  Application callbacks (may be NULL).
 */
void atvv_init(const atvv_cb_t *cb);

/**
 * @brief Send an audio frame notification on the RX characteristic.
 *
 * @p frame must point to a fully populated @ref atvv_audio_frame. With
 * CONFIG_ATVV_SPEC_V1_0, the library sends @p val as one logical
 * 128-byte RX notification; fill @p val only, with metadata carried by the
 * preceding AUDIO_SYNC control notification. With CONFIG_ATVV_SPEC_V0_4,
 * the complete frame is fragmented into ATVV_BYTES_PER_CHAR-byte
 * notifications and the six-byte frame header must also be filled.
 *
 * Only one logical audio frame is allowed in the ATT TX path at a time. The
 * next frame waits for the previous notification completion callback, with a
 * bounded timeout. Returns 0 on success, -ENOTCONN if RX notifications are
 * not enabled, -EAGAIN if the ATT TX path remains busy, or another negative
 * Zephyr BT error code.
 */
int atvv_send_audio_frame(const struct atvv_audio_frame *frame);

/**
 * @brief Send a control notification on the CTL characteristic.
 *
 * The CTL characteristic value is @p [code | data[0..len-1]].
 *
 * @param code  Control code (ATVV_CTL_* constant)
 * @param data  Optional parameters (may be NULL when len == 0)
 * @param len   Length of @p data
 *
 * Returns 0 on success, -ENOTCONN if CTL notifications are not enabled,
 * or a negative Zephyr BT error code.
 */
int atvv_send_ctl(uint8_t code, const uint8_t *data, uint8_t len);

/**
 * @brief Get the current ATVV state.
 */
atvv_state_t atvv_get_state(void);

/** Set the negotiated ATT MTU and validate v1.0 audio transport. */
int atvv_set_att_mtu(uint16_t mtu);

/** Reset connection-specific ATVV state and audio TX flow control. */
void atvv_reset_connection(void);

/**
 * @brief Send CAPS_RESP to the host.
 *
 * The payload format is selected by CONFIG_ATVV_SPEC_V1_0. The
 * configuration-specific wire formats are unchanged.
 *
 * @param params CAPS_RESP parameters.
 *
 * Returns 0 on success or a negative error code.
 */
int atvv_send_caps_resp(const struct atvv_caps_resp_params *params);

#if defined(CONFIG_ATVV_SPEC_V1_0)

/**
 * @brief Send AUDIO_START to the host (v1.0).
 *
 * v1.0 AUDIO_START payload (3 bytes): reason(1), codec_used(1), stream_id(1).
 *
 * @param reason      ATVV_AUDIO_START_REASON_* value.
 * @param codec_used  ATVV_CODEC_ADPCM_8K or ATVV_CODEC_ADPCM_16K.
 * @param stream_id   ATVV_STREAM_ID_MIC_OPEN (0x00) or an auto-incremented
 *                    PTT/HTT stream identifier (0x01..0x80).
 *
 * Returns 0 on success or a negative error code.
 */
int atvv_send_audio_start(uint8_t reason, uint8_t codec_used, uint8_t stream_id);

/**
 * @brief Send AUDIO_STOP to the host (v1.0).
 *
 * v1.0 AUDIO_STOP payload (1 byte): reason (ATVV_AUDIO_STOP_REASON_*).
 *
 * Returns 0 on success or a negative error code.
 */
int atvv_send_audio_stop(uint8_t reason);

/**
 * @brief Send AUDIO_SYNC to the host (v1.0).
 *
 * v1.0 AUDIO_SYNC payload (6 bytes): codec_used(1), frame_no(2, big-endian),
 * pred_value(2, big-endian), step_index(1).
 *
 * @param codec_used  Codec used for audio after this sync point.
 * @param frame_no    Sequence number of the frame about to be sent.
 * @param pred_value  Current ADPCM predictor.
 * @param step_index  Current ADPCM step-table index.
 *
 * Returns 0 on success or a negative error code.
 */
int atvv_send_audio_sync(uint8_t codec_used, uint16_t frame_no, int16_t pred_value,
			 uint8_t step_index);

#else /* CONFIG_ATVV_SPEC_V0_4 */

/**
 * @brief Send AUDIO_START to the host (no payload, per v0.4e spec).
 *
 * Sent by the remote in response to MIC_OPEN, before streaming audio frames.
 *
 * Returns 0 on success or a negative error code.
 */
int atvv_send_audio_start(void);

/**
 * @brief Send AUDIO_STOP to the host (no payload, per v0.4e spec).
 *
 * Signals the end of a voice session.
 *
 * Returns 0 on success or a negative error code.
 */
int atvv_send_audio_stop(void);

/**
 * @brief Send AUDIO_SYNC to the host (v0.4e).
 *
 * v0.4e AUDIO_SYNC payload (2 bytes): frame_num (big-endian).
 *
 * @param frame_num  16-bit frame sequence number (big-endian).
 *
 * Returns 0 on success or a negative error code.
 */
int atvv_send_audio_sync(uint16_t frame_num);

#endif /* CONFIG_ATVV_SPEC_V1_0 */

/**
 * @brief Send MIC_OPEN_ERROR to the host.
 *
 * @param error_code  16-bit error code (big-endian), e.g. ATVV_ERR_INVALID_CODEC.
 *
 * Returns 0 on success or a negative error code.
 */
int atvv_send_mic_open_error(uint16_t error_code);

#ifdef __cplusplus
}
#endif
