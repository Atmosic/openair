/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      BLE DRBG definition.
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

#ifndef BB_BLE_DRBG_H
#define BB_BLE_DRBG_H

#include "wsf_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup BB_BLE_DRBG
 *  \{ */

/**************************************************************************************************
  Macros
**************************************************************************************************/

#define BB_BLE_DRBG_KEY_LEN                  16       /*!< Length of DRBG key. */
#define BB_BLE_DRBG_NONCE_LEN                16       /*!< Length of DRBG nonce vector. */

/*! \brief      DRBG transaction ID. */
enum
{
  BB_BLE_DRBG_TRANSID_HOP_CHANNEL_SET_NON_MODE0,      /*!< Randomization of hop channel set for non-mode-0 steps. */
  BB_BLE_DRBG_TRANSID_HOP_CHANNEL_SET_MODE0,          /*!< Randomization of hop channel set for mode-0 steps. */
  BB_BLE_DRBG_TRANSID_RANDOMIZATION_SUBMODE,          /*!< Randomization of subevent sub-mode (into main-mode cycle). */
  BB_BLE_DRBG_TRANSID_T_PM,                           /*!< T_PM CS tone extension slot transmission presence. */
  BB_BLE_DRBG_TRANSID_T_ANT_PATH_PERMUT,              /*!< Antenna path permutation index selection. */
  BB_BLE_DRBG_TRANSID_RTT_PN_SEQ,                     /*!< RTT PN sequence CS Access Address generation. */
  BB_BLE_DRBG_TRANSID_SOUNDING_SEQ_POS_RANDOMIZATION, /*!< Sounding sequence marker position randomization. */
  BB_BLE_DRBG_TRANSID_SOUNDING_SEQ_SIG_SELECTION,     /*!< Sounding sequence marker signal selection. */
  BB_BLE_DRBG_TRANSID_RANDOM_SEQ,                     /*!< Random sequence generation. */
  BB_BLE_DRBG_TRANSID_BACKTRACK_RESIST,               /*!< Backtracking resistance. */
  BB_BLE_DRBG_TRANSID_MAX                             /*!< Number of transaction identifiers. */
};

/*! \brief   Deterministic Random Bit Generator block table. */
typedef struct
{
  uint8_t vDRBG[BB_BLE_DRBG_NONCE_LEN];     /*!< V_DRBG. Note: Field represented in LE. */
  uint8_t key[BB_BLE_DRBG_KEY_LEN];         /*!< Key. Note: Field represented in LE. */
  uint8_t nonce[BB_BLE_DRBG_NONCE_LEN];     /*!< Nonce. Note: Field represented in LE. */
  struct
  {
    uint8_t bitIndex;
    uint8_t remainingBits;
    uint8_t lastStepUsed;
    uint8_t transCnt;
    uint8_t out[16];
  } data[BB_BLE_DRBG_TRANSID_MAX];
} BbBleDrbgCtx_t;

/*************************************************************************************************/
/*!
 *  \brief  Invoke backtracking resistance.
 */
/*************************************************************************************************/
void BbBleDrbgInvokeBacktrackResist(BbBleDrbgCtx_t *pCtx);

/*************************************************************************************************/
/*!
 *  \brief  Instantiates the Deterministic Random Bit Generator temporal key and nonce vector.
 *
 *  \param  pIV           Initialization vector (128 bits).
 *  \param  pIN           Instantiation nonce (64 bits).
 *  \param  pPV           Personalization vector (128 bits).
 *  \param  pCtx          DRBG control block.
 */
/*************************************************************************************************/
void BbBleDrbgInstantiate(const uint8_t *pIV, const uint8_t *pIN, const uint8_t *pPV, BbBleDrbgCtx_t *pCtx);

/*************************************************************************************************/
/*!
 *  \brief  Get random bits position from DRBG.
 *
 *  \param  n             Number of required bits.
 *  \param  transId       Channel sounding transaction ID.
 *  \param  stepCount     Channel sounding step count.
 *  \param  pCtx          DRBG control block.
 *
 *  \return Pointer to the random bits in the DRBG output buffer.
 */
/*************************************************************************************************/
uint8_t *BbBleDrbgGetRandomBitsPos(const uint8_t n, const uint8_t transId, const uint16_t stepCount, BbBleDrbgCtx_t *pCtx);

/*************************************************************************************************/
/*!
 *  \brief  Instantiates the Deterministic Random Bit Generator temporal key and nonce vector in test mode.
 *
 *  \param  drbgNonce           DRBG nonce bytes 14 and 15.
 */
/*************************************************************************************************/
void BbCsTest(const uint16_t drbgNonce);

/*! \} */    /* BB_BLE_DRBG */

#ifdef __cplusplus
};
#endif

#endif /* BB_BLE_DRBG_H */
