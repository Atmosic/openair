/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/ztest.h>
#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/drivers/pwm_atm_fifo.h>
#include <zephyr/kernel.h>

#define PWM0_NODE    DT_ALIAS(pwm_0)
#define PWM0_CHANNEL DT_PROP(PWM0_NODE, channel)

static const struct device *pwm0_dev;
static bool callback_called;
static struct k_sem test_sem;
static volatile bool alert_waiting;

/* Write vs Deinit race test variables */
static struct k_thread write_thread_data;
static struct k_thread deinit_thread_data;
static K_THREAD_STACK_DEFINE(write_thread_stack, 1024);
static K_THREAD_STACK_DEFINE(deinit_thread_stack, 1024);
static struct k_sem write_deinit_sync_sem;
static struct k_sem write_deinit_start_sem;
static int write_thread_result;
static int deinit_thread_result;
static volatile bool keep_writing;

static void test_alert_callback(const struct device *dev, uint32_t channel, int error)
{
	callback_called = true;
	if (error < 0) {
		printk("Alert callback called with error: %d\n", error);
	}
	if (alert_waiting) {
		k_sem_give(&test_sem);
	}
}

static void test_done_callback(const struct device *dev, uint32_t channel, int error)
{
	callback_called = true;
	if (error < 0) {
		printk("Done callback called with error: %d\n", error);
	}
	k_sem_give(&test_sem);
}

/* Write vs Deinit race test functions */
static void write_cmd_thread(void *arg1, void *arg2, void *arg3)
{
	ARG_UNUSED(arg1);
	ARG_UNUSED(arg2);
	ARG_UNUSED(arg3);

	/* Wait for both threads to be ready */
	k_sem_take(&write_deinit_start_sem, K_FOREVER);

	/* Continuously write commands until told to stop */
	struct pwm_atm_fifo_cmd cmd = {
		.carrier = 0,
		.carrier_on = true,
		.carrier_count = 100,
	};

	int write_count = 0;
	write_thread_result = 0;

	printk("Write thread: Starting continuous write operations\n");

	while (keep_writing) {
		int ret = pwm_atm_fifo_write_cmd(pwm0_dev, PWM0_CHANNEL, &cmd);
		if (ret < 0) {
			if (ret == -ENODEV) {
				/* Expected when deinit happens */
				printk("Write thread: Got -ENODEV (expected after deinit)\n");
				write_thread_result = ret;
				break;
			} else if (ret == -ENOSPC) {
				/* FIFO full, brief delay and retry */
				k_usleep(10);
				continue;
			} else {
				printk("Write thread: Unexpected error %d\n", ret);
				write_thread_result = ret;
				break;
			}
		}
		write_count++;

		/* Aggressive writing to increase race probability */
		if (write_count % 50 == 0) {
			printk("Write thread: %d commands written\n", write_count);
			/* Very brief yield to allow deinit thread to run */
			k_yield();
		}
	}

	printk("Write thread: Completed %d writes, result = %d\n", write_count,
	       write_thread_result);

	/* Signal completion */
	k_sem_give(&write_deinit_sync_sem);
}

static void deinit_thread(void *arg1, void *arg2, void *arg3)
{
	ARG_UNUSED(arg1);
	ARG_UNUSED(arg2);
	ARG_UNUSED(arg3);

	/* Wait for both threads to be ready */
	k_sem_take(&write_deinit_start_sem, K_FOREVER);

	/* Let write thread run for a bit */
	k_msleep(5);

	printk("Deinit thread: Starting deinit operation while writes continue\n");

	/* Perform deinit WHILE write thread is still running - this creates the race! */
	deinit_thread_result = pwm_atm_fifo_deinit(pwm0_dev, PWM0_CHANNEL);

	printk("Deinit thread: Deinit result = %d\n", deinit_thread_result);

	/* Now stop the write thread after deinit is complete */
	k_msleep(10);
	keep_writing = false;

	/* Signal completion */
	k_sem_give(&write_deinit_sync_sem);
}

ZTEST_SUITE(pwm_atm_fifo, NULL, NULL, NULL, NULL, NULL);

ZTEST(pwm_atm_fifo, test01_device_ready)
{
	pwm0_dev = DEVICE_DT_GET(PWM0_NODE);
	zassert_true(device_is_ready(pwm0_dev), "PWM device 0 should be ready");
}

ZTEST(pwm_atm_fifo, test02_fifo_init)
{
	int ret;

	static const struct pwm_atm_carrier_config carrier1 = {
		.freq_hz = 1000,
		.duty_cycle = 50,
	};

	static const struct pwm_atm_carrier_config carrier2 = {
		.freq_hz = 2000,
		.duty_cycle = 25,
	};

	static const struct pwm_atm_fifo_config fifo_config = {
		.carrier1 = &carrier1,
		.carrier2 = &carrier2,
		.polarity = 0,
		.fifo_alert_threshold = 8,
		.fifo_alert_callback = test_alert_callback,
		.fifo_done_callback = test_done_callback,
	};

	ret = pwm_atm_fifo_init(pwm0_dev, PWM0_CHANNEL, &fifo_config);
	zassert_ok(ret, "FIFO init should succeed");
}

ZTEST(pwm_atm_fifo, test03_fifo_write_cmd)
{
	int ret;
	struct pwm_atm_fifo_cmd cmd = {
		.carrier = 0,
		.carrier_on = true,
		.carrier_count = 100,
	};

	ret = pwm_atm_fifo_write_cmd(pwm0_dev, PWM0_CHANNEL, &cmd);
	zassert_ok(ret, "FIFO write command should succeed");
}

ZTEST(pwm_atm_fifo, test04_fifo_write_multiple_cmds)
{
	int ret;
	struct pwm_atm_fifo_cmd cmds[] = {
		{.carrier = 0, .carrier_on = true, .carrier_count = 50},
		{.carrier = 0, .carrier_on = false, .carrier_count = 25},
		{.carrier = 1, .carrier_on = true, .carrier_count = 75},
		{.carrier = 0, .carrier_on = true, .carrier_count = 60},
		{.carrier = 0, .carrier_on = false, .carrier_count = 30},
		{.carrier = 1, .carrier_on = true, .carrier_count = 40},
		{.carrier = 1, .carrier_on = false, .carrier_count = 20},
		{.carrier = 0, .carrier_on = true, .carrier_count = 55},
		{.carrier = 0, .carrier_on = false, .carrier_count = 15},
		{.carrier = 1, .carrier_on = true, .carrier_count = 35},
		{.carrier = 0, .carrier_on = true, .carrier_count = 45},
		{.carrier = 1, .carrier_on = false, .carrier_count = 10},
	};

	ret = pwm_atm_fifo_write_cmds(pwm0_dev, PWM0_CHANNEL, cmds, ARRAY_SIZE(cmds));
	zassert_ok(ret, "FIFO write multiple commands should succeed");
}

ZTEST(pwm_atm_fifo, test05_fifo_status)
{
	int free_slots;
	bool is_empty, is_full;

	free_slots = pwm_atm_fifo_get_free_slots(pwm0_dev, PWM0_CHANNEL);
	zassert_true(free_slots >= 0, "Free slots should be non-negative");
	zassert_true(free_slots <= 16, "Free slots should not exceed FIFO size");

	is_empty = pwm_atm_fifo_is_empty(pwm0_dev, PWM0_CHANNEL);
	is_full = pwm_atm_fifo_is_full(pwm0_dev, PWM0_CHANNEL);

	/* FIFO should not be both empty and full */
	zassert_false(is_empty && is_full, "FIFO cannot be both empty and full");
}

ZTEST(pwm_atm_fifo, test06_fifo_start_stop)
{
	k_sem_init(&test_sem, 0, 2);
	alert_waiting = true;
	callback_called = false;

	int ret = pwm_atm_fifo_start(pwm0_dev, PWM0_CHANNEL);
	zassert_ok(ret, "FIFO start should succeed");

	/* Wait for alert callback when threshold is crossed */
	ret = k_sem_take(&test_sem, K_MSEC(300));
	zassert_ok(ret, "Should receive alert callback for fifo_alert_threshold within timeout");
	alert_waiting = false; /* subsequent semaphore give should only come from DONE */

	/* Wait for completion (done) callback when all commands drain */
	ret = k_sem_take(&test_sem, K_SECONDS(1));
	zassert_ok(ret, "Should receive completion (done) callback within timeout");

	ret = pwm_atm_fifo_stop(pwm0_dev, PWM0_CHANNEL);
	zassert_ok(ret, "FIFO stop should succeed");

	zassert_true(pwm_atm_fifo_is_empty(pwm0_dev, PWM0_CHANNEL),
		     "FIFO should be empty after completion");
}

ZTEST(pwm_atm_fifo, test07_fifo_dma_mode)
{
	int ret;
	static const uint16_t dma_cmds[] = {
		(0 << 15) | (1 << 14) | 9, /* Carrier1 ON for 10 cycles */
		(0 << 15) | (0 << 14) | 4, /* Carrier1 OFF for 5 cycles */
	};

	k_sem_init(&test_sem, 0, 1);
	callback_called = false;

	ret = pwm_atm_fifo_run_dma(pwm0_dev, PWM0_CHANNEL, dma_cmds, ARRAY_SIZE(dma_cmds));
	zassert_ok(ret, "FIFO DMA run should succeed");

	/* Wait for completion */
	ret = k_sem_take(&test_sem, K_SECONDS(2));
	zassert_ok(ret, "Should receive DMA completion callback within timeout");
}

ZTEST(pwm_atm_fifo, test08_invalid_parameters)
{
	int ret;
	struct pwm_atm_fifo_cmd cmd = {
		.carrier = 0, .carrier_on = true, .carrier_count = 0, /* Invalid count */
	};

	/* Test invalid channel */
	ret = pwm_atm_fifo_write_cmd(pwm0_dev, 99, &cmd);
	zassert_not_ok(ret, "Invalid channel should fail");

	/* Test invalid command count */
	cmd.carrier_count = 0;
	ret = pwm_atm_fifo_write_cmd(pwm0_dev, PWM0_CHANNEL, &cmd);
	zassert_not_ok(ret, "Invalid carrier count should fail");

	/* Test NULL command */
	ret = pwm_atm_fifo_write_cmd(pwm0_dev, PWM0_CHANNEL, NULL);
	zassert_not_ok(ret, "NULL command should fail");
}

ZTEST(pwm_atm_fifo, test09_write_cmd_vs_deinit_race)
{
	int ret;

	/* Initialize semaphores for thread synchronization */
	k_sem_init(&write_deinit_sync_sem, 0, 2);
	k_sem_init(&write_deinit_start_sem, 0, 2);

	/* Reset results and control variables */
	write_thread_result = -999;
	deinit_thread_result = -999;
	keep_writing = true;

	printk("=== Write vs Deinit Race Test ===\n");
	printk("Testing race condition: write_cmd accessing fifo_config while deinit nullifies "
	       "it\n");

	/* First initialize PWM FIFO for the test */
	static const struct pwm_atm_carrier_config carrier1_race = {
		.freq_hz = 1000,
		.duty_cycle = 50,
	};

	static const struct pwm_atm_carrier_config carrier2_race = {
		.freq_hz = 2000,
		.duty_cycle = 50,
	};

	static const struct pwm_atm_fifo_config fifo_config_race = {
		.carrier1 = &carrier1_race,
		.carrier2 = &carrier2_race,
		.polarity = 0,
		.fifo_alert_threshold = 8,
		.fifo_alert_callback = test_alert_callback,
		.fifo_done_callback = test_done_callback,
	};

	ret = pwm_atm_fifo_init(pwm0_dev, PWM0_CHANNEL, &fifo_config_race);
	zassert_ok(ret, "FIFO init should succeed for race test");

	/* Create two threads: one writing commands, one doing deinit */
	k_tid_t write_tid = k_thread_create(
		&write_thread_data, write_thread_stack, K_THREAD_STACK_SIZEOF(write_thread_stack),
		write_cmd_thread, NULL, NULL, NULL, K_PRIO_PREEMPT(6), 0, K_NO_WAIT);

	k_tid_t deinit_tid =
		k_thread_create(&deinit_thread_data, deinit_thread_stack,
				K_THREAD_STACK_SIZEOF(deinit_thread_stack), deinit_thread, NULL,
				NULL, NULL, K_PRIO_PREEMPT(7), 0, K_NO_WAIT);

	/* Give threads a moment to start and reach the semaphore */
	k_msleep(10);

	printk("Starting concurrent write and deinit operations...\n");

	/* Release both threads simultaneously to create race condition */
	k_sem_give(&write_deinit_start_sem);
	k_sem_give(&write_deinit_start_sem);

	/* Wait for both threads to complete */
	ret = k_sem_take(&write_deinit_sync_sem, K_SECONDS(10));
	zassert_ok(ret, "Write thread should complete within timeout");

	ret = k_sem_take(&write_deinit_sync_sem, K_SECONDS(10));
	zassert_ok(ret, "Deinit thread should complete within timeout");

	/* Clean up threads */
	k_thread_join(write_tid, K_SECONDS(1));
	k_thread_join(deinit_tid, K_SECONDS(1));

	printk("Write thread result: %d\n", write_thread_result);
	printk("Deinit thread result: %d\n", deinit_thread_result);

	/* Analyze results */
	if (write_thread_result == 0 && deinit_thread_result == 0) {
		printk("INCORRECT: Both operations completed successfully\n");
		printk("This means write continued after deinit - race protection failed!\n");
		printk("Expected: write should get -ENODEV after deinit\n");
		zassert_true(false, "Race protection failed - write should fail after deinit");
	} else if (write_thread_result == -ENODEV && deinit_thread_result == 0) {
		printk("SUCCESS: Write got -ENODEV after deinit (correct behavior)\n");
		printk("This indicates proper thread safety protection\n");
	} else if (write_thread_result == 0 && deinit_thread_result != 0) {
		printk("Write succeeded but deinit failed: %d\n", deinit_thread_result);
		zassert_ok(deinit_thread_result, "Deinit should succeed");
	} else {
		printk("Unexpected results: Write=%d, Deinit=%d\n", write_thread_result,
		       deinit_thread_result);
		zassert_true(false, "Unexpected thread results");
	}

	/* Ensure cleanup is complete - if deinit failed, try again */
	if (deinit_thread_result != 0) {
		ret = pwm_atm_fifo_deinit(pwm0_dev, PWM0_CHANNEL);
		printk("Cleanup deinit result: %d\n", ret);
	}

	printk("=== Write vs Deinit Race Test Complete ===\n");
}

ZTEST(pwm_atm_fifo, test10_write_cmd_ownership_validation)
{
	int ret;

	printk("=== Write Command Ownership Validation Test ===\n");
	printk("Testing that write_cmd validates device ownership\n");

	/* Initialize FIFO on device 0 */
	static const struct pwm_atm_carrier_config carrier1_own = {
		.freq_hz = 1000,
		.duty_cycle = 50,
	};

	static const struct pwm_atm_carrier_config carrier2_own = {
		.freq_hz = 2000,
		.duty_cycle = 50,
	};

	static const struct pwm_atm_fifo_config fifo_config_own = {
		.carrier1 = &carrier1_own,
		.carrier2 = &carrier2_own,
		.polarity = 0,
		.fifo_alert_threshold = 8,
		.fifo_alert_callback = test_alert_callback,
		.fifo_done_callback = test_done_callback,
	};

	ret = pwm_atm_fifo_init(pwm0_dev, PWM0_CHANNEL, &fifo_config_own);
	zassert_ok(ret, "FIFO init on device 0 should succeed");

	/* Try to write command with correct device - should succeed */
	struct pwm_atm_fifo_cmd cmd = {
		.carrier = 0,
		.carrier_on = true,
		.carrier_count = 100,
	};

	printk("Testing write_cmd with correct device (pwm0_dev)...\n");
	ret = pwm_atm_fifo_write_cmd(pwm0_dev, PWM0_CHANNEL, &cmd);
	if (ret == -ENOSPC) {
		printk("FIFO full, this is acceptable for ownership test\n");
		/* FIFO full is OK - we're testing ownership, not FIFO functionality */
	} else {
		zassert_ok(ret,
			   "Write command with correct device should succeed or return -ENOSPC");
	}

	/* Try to write command with correct device but wrong channel - should fail */
	printk("Testing write_cmd with correct device but wrong channel...\n");
	/* Use a different valid channel number (not PWM0_CHANNEL) to test ownership validation
	 * Use channel 0 if PWM0_CHANNEL != 0, otherwise use channel 1
	 * This ensures we always use a valid channel number < 8 that's not initialized
	 */
	uint32_t wrong_channel = !(PWM0_CHANNEL != 0);
	ret = pwm_atm_fifo_write_cmd(pwm0_dev, wrong_channel, &cmd);
	zassert_equal(ret, -ENODEV, "Write command with wrong channel should fail with -ENODEV");
	printk("Correctly rejected write_cmd with wrong channel with -ENODEV\n");

	/* Try to write command with invalid channel number - should fail */
	printk("Testing write_cmd with invalid channel number...\n");
	ret = pwm_atm_fifo_write_cmd(pwm0_dev, 99, &cmd);
	zassert_equal(ret, -EINVAL, "Write command with invalid channel should fail with -EINVAL");
	printk("Correctly rejected write_cmd with invalid channel with -EINVAL\n");

	/* Clean up */
	ret = pwm_atm_fifo_deinit(pwm0_dev, PWM0_CHANNEL);
	zassert_ok(ret, "FIFO deinit should succeed");

	printk("=== Ownership Validation Test Complete ===\n");
}
