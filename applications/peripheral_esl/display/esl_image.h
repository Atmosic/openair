/*
 *******************************************************************************
 *
 * @file esl_image.h
 *
 * @brief Electronic Shelf Label Service image Header File
 *
 * Copyright (c) 2024-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */
#define IMG_STORAGE_SECTOR_MAX_SIZE 1792

/**
 * @brief Initializes the ESL information characteristics.
 *
 * This function initializes the ESL image information characteristics
 * by setting the characteristic values.
 *
 * @param init_param A pointer to a bt_esls_init_param struct containing
 * initialization parameters for the Bluetooth Electronic Shelf Label (ESL).
 */
void esl_img_init_img_info(struct bt_esls_init_param *init_param);

/**
 * @brief Read ESL image data
 *
 * @param[in] img_idx index for image
 * @param[in] buf data buffer for reading
 * @param[in] offset image data offset,multiple of IMG_STORAGE_SECTOR_MAX_SIZE
 * @param[in] len data length
 * @return Zero in case of success and error code in case of error.
 */
int esl_img_rd_data(uint8_t img_idx, uint8_t *buf, uint16_t offset, uint16_t len);

/**
 * @brief Read ESL image size
 *
 * @param[in] img_idx index for image
 * @param[in] size image size
 * @return Zero in case of success and error code in case of error.
 */
int esl_img_rd_size(uint8_t img_idx, uint16_t *size);
