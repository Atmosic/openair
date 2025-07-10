/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "test_gpio_api.h"

ZTEST(gpio_api_1pin_conf, test_gpio_get_config)
{
	struct device const *port = DEVICE_DT_GET(TEST_NODE);

	int ret;
	gpio_flags_t flags;

	ret = gpio_pin_configure(port, TEST_PIN, GPIO_OUTPUT);
	zassert_equal(ret, 0, "Failed to configure the pin as an output");
	ret = gpio_pin_get_config(port, TEST_PIN, &flags);
	zassert_ok(ret, "get config failed");
	zassert_true(flags & GPIO_OUTPUT, "test GPIO_OUTPUT fail");

	ret = gpio_pin_configure(port, TEST_PIN, GPIO_INPUT);
	zassert_equal(ret, 0, "Failed to configure the pin as an input");
	ret = gpio_pin_get_config(port, TEST_PIN, &flags);
	zassert_ok(ret, "get config failed");
	zassert_true(flags & GPIO_INPUT, "test GPIO_INPUT fail");

	ret = gpio_pin_configure(port, TEST_PIN, GPIO_OUTPUT | GPIO_INPUT);
	if (ret == -ENOTSUP) {
		TC_PRINT("Simultaneous pin in/out mode is not supported.\n");
		ztest_test_skip();
		return;
	}
	zassert_equal(ret, 0, "Failed to configure the pin in in/out mode");
	ret = gpio_pin_get_config(port, TEST_PIN, &flags);
	zassert_ok(ret, "get config failed");
	zassert_true(flags & (GPIO_INPUT | GPIO_OUTPUT), "test GPIO_INPUT | GPIO_OUTPUT fail");

	ret = gpio_pin_configure(port, TEST_PIN, GPIO_OUTPUT_HIGH | GPIO_INPUT);
	zassert_equal(ret, 0,
		      "Failed to configure the pin in in/out mode and "
		      "initialize it to high");
	ret = gpio_pin_get_config(port, TEST_PIN, &flags);
	zassert_ok(ret, "get config failed");
	zassert_true(flags & (GPIO_OUTPUT_HIGH | GPIO_INPUT),
		     "test GPIO_OUTPUT_HIGH | GPIO_INPUT fail");

	ret = gpio_pin_configure(port, TEST_PIN, GPIO_OUTPUT_LOW | GPIO_INPUT);
	zassert_equal(ret, 0,
		      "Failed to configure the pin in in/out mode and "
		      "initialize it to low");
	ret = gpio_pin_get_config(port, TEST_PIN, &flags);
	zassert_ok(ret, "get config failed");
	zassert_true(flags & (GPIO_OUTPUT_LOW | GPIO_INPUT),
		     "test GPIO_OUTPUT_LOW | GPIO_INPUT fail");
}
