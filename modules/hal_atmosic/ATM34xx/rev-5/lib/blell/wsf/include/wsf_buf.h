/*************************************************************************************************/
/*!
 *  \file   wsf_buf.h
 *
 *  \brief  Buffer pool service.
 *
 *  Copyright (c) 2009-2018 Arm Ltd. All Rights Reserved.
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
#ifndef WSF_BUF_H
#define WSF_BUF_H

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup WSF_BUF_API
 *  \{ */

/**************************************************************************************************
  Configuration
**************************************************************************************************/

/*! \brief Check if trying to free a buffer that is already free */
#ifndef WSF_BUF_FREE_CHECK_ASSERT
#define WSF_BUF_FREE_CHECK_ASSERT true
#endif

/*! \brief Assert on best-fit buffer allocation failure */
#ifndef WSF_BUF_ALLOC_BEST_FIT_FAIL_ASSERT
#define WSF_BUF_ALLOC_BEST_FIT_FAIL_ASSERT false
#endif

/*! \brief Assert on buffer allocation failure */
#ifndef WSF_BUF_ALLOC_FAIL_ASSERT
#define WSF_BUF_ALLOC_FAIL_ASSERT true
#endif

/*! \brief Buffer histogram stats */
#ifndef WSF_BUF_STATS_HIST
#define WSF_BUF_STATS_HIST false
#endif

/**************************************************************************************************
  Macros
**************************************************************************************************/

/*! \brief Length of the buffer statistics array */
#define WSF_BUF_STATS_MAX_LEN       128

/*! \brief Max number of pools can allocate */
#define WSF_BUF_STATS_MAX_POOL      32

/*! \brief Failure Codes */
#define WSF_BUF_ALLOC_FAILED        1

#ifndef WSF_BUF_STATS
/*! \brief Enable buffer allocation statistics. */
#define WSF_BUF_STATS false
#endif

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief Buffer pool descriptor structure */
typedef struct
{
  uint16_t   len;                  /*!< Length of buffers in pool */
  uint8_t    num;                  /*!< Number of buffers in pool */
} wsfBufPoolDesc_t;

/*! \brief Pool statistics */
typedef struct
{
  uint16_t   bufSize;              /*!< Pool buffer size. */
  uint8_t    numBuf;               /*!< Total number of buffers. */
  uint8_t    numAlloc;             /*!< Number of outstanding allocations. */
  uint8_t    maxAlloc;             /*!< High allocation watermark. */
  uint16_t   maxReqLen;            /*!< Maximum requested buffer length. */
} WsfBufPoolStat_t;

/*! \brief WSF buffer diagnostics - buffer allocation failure */
typedef struct
{
  uint8_t    taskId;               /*!< Task handler ID where failure occurred */
  uint16_t   len;                  /*!< Length of buffer being allocated */
} wsfBufDiagAllocFail_t;

/*! \brief WSF buffer diagnostics message */
typedef struct
{
  union
  {
    wsfBufDiagAllocFail_t alloc;   /*!< Buffer allocation failure */
  } param;                         /*!< Union of diagnostic data types. */

  uint8_t type;                    /*!< Type of error */
} WsfBufDiag_t;

/**************************************************************************************************
  Callback Function Datatypes
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief  Callback providing WSF buffer diagnostic messages.
 *
 *  \param  pInfo     Diagnostics message.
 */
/*************************************************************************************************/
typedef void (*WsfBufDiagCback_t)(WsfBufDiag_t *pInfo);

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief  Calculate size required by the buffer pool.
 *
 *  \param  numPools  Number of buffer pools.
 *  \param  pDesc     Array of buffer pool descriptors, one for each pool.
 *
 *  \return Amount of pBufMem used.
 */
/*************************************************************************************************/
uint32_t WsfBufCalcSize(uint8_t numPools, wsfBufPoolDesc_t *pDesc);

/*************************************************************************************************/
/*!
 *  \brief  Initialize the buffer pool service.  This function should only be called once
 *          upon system initialization.
 *
 *  \param  numPools  Number of buffer pools.
 *  \param  pDesc     Array of buffer pool descriptors, one for each pool.
 *
 *  \return Amount of pBufMem used or 0 for failures.
 */
/*************************************************************************************************/
uint32_t WsfBufInit(uint8_t numPools, wsfBufPoolDesc_t *pDesc);

/*************************************************************************************************/
/*!
 *  \brief  Allocate a buffer.
 *
 *  \param  len     Length of buffer to allocate.
 *
 *  \return Pointer to allocated buffer or NULL if allocation fails.
 */
/*************************************************************************************************/
void *WsfBufAlloc(uint16_t len);

/*************************************************************************************************/
/*!
 *  \brief  Free a buffer.
 *
 *  \param  pBuf    Buffer to free.
 */
/*************************************************************************************************/
void WsfBufFree(void *pBuf);

/*************************************************************************************************/
/*!
 *  \brief  Diagnostic function to get the buffer allocation statistics.
 *
 *  \return Buffer allocation statistics array.
 */
/*************************************************************************************************/
uint8_t *WsfBufGetAllocStats(void);

/*************************************************************************************************/
/*!
 *  \brief  Diagnostic function to get the number of overflow times for each pool.
 *
 *  \return Overflow times statistics array
 */
/*************************************************************************************************/
uint8_t *WsfBufGetPoolOverFlowStats(void);

/*************************************************************************************************/
/*!
 *  \brief  Get number of pools.
 *
 *  \return Number of pools.
 */
/*************************************************************************************************/
uint8_t WsfBufGetNumPool(void);

/*************************************************************************************************/
/*!
 *  \brief  Get statistics for each pool.
 *
 *  \param  pStat   Buffer to store the statistics.
 *  \param  numPool Number of pool elements.
 *
 *  \return Pool statistics.
 */
/*************************************************************************************************/
void WsfBufGetPoolStats(WsfBufPoolStat_t *pStat, uint8_t numPool);

/*************************************************************************************************/
/*!
 *  \brief  Called to register the buffer diagnostics callback function.
 *
 *  \param  callback   Pointer to the callback function.
 */
/*************************************************************************************************/
void WsfBufDiagRegister(WsfBufDiagCback_t callback);

/*************************************************************************************************/
/*!
 *  \brief  Get the number of outstanding memory pool buffers
 *
 *  \return The number of outstanding buffers
 */
/*************************************************************************************************/
uint32_t WsfBufNumOutstanding(void);

/*! \} */    /* WSF_BUF_API */

#ifdef __cplusplus
};
#endif

#endif /* WSF_BUF_H */
