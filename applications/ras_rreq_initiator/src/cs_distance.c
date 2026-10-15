/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <math.h>

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/net_buf.h>
#include <zephyr/bluetooth/cs.h>
#include <zephyr/bluetooth/hci_types.h>

#include "ras.h"
#include "cs_distance.h"
#include "cs_display.h"
#include "estimator.h"
#include "scored_pool.h"

LOG_MODULE_DECLARE(rreq_smf, CONFIG_RREQ_SMF_LOG_LEVEL);

#define CS_DIST_MAX_STEPS BT_RAS_MAX_STEPS_PER_PROCEDURE

/*
 * RAS ranging-data subevent header wire format (8 bytes). Mirrors the
 * ras_rd_subevent_hdr_t in the RAS subsys private header; redefined locally
 * to avoid depending on the subsys-internal include path.
 */
struct cs_ras_subevent_hdr {
	uint16_t acl_conn_evt;
	uint16_t freq_comp;
	uint8_t done_status;
	uint8_t abort_reason;
	uint8_t ref_pwr_lvl;
	uint8_t reported_step;
} __packed;
BUILD_ASSERT(sizeof(struct cs_ras_subevent_hdr) == 8, "RAS subevent header must be 8 bytes");

static uint8_t cached_step_modes[CS_DIST_MAX_STEPS];
static uint8_t cached_step_channels[CS_DIST_MAX_STEPS];
static uint16_t cached_step_count;
static uint32_t cached_init_proc = UINT32_MAX;

/*
 * Decoded per-side measurement buffers, fed straight to the estimator with
 * no intermediate text/CSV formatting (minimal copying). Each mode-2 step
 * contributes up to n_ap (<= 4) records; a full procedure was observed with
 * ~72 channels x 4 antennas = 288 records, so 320 leaves headroom. Records
 * past the cap are dropped with a warning.
 *
 * Do NOT raise this to silence a "meas buffer full" warning. One procedure
 * cannot exceed the cap, so hitting it means several procedures were merged
 * upstream and the snapshot is already corrupt -- the cap is what bounds the
 * damage, not what causes it. Measured on ATM34 at a true 2.5 m: raising it to
 * 512 turned the warning into visibly worse output (134 -> 38 distances,
 * median 4.38 m -> 15.20 m, "not enough mem" 8 -> 103) and exposed init_meas_n
 * reaching 428 and 512, far past the ~296 a single procedure produces.
 *
 * The real causes were fixed elsewhere: latest_local_steps is now flushed when
 * a new procedure starts before the previous one was drained (rreq_smf.c), and
 * reflector data whose procedure counter does not match cached_init_proc is
 * dropped rather than paired against the wrong initiator snapshot (see
 * cs_distance_dump_peer below). If this warning reappears, look at those two
 * paths first.
 */
#define CS_DIST_MAX_MEAS 320
static ChannelMeasI16 init_meas[CS_DIST_MAX_MEAS];
static ChannelMeasI16 refl_meas[CS_DIST_MAX_MEAS];
static uint16_t init_meas_n;
static uint16_t refl_meas_n;

/*
 * Static EstimatorSession backing store. The session type is opaque, so the
 * buffer is sized against estimator_session_size() and validated at runtime.
 * Persists across procedures (Kalman history).
 *
 * sizeof(EstimatorSession) for this build (ereal=float, E_MAX_ANTENNAS=4,
 * E_MAX_CANDS_PER_ANT=16 -> E_MAX_CANDS_TOTAL=64, SP_HISTORY_LEN=8,
 * ESTIMATOR_ENABLE_SHORT_RANGE_DELEAK=0) is 13016 B, confirmed by
 * disassembling estimator_session_size() (movw r0, #13016). The struct is
 * fixed-size (no flexible array / trailing sub-allocation), and
 * estimator_init_static() guards on buffer_size < sizeof(EstimatorSession)
 * and only writes sizeof(*s) bytes. 14 KiB leaves ~1.3 KiB margin and is
 * 8-aligned to satisfy _Alignof(EstimatorSession).
 */
#define CS_DIST_SESSION_BYTES (14u * 1024u)
static uint8_t __aligned(8) session_buf[CS_DIST_SESSION_BYTES];
static EstimatorSession *session;

struct init_walk_ctx {
	uint8_t n_ap;
	uint16_t step_idx;
	uint16_t mode2_count;
};

/*
 * Decode the n_ap mode-2 tones for one step and append them to a
 * measurement array. The antenna path is resolved via the permutation
 * table so initiator and reflector records pair up on the same physical
 * (channel, antenna) inside the estimator's align stage.
 */
static void append_mode2_meas(ChannelMeasI16 *arr, uint16_t *n, uint8_t channel, uint8_t n_ap,
			      uint8_t perm, const struct bt_hci_le_cs_step_data_tone_info *tones)
{
	for (uint8_t i = 0; i < n_ap; i++) {
		if (*n >= CS_DIST_MAX_MEAS) {
			LOG_WRN("meas buffer full (%u)", CS_DIST_MAX_MEAS);
			return;
		}
		int ap = bt_le_cs_get_antenna_path(n_ap, perm, i);
		if (ap < 0) {
			LOG_WRN("bad ap n_ap=%u perm=%u i=%u", n_ap, perm, i);
			continue;
		}
		struct bt_le_cs_iq_sample iq = bt_le_cs_parse_pct(tones[i].phase_correction_term);
		ChannelMeasI16 *m = &arr[(*n)++];
		m->channel = (int16_t)channel;
		m->antenna = (int16_t)ap;
		m->I = (int16_t)iq.i;
		m->Q = (int16_t)iq.q;
		m->quality = (int16_t)tones[i].quality_indicator;
		m->_pad = 0;
	}
}

static bool init_step_cb(struct bt_le_cs_subevent_step *step, void *user_data)
{
	struct init_walk_ctx *ctx = user_data;

	if (ctx->step_idx >= CS_DIST_MAX_STEPS) {
		LOG_WRN("init step cache overflow at %u", ctx->step_idx);
		return false;
	}
	cached_step_modes[ctx->step_idx] = step->mode;
	cached_step_channels[ctx->step_idx] = step->channel;
	ctx->step_idx++;

	if (step->mode == BT_HCI_OP_LE_CS_MAIN_MODE_2) {
		const struct bt_hci_le_cs_step_data_mode_2 *m2 =
			(const struct bt_hci_le_cs_step_data_mode_2 *)step->data;
		append_mode2_meas(init_meas, &init_meas_n, step->channel, ctx->n_ap,
				  m2->antenna_permutation_index, m2->tone_info);
		ctx->mode2_count++;
	}
	return true;
}

void cs_distance_dump_init(uint32_t proc, uint8_t n_ap, const uint8_t *data, uint16_t len)
{
	if (!data || !len || !n_ap || n_ap > 4) {
		LOG_WRN("init bad args proc=%u n_ap=%u len=%u", proc, n_ap, len);
		return;
	}

	init_meas_n = 0;

	struct net_buf_simple ns;
	net_buf_simple_init_with_data(&ns, (void *)data, len);

	struct init_walk_ctx ctx = {.n_ap = n_ap};
	bt_le_cs_step_data_parse(&ns, init_step_cb, &ctx);

	cached_init_proc = proc;
	cached_step_count = ctx.step_idx;
}

/*
 * Body length for a single peer step body (excluding the 1-byte step_mode).
 * Mirrors BT_RAS_STEP_MODE_*_MAX_LEN sizing from rreq_smf.c.
 */
static uint16_t peer_step_body_len(uint8_t mode, uint8_t n_ap)
{
	switch (mode) {
	case 0:
		return sizeof(struct bt_hci_le_cs_step_data_mode_0_reflector);
	case 1:
		/* Non-ss_rtt layout (6 bytes); the RAS configuration in use never
		 * carries the extra ss_rtt PCT fields. Matches csplot's peer
		 * parser (resolve_rap_ref_raw_to_stepDict).
		 */
		return sizeof(struct bt_hci_le_cs_step_data_mode_1);
	case 2:
		return sizeof(struct bt_hci_le_cs_step_data_mode_2) +
		       (n_ap + 1) * sizeof(struct bt_hci_le_cs_step_data_tone_info);
	case 3:
		return sizeof(struct bt_hci_le_cs_step_data_mode_3) +
		       (n_ap + 1) * sizeof(struct bt_hci_le_cs_step_data_tone_info);
	default:
		return 0;
	}
}

/*
 * Format an ereal metre value as a fixed-point millimetre string using
 * integer math only, so no soft-float printf support is pulled in.
 */
static void fmt_mm(ereal v, char *buf, size_t n)
{
	if (!isfinite((double)v)) {
		snprintk(buf, n, "nan");
		return;
	}
	int neg = v < ER(0.0);
	if (neg) {
		v = -v;
	}
	long mm = (long)(v * ER(1000.0) + ER(0.5));
	snprintk(buf, n, "%s%ld.%03ld", neg ? "-" : "", mm / 1000, mm % 1000);
}

/*
 * Format an ereal metre value to a single fractional digit (e.g. "1.2"),
 * for the OLED where a full millimetre-precision string doesn't fit.
 * Same integer-math approach as fmt_mm(), just scaled by 10 instead of
 * 1000, so callers get a ready-to-print string without any further
 * string manipulation.
 */
static void fmt_m_1dp(ereal v, char *buf, size_t n)
{
	if (!isfinite((double)v)) {
		snprintk(buf, n, "nan");
		return;
	}
	int neg = v < ER(0.0);
	if (neg) {
		v = -v;
	}
	long d = (long)(v * ER(10.0) + ER(0.5));
	/*
	 * Clamp both ends so the compiler can prove "%ld" fits the destination
	 * buffer (distances are physically well under 1000 m; this is just a
	 * display-string bound, not a real limit on the estimator output). The
	 * lower bound is needed for -Werror=format-truncation: v is already made
	 * non-negative above, but the compiler cannot prove it across the branch,
	 * so without it d/10 is treated as possibly ~-2e8 (10 digits).
	 */
	if (d < 0) {
		d = 0;
	}
	if (d > 9999) {
		d = 9999;
	}
	snprintk(buf, n, "%s%ld.%ld", neg ? "-" : "", d / 10, d % 10);
}

/*
 * Run one estimator snapshot from the accumulated init/refl buffers and
 * report the estimated distance to the UART in real time.
 */
static void run_estimator(uint32_t proc)
{
	if (!session) {
		/*
		 * Canonical production baseline, matching the validated parity
		 * harness (compare_c_vs_python.py / _baseline_env.sh):
		 * CLEAN_MAX_ITER=1 plus the Phase D/E/G features. The library's
		 * NULL defaults keep the older CLEAN_MAX_ITER=4 baseline with
		 * those phases off, so pass an explicit config here.
		 */
		const EstimatorConfig cfg = {
			.ifft_cal_factor = ER(1.0),
			.mcpd_enable = 1,
			.clean_max_iter = 1,
			.mcpd_base_score = ER(0.40),
			.flags = ESTIMATOR_F_MPM | ESTIMATOR_F_SEARCHBACK |
				 ESTIMATOR_F_SCORED_POOL | ESTIMATOR_F_FAT_PEAK |
				 ESTIMATOR_F_FAT_LS | ESTIMATOR_F_CLEAN_CANCEL |
				 ESTIMATOR_F_KALMAN_LOWER_BOUND | ESTIMATOR_F_SHORT_CLEAN_RESCUE |
				 ESTIMATOR_F_LR_CLUSTER_MCPD,
			.lr_selector_mode = SP_LR_MODE_CLUSTER_MCPD,
			.lr_selector_margin = ER(0.40),
		};

		session = estimator_init_static(session_buf, sizeof(session_buf), &cfg, (ereal)NAN);
		if (!session) {
			LOG_ERR("estimator init failed need=%u have=%u",
				(unsigned)estimator_session_size(), (unsigned)sizeof(session_buf));
			return;
		}
	}
	if (!init_meas_n || !refl_meas_n) {
		LOG_WRN("no meas proc=%u init=%u refl=%u", proc, init_meas_n, refl_meas_n);
		return;
	}

	EstimatorOutput out;
	ereal ts = (ereal)k_uptime_get() / ER(1000.0);
	int rc = estimator_process_snapshot_i16_at(session, init_meas, init_meas_n, refl_meas,
						   refl_meas_n, ts, &out);
	if (rc < 0) {
		LOG_ERR("estimator rc=%d proc=%u", rc, proc);
		return;
	}

	char rawb[16];
	char smb[16];
	char smb1[8];
	fmt_mm(out.raw_distance, rawb, sizeof(rawb));
	fmt_mm(out.smoothed_distance, smb, sizeof(smb));
	fmt_m_1dp(out.smoothed_distance, smb1, sizeof(smb1));
	LOG_INF("Ariad: proc=%u, raw=%s m, smoothed=%s m", proc, rawb, smb);

#ifdef CONFIG_RREQ_USE_DISPLAY
	/*
	 * This file only builds under RREQ_USE_ARIAD, so the estimator is a given
	 * here; the OLED on top of it is the separate opt-in.
	 */
	cs_display_show_distance(smb1);
#endif
}

void cs_distance_dump_peer(uint32_t proc, uint8_t n_ap, const uint8_t *data, uint16_t len)
{
	if (!data || !len || !n_ap || n_ap > 4) {
		LOG_WRN("peer bad args proc=%u n_ap=%u len=%u", proc, n_ap, len);
		return;
	}

	if ((cached_init_proc ^ proc) & BT_RAS_RD_HEADER_RANGING_COUNTER_MASK_REALTIME) {
		LOG_WRN("peer proc mismatch peer=%u cached_init=%u dropped", proc,
			cached_init_proc);
		return;
	}

	refl_meas_n = 0;

	const uint8_t *p = data;
	const uint8_t *end = data + len;
	uint16_t step_idx = 0;
	bool truncated = false;

	while (p < end && !truncated) {
		if ((size_t)(end - p) < sizeof(struct cs_ras_subevent_hdr)) {
			LOG_WRN("peer truncated subevent header off=%u", (unsigned)(p - data));
			break;
		}
		const struct cs_ras_subevent_hdr *hdr = (const void *)p;
		uint8_t reported = hdr->reported_step;
		p += sizeof(*hdr);

		for (uint8_t s = 0; s < reported && p < end; s++) {
			uint8_t mode = *p++;
			uint16_t body = peer_step_body_len(mode, n_ap);

			if (!body || (size_t)(end - p) < body) {
				LOG_WRN("peer truncated step s=%u mode=%u remain=%u", step_idx,
					mode, (unsigned)(end - p));
				truncated = true;
				break;
			}

			uint8_t channel = (step_idx < cached_step_count)
						  ? cached_step_channels[step_idx]
						  : 0xFF;
			uint8_t cmode =
				(step_idx < cached_step_count) ? cached_step_modes[step_idx] : 0xFF;
			if (cmode != 0xFF && cmode != mode) {
				LOG_WRN("peer mode mismatch s=%u peer=%u init=%u", step_idx, mode,
					cmode);
			}

			if (mode == BT_HCI_OP_LE_CS_MAIN_MODE_2) {
				const struct bt_hci_le_cs_step_data_mode_2 *m2 = (const void *)p;
				append_mode2_meas(refl_meas, &refl_meas_n, channel, n_ap,
						  m2->antenna_permutation_index, m2->tone_info);
			}
			p += body;
			step_idx++;
		}
	}

	run_estimator(cached_init_proc);
}
