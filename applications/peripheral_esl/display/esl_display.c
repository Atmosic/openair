/*
 *******************************************************************************
 *
 * @file esl_display.c
 *
 * @brief This is display driver for ESL service
 *
 * Copyright (c) 2024-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(esl_display, LOG_LEVEL_INF);

#include <zephyr/device.h>
#include <zephyr/drivers/display.h>
#include "esls.h"
#include "esl_image.h"

typedef struct {
	uint16_t cur_y;
	uint16_t valid_data;
	uint16_t min_set_size;
	uint16_t max_set_size;
	uint8_t setbuf[IMG_STORAGE_SECTOR_MAX_SIZE];
	uint8_t readbuf[IMG_STORAGE_SECTOR_MAX_SIZE];
	uint8_t dis_idx;
	bool updating;
} esl_display_context_t;

typedef struct {
	const struct device *dis_dev;
	struct bt_esls_display_info dis_info;
	uint16_t display_size;
} esl_display_info_t;

static struct display_buffer_descriptor disp_buf_desc;
static esl_display_context_t esl_disp_ctx;
static esl_display_info_t esl_disp[CONFIG_BT_ESLS_DISPLAY_NUM];

int esl_display_init(void)
{
	for (uint8_t idx = 0; idx < CONFIG_BT_ESLS_DISPLAY_NUM; idx++) {
		esl_disp[idx].dis_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
		if (!device_is_ready(esl_disp[idx].dis_dev)) {
			LOG_ERR("Device %s not found.", esl_disp[idx].dis_dev->name);
			return -ENXIO;
		}

		LOG_INF("Display sample for %s", esl_disp[idx].dis_dev->name);
		struct display_capabilities disp_capa;
		display_get_capabilities(esl_disp[idx].dis_dev, &disp_capa);
		esl_disp[idx].dis_info.width = disp_capa.x_resolution;
		esl_disp[idx].dis_info.height = disp_capa.y_resolution;
#ifdef CONFIG_SHIELD_PERVASIVE_EPAPER_E2266QS0F1
		esl_disp[idx].dis_info.type = BT_ESLS_DISPLAY_TYPE_RED_YELLOW_BLACK_WHITE;
#elif defined(CONFIG_SHIELD_PERVASIVE_EPAPER_E2266CS0C2)
		esl_disp[idx].dis_info.type = BT_ESLS_DISPLAY_TYPE_BLACK_WHITE;
#elif defined(CONFIG_SHIELD_PERVASIVE_EPAPER_E2741JS0B2)
		esl_disp[idx].dis_info.type = BT_ESLS_DISPLAY_TYPE_RED_BLACK_WHITE;
#else
		esl_disp[idx].dis_info.type = BT_ESLS_DISPLAY_TYPE_BLACK_WHITE;
#endif
		uint8_t pixel_bits =
			(esl_disp[idx].dis_info.type == BT_ESLS_DISPLAY_TYPE_RED_YELLOW_BLACK_WHITE)
				? 2
				: 1;
		esl_disp[idx].display_size =
			(disp_capa.x_resolution >> (4 - pixel_bits)) * disp_capa.y_resolution;
	}
	return 0;
}

static int esl_display_ctx_reset(uint8_t display_idx)
{
	if (esl_disp_ctx.updating) {
		LOG_ERR("display is in progaming.");
		return -EINPROGRESS;
	}

	uint8_t pixel_bits =
		(esl_disp[display_idx].dis_info.type == BT_ESLS_DISPLAY_TYPE_RED_YELLOW_BLACK_WHITE)
			? 2
			: 1;
	esl_disp_ctx.min_set_size = esl_disp[display_idx].dis_info.width >> (4 - pixel_bits);
	uint16_t max_set_h;
	max_set_h = (IMG_STORAGE_SECTOR_MAX_SIZE << (4 - pixel_bits)) /
		    esl_disp[display_idx].dis_info.width;
	esl_disp_ctx.max_set_size = max_set_h * esl_disp_ctx.min_set_size;
	esl_disp_ctx.valid_data = 0;
	esl_disp_ctx.cur_y = 0;
	esl_disp_ctx.updating = false;
	esl_disp_ctx.dis_idx = CONFIG_BT_ESLS_DISPLAY_NUM;

	return 0;
}

static int esl_display_write_ctx(uint8_t disp_idx, uint16_t write_size)
{
	disp_buf_desc.buf_size = write_size;
	disp_buf_desc.width = esl_disp[disp_idx].dis_info.width;
	disp_buf_desc.pitch = disp_buf_desc.width;
	disp_buf_desc.height = write_size / esl_disp_ctx.min_set_size;

	int err = display_write(esl_disp[disp_idx].dis_dev, 0, esl_disp_ctx.cur_y, &disp_buf_desc,
				esl_disp_ctx.setbuf);
	if (err) {
		esl_disp_ctx.updating = false;
		LOG_ERR("%s ", __func__);
		return err;
	}
	esl_disp_ctx.cur_y += disp_buf_desc.height;
	return err;
}

static int esl_display_update(uint8_t display_idx, uint16_t buflen)
{
	if (esl_disp_ctx.cur_y) {
		if (!esl_disp_ctx.updating || (esl_disp_ctx.dis_idx != display_idx)) {
			LOG_ERR("%s y:%d", __func__, esl_disp_ctx.cur_y);
			return -EINVAL;
		}
	} else {
		esl_disp_ctx.updating = true;
		esl_disp_ctx.dis_idx = display_idx;
	}

	uint16_t set_size, copy_size;
	set_size = esl_disp_ctx.valid_data + buflen;
	if (set_size > esl_disp_ctx.max_set_size) {
		set_size = esl_disp_ctx.max_set_size;
	}
	if (set_size % esl_disp_ctx.min_set_size) {
		LOG_ERR("%s Not support valid:%d read:%d", __func__, esl_disp_ctx.valid_data,
			buflen);
		return -EINVAL;
	}
	copy_size = set_size - esl_disp_ctx.valid_data;
	memcpy(&esl_disp_ctx.setbuf[esl_disp_ctx.valid_data], esl_disp_ctx.readbuf, copy_size);

	int err = esl_display_write_ctx(display_idx, set_size);
	if (err) {
		return err;
	}
	esl_disp_ctx.valid_data = buflen - copy_size;
	memcpy(esl_disp_ctx.setbuf, &esl_disp_ctx.readbuf[copy_size], esl_disp_ctx.valid_data);

	bool img_end = false;
	if ((esl_disp_ctx.valid_data / esl_disp_ctx.min_set_size + esl_disp_ctx.cur_y) ==
	    esl_disp[display_idx].dis_info.height) {
		img_end = true;
	}

	// Image End or do one more time if there are more data in buffer
	if ((esl_disp_ctx.valid_data >= esl_disp_ctx.max_set_size) ||
	    (img_end && esl_disp_ctx.valid_data)) {
		set_size = img_end ? esl_disp_ctx.valid_data : esl_disp_ctx.max_set_size;
		err = esl_display_write_ctx(display_idx, set_size);
		if (err) {
			return err;
		}
		esl_disp_ctx.valid_data -= set_size;
		if (esl_disp_ctx.valid_data) {
			memcpy(esl_disp_ctx.setbuf, &esl_disp_ctx.setbuf[set_size],
			       esl_disp_ctx.valid_data);
		}
	}

	if (img_end) {
		esl_disp_ctx.updating = false;
	}

	return err;
}

static int esl_display_black(uint8_t display_idx)
{
	LOG_INF("%s: %d", __func__, display_idx);

	int err = esl_display_ctx_reset(display_idx);
	if (err) {
		return err;
	}
	display_blanking_off(esl_disp[display_idx].dis_dev);

	memset(esl_disp_ctx.readbuf, 0, IMG_STORAGE_SECTOR_MAX_SIZE);

	uint16_t img_size = esl_disp[display_idx].display_size;

	for (uint16_t offset = 0; offset < img_size;) {
		uint16_t read_size = img_size - offset;
		if (read_size > IMG_STORAGE_SECTOR_MAX_SIZE) {
			read_size = IMG_STORAGE_SECTOR_MAX_SIZE;
		}

		err = esl_display_update(display_idx, read_size);
		if (err) {
			LOG_ERR("%s display error:%d", __func__, err);
			return err;
		}
		offset += read_size;
	}
	return err;
}

static int esl_display_image(uint8_t display_idx, uint8_t img_idx)
{
	if (img_idx == CONFIG_BT_ESLS_IMAGE_NUM) {
		return esl_display_black(display_idx);
	}
	uint16_t img_size;
	int err = esl_img_rd_size(img_idx, &img_size);
	if (err || !img_size) {
		LOG_ERR("%s read_img_size error:%d, size:%d", __func__, err, img_size);
		return err;
	}
	if (img_size != esl_disp[display_idx].display_size) {
		LOG_ERR("%s Wrong Image size:%d, panel:%d", __func__, img_size,
			esl_disp[display_idx].display_size);
		return -EINVAL;
	}

	err = esl_display_ctx_reset(display_idx);
	if (err) {
		return err;
	}

	display_blanking_off(esl_disp[display_idx].dis_dev);

	for (uint16_t offset = 0; offset < img_size;) {
		uint16_t read_size = img_size - offset;
		if (read_size > IMG_STORAGE_SECTOR_MAX_SIZE) {
			read_size = IMG_STORAGE_SECTOR_MAX_SIZE;
		}
		if (esl_img_rd_data(img_idx, esl_disp_ctx.readbuf, offset, read_size)) {
			LOG_ERR("%s read_img_data error:%d", __func__, err);
			return -ESRCH;
		}
		err = esl_display_update(display_idx, read_size);
		if (err) {
			LOG_ERR("%s display error:%d", __func__, err);
			return err;
		}
		offset += read_size;
	}

	return err;
}

void esl_display_init_dsp_info(struct bt_esls_init_param *init_param)
{
	/** Initial Display elements here **/
	for (uint8_t idx = 0; idx < CONFIG_BT_ESLS_DISPLAY_NUM; idx++) {
		init_param->display_info[idx] = esl_disp[idx].dis_info;
		init_param->display_image = esl_display_image;
	}
}
