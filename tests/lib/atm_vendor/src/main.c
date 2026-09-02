/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <stddef.h>

#include <zephyr/kernel.h>
#include <zephyr/ztest.h>

#include "atm_vendor.h"
#include "atm_vendor_internal.h"

/* atm_hci_uart.c publishes the registered vendor handler table pointer.
 * The paired size is intentionally file-static in atm_hci_uart.c, so the
 * tests locate individual entries with a bounded, self-validating scan.
 */
extern struct vendor_handler const *vendor_hdlr;

/* Upper bound on the number of vendor_handler_tab entries in atm_vendor.c
 * under any supported CONFIG_VND_* combination. Kept generous so future
 * additions do not silently fail lookup, but bounded so a lookup for a
 * missing entry cannot walk off the array indefinitely.
 */
#define TEST_HANDLER_SCAN_MAX 64

static bool init_done;

static void *atm_vendor_test_setup(void)
{
	if (!init_done) {
		/* Registers vendor_handler_tab via atm_vendor_handler_register()
		 * and spawns the HCI TX/RX threads (which call bt_enable_raw()).
		 */
		atm_vendor_init();
		init_done = true;

		/* Give the RX thread time to open the HCI raw driver so
		 * subsequent tests operate against a fully initialized stack.
		 */
		k_msleep(200);
	}

	return NULL;
}

/* Lookup helper shared by all test source files.
 *
 * Scans up to TEST_HANDLER_SCAN_MAX entries. The (ocf, ogf) equality plus
 * non-NULL callback checks make a false-positive match on memory past the
 * table effectively impossible for the specific opcodes the tests query.
 */
struct vendor_handler const *test_find_handler(uint8_t ocf, uint8_t ogf)
{
	if (!vendor_hdlr) {
		return NULL;
	}

	for (size_t i = 0; i < TEST_HANDLER_SCAN_MAX; i++) {
		struct vendor_handler const *h = &vendor_hdlr[i];

		if (h->ocf == ocf && h->ogf == ogf && h->cmd_hdlr != NULL &&
		    h->cmd_cmp_hdlr != NULL) {
			return h;
		}
	}

	return NULL;
}

ZTEST_SUITE(atm_vendor_psm, NULL, atm_vendor_test_setup, NULL, NULL, NULL);
ZTEST_SUITE(atm_vendor, NULL, atm_vendor_test_setup, NULL, NULL, NULL);
ZTEST_SUITE(atm_hci_uart, NULL, atm_vendor_test_setup, NULL, NULL, NULL);
