/*****************************************************************************************
*
* @file spi_flash.c
*
* @brief Sydney 1.0 SPI flash driver
*
* Copyright (C) Atmosic 2019
*
*
*****************************************************************************************/

#include "arch.h"
#include "spi.h"
#include "spi_flash.h"

__NR_STATIC uint32_t
spi_flash_addr_to_lower(uint32_t addr)
{
    return (((addr & 0xff) << 16) |
	    ((addr & 0xff00) << 0) |
	    ((addr & 0xff0000) >> 16));
}

uint8_t
spi_flash_read_byte(const spi_dev_t *spi, uint32_t addr)
{
    const uint8_t opcode = 0x03;  // READ
    do_spi_transaction(spi, 0, opcode, 4, 0x0, spi_flash_addr_to_lower(addr));
    return (spi->base->DATA_BYTES_LOWER >> 24);
}

uint16_t
spi_flash_read_short(const spi_dev_t *spi, uint32_t addr)
{
    const uint8_t opcode = 0x03;  // READ
    do_spi_transaction(spi, 0, opcode, 5, 0x0, spi_flash_addr_to_lower(addr));
    return (((spi->base->DATA_BYTES_UPPER & 0xff) << 8) |
	    (spi->base->DATA_BYTES_LOWER >> 24));
}

uint32_t
spi_flash_read_word(const spi_dev_t *spi, uint32_t addr)
{
    const uint8_t opcode = 0x03;  // READ
    do_spi_transaction(spi, 0, opcode, 7, 0x0, spi_flash_addr_to_lower(addr));
    return ((spi->base->DATA_BYTES_UPPER << 8) |
	    (spi->base->DATA_BYTES_LOWER >> 24));
}

__NR_STATIC uint8_t
spi_flash_wait_for_no_wip(const spi_dev_t *spi)
{
    uint8_t ret;

    // FIXME: timeout
    for (;;) {
	ret = spi_read(spi, 0x05);  // READ STATUS
	if (!(ret & 0x1)) {
	    break;
	}
	YIELD();
    }
    return ret;
}

__NR_STATIC void
spi_flash_write_enable(const spi_dev_t *spi)
{
    do_spi_transaction(spi, 0, 0x06, 0, 0x0, 0x0);  // WRITE ENABLE
}

__NR_STATIC void
spi_flash_vsr_write_enable(const spi_dev_t *spi)
{
    do_spi_transaction(spi, 0, 0x50, 0, 0x0, 0x0);  // VSR WRITE ENABLE
}

#ifdef UNUSED
__NR_STATIC void
spi_flash_write_disable(const spi_dev_t *spi)
{
    do_spi_transaction(spi, 0, 0x04, 0, 0x0, 0x0);  // WRITE DISABLE
}
#endif

void
spi_flash_write_byte(const spi_dev_t *spi, uint32_t addr, uint8_t data)
{
    const uint8_t opcode = 0x02;  // PAGE PROGRAM
    uint32_t lower = (((uint32_t)data) << 24) | spi_flash_addr_to_lower(addr);

    spi_flash_write_enable(spi);
    do_spi_transaction(spi, 0, opcode, 4, 0x0, lower);

    spi_flash_wait_for_no_wip(spi);
}

void
spi_flash_write_short(const spi_dev_t *spi, uint32_t addr, uint16_t data)
{
    const uint8_t opcode = 0x02;  // PAGE PROGRAM
    uint32_t lower = (((uint32_t)data) << 24) | spi_flash_addr_to_lower(addr);
    uint32_t upper = data >> 8;

    spi_flash_write_enable(spi);
    do_spi_transaction(spi, 0, opcode, 5, upper, lower);

    spi_flash_wait_for_no_wip(spi);
}

void
spi_flash_write_word(const spi_dev_t *spi, uint32_t addr, uint32_t data)
{
    const uint8_t opcode = 0x02;  // PAGE PROGRAM
    uint32_t lower = (((uint32_t)data) << 24) | spi_flash_addr_to_lower(addr);
    uint32_t upper = data >> 8;

    spi_flash_write_enable(spi);
    do_spi_transaction(spi, 0, opcode, 7, upper, lower);

    spi_flash_wait_for_no_wip(spi);
}

bool
spi_macronix_make_quad(const spi_dev_t *spi)
{
    spi_flash_wait_for_no_wip(spi);
    spi_flash_write_enable(spi);

    // WRITE STATUS REG - High perf, Quad Enable
    do_spi_transaction(spi, 0, 0x01, 3, 0x0, 0x020040);

    return ((spi_flash_wait_for_no_wip(spi) & 0x40) == 0x40);
}

/**
 * @brief Command external flash device to exit performance mode.
 *
 * @note For FlashROM images, __FAST will locate this function in RAM.
 */
__FAST
void
spi_macronix_exit_performance_mode(const spi_dev_t *spi)
{
    do_spi_transaction(spi, 0, 0xff, 0, 0x0, 0x0);
}

bool
spi_giga_make_quad(const spi_dev_t *spi)
{
    if (spi_read(spi, 0x35) & 0x02) {  // READ STATUS REG-2
	// QE already set
	return true;
    }

    spi_flash_wait_for_no_wip(spi);
    spi_flash_write_enable(spi);

    // WRITE STATUS REG - Quad Enable
    do_spi_transaction(spi, 0, 0x01, 2, 0x0, 0x0200);

    spi_flash_wait_for_no_wip(spi);

    return ((spi_read(spi, 0x35) & 0x02) == 0x02);
}

bool
spi_winbond_make_quad(const spi_dev_t *spi)
{
    if (spi_read(spi, 0x35) & 0x02) {  // READ STATUS REG-2
	// QE already set
	return true;
    }
    spi_flash_vsr_write_enable(spi);

    // WRITE STATUS REG-2
    do_spi_transaction(spi, 0, 0x31, 1, 0x0, 0x02);

    return ((spi_read(spi, 0x35) & 0x02) == 0x02);
}

/**
 * @brief Command external flash device to power down.
 *
 * @note For FlashROM images, __FAST will locate this function in RAM.
 */
__FAST
void
spi_macronix_deep_power_down(const spi_dev_t *spi)
{
    // Also works as Winbond power-down
    do_spi_transaction(spi, 0, 0xb9, 0, 0x0, 0x0);
}

void
spi_macronix_exit_deep_power_down(const spi_dev_t *spi)
{
    // Winbond release power-down
    // Also works as Macronix release deep power-down
    do_spi_transaction(spi, 0, 0xab, 0, 0x0, 0x0);
}

void
spi_micron_make_quad(const spi_dev_t *spi)
{
    // READ ENHANCED VOLATILE CONFIGURATION REGISTER
    uint8_t evcr = spi_read(spi, 0x65);

    spi_flash_wait_for_no_wip(spi);
    spi_flash_write_enable(spi);

    // WRITE ENHANCED VOLATILE CONFIGURATION REGISTER
    do_spi_transaction(spi, 0, 0x61, 1, 0x0, evcr & ~0xd0);
}
