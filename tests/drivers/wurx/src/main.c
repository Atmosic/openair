/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/ztest.h>
#include <zephyr/device.h>
#include <zephyr/logging/log.h>
#include "wurx.h"

LOG_MODULE_REGISTER(wurx_test, LOG_LEVEL_DBG);

#define WURX_NODE DT_NODELABEL(wurx)

static const struct device *wurx_dev = DEVICE_DT_GET(WURX_NODE);

/* Test data for algorithm operations */
static const uint8_t valid_algorithms[] = {WURX_ALGORITHM_0, WURX_ALGORITHM_1};
static const uint8_t invalid_algorithms[] = {99, 255, 2};

/* Helper function to test algorithm enable/disable operations */
static void assert_algorithm_operation(uint8_t algorithm, bool enable, int expected_ret,
				       const char *description)
{
	int ret = wurx_set_algorithm(wurx_dev, algorithm, enable);
	zassert_equal(ret, expected_ret, "%s", description);
}

/* Helper function to test multiple algorithm states */
static void set_algorithm_states(const uint8_t *algorithms, const bool *states, size_t count)
{
	for (size_t i = 0; i < count; i++) {
		int ret = wurx_set_algorithm(wurx_dev, algorithms[i], states[i]);
		zassert_equal(ret, 0, "Algorithm %d %s should succeed", algorithms[i],
			      states[i] ? "enable" : "disable");
	}
}

/* Helper function to test invalid algorithm parameters */
static void test_invalid_algorithms(void)
{
	for (size_t i = 0; i < ARRAY_SIZE(invalid_algorithms); i++) {
		assert_algorithm_operation(invalid_algorithms[i], true, -EINVAL,
					   "Invalid algorithm should return -EINVAL");
	}
}

ZTEST(wurx_driver_test, test_wurx_device_ready)
{
	zassert_true(device_is_ready(wurx_dev), "WURX device should be ready");
}

ZTEST(wurx_driver_test, test_wurx_basic_operations)
{
	/* Test basic enable/disable for all valid algorithms */
	for (size_t i = 0; i < ARRAY_SIZE(valid_algorithms); i++) {
		uint8_t alg = valid_algorithms[i];
		assert_algorithm_operation(alg, true, 0, "Algorithm enable should succeed");
		assert_algorithm_operation(alg, false, 0, "Algorithm disable should succeed");
	}

	/* Test invalid algorithm parameters */
	test_invalid_algorithms();
}

ZTEST(wurx_driver_test, test_wurx_algorithm_combinations)
{
	/* Test data for different algorithm state combinations */
	struct {
		bool alg0_state;
		bool alg1_state;
		const char *description;
	} test_combinations[] = {
		{true, false, "Algorithm 0 only"},
		{false, true, "Algorithm 1 only"},
		{true, true, "Both algorithms enabled"},
		{false, false, "Both algorithms disabled"},
	};

	/* Test all algorithm state combinations */
	for (size_t i = 0; i < ARRAY_SIZE(test_combinations); i++) {
		const uint8_t algorithms[] = {WURX_ALGORITHM_0, WURX_ALGORITHM_1};
		const bool states[] = {test_combinations[i].alg0_state,
				       test_combinations[i].alg1_state};

		LOG_DBG("Testing: %s", test_combinations[i].description);
		set_algorithm_states(algorithms, states, ARRAY_SIZE(algorithms));
	}
}

ZTEST(wurx_driver_test, test_wurx_edge_cases)
{
	/* Test rapid enable/disable cycles for all algorithms */
	for (size_t i = 0; i < ARRAY_SIZE(valid_algorithms); i++) {
		uint8_t alg = valid_algorithms[i];

		/* Rapid cycle: enable -> disable -> enable */
		assert_algorithm_operation(alg, true, 0, "Algorithm enable should succeed");
		assert_algorithm_operation(alg, false, 0, "Algorithm disable should succeed");
		assert_algorithm_operation(alg, true, 0, "Algorithm re-enable should succeed");

		/* Test duplicate operations (idempotent behavior) */
		assert_algorithm_operation(alg, true, 0, "Duplicate enable should succeed");
		assert_algorithm_operation(alg, false, 0, "Algorithm disable should succeed");
		assert_algorithm_operation(alg, false, 0, "Duplicate disable should succeed");
	}
}

ZTEST_SUITE(wurx_driver_test, NULL, NULL, NULL, NULL, NULL);
