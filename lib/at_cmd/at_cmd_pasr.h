/**
 *******************************************************************************
 *
 * @file at_cmd_pasr.h
 *
 * @brief Atmosic AT Command Parser
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
 * @defgroup ATM_BTFM_ATPASR AT command parser
 * @ingroup ATM_BTFM_PROC
 * @brief ATM bluetooth framework AT command parser
 *
 * This module contains the necessary procedure AT command parser.
 *
 * @{
 *******************************************************************************
 */

#include <stdint.h>
#include <compiler.h>

#ifdef __cplusplus
extern "C" {
#endif

/// AT command parser error code
typedef enum {
    /// OK
    AT_PASR_OK,
    /// Range exceed
    AT_PASR_RANGE_EXCEED,
    /// Wrong type
    AT_PASR_WRONG_TYPE,
    /// The parser not available
    AT_PASR_BUSY,
    /// No parameter
    AT_PASR_EMPTY_DATA,
    /// Insufficient resource
    AT_PASR_NO_MEMORY,
    /// Invalid parameter
    AT_PASR_INVALID_DATA,
    /// Extra parameter
    AT_PASR_MORE_DATA,
} at_pasr_err_t;

typedef enum {
    /// int8_t (b)
    at_pasr_dt_i8,
    /// uint8_t (B)
    at_pasr_dt_u8,
    /// int16_t (w)
    at_pasr_dt_i16,
    /// uint16_t (W)
    at_pasr_dt_u16,
    /// int32_t (d)
    at_pasr_dt_i32,
    /// uint32_t (D)
    at_pasr_dt_u32,
    /// Array (A)
    at_pasr_dt_array,
    /// String (S)
    at_pasr_dt_string,
    /// Unknow
    at_pasr_dt_unknow,
    /// Data type number
    at_pasr_dt_num = at_pasr_dt_unknow,
} at_pasr_dt_t;

/**
 *******************************************************************************
 * @brief Check parameter length
 * @param[in] P Structure parameter (@ref at_pasr_tlv_t)
 * @param[in] I Index
 * @param[in] LEN Length
 * @return true is enough size; otherwise return false
 *******************************************************************************
 */
#define AT_PASR_GET_PARAM_LEN_CHECK(P, I, LEN) ({ \
    (LEN == P->args[I]->length); \
})

/**
 *******************************************************************************
 * @brief Get parser parameter
 * @param[in] P Structure parameter (@ref at_pasr_tlv_t)
 * @param[in] T Type
 * @param[in] I Index
 * @return Parameter content
 *******************************************************************************
 */
#define AT_PASR_GET_PARAM(P, T, I) ({ \
    ASSERT_ERR(P->args[I]->type == at_pasr_dt_##T); \
    P->args[I]->T; \
})

/**
 *******************************************************************************
 * @brief Get parser parameter minimal value
 * @param[in] P Structure parameter (@ref at_pasr_tlv_t)
 * @param[in] T Type
 * @param[in] I Index
 * @return Parameter minimal value
 *******************************************************************************
 */
#define AT_PASR_GET_PARAM_MIN(P, T, I) ({ \
    P->args[I]->T##min; \
})

/**
 *******************************************************************************
 * @brief Get parser parameter maximal value
 * @param[in] P Structure parameter (@ref at_pasr_tlv_t)
 * @param[in] T Type
 * @param[in] I Index
 * @return Parameter maximal value
 *******************************************************************************
 */
#define AT_PASR_GET_PARAM_MAX(P, T, I) ({ \
    P->args[I]->T##max; \
})

/**
 *******************************************************************************
 * @brief Get parser parameter length
 * @param[in] P Structure parameter (@ref at_pasr_tlv_t)
 * @param[in] I Index
 * @return Parameter length
 *******************************************************************************
 */
#define AT_PASR_GET_PARAM_LEN(P, I) ({ \
    P->args[I]->length; \
})

typedef struct {
    /// Data type
    at_pasr_dt_t type;
    /// Error code
    at_pasr_err_t status;
    /// The TLV length
    uint16_t length;

    union {
	/// uint32_t
	struct {
	    uint32_t u32min;
	    uint32_t u32max;
	    uint32_t u32;
	};

	/// uint16_t
	struct {
	    uint16_t u16min;
	    uint16_t u16max;
	    uint16_t u16;
	};

	/// uint8_t
	struct {
	    uint8_t u8min;
	    uint8_t u8max;
	    uint8_t u8;
	};

	/// int32_t
	struct {
	    int32_t i32min;
	    int32_t i32max;
	    int32_t i32;
	};

	/// int16_t
	struct {
	    int16_t i16min;
	    int16_t i16max;
	    int16_t i16;
	};

	/// int8_t
	struct {
	    int8_t i8min;
	    int8_t i8max;
	    int8_t i8;
	};

	/// array (uint8_t)
	struct {
	    uint16_t arraymin;
	    uint16_t arraymax;
	    uint8_t array[];
	};

	/// string (char)
	struct {
	    uint16_t stringmin;
	    uint16_t stringmax;
	    char string[];
	};
    };
} at_pasr_tlv_t;

/**
 *******************************************************************************
 * @brief Validate the AT command
 * @param[in] input Input string
 * @param[in] format The format of AT command
 * @return Error code after parsing the input string
 *******************************************************************************
 */
__NONNULL(2)
at_pasr_err_t at_pasr_param_validate(char const *input, char const *format);

/**
 *******************************************************************************
 * @brief Get parameter of AT command after validating
 * @return Parameter of AT command
 *******************************************************************************
 */
at_pasr_tlv_t **at_pasr_param(void);

/**
 *******************************************************************************
 * @brief Get parameter of AT command by index after validating
 * @param[in] idx The parameter index of AT command
 * @return Parameter of AT command
 *******************************************************************************
 */
at_pasr_tlv_t *at_pasr_param_get(uint16_t idx);

/**
 *******************************************************************************
 * @brief How manay parameters of AT command after validating
 * @return Parameter of AT command
 *******************************************************************************
 */
uint16_t at_pasr_param_num_get(void);

/**
 *******************************************************************************
 * @brief Reset parser
 *******************************************************************************
 */
void at_pasr_clear(void);

/**
 *******************************************************************************
 * @brief Identify data type from format string token
 * @param[in] literal Format string token (e.g., "B", "W(1~7)", "A(6~6)")
 * @return Pointer to at_pasr_tlv_t with identified type and range info
 *
 * @note Caller must free the returned pointer
 *       Returns NULL if memory allocation fails
 *       Type will be at_pasr_dt_unknow if format is invalid
 *******************************************************************************
 */
at_pasr_tlv_t *at_pasr_dt_identify(char *literal);

/**
 *******************************************************************************
 * @brief Get printf format string for a data type
 * @param[in] type Data type (@ref at_pasr_dt_t)
 * @return Printf format string (e.g., "%d", "%lu", "%s")
 *
 * @note Returns the appropriate printf format specifier for the given data type.
 *       For example:
 *       - at_pasr_dt_i8 -> "%d"
 *       - at_pasr_dt_u32 -> "%lu"
 *       - at_pasr_dt_string -> "%s"
 *******************************************************************************
 */
char const *at_pasr_dt_printf_fmt(at_pasr_dt_t type);

#ifdef __cplusplus
}
#endif

/// @} ATM_BTFM_ATPASR
