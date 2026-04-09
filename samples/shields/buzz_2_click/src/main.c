/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/logging/log.h>
#include "atm_buzzer.h"

LOG_MODULE_REGISTER(buzz_2_click, LOG_LEVEL_INF);

#define BUZZER_NODE DT_NODELABEL(buzzer)

BUILD_ASSERT(DT_NODE_EXISTS(BUZZER_NODE), "BUZZER_NODE does not exist in the Device Tree!");

#ifdef CONFIG_ATM_BUZZER_TIMEOUT
/* Simple callback function for when buzzer stops */
static void buzzer_stop_callback(const struct device *dev)
{
	LOG_DBG("Buzzer stopped automatically");
}
#endif

/* Frequencies for the continuous beep loop */
static const uint32_t frequencies[] = {
	500,   /* 500 Hz*/
	4000,  /* 4000 Hz*/
	5000,  /* 5000 Hz*/
	10000, /* 10000 Hz*/
};

/* Duration for each frequency in milliseconds */
static const uint32_t durations[] = {
	500, /* duration - 300ms */
	300, /* duration - 200ms */
	200, /* duration - 100ms */
	100, /* duration - 100ms */
};

#define FREQ_COUNT        ARRAY_SIZE(frequencies)
#define PAUSE_DURATION_MS 20
#define DUTY_CYCLE        50 /* 50% duty cycle */

int main(void)
{
	int ret;
	const struct device *buzzer = DEVICE_DT_GET(BUZZER_NODE);

	LOG_INF("Buzz 2 Click Sample - PWM Buzzer Demo");

	/* Check if buzzer device is ready */
	if (!device_is_ready(buzzer)) {
		LOG_ERR("Buzzer device not ready");
		return -ENODEV;
	}

	LOG_INF("Buzzer device ready: %s", buzzer->name);

#ifdef CONFIG_ATM_BUZZER_TIMEOUT
	/* Set stop callback */
	atm_buzzer_set_stop_callback(buzzer, buzzer_stop_callback);
#endif

	LOG_INF("Starting continuous frequency loop...\n");

	while (1) {
		/* Cycle through C3, C4, E5 frequencies continuously */
		for (int i = 0; i < FREQ_COUNT; i++) {
			const char *freq_name;
			switch (i) {
			case 0:
				freq_name = "C3";
				break;
			case 1:
				freq_name = "C4";
				break;
			case 2:
				freq_name = "E5";
				break;
			default:
				freq_name = "unknown";
				break;
			}

			LOG_INF("Playing %s frequency: %u Hz for %u ms", freq_name, frequencies[i],
				durations[i]);

#ifdef CONFIG_ATM_BUZZER_TIMEOUT
			/* Use atm_buzzer_beep_time() for automatic timing */
			ret = atm_buzzer_beep_time(buzzer, frequencies[i], DUTY_CYCLE,
						   durations[i]);
			if (ret != BUZ_NO_ERROR) {
				LOG_ERR("Failed to start beep: %d", ret);
				continue;
			}
			/* Wait for beep to finish plus pause time */
			k_msleep(durations[i] + PAUSE_DURATION_MS);
#else
			/* Use atm_buzzer_beep() and manual timing */
			ret = atm_buzzer_beep(buzzer, frequencies[i], DUTY_CYCLE);
			if (ret != BUZ_NO_ERROR) {
				LOG_ERR("Failed to start beep: %d", ret);
				continue;
			}
			k_msleep(durations[i]);
			atm_buzzer_onoff(buzzer, false);
			k_msleep(PAUSE_DURATION_MS);
#endif
		}

		/* Log message to match sample.yaml regex pattern */
		LOG_INF("Melody complete. Pausing before repeat...");
		k_msleep(2000); /* 2 second pause before repeating */
	}

	return 0;
}
