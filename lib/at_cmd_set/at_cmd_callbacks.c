/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025-2026 Atmosic
 */

#include "at_cmd_callbacks.h"
#include "at_cmd_internal.h"
#include <zephyr/logging/log.h>
#include <string.h>

LOG_MODULE_REGISTER(at_cmd_callbacks, CONFIG_ATM_AT_CMD_SET_LOG_LEVEL);

/**
 * @brief Global callback structure to store registered callbacks
 * This is accessible to AT command implementations for direct callback access.
 */
at_cmd_extension_callbacks_t g_at_callbacks;
bool g_callbacks_initialized = false;

int at_cmd_extension_init(const at_cmd_extension_callbacks_t *callbacks)
{
	if (callbacks == NULL) {
		LOG_ERR("Callbacks structure is NULL");
		return -EINVAL;
	}

	LOG_INF("Initializing AT command extension callbacks");

	/* Copy callbacks directly - NULL pointers are allowed */
	g_at_callbacks.set_device_name = callbacks->set_device_name;
	g_at_callbacks.set_adv_interval = callbacks->set_adv_interval;
	g_at_callbacks.set_adv_data = callbacks->set_adv_data;
	g_at_callbacks.reset_device = callbacks->reset_device;
	g_at_callbacks.unlock_update_proc = callbacks->unlock_update_proc;
	g_at_callbacks.check_unlock_state = callbacks->check_unlock_state;

	g_callbacks_initialized = true;

	LOG_INF("AT command extension callbacks initialized successfully");
	return 0;
}
