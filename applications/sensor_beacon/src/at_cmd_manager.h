/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <zephyr/kernel.h>
#include <stdint.h>
#include "at_cmd.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize AT command manager
 *
 * @return 0 on success, negative error code on failure
 */
int at_cmd_manager_init(void);

#ifdef CONFIG_AT_CMD_LOCK_SET
/**
 * @brief Handle connection events for lock state management
 *
 * @param connected true if connected, false if disconnected
 */
void at_cmd_connection_event(bool connected);
#endif

#ifdef __cplusplus
}
#endif
