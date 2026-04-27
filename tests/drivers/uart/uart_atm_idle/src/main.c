/*
 * Copyright (c) 2026, Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/drivers/uart_atm.h>
#include <zephyr/ztest.h>

static const struct device *uart_dev;
static volatile bool callback_invoked;
static struct k_sem callback_sem;

static void test_rx_callback(const struct device *dev)
{
	callback_invoked = true;
	k_sem_give(&callback_sem);
}

ZTEST_SUITE(uart_atm_idle, NULL, NULL, NULL, NULL, NULL);

ZTEST(uart_atm_idle, test_01_device_ready)
{
	uart_dev = DEVICE_DT_GET(DT_NODELABEL(uart0));
	zassert_not_null(uart_dev, "UART device should not be NULL");
	zassert_true(device_is_ready(uart_dev), "UART device should be ready");
}

ZTEST(uart_atm_idle, test_02_set_idle_null_device)
{
	int ret = uart_atm_set_idle(NULL, test_rx_callback);
	zassert_equal(ret, -EINVAL, "Should return -EINVAL for NULL device");
}

ZTEST(uart_atm_idle, test_03_set_idle_null_callback)
{
	uart_dev = DEVICE_DT_GET(DT_NODELABEL(uart0));
	int ret = uart_atm_set_idle(uart_dev, NULL);
	zassert_equal(ret, -EINVAL, "Should return -EINVAL for NULL callback");
}

ZTEST(uart_atm_idle, test_04_set_idle_valid)
{
	uart_dev = DEVICE_DT_GET(DT_NODELABEL(uart0));
	k_sem_init(&callback_sem, 0, 1);
	callback_invoked = false;

	int ret = uart_atm_set_idle(uart_dev, test_rx_callback);
	zassert_equal(ret, 0, "uart_atm_set_idle should succeed with valid params");

	/*
	 * Note: The callback will be invoked when RX line transitions LOW->HIGH.
	 * In a real test environment, this would require external hardware
	 * to toggle the RX line. For now, we just verify the API call succeeds.
	 */
}

ZTEST(uart_atm_idle, test_05_set_idle_no_rx_pin)
{
	/*
	 * This test would require a UART device without rx-pin configured.
	 * Skip if uart1 doesn't exist or has rx-pin.
	 */
	const struct device *uart1_dev = DEVICE_DT_GET_OR_NULL(DT_NODELABEL(uart1));

	if (uart1_dev == NULL || !device_is_ready(uart1_dev)) {
		ztest_test_skip();
		return;
	}

	/* Try to set idle on uart1 - may fail if no rx-pin configured */
	int ret = uart_atm_set_idle(uart1_dev, test_rx_callback);

	/*
	 * If uart1 has rx-pin, it should succeed (ret == 0)
	 * If uart1 has no rx-pin, it should fail (ret == -ENOTSUP)
	 */
	zassert_true(ret == 0 || ret == -ENOTSUP, "Should return 0 or -ENOTSUP, got %d", ret);
}
