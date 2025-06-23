/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      SPI driver definition.
 *
 *  Copyright (c) 2019-2022 Packetcraft, Inc.  All rights reserved.
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

#ifndef PAL_SPI_H
#define PAL_SPI_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_SPI
 *  \{ */

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Signaling mode. */
typedef enum
{
  PAL_SPI_MODE_SLAVE,                   /*!< Slave mode. */
  PAL_SPI_MODE_MASTER                   /*!< Master mode. */
} PalSpiMode_t;

/*! \brief      Data exchange completion callback. */
typedef void (*PalSpiCompCback)(void);

/*! \brief      Peripheral configuration. */
typedef struct
{
  uint32_t clkRateHz;                   /*!< Clock rate in Hz. */
  PalSpiMode_t mode;                    /*!< Signaling mode. */
  PalSpiCompCback compCback;            /*!< Data exchange completion callback. */
} PalSpiConfig_t;

/*! \brief      Operational states. */
typedef enum
{
  PAL_SPI_STATE_UNINIT = 0,             /*!< Uninitialized state. */
  PAL_SPI_STATE_ERROR  = 0,             /*!< Error state. */
  PAL_SPI_STATE_READY,                  /*!< Ready state. */
  PAL_SPI_STATE_BUSY                    /*!< Data exchange in progress. */
} PalSpiState_t;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/* Initialization */

/*************************************************************************************************/
/*!
 *  \brief      Initialize SPI resources.
 *  
 *  \param      pCfg    TBD
 */
/*************************************************************************************************/
void PalSpiInit(const PalSpiConfig_t *pCfg);

/*************************************************************************************************/
/*!
 *  \brief      De-Initialize the SPI resources.
 */
/*************************************************************************************************/
void PalSpiDeInit(void);

/* Control and Status */

/*************************************************************************************************/
/*!
 *  \brief      Get the current state.
 *
 *  \return     Current state.
 *
 *  Return the current state of the TWI.
 */
/*************************************************************************************************/
PalSpiState_t PalSpiGetState(void);

/* Data Transfer */
/*! \brief      Always start an operation before reading or writing on TWI interface.
 *
 *  \param      pRdData     TBD
 *  \param      rdDataLen   TBD
 *  \param      pWrData     TBD
 *  \param      wrDataLen   TBD
 */
void PalSpiDataExchange(uint8_t *pRdData, uint16_t rdDataLen, const uint8_t *pWrData, uint16_t wrDataLen);

/*! \} */    /* PAL_SPI */

#ifdef __cplusplus
};
#endif

#endif /* PAL_SPI_H */
