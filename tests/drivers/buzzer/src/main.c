/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/ztest.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/device.h>
#include "atm_buzzer.h"

#define BUZZER_NODE DT_NODELABEL(buzzer)

BUILD_ASSERT(DT_NODE_EXISTS(BUZZER_NODE), "BUZZER_NODE does not exist in the Device Tree!");

/* Test configuration */
#define TEST_FREQUENCY_LOW_HZ    500
#define TEST_FREQUENCY_MID_HZ    1000
#define TEST_FREQUENCY_HIGH_HZ   2000
#define TEST_DUTY_CYCLE_LOW_PCT  25
#define TEST_DUTY_CYCLE_MID_PCT  50
#define TEST_DUTY_CYCLE_HIGH_PCT 75
#define TEST_DURATION_SHORT_MS   200
#define TEST_DURATION_MEDIUM_MS  500
#define TEST_PAUSE_SHORT_MS      100

/* Boundary/Error test configuration - based on app.overlay min/max frequency */
#define TEST_FREQUENCY_BELOW_MIN 50      /* Below min-frequency (123 Hz) */
#define TEST_FREQUENCY_ABOVE_MAX 8000100 /* Above max-frequency (8000000 Hz) */
#define TEST_DUTY_CYCLE_ZERO     0
#define TEST_DUTY_CYCLE_MAX      100
#define TEST_DUTY_CYCLE_INVALID  150 /* > 100% */

/* Global test state */
#ifdef CONFIG_ATM_BUZZER_TIMEOUT
static bool callback_triggered;
#endif

/* Buzzer device pointer */
static const struct device *buzzer_dev;

#ifdef CONFIG_ATM_BUZZER_TIMEOUT
/* Callback function for timeout tests */
static void buzzer_stop_callback(const struct device *dev)
{
	callback_triggered = true;
}
#endif

/* ===== Device Ready Tests ===== */
ZTEST(buzzer_driver, test_01_device_ready)
{
	buzzer_dev = DEVICE_DT_GET(BUZZER_NODE);
	zassert_not_null(buzzer_dev, "Buzzer device should not be NULL");
	zassert_true(device_is_ready(buzzer_dev), "Buzzer device should be ready");
}

/* ===== Configure API Tests ===== */
ZTEST(buzzer_driver, test_02_configure_valid_params)
{
	int ret = atm_buzzer_configure(buzzer_dev, TEST_FREQUENCY_MID_HZ, TEST_DUTY_CYCLE_MID_PCT);
	zassert_equal(ret, 0, "Configure with valid parameters should succeed");
}

ZTEST(buzzer_driver, test_03_configure_duty_cycle_25)
{
	int ret = atm_buzzer_configure(buzzer_dev, TEST_FREQUENCY_MID_HZ, TEST_DUTY_CYCLE_LOW_PCT);
	zassert_equal(ret, 0, "Configure with 25%% duty cycle should succeed");
}

ZTEST(buzzer_driver, test_04_configure_duty_cycle_75)
{
	int ret = atm_buzzer_configure(buzzer_dev, TEST_FREQUENCY_MID_HZ, TEST_DUTY_CYCLE_HIGH_PCT);
	zassert_equal(ret, 0, "Configure with 75%% duty cycle should succeed");
}

/* ===== On/Off API Tests ===== */
ZTEST(buzzer_driver, test_05_turn_buzzer_on)
{
	int ret = atm_buzzer_configure(buzzer_dev, TEST_FREQUENCY_MID_HZ, TEST_DUTY_CYCLE_MID_PCT);
	zassert_equal(ret, 0, "Pre-configure buzzer for on/off test");

	ret = atm_buzzer_onoff(buzzer_dev, true);
	zassert_equal(ret, 0, "Turn buzzer ON should succeed");
	k_msleep(TEST_DURATION_SHORT_MS);
}

ZTEST(buzzer_driver, test_06_turn_buzzer_off)
{
	int ret = atm_buzzer_onoff(buzzer_dev, false);
	zassert_equal(ret, 0, "Turn buzzer OFF should succeed");
	k_msleep(TEST_PAUSE_SHORT_MS);
}

/* ===== Beep API Tests ===== */
ZTEST(buzzer_driver, test_07_beep_mid_freq)
{
	int ret = atm_buzzer_beep(buzzer_dev, TEST_FREQUENCY_MID_HZ, TEST_DUTY_CYCLE_MID_PCT);
	zassert_equal(ret, 0, "Beep with mid frequency should succeed");
	k_msleep(TEST_DURATION_SHORT_MS);
	atm_buzzer_onoff(buzzer_dev, false);
	k_msleep(TEST_PAUSE_SHORT_MS);
}

ZTEST(buzzer_driver, test_08_beep_low_freq)
{
	int ret = atm_buzzer_beep(buzzer_dev, TEST_FREQUENCY_LOW_HZ, TEST_DUTY_CYCLE_LOW_PCT);
	zassert_equal(ret, 0, "Beep with low frequency should succeed");
	k_msleep(TEST_DURATION_SHORT_MS);
	atm_buzzer_onoff(buzzer_dev, false);
	k_msleep(TEST_PAUSE_SHORT_MS);
}

ZTEST(buzzer_driver, test_09_beep_high_freq)
{
	int ret = atm_buzzer_beep(buzzer_dev, TEST_FREQUENCY_HIGH_HZ, TEST_DUTY_CYCLE_HIGH_PCT);
	zassert_equal(ret, 0, "Beep with high frequency should succeed");
	k_msleep(TEST_DURATION_SHORT_MS);
	atm_buzzer_onoff(buzzer_dev, false);
	k_msleep(TEST_PAUSE_SHORT_MS);
}

/* ===== Error Handling Tests ===== */
ZTEST(buzzer_driver, test_10_configure_freq_below_min)
{
	int ret =
		atm_buzzer_configure(buzzer_dev, TEST_FREQUENCY_BELOW_MIN, TEST_DUTY_CYCLE_MID_PCT);
	zassert_equal(ret, BUZ_PARAM_INCORRECT, "Configure with frequency below min should fail");
}

ZTEST(buzzer_driver, test_11_configure_freq_above_max)
{
	int ret =
		atm_buzzer_configure(buzzer_dev, TEST_FREQUENCY_ABOVE_MAX, TEST_DUTY_CYCLE_MID_PCT);
	zassert_equal(ret, BUZ_PARAM_INCORRECT, "Configure with frequency above max should fail");
}

ZTEST(buzzer_driver, test_12_configure_duty_cycle_invalid)
{
	int ret = atm_buzzer_configure(buzzer_dev, TEST_FREQUENCY_MID_HZ, TEST_DUTY_CYCLE_INVALID);
	zassert_equal(ret, BUZ_PARAM_INCORRECT, "Configure with duty cycle > 100%% should fail");
}

ZTEST(buzzer_driver, test_13_beep_freq_below_min)
{
	int ret = atm_buzzer_beep(buzzer_dev, TEST_FREQUENCY_BELOW_MIN, TEST_DUTY_CYCLE_MID_PCT);
	zassert_equal(ret, BUZ_PARAM_INCORRECT, "Beep with frequency below min should fail");
}

ZTEST(buzzer_driver, test_14_beep_freq_above_max)
{
	int ret = atm_buzzer_beep(buzzer_dev, TEST_FREQUENCY_ABOVE_MAX, TEST_DUTY_CYCLE_MID_PCT);
	zassert_equal(ret, BUZ_PARAM_INCORRECT, "Beep with frequency above max should fail");
}

/* ===== Boundary Value Tests ===== */
ZTEST(buzzer_driver, test_15_configure_duty_cycle_zero)
{
	int ret = atm_buzzer_configure(buzzer_dev, TEST_FREQUENCY_MID_HZ, TEST_DUTY_CYCLE_ZERO);
	zassert_equal(ret, 0, "Configure with 0%% duty cycle should succeed");
}

ZTEST(buzzer_driver, test_16_configure_duty_cycle_max)
{
	int ret = atm_buzzer_configure(buzzer_dev, TEST_FREQUENCY_MID_HZ, TEST_DUTY_CYCLE_MAX);
	zassert_equal(ret, 0, "Configure with 100%% duty cycle should succeed");
}

#ifdef CONFIG_ATM_BUZZER_TIMEOUT
/* ===== Beep Time API Tests ===== */
ZTEST(buzzer_driver, test_17_beep_time_short)
{
	callback_triggered = false;
	atm_buzzer_set_stop_callback(buzzer_dev, buzzer_stop_callback);

	int ret = atm_buzzer_beep_time(buzzer_dev, TEST_FREQUENCY_MID_HZ, TEST_DUTY_CYCLE_MID_PCT,
				       TEST_DURATION_SHORT_MS);
	zassert_equal(ret, 0, "Timed beep should succeed");
	k_msleep(TEST_DURATION_SHORT_MS + 100);
	zassert_true(callback_triggered, "Callback should be triggered after timeout");
	k_msleep(TEST_PAUSE_SHORT_MS);
}

ZTEST(buzzer_driver, test_18_beep_time_medium)
{
	callback_triggered = false;
	int ret = atm_buzzer_beep_time(buzzer_dev, TEST_FREQUENCY_MID_HZ, TEST_DUTY_CYCLE_MID_PCT,
				       TEST_DURATION_MEDIUM_MS);
	zassert_equal(ret, 0, "Timed beep should succeed");
	k_msleep(TEST_DURATION_MEDIUM_MS + 100);
	zassert_true(callback_triggered, "Callback should be triggered after timeout");
	k_msleep(TEST_PAUSE_SHORT_MS);
}

ZTEST(buzzer_driver, test_19_beep_time_zero_duration)
{
	/* Zero duration means buzzer should stay on indefinitely (no auto-stop scheduled) */
	int ret =
		atm_buzzer_beep_time(buzzer_dev, TEST_FREQUENCY_MID_HZ, TEST_DUTY_CYCLE_MID_PCT, 0);
	zassert_equal(ret, 0, "Timed beep with zero duration should succeed");
	k_msleep(TEST_DURATION_SHORT_MS);
	/* Buzzer should still be on, manually turn it off */
	atm_buzzer_onoff(buzzer_dev, false);
	k_msleep(TEST_PAUSE_SHORT_MS);
}

ZTEST(buzzer_driver, test_20_beep_time_freq_invalid)
{
	int ret = atm_buzzer_beep_time(buzzer_dev, TEST_FREQUENCY_BELOW_MIN,
				       TEST_DUTY_CYCLE_MID_PCT, TEST_DURATION_SHORT_MS);
	zassert_equal(ret, BUZ_PARAM_INCORRECT, "Timed beep with frequency below min should fail");
}
#endif

/* ZTEST suite definition */
ZTEST_SUITE(buzzer_driver, NULL, NULL, NULL, NULL, NULL);
