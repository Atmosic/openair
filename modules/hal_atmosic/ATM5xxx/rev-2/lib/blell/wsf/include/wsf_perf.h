/**
 *******************************************************************************
 *
 * @file   wsf_perf.h
 *
 * @brief  Performance tracking interface.
 *
 * Copyright (C) Atmosic 2023
 *
 *******************************************************************************
 */
#ifndef WSF_PERF_H
#define WSF_PERF_H

#ifdef __cplusplus
extern "C" {
#endif

#include "wsf_types.h"

/*! \addtogroup WSF_PERF_API
 *  \{ */

/**************************************************************************************************
  Macros
**************************************************************************************************/

#ifndef WSF_PERF_TRACKING
#define WSF_PERF_TRACKING     false
#endif

/**************************************************************************************************
  Data Types
**************************************************************************************************/

typedef enum {
  WSF_EVENT_UNINITIALIZED = 0,
  WSF_EVENT_154_ASSOC_INIT,
  WSF_EVENT_154_ASSOC_TX_CBACK,
  WSF_EVENT_154_ASSOC_RX_CBACK,
  WSF_EVENT_154_ASSOC_ERR_CBACK,
  WSF_EVENT_154_ASSOC_ASSOC_REQ_TX,
  WSF_EVENT_154_ASSOC_DATA_REQ_TX,
  WSF_EVENT_154_ASSOC_ASSOC_RSP_RX,
  WSF_EVENT_154_ASSOC_FINISH,
  WSF_EVENT_154_DATA_ASSOC_REQ_RX,
  WSF_EVENT_154_DATA_QUEUE_INDIRECT,
  WSF_EVENT_154_DATA_FP_CHECK,
  WSF_EVENT_154_DATA_INDIRECT_TX,
} WsfPerfEvent_t;

typedef struct {
    uint16_t event;
    uint32_t time;
} WsfPerfInstance_t;

/**************************************************************************************************
  Function Prototypes
**************************************************************************************************/

#if defined(WSF_PERF_TRACKING) && WSF_PERF_TRACKING == true
/*************************************************************************************************/
/*!
 *  \brief  Track event timestamp for performance monitoring
 *
 *  \param  event     The event that just occurred
 */
/*************************************************************************************************/
void WsfPerfTrack(WsfPerfEvent_t event);

/*************************************************************************************************/
/*!
 *  \brief  Get an array of traced events, clearing the stored events
 *
 *  \param  len       Length of returned array. Pass in 0, get back actual value
 *  \return Array containing all traced events from initialization until the buffer is filled
 */
/*************************************************************************************************/
WsfPerfInstance_t *WsfPerfGetClearResults(uint8_t *len);
#else
#define WsfPerfTrack(event) ((void) event)
#define WsfPerfGetClearResults(len) NULL
#endif

/*! \} */    /* WSF_PERF_API */

#ifdef __cplusplus
};
#endif

#endif /* WSF_PERF_H */
