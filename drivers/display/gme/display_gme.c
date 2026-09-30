/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/*
 * GME12864 family monochrome OLED on I2C.
 */

#define DT_DRV_COMPAT atmosic_gme_oled

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/display.h>
#include <zephyr/sys/util.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(gme_oled, CONFIG_GME_OLED_LOG_LEVEL);

/*
 * Control bytes: bit 6 selects data over command, and Co stays 0 so the rest of the
 * transfer is a stream of that kind.
 */
#define GME_CTRL_CMD  0x00
#define GME_CTRL_DATA 0x40

#define GME_SET_CONTRAST         0x81
#define GME_SET_ENTIRE_DISP_OFF  0xa4
#define GME_SET_NORMAL_DISPLAY   0xa6
#define GME_SET_REVERSE_DISPLAY  0xa7
#define GME_SET_DISPLAY_OFF      0xae
#define GME_SET_DISPLAY_ON       0xaf
#define GME_SET_MEM_ADDR_MODE    0x20
#define GME_SET_COLUMN_ADDRESS   0x21
#define GME_SET_PAGE_ADDRESS     0x22
#define GME_SET_START_LINE       0x40
#define GME_SET_SEGMENT_NORMAL   0xa0
#define GME_SET_SEGMENT_REMAPED  0xa1
#define GME_SET_MULTIPLEX_RATIO  0xa8
#define GME_SET_IREF_MODE        0xad
#define GME_SET_COM_SCAN_NORMAL  0xc0
#define GME_SET_COM_SCAN_FLIPPED 0xc8
#define GME_SET_DISPLAY_OFFSET   0xd3
#define GME_SET_CLOCK_DIV_RATIO  0xd5
#define GME_SET_CHARGE_PERIOD    0xd9
#define GME_SET_PADS_HW_CONFIG   0xda
#define GME_SET_VCOM_DESEL_LEVEL 0xdb
#define GME_SET_CHARGE_PUMP      0x8d

#define GME_ADDR_MODE_HORIZONTAL 0x00
#define GME_CHARGE_PUMP_ENABLED  0x14
#define GME_CLOCK_DIV_DEFAULT    0x80
#define GME_PADS_HW_SEQUENTIAL   0x02
#define GME_PADS_HW_ALTERNATIVE  0x12
#define GME_IREF_INTERNAL        0x30
#define GME_IREF_EXTERNAL        0x00

/* Rows are packed eight to a byte, so a y coordinate maps to a page by >> 3. */
#define GME_PPB_SHIFT 3
#define GME_PPB       (1U << GME_PPB_SHIFT)

struct gme_config {
	struct i2c_dt_spec bus;
	uint16_t width;
	uint16_t height;
	uint8_t multiplex_ratio;
	uint8_t display_offset;
	uint8_t prechargep;
	uint8_t vcom_desel_level;
	uint8_t contrast;
	bool segment_remap;
	bool com_invdir;
	bool com_sequential;
	bool inversion_on;
	bool use_internal_iref;
	uint16_t max_write_len;
	uint16_t write_gap_us;
	uint16_t ready_time_ms;
};

struct gme_data {
	enum display_pixel_format pf;
};

static int gme_write_bus(const struct device *dev, const uint8_t *buf, size_t len, bool command)
{
	const struct gme_config *config = dev->config;
	const uint8_t ctrl = command ? GME_CTRL_CMD : GME_CTRL_DATA;
	const size_t max = config->max_write_len ? config->max_write_len : len;

	for (size_t off = 0; off < len; off += max) {
		int ret = i2c_burst_write_dt(&config->bus, ctrl, &buf[off], MIN(max, len - off));

		if (ret < 0) {
			return ret;
		}
		if (config->write_gap_us) {
			k_sleep(K_USEC(config->write_gap_us));
		}
	}

	return 0;
}

static inline int gme_cmd(const struct device *dev, const uint8_t *buf, size_t len)
{
	return gme_write_bus(dev, buf, len, true);
}

static int gme_blanking_on(const struct device *dev)
{
	uint8_t cmd = GME_SET_DISPLAY_OFF;

	return gme_cmd(dev, &cmd, sizeof(cmd));
}

static int gme_blanking_off(const struct device *dev)
{
	uint8_t cmd = GME_SET_DISPLAY_ON;

	return gme_cmd(dev, &cmd, sizeof(cmd));
}

static int gme_set_contrast(const struct device *dev, const uint8_t contrast)
{
	uint8_t cmd[] = {GME_SET_CONTRAST, contrast};

	return gme_cmd(dev, cmd, sizeof(cmd));
}

static int gme_write(const struct device *dev, const uint16_t x, const uint16_t y,
		     const struct display_buffer_descriptor *desc, const void *buf)
{
	const struct gme_config *config = dev->config;
	uint8_t cmd[] = {
		GME_SET_MEM_ADDR_MODE,  GME_ADDR_MODE_HORIZONTAL,
		GME_SET_COLUMN_ADDRESS, x,
		x + desc->width - 1,    GME_SET_PAGE_ADDRESS,
		y >> GME_PPB_SHIFT,     (((y + desc->height) >> GME_PPB_SHIFT) - 1),
	};
	int ret;

	if (desc->pitch != desc->width) {
		LOG_ERR("Unsupported pitch %u for width %u", desc->pitch, desc->width);
		return -ENOTSUP;
	}
	if ((y & (GME_PPB - 1)) || (desc->height & (GME_PPB - 1))) {
		LOG_ERR("y %u and height %u must both be a multiple of %u", y, desc->height,
			GME_PPB);
		return -EINVAL;
	}
	if ((x + desc->width) > config->width || (y + desc->height) > config->height) {
		LOG_ERR("Write of %ux%u at (%u,%u) leaves the %ux%u panel", desc->width,
			desc->height, x, y, config->width, config->height);
		return -EINVAL;
	}

	ret = gme_cmd(dev, cmd, sizeof(cmd));
	if (ret < 0) {
		LOG_ERR("Failed to set the write window: %d", ret);
		return ret;
	}

	return gme_write_bus(dev, buf, desc->buf_size, false);
}

static void gme_get_capabilities(const struct device *dev, struct display_capabilities *caps)
{
	const struct gme_config *config = dev->config;
	struct gme_data *data = dev->data;

	caps->x_resolution = config->width;
	caps->y_resolution = config->height;
	caps->supported_pixel_formats = PIXEL_FORMAT_MONO10 | PIXEL_FORMAT_MONO01;
	caps->current_pixel_format = data->pf;
	caps->screen_info = SCREEN_INFO_MONO_VTILED;
	caps->current_orientation = DISPLAY_ORIENTATION_NORMAL;
}

static int gme_set_pixel_format(const struct device *dev, const enum display_pixel_format pf)
{
	struct gme_data *data = dev->data;
	uint8_t cmd;
	int ret;

	if (pf == data->pf) {
		return 0;
	}

	if (pf == PIXEL_FORMAT_MONO10) {
		cmd = GME_SET_REVERSE_DISPLAY;
	} else if (pf == PIXEL_FORMAT_MONO01) {
		cmd = GME_SET_NORMAL_DISPLAY;
	} else {
		LOG_WRN("Unsupported pixel format");
		return -ENOTSUP;
	}

	ret = gme_cmd(dev, &cmd, sizeof(cmd));
	if (ret < 0) {
		return ret;
	}
	data->pf = pf;

	return 0;
}

static int gme_init(const struct device *dev)
{
	const struct gme_config *config = dev->config;
	struct gme_data *data = dev->data;
	const uint8_t init_seq[] = {
		GME_SET_DISPLAY_OFF,
		GME_SET_CLOCK_DIV_RATIO,
		GME_CLOCK_DIV_DEFAULT,
		GME_SET_CHARGE_PERIOD,
		config->prechargep,
		GME_SET_VCOM_DESEL_LEVEL,
		config->vcom_desel_level,
		GME_SET_START_LINE,
		GME_SET_DISPLAY_OFFSET,
		config->display_offset,
		GME_SET_PADS_HW_CONFIG,
		config->com_sequential ? GME_PADS_HW_SEQUENTIAL : GME_PADS_HW_ALTERNATIVE,
		GME_SET_MULTIPLEX_RATIO,
		config->multiplex_ratio,
		config->segment_remap ? GME_SET_SEGMENT_REMAPED : GME_SET_SEGMENT_NORMAL,
		config->com_invdir ? GME_SET_COM_SCAN_FLIPPED : GME_SET_COM_SCAN_NORMAL,
		GME_SET_CHARGE_PUMP,
		GME_CHARGE_PUMP_ENABLED,
		GME_SET_IREF_MODE,
		config->use_internal_iref ? GME_IREF_INTERNAL : GME_IREF_EXTERNAL,
		/* Show RAM rather than every pixel; a panel left in 0xA5 looks like noise. */
		GME_SET_ENTIRE_DISP_OFF,
		config->inversion_on ? GME_SET_REVERSE_DISPLAY : GME_SET_NORMAL_DISPLAY,
		GME_SET_CONTRAST,
		config->contrast,
		GME_SET_MEM_ADDR_MODE,
		GME_ADDR_MODE_HORIZONTAL,
		GME_SET_DISPLAY_ON,
	};

	k_sleep(K_TIMEOUT_ABS_MS(config->ready_time_ms));

	if (!i2c_is_ready_dt(&config->bus)) {
		LOG_ERR("Bus device %s not ready", config->bus.bus->name);
		return -ENODEV;
	}

	data->pf = config->inversion_on ? PIXEL_FORMAT_MONO10 : PIXEL_FORMAT_MONO01;

	int ret = gme_cmd(dev, init_seq, sizeof(init_seq));

	if (ret < 0) {
		LOG_ERR("Failed to initialize panel: %d", ret);
		return ret;
	}

	return 0;
}

static DEVICE_API(display, gme_driver_api) = {
	.blanking_on = gme_blanking_on,
	.blanking_off = gme_blanking_off,
	.write = gme_write,
	.set_contrast = gme_set_contrast,
	.get_capabilities = gme_get_capabilities,
	.set_pixel_format = gme_set_pixel_format,
};

#define GME_DEFINE(n)                                                                              \
	static struct gme_data gme_data_##n;                                                       \
	static const struct gme_config gme_config_##n = {                                          \
		.bus = I2C_DT_SPEC_INST_GET(n),                                                    \
		.width = DT_INST_PROP(n, width),                                                   \
		.height = DT_INST_PROP(n, height),                                                 \
		.multiplex_ratio = DT_INST_PROP(n, multiplex_ratio),                               \
		.display_offset = DT_INST_PROP(n, display_offset),                                 \
		.prechargep = DT_INST_PROP(n, prechargep),                                         \
		.vcom_desel_level = DT_INST_PROP(n, vcom_desel_level),                             \
		.contrast = DT_INST_PROP(n, contrast),                                             \
		.segment_remap = DT_INST_PROP(n, segment_remap),                                   \
		.com_invdir = DT_INST_PROP(n, com_invdir),                                         \
		.com_sequential = DT_INST_PROP(n, com_sequential),                                 \
		.inversion_on = DT_INST_PROP(n, inversion_on),                                     \
		.use_internal_iref = DT_INST_PROP(n, use_internal_iref),                           \
		.max_write_len = DT_INST_PROP(n, max_write_len),                                   \
		.write_gap_us = DT_INST_PROP(n, write_gap_us),                                     \
		.ready_time_ms = DT_INST_PROP(n, ready_time_ms),                                   \
	};                                                                                         \
	DEVICE_DT_INST_DEFINE(n, gme_init, NULL, &gme_data_##n, &gme_config_##n, POST_KERNEL,      \
			      CONFIG_DISPLAY_INIT_PRIORITY, &gme_driver_api);

DT_INST_FOREACH_STATUS_OKAY(GME_DEFINE)
