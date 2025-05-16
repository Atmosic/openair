/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#ifdef CONFIG_ATM_FIFO_TX_ISR
/**
 * @brief Get the pre-allocated buffer for I2S ATM driver
 *
 * @param dev Pointer to the device structure for the driver instance
 * @retval Pointer to the buffer
 *         or NULL if no buffer is available
 */
void *i2s_atm_get_tx_buffer(struct device const *dev);

/**
 * @brief Get the size of the pre-allocated buffer for I2S ATM driver
 *
 * @param dev Pointer to the device structure for the driver instance
 * @retval Size of the buffer
 */
const int i2s_atm_get_tx_buffer_size(struct device const *dev);

/**
 * @brief Register a callback for when all buffers are available.
 *
 * @param dev Pointer to the device structure for the driver instance
 * @param cb Callback function to be called when all buffers are available.
 */
void i2s_atm_reg_tx_write_cb(struct device const *dev,
			     void (*cb)(struct device const *dev, void *ctx), void *ctx);
#endif
