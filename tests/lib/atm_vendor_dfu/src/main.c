/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/kernel.h>

#ifdef CONFIG_ZTEST
#include <zephyr/ztest.h>

#include "atm_vendor_dfu.h"

static void *atm_vendor_dfu_setup(void)
{
	int ret = atm_vendor_dfu_init();

	zassert_ok(ret, "atm_vendor_dfu_init failed: %d", ret);
	return NULL;
}

static void atm_vendor_dfu_before(void *fixture)
{
	ARG_UNUSED(fixture);
	atm_vendor_dfu_reset();
}

ZTEST_SUITE(atm_vendor_dfu, NULL, atm_vendor_dfu_setup, atm_vendor_dfu_before, NULL, NULL);
#else  /* !CONFIG_ZTEST */

void dfu_test_app_run(void);

int main(void)
{
	dfu_test_app_run();
	return 0;
}
#endif /* CONFIG_ZTEST */
