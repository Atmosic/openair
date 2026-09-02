/*
 * Copyright (c) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <stdint.h>
#include <string.h>

#include <zephyr/kernel.h>
#include <zephyr/sys/util.h>
#include <zephyr/audio/dmic.h>

#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(dmic_sample);

#define MAX_SAMPLE_RATE  CONFIG_SAMPLE_RATE_HZ
#define SAMPLE_BIT_WIDTH 16
#define PDM_CTL_IDX      CONFIG_HW_CHANNEL_INDEX
#define BYTES_PER_SAMPLE (SAMPLE_BIT_WIDTH / 8)
#define READ_TIMEOUT     1000

#define PDM_HW_CHUNK_WORDS   16
#define PDM_HW_CHUNK_SAMPLES (PDM_HW_CHUNK_WORDS * 2)
#define PDM_BLOCK_SIZE       (PDM_HW_CHUNK_SAMPLES * BYTES_PER_SAMPLE)

#define MAX_BLOCK_SIZE PDM_BLOCK_SIZE
#define BLOCK_COUNT    4
K_MEM_SLAB_DEFINE_STATIC(mem_slab, MAX_BLOCK_SIZE, BLOCK_COUNT, 4);

#define DMIC_BENCH_WARMUP_MS 1000
#define MAX_READ_FAILURES    50

#define CAP_SAMPLES (MAX_SAMPLE_RATE * CONFIG_DMIC_BENCH_DURATION_S)
static int16_t capture_buf[CAP_SAMPLES];

int main(void)
{
	const struct device *dmic_dev = DEVICE_DT_GET(DT_NODELABEL(dmic_dev));

	if (!device_is_ready(dmic_dev)) {
		LOG_ERR("DMIC not ready");
		return 0;
	}

	struct pcm_stream_cfg stream = {
		.pcm_width = SAMPLE_BIT_WIDTH,
		.mem_slab = &mem_slab,
	};
	struct dmic_cfg cfg = {
		.io =
			{
				.min_pdm_clk_freq = 1000000,
				.max_pdm_clk_freq = 4000000,
				.min_pdm_clk_dc = 40,
				.max_pdm_clk_dc = 60,
			},
		.streams = &stream,
		.channel =
			{
				.req_num_streams = 1,
				.req_num_chan = 1,
				.req_chan_map_lo =
					dmic_build_channel_map(0, PDM_CTL_IDX, PDM_CHAN_LEFT),
			},
	};
	cfg.streams[0].pcm_rate = MAX_SAMPLE_RATE;
	cfg.streams[0].block_size = PDM_BLOCK_SIZE;

	int ret = dmic_configure(dmic_dev, &cfg);
	if (ret < 0) {
		LOG_ERR("Configure failed: %d", ret);
		return 0;
	}

	ret = dmic_trigger(dmic_dev, DMIC_TRIGGER_START);
	if (ret < 0) {
		LOG_ERR("START failed: %d", ret);
		return 0;
	}

	uint32_t pcm_rate = cfg.streams[0].pcm_rate;
	uint32_t warmup_samples = (DMIC_BENCH_WARMUP_MS * pcm_rate) / 1000U;
	uint32_t failures = 0;

	for (uint32_t warmed = 0; warmed < warmup_samples;) {
		void *buf;
		uint32_t size;
		ret = dmic_read(dmic_dev, 0, &buf, &size, READ_TIMEOUT);
		if (ret < 0) {
			if (++failures >= MAX_READ_FAILURES) {
				LOG_ERR("Warm-up abort: %u failures", failures);
				break;
			}
			continue;
		}
		failures = 0;
		k_mem_slab_free(&mem_slab, buf);
		warmed += PDM_HW_CHUNK_SAMPLES;
	}

	LOG_INF("Bench streaming started");

	uint32_t cap =
		MIN(CONFIG_DMIC_BENCH_DURATION_S * pcm_rate, (uint32_t)ARRAY_SIZE(capture_buf));
	uint32_t captured = 0, dropped = 0;
	failures = 0;

	while (captured < cap) {
		void *buf;
		uint32_t size;
		ret = dmic_read(dmic_dev, 0, &buf, &size, READ_TIMEOUT);
		if (ret < 0) {
			dropped++;
			if (++failures >= MAX_READ_FAILURES) {
				break;
			}
			continue;
		}
		failures = 0;
		memcpy(&capture_buf[captured], buf, PDM_HW_CHUNK_SAMPLES * sizeof(capture_buf[0]));
		k_mem_slab_free(&mem_slab, buf);
		captured += PDM_HW_CHUNK_SAMPLES;
	}

	dmic_trigger(dmic_dev, DMIC_TRIGGER_STOP);

	printk("PDM_CAPTURE_BEGIN rate=%u bits=%u samples=%u\n", pcm_rate, SAMPLE_BIT_WIDTH,
	       captured);
	for (uint32_t i = 0; i < captured; i++) {
		printk("%04x%c", (uint16_t)capture_buf[i],
		       (i % PDM_HW_CHUNK_SAMPLES == PDM_HW_CHUNK_SAMPLES - 1) ? '\n' : ' ');
	}
	if (captured % PDM_HW_CHUNK_SAMPLES != 0) {
		printk("\n");
	}
	printk("PDM_CAPTURE_END captured=%u dropped=%u\n", captured, dropped);

	return 0;
}
