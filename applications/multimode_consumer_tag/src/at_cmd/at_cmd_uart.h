/**
 *******************************************************************************
 *
 * @file at_cmd_uart.h
 *
 * @brief AT command UART module
 *
 * Copyright (C) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#pragma once

#include "at_cmd.h"
#include "at_cmd_tag.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get AT command UART channel
 *
 * @return AT command channel allocated by at_cmd_alloc()
 */
at_cmd_ch_t at_cmd_uart_ch_get(void);

/**
 * @brief Initialize AT command UART module
 *
 * @return 0 on success, negative error code on failure
 */
int at_cmd_uart_multimode_tag_init(void);

#ifdef __cplusplus
}
#endif
