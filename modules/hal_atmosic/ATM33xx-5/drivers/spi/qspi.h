/**
 *******************************************************************************
 *
 * @file qspi.h
 *
 * @brief QSPI driver
 *
 * Copyright (C) Atmosic 2018-2022
 *
 *******************************************************************************
 */

#ifndef __QSPI_H__
#define __QSPI_H__

/**
 * @defgroup QSPI QSPI
 * @ingroup DRIVERS
 * @brief User driver for QSPI master interface
 * @{
 */

#include <stdint.h>

#include "at_apb_qspi_regs_core_macro.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Begin QSPI transaction
 */
#ifndef __GNUC__
__INLINE void
#else
static inline void
#endif
qspi_drive_start(void)
{
    CMSDK_QSPI->TRANSACTION_SETUP = QSPI_TRANSACTION_SETUP__CSN_VAL__MASK;
}

/**
 * @brief Drive serial SPI command
 * @param[in] cmd 8-bit command to drive on DOUT_0
 */
#ifndef __GNUC__
__INLINE void
#else
static inline void
#endif
qspi_drive_serial_cmd(uint8_t cmd)
{
    for (int i=0; i<8; i++, cmd<<=1) {
	uint32_t oe = ((cmd & 0x80) ? 0x0003 : 0x0002)
	    << QSPI_TRANSACTION_SETUP__DOUT_0_CTRL__SHIFT;

	CMSDK_QSPI->TRANSACTION_SETUP = oe;
	CMSDK_QSPI->TRANSACTION_SETUP = oe |
	    QSPI_TRANSACTION_SETUP__CLK_VAL__MASK;
    }
}

/**
 * @brief Read SPI input for 8 cycles
 * @return read byte
 */
#ifndef CFG_ROM
__INLINE uint8_t
qspi_read_serial_byte(void)
{
    uint8_t data = 0;
    for (uint8_t i = 0x80; i; i >>= 1) {
	CMSDK_QSPI->TRANSACTION_SETUP = 0;
	CMSDK_QSPI->TRANSACTION_SETUP = QSPI_TRANSACTION_SETUP__CLK_VAL__MASK;
	CMSDK_QSPI->TRANSACTION_SETUP = QSPI_TRANSACTION_SETUP__CLK_VAL__MASK |
	    QSPI_TRANSACTION_SETUP__SAMPLE_DIN__WRITE(0x02);

	if (CMSDK_QSPI->READ_DATA & 0x02) {
	    data |= i;
	}
    }
    return (data);
}
#endif

/**
 * @brief Convert nibble to OE/val format for TRANSACTION_SETUP register
 * @param[in] nibble 4-bit value to convert
 * @return OE/val format for TRANSACTION_SETUP register
 */
#ifndef __GNUC__
__INLINE uint32_t
to_oe_format_quad(uint8_t nibble)
{
    if (nibble > 0xf) {
	return 0;
    }
    return (0x2222 | (nibble & 0x1) | ((nibble & 0x2) << 3) |
	((nibble & 0x4) << 6) | ((nibble & 0x8) << 9));
}
#else
static inline uint32_t
to_oe_format_quad(uint8_t nibble)
{
    switch (nibble) {
	case 0x0: return 0x2222;
	case 0x1: return 0x2223;
	case 0x2: return 0x2232;
	case 0x3: return 0x2233;
	case 0x4: return 0x2322;
	case 0x5: return 0x2323;
	case 0x6: return 0x2332;
	case 0x7: return 0x2333;
	case 0x8: return 0x3222;
	case 0x9: return 0x3223;
	case 0xa: return 0x3232;
	case 0xb: return 0x3233;
	case 0xc: return 0x3322;
	case 0xd: return 0x3323;
	case 0xe: return 0x3332;
	case 0xf: return 0x3333;
	default: break;
    }
    return 0;
}
#endif

/**
 * @brief Drive all QSPI outputs for a single cycle
 * @param[in] nibble 4-bit value to drive
 */
#ifndef __GNUC__
__INLINE void
#else
static inline void
#endif
qspi_drive_nibble(uint8_t nibble)
{
    uint32_t oe = to_oe_format_quad(nibble)
	<< QSPI_TRANSACTION_SETUP__DOUT_0_CTRL__SHIFT;
    CMSDK_QSPI->TRANSACTION_SETUP = oe;
    CMSDK_QSPI->TRANSACTION_SETUP = QSPI_TRANSACTION_SETUP__CLK_VAL__MASK | oe;
}

/**
 * @brief Drive all QSPI outputs for two cycles
 * @param[in] byte 8-bit value to drive
 */
#ifndef __GNUC__
__INLINE void
#else
static inline void
#endif
qspi_drive_byte(uint8_t byte)
{
    qspi_drive_nibble((byte & 0xf0) >> 4);
    qspi_drive_nibble(byte & 0x0f);
}

/**
 * @brief Drive dummy cycles on QSPI bus
 * @param[in] cycles Number of dummy cycles to drive
 */
#ifndef __GNUC__
__INLINE void
#else
static inline void
#endif
qspi_dummy(uint8_t cycles)
{
    for (; cycles; cycles--) {
	CMSDK_QSPI->TRANSACTION_SETUP = 0;
	CMSDK_QSPI->TRANSACTION_SETUP = QSPI_TRANSACTION_SETUP__CLK_VAL__MASK;
    }
}

/**
 * @brief Read all QSPI inputs for two cycles
 */
#ifndef __GNUC__
__INLINE void
#else
static inline void
#endif
qspi_capture_byte(void)
{
    CMSDK_QSPI->TRANSACTION_SETUP = 0;
    CMSDK_QSPI->TRANSACTION_SETUP = QSPI_TRANSACTION_SETUP__CLK_VAL__MASK;
    CMSDK_QSPI->TRANSACTION_SETUP = QSPI_TRANSACTION_SETUP__CLK_VAL__MASK |
	QSPI_TRANSACTION_SETUP__SAMPLE_DIN__WRITE(0xf0);

    CMSDK_QSPI->TRANSACTION_SETUP = 0;
    CMSDK_QSPI->TRANSACTION_SETUP = QSPI_TRANSACTION_SETUP__CLK_VAL__MASK;
    CMSDK_QSPI->TRANSACTION_SETUP = QSPI_TRANSACTION_SETUP__CLK_VAL__MASK |
	QSPI_TRANSACTION_SETUP__SAMPLE_DIN__WRITE(0x0f);
}

/**
 * @brief End QSPI transaction
 */
#ifndef __GNUC__
__INLINE void
#else
static inline void
#endif
qspi_drive_stop(void)
{
    CMSDK_QSPI->TRANSACTION_SETUP = 0;
    CMSDK_QSPI->TRANSACTION_SETUP = QSPI_TRANSACTION_SETUP__CSN_VAL__MASK;
}

#ifdef __cplusplus
}
#endif

/// @} QSPI

#endif // __QSPI_H__
