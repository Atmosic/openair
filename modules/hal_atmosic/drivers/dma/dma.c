/**
 *******************************************************************************
 *
 * @file dma.c
 *
 * @brief DMA driver
 *
 * Copyright (C) Atmosic 2020-2025
 *
 *******************************************************************************
 */

#ifdef __ICCARM__
#define __AS_BOUNDS__
#endif

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#ifdef CONFIG_ATM_DMA_RELOC_SRAM
#include <kernel_internal.h>
#endif
#include <soc.h>
#include <zephyr/init.h>
#ifdef CONFIG_PM
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#endif
#endif // CONFIG_SOC_FAMILY_ATM

#include "arch.h"
#include <inttypes.h>
#include <string.h>
#include <stdint.h>
#include "dma.h"
#ifndef CFG_DMA_MINIMAL
#include "atm_utils_c.h"
#include "vectors.h"
#if CFG_DMA_COPY
#include "em_map.h"
#endif
#include "at_clkrstgen.h"
#endif
#include "at_ahb_dma_regs_core_macro.h"


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

__STATIC_FORCEINLINE
void *dma_memcpy_inline(void *d, const void *s, size_t n)
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

#ifdef CONFIG_ATM_DMA_RELOC_SRAM
void z_early_memcpy(void *d, const void *s, size_t n)
{
    (void) dma_memcpy_inline(d, s, n);
}

__ramfunc
#endif
void *dma_memcpy(void *d, const void *s, size_t n)
{
    return dma_memcpy_inline(d, s, n);
}

#ifndef CONFIG_USERSPACE
// Override libc memcpy()
void *memcpy(void *d, const void *s, size_t n)
    __attribute__((alias("dma_memcpy")));
#endif

__STATIC_FORCEINLINE
void *dma_memset_inline(void *m, int c, size_t n)
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

#ifdef CONFIG_ATM_DMA_RELOC_SRAM
void z_early_memset(void *m, int c, size_t n)
{
    (void) dma_memset_inline(m, c, n);
}

__ramfunc
#endif
void *dma_memset(void *m, int c, size_t n)
{
    return dma_memset_inline(m, c, n);
}

#ifndef CONFIG_USERSPACE
// Override libc memset()
void *memset(void *m, int c, size_t n)
    __attribute__((alias("dma_memset")));
#endif

// minimal DMA only supports memcpy/memset for basic functionality
#ifndef CFG_DMA_MINIMAL
#if CFG_DMA_COPY
/*
 * Access to EM must be done at or above 16MHz
 */
#define EM_MIN_FREQ 16000000
static bool is_em_addr(void const *addr)
{
    return (((uintptr_t)addr & 0xffff8000) == EM_BASE_ADDR);
}
#endif

#ifdef CONFIG_ATM_DMA_FIFO_RX
static volatile dma_cb_t chan2_cb;
static void const *chan2_ctx;

void DMA2_Handler(void)
{
    uint32_t int_stat = CMSDK_AT_DMA->CHAN2_INTERRUPT_STATUS;
    if (!int_stat) {
	DEBUG_TRACE("Spurious DMA2 interrupt");
	ASSERT_ERR(0);
	return;
    }

    ASSERT_INFO(!AT_DMA_CHAN2_INTERRUPT_STATUS__DMA_ERR__READ(int_stat),
	int_stat, CMSDK_AT_DMA->CHAN2_ERR_STAT);
    chan2_cb(chan2_ctx);
    CMSDK_AT_DMA->CHAN2_RESET_INTERRUPT = AT_DMA_RESET_INTERRUPT__WRITE;
    chan2_cb = NULL;
}
#endif

static volatile dma_cb_t chan3_cb;
static void const *chan3_ctx;

#ifdef CONFIG_SOC_FAMILY_ATM
static K_SEM_DEFINE(dma_tx_sem, 1, 1);
#endif
void DMA3_Handler(void)
{
    uint32_t int_stat = CMSDK_AT_DMA->CHAN3_INTERRUPT_STATUS;
    if (!int_stat) {
	DEBUG_TRACE("Spurious DMA3 interrupt");
	ASSERT_ERR(0);
	return;
    }

    ASSERT_INFO(!AT_DMA_CHAN3_INTERRUPT_STATUS__DMA_ERR__READ(int_stat),
	int_stat, CMSDK_AT_DMA->CHAN3_ERR_STAT);
    dma_cb_t cb = chan3_cb;
    CMSDK_AT_DMA->CHAN3_RESET_INTERRUPT = AT_DMA_RESET_INTERRUPT__WRITE;
    chan3_cb = NULL;
#ifdef CONFIG_SOC_FAMILY_ATM
#ifdef CONFIG_PM
    pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
#endif
    k_sem_give(&dma_tx_sem);
#endif // CONFIG_SOC_FAMILY_ATM
    if (cb) {
	cb(chan3_ctx);
    }
}

static void dma_dummy_callback(void const *ctx)
{
}

#ifdef CONFIG_ATM_DMA_FIFO_RX
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
#ifdef CMSDK_PDM1_NONSECURE
    [DMA_FIFO_RX_PDM1] = {
	CMSDK_PDM1_PP_NONSECURE_BASE,
	AT_DMA_SRC_CTRL__SRC_BUS_SIZE__WRITE(4) |
	    AT_DMA_SRC_CTRL__SRC_TYPE__WRITE(1),
	(uint32_t)&CMSDK_PDM1_NONSECURE->BUFFER_DEPTH
    },
#endif
    [DMA_FIFO_RX_I2S] = {
	(uint32_t)&CMSDK_I2S_NONSECURE->I2S_PP1_RDATA,
	AT_DMA_SRC_CTRL__SRC_BUS_SIZE__WRITE(4) |
	    AT_DMA_SRC_CTRL__SRC_TYPE__WRITE(1),
	(uint32_t)&CMSDK_I2S_NONSECURE->BUFFER_DEPTH
    },
#ifdef CMSDK_AT_UART2_NONSECURE
    [DMA_FIFO_RX_UART2] = {
	(uint32_t)&CMSDK_AT_UART2_NONSECURE->DATA,
	AT_DMA_SRC_CTRL__SRC_BUS_SIZE__WRITE(1) |
	    AT_DMA_SRC_CTRL__SRC_TYPE__WRITE(1),
	(uint32_t)&CMSDK_AT_UART2_NONSECURE->RX_FIFO_ENTRIES
    },
#endif
};

static uint32_t chan2_min_freq;

void dma_fifo_rx_async(enum dma_fifo_rx_port port, void *dst, size_t len,
    dma_cb_t cb, void const *ctx)
{
    ASSERT_INFO(port < ARRAY_LEN(dma_rx_port), port, cb);
#if defined(WRPRPINS_PIPE_LINE_CTRL__PIPE_LINE_EN__READ) && \
    !defined(AT_DMA_OPMODE__BURST_MODE_N__MASK)
    ASSERT_ERR(!WRPRPINS_PIPE_LINE_CTRL__PIPE_LINE_EN__READ(
	CMSDK_WRPR0_NONSECURE->PIPE_LINE_CTRL));
#endif

    if (!cb) {
	cb = dma_dummy_callback;
    }

    // Wait for any previous transaction and award exactly one winner
    WFI_COND(!chan2_cb && ((chan2_cb = cb), true));

    chan2_ctx = ctx;
#if CFG_DMA_COPY
    chan2_min_freq = is_em_addr(dst) ? EM_MIN_FREQ : 0;
#else
    chan2_min_freq = 0;
#endif

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
#endif // CONFIG_ATM_DMA_FIFO_RX

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
	AT_DMA_TAR_CTRL__TAR_BUS_SIZE__WRITE(2) |
	    AT_DMA_TAR_CTRL__TAR_TYPE__WRITE(1),
	(uint32_t)&CMSDK_I2S_NONSECURE->BUFFER_DEPTH
    },
    [DMA_FIFO_TX_PWM] = {
	(uint32_t)&CMSDK_PWM_NONSECURE->FIFO_DATA,
	AT_DMA_TAR_CTRL__TAR_BUS_SIZE__WRITE(2) |
	    AT_DMA_TAR_CTRL__TAR_TYPE__WRITE(1),
	(uint32_t)&CMSDK_PWM_NONSECURE->FIFO_STAT1,
    },
#ifdef CMSDK_AT_UART2_NONSECURE
    [DMA_FIFO_TX_UART2] = {
	(uint32_t)&CMSDK_AT_UART2_NONSECURE->DATA,
	AT_DMA_TAR_CTRL__TAR_BUS_SIZE__WRITE(1) |
	    AT_DMA_TAR_CTRL__TAR_TYPE__WRITE(1),
	(uint32_t)&CMSDK_AT_UART2_NONSECURE->TX_FIFO_SPACES
    },
#endif
};

static uint32_t chan3_min_freq;

void dma_fifo_tx_async(enum dma_fifo_tx_port port, const void *src, size_t len,
    dma_cb_t cb, void const *ctx)
{
    ASSERT_INFO(port < ARRAY_LEN(dma_tx_port), port, cb);
#if defined(WRPRPINS_PIPE_LINE_CTRL__PIPE_LINE_EN__READ) && \
    !defined(AT_DMA_OPMODE__BURST_MODE_N__MASK)
    ASSERT_ERR(!WRPRPINS_PIPE_LINE_CTRL__PIPE_LINE_EN__READ(
	CMSDK_WRPR0_NONSECURE->PIPE_LINE_CTRL));
#endif

    if (!cb) {
	cb = dma_dummy_callback;
    }

#ifdef CONFIG_SOC_FAMILY_ATM
    k_sem_take(&dma_tx_sem, K_FOREVER);
    chan3_cb = cb;
#else
    // Wait for any previous transaction and award exactly one winner
    WFI_COND(!chan3_cb && ((chan3_cb = cb), true));
#endif

    chan3_ctx = ctx;
#if CFG_DMA_COPY
    chan3_min_freq = is_em_addr(src) ? EM_MIN_FREQ : 0;
#else
    chan3_min_freq = 0;
#endif

    CMSDK_AT_DMA->CHAN3_SRC_ADDR = (uint32_t)src;
    CMSDK_AT_DMA->CHAN3_TAR_ADDR = dma_tx_port[port].tar_addr;
    CMSDK_AT_DMA->CHAN3_SIZE = len;
    CMSDK_AT_DMA->CHAN3_SRC_CTRL = 0;
    CMSDK_AT_DMA->CHAN3_TAR_CTRL = dma_tx_port[port].tar_ctrl;
    CMSDK_AT_DMA->CHAN3_FIFO_DPTH_ADDR = dma_tx_port[port].fifo_dpth_addr;
    CMSDK_AT_DMA->CHAN3_FIFO_PORT_SEL =
	AT_DMA_FIFO_PORT_SEL__TAR_PORT_SEL__WRITE(port);

#if defined(CONFIG_SOC_FAMILY_ATM) && defined(CONFIG_PM)
    pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
#endif
    CMSDK_AT_DMA->CHAN3_OPMODE = AT_DMA_OPMODE__GO__MASK;
}

#if CFG_DMA_COPY
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
#endif // CFG_DMA_COPY

#ifndef CONFIG_SOC_FAMILY_ATM
static rep_vec_err_t
dma_prevent_retention(bool *prevent, int32_t *pseq_dur, int32_t ble_dur)
{
    if (
#if CFG_DMA_COPY
	CMSDK_AT_DMA->CHAN1_STATUS ||
#endif
	AT_DMA_CHAN2_STATUS__RUNNING__READ(CMSDK_AT_DMA->CHAN2_STATUS) ||
	CMSDK_AT_DMA->CHAN3_STATUS) {
	*prevent = true;
	return (RV_DONE);
    }

    return (RV_NEXT);
}

#if defined(WRPRPINS_PIPE_LINE_CTRL__PIPE_LINE_EN__READ) && \
    !defined(AT_DMA_OPMODE__BURST_MODE_N__MASK)
static uint32_t dma_chan2_save_rem, dma_chan2_save_size;

static rep_vec_err_t
dma_enter_retention(bool *sleep, int32_t duration, uint32_t *int_set)
{
    if (CMSDK_AT_DMA->CHAN2_STATUS) {
	// Stop the operation
	CMSDK_AT_DMA->CHAN2_INTERRUPT_MASK = 0;
	dma_chan2_save_size = CMSDK_AT_DMA->CHAN2_SIZE;
	ASSERT_ERR(dma_chan2_save_size);
	CMSDK_AT_DMA->CHAN2_SIZE = 0;
	dma_chan2_save_rem = CMSDK_AT_DMA->CHAN2_TOTAL_WRITE_REMAINDER;
	CMSDK_AT_DMA->CHAN2_OPMODE = AT_DMA_OPMODE__GO__MASK;
    }

    return RV_NEXT;
}

static rep_vec_err_t
dma_exit_retention(void)
{
    if (dma_chan2_save_size) {
	// Resume the operation
	ASSERT_INFO(dma_chan2_save_size >= dma_chan2_save_rem,
	    dma_chan2_save_size, dma_chan2_save_rem);
	uint32_t sent = dma_chan2_save_size - dma_chan2_save_rem;
	if (sent) {
	    CMSDK_AT_DMA->CHAN2_TAR_ADDR += sent;
	}
	CMSDK_AT_DMA->CHAN2_SIZE = dma_chan2_save_rem;
	CMSDK_AT_DMA->CHAN2_RESET_INTERRUPT = AT_DMA_RESET_INTERRUPT__WRITE;
	CMSDK_AT_DMA->CHAN2_OPMODE = AT_DMA_OPMODE__GO__MASK;
	CMSDK_AT_DMA->CHAN2_INTERRUPT_MASK = AT_DMA_INTERRUPT_MASK__WRITE;
    }

    return RV_NEXT;
}
#endif
#endif // !CONFIG_SOC_FAMILY_ATM

#if !defined(CONFIG_SOC_FAMILY_ATM) || defined(CONFIG_PM)
#ifdef CONFIG_ATM_DMA_RELOC_SRAM
__ramfunc
#endif
static rep_vec_err_t dma_bp_throttle(uint32_t bp_freq, uint32_t *min_freq)
{
#if CFG_DMA_COPY
    if (CMSDK_AT_DMA->CHAN1_STATUS) {
	if (*min_freq < chan1_min_freq) {
	    *min_freq = chan1_min_freq;
	}
    }
#endif
#ifdef CONFIG_ATM_DMA_FIFO_RX
    if (CMSDK_AT_DMA->CHAN2_STATUS) {
	if (*min_freq < chan2_min_freq) {
	    *min_freq = chan2_min_freq;
	}
    }
#endif
    if (CMSDK_AT_DMA->CHAN3_STATUS) {
	if (*min_freq < chan3_min_freq) {
	    *min_freq = chan3_min_freq;
	}
    }

    return (RV_NEXT);
}
#endif // CONFIG_PM

#ifdef DEBUG_DMA
static rep_vec_err_t dma_schedule(void)
{
#if CFG_DMA_COPY
    static uint32_t last_dma_copy_cnt, last_dma_wait_cnt, last_dma_go_cnt;

    if (last_dma_copy_cnt != dma_copy_cnt) {
	DEBUG_TRACE("dma_copy_cnt was %" PRIu32 " now %" PRIu32,
	    last_dma_copy_cnt, dma_copy_cnt);
	last_dma_copy_cnt = dma_copy_cnt;
    }
    if (last_dma_wait_cnt != dma_wait_cnt) {
	DEBUG_TRACE("dma_wait_cnt was %" PRIu32 " now %" PRIu32,
	    last_dma_wait_cnt, dma_wait_cnt);
	last_dma_wait_cnt = dma_wait_cnt;
    }
    if (last_dma_go_cnt != dma_go_cnt) {
	DEBUG_TRACE("dma_go_cnt was %" PRIu32 " now %" PRIu32,
	    last_dma_go_cnt, dma_go_cnt);
	last_dma_go_cnt = dma_go_cnt;
    }
#endif

    return (RV_NEXT);
}
#endif // DEBUG_DMA

#ifndef CONFIG_SOC_FAMILY_ATM
__attribute__((constructor))
#endif
static void dma_constructor(void)
{
#ifdef AT_DMA_REV_HASH__RESET_VALUE
    ASSERT_INFO(CMSDK_AT_DMA->REV_HASH == AT_DMA_REV_HASH__RESET_VALUE,
	CMSDK_AT_DMA->REV_HASH, AT_DMA_REV_HASH__RESET_VALUE);
#endif

#if CFG_DMA_COPY
    // Mark done so first transaction won't wait
    CMSDK_AT_DMA->CHAN1_SET_INTERRUPT = AT_DMA_INTERRUPT_STATUS__DMA_DONE__MASK;
#endif

    CMSDK_AT_DMA->CHAN2_RESET_INTERRUPT = AT_DMA_RESET_INTERRUPT__WRITE;
    CMSDK_AT_DMA->CHAN2_INTERRUPT_MASK = AT_DMA_INTERRUPT_MASK__WRITE;
    CMSDK_AT_DMA->CHAN3_RESET_INTERRUPT = AT_DMA_RESET_INTERRUPT__WRITE;
    CMSDK_AT_DMA->CHAN3_INTERRUPT_MASK = AT_DMA_INTERRUPT_MASK__WRITE;

    NVIC_ClearPendingIRQ(DMA2_IRQn);
    NVIC_ClearPendingIRQ(DMA3_IRQn);
    NVIC_SetPriority(DMA2_IRQn, IRQ_PRI_MID);
    NVIC_SetPriority(DMA3_IRQn, IRQ_PRI_MID);
    NVIC_EnableIRQ(DMA2_IRQn);
    NVIC_EnableIRQ(DMA3_IRQn);

#ifndef CONFIG_SOC_FAMILY_ATM
    RV_PLF_PREVENT_RETENTION_ADD(dma_prevent_retention);
#if defined(WRPRPINS_PIPE_LINE_CTRL__PIPE_LINE_EN__READ) && \
    !defined(AT_DMA_OPMODE__BURST_MODE_N__MASK)
    RV_PLF_RETAIN_ALL_ADD(dma_enter_retention);
    RV_PLF_BACK_FROM_RETAIN_ALL_ADD(dma_exit_retention);
#endif
#endif // !CONFIG_SOC_FAMILY_ATM

#if !defined(CONFIG_SOC_FAMILY_ATM) || defined(CONFIG_PM)
    RV_PLF_BP_THROTTLE_ADD(dma_bp_throttle);
#endif

#ifdef DEBUG_DMA
    RV_PLF_SCHEDULE_ADD(dma_schedule);
#endif
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int dma_sys_init(void)
{
#ifdef CONFIG_ATM_DMA_FIFO_RX
    Z_ISR_DECLARE(DMA2_IRQn, 0, DMA2_Handler, NULL);
#endif
    Z_ISR_DECLARE(DMA3_IRQn, 0, DMA3_Handler, NULL);
    dma_constructor();
    return 0;
}

SYS_INIT(dma_sys_init, PRE_KERNEL_2, 10);
#endif
#endif // CFG_DMA_MINIMAL
