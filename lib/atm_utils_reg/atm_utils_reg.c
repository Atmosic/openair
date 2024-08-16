/**
 *******************************************************************************
 *
 * @file atm_utils_reg.c
 *
 * @brief ATM utility functions for register access
 *
 * Copyright (C) Atmosic 2022-2023
 *
 *******************************************************************************
 */

#include <stdint.h>
#include "atm_utils_reg.h"

#ifdef __ARM_FEATURE_UNALIGNED
#define UNALIGNED_OK 1
#else
#define UNALIGNED_OK 0
#endif

void atm_reg_write_multiple(uint32_t volatile *reg, uint8_t const *data,
    size_t const num_bytes)
{
    size_t i = 0;
    size_t num_words = num_bytes / sizeof(uint32_t);
    if (UNALIGNED_OK || (uintptr_t)data % sizeof(uint32_t) == 0) {
	// we can transfer (at least in part) with word writes
	for (; i < num_words; i++) {
	    reg[i] = ((uint32_t __UNALIGNED const *)data)[i];
	}
    } else {
	// transfer full misaligned words
	for (; i < num_words; i++) {
	    reg[i] = ((misaligned_uint32_t const *)data)[i].d;
	}
    }

    size_t trailing_bytes = i * sizeof(uint32_t);
    union {
	uint32_t u32;
	uint8_t u8[sizeof(uint32_t)];
    } aligned_int = {.u32 = 0};
    switch (num_bytes - trailing_bytes) {
	// transfer trailing bytes
	case 3:
	    aligned_int.u8[2] = data[trailing_bytes + 2];
	    /* FALLTHRU */
	case 2:
	    aligned_int.u8[1] = data[trailing_bytes + 1];
	    /* FALLTHRU */
	case 1:
	    aligned_int.u8[0] = data[trailing_bytes];
	    reg[i] = aligned_int.u32;
	    /* FALLTHRU */
	default:
	    break;
    }
}

void atm_reg_read_multiple(uint32_t volatile const *reg, uint8_t *data,
    size_t const num_bytes)
{
    size_t i = 0;
    size_t num_words = num_bytes / sizeof(uint32_t);
    if (UNALIGNED_OK || (uintptr_t)data % sizeof(uint32_t) == 0) {
	// we can transfer (at least in part) with word writes
	for (; i < num_words; i++) {
	    ((uint32_t __UNALIGNED *)data)[i] = reg[i];
	}
    } else {
	// transfer full misaligned words
	for (; i < num_words; i++) {
	    ((misaligned_uint32_t *)data)[i].d = reg[i];
	}
    }

    size_t trailing_bytes = i * sizeof(uint32_t);
    union {
	uint32_t u32;
	uint8_t u8[sizeof(uint32_t)];
    } aligned_int = {.u32 = reg[i]};
    switch (num_bytes - trailing_bytes) {
	// transfer trailing bytes
	case 3:
	    data[trailing_bytes + 2] = aligned_int.u8[2];
	    /* FALLTHRU */
	case 2:
	    data[trailing_bytes + 1] = aligned_int.u8[1];
	    /* FALLTHRU */
	case 1:
	    data[trailing_bytes] = aligned_int.u8[0];
	    /* FALLTHRU */
	default:
	    break;
    }
}

void atm_reg_write_multiple_r(uint32_t volatile *reg, size_t const num_regs,
    uint8_t const *data, size_t const num_bytes)
{
    uint8_t const *data_full_word = data + num_bytes % sizeof(uint32_t);
    size_t i = num_regs - (num_bytes / sizeof(uint32_t));
    size_t partial_word = i - 1;
    size_t j = 0;
    if (UNALIGNED_OK || (uintptr_t)data_full_word % sizeof(uint32_t) == 0) {
	// we can transfer (at least in part) with word writes
	for (; i < num_regs; i++) {
	    reg[i] = ((uint32_t __UNALIGNED const *)data_full_word)[j++];
	}
    } else {
	// transfer full misaligned words
	for (; i < num_regs; i++) {
	    reg[i] = ((misaligned_uint32_t const *)data_full_word)[j++].d;
	}
    }

    union {
	uint32_t u32;
	uint8_t u8[sizeof(uint32_t)];
    } aligned_int = {.u32 = 0};
    j = 0;
    switch (num_bytes % sizeof(uint32_t)) {
	// transfer remaining bytes
	case 3:
	    aligned_int.u8[1] = data[j++];
	    /* FALLTHRU */
	case 2:
	    aligned_int.u8[2] = data[j++];
	    /* FALLTHRU */
	case 1:
	    aligned_int.u8[3] = data[j];
	    reg[partial_word] = aligned_int.u32;
	    /* FALLTHRU */
	default:
	    break;
    }
}

void atm_reg_read_multiple_r(uint32_t volatile const *reg,
    size_t const num_regs, uint8_t *data, size_t const num_bytes)
{
    uint8_t *data_full_word = data + num_bytes % sizeof(uint32_t);
    size_t i = num_regs - (num_bytes / sizeof(uint32_t));
    size_t partial_word = i - 1;
    size_t j = 0;
    if (UNALIGNED_OK || (uintptr_t)data_full_word % sizeof(uint32_t) == 0) {
	// we can transfer (at least in part) with word writes
	for (; i < num_regs; i++) {
	    ((uint32_t __UNALIGNED *)data_full_word)[j++] = reg[i];
	}
    } else {
	// transfer full misaligned words
	for (; i < num_regs; i++) {
	    ((misaligned_uint32_t *)data_full_word)[j++].d = reg[i];
	}
    }

    union {
	uint32_t u32;
	uint8_t u8[sizeof(uint32_t)];
    } aligned_int = {.u32 = reg[partial_word]};
    j = 0;
    switch (num_bytes % sizeof(uint32_t)) {
	// transfer remaining bytes
	case 3:
	    data[j++] = aligned_int.u8[1];
	    /* FALLTHRU */
	case 2:
	    data[j++] = aligned_int.u8[2];
	    /* FALLTHRU */
	case 1:
	    data[j] = aligned_int.u8[3];
	    /* FALLTHRU */
	default:
	    break;
    }
}
