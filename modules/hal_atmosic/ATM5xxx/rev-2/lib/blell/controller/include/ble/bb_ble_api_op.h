/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      BLE baseband interface file.
 *
 *  Copyright (c) 2016-2019 Arm Ltd. All Rights Reserved.
 *
 *  Copyright (c) 2019-2024 Packetcraft, Inc.  All rights reserved.
 *  Packetcraft, Inc. confidential and proprietary.
 *
 *  Copyright (c) Atmosic 2025
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

#ifndef BB_BLE_API_OP_H
#define BB_BLE_API_OP_H

#include "bb_api.h"
#include "cfg_mac_ble.h"
#include "pal_bb_ble.h"
#include "bb_ble_api_pdufilt.h"
#include "ll_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup BB_API_BLE
 *  \{ */

/**************************************************************************************************
  Macros
**************************************************************************************************/

/*! \brief      Convert BLE protocol ticks to BB ticks. */
#define BB_BLE_TO_US(n)             ((n) * LL_BLE_US_PER_TICK)

#if (BB_ENABLE_STATS)
/*! \brief      Increment statistics counter. */
#define BB_INC_STAT(s)              (s)++

/*! \brief      Reset statistics counter value. */
#define BB_STATS_RESET(s)           memset(&s, 0, sizeof(s))
#else
#define BB_INC_STAT(s)
#define BB_STATS_RESET(s)
#endif  /* BB_ENABLE_STATS */

/**************************************************************************************************
  Constants
**************************************************************************************************/

/*! \brief      Operation types. */
enum
{
  BB_BLE_OP_TEST_TX,                /*!< Continuous Tx test mode. */
  BB_BLE_OP_TEST_RX,                /*!< Continuous Rx test mode. */
  BB_BLE_OP_MST_ADV_EVENT,          /*!< Master advertising event. */
  BB_BLE_OP_SLV_ADV_EVENT,          /*!< Slave advertising event. */
  BB_BLE_OP_MST_CONN_EVENT,         /*!< Master connection event. */
  BB_BLE_OP_SLV_CONN_EVENT,         /*!< Slave connection event. */
  BB_BLE_OP_MST_AUX_ADV_EVENT,      /*!< Master auxiliary advertising event. */
  BB_BLE_OP_SLV_AUX_ADV_EVENT,      /*!< Slave auxiliary advertising event. */
  BB_BLE_OP_SLV_PER_ADV_EVENT,      /*!< Slave periodic advertising event. */
  BB_BLE_OP_MST_PER_SCAN_EVENT,     /*!< Master periodic scanning event. */
  BB_BLE_OP_MST_CIS_EVENT,          /*!< Master CIS event. */
  BB_BLE_OP_SLV_CIS_EVENT,          /*!< Slave CIS event. */
  BB_BLE_OP_MST_BIS_EVENT,          /*!< Master BIS event. */
  BB_BLE_OP_SLV_BIS_EVENT,          /*!< Slave BIS event. */
  BB_BLE_OP_DAA_EDS_EVENT,          /*!< DAA EDS event. */
  BB_BLE_OP_PAWR_RSP_EVENT,         /*!< PAwR Response event. */
  BB_BLE_OP_INIT_CS_EVENT,          /*!< Initiator CS event. */
  BB_BLE_OP_REFL_CS_EVENT,          /*!< Reflector CS event. */
  BB_BLE_OP_NUM                     /*!< Total number of operations. */
};
typedef uint8_t BbBleOp_t;

/*! \brief      Maximum request PDU length (MAX(LL_SCAN_REQ_PDU_LEN, LL_CONN_IND_PDU_LEN)). */
#define BB_REQ_PDU_MAX_LEN          (LL_ADV_HDR_LEN + LL_CONN_IND_PDU_LEN)

/*! \brief      Minimum scan time to cover one advertise data exchange. */
#define BB_MIN_SCAN_US              (LL_ADV_PKT_MAX_USEC  + LL_BLE_TIFS_US + \
                                     LL_SCAN_REQ_MAX_USEC + LL_BLE_TIFS_US + \
                                     LL_SCAN_RSP_MAX_USEC)

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Pre-execute callback signature. */
typedef void (*BbBlePreExec_t)(BbOpDesc_t *pBod);

/*! \brief      Execute callback signature. */
typedef void (*BbBleExec_t)(BbOpDesc_t *pBod);

/*! \brief      Cancel callback signature. */
typedef void (*BbBleCancel_t)(BbOpDesc_t *pBod);

/*! \brief      Advertising PDU transmit setup call signature. */
typedef void (*BbBleTxAdvSetup_t)(BbOpDesc_t *pBod, uint32_t advTxTime);

/*! \brief      Chain indication PDU transmit setup call signature. */
typedef uint32_t (*BbBleTxAuxSetup_t)(BbOpDesc_t *pBod, bool isChainInd);

/*! \brief      Aux Rx setup call signature. Returns true if Scan was programmed. */
typedef bool (*BbBleRxAuxSetup_t)(BbOpDesc_t *pBod, uint32_t refTime, uint32_t remScanDur);

/*! \brief      Aux Tx complete call signature. Returns true if BOD is complete. */
typedef bool (*BbBleAuxTxComp_t)(BbOpDesc_t *pBod, uint8_t status);

/*! \brief      Aux Rx complete call signature. Returns true if BOD is complete. */
typedef bool (*BbBleAuxRxComp_t)(BbOpDesc_t *pBod, uint8_t status, int8_t rssi, uint32_t crc, uint32_t timestamp, uint8_t rxPhyOptions);

/*! \brief      Returns true if an scan request/response required. */
typedef bool (*BbBleAdvComp_t)(BbOpDesc_t *pBod, const uint8_t *pBuf);

/*! \brief      Monitoring advertising call signature. */
typedef void (*BbBleMonAdvProcessAdv_t)(bool randomAddr, uint64_t addr, int8_t advRssi);

/*! \brief      Rx completion post processing call signature. */
typedef void (*BbBleAdvPost_t)(BbOpDesc_t *pBod, const uint8_t *pBuf);

/*! \brief      Chain indication PDU received call signature. */
typedef uint32_t (*BbBleRxChain_t)(BbOpDesc_t *pBod, const uint8_t *pBuf);

/*! \brief      Chain indication PDU received post call signature. */
typedef bool (*BbBleRxChainPost_t)(BbOpDesc_t *pBod, const uint8_t *pBuf);

/*! \brief      Data transmit completion callback signature. */
typedef void (*BbBleTxDataComp_t)(BbOpDesc_t *pBod, uint8_t status);

/*! \brief      Data receive completion callback signature. */
typedef void (*BbBleRxDataComp_t)(BbOpDesc_t *pBod, uint8_t *pBuf, uint8_t status);

/*! \brief      Receiver diversity callback signature. */
typedef void (*BbBleRxdCback_t)(BbOpDesc_t *pBod, uint8_t status, int8_t rssi);

/*! \brief      CIS check whether to continue current operation call signature. */
typedef uint32_t (*BbBleCisCheckContOp_t)(BbOpDesc_t *pBod, bool *pNewCisCtx);

/*! \brief      CIS post execute callback signature. */
typedef void (*BbBleCisPostExec_t)(BbOpDesc_t *pBod, uint8_t status);

/*! \brief      CIS data receive completion callback signature. */
typedef void (*BbBleCisRxDataComp_t)(BbOpDesc_t *pBod, uint8_t *pBuf, uint8_t status);

/*! \brief      CIS data receive completion post callback signature. */
typedef void (*BbBleCisRxDataPostComp_t)(BbOpDesc_t *pBod, uint8_t status);

/*! \brief      Tx test completion callback signature. */
typedef bool (*BbBleTxTestComp_t)(BbOpDesc_t *pBod, uint8_t status);

/*!
 *  \brief      Rx test completion callback signature.
 *
 *  This callback is invoked upon completion of each BLE test mode receive operation.
 *  It provides timing and PHY information needed for packet interval calculation
 *  and synchronization tracking.
 *
 *  \param      pBod          Pointer to the BOD (Baseband Operation Descriptor).
 *  \param      status        Reception status (BB_STATUS_SUCCESS, BB_STATUS_CRC_FAILED, etc.).
 *  \param      rxPhyOption   PHY options of the received packet (for interval calculation).
 *  \param      startTs       Timestamp when packet reception started (microseconds).
 *
 *  \return     true to continue receiving next packet, false to terminate reception.
 */
typedef bool (*BbBleRxTestComp_t)(BbOpDesc_t *pBod, uint8_t status, uint8_t rxPhyOption, uint32_t startTs);

/*! \brief      Periodic PDU Rx complete call signature. */
typedef uint32_t (*BbBlePerComp_t)(BbOpDesc_t *pBod, const uint8_t *pBuf, uint8_t status);

/*! \brief      Periodic PDU Rx complete post call signature. */
typedef bool (*BbBlePerPostComp_t)(BbOpDesc_t *pBod, const uint8_t *pBuf);

/*! \brief      EDS scan complete call signature. */
typedef void (*BbBleEdsComp_t)(int8_t rssi);

/*! \brief      PAwR Rx buffer get call signature. */
typedef uint8_t *(*BbBleRxQueueGet_t)(void);

/*! \brief      PAwR Rx buffer append call signature. */
typedef void (*BbBleRxQueueAppend_t)(uint8_t **pBuf);

/*! \brief      PAwR Tx completion callback signature. */
typedef bool (*BbBlePawrComp_t)(uint8_t **pBuf, uint32_t base, uint32_t offset, uint32_t wwTotalUsec, BbBleRxQueueGet_t pRxQueueGetCb);

/*! \brief      PAwR Tx SYNC_SUBEVENT_RSP call signature. */
typedef void (*BbBlePerTxSyncRsp_t)(BbOpDesc_t *pBod, uint32_t base, uint32_t offset, PalBbBleTxBufDesc_t*, uint8_t numDescs);

/*! \brief      PAwR Peripheral Rx RSP observation call signature. */
typedef void (*BbBlePerPerRxSyncRspObs_t)(BbOpDesc_t *pBod, uint32_t base, uint32_t offset, uint8_t **pBuf, uint16_t len, uint32_t wwUsec, BbBleRxQueueGet_t pRxQueueGetCb);

/*! \brief      PAwR Central Rx Response call signature. */
typedef void (*BbBlePerCenRxSyncRsp_t)(BbOpDesc_t *pBod, uint8_t bufNumber);

/*! \brief      PAwR Peripheral Rx Response call signature. */
typedef bool (*BbBlePerPerRxSyncRsp_t)(BbOpDesc_t *pBod, uint8_t bufNumber);

/*! \brief      CS_SYNC PDU transmit setup call signature. */
typedef uint32_t (*BbBleTxCsSyncSetup_t)(BbOpDesc_t *pBod);

/*! \brief      CS step operation callback signature. */
typedef void (*BbBleCsOpCompCback_t)(uint32_t timestamp, BbOpDesc_t *pBod);

/*! \brief      CS time offset between end of step and start of next step calculation callback signature. */
typedef void (*BbBleCsCalcTimeCback_t)(BbOpDesc_t *pBod);

/*! \brief      Next CS step mode callback signature. */
typedef void (*BbBleCsUpdateModeCback_t)(BbOpDesc_t *pBod);

/*! \brief      Check CS subevent abort required callback signature. */
typedef bool (*BbBleCsCheckSubevtAbortReqdCback_t)(BbOpDesc_t *pBod);

/*! \brief      Send subevent reports callback signature. */
typedef void (*BbBleCsSendSubevtReportCback_t)(BbOpDesc_t *pBod);

/*! \brief      Start of Procedure callback signature. */
typedef void (*BbBleCsProcStartCback_t)(BbOpDesc_t *pBod);

/*! \brief      BLE interframe space parameters. */
typedef struct
{
  uint16_t tifsAclCp;                   /*!< TIFS for ACL central-peripheral. */
  uint16_t tifsAclPc;                   /*!< TIFS for ACL peripheral-central. */
  uint16_t tifsCis;                     /*!< TIFS for CIS. */
  uint16_t tmces;                       /*!< TMCES. */
  uint16_t rxTimeoutOffset;             /*!< Amount to offset rxTimeout. */
} bbBleIfs_t;

/*! \brief      Bluetooth Low Energy protocol specific operation parameters. */
typedef struct BbBleData_tag
{
  PalBbBleChan_t       chan;            /*!< Channelization parameters. */
  bbBlePduFiltParams_t pduFilt;         /*!< PDU filter parameters. */
  bbBleIfs_t           ifs;             /*!< Interframe space parameters. */
} BbBleData_t;

/*!
 * \brief       Master advertising event operation data (\ref BB_BLE_OP_MST_ADV_EVENT).
 *
 * \note        BB assumes maximum adversing and scan response payload is 39 bytes.
 */
typedef struct
{
  BbBleData_t             cmn;                /*!< Common operation parameters. */

  uint8_t                 *pRxAdvBuf;         /*!< Advertising buffer. */
  uint8_t                 *pTxReqBuf;         /*!< Scan request buffer. */
  uint8_t                 *pRxRspBuf;         /*!< Scan response buffer. */

  BbBlePreExec_t          preExecCback;       /*!< Pre-execute callback. */
  BbBleAdvComp_t          rxAdvCback;         /*!< Advertising completion callback. */
  BbBleAdvPost_t          rxAdvPostCback;     /*!< Advertising completion post processing callback. */
  BbBleAdvComp_t          txReqCback;         /*!< Scan request completion callback. */
  BbBleAdvComp_t          rxRspCback;         /*!< Scan response completion callback. */
  BbBleMonAdvProcessAdv_t monAdvCback;        /*!< Process monitored advertisers. */

  /* Aux Scan BOD link */
  BbOpDesc_t              *auxScanBod;        /*!< Pointer to the Aux Scan BOD */
  BbBleRxAuxSetup_t       auxScanCheckCback;  /*!< Setup an Aux Scan that needs to be programmed ASAP. */
  BbBleAuxTxComp_t        auxScanTxCompCback; /*!< Aux Scan Tx complete. */
  BbBleAuxRxComp_t        auxScanRxCompCback; /*!< Aux Scan Rx complete. */
  bool                    auxScanOpRunning;   /*!< Informs if an Aux Scan operation is running in the context of the Ext Scan BOD. */

  uint8_t                 txReqLen;           /*!< Scan request buffer length. */
  uint8_t                 rxAdvLen;           /*!< Advertising buffer length. */

  uint8_t                 scanChMap;          /*!< Scan channel map. */

  /* Return parameters. */
  int8_t                  advRssi;            /*!< RSSI of advertisement. */
  uint8_t                 advRxPhyOptions;    /*!< Rx PHY options. */
  uint32_t                advCrc;             /*!< CRC of advertisement. */
  uint32_t                advStartTsUsec;     /*!< Start of advertising packet timestamp in microseconds. */
  uint32_t                elapsedUsec;        /*!< Elapsed time of a single scan window in microseconds. */

  /* Filter results. */
  bbBlePduFiltResults_t   filtResults;        /*!< Results from PDU filtering. */
} BbBleMstAdvEvent_t;

/*!
 * \brief       Slave advertising event operation data (\ref BB_BLE_OP_SLV_ADV_EVENT).
 *
 * \note        BB assumes maximum scan request payload is 39 bytes.
 */
typedef struct
{
  BbBleData_t             cmn;                /*!< Common operation parameters. */

  uint8_t                 *pTxAdvBuf;         /*!< Advertising buffer. */
  uint8_t                 *pRxReqBuf;         /*!< Scan request buffer (must be size of BB_REQ_PDU_MAX_LEN). */
  uint8_t                 *pTxRspBuf;         /*!< Scan response buffer. */

  BbBleExec_t             execCback;          /*!< Execute callback. */
  BbBleTxAdvSetup_t       txAdvSetupCback;    /*!< Adv PDU transmit setup callback. */
  BbBleAdvComp_t          rxReqCback;         /*!< Scan/Connect request receive completion callback. */
  BbBleAdvPost_t          rxReqPostCback;     /*!< Scan/Connect request receive post processing callback. */

  uint8_t                 txAdvLen;           /*!< Advertising buffer length. */
  uint8_t                 txRspLen;           /*!< Scan response buffer length. */

  uint8_t                 firstAdvChIdx;      /*!< first advertising channel index. */

  uint8_t                 advChMap;           /*!< Advertising channel map. */

  /* Return parameters. */
  uint32_t                reqStartTsUsec;     /*!< Start of request packet timestamp in microseconds. */

  /* Filter results. */
  bbBlePduFiltResults_t   filtResults;        /*!< Results from PDU filtering. */
} BbBleSlvAdvEvent_t;

/*! \brief       Master auxiliary advertising event operation data (\ref BB_BLE_OP_MST_AUX_ADV_EVENT). */
typedef struct
{
  BbBleData_t             cmn;                /*!< Common operation parameters. */

  uint8_t                 *pTxAuxReqBuf;      /*!< Scan request buffer. */

  BbBleAdvComp_t          rxAuxAdvCback;      /*!< Advertising completion callback. */
  BbBleAdvPost_t          rxAuxAdvPostCback;  /*!< Advertising completion post callback. */
  BbBleAdvComp_t          rxAuxRspCback;      /*!< Scan response completion callback. */
  BbBleRxChain_t          rxAuxChainCback;    /*!< Chain completion callback. */
  BbBleRxChainPost_t      rxAuxChainPostCback;/*!< Chain completion post callback. */
  BbBleMonAdvProcessAdv_t monAdvCback;        /*!< Process monitored advertisers. */

  uint8_t                 txAuxReqLen;        /*!< Scan request buffer length. */

  uint32_t                rxSyncDelayUsec;    /*!< Receive timeout in microseconds. */
  bool                    isInit;             /*!< true if the event is for an initiation. */

  /* Return parameters. */
  int8_t                  auxAdvRssi;         /*!< RSSI of advertisement. */
  uint8_t                 auxRxPhyOptions;    /*!< Rx PHY options. */
  uint32_t                auxAdvCrc;          /*!< CRC of advertisement. */
  uint32_t                auxStartTsUsec;     /*!< Start of auxiliary advertising packet timestamp in microseconds. */

  /* Filter results. */
  bbBlePduFiltResults_t   filtResults;        /*!< Results from PDU filtering. */
} BbBleMstAuxAdvEvent_t;

/*! \brief       Master periodic scanning event operation data (\ref BB_BLE_OP_MST_PER_SCAN_EVENT). */
typedef struct
{
  BbBleData_t               cmn;                         /*!< Common operation parameters. */

  BbBlePerComp_t            rxPerAdvCback;               /*!< Periodic scanning completion callback. */
  BbBlePerPostComp_t        rxPerAdvPostCback;           /*!< Periodic scanning completion post callback. */
  uint32_t                  rxSyncDelayUsec;             /*!< Receive timeout in microseconds. */
  uint32_t                  syncRspOffsetUsec;           /*!< Offset between AUX_SYNC_SUBEVENT_IND and AUX_SYNC_SUBEVENT_RSP. */
  BbBlePerTxSyncRsp_t       txSyncSubeventRspCback;      /*!< Tx sync subevent response callback. */
  PalBbBleTxBufDesc_t       txAuxSyncSubevtRspPdu[2];    /*!< AUX_SYNC_SUBEVENT_RSP PDU descriptor. */
  bool                      sendAuxConnRsp;              /*!< true if AUX_CONNECT_RSP is sent to the advertiser. */
#if (LL_FEAT_RSPOBS)
  uint8_t                   auxPawrSyncRspCount;         /*!< Response observation subevent response buffer counter. */
  uint8_t                   auxPawrSyncRspIdx;           /*!< Response observation subevent response buffer index. */
  uint8_t                   maxAuxPawrSyncRsp;           /*!< Response observation maximum number of PAwR response slots. */
  uint8_t                   numRespSlots;                /*!< Response observation number of response slots. */
  uint8_t                   currSubevent;                /*!< Response observation subevent counter. */
  uint64_t                  rspSlotMask[4];              /*!< Response observation TX response slot bitmap. */
  uint8_t                   *pRxAuxSyncRspBuf[LL_MAX_PAWR_RX_IDX];
                                                         /*!< Response observation subevent response buffer. */
  uint32_t                  slotSpacingUsec;             /*!< Response observation response slot spacing. */
  uint32_t                  rspSlotDelayUsec;            /*!< Response observation response slot delay. */
  uint32_t                  wwTotalUsec;                 /*!< Response observation response window widening. */
  BbBlePerPerRxSyncRspObs_t rxSyncSubeventRspObsCback;   /*!< Response observation callback. */
  BbBlePerPerRxSyncRsp_t    rxPerAdvRspPostCback;        /*!< Response Observation completion post callback. */
  BbBleRxQueueGet_t         rxQueueGetCback;             /*!< Response Observation buffer alloc callback. */
  BbBleRxQueueAppend_t      rxQueueAppendCback;          /*!< Response Observation buffer free callback. */
  uint64_t                  obsSlots[LL_NUM_PAWR_SUBEVT];/*!< Response Observation slots to observe. */
                                                         /*!< Response Observation AUX_SYNC_SUBEVENT_RSP PDU descriptors. */
#if (LL_FEAT_RSPOBS && LL_ENABLE_TESTER)
  PalBbBleTxBufDesc_t       txAuxSyncSubevtRspObsPdu[LL_MAX_PAWR_RSP_SLOTS * 2];
#endif

#endif /* LL_FEAT_RSPOBS */

  /* Return parameters. */
  uint8_t                   rxStatus;            /*!< RX status. */
  int8_t                    perAdvRssi;          /*!< RSSI of advertisement. */
  uint8_t                   perRxPhyOptions;     /*!< Rx PHY options. */
  uint32_t                  perAdvCrc;           /*!< CRC of advertisement. */
  uint32_t                  perStartTsUsec;      /*!< Start of periodic advertising packet timestamp in microseconds. */
  bool                      perIsFirstTs;        /*!< true if it is the first timestamp for a serial of periodic packets. */
  uint8_t                   numSamples;          /*!< Number of samples received from IQ scanning (if enabled). */
  bool                      isAuxSyncSubeventInd;/*!< true if PDU is an AUX_SYNC_SUBEVENT_IND. */
} BbBleMstPerScanEvent_t;

/*! \brief       Slave auxiliary advertising event operation data (\ref BB_BLE_OP_SLV_AUX_ADV_EVENT). */
typedef struct
{
  BbBleData_t             cmn;                /*!< Common operation parameters. */

  /* TODO BbBleSlvAuxAdvEvent_t hide buffer descriptors in BB layer. */
  PalBbBleTxBufDesc_t     txAuxAdvPdu[2];     /*!< Advertising PDU descriptor. */
  uint8_t                 *pRxAuxReqBuf;      /*!< Auxiliary request buffer (must be size of BB_REQ_PDU_MAX_LEN). */
  PalBbBleTxBufDesc_t     txAuxRspPdu[2];     /*!< Response PDU descriptor. */
  PalBbBleTxBufDesc_t     txAuxChainPdu[2];   /*!< Auxiliary chain PDU descriptor. */

  BbBleAdvComp_t          rxAuxReqCback;      /*!< Auxiliary request receive completion callback. */
  BbBleAdvPost_t          rxAuxReqPostCback;  /*!< Auxiliary scan/connect request receive post processing callback. */
  BbBleTxAuxSetup_t       txAuxSetupCback;    /*!< Auxiliary chain indication setup callback. */
  BbBlePerCenRxSyncRsp_t  rxAuxRspPostCback;  /*!< Auxiliary response receive processing callback. */
  BbBleRxQueueGet_t       rxQueueGetCback;    /*!< PAwR buffer alloc callback. */
  BbBleRxQueueAppend_t    rxQueueAppendCback; /*!< PAwR buffer free callback. */
  uint8_t                 auxAdvCh;           /*!< Advertising channel map. */

  /* Return parameters. */
  uint8_t                 auxRxPhyOptions;    /*!< Rx PHY options. */
  uint32_t                auxReqStartTsUsec;  /*!< Start of request packet timestamp in microseconds. */

  /* Filter results. */
  bbBlePduFiltResults_t   filtResults;        /*!< Results from PDU filtering. */

  uint8_t                 *pRxAuxConnRspBuf;  /*!< Auxiliary connection response buffer. */
  uint8_t                 *pRxAuxSyncRspBuf[LL_MAX_PAWR_RX_IDX];
                                              /*!< Auxiliary sync subevent response buffer. */
  uint8_t                 auxPawrSyncRspCount;/*!< Auxiliary sync subevent response buffer counter. */
  uint8_t                 auxPawrSyncRspIdx;  /*!< Auxiliary sync subevent response buffer index. */
  uint8_t                 maxAuxPawrSyncRsp;  /*!< Maximum number of PAwR response slots. */
  int8_t                  rssi;               /*!< RSSI of RX packet. */
  uint8_t                 numRespSlots;       /*!< Number of response slots. */
  BbBlePawrComp_t         txPawrCback;        /*!< PAwR Tx callback. */
  uint32_t                timestamp;          /*!< Timestamp of AUX_SYNC_SUBEVENT_IND Tx. */
  uint32_t                timestampData;      /*!< Timestamp of last AUX_SYNC_SUBEVENT_IND Tx with data. */
  uint32_t                slotDelayUsec;      /*!< PAwR response slot delay. */
  uint32_t                slotSpacingUsec;    /*!< PAwR response slot spacing. */
  uint32_t                wwTotalUsec;        /*!< PAwR response window widening. */
  uint32_t                wwSlotTotalUsec;    /*!< PAwR response window widening. */
  bool                    connPawrFlag;       /*!< AUX_CONNECT_REQ was transmitted instead of AUX_SYNC_SUBEVENT_IND. */
  bool                    auxPawrSyncRspMiss; /*!< AUX_SYNC_SUBEVENT_RSP missing. */
  bool                    auxPawrSubEvtUpd;   /*!< AUX_SUBEVENT Updated. */
#if (LL_FEAT_RSPOBS)
  uint32_t                rspSlotMask;        /*!< Response observation TX slot mask. */
  bool                    indSent;            /*!< true is AUX_SYNC_SUBEVENT_IND was sent. */
  BbBlePerTxSyncRsp_t     txSyncSubeventRspCback;
                                              /*!< Response observation TX response callback. */
  PalBbBleTxBufDesc_t     txAuxSyncSubevtRspObsPdu[2];
                                              /*!< Response Observation AUX_SYNC_SUBEVENT_RSP PDU descriptors. */
#endif
} BbBleSlvAuxAdvEvent_t;

/*! \brief      Connection event operation data (\ref BB_BLE_OP_MST_CONN_EVENT). */
typedef struct
{
  BbBleData_t             cmn;                /*!< Common operation parameters. */

  BbBleExec_t             execCback;          /*!< Execute callback. */
  BbBleCancel_t           cancelCback;        /*!< Cancel callback. */
  BbBleTxDataComp_t       txDataCback;        /*!< Transmit completion callback. */
  BbBleRxDataComp_t       rxDataCback;        /*!< Receive completion callback. */
  BbBleRxdCback_t         rxdRxCback;         /*!< Receiver RX diversity callback. */
  BbBleRxdCback_t         rxdTxCback;         /*!< Receiver TX diversity callback. */

  /* Return parameters. */
  int8_t                  rssi;               /*!< RSSI of the last received packet. */
  uint8_t                 rxPhyOptions;       /*!< Rx PHY options. */
} BbBleMstConnEvent_t;

/*! \brief      Connection event operation data (\ref BB_BLE_OP_SLV_CONN_EVENT). */
typedef struct
{
  BbBleData_t             cmn;                /*!< Common operation parameters. */

  uint32_t                rxSyncDelayUsec;    /*!< Receive timeout in microseconds. */
  BbBleExec_t             execCback;          /*!< Execute callback. */
  BbBleCancel_t           cancelCback;        /*!< Cancel callback. */
  BbBleTxDataComp_t       txDataCback;        /*!< Transmit completion callback. */
  BbBleRxDataComp_t       rxDataCback;        /*!< Receive completion callback. */
  BbBleRxdCback_t         rxdRxCback;         /*!< Receiver RX diversity callback. */
  BbBleRxdCback_t         rxdTxCback;         /*!< Receiver TX diversity callback. */

  /* Return parameters. */
  uint32_t                startTsUsec;        /*!< Start timestamp of the first received packet in microseconds. */
  int8_t                  rssi;               /*!< RSSI of the last received packet. */
  uint8_t                 rxPhyOptions;       /*!< Rx PHY options. */
} BbBleSlvConnEvent_t;

/*! \brief      CIS master event operation data (\ref BB_BLE_OP_MST_CIS_EVENT). */
typedef struct
{
  BbBleData_t              cmn;                  /*!< Common operation parameters. */

  BbBleCisCheckContOp_t    checkContOpCback;     /*!< Check whether to continue current operation callback. */
  BbBleCisCheckContOp_t    checkContOpPostCback; /*!< Check whether to continue current operation callback. */
  BbBleExec_t              execCback;            /*!< Execute callback. */
  BbBleExec_t              contExecCback;        /*!< Continue execute callback. */
  BbBleCisPostExec_t       postSubEvtCback;      /*!< Post subevent callback. */
  BbBleCancel_t            cancelCback;          /*!< Cancel callback. */
  BbBleTxDataComp_t        txDataCback;          /*!< Transmit completion callback. */
  BbBleCisRxDataComp_t     rxDataCback;          /*!< Receive completion callback. */
  BbBleCisRxDataPostComp_t rxDataPostCback;      /*!< Receive completion post callback. */
  /* Return parameters. */
  int8_t                   rssi;                 /*!< RSSI of the last received packet. */
  uint8_t                  rxPhyOptions;         /*!< Rx PHY options. */
} BbBleMstCisEvent_t;

/*! \brief      CIS slave event operation data (\ref BB_BLE_OP_SLV_CIS_EVENT). */
typedef struct
{
  BbBleData_t             cmn;                  /*!< Common operation parameters. */

  BbBleCisCheckContOp_t   checkContOpCback;     /*!< Check whether to continue current operation callback. */
  BbBleCisCheckContOp_t   checkContOpPostCback; /*!< Check whether to continue current operation callback. */
  BbBleExec_t             execCback;            /*!< Execute callback. */
  BbBleExec_t             contExecCback;        /*!< Continue execute callback. */
  BbBleCisPostExec_t      postSubEvtCback;      /*!< Post subevent callback. */
  BbBleCancel_t           cancelCback;          /*!< Cancel callback. */
  BbBleTxDataComp_t       txDataCback;          /*!< Transmit completion callback. */
  BbBleRxDataComp_t       rxDataCback;          /*!< Receive completion callback. */

  /* Return parameters. */
  bool                    isFirstTs;          /*!< true for the first timestamp. */
  uint32_t                startTsUsec;        /*!< Start timestamp of the first received packet in microseconds. */
  uint32_t                rxTsUsec;           /*!< Timestamp of the received packet. */
  int8_t                  rssi;               /*!< RSSI of the last received packet. */
  uint8_t                 rxPhyOptions;       /*!< Rx PHY options. */
  uint32_t                rxSyncDelayUsec;    /*!< Receive timeout in microseconds. */
} BbBleSlvCisEvent_t;

/*! \brief      BIS master event operation data (\ref BB_BLE_OP_MST_BIS_EVENT). */
typedef struct
{
  BbBleData_t             cmn;                /*!< Common operation parameters. */

  uint32_t                rxSyncDelayUsec;    /*!< Receive timeout in microseconds. */
  BbBleExec_t             execCback;          /*!< Execute callback. */
  BbBleRxDataComp_t       rxDataCback;        /*!< Receive completion callback. */
  BbBleRxdCback_t         rxdCback;           /*!< Receiver diversity callback. */

  /* Return parameters. */
  uint32_t                startTsUsec;        /*!< First Rx timestamp. */
  int8_t                  rssi;               /*!< RSSI of the last received packet. */
} BbBleMstBisEvent_t;

/*! \brief      BIS slave event operation data (\ref BB_BLE_OP_SLV_BIS_EVENT). */
typedef struct
{
  BbBleData_t             cmn;                /*!< Common operation parameters. */

  BbBleExec_t             execCback;          /*!< Execute callback. */
  BbBleTxDataComp_t       txDataCback;        /*!< Transmit completion callback. */

  /* Return parameters. */
  /* None */
} BbBleSlvBisEvent_t;

/*! \brief      Continuous transmit operation data (\ref BB_BLE_OP_TEST_TX). */
typedef struct
{
  BbBleData_t             cmn;                /*!< Common operation parameters. */

  BbBleTxTestComp_t       testCback;          /*!< Test callback. */

  uint8_t                 *pTxBuf;            /*!< Transmit data buffer. */
  uint16_t                txLen;              /*!< Transmit data buffer length. */
  uint16_t                pktInterUsec;       /*!< Transmit packet interval. */
} BbBleTestTx_t;

/*! \brief      Continuous receive operation data (\ref BB_BLE_OP_TEST_RX). */
typedef struct
{
  BbBleData_t             cmn;                /*!< Common operation parameters. */

  uint32_t                rxSyncDelayUsec;    /*!< Synchronization delay in microseconds. */
  BbBleRxTestComp_t       testCback;          /*!< Test completion callback. */
  uint32_t                dueUsec;            /*!< Next expected packet reception time (microseconds). */
  uint8_t                 *pRxBuf;            /*!< Receive data buffer. */
  uint16_t                rxLen;              /*!< Receive data buffer length. */
  uint16_t                pktInterval;        /*!< Calculated packet interval from received packets (microseconds). */
  int8_t                  rssi;               /*!< RSSI of last received packet. */
  bool                    syncOnce;           /*!< Synchronization status: true if synchronized to packet timing. */
} BbBleTestRx_t;

/*! \brief       DAA EDS event operation data (\ref BB_BLE_OP_DAA_EDS_EVENT). */
typedef struct
{
  BbBleData_t             cmn;                /*!< Common operation parameters. */

  BbBleEdsComp_t          scanCback;          /*!< Scan complete callback. */

  uint16_t                durUsec;            /*!< EDS duration in microseconds. */
  uint64_t                defaultScanMask;    /*!< EDS scan list. */
  uint64_t                scanMask;           /*!< Temporary EDS scan list. */
} BbBleDaaEdsEvent_t;

/*! \brief       CS central event operation data (\ref BB_BLE_OP_INIT_CS_EVENT). */
typedef struct
{
  BbBleData_t             cmn;                /*!< Common operation parameters. */

  bool                    testMode;           /*!< True if CS Test command is being used. */
  uint16_t                totalDriffPpm;      /*!< Total clock driff. */

  /* Return parameters. */
  uint32_t                wwTotalUsec;        /*!< Window widening. */
} BbBleCsEvent_t;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief      Transmit data PDU at next transmit slot.
 *
 *  \param      descs       Array of transmit buffer descriptor.
 *  \param      cnt         Number of descriptors.
 *
 *  \note       This function is expected to be called during the call context of
 *              \ref BbBleSlvConnEvent_t::rxDataCback callback routine.
 */
/*************************************************************************************************/
void BbBleTxData(PalBbBleTxBufDesc_t descs[], uint8_t cnt);

/*************************************************************************************************/
/*!
 *  \brief      Set receive data buffer for next receive slot.
 *
 *  \param      pBuf        Receive data buffer.
 *  \param      len         Maximum length of data buffer.
 *
 *  \note       This function is expected to be called during the call context of
 *              \ref BbBleSlvConnEvent_t::rxDataCback callback routine.
 *
 *  \note       BB must always call the BbSlvConnEvent_t::rxDataCback callback routine of the
 *              currently executing BOD with the given buffer.
 */
/*************************************************************************************************/
void BbBleRxData(uint8_t *pBuf, uint16_t len);

/*************************************************************************************************/
/*!
 *  \brief      Transmit CIS PDU at next transmit slot.
 *
 *  \param      descs       Array of transmit buffer descriptor.
 *  \param      cnt         Number of descriptors.
 *
 *  \note       This function is expected to be called during the call context of
 *              \ref BbBleMstCisEvent_t::rxDataCback or \ref BbBleSlvCisEvent_t::rxDataCback
 *              callback routine.
 */
/*************************************************************************************************/
void BbBleCisTxData(PalBbBleTxBufDesc_t descs[], uint8_t cnt);

/*************************************************************************************************/
/*!
 *  \brief      Set receive data buffer for next receive slot.
 *
 *  \param      pBuf        Receive data buffer.
 *  \param      len         Maximum length of data buffer.
 *
 *  \note       This function is expected to be called during the call context of
 *              \ref BbBleSlvCisEvent_t::rxDataCback callback routine.
 *
 *  \note       BB must always call the BbBleSlvCisEvent_t::rxDataCback callback routine of the
 *              currently executing BOD with the given buffer.
 */
/*************************************************************************************************/
void BbBleCisRxData(uint8_t *pBuf, uint16_t len);


/*************************************************************************************************/
/*!
 *  \brief      Recover CIS data PDU transmission at next transmit slot.
 */
/*************************************************************************************************/
void BbBleCisRecoverTx(void);

/*************************************************************************************************/
/*!
 *  \brief      Recover CIS data PDU reception at next receive slot.
 */
/*************************************************************************************************/
void BbBleCisRecoverRx(void);

/*************************************************************************************************/
/*!
 *  \brief      Transmit BIS Data PDU at next transmit slot.
 *
 *  \param      descs       Array of transmit buffer descriptor.
 *  \param      cnt         Number of descriptors.
 *  \param      nextPduTime Next PDU time.
 *  \param      pNextChan   Next PDU channel.
 */
/*************************************************************************************************/
void BbBleBisTxData(PalBbBleTxBufDesc_t descs[], uint8_t cnt, uint32_t nextPduTime, PalBbBleChan_t *pNextChan);

/*************************************************************************************************/
/*!
 *  \brief      Set receive BIS Data PDU buffer for next receive slot.
 *
 *  \param      pBuf        Receive data buffer.
 *  \param      len         Maximum length of data buffer.
 *  \param      nextPduTime Next PDU time.
 *  \param      pNextChan   Next PDU channel.
 *  \param      reAcq       Rx train re-acquisition required.
 */
/*************************************************************************************************/
void BbBleBisRxData(uint8_t *pBuf, uint16_t len, uint32_t nextPduTime, PalBbBleChan_t *pNextChan, bool reAcq);

/*************************************************************************************************/
/*!
 *  \brief      Receive data re-acquisition.
 *
 *  \param      syncTime           Due time for the next Rx operation.
 *  \param      syncTimeoutUsec    Rx correlation timeout.
 *  \param      pChan              Channel parameters.
 *
 *  Update due time for next Rx operation. Called after a missed Rx operation for re-acquisition
 *  of the receive train.
 */
/*************************************************************************************************/
void BbBleBisRxDataReAcq(uint32_t syncTime, uint32_t syncTimeoutUsec, PalBbBleChan_t *pChan);

/*************************************************************************************************/
/*!
 *  \brief      Update sync timeout for same Rx operation with TIFS timing.
 *
 *  \param      syncTimeoutUsec    Rx correlation timeout.
 *
 *  Update sync timeout for same Rx operation with TIFS timing. Called after committing reception.
 */
/*************************************************************************************************/
void BbBleBisRxDataUpdateSyncTimeout(uint32_t syncTimeoutUsec);

/*************************************************************************************************/
/*!
 *  \brief      Execute auxiliary scanning master BOD.
 *
 *  \param      pBod    Pointer to the BOD to execute.
 *  \param      pBle    BLE operation parameters.
 */
/*************************************************************************************************/
void BbMstExecuteLinkedAuxScanOp(BbOpDesc_t *pBod, BbBleData_t *pBle);

/*************************************************************************************************/
/*!
 *  \brief      Tx completion for auxiliary scanning master operation.
 *
 *  \param      status      Completion status.
 *  \param      pBod        Pointer to the BOD
 *
 *  Setup for next action in the operation or complete the operation.
 *
 *  \return     true if BOD is complete, false otherwise.
 */
/*************************************************************************************************/
bool BbMstAuxScanTxCompHandler(BbOpDesc_t * const pBod, uint8_t status);

/*************************************************************************************************/
/*!
 *  \brief      Rx completion for auxiliary scanning master operation.
 *
 *  \param      pCur            Pointer to the BOD
 *  \param      status          Reception status.
 *  \param      rssi            RSSI value.
 *  \param      crc             CRC value.
 *  \param      timestamp       Start of packet timestamp in microseconds.
 *  \param      rxPhyOptions    Rx PHY options.
 *
 *  Setup for next action in the operation or complete the operation.
 *
 *  \return     true if BOD is complete, false otherwise.
 */
/*************************************************************************************************/
bool BbMstAuxScanRxCompHandler(BbOpDesc_t * const pCur, uint8_t status, int8_t rssi, uint32_t crc,
                               uint32_t timestamp, uint8_t rxPhyOptions);

/*************************************************************************************************/
/*!
 *  \brief      Tx completion for PAwR.
 *
 *  \param      pBuf          Rx buffer.
 *  \param      base          Timestamp base.
 *  \param      offset        Timestamp offset.
 *  \param      wwTotalUsec   Window widening value.
 *  \param      pRxQueueGetCb Buffer memory callback.
 *
 *  Setup for next action in the operation or complete the operation.
 *
 *  \return     true if BOD is complete, false otherwise.
 */
/*************************************************************************************************/
bool BbSlvPawrTxCompCback(uint8_t ** pBuf, uint32_t base, uint32_t offset, uint32_t wwTotalUsec, BbBleRxQueueGet_t pRxQueueGetCb);

/*************************************************************************************************/
/*!
 *  \brief      Tx callback for PAwR AUX_SYNC_SUBEVENT_RSP.
 *
 *  \param      pBod      Pointer to BOD.
 *  \param      base      Timestamp base.
 *  \param      offset    Timestamp offset
 *  \param      pDescs    Storage for BB descriptors.
 *  \param      numDescs  Number of elements in pDescs.
 *
 *  Setup for next action in the operation or complete the operation.
 */
/*************************************************************************************************/
void BbMstPawrTxSyncRspCback(BbOpDesc_t *pBod, uint32_t base, uint32_t offset, PalBbBleTxBufDesc_t *pDescs, uint8_t numDescs);

/*************************************************************************************************/
/*!
 *  \brief      Rx callback for PAwR Response Observation.
 *
 *  \param      pBod          Pointer to BOD.
 *  \param      base          Timestamp base.
 *  \param      offset        Timestamp offset.
 *  \param      pBuf          RX Buffer.
 *  \param      len           Length.
 *  \param      wwUsec        Window widening.
 *  \param      pRxQueueGetCb Buffer memory callback.
 *
 *  Setup for next action in the operation or complete the operation.
 */
/*************************************************************************************************/
void BbMstPawrRxRspObsCback(BbOpDesc_t *pBod, uint32_t base, uint32_t offset, uint8_t **pBuf, uint16_t len, uint32_t wwUsec, BbBleRxQueueGet_t pRxQueueGetCb);

/*************************************************************************************************/
/*!
 *  \brief      Tx completion for PAwR scan master operation.
 *
 *  \param      status      Completion status.
 *
 *  Setup for next action in the operation or complete the operation.
 */
/*************************************************************************************************/
void BbMstPerScanTxCompPawrCback(uint8_t status);

/*************************************************************************************************/
/*!
 *  \brief      Initialize central baseband.
 */
/*************************************************************************************************/
void BbPawrCentralInit(void);

/*************************************************************************************************/
/*!
 *  \brief      Initialize peripheral baseband.
 */
/*************************************************************************************************/
void BbPawrPeripheralInit(void);

/*************************************************************************************************/
/*!
 *  \brief      Rx completion for PAwR response Observation operation.
 *
 *  \param      pCur      Current BOD.
 *
 *  Setup for next action in the operation or complete the operation.
 */
/*************************************************************************************************/
bool BbPawrRspObservationCback(BbOpDesc_t *pCur);

/*************************************************************************************************/
/*!
 *  \brief      Rx Subevent Response for PAwR.
 *
 *  \param      pCur          Current BOD.
 *  \param      pPerScan      Master periodic scanning event operation data.
 *  \param      bodComplete   Current operation status.
 *  \param      timestamp     Start of packet timestamp in microseconds.
 *
 *  \return     Operation status.
 */
/*************************************************************************************************/
bool BbMstPawrRxRspObsAuxCback(BbOpDesc_t * const pCur, BbBleMstPerScanEvent_t * const pPerScan, bool bodComplete, uint32_t timestamp);

/*************************************************************************************************/
/*!
 *  \brief      Tx PAwR connection request response.
 *
 *  \param      pPerScan      Master periodic scanning event operation data.
 *  \param      bodCont       Current operation status.
 *
 *  \return     Operation status.
 */
/*************************************************************************************************/
bool BbMstPawrTxConReqCback(BbBleMstPerScanEvent_t * const pPerScan, bool bodCont);

/*************************************************************************************************/
/*!
 *  \brief      Tx PAwR Subevent Indicaton response.
 *
 *  \param      pCur          Current BOD.
 *  \param      pPerScan      Master periodic scanning event operation data.
 *  \param      bbPerScanBuf  Periodic scanning buffer
 *  \param      bodCont       Current operation status.
 *  \param      timestamp     Start of packet timestamp in microseconds.
 *
 *  \return     Operation status.
 */
/*************************************************************************************************/
bool BbMstPawrTxSubIndCback(BbOpDesc_t * const pCur, BbBleMstPerScanEvent_t * const pPerScan, uint8_t *bbPerScanBuf, bool bodCont, uint32_t timestamp);

/*************************************************************************************************/
/*!
 *  \brief      Rx Subevent Response for PAwR.
 *
 *  \param      pCur          Current BOD.
 *  \param      pAuxAdv       Auxiliary advertising context.
 *  \param      bodComplete   Current operation status.
 *
 *  \return     Operation status.
 */
/*************************************************************************************************/
bool BbSlvPawrRxSubRspCback(BbOpDesc_t * const pCur, BbBleSlvAuxAdvEvent_t * const pAuxAdv, bool bodComplete);

/*************************************************************************************************/
/*!
 *  \brief      First Rx Subevent Response for PAwR.
 *
 *  \param      pCur          Current BOD.
 *  \param      pAuxAdv       Auxiliary advertising context.
 *  \param      bodComplete   Current operation status.
 *
 *  \return     Operation status.
 */
/*************************************************************************************************/
bool BbSlvPawrRxAuxSubRspCback(BbOpDesc_t * const pCur, BbBleSlvAuxAdvEvent_t * const pAuxAdv, bool bodComplete);

/*************************************************************************************************/
/*!
 *  \brief      Tx response for PAwR.
 *
 *  \param      pCur          Current BOD.
 *  \param      pAuxAdv       Auxiliary advertising context.
 *
 *  \return     Operation status.
 */
/*************************************************************************************************/
bool BbSlvPawrTxAuxCback(BbOpDesc_t * const pCur, BbBleSlvAuxAdvEvent_t * const pAuxAdv);
/*! \} */    /* BB_API_BLE */

#ifdef __cplusplus
};
#endif

#endif /* BB_BLE_API_OP_H */
