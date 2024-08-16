/*
 * Copyright (c) 2024 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include "string.h"
#include "atm_utils_c.h"
#include "cust_sec_func.h"
#include "sec_service.h"

__attribute__((cmse_nonsecure_entry)) __attribute__((used)) bool
nsc_hello_world(uint8_t *buffer, uint32_t *buf_len)
{
    // before checking if we have access to the buffer, need to check access
    // to buf_len
    if (!mem_check_has_access(buf_len, sizeof(uint32_t), true, true)) {
	return false;
    }
    uint32_t length = *buf_len;
    // Verify access to the whole range of the buffer itself
    if (!mem_check_has_access(buffer, length, true, true)) {
	return false;
    }

#define OUTPUT_STR "Hello from Secure World"
    uint32_t total_len = strlen(OUTPUT_STR);
    if (length < total_len) {
	return false;
    }

    memcpy(buffer, OUTPUT_STR, total_len);
    *buf_len = total_len;
    return true;
}
