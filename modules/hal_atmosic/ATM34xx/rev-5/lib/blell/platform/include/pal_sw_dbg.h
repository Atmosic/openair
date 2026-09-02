/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      Software logic analyzer interface.
 *
 *  Copyright (C) Atmosic 2026
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

#ifndef PAL_SW_DBG_H
#define PAL_SW_DBG_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
  Macros
**************************************************************************************************/

#ifndef SW_DBG_TRACE_EN
#ifdef DEBUG
#define SW_DBG_TRACE_EN                    1
#else
#define SW_DBG_TRACE_EN                    0
#endif
#endif

#define SW_DBG_USE_LC_TIME                 (1UL << 0)
#define SW_DBG_TRACE_SCH_EVT               (1UL << 1)
#define SW_DBG_TRACE_SCH_INSERT            (1UL << 2)
#define SW_DBG_TRACE_PAL_RADIO_STATUS      (1UL << 3)
#define SW_DBG_TRACE_HCI_CMD_EVT           (1UL << 4)
#define SW_DBG_TRACE_HCI_ACL               (1UL << 5)
#define SW_DBG_TRACE_LLCP_OP               (1UL << 6)
#define SW_DBG_TRACE_LLCP_PROC             (1UL << 7)
#define SW_DBG_TRACE_USER_PIN              (1UL << 8)
#define SW_DBG_TRACE_USER_VALUE            (1UL << 9)

#define SW_DBG_TRACE_MASK_ENABLED(mask)    (PalSwDbgTraceMask & (mask))

#define SW_DBG_LLCP_OP_RX                  0U
#define SW_DBG_LLCP_OP_TX                  1U

/**************************************************************************************************
  Global Variables
**************************************************************************************************/

extern uint32_t PalSwDbgTraceMask;

/**************************************************************************************************
  Data Types
**************************************************************************************************/

typedef enum
{
  SW_DBG_SCH_EVT,
  SW_DBG_SCH_INSERT_AT_DUE,
  SW_DBG_SCH_INSERT_NEXT_AVA,
  SW_DBG_SCH_INSERT_EARLY,
  SW_DBG_SCH_INSERT_LATE,
  SW_DBG_PAL_RADIO_STATUS,
  SW_DBG_HCI_CMD,
  SW_DBG_HCI_EVT,
  SW_DBG_HCI_ACL_FROM_HOST,
  SW_DBG_HCI_ACL_TO_HOST,
  SW_DBG_LLCP_OP,
  SW_DBG_LLCP_PROC,
  SW_DBG_DUMP_START = 255,
} sw_dbg_common_type_t;

typedef struct
{
  uint32_t type;
  uint32_t time;
  uint32_t value;
} PalSwDbgEntry_t;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief      Record a GPIO assertion.
 *
 *  \param      pin_num     GPIO pin number.
 */
/*************************************************************************************************/
void PalSwDbgPinSet(uint16_t pin_num);

/*************************************************************************************************/
/*!
 *  \brief      Record a GPIO deassertion.
 *
 *  \param      pin_num     GPIO pin number.
 */
/*************************************************************************************************/
void PalSwDbgPinClear(uint16_t pin_num);

/*************************************************************************************************/
/*!
 *  \brief      Record a common trace value.
 *
 *  \param      type        Trace value type.
 *  \param      value       Trace value.
 */
/*************************************************************************************************/
void PalSwDbgCommonValue(sw_dbg_common_type_t type, uint32_t value);

/*************************************************************************************************/
/*!
 *  \brief      Record a user trace value.
 *
 *  \param      num         User trace value number.
 *  \param      value       Trace value.
 */
/*************************************************************************************************/
void PalSwDbgUserValue(uint8_t num, uint32_t value);

/*************************************************************************************************/
/*!
 *  \brief      Get the next software trace buffer write index.
 *
 *  The caller must disable interrupts when a consistent snapshot is needed.
 *
 *  \return     Index of the next entry to be written.
 */
/*************************************************************************************************/
uint16_t PalSwDbgGetIndex(void);

/*************************************************************************************************/
/*!
 *  \brief      Initialize software logic analyzer tracing.
 *
 *  \param      pDumpTable  Dump table buffer.
 *  \param      entryNum    Number of entries in the dump table.
 *  \param      traceMask   Bit mask of trace categories to enable.
 */
/*************************************************************************************************/
void PalSwDbgInit(PalSwDbgEntry_t *pDumpTable, uint16_t entryNum,
    uint32_t traceMask);

typedef enum
{
  SW_DBG_RADIO_ON,
  SW_DBG_RADIO_STOP,
  SW_DBG_RADIO_DONE,
} sw_dbg_radio_status;

typedef enum
{
  SW_DBG_RADIO_TX,
  SW_DBG_RADIO_RX,
} sw_dbg_radio_type;

#if SW_DBG_TRACE_EN

#define SW_DBG_SCH_TRACE_EVT_START(evt, bod) \
  do { \
    if (SW_DBG_TRACE_MASK_ENABLED(SW_DBG_TRACE_SCH_EVT)) \
    { \
      PalSwDbgCommonValue(SW_DBG_SCH_EVT, ((bod) << 8) | (evt)); \
    } \
  } while (0)

#define SW_DBG_SCH_TRACE_EVT_END(state) \
  do { \
    if (SW_DBG_TRACE_MASK_ENABLED(SW_DBG_TRACE_SCH_EVT)) \
    { \
      PalSwDbgCommonValue(SW_DBG_SCH_EVT, ((state) << 8) | 0xFF); \
    } \
  } while (0)

#define SW_DBG_SCH_INSERT(type, due_time) \
  do { \
    if (SW_DBG_TRACE_MASK_ENABLED(SW_DBG_TRACE_SCH_INSERT)) \
    { \
      PalSwDbgCommonValue(type, due_time); \
    } \
  } while (0)

#define SW_DBG_PAL_RADIO_ON_TRACE(type) \
  do { \
    if (SW_DBG_TRACE_MASK_ENABLED(SW_DBG_TRACE_PAL_RADIO_STATUS)) \
    { \
      PalSwDbgCommonValue(SW_DBG_PAL_RADIO_STATUS, \
          (type) << 2 | SW_DBG_RADIO_ON); \
    } \
  } while (0)

#define SW_DBG_PAL_RADIO_STOP_TRACE() \
  do { \
    if (SW_DBG_TRACE_MASK_ENABLED(SW_DBG_TRACE_PAL_RADIO_STATUS)) \
    { \
      PalSwDbgCommonValue(SW_DBG_PAL_RADIO_STATUS, SW_DBG_RADIO_STOP); \
    } \
  } while (0)

#define SW_DBG_PAL_RADIO_DONE_TRACE(type, status) \
  do { \
    if (SW_DBG_TRACE_MASK_ENABLED(SW_DBG_TRACE_PAL_RADIO_STATUS)) \
    { \
      PalSwDbgCommonValue(SW_DBG_PAL_RADIO_STATUS, \
          ((status) << 3) | ((type) << 2) | SW_DBG_RADIO_DONE); \
    } \
  } while (0)

#define SW_DBG_HCI_CMD(ogf, ocf, len) \
  do { \
    if (SW_DBG_TRACE_MASK_ENABLED(SW_DBG_TRACE_HCI_CMD_EVT)) \
    { \
      PalSwDbgCommonValue(SW_DBG_HCI_CMD, \
          ((len) << 24) | ((ogf) << 16) | (ocf)); \
    } \
  } while (0)

#define SW_DBG_HCI_EVT(pEvt) \
  do { \
    if (SW_DBG_TRACE_MASK_ENABLED(SW_DBG_TRACE_HCI_CMD_EVT)) \
    { \
      uint8_t *ptr = (uint8_t *)pEvt; \
      PalSwDbgCommonValue(SW_DBG_HCI_EVT, \
          (ptr[3] << 24) | (ptr[2] << 16) | (ptr[1] << 8 | ptr[0])); \
    } \
  } while (0)

#define SW_DBG_HCI_ACL_FROM_HOST(pHciHead) \
  do { \
    if (SW_DBG_TRACE_MASK_ENABLED(SW_DBG_TRACE_HCI_ACL)) \
    { \
      uint8_t *ptr = (uint8_t *)pHciHead; \
      PalSwDbgCommonValue(SW_DBG_HCI_ACL_FROM_HOST, \
          (ptr[3] << 16) | (ptr[2] << 8) | ptr[0]); \
    } \
  } while (0)

#define SW_DBG_HCI_ACL_TO_HOST(pHciHead) \
  do { \
    if (SW_DBG_TRACE_MASK_ENABLED(SW_DBG_TRACE_HCI_ACL)) \
    { \
      uint8_t *ptr = (uint8_t *)pHciHead; \
      PalSwDbgCommonValue(SW_DBG_HCI_ACL_TO_HOST, \
          (ptr[3] << 16) | (ptr[2] << 8) | ptr[0]); \
    } \
  } while (0)

#define SW_DBG_LLCP_OP_TRACE(opcode, direction) \
  do { \
    if (SW_DBG_TRACE_MASK_ENABLED(SW_DBG_TRACE_LLCP_OP)) \
    { \
      PalSwDbgCommonValue(SW_DBG_LLCP_OP, \
          (uint32_t)(opcode) | ((uint32_t)(direction) << 8)); \
    } \
  } while (0)

#define SW_DBG_LLCP_PROC_TRACE(event, proc) \
  do { \
    if (SW_DBG_TRACE_MASK_ENABLED(SW_DBG_TRACE_LLCP_PROC)) \
    { \
      PalSwDbgCommonValue(SW_DBG_LLCP_PROC, \
          ((uint32_t)(proc) << 8) | (event)); \
    } \
  } while (0)

#else

#define SW_DBG_SCH_TRACE_EVT_START(evt, bod)
#define SW_DBG_SCH_TRACE_EVT_END(state)
#define SW_DBG_SCH_INSERT(type, due_time)
#define SW_DBG_PAL_RADIO_ON_TRACE(type)
#define SW_DBG_PAL_RADIO_STOP_TRACE()
#define SW_DBG_PAL_RADIO_DONE_TRACE(type, status)
#define SW_DBG_HCI_CMD(ogf, ocf, len)
#define SW_DBG_HCI_EVT(pEvt)
#define SW_DBG_HCI_ACL_FROM_HOST(pHciHead)
#define SW_DBG_HCI_ACL_TO_HOST(pHciHead)
#define SW_DBG_LLCP_OP_TRACE(opcode, direction)
#define SW_DBG_LLCP_PROC_TRACE(event, proc)
#endif

#ifdef __cplusplus
};
#endif

#endif /* PAL_SW_DBG_H */
