/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      BLE baseband resolving list interface file.
 *
 *  Copyright (c) 2016-2019 Arm Ltd. All Rights Reserved.
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

#ifndef BB_BLE_API_RESLIST_H
#define BB_BLE_API_RESLIST_H

#include "wsf_types.h"
#include "bb_ble_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup BB_API_BLE_RL
 *  \{ */

/**************************************************************************************************
  Constants
**************************************************************************************************/

/*! \brief      Resolvable address status. */
enum
{
  BB_BLE_RESLIST_STATUS_ID_ADDR_NOT_IN_LIST,  /*!< Identity address is not in list. */
  BB_BLE_RESLIST_STATUS_ZERO_IRK,             /*!< IRK is zero for address. */
  BB_BLE_RESLIST_STATUS_RES_ADDR_UNASSIGNED,  /*!< Resolvable address is unassigned. */
  BB_BLE_RESLIST_STATUS_RES_ADDR_ASSIGNED     /*!< Resolvable address is assigned. */
};

/*! \brief      Privacy modes. */
enum
{
  BB_BLE_RESLIST_PRIV_MODE_NETWORK = 0,       /*!< Network privacy mode. */
  BB_BLE_RESLIST_PRIV_MODE_DEVICE  = 1,       /*!< Device privacy mode. */
};

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Address resolution needed callback signature. */
typedef void (*bbBleResListAddrResNeeded_t)(uint64_t rpa, bool peer, uint8_t peerAddrType, uint64_t peerIdentityAddr);

/**************************************************************************************************
  Global Declarations
**************************************************************************************************/

/*! \brief      Device filter statistics. */
extern BbBlePduFiltStats_t  bbBlePduFiltStats;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief      Set address resolution needed callback.
 *
 *  \param      cback             Callback.
 */
/*************************************************************************************************/
void BbBleResListSetAddrResNeededCback(bbBleResListAddrResNeeded_t cback);

/*************************************************************************************************/
/*!
 *  \brief      Get address resolution needed callback.
 *
 *  \return     Callback.
 */
/*************************************************************************************************/
bbBleResListAddrResNeeded_t BbBleResListGetAddrResNeededCback(void);

/*************************************************************************************************/
/*!
 *  \brief      Get resolving list size.
 *
 *  \return     Total number of resolving list entries.
 *
 *  Get the resolving list capacity supported by the BB.
 */
/*************************************************************************************************/
uint8_t BbBleResListGetSize(void);

/*************************************************************************************************/
/*!
 *  \brief      Verify a resolvable tag was generated from an IRK.
 *
 *  \param      pIrk            IRK.
 *  \param      hash            Hash.
 *  \param      prand           Prand.
 *
 *  \return     true if the resolvable tag was generated from this IRK.
 *
 *  Verify a resolvable tag was generated from an IRK.
 */
/*************************************************************************************************/
bool BbBleVerifyResolvableTag(const uint8_t *pIrk, uint32_t hash, uint32_t prand);

/*************************************************************************************************/
/*!
 *  \brief      Clear resolving list.
 *
 *  Clear all resolving list entries stored in the BB.
 */
/*************************************************************************************************/
void BbBleResListClear(void);

/*************************************************************************************************/
/*!
 *  \brief      Add device to resolving list.
 *
 *  \param      peerAddrType        Peer identity address type.
 *  \param      peerIdentityAddr    Peer identity address.
 *  \param      pPeerIrk            Peer IRK.
 *  \param      pLocalIrk           Local IRK.
 *
 *  \return     true if successful, false if list full.
 *
 *  Add device to resolving list.
 */
/*************************************************************************************************/
bool BbBleResListAdd(uint8_t peerAddrType, uint64_t peerIdentityAddr, const uint8_t *pPeerIrk,
                     const uint8_t *pLocalIrk);

/*************************************************************************************************/
/*!
 *  \brief      Remove device from resolving list.
 *
 *  \param      peerAddrType        Peer identity address type.
 *  \param      peerIdentityAddr    Peer identity address.
 *
 *  \return     true if successful, false if address not in the list.
 *
 *  Remove device from resolving list.
 */
/*************************************************************************************************/
bool BbBleResListRemove(uint8_t peerAddrType, uint64_t peerIdentityAddr);

/*************************************************************************************************/
/*!
 *  \brief      Set privacy mode of a device.
 *
 *  \param      peerAddrType        Peer identity address type.
 *  \param      peerIdentityAddr    Peer identity address.
 *  \param      privMode            Privacy mode.
 *
 *  \return     true if successful, false if address not in the list.
 *
 *  Set privacy mode of a device.
 */
/*************************************************************************************************/
bool BbBleResListSetPrivacyMode(uint8_t peerAddrType, uint64_t peerIdentityAddr, uint8_t privMode);

/*************************************************************************************************/
/*!
 *  \brief      Get privacy mode of a device.
 *
 *  \param      peerAddrType        Peer identity address type.
 *  \param      peerIdentityAddr    Peer identity address.
 *  \param      pPrivMode           Storage for privacy mode.
 *
 *  \return     true if successful, false if address not in the list.
 *
 *  Get privacy mode of a device.
 */
/*************************************************************************************************/
bool BbBleResListGetPrivacyMode(uint8_t peerAddrType, uint64_t peerIdentityAddr, uint8_t *pPrivMode);

/*************************************************************************************************/
/*!
 *  \brief      Read peer resolvable address.
 *
 *  \param      peerAddrType        Peer identity address type.
 *  \param      peerIdentityAddr    Peer identity address.
 *  \param      pRpa                Storage for peer resolvable private address
 *
 *  \return     true if successful, false if address not in list.
 *
 *  Get the peer resolvable private address that is currently being used for the peer identity
 *  address.
 */
/*************************************************************************************************/
bool BbBleResListReadPeer(uint8_t peerAddrType, uint64_t peerIdentityAddr, uint64_t *pRpa);

/*************************************************************************************************/
/*!
 *  \brief      Read local resolvable address.
 *
 *  \param      peerAddrType        Peer identity address type.
 *  \param      peerIdentityAddr    Peer identity address.
 *  \param      pRpa                Storage for peer resolvable private address
 *
 *  \return     true if successful, false if address not in list.
 *
 *  Get the local resolvable private address that is currently being used for the peer identity
 *  address.
 */
/*************************************************************************************************/
bool BbBleResListReadLocal(uint8_t peerAddrType, uint64_t peerIdentityAddr, uint64_t *pRpa);

/*************************************************************************************************/
/*!
 *  \brief      Update local resolvable address.
 *
 *  \param      peerAddrType        Peer identity address type.
 *  \param      peerIdentityAddr    Peer identity address.
 *  \param      pRpa                Storage for local resolvable private address
 *
 *  \return     true if successful, false if address not in list.
 *
 *  Update the local resolvable private address that is currently being used for the peer identity
 *  address.
 */
/*************************************************************************************************/
bool BbBleResListUpdateLocal(uint8_t peerAddrType, uint64_t peerIdentityAddr, uint64_t *pRpa);

/*************************************************************************************************/
/*!
 *  \brief      Generate peer resolvable address.
 *
 *  \param      peerAddrType        Peer identity address type.
 *  \param      peerIdentityAddr    Peer identity address.
 *  \param      pRpa                Storage for peer resolvable private address.
 *
 *  \return     true if successful, false if address not in list or peer IRK is zero.
 *
 *  Generate a peer resolvable address for a peer.
 */
/*************************************************************************************************/
bool BbBleResListGeneratePeer(uint8_t peerAddrType, uint64_t peerIdentityAddr, uint64_t *pRpa);

/*************************************************************************************************/
/*!
 *  \brief      Check whether a peer address has been resolved.
 *
 *  \param      rpa                 Peer resolvable private address
 *  \param      pPeerAddrType       Storage for peer identity address type.
 *  \param      pPeerIdentityAddr   Storage for peer identity address.
 *
 *  \return     true if successful, false if address has not been resolved.
 *
 *  Check whether a peer address has been resolved.  Because of timing constraints, addresses should
 *  not be resolved in this function; instead, the resolution callback should be invoked to schedule
 *  the operation later.
 */
/*************************************************************************************************/
bool BbBleResListCheckResolvePeer(uint64_t rpa, uint8_t *pPeerAddrType, uint64_t *pPeerIdentityAddr);

/*************************************************************************************************/
/*!
 *  \brief      Check whether a local address has been resolved.
 *
 *  \param      rpa                 Local resolvable private address
 *  \param      peerAddrType        Peer identity address type.
 *  \param      peerIdentityAddr    Peer identity address.
 *
 *  \return     true if successful, false if address has not been resolved.
 *
 *  Check whether a local address has been resolved.  Because of timing constraints, addresses should
 *  not be resolved in this function; instead, the resolution callback should be invoked to schedule
 *  the operation later.
 */
/*************************************************************************************************/
bool BbBleResListCheckResolveLocal(uint64_t rpa, uint8_t peerAddrType, uint64_t peerIdentityAddr);

/*************************************************************************************************/
/*!
 *  \brief      Check whether a local address has been resolved.
 *
 *  \param      rpa                 Local resolvable private address
 *  \param      peerAddrType        Peer identity address type.
 *  \param      peerIdentityAddr    Peer identity address.
 *
 *  \return     true if successful, false if address has not been resolved.
 *
 */
/*************************************************************************************************/
bool BbBleResListIsLocalResolved(uint64_t rpa, uint8_t peerAddrType, uint64_t peerIdentityAddr);

/*************************************************************************************************/
/*!
 *  \brief      Resolve peer resolvable address.
 *
 *  \param      rpa                 Peer resolvable private address
 *  \param      pPeerAddrType       Storage for peer identity address type.
 *  \param      pPeerIdentityAddr   Storage for peer identity address.
 *
 *  \return     true if successful, false if address could not be resolved.
 *
 *  Resolve a peer resolvable address.
 */
/*************************************************************************************************/
bool BbBleResListResolvePeer(uint64_t rpa, uint8_t *pPeerAddrType, uint64_t *pPeerIdentityAddr);

/*************************************************************************************************/
/*!
 *  \brief      Resolve local resolvable address.
 *
 *  \param      rpa                 Local resolvable private address
 *  \param      pPeerAddrType       Storage for peer identity address type.
 *  \param      pPeerIdentityAddr   Storage for peer identity address.
 *
 *  \return     true if successful, false if address could not be resolved.
 *
 *  Resolve a local resolvable address.
 */
/*************************************************************************************************/
bool BbBleResListResolveLocal(uint64_t rpa, uint8_t *pPeerAddrType, uint64_t *pPeerIdentityAddr);

/*************************************************************************************************/
/*!
 *  \brief      Check if RPA is resolved by existing entries
 *
 *  \param      rpa                 Resolvable private address.
 *
 *  \return     false if unresolvable, true otherwise.
 *
 */
/*************************************************************************************************/
bool BbBleResListIsAddressResolved(uint64_t rpa);

/*************************************************************************************************/
/*!
 *  \brief      Get status of peer address in resolving list.
 *
 *  \param      peerAddrRand        true if peer identity address is random.
 *  \param      peerIdentityAddr    Peer identity address.
 *
 *  \return     Peer address status.
 *
 *  Get the peer resolvable private address status
 */
/*************************************************************************************************/
uint8_t BbBleResListPeerStatus(bool peerAddrRand, uint64_t peerIdentityAddr);

/*************************************************************************************************/
/*!
 *  \brief      Get status of local address in resolving list.
 *
 *  \param      peerAddrRand        true if peer identity address is random.
 *  \param      peerIdentityAddr    Peer identity address.
 *
 *  \return     Local address status.
 *
 *  Get the peer resolvable private address status
 */
/*************************************************************************************************/
uint8_t BbBleResListLocalStatus(bool peerAddrRand, uint64_t peerIdentityAddr);

/*************************************************************************************************/
/*!
 *  \brief      Handle timeout of local resolvable addresses.
 *
 *  A new local resolvable address will be generated for each entry in the resolving list.
 */
/*************************************************************************************************/
void BbBleResListRefreshEntries(void);

/*************************************************************************************************/
/*!
 *  \brief      Handle timeout of a local resolvable address.
 *
 *  \param      peerAddrType        Peer identity address type.
 *  \param      peerIdentityAddr    Peer identity address.
 *
 *  A new local resolvable address will be generated for each entry in the resolving list.
 */
/*************************************************************************************************/
void BbBleResListRefreshEntry(uint8_t peerAddrType, uint64_t peerIdentityAddr);

/*************************************************************************************************/
/*!
 *  \brief      Check if either local RPA or peer RPA is updated.
 *
 *  \param      peerAddrType        Peer identity address type.
 *  \param      peerIdentityAddr    Peer identity address.
 *
 *  \return     true if either local RPA or peer RPA is updated.
 *
 */
/*************************************************************************************************/
bool BbBleResListIsRpaUpd(uint8_t peerAddrType, uint64_t peerIdentityAddr);

/*************************************************************************************************/
/*!
 *  \brief      Check if peer identity is in the resolving list.
 *
 *  \param      peerAddrType        Peer identity address type.
 *  \param      peerIdentityAddr    Peer identity address.
 *
 *  \return     true if peer addr is in the resolving list.
 *
 */
/*************************************************************************************************/
bool bbBleIsPeerInResList(uint8_t peerAddrType, uint64_t peerIdentityAddr);

/*! \} */    /* BB_API_BLE_RL */

#ifdef __cplusplus
};
#endif

#endif /* BB_BLE_API_RESLIST_H */
