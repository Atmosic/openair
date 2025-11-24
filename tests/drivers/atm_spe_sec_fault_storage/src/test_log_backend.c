/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log_backend.h>
#include <zephyr/logging/log_ctrl.h>
#include <zephyr/sys/printk.h>
#include <inttypes.h>

/* Backend API implementation - simplified */
static void test_log_process(const struct log_backend *const backend, union log_msg_generic *msg)
{
	/* Simplified - we only care about panic functionality */
	ARG_UNUSED(backend);
	ARG_UNUSED(msg);
}

static void test_log_dropped(const struct log_backend *const backend, uint32_t cnt)
{
	ARG_UNUSED(backend);
	printk("[TEST_LOG_BACKEND] Dropped %" PRIu32 " log messages\n", cnt);
}

void test_log_panic(const struct log_backend *const backend)
{
	ARG_UNUSED(backend);
	printk("*** TEST LOG PANIC SAVE COMPLETE ***\n");
}

static void test_log_init(const struct log_backend *const backend)
{
	ARG_UNUSED(backend);
}

static int test_log_is_ready(const struct log_backend *const backend)
{
	ARG_UNUSED(backend);
	return 0;
}

/* Backend API structure */
static const struct log_backend_api test_log_backend_api = {
	.process = test_log_process,
	.dropped = test_log_dropped,
	.panic = test_log_panic,
	.init = test_log_init,
	.is_ready = test_log_is_ready,
};

/* Define the backend - autostart enabled */
LOG_BACKEND_DEFINE(test_log_backend, test_log_backend_api, true);

/* Force backend activation during initialization */
static int test_log_backend_init(void)
{
	/* Enable the backend with DEBUG level to capture all logs */
	log_backend_enable(&test_log_backend, NULL, LOG_LEVEL_DBG);
	return 0;
}

/* Initialize at POST_KERNEL level to ensure logging is ready */
SYS_INIT(test_log_backend_init, POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
