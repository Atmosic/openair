/**
 *******************************************************************************
 *
 * @file platform_ctrl_motion_detect.c
 *
 * @brief Platform control motion detect For Multimode Consumer Tag
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
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

#ifdef CONFIG_LIS2DH
static const struct device *motion_sensor;
#endif

#ifdef CONFIG_AT_CMD_TAGMOTIONRPT

#define MOTION_ACCEL_AXES 3

/* Injected acceleration from host, stored in sensor_value format (m/s²) for accel_to_raw() */
static struct sensor_value motion_injected_accel[MOTION_ACCEL_AXES];
#endif

/*
 * Convert XYZ acceleration readings to an approximate tilt angle in degrees.
 *
 * Tilt is computed from the horizontal acceleration magnitude:
 *   theta(deg) = arcsin(horiz / g) ≈ horiz / g × (180/π)  [small-angle]
 *
 * All arithmetic uses 0.01 m/s² (cm/s²) units to include val2 (fractional
 * part) without floating point. g ≈ 981 cm/s², 180/π ≈ 57.29:
 *   tilt_deg = horiz_cs2 × 5729 / 100000  (+ 50000 for rounding)
 *
 * Uses max(|X|, |Y|) as horizontal magnitude to avoid integer sqrt.
 * Underestimates by at most 30% for diagonal motion, which is acceptable
 * for the 5°/7°/10° motion classification thresholds.
 */
static uint8_t accel_to_tilt_deg(const struct sensor_value *accel)
{
	int32_t x_cs2 = accel[0].val1 * 100 + accel[0].val2 / 10000;
	int32_t y_cs2 = accel[1].val1 * 100 + accel[1].val2 / 10000;
	int32_t horiz_cs2 = (abs(x_cs2) > abs(y_cs2)) ? abs(x_cs2) : abs(y_cs2);
	int32_t tilt_deg = (horiz_cs2 * 5729 + 50000) / 100000;

	return (tilt_deg > UINT8_MAX) ? UINT8_MAX : (uint8_t)tilt_deg;
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
}
#endif

int platform_ctrl_motion_detect_init(void)
{
#ifdef CONFIG_LIS2DH
	if (motion_sensor) {
		return 0;
	}
	motion_sensor = DEVICE_DT_GET_ANY(st_lis2dh);
	if (!motion_sensor) {
		LOG_ERR("motion_detect: no LIS2DH device found in DT");
		return -ENODEV;
	}
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
		LOG_ERR("motion_detect: Not init yet");
		return -ENODEV;
	}

	if (action) {
	} else {
		motion_detected = false;
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
	int rc = sensor_sample_fetch(motion_sensor);

	if (rc && (rc != -EBADMSG)) {
		LOG_ERR("motion_detect: fetch failed: %d", rc);
		return 0;
	}
	rc = sensor_channel_get(motion_sensor, SENSOR_CHAN_ACCEL_XYZ, accel);
	if (rc) {
		LOG_ERR("motion_detect: channel get failed: %d", rc);
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
