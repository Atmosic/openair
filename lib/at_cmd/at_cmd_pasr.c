/**
 *******************************************************************************
 *
 * @file at_cmd_pasr.c
 *
 * @brief Atmosic AT Command Parser
 *
 * Copyright (C) Atmosic 2021-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */
#define _GNU_SOURCE
#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(at_pasr, LOG_LEVEL_INF);
#undef ATM_LOG
#define ATM_LOG(MSK, fmt, ...) LOG_INF(fmt, ##__VA_ARGS__)
#endif

#include "arch.h"
#include <inttypes.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include "at_cmd_pasr.h"
#ifndef CONFIG_SOC_FAMILY_ATM
#include "atm_log.h"
ATM_LOG_LOCAL_SETTING("at_pasr", N);
#endif

// the max parameters of AT command
#ifndef AT_PASR_PARAM_MAX_CNT
#define AT_PASR_PARAM_MAX_CNT 10
#endif // AT_PASR_PARAM_MAX_CNT

typedef struct at_pasr_dt_ctx_s {
    char kword[at_pasr_dt_num];
    int32_t min[at_pasr_dt_num];
    uint32_t max[at_pasr_dt_num];
} at_pasr_dt_ctx_t;

static at_pasr_dt_ctx_t const dt_ctx = {
    .kword = {
	'b', // int8_t
	'B', // uint8_t
	'w', // int16_t
	'W', // uint16_t
	'd', // int32_t
	'D', // uint32_t
	'A', // array
	'S', // string
    },
    .min = {
	SCHAR_MIN,
	0x0,
	SHRT_MIN,
	0x0,
	INT_MIN,
	0x0,
	0x0,
	0x0,
    },
    .max = {
	SCHAR_MAX,
	UCHAR_MAX,
	SHRT_MAX,
	USHRT_MAX,
	INT_MAX,
	UINT_MAX,
	0xFF,
	0xFFF,
    },
};

static at_pasr_tlv_t *at_cmd_param[AT_PASR_PARAM_MAX_CNT];
static int at_cmd_param_cnt;

static char *at_pasr_input_num(char *str, char delimiter, uint32_t *val)
{
    char *ptr = str;
    while (*ptr) {
	if (*ptr == delimiter) {
	    break;
	}
	ptr++;
    }

    if (*ptr) {
	*ptr = 0;
	*val = atoi(str);
	return ptr + 1;
    }

    return ptr;
}

static void at_pasr_input_u8(char const *input, at_pasr_tlv_t **tlv)
{
    at_pasr_tlv_t *ptlv = *tlv;
    char *end;
    ptlv->u8 = strtoul(input, &end, 10);
    if (!(*end) || (*end == ',')) {
	ptlv->length = sizeof(uint8_t);
	if ((ptlv->u8 >= ptlv->u8min) && (ptlv->u8 <= ptlv->u8max)) {
	    ptlv->status = AT_PASR_OK;
	} else {
	    ptlv->status = AT_PASR_RANGE_EXCEED;
	}
    } else {
	ptlv->u8 = 0;
	ptlv->status = AT_PASR_WRONG_TYPE;
    }
}

static void at_pasr_input_i8(char const *input, at_pasr_tlv_t **tlv)
{
    at_pasr_tlv_t *ptlv = *tlv;
    char *end;
    ptlv->i8 = strtol(input, &end, 10);
    if (!(*end) || (*end == ',')) {
	ptlv->length = sizeof(int8_t);
	if ((ptlv->i8 >= ptlv->i8min) && (ptlv->i8 <= ptlv->i8max)) {
	    ptlv->status = AT_PASR_OK;
	} else {
	    ptlv->status = AT_PASR_RANGE_EXCEED;
	}
    } else {
	ptlv->i8 = 0;
	ptlv->status = AT_PASR_WRONG_TYPE;
    }
}

static void at_pasr_input_i16(char const *input, at_pasr_tlv_t **tlv)
{
    at_pasr_tlv_t *ptlv = *tlv;
    char *end;
    ptlv->i16 = strtol(input, &end, 10);
    if (!(*end) || (*end == ',')) {
	ptlv->length = sizeof(int16_t);
	if ((ptlv->i16 >= ptlv->i16min) && (ptlv->i16 <= ptlv->i16max)) {
	    ptlv->status = AT_PASR_OK;
	} else {
	    ptlv->status = AT_PASR_RANGE_EXCEED;
	}
    } else {
	ptlv->i16 = 0;
	ptlv->status = AT_PASR_WRONG_TYPE;
    }
}

static void at_pasr_input_u16(char const *input, at_pasr_tlv_t **tlv)
{
    at_pasr_tlv_t *ptlv = *tlv;
    char *end;
    ptlv->u16 = strtoul(input, &end, 10);
    if (!(*end) || (*end == ',')) {
	ptlv->length = sizeof(uint16_t);
	if ((ptlv->u16 >= ptlv->u16min) && (ptlv->u16 <= ptlv->u16max)) {
	    ptlv->status = AT_PASR_OK;
	} else {
	    ptlv->status = AT_PASR_RANGE_EXCEED;
	}
    } else {
	ptlv->u16 = 0;
	ptlv->status = AT_PASR_WRONG_TYPE;
    }
}

static void at_pasr_input_u32(char const *input, at_pasr_tlv_t **tlv)
{
    at_pasr_tlv_t *ptlv = *tlv;
    char *end;
    ptlv->u32 = strtoul(input, &end, 10);
    if (!(*end) || (*end == ',')) {
	ptlv->length = sizeof(uint32_t);
	if ((ptlv->u32 >= ptlv->u32min) && (ptlv->u32 <= ptlv->u32max)) {
	    ptlv->status = AT_PASR_OK;
	} else {
	    ptlv->status = AT_PASR_RANGE_EXCEED;
	}
    } else {
	ptlv->u32 = 0;
	ptlv->status = AT_PASR_WRONG_TYPE;
    }
}

static void at_pasr_input_i32(char const *input, at_pasr_tlv_t **tlv)
{
    at_pasr_tlv_t *ptlv = *tlv;
    char *end;
    ptlv->i32 = strtol(input, &end, 10);
    if (!(*end) || (*end == ',')) {
	ptlv->length = sizeof(int32_t);
	if ((ptlv->i32 >= ptlv->i32min) && (ptlv->i32 <= ptlv->i32max)) {
	    ptlv->status = AT_PASR_OK;
	} else {
	    ptlv->status = AT_PASR_RANGE_EXCEED;
	}
    } else {
	ptlv->status = AT_PASR_WRONG_TYPE;
    }
}

#define SIZEOF_AT_PASR_TLV_T(__f, len) (offsetof(at_pasr_tlv_t, __f) + (len))

static void at_pasr_input_array(char const *input, at_pasr_tlv_t **tlv)
{
    char *next = strchr(input, ',');
    if (!next) {
	next = strchr(input, 0);
    }

    uint16_t len = (next - input) / 2;
    at_pasr_tlv_t *ptlv = realloc(*tlv, SIZEOF_AT_PASR_TLV_T(array, len));
    if (!ptlv) {
	if (*tlv) {
	    free(*tlv);
	    *tlv = NULL;
	}

	return;
    }
    *tlv = ptlv;

    char tmp[3] = {0, 0, 0};
    for (int i = 0; i < len; i++) {
	memcpy(tmp, (input + i * 2), 2);
	ptlv->array[i] = strtoul(tmp, NULL, 16);
    }

    ptlv->length = len;
    if ((len >= ptlv->arraymin) && (len <= ptlv->arraymax)) {
	ptlv->status = AT_PASR_OK;
    } else {
	ptlv->status = AT_PASR_RANGE_EXCEED;
    }

    if ((next - input) % 2) {
	ptlv->status = AT_PASR_INVALID_DATA;
    }
}

static void at_pasr_input_string(char const *input, at_pasr_tlv_t **tlv)
{
    char *next = strchr(input, ',');
    if (!next) {
	next = strchr(input, 0);
    }

    uint16_t len = next - input;
    at_pasr_tlv_t *ptlv = realloc(*tlv, SIZEOF_AT_PASR_TLV_T(string, len + 1));
    if (!ptlv) {
	if (*tlv) {
	    free(*tlv);
	    *tlv = NULL;
	}

	return;
    }
    *tlv = ptlv;

    memcpy(ptlv->string, input, len);
    ptlv->string[len] = '\0';
    ptlv->length = len;
    if ((len >= ptlv->stringmin) && (len <= ptlv->stringmax)) {
	ptlv->status = AT_PASR_OK;
    } else {
	ptlv->status = AT_PASR_RANGE_EXCEED;
    }
}

static void at_pasr_input_wrong(char const *input, at_pasr_tlv_t **tlv)
{
    at_pasr_input_string(input, tlv);
    (*tlv)->status = AT_PASR_WRONG_TYPE;
}

typedef void (*at_pasr_input_ctx)(char const *input, at_pasr_tlv_t **tlv);

static at_pasr_input_ctx const at_pasr_input_fn[] = {
    at_pasr_input_i8,
    at_pasr_input_u8,
    at_pasr_input_i16,
    at_pasr_input_u16,
    at_pasr_input_i32,
    at_pasr_input_u32,
    at_pasr_input_array,
    at_pasr_input_string,
    at_pasr_input_wrong,
};

static bool at_pasr_input_walk(char const **in, at_pasr_tlv_t **tlv)
{
    char const *input = *in;
    if (!input) {
	return false;
    }

    if (*input == ',' || !(*input)) {
	(*tlv)->status = AT_PASR_EMPTY_DATA;
    } else {
	at_pasr_input_fn[(*tlv)->type](input, tlv);
    }

    char *next = strchr(input, ',');
    *in = next ? (next + 1) : 0;

    return true;
}

at_pasr_tlv_t *at_pasr_dt_identify(char *literal)
{
    uint8_t type = at_pasr_dt_unknow;
    uint32_t max;
    int32_t min;
    for (int dt = at_pasr_dt_i8; dt < at_pasr_dt_num; dt++) {
	if (literal[0] == dt_ctx.kword[dt]) {
	    type = dt;
	    min = dt_ctx.min[dt];
	    max = dt_ctx.max[dt];
	    break;
	}
    }

    switch (literal[1]) {
	case '(': {
	    if (literal[2] == '~') {
		char *str = at_pasr_input_num(literal + 3, ')', &max);
		if (*str) {
		    type = at_pasr_dt_unknow;
		}
	    } else {
		char *str = at_pasr_input_num(literal + 2, '~', (uint32_t *)&min);
		if (!str) {
		    type = at_pasr_dt_unknow;
		} else if (str[0] != ')') {
		    str = at_pasr_input_num(str, ')', &max);
		    if (*str) {
			type = at_pasr_dt_unknow;
		    }
		}
	    }
	} break;

	case 0:
	default:
	    break;
    }

#define AT_PASR_PARAM_INIT(T, LEN) \
    case at_pasr_dt_##T: { \
	ptlv = calloc(1, SIZEOF_AT_PASR_TLV_T(T, LEN)); \
	ptlv->type = at_pasr_dt_##T; \
	ptlv->status = AT_PASR_EMPTY_DATA; \
	ptlv->T##min = min; \
	ptlv->T##max = max; \
    } break;

#if defined(__GNUC__) && (__GNUC__ >= 10)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
#endif
    at_pasr_tlv_t *ptlv = NULL;
    switch (type) {
	AT_PASR_PARAM_INIT(i8, sizeof(int8_t));
	AT_PASR_PARAM_INIT(u8, sizeof(uint8_t));
	AT_PASR_PARAM_INIT(i16, sizeof(int16_t));
	AT_PASR_PARAM_INIT(u16, sizeof(uint16_t));
	AT_PASR_PARAM_INIT(i32, sizeof(int32_t));
	AT_PASR_PARAM_INIT(u32, sizeof(uint32_t));
	AT_PASR_PARAM_INIT(array, 0);
	AT_PASR_PARAM_INIT(string, 0);

	default:
	    ATM_LOG(E, "Unknown AT parser type!");
	    break;
    }
#if defined(__GNUC__) && (__GNUC__ >= 10)
#pragma GCC diagnostic pop
#endif

    if (!ptlv) {
	ATM_LOG(E, "Not enough resource!");
    }

    return ptlv;
}

static at_pasr_tlv_t *at_pasr_fmt_walk(char *format)
{
    static char *save_fmt;
    char *fmt = !at_cmd_param_cnt ? format : NULL;

    char *token = strtok_r(fmt, ",", &save_fmt);

    if (!token) {
	return NULL;
    }

    return at_pasr_dt_identify(token);
}

static void at_pasr_param_store(at_pasr_tlv_t *tlv)
{
    if (at_cmd_param_cnt < AT_PASR_PARAM_MAX_CNT) {
        at_cmd_param[at_cmd_param_cnt++] = tlv;
    } else {
	free(tlv);
	ATM_LOG(E, "Please increase AT_PASR_PARAM_MAX_CNT in compile option to "
	    "apply more parameters in AT command." );
    }
}

static inline bool is_result_clear(void)
{
    return !at_cmd_param_cnt;
}

at_pasr_err_t at_pasr_param_validate(char const *input, char const *format)
{
    if (!is_result_clear()) {
	return AT_PASR_BUSY;
    }

    char fmt[strlen(format) + 1];
    strcpy(fmt, format);
    at_pasr_tlv_t *tlv;
    while ((tlv = at_pasr_fmt_walk(fmt)) != NULL) {
	if (!at_pasr_input_walk(&input, &tlv)) {
	    break;
	}
	at_pasr_param_store(tlv);
    }

    return (input ? AT_PASR_MORE_DATA : AT_PASR_OK);
}

at_pasr_tlv_t *at_pasr_param_get(uint16_t idx)
{
    if (idx >= at_cmd_param_cnt) {
	return NULL;
    }

    return at_cmd_param[idx];
}

uint16_t at_pasr_param_num_get(void)
{
    return at_cmd_param_cnt;
}

at_pasr_tlv_t **at_pasr_param(void)
{
    ATM_LOG(V, "%s: at_cmd_param_cnt (%d)", __func__, at_cmd_param_cnt);
    return at_cmd_param;
}

void at_pasr_clear(void)
{
    for (int i = 0; i < at_cmd_param_cnt; i++) {
	free(at_cmd_param[i]);
    }

    at_cmd_param_cnt = 0;
}

/**
 * @brief Get printf format string for a data type
 */
char const *at_pasr_dt_printf_fmt(at_pasr_dt_t type)
{
	switch (type) {
	case at_pasr_dt_i8:
		return "%" PRId8;

	case at_pasr_dt_u8:
		return "%" PRIu8;

	case at_pasr_dt_i16:
		return "%" PRId16;

	case at_pasr_dt_u16:
		return "%" PRIu16;

	case at_pasr_dt_i32:
		return "%" PRId32;

	case at_pasr_dt_u32:
		return "%" PRIu32;

	case at_pasr_dt_array:
		// Array type is handled specially (hex encoding)
		return NULL;

	case at_pasr_dt_string:
		return "%s";

	default:
		ASSERT_ERR(0);
		return NULL;
	}
}
