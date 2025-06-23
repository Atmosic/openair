/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      Packet sniffer interface file.
 *
 *  Copyright (c) 2019 Arm Ltd. All Rights Reserved.
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

#ifndef BB_BLE_SNIFFER_API_H
#define BB_BLE_SNIFFER_API_H

#include "wsf_types.h"
#include "bb_api.h"
#include "pal_bb_ble.h"
#include "ll_defs.h"
#include "bb_ble_api.h"

#ifndef BB_SNIFFER_ENABLED
/*! \brief     Sniffer enabled for controller */
#define BB_SNIFFER_ENABLED          false
#endif

#ifdef __cplusplus
extern "C" {
#endif
/**************************************************************************************************
  Constants
**************************************************************************************************/

/*! \brief   Maximum number of buffer. */
#define BB_SNIFFER_MAX_NUM_BUF 20

/*! \brief   Max packet size for a sniffer packet. */
#define BB_SNIFFER_MAX_PKT_SIZE 28

/*! \brief   Output methods of sniffer. */
enum
{
  BB_SNIFFER_OUTPUT_HCI_TOKEN,       /*!< Output over HCI through tokens. */
  BB_SNIFFER_OUTPUT_TOTAL_METHODS,   /*!< Total output methods. */

  BB_SNIFFER_OUTPUT_NULL_METHOD      /*!< Null output method. */
};

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief   Sniffer Packet types (Used to parse packet for sniffer). */
enum
{
  BB_SNIFF_PKT_TYPE_TX,   /*!< Transmit packets. */
  BB_SNIFF_PKT_TYPE_RX    /*!< Receive packets. */
};

/*! \brief   Sniffer packet metadata. */
typedef struct
{
  uint8_t           type;        /*!< TX/RX. */
  uint8_t           status;      /*!< TX/RX status. */
  uint8_t           state;       /*!< State of the operation. */
  uint32_t          timeStamp;   /*!< Timestamp. */
  uint8_t           rssi;        /*!< Signal power (TxPower, or RSSI). */
  PalBbBleChan_t    chan;        /*!< channelization params. */
} BbBleSnifferMeta_t;

/*! \brief   Sniffer data packet. */
typedef struct
{
  BbBleSnifferMeta_t    meta;                         /*!< Metadata header. */
  uint8_t               hdr[LL_DATA_HDR_MAX_LEN];     /*!< Header raw data. */
} BbBleDataSniffPkt_t;

/*! \brief   Sniffer advertisement packet. */
typedef struct
{
  BbBleSnifferMeta_t    meta;                         /*!< Metadata header. */
  uint8_t               hdr[LL_ADV_HDR_LEN];          /*!< Header raw data. */
} BbBleAdvSniffPkt_t;

/*! \brief      Sniffer generic packet. */
typedef struct
{
  union
  {
    BbBleSnifferMeta_t  meta;     /*!< Metadata. */
    BbBleDataSniffPkt_t dataPkt;  /*!< Data packet. */
    BbBleAdvSniffPkt_t  advPkt;   /*!< Advertising packet. */
  } pktType;                      /*!< Packet type. */
} BbBleSnifferPkt_t;

/*! \brief      Sniffer output call signature. */
typedef void (*bbSnifferFn_t)(BbBleSnifferPkt_t *pPkt);

/*! \brief      Sniffer get packet call signature. */
typedef BbBleSnifferPkt_t* (*bbSnifferGetPktFn_t)(void);

/*! \brief   HCI output context. */
typedef struct
{
  uint16_t               bufIdx;                          /*!< Current packet buffer index. */
  BbBleSnifferPkt_t      pktBuf[BB_SNIFFER_MAX_NUM_BUF];  /*!< Sotrage for packet buffer. */
} BbBleSnifferHciCtx_t;

/*! \brief   Sniffer context. */
typedef struct
{
  /* Control variables. */
  bool                   enabled;         /*!< Enable status of sniffer. */
  bbSnifferGetPktFn_t    snifferGetPktFn; /*!< Sniffer get packet function callback. */
  bbSnifferFn_t          snifferOutCb;    /*!< Sniffer output callback. */
  uint32_t               packetCtr;       /*!< Number of packets processed. */

  /* Temporary storage. */
  uint8_t                txBuf[LL_DATA_HDR_MAX_LEN];      /*!< Temporary storage for conn tx buf. */
  uint8_t                chanIdx;                         /*!< Temporary storage for adv channel index. */

  /* Output contexts. */
  union
  {
    BbBleSnifferHciCtx_t  hci;           /*!< HCI Output context. */
  } outputCtx;                           /*!< Output context union. */
} bbSnifferCtx_t;

/**************************************************************************************************
  Globals
**************************************************************************************************/

extern bbSnifferCtx_t bbSnifferCtx;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

uint32_t BbBleInitSnifferMem(uint8_t *pFreeMem, uint32_t freeMemAvail);
uint8_t BbBleInitSniffer(uint8_t outMethod, bool enable);
void bbBleSnifferMstScanPktHandler(BbOpDesc_t * pBod, BbBleSnifferPkt_t *pPktData);
void bbBleSnifferMstAuxScanPktHandler(BbOpDesc_t * pBod, BbBleSnifferPkt_t *pPktData);
void bbBleSnifferSlvAdvPktHandler(BbOpDesc_t * pBod, BbBleSnifferPkt_t * pPktData);
void bbBleSnifferSlvAuxAdvPktHandler(BbOpDesc_t * pBod, BbBleSnifferPkt_t * pPktData);
void bbBleSnifferMstPerScanPktHandler(BbOpDesc_t * pBod, BbBleSnifferPkt_t *pPktData);
void bbBleSnifferConnPktHandler(BbOpDesc_t * pBod, BbBleSnifferPkt_t * pPktData);

#ifdef __cplusplus
};
#endif

#endif /* BB_BLE_TESTER_API_H */
