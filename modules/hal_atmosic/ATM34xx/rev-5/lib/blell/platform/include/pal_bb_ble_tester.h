/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      BLE Baseband tester interface file.
 *
 *  Copyright (c) 2018 Arm Ltd. All Rights Reserved.
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

#ifndef PAL_BB_BLE_TESTER_H
#define PAL_BB_BLE_TESTER_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief      Enable bypassing PDU filtering.
 *
 *  \param      enable      If true enable bypass PDU filtering, false otherwise.
 *
 *  Enable bypassing PDU filtering.
 */
/*************************************************************************************************/
void PalBbTesterEnablePduFilterBypass(bool enable);

/*************************************************************************************************/
/*!
 *  \brief      Invalidate next access address.
 *
 *  \param      forRx    For Rx or Tx boolean.
 */
/*************************************************************************************************/
void PalBbInvalidateNextAccAddr(bool forRx);

/*************************************************************************************************/
/*!
 *  \brief      Invalidate access address value.
 *
 *  \param      chanMask    Invalidate channel mask.
 *  \param      invalidMask Enable mask for invalidating access address (0 to disable).
 *  \param      shiftMask   true if corrupting AA by one bit and corrupted bit location is shifted every TX/RX.
 *  \param      forRx       true for Rx, false for Tx.
 *
 *  Force the receiver to receive a miss a packet if the receive channel is in
 *  \b chanMask while stepping through the invalid pattern in \b invalidMask.
 */
/*************************************************************************************************/
void PalBbTesterSetInvalidAccessAddress(uint64_t chanMask, uint32_t invalidMask, bool shiftMask, bool forRx);

/*************************************************************************************************/
/*!
 *  \brief      Invalidate CRC initialization value.
 *
 *  \param      chanMask    Invalidate channel mask.
 *  \param      adjMask     Number of adjustments (0 to disable).
 *  \param      forRx       true for Rx, false for Tx.
 *
 *  Force the receiver to receive a packet with CRC error if the receive channel is in
 *  \b chanMask while stepping through the invalid pattern in \b invalidMask.
 */
/*************************************************************************************************/
void PalBbTesterSetInvalidCrcInit(uint64_t chanMask, uint32_t adjMask, bool forRx);

/*************************************************************************************************/
/*!
 *  \brief      Trigger channel modifications on matching Tx packet header.
 *
 *  \param      hdrMask     Header mask.
 *  \param      hdrValue    Match value.
 *
 *  Modify the transmit channel parameters of a packet only when the Tx packet header matches
 *  the given parameters. This applies to the modification parameter provided by the following
 *  routines:
 *
 *      - \ref PalBbTesterSetInvalidCrcInit()
 *      - \ref PalBbTesterSetInvalidAccessAddress()
 */
/*************************************************************************************************/
void PalBbTesterSetModifyTxPktTrigger(uint16_t hdrMask, uint16_t hdrValue);

/*************************************************************************************************/
/*!
 *  \brief      Adjust Tx TIFS timing value.
 *
 *  \param      adjNs       Adjustment value in nanoseconds.
 *
 *  Adjust the TIFS timing of transmit by the given signed value of timer ticks.
 *  If adjustment value is out of range, maximum allowed value is used.
 */
/*************************************************************************************************/
void PalBbTesterAdjTxTifsNs(int16_t adjNs);

/*************************************************************************************************/
/*!
 *  \brief      BLE Baseband tester initialization.
 *
 *  Plugs external hooks to extended testing functions in this module.
 */
/*************************************************************************************************/
void PalBbTesterInit(void);

#ifdef __cplusplus
};
#endif

#endif /* PAL_BB_BLE_TESTER_H */
