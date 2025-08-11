/**
 *******************************************************************************
 *
 * @file spi_flash.h
 *
 * @brief SPI flash driver
 *
 * Copyright (C) Atmosic 2019-2022
 *
 *******************************************************************************
 */

#ifndef __SPI_FLASH_H__
#define __SPI_FLASH_H__

/**
 * @defgroup SPI_FLASH SPI flash
 * @ingroup SPI
 * @brief User driver for SPI-connected flash device
 * @{
 */

#include "spi.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    SPI_FLASH_FREAD = 0x0b,	// Read Array (fast)
    SPI_FLASH_READ = 0x03,	// Read Array (low power)
    SPI_FLASH_DREAD = 0x3b,	// Read Dual Output
    SPI_FLASH_2READ = 0xbb,	// Read 2x I/O
    SPI_FLASH_QREAD = 0x6b,	// Read Quad Output
    SPI_FLASH_4READ = 0xeb,	// Read 4x I/O

    SPI_FLASH_PE = 0x81,	// Page Erase
    SPI_FLASH_SE = 0x20,	// Sector Erase (4K bytes)
    SPI_FLASH_BE32 = 0x52,	// Block Erase (32K bytes)
    SPI_FLASH_BE64 = 0xd8,	// Block Erase (64K bytes)
    SPI_FLASH_CE = 0x60,	// Chip Erase
    SPI_FLASH_CE_ALT = 0xc7,	// Chip Erase
    SPI_FLASH_PP = 0x02,	// Page Program
    SPI_FLASH_2PP = 0xa2,	// Dual-IN Page Program
    SPI_FLASH_QPP = 0x32,	// Quad Page Program
    SPI_FLASH_PES = 0x75,	// Program/Erase Suspend
    SPI_FLASH_PES_ALT = 0xb0,	// Program/Erase Suspend
    SPI_FLASH_PER = 0x7a,	// Program/Erase Resume
    SPI_FLASH_PER_ALT = 0x30,	// Program/Erase Resume

    SPI_FLASH_WREN = 0x06,	// Write Enable
    SPI_FLASH_WRDI = 0x04,	// Write Disable
    SPI_FLASH_VWREN = 0x50,	// Volatile SR Write Enable

    SPI_FLASH_ERSCUR = 0x44,	// Erase Security Registers
    SPI_FLASH_PRSCUR = 0x42,	// Program Security Registers
    SPI_FLASH_RDSCUR = 0x48,	// Read Security Registers

    SPI_FLASH_RDSR = 0x05,	// Read Status Register
    SPI_FLASH_RDSR2 = 0x35,	// Read Status Register
    SPI_FLASH_ASI = 0x25,	// Active Status Interrupt
    SPI_FLASH_WRSR = 0x01,	// Write Status Register

    SPI_FLASH_RSTEN = 0x66,	// Reset Enable
    SPI_FLASH_RST = 0x99,	// Reset
    SPI_FLASH_RDID = 0x9f,	// Read Manufacturer/Device ID
    SPI_FLASH_REMS = 0x90,	// Read Manufacturer ID
    SPI_FLASH_DREMS = 0x92,	// Dual Read Manufacturer ID
    SPI_FLASH_QREMS = 0x94,	// Quad Read Manufacturer ID
    SPI_FLASH_DP = 0xb9,	// Deep Power-down
    SPI_FLASH_RDP = 0xab,	// Release Deep Power-down
    SPI_FLASH_SBL = 0x77,	// Set Burst Length
    SPI_FLASH_RDSFDP = 0x5a,	// Read SFDP
    SPI_FLASH_RRE = 0xff,	// Release Read Enhanced
    SPI_FLASH_RUID = 0x4b,	// Read Unique ID
} spi_flash_cmd_t;

/**
 * @brief Read data from SPI-connected flash device.
 * @param[in] spi  Device structure.
 * @param[in] addr 3-byte address of data in flash.
 * @return Data read from flash device.
 */
uint8_t spi_flash_read_byte(const spi_dev_t *spi, uint32_t addr);

/**
 * @brief Read data from SPI-connected flash device.
 * @param[in] spi  Device structure.
 * @param[in] addr 3-byte address of data in flash.
 * @return Data read from flash device.
 */
uint16_t spi_flash_read_short(const spi_dev_t *spi, uint32_t addr);

/**
 * @brief Read data from SPI-connected flash device.
 * @param[in] spi  Device structure.
 * @param[in] addr 3-byte address of data in flash.
 * @return Data read from flash device.
 */
uint32_t spi_flash_read_word(const spi_dev_t *spi, uint32_t addr);


/**
 * @brief Write data to SPI-connected flash device.
 * @param[in] spi  Device structure.
 * @param[in] addr 3-byte address of data in flash.
 * @param[in] data Data to write to flash device.
 */
void spi_flash_write_byte(const spi_dev_t *spi, uint32_t addr, uint8_t data);

/**
 * @brief Write data to SPI-connected flash device.
 * @param[in] spi  Device structure.
 * @param[in] addr 3-byte address of data in flash.
 * @param[in] data Data to write to flash device.
 */
void spi_flash_write_short(const spi_dev_t *spi, uint32_t addr, uint16_t data);

/**
 * @brief Write data to SPI-connected flash device.
 * @param[in] spi  Device structure.
 * @param[in] addr 3-byte address of data in flash.
 * @param[in] data Data to write to flash device.
 */
void spi_flash_write_word(const spi_dev_t *spi, uint32_t addr, uint32_t data);


/**
 * @brief Turn on QE in remote flash device.
 * @param[in] spi Device structure.
 * @return Success: true
 * Failure: false
 */
bool spi_macronix_make_quad(const spi_dev_t *spi);

/**
 * @brief Force remote flash device out of performance enhance mode.
 * @param[in] spi Device structure.
 */
void spi_macronix_exit_performance_mode(const spi_dev_t *spi);

/**
 * @brief Turn on QE in remote flash device.
 * @param[in] spi Device structure.
 * @return Success: true
 * Failure: false
 */
bool spi_giga_make_quad(const spi_dev_t *spi);

/**
 * @brief Turn on QE in remote flash device.
 * @param[in] spi Device structure.
 * @return Success: true
 * Failure: false
 */
bool spi_winbond_make_quad(const spi_dev_t *spi);

/**
 * @brief Place remote flash device in deep power down mode.
 * @param[in] spi Device structure.
 */
void spi_macronix_deep_power_down(const spi_dev_t *spi);

/**
 * @brief Wake up remote flash device from deep power down mode.
 * @param[in] spi Device structure.
 */
void spi_macronix_exit_deep_power_down(const spi_dev_t *spi);

/**
 * @brief Enable Quad I/O protocol in remote flash device.
 * @param[in] spi Device structure.
 */
void spi_micron_make_quad(const spi_dev_t *spi);

#ifdef __cplusplus
}
#endif

/// @} SPI_FLASH

#endif // __SPI_FLASH_H__
