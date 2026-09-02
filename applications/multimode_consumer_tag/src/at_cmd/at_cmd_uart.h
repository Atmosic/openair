/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include "at_cmd_set.h"
#include "at_cmd_tag.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize AT command UART module for multimode consumer tag
 *
 * Registers application-specific tag callbacks and delegates transport
 * initialization to at_cmd_set_uart_ch_init().
 *
 * @return 0 on success, negative error code on failure
 */
int at_cmd_uart_multimode_tag_init(void);

#ifdef __cplusplus
}
#endif
