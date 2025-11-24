/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025 Atmosic
 */

#include <zephyr/drivers/adc.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/__assert.h>
#include <inttypes.h>

#include "battery_monitor.h"
#include "atm_adc.h"

LOG_MODULE_REGISTER(battery_monitor, CONFIG_SENSOR_BEACON_LOG_LEVEL);

#define ADC_BUFFER_SIZE 2
#define ADC_RESOLUTION  DT_PROP(DT_NODELABEL(adc), resolution)

#define ADC_CHANNEL_VBATT                                                                          \
	ADC_CHANNEL_DT_NODE(DT_NODELABEL(adc), DT_PROP(DT_NODELABEL(adc), ch_cell))
#define ADC_CHANNEL_VBATT_ID DT_REG_ADDR(ADC_CHANNEL_VBATT)
#define ADC_CHANNEL_VSTORE                                                                         \
	ADC_CHANNEL_DT_NODE(DT_NODELABEL(adc), DT_PROP(DT_NODELABEL(adc), ch_store))
#define ADC_CHANNEL_VSTORE_ID DT_REG_ADDR(ADC_CHANNEL_VSTORE)

static const struct device *const adc_dev = DEVICE_DT_GET(DT_NODELABEL(adc));

enum {
	ADC_CHANNEL_VBATT_INDEX,
	ADC_CHANNEL_VSTORE_INDEX,
};

static const struct adc_channel_cfg channel_cfg[] = {
	ADC_CHANNEL_CFG_DT(ADC_CHANNEL_VBATT),
	ADC_CHANNEL_CFG_DT(ADC_CHANNEL_VSTORE),
};

int battery_monitor_init(void)
{
	__ASSERT(adc_dev, "Cannot get ADC device");

	if (!device_is_ready(adc_dev)) {
		LOG_ERR("ADC device is not ready");
		return -ENODEV;
	}

	int ret = adc_channel_setup(adc_dev, &channel_cfg[ADC_CHANNEL_VBATT_INDEX]);
	if (ret) {
		LOG_ERR("Setting up VBatt ADC channel failed: %" PRId32, ret);
		return ret;
	}

	ret = adc_channel_setup(adc_dev, &channel_cfg[ADC_CHANNEL_VSTORE_INDEX]);
	if (ret) {
		LOG_ERR("Setting up VStore ADC channel failed: %" PRId32, ret);
		return ret;
	}

	LOG_INF("Battery monitor initialized");
	return 0;
}

int battery_monitor_get_voltages(float *vstore, float *vbatt)
{
	int32_t sample_buffer[ADC_BUFFER_SIZE];

	const struct adc_sequence sequence = {
		.channels = BIT(ADC_CHANNEL_VBATT_ID) | BIT(ADC_CHANNEL_VSTORE_ID),
		.buffer = sample_buffer,
		.buffer_size = sizeof(sample_buffer),
		.resolution = ADC_RESOLUTION,
	};

	/* Setup async read */
	struct k_poll_signal async_sig = K_POLL_SIGNAL_INITIALIZER(async_sig);
	struct k_poll_event async_evt =
		K_POLL_EVENT_INITIALIZER(K_POLL_TYPE_SIGNAL, K_POLL_MODE_NOTIFY_ONLY, &async_sig);

	int ret = adc_read_async(adc_dev, &sequence, &async_sig);
	if (ret) {
		LOG_ERR("ADC read async failed: %" PRId32, ret);
		return ret;
	}

	/* Wait for completion */
	ret = k_poll(&async_evt, 1, K_FOREVER);
	if (ret) {
		LOG_ERR("ADC poll failed: %" PRId32, ret);
		return ret;
	}

	/* Convert VBatt */
	uint16_t ref = adc_ref_internal(adc_dev);
	int32_t mv = sample_buffer[ADC_CHANNEL_VBATT_INDEX];
	atm_adc_raw_to_millivolts(ref, channel_cfg[ADC_CHANNEL_VBATT_INDEX].gain, ADC_RESOLUTION,
		&mv);
	*vbatt = mv / 1000.0f;

	/* Convert VStore */
	mv = sample_buffer[ADC_CHANNEL_VSTORE_INDEX];
	atm_adc_raw_to_millivolts(ref, channel_cfg[ADC_CHANNEL_VSTORE_INDEX].gain, ADC_RESOLUTION,
		&mv);
	*vstore = mv / 1000.0f;

	LOG_DBG("VStore: %.4f V, VBatt: %.4f V", (double)*vstore, (double)*vbatt);

	return 0;
}
