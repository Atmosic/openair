/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/ztest.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>

#include "dtm_mgr.h"
#include "dtm_hci_bridge.h"
#include "ble_dtm.h"

#define TIMEOUT 2000

/* Device references */
#if DT_NODE_EXISTS(DT_CHOSEN(zephyr_dtm_2wire_uart))
static const struct device *uart_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_dtm_2wire_uart));
#else
static const struct device *uart_dev = NULL;
#endif

/* Test fixture setup and teardown */
static void *dtm_2wire_setup(void)
{
	/* Initialize Bluetooth stack for HCI operations */
	int err = bt_enable(NULL);
	if (err) {
		TC_PRINT("Bluetooth init failed (err %d)\n", err);
	}

	return NULL;
}

static void dtm_2wire_before(void *fixture)
{
	ARG_UNUSED(fixture);
	/* Clean state before each test */
}

static void dtm_2wire_after(void *fixture)
{
	ARG_UNUSED(fixture);
	/* Clean up after each test */
}

static void dtm_2wire_teardown(void *fixture)
{
	ARG_UNUSED(fixture);
	/* Final cleanup */
}

/* Helper functions for tests */
const struct device *test_get_uart_device(void)
{
	return uart_dev;
}

bool test_uart_available(void)
{
	return uart_dev && device_is_ready(uart_dev);
}

ZTEST_SUITE(dtm_hci_bridge, NULL, dtm_2wire_setup, dtm_2wire_before, dtm_2wire_after,
	    dtm_2wire_teardown);

ZTEST_SUITE(dtm_message_processing, NULL, dtm_2wire_setup, dtm_2wire_before, dtm_2wire_after,
	    dtm_2wire_teardown);

ZTEST_SUITE(dtm_state_machine, NULL, dtm_2wire_setup, dtm_2wire_before, dtm_2wire_after,
	    dtm_2wire_teardown);
