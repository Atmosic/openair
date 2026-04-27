/*
 * Copyright (c) 2024-2026 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/ztest.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>

static const struct device *const uart1_dev = DEVICE_DT_GET(DT_NODELABEL(uart1));
static const struct device *const uart0_dev = DEVICE_DT_GET(DT_NODELABEL(uart0));

static void uart_cb(const struct device *dev, void *user_data)
{
	if (!uart_irq_update(dev) || !uart_irq_rx_ready(dev)) {
		return;
	}

	const struct device *dest_dev = (const struct device *)user_data;

	/* read until FIFO empty and forward to destination UART */
	uint8_t buf[16];
	for (int len; len = uart_fifo_read(dev, buf, sizeof(buf)), len > 0;) {
		for (int i = 0; i < len; i++) {
			uart_poll_out(dest_dev, buf[i]);
		}
	}
}

/**
 * @brief Suite setup - initialize UART devices and callbacks
 */
static void *uart_passthrough_setup(void)
{
	printk("UART Passthrough Test Setup\n");

	zassert_true(device_is_ready(uart0_dev), "UART0 device not ready");
	zassert_true(device_is_ready(uart1_dev), "UART1 device not ready");

	/* configure interrupt and callback to receive data */
	int ret = uart_irq_callback_user_data_set(uart1_dev, uart_cb, (void *)uart0_dev);
	zassert_equal(ret, 0, "Error setting UART1 callback: %d", ret);

	ret = uart_irq_callback_user_data_set(uart0_dev, uart_cb, (void *)uart1_dev);
	zassert_equal(ret, 0, "Error setting UART0 callback: %d", ret);

	uart_irq_rx_enable(uart1_dev);
	uart_irq_rx_enable(uart0_dev);

	printk("UART passthrough initialized - UART0 <-> UART1\n");
	return NULL;
}

/**
 * @brief Test UART IRQ RX enable/disable API
 *
 * This test runs first to verify the uart_irq_rx_enable/disable API
 * is functional before the passthrough test.
 */
ZTEST(uart_passthrough, test_a_uart_irq_rx_api)
{
	printk("Testing UART IRQ RX enable/disable API\n");

	/* Test enable/disable multiple times for both UARTs */
	for (int i = 0; i < 100; i++) {
		printk("IRQ RX disable/enable cycle %d\n", i + 1);
		uart_irq_rx_disable(uart0_dev);
		uart_irq_rx_disable(uart1_dev);
		k_sleep(K_MSEC(10));
		uart_irq_rx_enable(uart0_dev);
		uart_irq_rx_enable(uart1_dev);
		k_sleep(K_MSEC(10));
	}
	/* Leave IRQ RX enabled for the passthrough test */
	printk("UART IRQ RX API test passed\n");
}

/**
 * @brief Main UART passthrough test
 *
 * Python script sends data to UART0, firmware forwards it to UART1.
 * Firmware logs the data for pytest to verify.
 */
ZTEST(uart_passthrough, test_b_uart_passthrough)
{
	printk("UART passthrough test running\n");
	printk("Send data to UART0 -> firmware forwards to UART1\n");
	printk("Waiting for external test data...\n");

	/* Wait for pytest to send and verify data */
	k_sleep(K_FOREVER);
}

ZTEST_SUITE(uart_passthrough, NULL, uart_passthrough_setup, NULL, NULL, NULL);
