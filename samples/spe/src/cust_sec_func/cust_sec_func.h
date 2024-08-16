/*
 * Copyright (c) 2024 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include "stdbool.h"

/**
 * @brief Populates a nonsecure buffer with a string
 *
 * @note Does *not* append a null terminator ('\0'). Caller can check buf_len
 *       to check how many characters were populated.
 *
 * @param[out] buffer buffer to fill
 * @param[in,out] buf_len length of buffer, length of populate characters
 * @return true if buffer filled successfully, false otherwise
 */
bool nsc_hello_world(uint8_t *buffer, uint32_t *buf_len);