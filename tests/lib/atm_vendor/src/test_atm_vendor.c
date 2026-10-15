/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <stddef.h>
#include <stdint.h>

#include <zephyr/kernel.h>
#include <zephyr/ztest.h>

#include "atm_vendor.h"
#include "atm_vendor_internal.h"

extern struct vendor_handler const *test_find_handler(uint8_t ocf, uint8_t ogf);
extern struct vendor_handler const *vendor_hdlr;

/**
 * @brief atm_vendor_init() has run in setup and must have registered a
 * vendor handler table with atm_hci_uart.
 */
ZTEST(atm_vendor, test_init_registers_handlers)
{
	zassert_not_null(vendor_hdlr, "vendor_hdlr must be non-NULL after atm_vendor_init()");
}

/**
 * @brief The mandatory EXIT_VENDOR handler is always present regardless of the
 * enabled CFG_VND_* set.
 */
ZTEST(atm_vendor, test_exit_vendor_handler_registered)
{
	struct vendor_handler const *hdlr =
		test_find_handler(EXIT_VENDOR_CMD_OCF, EXIT_VENDOR_CMD_OGF);

	zassert_not_null(hdlr, "EXIT_VENDOR handler must be registered");
	zassert_equal(hdlr->cmd_len, EXIT_VENDOR_CMD_LEN, "EXIT_VENDOR cmd_len mismatch");
}

/**
 * @brief PSM handler is registered when CONFIG_VND_PSM is on.
 */
ZTEST(atm_vendor, test_psm_handler_registered)
{
	struct vendor_handler const *hdlr = test_find_handler(PSM_CMD_OCF, PSM_CMD_OGF);

	zassert_not_null(hdlr, "PSM handler must be registered with CONFIG_VND_PSM=y");
	zassert_true(hdlr->check_cmd_len, "PSM entry must validate cmd_len");
	zassert_equal(hdlr->cmd_len, PSM_CMD_LEN, "PSM cmd_len mismatch");
}

/**
 * @brief atm_vendor_get_hci_vendor_en() returns a bool without side effects.
 *
 * The underlying flag is __UNINIT, so its value is not asserted; the API just
 * has to be callable and consistent across successive reads.
 */
ZTEST(atm_vendor, test_get_hci_vendor_en_stable)
{
	bool a = atm_vendor_get_hci_vendor_en();
	bool b = atm_vendor_get_hci_vendor_en();

	zassert_equal(a, b, "atm_vendor_get_hci_vendor_en() must be idempotent");
}
