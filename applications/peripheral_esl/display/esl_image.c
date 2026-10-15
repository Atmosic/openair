/*
 *******************************************************************************
 *
 * @file esl_display.c
 *
 * @brief This is image driver for ESL service
 *
 * Copyright (c) 2024-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(esl_image, LOG_LEVEL_INF);
#include <zephyr/drivers/flash.h>
#include <zephyr/kvss/nvs.h>
#include <zephyr/storage/flash_map.h>
#include "esls.h"
#include "esl_image.h"

#define IMG_STORAGE_SECTOR_MAX_NUM                                                                 \
	((CONFIG_BT_ESLS_IMAGE_MAX_SIZE / IMG_STORAGE_SECTOR_MAX_SIZE) + 1)
#define NVS_ID_IMG_START           1
#define NVS_ID_IMG_SIZE_START(IDX) (NVS_ID_IMG_START + (IDX) * (IMG_STORAGE_SECTOR_MAX_NUM + 1))
#define NVS_ID_IMG_DATA_START(IDX) (NVS_ID_IMG_SIZE_START(IDX) + 1)
#define NVS_ID_IMG_DATA_END(IDX)   (NVS_ID_IMG_DATA_START(IDX) + IMG_STORAGE_SECTOR_MAX_NUM - 1)
static char *obj_name = "ESL Image_0";
#define EPD_STORAGE          epd_storage
#define EPD_PARTITION_DEVICE PARTITION_DEVICE(EPD_STORAGE)
#define EPD_PARTITION_OFFSET PARTITION_OFFSET(EPD_STORAGE)
#define EPD_PARTITION_SIZE   PARTITION_SIZE(EPD_STORAGE)

static struct nvs_fs esl_storage = {
	.flash_device = EPD_PARTITION_DEVICE,
	.offset = EPD_PARTITION_OFFSET,
};

static int esl_img_get_img_name(uint8_t img_idx, char **name)
{
#define IMG_NAME_IDX_OFFSET 10
	obj_name[IMG_NAME_IDX_OFFSET] = img_idx + '0';
	*name = obj_name;
	return 0;
}

static void esl_img_nvs_init(void)
{
	struct flash_pages_info info;

	if (flash_get_page_info_by_offs(esl_storage.flash_device, esl_storage.offset, &info)) {
		LOG_ERR("Unable to get page info");
		esl_storage.sector_size = 4096;
	} else {
		esl_storage.sector_size = info.size;
	}

	if (IMG_STORAGE_SECTOR_MAX_SIZE >= esl_storage.sector_size) {
		LOG_ERR("%s:ERR-IMG_STORAGE_SECTOR_MAX_SIZE:%d, sec:%d", __func__,
			IMG_STORAGE_SECTOR_MAX_SIZE, esl_storage.sector_size);
	}

	esl_storage.sector_count = EPD_PARTITION_SIZE / esl_storage.sector_size;

	uint16_t min_saved_secs = (esl_storage.sector_count - 1) *
				  (esl_storage.sector_size / IMG_STORAGE_SECTOR_MAX_SIZE);
	uint16_t needed_secs = IMG_STORAGE_SECTOR_MAX_NUM * CONFIG_BT_ESLS_IMAGE_NUM + 1;

	// 1 sectore for gc, 1 img sector for updating
	if (min_saved_secs < needed_secs) {
		LOG_ERR("%s:%d, min:%d needed:%d", __func__, esl_storage.sector_count,
			min_saved_secs, needed_secs);
	}

	int err = nvs_mount(&esl_storage);
	if (err) {
		LOG_ERR("%s err:%d", __func__, err);
	}
	ssize_t reaserved = nvs_calc_free_space(&esl_storage);
	LOG_INF("%s free:%d, sec:%d, size:%d", __func__, reaserved, esl_storage.sector_count,
		esl_storage.sector_size);
}

int esl_img_rd_size(uint8_t img_idx, uint16_t *size)
{
	LOG_INF("%s id:%d", __func__, NVS_ID_IMG_SIZE_START(img_idx));
	ssize_t err =
		nvs_read(&esl_storage, NVS_ID_IMG_SIZE_START(img_idx), size, sizeof(uint16_t));
	if (err < 0) {
		*size = 0;
		if (err == -ENOENT) {
			LOG_INF("%s err:%d", __func__, err);
			return 0;
		}
		LOG_ERR("%s err:%d", __func__, err);
		return err;
	}
	return 0;
}

int esl_img_rd_data(uint8_t img_idx, uint8_t *buf, uint16_t offset, uint16_t len)
{
	LOG_INF("%s len:%d", __func__, len);
	uint16_t rem = len;
	uint16_t nvs_id = NVS_ID_IMG_DATA_START(img_idx);

	if (offset % IMG_STORAGE_SECTOR_MAX_SIZE) {
		LOG_ERR("%s err:Not supportted offset", __func__);
		return -EINVAL;
	}
	uint8_t i = offset / IMG_STORAGE_SECTOR_MAX_SIZE;
	for (; i < IMG_STORAGE_SECTOR_MAX_NUM; i++) {
		uint16_t read_len =
			(rem > IMG_STORAGE_SECTOR_MAX_SIZE) ? IMG_STORAGE_SECTOR_MAX_SIZE : rem;
		ssize_t size = nvs_read(&esl_storage, nvs_id + i, buf, read_len);
		if (size < 0) {
			LOG_ERR("%s err:%d", __func__, size);
			return size;
		}
		rem -= read_len;
		buf += read_len;
		if (!rem) {
			break;
		}
	}
	return 0;
}

static int esl_img_wr_data(uint8_t img_idx, uint8_t *buf, uint16_t len)
{
	LOG_INF("%s img_idx:%d, len:%d", __func__, img_idx, len);

	ssize_t size;
	uint16_t rem = len;
	uint16_t nvs_id = NVS_ID_IMG_DATA_START(img_idx);
	for (uint8_t i = 0; i < IMG_STORAGE_SECTOR_MAX_NUM; i++) {
		uint16_t write_len =
			(rem > IMG_STORAGE_SECTOR_MAX_SIZE) ? IMG_STORAGE_SECTOR_MAX_SIZE : rem;
		size = nvs_write(&esl_storage, nvs_id + i, buf, write_len);
		if (size < 0) {
			LOG_ERR("%s err:%d", __func__, size);
			return size;
		}
		rem -= write_len;
		buf += write_len;
		if (!rem) {
			break;
		}
	}
	nvs_id = NVS_ID_IMG_SIZE_START(img_idx);
	size = nvs_write(&esl_storage, nvs_id, &len, sizeof(len));
	if (size < 0) {
		LOG_ERR("%s sz err:%d", __func__, size);
		return size;
	}
	LOG_INF("%s Write done:img_idx:%d, len:%d", __func__, img_idx, len);
	return 0;
}

static int esl_img_del_data(void)
{
	int err = 0;
	uint16_t nvs_id = NVS_ID_IMG_DATA_END(CONFIG_BT_ESLS_IMAGE_NUM - 1);
	for (uint8_t i = NVS_ID_IMG_START; i < nvs_id; i++) {
		int nvs_err = nvs_delete(&esl_storage, i);
		if (nvs_err) {
			LOG_ERR("%s nvs_id:%d err%d", __func__, i, nvs_err);
			err = nvs_err;
		}
	}

	return err;
}

void esl_img_init_img_info(struct bt_esls_init_param *init_param)
{
	esl_img_nvs_init();

	init_param->get_image_name = esl_img_get_img_name;
	init_param->write_image_data = esl_img_wr_data;
	init_param->read_image_data = esl_img_rd_data;
	init_param->read_image_size = esl_img_rd_size;
	init_param->delete_image_data = esl_img_del_data;
}
