/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      ADC Interface
 *
 *  Copyright (c) 2024 Packetcraft, Inc.  All rights reserved.
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

#ifndef PAL_ADC_H
#define PAL_ADC_H

#include "pal_adc_board.h"
#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_ADC
 *  \{ */

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Result of conversion in microvolts. */
typedef int32_t PalAdcResultMicrovolts_t;

/*! \brief      Completion callback. */
typedef void (*PalAdcCompCback_t)(const PalAdcResultMicrovolts_t resultVolts);

/*! \brief      ADC State. */
typedef enum
{
  PAL_ADC_STATE_RESULT_VALID,    /*!< Requested conversion is immediately available. */
  PAL_ADC_STATE_RESULT_PENDING,  /*!< Requested conversion is delayed until event. */
  PAL_ADC_STATE_BUSY             /*!< Requested conversion is ignored, due to previous request still in progress. */
} PalAdcState_t;

/*! \brief      ADC Inputs. */
typedef enum
{
  PAL_ADC_INPUTS  /*!< Inputs, defined in pal_adc_board.h. */
  PAL_ADC_MAX     /*!< Number of ADC instances. */
} PalAdcId_t;

/*! \brief      Peripheral configuration. */
typedef struct
{
  PalAdcId_t id;                /*!< ID. */
  PalAdcCompCback_t rdCback;    /*!< Read data completion callback. NULL means no return until result is ready. */
} PalAdcConfig_t;

/**************************************************************************************************
  Global Variables
**************************************************************************************************/

/*! \brief      Channel configurations, defined in pal_adc_board.c. */
extern const PalAdcChannelConfig_t PalAdcChannelConfig[PAL_ADC_MAX];

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/* Initialization */

/*************************************************************************************************/
/*!
 *  \brief      Initialize ADC.
 *
 *  \param      pCfg    Pointer to ADC configurations.
 *  \param      count   Number of ADC configurations.
 */
/*************************************************************************************************/
void PalADCInit(const PalAdcConfig_t *pCfg, const uint8_t count);

/*************************************************************************************************/
/*!
 *  \brief      De-Initialize ADC.
 */
/*************************************************************************************************/
void PalAdcDeInit(void);

/* Data Transfer */

/*************************************************************************************************/
/*!
 *  \brief      Read ADC, one channel.
 *
 *              If a callback was specified, then pResult is ignored, and the result is delayed
 *              until the conversion is complete, and the result is provided to the callback.
 *              If a callback was not specified, then the result is returned immediately to,
 *              pResult if provided.
 *
 *  \param      id        ADC ID.
 *  \param      pResult   Result of conversion, in counts; if results pending, then INT16_MIN.
 *
 *  \return     State after read request;
 *              PAL_ADC_STATE_BUSY if previous conversion still in progress;
 *              PAL_ADC_STATE_RESULT_VALID if conversion result is immediately available in pData;
 *              PAL_ADC_STATE_RESULT_PENDING if conversion result is delated until callback
 */
/*************************************************************************************************/
PalAdcState_t PalAdcReadData(const PalAdcId_t id, PalAdcResultMicrovolts_t *pResult);

/*! \} */    /* PAL_ADC */

#ifdef __cplusplus
};
#endif

#endif /* PAL_ADC_H */
