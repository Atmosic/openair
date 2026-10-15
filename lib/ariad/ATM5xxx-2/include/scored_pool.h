/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/* Scored-pool selector: C reference port of select_scored_pool_distance
 * for the production-baseline configuration (no NLOS / PDoA / sub-band /
 * plateau-tiebreak / oracle gates -- the Python wrapper falls back to the
 * full Python implementation when any of those is enabled). */
#ifndef SCORED_POOL_H
#define SCORED_POOL_H

#include "scalar_types.h" /* ereal + ER() + INFINITY (via tgmath/math) */
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Tunables, kept in sync with peaks3.py constants. Float-valued constants
 * are wrapped in ER() so they stay in the active scalar type when they meet
 * an ereal operand (no double promotion in the float build; identity in the
 * f64 validation build). */
#define SP_SUPPORT_M           ER(0.60)
#define SP_HISTORY_LEN         8
#define SP_SCORE_THRESH        ER(1.05)
#define SP_SHORT_FALLBACK_M    ER(5.2)
#define SP_SHORT_EARLY_SCORE   ER(9.00)
#define SP_NEAR_EARLY_SCORE    ER(1.95)
#define SP_EARLY_RESCUE_GAP_M  ER(0.35)
#define SP_HISTORY_EMIT_THRESH ER(0.75)

/* SHORT_CLEAN_RESCUE_ENABLE (Phase G). Mirrors peaks3.py:236-240. */
#define SP_SHORT_CLEAN_RESCUE_MIN_SUPPORT   2
#define SP_SHORT_CLEAN_RESCUE_MIN_HISTORY   4
#define SP_SHORT_CLEAN_RESCUE_MIN_AMP       ER(0.75)
#define SP_SHORT_CLEAN_RESCUE_MAX_ADVANCE_M ER(1.6)

/* SHORT_RANGE_DELEAK_ENABLE (Phase F). Mirrors peaks3.py:225-230.
 * SP_SHORT_HANN_MATCH_M shares the scored-pool support radius. The
 * Python default for SHORT_HANN_GAP_MAX_M is 'inf' (the gap gate is
 * effectively off in baseline). SHORT_HANN_PENALTY is configurable
 * via EstimatorConfig.short_hann_penalty (production baseline pins
 * 0.60 in _baseline_env.sh; peaks3.py default is 0.40). */
#define SP_SHORT_RANGE_THR_M          ER(4.0)
#define SP_SHORT_HANN_MATCH_M         SP_SUPPORT_M
#define SP_SHORT_HANN_SURVIVE_MIN     ER(0.25)
#define SP_SHORT_HANN_GAP_MAX_M       INFINITY
#define SP_SHORT_HANN_PENALTY_DEFAULT ER(0.40)

/* LONG_RANGE_SELECTOR=cluster_mcpd family (Phase D). Mirrors peaks3.py
 * lines 170-209 + selector logic 3815-3905. SP_LR_THR_M must equal the
 * estimator-side E_LONG_RANGE_SELECTOR_THR (12.0); both are referenced
 * from the same peaks3 LONG_RANGE_SELECTOR_THR.
 * Selector modes (passed in cfg / wrapper as int):
 *   SP_LR_MODE_OFF (0)              - Phase D inactive; legacy earliest-credible.
 *   SP_LR_MODE_CLUSTER_FRONT (1)    - LONG_RANGE_SELECTOR in {cluster, cluster_front}.
 *   SP_LR_MODE_CLUSTER_MCPD  (2)    - cluster_front + the MCPD-anchored rescue.
 * SP_SRC_MCPD must match estimator.c's SRC_MCPD value (3); update both
 * if the SRC_* enum order ever changes. */
#define SP_LR_THR_M                          ER(12.0)
#define SP_LR_CLUSTER_RADIUS_M               SP_SUPPORT_M
#define SP_LR_CLUSTER_FRONT_BACKOFF          ER(0.40)
#define SP_LR_MCPD_RESCUE_GAP_M              ER(3.0)
#define SP_LR_MCPD_RESCUE_WINDOW_M           ER(1.2)
#define SP_LR_MCPD_RESCUE_MAD_M              ER(1.10)
#define SP_LR_MCPD_RESCUE_CLUSTER_MARGIN     ER(0.90)
#define SP_LR_MCPD_RESCUE_MIN_ANTS           2
#define SP_LR_MCPD_RESCUE_MIN_SRCS           2
#define SP_LR_MCPD_RESCUE_MAX_CHOSEN_SCORE   ER(2.78)
#define SP_LR_MCPD_RESCUE_MAX_FALLBACK_GAP_M INFINITY
#define SP_LR_MODE_OFF                       0
#define SP_LR_MODE_CLUSTER_FRONT             1
#define SP_LR_MODE_CLUSTER_MCPD              2
#define SP_SRC_MCPD                          3

/* Stack-cap for per-candidate scratch in the selector. Firmware builds may
 * reduce this to their estimator.c E_MAX_CANDS_TOTAL. */
#ifndef SP_MAX_CANDS
#define SP_MAX_CANDS 512
#endif

struct selector_input {
	ereal distance; /* one-way metres */
	ereal score;    /* per-candidate raw score */
	int antenna;    /* antenna id; treat as opaque (used in cross-ant set) */
	int is_fat_main;
	int is_clean_resid;  /* SHORT_CLEAN_RESCUE: 1 iff source == 'clean_resid' */
	ereal clean_amp;     /* SHORT_CLEAN_RESCUE: CLEAN residual amplitude
			      * (peaks3 cand['clean_amp']); 0 for non-CLEAN. */
	int is_hann_checked; /* SHORT_RANGE_DELEAK: 1 iff source startswith
			      * ifft/mpm/omp/l1_/clean (the families subject
			      * to the Hann-survival penalty). */
	ereal hann_survival; /* SHORT_RANGE_DELEAK: (hann_local/hann_max) /
			      * (rect_local/max_power). NaN when unavailable
			      * (no Hann pass run, or short-circuit). */
	ereal hann_dist_gap; /* SHORT_RANGE_DELEAK: min(|hann_peak_dists -
			      * candidate.distance|). NaN when no Hann peaks. */
	int source_id;       /* LONG_RANGE_SELECTOR (Phase D): per-cand source
			      * tag. Mirrors estimator.c SRC_* enum: 0 IFFT_PEAK,
			      * 1 IFFT_SBACK, 2 MPM_POLE, 3 MCPD, 4 CLEAN_RESID,
			      * 5..8 FAT_*. Unknown sources from the Python
			      * wrapper map to -1; the cluster-score "distinct
			      * sources" count treats every -1 as the same id
			      * (matches the Python tuple-of-strings set; close
			      * enough for the baseline pool which never emits
			      * un-mapped families). */
};

/* Compute final scores for n_cands candidates, write the chosen index
 * (or -1 if no credible) and the chosen distance and final score.
 *
 *   cands              : n_cands input candidates (caller-built).
 *   fallback_dist      : NaN if not finite; else the IFFT fallback distance.
 *   no_history         : 1 = stateless mode.
 *   history_flat       : concatenation of per-frame distance arrays.
 *   history_frame_lens : per-frame counts (length history_n_frames).
 *   history_n_frames   : 0..SP_HISTORY_LEN.
 *   lower_bound        : KALMAN_LOWER_BOUND physical floor (one-way m). When
 *                        finite, the earliest-credible pick is restricted to
 *                        credible candidates with distance >= lower_bound,
 *                        unless none qualify (then the bound is ignored,
 *                        mirroring peaks3.py `if lb_pool:`). Pass NaN/inf to
 *                        disable (legacy behaviour).
 *   rescue_enable      : SHORT_CLEAN_RESCUE_ENABLE (Phase G). When non-zero,
 *                        CLEAN-residual candidates that satisfy advance/
 *                        support/history/amp gates (peaks3.py:3704-3714) are
 *                        exempted from the short_guard/near_guard score floor
 *                        AND from the short_mode credible-filter distance
 *                        gate. 0 = legacy behaviour (no rescue).
 *   short_deleak_enable: SHORT_RANGE_DELEAK_ENABLE (Phase F). When non-zero
 *                        AND fallback_dist in (0, SP_SHORT_RANGE_THR_M],
 *                        candidates with is_hann_checked=1 take a
 *                        -short_hann_penalty hit on final_score whenever
 *                        hann_survival < SP_SHORT_HANN_SURVIVE_MIN or
 *                        hann_dist_gap > SP_SHORT_HANN_GAP_MAX_M (mirrors
 *                        peaks3.py:3670-3685).
 *   short_hann_penalty : magnitude of the Hann-penalty score deduction.
 *                        Use SP_SHORT_HANN_PENALTY_DEFAULT (0.40) unless
 *                        the caller is plumbing a tuned value (baseline:
 *                        0.60). Ignored when short_deleak_enable == 0.
 *   last_smoothed      : previous frame's smoothed distance (Kalman x[0]
 *                        BEFORE this snapshot's predict step) used to
 *                        gate the long-range regime. Pass NaN to disable
 *                        the LR selector outright.
 *   lr_selector_mode   : SP_LR_MODE_OFF / _CLUSTER_FRONT / _CLUSTER_MCPD.
 *                        Phase D selector behaviour; only engages when
 *                        last_smoothed > SP_LR_THR_M and len(credible)>=2.
 *   lr_selector_margin : LONG_RANGE_SELECTOR_MARGIN (peaks3.py:184). The
 *                        cluster-front override fires only when the best
 *                        cluster score exceeds the earliest cluster's by
 *                        at least this margin. Default 0.0 (always fire).
 *
 * Outputs (all caller-allocated):
 *   final_scores_out      : [n_cands] -- final_score per candidate.
 *   supports_out          : [n_cands] -- cross-antenna support count.
 *   history_supports_out  : [n_cands] -- temporal-support count.
 *   chosen_idx_out        : -1 when no candidate clears SP_SCORE_THRESH.
 *   chosen_distance_out   : fallback_dist when chosen_idx_out < 0.
 *   chosen_score_out      : max(final_score) over all when no credible;
 *                           else the chosen candidate's final_score.
 *
 * Returns 0 when at least one valid candidate exists, 1 when n_cands == 0
 * (caller should treat as "fallback_no_candidates"). */
int select_scored_pool_distance_c(const struct selector_input *cands, int n_cands,
				  ereal fallback_dist, int no_history, const ereal *history_flat,
				  const int *history_frame_lens, int history_n_frames,
				  ereal lower_bound, int rescue_enable, int short_deleak_enable,
				  ereal short_hann_penalty, ereal last_smoothed,
				  int lr_selector_mode, ereal lr_selector_margin,
				  ereal *final_scores_out, int *supports_out,
				  int *history_supports_out, int *chosen_idx_out,
				  ereal *chosen_distance_out, ereal *chosen_score_out);

/* Embedded/session variant: same selector contract, but history_flat points to
 * a strided two-dimensional history buffer. This avoids flattening the
 * EstimatorSession history into an extra static RAM buffer. Existing Python
 * ctypes callers should continue using select_scored_pool_distance_c. */
int select_scored_pool_distance_strided_c(
	const struct selector_input *cands, int n_cands, ereal fallback_dist, int no_history,
	const ereal *history_flat, const int *history_frame_lens, int history_n_frames,
	int history_frame_stride, ereal lower_bound, int rescue_enable, int short_deleak_enable,
	ereal short_hann_penalty, ereal last_smoothed, int lr_selector_mode,
	ereal lr_selector_margin, ereal *final_scores_out, int *supports_out,
	int *history_supports_out, int *chosen_idx_out, ereal *chosen_distance_out,
	ereal *chosen_score_out);

#ifdef __cplusplus
}
#endif

#endif /* SCORED_POOL_H */
