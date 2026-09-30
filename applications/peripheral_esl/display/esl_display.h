/*
 *******************************************************************************
 *
 * @file esl_display.h
 *
 * @brief Electronic Shelf Label Service Display Header File
 *
 * Copyright (c) 2024-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

/**
 * @brief Initializes the ESL information characteristics.
 *
 * This function initializes the ESL displayinformation characteristics
 * by setting the characteristic values.
 *
 * @param init_param A pointer to a bt_esls_init_param struct containing
 * initialization parameters for the Bluetooth Electronic Shelf Label (ESL).
 */
void esl_display_init_dsp_info(struct bt_esls_init_param *init_param);

/**
 * @brief Initializes the display hardware.
 *
 * This function initializes the display hardware and returns an error code
 * if the initialization fails.
 *
 * @return 0 if the initialization is successful, or a negative error code
 * if the initialization fails.
 */
int esl_display_init(void);
