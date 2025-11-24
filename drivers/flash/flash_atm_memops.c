/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#define FLASH_ATM_INTERNAL_GUARD
#include "flash_atm_memops.h"

typedef struct {
	uint16_t d;
} __packed misaligned_uint16_t;

typedef struct {
	uint32_t d;
} __packed misaligned_uint32_t;

void flash_atm_memcpy_slow_dest(void *dst, const void *src, size_t len)
{
	// Flash writes are WAY more expensive than misaligned RAM reads,
	// so optimize the write transactions more than memcpy() would
	uintptr_t addr = (uintptr_t)dst;
	uintptr_t end = addr + len;
	uint8_t const *buffer = src;

	if (addr & 0x1) {
		*(volatile uint8_t *)addr++ = *buffer++;
	}

	uintptr_t final_16 = end - sizeof(uint16_t);
	if (addr <= final_16) {
		if (addr & 0x2) {
			*(volatile uint16_t *)addr = ((misaligned_uint16_t const *)buffer)->d;
			addr += sizeof(uint16_t);
			buffer += sizeof(uint16_t);
		}

		uintptr_t final_32 = end - sizeof(uint32_t);
		while (addr <= final_32) {
			*(volatile uint32_t *)addr = ((misaligned_uint32_t const *)buffer)->d;
			addr += sizeof(uint32_t);
			buffer += sizeof(uint32_t);
		}

		if (addr <= final_16) {
			*(volatile uint16_t *)addr = ((misaligned_uint16_t const *)buffer)->d;
			addr += sizeof(uint16_t);
			buffer += sizeof(uint16_t);
		}
	}

	while (addr < end) {
		*(volatile uint8_t *)addr++ = *buffer++;
	}
}

void flash_atm_memset_slow_dest(void *dst, int c, size_t len)
{
	uintptr_t addr = (uintptr_t)dst;
	uintptr_t end = addr + len;
	union {
		uint32_t u32;
		uint16_t u16[2];
		uint8_t u8[4];
	} buf = {.u8 = {c, c, c, c}};

	if (addr & 0x1) {
		*(volatile uint8_t *)addr++ = buf.u8[0];
	}

	uintptr_t final_16 = end - sizeof(uint16_t);
	if (addr <= final_16) {
		if (addr & 0x2) {
			*(volatile uint16_t *)addr = buf.u16[0];
			addr += sizeof(uint16_t);
		}

		uintptr_t final_32 = end - sizeof(uint32_t);
		while (addr <= final_32) {
			*(volatile uint32_t *)addr = buf.u32;
			addr += sizeof(uint32_t);
		}

		if (addr <= final_16) {
			*(volatile uint16_t *)addr = buf.u16[0];
			addr += sizeof(uint16_t);
		}
	}

	while (addr < end) {
		*(volatile uint8_t *)addr++ = buf.u8[0];
	}
}
