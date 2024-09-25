/**
 *******************************************************************************
 *
 * @file dma.c
 *
 * @brief ATM DMA driver
 *
 * Copyright (C) Atmosic 2020-2024
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#endif

#include "arch.h"
#include <string.h>
#include <stdint.h>
#ifndef CFG_DMA_MINIMAL
#include "co_utils.h"
#include "vectors.h"
#include "em_map.h"
#endif
#include "at_ahb_dma_regs_core_macro.h"
#include "dma.h"


// Debugs - to enable, change undef to define
#undef DEBUG_DMA


#ifdef CMSDK_AT_DMA_NONSECURE
#define CMSDK_AT_DMA	CMSDK_AT_DMA_NONSECURE
#endif

#define DMA_SIZE_LIMIT	((1 << AT_DMA_SIZE__SIZE__WIDTH) - 4)

#ifdef SECURE_MODE
// allow DMA to access secure memory
#define DMA_SEC_CFG_ALLOW_SECURE() do { \
    uint32_t _saved_cfg_hnonsec = CMSDK_AT_DMA_SECURE->CFG_HNONSEC; \
    AT_DMA_CFG_HNONSEC__CFG_HNONSEC__CLR(CMSDK_AT_DMA_SECURE->CFG_HNONSEC) \

#define DMA_SEC_CFG_RESTORE() \
    CMSDK_AT_DMA_SECURE->CFG_HNONSEC = _saved_cfg_hnonsec; \
} while (0)
#else
#define DMA_SEC_CFG_ALLOW_SECURE() do {} while (0)
#define DMA_SEC_CFG_RESTORE() do {} while (0)
#endif

void *
dma_memcpy(void *d, const void *s, size_t n)
{
    ASSERT_INFO(n <= DMA_SIZE_LIMIT, n, DMA_SIZE_LIMIT);

    uint32_t int_stat;
    uint32_t err_stat;
    GLOBAL_INT_DISABLE();
    DMA_SEC_CFG_ALLOW_SECURE();
    CMSDK_AT_DMA->SRC_ADDR = (uintptr_t)s;
    CMSDK_AT_DMA->TAR_ADDR = (uintptr_t)d;
    CMSDK_AT_DMA->SIZE = n;

    CMSDK_AT_DMA->RESET_INTERRUPT = AT_DMA_RESET_INTERRUPT__WRITE;

    CMSDK_AT_DMA->OPMODE = AT_DMA_OPMODE__GO__MASK;

    for (;;) {
	int_stat = CMSDK_AT_DMA->INTERRUPT_STATUS;
	if (int_stat) {
	    break;
	}
	YIELD();
    }

    err_stat = CMSDK_AT_DMA->ERR_STAT;

    DMA_SEC_CFG_RESTORE();
    GLOBAL_INT_RESTORE();

    if (err_stat) {
	if (AT_DMA_ERR_STAT__SIZE_0__READ(err_stat)) {
	    return d;
	}

	if (AT_DMA_ERR_STAT__ADDR_OVLP__READ(err_stat)) {
	    // Can't copy overlapping buffers; use libc's memmove
	    return (memmove(d, s, n));
	}

	DEBUG_TRACE("dma_memcpy(%p, %p, %u)", d, s, n);
	ASSERT_INFO(0, int_stat, err_stat);
    } else if (AT_DMA_INTERRUPT_STATUS__DMA_ERR__READ(int_stat)) {
	DEBUG_TRACE("dma_memcpy(%p, %p, %u)", d, s, n);
	ASSERT_INFO(0, int_stat, err_stat);
    }

    return d;
}

#if !defined(CONFIG_MINIMAL_LIBC) && !defined(CONFIG_USERSPACE)
// Override libc memcpy()
void *memcpy(void *d, const void *s, size_t n)
    __attribute__((alias("dma_memcpy")));
#endif

void *
dma_memset(void *m, int c, size_t n)
{
    uintptr_t addr = (uintptr_t)m;
    unsigned int d = (unsigned char)c;
    unsigned long buf = (d << 8) | d;
    buf |= (buf << 16);

    do {
	size_t sz = (n > DMA_SIZE_LIMIT) ? DMA_SIZE_LIMIT : n;
	uint32_t int_stat;
	__UNUSED uint32_t err_stat;
	GLOBAL_INT_DISABLE();
	DMA_SEC_CFG_ALLOW_SECURE();
	CMSDK_AT_DMA->CONST_WDATA = buf;
	CMSDK_AT_DMA->TAR_ADDR = addr;
	CMSDK_AT_DMA->SIZE = sz;

	CMSDK_AT_DMA->RESET_INTERRUPT = AT_DMA_RESET_INTERRUPT__WRITE;

	CMSDK_AT_DMA->OPMODE = AT_DMA_OPMODE__GO__MASK |
			       AT_DMA_OPMODE__CONST_TRANS__MASK;

	addr += sz;
	n -= sz;

	for (;;) {
	    int_stat = CMSDK_AT_DMA->INTERRUPT_STATUS;
	    if (int_stat) {
		break;
	    }
	    YIELD();
	}

	err_stat = CMSDK_AT_DMA->ERR_STAT;

	DMA_SEC_CFG_RESTORE();
	GLOBAL_INT_RESTORE();

	if (err_stat) {
	    if (AT_DMA_ERR_STAT__SIZE_0__READ(err_stat)) {
		return m;
	    }

	    DEBUG_TRACE("dma_memset(%p, %d, %u)", m, c, n);
	    ASSERT_INFO(0, int_stat, err_stat);
	} else if (AT_DMA_INTERRUPT_STATUS__DMA_ERR__READ(int_stat)) {
	    DEBUG_TRACE("dma_memset(%p, %d, %u)", m, c, n);
	    ASSERT_INFO(0, int_stat, err_stat);
	}
    } while (n);

    return m;
}

#if !defined(CONFIG_MINIMAL_LIBC) && !defined(CONFIG_USERSPACE)
// Override libc memset()
void *memset(void *m, int c, size_t n)
    __attribute__((alias("dma_memset")));
#endif

// minimal DMA only supports memcpy/memset for basic functionality
#ifndef CFG_DMA_MINIMAL
/*
 * Access to EM must be done at or above 16MHz
 */
#define EM_MIN_FREQ 16000000
static bool is_em_addr(void const *addr)
{
    return (((uintptr_t)addr & 0xffff8000) == EM_BASE_ADDR);
}

static volatile dma_cb_t chan2_cb;
static void const *chan2_ctx;

void DMA2_Handler(void)
{
    uint32_t int_stat = CMSDK_AT_DMA->CHAN2_INTERRUPT_STATUS;
    if (int_stat) {
	ASSERT_INFO(!AT_DMA_CHAN2_INTERRUPT_STATUS__DMA_ERR__READ(int_stat),
	    int_stat, CMSDK_AT_DMA->CHAN2_ERR_STAT);
	chan2_cb(chan2_ctx);
	CMSDK_AT_DMA->CHAN2_RESET_INTERRUPT = AT_DMA_RESET_INTERRUPT__WRITE;
	chan2_cb = NULL;
    } else {
	DEBUG_TRACE("Spurious DMA2 interrupt");
	ASSERT_ERR(0);
    }
}

static volatile dma_cb_t chan3_cb;
static void const *chan3_ctx;

void DMA3_Handler(void)
{
    uint32_t int_stat = CMSDK_AT_DMA->CHAN3_INTERRUPT_STATUS;
    if (int_stat) {
	ASSERT_INFO(!AT_DMA_CHAN3_INTERRUPT_STATUS__DMA_ERR__READ(int_stat),
	    int_stat, CMSDK_AT_DMA->CHAN3_ERR_STAT);
	chan3_cb(chan3_ctx);
	CMSDK_AT_DMA->CHAN3_RESET_INTERRUPT = AT_DMA_RESET_INTERRUPT__WRITE;
	chan3_cb = NULL;
    } else {
	DEBUG_TRACE("Spurious DMA3 interrupt");
	ASSERT_ERR(0);
    }
}

static void dma_dummy_callback(void const *ctx)
{
}

static struct {
    uint32_t src_addr;
    uint32_t src_ctrl;
    uint32_t fifo_dpth_addr;
} const dma_rx_port[] = {
    [DMA_FIFO_RX_UART0] = {
	(uint32_t)&CMSDK_AT_UART0_NONSECURE->DATA,
	AT_DMA_SRC_CTRL__SRC_BUS_SIZE__WRITE(1) |
	    AT_DMA_SRC_CTRL__SRC_TYPE__WRITE(1),
	(uint32_t)&CMSDK_AT_UART0_NONSECURE->RX_FIFO_ENTRIES
    },
    [DMA_FIFO_RX_UART1] = {
	(uint32_t)&CMSDK_AT_UART1_NONSECURE->DATA,
	AT_DMA_SRC_CTRL__SRC_BUS_SIZE__WRITE(1) |
	    AT_DMA_SRC_CTRL__SRC_TYPE__WRITE(1),
	(uint32_t)&CMSDK_AT_UART1_NONSECURE->RX_FIFO_ENTRIES
    },
    [DMA_FIFO_RX_PDM0] = {
	CMSDK_PDM0_PP_NONSECURE_BASE,
	AT_DMA_SRC_CTRL__SRC_BUS_SIZE__WRITE(4) |
	    AT_DMA_SRC_CTRL__SRC_TYPE__WRITE(1),
	(uint32_t)&CMSDK_PDM0_NONSECURE->BUFFER_DEPTH
    },
    [DMA_FIFO_RX_PDM1] = {
	CMSDK_PDM1_PP_NONSECURE_BASE,
	AT_DMA_SRC_CTRL__SRC_BUS_SIZE__WRITE(4) |
	    AT_DMA_SRC_CTRL__SRC_TYPE__WRITE(1),
	(uint32_t)&CMSDK_PDM1_NONSECURE->BUFFER_DEPTH
    },
    [DMA_FIFO_RX_I2S] = {
	(uint32_t)&CMSDK_I2S_NONSECURE->I2S_PP1_RDATA,
	AT_DMA_SRC_CTRL__SRC_BUS_SIZE__WRITE(4) |
	    AT_DMA_SRC_CTRL__SRC_TYPE__WRITE(1),
	(uint32_t)&CMSDK_I2S_NONSECURE->BUFFER_DEPTH
    },
};

static uint32_t chan2_min_freq;

void dma_fifo_rx_async(enum dma_fifo_rx_port port, void *dst, size_t len,
    dma_cb_t cb, void const *ctx)
{
    ASSERT_INFO(port < ARRAY_LEN(dma_rx_port), port, cb);

    if (!cb) {
	cb = dma_dummy_callback;
    }

    // Wait for any previous transaction and award exactly one winner
    WFI_COND(!chan2_cb && ((chan2_cb = cb), true));

    chan2_ctx = ctx;
    chan2_min_freq = is_em_addr(dst) ? EM_MIN_FREQ : 0;

    CMSDK_AT_DMA->CHAN2_SRC_ADDR = dma_rx_port[port].src_addr;
    CMSDK_AT_DMA->CHAN2_TAR_ADDR = (uint32_t)dst;
    CMSDK_AT_DMA->CHAN2_SIZE = len;
    CMSDK_AT_DMA->CHAN2_SRC_CTRL = dma_rx_port[port].src_ctrl;
    CMSDK_AT_DMA->CHAN2_TAR_CTRL = 0;
    CMSDK_AT_DMA->CHAN2_FIFO_DPTH_ADDR = dma_rx_port[port].fifo_dpth_addr;
    CMSDK_AT_DMA->CHAN2_FIFO_PORT_SEL =
	AT_DMA_FIFO_PORT_SEL__SRC_PORT_SEL__WRITE(port);

    CMSDK_AT_DMA->CHAN2_OPMODE = AT_DMA_OPMODE__GO__MASK;
}

static struct {
    uint32_t tar_addr;
    uint32_t tar_ctrl;
    uint32_t fifo_dpth_addr;
} const dma_tx_port[] = {
    [DMA_FIFO_TX_UART0] = {
	(uint32_t)&CMSDK_AT_UART0_NONSECURE->DATA,
	AT_DMA_TAR_CTRL__TAR_BUS_SIZE__WRITE(1) |
	    AT_DMA_TAR_CTRL__TAR_TYPE__WRITE(1),
	(uint32_t)&CMSDK_AT_UART0_NONSECURE->TX_FIFO_SPACES
    },
    [DMA_FIFO_TX_UART1] = {
	(uint32_t)&CMSDK_AT_UART1_NONSECURE->DATA,
	AT_DMA_TAR_CTRL__TAR_BUS_SIZE__WRITE(1) |
	    AT_DMA_TAR_CTRL__TAR_TYPE__WRITE(1),
	(uint32_t)&CMSDK_AT_UART1_NONSECURE->TX_FIFO_SPACES
    },
    [DMA_FIFO_TX_I2S] = {
	(uint32_t)&CMSDK_I2S_NONSECURE->I2S_PP0_WDATA,
	AT_DMA_TAR_CTRL__TAR_BUS_SIZE__WRITE(4) |
	    AT_DMA_TAR_CTRL__TAR_TYPE__WRITE(1),
	(uint32_t)&CMSDK_I2S_NONSECURE->BUFFER_DEPTH
    },
    [DMA_FIFO_TX_PWM] = {
	(uint32_t)&CMSDK_PWM_NONSECURE->FIFO_DATA,
	AT_DMA_TAR_CTRL__TAR_BUS_SIZE__WRITE(2) |
	    AT_DMA_TAR_CTRL__TAR_TYPE__WRITE(1),
	(uint32_t)&CMSDK_PWM_NONSECURE->FIFO_STAT1,
    },
};

static uint32_t chan3_min_freq;

void dma_fifo_tx_async(enum dma_fifo_tx_port port, const void *src, size_t len,
    dma_cb_t cb, void const *ctx)
{
    ASSERT_INFO(port < ARRAY_LEN(dma_tx_port), port, cb);

    if (!cb) {
	cb = dma_dummy_callback;
    }

    // Wait for any previous transaction and award exactly one winner
    WFI_COND(!chan3_cb && ((chan3_cb = cb), true));

    chan3_ctx = ctx;
    chan3_min_freq = is_em_addr(src) ? EM_MIN_FREQ : 0;

    CMSDK_AT_DMA->CHAN3_SRC_ADDR = (uint32_t)src;
    CMSDK_AT_DMA->CHAN3_TAR_ADDR = dma_tx_port[port].tar_addr;
    CMSDK_AT_DMA->CHAN3_SIZE = len;
    CMSDK_AT_DMA->CHAN3_SRC_CTRL = 0;
    CMSDK_AT_DMA->CHAN3_TAR_CTRL = dma_tx_port[port].tar_ctrl;
    CMSDK_AT_DMA->CHAN3_FIFO_DPTH_ADDR = dma_tx_port[port].fifo_dpth_addr;
    CMSDK_AT_DMA->CHAN3_FIFO_PORT_SEL =
	AT_DMA_FIFO_PORT_SEL__TAR_PORT_SEL__WRITE(port);

    CMSDK_AT_DMA->CHAN3_OPMODE = AT_DMA_OPMODE__GO__MASK;
}

#ifdef DEBUG_DMA
static uint32_t dma_copy_cnt, dma_wait_cnt, dma_go_cnt;
#endif

static uint32_t chan1_min_freq;

void dma_copy(uint8_t channel, void *p_dst_addr, const void *p_src_addr,
    uint16_t size)
{
#ifdef DEBUG_DMA
    dma_copy_cnt++;
#endif
    ASSERT_INFO(channel == DMA_CHAN_DATA_PATH, channel, DMA_CHAN_DATA_PATH);

    // Wait for any previous transaction
    uint32_t int_stat;
    while (!(int_stat = CMSDK_AT_DMA->CHAN1_INTERRUPT_STATUS)) {
#ifdef DEBUG_DMA
	dma_wait_cnt++;
#endif
	YIELD();
    }
    ASSERT_INFO(!AT_DMA_CHAN1_INTERRUPT_STATUS__DMA_ERR__READ(int_stat),
	int_stat, CMSDK_AT_DMA->CHAN1_ERR_STAT);

    chan1_min_freq = (is_em_addr(p_dst_addr) || is_em_addr(p_src_addr)) ?
	EM_MIN_FREQ : 0;

    CMSDK_AT_DMA->CHAN1_SRC_ADDR = (uintptr_t)p_src_addr;
    CMSDK_AT_DMA->CHAN1_TAR_ADDR = (uintptr_t)p_dst_addr;
    CMSDK_AT_DMA->CHAN1_SIZE = size;

    CMSDK_AT_DMA->CHAN1_RESET_INTERRUPT = AT_DMA_RESET_INTERRUPT__WRITE;

    CMSDK_AT_DMA->CHAN1_OPMODE = AT_DMA_OPMODE__GO__MASK;

#ifdef DEBUG_DMA
    dma_go_cnt++;
#endif
}

static rep_vec_err_t
dma_prevent_retention(bool *prevent, int32_t *pseq_dur, int32_t ble_dur)
{
    if (CMSDK_AT_DMA->CHAN1_STATUS ||
	AT_DMA_CHAN2_STATUS__RUNNING__READ(CMSDK_AT_DMA->CHAN2_STATUS) ||
	CMSDK_AT_DMA->CHAN3_STATUS) {
        *prevent = true;
        return (RV_DONE);
    }

    return (RV_NEXT);
}

static rep_vec_err_t dma_bp_throttle(uint32_t bp_freq, uint32_t *min_freq)
{
    if (CMSDK_AT_DMA->CHAN1_STATUS) {
	if (*min_freq < chan1_min_freq) {
	    *min_freq = chan1_min_freq;
	}
    }
    if (CMSDK_AT_DMA->CHAN2_STATUS) {
	if (*min_freq < chan2_min_freq) {
	    *min_freq = chan2_min_freq;
	}
    }
    if (CMSDK_AT_DMA->CHAN3_STATUS) {
	if (*min_freq < chan3_min_freq) {
	    *min_freq = chan3_min_freq;
	}
    }

    return (RV_NEXT);
}

#ifdef DEBUG_DMA
static rep_vec_err_t dma_schedule(void)
{
    static uint32_t last_dma_copy_cnt, last_dma_wait_cnt, last_dma_go_cnt;

    if (last_dma_copy_cnt != dma_copy_cnt) {
	DEBUG_TRACE("dma_copy_cnt was %lu now %lu", last_dma_copy_cnt, dma_copy_cnt);
	last_dma_copy_cnt = dma_copy_cnt;
    }
    if (last_dma_wait_cnt != dma_wait_cnt) {
	DEBUG_TRACE("dma_wait_cnt was %lu now %lu", last_dma_wait_cnt, dma_wait_cnt);
	last_dma_wait_cnt = dma_wait_cnt;
    }
    if (last_dma_go_cnt != dma_go_cnt) {
	DEBUG_TRACE("dma_go_cnt was %lu now %lu", last_dma_go_cnt, dma_go_cnt);
	last_dma_go_cnt = dma_go_cnt;
    }

    return (RV_NEXT);
}
#endif

#ifndef CONFIG_SOC_FAMILY_ATM
__attribute__((constructor))
#endif
static void dma_constructor(void)
{
    // Mark done so first transaction won't wait
    CMSDK_AT_DMA->CHAN1_SET_INTERRUPT = AT_DMA_INTERRUPT_STATUS__DMA_DONE__MASK;

    CMSDK_AT_DMA->CHAN2_RESET_INTERRUPT = AT_DMA_RESET_INTERRUPT__WRITE;
    CMSDK_AT_DMA->CHAN2_INTERRUPT_MASK = AT_DMA_INTERRUPT_MASK__WRITE;
    CMSDK_AT_DMA->CHAN3_RESET_INTERRUPT = AT_DMA_RESET_INTERRUPT__WRITE;
    CMSDK_AT_DMA->CHAN3_INTERRUPT_MASK = AT_DMA_INTERRUPT_MASK__WRITE;

    NVIC_ClearPendingIRQ(DMA2_IRQn);
    NVIC_ClearPendingIRQ(DMA3_IRQn);
    NVIC_SetPriority(DMA2_IRQn, IRQ_PRI_HIGH);
    NVIC_SetPriority(DMA3_IRQn, IRQ_PRI_HIGH);
    NVIC_EnableIRQ(DMA2_IRQn);
    NVIC_EnableIRQ(DMA3_IRQn);

    RV_PLF_PREVENT_RETENTION_ADD(dma_prevent_retention);
    RV_PLF_BP_THROTTLE_ADD(dma_bp_throttle);

#ifdef DEBUG_DMA
    RV_PLF_SCHEDULE_ADD(dma_schedule);
#endif
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int dma_sys_init(void)
{
    Z_ISR_DECLARE(DMA2_IRQn, 0, DMA2_Handler, NULL);
    Z_ISR_DECLARE(DMA3_IRQn, 0, DMA3_Handler, NULL);
    dma_constructor();
    return 0;
}

SYS_INIT(dma_sys_init, PRE_KERNEL_2, 10);
#endif
#endif // CFG_DMA_MINIMAL
