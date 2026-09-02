/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include "rc_audio.h"
#include "rc_mmi.h"
#include "atvv.h"

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/logging/log_ctrl.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/settings/settings.h>

#if defined(CONFIG_DMIC_ATM)
#include "adpcm_enc.h"
#include <zephyr/audio/dmic.h>
#endif

LOG_MODULE_REGISTER(rc_audio, CONFIG_HID_REMOTE_LOG_LEVEL);

#define RC_ATVV_SETTINGS_KEY "atvv/cfg"

static bool atvv_configured;

#if defined(CONFIG_DMIC_ATM)
/* DMIC to ADPCM to ATVV streaming pipeline. */
/* The PDM block contains 32 samples; one ATVV frame contains 256 samples. */
#define PP_BUFFER_WORDS 16
#define PP_SAMPLES      (PP_BUFFER_WORDS * 2)
#if defined(CONFIG_RC_ATVV_AUDIO_RATE_16KHZ)
#define AUDIO_SAMPLE_RATE 16000
#else
#define AUDIO_SAMPLE_RATE 8000
#endif
#define PCM_WIDTH_BITS        16
#define BLOCK_SIZE            (PP_SAMPLES * sizeof(int16_t)) /* 64 bytes */
#define PCM_SAMPLES_PER_FRAME (ATVV_AUDIO_DATA_SIZE * 2)
#define NUM_SLAB_BLOCKS       ((PCM_SAMPLES_PER_FRAME + PP_SAMPLES - 1) / PP_SAMPLES + 4)

K_MEM_SLAB_DEFINE_STATIC(audio_slab, BLOCK_SIZE, NUM_SLAB_BLOCKS, 4);

static const struct device *dmic_dev = DEVICE_DT_GET(DT_NODELABEL(pdm0));

static volatile bool streaming_active;
static uint16_t frame_seq;
static struct k_sem stream_sem;

#define AUDIO_STACK_SIZE 2048
static K_THREAD_STACK_DEFINE(audio_stack, AUDIO_STACK_SIZE);
static struct k_thread audio_tid;

/* Send AUDIO_SYNC periodically, including frame 0. */
#define SYNC_PERIOD_FRAMES 20

#ifdef CONFIG_RC_PDM_DEBUG
/* Optional debug capture buffers. */
#define PDM_DBG_DUMP_FRAMES 125
static int16_t pdm_dbg_pcm[PDM_DBG_DUMP_FRAMES * PCM_SAMPLES_PER_FRAME];
static uint8_t pdm_dbg_adpcm[PDM_DBG_DUMP_FRAMES * ATVV_AUDIO_DATA_SIZE];
static uint32_t pdm_dbg_frame_cnt;
#endif
#endif /* CONFIG_DMIC_ATM */

static int atvv_cfg_set(const char *key, size_t len, settings_read_cb read_cb, void *cb_arg)
{
	ARG_UNUSED(key);
	if (len != sizeof(atvv_configured)) {
		return -EINVAL;
	}
	int rc = read_cb(cb_arg, &atvv_configured, sizeof(atvv_configured));
	return rc < 0 ? rc : 0;
}

SETTINGS_STATIC_HANDLER_DEFINE(rc_atvv, "atvv", NULL, atvv_cfg_set, NULL, NULL);

static void atvv_save_configured(bool configured)
{
	atvv_configured = configured;
	settings_save_one(RC_ATVV_SETTINGS_KEY, &atvv_configured, sizeof(atvv_configured));
}

/* ATVV callbacks. */

#if defined(CONFIG_ATVV_SPEC_V1_0)

#if defined(CONFIG_RC_ATVV_AUDIO_RATE_16KHZ)
#define RC_ATVV_CODEC_USED ATVV_CODEC_ADPCM_16K
#else
#define RC_ATVV_CODEC_USED ATVV_CODEC_ADPCM_8K
#endif
#define RC_ATVV_CODECS_SUPPORTED ATVV_CODEC_ADPCM_8K_16K

/* Assistant interaction model reported in CAPS_RESP. */
#if defined(CONFIG_RC_ATVV_ASST_MODEL_HTT)
#define RC_ATVV_MODEL ATVV_ASST_MODEL_HTT
#elif defined(CONFIG_RC_ATVV_ASST_MODEL_PTT)
#define RC_ATVV_MODEL ATVV_ASST_MODEL_PTT
#else /* CONFIG_RC_ATVV_ASST_MODEL_ON_REQUEST */
#define RC_ATVV_MODEL ATVV_ASST_MODEL_ON_REQUEST
#endif

/* Current ATVV stream ID. */
static uint8_t current_stream_id;
/* True while an ATVV audio session is active. */
static bool session_active;

#if defined(CONFIG_RC_ATVV_ASST_MODEL_PTT) || defined(CONFIG_RC_ATVV_ASST_MODEL_HTT)
/* Allocate PTT/HTT stream IDs. */
static uint8_t alloc_stream_id(void)
{
	static uint8_t next_id = 0x01;
	uint8_t id = next_id;

	next_id = (next_id >= 0x80) ? 0x01 : (uint8_t)(next_id + 1);
	return id;
}
#endif

#endif /* CONFIG_ATVV_SPEC_V1_0 */

/* Audio transfer timeout. */

static void audio_timeout_handler(struct k_work *work);
static K_WORK_DELAYABLE_DEFINE(audio_timeout_work, audio_timeout_handler);

/* Start or reset the audio timeout. */
static void audio_timeout_start(void)
{
	k_work_reschedule(&audio_timeout_work, K_MSEC(CONFIG_RC_AUDIO_STREAM_TIMEOUT_CS * 10));
	LOG_DBG("Audio Transfer Timeout started/reset (%u cs)", CONFIG_RC_AUDIO_STREAM_TIMEOUT_CS);
}

static void audio_timeout_stop(void)
{
	k_work_cancel_delayable(&audio_timeout_work);
}

static void audio_timeout_handler(struct k_work *work)
{
	LOG_WRN("Audio Transfer Timeout expired — stopping stream");
	rc_audio_stream_stop();
	rc_mmi_run_event(MMI_OP_CLOSE_MIC);
#if defined(CONFIG_ATVV_SPEC_V1_0)
	atvv_send_audio_stop(ATVV_AUDIO_STOP_REASON_TIMEOUT);
	session_active = false;
#else
	atvv_send_audio_stop();
#endif
}

static void atvv_tx_recv_cb(uint8_t cmd, uint8_t const *data, uint16_t len)
{
	switch (cmd) {
	case ATVV_TX_GET_CAPS:
		/* Host requests capabilities — respond with CAPS_RESP */
		LOG_INF("GET_CAPS");
#if defined(CONFIG_ATVV_SPEC_V1_0)
		const struct atvv_caps_resp_params caps = {
			.version = ATVV_VERSION_V1_0,
			.codecs = RC_ATVV_CODECS_SUPPORTED,
			.asst_model = RC_ATVV_MODEL,
			.frame_size = ATVV_FRAME_SIZE,
		};
#else
		const struct atvv_caps_resp_params caps = {
			.version = ATVV_VERSION_V0_4,
			.codecs = ATVV_CODEC_ADPCM_8K,
			.asst_model = 0,
			.frame_size = ATVV_FRAME_SIZE,
		};
#endif
		atvv_send_caps_resp(&caps);
		atvv_save_configured(true);
		break;
	case ATVV_TX_MIC_OPEN: {
#if defined(CONFIG_ATVV_SPEC_V1_0)
		if (atvv_get_state() != ATVV_STATE_READY || len != 1) {
			LOG_WRN("MIC_OPEN ignored: state=%d len=%u", atvv_get_state(), len);
			break;
		}

		/* v1.0 MIC_OPEN contains mic_mode; the codec comes from configuration. */
		uint8_t mic_mode = (len >= 1) ? data[0] : ATVV_MIC_MODE_PLAYBACK;

		LOG_INF("MIC_OPEN mic_mode=0x%02x codec=0x%02x", mic_mode,
			(unsigned)RC_ATVV_CODEC_USED);

		if (session_active) {
			if (current_stream_id != ATVV_STREAM_ID_MIC_OPEN) {
				LOG_WRN("MIC_OPEN rejected: PTT/HTT stream ongoing");
				atvv_send_mic_open_error(ATVV_ERR_PTT_HTT_ONGOING);
			} else {
				LOG_DBG("MIC_OPEN ignored: stream already active");
			}
			break;
		}
		current_stream_id = ATVV_STREAM_ID_MIC_OPEN;
		session_active = true;
		atvv_send_audio_start(ATVV_AUDIO_START_REASON_MIC_OPEN, RC_ATVV_CODEC_USED,
				      current_stream_id);
		audio_timeout_start();
#else
		if (atvv_get_state() != ATVV_STATE_READY || len != 2) {
			LOG_WRN("MIC_OPEN ignored: state=%d len=%u", atvv_get_state(), len);
			break;
		}

		/* v0.4e MIC_OPEN payload: codec_used(2, big-endian) */
		uint16_t codec_used = (len >= 2) ? sys_get_be16(data) : ATVV_CODEC_ADPCM_8K;

		LOG_INF("MIC_OPEN codec=0x%04x", codec_used);
		if (codec_used != ATVV_CODEC_ADPCM_8K) {
			LOG_WRN("Unsupported codec 0x%04x", codec_used);
			atvv_send_mic_open_error(ATVV_ERR_INVALID_CODEC);
			break;
		}
		atvv_send_audio_start();
		audio_timeout_start();
#endif
		rc_mmi_run_event(MMI_OP_OPEN_MIC);
		break;
	}
	case ATVV_TX_MIC_CLOSE:
#if defined(CONFIG_ATVV_SPEC_V1_0)
	{
		if (!session_active) {
			LOG_DBG("MIC_CLOSE ignored: no active session");
			break;
		}

		/* v1.0 MIC_CLOSE contains the stream ID. */
		uint8_t req_id = (len >= 1) ? data[0] : ATVV_STREAM_ID_ANY;

		LOG_INF("MIC_CLOSE stream_id=0x%02x (active=0x%02x)", req_id, current_stream_id);
		if (req_id != ATVV_STREAM_ID_ANY && req_id != current_stream_id) {
			LOG_DBG("MIC_CLOSE stream_id mismatch — ignored");
			break;
		}
		audio_timeout_stop();
		rc_audio_stream_stop();
		atvv_send_audio_stop(ATVV_AUDIO_STOP_REASON_MIC_CLOSE);
		session_active = false;
	}
#else
		LOG_INF("MIC_CLOSE");
		audio_timeout_stop();
		rc_audio_stream_stop();
		atvv_send_audio_stop();
#endif
		rc_mmi_run_event(MMI_OP_CLOSE_MIC);
		break;
#if defined(CONFIG_ATVV_SPEC_V1_0)
	case ATVV_TX_MIC_EXTEND:
		/* Keep the audio timeout alive. */
		LOG_DBG("MIC_EXTEND stream_id=0x%02x", (len >= 1) ? data[0] : 0xFF);
		if (session_active) {
			audio_timeout_start(); /* reset the timer */
		}
		break;
#endif
	default:
		LOG_DBG("ATVV TX cmd 0x%02x (unhandled)", cmd);
		break;
	}
}

static void atvv_state_changed_cb(atvv_state_t state)
{
	LOG_INF("ATVV state -> %d", state);
	switch (state) {
	case ATVV_STATE_READY:
		rc_mmi_run_event(MMI_OP_ATVV_READY);
		break;
	case ATVV_STATE_IDLE:
#if defined(CONFIG_ATVV_SPEC_V1_0)
		audio_timeout_stop();
		session_active = false;
		current_stream_id = ATVV_STREAM_ID_MIC_OPEN;
#endif
		atvv_save_configured(false);
		rc_mmi_run_event(MMI_OP_ATVV_UNREADY);
		break;
	case ATVV_STATE_ENABLED:
		rc_mmi_run_event(MMI_OP_ATVV_UNREADY);
		break;
	}
}

static atvv_cb_t const atvv_cbs = {
	.tx_recv = atvv_tx_recv_cb,
	.state_changed = atvv_state_changed_cb,
};

bool rc_audio_atvv_was_configured(void)
{
	return atvv_configured;
}

#if defined(CONFIG_DMIC_ATM)
static void audio_thread_fn(void *p1, void *p2, void *p3)
{
	static int16_t pcm_acc[PCM_SAMPLES_PER_FRAME];
	static int16_t block_pcm[PP_SAMPLES];
	size_t pcm_samples = 0;
	bool mtu_error = false;

	/* Reset the encoder at the start of each session. */
	adpcm_reset();

#ifdef CONFIG_RC_PDM_DEBUG
	pdm_dbg_frame_cnt = 0;
#endif

	while (streaming_active) {
		void *buf = NULL;
		size_t size = 0;
		int ret = dmic_read(dmic_dev, 0, &buf, &size, 200);
		if (ret) {
			if (ret != -EAGAIN) {
				LOG_ERR("dmic_read err %d", ret);
			}
			continue;
		}

		size_t sample_count = MIN(size / sizeof(int16_t), ARRAY_SIZE(block_pcm));
		memcpy(block_pcm, buf, sample_count * sizeof(int16_t));
		k_mem_slab_free(&audio_slab, buf);

		for (size_t i = 0; i < sample_count; i++) {
			pcm_acc[pcm_samples++] = block_pcm[i];
			if (pcm_samples < PCM_SAMPLES_PER_FRAME) {
				continue;
			}

			/* Capture the encoder state before this frame. */
			struct atvv_audio_frame frame = {};
			uint8_t predictor_idx = 0;
			int32_t predictor_val = adpcm_get_index(&predictor_idx);
			uint16_t this_frame_no = frame_seq;
			bool need_sync = (this_frame_no % SYNC_PERIOD_FRAMES) == 0;

			/* Encode one frame. */
			adpcm_encode_buf(pcm_acc, frame.val, PCM_SAMPLES_PER_FRAME);
			frame_seq++;

#ifdef CONFIG_RC_PDM_DEBUG
			if (pdm_dbg_frame_cnt < PDM_DBG_DUMP_FRAMES) {
				memcpy(&pdm_dbg_pcm[pdm_dbg_frame_cnt * PCM_SAMPLES_PER_FRAME],
				       pcm_acc, PCM_SAMPLES_PER_FRAME * sizeof(int16_t));
				memcpy(&pdm_dbg_adpcm[pdm_dbg_frame_cnt * ATVV_AUDIO_DATA_SIZE],
				       frame.val, ATVV_AUDIO_DATA_SIZE);
				pdm_dbg_frame_cnt++;
			}
#endif

			/* Continue remaining samples in the next frame. */
			pcm_samples = 0;

#if defined(CONFIG_ATVV_SPEC_V1_0)
			/* v1.0 sends state in periodic AUDIO_SYNC messages. */
			if (need_sync) {
				/* Count logical audio notifications. */
				uint16_t notify_seq = this_frame_no * ATVV_AUDIO_NOTIFY_COUNT;
				int sync_ret =
					atvv_send_audio_sync(RC_ATVV_CODEC_USED, notify_seq,
							     (int16_t)predictor_val, predictor_idx);
				if (sync_ret) {
					LOG_WRN("ATVV AUDIO_SYNC failed: %d, seq=%u", sync_ret,
						notify_seq);
				}
			}
			int send_ret = atvv_send_audio_frame(&frame);
			if (send_ret == -EMSGSIZE) {
				LOG_ERR("ATVV audio stopped: insufficient ATT MTU");
				streaming_active = false;
				mtu_error = true;
			} else if (send_ret) {
				LOG_WRN("ATVV audio packet dropped (%d), frame=%u", send_ret,
					this_frame_no);
			}
#else
			/* v0.4e carries state in the frame header. */
			frame.idx = predictor_idx;
			frame.prevp = sys_cpu_to_be16((int16_t)predictor_val);
			frame.seqn = sys_cpu_to_be16(this_frame_no);
			frame.padding = 0x00;

			int send_ret = atvv_send_audio_frame(&frame);
			if (send_ret == -EMSGSIZE) {
				LOG_ERR("ATVV audio stopped: insufficient ATT MTU");
				streaming_active = false;
				mtu_error = true;
			} else if (send_ret) {
				LOG_DBG("ATVV send dropped (%d)", send_ret);
			}
			if (need_sync) {
				atvv_send_audio_sync(this_frame_no);
			}
#endif
		}
	}

	dmic_trigger(dmic_dev, DMIC_TRIGGER_STOP);
	LOG_INF("audio thread stopped");
	if (mtu_error) {
#if defined(CONFIG_ATVV_SPEC_V1_0)
		atvv_send_audio_stop(ATVV_AUDIO_STOP_REASON_OTHER);
#else
		atvv_send_audio_stop();
#endif
		rc_mmi_run_event(MMI_OP_CLOSE_MIC);
	}

#ifdef CONFIG_RC_PDM_DEBUG
	/* Serialize optional debug output. */
	LOG_PANIC();
	LOG_INF("=== PDM DBG dump: %u frames ===", pdm_dbg_frame_cnt);
	for (uint32_t i = 0; i < pdm_dbg_frame_cnt; i++) {
		LOG_HEXDUMP_INF(&pdm_dbg_pcm[i * PCM_SAMPLES_PER_FRAME],
				PCM_SAMPLES_PER_FRAME * sizeof(int16_t), "PCM");
	}
	LOG_INF("=== PDM DBG dump end ===");
	LOG_INF("=== ADPCM DBG dump: %u frames, %u bytes/frame ===", pdm_dbg_frame_cnt,
		ATVV_AUDIO_DATA_SIZE);
	for (uint32_t i = 0; i < pdm_dbg_frame_cnt; i++) {
		LOG_HEXDUMP_INF(&pdm_dbg_adpcm[i * ATVV_AUDIO_DATA_SIZE], ATVV_AUDIO_DATA_SIZE,
				"ADPCM");
	}
	LOG_INF("=== ADPCM DBG dump end ===");
#endif
}

static int dmic_start_capture(void)
{
	struct pcm_stream_cfg stream = {
		.pcm_rate = AUDIO_SAMPLE_RATE,
		.pcm_width = PCM_WIDTH_BITS,
		.block_size = BLOCK_SIZE,
		.mem_slab = &audio_slab,
	};
	struct dmic_cfg cfg = {
		.io =
			{
				.min_pdm_clk_freq = 1000000,
				.max_pdm_clk_freq = 4000000,
				.min_pdm_clk_dc = 40,
				.max_pdm_clk_dc = 60,
			},
		.streams = &stream,
		.channel =
			{
				.req_num_chan = 1,
				.req_num_streams = 1,
			},
	};

	int ret = dmic_configure(dmic_dev, &cfg);
	if (ret) {
		LOG_ERR("dmic_configure err %d", ret);
		return ret;
	}

	ret = dmic_trigger(dmic_dev, DMIC_TRIGGER_START);
	if (ret) {
		LOG_ERR("dmic_trigger START err %d", ret);
	}
	return ret;
}

#endif /* CONFIG_DMIC_ATM */

/* ── Public API ──────────────────────────────────────────────────────────── */

void rc_audio_init(void)
{
	settings_load_subtree("atvv");
	LOG_INF("ATVV prev configured: %d", atvv_configured);
	atvv_init(&atvv_cbs);
#if defined(CONFIG_DMIC_ATM)
	if (!device_is_ready(dmic_dev)) {
		LOG_ERR("DMIC device not ready");
		return;
	}
	k_sem_init(&stream_sem, 0, 1);
	LOG_INF("rc_audio init: DMIC+ATVV ready");
#else
	LOG_INF("rc_audio init: ATVV only (no DMIC)");
#endif
}

void rc_audio_stream_start(void)
{
#if defined(CONFIG_DMIC_ATM)
	if (streaming_active) {
		return;
	}
	frame_seq = 0;
	streaming_active = true;

	int ret = dmic_start_capture();
	if (ret) {
		streaming_active = false;
		rc_mmi_run_event(MMI_OP_CLOSE_MIC);
		return;
	}

	k_thread_create(&audio_tid, audio_stack, K_THREAD_STACK_SIZEOF(audio_stack),
			audio_thread_fn, NULL, NULL, NULL, K_PRIO_PREEMPT(7), 0, K_NO_WAIT);
	k_thread_name_set(&audio_tid, "rc_audio");
	LOG_INF("audio stream started");
#else
	LOG_INF("rc_audio_stream_start: DMIC not enabled");
#endif
}

void rc_audio_stream_stop(void)
{
#if defined(CONFIG_DMIC_ATM)
	if (!streaming_active) {
		return;
	}
	streaming_active = false;
	/* audio_thread_fn checks streaming_active and will call dmic_trigger(STOP) */
	LOG_INF("audio stream stop requested");
#endif
}

void rc_audio_start_search(void)
{
	if (atvv_get_state() != ATVV_STATE_READY) {
		LOG_WRN("ATVV not ready, ignoring start_search");
		return;
	}

#if defined(CONFIG_RC_ATVV_ASST_MODEL_PTT) || defined(CONFIG_RC_ATVV_ASST_MODEL_HTT)
	/* PTT/HTT: remote unilaterally opens the mic on button press,
	 * without waiting for a host MIC_OPEN (v1.0 §4.5.2 / §4.5.3). */
	if (session_active) {
		LOG_DBG("start_search: session already active");
		return;
	}
	current_stream_id = alloc_stream_id();
	session_active = true;
#if defined(CONFIG_RC_ATVV_ASST_MODEL_HTT)
	atvv_send_audio_start(ATVV_AUDIO_START_REASON_HTT, RC_ATVV_CODEC_USED, current_stream_id);
#else
	atvv_send_audio_start(ATVV_AUDIO_START_REASON_PTT, RC_ATVV_CODEC_USED, current_stream_id);
#endif
	audio_timeout_start();
	LOG_INF("PTT/HTT stream opened (stream_id=0x%02x)", current_stream_id);
	rc_mmi_run_event(MMI_OP_OPEN_MIC);
#else
	/* On-request (mandatory baseline): remote sends START_SEARCH on mic
	 * button press. Host responds with MIC_OPEN to begin streaming. */
	LOG_INF("START_SEARCH");
	atvv_send_ctl(ATVV_CTL_SEARCH_START, NULL, 0);
#endif
}

void rc_audio_stop_search(void)
{
#if defined(CONFIG_RC_ATVV_ASST_MODEL_PTT)
	/* PTT: stop the locally initiated stream on button release. */
	if (!session_active) {
		return;
	}
	audio_timeout_stop();
	rc_audio_stream_stop();
	rc_mmi_run_event(MMI_OP_CLOSE_MIC);
	atvv_send_audio_stop(ATVV_AUDIO_STOP_REASON_OTHER);
	session_active = false;
	LOG_INF("PTT release stopped");
#elif defined(CONFIG_RC_ATVV_ASST_MODEL_HTT)
	/* HTT: button release stops the stream immediately, remote-initiated
	 * (v1.0 §4.5.3), without waiting for MIC_CLOSE. */
	if (!session_active) {
		return;
	}
	audio_timeout_stop();
	rc_audio_stream_stop();
	rc_mmi_run_event(MMI_OP_CLOSE_MIC);
	atvv_send_audio_stop(ATVV_AUDIO_STOP_REASON_HTT_RELEASE);
	session_active = false;
	LOG_INF("HTT release stopped");
#else
	/* On-request: button-initiated stop mirrors a host-driven MIC_CLOSE
	 * from the remote's own release of the mic key. */
	audio_timeout_stop();
	rc_audio_stream_stop();
	rc_mmi_run_event(MMI_OP_CLOSE_MIC);
#if defined(CONFIG_ATVV_SPEC_V1_0)
	atvv_send_audio_stop(ATVV_AUDIO_STOP_REASON_MIC_CLOSE);
	session_active = false;
	current_stream_id = ATVV_STREAM_ID_MIC_OPEN;
#else
	atvv_send_audio_stop();
#endif
	LOG_INF("search stopped");
#endif
}

void rc_audio_dpad_select(void)
{
	atvv_state_t s = atvv_get_state();

	if (s == ATVV_STATE_READY || s == ATVV_STATE_ENABLED) {
		LOG_DBG("DPAD_SELECT");
		atvv_send_ctl(ATVV_CTL_DPAD_SELECT, NULL, 0);
	}
}
