/**
 ******************************************************************************
 *
 * @file key_sideload.c
 *
 * @brief Sideload driver
 *
 * Copyright (C) Atmosic 2022-2024
 *
 ******************************************************************************
 */

#include <stdbool.h>
#include <stdint.h>
#include "arch.h"
#include "at_apb_aes_regs_core_macro.h"
#include "key_sideload.h"
#include "sec_cache.h"

#ifndef SECURE_MODE
#error "sideload is a secure-only driver."
#endif

void key_sideload_slot_load(uint8_t const *const slot)
{
    if (key_sideload_address_valid(slot)) {
	uint32_t volatile const *const key = (uint32_t volatile const *)slot;
	// disable icache for the key load reads
	ICACHE_DISABLE();
	for (size_t i = 0; i < KEY_SIDELOAD_SLOT_SIZE / sizeof(uint32_t); i++) {
	    key[i];
	}
	ICACHE_ENABLE();
    }
}
