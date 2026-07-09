/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include "platform_common.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_TAG_BUTTON

/**
 * @brief Platform control button init
 *
 * Initialize button GPIO and interrupt handling. When CONFIG_TAG_BUTTON=y,
 * this function sets up the button hardware for tag control.
 *
 * @return true if success, false if initialization failed
 */
bool platform_ctrl_button_init(void);

#endif /* CONFIG_TAG_BUTTON */

#ifdef __cplusplus
}
#endif
