/**
 *******************************************************************************
 *
 * @file main.c
 *
 * @brief Atmosic Retained Memory Test
 *
 * Copyright (C) Atmosic 2025
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 *******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <zephyr/device.h>
#include <zephyr/drivers/retained_mem.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#include <zephyr/random/random.h>
#include <zephyr/ztest.h>

#include "arch.h"

LOG_MODULE_REGISTER(retained_mem_test, CONFIG_RETAINED_MEM_TEST_LOG_LEVEL);
#include "reset.h"

/* Get the retained memory device */
#define RETAINED_MEM_DEVICE DEVICE_DT_GET(DT_NODELABEL(retained_mem_hib))

/*
 * Retained memory size handling:
 * - Use get_retained_mem_size() for runtime size queries (preferred)
 * - MEM_RETAINED_SIZE_MAX is kept for compile-time contexts only
 */

/* Get the actual retained memory size from the driver (runtime) */
static inline size_t get_retained_mem_size(void)
{
    const struct device *dev = RETAINED_MEM_DEVICE;

    if (!device_is_ready(dev)) {
	LOG_ERR("Retained memory device not ready\n");
	return 0;
    }

    ssize_t size = retained_mem_size(dev);
    return (size > 0) ? size : 0;
}

/* Conservative compile-time size for array declarations - no chip-specific
 * macros */
#define MEM_RETAINED_SIZE_MAX 256

/* Test configuration */
#ifdef CONFIG_RETAINED_MEM_TEST_HIBERNATION_DURATION_MS
#define HIB_TEST_DURATION_MS CONFIG_RETAINED_MEM_TEST_HIBERNATION_DURATION_MS
#else
#define HIB_TEST_DURATION_MS 3000 /* Default: 3 seconds hibernation */
#endif

#define TEST_DATA_SIZE_SMALL 16
#define TEST_DATA_SIZE_MEDIUM 64
#define TEST_DATA_SIZE_LARGE 128

/* Hibernation test cycle management */
#define HIB_TEST_CYCLE_MAGIC 0x48544553 /* "HTES" */
typedef enum {
    HIB_TEST_SIMPLE = 0,
    HIB_TEST_SMALL_DATA,
    HIB_TEST_MEDIUM_DATA,
    HIB_TEST_LARGE_DATA,
    HIB_TEST_MAX_DATA,
    HIB_TEST_COMPLETE
} hib_test_cycle_t;

typedef struct {
    uint32_t magic;
    hib_test_cycle_t current_test;
    uint32_t test_results; /* Bitmask of passed tests */
} __packed hib_test_cycle_state_t;

/* Test patterns */
#define TEST_PATTERN_0x55 0x55
#define TEST_PATTERN_0xAA 0xAA
#define TEST_PATTERN_PSEUDO_RANDOM \
    0x42 /* Deterministic pseudo-random pattern */

/* Test state for hibernation tests */
#define HIB_TEST_MAGIC 0x48494221 /* "HIB!" */
typedef struct {
    uint32_t magic;
    uint32_t test_id;
    uint32_t data_size;
    uint32_t checksum;
    uint8_t pattern;
} __packed hib_test_state_t;

/* Calculate maximum test data size accounting for overhead */
#define HIB_OVERHEAD_SIZE \
    (sizeof(hib_test_cycle_state_t) + sizeof(hib_test_state_t))

/* Size of test_data array in combined structure - must match structure
 * definition */
#define HIB_COMBINED_TEST_DATA_SIZE 196

/* Get the actual maximum test data size based on hardware capacity */
static inline size_t get_max_test_data_size(void)
{
    size_t capacity = get_retained_mem_size();
    if (capacity <= HIB_OVERHEAD_SIZE) {
	return 0;
    }
    size_t max_from_capacity = capacity - HIB_OVERHEAD_SIZE;

    /* Also limit by the combined storage structure size */
    size_t max_from_structure = HIB_COMBINED_TEST_DATA_SIZE;

    /* Return the smaller of the two limits */
    return (max_from_capacity < max_from_structure) ? max_from_capacity :
						      max_from_structure;
}

/* Compile-time maximum for array sizing - conservative estimate */
#define TEST_DATA_SIZE_MAX (MEM_RETAINED_SIZE_MAX - HIB_OVERHEAD_SIZE)

/* Test data storage - sized for worst-case, trimmed at runtime */
static uint8_t test_data_buffer[TEST_DATA_SIZE_MAX];
static uint8_t restored_data_buffer[TEST_DATA_SIZE_MAX];

/* Wrapper functions for retained memory driver API */
static void hib_save_data(const uint8_t *src, uint32_t len)
{
    const struct device *dev = RETAINED_MEM_DEVICE;

    if (!device_is_ready(dev)) {
	LOG_ERR("Retained memory device not ready\n");
	return;
    }

    int ret = retained_mem_write(dev, 0, src, len);
    if (ret) {
	LOG_ERR("Failed to write to retained memory: %d\n", ret);
    }
}

static void hib_restore_data(uint8_t *data_rst, uint32_t len)
{
    const struct device *dev = RETAINED_MEM_DEVICE;

    if (!device_is_ready(dev)) {
	LOG_ERR("Retained memory device not ready\n");
	return;
    }

    int ret = retained_mem_read(dev, 0, data_rst, len);
    if (ret) {
	LOG_ERR("Failed to read from retained memory: %d\n", ret);
    }
}

/* Utility functions */
static uint32_t simple_prng(uint32_t seed, uint32_t index)
{
    /* Simple deterministic pseudo-random number generator */
    /* Uses a linear congruential generator (LCG) formula */
    uint32_t a = 1664525;
    uint32_t c = 1013904223;
    return (a * (seed + index) + c);
}

static void generate_test_data(uint8_t *data, size_t len, uint8_t pattern)
{
    for (size_t i = 0; i < len; i++) {
	if (pattern == TEST_PATTERN_PSEUDO_RANDOM) {
	    /* Generate deterministic pseudo-random data that can be reproduced
	     */
	    uint32_t pseudo_random = simple_prng(pattern, i);
	    data[i] = (uint8_t)(pseudo_random & 0xFF);
	} else {
	    /* Generate pattern-based data */
	    data[i] = pattern ^ (i & 0xFF);
	}
    }
}

static uint32_t calculate_checksum(const uint8_t *data, size_t len)
{
    uint32_t checksum = 0;
    for (size_t i = 0; i < len; i++) {
	checksum += data[i];
    }
    return checksum;
}

static void trigger_hibernation_with_timer(void)
{
    LOG_INF("Triggering hibernation for %d ms...", HIB_TEST_DURATION_MS);

#ifdef CONFIG_PM
    /* Release any power management locks to allow hibernation */
    if (pm_policy_state_lock_is_active(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES)) {
	pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
    }
#endif

    /* Use k_sleep to trigger hibernation via Zephyr PM system */
    k_sleep(K_MSEC(HIB_TEST_DURATION_MS));
}

/* Combined data structure for single save/restore operation
 * Note: test_data size is set to fit within minimum expected HIB capacity
 */
typedef struct {
    hib_test_cycle_state_t cycle_state;
    hib_test_state_t test_state;
    uint8_t test_data[HIB_COMBINED_TEST_DATA_SIZE];
} __packed hib_combined_data_t;

static hib_combined_data_t combined_storage;

static void save_combined_hibernation_data(hib_test_cycle_t next_test,
    uint32_t results, size_t data_size, uint8_t pattern,
    const uint8_t *test_data)
{
    /* Clear the combined storage */
    memset(&combined_storage, 0, sizeof(combined_storage));

    /* Fill cycle state */
    combined_storage.cycle_state.magic = HIB_TEST_CYCLE_MAGIC;
    combined_storage.cycle_state.current_test = next_test;
    combined_storage.cycle_state.test_results = results;

    /* Fill test state */
    combined_storage.test_state.magic = HIB_TEST_MAGIC;
    combined_storage.test_state.test_id = 1;
    combined_storage.test_state.data_size = data_size;
    combined_storage.test_state.pattern = pattern;
    combined_storage.test_state.checksum =
	calculate_checksum(test_data, data_size);

    /* Copy test data */
    if (data_size > 0 && test_data != NULL) {
	memcpy(combined_storage.test_data, test_data, data_size);
    }

    /* Calculate total size needed */
    size_t total_size = HIB_OVERHEAD_SIZE + data_size;

    /* Safety check - ensure we don't exceed retained memory capacity */
    size_t hib_capacity = get_retained_mem_size();
    if (total_size > hib_capacity) {
	LOG_ERR("Combined data size %zu exceeds retained memory capacity %zu\n",
	    total_size, hib_capacity);
	LOG_INF("  Overhead: %zu bytes, Data: %zu bytes", HIB_OVERHEAD_SIZE,
	    data_size);
	return;
    }

    LOG_DBG("Saving combined data - test=%d, results=0x%08x, "
	    "data_size=%zu, total=%zu/%zu",
	next_test, results, data_size, total_size, hib_capacity);
    LOG_DBG("Size breakdown - combined_struct=%zu, overhead=%zu, "
	    "max_data=%zu",
	sizeof(combined_storage), HIB_OVERHEAD_SIZE, TEST_DATA_SIZE_MAX);

    /* Single save operation - only save what we need */
    hib_save_data((uint8_t *)&combined_storage, total_size);
}

static bool load_combined_hibernation_data(hib_test_cycle_t *current_test,
    uint32_t *results, size_t *data_size, uint8_t *pattern, uint8_t *test_data)
{
    /* Clear the combined storage */
    memset(&combined_storage, 0, sizeof(combined_storage));

    /* Single restore operation - restore maximum possible size */
    hib_restore_data((uint8_t *)&combined_storage, get_retained_mem_size());

    LOG_DBG("Loaded combined data - cycle_magic=0x%08x, test_magic=0x%08x",
	combined_storage.cycle_state.magic, combined_storage.test_state.magic);
    LOG_DBG("Expected cycle_magic=0x%08x, test_magic=0x%08x",
	HIB_TEST_CYCLE_MAGIC, HIB_TEST_MAGIC);

    /* Validate cycle state */
    if (combined_storage.cycle_state.magic != HIB_TEST_CYCLE_MAGIC) {
	LOG_ERR(
	    "Invalid cycle state magic - retained memory data corrupted or not "
	    "preserved\n");
	LOG_INF("This indicates hibernation storage is not working correctly");

	/* Print first 32 bytes of raw data for debugging */
	LOG_DBG("First 32 bytes of retained memory:");
	uint8_t *raw_data = (uint8_t *)&combined_storage;
	for (int i = 0; i < 32; i += 8) {
	    LOG_DBG("  %02d: %02x %02x %02x %02x %02x %02x %02x %02x", i,
		raw_data[i], raw_data[i + 1], raw_data[i + 2], raw_data[i + 3],
		raw_data[i + 4], raw_data[i + 5], raw_data[i + 6],
		raw_data[i + 7]);
	}

	*current_test = HIB_TEST_SIMPLE;
	*results = 0;
	*data_size = 0;
	return false;
    }

    /* Extract cycle state */
    *current_test = combined_storage.cycle_state.current_test;
    *results = combined_storage.cycle_state.test_results;

    /* Validate and extract test state if present */
    if (combined_storage.test_state.magic == HIB_TEST_MAGIC) {
	*data_size = combined_storage.test_state.data_size;
	*pattern = combined_storage.test_state.pattern;

	if (*data_size > 0 && test_data != NULL) {
	    memcpy(test_data, combined_storage.test_data, *data_size);
	}

	LOG_DBG(
	    "Valid test state - data_size=%zu, pattern=0x%02x, checksum=0x%08x",
	    *data_size, *pattern, combined_storage.test_state.checksum);
    } else {
	*data_size = 0;
	*pattern = 0;
    }

    return true;
}

static const char *get_test_name(hib_test_cycle_t test)
{
    switch (test) {
	case HIB_TEST_SIMPLE:
	    return "Simple";
	case HIB_TEST_SMALL_DATA:
	    return "Small Data";
	case HIB_TEST_MEDIUM_DATA:
	    return "Medium Data";
	case HIB_TEST_LARGE_DATA:
	    return "Large Data";
	case HIB_TEST_MAX_DATA:
	    return "Max Data";
	case HIB_TEST_COMPLETE:
	    return "Complete";
	default:
	    return "Unknown";
    }
}

static bool test_hibernation_with_data(size_t data_size, uint8_t pattern,
    const char *test_name)
{
    LOG_INF("Verifying hibernation test: %s (size=%zu, pattern=0x%02x)",
	test_name, data_size, pattern);

    /* Data was already loaded by the caller, just verify it */
    hib_test_state_t *state = &combined_storage.test_state;

    /* Validate state parameters */
    if ((state->data_size != data_size) || (state->pattern != pattern)) {
	LOG_ERR("State mismatch - size: expected %zu got %u, "
		"pattern: expected 0x%02x got 0x%02x\n",
	    data_size, state->data_size, pattern, state->pattern);
	return false;
    }

    /* Copy restored data to buffer for verification */
    memcpy(restored_data_buffer, combined_storage.test_data, state->data_size);

    /* Regenerate original test data for comparison */
    generate_test_data(test_data_buffer, state->data_size, state->pattern);
    uint32_t expected_checksum =
	calculate_checksum(test_data_buffer, state->data_size);
    uint32_t actual_checksum =
	calculate_checksum(restored_data_buffer, state->data_size);

    LOG_DBG("Checksum - Expected: 0x%08x, Actual: 0x%08x, Stored: 0x%08x",
	expected_checksum, actual_checksum, state->checksum);

    if (expected_checksum != actual_checksum) {
	LOG_ERR("Checksum mismatch!\n");

	/* Debug: Print first few bytes of data */
	LOG_DBG("First 8 bytes - Expected vs Actual:");
	for (size_t i = 0; i < 8 && i < state->data_size; i++) {
	    LOG_DBG("  [%zu] 0x%02x vs 0x%02x %s", i, test_data_buffer[i],
		restored_data_buffer[i],
		(test_data_buffer[i] == restored_data_buffer[i]) ? "OK" :
								   "FAIL");
	}
	return false;
    }

    LOG_INF("SUCCESS: %s hibernation test PASSED!", test_name);
    return true;
}

static bool test_hib_hibernation_simple(void)
{
    /* Simple hibernation test with fixed-size data - only called on hibernation
     * wakeup */
    static uint8_t simple_test_data[32];
    const uint8_t test_pattern = 0xA5;
    const size_t data_size = sizeof(simple_test_data);

    LOG_INF("=== SIMPLE HIB TEST: Verifying hibernation data ===");

    /* Data was already loaded by the caller, extract from combined storage */
    if (combined_storage.test_state.data_size != data_size) {
	LOG_ERR("Simple test data size mismatch: expected %zu, got %u\n",
	    data_size, combined_storage.test_state.data_size);
	return false;
    }

    /* Print first few bytes for debugging */
    if (IS_ENABLED(CONFIG_LOG)) {
	char hex_str[32] = {0};
	for (int i = 0; i < 8; i++) {
	    snprintf(hex_str + strlen(hex_str),
		sizeof(hex_str) - strlen(hex_str), "0x%02x ",
		combined_storage.test_data[i]);
	}
	LOG_DBG("First 8 restored bytes: %s", hex_str);
    }

    /* Regenerate expected data */
    for (size_t i = 0; i < data_size; i++) {
	simple_test_data[i] = test_pattern ^ (i & 0xFF);
    }

    /* Compare data */
    bool passed = true;
    for (size_t i = 0; i < data_size; i++) {
	if (simple_test_data[i] != combined_storage.test_data[i]) {
	    LOG_ERR("Mismatch at byte %zu: expected 0x%02x, got 0x%02x\n", i,
		simple_test_data[i], combined_storage.test_data[i]);
	    passed = false;
	    if (i >= 8)
		break; /* Limit error output */
	}
    }

    if (passed) {
	LOG_INF("SUCCESS: Simple hibernation test PASSED!");
    } else {
	LOG_INF("FAILED: Simple hibernation test FAILED!");
    }

    return passed;
}

static bool run_hibernation_test_verification(hib_test_cycle_t test_type)
{
    /* This function only runs verification after hibernation wakeup */
    switch (test_type) {
	case HIB_TEST_SIMPLE:
	    return test_hib_hibernation_simple();

	case HIB_TEST_SMALL_DATA:
	    return test_hibernation_with_data(TEST_DATA_SIZE_SMALL,
		TEST_PATTERN_0x55, "small data");

	case HIB_TEST_MEDIUM_DATA:
	    return test_hibernation_with_data(TEST_DATA_SIZE_MEDIUM,
		TEST_PATTERN_0xAA, "medium data");

	case HIB_TEST_LARGE_DATA:
	    return test_hibernation_with_data(TEST_DATA_SIZE_LARGE,
		TEST_PATTERN_PSEUDO_RANDOM, "large data");

	case HIB_TEST_MAX_DATA:
	    return test_hibernation_with_data(get_max_test_data_size(),
		TEST_PATTERN_0x55, "max data");

	default:
	    LOG_ERR("Unknown hibernation test type: %d\n", test_type);
	    return false;
    }
}

static void trigger_hibernation_for_test(hib_test_cycle_t test_type)
{
    /* This function prepares data and triggers hibernation */
    LOG_INF("Triggering hibernation for test: %s", get_test_name(test_type));
    trigger_hibernation_with_timer();
}

static hib_test_cycle_t get_next_test(hib_test_cycle_t current_test)
{
    switch (current_test) {
	case HIB_TEST_SIMPLE:
	    return HIB_TEST_SMALL_DATA;
	case HIB_TEST_SMALL_DATA:
	    return HIB_TEST_MEDIUM_DATA;
	case HIB_TEST_MEDIUM_DATA:
	    return HIB_TEST_LARGE_DATA;
	case HIB_TEST_LARGE_DATA:
	    return HIB_TEST_MAX_DATA;
	case HIB_TEST_MAX_DATA:
	    return HIB_TEST_COMPLETE;
	default:
	    return HIB_TEST_COMPLETE;
    }
}

/* ZTEST setup function */
static void *retained_mem_setup(void)
{
    LOG_INF("\n=== Retained Memory Driver Test Suite ===");
    LOG_INF("Running on Atmosic SOC");

    /* Print boot status */
    if (is_boot_type(TYPE_POWER_ON)) {
	LOG_INF("Boot type: POWER_ON (cold boot)");
    } else if (is_boot_type(TYPE_HIB)) {
	LOG_INF("Boot type: HIBERNATION (woke up from hibernation)");
    } else if (is_boot_type(TYPE_RESET)) {
	LOG_INF("Boot type: RESET");
    } else if (is_boot_type(TYPE_SOCOFF)) {
	LOG_INF("Boot type: SOC_OFF");
    } else {
	LOG_INF("Boot type: UNKNOWN");
    }

    /* Verify retained memory device is ready */
    const struct device *dev = RETAINED_MEM_DEVICE;
    if (!device_is_ready(dev)) {
	LOG_ERR("Retained memory device not ready");
	return NULL;
    }
    LOG_INF("Retained memory device ready");

    return NULL;
}

/* Basic retained memory tests */
ZTEST(retained_mem, test_size_validation)
{
    /* Only run size validation on cold boot */
    if (!is_boot_type(TYPE_POWER_ON)) {
	ztest_test_skip();
	return;
    }

    size_t hib_capacity = get_retained_mem_size();

    LOG_INF("=== Retained Memory Size Analysis ===");
    LOG_INF("Actual retained memory size: %zu bytes", hib_capacity);
    LOG_INF("Cycle state size: %zu bytes", sizeof(hib_test_cycle_state_t));
    LOG_INF("Test state size: %zu bytes", sizeof(hib_test_state_t));
    LOG_INF("HIB overhead total: %zu bytes", HIB_OVERHEAD_SIZE);
    LOG_INF("Compile-time max test data: %zu bytes",
	(size_t)TEST_DATA_SIZE_MAX);
    LOG_INF("Actual max test data size: %zu bytes", get_max_test_data_size());
    LOG_INF("Combined structure size: %zu bytes", sizeof(combined_storage));

    /* Validate that our structure fits in the available capacity */
    zassert_true(sizeof(combined_storage) <= hib_capacity,
	"Combined structure (%zu) exceeds HIB capacity (%zu)",
	sizeof(combined_storage), hib_capacity);

    /* Validate that we have reasonable capacity for testing */
    zassert_true(hib_capacity >= 128,
	"Retained memory capacity (%zu) seems too small for meaningful testing",
	hib_capacity);

    LOG_INF("Remaining capacity: %zu bytes",
	hib_capacity - sizeof(combined_storage));

    LOG_INF("✅ Size validation passed - structure fits in retained memory");
}

ZTEST(retained_mem, test_basic_save_restore)
{
    /* Only run basic tests on cold boot */
    if (!is_boot_type(TYPE_POWER_ON)) {
	ztest_test_skip();
	return;
    }

    LOG_INF("Testing basic save/restore without hibernation...");

    uint8_t test_data[32];
    uint8_t restored_data[32];

    /* Generate test data */
    for (int i = 0; i < 32; i++) {
	test_data[i] = (uint8_t)(i ^ 0xAA);
    }

    /* Save data */
    hib_save_data(test_data, sizeof(test_data));

    /* Clear buffer */
    memset(restored_data, 0, sizeof(restored_data));

    /* Restore data */
    hib_restore_data(restored_data, sizeof(restored_data));

    /* Verify data */
    zassert_mem_equal(test_data, restored_data, sizeof(test_data),
	"Restored data should match original data");
}

ZTEST(retained_mem, test_magic_values_preservation)
{
    /* Only run basic tests on cold boot */
    if (!is_boot_type(TYPE_POWER_ON)) {
	ztest_test_skip();
	return;
    }

    LOG_INF("Testing magic value preservation in retained memory...");

    /* Test if magic values are preserved correctly */
    hib_test_cycle_state_t test_cycle_state = {.magic = HIB_TEST_CYCLE_MAGIC,
	.current_test = HIB_TEST_SIMPLE,
	.test_results = 0x12345678};

    /* Save the structures */
    hib_save_data((uint8_t *)&test_cycle_state, sizeof(test_cycle_state));

    /* Clear and restore */
    hib_test_cycle_state_t restored_cycle_state = {0};
    hib_restore_data((uint8_t *)&restored_cycle_state,
	sizeof(restored_cycle_state));

    /* Verify magic values are preserved */
    zassert_equal(restored_cycle_state.magic, HIB_TEST_CYCLE_MAGIC,
	"Cycle state magic should be preserved");
    zassert_equal(restored_cycle_state.current_test, HIB_TEST_SIMPLE,
	"Current test should be preserved");
    zassert_equal(restored_cycle_state.test_results, 0x12345678,
	"Test results should be preserved");
}

ZTEST(retained_mem, test_zero_data)
{
    /* Only run basic tests on cold boot */
    if (!is_boot_type(TYPE_POWER_ON)) {
	ztest_test_skip();
	return;
    }

    LOG_INF("Testing zero data preservation...");

    uint8_t zero_data[16] = {0};
    uint8_t restored_data[16];

    /* Save zero data */
    hib_save_data(zero_data, sizeof(zero_data));

    /* Fill with non-zero pattern */
    memset(restored_data, 0xFF, sizeof(restored_data));

    /* Restore data */
    hib_restore_data(restored_data, sizeof(restored_data));

    /* Verify all zeros */
    for (int i = 0; i < 16; i++) {
	zassert_equal(restored_data[i], 0, "Byte %d should be zero", i);
    }
}

ZTEST(retained_mem, test_single_byte)
{
    /* Only run basic tests on cold boot */
    if (!is_boot_type(TYPE_POWER_ON)) {
	ztest_test_skip();
	return;
    }

    LOG_INF("Testing single byte save/restore...");

    uint8_t test_byte = 0x42;
    uint8_t restored_byte = 0;

    hib_save_data(&test_byte, 1);
    hib_restore_data(&restored_byte, 1);

    zassert_equal(restored_byte, test_byte, "Single byte should be preserved");
}

ZTEST(retained_mem, test_max_size_data)
{
    /* Only run basic tests on cold boot */
    if (!is_boot_type(TYPE_POWER_ON)) {
	ztest_test_skip();
	return;
    }

    size_t max_data_size = get_max_test_data_size();
    LOG_INF("Testing maximum test data size (%zu bytes)...", max_data_size);

    uint8_t *test_data = test_data_buffer;
    uint8_t *restored_data = restored_data_buffer;

    /* Generate test data with checksum pattern */
    for (size_t i = 0; i < max_data_size; i++) {
	test_data[i] = (uint8_t)(i ^ (i >> 8));
    }

    /* Save and restore */
    hib_save_data(test_data, max_data_size);
    memset(restored_data, 0, max_data_size);
    hib_restore_data(restored_data, max_data_size);

    /* Verify data */
    zassert_mem_equal(test_data, restored_data, max_data_size,
	"Max test data size should be preserved");
}

ZTEST(retained_mem, test_retained_mem_capacity)
{
    /* Only run basic tests on cold boot */
    if (!is_boot_type(TYPE_POWER_ON)) {
	ztest_test_skip();
	return;
    }

    size_t hib_capacity = get_retained_mem_size();
    LOG_INF("Testing retained memory full capacity (%zu bytes)...",
	hib_capacity);

    /* Allocate buffers for full HIB storage test */
    static uint8_t full_test_data[MEM_RETAINED_SIZE_MAX];
    static uint8_t full_restored_data[MEM_RETAINED_SIZE_MAX];

    /* Generate test data with checksum pattern */
    for (size_t i = 0; i < hib_capacity; i++) {
	full_test_data[i] = (uint8_t)(i ^ (i >> 8));
    }

    /* Save and restore */
    hib_save_data(full_test_data, hib_capacity);
    memset(full_restored_data, 0, hib_capacity);
    hib_restore_data(full_restored_data, hib_capacity);

    /* Verify data */
    zassert_mem_equal(full_test_data, full_restored_data, hib_capacity,
	"Full retained memory capacity should be preserved");
}

ZTEST(retained_mem, test_multiple_cycles)
{
    /* Only run basic tests on cold boot */
    if (!is_boot_type(TYPE_POWER_ON)) {
	ztest_test_skip();
	return;
    }

    LOG_INF("Testing multiple save/restore cycles...");

    uint8_t test_data[32];
    uint8_t restored_data[32];

    /* Test multiple save/restore cycles */
    for (int cycle = 0; cycle < 3; cycle++) {
	/* Generate different data each cycle */
	for (size_t i = 0; i < sizeof(test_data); i++) {
	    test_data[i] = (uint8_t)(cycle * 0x11 + i);
	}

	/* Save data */
	hib_save_data(test_data, sizeof(test_data));

	/* Clear restored buffer */
	memset(restored_data, ~(cycle + 1), sizeof(restored_data));

	/* Restore data */
	hib_restore_data(restored_data, sizeof(restored_data));

	/* Verify data integrity for this cycle */
	zassert_mem_equal(test_data, restored_data, sizeof(test_data),
	    "Data should be preserved in cycle %d", cycle);
    }
}

/* Hibernation test - handles both cold boot and hibernation wakeup */
/* Named with 'z_' prefix to run last alphabetically */
ZTEST(retained_mem, z_test_hibernation_cycle)
{
    hib_test_cycle_t current_test;
    uint32_t test_results;

    if (is_boot_type(TYPE_HIB)) {
	/* Hibernation wakeup - verify previous test and continue cycle */
	size_t data_size;
	uint8_t pattern;
	if (!load_combined_hibernation_data(&current_test, &test_results,
		&data_size, &pattern, NULL)) {
	    LOG_INF(
		"WARNING: Could not load hibernation test data - retained memory "
		"may not be working");
	    LOG_INF("This could indicate:");
	    LOG_INF(
		"1. Retained memory is not preserving data across hibernation");
	    LOG_INF("2. Data corruption during hibernation/wakeup");
	    LOG_INF("3. Retained memory size/alignment issues");
	    LOG_INF("Skipping hibernation test validation");
	    return;
	}

	LOG_INF("=== Hibernation Wakeup: Running %s Test ===",
	    get_test_name(current_test));

	/* Run the current hibernation test verification */
	bool test_passed = run_hibernation_test_verification(current_test);
	zassert_true(test_passed, "%s hibernation test should pass",
	    get_test_name(current_test));

	/* Update test results */
	if (test_passed) {
	    test_results |= (1 << current_test);
	}

	/* Move to next test */
	hib_test_cycle_t next_test = get_next_test(current_test);

	if (next_test == HIB_TEST_COMPLETE) {
	    /* All hibernation tests completed */
	    LOG_INF("\n=== All Hibernation Tests Completed ===");
	    LOG_INF("Test Results Summary:");
	    LOG_INF("- Simple Test:     %s",
		(test_results & (1 << HIB_TEST_SIMPLE)) ? "PASS" : "FAIL");
	    LOG_INF("- Small Data:      %s",
		(test_results & (1 << HIB_TEST_SMALL_DATA)) ? "PASS" : "FAIL");
	    LOG_INF("- Medium Data:     %s",
		(test_results & (1 << HIB_TEST_MEDIUM_DATA)) ? "PASS" : "FAIL");
	    LOG_INF("- Large Data:      %s",
		(test_results & (1 << HIB_TEST_LARGE_DATA)) ? "PASS" : "FAIL");
	    LOG_INF("- Max Data:        %s",
		(test_results & (1 << HIB_TEST_MAX_DATA)) ? "PASS" : "FAIL");

	    int passed_count = __builtin_popcount(test_results);
	    LOG_INF("Total: %d/5 hibernation tests passed", passed_count);

	    if (passed_count == 5) {
		LOG_INF("🎉 ALL HIBERNATION TESTS PASSED! 🎉");
		LOG_INF("\n=== FINAL TEST SUMMARY ===");
		LOG_INF("Basic Tests: 6/6 PASSED");
		LOG_INF("Hibernation Tests: 5/5 PASSED");
		LOG_INF("🎉 ALL TESTS COMPLETED SUCCESSFULLY! 🎉");
	    } else {
		LOG_INF("❌ Some hibernation tests failed");
		LOG_INF("\n=== FINAL TEST SUMMARY ===");
		LOG_INF("Basic Tests: 6/6 PASSED");
		LOG_INF("Hibernation Tests: %d/5 PASSED", passed_count);
		LOG_INF("❌ SOME TESTS FAILED");
	    }
	} else {
	    /* Prepare for next hibernation test */
	    LOG_INF("\n=== Preparing Next Test: %s ===",
		get_test_name(next_test));

	    /* Prepare test data for next test */
	    size_t next_data_size;
	    uint8_t next_pattern;

	    switch (next_test) {
		case HIB_TEST_SIMPLE:
		    next_data_size = 32;
		    next_pattern = 0xA5;
		    break;
		case HIB_TEST_SMALL_DATA:
		    next_data_size = TEST_DATA_SIZE_SMALL;
		    next_pattern = TEST_PATTERN_0x55;
		    break;
		case HIB_TEST_MEDIUM_DATA:
		    next_data_size = TEST_DATA_SIZE_MEDIUM;
		    next_pattern = TEST_PATTERN_0xAA;
		    break;
		case HIB_TEST_LARGE_DATA:
		    next_data_size = TEST_DATA_SIZE_LARGE;
		    next_pattern = TEST_PATTERN_PSEUDO_RANDOM;
		    break;
		case HIB_TEST_MAX_DATA:
		    next_data_size = get_max_test_data_size();
		    next_pattern = TEST_PATTERN_0x55;
		    break;
		default:
		    next_data_size = 32;
		    next_pattern = 0xA5;
		    break;
	    }

	    /* Generate test data */
	    generate_test_data(test_data_buffer, next_data_size, next_pattern);

	    /* Save combined data and trigger hibernation */
	    save_combined_hibernation_data(next_test, test_results,
		next_data_size, next_pattern, test_data_buffer);
	    trigger_hibernation_for_test(next_test);

	    /* Should not reach here if hibernation worked */
	    LOG_INF("Warning: System did not hibernate as expected");
	}
    } else {
	/* Cold boot - start hibernation test cycle */
	LOG_INF("=== Cold Boot: Starting Hibernation Test Cycle ===");
	LOG_INF("Will run 5 hibernation tests across multiple wake cycles:");
	LOG_INF("1. Simple Test (32 bytes)");
	LOG_INF("2. Small Data (%d bytes)", TEST_DATA_SIZE_SMALL);
	LOG_INF("3. Medium Data (%d bytes)", TEST_DATA_SIZE_MEDIUM);
	LOG_INF("4. Large Data (%d bytes, pseudo-random)",
	    TEST_DATA_SIZE_LARGE);
	LOG_INF("5. Max Data (%zu bytes)", get_max_test_data_size());

	/* Start with simple test */
	current_test = HIB_TEST_SIMPLE;
	test_results = 0;

	LOG_INF("\n=== Starting Test 1: %s ===", get_test_name(current_test));

	/* Generate simple test data */
	const size_t simple_data_size = 32;
	const uint8_t simple_pattern = 0xA5;
	for (size_t i = 0; i < simple_data_size; i++) {
	    test_data_buffer[i] = simple_pattern ^ (i & 0xFF);
	}

	/* Save combined data and trigger hibernation */
	save_combined_hibernation_data(current_test, test_results,
	    simple_data_size, simple_pattern, test_data_buffer);
	trigger_hibernation_for_test(current_test);

	/* Should not reach here if hibernation worked */
	zassert_true(false, "System should have hibernated");
    }
}

/* ZTEST suite definition */
ZTEST_SUITE(retained_mem, NULL, retained_mem_setup, NULL, NULL, NULL);
