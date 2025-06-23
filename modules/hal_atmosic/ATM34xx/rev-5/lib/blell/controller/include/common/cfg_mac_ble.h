/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      BLE MAC system configuration.
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
 *  if you do not have a copy of the Agreement, you must contact Packetcraft, Inc. prior
 *  to any use, copying or further distribution of this software.
 */
/*************************************************************************************************/

#ifndef CFG_MAC_BLE_H
#define CFG_MAC_BLE_H

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
  Macros
**************************************************************************************************/

/*** LL: Features ***/

/* Enable features by default. Initialization code will only enable features where both the
 * feature is enabled and BT_VER meets the feature's requirement.
 *
 * Features requiring additional HW to function, such as CTE and CS are disabled by default.
 */

/* Controller features: BLE v5.1 (initialization also requires BT_VER >= 0x0A) */

#ifndef LL_FEAT_CTE
#define LL_FEAT_CTE             0       /*!< Enable CTE (additionally enable CTE_PRESENT). */
#endif

#ifndef LL_FEAT_PAST
#define LL_FEAT_PAST            1       /*!< Enable PAST. */
#endif

/* Controller features: BLE v5.2 (initialization also requires BT_VER >= 0x0B) */

#ifndef LL_FEAT_CODEC
#define LL_FEAT_CODEC           0       /*!< Enable Codec. */
#endif

#ifndef LL_FEAT_BIS
#define LL_FEAT_BIS             1       /*!< Enable BIS. */
#endif

#ifndef LL_FEAT_CIS
#define LL_FEAT_CIS             1       /*!< Enable CIS. */
#endif

#ifndef LL_FEAT_ISO
#define LL_FEAT_ISO             1       /*!< Enable ISO. */
#endif

#ifndef LL_FEAT_PC
#define LL_FEAT_PC              1       /*!< Enable PC. */
#endif

/* Controller features: BLE v5.3 (initialization also requires BT_VER >= 0x0C) */

#ifndef LL_FEAT_ECU
#define LL_FEAT_ECU             1       /*!< Enable ECU. */
#endif

/* Controller features: BLE v5.4 (initialization also requires BT_VER >= 0x0D) */

#ifndef LL_FEAT_PAWR
#define LL_FEAT_PAWR            1       /*!< Enable PAWR. */
#endif

/* Controller features: BLE v6.0 (initialization also requires BT_VER >= 0x0E) */

#ifndef LL_FEAT_CS
#define LL_FEAT_CS              0       /*!< Enable CS (additionally enable CS_PRESENT). */
#endif

#ifndef LL_FEAT_CS_TEST
#define LL_FEAT_CS_TEST         0       /*!< Enable CS Test. */
#endif

#ifndef LL_FEAT_DBAF
#define LL_FEAT_DBAF            1       /*!< Enable DBAF. */
#endif

#ifndef LL_FEAT_EISOAL
#define LL_FEAT_EISOAL          1       /*!< Enable eISOAL. */
#endif

#ifndef LL_FEAT_EXTFEAT
#define LL_FEAT_EXTFEAT         1       /*!< Enable Extended Feature Set. */
#endif

#ifndef LL_FEAT_MONADV
#define LL_FEAT_MONADV          1       /*!< Enable Monitoring Advertisers. */
#endif

#ifndef LL_FEAT_FSU
#define LL_FEAT_FSU             1       /*!< Enable Frame Space Update. */
#endif

/* Controller features: Custom */

#ifndef LL_FEAT_DAA
#define LL_FEAT_DAA             0       /*!< Enable DAA. */
#endif

#ifndef LL_FEAT_RXD
#define LL_FEAT_RXD             0       /*!< Enable Rx Antenna Diversity. */
#endif

#ifndef LL_FEAT_RSPOBS
#define LL_FEAT_RSPOBS          0       /*!< Enable Response Observation. */
#endif

/*** LL: Configuration ***/

#ifndef LL_API_PARAM_CHECK
#define LL_API_PARAM_CHECK      1       /*!< Check API parameters. */
#endif

#ifndef LL_MAX_CONN
#define LL_MAX_CONN             4       /*!< Absolute maximum number of connections (maximum is 32). */
#endif

#ifndef LL_MAX_FRAG
#define LL_MAX_FRAG             8       /*!< Maximum number of Data PDU fragments. */
#endif

#ifndef LL_NUM_ADV_FILT
#define LL_NUM_ADV_FILT         8       /*!< Table size for advertising filter. */
#endif

#ifndef LL_MAX_ADV_SETS
#define LL_MAX_ADV_SETS         6      /*!< Absolute maximum number of advertising sets. */
#endif

#ifndef LL_SCAN_PHY_MAX
#define LL_SCAN_PHY_MAX         3       /*!< Absolute maximum number of PHYs supported. */
#endif

#ifndef LL_MAX_PER_SCAN
#define LL_MAX_PER_SCAN         6       /*!< Absolute maximum number of periodic scanners (maximum is 32). */
#endif

#ifndef LL_SHARE_ADV_SCAN_DATA
#define LL_SHARE_ADV_SCAN_DATA  0       /*!< Enable to share scanner response data and advertising data buffer. */
#endif

#ifndef LL_ENABLE_TESTER
#define LL_ENABLE_TESTER        0       /*!< Enable LL tester extensions. */
#endif

#ifndef LL_ENABLE_CALIBRATION
#define LL_ENABLE_CALIBRATION   0       /*!< Enable LL calibration extensions. */
#endif

#ifndef LL_MAX_CIG
#define LL_MAX_CIG              2       /*!< Absolute maximum number of connected isochronous groups. */
#endif

#ifndef LL_MAX_CIS
#define LL_MAX_CIS              6       /*!< Absolute maximum number of connected isochronous streams, it is shared by CIGs. */
#endif

#ifndef LL_MAX_BIG
#define LL_MAX_BIG              2       /*!< Absolute maximum number of broadcast isochronous groups. */
#endif

#ifndef LL_MAX_BIS
#define LL_MAX_BIS              6       /*!< Absolute maximum number of broadcast isochronous streams, it is shared by BIGs. */
#endif

#ifndef LL_MAX_BN
#define LL_MAX_BN               6       /*!< Absolute maximum number of bursts. */
#endif

#ifndef LL_MAX_PTO
#define LL_MAX_PTO              1       /*!< Absolute maximum value of PTO. */
#endif

#ifndef LL_MAX_NSE
#define LL_MAX_NSE              8       /*!< Maximum value for ISO number of subevent. */
#endif

#ifndef LL_MAX_IRC
#define LL_MAX_IRC              4       /*!< Maximum value for ISO immediate repetition count. */
#endif

#ifndef LL_PC_TBL_POW
#define LL_PC_TBL_POW           2U       /*!< Running average power control array sizes, must be a power of 2. */
#endif

#ifndef LL_PC_SERVICE_MS
#define LL_PC_SERVICE_MS        1000    /*!< Power control service intervals in milliseconds. */
#endif

#ifndef LL_PC_REQ_CHANGE_DBM
#define LL_PC_REQ_CHANGE_DBM    4       /*!< Request of increase/decrease in power value in units of dBm. */
#endif

#ifndef LHCI_ENABLE_VS
#define LHCI_ENABLE_VS          1       /*!< Enable vendor specific command processing. */
#endif

#ifndef LL_MAX_CTE_SAMPLE
#define LL_MAX_CTE_SAMPLE       0x52    /*!< Max sample size. */
#endif

#ifndef LL_MAX_PAWR_ADV_SETS
#define LL_MAX_PAWR_ADV_SETS    4       /*!< Absolute maximum number of advertising sets using PAwR. */
#endif

#ifndef LL_MAX_PAWR_RSP_SLOTS
#define LL_MAX_PAWR_RSP_SLOTS   25      /*!< Max number of PAwR response slots. */
#endif

#ifndef LL_NUM_PAWR_RSP_REPORT_BUF
#define LL_NUM_PAWR_RSP_REPORT_BUF  2  /*!< Number of PAwR response report buffer. */
#endif

#ifndef LL_MAX_PAWR_RX_IDX
#define LL_MAX_PAWR_RX_IDX      4       /*!< Max iteration of PAwR Rx circle buffer. */
#endif

#ifndef LL_MAX_SUBEVENT
#define LL_MAX_SUBEVENT         16      /*!< Maximum number of subevent data. */
#endif

#ifndef LL_MIN_CS_EVT_OFFSET_US
#define LL_MIN_CS_EVT_OFFSET_US 2500
#endif

#ifndef LL_ENABLE_RSPOBS
#define LL_ENABLE_RSPOBS        0       /*!< Enable PAwR response observation. */
#endif

#ifndef LL_NUM_PAWR_SUBEVT
#define LL_NUM_PAWR_SUBEVT      (LL_MAX_PAWR_SUBEVT > LL_MAX_SUBEVENT ? LL_MAX_SUBEVENT : LL_MAX_PAWR_SUBEVT)    /*!< Maximum number of PAwR subevents. Must be less than 0x40. It is used as a 64-bit bitmask. */
#endif

#ifndef LL_MAX_DECISION_TESTS
#define LL_MAX_DECISION_TESTS   8       /*!< Absolute maximum number decision instruction tests. */
#endif

#ifndef LL_MAX_MON_ADV
#define LL_MAX_MON_ADV          8       /*!< Absolute maximum number monitored advertisers. */
#endif

#ifndef LL_SHARE_INIT_SCAN_MEM
#define LL_SHARE_INIT_SCAN_MEM  0       /*!< Share init and scan memory, N.B. Application must guarantee initiate and scan states are mutually exclusive. */
#endif

#ifndef LL_COMP_EXT_ADV_DATA_MAX_LEN
#define LL_COMP_EXT_ADV_DATA_MAX_LEN    251     /*!< Maximum size of a single complete advertising data buffer. */
#endif

#ifndef LL_EXT_FEAT_NUM_EXT_PAGES
#define LL_EXT_FEAT_NUM_EXT_PAGES       1       /*!< Number of local extended feature pages allocated. */
#endif

/*** Scheduler ***/

#ifndef SCH_RM_MAX_RSVN
#define SCH_RM_MAX_RSVN         (LL_MAX_CONN + LL_MAX_ADV_SETS + LL_MAX_CIG + LL_MAX_BIG) /*!< Maximum number of reservations (maximum is 32). */
#endif

#ifndef SCH_RM_PREF_PER_USEC
#define SCH_RM_PREF_PER_USEC        10000 /*!< Preferred periodicity. */
#endif

#ifndef SCH_RM_PREF_PER_USEC_LOWEST
#define SCH_RM_PREF_PER_USEC_LOWEST 5000 /*!< Lowest preferred periodicity (for cases where intervalMax < SCH_RM_PREF_PER_USEC). */
#endif

#ifndef SCH_RM_MIN_SLOT_SIZE
#define SCH_RM_MIN_SLOT_SIZE        625  /*!< Minimum periodicity. */
#endif

/*** Baseband ***/

#ifndef BB_DATA_PLD_MAX_LEN
#define BB_DATA_PLD_MAX_LEN     251     /*!< Maximum data channel payload length (valid range 27 to 251, exclude MIC). */
#endif

#ifndef BB_ADV_PLD_MAX_LEN
#define BB_ADV_PLD_MAX_LEN      (BB_DATA_PLD_MAX_LEN + 4)
                                        /*!< Maximum advertising channel payload length (valid range 95 to 255). */
#endif

#ifndef BB_FIXED_DATA_PKT_LEN
#define BB_FIXED_DATA_PKT_LEN   0       /*!< Fixed packet length required for BB data receive buffers (0 to disable). */
#endif

#ifndef BB_FIXED_ADVB_PKT_LEN
#define BB_FIXED_ADVB_PKT_LEN   0       /*!< Fixed packet length required for BB advertisement receive buffers (0 to disable). */
#endif

#ifndef BB_DATA_PDU_TAILROOM
#define BB_DATA_PDU_TAILROOM    4       /*!< Extra byte allocation required for BB operations (i.e. MIC). */
#endif

#ifndef BB_ENABLE_INLINE_ENC_TX
#define BB_ENABLE_INLINE_ENC_TX 1       /*!< Enable inline encryption mode. Not available for all projects. */
#endif

#ifndef BB_ENABLE_INLINE_DEC_RX
#define BB_ENABLE_INLINE_DEC_RX 1       /*!< Enable inline decryption mode. Not available for all projects. */
#endif

#ifndef BB_ENABLE_STATS
#define BB_ENABLE_STATS         0       /*!< Enable statistics in Baseband. */
#endif

#ifndef BB_SYM_PHY_REQ
#define BB_SYM_PHY_REQ          0       /*!< Symmetric PHY required on connections. */
#endif

#ifndef BB_MAX_SWITCH_LEN
#define BB_MAX_SWITCH_LEN       5       /*!< Absolute maximum number of antenna switching pattern. */
#endif

#ifndef BB_MAX_ANT
#define BB_MAX_ANT              1       /*!< Maximum number of antennas. */
#endif

#ifdef __cplusplus
};
#endif

#endif /* CFG_MAC_BLE_H */
