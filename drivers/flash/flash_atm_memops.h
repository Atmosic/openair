/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#ifndef FLASH_ATM_INTERNAL_GUARD
#error "flash_atm_memops.h should only be included in flash driver source files"
#endif

/**
 * @brief Copy memory area to a relatively slow destination
 *
 * @param dst  Relatively slow destination memory area
 * @param src  Source memory area
 * @param len  Bytes to copy.  Must not be zero.
 */
void flash_atm_memcpy_slow_dest(void *dst, const void *src, size_t len)
	__attribute_nonnull(1, 2);

/**
 * @brief Fill relatively slow memory with a constant byte
 *
 * @param dst  Relatively slow destination memory area
 * @param c    Byte constant used to fill
 * @param len  Bytes to fill.  Must not be zero.
 */
void flash_atm_memset_slow_dest(void *dst, int c, size_t len)
	__attribute_nonnull(1);
