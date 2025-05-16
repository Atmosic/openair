/**
 ******************************************************************************
 *
 * @file key_sideload.h
 *
 * @brief Key sideloading
 *
 * Copyright (C) Atmosic 2022
 *
 ******************************************************************************
 */

#pragma once

#include <stddef.h>
#include <stdint.h>

/**
 * @defgroup KEY_SIDELOAD Key sideloading
 * @ingroup DRIVERS
 * @brief Key sideloading for HMAC and AES
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#define KEY_SIDELOAD_SLOT_START_ADDRESS 0x1008FF00
#define KEY_SIDELOAD_SLOT_SIZE 0x20
#define KEY_SIDELOAD_SLOT_COUNT 8

#define KEY_SIDELOAD_SLOT_0 ((uint8_t *)KEY_SIDELOAD_SLOT_START_ADDRESS)
#define KEY_SIDELOAD_SLOT_1 \
    ((uint8_t *)KEY_SIDELOAD_SLOT_0 + KEY_SIDELOAD_SLOT_SIZE)
#define KEY_SIDELOAD_SLOT_2 \
    ((uint8_t *)KEY_SIDELOAD_SLOT_1 + KEY_SIDELOAD_SLOT_SIZE)
#define KEY_SIDELOAD_SLOT_3 \
    ((uint8_t *)KEY_SIDELOAD_SLOT_2 + KEY_SIDELOAD_SLOT_SIZE)
#define KEY_SIDELOAD_SLOT_4 \
    ((uint8_t *)KEY_SIDELOAD_SLOT_3 + KEY_SIDELOAD_SLOT_SIZE)
#define KEY_SIDELOAD_SLOT_5 \
    ((uint8_t *)KEY_SIDELOAD_SLOT_4 + KEY_SIDELOAD_SLOT_SIZE)
#define KEY_SIDELOAD_SLOT_6 \
    ((uint8_t *)KEY_SIDELOAD_SLOT_5 + KEY_SIDELOAD_SLOT_SIZE)
#define KEY_SIDELOAD_SLOT_7 \
    ((uint8_t *)KEY_SIDELOAD_SLOT_6 + KEY_SIDELOAD_SLOT_SIZE)

#define KEY_SIDELOAD_SLOT_MIN_256 KEY_SIDELOAD_SLOT_0
#define KEY_SIDELOAD_SLOT_MAX_256 KEY_SIDELOAD_SLOT_3
#define KEY_SIDELOAD_SLOT_MIN_128 KEY_SIDELOAD_SLOT_4
#define KEY_SIDELOAD_SLOT_MAX_128 KEY_SIDELOAD_SLOT_7

/**
 * @brief Verify if the provided address is a valid slot
 *
 * @param address Address of the sideload slot
 * @return True if the address is a valid slot
 */
static inline bool key_sideload_address_valid(uint8_t const *const address)
{
    if ((uintptr_t)address >= KEY_SIDELOAD_SLOT_START_ADDRESS &&
	(uintptr_t)address <=
	    (KEY_SIDELOAD_SLOT_START_ADDRESS +
		KEY_SIDELOAD_SLOT_SIZE * KEY_SIDELOAD_SLOT_COUNT) &&
	!((uintptr_t)address & (KEY_SIDELOAD_SLOT_SIZE - 1))) {
	return true;
    }
    return false;
}

/**
 * @brief Verify if the provided slot and size combination is valid for AES
 *
 * @note HMAC keys are all 256 bit and can be in any slot
 *
 * @param slot Address of the slot to check
 * @param num_bytes Size of the slot in bytes
 *
 * @return True if the combination is valid for AES
 */
static inline bool key_sideload_slot_size_valid_aes(uint8_t const *const slot,
    size_t const num_bytes)
{
    if (key_sideload_address_valid(slot)) {
	if (num_bytes == KEY_SIDELOAD_SLOT_SIZE) {
	    if (slot >= KEY_SIDELOAD_SLOT_MIN_256 &&
		slot <= KEY_SIDELOAD_SLOT_MAX_256) {
		return true;
	    }
	} else if (num_bytes == KEY_SIDELOAD_SLOT_SIZE / 2) {
	    if (slot >= KEY_SIDELOAD_SLOT_MIN_128 &&
		slot <= KEY_SIDELOAD_SLOT_MAX_128) {
		return true;
	    }
	}
    }
    return false;
}

/**
 * @brief load the key from the designated slot
 *
 * @param slot address of the key to load
 */
void key_sideload_slot_load(uint8_t const *const slot);

#ifdef __cplusplus
}
#endif

/// @}
