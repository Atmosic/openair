/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief  PAL flash driver.
 *
 *  Copyright (c) 2018-2019 Arm Ltd. All Rights Reserved.
 *
 *  Copyright (c) 2019-2024 Packetcraft, Inc.  All rights reserved.
 *  Packetcraft, Inc. confidential and proprietary.
 *  
 *  IMPORTANT.  Your use of this file is governed by a Software License Agreement
 *  ("Agreement") that must be accepted in order to download or otherwise receive a
 *  copy of this file.  You may not use or copy this file for any purpose other than
 *  as described in the Agreement.  If you do not agree to all of the terms of the
 *  Agreement do not use this file and delete all copies in your possession or control;
 *  if you do not have a copy of the Agreement, you must contact Packetcraft, Inc. prior
 *  to any use, copying or further distribution of this software.
 */
/*************************************************************************************************/

#ifndef PAL_FLASH_H
#define PAL_FLASH_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_FLASH
 *  \{ */

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Operational states. */
typedef enum
{
  PAL_FLASH_STATE_UNINIT = 0,   /*!< Uninitialized state. */
  PAL_FLASH_STATE_ERROR  = 0,   /*!< Error state. */
  PAL_FLASH_STATE_READY,        /*!< Ready state. */
  PAL_FLASH_STATE_BUSY          /*!< Busy state. */
} PalFlashState_t;

/*! \brief      Partition. */
typedef enum
{
  PAL_FLASH_PART_NVM = 0,       /*!< Non-Volatile Memory partition. */
  PAL_FLASH_PART_FOTA_FW,       /*!< Firmware image partition. */
  PAL_FLASH_PART_FOTA_AUTH,     /*!< Firmware image authentication partition. */
  PAL_FLASH_PART_DIAG_SYS,      /*!< System diagnostics partition. */
  PAL_FLASH_PART_MAX            /*!< Maximum number of partitions. */
} PalFlashPartition_t;

/*! \brief      Operation completion callback (may be called in interrupt context).. */
typedef void (*PalFlashCback_t)(void);

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/* Initialization */
void PalFlashInit(void);       /*!< TBD */
void PalFlashDeInit(void);     /*!< TBD */

/* Control and Status */

/*************************************************************************************************/
/*!
 *  \brief      Get flash state.
 *
 *  \param      part     Partition type.
 *
 *  \return     flash state.
 */
/*************************************************************************************************/
PalFlashState_t PalFlashGetState(PalFlashPartition_t part);

/*************************************************************************************************/
/*!
 *  \brief      Get total size of NVM storage.
 *
 *  \param      part     Partition type.
 *
 *  \return     Total size.
 */
/*************************************************************************************************/
uint32_t PalFlashGetTotalSize(PalFlashPartition_t part);

/*************************************************************************************************/
/*!
 *  \brief      Get sector size of NVM storage.
 *
 *  \param      part     Partition type.
 *
 *  \return     Sector size.
 */
/*************************************************************************************************/
uint32_t PalFlashGetSectorSize(PalFlashPartition_t part);

/*************************************************************************************************/
/*!
 *  \brief      Pal Flash Service function.
 *
 *  \return     true if tasks pending, false if idle.
 */
/*************************************************************************************************/
bool PalFlashService(void);

/* Data Transfer */

/*************************************************************************************************/
/*! 
 *  \brief      Reads data from flash storage.
 *
 *  \param      part       Partition type.
 *  \param      pBuf       Pointer to memory buffer where data will be stored.
 *  \param      size       Data size in bytes to be read.
 *  \param      offset     Word aligned address from where data is read.
 *  \param      compCback  Callback function.
 */
/*************************************************************************************************/
void PalFlashRead(PalFlashPartition_t part, void *pBuf, uint32_t size, uint32_t offset,
                  PalFlashCback_t compCback);

/*************************************************************************************************/
/*! 
 *  \brief      Writes data to flash storage.
 *
 *  \param      part        Partition type.
 *  \param      pBuf        Pointer to memory buffer from where data will be written.
 *  \param      size        Data size in bytes to be written.
 *  \param      offset      Word aligned address to write data.
 *  \param      compCback   Callback function.
 */
/*************************************************************************************************/
void PalFlashWrite(PalFlashPartition_t part, void *pBuf, uint32_t size,
                   uint32_t offset, PalFlashCback_t compCback);

/*************************************************************************************************/
/*!
 *  \brief      Erase sector.
 *
 *  \param      part         Partition type.
 *  \param      numOfSectors Number of sectors to be erased.
 *  \param      offset       Word aligned address.
 *  \param      compCback    Callback function.  
 */
/*************************************************************************************************/
void PalFlashEraseSector(PalFlashPartition_t part, uint32_t numOfSectors, uint32_t offset,
                         PalFlashCback_t compCback);

/*! \} */    /* PAL_FLASH */

#ifdef __cplusplus
};
#endif

#endif  /* PAL_FLASH_H */
