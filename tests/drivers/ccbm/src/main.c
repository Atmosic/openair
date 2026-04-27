/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/ztest.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/logging/log.h>
#include "ccbm.h"

LOG_MODULE_REGISTER(ccbm_test, LOG_LEVEL_DBG);

/* Test configuration */
#define TEST_SETTLING_DELAY_ZERO_MS   0
#define TEST_SETTLING_DELAY_SHORT_MS  10
#define TEST_SETTLING_DELAY_MEDIUM_MS 50
#define TEST_SETTLING_DELAY_LONG_MS   100

/* Expected impedance ranges for coin cell battery (in milliohms) */
#define IMPEDANCE_MIN_EXPECTED_MOHM 0    /* Minimum expected battery impedance */
#define IMPEDANCE_MAX_EXPECTED_MOHM 1000 /* Maximum expected battery impedance */

/* Test state */
static volatile bool callback_invoked;
static volatile ccbm_status_t callback_status;
static ccbm_result_t callback_result;
static volatile bool check_cb_invoked;
static K_SEM_DEFINE(test_sem, 0, 1);

/* Callback function for CCBM measurements */
static void ccbm_test_callback(ccbm_status_t status, const ccbm_result_t *result, void *user_data)
{
	callback_invoked = true;
	callback_status = status;

	if (result != NULL) {
		callback_result = *result;
		LOG_INF("Callback: status=%d, impedance=%u mOhm, vbatt_no_load=%d mV, "
			"vbatt_with_load=%d mV",
			status, result->impedance, result->vbatt_no_load_mv,
			result->vbatt_with_load_mv);
	} else {
		LOG_INF("Callback: status=%d, result=NULL", status);
	}

	/* Signal test completion */
	k_sem_give(&test_sem);
}

/* Check callbacks for authorization tests */
static bool check_cb_allow(void *user_data)
{
	check_cb_invoked = true;
	return true;
}

static bool check_cb_deny(void *user_data)
{
	check_cb_invoked = true;
	return false;
}

/* Helper function to reset test state */
static void reset_test_state(void)
{
	callback_invoked = false;
	callback_status = CCBM_STATUS_ERROR;
	check_cb_invoked = false;
	memset(&callback_result, 0, sizeof(callback_result));
	k_sem_reset(&test_sem);
}

/* Helper function to wait for callback with timeout */
static bool wait_for_callback(k_timeout_t timeout)
{
	return (k_sem_take(&test_sem, timeout) == 0);
}

/* ===== Initialization Tests ===== */
ZTEST(ccbm_driver, test_01_ccbm_init)
{
	int ret = ccbm_init();
	zassert_equal(ret, 0, "CCBM initialization should succeed");
}

/* ===== Basic Measurement Tests ===== */
ZTEST(ccbm_driver, test_02_measure_impedance_zero_delay)
{
	reset_test_state();

	int ret =
		ccbm_measure_impedance(TEST_SETTLING_DELAY_ZERO_MS, NULL, ccbm_test_callback, NULL);
	zassert_equal(ret, 0, "Measure impedance with zero delay should succeed");

	/* Wait for callback (max 5 seconds) */
	bool callback_received = wait_for_callback(K_SECONDS(5));
	zassert_true(callback_received, "Callback should be invoked within timeout");
	zassert_true(callback_invoked, "Callback should be invoked");
	zassert_equal(callback_status, CCBM_STATUS_SUCCESS, "Callback status should be SUCCESS");
}

/* ===== Impedance Validation Tests ===== */
ZTEST(ccbm_driver, test_03_validate_impedance_reading)
{
	reset_test_state();

	int ret = ccbm_measure_impedance(TEST_SETTLING_DELAY_SHORT_MS, NULL, ccbm_test_callback,
					 NULL);
	zassert_equal(ret, 0, "Measure impedance should succeed");

	bool callback_received = wait_for_callback(K_SECONDS(5));
	zassert_true(callback_received, "Callback should be invoked");
	zassert_equal(callback_status, CCBM_STATUS_SUCCESS, "Measurement should succeed");

	/* Validate impedance is within expected range */
	zassert_true(callback_result.impedance >= IMPEDANCE_MIN_EXPECTED_MOHM &&
			     callback_result.impedance <= IMPEDANCE_MAX_EXPECTED_MOHM,
		     "Impedance (%u mOhm) should be within expected range [%u, %u]",
		     callback_result.impedance, IMPEDANCE_MIN_EXPECTED_MOHM,
		     IMPEDANCE_MAX_EXPECTED_MOHM);

	LOG_INF("Battery impedance: %u mOhm, voltages: no-load=%d mV, with-load=%d mV",
		callback_result.impedance, callback_result.vbatt_no_load_mv,
		callback_result.vbatt_with_load_mv);
}

/* ===== Settling Delay Tests ===== */
ZTEST(ccbm_driver, test_04_measure_with_medium_delay)
{
	reset_test_state();

	int ret = ccbm_measure_impedance(TEST_SETTLING_DELAY_MEDIUM_MS, NULL, ccbm_test_callback,
					 NULL);
	zassert_equal(ret, 0, "Measure impedance with medium delay should succeed");

	bool callback_received = wait_for_callback(K_SECONDS(5));
	zassert_true(callback_received, "Callback should be invoked");
	zassert_equal(callback_status, CCBM_STATUS_SUCCESS, "Measurement should succeed");
}

ZTEST(ccbm_driver, test_05_measure_with_long_delay)
{
	reset_test_state();

	int ret =
		ccbm_measure_impedance(TEST_SETTLING_DELAY_LONG_MS, NULL, ccbm_test_callback, NULL);
	zassert_equal(ret, 0, "Measure impedance with long delay should succeed");

	bool callback_received = wait_for_callback(K_SECONDS(5));
	zassert_true(callback_received, "Callback should be invoked");
	zassert_equal(callback_status, CCBM_STATUS_SUCCESS, "Measurement should succeed");
}

/* ===== Error Handling Tests ===== */
ZTEST(ccbm_driver, test_06_null_callback_error)
{
	/* done_cb is mandatory - should return error */
	int ret = ccbm_measure_impedance(TEST_SETTLING_DELAY_ZERO_MS, NULL, NULL, NULL);
	zassert_equal(ret, CCBM_STATUS_INVALID, "NULL done_cb should return CCBM_STATUS_INVALID");
}

ZTEST(ccbm_driver, test_07_busy_state_handling)
{
	reset_test_state();

	/* Start first measurement */
	int ret =
		ccbm_measure_impedance(TEST_SETTLING_DELAY_LONG_MS, NULL, ccbm_test_callback, NULL);
	zassert_equal(ret, 0, "First measurement should succeed");

	/* Try to start second measurement while first is in progress */
	ret = ccbm_measure_impedance(TEST_SETTLING_DELAY_ZERO_MS, NULL, ccbm_test_callback, NULL);
	zassert_equal(ret, CCBM_STATUS_BUSY, "Second measurement should return CCBM_STATUS_BUSY");

	/* Wait for first measurement to complete */
	bool callback_received = wait_for_callback(K_SECONDS(5));
	zassert_true(callback_received, "First measurement callback should be invoked");
}

/* ===== Sequential Measurement Tests ===== */
ZTEST(ccbm_driver, test_08_sequential_measurements)
{
	/* Perform multiple sequential measurements */
	for (int i = 0; i < 3; i++) {
		reset_test_state();

		LOG_INF("Sequential measurement %d/3", i + 1);
		int ret = ccbm_measure_impedance(TEST_SETTLING_DELAY_SHORT_MS, NULL,
						 ccbm_test_callback, NULL);
		zassert_equal(ret, 0, "Sequential measurement %d should succeed", i + 1);

		bool callback_received = wait_for_callback(K_SECONDS(5));
		zassert_true(callback_received, "Callback %d should be invoked", i + 1);
		zassert_equal(callback_status, CCBM_STATUS_SUCCESS, "Measurement %d should succeed",
			      i + 1);

		/* Small delay between measurements */
		k_msleep(100);
	}
}

/* ===== User Data Tests ===== */
ZTEST(ccbm_driver, test_09_user_data_passing)
{
	reset_test_state();

	/* Use a unique value as user data */
	uint32_t user_data_value = 0xDEADBEEF;
	static uint32_t received_user_data;

	/* Custom callback that checks user data */
	void custom_callback(ccbm_status_t status, const ccbm_result_t *result, void *user_data)
	{
		if (user_data != NULL) {
			received_user_data = *(uint32_t *)user_data;
		}
		ccbm_test_callback(status, result, user_data);
	}

	int ret = ccbm_measure_impedance(TEST_SETTLING_DELAY_ZERO_MS, NULL, custom_callback,
					 &user_data_value);
	zassert_equal(ret, 0, "Measurement with user data should succeed");

	bool callback_received = wait_for_callback(K_SECONDS(5));
	zassert_true(callback_received, "Callback should be invoked");
	zassert_equal(received_user_data, user_data_value,
		      "User data should be passed correctly to callback");
}

#ifdef FIXME
/* ===== Consistency Tests ===== */
ZTEST(ccbm_driver, test_10_measurement_consistency)
{
	ccbm_result_t results[3];

	/* Perform 3 measurements and check consistency */
	for (int i = 0; i < 3; i++) {
		reset_test_state();

		int ret = ccbm_measure_impedance(TEST_SETTLING_DELAY_SHORT_MS, NULL,
						 ccbm_test_callback, NULL);
		zassert_equal(ret, 0, "Measurement %d should succeed", i + 1);

		bool callback_received = wait_for_callback(K_SECONDS(5));
		zassert_true(callback_received, "Callback %d should be invoked", i + 1);
		zassert_equal(callback_status, CCBM_STATUS_SUCCESS, "Measurement %d should succeed",
			      i + 1);

		results[i] = callback_result;
		LOG_INF("Measurement %d: impedance = %u mOhm", i + 1, results[i].impedance);
		k_msleep(100);
	}

	/* Check that measurements are reasonably consistent (within 20% variation) */
	for (int i = 1; i < 3; i++) {
		uint32_t diff = (results[i].impedance > results[0].impedance)
					? (results[i].impedance - results[0].impedance)
					: (results[0].impedance - results[i].impedance);

		uint32_t max_variation = results[0].impedance / 5; /* 20% tolerance */

		zassert_true(diff <= max_variation,
			     "Impedance variation (%u mOhm) should be within 20%% (%u mOhm)", diff,
			     max_variation);
	}

	LOG_INF("Measurement consistency validated across 3 measurements");
}
#endif

/* ===== Authorization Callback Tests ===== */

/**
 * test_10_check_cb_abort: Verify that when check_cb returns false the
 * measurement is aborted and done_cb is NOT invoked.
 */
ZTEST(ccbm_driver, test_10_check_cb_abort)
{
	reset_test_state();

	int ret = ccbm_measure_impedance(TEST_SETTLING_DELAY_ZERO_MS, check_cb_deny,
					 ccbm_test_callback, NULL);
	zassert_equal(ret, 0, "Scheduling measurement with deny check_cb should succeed");

	/* done_cb must NOT be invoked — wait with a short timeout and confirm */
	bool callback_received = wait_for_callback(K_SECONDS(5));
	zassert_false(callback_received,
		      "done_cb should NOT be invoked when check_cb returns false");
	zassert_false(callback_invoked,
		      "done_cb should NOT be invoked when check_cb returns false");
	zassert_true(check_cb_invoked, "check_cb should have been invoked");
}

/**
 * test_11_check_cb_allow: Verify that when check_cb returns true the
 * measurement proceeds normally and done_cb IS invoked.
 */
ZTEST(ccbm_driver, test_11_check_cb_allow)
{
	reset_test_state();

	int ret = ccbm_measure_impedance(TEST_SETTLING_DELAY_ZERO_MS, check_cb_allow,
					 ccbm_test_callback, NULL);
	zassert_equal(ret, 0, "Scheduling measurement with allow check_cb should succeed");

	bool callback_received = wait_for_callback(K_SECONDS(5));
	zassert_true(callback_received, "done_cb should be invoked when check_cb returns true");
	zassert_true(callback_invoked, "done_cb should be invoked when check_cb returns true");
	zassert_true(check_cb_invoked, "check_cb should have been invoked");
	zassert_equal(callback_status, CCBM_STATUS_SUCCESS,
		      "Measurement should succeed when check_cb allows it");
}

ZTEST_SUITE(ccbm_driver, NULL, NULL, NULL, NULL, NULL);
