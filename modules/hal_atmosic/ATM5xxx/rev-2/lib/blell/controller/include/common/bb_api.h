/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      Baseband interface file.
 *
 *  Copyright (c) 2013-2018 ARM Ltd. All Rights Reserved.
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
 *
 *  \addtogroup BB_API              Baseband (BB) API
 *  \{
 *
 *  The baseband porting layer is a protocol independent BB + radio abstraction layer. It allows
 *  the simultaneous operation of protocol specific schedulers to transport packets across each
 *  medium via a single multi-protocol baseband. This interface describes operations for the
 *  following protocols:
 *
 *    - Bluetooth low energy: advertising and connections
 *    - ZigBee/802.15.4 (TBD)
 *    - BAN/802.15.6 (TBD)
 *
 *  \dot
 *  digraph
 *  {
 *    node [shape=record, width=1.0, height=0.5, fontname=Helvetica, fontsize=8];
 *
 *    ble    [label="BLE\nlink layer", style=filled, fillcolor=lightgray];
 *    zigbee [label="802.15.4\nMAC", style=filled, fillcolor=lightgray];
 *    ban    [label="802.15.6\nMAC", style=filled, fillcolor=lightgray];
 *    sch    [label="Multi-protocol\nscheduler", style=filled, fillcolor=lightgray];
 *    bb_drv [label="{ BB porting layer | BB specific driver }"];
 *    bb_hw  [label="BB hardware", style=filled, fillcolor=dimgray];
 *
 *    ble -> sch;
 *    ble -> bb_drv;
 *    zigbee -> sch;
 *    zigbee -> bb_drv;
 *    ban -> sch;
 *    ban -> bb_drv;
 *    sch -> bb_drv;
 *    bb_drv -> bb_hw [style=dashed];
 *  }
 *  \enddot
 *
 *  \defgroup BB_API_INIT           Initialization
 *  \defgroup BB_API_BOD            Baseband Operation Descriptors (BOD)
 *  \defgroup BB_API_CTRL           Control interface
 *  \defgroup BB_API_BLE            Bluetooth Low Energy Protocol
 *
 *  \}
 */
/*************************************************************************************************/

#ifndef BB_API_H
#define BB_API_H

#include "wsf_types.h"
#include "cfg_mac.h"
#include "pal_bb.h"

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
  Constants
**************************************************************************************************/

/*! \addtogroup BB_API_BOD
 *  \{ */

/*! \} */    /* BB_API_BOD */

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \addtogroup BB_API_INIT
 *  \{ */

/*! \brief      BB runtime configuration parameters. */
typedef struct
{
  /* Common */
  uint16_t  clkPpm;                 /*!< Clock accuracy in PPM. */
  uint8_t   rfSetupDelayUs;         /*!< RF setup delay in microseconds. */

  /* BLE */
  uint16_t  maxScanPeriodMs;        /*!< Maximum duration to scan in a scan interval. */

  /* Scheduler */
  uint16_t  schSetupDelayUs;        /*!< Operation setup delay in microseconds. */

  /* CTE */
  uint8_t   maxCteLen;              /*!< Maximum CTE length. */
  uint8_t   supportedSwitchRates;   /*!< Supported switching sampling rates. */
  uint8_t   numAntennae;            /*!< Number of antennae supported by the controller. */
  uint8_t   maxSwitchPatternLen;    /*!< Maximum length of antenna switching pattern supported by controller. */
  uint8_t   supportedCteTypes;      /*!< Supported CTE Types. */
} BbRtCfg_t;

/*! \} */    /* BB_API_INIT */

/*! \addtogroup BB_API_BOD
 *  \{ */

/* Forward definition of BOD. */
struct BbOpDesc_tag;

/*! \brief      BOD completion event callback signature. */
typedef void (*BbBodCompCback_t)(void);

/*! \brief      BOD event callback signature. */
typedef void (*BbBodCback_t)(struct BbOpDesc_tag *pBod);

/*! \brief     Protocol event callback signature. */
typedef void (*BbProtCback_t)(void);

/*! \brief     Low power callback. */
typedef void (*BbLowPowerCback_t)(void);

/*! \brief     Setup delay callback. */
typedef uint16_t (*BbSetupDelayCback_t)(struct BbOpDesc_tag *pBod);

/*! \brief      BOD rescheduling policy (listed in priority order). */
typedef enum
{
  BB_RESCH_FIXED_PREFERRED,         /*!< BOD is fixed (rescheduling has limited recoverable consequences). */
  BB_RESCH_FIXED,                   /*!< BOD is fixed (rescheduling has recoverable consequences). */
  BB_RESCH_MOVEABLE_PREFERRED,      /*!< BOD is movable (rescheduling has minor consequences). */
  BB_RESCH_MOVEABLE,                /*!< BOD is movable (rescheduling has no consequences). */
  BB_RESCH_BACKGROUND               /*!< BOD is single background task. */
} BbReschPol_t;

/*! \brief      BOD scheduling preference. */
typedef enum
{
  BB_SCH_WINDOW,                    /*!< BOD offset is calculated in the center of existing BODs. */
  BB_SCH_ADJACENT                   /*!< BOD offset is calculated adjacent to an existing BOD. */
} BbSchPref_t;

/*! \} */    /* BB_API_BOD */

/*! \addtogroup BB_API_BOD
 *  \{ */

/* Forward protocol data definitions. */
struct BbBleData_tag;
struct Bb154Data_tag;

/*! \brief      Baseband operation descriptor (BOD). */
typedef struct BbOpDesc_tag
{
  struct BbOpDesc_tag *pPrev;       /*!< Previous BOD. */
  struct BbOpDesc_tag *pNext;       /*!< Next BOD. */

  uint32_t      dueUsec;            /*!< Absolute clock due time in microseconds. */
  uint32_t      minDurUsec;         /*!< Minimum required duration in microseconds. */
  uint32_t      maxDurUsec;         /*!< Maximum required duration in microseconds. */
  uint32_t      intervalUsec;       /*!< Interval of reoccurrence in microseconds. */

  BbReschPol_t  reschPolicy:8;      /*!< Rescheduling policy. */
  BbSchPref_t   schPref:8;          /*!< Scheduling preference. */

  PalBbProt_t   protId:8;           /*!< Protocol type. */

  bool          recoverable;        /*!< Indicates if the BOD can recover if the dueUsec time is in the past. */

  BbBodCback_t  endCback;           /*!< End of BOD callback (when BOD ends). */
  BbBodCback_t  abortCback;         /*!< Abort BOD callback (when BOD is removed before beginning). */

  BbBodCback_t  backupCback;        /*!< Backup of BOD callback (before BOD being interrupted). */
  BbBodCback_t  restoreCback;       /*!< Restore of BOD callback (after gap BOD ends). */

  void          *pCtx;              /*!< Client defined context. */
  uint16_t      *pDataLen;          /*!< Pointer to client data length. */

  uint32_t      *pSeStartOffsetUsec; /*!< Pointer to array of subevent start offset. */
  uint32_t      *pGapOccupiedUsec;   /*!< Pointer to array of subevent length.*/
  uint32_t      gapNum;              /*!< Number of gap. */

  union
  {
    struct BbBleData_tag *pBle;     /*!< BLE operation data. */
    struct Bb154Data_tag *p154;     /*!< 802.15.4 operation data. */
  } prot;                           /*!< Protocol specific data. */
} BbOpDesc_t;

/*! \} */    /* BB_API_BOD */

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*! \addtogroup BB_API_INIT
 *  \{ */

/*************************************************************************************************/
/*!
 *  \brief      Initialize runtime configuration.
 *
 *  \param      pCfg        Pointer to runtime configuration parameters (data must be static).
 *
 *  This function initializes the BB subsystem's runtime configuration.
 *
 *  \note       This routine must be called only once before any other initialization routine.
 */
/*************************************************************************************************/
void BbInitRunTimeCfg(const BbRtCfg_t *pCfg);

/*************************************************************************************************/
/*!
 *  \brief      Initialize the BB.
 *
 *  Initialize baseband resources.
 */
/*************************************************************************************************/
void BbInit(void);

/*************************************************************************************************/
/*!
 *  \brief      Register operation completion handler.
 *
 *  \param      eventCback  Event callback.
 *
 *  Register operation completion handler.
 */
/*************************************************************************************************/
void BbRegister(BbBodCompCback_t eventCback);

/*************************************************************************************************/
/*!
 *  \brief      Register protocol handlers.
 *
 *  \param      protId          Protocol ID.
 *  \param      execOpCback     Execute operation callback.
 *  \param      cancelOpCback   Cancel operation callback.
 *  \param      startProtCback  Start protocol callback.
 *  \param      stopProtCback   Stop protocol callback.
 */
/*************************************************************************************************/
void BbRegisterProt(PalBbProt_t protId, BbBodCback_t execOpCback, BbBodCback_t cancelOpCback,
                    BbProtCback_t startProtCback, BbProtCback_t stopProtCback);

/*************************************************************************************************/
/*!
 *  \brief      Register protocol handlers for low power.
 *
 *  \param      protId          Protocol ID.
 *  \param      lowPowerOpCback Low power operation callback.
 */
/*************************************************************************************************/
void BbRegisterProtLowPower(PalBbProt_t protId, BbLowPowerCback_t lowPowerOpCback);

/*! \} */    /* BB_API_INIT */

/*! \addtogroup BB_API_CTRL
 *  \{ */

/*************************************************************************************************/
/*!
 *  \brief      Start BB processing of given protocol.
 *
 *  \param      protId  Protocol ID.
 *
 *  Enable BB and start processing the list of BODs.  This routine may be called several times, if
 *  a protocol layers has several simultaneously-enabled operations.  However, \ref BbStop() must
 *  be called an equal number of time to disable the baseband.
 */
/*************************************************************************************************/
void BbStart(PalBbProt_t protId);

/*************************************************************************************************/
/*!
 *  \brief      Stop BB processing of given protocol.
 *
 *  \param      protId  Protocol ID.
 *
 *  Disable BB processing of BODs.
 *
 *  \note       For any particular protocol, calls to \ref BbStart() and \ref BbStop() must be
 *              balanced to ensure that the hardware is disabled if and only if appropriate.
 */
/*************************************************************************************************/
void BbStop(PalBbProt_t protId);

/*************************************************************************************************/
/*!
 *  \brief      Execute BOD.
 *
 *  \param      pBod    Pointer to the BOD to execute.
 *
 *  Execute the protocol specific BOD handler.
 */
/*************************************************************************************************/
void BbExecuteBod(BbOpDesc_t *pBod);

/*************************************************************************************************/
/*!
 *  \brief      Cancel current executing BOD.
 */
/*************************************************************************************************/
void BbCancelBod(void);

/*************************************************************************************************/
/*!
 *  \brief      Recover BOD.
 *
 *  \param      pBod    Pointer to the BOD to recover.
 *
 *  Recover the protocol specific BOD handler.
 */
/*************************************************************************************************/
void BbRecoverBod(BbOpDesc_t *pBod);

/*************************************************************************************************/
/*!
 *  \brief      Get the currently-executing BOD.
 *
 *  \return     Currently-executing BOD.
 */
/*************************************************************************************************/
BbOpDesc_t *BbGetCurrentBod(void);

/*************************************************************************************************/
/*!
 *  \brief      Get the scheduler setup delay for a BOD (Baseband Operation Descriptor).
 *
 *  \param      pBod    Pointer to the BOD.
 *
 *  \return     Setup delay in microseconds required before the BOD can be executed.
 *
 *  This function returns the time delay needed by the scheduler to prepare and set up
 *  the baseband hardware before executing the specified BOD. The setup delay accounts
 *  for radio configuration, frequency synthesis, and other hardware preparation time.
 */
/*************************************************************************************************/
uint16_t BbGetBodSchSetupDelay(BbOpDesc_t *pBod);

/*************************************************************************************************/
/*!
 *  \brief      Register setup delay callback for a protocol.
 *
 *  \param      protId      Protocol ID.
 *  \param      cback       Setup delay callback function.
 *
 *  Register a callback function that will be called to get the setup delay
 *  for BODs of the specified protocol. The callback allows dynamic calculation
 *  of setup delays based on BOD parameters.
 */
/*************************************************************************************************/
void BbRegisterSetupDelayCback(uint8_t protId, BbSetupDelayCback_t cback);

/*************************************************************************************************/
/*!
 *  \brief      Set termination flag of current executing BOD.
 *
 *  \note       This function is expected to be called during the execution context of the
 *              current executing BOD, typically in the related ISRs. In the end, termination
 *              flag will help to decide if BbTerminateBod() should be called.
 */
/*************************************************************************************************/
void BbSetBodTerminateFlag(void);

/*************************************************************************************************/
/*!
 *  \brief      Get termination state of current executing BOD.
 *
 *  \return     true if termination flag set, false otherwise.
 */
/*************************************************************************************************/
bool BbGetBodTerminateFlag(void);

/*************************************************************************************************/
/*!
 *  \brief      Terminate a BOD immediately.
 *
 *  \note       This function is expected to be called during the execution context of the
 *              current executing BOD, typically in the related ISRs.
 */
/*************************************************************************************************/
void BbTerminateBod(void);

/*************************************************************************************************/
/*!
 *  \brief      Get BB clock accuracy.
 *
 *  \return     Clock accuracy in part per million.
 *
 *  Returns the current BB clock accuracy.
 */
/*************************************************************************************************/
uint16_t BbGetClockAccuracy(void);

/*************************************************************************************************/
/*!
 *  \brief      Get RF setup delay.
 *
 *  \return     RF setup delay in microseconds.
 *
 *  Returns the RF setup delay.
 */
/*************************************************************************************************/
uint16_t BbGetRfSetupDelayUs(void);

/*************************************************************************************************/
/*!
 *  \brief      Get scheduler setup delay.
 *
 *  \return     Scheduler setup delay in microseconds.
 *
 *  Returns the scheduler setup delay.
 */
/*************************************************************************************************/
uint16_t BbGetSchSetupDelayUs(void);

/*************************************************************************************************/
/*!
 *  \brief     Return maximum CTE length supported.
 *
 *  \return    Maximum CTE length supported.
 *
 *  Returns the maximum CTE length;
 */
/*************************************************************************************************/
uint8_t BbGetMaxCteLen(void);

/*************************************************************************************************/
/*!
 *  \brief     Return the supported switching rates for the controller.
 *
 *  \return    Switching rate support bitfield.
 *
 *  Returns the switching rate support bitfield.
 */
/*************************************************************************************************/
uint8_t BbGetSupportedSwitchRates(void);

/*************************************************************************************************/
/*!
 *  \brief     Return number of antennae that the controller is supporting.
 *
 *  \return    Number of antennae
 *
 *  Returns the number of antennae supported.
 */
/*************************************************************************************************/
uint8_t BbGetNumAntennae(void);

/*************************************************************************************************/
/*!
 *  \brief     Return the maximum switching pattern length.
 *
 *  \return    Maximum switch rate length.
 *
 *  Returns the maximum switching rate pattern length.
 */
/*************************************************************************************************/
uint8_t BbGetMaxSwitchPatternLen(void);

/*************************************************************************************************/
/*!
 *  \brief     Return supported CTE types of this controller.
 *
 *  \return    Supported CTE types.
 *
 *  Returns the supported CTE types of the controller.
 */
/*************************************************************************************************/
uint8_t BbGetSupportedCteTypes(void);

/*************************************************************************************************/
/*!
 *  \brief      Returns the ID of the active protocol.
 *
 *  \return     Protocol operation in progress.
 */
/*************************************************************************************************/
uint8_t BbGetActiveProtocol(void);

/*! \} */    /* BB_API_CTRL */

#ifdef __cplusplus
};
#endif

#endif /* BB_API_H */
