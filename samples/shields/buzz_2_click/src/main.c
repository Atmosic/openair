/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/logging/log.h>
#include "atm_buzzer.h"

LOG_MODULE_REGISTER(buzz_2_click, LOG_LEVEL_INF);

#define BUZZER_NODE     DT_NODELABEL(buzzer)
#define BUZZER_PWM_NODE DT_PHANDLE(BUZZER_NODE, pwms)

BUILD_ASSERT(DT_NODE_EXISTS(BUZZER_NODE), "BUZZER_NODE does not exist in the Device Tree!");

#ifdef CONFIG_ATM_BUZZER_TIMEOUT
/* Simple callback function for when buzzer stops */
static void buzzer_stop_callback(atm_buzzer_t *buzzer)
{
	LOG_DBG("Buzzer stopped automatically");
}
#endif

/* Buzzer configuration structure */
static atm_buzzer_t buzzer_cfg = {
	.pwm_dt = PWM_DT_SPEC_GET(BUZZER_NODE),
	.pulse = DT_PROP(BUZZER_NODE, pulse),
	.min_frequency = DT_PROP(BUZZER_PWM_NODE, min_frequency),
	.max_frequency = DT_PROP(BUZZER_PWM_NODE, max_frequency),
#ifdef CONFIG_ATM_BUZZER_TIMEOUT
	.stop_cb = buzzer_stop_callback,
	.context = NULL,
#endif
};

/* Frequencies for the continuous beep loop */
static const uint32_t frequencies[] = {
	NOTE_C3, /* C3 - 131 Hz */
	NOTE_C4, /* C4 - 262 Hz */
	NOTE_E5, /* E5 - 659 Hz */
};

/* Duration for each frequency in milliseconds */
static const uint32_t durations[] = {
	300, /* C3 duration - 300ms */
	200, /* C4 duration - 200ms */
	100, /* E5 duration - 100ms */
};

#define FREQ_COUNT        ARRAY_SIZE(frequencies)
#define PAUSE_DURATION_MS 20
#define DUTY_CYCLE        50 /* 50% duty cycle */

int main(void)
{
	int ret;

	LOG_INF("Buzz 2 Click Sample - PWM Buzzer Demo");
	LOG_INF("Buzzer PWM period: %u ns, pulse: %u ns", buzzer_cfg.pwm_dt.period,
		buzzer_cfg.pulse);
	LOG_INF("Frequency range: %u Hz - %u Hz", buzzer_cfg.min_frequency,
		buzzer_cfg.max_frequency);

	/* Check if PWM device is ready */
	if (!device_is_ready(buzzer_cfg.pwm_dt.dev)) {
		LOG_ERR("PWM device %s is not ready", buzzer_cfg.pwm_dt.dev->name);
		return -ENODEV;
	}

	LOG_INF("PWM device ready: %s", buzzer_cfg.pwm_dt.dev->name);

#ifdef CONFIG_ATM_BUZZER_TIMEOUT
	/* Initialize the buzzer timeout functionality */
	ret = atm_buzzer_cb_reg(&buzzer_cfg);
	if (ret != BUZ_NO_ERROR) {
		LOG_ERR("Failed to register buzzer callback: %d", ret);
		return ret;
	}
	LOG_INF("Buzzer timeout functionality initialized");
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

			/* Use atm_buzzer_beep_time() for automatic timing */
			ret = atm_buzzer_beep_time(&buzzer_cfg, frequencies[i], DUTY_CYCLE,
						   durations[i]);
			if (ret != BUZ_NO_ERROR) {
				LOG_ERR("Failed to start timed beep: %d", ret);
				continue;
			}

			/* Wait for beep to finish plus pause time */
			k_msleep(durations[i] + PAUSE_DURATION_MS);
		}

		/* Log message to match sample.yaml regex pattern */
		LOG_INF("Melody complete. Pausing before repeat...");
		k_msleep(2000); /* 2 second pause before repeating */
	}

	return 0;
}
