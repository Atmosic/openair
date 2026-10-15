/**
 ******************************************************************************
 *
 * @file nv_mem_prot_internal.h
 *
 * @brief memory protection driver internal definitions
 *
 * Copyright (C) Atmosic 2025
 *
 ******************************************************************************
 */

#pragma once

#ifndef NV_MEM_PROT_INTERNAL_GUARD
#error "NV MEM protection driver internal header file only!"
#endif

#ifdef __cplusplus
extern "C" {
#endif

// define to debug
#undef NVM_MEM_PROT_DEBUG

bool nv_mem_prot_range_check(uint32_t offset, uint32_t length, uint32_t max_size, bool force_align,
			     uint32_t block_size);

void nv_mem_prot_set_clr_bits(uint32_t volatile *rreg, uint32_t offset, uint32_t length, bool set,
			      bool sticky, uint32_t block_size);

void nv_mem_prot_sticky_clock_control(uint32_t enable);

#define NUM_MEM_PROT_REG_ROUND_UP(num) (((num) + 31) / 32)

#ifdef __cplusplus
}
#endif

/// @}
