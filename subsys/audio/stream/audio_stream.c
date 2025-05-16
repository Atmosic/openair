/*
 * Copyright (C) Atmosic 2025
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/drivers/i2s.h>
#include <zephyr/audio/codec.h>
#include <zephyr/audio/audio_stream.h>
#ifdef CONFIG_ATM_FIFO_TX_ISR
#include "i2s_atm.h"
#endif

/* Internal static variables to store device handles */
static const struct device *i2s_dev_handle;
static const struct device *codec_dev_handle;

/* Maybe save config if needed */
static struct i2s_config i2s_config_handle;

/* Playing status */
static enum {
	PLAYBACK_IDLE, /* codec is off */
	PLAYBACK_READY, /* codec is on*/
	PLAYBACK_BUSY, /* playing */
} pb_sts;

#ifdef CONFIG_ATM_FIFO_TX_ISR
/* buffer Block size */
static int BLOCK_SIZE;
#else
#define MAX_TX_BLOCK 20
#define BLOCK_SIZE   128
static __noinit char __aligned(WB_UP(32)) _k_mem_slab_buf_tx_0_mem[(MAX_TX_BLOCK)*WB_UP(BLOCK_SIZE)];
static STRUCT_SECTION_ITERABLE(k_mem_slab, tx_0_mem_slab) = Z_MEM_SLAB_INITIALIZER(
	tx_0_mem_slab, _k_mem_slab_buf_tx_0_mem, WB_UP(BLOCK_SIZE), MAX_TX_BLOCK);
#endif

int audio_stream_init(const struct audio_stream_config *cfg)
{
	if (!cfg || !cfg->i2s_dev || !cfg->i2s_cfg) {
		return -EINVAL;
	}

	if (cfg->direction == AUDIO_STREAM_INPUT) {
		return -ENOTSUP;
	}

	if (!device_is_ready(cfg->i2s_dev)) {
		return -ENODEV;
	}

	i2s_dev_handle = cfg->i2s_dev;
	codec_dev_handle = cfg->codec_dev;
	i2s_config_handle = *cfg->i2s_cfg;
#ifndef CONFIG_ATM_FIFO_TX_ISR
	i2s_config_handle.mem_slab = &tx_0_mem_slab;
	i2s_config_handle.block_size = BLOCK_SIZE;
#endif

	/* friendly for non-codec environment */
	if (codec_dev_handle && device_is_ready(codec_dev_handle)) {
		struct audio_codec_cfg audio_cfg;
		audio_cfg.dai_route = AUDIO_ROUTE_PLAYBACK;
		audio_cfg.dai_type = AUDIO_DAI_TYPE_I2S;
		audio_cfg.dai_cfg.i2s = *cfg->i2s_cfg;

		int ret = audio_codec_configure(codec_dev_handle, &audio_cfg);
		if (ret < 0) {
			return ret;
		}

		audio_property_value_t prop = {.vol = CONFIG_AUDIO_DEFAULT_VOLUME};
		audio_codec_set_property(codec_dev_handle, AUDIO_PROPERTY_OUTPUT_VOLUME, AUDIO_CHANNEL_ALL, prop);
	}

    return 0;
}

static inline int write_samples(const struct device *dev_i2s, uint8_t **buf, int *residue)
{
	void *mem_block;
	int size;

#ifdef CONFIG_ATM_FIFO_TX_ISR
	size = MIN(*residue, BLOCK_SIZE >> 1);
#else
	const struct i2s_config *tx_cfg = i2s_config_get((const struct device *)dev_i2s, I2S_DIR_TX);
	if (!tx_cfg) {
		return -EIO;
	}
	size = MIN(*residue, tx_cfg->block_size >> 1);
#endif

	if (!size) {
		return -EINVAL;
	}

	int ret;

#ifdef CONFIG_ATM_FIFO_TX_ISR
	mem_block = i2s_atm_get_tx_buffer(dev_i2s);
	if (!mem_block) {
		return -ENOMEM;
	}
#else
	ret = k_mem_slab_alloc(tx_cfg->mem_slab, &mem_block, K_NO_WAIT);
	if (ret < 0) {
		return -ENOMEM;
	}
#endif

	uint16_t *mem_dst = (uint16_t *)mem_block;
	uint16_t *mem_src = (uint16_t *)*buf;

	for (int i = 0; i < size / 2; i++) {
		mem_dst[2 * i] = sys_cpu_to_le16(mem_src[i]);
		mem_dst[2 * i + 1] = sys_cpu_to_le16(mem_src[i]);
	}

	ret = i2s_write(dev_i2s, mem_block, size << 1);

	if (ret) {
#ifndef CONFIG_ATM_FIFO_TX_ISR
		k_mem_slab_free(tx_cfg->mem_slab, mem_block);
#endif
		return ret;
	}


	*buf += size;
	*residue -= size;
	return 0;
}

static int codec_onoff(const struct device *dev_i2s, struct i2s_config const *i2s_cfg, bool on)
{
	static uint8_t dummy[128] = {0};
	if (!device_is_ready(i2s_dev_handle)) {
		return -ENODEV;
	}
	i2s_configure(dev_i2s, I2S_DIR_TX, i2s_cfg);
	i2s_write(dev_i2s, (void *)dummy, sizeof(dummy));
	i2s_trigger(dev_i2s, I2S_DIR_TX, I2S_TRIGGER_START);

	/* friendly for non-codec environment */
	if (codec_dev_handle && device_is_ready(codec_dev_handle)) {
		on ? audio_codec_start_output(codec_dev_handle) : audio_codec_stop_output(codec_dev_handle);
	}

	i2s_trigger(dev_i2s, I2S_DIR_TX, I2S_TRIGGER_PREPARE);
	return 0;
}

#ifdef CONFIG_ATM_FIFO_TX_ISR
static struct write_context {
	uint8_t *buf;
	size_t size;
} write_cb_ctx;
static void i2s_write_cb(const struct device *dev, void *ctx)
{
	struct write_context *w_ctx = ctx;
	write_samples(dev, &w_ctx->buf, &w_ctx->size);
}
#endif

int audio_stream_start(void)
{
	if (pb_sts != PLAYBACK_IDLE) {
		return -EINVAL;
	}

	// Turn on codec
	int ret = codec_onoff(i2s_dev_handle, &i2s_config_handle, true);
	if (!ret) {
		pb_sts = PLAYBACK_READY;
	}

	return ret;
}

int audio_stream_write(const void *pcm_data, size_t size_bytes,
	enum audio_playback_mode mode)
{
	if (!i2s_dev_handle || !pcm_data || size_bytes == 0) {
		return -EINVAL;
	}

#ifdef CONFIG_ATM_FIFO_TX_ISR
	BLOCK_SIZE = i2s_atm_get_tx_buffer_size(i2s_dev_handle);
#endif

	// configure I2S
	int ret = i2s_configure(i2s_dev_handle, I2S_DIR_TX, &i2s_config_handle);
	if (ret < 0) {
		return ret;
	}

	switch (mode) {
	case AUDIO_PLAYBACK_MODE_NORMAL: {
		// I2s_write directly from audio data.
		if ((ret = i2s_write(i2s_dev_handle, (void *)pcm_data, size_bytes))) {
			return ret;
		}

		// Start I2S
		if ((ret = i2s_trigger(i2s_dev_handle, I2S_DIR_TX, I2S_TRIGGER_START))) {
			return ret;
		}
	} break;
	case AUDIO_PLAYBACK_MODE_PADDED_SAMPLE: {
#ifdef CONFIG_ATM_FIFO_TX_ISR
		// register high prio write cb
		write_cb_ctx.buf = (uint8_t *)pcm_data;
		write_cb_ctx.size = size_bytes;
		i2s_atm_reg_tx_write_cb(i2s_dev_handle, i2s_write_cb, &write_cb_ctx);
#else
		uint8_t *buf = (uint8_t *)pcm_data;
		// pre-write NUM_BLOCKS blocks to queue
		while (!write_samples(i2s_dev_handle, &buf, &size_bytes));
#endif

		// Start I2S
		int ret = i2s_trigger(i2s_dev_handle, I2S_DIR_TX, I2S_TRIGGER_START);
		if (ret < 0) {
			return ret;
		}

#ifdef CONFIG_ATM_FIFO_TX_ISR
		while (write_cb_ctx.size) {
			k_yield();
		}
#else
		// write until data is consumped
		while (size_bytes) {
			if (write_samples(i2s_dev_handle, &buf, &size_bytes) == -ENOMEM) {
				k_yield();
			}
		}
#endif
	} break;

	default:
		return -EINVAL;
	}

	// Drain all data from queue, then stop.
	ret = i2s_trigger(i2s_dev_handle, I2S_DIR_TX, I2S_TRIGGER_DRAIN);
	if (ret) {
		return ret;
	}

	// wait for last I2S to be ready
	while (i2s_config_get(i2s_dev_handle, I2S_DIR_TX)) {
		k_yield();
	};

	return 0;
}

int audio_stream_stop(void)
{
	if (pb_sts != PLAYBACK_READY) {
		return -EINVAL;
	}
	int ret = codec_onoff(i2s_dev_handle, &i2s_config_handle, false);
	pb_sts = PLAYBACK_IDLE;
	return ret;
}

/**
 * @brief Deinitialize playback system
 */
int audio_stream_deinit(void)
{
	if (!i2s_dev_handle) {
		return -EINVAL;
	}

	/* TODO: Deinitialize I2S and optionally codec */

	i2s_dev_handle = NULL;
	codec_dev_handle = NULL;

	return 0;
}
