/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      BLE baseband CS interface file.
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

#ifndef BB_BLE_CS_API_H
#define BB_BLE_CS_API_H

#include "bb_api.h"
#include "pal_crypto.h"
#include "bb_ble_api.h"
#include "bb_ble_api_drbg.h"
#include "bb_ble_api_op.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup BB_API_BLE_CS
 *  \{ */

/**************************************************************************************************
  Macros
**************************************************************************************************/

/*! \brief      CS trailers. */
#define LCTR_CS_TRAILER_0101             5
#define LCTR_CS_TRAILER_1010             10

/*! \brief      CS trailer mask. */
#define LCTR_CS_TRAILER_MASK             0xF

/*! \brief      CS sounding sequence markers. */
#define LCTR_CS_MARKER_0011              12 /* LSB in the air */
#define LCTR_CS_MARKER_1100              3

/*! \brief      CS marker mask. */
#define LCTR_CS_MARKER_MASK              0xF

/**************************************************************************************************
  Constants
**************************************************************************************************/

/*! \brief      CS AA checking quality. */
enum
{
  CS_AA_CHECKING_SUCCESSFUL,  /*! CS Access Address check is successful and all bits match the expected sequence.
                               * For non-Mode-0 packets, the device has obtained a ToA-ToD (or ToD-ToA) measurement from the packet. */
  CS_AA_CHECKING_WITH_ERRORS, /*! CS Access Address check contains 1 or more bit errors. For non-Mode-0 packets,
                               * the device has obtained a ToA-ToD (or ToD-ToA) measurement from the packet. */
  CS_AA_CHECKING_NOT_FOUND    /*! CS Access Address not found. */
};

/*! \brief CS sounding sequence length. */
enum
{
  CS_SOUNDING_SEQUENCE_32_BITS,
  CS_SOUNDING_SEQUENCE_96_BITS
};

/*! \brief CS random sequence length. */
enum
{
  CS_RANDOM_SEQUENCE_32_BITS = 1,
  CS_RANDOM_SEQUENCE_64_BITS,
  CS_RANDOM_SEQUENCE_96_BITS,
  CS_RANDOM_SEQUENCE_128_BITS
};

/*! \brief CS random sequence override types. */
enum
{
  CS_OVERRIDE_RANDOM_SEQUENCE_PRBS9,
  CS_OVERRIDE_RANDOM_SEQUENCE_11110000,
  CS_OVERRIDE_RANDOM_SEQUENCE_10101010,
  CS_OVERRIDE_RANDOM_SEQUENCE_PRBS15,
  CS_OVERRIDE_RANDOM_SEQUENCE_11111111,
  CS_OVERRIDE_RANDOM_SEQUENCE_00000000,
  CS_OVERRIDE_RANDOM_SEQUENCE_00001111,
  CS_OVERRIDE_RANDOM_SEQUENCE_01010101,
  CS_OVERRIDE_RANDOM_SEQUENCE_USER_DEFINED = 0x80
};

/*! \brief      CS random sequence override values. */
#define CS_RANDOM_VALUE_OVERRIDE_11110000             0x0F0F0F0F
#define CS_RANDOM_VALUE_OVERRIDE_10101010             0x55555555
#define CS_RANDOM_VALUE_OVERRIDE_11111111             0xFFFFFFFF
#define CS_RANDOM_VALUE_OVERRIDE_00000000             0x00000000
#define CS_RANDOM_VALUE_OVERRIDE_00001111             0xF0F0F0F0
#define CS_RANDOM_VALUE_OVERRIDE_01010101             0xAAAAAAAA

/*! \brief      Channel sounding duration mode. */
enum
{
  BB_CS_COMPLETE_STEP,                           /*!< Complete step duration. */
  BB_CS_FIRST_HALF_STEP,                         /*!< First half step duration. */
  BB_CS_SECOND_HALF_STEP                         /*!< Second half step duration. */
};

typedef struct {
  uint8_t  toneExtPrsntMask;
  uint8_t  mode;
  uint8_t  chan;
  uint8_t  tonePermIdx;
  uint32_t accaddr;
  uint32_t peerAccAddr;
  uint32_t seqInit[LL_MAX_CS_SEQUENCE_LEN >> 2];
  uint32_t seqRefl[LL_MAX_CS_SEQUENCE_LEN >> 2];
} drbgData_t;

/*! \brief      CS channel selection type. */
enum
{
  BB_CHANSEL_TYPE_3B,                            /*!< Channel Selection Algorithm #3b. */
  BB_CHANSEL_TYPE_3C                             /*!< Channel Selection Algorithm #3c. */
};

/*! \brief      RTT type. */
enum
{
  BB_CS_RTT_AA_ONLY          = 0x00,             /*!< RTT type 0. */
  BB_CS_RTT_SOUNDING_32BITS  = 0x01,             /*!< RTT type 1. */
  BB_CS_RTT_SOUNDING_96BITS  = 0x02,             /*!< RTT type 2. */
  BB_CS_RTT_RANDOM_32BITS    = 0x03,             /*!< RTT type 3. */
  BB_CS_RTT_RANDOM_64BITS    = 0x04,             /*!< RTT type 4. */
  BB_CS_RTT_RANDOM_96BITS    = 0x05,             /*!< RTT type 5. */
  BB_CS_RTT_RANDOM_128BITS   = 0x06              /*!< RTT type 6. */
};

#define CS_N_RANGE_GEN_RANDOMIZED_BITS  8
#define BB_CS_MAX_CHAN_MAP_REP          3        /*!< Max number of channel map repetitions. */

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief      Generates a sounding sequence for CS initiator and reflector.
 *
 *  \param      pSeqInit        Output buffer for initiator sounding sequence.
 *  \param      pSeqRefl        Output buffer for reflector sounding sequence.
 *  \param      rttType         RTT type for the sounding sequence.
 *  \param      transCntPos     Transaction counter for position randomization.
 *  \param      stepCnt         Step counter.
 *  \param      markPosOverride Enable marker position override.
 *  \param      pos1            First marker position (when override enabled).
 *  \param      pos2            Second marker position (when override enabled).
 *  \param      markValOverride Enable marker value override.
 *  \param      val             Marker value (when override enabled).
 *  \param      count           Marker count.
 *  \param      pCtx            DRBG control block.
 *  \param      pTrCnt          Transaction counter pointer.
 */
/*************************************************************************************************/
__attribute__((nonnull(1, 2)))
void BbCsGenerateSoundingSequence(uint32_t *pSeqInit, uint32_t *pSeqRefl, uint8_t rttType, uint8_t stepCnt, bool markPosOverride, uint8_t pos1, uint8_t pos2, bool markValOverride, uint8_t val, uint8_t count, BbBleDrbgCtx_t *pCtx);

/*************************************************************************************************/
/*!
 *  \brief      Generates random sequences for CS initiator and reflector.
 *
 *  \param      pSeqInit            Output buffer for initiator sequence.
 *  \param      pSeqRefl            Output buffer for reflector sequence.
 *  \param      rttType             RTT type for the random sequence.
 *  \param      stepCnt             Step counter.
 *  \param      transCnt            Transaction counter.
 *  \param      payloadOverride     Enable payload override mode.
 *  \param      payloadType         Type of payload when override is enabled.
 *  \param      pUserPayloadPattern User-defined payload pattern.
 *  \param      pCtx                DRBG control block.
 */
/*************************************************************************************************/
__attribute__((nonnull(1, 2)))
void BbCsGenerateRandomSequence(uint8_t *pSeqInit, uint8_t *pSeqRefl, uint8_t rttType, uint8_t stepCnt, uint8_t transCnt, bool payloadOverride, uint8_t payloadType, uint8_t *pUserPayloadPattern, BbBleDrbgCtx_t *pCtx);

/*************************************************************************************************/
/*!
 *  \brief     CS generate channel array from bitmap.
 *
 *  \param     chanMap           Channel map.
 *  \param     chanArray         Channel array.
 *
 *  \return    Size of array
 */
/*************************************************************************************************/
__attribute__((nonnull(1, 2)))
uint8_t bbCsGenerateChanArr(uint8_t *chanMap, uint8_t *chanArr);

/*! \} */ /* BB_API_BLE_CS */

#ifdef __cplusplus
};
#endif

#endif /* BB_BLE_CS_API_H */
