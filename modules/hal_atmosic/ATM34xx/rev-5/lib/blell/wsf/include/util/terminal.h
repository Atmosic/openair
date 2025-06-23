/*************************************************************************************************/
/*!
 *  \file       terminal.h
 *
 *  \brief      Terminal handler.
 *
 *  Copyright (c) 2015-2018 Arm Ltd. All Rights Reserved.
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

#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdarg.h>

#include "wsf_types.h"
#include "wsf_os.h"

/*! \addtogroup WSF_UTIL_API
 *  \{ */

/**************************************************************************************************
  Macros
**************************************************************************************************/

#ifndef TERMINAL_MAX_ARGC
#define TERMINAL_MAX_ARGC           8u          /*!< Maximum number of arguments to any command. */
#endif
#ifndef TERMINAL_MAX_COMMAND_LEN
#define TERMINAL_MAX_COMMAND_LEN    256u        /*!< Maximum length of command line. */
#endif
#ifndef TERMINAL_PRINTF_MAX_LEN
#define TERMINAL_PRINTF_MAX_LEN     256u        /*!< Maximum length of any printed output. */
#endif
#define TERMINAL_STRING_PROMPT      "> "        /*!< Prompt string. */
#define TERMINAL_STRING_ERROR       "ERROR: "   /*!< Error prefix. */
#define TERMINAL_STRING_USAGE       "USAGE: "   /*!< Usage prefix. */
#define TERMINAL_STRING_NEW_LINE    "\r\n"      /*!< New line string. */

/*! \brief    Terminal command error codes. */
enum
{
  TERMINAL_ERROR_OK                 = 0,  /*!< Command completed. */
  TERMINAL_ERROR_BAD_ARGUMENTS      = 1,  /*!< ERROR: Invalid argument(s) */
  TERMINAL_ERROR_TOO_FEW_ARGUMENTS  = 2,  /*!< ERROR: Too few arguments */
  TERMINAL_ERROR_TOO_MANY_ARGUMENTS = 3,  /*!< ERROR: Too many arguments */
  TERMINAL_ERROR_EXEC               = 4   /*!< Command completed with execution error. */
};

#ifndef TERMINAL_TIMESTAMP_INCLUDED
#define TERMINAL_TIMESTAMP_INCLUDED                 false
#endif

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief  Handler for a terminal command.
 *
 *  \param  argc      The number of arguments passed to the command.
 *  \param  argv      The array of arguments; the 0th argument is the command.
 *
 *  \return Error code.
 */
/*************************************************************************************************/
typedef uint8_t (*terminalHandler_t)(uint32_t argc, char **argv);

/*************************************************************************************************/
/*!
 *  \brief  Handler for transmit.
 *
 *  \param  pBuf      Buffer to transmit.
 *  \param  len       Number of bytes to transmit.
 */
/*************************************************************************************************/
typedef bool (*terminalUartTx_t)(const uint8_t *pBuf, uint32_t len);

/*! \brief  Terminal command. */
typedef struct terminalCommand_tag
{
  struct terminalCommand_tag   *pNext;     /*!< Pointer to next command in list. */
  const char                   *pName;     /*!< Name of command. */
  const char                   *pHelpStr;  /*!< Help String for command. */
  terminalHandler_t            handler;    /*!< Handler for command. */
} terminalCommand_t;

/**************************************************************************************************
  Function Prototypes
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief  Initialize terminal.
 *
 *  \param  handlerId   Handler ID for TerminalHandler().
 *  \param  echo        Echo enable.
 */
/*************************************************************************************************/
void TerminalInit(wsfHandlerId_t handlerId, bool echo);

/*************************************************************************************************/
/*!
 *  \brief  Register the UART Tx Function for the platform.
 *
 *  \param  uartTxFunc    UART Tx callback function.
 */
/*************************************************************************************************/
void TerminalRegisterUartTxFunc(terminalUartTx_t uartTxFunc);

/*************************************************************************************************/
/*!
 *  \brief  Register command with terminal.
 *
 *  \param  pCommand    Command.
 */
/*************************************************************************************************/
void TerminalRegisterCommand(terminalCommand_t *pCommand);

/*************************************************************************************************/
/*!
 *  \brief  Handler for terminal messages.
 *
 *  \param  event       WSF event mask.
 *  \param  pMsg        WSF message.
 */
/*************************************************************************************************/
void TerminalHandler(wsfEventMask_t event, wsfMsgHdr_t *pMsg);

/*************************************************************************************************/
/*!
 *  \brief  Called by application when a data byte is received.
 *
 *  \param  dataByte    received byte
 */
/*************************************************************************************************/
void TerminalRx(uint8_t dataByte);

/*************************************************************************************************/
/*!
 *  \brief  Called by application to transmit string.
 *
 *  \param  pStr      String.
 */
/*************************************************************************************************/
void TerminalTxStr(const char *pStr);

/*************************************************************************************************/
/*!
 *  \brief  Called by application to transmit character.
 *
 *  \param  c         Character.
 */
/*************************************************************************************************/
void TerminalTxChar(char c);

/*************************************************************************************************/
/*!
 *  \brief  Called by application to print formatted data.
 *
 *  \param  pStr      Message format string
 *  \param  ...       Additional arguments, printf-style
 */
/*************************************************************************************************/
void TerminalTxPrint(const char *pStr, ...);

/*************************************************************************************************/
/*!
 *  \brief  Application function to transmit data..
 *
 *  \param  pData     Data.
 *  \param  len       Length of data, in bytes.
 */
/*************************************************************************************************/
void TerminalTx(const uint8_t *pData, uint16_t len);

#if defined (TERMINAL_TIMESTAMP_INCLUDED) && (TERMINAL_TIMESTAMP_INCLUDED == true)

/*************************************************************************************************/
/*!
 *  \brief  Enable/disable timestamping TerminalTx
 *
 *  \param  enable    true to enable, else false.
 */
/*************************************************************************************************/
void TerminalTimestampEnable(bool enable);

#endif

/*! \} */    /* WSF_UTIL_API */

#endif /* TERMINAL_H */
