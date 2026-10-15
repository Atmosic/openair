/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/* Single-entry-point estimator: embedded-deployment shape.
 *
 * This is the C orchestrator that mirrors what the embedded device sees
 * per BLE channel-sounding snapshot. The Python harness (peaks3.py) only
 * does file I/O and plotting; the entire numerical pipeline (filter +
 * align by (channel, antenna), per-antenna IFFT/MPM/MCPD/CLEAN, fat-peak
 * FWHM + 2-tap LS, scored-pool selector, Kalman smoothing with 3-sigma
 * jump gate) runs inside estimator_process_snapshot.
 *
 * Mirrors the production-baseline configuration from
 * HANDOFF_UNITARY_BASELINE_AND_NEXT_STEPS.md:
 *   MPM_VARIANT='unitary', MCPD_ENABLE=1, CLEAN_MAX_ITER=4,
 *   flags='mpm searchback scored-pool fat-peak fat-ls clean-cancel'.
 */
#ifndef ESTIMATOR_H
#define ESTIMATOR_H

#include "scalar_types.h"
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* One BLE measurement record. Matches the CSV-row layout
 * (channel, I, Q, antenna, quality) consumed by load_data_from_csv.
 *
 * Two variants exist:
 *
 *  ChannelMeas    : host-validation API. I/Q are ereal; under
 *                   USE_F64_VALIDATION (ereal=double) the Python bench
 *                   (pandas) can pass float64 columns straight through.
 *
 *  ChannelMeasI16 : embedded deployment API. I/Q are int16_t — matches
 *                   what BLE channel-sounding hardware produces (~10-12
 *                   bit signed ADC samples; observed ±570 in captures).
 *                   The library does the complex multiply h = init*refl
 *                   in int32 arithmetic, eliminating the soft-float
 *                   widening that a double API would force on M33.
 *                   Use estimator_process_snapshot_i16[_at] with this
 *                   struct. Struct is 12 bytes (vs 24 for ChannelMeas).
 */
typedef struct {
	int channel; /* BLE channel index (>= 0; production uses 0..71) */
	ereal I;
	ereal Q;
	int antenna; /* antenna id (>= 0) */
	int quality; /* signal-quality flag; <= 2 is accepted */
} ChannelMeas;

typedef struct {
	int16_t channel; /* BLE channel index 0..79 */
	int16_t antenna; /* antenna id 0..(E_MAX_ANTENNAS-1) */
	int16_t I;       /* raw I from CS hardware */
	int16_t Q;       /* raw Q from CS hardware */
	int16_t quality; /* signal-quality flag; <= 2 accepted */
	int16_t _pad;    /* explicit padding -> 12 bytes, 4-byte aligned */
} ChannelMeasI16;

/* Feature flags. OR these into EstimatorConfig.flags. Matches the
 * extra_args tokens parsed in peaks3.py's __main__ block. */
#define ESTIMATOR_F_MPM                (1u << 0)
#define ESTIMATOR_F_SEARCHBACK         (1u << 1)
#define ESTIMATOR_F_SCORED_POOL        (1u << 2)
#define ESTIMATOR_F_FAT_PEAK           (1u << 3)
#define ESTIMATOR_F_FAT_LS             (1u << 4)
#define ESTIMATOR_F_CLEAN_CANCEL       (1u << 5)
/* KALMAN_LOWER_BOUND_ENABLE (Phase E). Off in the production-baseline
 * defaults; the long-range credible-pool floor only engages once the
 * smoothed Kalman state exceeds E_LONG_RANGE_SELECTOR_THR. */
#define ESTIMATOR_F_KALMAN_LOWER_BOUND (1u << 6)
/* SHORT_CLEAN_RESCUE_ENABLE (Phase G). Off by default. When set, CLEAN-
 * residual candidates that beat the IFFT fallback by <=1.6 m and have
 * cross-antenna and historical support plus enough amplitude are admitted
 * to the credible pool in the short-fallback regime (mirrors peaks3.py
 * SHORT_CLEAN_RESCUE_ENABLE / select_scored_pool_distance lines 3704-3746). */
#define ESTIMATOR_F_SHORT_CLEAN_RESCUE (1u << 7)
/* SHORT_RANGE_DELEAK_ENABLE (Phase F). Off by default. When set, run a
 * second Hann-windowed IFFT pass per antenna; annotate each candidate
 * with hann_survival and hann_dist_gap; in the short-fallback regime
 * (fallback in (0, SP_SHORT_RANGE_THR_M]) apply -short_hann_penalty
 * to the final score of any ifft/mpm/clean/omp/l1_ candidate whose
 * Hann survival or distance gap fails the gate. Mirrors peaks3.py
 * SHORT_RANGE_DELEAK_ENABLE / select_scored_pool_distance:3670-3685. */
#define ESTIMATOR_F_SHORT_RANGE_DELEAK (1u << 8)
/* LONG_RANGE_SELECTOR family (Phase D). The actual mode (cluster_front
 * vs cluster_mcpd) is carried by EstimatorConfig.lr_selector_mode; this
 * flag is a master enable. Off by default. When set AND the previous
 * frame's smoothed distance > SP_LR_THR_M (12.0 m), candidates are
 * grouped into distance clusters and the cluster-front (or MCPD-anchored
 * cluster) override fires per peaks3.py:3815-3905. */
#define ESTIMATOR_F_LR_CLUSTER_MCPD    (1u << 9)

/* Persistent state across snapshots (Kalman tracker + scored-pool
 * history queue). Opaque to the caller. Created via estimator_create
 * and destroyed via estimator_destroy. Not thread-safe; one session
 * per estimation stream. */
typedef struct EstimatorSession EstimatorSession;

/* Per-session config. Pass NULL to estimator_create for the production
 * unitary baseline defaults: ifft_cal_factor = 1.0, mcpd_enable = 1,
 * clean_max_iter = 4, mcpd_base_score = 0.40, flags = all of the
 * ESTIMATOR_F_* above. */
typedef struct {
	ereal ifft_cal_factor;
	int mcpd_enable;
	int clean_max_iter;
	ereal mcpd_base_score;
	unsigned flags;
	/* SHORT_HANN_PENALTY (Phase F): score deduction applied to a Hann-
	 * checked candidate that fails the survival/gap gate. Production
	 * baseline (_baseline_env.sh) is 0.60; peaks3.py default is 0.40.
	 * Leave <= 0 to use SP_SHORT_HANN_PENALTY_DEFAULT (0.40). Only
	 * consulted when ESTIMATOR_F_SHORT_RANGE_DELEAK is set. */
	ereal short_hann_penalty;
	/* LONG_RANGE_SELECTOR (Phase D): mode + override-firing margin.
	 * lr_selector_mode is one of SP_LR_MODE_* (0=off, 1=cluster_front,
	 * 2=cluster_mcpd). lr_selector_margin maps to peaks3.py
	 * LONG_RANGE_SELECTOR_MARGIN (baseline 0.40, default 0.0). Both
	 * consulted only when ESTIMATOR_F_LR_CLUSTER_MCPD is set. */
	int lr_selector_mode;
	ereal lr_selector_margin;
	/* Kalman per-step cadence (s). Maps to peaks3.py KALMAN_DT_S
	 * (production baseline 0.3; default 1/3 when unset). Used as the
	 * fallback dt for the constant-velocity predict step and the
	 * KALMAN_LOWER_BOUND physical floor. The process-noise reference and
	 * the jump-gate physics term stay pinned to E_KALMAN_DT (1/3), which
	 * mirrors Python's _DT_REF and DistanceTracker.dt (never rescaled by
	 * predict). Leave <= 0 to use E_KALMAN_DT. */
	ereal kalman_dt;
} EstimatorConfig;

/* Per-snapshot output. */
typedef struct {
	ereal raw_distance;      /* selector output; NaN if all candidates
				  * failed the score threshold AND no
				  * fallback was available */
	ereal smoothed_distance; /* Kalman post-update distance */
	ereal confidence;        /* selector final_score of the chosen
				  * candidate; 0 when fallback fired */
	int rejected_jump;       /* 1 if the dynamic 3-sigma gate rejected
				  * raw_distance (Kalman still advanced
				  * with NaN, inflating P by 1.5x) */
	char reason[64];         /* selector reason string, e.g.
				  * "scored_mpm_pole_ant2_s0.85_n3_h2" or
				  * "fallback_low_score" */
} EstimatorOutput;

/* Lifecycle.
 *
 * estimator_create:
 *   cfg              : config struct or NULL for defaults.
 *   initial_distance : Optional Kalman state initialiser (m). Pass NaN when
 *                      no real prior is available; the first finite raw
 *                      estimate will initialize the Kalman state and bypass
 *                      the jump gate for that first lock.
 *
 * Returns NULL on allocation failure.
 */
EstimatorSession *estimator_create(const EstimatorConfig *cfg, ereal initial_distance);

/* Caller-owned session storage for heap-constrained firmware.
 *
 * estimator_session_size/alignment return the required byte size and minimum
 * alignment for an EstimatorSession. estimator_init_static initializes a
 * caller-provided buffer and returns it as an EstimatorSession*, or NULL if the
 * buffer is NULL, too small, or misaligned. estimator_destroy is safe to call
 * for both heap-created and static sessions; static sessions are not freed.
 */
size_t estimator_session_size(void);
size_t estimator_session_alignment(void);
EstimatorSession *estimator_init_static(void *buffer, size_t buffer_size,
					const EstimatorConfig *cfg, ereal initial_distance);

void estimator_destroy(EstimatorSession *s);

/* One snapshot in, one distance pair out.
 *
 *   s         : session created with estimator_create.
 *   init      : initiator-side ChannelMeas array of length n_init.
 *   refl      : reflector-side ChannelMeas array of length n_refl.
 *   out       : caller-allocated output struct; written on every call.
 *
 * Returns
 *   0  on success (out is fully populated; raw/smoothed may still be
 *      NaN if no valid antennas survived alignment, in which case the
 *      Kalman is still advanced with NaN, mirroring the Python
 *      except-block fallback in peaks3.py:3438-3442).
 *  <0  on hard error (e.g. NULL pointers, n_init <= 0).
 */
int estimator_process_snapshot(EstimatorSession *s, const ChannelMeas *init, int n_init,
			       const ChannelMeas *refl, int n_refl, EstimatorOutput *out);

/* Variant of estimator_process_snapshot that accepts a wall-clock
 * timestamp for the snapshot (in seconds; absolute or any monotone
 * scale is fine). The session computes the real per-step dt as
 *
 *   dt_s = clamp(timestamp_s - last_timestamp_s, DT_MIN_S, DT_MAX_S)
 *
 * and passes it to kalman_predict / kalman_jump_gate so the constant-
 * velocity model and the physics-floor gate scale correctly with the
 * actual cadence. The process-noise diagonal Q is rescaled at the same
 * time (Q00 ~ dt^2, Q11 ~ dt; matches a continuous-time random-walk
 * acceleration model). On the very first call (no prior timestamp),
 * the default dt is used and timestamp_s is stored for the next call.
 *
 *   timestamp_s : seconds. Pass NaN or a non-finite value to fall back
 *                 to the default 1/3 s cadence (then this call is
 *                 numerically identical to estimator_process_snapshot).
 *
 * Clamp bounds DT_MIN_S = 0.05, DT_MAX_S = 2.0 protect against bursty
 * captures and long outages; tune at the top of estimator.c if needed.
 *
 * Returns the same status codes as estimator_process_snapshot. */
int estimator_process_snapshot_at(EstimatorSession *s, const ChannelMeas *init, int n_init,
				  const ChannelMeas *refl, int n_refl, ereal timestamp_s,
				  EstimatorOutput *out);

/* int16 deployment-shape variants of the two snapshot entry points.
 *
 * Semantically identical to estimator_process_snapshot[_at] but:
 *  - Records arrive as int16 (no firmware-side int->double widening).
 *  - h_combined = init * refl is computed as int32_t complex multiply
 *    (4 SMUL + 2 add/sub on M33), then cast once to the internal scalar
 *    type. Replaces 4 soft-float f64 multiplies per tone on cores
 *    without f64 hardware.
 *  - Public output (EstimatorOutput) is unchanged.
 *
 * Pass-rate-identical to the double-API path on bit-equivalent inputs
 * (int16 -> int32 multiply is exact; values fit losslessly in double).
 */
int estimator_process_snapshot_i16(EstimatorSession *s, const ChannelMeasI16 *init, int n_init,
				   const ChannelMeasI16 *refl, int n_refl, EstimatorOutput *out);

int estimator_process_snapshot_i16_at(EstimatorSession *s, const ChannelMeasI16 *init, int n_init,
				      const ChannelMeasI16 *refl, int n_refl, ereal timestamp_s,
				      EstimatorOutput *out);

#ifdef __cplusplus
}
#endif

#endif /* ESTIMATOR_H */
