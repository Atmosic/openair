/**
 *******************************************************************************
 *
 * @file spi.h
 *
 * @brief SPI driver
 *
 * Copyright (C) Atmosic 2018-2023
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup SPI SPI
 * @ingroup DRIVERS
 * @brief User driver for SPI master interface
 * @{
 */

#include <stdbool.h>
#include <stdint.h>

#include "at_apb_spi_regs_core_macro.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Device structure
typedef struct spi_dev_s {
    CMSDK_AT_APB_SPI_TypeDef *base;
    uint16_t clkdiv;
    uint8_t dummy_cycles;
} spi_dev_t;

/// SPI2 device, 8MHz clk, no dummy cycles
extern
#if defined(CFG_ROM) || defined(CFG_USER)
const
#endif
spi_dev_t spi2_8MHz_0;

/// SPI interface to PMU
extern
#if defined(CFG_ROM) || defined(CFG_USER)
const
#endif
spi_dev_t spi_pmu;

/// SPI interface to RADIO
extern
#if defined(CFG_ROM) || defined(CFG_USER)
const
#endif
spi_dev_t spi_radio;

/**
 * @brief Base function for all SPI transactions.
 * @param[in] spi            Device structure.
 * @param[in] csn_stays_low  State of select at end of transaction.
 * @param[in] opcode         First byte written to bus by master.
 * @param[in] num_data_bytes Total bytes in transaction.
 * @param[in] upper          Upper 4 bytes to read/write.
 * @param[in] lower          Lower 4 bytes to read/write.
 */
#ifdef CFG_ROM
static inline
#else
__INLINE
#endif
void
do_spi_transaction(const spi_dev_t *spi, bool csn_stays_low,
    uint8_t opcode, uint8_t num_data_bytes, uint32_t upper, uint32_t lower)
{
    uint32_t transaction =
	SPI_TRANSACTION_SETUP__DUMMY_CYCLES__WRITE(spi->dummy_cycles) |
	SPI_TRANSACTION_SETUP__CSN_STAYS_LOW__WRITE(csn_stays_low) |
	SPI_TRANSACTION_SETUP__OPCODE__WRITE(opcode) |
	SPI_TRANSACTION_SETUP__CLKDIV__WRITE(spi->clkdiv) |
	SPI_TRANSACTION_SETUP__RWB__MASK |
	SPI_TRANSACTION_SETUP__NUM_DATA_BYTES__WRITE(num_data_bytes);

    spi->base->DATA_BYTES_LOWER = lower;
    spi->base->DATA_BYTES_UPPER = upper;
#ifdef SPI_TRANS_WFI
    spi->base->RESET_INTERRUPT = SPI_RESET_INTERRUPT__WRITE;
    spi->base->RESET_INTERRUPT = 0;
    IPSR_Type psr = {.w = __get_IPSR()};
    // check if we can use WFI
    //   - Not in an interrupt handler
    //   - Only when interrupts are enabled by the driver constructor
    bool can_use_wfi = !psr.b.ISR && NVIC_GetEnableIRQ(SPI_PMU_IRQn);
    if (can_use_wfi) {
	spi->base->INTERRUPT_MASK = SPI_INTERRUPT_MASK__WRITE;
    }
#endif
    spi->base->TRANSACTION_SETUP = transaction;
    spi->base->TRANSACTION_SETUP = transaction |
	SPI_TRANSACTION_SETUP__START__MASK;

#ifdef SPI_TRANS_WFI
    if (!can_use_wfi) {
	// can't use WFI at the moment
	while (spi->base->TRANSACTION_STATUS &
	    SPI_TRANSACTION_STATUS__RUNNING__MASK) {
	    YIELD();
	}
    } else {
	WFI_COND(!(spi->base->TRANSACTION_STATUS &
	    SPI_TRANSACTION_STATUS__RUNNING__MASK));
    }
    spi->base->INTERRUPT_MASK = 0;
#else
    while (spi->base->TRANSACTION_STATUS &
	SPI_TRANSACTION_STATUS__RUNNING__MASK) {
	YIELD();
    }
#endif
}

/**
 * @brief Read addressed single byte from SPI slave device.
 * @param[in] spi    Device structure.
 * @param[in] opcode Single byte opcode/address of data to read.
 * @return Data read from SPI slave device.
 */
uint8_t spi_read(const spi_dev_t *spi, uint8_t opcode);

/**
 * @brief Read addressed 2 bytes from SPI slave device.
 * @param[in] spi    Device structure.
 * @param[in] opcode Single byte opcode/address of data to read.
 * @return Data read from SPI slave device.
 */
uint16_t spi_read_2(const spi_dev_t *spi, uint8_t opcode);

/**
 * @brief Read addressed 3 bytes from SPI slave device.
 * @param[in] spi    Device structure.
 * @param[in] opcode Single byte opcode/address of data to read.
 * @return Data read from SPI slave device.
 */
uint32_t spi_read_3(const spi_dev_t *spi, uint8_t opcode);

/**
 * @brief Read addressed 4 bytes from SPI slave device.
 * @param[in] spi    Device structure.
 * @param[in] opcode Single byte opcode/address of data to read.
 * @return Data read from SPI slave device.
 */
uint32_t spi_read_4(const spi_dev_t *spi, uint8_t opcode);


/**
 * @brief Write addressed single byte to SPI slave device.
 * @param[in] spi    Device structure.
 * @param[in] opcode Single byte opcode/address of data to write.
 * @param[in] data   Data to write to SPI slave device.
 */
void spi_write(const spi_dev_t *spi, uint8_t opcode, uint8_t data);

/**
 * @brief Write addressed 2 bytes to SPI slave device.
 * @param[in] spi    Device structure.
 * @param[in] opcode Single byte opcode/address of data to write.
 * @param[in] data   Data to write to SPI slave device.
 */
void spi_write_2(const spi_dev_t *spi, uint8_t opcode, uint16_t data);

/**
 * @brief Write addressed 3 bytes to SPI slave device.
 * @param[in] spi    Device structure.
 * @param[in] opcode Single byte opcode/address of data to write.
 * @param[in] data   Data to write to SPI slave device.
 */
void spi_write_3(const spi_dev_t *spi, uint8_t opcode, uint32_t data);

/**
 * @brief Write addressed 4 bytes to SPI slave device.
 * @param[in] spi    Device structure.
 * @param[in] opcode Single byte opcode/address of data to write.
 * @param[in] data   Data to write to SPI slave device.
 */
void spi_write_4(const spi_dev_t *spi, uint8_t opcode, uint32_t data);


/**
 * @brief Read PMU or RADIO module register.
 * @param[in] spi   Device structure.
 * @param[in] block Single byte module block to read.
 * @param[in] addr  Single byte address of data to read.
 * @return Data read from PMU or RADIO module.
 */
uint32_t spi_pmuradio_read_word(const spi_dev_t *spi, uint8_t block, uint8_t addr);

/**
 * @brief Write PMU or RADIO module register.
 * @param[in] spi   Device structure.
 * @param[in] block Single byte module block to write.
 * @param[in] addr  Single byte address of data to write.
 * @param[in] data  Data to write to PMU or RADIO module.
 */
void spi_pmuradio_write_word(const spi_dev_t *spi, uint8_t block, uint8_t addr, uint32_t data);

#ifndef VERIFY_SPI_CAL
#define VERIFY_SPI_CAL PLF_DEBUG
#endif

#define SPR_READ(__d, __m, __reg) \
    spi_pmuradio_read_word(__d, __m ## __REG_BLADDR, __m ## __ ##  __reg)

#if VERIFY_SPI_CAL
#define SPR_VERIFY(__d, __m, __reg, __val) do { \
    uint32_t read_back = SPR_READ(__d, __m, __reg); \
    ASSERT_INFO((__val) == read_back, (__val), read_back); \
} while (0)
#else
#define SPR_VERIFY(__d, __m, __reg, __val) do {} while (0)
#endif

#define SPR_WRITE(__d, __m, __reg, __val) do { \
    uint32_t tmp_val = (__val); \
    spi_pmuradio_write_word(__d, __m ## __REG_BLADDR, __m ## __ ## __reg, \
	tmp_val); \
    SPR_VERIFY(__d, __m, __reg, tmp_val); \
} while (0)

#define PMU_READ(__m, __reg) SPR_READ(&spi_pmu, PMU_ ## __m, __reg)
#define PMU_VERIFY(__m, __reg, __val) \
    SPR_VERIFY(&spi_pmu, PMU_ ## __m, __reg, __val)
#define PMU_WRITE(__m, __reg, __val) \
    SPR_WRITE(&spi_pmu, PMU_ ## __m, __reg, __val)

#define SWREG_READ(__m, __reg) SPR_READ(&spi_pmu, SWREG_ ## __m, __reg)
#define SWREG_WRITE(__m, __reg, __val) \
    SPR_WRITE(&spi_pmu, SWREG_ ## __m, __reg, __val)

#define PMU_GADC_READ(__reg) PMU_READ(GADC, __reg)
#define PMU_GADC_WRITE(__reg, __val) PMU_WRITE(GADC, __reg, __val)

#define PMU_SWREG_READ(__reg) PMU_READ(SWREG, __reg)
#define PMU_SWREG_WRITE(__reg, __val) PMU_WRITE(SWREG, __reg, __val)

#define PMU_TOP_READ(__reg) PMU_READ(TOP, __reg)
#define PMU_TOP_WRITE(__reg, __val) PMU_WRITE(TOP, __reg, __val)

#define PMU_WURX_READ(__reg) PMU_READ(WURX, __reg)
#define PMU_WURX_WRITE(__reg, __val) PMU_WRITE(WURX, __reg, __val)

#define RADIO_READ(__m, __reg) SPR_READ(&spi_radio, RADIO_ ## __m, __reg)
#define RADIO_VERIFY(__m, __reg, __val) \
    SPR_VERIFY(&spi_radio, RADIO_ ## __m, __reg, __val)
#define RADIO_WRITE(__m, __reg, __val) \
    SPR_WRITE(&spi_radio, RADIO_ ## __m, __reg, __val)

#define RADIO_RX_READ(__reg) RADIO_READ(RX, __reg)
#define RADIO_RX_WRITE(__reg, __val) RADIO_WRITE(RX, __reg, __val)

#define RADIO_SYNTH_READ(__reg) RADIO_READ(SYNTH, __reg)
#define RADIO_SYNTH_WRITE(__reg, __val) RADIO_WRITE(SYNTH, __reg, __val)

#define RADIO_TOP_READ(__reg) RADIO_READ(TOP, __reg)
#define RADIO_TOP_WRITE(__reg, __val) RADIO_WRITE(TOP, __reg, __val)

#ifdef __cplusplus
}
#endif

/// @} SPI
