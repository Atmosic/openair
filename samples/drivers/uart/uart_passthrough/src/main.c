/*
 * Copyright (c) 2024 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>

static const struct device *const uart1_dev = DEVICE_DT_GET(DT_NODELABEL(uart1));
static const struct device *const uart0_dev = DEVICE_DT_GET(DT_NODELABEL(uart0));

void uart_cb(const struct device *dev, void *user_data)
{
    if (!uart_irq_update(dev) || !uart_irq_rx_ready(dev)) {
	return;
    }

    const struct device *dest_dev = (const struct device *)user_data;

    /* read until FIFO empty */
    uint8_t buf[16];
    // `len` is first evaluated and then `len > 0` is used for conditional
    for (int len; len = uart_fifo_read(dev, buf, sizeof(buf)), len > 0;) {
	// UART1 TX
	for (int i = 0; i < len; i++) {
	    uart_poll_out(dest_dev, buf[i]);
	}
    }
}

int main(void)
{
    if (!device_is_ready(uart1_dev) || !device_is_ready(uart0_dev)) {
	printk("UART device not ready\n");
	return 0;
    }

    /* configure interrupt and callback to receive data */
    int ret = uart_irq_callback_user_data_set(uart1_dev, uart_cb, (void *)uart0_dev);

    if (ret < 0) {
	printk("Error setting UART1 callback: %d\n", ret);
	return 0;
    }

    ret = uart_irq_callback_user_data_set(uart0_dev, uart_cb, (void *)uart1_dev);

    if (ret < 0) {
	printk("Error setting UART0 callback: %d\n", ret);
	return 0;
    }

    uart_irq_rx_enable(uart1_dev);
    uart_irq_rx_enable(uart0_dev);

    return 0;
}
