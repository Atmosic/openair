/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      Link layer constant definitions.
 *
 *  Copyright (c) 2013-2019 Arm Ltd. All Rights Reserved.
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

#ifndef LL_DEFS_H
#define LL_DEFS_H

#include "wsf_types.h"
#include "wsf_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
  Constants
**************************************************************************************************/

/*** Version ***/

#define LL_VER_BT_CORE_SPEC_4_0     0x06    /*!< Bluetooth core specification 4.0 */
#define LL_VER_BT_CORE_SPEC_4_1     0x07    /*!< Bluetooth core specification 4.1 */
#define LL_VER_BT_CORE_SPEC_4_2     0x08    /*!< Bluetooth core specification 4.2 */
#define LL_VER_BT_CORE_SPEC_5_0     0x09    /*!< Bluetooth core specification 5.0 */
#define LL_VER_BT_CORE_SPEC_5_1     0x0A    /*!< Bluetooth core specification 5.1 */
#define LL_VER_BT_CORE_SPEC_5_2     0x0B    /*!< Bluetooth core specification 5.2 */
#define LL_VER_BT_CORE_SPEC_5_3     0x0C    /*!< Bluetooth core specification 5.3 */
#define LL_VER_BT_CORE_SPEC_5_4     0x0D    /*!< Bluetooth core specification 5.4 */
#define LL_VER_BT_CORE_SPEC_6_0     0x0E    /*!< Bluetooth core specification 6.0 */

/*** Common ***/

#define LL_RSSI_MIN                 -127    /*!< Minimum RSSI value. */
#define LL_RSSI_MAX                 20      /*!< Maximum RSSI value. */
#define LL_RSSI_NOT_AVAIL           127     /*!< RSSI is not available. */

#define LL_CRC_LEN                  3U      /*!< CRC length. */
#define LL_AA_LEN                   4U      /*!< Access address length. */
#define LL_PREAMBLE_LEN_1M          1U      /*!< Preamble length (LE 1M PHY). */
#define LL_PREAMBLE_LEN_2M          2U      /*!< Preamble length (LE 2M PHY). */
#define LL_PREAMBLE_LEN_CODED_BITS  10U     /*!< Preamble length (LE Coded PHY). */
#define LL_CI_LEN_BITS              2U      /*!< Coding indicator length (LE Coded PHY). */
#define LL_TERM1_LEN_BITS           3U      /*!< TERM1 length (LE Coded PHY). */
#define LL_TERM2_LEN_BITS           3U      /*!< TERM2 length (LE Coded PHY). */

#define LL_RAND_ADDR_TYPE_MASK      UINT64_C(0xC00000000000)    /*!< BD Random Address type mask. */
#define LL_RAND_ADDR_TYPE_STATIC    UINT64_C(0xC00000000000)    /*!< Static Random Address type. */
#define LL_RAND_ADDR_TYPE_RPA       UINT64_C(0x400000000000)    /*!< Resolvable Private Address type. */
#define LL_RAND_ADDR_TYPE_NRPA      UINT64_C(0x000000000000)    /*!< Non-Resolvable Private Address type. */

/*** Advertising PDU ***/

/*! \brief      Advertising channel PDU types. */
enum
{
  /* --- Core Spec 4.0 --- */
  LL_PDU_ADV_IND                = 0,    /*!< Connectable undirected advertising PDU. */
  LL_PDU_ADV_DIRECT_IND         = 1,    /*!< Connectable directed advertising PDU. */
  LL_PDU_ADV_NONCONN_IND        = 2,    /*!< Non-connectable undirected advertising PDU. */
  LL_PDU_SCAN_REQ               = 3,    /*!< Scan request PDU. */
  LL_PDU_SCAN_RSP               = 4,    /*!< Scan response PDU. */
  LL_PDU_CONNECT_IND            = 5,    /*!< Connect indication PDU. */
  LL_PDU_ADV_SCAN_IND           = 6,    /*!< Scannable undirected advertising PDU. */
  /* --- Core Spec 5.0 --- */
  LL_PDU_AUX_SCAN_REQ           = 3,    /*!< Auxiliary scan request PDU. */
  LL_PDU_AUX_CONNECT_REQ        = 5,    /*!< Auxiliary connect request PDU. */
  LL_PDU_ADV_EXT_IND            = 7,    /*!< Extended advertising PDU. */
  LL_PDU_AUX_ADV_IND            = 7,    /*!< Auxiliary advertising PDU. */
  LL_PDU_AUX_SCAN_RSP           = 7,    /*!< Auxiliary scan response PDU. */
  LL_PDU_AUX_SYNC_IND           = 7,    /*!< Auxiliary synchronize PDU. */
  LL_PDU_AUX_CHAIN_IND          = 7,    /*!< Auxiliary chain PDU. */
  LL_PDU_AUX_CONNECT_RSP        = 8,    /*!< Auxiliary connect response PDU. */
  /* --- Core Spec 5.4 --- */
  LL_PDU_AUX_SYNC_SUBEVENT_IND  = 7,    /*!< Auxiliary synchronize subevent PDU. */
  LL_PDU_AUX_SYNC_SUBEVENT_RSP  = 7,    /*!< Auxiliary synchronize subevent response PDU. */
  /* --- Core Spec 6.0 --- */
  LL_PDU_ADV_DECISION_IND       = 9     /*!< Advertising decision PDU. */
};

#define LL_SCAN_REQ_PDU_LEN     12      /*!< Size of a scan request PDU. */
#define LL_CONN_IND_PDU_LEN     34      /*!< Size of a connect indication PDU. */
#define LL_CONN_RSP_PDU_LEN     14      /*!< Size of an auxiliary connect response PDU. */

#define LL_CHAN_ADV_MIN_IDX     37      /*!< Minimum advertising channel index. */
#define LL_CHAN_ADV_MAX_IDX     39      /*!< Maximum advertising channel index. */
#define LL_NUM_CHAN_ADV         3U       /*!< Total number of advertising channels. */
#define LL_NUM_CHAN_DATA        37      /*!< Total number of data channels. */
#define LL_NUM_CHAN             40      /*!< Total number of channels. */

#define LL_ADVBU_MAX_LEN        31      /*!< Maximum advertising channel host data length. */
#define LL_ADVB_MAX_LEN         39      /*!< Maximum advertising channel PDU length. */
#define LL_ADVB_MIN_LEN         (LL_ADVB_MAX_LEN - LL_ADVBU_MAX_LEN)    /*!< Minimum advertising channel packet length. */
#define LL_ADVB_MAX_TIME_1M     ((LL_BLE_US_PER_BYTE_1M * (LL_ADVB_MAX_LEN - LL_ADV_HDR_LEN)) + LL_MIN_PKT_TIME_US_1M)
                                        /*!< Maximum time for a 1M advertising channel PDU. */
#define LL_ADVB_MAX_TIME_2M     ((LL_BLE_US_PER_BYTE_2M * (LL_ADVB_MAX_LEN - LL_ADV_HDR_LEN)) + LL_MIN_PKT_TIME_US_2M)
                                        /*!< Maximum time for a 2M advertising channel PDU. */
#define LL_ADVB_MAX_TIME_S2     ((LL_BLE_US_PER_BYTE_CODED_S2 * (LL_ADVB_MAX_LEN - LL_ADV_HDR_LEN)) + LL_MIN_PKT_TIME_US_CODED_S2)
                                        /*!< Maximum time for a Coded S2 advertising channel PDU. */
#define LL_ADVB_MAX_TIME_S8     ((LL_BLE_US_PER_BYTE_CODED_S8 * (LL_ADVB_MAX_LEN - LL_ADV_HDR_LEN)) + LL_MIN_PKT_TIME_US_CODED_S8)
                                        /*!< Maximum time for a Coded S8 advertising channel PDU. */

#define LL_ADV_PKT_MAX_USEC     LL_ADVB_MAX_TIME_1M /*!< Maximum time in microseconds for an advertising packet. */
#define LL_SCAN_REQ_MAX_USEC    ((8 * (LL_ADV_PREFIX_LEN + LL_SCAN_PREFIX_LEN)) + LL_MIN_PKT_TIME_US_1M)
                                                    /*!< Maximum time in microseconds for a scan request packet. */
#define LL_SCAN_RSP_MAX_USEC    LL_ADVB_MAX_TIME_1M /*!< Maximum time in microseconds for a scan response packet. */

#define LL_ADV_HDR_LEN          2U      /*!< Advertising channel header length. */
#define LL_ADV_HDR_TYPE_OFFS    0U      /*!< Advertising header type offset. */
#define LL_ADV_HDR_TYPE_MSK     0x0F    /*!< Advertising header type mask. */
#define LL_ADV_HDR_LEN_OFFS     1U      /*!< Advertising header length offset. */
#define LL_ADV_HDR_LEN_MSK      0x3FU   /*!< Advertising header length mask for 4.2. */
#define LL_ADV_HDR_CP_MSK       0x40    /*!< Advertising header CP Mask for 5.1. */
#define LL_ADV_EXT_HDR_LEN_MSK  0xFFU   /*!< Advertising extension header length mask for 5.0. */
#define LL_ADV_PREFIX_LEN       6U      /*!< Advertising PDU payload prefix length (AdvA). */
#define LL_SCAN_PREFIX_LEN      6U      /*!< Scan request/response PDU payload prefix length (AdvA). */

#define LL_ADV_ACCESS_ADDR      UINT32_C(0x8E89BED6)    /*!< Advertising channel access address. */
#define LL_ADV_CRC_INIT         UINT32_C(0x555555)      /*!< Advertising CRC initial value. */

#define LL_DIR_ADV_INTER_TICKS  6       /*!< Advertising interval between directed advertising events (3.75 ms). */
#define LL_DIR_ADV_DUR_TICKS    2048    /*!< Maximum high duty cycle directed advertising duration (1.28 seconds). */

/*! \brief      Extended header bit definition. */
enum
{
  LL_EXT_HDR_ADV_ADDR_BIT   = (1 << 0), /*!< Extended header AdvA bit. */
  LL_EXT_HDR_TGT_ADDR_BIT   = (1 << 1), /*!< Extended header TargetA bit. */
  LL_EXT_HDR_CTE_INFO_BIT   = (1 << 2), /*!< Extended header CTEInfo bit. */
  LL_EXT_HDR_ADI_BIT        = (1 << 3), /*!< Extended header AdvDataInfo bit. */
  LL_EXT_HDR_AUX_PTR_BIT    = (1 << 4), /*!< Extended header AuxPtr bit. */
  LL_EXT_HDR_SYNC_INFO_BIT  = (1 << 5), /*!< Extended header SyncInfo bit. */
  LL_EXT_HDR_TX_PWR_BIT     = (1 << 6), /*!< Extended header TxPower bit. */
};

#define LL_MAX_ADV_HANDLE             0xEFU    /*!< Maximum advertising handle. */
#define LL_MAX_ADV_SID                0x0FU    /*!< Maximum advertising SID */

#define LL_DID_NOT_PRESENT      0xFFF    /*!< Periodic advertising data DID was not present. */

#define LL_EXT_ADV_HDR_MIN_LEN      1U       /*!< Minimum extended advertising header length (ExtHdrLen and AdvMode fields). */
#define LL_EXT_ADV_HDR_MAX_LEN      64U      /*!< Maximum extended advertising header length (ExtHdrLen, AdvMode fields and Extended header). */
#define LL_EXT_ADVBU_MAX_LEN        251U     /*!< Maximum extended advertising channel PDU host data length. */
#define LL_EXT_ADVB_MAX_LEN         257U     /*!< Maximum extended advertising channel PDU length. */

#define LL_EXT_HDR_FLAG_LEN         1       /*!< Length of extended header flag field */
#define LL_EXT_HDR_ADVA_LEN         6       /*!< Length of extended header AdvA field */
#define LL_EXT_HDR_TARGETA_LEN      6       /*!< Length of extended header TargetA field */
#define LL_EXT_HDR_CTE_INFO_LEN     1       /*!< Length of extended header CTEInfo field */
#define LL_EXT_HDR_ADI_LEN          2       /*!< Length of extended header AdvData Info (ADI) field */
#define LL_EXT_HDR_AUX_PTR_LEN      3       /*!< Length of extended header AuxPtr field */
#define LL_EXT_HDR_SYNC_INFO_LEN    18      /*!< Length of extended header SyncInfo field */
#define LL_EXT_HDR_TX_POWER_LEN     1       /*!< Length of extended header TxPower field */

#define LL_EXT_HDR_ACAD_MAX_LEN     LL_EXT_ADV_HDR_MAX_LEN - LL_EXT_ADV_HDR_MIN_LEN - LL_EXT_HDR_FLAG_LEN /*!< Maximum possible ACAD length (Max extended header minus ExtHdrLen, AdvMode, and extended header flag field. */

#define LL_EXT_ADVB_MAX_TIME_1M     ((LL_BLE_US_PER_BYTE_1M * (LL_EXT_ADVB_MAX_LEN - LL_ADV_HDR_LEN)) + LL_MIN_PKT_TIME_US_1M)
                                        /*!< Maximum time for a 1M advertising channel PDU. */
#define LL_EXT_ADVB_NORMAL_TIME_1M  ((LL_BLE_US_PER_BYTE_1M * (LL_EXT_ADVB_NORMAL_LEN - LL_ADV_HDR_LEN)) + LL_MIN_PKT_TIME_US_1M)
                                        /*!< Time for a 1M advertising channel PDU with normal length. */
#define LL_EXT_ADVB_MAX_TIME_2M     ((LL_BLE_US_PER_BYTE_2M * (LL_EXT_ADVB_MAX_LEN - LL_ADV_HDR_LEN)) + LL_MIN_PKT_TIME_US_2M)
                                        /*!< Maximum time for a 2M advertising channel PDU. */
#define LL_EXT_ADVB_NORMAL_TIME_2M  ((LL_BLE_US_PER_BYTE_2M * (LL_EXT_ADVB_NORMAL_LEN - LL_ADV_HDR_LEN)) + LL_MIN_PKT_TIME_US_2M)
                                        /*!< Time for a 1M advertising channel PDU with normal length. */
#define LL_EXT_ADVB_MAX_TIME_S2     ((LL_BLE_US_PER_BYTE_CODED_S2 * (LL_EXT_ADVB_MAX_LEN - LL_ADV_HDR_LEN)) + LL_MIN_PKT_TIME_US_CODED_S2)
                                        /*!< Maximum time for a Coded S2 advertising channel PDU. */
#define LL_EXT_ADVB_MAX_TIME_S8     ((LL_BLE_US_PER_BYTE_CODED_S8 * (LL_EXT_ADVB_MAX_LEN - LL_ADV_HDR_LEN)) + LL_MIN_PKT_TIME_US_CODED_S8)
                                        /*!< Maximum time for a Coded S8 advertising channel PDU. */

#define LL_AUX_PTR_MAX_USEC     2457300 /*!< Maximum AuxPtr offset value in microseconds. */

#define LL_SYNC_MIN_TIMEOUT     0x000A  /*!< Minimum synchronization timeout. */
#define LL_SYNC_MAX_TIMEOUT     0x4000  /*!< Maximum synchronization timeout. */
#define LL_SYNC_MAX_SKIP        0x01F3  /*!< Maximum synchronization skip. */
#define LL_SYNC_MAX_HANDLE      0x0EFF  /*!< Maximum synchronization handle. */
#define LL_CTE_DTM_HANDLE       0x0FFF  /*!< CTE DTM handle for IQ reports. */

#define LL_PER_ADV_INT_MIN      0x0006  /*!< Minimum periodic advertising interval. */

#define LL_SYNC_OFFS_ADJUST_USEC  2457600U   /*!< Sync offset adjust of 2.4576 seconds. */
#define LL_SYNC_INFO_LEN        18      /*!< Size of SyncInfo field. */

#define LL_CTE_TIME_MSK               0x1FU   /*!< CTE Info CTE time mask. */
#define LL_CTE_TYPE_MSK               0x03U   /*!< CTE Info CTE type mask. */
#define LL_CTE_TYPE_BIT_POS              6    /*!< CTE Info CTE type bit position. */
#define LL_CTE_MAX_SAMPLE_COUNT       0x10    /*!< Maximum sample count of a periodic advertising event. */

/*! \brief      CTE types parameter bitfield. */
enum
{
  LL_CTE_TYPES_AOA_BIT      = (1 << 0),        /*!< CTE Type bit for AoA. */
  LL_CTE_TYPES_AOD_1US_BIT  = (1 << 1),        /*!< CTE Type bit for AoD 1US slots. */
  LL_CTE_TYPES_AOD_2US_BIT  = (1 << 2),        /*!< CTE Type bit for AoD 2US slots. */

  LL_CTE_TYPES_ALL_BITS     = LL_CTE_TYPES_AOA_BIT | LL_CTE_TYPES_AOD_1US_BIT | LL_CTE_TYPES_AOD_2US_BIT
};

/*! \brief      CTE Supported switching rates bitfield. */
enum
{
  LL_CTE_SWITCH_1US_AOD_TX  = (1 << 0),
  LL_CTE_SWITCH_1US_AOD_RX  = (1 << 1),
  LL_CTE_SWITCH_1US_AOA     = (1 << 2),

  LL_CTE_SWITCH_ALL_SUP     = LL_CTE_SWITCH_1US_AOD_TX | LL_CTE_SWITCH_1US_AOD_RX | LL_CTE_SWITCH_1US_AOA
};

/*! \brief      Sync CTE Type bitfield. */
enum
{
  LL_CTE_EXCLUDE_AOA     = (1 << 0),
  LL_CTE_EXCLUDE_AOD_1US = (1 << 1),
  LL_CTE_EXCLUDE_AOD_2US = (1 << 2),
  LL_CTE_EXCLUDE_RFU     = (1 << 3),
  LL_CTE_EXCLUDE_NO_CTE  = (1 << 4),

  LL_CTE_EXCLUSION_ALL_BITS = LL_CTE_EXCLUDE_AOA | LL_CTE_EXCLUDE_AOD_1US | LL_CTE_EXCLUDE_AOD_2US | LL_CTE_EXCLUDE_RFU | LL_CTE_EXCLUDE_NO_CTE
};

#define LL_MAX_NUM_SUBEVENT           (uint8_t)0xF     /*!< Maximum number of subevent data in a command. */
#define LL_MAX_PAWR_SUBEVT            (uint8_t)0x40    /*!< Maximum number of PAwR subevents. */
#define LL_MIN_PAWR_SUBEVT_INT        (uint8_t)0x06    /*!< Minimum PAwR subevent interval. */
#define LL_MAX_PAWR_RESP_SLOT_DELAY   (uint8_t)0xFE    /*!< Maximum PAwR response slot delay. */
#define LL_MIN_PAWR_RESP_SLOT_DELAY   (uint8_t)0x01    /*!< Maximum PAwR response slot delay. */
#define LL_MAX_PAWR_RESP_SLOT_SPACING (uint8_t)0xFF    /*!< Maximum PAwR response slot spacing. */
#define LL_MIN_PAWR_RESP_SLOT_SPACING (uint8_t)0x02    /*!< Maximum PAwR response slot spacing. */
#define LL_MAX_PAWR_NUM_RESP_SLOTS    (uint8_t)0xFF    /*!< Maximum PAwR number of response slots. */
#define LL_MIN_PAWR_NUM_RESP_SLOTS    (uint8_t)0x00    /*!< Minimum PAwR number of response slots. */
#define LL_MAX_PAWR_SUB_DATA_LEN      (uint8_t)0xFB    /*!< Maximum PAwR subevent data length. */
#define LL_MAX_PAWR_RESP_DATA_LEN     (uint8_t)0xFB    /*!< Maximum PAwR response data length. */
#define LL_SUBEVT_CTR_PAWR_MSK        (uint8_t)0x7F    /*!< PAwR subevent counter mask. */

/*! \brief      Periodic sync transfer receive mode. */
enum
{
  LL_SYNC_TRSF_MODE_OFF           = 0,    /*!< Periodic sync transfer receive is disabled. */
  LL_SYNC_TRSF_MODE_REP_DISABLED  = 1,    /*!< Periodic sync transfer receive is enabled, report event is disabled. */
  LL_SYNC_TRSF_MODE_REP_ENABLED   = 2,    /*!< Periodic sync transfer receive is enabled, report event is enabled. */
  LL_SYNC_TRSF_MODE_DUP_FILTERED  = 3,    /*!< Periodic sync transfer receive is enabled, report event is enabled, duplicates will be filtered if ADI field is present. */
  LL_SYNC_TRSF_MAX_MODE           = LL_SYNC_TRSF_MODE_DUP_FILTERED
};

/*** Data PDU ***/

/*! \brief      Data channel LL Control PDU types. */
enum
{
  /* --- Core Spec 4.0 --- */
  LL_PDU_CONN_UPDATE_IND        = 0x00, /*!< Connection update indication PDU. */
  LL_PDU_CHANNEL_MAP_IND        = 0x01, /*!< Channel map indication PDU. */
  LL_PDU_TERMINATE_IND          = 0x02, /*!< Terminate indication PDU. */
  LL_PDU_ENC_REQ                = 0x03, /*!< Encryption request PDU. */
  LL_PDU_ENC_RSP                = 0x04, /*!< Encryption response PDU. */
  LL_PDU_START_ENC_REQ          = 0x05, /*!< Start encryption request PDU. */
  LL_PDU_START_ENC_RSP          = 0x06, /*!< Start encryption response PDU. */
  LL_PDU_UNKNOWN_RSP            = 0x07, /*!< Unknown response PDU. */
  LL_PDU_FEATURE_REQ            = 0x08, /*!< Feature request PDU. */
  LL_PDU_FEATURE_RSP            = 0x09, /*!< Feature response PDU. */
  LL_PDU_PAUSE_ENC_REQ          = 0x0A, /*!< Pause encryption request PDU. */
  LL_PDU_PAUSE_ENC_RSP          = 0x0B, /*!< Pause encryption response PDU. */
  LL_PDU_VERSION_IND            = 0x0C, /*!< Version indication PDU. */
  LL_PDU_REJECT_IND             = 0x0D, /*!< Reject indication PDU. */
  /* --- Core Spec 4.2 --- */
  LL_PDU_PER_FEATURE_REQ        = 0x0E, /*!< Slave feature request PDU. */
  LL_PDU_CONN_PARAM_REQ         = 0x0F, /*!< Connection parameter request PDU. */
  LL_PDU_CONN_PARAM_RSP         = 0x10, /*!< Connection parameter response PDU. */
  LL_PDU_REJECT_EXT_IND         = 0x11, /*!< Reject extended indication PDU. */
  LL_PDU_PING_REQ               = 0x12, /*!< Ping request PDU. */
  LL_PDU_PING_RSP               = 0x13, /*!< Ping response PDU. */
  LL_PDU_LENGTH_REQ             = 0x14, /*!< Data length request PDU. */
  LL_PDU_LENGTH_RSP             = 0x15, /*!< Data length response PDU. */
  /* --- Core Spec 5.0 --- */
  LL_PDU_PHY_REQ                = 0x16, /*!< PHY request PDU. */
  LL_PDU_PHY_RSP                = 0x17, /*!< PHY response PDU. */
  LL_PDU_PHY_UPDATE_IND         = 0x18, /*!< PHY update indication PDU. */
  LL_PDU_MIN_USED_CHAN_IND      = 0x19, /*!< Minimum used channels indication PDU. */
  /* --- Core Spec 5.1 --- */
  LL_PDU_CTE_REQ                = 0x1A, /*!< Consonant tone request PDU. */
  LL_PDU_CTE_RSP                = 0x1B, /*!< Consonant tone response PDU. */
  LL_PDU_PERIODIC_SYNC_IND      = 0x1C, /*!< Periodic sync indication PDU. */
  /* --- Core Spec 5.2 --- */
  LL_PDU_PEER_SCA_REQ           = 0x1D, /*!< Peer SCA request PDU. */
  LL_PDU_PEER_SCA_RSP           = 0x1E, /*!< Peer SCA response PDU. */
  LL_PDU_CIS_REQ                = 0x1F, /*!< CIS request PDU. */
  LL_PDU_CIS_RSP                = 0x20, /*!< CIS response PDU. */
  LL_PDU_CIS_IND                = 0x21, /*!< CIS indication PDU. */
  LL_PDU_CIS_TERM_IND           = 0x22, /*!< CIS terminate indication PDU. */
  LL_PDU_PWR_CTRL_REQ           = 0x23, /*!< Power Control request. */
  LL_PDU_PWR_CTRL_RSP           = 0x24, /*!< Power Control response. */
  LL_PDU_PWR_CHANGE_IND         = 0x25, /*!< Transmit power change indication PDU. */
  /* --- Core Spec 5.3 --- */
  LL_PDU_SUBRATE_REQ            = 0x26, /*!< Connection subrate request PDU. */
  LL_PDU_SUBRATE_IND            = 0x27, /*!< Connection subrate indication PDU. */
  LL_PDU_CH_REPORTING_IND       = 0x28, /*!< Channel class reporting indication PDU. */
  LL_PDU_CH_STATUS_IND          = 0x29, /*!< Channel status indication PDU. */
  /* --- Core Spec 5.4  --- */
  LL_PDU_PERIODIC_SYNC_WR_IND   = 0x2A, /*!< Periodic sync indication with response PDU. */
  /* --- Core Spec 6.0 --- */
  LL_PDU_FEATURE_EXT_REQ        = 0x2B, /*!< Extended feature request PDU. */
  LL_PDU_FEATURE_EXT_RSP        = 0x2C, /*!< Extended feature response PDU. */
  LL_PDU_CS_SEC_RSP             = 0x2D, /*< CS security response PDU. */
  LL_PDU_CS_CAPABILITIES_REQ    = 0x2E, /*< CS capabilities request PDU.*/
  LL_PDU_CS_CAPABILITIES_RSP    = 0x2F, /*< CS capabilities response PDU. */
  LL_PDU_CS_CONFIG_REQ          = 0x30, /*< CS configuration request PDU. */
  LL_PDU_CS_CONFIG_RSP          = 0x31, /*< CS configuration response PDU. */
  LL_PDU_CS_REQ                 = 0x32, /*< CS request PDU. */
  LL_PDU_CS_RSP                 = 0x33, /*< CS response PDU. */
  LL_PDU_CS_IND                 = 0x34, /*< CS indication PDU. */
  LL_PDU_CS_TERMINATE_REQ       = 0x35, /*< CS terminate request PDU. */
  LL_PDU_CS_FAE_REQ             = 0x36, /*< CS FAE request PDU. */
  LL_PDU_CS_FAE_RSP             = 0x37, /*< CS FAE response PDU. */
  LL_PDU_CS_CHANNEL_MAP_IND     = 0x38, /*< CS channel map indication PDU. */
  LL_PDU_CS_SEC_REQ             = 0x39, /*< CS security request PDU. */
  LL_PDU_CS_TERMINATE_RSP       = 0x3A, /*< CS terminate response PDU. */
  LL_PDU_FRAME_SPACE_REQ        = 0x3B, /*< Frame space update request PDU. */
  LL_PDU_FRAME_SPACE_RSP        = 0x3C, /*< Frame space update response PDU. */
  LL_PDU_UNSPECIFIED            = 0xFF  /*!< Unspecified PDU. */
};

/* Data PDU length */

/* --- Core Spec 4.0 --- */
#define LL_CONN_UPD_IND_PDU_LEN       12      /*!< Connection update indication PDU length. */
#define LL_CHAN_MAP_IND_PDU_LEN       8       /*!< Channel map indication PDU length. */
#define LL_TERMINATE_IND_PDU_LEN      2       /*!< Terminate indication PDU length. */
#define LL_ENC_REQ_LEN                23      /*!< Encryption request PDU length. */
#define LL_ENC_RSP_LEN                13      /*!< Encryption response PDU length. */
#define LL_START_ENC_LEN              1       /*!< Start encryption request/response PDU length. */
#define LL_UNKNOWN_RSP_LEN            2       /*!< Unknown response PDU length. */
#define LL_FEATURE_PDU_LEN            9       /*!< Feature request/response PDU length. */
#define LL_PAUSE_ENC_LEN              1       /*!< Pause encryption request/response PDU length. */
#define LL_VERSION_IND_PDU_LEN        6       /*!< Version indication PDU length. */
#define LL_REJECT_IND_PDU_LEN         2       /*!< Reject indication PDU length. */
/* --- Core Spec 4.2 --- */
#define LL_CONN_PARAM_PDU_LEN         24      /*!< Connection parameter request or response PDU length. */
#define LL_REJECT_EXT_IND_PDU_LEN     3       /*!< Reject extended indication PDU length. */
#define LL_PING_PDU_LEN               1       /*!< Ping request/response PDU length. */
#define LL_DATA_LEN_PDU_LEN           9       /*!< Data length request or response PDU length. */
/* --- Core Spec 5.0 --- */
#define LL_PHY_PDU_LEN                3       /*!< PHY request/response PDU length. */
#define LL_PHY_UPD_IND_PDU_LEN        5       /*!< PHY update indication PDU length. */
#define LL_MIN_USED_CHAN_PDU_LEN      3       /*!< Minimum used channels indication PDU length. */
/* --- Core Spec 5.1 --- */
#define LL_PERIODIC_SYNC_PDU_LEN      35      /*!< Periodic sync indication PDU length. */
#define LL_CTE_REQ_LEN                2       /*!< CTE Request PDU length. */
#define LL_CTE_RSP_LEN                1       /*!< CTE Response PDU length. */
/* --- Core Spec 5.2 --- */
#define LL_PEER_SCA_REQ_LEN           2       /*!< Peer SCA request PDU length. */
#define LL_PEER_SCA_RSP_LEN           2       /*!< Peer SCA response PDU length. */
#define LL_CIS_REQ_LEN                36      /*!< CIS request PDU length. */
#define LL_CIS_RSP_LEN                9       /*!< CIS response PDU length. */
#define LL_CIS_IND_LEN                16      /*!< CIS indication PDU length. */
#define LL_CIS_TERM_LEN               4       /*!< CIS termination PDU length. */
#define LL_CIS_SDU_CONFIG_REQ_LEN     13      /*!< CIS SDU config request PDU length. */
#define LL_CIS_SDU_CONFIG_RSP_LEN     4       /*!< CIS SDU config response PDU length. */
#define LL_PWR_CTRL_REQ_LEN           4       /*!< Power Control request PDU length. */
#define LL_PWR_CTRL_RSP_LEN           5       /*!< Power Control response PDU length. */
#define LL_PWR_CHANGE_IND_LEN         5       /*!< Power Indication PDU length. */

#define LL_EMPTY_PDU_LEN              2       /*!< Length of an empty data PDU. */

#define LL_DATA_HDR_LEN               2       /*!< Data channel header length. */
#define LL_DATA_HDR_MAX_LEN           3       /*!< Data channel header max length (with CTE field). */
#define LL_DATA_MIC_LEN               4U       /*!< Data channel PDU MIC length. */

#define LL_DATA_HDR_LLID_MSK          0x03U    /*!< Data PDU LLID mask. */
#define LL_DATA_HDR_CP_MSK            0x20U    /*!< Data PDU CP bit mask. */
#define LL_DATA_HDR_LEN_MSK           0xFFU    /*!< Data header length mask. BLE 4.2 data len extension allows 8 bits. */

#define LL_MAX_NUM_CHAN_DATA          37      /*!< Maximum number of used data channels. */
#define LL_MIN_NUM_CHAN_DATA          2       /*!< Minimum number of used data channels. */
/* --- Core Spec 5.3 --- */
#define LL_SUBRATE_REQ_LEN            11      /*!< LL Connection subrating request PDU length. */
#define LL_SUBRATE_IND_LEN            11      /*!< LL Connection subrating indication PDU length. */
#define LL_CH_REPORTING_LEN           4       /*!< Channel class reporting indication PDU length. */
#define LL_CH_STATUS_LEN              11      /*!< Channel status indication PDU length. */
/* --- Core Spec 5.4 --- */
#define LL_PERIODIC_SYNC_WR_PDU_LEN   43      /*!< Periodic sync with response indication PDU length. */
/* --- Core Spec 6.0 --- */
#define LL_FEATURE_EXT_PDU_LEN        27      /*!< Extended feature request/response PDU length. */
#define LL_CS_SEC_LEN                 21      /*< CS security request/response PDU length. */
#define LL_CS_CAPABILITIES_LEN        26      /*< CS capabilities request/response PDU length.*/
#define LL_CS_CONFIG_REQ_LEN          28      /*< CS configuration request PDU length. */
#define LL_CS_CONFIG_RSP_LEN          2       /*< CS configuration response PDU length. */
#define LL_CS_REQ_LEN                 29      /*< CS request PDU length. */
#define LL_CS_RSP_LEN                 22      /*< CS response PDU length. */
#define LL_CS_IND_LEN                 19      /*< CS indication PDU length. */
#define LL_CS_TERMINATE_REQ_LEN       5       /*< CS terminate request PDU length. */
#define LL_CS_FAE_REQ_LEN             1       /*< CS FAE request PDU length. */
#define LL_CS_FAE_RSP_LEN             73      /*< CS FAE response PDU length. */
#define LL_CS_CHANNEL_MAP_IND_LEN     13      /*< CS channel map indication PDU length. */
#define LL_CS_TERMINATE_RSP_LEN       5       /*< CS terminate response PDU length. */
#define LL_FRAME_SPACE_REQ_LEN        8       /*< CS frame space request PDU length. */
#define LL_FRAME_SPACE_RSP_LEN        6       /*< CS frame space response PDU length. */

/*! \brief      Data PDU LLID types. */
enum
{
  LL_LLID_VS_PDU                    = 0x00,   /*!< Vendor specific PDU. */
  /* N.B. next two enumerations intentionally use identical values. */
  LL_LLID_EMPTY_PDU                 = 0x01,   /*!< Empty PDU. */
  LL_LLID_CONT_PDU                  = 0x01,   /*!< Data PDU: continuation fragment of an L2CAP message. */
  LL_LLID_START_PDU                 = 0x02,   /*!< Data PDU: start of an L2CAP message or a complete L2CAP message with no fragmentation. */
  LL_LLID_CTRL_PDU                  = 0x03,   /*!< Control PDU. */
};

/*** Encryption ***/

#define LL_ECC_KEY_LEN                32      /*!< ECC key length. */

#define LL_DEF_RES_ADDR_TO_SEC        900     /*!< Default resolvable address timeout in seconds. */

#define LL_RAND_LEN                   8       /*!< Length of random number */
#define LL_KEY_LEN                    16      /*!< Encryption key length. */
#define LL_SKD_LEN                    LL_KEY_LEN      /*!< Session key diversifier length. */
#define LL_IV_LEN                     8       /*!< Initialization vector length. */
#define LL_BC_LEN                     LL_KEY_LEN      /*!< Broadcast code length. */
#define LL_GIV_LEN                    8       /*!< GIV length. */
#define LL_GSKD_LEN                   16      /*!< GSKD code length. */

#define LL_DEF_AUTH_TO_MS             30000   /*!< Default authentication timeout in milliseconds. */

/*** LLCP ***/

#define LL_DATA_LEN_TO_TIME_1M(len, enc)        (uint32_t)((LL_BLE_US_PER_BYTE_1M * ((len) + ((enc) ? LL_DATA_MIC_LEN : 0))) + LL_MIN_PKT_TIME_US_1M)
                                              /*!< Convert data length to time. */
#define LL_DATA_LEN_TO_TIME_2M(len, enc)        (uint32_t)((LL_BLE_US_PER_BYTE_2M * ((len) + ((enc) ? LL_DATA_MIC_LEN : 0))) + LL_MIN_PKT_TIME_US_2M)
                                              /*!< Convert data length to time. */
#define LL_DATA_LEN_TO_TIME_CODED_S8(len, enc)  (uint32_t)((LL_BLE_US_PER_BYTE_CODED_S8 * ((len) + ((enc) ? LL_DATA_MIC_LEN : 0))) + LL_MIN_PKT_TIME_US_CODED_S8)
                                              /*!< Convert data length to time. */
#define LL_DATA_LEN_TO_TIME_CODED_S2(len, enc)  (uint32_t)((LL_BLE_US_PER_BYTE_CODED_S2 * ((len) + ((enc) ? LL_DATA_MIC_LEN : 0))) + LL_MIN_PKT_TIME_US_CODED_S2)
                                              /*!< Convert data length to time. */

#define LL_MIN_INSTANT                6       /*!< Minimum number of CE to apply a CONN_UPD or CHAN_MAP. */

#define LL_MAX_ADV_DATA_LEN           1650    /*!< Maximum advertising data length. */

#define LL_MAX_DATA_LEN_MIN           27      /*!< Minimum value for maximum Data PDU length */
#define LL_MAX_DATA_LEN_ABS_MAX       251     /*!< Absolute maximum limit for maximum Data PDU length */

#define LL_MAX_DATA_TIME_MIN          328     /*!< Minimum value for maximum Data PDU time */
#define LL_MAX_DATA_TIME_ABS_MAX      17040   /*!< Absolute maximum limit for maximum Data PDU time */
#define LL_MAX_DATA_TIME_ABS_MAX_1M   2120    /*!< Absolute maximum limit for maximum Data PDU time (LE 1M PHY). Core Spec Table 4.5: 2128 if CTE is supported, else 2120. */
#define LL_MAX_DATA_TIME_ABS_MIN_CODED  2704  /*!< Absolute maximum limit for maximum Data PDU time (CODED PHY) */

#define LL_T_PRT_SEC                  40      /*!< LLCP procedure response timeout in seconds. */

#define LL_MAX_ADV_DLY_MS             10      /*!< Maximum advertising delay in milliseconds. */

#define LL_MIN_CONN_INTERVAL          6       /*!< Minimum value for connection interval. */
#define LL_MAX_CONN_INTERVAL          3200    /*!< Maximum value for connection interval. */

#define LL_MIN_TX_WIN_SIZE            1       /*!< Minimum value for transmit window size. */
#define LL_MAX_TX_WIN_SIZE            8       /*!< Maximum value for transmit window size. */

#define LL_MAX_CONN_LATENCY           499     /*!< Maximum value for connection slave latency. */

#define LL_MIN_SUP_TIMEOUT            10      /*!< Minimum value for connection supervision timeout. */
#define LL_MAX_SUP_TIMEOUT            3200    /*!< Maximum value for connection supervision timeout. */

#define LL_MIN_POWER_THRESHOLD        -128    /*!< Minimum value for power threshold. */
#define LL_MAX_POWER_THRESHOLD        127     /*!< Maximum value for power threshold. */

#define LL_MAX_PHYS                   3       /*!< Number of LE PHYs. */
#define LL_ALL_PHYS_MSK               0x7U     /*!< All supported LE PHYs mask. */
#define LL_PHY_RFU_BIT                (1 << 7)/*!< RFU PHY mask bit. */

/*** CTE ***/

#define LL_CTE_COUNT_MAX              0x10    /*!< Max CTE count. */
#define LL_CTE_LEN_TO_USEC(cteLen)    ((cteLen) * 8)
                                              /*!< Convert CTELength units to microseconds. */
#define LL_CTE_PKT_STATUS_CRC_ERR_FIELD_USED     0x01
                                              /*!< Invalid CRC, but used the CTE field to sample. */
#define LL_CTE_PKT_STATUS_INSUFFICIENT_RESOURCES 0xFF
                                              /*!< Insufficient resources to calculate CTE due to CRC error. */

/*** ISO ***/

#define LL_ISO_DATA_HDR_LEN           2       /*!< ISO Data PDU header length. */
#define LL_ISO_DATA_PLD_MAX_LEN       251     /*!< Maximum ISO Data PDU payload length */
#define LL_ISO_PDU_MAX_LEN            (HCI_ISO_HDR_LEN + BB_DATA_PLD_MAX_LEN + BB_DATA_PDU_TAILROOM)
                                              /*!< Maximum ISO Data PDU length. */

#define LL_ISO_SEG_HDR_LEN            2       /*!< Segmentation header length. */
#define LL_ISO_SEG_TO_LEN             3       /*!< Segmentation Time Offset length. */
#define LL_ISO_SEG_HDR_MAX_LEN        (LL_ISO_SEG_HDR_LEN + LL_ISO_SEG_TO_LEN)
                                              /*!< ISO segmentation header max length. */
#define LL_ISO_MAXDRIFT               10000   /*!< Maximum drift on the average timing of SDU delivery (100 ppm). */

#define LL_MAX_CIS_COUNT              0x10    /*!< Maximum count for CIS. */

#define LL_MIN_CIG_ID                 0x00    /*!< Minimum value for CIG ID. */
#define LL_MAX_CIG_ID                 0xEF    /*!< Maximum value for CIG ID. */

#define LL_MIN_CIS_ID                 0x00    /*!< Minimum value for CIS ID. */
#define LL_MAX_CIS_ID                 0xEF    /*!< Maximum value for CIS ID. */

#define LL_MIN_ISO_INTERV             0x0004  /*!< Minimum value for ISO interval. */
#define LL_MAX_ISO_INTERV             0x0C80  /*!< Maximum value for ISO interval. */

#define LL_MIN_ISOAL_PDU_TYPE         0x00    /*!< Minimum value for ISOAL PDU type. */
#define LL_MAX_ISOAL_PDU_TYPE         0x01    /*!< Maximum value for ISOAL PDU type. */

#define LL_MIN_FRAMING_MODE           0x00    /*!< Minimum value for framing mode. */
#define LL_MAX_FRAMING_MODE           0x01    /*!< Maximum value for framing mode. */

#define LL_MIN_SDU_SIZE               0x000   /*!< Minimum value for SDU size. */
#define LL_MAX_SDU_SIZE               0xFFF   /*!< Maximum value for SDU size. */

#define LL_MIN_SDU_INTERV             0x000FF /*!< Minimum value for SDU interval. */
#define LL_MAX_SDU_INTERV             0xFFFFF /*!< Maximum value for SDU interval. */

#define LL_MIN_CIS_NSE                0x01    /*!< Minimum value for CIS number of subevent. */
#define LL_MAX_CIS_NSE                0x1F    /*!< Maximum value for CIS number of subevent. */

#define LL_MIN_CIS_PL                 0x0000  /*!< Minimum value for CIS payload. */
#define LL_MAX_CIS_PL                 0x0FFB  /*!< Maximum value for CIS payload. */

#define LL_MIN_CIS_TRANS_LAT          0x0005  /*!< Minimum value for CIS transport latency. */
#define LL_MAX_CIS_TRANS_LAT          0x0FA0  /*!< Maximum value for CIS transport latency. */

#define LL_MIN_CIS_PHY_BIT            0x00    /*!< Minimum value for CIS PHY bit. */
#define LL_MAX_CIS_PHY_BIT            0x02    /*!< Maximum value for CIS PHY bit. */

#define LL_MIN_CIS_FT                 0x01    /*!< Minimum value for CIS flush time. */
#define LL_MAX_CIS_FT                 0x1F    /*!< Maximum value for CIS flush time. */

#define LL_MIN_CIS_BN                 0x00    /*!< Minimum value for CIS burst number. */
#define LL_MAX_CIS_BN                 0x10    /*!< Maximum value for CIS burst number. */

#define LL_MIN_CIS_RTN                0x00    /*!< Minimum value for CIS retransmission number. */
#define LL_MAX_CIS_RTN                0x0F    /*!< Maximum value for CIS retransmission number. */

#define LL_MIN_CIS_ISO_INT_US         5000    /*!< Minimum value for CIS ISO interval. */

#define LL_MIN_CIS_OFFSET_USEC        500     /*!< Minimum first CIS anchor point offset of ACL anchorpoint. */

/*! \brief      ISO PDU LLID types. */
enum
{
  /* ISO */
  LL_LLID_ISO_UNF_END_PDU             = 0x00, /*!< Unframed ISO Data PDU; end fragment of a SDU. */
  LL_LLID_ISO_UNF_CONT_PDU            = 0x01, /*!< Unframed ISO Data PDU; start or continuation fragment of a SDU. */
  LL_LLID_ISO_FRA_PDU                 = 0x02, /*!< Framed ISO Data PDU; one or more segments of a SDU. */
  LL_LLID_ISO_CIS_EMPTY_PDU           = 0x01, /*!< ISO CIS Empty PDU. */
  LL_LLID_ISO_BIS_EMPTY_PDU           = 0x01, /*!< ISO BIS Empty PDU. */

  /* BIS */
  LL_LLID_BIG_CTRL_PDU                = 0x03  /*!< BIG Control PDU. */
};
typedef uint8_t LlIsoLlid_t;

/*! \brief      ISO PDU type. */
enum
{
  LL_ISO_PDU_TYPE_UNFRAMED            = 0x00, /*!< Unframed PDU type. */
  LL_ISO_PDU_TYPE_FRAMED              = 0x01, /*!< Framed PDU type, Segmentable mode. */
  LL_ISO_PDU_TYPE_FRAMED_UNSEGMENTED  = 0x02, /*!< Framed PDU type, Unsegmented mode. */
};
typedef uint8_t LlFraming_t;

/*! \brief      Framing mode. */
enum
{
  LL_FRAMING_MODE_SEGMENTABLE         = 0x00, /*!< Segmentable mode. */
  LL_FRAMING_MODE_UNSEGMENTED         = 0x01  /*!< Unsegmented mode. */
};
typedef uint8_t LlFramingMode_t;

/*! \brief      ISO test payload types. */
enum
{
  LL_ISO_TEST_PL_LEN_ZERO             = 0x00, /*!< Zero length test payload */
  LL_ISO_TEST_PL_LEN_VAR              = 0x01, /*!< Variable length test payload */
  LL_ISO_TEST_PL_LEN_MAX              = 0x02  /*!< Maximum length test payload */
};

/*! \brief      ISOAL SDU assembly states. */
enum
{
  LL_ISO_SDU_STATE_NEW                = 0x00, /*!< New SDU state. */
  LL_ISO_SDU_STATE_CONT               = 0x01, /*!< SDU pending state. */
  LL_ISO_SDU_STATE_PAD                = 0x02  /*!< SDU padding state. */
};

#define LL_ISO_TEST_VAR_MIN_LEN       4       /*!< Minimum length test payload. */
#define LL_ISO_MTL_MIN_MS             5       /*!< Minimum value for maximum transport latency. */

/*** DTM ***/

#define LL_DTM_HDR_LEN                2                       /*!< Direct Test Mode PDU header length. */
#define LL_DTM_SYNC_WORD              UINT32_C(0x71764129)    /*!< Direct Test Mode sync word. */
#define LL_DTM_CRC_INIT               UINT32_C(0x555555)      /*!< Direct Test Mode CRC initial value. */
#define LL_DTM_MAX_INT_US             12500   /*!< Maximum time interval between packets in microseconds. */
#define LL_DTM_PDU_ABS_MAX_LEN        255     /*!< Absolute maximum DTM PDU length. */
#define LL_DTM_MAX_CHAN_IDX           39      /*!< Maximum channel index. */

/*** Baseband ***/

#define LL_CHAN_DATA_MIN_IDX          0       /*!< Minimum data channel index. */
#define LL_CHAN_DATA_MAX_IDX          36      /*!< Maximum data channel index. */
#define LL_CHAN_DATA_ALL              UINT64_C(0x0000001FFFFFFFFF)    /*!< Maximum data channel index. */

#define LL_BLE_BIT_PER_US             1       /*!< BLE PHY rate. */
#define LL_BLE_US_PER_BYTE_1M         8       /*!< BLE PHY speed (LE 1M PHY). */
#define LL_BLE_US_PER_BYTE_2M         4       /*!< BLE PHY speed (LE 2M PHY). */
#define LL_BLE_US_PER_BYTE_CODED_S8   64      /*!< BLE PHY speed (LE Coded PHY, S=8). */
#define LL_BLE_US_PER_BIT_CODED_S8    8U      /*!< BLE PHY speed (LE Coded PHY, S=8). */
#define LL_BLE_US_PER_BYTE_CODED_S2   16      /*!< BLE PHY speed (LE Coded PHY, S=2). */
#define LL_BLE_US_PER_BIT_CODED_S2    2U      /*!< BLE PHY speed (LE Coded PHY, S=2). */
#define LL_BLE_TIFS_US                150U    /*!< BLE inter-frame space. */
#define LL_BLE_MAFS_US                300     /*!< BLE minimum AUX frame space. */
#define LL_BLE_US_PER_TICK            625     /*!< Microseconds per BLE tick. */
#define LL_BLE_TMSS_US                150     /*!< BLE minimum subevent space. */
#define LL_BLE_TMCES_US               150U    /*!< BLE minimum connection event space. */

#define LL_MIN_PKT_TIME_US_1M         80      /*!< Minimum packet time (i.e. empty PDU) on LE 1M PHY. */
#define LL_MIN_PKT_TIME_US_2M         44      /*!< Minimum packet time (i.e. empty PDU) on LE 2M PHY. */
#define LL_MIN_PKT_TIME_US_CODED_S8   720U    /*!< Minimum packet time (i.e. empty PDU) on LE Coded PHY, S=8. */
#define LL_MIN_PKT_TIME_US_CODED_S2   462     /*!< Minimum packet time (i.e. empty PDU) on LE Coded PHY, S=2. */

#define LL_MIN_ADV_TX_PWR_LVL         -20     /*!< Minimum Tx power level for advertising. */
#define LL_MAX_ADV_TX_PWR_LVL         10      /*!< Maximum Tx power level for advertising. */

#define LL_MIN_TX_PWR_LVL             -30     /*!< Minimum Tx power level for connections. */
#define LL_MAX_TX_PWR_LVL             20      /*!< Maximum Tx power level for connections. */

#define LL_MAX_TIFS_DEVIATION         2       /*!< Maximum TIFS deviation in microseconds. */

#define LL_WW_RX_DEVIATION_ACTIVE_USEC      1       /*!< Rx deviation in microseconds for window widening when the active clock applies. */
#define LL_WW_RX_DEVIATION_SLEEP_USEC       16      /*!< Rx deviation in microseconds for window widening when the sleep clock applies. */

#define LL_WW_CIS_SUBEVT_DIVISOR            20000   /*!< Divisor for window widening calculation between CIS subevents. (Vol 6, Part B, 4.2.4) */

#define LL_30_USEC_OFFS_MAX_USEC      245700  /*!< Maximum value for 30 microseconds offset unit in microseconds. */
#define LL_SYNC_OFFS_MAX_USEC         (LL_SYNC_OFFS_ADJUST_USEC + LL_AUX_PTR_MAX_USEC)   /*!< Maximum sync offset in microseconds.*/

/*** ACAD ***/

/*! \brief      ACAD opcodes. */
enum
{
  LL_ACAD_OPCODE_CHAN_MAP_UPD            = 0x28, /*!< Opcode for ACAD Channel Map Update Indication. */
  LL_ACAD_OPCODE_BIG_INFO                = 0x2C, /*!< Opcode for ACAD BIG Info. */
  LL_ACAD_OPCODE_PER_ADV_RSP_TIMING_INFO = 0x32  /*!< Opcode for ACAD Periodic Advertising Response Timing Information. */
};

#define LL_ACAD_OPCODE_LEN            1       /*!< Length of a single ACAD opcode. */
#define LL_ACAD_LEN_FIELD_LEN         1       /*!< Length of ACAD length field */
#define LL_ACAD_DATA_FIELD_MAX_LEN    (LL_EXT_HDR_ACAD_MAX_LEN - LL_ACAD_OPCODE_LEN - LL_ACAD_LEN_FIELD_LEN)
                                              /*!< Length of max ACAD field length without opcode and length field */
#define LL_ACAD_CHAN_MAP_UPD_LEN            8  /*!< Length of ACAD update periodic channel map data field. */
#define LL_ACAD_BIG_INFO_UNENCRPT_LEN       33 /*!< Length of ACAD for an unencrypted BIG Info. */
#define LL_ACAD_BIG_INFO_ENCRPT_LEN         57 /*!< Length of ACAD for an encrypted BIG Info. */
#define LL_ACAD_PER_ADV_RSP_TIMING_INFO_LEN 9  /*!< Length of ACAD periodic advertising response timing info field. */

/*** BIG Control PDUs ***/

/*! \brief      BIG Control opcodes. */
enum
{
  LL_BIG_OPCODE_CHAN_MAP_IND = 0x00,          /*!< Opcode for BIG Channel Map Indication. */
  LL_BIG_OPCODE_BIG_TERM_IND = 0x01,          /*!< Opcode for BIG Terminate Indication. */
  LL_BIG_OPCODE_MAX                           /*!< Maximum number of BIG opcodes. */
};

#define LL_BIG_OPCODE_LEN             1       /*!< Length of a BIG Control PDU opcode. */

#define LL_BIG_CHAN_MAP_IND_PDU_LEN   7       /*!< BIG Channel Map indication PDU length. */
#define LL_BIG_TERMINATE_IND_PDU_LEN  3       /*!< BIG Terminate indication PDU length. */

#define LL_BIG_CS_PDU_LEN_MAX         LL_BIG_CHAN_MAP_IND_PDU_LEN

#define LL_BIG_MIN_INSTANT            6       /*!< Minimum number of BIG Events to apply a BIG Control PDU. */

/*** Modify Sleep Clock Accuracy ***/

/*! \brief      Action parameter. */
enum
{
  LL_MODIFY_SCA_MORE_ACCURATE = 0x00,         /*!< Modify to more accurate clock accuracy. */
  LL_MODIFY_SCA_LESS_ACCURATE = 0x01,         /*!< Modify to less accurate clock accuracy. */
  LL_MODIFY_SCA_NO_ACTION                     /*!< No action (Used for request sca tester command). */
};

#define LL_SCA_MIN_INDEX              0       /*!< Index for lowest accuracy clock. */
#define LL_SCA_MAX_INDEX              7       /*!< Index for highest accuracy clock. */

/*** Power Control ***/

/*! \brief      Power control Limit field. */
#define LL_PWR_CONTROL_LIMIT_MIN_BIT  (1 << 0)  /*!< txPower is at it's minimum limit. */
#define LL_PWR_CONTROL_LIMIT_MAX_BIT  (1 << 1)  /*!< txPower is at it's maximum limit. */

/*! \brief       Power control APR field. */
#define LL_PWR_CTRL_APR_UNDEF         0xFF    /*!< Undefined power reduction limit. */

/*! \brief       Power control txPower field. */
#define LL_PWR_CTRL_TXPOWER_MAX         0x7F  /*!< txPower symbol for maximum txPower. */
#define LL_PWR_CTRL_TXPOWER_MIN         0x7E  /*!< txPower symbol for minimum txPower. */
#define LL_PWR_CTRL_MIN_TXPOWER         -126  /*!< Absolute minimum txPower possible. */
#define LL_PWR_CTRL_MAX_TXPOWER         20    /*!< Absolute maximum txPower possible. */
#define LL_PWR_CTRL_TXPOWER_UNAVAILABLE 127   /*!< Power is unavailable for this PHY. */
#define LL_PWR_CTRL_TXPOWER_UNMANAGED   126   /*!< Power is unmanaged for this PHY. */

/*! \brief   Path loss monitoring zones. */
enum
{
  LL_PATH_LOSS_ZONE_LOW = 0x00,               /*!< Low path loss zone. */
  LL_PATH_LOSS_ZONE_MID,                      /*!< Medium path loss zone. */
  LL_PATH_LOSS_ZONE_HIGH                      /*!< High path loss zone. */
};

#define LL_PATH_LOSS_UNAVAILABLE 0xFF  /*!< Path loss is unavailable. */

/*! \brief    Power control reporting reasons table. */
enum
{
  LL_POWER_REPORT_REASON_LOCAL,               /*!< Local power change report. */
  LL_POWER_REPORT_REASON_REMOTE,              /*!< Remote power change report. */
  LL_POWER_REPORT_REASON_READ_REMOTE          /*!< Remote transmit power read report. */
};

/*** ISO ***/

#define LL_ISOAL_SEG_HDR_MASK_SC      0x01U    /*!< Mask for segmentation header start/continuation bit. */
#define LL_ISOAL_SEG_HDR_MASK_CMPLT   0x02U    /*!< Mask for segmentation header complete bit. */

/*! \brief  Codec transport types. */
enum
{
  LL_CODEC_TRANS_CIS_BIT = (1 << 2),          /*!< Codec supported over LE CIS. */
  LL_CODEC_TRANS_BIS_BIT = (1 << 3)           /*!< Codec supported over LE BIS. */
};

/*** Connection Accept Timeout ***/

#define LL_CONN_ACCEPT_TIMEOUT_MIN    0x0001U  /*!< Minimum value for connection accept timeout. */
#define LL_CONN_ACCEPT_TIMEOUT_MAX    0xB540U  /*!< Maximum value for connection accept timeout. */
#define LL_CONN_ACCEPT_TIMEOUT_DEF    0x1FA0U  /*!< Default value for connection accept timeout. */

/*** Channel classification ***/

#define LL_CH_RPT_SPACING_MIN            5U   /*!< Minimum value for minimum spacing and max delay parameter. */
#define LL_CH_RPT_SPACING_MAX          150U   /*!< Maximum value for minimum spacing and max delay parameter. */
#define LL_CH_RPT_SPACING_DEF           10    /*!< Default spacing for channel reporting indication. */

#define LL_CH_CLASS_UNKNOWN              0    /*!< Channel classification is unknown. */
#define LL_CH_CLASS_GOOD                 1    /*!< Channel classification is good. */
#define LL_CH_CLASS_BAD                  3    /*!< Channel classification is bad. */

/*! \brief      Minimum and maximum time between LL_CHANNEL_STATUS_IND reports in 200ms units. */
enum
{
  LL_MIN_CH_STATUS_INTERVAL = 5,              /*!< Channel class reporting minimum (1 second). */
  LL_MAX_CH_STATUS_INTERVAL = 150,            /*!< Channel class reporting maximum (30 seconds). */
};

/*** Enhanced connection update ***/

/*! \brief      Minimum and maximum subrate. */
enum
{
  LL_MIN_SUBRATE = 1,                         /*!< Minimum subrate. */
  LL_MAX_SUBRATE = 500                        /*!< Maximum subrate. */
};

/*** PAwR ***/

#define LL_PAWR_UNUSED_ADV_HANDLE         0xFFU   /*!< Unused PAwR advertising handle. */
#define LL_PAWR_MISSING_RESPONSE          0xFFU   /*!< Missing PAwR response index. */
#define LL_PAWR_UNUSED_SYNC_HANDLE        0xFFFFU /*!< Unused PAwR sync handle. */
#define LL_PAWR_UNUSED_SUBEVENT           0xFFU   /*!< Unused PAwR subevent. */

/*** Channel Sounding ***/

#define LL_CS_REM_FAE_TBL_SIZE            0x48   /*!< Remote FAE table size. */
#define LL_CS_CHAN_MAP_SIZE               0x0A   /*!< CS Channel Map size. */
#define LL_CS_MAX_OVERRIDE_PARAMS         0x04   /*!< Maximum CS override parameter length. */
#define LL_CS_MAX_MAIN_MODE_REP_CH_LEN    0x03   /*!< Maximum CS main mode repetition length. */
#define LL_CS_USER_PAYLOAD_SIZE           0x10   /*!< CS user payload size. */
#define LL_CS_MAX_NUM_ANT_PATHS           0x04   /*!< Maximum number of antenna paths. */
#define LL_CS_SEC_INIT_VECTOR_LEN         8      /*!< CS security initialization vector length. */
#define LL_CS_SEC_INST_NONCE_LEN          4      /*!< CS security instantiation nonce length. */
#define LL_CS_SEC_PER_VECTOR_LEN          8      /*!< CS security personalization vector length. */
#define LL_CS_SEC_CONCAT_INIT_VECTOR_LEN  (LL_CS_SEC_INIT_VECTOR_LEN * 2)  /*!< CS security concatenated initialization vector length. */
#define LL_CS_SEC_CONCAT_INST_NONCE_LEN   (LL_CS_SEC_INST_NONCE_LEN * 2)   /*!< CS security concatenated instantiation nonce length. */
#define LL_CS_SEC_CONCAT_PER_VECTOR_LEN   (LL_CS_SEC_PER_VECTOR_LEN * 2)   /*!< CS security concatenated personalization vector length. */
#define LL_CS_MAX_NUM_CHAN                (LL_CS_CHAN_MAP_SIZE * 8 - 1)  /*!< CS maximum number of channels */
#define LL_CS_MAX_NUM_CHAN_QUARTER        20     /*!< Size of a channel quarters. */
#define LL_CS_MINIMUM_CHANNELS_SET        15     /*!< Minimum channels required before CS start procedure. */
#define LL_CS_MIN_SUBEVT_LEN_USEC         1250   /*!< Minimum length of CS subevent. */
#define LL_CS_MAX_SUBEVT_LEN_USEC         4000000/*!< Minimum length of CS subevent. */
#define LL_CS_MIN_OFFSET_USEC             500    /*!< Minimum offset of CS PDU. */
#define LL_CS_MAX_OFFSET_USEC             4000000/*!< Maximum offset of CS PDU. */

/*! \brief  Override Parameters Data bits. */
enum
{
  LL_CS_CHANNEL_BIT         = (1 << 0),          /*!< CS channel data bit. */
  LL_CS_MAIN_MODE_STEPS_BIT = (1 << 2),          /*!< CS main mode steps bit. */
  LL_CS_T_PM_TONE_EXT_BIT   = (1 << 3),          /*!< CS T PM tone ext bit. */
  LL_CS_TONE_ANT_PERM_BIT   = (1 << 4),          /*!< CS tone antenna permutation bit. */
  LL_CS_SYNC_AA_BIT         = (1 << 5),          /*!< CS SYNC AA initiator/reflector bit. */
  LL_CS_SS_MARK_POS_BIT     = (1 << 6),          /*!< CS SS marker position bit. */
  LL_CS_SS_MARK_VAL_BIT     = (1 << 7),          /*!< CS SS marker value bit. */
  LL_CS_SYNC_USER_PLD_BIT   = (1 << 8),          /*!< CS SYNC user payload bit. */
  LL_CS_STABLE_PHASE_BIT    = (1 << 10)          /*!< CS stable phase bit. */
};

/*! \brief  Mode type. */
enum
{
  LL_CS_MODE_TYPE_0,                             /*!< Mode type 0. */
  LL_CS_MODE_TYPE_1,                             /*!< Mode type 1. */
  LL_CS_MODE_TYPE_2,                             /*!< Mode type 2. */
  LL_CS_MODE_TYPE_3,                             /*!< Mode type 3. */
  LL_CS_MODE_TYPE_STABLE,                        /*!< Mode type stable. */
  LL_CS_MODE_TYPE_N,                             /*!< Number of modes. */
  LL_CS_MODE_TYPE_UNUSED = 0xFF                  /*!< Unused submode. */
};

/*! \brief  CS shape. */
enum
{
  LL_CS_SHAPE_HAT,                               /*!< Hat pattern. */
  LL_CS_SHAPE_X                                  /*!< X pattern. */
};

/*! \addtogroup LL_API_CS
 *  \{ */

/*! \brief      RTT type. */
enum
{
  LL_CS_RTT_AA_ONLY          = 0x00, /*!< RTT type 0. */
  LL_CS_RTT_SOUNDING_32BITS  = 0x01, /*!< RTT type 1. */
  LL_CS_RTT_SOUNDING_96BITS  = 0x02, /*!< RTT type 2. */
  LL_CS_RTT_RANDOM_32BITS    = 0x03, /*!< RTT type 3. */
  LL_CS_RTT_RANDOM_64BITS    = 0x04, /*!< RTT type 4. */
  LL_CS_RTT_RANDOM_96BITS    = 0x05, /*!< RTT type 5. */
  LL_CS_RTT_RANDOM_128BITS   = 0x06  /*!< RTT type 6. */
};

/*! \brief      Transaction ID. */
enum
{
  LL_CS_TRANSID_HOP_CHANNEL_SET_NON_MODE0,      /*!< Randomization of hop channel set for non-mode-0 steps. */
  LL_CS_TRANSID_HOP_CHANNEL_SET_MODE0,          /*!< Randomization of hop channel set for mode-0 steps. */
  LL_CS_TRANSID_RANDOMIZATION_SUBMODE,          /*!< Randomization of subevent sub-mode (into main-mode cycle). */
  LL_CS_TRANSID_T_PM,                           /*!< T_PM CS tone extension slot transmission presence. */
  LL_CS_TRANSID_T_ANT_PATH_PERMUT,              /*!< Antenna path permutation index selection. */
  LL_CS_TRANSID_RTT_PN_SEQ,                     /*!< RTT PN sequence CS Access Address generation. */
  LL_CS_TRANSID_SOUNDING_SEQ_POS_RANDOMIZATION, /*!< Sounding sequence marker position randomization. */
  LL_CS_TRANSID_SOUNDING_SEQ_SIG_SELECTION,     /*!< Sounding sequence marker signal selection. */
  LL_CS_TRANSID_RANDOM_SEQ,                     /*!< Random sequence generation. */
  LL_CS_TRANSID_BACKTRACK_RESIST,               /*!< Backtracking resistance. */
  LL_CS_TRANSID_N                               /*!< Number of transaction identifiers. */
};

enum
{
  LL_CS_TIME_T_IP1_IDX_10US,                    /*!< T_IP1 index 10us. */
  LL_CS_TIME_T_IP1_IDX_20US,                    /*!< T_IP1 index 20us. */
  LL_CS_TIME_T_IP1_IDX_30US,                    /*!< T_IP1 index 30us. */
  LL_CS_TIME_T_IP1_IDX_40US,                    /*!< T_IP1 index 40us. */
  LL_CS_TIME_T_IP1_IDX_50US,                    /*!< T_IP1 index 50us. */
  LL_CS_TIME_T_IP1_IDX_60US,                    /*!< T_IP1 index 60us. */
  LL_CS_TIME_T_IP1_IDX_80US,                    /*!< T_IP1 index 80us. */
  LL_CS_TIME_T_IP1_IDX_145US,                   /*!< T_IP1 index 145us. */
  LL_CS_TIME_T_IP1_IDX_N,                       /*!< Number of T_IP1 indexes. */
};

enum
{
  LL_CS_TIME_T_IP2_IDX_10US,                    /*!< T_IP2 index 10us. */
  LL_CS_TIME_T_IP2_IDX_20US,                    /*!< T_IP2 index 20us. */
  LL_CS_TIME_T_IP2_IDX_30US,                    /*!< T_IP2 index 30us. */
  LL_CS_TIME_T_IP2_IDX_40US,                    /*!< T_IP2 index 40us. */
  LL_CS_TIME_T_IP2_IDX_50US,                    /*!< T_IP2 index 50us. */
  LL_CS_TIME_T_IP2_IDX_60US,                    /*!< T_IP2 index 60us. */
  LL_CS_TIME_T_IP2_IDX_80US,                    /*!< T_IP2 index 80us. */
  LL_CS_TIME_T_IP2_IDX_145US,                   /*!< T_IP2 index 145us. */
  LL_CS_TIME_T_IP2_IDX_N,                       /*!< Number of T_IP2 indexes. */
};

enum
{
  LL_CS_TIME_T_FCS_IDX_15US,                    /*!< T_FCS index 15us. */
  LL_CS_TIME_T_FCS_IDX_20US,                    /*!< T_FCS index 20us. */
  LL_CS_TIME_T_FCS_IDX_30US,                    /*!< T_FCS index 30us. */
  LL_CS_TIME_T_FCS_IDX_40US,                    /*!< T_FCS index 40us. */
  LL_CS_TIME_T_FCS_IDX_50US,                    /*!< T_FCS index 50us. */
  LL_CS_TIME_T_FCS_IDX_60US,                    /*!< T_FCS index 60us. */
  LL_CS_TIME_T_FCS_IDX_80US,                    /*!< T_FCS index 80us. */
  LL_CS_TIME_T_FCS_IDX_100US,                   /*!< T_FCS index 100us. */
  LL_CS_TIME_T_FCS_IDX_120US,                   /*!< T_FCS index 120us. */
  LL_CS_TIME_T_FCS_IDX_150US,                   /*!< T_FCS index 150us. */
  LL_CS_TIME_T_FCS_IDX_N,                       /*!< Number of T_FCS indexes. */
};

enum
{
  LL_CS_TIME_T_PM_IDX_10US,                     /*!< T_PM index 10us. */
  LL_CS_TIME_T_PM_IDX_20US,                     /*!< T_PM index 20us. */
  LL_CS_TIME_T_PM_IDX_40US,                     /*!< T_PM index 40us. */
  LL_CS_TIME_T_PM_IDX_N,                        /*!< Number of T_TM indexes. */
};

#define LL_CS_T_RD_US                     5     /*!< CS ramp-down time. */
#define LL_CS_T_FM_US                     80    /*!< CS frequency measurement time. */
#define LL_CS_T_GD_US                     10    /*!< CS guard time. */

#define LL_MAX_CS_SEQUENCE_LEN            16    /*!< Maximum CS_SYNC sequence length in bytes. */
#define LL_CS_TRAILER_LEN                 1     /*!< CS_SYNC trailer length in bytes. */
#define LL_CS_MAX_SUBEVT_PER_PROC         32    /*!< Maximum number of CS subevents within any CS procedure. */
#define LL_CS_MAX_STEPS_PER_SUBEVENT      160   /*!< Maximum number of CS steps within any CS subevent. */
#define LL_CS_STEPS_MAX                   256   /*!< Maximum number of CS steps within any CS procedure. */
#define LL_CS_MAX_MODE0_STEPS_PER_SUBEVT  3     /*!< Maximum number of mode-0 steps per subevent. */

#define LL_CS_NUM_CHAN                    79    /*!< Total number of CS channels. */
#define LL_CS_NUM_ALLOWED_CHAN            72    /*!< Total number of allowed CS channels. */
#define LL_CS_MAX_NON_MODE0_CHAN_LIST    130   /*!< Maximum number of non-mode0 CS channels list. */

#define LL_CS_BLE_US_TRAILER_1M           4     /*!< BLE CS trailer time (LE 1M PHY). */
#define LL_CS_BLE_US_TRAILER_2M           2     /*!< BLE CS trailer time (LE 2M PHY). */

#define LL_CS_ROLE_INITIATOR              0     /*!< CS initiator. */
#define LL_CS_ROLE_REFLECTOR              1     /*!< CS reflector. */

#define LL_CS_CHAN_SELECT_TYPE_3B         0     /*!< CS Algorithm #3B type. */
#define LL_CS_CHAN_SELECT_TYPE_3C         1     /*!< CS Algorithm #3C type. */

#define LL_CS_SYNC_LEN_US_1M ((LL_PREAMBLE_LEN_1M + LL_AA_LEN) * LL_BLE_US_PER_BYTE_1M) /* CS sync length for 1M */
#define LL_CS_SYNC_LEN_US_2M ((LL_PREAMBLE_LEN_2M + LL_AA_LEN) * LL_BLE_US_PER_BYTE_2M) /* CS sync length for 2M */

/*! \} */    /* LL_API_CS */

/*! \addtogroup LL_API_DBAF
 *  \{ */

#define LL_DBAF_TEST_PARAM_LEN            16      /*!< DBAF test parameters length. */
#define LL_DBAF_MAX_DATA_LEN               8      /*!< Maximum decision data length. */
#define LL_DBAF_RESOLVABLE_TAG_LEN         6      /*!< Resolvable tag length. */

/*! \} */    /* LL_API_DBAF */

/*! \addtogroup LL_API_MONADV
 *  \{ */

#define LL_MONADV_MAX_ADDRESS_TYPE         1      /*!< Maximum Address_Type. */
#define LL_MONADV_MAX_RSSI_THRESHOLD      20      /*!< Maximum RSSI_Threshold. */

/*! \} */    /* LL_API_MONADV */

/*! \addtogroup LL_API_EXT_FEAT
 *  \{ */

#define LL_EXT_FEAT_LEN                   248     /*!< Length of features byte array. */
#define LL_EXT_FEAT_MAX_EXT_PAGES          10     /*!< Number of extended feature pages. */
#define LL_FEATURE_EXT_PAGE_LEN            24     /*!< Length of a feature page. */

/*! \} */    /* LL_API_EXT_FEAT */

#define LL_CS_OPT_SUB_FEAT_COMPANION_SIG  (1 << 0)
#define LL_CS_OPT_SUB_FEAT_ZERO_FREQ_ERR  (1 << 1)
#define LL_CS_OPT_SUB_FEAT_ALGO_3C        (1 << 2)
#define LL_CS_OPT_SUB_FEAT_SS_RANGING     (1 << 3)
/*! \addtogroup LL_API_FSU
 *  \{ */

#define LL_FSU_MAX_FRAME_SPACE          0x2710  /*!< Maximum frame space value. */
#define LL_FSU_IFS_UPDATE_CE                 6  /*!< IFS values shall change after this number of connection anchor points. */

/*! \brief     FSU PHYs. */
enum
{
  LL_FSU_PHY_1M,
  LL_FSU_PHY_2M,
  LL_FSU_PHY_CODED,

  LL_FSU_PHY_TOTAL        = LL_FSU_PHY_CODED + 1,
  LL_FSU_PHY_INVALID      = 0xFF
};

/*! \brief      FSU Spacing Types */
enum
{
  LL_FSU_T_IFS_ACL_CP,     /* T_IFS for ACL from central to peripheral. */
  LL_FSU_T_IFS_ACL_PC,     /* T_IFS for ACL from peripheral to central. */
  LL_FSU_T_MCES,           /* Minimum connection event spacing. */
  LL_FSU_T_IFS_CIS,        /* T_IFS for CIS. */
  LL_FSU_T_MSS_CIS,        /* Minimum subevent spacing for CIS. */
  LL_FSU_MAX_SPACING_TYPE  /* Maximum spacing type. */
};

/*! \brief      FSU Initiator. */
enum
{
  LL_FSU_INIT_HOST,             /* Local host initiated. */
  LL_FSU_INIT_CONTROLLER,       /* Local controller initiated. */
  LL_FSU_INIT_PEER,             /* Peer initiated. */
  LL_FSU_INIT_UNDEFINED = 0xFF  /* Initiator undefined. */
};

/*! \} */    /* LL_API_FSU */

#ifdef __cplusplus
};
#endif

#endif /* LL_DEFS_H */
