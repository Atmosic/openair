/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      Baseband interface file.
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

#ifndef PAL_BB_H
#define PAL_BB_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
  Macros
**************************************************************************************************/

/*! \brief      Protocol types. */
typedef enum
{
  BB_PROT_NONE,                         /*!< Non-protocol specific operation. */
  BB_PROT_BLE,                          /*!< Bluetooth Low Energy normal mode. */
  BB_PROT_BLE_DTM,                      /*!< Bluetooth Low Energy direct test mode. */
  BB_PROT_PRBS15,                       /*!< Enable the continuous PRBS15 transmit sequence. */
  BB_PROT_15P4,                         /*!< 802.15.4. */
  BB_PROT_NUM                           /*!< Number of protocols. */
} PalBbProt_t;

/*! \brief      Status codes. */
enum
{
  BB_STATUS_SUCCESS,                    /*!< Operation successful. */
  BB_STATUS_FAILED,                     /*!< General failure. */
  BB_STATUS_CANCELED,                   /*!< Receive canceled. */
  BB_STATUS_RX_TIMEOUT,                 /*!< Receive packet timeout. */
  BB_STATUS_CRC_FAILED,                 /*!< Receive packet with CRC verification failed. */
  BB_STATUS_FRAME_FAILED,               /*!< Receive packet with frame verification failed. */
  BB_STATUS_MIC_FAILED,                 /*!< Receive packet with MIC verification failed. */
  BB_STATUS_ACK_FAILED,                 /*!< ACK packet failure. */
  BB_STATUS_ACK_TIMEOUT,                /*!< ACK packet timeout. */
  BB_STATUS_TX_CCA_FAILED,              /*!< Transmit CCA failure. */
  BB_STATUS_TX_FAILED,                  /*!< Transmit failure. */
  BB_STATUS_CS_AA_FAILED,               /*!< Received packet with AA verification failed. */
  BB_STATUS_CS_SEQ_FAILED               /*!< Received packet with Sounding Sequence or Random Sequence verification failed. */
};
typedef uint8_t PalBbStatus_t;

/*! \brief      PHY types. */
enum {
  BB_PHY_BLE_1M                   = 1,  /*!< Bluetooth Low Energy 1Mbps PHY. */
  BB_PHY_BLE_2M                   = 2,  /*!< Bluetooth Low Energy 2Mbps PHY. */
  BB_PHY_BLE_CODED                = 3,  /*!< Bluetooth Low Energy Coded PHY (data coding unspecified). */
  BB_PHY_BLE_2M_2BT               = 4,  /*!< Bluetooth Low Energy 2Mbps 2BT PHY (for Channel Sounding only). */
  BB_PHY_15P4                     = 5,   /*!< 802.15.4 PHY. */
  BB_CS_PHY_BLE_2M_2BT            = 3,  /*!< Bluetooth Low Energy 2Mbps 2BT PHY (for Channel Sounding test only). */
};
typedef uint8_t PalBbPhy_t;

/*! \brief      PHY options. */
enum
{
  BB_PHY_OPTIONS_DEFAULT          = 0,  /*!< BB defined PHY Options behavior. */
  BB_PHY_OPTIONS_BLE_S2           = 1,  /*!< Always use S=2 coding when transmitting on LE Coded PHY. */
  BB_PHY_OPTIONS_BLE_S8           = 2   /*!< Always use S=8 coding when transmitting on LE Coded PHY. */
};

/*! \brief      Typical maximum duration to scan in a scan interval (BbRtCfg_t::maxScanPeriodMs). */
#define BB_MAX_SCAN_PERIOD_MS     1000

/*! \brief      Typical RF setup delay (BbRtCfg_t::rfSetupDelayUs). */
#define BB_RF_SETUP_DELAY_US      150

/*! \brief      Typical operation setup delay in microseconds (BbRtCfg_t::schSetupDelayUs). */
#define BB_SCH_SETUP_DELAY_US     500

/**************************************************************************************************
  Type Definitions
**************************************************************************************************/

/*! \brief  IRQ callback datatypes. */
typedef void (*bbDrvIrqCback_t)(void);

/*! \brief  BB configuration. */
typedef struct
{
  uint16_t clkPpm;                  /*!< Clock accuracy in PPM. */
  uint8_t  rfSetupDelayUsec;        /*!< RF setup delay in microseconds. */
  uint16_t maxScanPeriodMsec;       /*!< Maximum scan period in milliseconds. */
  uint16_t schSetupDelayUsec;       /*!< Schedule setup delay in microseconds. */
  uint8_t  maxCteLen;               /*!< Maximum CTE length. */
  uint8_t  supportedSwitchRates;    /*!< Supported switching sampling rates. */
  uint8_t  numAntennae;             /*!< Number of antennae supported by the controller. */
  uint8_t  maxSwitchPatternLen;     /*!< Maximum length of antenna switching pattern supported by controller. */
  uint8_t  supportedCteTypes;       /*!< Supported CTE Types. */
} PalBbCfg_t;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*! \addtogroup PAL_BB_INIT
 *  \{
 *  This section contains driver routines which initialize as well as enable the sleep mode
 *  of the BB hardware.
 */

/*************************************************************************************************/
/*!
 *  \brief      Initialize the baseband driver.
 *
 *  One-time initialization of baseband resources. This routine can be used to setup baseband
 *  resources, load RF trim parameters and execute RF calibrations and seed the random number
 *  generator.
 *
 *  This routine should block until the BB hardware is completely initialized.
 */
/*************************************************************************************************/
void PalBbInit(void);

/*************************************************************************************************/
/*!
 *  \brief      Enable the BB hardware.
 *
 *  This routine brings the BB hardware out of low power (enable power and clocks) just before a
 *  first BB operation is executed.
 */
/*************************************************************************************************/
void PalBbEnable(void);

/*************************************************************************************************/
/*!
 *  \brief      Disable the BB hardware.
 *
 *  This routine signals the BB hardware to go into low power (disable power and clocks) after all
 *  BB operations have been disabled.
 */
/*************************************************************************************************/
void PalBbDisable(void);

/*************************************************************************************************/
/*!
 *  \brief      Load BB timing configuration.
 *
 *  \param      pCfg                Return configuration values.
 */
/*************************************************************************************************/
void PalBbLoadCfg(PalBbCfg_t *pCfg);

/*! \} */    /* PAL_BB_INIT */

/*! \addtogroup PAL_BB_CLOCK
 *  \{
 *  This section contains driver routines related to the BB clock.
 */

/*************************************************************************************************/
/*!
 *  \brief      Called to register a protocol's Radio and Timer IRQ callback functions.
 *
 *  \param      protId      Protocol ID.
 *  \param      timerCback  Timer IRQ callback.
 *  \param      radioCback  Radio IRQ callback.
 */
/*************************************************************************************************/
void PalBbRegisterProtIrq(uint8_t protId, bbDrvIrqCback_t timerCback, bbDrvIrqCback_t radioCback);

/*************************************************************************************************/
/*!
 *  \brief      Set protocol ID.
 *
 *  \param      protId      Protocol ID.
 */
/*************************************************************************************************/
void PalBbSetProtId(uint8_t protId);

/*! \} */    /* PAL_BB_CLOCK */

#ifdef __cplusplus
};
#endif

#endif /* PAL_BB_H */
