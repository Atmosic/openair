/**
 ****************************************************************************************
 *
 * @file dma.h
 *
 * @brief DMA driver for memory copy
 *
 * Copyright (C) RivieraWaves 2009-2019
 *
 * Copyright (C) Atmosic 2020-2024
 *
 ****************************************************************************************
 */

#ifndef DMA_H_
#define DMA_H_

/**
 ****************************************************************************************
 * @addtogroup DMA
 * @ingroup DRIVERS
 * @brief DMA driver for memory copy
 *
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDES
 ****************************************************************************************
 */
#include <stdint.h>

/*
 * DEFINES
 ****************************************************************************************
 */

/// List of available DMA channels
enum dma_channels
{
    /// DMA Channel reserved for data path
    DMA_CHAN_DATA_PATH = 0,
    /// DMA Channel available for other operation
    DMA_CHAN_UNUSED,

    DMA_CHAN_MAX,
};

enum dma_fifo_rx_port {
    DMA_FIFO_RX_UART0 = 0,
    DMA_FIFO_RX_UART1 = 1,
    DMA_FIFO_RX_PDM0 = 2,
    DMA_FIFO_RX_PDM1 = 3,
    DMA_FIFO_RX_I2S = 4,
    DMA_FIFO_RX_RSVD = 5,
};

enum dma_fifo_tx_port {
    DMA_FIFO_TX_UART0 = 0,
    DMA_FIFO_TX_UART1 = 1,
    DMA_FIFO_TX_RSVD = 2,
    DMA_FIFO_TX_RSVD1 = 3,
    DMA_FIFO_TX_I2S = 4,
    DMA_FIFO_TX_PWM = 5,
};

typedef void (*dma_cb_t)(void const *ctx);

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

void *dma_memcpy(void *d, const void *s, size_t n);
void *dma_memset(void *m, int c, size_t n);

void dma_fifo_rx_async(enum dma_fifo_rx_port port, void *dst, size_t len,
    dma_cb_t cb, void const *ctx);
void dma_fifo_tx_async(enum dma_fifo_tx_port port, const void *src, size_t len,
    dma_cb_t cb, void const *ctx);

/**
 * @brief Request an address to address memory copy using a DMA block (non blocking).
 *
 * If this function is called while DMA channel is in use, function is blocked till DMA channel is released
 *
 * @param[in] channel       DMA channel used (@see enum dma_channels)
 * @param[in] p_dst_addr    Destination address of the memory copy
 * @param[in] p_src_addr    Source address of the memory copy
 * @param[in] size          Size of data to copy in octets.
 */
void dma_copy(uint8_t channel, void* p_dst_addr, const void* p_src_addr, uint16_t size);

/**
 * @brief Fetch power management status
 * @param[in,out] min_freq  Minimum frequency required by pending operations
 * @return Avoid power saving modes when true
 */
bool dma_is_active(uint32_t *min_freq);

/// @} DMA

#endif // DMA_H_
