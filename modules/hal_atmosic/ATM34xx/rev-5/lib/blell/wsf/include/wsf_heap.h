/*************************************************************************************************/
/*!
 *  \file   wsf_heap.h
 *
 *  \brief  Buffer heap service.
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
#ifndef WSF_HEAP_H
#define WSF_HEAP_H

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup WSF_HEAP_API
 *  \{ */
/**************************************************************************************************
  Global Variables
**************************************************************************************************/

extern uint8_t *SystemHeapStart;
extern uint32_t SystemHeapSize;

#define WSF_HEAP_INIT_MEM(initFunc, pFreeMem, freeMemAvail, totalMemUsed) do { \
  uint32_t memUsed ## initFunc = initFunc(pFreeMem, freeMemAvail); \
  pFreeMem += memUsed ## initFunc; \
  freeMemAvail -= memUsed ## initFunc; \
  totalMemUsed += memUsed ## initFunc; \
} while (0)

#define WSF_HEAP_INIT_ALLOC(pAvailMem, pStruct, freeMemAvail) do { \
  pAvailMem = WsfHeapAlignWord(pAvailMem); \
  pStruct = (__typeof__(pStruct)) pAvailMem; \
  pAvailMem += sizeof(*pStruct); \
  WSF_ASSERT((uint32_t) (pAvailMem - pFreeMem) <= freeMemAvail); \
} while (0)

/*************************************************************************************************/
/*!
 *  \brief      Initialize heap memory.
 */
/*************************************************************************************************/
void WsfHeapInit(void);

/*************************************************************************************************/
/*!
 *  \brief      Get heap available.
 *
 *  \return     Number of bytes of heap memory available.
 */
/*************************************************************************************************/
uint32_t WsfHeapCountAvailable(void);

/*************************************************************************************************/
/*!
 *  \brief      Get heap used.
 *
 *  \return     Number of bytes of heap memory used.
 */
/*************************************************************************************************/
uint32_t WsfHeapCountUsed(void);

/*************************************************************************************************/
/*!
 *  \brief      Reserve heap memory.
 *
 *  \param      size    Number of bytes of heap memory used.
 */
/*************************************************************************************************/
void WsfHeapAlloc(uint32_t size);

/*************************************************************************************************/
/*!
 *  \brief      Get next available heap memory.
 *
 *  \return     Address of the start of heap memory.
 */
/*************************************************************************************************/
void *WsfHeapGetFreeStartAddress(void);

/*************************************************************************************************/
/*!
 *  \brief      Align memory pointer to next word.
 *
 *  \return     Aligned memory pointer
 */
/*************************************************************************************************/
void *WsfHeapAlignWord(void *pAddr);

/*************************************************************************************************/
/*!
 *  \brief  get heap start address.
 *
 *  \return heap start.
 */
/*************************************************************************************************/
void *WsfHeapGetStartAddress(void);

/*************************************************************************************************/
/*!
 *  \brief  get heap end address.
 *
 *  \return heap end.
 */
/*************************************************************************************************/
void *WsfHeapGetEndAddress(void);

/*! \} */    /* WSF_HEAP_API */

#ifdef __cplusplus
};
#endif

#endif /* WSF_HEAP_H */
