/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/ztest.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include "atm_spe_sec_fault_ns.h"
#include <inttypes.h>

#ifdef CONFIG_TEST_LOG_PANIC
#include <zephyr/logging/log_ctrl.h>
#endif

static void nsc_process_debug_data(const atm_spe_secure_fault_data_t *data)
{
	printk("***** SPE SECURE FAULT *****\n");
	printk("  xpsr: 0x%" PRIx32 "\n", data->basic_sf.xpsr);
	printk("  lr  : 0x%" PRIx32 "\n", data->basic_sf.lr);
	printk("  pc  : 0x%" PRIx32 "\n", data->basic_sf.pc);
	printk("Fault Reason: %d\n", data->fault_reason);
}

void atm_ns_spe_fault_handler(atm_spe_secure_fault_data_t const *fault_data)
{
	printk("=== SPE SECURE FAULT DETECTED ===\n");
	nsc_process_debug_data(fault_data);
#ifdef CONFIG_TEST_LOG_PANIC
	LOG_PANIC();
#endif
	k_fatal_halt(K_ERR_CPU_EXCEPTION);
}

/**
 * @brief Test actual null pointer access (will cause system reset)
 */
ZTEST(atm_spe_sec_fault_storage, test_actual_null_access)
{
	printk("TESTING NULL POINTER ACCESS\n");

	// check if there is any secure fault data stored
	atm_spe_secure_fault_data_t fault_data;
	if (atm_nsc_spe_get_secure_fault_data(&fault_data, true)) {
		atm_ns_spe_fault_handler(&fault_data);
	}

	/* This will cause a memory fault and trigger the SPE fault handler */
	volatile uint32_t *null_ptr = NULL;
	*null_ptr = 0xDEADBEEF;

	/* We should never reach this point */
	printk("ERROR: Should not reach this point after null access!\n");
	zassert_true(false, "System should have reset after null pointer access");
}

/**
 * @brief Test NSC API with invalid parameters
 */
ZTEST(atm_spe_sec_fault_storage, test_nsc_invalid_params)
{
	bool result;

	/* Test with NULL pointer */
	result = atm_nsc_spe_get_secure_fault_data(NULL, false);
	zassert_false(result, "Should fail with NULL pointer");

	result = atm_nsc_spe_get_secure_fault_data(NULL, true);
	zassert_false(result, "Should fail with NULL pointer when clearing");
}

/* Test suite definition */
ZTEST_SUITE(atm_spe_sec_fault_storage, NULL, NULL, NULL, NULL, NULL);
