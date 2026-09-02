/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <stddef.h>
#include <stdint.h>

#include <zephyr/kernel.h>
#include <zephyr/ztest.h>

#include "atm_vendor_internal.h"

extern struct vendor_handler const *vendor_hdlr;
extern struct vendor_handler const *test_find_handler(uint8_t ocf, uint8_t ogf);

/**
 * @brief After atm_vendor_init() the vendor handler table pointer is set.
 * atm_hci_init() (called from atm_vendor_init) invokes
 * atm_vendor_handler_register() with the atm_vendor.c static table.
 */
ZTEST(atm_hci_uart, test_vendor_handler_pointer_set)
{
	zassert_not_null(vendor_hdlr,
			 "atm_hci_uart's vendor_hdlr must be set after atm_vendor_init()");
}

/**
 * @brief A handler lookup by (ocf, ogf) via the shared test_find_handler
 * helper returns the corresponding entry from the atm_vendor table.
 */
ZTEST(atm_hci_uart, test_find_handler_lookup)
{
	struct vendor_handler const *hdlr = test_find_handler(PSM_CMD_OCF, PSM_CMD_OGF);

	zassert_not_null(hdlr, "PSM handler must be discoverable via test_find_handler");
	zassert_equal(hdlr->ocf, PSM_CMD_OCF, "OCF mismatch");
	zassert_equal(hdlr->ogf, PSM_CMD_OGF, "OGF mismatch");
}
