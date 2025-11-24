/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(pir_click, LOG_LEVEL_INF);

#define PIR_SAMPLE_INTERVAL_MS 500
#define MCP_NODE               DT_NODELABEL(mcp3221)
#define ADC_NODE               DT_NODELABEL(adc)
#define ADC_CHANNEL            ADC_CHANNEL_CFG_DT(DT_CHILD(ADC_NODE, channel_7))

static const struct device *const mcp_dev = DEVICE_DT_GET(MCP_NODE);
static const struct device *const adc_dev = DEVICE_DT_GET(ADC_NODE);
static const struct adc_channel_cfg adc_cfg = ADC_CHANNEL;
static struct adc_sequence adc_seq;
static int32_t adc_sample_buffer;

static int pir_click_adc_init(void)
{
	__ASSERT(adc_dev, "Cannot get ADC device");

	if (!device_is_ready(adc_dev)) {
		LOG_ERR("ADC device %s is not ready", adc_dev->name);
		return -ENODEV;
	}

	int ret = adc_channel_setup(adc_dev, &adc_cfg);
	if (ret < 0) {
		LOG_ERR("ADC channel setup failed: %d", ret);
		return ret;
	}

	adc_seq = (struct adc_sequence){
		.channels = BIT(adc_cfg.channel_id),
		.buffer = &adc_sample_buffer,
		.buffer_size = sizeof(adc_sample_buffer),
		.resolution = DT_PROP(ADC_NODE, resolution),
	};

	LOG_INF("ADC configured: channel %d", adc_cfg.channel_id);
	return 0;
}

static int pir_click_adc_read(int32_t *voltage_mv)
{
	int ret = adc_read(adc_dev, &adc_seq);
	if (ret < 0) {
		LOG_ERR("ADC read failed: %d", ret);
		return ret;
	}

	ret = adc_raw_to_millivolts(adc_ref_internal(adc_dev), adc_cfg.gain, adc_seq.resolution,
				    &adc_sample_buffer);
	if (ret < 0) {
		LOG_ERR("ADC conversion failed: %d", ret);
		return ret;
	}

	*voltage_mv = adc_sample_buffer;

	return 0;
}

static int pir_click_mcp3221_init(void)
{
	__ASSERT(mcp_dev, "Cannot get MCP3221 device");

	if (!device_is_ready(mcp_dev)) {
		LOG_ERR("MCP3221 device %s is not ready", mcp_dev->name);
		return -ENODEV;
	}

	LOG_INF("MCP3221 device ready: %s", mcp_dev->name);
	return 0;
}

static int pir_click_mcp3221_read(int32_t *voltage_mv)
{
	int ret = sensor_sample_fetch(mcp_dev);
	if (ret < 0) {
		LOG_ERR("MCP3221 sample fetch failed: %d", ret);
		return ret;
	}

	struct sensor_value voltage;
	ret = sensor_channel_get(mcp_dev, SENSOR_CHAN_VOLTAGE, &voltage);
	if (ret < 0) {
		LOG_ERR("MCP3221 channel get failed: %d", ret);
		return ret;
	}

	*voltage_mv = voltage.val1 * 1000 + voltage.val2 / 1000;
	return 0;
}

int main(void)
{
	LOG_INF("Sample interval: %d ms", PIR_SAMPLE_INTERVAL_MS);

	int ret = pir_click_adc_init();
	if (ret < 0) {
		LOG_ERR("Failed to initialize ADC: %d", ret);
		return ret;
	}

	ret = pir_click_mcp3221_init();
	if (ret < 0) {
		LOG_ERR("Failed to initialize MCP3221: %d", ret);
		return ret;
	}

	LOG_INF("Starting PIR sensor voltage monitoring...");

	int32_t adc_vol_mv = 0;
	int32_t mcp_vol_mv = 0;

	while (1) {
		ret = pir_click_adc_read(&adc_vol_mv);
		if (ret != 0) {
			LOG_ERR("ADC read failed: %d", ret);
			adc_vol_mv = -1;
		}

		ret = pir_click_mcp3221_read(&mcp_vol_mv);
		if (ret != 0) {
			LOG_ERR("MCP3221 read failed: %d", ret);
			mcp_vol_mv = -1;
		}

		LOG_INF("ADC: %d mV, MCP3221: %d mV", adc_vol_mv, mcp_vol_mv);
		k_msleep(PIR_SAMPLE_INTERVAL_MS);
	}

	return 0;
}
