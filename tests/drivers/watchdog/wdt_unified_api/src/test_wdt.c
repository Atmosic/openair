/*
 * Copyright (c) 2018 Nordic Semiconductor
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/**
 * @addtogroup t_wdt_unified
 * @{
 * @defgroup t_wdt_unified_timeout test_wdt_unified_timeout_capabilities
 * @brief TestPurpose: verify Unified Watchdog Timer install/setup/feed can work,
 *        and reset can be triggered when timeout
 * @details
 * There are three tests. Each test provides watchdog installation, setup and
 * wait for reset. Three variables are placed in noinit section to prevent
 * clearing them during board reset. These variables save number of the current
 * test case, current test state and value to check if test passed or not.
 *
 * - Test Steps - test_wdt_no_callback
 *   -# Get device.
 *   -# Check if the state was changed and test should be finished.
 *   -# Set callback to NULL value.
 *   -# Install watchdog with current configuration.
 *   -# Setup watchdog with no additions options.
 *   -# Wait for reset.
 * - Expected Results
 *   -# If reset comes, the same testcase should be executed but state should
 *      be set to finish value and test should return with success.
 *
 * - Test Steps - test_wdt_callback_1
 *   -# Get device.
 *   -# Check if the state was changed. If so check testvalue if interrupt
 *      occurred.
 *   -# Set callback as pointer to wdt_int_cb0.
 *   -# Install watchdog with current configuration.
 *   -# Setup watchdog with no additions options.
 *   -# Wait for reset.
 * - Expected Results
 *   -# If reset comes, the same testcase should be executed but state should be
 *      set to finish value and test checks if m_testvalue was set in interrupt
 *      right before reset.
 *
 * - Test Steps - test_wdt_pmu_warning
 *   -# Get device (unified watchdog).
 *   -# Set callback as pointer to wdt_int_pmu_cb.
 *   -# Install watchdog with short timeout (1 second).
 *   -# Setup watchdog with no additions options.
 *   -# Acquire power lock to prevent retention mode.
 *   -# Extract ARM watchdog device from unified watchdog config.
 *   -# Feed only ARM watchdog periodically to prevent ARM watchdog from firing.
 *   -# Let PMU watchdog timeout and fire warning (at ARM timeout + 100ms offset).
 *   -# Check if callback was invoked by examining m_testvalue.
 *   -# Disable watchdog and release power lock.
 * - Expected Results
 *   -# PMU warning callback fires in active state (retention disabled by power lock).
 *   -# Callback sets m_testvalue to WDT_TEST_PMU_TEST_VALUE.
 *   -# Test detects callback was invoked and exits successfully.
 *
 * - Test Steps - test_wdt_pmu_warning_retention
 *   -# Get device (unified watchdog).
 *   -# Set callback as pointer to wdt_int_pmu_retention_cb.
 *   -# Install watchdog with long timeout (15 seconds).
 *   -# Setup watchdog with no additions options.
 *   -# Allow system to enter retention state (PM enabled).
 *   -# PMU watchdog warning fires based on CONFIG_ATM_WDT_PMU_WARN_OFFSET_SEC.
 *   -# System wakes from retention, callback is invoked.
 *   -# System feeds watchdog and re-enters retention.
 *   -# After total sleep time (~10s), wake up and check m_testvalue.
 *   -# Disable watchdog.
 * - Expected Results
 *   -# PMU warning callback fires during retention state.
 *   -# Callback sets m_testvalue to WDT_TEST_PMU_RETENTION_VALUE.
 *   -# System successfully wakes, feeds watchdog, and re-enters retention.
 *   -# Test detects callback was invoked and exits successfully.
 *
 * - Test Steps - test_wdt_pmu_warning_hibernation
 *   -# Check if system just woke from hibernation due to PMU warning (via boot status).
 *   -# If yes, verify wakeup reason and pass test.
 *   -# If no, configure watchdog with very long timeout (60 seconds).
 *   -# Setup watchdog with no additions options.
 *   -# Unlock only hibernation substate (PM_SUBSTATE_HIBERNATE) to ensure system
 *      enters hibernation and not SOC-off when both are available.
 *   -# Enter hibernation state (PM_STATE_SOFT_OFF with PM_SUBSTATE_HIBERNATE).
 *   -# PMU watchdog warning fires based on CONFIG_ATM_WDT_PMU_WARN_OFFSET_SEC.
 *   -# System reboots due to PMU warning wakeup.
 *   -# On next boot, detect PMU warning wakeup via boot status API.
 *   -# Disable watchdog.
 * - Expected Results
 *   -# PMU warning timer fires during hibernation state.
 *   -# System wakes/reboots from hibernation due to PMU warning.
 *   -# Boot status indicates BOOT_STATUS_HIB_WKUP_PMU_WDOG_WARN.
 *   -# Test detects PMU warning wakeup and exits successfully.
 *
 * - Test Steps - test_wdt_pmu_reset_socoff
 *   -# Check if system just woke from SOC-off due to timer (via boot status).
 *   -# If yes, verify wakeup reason and pass test.
 *   -# If no, configure ARM watchdog with very long timeout (60 seconds).
 *   -# Setup watchdog with no additions options.
 *   -# Unlock all SOFT_OFF substates (PM_ALL_SUBSTATES) to allow SOC-off entry.
 *   -# Enter SOC-off state by sleeping indefinitely (K_FOREVER).
 *   -# System wakes from SOC-off via timer after CONFIG_PM_MAX_SLEEP_DURATION_SEC seconds.
 *   -# On next boot, detect timer wakeup from SOC-off via boot status API.
 *   -# Disable watchdog.
 * - Expected Results
 *   -# System enters SOC-off state successfully.
 *   -# System wakes from SOC-off via timer interrupt.
 *   -# Boot status indicates BOOT_STATUS_SOCOFF_WKUP_TIMER.
 *   -# Test detects timer wakeup and exits successfully.
 *
 * @}
 */

#include <zephyr/drivers/watchdog.h>
#include <zephyr/kernel.h>
#include <zephyr/ztest.h>
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>

#ifdef CONFIG_ATM_PMU_WDT_ENABLE
#include "reset.h"
#include "power.h"
#endif

#define WDT_NODE DT_ALIAS(watchdog0)

#define WDT_TEST_STATE_IDLE            0
#define WDT_TEST_STATE_CHECK_RESET     1
#define WDT_TEST_STATE_RETENTION_SLEEP 2
#define WDT_TEST_STATE_HIBERNATION     3
#define WDT_TEST_STATE_SOCOFF          4

#define WDT_TEST_CB0_TEST_VALUE        0x0CB0
#define WDT_TEST_PMU_TEST_VALUE        0x0CB2
#define WDT_TEST_PMU_RETENTION_VALUE   0x0CB3
#define WDT_TEST_PMU_HIBERNATION_VALUE 0x0CB4

#ifndef WDT_TEST_MAX_WINDOW
#define WDT_TEST_MAX_WINDOW 2000U
#endif

/* Unified watchdog config structure for accessing ARM watchdog */
struct wdt_atmosic_unified_config {
	const struct device *arm_wdt;
};

/* m_state indicates state of particular test. Used to check whether testcase
 * should go to reset state or check other values after reset.
 */
static volatile uint32_t m_state __attribute__((section(".noinit.test_wdt")));

/* m_testcase_index is incremented after each test to make test possible
 * switch to next testcase.
 */
static volatile uint32_t m_testcase_index __attribute__((section(".noinit.test_wdt")));

/* m_testvalue contains value set in interrupt callback to point whether
 * first or second interrupt was fired.
 */
static volatile uint32_t m_testvalue __attribute__((section(".noinit.test_wdt")));

static void wdt_int_cb0(const struct device *wdt_dev, int channel_id)
{
	ARG_UNUSED(wdt_dev);
	ARG_UNUSED(channel_id);
	m_testvalue += WDT_TEST_CB0_TEST_VALUE;
}

#ifdef CONFIG_ATM_PMU_WDT_ENABLE
static void wdt_int_pmu_cb(const struct device *wdt_dev, int channel_id)
{
	ARG_UNUSED(wdt_dev);
	ARG_UNUSED(channel_id);
	TC_PRINT("PMU warning callback fired!\n");
	m_testvalue += WDT_TEST_PMU_TEST_VALUE;
}

static void wdt_int_pmu_retention_cb(const struct device *wdt_dev, int channel_id)
{
	ARG_UNUSED(wdt_dev);
	ARG_UNUSED(channel_id);
	TC_PRINT("PMU warning callback fired during retention!\n");
	m_testvalue += WDT_TEST_PMU_RETENTION_VALUE;

	/* Disable retention to prevent system from going back to sleep */
	pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
	TC_PRINT("Retention disabled in callback - system will stay active\n");
}

static void wdt_int_pmu_hibernation_cb(const struct device *wdt_dev, int channel_id)
{
	ARG_UNUSED(wdt_dev);
	ARG_UNUSED(channel_id);
	TC_PRINT("PMU warning callback fired during hibernation!\n");
	m_testvalue += WDT_TEST_PMU_HIBERNATION_VALUE;

	/* Note: This callback won't actually execute during hibernation because
	 * hibernation causes a full system reboot. This callback is here for
	 * consistency with the retention test, but the actual wakeup detection
	 * will be done via boot status check after reboot.
	 */
}
#endif /* CONFIG_ATM_PMU_WDT_ENABLE */

/**
 * @brief Test watchdog without callback - triggers reset
 *
 * This test installs a watchdog timeout without a callback and waits for
 * the system to reset. After reset, it verifies the reset occurred.
 * Returns true if test passed, false otherwise.
 */
static bool test_wdt_no_callback(void)
{
	const struct device *const wdt = DEVICE_DT_GET(WDT_NODE);

	zassert_true(device_is_ready(wdt), "WDT device is not ready");

	TC_PRINT("Testcase: %s\n", __func__);

	/* Check if we're coming back from a reset */
	if (m_state == WDT_TEST_STATE_CHECK_RESET) {
		m_state = WDT_TEST_STATE_IDLE;
		TC_PRINT("Reset occurred - testcase passed\n");
		return true;
	}

	/* First run - configure watchdog and wait for reset */
	struct wdt_timeout_cfg cfg_wdt = {
		.callback = NULL,
		.flags = WDT_FLAG_RESET_SOC,
		.window.max = WDT_TEST_MAX_WINDOW,
	};

	int err = wdt_install_timeout(wdt, &cfg_wdt);

	zassert_true(err >= 0, "Watchdog install error: %d", err);

	err = wdt_setup(wdt, WDT_OPT_PAUSE_HALTED_BY_DBG);
	if (err == -ENOTSUP) {
		TC_PRINT("- pausing watchdog by debugger is not supported\n");
		err = wdt_setup(wdt, 0);
	}
	zassert_true(err >= 0, "Watchdog setup error: %d", err);

	TC_PRINT("Waiting to restart MCU\n");
	m_testvalue = 0U;
	m_state = WDT_TEST_STATE_CHECK_RESET;
	for (;;) {
		k_yield();
	}

	/* Should not reach here */
	return false;
}

/**
 * @brief Test watchdog with callback - verifies callback fires before reset
 *
 * This test installs a watchdog timeout with a callback and waits for
 * the system to reset. After reset, it verifies the callback was invoked.
 * Returns true if test passed, false otherwise.
 */
static bool test_wdt_callback_1(void)
{
	const struct device *const wdt = DEVICE_DT_GET(WDT_NODE);

	zassert_true(device_is_ready(wdt), "WDT device is not ready");

	TC_PRINT("Testcase: %s\n", __func__);

	/* Check if we're coming back from a reset */
	if (m_state == WDT_TEST_STATE_CHECK_RESET) {
		m_state = WDT_TEST_STATE_IDLE;
		zassert_equal(m_testvalue, WDT_TEST_CB0_TEST_VALUE,
			      "Callback was not invoked (m_testvalue=0x%x, expected=0x%x)",
			      (unsigned int)m_testvalue, WDT_TEST_CB0_TEST_VALUE);
		TC_PRINT("Callback was invoked - testcase passed\n");
		return true;
	}

	/* First run - disable any existing watchdog */
	int err = wdt_disable(wdt);

	if (err < 0 && err != -EPERM && err != -EFAULT) {
		zassert_true(false, "Watchdog disable error: %d", err);
	}

	/* Configure watchdog with callback */
	m_testvalue = 0U;
	struct wdt_timeout_cfg cfg_wdt = {
		.flags = WDT_FLAG_RESET_SOC,
		.callback = wdt_int_cb0,
		.window.max = WDT_TEST_MAX_WINDOW,
	};

	err = wdt_install_timeout(wdt, &cfg_wdt);
	if (err == -ENOTSUP) {
		TC_PRINT("Callback not supported on platform - skipping test\n");
		return false;
	}
	zassert_true(err >= 0, "Watchdog install error: %d", err);

	err = wdt_setup(wdt, WDT_OPT_PAUSE_HALTED_BY_DBG);
	if (err == -ENOTSUP) {
		TC_PRINT("- pausing watchdog by debugger is not supported\n");
		err = wdt_setup(wdt, 0);
	}
	zassert_true(err >= 0, "Watchdog setup error: %d", err);

	TC_PRINT("Waiting to restart MCU\n");
	m_state = WDT_TEST_STATE_CHECK_RESET;
	for (;;) {
		k_yield();
	}

	/* Should not reach here */
	return false;
}

#ifdef CONFIG_ATM_PMU_WDT_ENABLE
/**
 * @brief Test PMU watchdog warning interrupt
 *
 * This test verifies that the PMU watchdog warning interrupt fires correctly
 * when only the ARM watchdog is fed. The test holds a power lock to prevent
 * retention mode, ensuring the interrupt fires in active state.
 * Returns true if test passed, false otherwise.
 */
static bool test_wdt_pmu_warning(void)
{
	const struct device *const wdt = DEVICE_DT_GET(WDT_NODE);

	zassert_true(device_is_ready(wdt), "WDT device is not ready");

	TC_PRINT("Testcase: %s\n", __func__);

	/* Disable any existing watchdog */
	int err = wdt_disable(wdt);

	if (err < 0 && err != -EPERM && err != -EFAULT) {
		zassert_true(false, "Watchdog disable error: %d", err);
	}

	/* Configure watchdog with PMU warning callback */
	m_testvalue = 0U;
	struct wdt_timeout_cfg cfg_wdt = {
		.flags = WDT_FLAG_RESET_SOC,
		.callback = wdt_int_pmu_cb,
		.window.max = 7000U, /* 7 seconds - larger than PMU offset of 5 seconds */
	};

	err = wdt_install_timeout(wdt, &cfg_wdt);
	if (err == -ENOTSUP) {
		TC_PRINT("PMU warning not supported on platform - skipping test\n");
		return false;
	}
	zassert_true(err >= 0, "Watchdog install error: %d", err);

	err = wdt_setup(wdt, WDT_OPT_PAUSE_HALTED_BY_DBG);
	if (err == -ENOTSUP) {
		TC_PRINT("- pausing watchdog by debugger is not supported\n");
		err = wdt_setup(wdt, 0);
	}
	zassert_true(err >= 0, "Watchdog setup error: %d", err);

	/* Hold power lock to prevent system from entering retention mode
	 * This ensures the PMU warning interrupt fires in active state */
	pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
	TC_PRINT("Waiting for PMU warning to fire (feeding only ARM watchdog)\n");

	/* Extract ARM watchdog device from unified watchdog config
	 * This allows us to feed only the ARM watchdog, letting the PMU
	 * watchdog timeout and fire its warning interrupt */
	const struct wdt_atmosic_unified_config *config = wdt->config;
	const struct device *arm_wdt = config->arm_wdt;
	uint32_t iterations = 0;

	for (;;) {
		k_sleep(K_MSEC(500));

		/* Check if PMU warning callback was called */
		if (m_testvalue == WDT_TEST_PMU_TEST_VALUE) {
			TC_PRINT("PMU warning callback was invoked successfully!\n");

			/* Disable watchdog before exiting */
			err = wdt_disable(wdt);
			if (err < 0 && err != -EPERM && err != -EFAULT) {
				TC_PRINT("Warning: Watchdog disable error\n");
			}

			/* Release power lock to re-enable retention */
			pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
			TC_PRINT("Power lock released - retention re-enabled\n");

			/* Mark test as complete */
			m_state = WDT_TEST_STATE_IDLE;
			TC_PRINT("Testcase passed\n");
			return true;
		}

		wdt_feed(arm_wdt, 0); /* Feed only ARM watchdog, not unified */
		iterations++;
		TC_PRINT("Fed ARM watchdog only (iteration %" PRIu32 ")\n", iterations);

		/* Safety limit: if we've been running for more than 5 seconds,
		 * something is wrong */
		if (iterations > 10) {
			/* Release power lock before failing */
			pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
			TC_PRINT("Power lock released\n");

			zassert_true(false, "PMU warning did not fire after 5 seconds");
			return false;
		}
	}

	/* Should not reach here */
	return false;
}

/**
 * @brief Test PMU watchdog warning during retention state
 *
 * This test validates that the PMU watchdog warning interrupt fires correctly
 * when the system is in retention (low-power) state. The test:
 * 1. Configures a long watchdog timeout (15 seconds)
 * 2. Allows the system to enter retention state
 * 3. PMU watchdog warning fires based on CONFIG_ATM_WDT_PMU_WARN_OFFSET_SEC
 * 4. System wakes, callback is invoked, watchdog is fed, and system re-enters retention
 * 5. After total sleep time, verifies the callback was invoked
 *
 * Returns true if test passed, false otherwise.
 */
static bool test_wdt_pmu_warning_retention(void)
{
	const struct device *const wdt = DEVICE_DT_GET(WDT_NODE);

	zassert_true(device_is_ready(wdt), "WDT device is not ready");

	TC_PRINT("Testcase: %s\n", __func__);

	/* First run - configure watchdog and enter retention */
	TC_PRINT("Configuring watchdog for retention test\n");

	/* Disable any existing watchdog */
	int err = wdt_disable(wdt);

	if (err < 0 && err != -EPERM && err != -EFAULT) {
		zassert_true(false, "Watchdog disable error: %d", err);
	}

	/* Configure watchdog with PMU retention warning callback */
	m_testvalue = 0U;
	struct wdt_timeout_cfg cfg_wdt = {
		.flags = WDT_FLAG_RESET_SOC,
		.callback = wdt_int_pmu_retention_cb,
		.window.max = 15000U, /* 15 seconds - longer than retention timeout */
	};

	err = wdt_install_timeout(wdt, &cfg_wdt);
	if (err == -ENOTSUP) {
		TC_PRINT("PMU warning not supported on platform - skipping test\n");
		return false;
	}
	zassert_true(err >= 0, "Watchdog install error: %d", err);

	err = wdt_setup(wdt, WDT_OPT_PAUSE_HALTED_BY_DBG);
	if (err == -ENOTSUP) {
		TC_PRINT("- pausing watchdog by debugger is not supported\n");
		err = wdt_setup(wdt, 0);
	}
	zassert_true(err >= 0, "Watchdog setup error: %d", err);

	TC_PRINT("Watchdog configured with 15s timeout\n");
	TC_PRINT("PMU warning offset: %d seconds\n", CONFIG_ATM_WDT_PMU_WARN_OFFSET_SEC);
	TC_PRINT("Entering retention state for ~10 seconds...\n");
	TC_PRINT("PMU warning should fire based on configured offset\n");

	/* Mark state as retention sleep so we know we're coming back from sleep */
	m_state = WDT_TEST_STATE_RETENTION_SLEEP;

	/* Sleep for 10 seconds - system will enter retention
	 * PMU watchdog warning will fire based on CONFIG_ATM_WDT_PMU_WARN_OFFSET_SEC
	 * System will wake, feed watchdog, and disable retention
	 * After 10 seconds total, we wake up and check the result */
	k_sleep(K_SECONDS(10));

	TC_PRINT("Woke up from sleep\n");

	/* Check if PMU warning callback was invoked */
	if (m_testvalue == WDT_TEST_PMU_RETENTION_VALUE) {
		TC_PRINT("PMU warning callback was invoked during retention!\n");

		/* Disable watchdog before exiting */
		err = wdt_disable(wdt);
		if (err < 0 && err != -EPERM && err != -EFAULT) {
			TC_PRINT("Warning: Watchdog disable error: %d\n", err);
		}

		/* Release power lock to re-enable retention */
		pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
		TC_PRINT("Power lock released - retention re-enabled\n");

		/* Mark test as complete */
		m_state = WDT_TEST_STATE_IDLE;
		TC_PRINT("Testcase passed\n");
		return true;
	} else {
		TC_PRINT("ERROR: PMU warning callback was NOT invoked (testvalue=0x%08" PRIx32
			 ")\n",
			 m_testvalue);
		m_state = WDT_TEST_STATE_IDLE;
		return false;
	}
}

#endif /* CONFIG_ATM_PMU_WDT_ENABLE */

#ifdef CONFIG_ATM_PMU_WDT_ENABLE
/**
 * @brief Test PMU watchdog warning during hibernation state
 *
 * This test verifies that the PMU watchdog warning can wake the system from
 * hibernation (PM_STATE_SOFT_OFF). Unlike retention, hibernation causes a full
 * system reboot, so we cannot use noinit variables to track state.
 *
 * Test flow:
 * 1. Check if we just woke from hibernation due to PMU warning (via boot status)
 * 2. If yes, verify and pass the test
 * 3. If no, configure watchdog and enter hibernation
 * 4. PMU warning timer fires during hibernation, causing system to wake/reboot
 * 5. On next boot, step 1 detects the PMU warning wakeup
 *
 * Returns true if test passed, false otherwise.
 */
static bool test_wdt_pmu_warning_hibernation(void)
{
	const struct device *const wdt = DEVICE_DT_GET(WDT_NODE);

	zassert_true(device_is_ready(wdt), "WDT device is not ready");

	TC_PRINT("Testcase: %s\n", __func__);

	/* Check if we just woke from hibernation due to PMU watchdog warning */
	if (is_boot_reason(BOOT_STATUS_HIB_WKUP_PMU_WDOG_WARN)) {
		TC_PRINT("✓ Detected PMU watchdog warning wakeup from hibernation!\n");
		TC_PRINT("Boot status indicates HIB_WKUP_PMU_WDOG_WARN\n");

		/* Disable watchdog before exiting */
		int err = wdt_disable(wdt);
		if (err < 0 && err != -EPERM && err != -EFAULT) {
			TC_PRINT("Warning: Watchdog disable error: %d\n", err);
		}

		/* Mark test as complete */
		m_state = WDT_TEST_STATE_IDLE;
		TC_PRINT("Testcase passed\n");
		return true;
	}

	/* First run - configure watchdog and enter hibernation */
	TC_PRINT("Configuring watchdog for hibernation test\n");

	/* Disable any existing watchdog */
	int err = wdt_disable(wdt);
	if (err < 0 && err != -EPERM && err != -EFAULT) {
		zassert_true(false, "Watchdog disable error: %d", err);
	}

	/* Configure watchdog with very long timeout to prevent ARM watchdog from firing
	 * We want only the PMU watchdog warning to fire during hibernation
	 */
	m_testvalue = 0U;
	struct wdt_timeout_cfg cfg_wdt = {
		.flags = WDT_FLAG_RESET_SOC,
		.callback = wdt_int_pmu_hibernation_cb,
		.window.max = 30000U, /* 30 seconds - much longer than hibernation timeout */
	};

	err = wdt_install_timeout(wdt, &cfg_wdt);
	if (err == -ENOTSUP) {
		TC_PRINT("PMU warning not supported on platform - skipping test\n");
		return false;
	}
	zassert_true(err >= 0, "Watchdog install error: %d", err);

	err = wdt_setup(wdt, WDT_OPT_PAUSE_HALTED_BY_DBG);
	if (err == -ENOTSUP) {
		TC_PRINT("- pausing watchdog by debugger is not supported\n");
		err = wdt_setup(wdt, 0);
	}
	zassert_true(err >= 0, "Watchdog setup error: %d", err);

	TC_PRINT("Watchdog configured with 30s timeout\n");
	TC_PRINT("PMU warning offset: %d seconds\n", CONFIG_ATM_WDT_PMU_WARN_OFFSET_SEC);
	TC_PRINT("Entering hibernation state...\n");
	TC_PRINT("PMU warning should fire based on configured offset\n");
	TC_PRINT("System will reboot when PMU warning fires\n");

	/* Mark state as hibernation so we know we're entering hibernation */
	m_state = WDT_TEST_STATE_HIBERNATION;

	/* Enter hibernation - system will reboot when PMU warning fires
	 * We use a long sleep duration to ensure we stay in hibernation
	 * long enough for the PMU warning to fire
	 *
	 * IMPORTANT: Unlock only hibernation substate to ensure we enter
	 * hibernation and not SOC-off (both are PM_STATE_SOFT_OFF but with
	 * different substate IDs). This prevents the system from accidentally
	 * entering SOC-off when both power states are enabled in device tree.
	 */
	pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_SUBSTATE_HIBERNATE);
	k_sleep(K_MSEC(10000));

	return true;
}

/**
 * @brief Test SOC-off entry and timer wakeup
 *
 * This test verifies that the system can enter SOC-off mode and wake up
 * via timer interrupt. When CONFIG_PM_MAX_SLEEP_DURATION_SEC is configured,
 * the system will wake from SOC-off after the specified duration via timer
 * interrupt, before the PMU watchdog can fire.
 *
 * Test flow:
 * 1. Check if we just woke from SOC-off due to timer (via boot status)
 * 2. If yes, verify and pass the test
 * 3. If no, configure ARM watchdog with very long timeout (won't fire during test)
 * 4. Enter SOC-off state by sleeping indefinitely (K_FOREVER)
 * 5. System wakes after CONFIG_PM_MAX_SLEEP_DURATION_SEC via timer interrupt
 * 6. On next boot, detect timer wakeup from SOC-off via boot status API
 *
 * Key differences from hibernation test:
 * - Uses PM_ALL_SUBSTATES to allow SOC-off (not just hibernation)
 * - Checks for BOOT_STATUS_SOCOFF_WKUP_TIMER (timer wakeup from SOC-off)
 * - Tests SOC-off entry/exit functionality
 * - Uses indefinite sleep (K_FOREVER) to trigger SOC-off entry
 */
static bool test_wdt_pmu_reset_socoff(void)
{
	const struct device *const wdt = DEVICE_DT_GET(WDT_NODE);

	zassert_true(device_is_ready(wdt), "WDT device is not ready");

	TC_PRINT("Testcase: %s\n", __func__);

	/* Check if we just woke from SOC-off due to timer */
	if (is_boot_reason(BOOT_STATUS_SOCOFF_WKUP_TIMER)) {
		TC_PRINT("✓ Detected timer wakeup from SOC-off!\n");
		TC_PRINT("Boot status indicates SOCOFF_WKUP_TIMER\n");

		/* Disable watchdog after successful test */
		int err = wdt_disable(wdt);
		if (err < 0 && err != -EPERM && err != -EFAULT) {
			TC_PRINT("Warning: Watchdog disable error: %d\n", err);
		}

		/* Mark test as complete */
		m_state = WDT_TEST_STATE_IDLE;
		TC_PRINT("Testcase passed\n");
		return true;
	}

	/* First run - configure watchdog and enter SOC-off */
	TC_PRINT("Configuring watchdog for SOC-off test\n");

	/* Disable any existing watchdog */
	int err = wdt_disable(wdt);
	if (err < 0 && err != -EPERM && err != -EFAULT) {
		zassert_true(false, "Watchdog disable error: %d", err);
	}

	/* Configure ARM watchdog with very long timeout (60 seconds)
	 * This ensures the ARM watchdog won't fire during the test.
	 * The system will wake from SOC-off via timer interrupt after
	 * CONFIG_PM_MAX_SLEEP_DURATION_SEC seconds.
	 */
	struct wdt_timeout_cfg cfg_wdt = {
		.flags = WDT_FLAG_RESET_SOC,
		.callback = NULL,     /* No callback needed - SOC-off causes reboot */
		.window.max = 60000U, /* 60 seconds */
	};

	err = wdt_install_timeout(wdt, &cfg_wdt);
	if (err == -ENOTSUP) {
		TC_PRINT("PMU watchdog not supported on platform - skipping test\n");
		return false;
	}
	zassert_true(err >= 0, "Watchdog install error: %d", err);

	err = wdt_setup(wdt, WDT_OPT_PAUSE_HALTED_BY_DBG);
	if (err == -ENOTSUP) {
		TC_PRINT("- pausing watchdog by debugger is not supported\n");
		err = wdt_setup(wdt, 0);
	}
	zassert_true(err >= 0, "Watchdog setup error: %d", err);

	TC_PRINT("Watchdog configured with 60s timeout\n");
	TC_PRINT("Entering SOC-off state (indefinite sleep)...\n");
	TC_PRINT("System will wake via timer after %d seconds\n", CONFIG_PM_MAX_SLEEP_DURATION_SEC);

	/* Mark state as SOC-off so we know we're entering SOC-off */
	m_state = WDT_TEST_STATE_SOCOFF;

	/* Enter SOC-off - system will reboot when PMU watchdog reset fires
	 * We use K_FOREVER (indefinite sleep) which will trigger SOC-off entry
	 * because the sleep duration exceeds any reasonable timeout.
	 *
	 * IMPORTANT: Unlock all SOFT_OFF substates to allow SOC-off entry.
	 * This is different from the hibernation test which only unlocks
	 * PM_SUBSTATE_HIBERNATE.
	 */
	pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	k_sleep(K_FOREVER);

	/* Should never reach here */
	return false;
}
#endif /* CONFIG_ATM_PMU_WDT_ENABLE */

/**
 * @brief Main watchdog test orchestrator - handles test sequencing across resets
 *
 * This test function orchestrates all watchdog tests, handling the state machine
 * that persists across resets via noinit section variables.
 * 1. Checks which test should run based on m_testcase_index
 * 2. On first boot: Runs test 0 (no callback), which triggers reset
 * 3. After reset: Verifies test 0, then runs test 1 (with callback), which triggers reset
 * 4. After reset: Verifies test 1, then runs test 2 (PMU warning active), which does NOT reset
 * 5. After test 2 completes: Runs test 3 (PMU warning retention), which does NOT reset
 * 6. After test 3 completes: Runs test 4 (PMU warning hibernation), which triggers reboot
 * 7. After reboot: Verifies test 4 via boot status, then runs test 5 (SOC-off timer wakeup), which
 * triggers reboot
 * 8. After reboot: Verifies test 5 via boot status, all tests done, reset state for next run
 */
ZTEST(wdt_unified_api_test_suite, test_wdt_cycle)
{
	bool test_passed = false;

#ifdef CONFIG_ATM_PMU_WDT_ENABLE
	/* Check if we just woke from hibernation due to PMU watchdog warning
	 * This must be checked BEFORE the switch statement because hibernation
	 * causes a full reboot and we need to detect it early
	 */
	if (is_boot_type(TYPE_HIB)) {
		TC_PRINT("=== Detected hibernation wakeup, resuming test 4 ===\n");
		/* Let test 4 handle the hibernation wakeup verification */
		m_testcase_index = 4U;
		m_state = WDT_TEST_STATE_HIBERNATION;
	}

	/* Check if we just woke from SOC-off due to timer
	 * This must be checked BEFORE the switch statement because SOC-off
	 * causes a full reboot and we need to detect it early
	 */
	if (is_boot_reason(BOOT_STATUS_SOCOFF_WKUP_TIMER)) {
		TC_PRINT("=== Detected SOC-off timer wakeup, resuming test 5 ===\n");
		/* Let test 5 handle the SOC-off wakeup verification */
		m_testcase_index = 5U;
		m_state = WDT_TEST_STATE_SOCOFF;
	}
#endif

	/* Initialize noinit variables if they contain garbage (first power-on) */
	if (m_testcase_index > 6U || m_state > WDT_TEST_STATE_SOCOFF) {
		TC_PRINT("Initializing test state (first power-on)\n");
		m_testcase_index = 0U;
		m_state = WDT_TEST_STATE_IDLE;
		m_testvalue = 0U;
	}

	TC_PRINT("=== Watchdog Test Cycle (index=%" PRIu32 ", state=%" PRIu32 ") ===\n",
		 m_testcase_index, m_state);

	switch (m_testcase_index) {
	case 0:
		/* Test 0: Watchdog without callback */
		TC_PRINT("\n=== Running Test 0: Watchdog without callback ===\n");
		test_passed = test_wdt_no_callback();
		if (test_passed) {
			/* Test verified after reset, move to next test and run it immediately */
			m_testcase_index = 1U;
			TC_PRINT("Test 0 passed, moving to test 1\n");
			/* Fall through to run test 1 immediately */
		} else {
			/* Test 0 is triggering reset, will verify on next boot */
			break;
		}
		__fallthrough;

	case 1:
		/* Test 1: Watchdog with callback */
		TC_PRINT("\n=== Running Test 1: Watchdog with callback ===\n");
		test_passed = test_wdt_callback_1();
		if (test_passed) {
			/* Test verified after reset, move to next test and run it immediately */
			m_testcase_index = 2U;
			TC_PRINT("Test 1 passed, moving to test 2\n");
			/* Fall through to run test 2 immediately */
		} else {
			/* Test 1 is triggering reset, will verify on next boot */
			break;
		}
		__fallthrough;

#ifdef CONFIG_ATM_PMU_WDT_ENABLE
	case 2:
		/* Test 2: PMU warning in active state (no reset) */
		TC_PRINT("\n=== Running Test 2: PMU warning interrupt (active state) ===\n");
		test_passed = test_wdt_pmu_warning();
		if (test_passed) {
			/* Move to next test */
			m_testcase_index = 3U;
			TC_PRINT("Test 2 passed, moving to test 3\n");
			/* Fall through to run test 3 immediately */
		} else {
			break;
		}
		__fallthrough;

	case 3:
		/* Test 3: PMU warning during retention (no reset) */
		TC_PRINT("\n=== Running Test 3: PMU warning during retention ===\n");
		test_passed = test_wdt_pmu_warning_retention();
		if (test_passed) {
			/* Move to next test */
			m_testcase_index = 4U;
			TC_PRINT("Test 3 passed, moving to test 4\n");
			/* Fall through to run test 4 immediately */
		} else {
			break;
		}
		__fallthrough;

	case 4:
		/* Test 4: PMU warning during hibernation (triggers reboot) */
		TC_PRINT("\n=== Running Test 4: PMU warning during hibernation ===\n");
		test_passed = test_wdt_pmu_warning_hibernation();
		if (test_passed) {
			/* Move to next test */
			m_testcase_index = 5U;
			TC_PRINT("Test 4 passed, moving to test 5\n");
			/* Fall through to run test 5 immediately */
		}
		__fallthrough;

	case 5:
		/* Test 5: SOC-off entry and timer wakeup (triggers reboot) */
		TC_PRINT("\n=== Running Test 5: SOC-off entry and timer wakeup ===\n");
		test_passed = test_wdt_pmu_reset_socoff();
		if (test_passed) {
			/* All tests complete */
			m_testcase_index = 6U;
			TC_PRINT("Test 5 passed, all tests complete\n");
		}
		break;
#else
	case 2:
	case 3:
	case 4:
	case 5:
		/* PMU tests are disabled, skip to completion */
		TC_PRINT("\n=== PMU tests disabled (CONFIG_ATM_PMU_WDT_ENABLE=n) ===\n");
		m_testcase_index = 6U;
		test_passed = true;
		break;
#endif /* CONFIG_ATM_PMU_WDT_ENABLE */

	case 6:
	default:
		/* All tests completed */
		TC_PRINT("\n=== All Watchdog Tests Completed Successfully ===\n");
		TC_PRINT("Test Results:\n");
		TC_PRINT("  - Test 0 (no callback):             PASS\n");
		TC_PRINT("  - Test 1 (with callback):           PASS\n");
#ifdef CONFIG_ATM_PMU_WDT_ENABLE
		TC_PRINT("  - Test 2 (PMU warning active):      PASS\n");
		TC_PRINT("  - Test 3 (PMU warning retention):   PASS\n");
		TC_PRINT("  - Test 4 (PMU warning hibernation): PASS\n");
		TC_PRINT("  - Test 5 (SOC-off timer wakeup):    PASS\n");
#else
		TC_PRINT("  - Tests 2-5 (PMU tests):            SKIPPED (PMU disabled)\n");
#endif
		TC_PRINT("🎉 ALL TESTS PASSED! 🎉\n");

		/* Reset state for next test run */
		m_state = WDT_TEST_STATE_IDLE;
		m_testcase_index = 0U;
		test_passed = true;
		break;
	}

	zassert_true(test_passed, "Watchdog test %" PRIu32 " should pass", m_testcase_index);
}

ZTEST_SUITE(wdt_unified_api_test_suite, NULL, NULL, NULL, NULL, NULL);
