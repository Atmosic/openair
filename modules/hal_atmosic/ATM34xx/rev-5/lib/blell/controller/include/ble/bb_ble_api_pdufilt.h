/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      BLE baseband PDU filtering interface file.
 *
 *  Copyright (c) 2016-2018 Arm Ltd. All Rights Reserved.
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

#ifndef BB_BLE_API_PDUFILT_H
#define BB_BLE_API_PDUFILT_H

#include "wsf_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup BB_API_BLE_PDU_FILT
 *  \{ */

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Check whether a flag is set. */
#define BB_BLE_PDU_FILT_FLAG_IS_SET(pFilt, flag)   (((pFilt)->flags & BB_BLE_PDU_FILT_FLAG_##flag) != 0)

/*! \brief      Set a flag. */
#define BB_BLE_PDU_FILT_SET_FLAG(pFilt, flag)        (pFilt)->flags |= BB_BLE_PDU_FILT_FLAG_##flag;

/*! \brief      Clear a flag. */
#define BB_BLE_PDU_FILT_CLR_FLAG(pFilt, flag)        (pFilt)->flags &= ~(BB_BLE_PDU_FILT_FLAG_##flag);


/*! \brief      PDU filtering flags. */
enum
{
  /* Common flags. */
  BB_BLE_PDU_FILT_FLAG_LOCAL_ADDR_MATCH_ENA  = (1 << 0),    /*!< Local address should be matched. */
  BB_BLE_PDU_FILT_FLAG_LOCAL_ADDR_MATCH_RAND = (1 << 1),    /*!< Local address to match is a random address. */
  BB_BLE_PDU_FILT_FLAG_PEER_ADDR_MATCH_ENA   = (1 << 2),    /*!< Peer address should be matched. */
  BB_BLE_PDU_FILT_FLAG_PEER_ADDR_MATCH_RAND  = (1 << 3),    /*!< Peer address to match is a random address. */

  /* Privacy flags. */
  BB_BLE_PDU_FILT_FLAG_LOCAL_ADDR_RES_ENA    = (1 << 4),    /*!< Local address resolution is enabled. */
  BB_BLE_PDU_FILT_FLAG_LOCAL_ADDR_RES_OPT    = (1 << 5),    /*!< Local address resolution is optional. */
  BB_BLE_PDU_FILT_FLAG_PEER_ADDR_RES_ENA     = (1 << 6),    /*!< Peer address resolution is enabled. */

  /* DBAF flags. */
  BB_BLE_PDU_FILT_FLAG_DECISION_IND_BYPASS   = (1 << 7)     /*!< Decision indications bypass the filter. */
};

/*! \brief      Periodic PDU filtering parameters. */
typedef struct
{
  uint8_t       filterPolicy;         /*!< Filter policy. */
  uint8_t       advSID;               /*!< Advertising SID. */
  uint8_t       advAddrType;          /*!< Advertiser Address Type. */
  uint64_t      advAddr;              /*!< Advertiser Address. */
  uint8_t       syncCteType;          /*!< CTE Type. */
} bbBlePerPduFiltParams_t;

/*! \brief      PDU filtering parameters. */
typedef struct
{
  uint16_t      pduTypeFilt;          /*!< Bit map of the PDUs the BB should allow. */
  uint16_t      wlPduTypeFilt;        /*!< Bit map of the PDUs the BB should pass through the whitelist. */
  uint32_t      flags;                /*!< Flags for PDU filtering. */
  uint64_t      localAddrMatch;       /*!< Local address to match. */
  uint64_t      peerAddrMatch;        /*!< Peer address to match. */
} bbBlePduFiltParams_t;

/*! \brief      Extended PDU filtering parameters. */
typedef struct
{
  uint64_t      peerAddr;             /*!< Peer address. */
  uint64_t      localAddr;            /*!< Local address. */
  uint8_t       pduType;              /*!< PDU type. */
  uint8_t       extHdrFlags;          /*!< Extended header flags. */
  bool          peerAddrRand;         /*!< true if peer address is random, false otherwise. */
  bool          localAddrRand;        /*!< true if local address is random, false otherwise. */
} bbBlePduExtFiltParams_t;

/*! \brief      PDU filtering results. */
typedef struct
{
  uint64_t      peerAddr;             /*!< Peer address. */
  uint64_t      peerIdAddr;           /*!< Peer ID address. */
  uint8_t       pduType;              /*!< PDU type. */
  uint8_t       pduLen;               /*!< PDU length. */
  bool          peerAddrRand;         /*!< true if peer address is random. */
  bool          peerIdAddrRand;       /*!< true if peer ID address is random. */
  bool          peerMatch;            /*!< true if peer address was resolved or matched. */
  bool          localMatch;           /*!< true if local address was resolved or matched. */
} bbBlePduFiltResults_t;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief      Check if PDU is allowed, i.e., should not be ignored.
 *
 *  \param      pBuf              PDU buffer.
 *  \param      pFiltParams       Filter parameters.
 *  \param      forceRes          true if address resolution should be forced.
 *  \param      pFiltResults      Storage for filter results.
 *
 *  \return     true if PDU is allowed, false if PDU should be ignored.
 */
/*************************************************************************************************/
bool BbBlePduFiltCheck(const uint8_t *pBuf, const bbBlePduFiltParams_t *pFiltParams,
                       bool forceRes, bbBlePduFiltResults_t *pFiltResults);

/*************************************************************************************************/
/*!
 *  \brief      Check if PDU is allowed, i.e., should not be ignored.
 *
 *  \param      pExtFiltParams    Extended filter parameters.
 *  \param      pFiltParams       Filter parameters.
 *  \param      forceRes          true if address resolution should be forced.
 *  \param      pFiltResults      Storage for filter results.
 *
 *  \return     true if PDU is allowed, false if PDU should be ignored.
 */
/*************************************************************************************************/
bool BbBleExtPduFiltCheck(const bbBlePduExtFiltParams_t *pExtFiltParams,
                          const bbBlePduFiltParams_t *pFiltParams,
                          bool forceRes, bbBlePduFiltResults_t *pFiltResults);

/*************************************************************************************************/
/*!
 *  \brief      Get the peer ID address.
 *
 *  \param      pFiltResults      Filter results.
 *  \param      pPeerIdAddr       Storage for peer ID address.
 *  \param      pPeerIdAddrType   Storage for peer ID address type;
 */
/*************************************************************************************************/
static inline void BbBlePduFiltResultsGetPeerIdAddr(const bbBlePduFiltResults_t *pFiltResults, uint64_t *pPeerIdAddr, uint8_t *pPeerIdAddrType)
{
  const unsigned int addrIdBit = 1 << 1;

  *pPeerIdAddrType = pFiltResults->peerIdAddrRand;
  if ((pFiltResults->peerIdAddrRand != pFiltResults->peerAddrRand) ||
      (pFiltResults->peerIdAddr     != pFiltResults->peerAddr))
  {
    *pPeerIdAddrType |= addrIdBit;
  }
  *pPeerIdAddr = pFiltResults->peerIdAddr;
}

/*************************************************************************************************/
/*!
 *  \brief      Get the peer RPA.
 *
 *  \param      pFiltResults      Filter results.
 *  \param      pPeerRpa          Storage for peer RPA or 0.
 */
/*************************************************************************************************/
static inline void BbBlePduFiltResultsGetPeerRpa(const bbBlePduFiltResults_t *pFiltResults, uint64_t *pPeerRpa)
{
  *pPeerRpa = 0;
  if ((pFiltResults->peerIdAddrRand != pFiltResults->peerAddrRand) ||
      (pFiltResults->peerIdAddr     != pFiltResults->peerAddr))
  {
    *pPeerRpa = pFiltResults->peerAddr;
  }
}

/*! \} */    /* BB_API_BLE_PDU_FILT */

#ifdef __cplusplus
};
#endif

#endif /* BB_BLE_API_PDUFILT_H */
