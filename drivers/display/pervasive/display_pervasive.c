/**
 *******************************************************************************
 *
 * @file display_pervasive.c
 *
 * @brief This is display driver for pervasive EPD device shields
 *
 * The confidential and proprietary information contained in this file may
 * only be used by a person authorised under and to the extent permitted
 * by a subsisting licensing agreement from Atmosic.
 *
 * Copyright (C) Atmosic 2024-2025
 *
 * This entire notice must be reproduced on all copies of this file
 * and copies of this file may only be made by a person if such person is
 * permitted to do so under the terms of a subsisting license agreement
 * from Atmosic.
 *
 *******************************************************************************
 */

#define LOG_LEVEL CONFIG_DISPLAY_LOG_LEVEL
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(display_pervasive);

#include <string.h>
#include <zephyr/device.h>
#include <zephyr/drivers/display.h>
#include <zephyr/init.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/sys/byteorder.h>

#include "pervasive_regs.h"

// Propietary pixel format
#define PIXEL_FORMAT_BWRY11 BIT(6)
#define PIXEL_FORMAT_CW10   BIT(7)

#ifdef CONFIG_PERVASIVE_SW_FB

#define PERVASIVE_COMMON_DATA(n)                                                                   \
	struct pervasive_data {                                                                    \
		struct k_work_delayable work;                                                      \
		const struct device *dev;                                                          \
		bool blanking_on;

#define E2266CS0C2_DATA_CREATE(n)                                                                  \
	PERVASIVE_COMMON_DATA(n)                                                                   \
	uint8_t frame_buf[DT_PROP(n, height) * DT_PROP(n, width) / 8];                             \
	const uint8_t dummy00[DT_PROP(n, height) * DT_PROP(n, width) / 8];                         \
	}                                                                                          \
	;

#define E2266QS0F1_DATA_CREATE(n)                                                                  \
	PERVASIVE_COMMON_DATA(n)                                                                   \
	uint8_t frame_buf[DT_PROP(n, height) * DT_PROP(n, width) / 4];                             \
	}                                                                                          \
	;

#else // CONFIG_PERVASIVE_SW_FB

#define PERVASIVE_COMMON_DATA(n)                                                                   \
	struct pervasive_data {                                                                    \
		uint16_t current_y;                                                                \
		bool blanking_on;

#define E2266CS0C2_DATA_CREATE(n)                                                                  \
	PERVASIVE_COMMON_DATA(n)                                                                   \
	const uint8_t dummy00[DT_PROP(n, height) * DT_PROP(n, width) / 8];                         \
	}                                                                                          \
	;

#define E2266QS0F1_DATA_CREATE(n)                                                                  \
	PERVASIVE_COMMON_DATA(n)                                                                   \
	}                                                                                          \
	;

#endif // CONFIG_PERVASIVE_SW_FB

#define E2741JS0B2_DATA_CREATE(n)                                                                  \
	PERVASIVE_COMMON_DATA(n)                                                                   \
	enum display_pixel_format allow_format;                                                    \
	enum display_pixel_format curr_format;                                                     \
	}                                                                                          \
	;

DT_FOREACH_STATUS_OKAY(pervasive_e2266cs0c2, E2266CS0C2_DATA_CREATE);
DT_FOREACH_STATUS_OKAY(pervasive_e2266qs0f1, E2266QS0F1_DATA_CREATE);
DT_FOREACH_STATUS_OKAY(pervasive_e2741js0b2, E2741JS0B2_DATA_CREATE);

#if DT_NODE_HAS_PROP(DT_CHILD(DT_NODELABEL(e2266qs0f1), ext_io), pc_gpios)
#define PC_GPIO_EXIST
struct gpio_dt_spec pc_gpio =
	GPIO_DT_SPEC_GET(DT_CHILD(DT_NODELABEL(e2266qs0f1), ext_io), pc_gpios);
#elif DT_NODE_HAS_PROP(DT_CHILD(DT_NODELABEL(e2266js0b2), ext_io), pc_gpios)
#define PC_GPIO_EXIST
struct gpio_dt_spec pc_gpio =
	GPIO_DT_SPEC_GET(DT_CHILD(DT_NODELABEL(e2266js0b2), ext_io), pc_gpios);
#elif DT_NODE_HAS_PROP(DT_CHILD(DT_NODELABEL(e2741js0b2), ext_io), pc_gpios)
#define PC_GPIO_EXIST
struct gpio_dt_spec pc_gpio =
	GPIO_DT_SPEC_GET(DT_CHILD(DT_NODELABEL(e2741js0b2), ext_io), pc_gpios);
#endif

struct pervasive_config {
	struct spi_dt_spec bus;
	struct gpio_dt_spec dc_gpio;
	struct gpio_dt_spec busy_gpio;
	struct gpio_dt_spec reset_gpio;
	uint16_t height;
	uint16_t width;
	uint32_t supported_pixel_formats;
	uint32_t spi_read_freq;
	int (*global_update_fn)(const struct device *dev, const void *buf, uint16_t width,
				uint16_t height);
#ifdef CONFIG_PERVASIVE_SW_FB
	int (*fb_update_fn)(const struct device *dev, const uint16_t x, const uint16_t y,
			    const uint8_t *buf, const struct display_buffer_descriptor *desc);
#endif
};

#define TIMEOUT_RST_BUSY_MS 1000

static inline int pervasive_busy_wait_check_high(const struct pervasive_config *config,
						 uint32_t tout_ms)
{
	int pin = gpio_pin_get_dt(&config->busy_gpio);

	while (!pin) {
		__ASSERT(pin >= 0, "gpio failure");
		k_msleep(1);
		pin = gpio_pin_get_dt(&config->busy_gpio);
		tout_ms--;
		if (!tout_ms) {
			return -ENOTCONN;
		}
	}
	return 0;
}

static inline void pervasive_busy_wait(const struct pervasive_config *config)
{
	pervasive_busy_wait_check_high(config, 0xffffffff);
}

static inline int pervasive_busy_wait_check_low(const struct pervasive_config *config,
						uint32_t tout_ms)
{
	int pin = gpio_pin_get_dt(&config->busy_gpio);
	while (pin) {
		k_msleep(1);
		tout_ms--;
		if (!tout_ms) {
			return -ENOTCONN;
		}
	}
	pervasive_busy_wait(config);
	return 0;
}

static inline int pervasive_spi_write(const struct spi_dt_spec *spec,
				      const struct spi_buf_set *tx_bufs)
{
	int err = spi_write_dt(spec, tx_bufs);
	if (err < 0) {
		spi_release_dt(spec);
	}
	return err;
}

static inline int pervasive_spi_read(const struct spi_dt_spec *spec,
				     const struct spi_buf_set *rx_bufs)
{
	int err = spi_read_dt(spec, rx_bufs);
	if (err < 0) {
		spi_release_dt(spec);
	}
	return err;
}

static inline int pervasive_read(const struct pervasive_config *config, uint8_t *data, size_t len)
{
	struct spi_buf buf = {.len = 1};

	struct spi_buf_set buf_set = {.buffers = &buf,
				      .count = sizeof(buf) / sizeof(struct spi_buf_set)};

	int err;
	for (int i = 0; i < len; i++) {
		buf.buf = &data[i];
		struct spi_dt_spec mybus = config->bus;
		mybus.config.frequency = config->spi_read_freq;
		mybus.config.operation |= SPI_HALF_DUPLEX;
		err = pervasive_spi_read(&mybus, &buf_set);
		if (err < 0) {
			break;
		}
	}
	return err;
}

static inline int pervasive_write_data(const struct pervasive_config *config, const uint8_t *data,
				       size_t len)
{
	const struct spi_buf buf = {.buf = (void *)data, .len = len};
	struct spi_buf_set buf_set = {.buffers = &buf,
				      .count = sizeof(buf) / sizeof(struct spi_buf_set)};

	int err = 0;

	err = gpio_pin_set_dt(&config->dc_gpio, 0);
	if (data != NULL) {
		err = pervasive_spi_write(&config->bus, &buf_set);
	}
	return err;
}

static inline int pervasive_write_cmd(const struct pervasive_config *config, uint8_t index,
				      const uint8_t *data, size_t len)
{
	struct spi_buf buf = {.buf = &index, .len = sizeof(index)};
	struct spi_buf_set buf_set = {.buffers = &buf,
				      .count = sizeof(buf) / sizeof(struct spi_buf_set)};

	int err = 0;

	err = gpio_pin_set_dt(&config->dc_gpio, 1);
	if (err < 0) {
		return err;
	}

	err = pervasive_spi_write(&config->bus, &buf_set);
	if (err < 0) {
		return err;
	}

	err = gpio_pin_set_dt(&config->dc_gpio, 0);

	if (data != NULL) {
		buf.buf = (void *)data;
		buf.len = len;
		err = pervasive_spi_write(&config->bus, &buf_set);
	}
	return err;
}

static inline int pervasive_write_one_bytes(const struct pervasive_config *config, uint8_t idx,
					    uint8_t data)
{
	return pervasive_write_cmd(config, idx, &data, 1);
}

static int pervasive_not_support(const struct device *dev, ...)
{
	return -ENOSYS;
}

static int pervasive_cog_power_off(const struct pervasive_config *config)
{
	gpio_pin_set_dt(&config->reset_gpio, 1);
	gpio_pin_set_dt(&config->dc_gpio, 1);
#ifdef PC_GPIO_EXIST
	gpio_pin_set_dt(&pc_gpio, 0);
#endif
	return 0;
}

static int pervasive_bus_config(const struct pervasive_config *config)
{
	int err;

	// check ready
	if (!spi_is_ready_dt(&config->bus)) {
		return -ENODEV;
	}
	if (!gpio_is_ready_dt(&config->reset_gpio)) {
		return -ENODEV;
	}
	if (!gpio_is_ready_dt(&config->dc_gpio)) {
		return -ENODEV;
	}
	if (!gpio_is_ready_dt(&config->busy_gpio)) {
		return -ENODEV;
	}

	// config GPIOs
#ifdef PC_GPIO_EXIST
	err = gpio_pin_configure_dt(&pc_gpio, GPIO_OUTPUT_INACTIVE);
	if (err < 0) {
		return err;
	}
#endif

	err = gpio_pin_configure_dt(&config->reset_gpio, GPIO_OUTPUT_ACTIVE);
	if (err >= 0) {
		err = gpio_pin_configure_dt(&config->dc_gpio, GPIO_OUTPUT_INACTIVE);
	}
	if (err >= 0) {
		err = gpio_pin_configure_dt(&config->busy_gpio, GPIO_INPUT);
	}

	return err;
}

static int pervasive_init(const struct device *dev)
{
	const struct pervasive_config *config = dev->config;
	struct pervasive_data *data = dev->data;
	// config bus
	pervasive_bus_config(config);
	data->blanking_on = true;
	return 0;
}

static int pervasive_check_param(const uint16_t x, const uint16_t y, const uint8_t *buf,
				 const struct device *dev,
				 const struct display_buffer_descriptor *desc)
{
	const struct pervasive_config *config = dev->config;
	LOG_INF("s: %d (x, y, w, h, p): (%d, %d, %d, %d, %d)", desc->buf_size, x, y, desc->width,
		desc->height, desc->pitch);

#ifdef CONFIG_PERVASIVE_SW_FB
	if (buf == NULL || desc->buf_size == 0U || (desc->pitch != desc->width) ||
	    (desc->pitch != desc->width) || ((y + desc->height) > config->height) ||
	    ((x + desc->width) > config->width)) {
		LOG_ERR("Invalid parameter");
		return -EINVAL;
	}
#else
	struct pervasive_data *data = dev->data;
	// only support full width update since too waste memory.
	if ((buf == NULL) || (desc->buf_size == 0U) || x || (desc->width != config->width) ||
	    (data->current_y != y) || (y + desc->height > config->height)) {
		LOG_ERR("Invalid parameter");
		return -EINVAL;
	}
#endif
	return 0;
}

#if defined(CONFIG_SHIELD_PERVASIVE_EPAPER_E2266CS0C2) ||                                          \
	defined(CONFIG_SHIELD_PERVASIVE_EPAPER_E2266QS0F1)
static int e2266_updating(const struct pervasive_config *config, uint8_t *ref, uint8_t len)
{
	int err;
	// dc/dc on
	err = pervasive_write_cmd(config, PERVASIVE_SEPD_IDX_DCDC, NULL, 0);

	// refresh
	if (err >= 0) {
		err = pervasive_busy_wait_check_low(config, 10);
	}

	if (err >= 0) {
		err = pervasive_write_cmd(config, PERVASIVE_SEPD_IDX_REFSH, ref, len);
	}

	// dc/dc off
	if (err >= 0) {
		pervasive_busy_wait(config);
		err = pervasive_write_cmd(config, PERVASIVE_SEPD_IDX_DCOFF, ref, len);
	}

	if (err >= 0) {
		pervasive_busy_wait(config);
	}

	return err;
}

#ifdef CONFIG_PERVASIVE_SW_FB
static void e2266_update_work(struct pervasive_data *data, k_timeout_t t)
{
	k_work_cancel_delayable(&data->work);
	k_work_schedule(&data->work, t);
}

static void e2266_globalupdate(struct k_work *work)
{
	const struct pervasive_data *data =
		CONTAINER_OF((struct k_work_delayable *)work, struct pervasive_data, work);

	const struct pervasive_config *config = data->dev->config;
	config->global_update_fn(data->dev, data->frame_buf, config->width, config->height);
}
#endif

static int e2266_init(const struct device *dev)
{
	pervasive_init(dev);
#ifdef CONFIG_PERVASIVE_SW_FB
	struct pervasive_data *data = dev->data;
	data->dev = dev;
	k_work_init_delayable(&data->work, e2266_globalupdate);
#endif
	return 0;
}

static int e2266_blanking_on(const struct device *dev)
{
	struct pervasive_data *data = dev->data;
	if (!data->blanking_on) {
		data->blanking_on = true;
#ifdef CONFIG_PERVASIVE_SW_FB
		k_work_cancel_delayable(&data->work);
#endif
	}
	return 0;
}

static int e2266_blanking_off(const struct device *dev)
{
	struct pervasive_data *data = dev->data;
	if (data->blanking_on) {
		data->blanking_on = false;
#ifdef CONFIG_PERVASIVE_SW_FB
		e2266_update_work(data, K_NO_WAIT);
#endif
	}

	return 0;
}

static int e2266_write(const struct device *dev, const uint16_t x, const uint16_t y,
		       const struct display_buffer_descriptor *desc, const void *buf)
{
	struct pervasive_data *data = dev->data;
	const struct pervasive_config *config = dev->config;
	int err;

#ifdef CONFIG_PERVASIVE_SW_FB
	// Abort pending update
	k_work_cancel_delayable(&data->work);
#endif

	if (pervasive_check_param(x, y, buf, dev, desc) < 0) {
		return -EINVAL;
	}

#ifdef CONFIG_PERVASIVE_SW_FB
	err = config->fb_update_fn(dev, x, y, buf, desc);
	if (err < 0) {
		return err;
	}
#endif

	if (data->blanking_on) {
		return 0;
	}

#ifdef CONFIG_PERVASIVE_SW_FB
	// update
	e2266_update_work(data, err == 1 ? K_MSEC(50) : K_NO_WAIT);
#else
	err = config->global_update_fn(dev, buf, desc->width, desc->height);
	data->current_y = y + desc->height;
	if (data->current_y == config->height) {
		data->current_y = 0;
	}
#endif

	return err;
}

static void e2266_get_capabilities(const struct device *dev, struct display_capabilities *caps)
{
	const struct pervasive_config *config = dev->config;
	memset(caps, 0, sizeof(struct display_capabilities));
	caps->x_resolution = config->width;
	caps->y_resolution = config->height;
	caps->supported_pixel_formats = config->supported_pixel_formats;
	caps->current_pixel_format = config->supported_pixel_formats;
	caps->screen_info = SCREEN_INFO_MONO_MSB_FIRST | SCREEN_INFO_EPD;
}

static int e2266_set_pixel_format(const struct device *dev, const enum display_pixel_format pf)
{
	const struct pervasive_config *config = dev->config;
	if (pf & config->supported_pixel_formats) {
		return 0;
	}

	return -ENOTSUP;
}

static const struct display_driver_api e2266_driver_api = {
	.blanking_on = e2266_blanking_on,
	.blanking_off = e2266_blanking_off,
	.get_framebuffer = (display_get_framebuffer_api)pervasive_not_support,
	.set_brightness = (display_set_brightness_api)pervasive_not_support,
	.set_contrast = (display_set_contrast_api)pervasive_not_support,
	.set_pixel_format = e2266_set_pixel_format,
	.read = (display_read_api)pervasive_not_support,
	.write = e2266_write,
	.get_capabilities = e2266_get_capabilities,
};

#endif

#ifdef CONFIG_SHIELD_PERVASIVE_EPAPER_E2266QS0F1

const uint8_t reg_266[] = {0x07, 0x0f, 0x29, 0x10, 0x54, 0x44, 0x05, 0x00, 0x3f,
			   0x0a, 0x25, 0x12, 0x1a, 0x37, 0x02, 0x02, 0x00, 0x98,
			   0x01, 0x28, 0x1c, 0x22, 0x78, 0xd0, 0x00, 0x01, 0x08};

// FIXME: spi 3-wire is not support yet.
static int e2266qs0f1_read_id(const struct pervasive_config *config)
{
	int err;
	err = pervasive_write_cmd(config, 0x70, NULL, 0);

	if (err >= 0) {
		uint8_t id[2];
		err = pervasive_read(config, id, sizeof(id));
		if (id[0] != 0x03 || id[1] != 0x02) {
			return -ENXIO;
		}
	}
	return err;
}

static int e2266qs0f1_cog_power_on(const struct pervasive_config *config)
{
	int err;

#ifdef PC_GPIO_EXIST
	err = gpio_pin_set_dt(&pc_gpio, 1);
	if (err < 0) {
		return err;
	}
#endif
	// reset device
	err = gpio_pin_set_dt(&config->reset_gpio, 0);

	if (err >= 0) {
		k_msleep(E2266QS0F1_RESET_BEFORE_DELAY);
		err = gpio_pin_set_dt(&config->reset_gpio, 1);
	}

	if (err >= 0) {
		k_msleep(E2266QS0F1_RESET_ING_DELAY);
		err = gpio_pin_set_dt(&config->reset_gpio, 0);
	}

	if (err >= 0) {
		k_msleep(E2266QS0F1_RESET_AFTER_DELAY);
		err = pervasive_busy_wait_check_high(config, TIMEOUT_RST_BUSY_MS);
	}

	if (err >= 0) {
		// FIXME: 3wire read not work now.
		e2266qs0f1_read_id(config);
	}

	// COG initial commands
	if (err >= 0 && (err = pervasive_write_cmd(config, 0x01, &reg_266[0], 1)) >= 0 &&
	    (err = pervasive_write_cmd(config, 0x00, &reg_266[1], 2)) >= 0 &&
	    (err = pervasive_write_cmd(config, 0x03, &reg_266[3], 3)) >= 0 &&
	    (err = pervasive_write_cmd(config, 0x06, &reg_266[6], 7)) >= 0 &&
	    (err = pervasive_write_cmd(config, 0x50, &reg_266[13], 1)) >= 0 &&
	    (err = pervasive_write_cmd(config, 0x60, &reg_266[14], 2)) >= 0 &&
	    (err = pervasive_write_cmd(config, 0x61, &reg_266[16], 4)) >= 0 &&
	    (err = pervasive_write_cmd(config, 0xe7, &reg_266[20], 1)) >= 0 &&
	    (err = pervasive_write_cmd(config, 0xe3, &reg_266[21], 1)) >= 0 &&
	    (err = pervasive_write_cmd(config, 0x4d, &reg_266[22], 1)) >= 0 &&
	    (err = pervasive_write_cmd(config, 0xb4, &reg_266[23], 1)) >= 0 &&
	    (err = pervasive_write_cmd(config, 0xb5, &reg_266[24], 1)) >= 0 &&
	    (err = pervasive_write_cmd(config, 0xe9, &reg_266[25], 1)) >= 0 &&
	    (err = pervasive_write_cmd(config, 0x30, &reg_266[26], 1))) {
	}

	return err;
}

static int e2266qs0f1_globalupdate(const struct device *dev, const void *buf, uint16_t width,
				   uint16_t height)
{
	const struct pervasive_config *config = dev->config;
	int err = 0;

#ifndef CONFIG_PERVASIVE_SW_FB
	struct pervasive_data *data = dev->data;
	bool frame_done = data->current_y + height == config->height;
	if (!data->current_y) {
#endif
		// power on
		err = e2266qs0f1_cog_power_on(config);
		if (err >= 0) {
			err = pervasive_write_cmd(config, 0x10, NULL, 0);
		}
#ifndef CONFIG_PERVASIVE_SW_FB
	}
#endif
	// power on and initial

	// update image
	if (err >= 0) {
		err = pervasive_write_data(config, buf, width * height / 4);
	}

#ifndef CONFIG_PERVASIVE_SW_FB
	if (!frame_done) {
		return err;
	}
#endif

	// updating
	if (err >= 0) {
		uint8_t ref = 0;
		err = e2266_updating(config, &ref, 1);
	}

	// power off
	if (err >= 0) {
		err = pervasive_cog_power_off(dev->config);
	}
	return err;
}

#ifdef CONFIG_PERVASIVE_SW_FB
static int e2266qs0f1_update_fb(const struct device *dev, const uint16_t x, const uint16_t y,
				const uint8_t *buf, const struct display_buffer_descriptor *desc)
{
	const struct pervasive_config *config = dev->config;
	struct pervasive_data *data = dev->data;

	__ASSERT(desc->pitch == desc->width, "should equal");
	__ASSERT(desc->pitch == desc->width, "should equal");
	__ASSERT((y + desc->height) <= config->height, "wrong");
	__ASSERT((x + desc->width) <= config->width, "wrong");

	const size_t buf_len = MIN(desc->buf_size, sizeof(data->frame_buf));

	if (buf_len < sizeof(data->frame_buf)) {
		int w = desc->width / 4;
		for (int h = 0; h < desc->height; h++) {
			memcpy(&data->frame_buf[(y + h) * (config->width / 4) + x / 4], &buf[h * w],
			       w);
		}
		return 1;
	} else {
		memcpy(data->frame_buf, buf, buf_len);
	}
	return 0;
}
#endif

#endif

#ifdef CONFIG_SHIELD_PERVASIVE_EPAPER_E2266CS0C2
static int e2266cs0c2_softreset(const struct pervasive_config *config)
{
	int err =
		pervasive_write_one_bytes(config, PERVASIVE_SEPD_IDX_SRST, PERVASIVE_SEPD_VAL_SRST);
	if (err >= 0) {
		pervasive_busy_wait(config);
	}
	return err;
}

static int e2266cs0c2_cog_power_on(const struct pervasive_config *config)
{
	int err;
#ifdef PC_GPIO_EXIST
	err = gpio_pin_set_dt(&pc_gpio, 1);
	if (err < 0) {
		return err;
	}
#endif
	// reset pins
	err = gpio_pin_set_dt(&config->reset_gpio, 0);

	if (err >= 0) {
		k_msleep(E2266CS0C2_RESET_BEFORE_DELAY);
		err = gpio_pin_set_dt(&config->reset_gpio, 1);
	}

	if (err >= 0) {
		k_msleep(E2266CS0C2_RESET_ING_DELAY);
		err = gpio_pin_set_dt(&config->reset_gpio, 0);
	}

	if (err >= 0) {
		k_msleep(E2266CS0C2_RESET_AFTER_DELAY);
		err = pervasive_busy_wait_check_high(config, TIMEOUT_RST_BUSY_MS);
	}

	if (err >= 0) {
		err = e2266cs0c2_softreset(config);
	}

	if (err >= 0) {
		err = pervasive_write_one_bytes(config, PERVASIVE_SEPD_IDX_TEMP,
						PERVASIVE_SEPD_VAL_TEMP);
	}
	if (err >= 0) {
		err = pervasive_write_one_bytes(config, PERVASIVE_SEPD_IDX_ACTT,
						PERVASIVE_SEPD_VAL_ACTT);
	}
	if (err >= 0) {
		err = pervasive_write_cmd(config, PERVASIVE_SEPD_IDX_PSR,
					  (uint8_t[]){PERVASIVE_SEPD_VAL_PSR}, 2);
	}

	return err;
}

static int e2266cs0c2_globalupdate(const struct device *dev, const void *buf, uint16_t width,
				   uint16_t height)
{
	const struct pervasive_config *config = dev->config;
	struct pervasive_data *data = dev->data;
	int err = 0;

#ifndef CONFIG_PERVASIVE_SW_FB
	bool frame_done = data->current_y + height == config->height;
	if (!data->current_y) {
#endif
		// power on
		err = e2266cs0c2_cog_power_on(config);
		if (err >= 0) {
			err = pervasive_write_cmd(config, 0x10, NULL, 0);
		}
#ifndef CONFIG_PERVASIVE_SW_FB
	}
#endif

	// update image1
	if (err >= 0) {
		err = pervasive_write_data(config, buf, width * height / 8);
	}

#ifndef CONFIG_PERVASIVE_SW_FB
	if (!frame_done) {
		return err;
	}
#endif

	// update 0x00s
	if (err >= 0) {
		err = pervasive_write_cmd(config, 0x13, data->dummy00, sizeof(data->dummy00));
	}

	if (err >= 0) {
		err = e2266_updating(config, NULL, 0);
	}

	// power off
	if (err >= 0) {
		err = pervasive_cog_power_off(dev->config);
	}
	return err;
}

#ifdef CONFIG_PERVASIVE_SW_FB
static int e2266cs0c2_update_fb(const struct device *dev, const uint16_t x, const uint16_t y,
				const uint8_t *buf, const struct display_buffer_descriptor *desc)
{
	const struct pervasive_config *config = dev->config;
	struct pervasive_data *data = dev->data;

	const size_t buf_len = MIN(desc->buf_size, sizeof(data->frame_buf));

	if (buf_len < sizeof(data->frame_buf)) {
		int w = desc->width / 8;
		for (int h = 0; h < desc->height; h++) {
			memcpy(&data->frame_buf[(y + h) * (config->width / 8) + x / 8], &buf[h * w],
			       w);
		}
		return 1;
	} else {
		memcpy(data->frame_buf, buf, buf_len);
	}

	return 0;
}
#endif

#endif

#ifdef CONFIG_SHIELD_PERVASIVE_EPAPER_E2741JS0B2

static void e2741js0b2_get_capabilities(const struct device *dev, struct display_capabilities *caps)
{
	const struct pervasive_config *config = dev->config;
	memset(caps, 0, sizeof(struct display_capabilities));
	caps->x_resolution = config->width;
	caps->y_resolution = config->height;
	caps->supported_pixel_formats = PIXEL_FORMAT_CW10 | PIXEL_FORMAT_MONO10;
	caps->current_pixel_format = PIXEL_FORMAT_MONO10;
	caps->screen_info = SCREEN_INFO_MONO_MSB_FIRST | SCREEN_INFO_EPD;
}

const uint8_t reg_init[] = {0x01, 0x01, 0x08, 0x13, 0x06, 0x00, 0x3b, 0x00, 0x00, 0x1f, 0x03,
			    0x90, 0x04, 0x00, 0x3b, 0x00, 0xc9, 0x12, 0x03, 0x3b, 0x00, 0x14};

static int e2741js0b2_cog_power_on(const struct pervasive_config *config)
{
	int err;

#ifdef PC_GPIO_EXIST
	err = gpio_pin_set_dt(&pc_gpio, 1);
	if (err < 0) {
		return err;
	}
#endif
	// reset device
	err = gpio_pin_set_dt(&config->reset_gpio, 0);

	if (err >= 0) {
		k_msleep(E2741JS0B2_RESET_BEFORE_DELAY);
		err = gpio_pin_set_dt(&config->reset_gpio, 1);
	}

	if (err >= 0) {
		k_msleep(E2741JS0B2_RESET_ING_DELAY);
		err = gpio_pin_set_dt(&config->reset_gpio, 0);
	}

	if (err >= 0) {
		k_msleep(E2741JS0B2_RESET_AFTER_DELAY);
		err = pervasive_busy_wait_check_high(config, TIMEOUT_RST_BUSY_MS);
		if (err < 0) {
			return err;
		}
		// COG initial commands
		const uint8_t *ptr = &reg_init[0];
		do {
			err = pervasive_write_cmd(config, ptr[0], &ptr[2], ptr[1]);
			ptr += ptr[1] + 2;
		} while (err >= 0 && (ptr < reg_init + sizeof(reg_init)));
	}

	return err;
}

static int e2741js0b2_dcdc_soft_start(const struct pervasive_config *config)
{
	pervasive_write_one_bytes(config, 0x05, 0x7d);
	k_msleep(200);
	pervasive_write_one_bytes(config, 0x05, 0x00);
	k_msleep(10);
	pervasive_write_one_bytes(config, 0xc2, 0x3f);
	k_msleep(1);
	pervasive_write_one_bytes(config, 0xd8, 0x00); // MS_SYNC mtp_0x1d
	pervasive_write_one_bytes(config, 0xd6, 0x00); // BVSS mtp_0x1e
	pervasive_write_one_bytes(config, 0xa7, 0x10);
	k_msleep(100);
	pervasive_write_one_bytes(config, 0xa7, 0x00);
	k_msleep(100);
	uint8_t data10[] = {0x00, 0x01};              // OSC
	pervasive_write_cmd(config, 0x03, data10, 2); // OSC mtp_0x12
	pervasive_write_one_bytes(config, 0x44, 0x00);
	pervasive_write_one_bytes(config, 0x45, 0x80);
	pervasive_write_one_bytes(config, 0xa7, 0x10);
	k_msleep(100);
	pervasive_write_one_bytes(config, 0xa7, 0x00);
	k_msleep(100);
	pervasive_write_one_bytes(config, 0x44, 0x06);
	pervasive_write_one_bytes(config, 0x45, 0x82); // Temperature 0x82@25C
	pervasive_write_one_bytes(config, 0xa7, 0x10);
	k_msleep(100);
	pervasive_write_one_bytes(config, 0xa7, 0x00);
	k_msleep(100);
	pervasive_write_one_bytes(config, 0x60, 0x25); // TCON mtp_0x0b
	pervasive_write_one_bytes(config, 0x61, 0x00); // STV_DIR mtp_0x1c
	pervasive_write_one_bytes(config, 0x01, 0x00); // DCTL mtp_0x10
	pervasive_write_one_bytes(config, 0x02, 0x00); // VCOM mtp_0x11

	// DC-DC soft-start
	uint8_t index51[] = {0x50, 0x01, 0x0a, 0x01};
	pervasive_write_cmd(config, 0x51, &index51[0], 2);
	uint8_t index09[] = {0x1f, 0x9f, 0x7f, 0xff};

	for (int value = 1; value <= 4; value++) {
		pervasive_write_one_bytes(config, 0x09, index09[0]);
		index51[1] = value;
		pervasive_write_cmd(config, 0x51, &index51[0], 2);
		pervasive_write_one_bytes(config, 0x09, index09[1]);
		k_msleep(2);
	}
	for (int value = 1; value <= 10; value++) {
		pervasive_write_one_bytes(config, 0x09, index09[0]);
		index51[3] = value;
		pervasive_write_cmd(config, 0x51, &index51[2], 2);
		pervasive_write_one_bytes(config, 0x09, index09[1]);
		k_msleep(2);
	}
	for (int value = 3; value <= 10; value++) {
		pervasive_write_one_bytes(config, 0x09, index09[2]);
		index51[3] = value;
		pervasive_write_cmd(config, 0x51, &index51[2], 2);
		pervasive_write_one_bytes(config, 0x09, index09[3]);
		k_msleep(2);
	}
	for (int value = 9; value >= 2; value--) {
		pervasive_write_one_bytes(config, 0x09, index09[2]);
		index51[2] = value;
		pervasive_write_cmd(config, 0x51, &index51[2], 2);
		pervasive_write_one_bytes(config, 0x09, index09[3]);
		k_msleep(2);
	}
	pervasive_write_one_bytes(config, 0x09, index09[3]);
	k_msleep(10);
	return 0;
}

static int e2741js0b2_updating(const struct pervasive_config *config)
{
	int err;
	// display refresh
	err = pervasive_write_one_bytes(config, 0x15, 0x3c);
	if (err >= 0) {
		k_msleep(5);
		err = pervasive_busy_wait_check_low(config, 10);
	}
	// DC-DC off
	if (err >= 0) {
		uint8_t off[] = {0x7f, 0x7d, 0x00};
		err = pervasive_write_cmd(config, 0x09, off, 3);
	}
	k_msleep(200);
	pervasive_busy_wait(config);
	return err;
}

static int e2741js0b2_globalupdate(const struct device *dev, const void *buf, uint16_t width,
				   uint16_t height)
{
	const struct pervasive_config *config = dev->config;
	struct pervasive_data *data = dev->data;
	int err = 0;
	bool frame_done = data->current_y + height == config->height;
	if (data->curr_format == PIXEL_FORMAT_MONO10) {
		if (!data->current_y) {
			// power on and initial
			err = e2741js0b2_cog_power_on(config);
			if (err >= 0) {
				err = pervasive_write_cmd(config, 0x10, NULL, 0);
			}
		}

		if (err >= 0) {
			err = pervasive_write_data(config, buf, height * width / 8);
		}

		if (!frame_done) {
			return err;
		}

		if (err >= 0) {
			err = pervasive_write_cmd(config, reg_init[17], &reg_init[19],
						  reg_init[18]);
		}
		return err;
	}

	if (!data->current_y) {
		// update image
		err = pervasive_write_cmd(config, 0x11, NULL, 0);
	}

	if (err >= 0) {
		err = pervasive_write_data(config, buf, height * width / 8);
	}

	if (!frame_done) {
		return err;
	}

	if (err >= 0) {
		e2741js0b2_dcdc_soft_start(config);
	}

	// updating
	if (err >= 0) {
		err = e2741js0b2_updating(config);
	}

	// power off
	if (err >= 0) {
		err = pervasive_cog_power_off(dev->config);
	}
	return err;
}

// Atmosic defined
static int e2741js0b2_set_pixel_format(const struct device *dev, const enum display_pixel_format pf)
{
	struct pervasive_data *data = dev->data;
	if (pf == data->allow_format || pf == data->curr_format) {
		data->curr_format = pf;
		return 0;
	}

	return -ENOTSUP;
}

static int e2741js0b2_write(const struct device *dev, const uint16_t x, const uint16_t y,
			    const struct display_buffer_descriptor *desc, const void *buf)
{
	struct pervasive_data *data = dev->data;
	const struct pervasive_config *config = dev->config;
	int err;

	if (pervasive_check_param(x, y, buf, dev, desc) < 0) {
		return -EINVAL;
	}

	if (data->allow_format != data->curr_format) {
		LOG_ERR("Pixel format change needed");
		return -EINVAL;
	}

	if (data->blanking_on) {
		return -EINVAL;
	}

	err = e2741js0b2_globalupdate(dev, buf, desc->width, desc->height);
	data->current_y = y + desc->height;

	if ((err >= 0) && (data->current_y == config->height)) {
		if (data->curr_format == PIXEL_FORMAT_MONO10) {
			data->allow_format = PIXEL_FORMAT_CW10;
		} else {
			data->allow_format = PIXEL_FORMAT_MONO10;
		}
		data->current_y = 0;
	}

	return err;
}

static int e2741_init(const struct device *dev)
{
	pervasive_init(dev);
	return 0;
}

static int pervasive_blanking_on(const struct device *dev)
{
	struct pervasive_data *data = dev->data;
	if (!data->blanking_on) {
		data->blanking_on = true;
	}
	return 0;
}

static int pervasive_blanking_off(const struct device *dev)
{
	struct pervasive_data *data = dev->data;
	if (data->blanking_on) {
		data->blanking_on = false;
	}

	return 0;
}

#endif

#define PERVASIVE_GET_CONFIG(n)                                                                    \
	.bus = SPI_DT_SPEC_GET(n, SPI_OP_MODE_MASTER | SPI_WORD_SET(8) | SPI_LOCK_ON),             \
	.reset_gpio = GPIO_DT_SPEC_GET(DT_CHILD(n, ext_io), reset_gpios),                          \
	.dc_gpio = GPIO_DT_SPEC_GET(DT_CHILD(n, ext_io), dc_gpios),                                \
	.busy_gpio = GPIO_DT_SPEC_GET(DT_CHILD(n, ext_io), busy_gpios),                            \
	.height = DT_PROP(n, height), .width = DT_PROP(n, width)

#if defined(CONFIG_SHIELD_PERVASIVE_EPAPER_E2266CS0C2) ||                                          \
	defined(CONFIG_SHIELD_PERVASIVE_EPAPER_E2266QS0F1)

#ifdef CONFIG_PERVASIVE_SW_FB
#define E2266_ADD_FB_FN(fn) .fb_update_fn = fn,
#else
#define E2266_ADD_FB_FN(fn)
#endif

#ifdef CONFIG_SHIELD_PERVASIVE_EPAPER_E2266CS0C2
#define E2266_GET_CONFIG(n)                                                                        \
	.supported_pixel_formats = PIXEL_FORMAT_MONO10,                                            \
	.global_update_fn = e2266cs0c2_globalupdate, E2266_ADD_FB_FN(e2266cs0c2_update_fb)

#elif CONFIG_SHIELD_PERVASIVE_EPAPER_E2266QS0F1
#define E2266_GET_CONFIG(n)                                                                        \
	.supported_pixel_formats = PIXEL_FORMAT_BWRY11,                                            \
	.spi_read_freq = DT_PROP(n, spi_read_max_freq),                                            \
	.global_update_fn = e2266qs0f1_globalupdate, E2266_ADD_FB_FN(e2266qs0f1_update_fb)

#endif

#define E2266_DEFINE(n)                                                                            \
	static const struct pervasive_config pervasive_cfg_##n = {PERVASIVE_GET_CONFIG(n),         \
								  E2266_GET_CONFIG(n)};            \
	static struct pervasive_data pervasive_data_##n;                                           \
	DEVICE_DT_DEFINE(n, e2266_init, NULL, &pervasive_data_##n, &pervasive_cfg_##n,             \
			 POST_KERNEL, CONFIG_DISPLAY_INIT_PRIORITY, &e2266_driver_api)

DT_FOREACH_STATUS_OKAY(pervasive_e2266cs0c2, E2266_DEFINE);
DT_FOREACH_STATUS_OKAY(pervasive_e2266qs0f1, E2266_DEFINE);

#elif CONFIG_SHIELD_PERVASIVE_EPAPER_E2741JS0B2

static const struct display_driver_api e2741js0b2_driver_api = {
	.blanking_on = pervasive_blanking_on,
	.blanking_off = pervasive_blanking_off,
	.get_framebuffer = (display_get_framebuffer_api)pervasive_not_support,
	.set_brightness = (display_set_brightness_api)pervasive_not_support,
	.set_contrast = (display_set_contrast_api)pervasive_not_support,
	.set_pixel_format = e2741js0b2_set_pixel_format,
	.read = (display_read_api)pervasive_not_support,
	.write = e2741js0b2_write,
	.get_capabilities = e2741js0b2_get_capabilities,
};
#define E2741JS0B2_DEFINE(n)                                                                       \
	static const struct pervasive_config pervasive_cfg_##n = {                                 \
		PERVASIVE_GET_CONFIG(n), .spi_read_freq = DT_PROP(n, spi_read_max_freq)};          \
	static struct pervasive_data pervasive_data_##n = {                                        \
		.allow_format = PIXEL_FORMAT_MONO10,                                               \
		.curr_format = PIXEL_FORMAT_MONO10,                                                \
	};                                                                                         \
	DEVICE_DT_DEFINE(n, e2741_init, NULL, &pervasive_data_##n, &pervasive_cfg_##n,             \
			 POST_KERNEL, CONFIG_DISPLAY_INIT_PRIORITY, &e2741js0b2_driver_api)

DT_FOREACH_STATUS_OKAY(pervasive_e2741js0b2, E2741JS0B2_DEFINE);

#endif
