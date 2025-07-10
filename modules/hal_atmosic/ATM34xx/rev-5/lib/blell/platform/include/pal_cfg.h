 /*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      System configuration definition.
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
 *  if you do not have a copy of the Agreement, you must contact Atmosic, Inc. prior
 *  to any use, copying or further distribution of this software.
 */
/*************************************************************************************************/

#ifndef PAL_CFG_H
#define PAL_CFG_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_CFG
 *  \{ */

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Configuration ID. */
#define PAL_CFG_ID_BD_ADDR        0U           /*!< BD address. */
#define PAL_CFG_ID_BLE_PHY        1U           /*!< BLE PHY. */
#define PAL_CFG_ID_LL_PARAM       2U           /*!< LL parameters. */
#define PAL_CFG_ID_MAC_ADDR       3U           /*!< MAC address. */
#define PAL_CFG_ID_UUID           4U           /*!< UUID. */
#define PAL_CFG_ID_BOOTSTRAP      5U           /*!< Bootstrap. */
#define PAL_CFG_ID_CTE            6U           /*!< CTE. */
typedef uint8_t PalCfgId_t;

typedef bool (*PalGetUserCfgCb_t) (uint8_t cfgId, void *pBuf, uint32_t len);

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief      Load device UUID.
 *
 *  \param      cfgId                Configuration ID.
 *  \param      pBuf                 Buffer.
 *  \param      len                  Buffer length.
 *
 *  \return     TBD
 */
/*************************************************************************************************/
bool PalCfgLoadData(uint8_t cfgId, void *pBuf, uint32_t len);

/*************************************************************************************************/
/*!
 *  \brief      Set device UUID.
 *
 *  \param      pBuf                Return device UUID.
 */
/*************************************************************************************************/
void PalCfgSetDeviceUuid(uint8_t *pBuf);

/*************************************************************************************************/
/*!
 *  \brief      Register a callback to modify the default configuration
 *
 *  \param      cb                Callback to get user configuration.
 */
/*************************************************************************************************/
void PalCfgSetUserCfgCb(PalGetUserCfgCb_t cb);

/*! \} */    /* PAL_CFG */

#ifdef __cplusplus
};
#endif

#endif /* PAL_CFG_H */
