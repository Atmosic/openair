/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/drivers/pwm_atm_fifo.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(pwm_fifo_sample, LOG_LEVEL_INF);

/* PWM device and channel configuration */
#define PWM_NODE    DT_ALIAS(pwm_0)
#define PWM_CHANNEL DT_PROP(PWM_NODE, channel)

/* Carrier frequencies for ringtone generation */
#define CARRIER1_FREQ_HZ   1000 /* 1 kHz tone */
#define CARRIER2_FREQ_HZ   2000 /* 2 kHz tone */
#define CARRIER_DUTY_CYCLE 50   /* 50% duty cycle */

/* FIFO configuration */
#define FIFO_ALERT_THRESHOLD 8

static const struct device *pwm_dev;
static bool fifo_done = false;
static struct k_sem fifo_sem;

/* Ringtone pattern: alternating tones with pauses */
static const struct pwm_atm_fifo_cmd ringtone_pattern[] = {
	/* Start with 1kHz tone for 100 cycles */
	{.carrier = 0, .carrier_on = true, .carrier_count = 100},
	/* Pause (carrier off) for 50 cycles */
	{.carrier = 0, .carrier_on = false, .carrier_count = 50},
	/* 2kHz tone for 100 cycles */
	{.carrier = 1, .carrier_on = true, .carrier_count = 100},
	/* Pause for 50 cycles */
	{.carrier = 1, .carrier_on = false, .carrier_count = 50},
	/* Repeat pattern with different durations */
	{.carrier = 0, .carrier_on = true, .carrier_count = 150},
	{.carrier = 0, .carrier_on = false, .carrier_count = 75},
	{.carrier = 1, .carrier_on = true, .carrier_count = 150},
	{.carrier = 1, .carrier_on = false, .carrier_count = 75},
	/* Final long tone */
	{.carrier = 0, .carrier_on = true, .carrier_count = 200},
};

/* FIFO alert callback - called when FIFO needs more commands */
static void fifo_alert_callback(const struct device *dev, uint32_t channel, int error)
{
	if (error < 0) {
		LOG_ERR("FIFO alert error on channel %u: %d", channel, error);
		if (error == -EOVERFLOW) {
			LOG_ERR("FIFO overflow detected - commands lost!");
		}
	} else {
		LOG_INF("FIFO alert: channel %u needs more commands", channel);
		/* In a real application, you could add more commands here */
	}
}

/* FIFO completion callback - called when all commands are executed */
static void fifo_done_callback(const struct device *dev, uint32_t channel, int error)
{
	if (error < 0) {
		LOG_ERR("FIFO completion error on channel %u: %d", channel, error);
	} else {
		LOG_INF("FIFO completed: channel %u finished all commands", channel);
	}
	fifo_done = true;
	k_sem_give(&fifo_sem);
}

static int setup_pwm_fifo(void)
{
	int ret;

	/* Get PWM device */
	pwm_dev = DEVICE_DT_GET(PWM_NODE);
	if (!device_is_ready(pwm_dev)) {
		LOG_ERR("PWM device not ready");
		return -ENODEV;
	}

	/* Configure carrier frequencies */
	static const struct pwm_atm_carrier_config carrier1 = {
		.freq_hz = CARRIER1_FREQ_HZ,
		.duty_cycle = CARRIER_DUTY_CYCLE,
	};

	static const struct pwm_atm_carrier_config carrier2 = {
		.freq_hz = CARRIER2_FREQ_HZ,
		.duty_cycle = CARRIER_DUTY_CYCLE,
	};

	/* FIFO configuration */
	static const struct pwm_atm_fifo_config fifo_config = {
		.carrier1 = &carrier1,
		.carrier2 = &carrier2,
		.polarity = 0, /* Normal polarity */
		.fifo_alert_threshold = FIFO_ALERT_THRESHOLD,
		.fifo_alert_callback = fifo_alert_callback,
		.fifo_done_callback = fifo_done_callback,
	};

	/* Initialize FIFO mode */
	ret = pwm_atm_fifo_init(pwm_dev, PWM_CHANNEL, &fifo_config);
	if (ret < 0) {
		LOG_ERR("Failed to initialize PWM FIFO mode: %d", ret);
		return ret;
	}

	LOG_INF("PWM FIFO mode initialized successfully");
	return 0;
}

static int play_ringtone(void)
{
	int ret;

	LOG_INF("Starting ringtone playback...");

	/* Write ringtone pattern to FIFO */
	ret = pwm_atm_fifo_write_cmds(pwm_dev, PWM_CHANNEL, ringtone_pattern,
				      ARRAY_SIZE(ringtone_pattern));
	if (ret < 0) {
		LOG_ERR("Failed to write FIFO commands: %d", ret);
		return ret;
	}

	LOG_INF("Written %zu commands to FIFO", ARRAY_SIZE(ringtone_pattern));

	/* Start FIFO execution */
	ret = pwm_atm_fifo_start(pwm_dev, PWM_CHANNEL);
	if (ret < 0) {
		LOG_ERR("Failed to start FIFO execution: %d", ret);
		return ret;
	}

	LOG_INF("FIFO execution started");
	return 0;
}

static void demonstrate_fifo_status(void)
{
	int free_slots;
	bool is_empty, is_full;

	/* Check FIFO status */
	free_slots = pwm_atm_fifo_get_free_slots(pwm_dev, PWM_CHANNEL);
	is_empty = pwm_atm_fifo_is_empty(pwm_dev, PWM_CHANNEL);
	is_full = pwm_atm_fifo_is_full(pwm_dev, PWM_CHANNEL);

	LOG_INF("FIFO Status: free_slots=%d, empty=%s, full=%s", free_slots,
		is_empty ? "yes" : "no", is_full ? "yes" : "no");
}

int main(void)
{
	int ret;

	LOG_INF("Atmosic PWM FIFO Mode Sample");
	LOG_INF("=============================");

	/* Initialize semaphore for completion notification */
	k_sem_init(&fifo_sem, 0, 1);

	/* Setup PWM FIFO mode */
	ret = setup_pwm_fifo();
	if (ret < 0) {
		LOG_ERR("Failed to setup PWM FIFO: %d", ret);
		return ret;
	}

	/* Demonstrate FIFO status functions */
	demonstrate_fifo_status();

	/* Play ringtone */
	ret = play_ringtone();
	if (ret < 0) {
		LOG_ERR("Failed to play ringtone: %d", ret);
		return ret;
	}

	/* Wait for completion */
	LOG_INF("Waiting for ringtone to complete...");
	ret = k_sem_take(&fifo_sem, K_SECONDS(10));
	if (ret < 0) {
		LOG_ERR("Timeout waiting for FIFO completion");
		pwm_atm_fifo_stop(pwm_dev, PWM_CHANNEL);
		return ret;
	}

	LOG_INF("Ringtone playback completed successfully!");

	/* Demonstrate FIFO status after completion */
	demonstrate_fifo_status();

	/* Example of using DMA mode with pre-formatted commands */
	LOG_INF("Demonstrating DMA mode...");

	static const uint16_t dma_commands[] = {
		/* Format: bit[15]=carrier, bit[14]=on/off, bit[13:0]=count-1 */
		(0 << 15) | (1 << 14) | 99, /* Carrier1 ON for 100 cycles */
		(0 << 15) | (0 << 14) | 49, /* Carrier1 OFF for 50 cycles */
		(1 << 15) | (1 << 14) | 99, /* Carrier2 ON for 100 cycles */
		(1 << 15) | (0 << 14) | 49, /* Carrier2 OFF for 50 cycles */
	};

	fifo_done = false;
	ret = pwm_atm_fifo_run_dma(pwm_dev, PWM_CHANNEL, dma_commands, ARRAY_SIZE(dma_commands));
	if (ret < 0) {
		LOG_ERR("Failed to run DMA commands: %d", ret);
		return ret;
	}

	/* Wait for DMA completion */
	ret = k_sem_take(&fifo_sem, K_SECONDS(5));
	if (ret < 0) {
		LOG_ERR("Timeout waiting for DMA completion");
		pwm_atm_fifo_stop(pwm_dev, PWM_CHANNEL);
		return ret;
	}

	LOG_INF("DMA mode demonstration completed!");

	/* Clean up PWM FIFO */
	ret = pwm_atm_fifo_deinit(pwm_dev, PWM_CHANNEL);
	if (ret < 0) {
		LOG_ERR("Failed to deinitialize PWM FIFO: %d", ret);
	} else {
		LOG_INF("PWM FIFO deinitialized successfully");
	}

	LOG_INF("PWM FIFO sample finished successfully");

	return 0;
}
