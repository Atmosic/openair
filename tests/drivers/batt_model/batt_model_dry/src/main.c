/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/ztest.h>
#include "batt_model.h"

static void batt_sample_cb(uint16_t lvl, int32_t mvolt)
{
	TC_PRINT("lvl=%u mvolt=%d\n", lvl, mvolt);
}

static dev_state_t batt_state_get(void)
{
	return DEV_INVALID;
}

static void batt_state_set(dev_state_t sts)
{
	zassert_equal(sts, DEV_ACTV, "Unexpected device state=%u", sts);
}

ZTEST(batt_model_dry, test_main)
{
	static batt_cbs const cbs = {
		.state = {
			.get = batt_state_get,
			.set = batt_state_set,
		},
	};
	batt_model()->init(&cbs);

	bool ret = batt_model()->sample(batt_sample_cb);
	zassert_true(ret, "Failed to sample data");

	ret = batt_model()->sample(NULL);
	zassert_true(ret, "Failed to sample data");
}

ZTEST_SUITE(batt_model_dry, NULL, NULL, NULL, NULL, NULL);
