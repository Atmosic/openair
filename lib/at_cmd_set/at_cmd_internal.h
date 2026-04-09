/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025-2026 Atmosic
 */

#ifndef AT_CMD_INTERNAL_H
#define AT_CMD_INTERNAL_H

/*
 * Internal header for AT command library implementation files only.
 * Applications should NOT include this file.
 *
 * This header provides access to internal globals and implementation
 * details that are needed by AT command handler files but should not
 * be exposed to applications using the library.
 */

#include "at_cmd_callbacks.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Internal globals for AT command implementations
 *
 * These globals are accessible only to AT command implementation files
 * within the library and should not be used by applications.
 *
 * Applications should only use the public API defined in at_cmd_callbacks.h
 */
extern at_cmd_extension_callbacks_t g_at_callbacks;
extern bool g_callbacks_initialized;

#ifdef __cplusplus
}
#endif

#endif /* AT_CMD_INTERNAL_H */
