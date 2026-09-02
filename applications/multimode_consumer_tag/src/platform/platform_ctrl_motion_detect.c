/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/**
 *******************************************************************************
 *
 * @file platform_ctrl_motion_detect.c
 *
 * @brief Platform control motion detect For Multimode Consumer Tag
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "platform_ctrl_motion_detect.h"
#include "platform_indicate.h"
#include <stdlib.h>
#include <zephyr/drivers/sensor.h>
#ifdef CONFIG_LIS2DH
#include <zephyr/device.h>
#endif

LOG_MODULE_DECLARE(multimode_consumer_tag, CONFIG_MULTIMODE_CONSUMER_TAG_LOG_LEVEL);

static bool motion_detected;
#if defined(CONFIG_LIS2DH_TRIGGER) || defined(CONFIG_AT_CMD_TAGMOTIONRPT)
static motion_event_cb_t motion_event_cb;
/* True while the motion trigger is armed; in trigger mode the HW IRQ (or
 * inject()) drives detection, so the _action() polling path stands down. */
static bool motion_trigger_active;
#endif

#ifdef CONFIG_LIS2DH
static const struct device *motion_sensor;

/* Previous per-axis reading (cm/s²) and validity, for consecutive-sample delta
 * motion detection in polling mode. */
static int32_t motion_prev_cs2[3];
static bool motion_have_prev;
/* ~10° tilt of the ~1g gravity vector shifts an axis by g*sin(10°) ≈ 170 cm/s²;
 * a larger per-axis change between samples is motion (mirrors SENSOR_TRIG_DELTA). */
#define MOTION_DELTA_THRESHOLD_CS2 170

static int motion_sample_accel(struct sensor_value accel[3])
{
	int rc = sensor_sample_fetch(motion_sensor);

	if (rc && (rc != -EBADMSG)) {
		LOG_ERR("motion_detect: fetch failed: %d", rc);
		return rc;
	}
	rc = sensor_channel_get(motion_sensor, SENSOR_CHAN_ACCEL_XYZ, accel);
	if (rc) {
		LOG_ERR("motion_detect: channel get failed: %d", rc);
	}
	return rc;
}

#ifdef CONFIG_LIS2DH_TRIGGER
static void motion_trigger_handler(const struct device *dev, const struct sensor_trigger *trig)
{
	ARG_UNUSED(dev);
	ARG_UNUSED(trig);
	if (motion_event_cb) {
		motion_event_cb();
	}
}
#endif /* CONFIG_LIS2DH_TRIGGER */
#endif /* CONFIG_LIS2DH */

#ifdef CONFIG_AT_CMD_TAGMOTIONRPT

#define MOTION_ACCEL_AXES 3

/* Injected acceleration from host, stored in sensor_value format (m/s²) for accel_to_raw() */
static struct sensor_value motion_injected_accel[MOTION_ACCEL_AXES];
#endif

#if !defined(CONFIG_TAG_MOTION_SENSOR_TYPE_NONE) || defined(CONFIG_AT_CMD_TAGMOTIONRPT)
#define MOTION_ACCEL_AXES_CNT 3
/* Reference gravity vector (cm/s²) of the last orientation the tag rested in. */
static int32_t motion_ref_cs2[MOTION_ACCEL_AXES_CNT];
static bool motion_have_ref;
/* Previous sample, used to tell "still" from "moving". */
static int32_t motion_last_cs2[MOTION_ACCEL_AXES_CNT];
static bool motion_have_last;
static uint8_t motion_still_cnt;
/* Uptime of the previous sample: samples are event-driven in trigger mode, so
 * stillness has to be judged on elapsed time, not on the sample count. */
static int64_t motion_last_ms;
/* Samples closer together than this carry no evidence of stillness; a trigger
 * burst delivers near-identical samples while the tag is actually moving. */
#define MOTION_STILL_MIN_GAP_MS 250
/* No sample for this long means no trigger fired, i.e. the tag has been at
 * rest; the next sample is taken as the new resting orientation. */
#define MOTION_QUIET_MS         5000
/* Sample-to-sample change at or below this is sensor noise, not movement. */
#define MOTION_STILL_DEG        2
/* Per-axis change that cannot exceed MOTION_STILL_DEG at ~1 g
 * (sqrt(3) × 15 / 981 → < 1.6°), so the angle computation can be skipped. */
#define MOTION_STILL_FAST_CS2   15
/* Consecutive still samples before the resting orientation is re-baselined. */
#define MOTION_STILL_SAMPLES    2
/* Re-baseline only near 1 g, i.e. not during linear acceleration or free fall. */
#define MOTION_MAG_MIN_SQ       ((uint64_t)900 * 900)
#define MOTION_MAG_MAX_SQ       ((uint64_t)1100 * 1100)
/* Below this magnitude the vector direction is meaningless (free fall / fault). */
#define MOTION_MIN_MAG_SQ       ((uint64_t)300 * 300)

static void accel_to_cs2(const struct sensor_value *accel, int32_t out[MOTION_ACCEL_AXES_CNT])
{
	for (int i = 0; i < MOTION_ACCEL_AXES_CNT; i++) {
		out[i] = accel[i].val1 * 100 + accel[i].val2 / 10000;
	}
}

static uint32_t motion_isqrt64(uint64_t v)
{
	uint64_t rem = 0;
	uint64_t root = 0;

	for (int i = 0; i < 32; i++) {
		root <<= 1;
		rem = (rem << 2) | (v >> 62);
		v <<= 2;
		if (root < rem) {
			rem -= root | 1;
			root += 2;
		}
	}
	return (uint32_t)(root >> 1);
}

/* Squared magnitude: the thresholds are compared squared to avoid a sqrt. */
static uint64_t motion_vec_mag_sq(const int32_t v[MOTION_ACCEL_AXES_CNT])
{
	uint64_t sq = 0;

	for (int i = 0; i < MOTION_ACCEL_AXES_CNT; i++) {
		sq += (uint64_t)((int64_t)v[i] * v[i]);
	}
	return sq;
}

/*
 * arctan of a milli-unit tangent (t = 1000 × tan) in whole degrees.
 * Rational approximation atan(x) ≈ x / (1 + 0.28·x²), valid for |x| ≤ 1
 * (error < 0.3°); larger tangents are handled by the caller via 90 - atan(1/x).
 */
static uint32_t motion_atan_milli_deg(uint32_t t)
{
	uint64_t den = 1000000ULL + (280ULL * t * t) / 1000ULL;

	return (uint32_t)((57296ULL * t + den / 2) / den);
}

/*
 * Angle in whole degrees between two acceleration vectors, computed from the
 * cross-product (sine) and dot-product (cosine) so the result is independent
 * of the sensor mounting orientation, of the zero-g bias and of any gain
 * error in the measured magnitude.
 */
static uint8_t motion_vec_angle_deg(const int32_t a[MOTION_ACCEL_AXES_CNT],
				    const int32_t b[MOTION_ACCEL_AXES_CNT])
{
	int64_t dot = (int64_t)a[0] * b[0] + (int64_t)a[1] * b[1] + (int64_t)a[2] * b[2];
	int64_t cx = (int64_t)a[1] * b[2] - (int64_t)a[2] * b[1];
	int64_t cy = (int64_t)a[2] * b[0] - (int64_t)a[0] * b[2];
	int64_t cz = (int64_t)a[0] * b[1] - (int64_t)a[1] * b[0];
	uint64_t cross_sq = (uint64_t)(cx * cx) + (uint64_t)(cy * cy) + (uint64_t)(cz * cz);
	uint64_t cross = motion_isqrt64(cross_sq);
	uint64_t adot = (dot < 0) ? (uint64_t)-dot : (uint64_t)dot;
	uint32_t deg;

	if (!cross) {
		deg = 0;
	} else if (cross <= adot) {
		deg = motion_atan_milli_deg((uint32_t)((cross * 1000U) / adot));
	} else {
		deg = 90U - motion_atan_milli_deg((uint32_t)((adot * 1000U) / cross));
	}
	if (dot < 0) {
		deg = 180U - deg;
	}
	return (deg > UINT8_MAX) ? UINT8_MAX : (uint8_t)deg;
}

#ifdef CONFIG_LIS2DH
static void motion_ref_reset(void)
{
	motion_have_ref = false;
	motion_have_last = false;
	motion_still_cnt = 0;
}
#endif

static void motion_vec_copy(int32_t dst[MOTION_ACCEL_AXES_CNT],
			    const int32_t src[MOTION_ACCEL_AXES_CNT])
{
	for (int i = 0; i < MOTION_ACCEL_AXES_CNT; i++) {
		dst[i] = src[i];
	}
}

/* True when the tag has not moved since the previous sample. The per-axis
 * pre-check settles the common stationary case without any angle math. */
static bool motion_sample_is_still(const int32_t cur[MOTION_ACCEL_AXES_CNT])
{
	for (int i = 0; i < MOTION_ACCEL_AXES_CNT; i++) {
		if (abs(cur[i] - motion_last_cs2[i]) > MOTION_STILL_FAST_CS2) {
			return motion_vec_angle_deg(cur, motion_last_cs2) <= MOTION_STILL_DEG;
		}
	}
	return true;
}

/* Samples arrive on the HW interrupt (or inject()) instead of on a fixed poll. */
static bool motion_trigger_mode(void)
{
#if defined(CONFIG_LIS2DH_TRIGGER) || defined(CONFIG_AT_CMD_TAGMOTIONRPT)
	return motion_trigger_active;
#else
	return false;
#endif
}

/*
 * Orientation change in degrees relative to the last orientation the tag was
 * resting in.
 *
 * Movement is the angle between the current sample and that resting reference.
 * The reference is re-baselined so that any mounting orientation and any
 * completed re-orientation decay back to 0 instead of latching a standing
 * angle. Callers may sample at a fixed poll rate or on motion events, so the
 * re-baseline is driven by elapsed time rather than by a sample count:
 *  - polling: MOTION_STILL_SAMPLES samples at ~1 g that are at least
 *    MOTION_STILL_MIN_GAP_MS apart and within MOTION_STILL_DEG of each other;
 *  - trigger: a gap of MOTION_QUIET_MS with no sample at all, which can only
 *    happen while the tag is at rest. Samples inside one trigger burst are
 *    closer than MOTION_STILL_MIN_GAP_MS and therefore never count as still,
 *    so a burst cannot re-baseline the reference mid-movement.
 */
static uint8_t accel_to_tilt_deg(const struct sensor_value *accel)
{
	int32_t cur[MOTION_ACCEL_AXES_CNT];

	accel_to_cs2(accel, cur);

	uint64_t mag_sq = motion_vec_mag_sq(cur);

	if (mag_sq < MOTION_MIN_MAG_SQ) {
		return 0;
	}

	int64_t now = k_uptime_get();
	int64_t gap_ms = motion_have_last ? (now - motion_last_ms) : 0;
	bool at_1g = (mag_sq >= MOTION_MAG_MIN_SQ) && (mag_sq <= MOTION_MAG_MAX_SQ);
	bool quiet =
		motion_have_last && at_1g && motion_trigger_mode() && (gap_ms >= MOTION_QUIET_MS);
	bool still = motion_have_last && at_1g && (gap_ms >= MOTION_STILL_MIN_GAP_MS) &&
		     motion_sample_is_still(cur);

	motion_vec_copy(motion_last_cs2, cur);
	motion_have_last = true;
	motion_last_ms = now;

	if (!motion_have_ref || quiet) {
		motion_vec_copy(motion_ref_cs2, cur);
		motion_have_ref = true;
		motion_still_cnt = 0;
		return 0;
	}

	if (!still) {
		motion_still_cnt = 0;
		return motion_vec_angle_deg(cur, motion_ref_cs2);
	}

	if (++motion_still_cnt >= MOTION_STILL_SAMPLES) {
		motion_still_cnt = MOTION_STILL_SAMPLES;
		motion_vec_copy(motion_ref_cs2, cur);
		return 0;
	}

	return motion_vec_angle_deg(cur, motion_ref_cs2);
}

static uint8_t accel_to_tilt_cs2(const struct sensor_value *accel)
{
	int32_t x_cs2 = accel[0].val1 * 100 + accel[0].val2 / 10000;
	int32_t y_cs2 = accel[1].val1 * 100 + accel[1].val2 / 10000;
	int32_t horiz = (abs(x_cs2) > abs(y_cs2)) ? abs(x_cs2) : abs(y_cs2);

	return (horiz > UINT8_MAX) ? UINT8_MAX : (uint8_t)horiz;
}

/* Convert XYZ acceleration to the requested raw unit. */
static uint8_t accel_to_raw(const struct sensor_value *accel, motion_raw_unit_t unit)
{
	return (unit == MOTION_RAW_UNIT_CS2) ? accel_to_tilt_cs2(accel) : accel_to_tilt_deg(accel);
}
#endif /* !defined(CONFIG_TAG_MOTION_SENSOR_TYPE_NONE) || defined(CONFIG_AT_CMD_TAGMOTIONRPT) */

#ifdef CONFIG_AT_CMD_TAGMOTIONRPT
void platform_ctrl_motion_detect_inject(int16_t x_cs2, int16_t y_cs2, int16_t z_cs2)
{
	int16_t cs2[MOTION_ACCEL_AXES] = {x_cs2, y_cs2, z_cs2};

	/* Convert cm/s² to sensor_value format: val1=m/s², val2=µm/s² fractional part */
	for (int i = 0; i < MOTION_ACCEL_AXES; i++) {
		motion_injected_accel[i].val1 = cs2[i] / 100;
		motion_injected_accel[i].val2 = (cs2[i] % 100) * 10000;
	}
	motion_detected = true;
	/* Fire event callback when trigger mode is active (replaces polling). */
	if (motion_trigger_active && motion_event_cb) {
		motion_event_cb();
	}
}
#endif

#if defined(CONFIG_LIS2DH_TRIGGER) || defined(CONFIG_AT_CMD_TAGMOTIONRPT)
void platform_ctrl_motion_detect_set_event_cb(motion_event_cb_t cb)
{
	motion_event_cb = cb;
}

void platform_ctrl_motion_detect_trigger_enable(bool enable)
{
#if defined(CONFIG_LIS2DH) && defined(CONFIG_LIS2DH_TRIGGER)
	if (!motion_sensor) {
		return;
	}
	static const struct sensor_trigger trig = {
		.type = SENSOR_TRIG_DELTA,
		.chan = SENSOR_CHAN_ACCEL_XYZ,
	};
	sensor_trigger_set(motion_sensor, &trig, enable ? motion_trigger_handler : NULL);
#endif
	motion_trigger_active = enable;
}
#endif /* CONFIG_LIS2DH_TRIGGER || CONFIG_AT_CMD_TAGMOTIONRPT */

int platform_ctrl_motion_detect_init(void)
{
#ifdef CONFIG_LIS2DH
	if (motion_sensor) {
		return 0;
	}
	motion_sensor = DEVICE_DT_GET(DT_CHOSEN(atm_motion_sensor));
	if (!device_is_ready(motion_sensor)) {
		LOG_ERR("motion_detect: device %s not ready", motion_sensor->name);
		return -ENODEV;
	}
	LOG_INF("motion_detect: LIS2DH ready: %s", motion_sensor->name);
#endif /* CONFIG_LIS2DH */
	return 0;
}

int platform_ctrl_motion_detect_action(bool action)
{
	LOG_DBG("motion_detect action %u", action);

#ifdef CONFIG_LIS2DH
	if (!motion_sensor) {
		/* Disabling an uninitialised sensor is a no-op; only enabling /
		 * sampling without init is an error. */
		if (action) {
			LOG_ERR("motion_detect: Not init yet");
			return -ENODEV;
		}
		return 0;
	}

	if (action) {
#if defined(CONFIG_LIS2DH_TRIGGER) || defined(CONFIG_AT_CMD_TAGMOTIONRPT)
		if (!motion_trigger_active)
#endif
		{
			struct sensor_value accel[3];

			if (!motion_sample_accel(accel)) {
				int32_t cur[3];

				for (int i = 0; i < 3; i++) {
					cur[i] = accel[i].val1 * 100 + accel[i].val2 / 10000;
				}
				if (motion_have_prev) {
					motion_detected = false;
					for (int i = 0; i < 3; i++) {
						if (abs(cur[i] - motion_prev_cs2[i]) >
						    MOTION_DELTA_THRESHOLD_CS2) {
							motion_detected = true;
							break;
						}
					}
				}
				for (int i = 0; i < 3; i++) {
					motion_prev_cs2[i] = cur[i];
				}
				motion_have_prev = true;
			}
		}
	} else {
		motion_detected = false;
		motion_have_prev = false;
#if !defined(CONFIG_TAG_MOTION_SENSOR_TYPE_NONE) || defined(CONFIG_AT_CMD_TAGMOTIONRPT)
		motion_ref_reset();
#endif
	}
#endif /* CONFIG_LIS2DH */

#ifdef CONFIG_AT_EVT_TAGMOTIONCTL
	platform_indicate_motion_ctl(action);
#endif

#if !defined(CONFIG_LIS2DH) && !defined(CONFIG_AT_EVT_TAGMOTIONCTL)
	ARG_UNUSED(action);
#endif
	return 0;
}

bool platform_ctrl_motion_detect_get_status(void)
{
	return motion_detected;
}

uint8_t platform_ctrl_motion_detect_get_raw_data(motion_raw_unit_t unit)
{
#ifdef CONFIG_LIS2DH
	if (!motion_sensor) {
		return 0;
	}

	struct sensor_value accel[3];

	if (motion_sample_accel(accel)) {
		return 0;
	}
	return accel_to_raw(accel, unit);
#elif defined(CONFIG_AT_CMD_TAGMOTIONRPT)
	return accel_to_raw(motion_injected_accel, unit);
#else
	ARG_UNUSED(unit);
	return 0;
#endif
}
