/**
 *******************************************************************************
 *
 * @file at_cmd.h
 *
 * @brief Atmosic AT Command Core
 *
 * Copyright (C) Atmosic 2021-2026
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 *******************************************************************************
 */

#pragma once

/**
 *******************************************************************************
 * @defgroup ATM_BTFM_ATCORE AT command core
 * @ingroup ATM_BTFM_PROC
 * @brief ATM bluetooth framework AT command core
 *
 * This module contains the necessary procedure of AT command core.
 *
 * @{
 *******************************************************************************
 */

#include <stdbool.h>
#include "at_cmd_pasr.h"

#ifdef __cplusplus
extern "C" {
#endif

/// The length of AT command response
#ifndef AT_CMD_RESP_LEN
#ifdef CONFIG_AT_CMD_RESP_LEN
#define AT_CMD_RESP_LEN CONFIG_AT_CMD_RESP_LEN
#else
#define AT_CMD_RESP_LEN 256
#endif
#endif // AT_CMD_RESP_LEN

#ifndef AT_CMD_RSP_FMT_MAX_LEN
#ifdef CONFIG_AT_CMD_RSP_FMT_MAX_LEN
#define AT_CMD_RSP_FMT_MAX_LEN CONFIG_AT_CMD_RSP_FMT_MAX_LEN
#else
#define AT_CMD_RSP_FMT_MAX_LEN 64
#endif
#endif // AT_CMD_RSP_FMT_MAX_LEN

/// Invalid channel number
#define AT_CMD_INVALID_CH 0xFF

/// The transfer layer support number
#ifndef AT_CMD_XFER_MAX_NUM
#define AT_CMD_XFER_MAX_NUM 3
#endif // AT_CMD_XFER_MAX_NUM

/// Command type
typedef enum {
    /// Test command. "AT+<x>=?"
    at_cmd_type_test,
    /// Read command. "AT+<x>?"
    at_cmd_type_query,
    /// Exec command. "AT+<x>="
    at_cmd_type_exec
} at_cmd_type_t;

/// AT command error code
typedef enum {
    /// No error
    AT_CMD_ERR_NO_ERROR,
    /// Command not support
    AT_CMD_ERR_NOT_SUPPORT,
    /// Wrong argument count
    AT_CMD_ERR_WRONG_ARGU_CNT,
    /// Wrong argument range
    AT_CMD_ERR_WRONG_ARGU_RANGE,
    /// Wrong argument type
    AT_CMD_ERR_WRONG_ARGU_TYPE,
    /// Wrong argument type or range
    AT_CMD_ERR_WRONG_ARGU_TYPE_OR_RANGE,
    /// Wrong argument content
    AT_CMD_ERR_WRONG_ARGU_CONTENT,
    /// Wrong execute type
    AT_CMD_ERR_WRONG_EXECUTE_TYPE,
    /// Specific error
    AT_CMD_ERR_SPECIFIC_ERR = 0x80
} at_cmd_err_t;

/// AT command channel
typedef uint8_t at_cmd_ch_t;

/// Forward declaration for at_cmd_param_t
typedef struct at_cmd_param_t at_cmd_param_t;

/// The AT command handler function pointer
typedef void (*at_cmd_hdlr_t)(at_cmd_param_t *param);

/// AT command definition
typedef struct {
	/// Command string. Ex: BCSC for AT+BCSC=
	char const *str;
	/// AT command parameter format
	char const *fmt;
	/// Expect paramter numbers
	uint16_t const param_num;
	/// AT command handler
	at_cmd_hdlr_t hdlr;
	/// Test response string. If no, left NULL.
	char const *test_str;
	/// Response format string (same format as CMD_PARM_FMT)
	/// e.g., "B,W,A(6~6)" for uint8_t, uint16_t, 6-byte array
	char const *rsp_fmt;
	/// Number of response parameters
	uint16_t rsp_num;
} at_cmd_t;

/// AT command parameter for handler
typedef struct at_cmd_param_t {
	/// AT command type
	at_cmd_type_t type;
	/// Error code
	at_cmd_err_t err;
	/// Argument count
	uint16_t argc;
	/// Argument content
	at_pasr_tlv_t **args;
	/// AT command data residue
	bool data_residue;
	/// Transport channel
	at_cmd_ch_t ch;
	/// Application error code
	uint16_t app_err;
	/// Command string
	char const *str;
	/// Command definition
	at_cmd_t const *cmd;
} at_cmd_param_t;

typedef enum {
    /// AT command response (prefix)
    at_prefix = 1,
    /// AT command response (data)
    at_data = (1 << 1),
    /// AT command response (postfix)
    at_postfix = (1 << 2),
    /// AT command response (prefix + data + postfix)
    at_all = at_prefix | at_data | at_postfix
} at_cmd_resp_flag_t;

/// The AT command response handler
typedef void (*at_cmd_resp_hdlr_t)(at_cmd_ch_t ch, void const *resp,
    uint16_t len);

/**
 *******************************************************************************
 * @brief The transport layer handler
 * @param[in] ch The channel got from @ref at_cmd_alloc
 * @param[in, out] data Data string
 * @param[in, out] len The length of data string
 *******************************************************************************
 */
typedef char const *(*at_cmd_xfer_hdlr_t)(at_cmd_ch_t ch, void const *data,
    uint16_t *len);

/// Built-in transport for UART
#define AT_CMD_DFT_XFER_UART ((at_cmd_xfer_hdlr_t)0x1)

/// The context of AT command allocate
typedef struct {
    /// Transport layer handler
    at_cmd_xfer_hdlr_t xfer;
    /// AT command response handler
    at_cmd_resp_hdlr_t resp;
} at_cmd_alloc_ctx_t;

/**
 *******************************************************************************
 * @brief Define AT command with response format
 * @param[in] cmd Command name
 * @param[in] fmt Command parameter format
 *    b(#~@) int8_t. (#: minimal number, @: maximal number)
 *    B(#~@) uint8_t.
 *        B(1~2), unsigned 8 bit number from 1 to 2.
 *    w(#~@) int16_t
 *    W(#~@) uint16_t.
 *        W(~5), unsigned 16 bit number from 0 to 5.
 *    d(#~@) int32_t.
 *        d(-3~10), signed 32 bit number from -3 to 10.
 *        d(~1000), signed 32 bit number from -2147483647 to 1000
 *    D(#~@) uint32_t.
 *        D(30~), unsigned 32 bit number from 30 to 4294967295
 *    A(#~@) byte array.
 *        A, byte array with any length
 *        A(3~), byte array with at least 3 bytes.
 *        A(2~5), byte array with length from 2 to 5 octets.
 *        A(6~6), byte array with 6 bytes exactly.
 *    S(#~@) UTF8 string.
 *        S, string with length 0 to 255 octets.
 *        S(3~), string with length from 3 to 255 octets.
 *        S(2~5), string with length from 2 to 5 octets.
 * @param[in] num Number of command parameters
 * @param[in] hdl Command handler function
 * @param[in] test Test response string
 * @param[in] rsp_fmt Response parameter format (same as CMD_PARM_FMT)
 * @param[in] rsp_num Number of response parameters
 *
 * Example:
 *   AT_COMMAND(TAGMODE, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler,
 *       CMD_PARM_DESC, "B", 1)
 *
 * This macro generates a command definition (at_cmd_t) with embedded
 * response format
 *******************************************************************************
 */
#define AT_COMMAND(cmd, fmt, num, hdl, test, rsp_fmt, rsp_num)                                     \
	AT_COMMAND_VAR(p##hdl, cmd, fmt, num, hdl, test, rsp_fmt, rsp_num)

#define AT_COMMAND_VAR(var, cmd, fmt, num, hdl, test, rsp_fmt, rsp_num)                            \
	static const at_cmd_t __attribute__((section(".at_cmd." cmd), used))                       \
	var = {cmd, fmt, num, hdl, test, rsp_fmt, rsp_num}

/**
 *******************************************************************************
 * @brief Allocate and configure AT command context
 * @param[in] ctx The context of AT command
 * @return Channel number if successful; otherwise return AT_CMD_INVALID_CH
 *******************************************************************************
 */
__NONNULL_ALL
at_cmd_ch_t at_cmd_alloc(at_cmd_alloc_ctx_t const *ctx);

/**
 *******************************************************************************
 * @brief AT command process
 * @param[in] ch The channel got from @ref at_cmd_alloc
 * @param[in] data Input string w/o command header (i.e. AT+)
 * @param[in] data_len The length of input string
 * @return true if successful
 *******************************************************************************
 */
__NONNULL(2)
bool at_cmd_proc(at_cmd_ch_t ch, void const *data, uint16_t data_len);

/**
 *******************************************************************************
 * @brief Send response based on command definition response format
 * @param[in] ch The channel got from @ref at_cmd_alloc
 * @param[in] flag @ref at_cmd_resp_flag_t
 * @param[in] cmd Command definition (@ref at_cmd_t)
 * @param[in] offset Starting parameter offset (0-based)
 * @param[in] param_count Number of parameters to send
 * @param[in] ... Variable arguments matching the parameter range
 *
 * @note This function sends response parameters specified by offset and
 *       param_count. Useful for sending all parameters at once or in
 *       multiple calls. For array parameters (A type), pass the pointer
 *       and length as two arguments.
 *
 * Example:
 *   AT_COMMAND(MYTEST, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler,
 *       CMD_PARM_DESC, "B,W,D", 3)
 *
 *   // Send all parameters at once
 *   at_cmd_resp(ch, at_all, param->cmd, 0, 3, val1, val2, val3);
 *
 *   // Or send parameters in multiple calls
 *   at_cmd_resp(ch, at_prefix | at_data, param->cmd, 0, 1, val1);
 *   at_cmd_resp(ch, at_data, param->cmd, 1, 1, val2);
 *   at_cmd_resp(ch, at_data | at_postfix, param->cmd, 2, 1, val3);
 *
 *   // For array parameters, pass pointer and length
 *   AT_COMMAND(BLEGATT, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler,
 *       CMD_PARM_DESC, "W,A(16~16)", 2)
 *   at_cmd_resp(ch, at_all, param->cmd, 0, 2, sec_prop, uuid_ptr,
 *       uuid_len);
 *   // Output: +BLEGATT:4660,0102030405060708090A0B0C0D0E0F10\r\n
 *   // (4660 is decimal representation of 0x1234)
 *******************************************************************************
 */
__NONNULL(3)
void at_cmd_resp(at_cmd_ch_t ch, at_cmd_resp_flag_t flag, at_cmd_t const *cmd, uint16_t offset,
		 uint16_t param_count, ...);

/**
 *******************************************************************************
 * @brief Send raw data directly without prefix/postfix
 * @param[in] ch The channel got from @ref at_cmd_alloc
 * @param[in] data Raw data pointer
 * @param[in] len Data length
 *
 * @note This function sends raw bytes directly without adding
 *       AT command prefix (\r\n) or postfix (\r\n)
 *******************************************************************************
 */
__NONNULL(2)
void at_cmd_send_raw(at_cmd_ch_t ch, void const *data, uint16_t len);

/**
 *******************************************************************************
 * @brief Retrieve number of AT commands available
 * @return How many AT commands available
 *******************************************************************************
 */
uint16_t at_cmd_count(void);

#ifdef __cplusplus
}
#endif

///@} ATM_BTFM_ATCORE
