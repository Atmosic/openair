/*****************************************************************************************
*
* @file spi.c
*
* @brief Sydney 1.0 SPI driver
*
* Copyright (C) Atmosic 2018-2023
*
*
*****************************************************************************************/

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#endif

#include "arch.h"
#include "spi.h"
#include "pmu_spi.h"
#include "radio_spi.h"
#include "at_wrpr.h"
#include "at_apb_pseq_regs_core_macro.h"
#include "atm_bp_clock.h"

#if defined(CFG_ROM) || defined(CFG_USER)
const
#else
// Make certain this structure isn't located in flash
__attribute__((section(".data")))
#endif
spi_dev_t spi2_8MHz_0 = { CMSDK_SPI2, 0, 0 };

#if defined(CFG_ROM) || defined(CFG_USER)
const
#endif
spi_dev_t spi_pmu = { CMSDK_PMU, 0, PMU_SPI__DUMMY_CYCLES };

#if defined(CFG_ROM) || defined(CFG_USER)
const
#else
// Make certain this structure isn't located in flash
__attribute__((section(".data")))
#endif
spi_dev_t spi_radio = { CMSDK_RADIO, 0, RADIO_SPI__DUMMY_CYCLES };

uint8_t
spi_read(const spi_dev_t *spi, uint8_t opcode)
{
    do_spi_transaction(spi, 0, opcode, 1, 0x0, 0x0);
    return (spi->base->DATA_BYTES_LOWER);
}

uint16_t
spi_read_2(const spi_dev_t *spi, uint8_t opcode)
{
    do_spi_transaction(spi, 0, opcode, 2, 0x0, 0x0);
    return (spi->base->DATA_BYTES_LOWER);
}

uint32_t
spi_read_3(const spi_dev_t *spi, uint8_t opcode)
{
    do_spi_transaction(spi, 0, opcode, 3, 0x0, 0x0);
    return (spi->base->DATA_BYTES_LOWER & 0xffffff);
}

uint32_t
spi_read_4(const spi_dev_t *spi, uint8_t opcode)
{
    do_spi_transaction(spi, 0, opcode, 4, 0x0, 0x0);
    return (spi->base->DATA_BYTES_LOWER);
}

void
spi_write(const spi_dev_t *spi, uint8_t opcode, uint8_t data)
{
    do_spi_transaction(spi, 0, opcode, 1, 0x0, data);
}

void
spi_write_2(const spi_dev_t *spi, uint8_t opcode, uint16_t data)
{
    do_spi_transaction(spi, 0, opcode, 2, 0x0, data);
}

void
spi_write_3(const spi_dev_t *spi, uint8_t opcode, uint32_t data)
{
    do_spi_transaction(spi, 0, opcode, 3, 0x0, data);
}

void
spi_write_4(const spi_dev_t *spi, uint8_t opcode, uint32_t data)
{
    do_spi_transaction(spi, 0, opcode, 4, 0x0, data);
}

uint32_t
spi_pmuradio_read_word(const spi_dev_t *spi, uint8_t block, uint8_t addr)
{
    uint8_t opcode = block << 4;

    do_spi_transaction(spi, 0, opcode, 5, 0x0, addr);
    return ((spi->base->DATA_BYTES_UPPER << 24) |
	    (spi->base->DATA_BYTES_LOWER >> 8));
}

void
spi_pmuradio_write_word(const spi_dev_t *spi, uint8_t block, uint8_t addr,
			uint32_t data)
{
    uint8_t opcode = (block << 4) | 0x1;
    uint32_t lower = (data << 8) | addr;
    uint32_t upper = data >> 24;

    do_spi_transaction(spi, 0, opcode, 5, upper, lower);
}

#ifdef SPI_TRANS_WFI
#include "vectors.h"

__INLINE void spi_interrupt_handler(CMSDK_AT_APB_SPI_TypeDef *base)
{
    // Nothing to do here but clear the interrupt source.
    uint32_t status = base->INTERRUPT_STATUS;
    base->RESET_INTERRUPT = status;
    base->RESET_INTERRUPT = 0;
    // WFI will wake up and continue.
}

#ifndef OVERRIDE_SPI_ISR
void SPI0_Handler(void)
{
    spi_interrupt_handler(CMSDK_SPI0);
}

void SPI1_Handler(void)
{
    spi_interrupt_handler(CMSDK_SPI1);
}
#endif

void SPI2_Handler(void)
{
    spi_interrupt_handler(CMSDK_SPI2);
}

void SPI_RADIO_Handler(void)
{
    spi_interrupt_handler(CMSDK_RADIO);
}

void SPI_PMU_Handler(void)
{
    spi_interrupt_handler(CMSDK_PMU);
}

#ifdef PSEQ_CTRL0__SPI_LATCH_OPEN__CLR
__FAST
static void spi_pseq_latch_close(void)
{
    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE);
    {
	PSEQ_CTRL0__SPI_LATCH_OPEN__CLR(CMSDK_PSEQ->CTRL0);
    }
    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_DISABLE);
}

__FAST
static rep_vec_err_t spi_back_from_retain_all(void)
{
    spi_pseq_latch_close();
    return RV_NEXT;
}
#endif
#endif // SPI_TRANS_WFI

#ifndef CONFIG_SOC_FAMILY_ATM
__CONSTRUCTOR_PRIO(CONSTRUCTOR_SPI)
#endif
static void spi_constructor(void)
{
#if !(defined(CFG_ROM) || defined(CFG_USER))
    uint32_t bp_freq = atm_bp_clock_get();
    uint16_t clkdiv = (bp_freq / 16000000U) - 1;

    spi2_8MHz_0.clkdiv = spi_pmu.clkdiv = spi_radio.clkdiv = clkdiv;
#endif

#ifdef SPI_TRANS_WFI
    NVIC_EnableIRQ(SPI0_IRQn);
    NVIC_EnableIRQ(SPI1_IRQn);
    NVIC_EnableIRQ(SPI2_IRQn);
    NVIC_EnableIRQ(SPI_RADIO_IRQn);
    NVIC_EnableIRQ(SPI_PMU_IRQn);
#ifdef PSEQ_CTRL0__SPI_LATCH_OPEN__CLR
    RV_PLF_BACK_FROM_RETAIN_ALL_ADD(spi_back_from_retain_all);
#endif
#endif // SPI_TRANS_WFI
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int spi_sys_init(void)
{
    spi_constructor();
    return 0;
}

SYS_INIT(spi_sys_init, PRE_KERNEL_2, 2);
#endif
