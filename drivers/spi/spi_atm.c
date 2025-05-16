/*
 * Copyright (C) Atmosic 2021-2025
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT atmosic_atm_spi

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(spi_atm, CONFIG_SPI_LOG_LEVEL);

#include <zephyr/sys/sys_io.h>
#include <zephyr/device.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/sys/math_extras.h>
#ifdef CONFIG_PM
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#endif
#include <soc.h>
#include <stdbool.h>
#include <inttypes.h>
#include "at_clkrstgen.h"

#include "spi_context.h"
#include "arch.h"
#include "at_wrpr.h"
#include "at_pinmux.h"
#include "at_apb_spi_regs_core_macro.h"
#ifdef CONFIG_SOC_SERIES_ATMX2
#include "intisr.h"
#define INTR_ROUTING_REQUIRED 1
#endif
#ifdef CONFIG_SPI_ATM_DMA
#include "dma.h"
#endif

#define SPI_WORD_SIZE 8
#define SPI_CLK at_clkrstgen_get_bp()
#define SPI_CLK_DIV(freq) ((DIV_ROUND_UP(SPI_CLK, freq) >> 1) - 1)
#define SPI_CLK_MIN (SPI_CLK >> (SPI_TRANSACTION_SETUP__CLKDIV__WIDTH + 1))
#define SPI_CORE_HARD_LIMIT_HZ 8000000
#define SPI_CLK_MAX MIN((SPI_CLK >> 1), SPI_CORE_HARD_LIMIT_HZ)
#define DEV_CFG(dev) ((struct spi_atm_config *)(dev)->config)
#define DEV_DATA(dev) ((struct spi_atm_data *)(dev)->data)
#define SPI_OPCODE(d) ((d)->io[0].tx)
#define SPI_DATA_SIZE(d) ((d)->num_bytes)
#define SPI_DATA_LOWER(d)                                                                          \
	(((d)->io[1].tx << 0) | ((d)->io[2].tx << 8) | ((d)->io[3].tx << 16) |                     \
	 ((d)->io[4].tx << 24))
#define SPI_DATA_UPPER(d)                                                                          \
	(((d)->io[5].tx << 0) | ((d)->io[6].tx << 8) | ((d)->io[7].tx << 16) |                     \
	 ((d)->io[8].tx << 24))
#define SPI_DATA_LOWER_WIDTH                                                                       \
	((SPI_DATA_BYTES_LOWER__BYTE0__WIDTH + SPI_DATA_BYTES_LOWER__BYTE1__WIDTH +                \
	  SPI_DATA_BYTES_LOWER__BYTE2__WIDTH + SPI_DATA_BYTES_LOWER__BYTE3__WIDTH) >>              \
	 3)
#define SPI_DATA_UPPER_WIDTH                                                                       \
	((SPI_DATA_BYTES_UPPER__BYTE4__WIDTH + SPI_DATA_BYTES_UPPER__BYTE5__WIDTH +                \
	  SPI_DATA_BYTES_UPPER__BYTE6__WIDTH + SPI_DATA_BYTES_UPPER__BYTE7__WIDTH) >>              \
	 3)
#define SPI_OPCODE_WIDTH (SPI_TRANSACTION_SETUP__OPCODE__WIDTH >> 3)
#define SPI_DATA_WIDTH (SPI_DATA_LOWER_WIDTH + SPI_DATA_UPPER_WIDTH)
#define SPI_PAYLOAD_WIDTH (SPI_OPCODE_WIDTH + SPI_DATA_WIDTH)
#define SPI_TXN_TIMEOUT_MULTIPLIER 50

#ifdef CONFIG_SPI_ATM_WATCHDOG
struct spi_atm_chunk_stats {
	int64_t start_time;
	int64_t end_time;
	uint64_t timeout;
};

#define SPI_ATM_CHUNKS_MAX 1024
#endif

struct spi_atm_data {
#ifdef CONFIG_SPI_ATM_DMA
	struct k_work tx_dma_work;
	struct device const *dev;
#endif
	struct spi_context ctx;
	struct shift {
		uint8_t tx;
		uint8_t *rx;
	} io[SPI_PAYLOAD_WIDTH];
	uint32_t num_bytes;
	bool read;
	struct k_sem completion_sem;
	spi_callback_t sync_cb;
#ifdef CONFIG_SPI_ATM_WATCHDOG
	struct k_timer txn_watchdog_timer;
	uint32_t chunk_index;
	struct spi_atm_chunk_stats chunk[SPI_ATM_CHUNKS_MAX];
	uint32_t busfreq;
	size_t tx_size;
	size_t rx_size;
	bool is_async;
	int64_t start_time;
	int64_t end_time;
#endif
};

typedef void (*set_callback_t)(void);

struct spi_atm_config {
	int dummy_cycles;
	CMSDK_AT_APB_SPI_TypeDef *base;
	set_callback_t config_pins;
	void (*irq_connect)(void);
#ifdef CONFIG_SPI_ATM_DMA
	IRQn_Type irqn;
	uint8_t port;
#endif
};

static int spi_atm_process_data(struct device const *dev)
{
	int ret = 0;
	struct spi_atm_data *data = DEV_DATA(dev);
	struct spi_atm_config const *aconfig = DEV_CFG(dev);

	for (int i = 0; i < SPI_PAYLOAD_WIDTH; i++) {
		if (data->io[i].rx) {
			uint8_t val = 0;
			switch (i) {
			case 0:
				val = SPI_TRANSACTION_STATUS__OPCODE_STATUS__READ(
					aconfig->base->TRANSACTION_STATUS);
				break;

			case 1:
				val = SPI_DATA_BYTES_LOWER__BYTE0__READ(
					aconfig->base->DATA_BYTES_LOWER);
				break;

			case 2:
				val = SPI_DATA_BYTES_LOWER__BYTE1__READ(
					aconfig->base->DATA_BYTES_LOWER);
				break;

			case 3:
				val = SPI_DATA_BYTES_LOWER__BYTE2__READ(
					aconfig->base->DATA_BYTES_LOWER);
				break;

			case 4:
				val = SPI_DATA_BYTES_LOWER__BYTE3__READ(
					aconfig->base->DATA_BYTES_LOWER);
				break;

			case 5:
				val = SPI_DATA_BYTES_UPPER__BYTE4__READ(
					aconfig->base->DATA_BYTES_UPPER);
				break;

			case 6:
				val = SPI_DATA_BYTES_UPPER__BYTE5__READ(
					aconfig->base->DATA_BYTES_UPPER);
				break;

			case 7:
				val = SPI_DATA_BYTES_UPPER__BYTE6__READ(
					aconfig->base->DATA_BYTES_UPPER);
				break;

			case 8:
				val = SPI_DATA_BYTES_UPPER__BYTE7__READ(
					aconfig->base->DATA_BYTES_UPPER);
				break;

			default:
				LOG_ERR("Invalid receive index. Received: %d", i);
				ret = -EINVAL;
			}

			if (!ret) {
				UNALIGNED_PUT(val, data->io[i].rx);
			}
		}
	}

	return ret;
}

static void spi_atm_start_transaction(struct device const *dev, uint16_t clkdiv, uint8_t dcycles,
				      bool csn)
{
	struct spi_atm_data *data = DEV_DATA(dev);
	LOG_DBG("SPI txn: %#x %#x %#x %d %d %d %d", SPI_OPCODE(data), SPI_DATA_LOWER(data),
		SPI_DATA_UPPER(data), SPI_DATA_SIZE(data), clkdiv, dcycles, csn);

	uint32_t transaction = SPI_TRANSACTION_SETUP__DUMMY_CYCLES__WRITE(dcycles) |
			       SPI_TRANSACTION_SETUP__CSN_STAYS_LOW__WRITE(csn) |
			       SPI_TRANSACTION_SETUP__OPCODE__WRITE(SPI_OPCODE(data)) |
			       SPI_TRANSACTION_SETUP__CLKDIV__WRITE(clkdiv) |
			       SPI_TRANSACTION_SETUP__RWB__MASK |
			       SPI_TRANSACTION_SETUP__NUM_DATA_BYTES__WRITE(SPI_DATA_SIZE(data));

#ifdef SPI_TRANSACTION_SETUP__LOOPBACK__SET
	struct spi_config const *config = data->ctx.config;
	bool loopback = (config->operation & SPI_MODE_LOOP);
	if (loopback) {
		SPI_TRANSACTION_SETUP__LOOPBACK__SET(transaction);
	}
#endif

	struct spi_atm_config const *aconfig = DEV_CFG(dev);
	aconfig->base->DATA_BYTES_LOWER = SPI_DATA_LOWER(data);
	aconfig->base->DATA_BYTES_UPPER = SPI_DATA_UPPER(data);
	aconfig->base->RESET_INTERRUPT = SPI_RESET_INTERRUPT__RESET_INTERRUPT0__MASK;
	aconfig->base->RESET_INTERRUPT = 0;
	aconfig->base->TRANSACTION_SETUP = transaction;
#ifdef CONFIG_SPI_ATM_DMA
	SPI_CTRL__DMA_MODE__CLR(aconfig->base->CTRL);
#endif
	aconfig->base->TRANSACTION_SETUP |= SPI_TRANSACTION_SETUP__START__MASK;
}

#ifdef CONFIG_PM
/* The pm_constraint functions below are called from both thread and isr contexts.  Normally, that
 * would require a critical section around accesses to pm_constraint_on, and that variable would
 * need to be volatile.  However, because of the spi context lock and the specific sequencing, the
 * critical section protection is not required here */
static bool pm_constraint_on;
static void spi_atm_pm_constraint_set(const struct device *dev)
{
	if (!pm_constraint_on) {
		pm_constraint_on = true;
		pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
		pm_policy_state_lock_get(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	}
}

static void spi_atm_pm_constraint_release(const struct device *dev)
{
	if (pm_constraint_on) {
		pm_constraint_on = false;
		pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
		pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	}
}
#endif /* CONFIG_PM */

#ifdef CONFIG_SPI_ATM_WATCHDOG
static void spi_atm_dump_stats(const struct device *dev)
{
	struct spi_atm_data *data = DEV_DATA(dev);
	LOG_INF("Async: %u, Clk: %u, TxS: %zu, RxS: %zu, Chunks: %u, Start: %" PRId64 ", Stop: %"
		PRId64, data->is_async, data->busfreq, data->tx_size, data->rx_size,
		data->chunk_index, data->start_time, data->end_time);
	for (uint32_t i = 0; i < data->chunk_index; i++) {
		LOG_INF("chunk %u: %" PRId64 " %" PRId64 " %" PRId64, i, data->chunk[i].start_time,
			data->chunk[i].end_time, data->chunk[i].timeout);
	}
}
#endif

static void spi_atm_context_lock(const struct device *dev,
				 bool asynchronous,
				 spi_callback_t callback,
				 void *callback_data,
				 const struct spi_config *spi_cfg)
{
	struct spi_atm_data *data = DEV_DATA(dev);
	spi_context_lock(&data->ctx, asynchronous, callback, callback_data, spi_cfg);
#ifdef CONFIG_PM
	spi_atm_pm_constraint_set(dev);
#endif

#ifdef CONFIG_SPI_ATM_WATCHDOG
	data->is_async = asynchronous;
	data->chunk_index = 0;
	data->tx_size = 0;
	data->rx_size = 0;
	data->start_time = k_uptime_ticks();
	data->end_time = 0;
#endif
}

static void spi_atm_context_unlock(const struct device *dev, bool complete, int status)
{
	struct spi_atm_data *data = DEV_DATA(dev);
#ifdef CONFIG_PM
	spi_atm_pm_constraint_release(dev);
#endif

#ifdef CONFIG_SPI_ATM_WATCHDOG
	data->end_time = k_uptime_ticks();
	if (status) {
		spi_atm_dump_stats(dev);
	}
#endif

	if (complete) {
		spi_context_complete(&data->ctx, dev, status);
	}
	spi_context_unlock_unconditionally(&data->ctx);
}

#ifdef CONFIG_SPI_ATM_WATCHDOG
static void spi_atm_txn_watchdog_start(struct device const *dev, size_t txn_len)
{
	struct spi_atm_data *data = DEV_DATA(dev);
	struct spi_config const *config = data->ctx.config;

	uint64_t expected_us = (uint64_t)DIV_ROUND_UP((uint64_t)txn_len * CHAR_BIT * 1000000,
						      config->frequency);
	k_timer_start(&data->txn_watchdog_timer, K_USEC(expected_us * SPI_TXN_TIMEOUT_MULTIPLIER),
		      K_NO_WAIT);
	struct spi_atm_chunk_stats *chunk = &data->chunk[data->chunk_index];
	chunk->start_time = k_uptime_ticks();
	chunk->timeout = expected_us * SPI_TXN_TIMEOUT_MULTIPLIER;
}
#endif

#ifdef CONFIG_SPI_ATM_DMA
static void spi_atm_tx_dma_worker(struct k_work *work)
{
	struct spi_atm_data *data = CONTAINER_OF(work, struct spi_atm_data, tx_dma_work);
	struct device const *dev = data->dev;
	struct spi_atm_config const *aconfig = DEV_CFG(dev);

	if (SPI_TRANSACTION_STATUS__RUNNING__READ(aconfig->base->TRANSACTION_STATUS)) {
		// Not done yet - try again
		k_work_submit(work);
		return;
	}

	// All done - kick off spi_atm_isr()
	NVIC_SetPendingIRQ(aconfig->irqn);
}

static void spi_atm_tx_dma_callback(void const *ctx)
{
	// DMA is done, but SPI transaction will likely still be running
	struct device const *dev = ctx;
	struct spi_atm_data *data = DEV_DATA(dev);

	// Poll for done, but not in this ISR context
	k_work_submit(&data->tx_dma_work);
}

static void spi_atm_dma_tx(struct device const *dev)
{
	struct spi_atm_data *data = DEV_DATA(dev);
	void const *dma_buf = data->ctx.tx_buf;
	size_t dma_len = data->ctx.tx_len;
	spi_context_update_tx(&data->ctx, 1, dma_len);

	LOG_DBG("SPI dma tx: %p %zu", dma_buf, dma_len);
	struct spi_atm_config const *aconfig = DEV_CFG(dev);
	SPI_TRANSACTION_SETUP__START__CLR(aconfig->base->TRANSACTION_SETUP);
	dma_spi_tx_async(aconfig->port, dma_buf, dma_len, spi_atm_tx_dma_callback, dev);

#ifdef CONFIG_SPI_ATM_WATCHDOG
	spi_atm_txn_watchdog_start(dev, dma_len);
#endif

	SPI_CTRL__DMA_MODE__SET(aconfig->base->CTRL);
}

#ifdef CONFIG_ATM_DMA_FIFO_RX
static void spi_atm_rx_dma_callback(void const *ctx)
{
	struct device const *dev = ctx;
	struct spi_atm_config const *aconfig = DEV_CFG(dev);

	// All done - kick off spi_atm_isr()
	NVIC_SetPendingIRQ(aconfig->irqn);
}

static void spi_atm_dma_rx(struct device const *dev)
{
	struct spi_atm_data *data = DEV_DATA(dev);
	void *dma_buf = data->ctx.rx_buf;
	size_t dma_len = data->ctx.rx_len;
	spi_context_update_rx(&data->ctx, 1, dma_len);

	LOG_DBG("SPI dma rx: %p %zu", dma_buf, dma_len);
	struct spi_atm_config const *aconfig = DEV_CFG(dev);
	SPI_TRANSACTION_SETUP__START__CLR(aconfig->base->TRANSACTION_SETUP);
	dma_spi_rx_async(aconfig->port, dma_buf, dma_len, spi_atm_rx_dma_callback, dev);

#ifdef CONFIG_SPI_ATM_WATCHDOG
	spi_atm_txn_watchdog_start(dev, dma_len);
#endif

	SPI_CTRL__DMA_MODE__SET(aconfig->base->CTRL);
}
#endif
#endif // CONFIG_SPI_ATM_DMA

static int spi_atm_transfer(struct device const *dev)
{
	struct spi_atm_data *data = DEV_DATA(dev);
	data->read = false;

#ifdef CONFIG_SPI_ATM_DMA
	if (!spi_context_rx_on(&data->ctx) && (data->ctx.tx_count == 1) && data->ctx.tx_buf &&
	    (data->ctx.tx_len > SPI_PAYLOAD_WIDTH)) {
		spi_atm_dma_tx(dev);
		return 0;
	}
#ifdef CONFIG_ATM_DMA_FIFO_RX
	if (!spi_context_tx_on(&data->ctx) && (data->ctx.rx_count == 1) && data->ctx.rx_buf &&
	    (data->ctx.rx_len > SPI_PAYLOAD_WIDTH)) {
		spi_atm_dma_rx(dev);
		return 0;
	}
#endif
#endif // CONFIG_SPI_ATM_DMA

	data->num_bytes = SPI_DATA_WIDTH;
	bool last = false;
	for (int i = 0; i < SPI_PAYLOAD_WIDTH; i++) {
		data->io[i].tx = 0;
		data->io[i].rx = NULL;
		if (last) {
			continue;
		}

		if (spi_context_tx_buf_on(&data->ctx)) {
			data->io[i].tx = UNALIGNED_GET(data->ctx.tx_buf);
		}
		spi_context_update_tx(&data->ctx, 1, 1);

		if (spi_context_rx_buf_on(&data->ctx)) {
			data->io[i].rx = data->ctx.rx_buf;
			data->read = true;
		}
		spi_context_update_rx(&data->ctx, 1, 1);

		if (!(spi_context_tx_on(&data->ctx) || spi_context_rx_on(&data->ctx))) {
			last = true;
			data->num_bytes = i;
		}
	}

	struct spi_atm_config const *aconfig = DEV_CFG(dev);
	uint8_t dcycles = (data->read) ? aconfig->dummy_cycles : 0;
	struct spi_config const *config = data->ctx.config;
	spi_atm_start_transaction(dev, SPI_CLK_DIV(config->frequency), dcycles, !last);

#ifdef CONFIG_SPI_ATM_WATCHDOG
	spi_atm_txn_watchdog_start(dev, SPI_PAYLOAD_WIDTH);
#endif

	aconfig->base->INTERRUPT_MASK = SPI_INTERRUPT_MASK__PASSTHRU0__MASK;

	return 0;
}

static void spi_atm_isr(const struct device *dev)
{
	struct spi_atm_config const *aconfig = DEV_CFG(dev);
	aconfig->base->INTERRUPT_MASK = 0;

	/* Process read data from the previous transfer */
	struct spi_atm_data *data = DEV_DATA(dev);
#ifdef CONFIG_SPI_ATM_WATCHDOG
	k_timer_stop(&data->txn_watchdog_timer);
#endif
	if (data->read) {
		spi_atm_process_data(dev);
	}

#ifdef CONFIG_SPI_ATM_WATCHDOG
	struct spi_atm_chunk_stats *chunk = &data->chunk[data->chunk_index];
	chunk->end_time = k_uptime_ticks();
	data->chunk_index++;
	if (data->chunk_index >= SPI_ATM_CHUNKS_MAX) {
		LOG_ERR("Overflow");
		data->chunk_index = 0;
	}
#endif

	if (spi_context_tx_on(&data->ctx) || spi_context_rx_on(&data->ctx)) {
		spi_atm_transfer(dev);
	} else {
		/* No more data, complete the ongoing transfer */
		if (data->sync_cb) {
			spi_callback_t cb = data->sync_cb;
			data->sync_cb = NULL;
			cb(dev, 0, NULL);
		}
		spi_atm_context_unlock(dev, true, 0);
	}
}

static void spi_atm_transceive_sync_cb(const struct device *dev, int result, void *ctxt)
{
	struct spi_atm_data *data = DEV_DATA(dev);
	k_sem_give(&data->completion_sem);
}

static int spi_atm_transceive(struct device const *dev,
			      struct spi_config const *config,
			      struct spi_buf_set const *tx_bufs,
			      struct spi_buf_set const *rx_bufs)
{
	if (SPI_WORD_SIZE_GET(config->operation) != SPI_WORD_SIZE) {
		LOG_ERR("Invalid word size. Received: %d", SPI_WORD_SIZE_GET(config->operation));
		return -ENOTSUP;
	}

	if (config->operation & SPI_CS_ACTIVE_HIGH) {
		LOG_ERR("Active high CS not supported");
		return -ENOTSUP;
	}

	if ((config->operation & SPI_LINES_MASK) != SPI_LINES_SINGLE) {
		LOG_ERR("MISO lines not supported. Received: %d",
			(config->operation & SPI_LINES_MASK));
		return -ENOTSUP;
	}

	if (config->operation & SPI_OP_MODE_SLAVE) {
		LOG_ERR("Slave mode not supported");
		return -ENOTSUP;
	}

	if ((config->frequency < SPI_CLK_MIN) || (config->frequency > SPI_CLK_MAX)) {
		LOG_ERR("Frequency not supported. Received: %d", config->frequency);
		return -ENOTSUP;
	}

	struct spi_atm_data *data = DEV_DATA(dev);
#ifdef CONFIG_SPI_ATM_WATCHDOG
	if (tx_bufs) {
		for (size_t i = 0; i < tx_bufs->count; i++) {
			data->tx_size += tx_bufs->buffers[i].len;
		}
	}
	if (rx_bufs) {
		for (size_t i = 0; i < rx_bufs->count; i++) {
			data->rx_size += rx_bufs->buffers[i].len;
		}
	}
	data->busfreq = config->frequency;
#endif
	data->ctx.config = config;
	spi_context_buffers_setup(&data->ctx, tx_bufs, rx_bufs, 1);

#ifndef SPI_TRANSACTION_SETUP__LOOPBACK__SET
	bool loopback = (config->operation & SPI_MODE_LOOP);
	struct spi_atm_config const *aconfig = DEV_CFG(dev);
	SPI_CTRL__LOOPBACK__MODIFY(aconfig->base->CTRL, loopback);
#endif

	return spi_atm_transfer(dev);
}

static int spi_atm_transceive_sync(struct device const *dev,
				   struct spi_config const *config,
				   struct spi_buf_set const *tx_bufs,
				   struct spi_buf_set const *rx_bufs)
{
	struct spi_atm_data *data = DEV_DATA(dev);
	spi_atm_context_lock(dev, false, NULL, NULL, config);
	k_sem_reset(&data->completion_sem);
	data->sync_cb = spi_atm_transceive_sync_cb;
	int ret = spi_atm_transceive(dev, config, tx_bufs, rx_bufs);
	if (ret) {
		spi_atm_context_unlock(dev, false, 0);
		return ret;
	}

	ret = k_sem_take(&data->completion_sem, K_FOREVER);
	if (ret) {
		struct spi_atm_config const *aconfig = DEV_CFG(dev);
		aconfig->base->TRANSACTION_SETUP = 0;
		LOG_ERR("SPI communication timed out: %#x", aconfig->base->TRANSACTION_STATUS);
		return -EIO;
	}

	return 0;
}

#ifdef CONFIG_SPI_ASYNC
static int spi_atm_transceive_async(struct device const *dev,
				    struct spi_config const *config,
				    struct spi_buf_set const *tx_bufs,
				    struct spi_buf_set const *rx_bufs,
				    spi_callback_t cb, void *userdata)
{
	spi_atm_context_lock(dev, true, cb, userdata, config);
	int ret = spi_atm_transceive(dev, config, tx_bufs, rx_bufs);
	if (ret) {
		spi_atm_context_unlock(dev, false, 0);
	}

	return ret;
}
#endif

static int spi_atm_release(struct device const *dev, struct spi_config const *config)
{
	struct spi_atm_data *data = DEV_DATA(dev);

	if (!spi_context_configured(&data->ctx, config)) {
		return -EINVAL;
	}

	spi_atm_context_unlock(dev, false, 0);

	return 0;
}

static struct spi_driver_api const spi_atm_driver_api = {
	.transceive = spi_atm_transceive_sync,
#ifdef CONFIG_SPI_ASYNC
	.transceive_async = spi_atm_transceive_async,
#endif
	.release = spi_atm_release,
};

#ifdef PSEQ_CTRL0__SPI_LATCH_OPEN__MASK
static void spi_pseq_latch_close(void)
{
	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		PSEQ_CTRL0__SPI_LATCH_OPEN__CLR(CMSDK_PSEQ->CTRL0);
	}
	WRPR_CTRL_POP();
}

#ifdef CONFIG_PM
static void notify_pm_state_exit(enum pm_state state)
{
	if (state == PM_STATE_SUSPEND_TO_RAM) {
		spi_pseq_latch_close();
	}
}

static struct pm_notifier notifier = {
	.state_entry = NULL,
	.state_exit = notify_pm_state_exit,
};
#endif
#endif // PSEQ_CTRL0__SPI_LATCH_OPEN__MASK

#ifdef CONFIG_SPI_ATM_WATCHDOG
static void txn_watchdog_timeout(struct k_timer *timer)
{
	struct device const *dev = k_timer_user_data_get(timer);
	struct spi_atm_config const *aconfig = DEV_CFG(dev);

	LOG_ERR("SPI asynchronous transaction timed out");

	// Disable further interrupts from the SPI peripheral
	aconfig->base->INTERRUPT_MASK = 0;

	// Reset the transaction setup to stop any ongoing hardware activity
	aconfig->base->TRANSACTION_SETUP = 0;

	spi_atm_context_unlock(dev, true, -ETIMEDOUT);
}
#endif

static int spi_atm_init(struct device const *dev)
{
	int err;
	struct spi_atm_config const *aconfig = DEV_CFG(dev);
	struct spi_atm_data *data = DEV_DATA(dev);

	aconfig->config_pins();
	err = spi_context_cs_configure_all(&data->ctx);
	if (err < 0) {
		return err;
	}
	spi_context_unlock_unconditionally(&data->ctx);

#ifdef PSEQ_CTRL0__SPI_LATCH_OPEN__MASK
	spi_pseq_latch_close();

#ifdef CONFIG_PM
	pm_notifier_register(&notifier);
#endif
#endif // PSEQ_CTRL0__SPI_LATCH_OPEN__MASK

#ifdef CONFIG_SPI_ATM_DMA
	k_work_init(&data->tx_dma_work, spi_atm_tx_dma_worker);
#endif
	k_sem_init(&data->completion_sem, 0, 1);
#ifdef CONFIG_SPI_ATM_WATCHDOG
	k_timer_init(&data->txn_watchdog_timer, txn_watchdog_timeout, NULL);
	k_timer_user_data_set(&data->txn_watchdog_timer, (void *)dev);
#endif
	aconfig->irq_connect();

	return 0;
}

#define SPI_SIG(n, sig) CONCAT(CONCAT(SPI, DT_INST_PROP(n, instance)), _##sig)
#define SPI_BASE(n) CONCAT(CMSDK_SPI, DT_INST_PROP(n, instance))
#define SPI_DEVICE_INIT(n)                                                                         \
	static void spi_atm_config_pins_##n(void)                                                  \
	{                                                                                          \
		/* Configure pinmux for the given intance */                                       \
		PIN_SELECT(DT_INST_PROP(n, cs_pin), SPI_SIG(n, CS));                               \
		PIN_SELECT(DT_INST_PROP(n, clk_pin), SPI_SIG(n, CLK));                             \
		IF_ENABLED(DT_INST_NODE_HAS_PROP(n, mosi_pin),					   \
			PIN_SELECT(DT_INST_PROP(n, mosi_pin), SPI_SIG(n, MOSI)));		   \
		IF_ENABLED(DT_INST_NODE_HAS_PROP(n, miso_pin),					   \
			PIN_SELECT(DT_INST_PROP(n, miso_pin), SPI_SIG(n, MISO)));		   \
		WRPR_CTRL_SET(SPI_BASE(n), WRPR_CTRL__CLK_ENABLE);                                 \
	}                                                                                          \
	ISR_DIRECT_DECLARE(spi_atm_isr##n)                                                         \
	{                                                                                          \
		struct device const *dev = DEVICE_DT_INST_GET(n);                                  \
		spi_atm_isr(dev);                                                                  \
		return 1;                                                                          \
	}                                                                                          \
	static void spi_atm_config_irq_##n(void)                                                   \
	{                                                                                          \
                IF_ENABLED(INTR_ROUTING_REQUIRED, (                                                \
			__IO uint32_t *INTRPT_CFG = ((&CMSDK_WRPR->INTRPT_CFG_0) +                 \
				DT_INST_IRQN(n));                                                  \
			*INTRPT_CFG = INTISR_SRC_SPI##n;                                           \
                ))                                                                                 \
		IRQ_DIRECT_CONNECT(DT_INST_IRQN(n), DT_INST_IRQ(n, priority), spi_atm_isr##n, 0);  \
		irq_enable(DT_INST_IRQN(n));                                                       \
	}											   \
	static struct spi_atm_config const spi_atm_config_##n = {                                  \
		.base = SPI_BASE(n),                                                               \
		.config_pins = spi_atm_config_pins_##n,                                            \
		.dummy_cycles = DT_INST_PROP(n, dummy_cycles),                                     \
		.irq_connect = spi_atm_config_irq_##n,                                             \
		IF_ENABLED(CONFIG_SPI_ATM_DMA, (						   \
			.irqn = DT_INST_IRQN(n),						   \
			.port = DT_INST_PROP(n, instance),					   \
		))										   \
	};                                                                                         \
	static struct spi_atm_data spi_atm_data_##n = {						   \
		IF_ENABLED(CONFIG_SPI_ATM_DMA, (						   \
			.dev = DEVICE_DT_INST_GET(n),						   \
		))										   \
		SPI_CONTEXT_INIT_LOCK(spi_atm_data_##n, ctx),					   \
		SPI_CONTEXT_INIT_SYNC(spi_atm_data_##n, ctx),					   \
	};											   \
	DEVICE_DT_INST_DEFINE(n, &spi_atm_init, NULL, &spi_atm_data_##n, &spi_atm_config_##n,      \
			      POST_KERNEL, CONFIG_SPI_INIT_PRIORITY, &spi_atm_driver_api);         \
	BUILD_ASSERT(SPI_BASE(n) == (CMSDK_AT_APB_SPI_TypeDef *)DT_REG_ADDR(DT_NODELABEL(          \
					    CONCAT(spi, DT_INST_PROP(n, instance)))));

DT_INST_FOREACH_STATUS_OKAY(SPI_DEVICE_INIT)
