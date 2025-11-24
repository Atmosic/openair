/*
 * Copyright (c) 2025 Atmosic Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>
#include <zephyr/ztest.h>
#include <zephyr/devicetree.h>
#include <inttypes.h>
#include <string.h>

LOG_MODULE_REGISTER(gpio_interrupt_test, LOG_LEVEL_INF);

/* Use board-specific button definition from device tree */
/* Using button1 (Button2) instead of button0 to avoid external pull-down resistor interference */
#define BUTTON_NODE DT_PATH(buttons, button_1)
#if !DT_NODE_HAS_STATUS(BUTTON_NODE, okay)
#error "Unsupported board: button_1 devicetree node is not defined"
#endif

/* GPIO device and callback data */
static const struct device *gpio_dev;
static struct gpio_callback gpio_cb_data;
static volatile bool interrupt_triggered;
static volatile uint32_t interrupt_count;

/**
 * @brief GPIO interrupt callback function
 *
 * This function is called when a GPIO interrupt occurs.
 * It sets a flag to indicate the interrupt was triggered and immediately
 * disables the interrupt to prevent continuous triggering.
 */
static void gpio_interrupt_callback(const struct device *dev, struct gpio_callback *cb,
				    uint32_t pins)
{
	interrupt_triggered = true;
	interrupt_count++;
	LOG_INF("GPIO interrupt triggered (count: %" PRIu32 ")", interrupt_count);

	/* Immediately disable interrupt to prevent continuous triggering */
	gpio_pin_interrupt_configure(dev, DT_GPIO_PIN(BUTTON_NODE, gpios), GPIO_INT_DISABLE);
}

/**
 * @brief Setup function for GPIO interrupt tests
 *
 * Initializes the GPIO device using the board-specific button definition.
 */
static void *gpio_interrupt_test_setup(void)
{
	/* Get GPIO device from device tree button definition */
	gpio_dev = DEVICE_DT_GET(DT_GPIO_CTLR(BUTTON_NODE, gpios));

	zassert_true(device_is_ready(gpio_dev), "GPIO device is not ready");

	LOG_INF("GPIO interrupt test setup complete - using button1 (GPIO pin %d)",
		DT_GPIO_PIN(BUTTON_NODE, gpios));
	return NULL;
}

/**
 * @brief Before each test function
 *
 * Resets the test state and ensures clean GPIO configuration.
 */
static void gpio_interrupt_test_before(void *fixture)
{
	const gpio_pin_t pin = DT_GPIO_PIN(BUTTON_NODE, gpios);

	/* Reset test state */
	interrupt_triggered = false;
	interrupt_count = 0;

	/* Disable any existing interrupts (ignore errors as pin may not be configured) */
	gpio_pin_interrupt_configure(gpio_dev, pin, GPIO_INT_DISABLE);

	/* Clear callback data structure */
	memset(&gpio_cb_data, 0, sizeof(gpio_cb_data));

	LOG_DBG("Test setup: GPIO pin %d reset, interrupts disabled", pin);
}

/**
 * @brief After each test function
 *
 * Cleans up GPIO configuration and removes callbacks.
 */
static void gpio_interrupt_test_after(void *fixture)
{
	const gpio_pin_t pin = DT_GPIO_PIN(BUTTON_NODE, gpios);

	/* Disable interrupt */
	gpio_pin_interrupt_configure(gpio_dev, pin, GPIO_INT_DISABLE);

	/* Remove callback */
	gpio_remove_callback(gpio_dev, &gpio_cb_data);

	LOG_DBG("Test cleanup complete");
}

/**
 * @brief Test GPIO rising edge interrupt with software-controlled toggling
 *
 * This test validates GPIO rising edge interrupt functionality by:
 * 1. Configuring the GPIO pin as output and setting it low
 * 2. Setting up rising edge interrupt configuration
 * 3. Switching pin to input mode
 * 4. Programmatically driving the pin high to trigger the interrupt
 * 5. Verifying the interrupt was triggered exactly once
 * 6. Ensuring proper cleanup to prevent interrupt loops
 */
ZTEST(gpio_interrupt_basic, test_gpio_rising_edge_interrupt)
{
	int ret;
	const gpio_pin_t pin = DT_GPIO_PIN(BUTTON_NODE, gpios);
	const gpio_flags_t pin_flags = DT_GPIO_FLAGS(BUTTON_NODE, gpios);

	LOG_INF("=== GPIO Rising Edge Interrupt Test ===");
	LOG_INF("Using button1: GPIO port %s, pin %d", gpio_dev->name, pin);

	/* Step 1: Configure GPIO pin as output and set to low state */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_OUTPUT_INACTIVE);
	zassert_ok(ret, "Failed to configure GPIO pin as output");
	LOG_INF("✓ GPIO pin configured as output, set to low state");

	/* Small delay to ensure pin state is stable */
	k_msleep(10);

	/* Step 2: Initialize callback and configure rising edge interrupt */
	gpio_init_callback(&gpio_cb_data, gpio_interrupt_callback, BIT(pin));
	ret = gpio_add_callback(gpio_dev, &gpio_cb_data);
	zassert_ok(ret, "Failed to add GPIO callback");
	LOG_INF("✓ GPIO callback initialized");

	/* Step 3: Switch pin to input mode and configure rising edge interrupt */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_INPUT | pin_flags);
	zassert_ok(ret, "Failed to configure GPIO pin as input");

	ret = gpio_pin_interrupt_configure(gpio_dev, pin, GPIO_INT_EDGE_RISING);
	zassert_ok(ret, "Failed to configure GPIO rising edge interrupt");
	LOG_INF("✓ GPIO rising edge interrupt configured");

	/* Step 4: Programmatically drive pin high to trigger interrupt */
	/* Note: We'll briefly switch back to output to drive the pin high */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_OUTPUT_ACTIVE);
	zassert_ok(ret, "Failed to configure GPIO pin as output active");
	LOG_INF("✓ GPIO pin driven high to trigger rising edge");

	/* Small delay to allow interrupt processing */
	k_msleep(50);

	/* Step 5: Verify interrupt was triggered exactly once */
	zassert_true(interrupt_triggered, "GPIO interrupt was not triggered");
	zassert_equal(interrupt_count, 1, "Expected exactly 1 interrupt, got %" PRIu32,
		      interrupt_count);
	LOG_INF("✅ GPIO rising edge interrupt triggered successfully (count: %" PRIu32 ")",
		interrupt_count);

	/* Step 6: Final cleanup - switch back to input and ensure interrupt is disabled */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_INPUT | pin_flags);
	zassert_ok(ret, "Failed to configure GPIO pin as input for cleanup");

	ret = gpio_pin_interrupt_configure(gpio_dev, pin, GPIO_INT_DISABLE);
	zassert_ok(ret, "Failed to disable GPIO interrupt");

	ret = gpio_remove_callback(gpio_dev, &gpio_cb_data);
	zassert_ok(ret, "Failed to remove GPIO callback");

	LOG_INF("=== GPIO Rising Edge Interrupt Test PASSED ===");
}

/**
 * @brief Test GPIO level high interrupt with software-controlled toggling
 *
 * This test validates GPIO level high interrupt functionality by:
 * 1. Configuring the GPIO pin as output and setting it low
 * 2. Setting up level high interrupt configuration
 * 3. Switching pin to input mode (maintains low state)
 * 4. Programmatically driving the pin high to trigger level interrupt
 * 5. Verifying the interrupt was triggered
 * 6. Immediately driving pin low to stop the level interrupt
 * 7. Ensuring proper cleanup to prevent continuous interrupt loops
 */
ZTEST(gpio_interrupt_basic, test_gpio_level_high_interrupt)
{
	int ret;
	const gpio_pin_t pin = DT_GPIO_PIN(BUTTON_NODE, gpios);
	const gpio_flags_t pin_flags = DT_GPIO_FLAGS(BUTTON_NODE, gpios);

	LOG_INF("=== GPIO Level High Interrupt Test ===");
	LOG_INF("Using button1: GPIO port %s, pin %d", gpio_dev->name, pin);

	/* Step 1: Configure GPIO pin as output and set to low state */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_OUTPUT_INACTIVE);
	zassert_ok(ret, "Failed to configure GPIO pin as output inactive");
	LOG_INF("✓ GPIO pin configured as output, set to low state");

	/* Small delay to ensure pin state is stable */
	k_msleep(10);

	/* Step 2: Initialize callback and configure level high interrupt */
	gpio_init_callback(&gpio_cb_data, gpio_interrupt_callback, BIT(pin));
	ret = gpio_add_callback(gpio_dev, &gpio_cb_data);
	zassert_ok(ret, "Failed to add GPIO callback");
	LOG_INF("✓ GPIO callback initialized");

	/* Step 3: Switch pin to input mode and configure level high interrupt */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_INPUT | pin_flags);
	zassert_ok(ret, "Failed to configure GPIO pin as input");

	ret = gpio_pin_interrupt_configure(gpio_dev, pin, GPIO_INT_LEVEL_HIGH);
	zassert_ok(ret, "Failed to configure GPIO level high interrupt");
	LOG_INF("✓ GPIO level high interrupt configured");

	/* Step 4: Programmatically drive pin high to trigger level interrupt */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_OUTPUT_ACTIVE);
	zassert_ok(ret, "Failed to configure GPIO pin as output active");
	LOG_INF("✓ GPIO pin driven high to trigger level interrupt");

	/* Small delay to allow interrupt processing */
	k_msleep(25);

	/* Step 5: Verify interrupt was triggered */
	zassert_true(interrupt_triggered, "GPIO level high interrupt was not triggered");
	zassert_true(interrupt_count >= 1, "Expected at least 1 interrupt, got %" PRIu32,
		     interrupt_count);
	LOG_INF("✅ GPIO level high interrupt triggered successfully (count: %" PRIu32 ")",
		interrupt_count);

	/* Step 6: Drive pin low to stop level interrupt and cleanup */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_OUTPUT_INACTIVE);
	zassert_ok(ret, "Failed to configure GPIO pin as output inactive");
	LOG_INF("✓ GPIO pin driven low to stop level interrupt");

	/* Small delay to ensure pin state change */
	k_msleep(10);

	/* Step 7: Final cleanup - switch back to input and ensure interrupt is disabled */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_INPUT | pin_flags);
	zassert_ok(ret, "Failed to configure GPIO pin as input for cleanup");

	ret = gpio_pin_interrupt_configure(gpio_dev, pin, GPIO_INT_DISABLE);
	zassert_ok(ret, "Failed to disable GPIO interrupt");

	ret = gpio_remove_callback(gpio_dev, &gpio_cb_data);
	zassert_ok(ret, "Failed to remove GPIO callback");

	LOG_INF("=== GPIO Level High Interrupt Test PASSED ===");
}

/**
 * @brief Test GPIO level low interrupt with software-controlled toggling
 *
 * This test validates GPIO level low interrupt functionality by:
 * 1. Configuring the GPIO pin as output and setting it high
 * 2. Setting up level low interrupt configuration
 * 3. Switching pin to input mode (maintains high state)
 * 4. Programmatically driving the pin low to trigger level interrupt
 * 5. Verifying the interrupt was triggered
 * 6. Immediately driving pin high to stop the level interrupt
 * 7. Ensuring proper cleanup to prevent continuous interrupt loops
 */
ZTEST(gpio_interrupt_basic, test_gpio_level_low_interrupt)
{
	int ret;
	const gpio_pin_t pin = DT_GPIO_PIN(BUTTON_NODE, gpios);
	const gpio_flags_t pin_flags = DT_GPIO_FLAGS(BUTTON_NODE, gpios);

	LOG_INF("=== GPIO Level Low Interrupt Test ===");
	LOG_INF("Using button1: GPIO port %s, pin %d", gpio_dev->name, pin);

	/* Step 1: Configure GPIO pin as output and set to high state */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_OUTPUT_ACTIVE);
	zassert_ok(ret, "Failed to configure GPIO pin as output active");
	LOG_INF("✓ GPIO pin configured as output, set to high state");

	/* Small delay to ensure pin state is stable */
	k_msleep(10);

	/* Step 2: Initialize callback and configure level low interrupt */
	gpio_init_callback(&gpio_cb_data, gpio_interrupt_callback, BIT(pin));
	ret = gpio_add_callback(gpio_dev, &gpio_cb_data);
	zassert_ok(ret, "Failed to add GPIO callback");
	LOG_INF("✓ GPIO callback initialized");

	/* Step 3: Switch pin to input mode and configure level low interrupt */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_INPUT | pin_flags);
	zassert_ok(ret, "Failed to configure GPIO pin as input");

	ret = gpio_pin_interrupt_configure(gpio_dev, pin, GPIO_INT_LEVEL_LOW);
	zassert_ok(ret, "Failed to configure GPIO level low interrupt");
	LOG_INF("✓ GPIO level low interrupt configured");

	/* Step 4: Programmatically drive pin low to trigger level interrupt */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_OUTPUT_INACTIVE);
	zassert_ok(ret, "Failed to configure GPIO pin as output inactive");
	LOG_INF("✓ GPIO pin driven low to trigger level interrupt");

	/* Small delay to allow interrupt processing */
	k_msleep(25);

	/* Step 5: Verify interrupt was triggered */
	zassert_true(interrupt_triggered, "GPIO level low interrupt was not triggered");
	zassert_true(interrupt_count >= 1, "Expected at least 1 interrupt, got %" PRIu32,
		     interrupt_count);
	LOG_INF("✅ GPIO level low interrupt triggered successfully (count: %" PRIu32 ")",
		interrupt_count);

	/* Step 6: Drive pin high to stop level interrupt and cleanup */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_OUTPUT_ACTIVE);
	zassert_ok(ret, "Failed to configure GPIO pin as output active");
	LOG_INF("✓ GPIO pin driven high to stop level interrupt");

	/* Small delay to ensure pin state change */
	k_msleep(10);

	/* Step 7: Final cleanup - switch back to input and ensure interrupt is disabled */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_INPUT | pin_flags);
	zassert_ok(ret, "Failed to configure GPIO pin as input for cleanup");

	ret = gpio_pin_interrupt_configure(gpio_dev, pin, GPIO_INT_DISABLE);
	zassert_ok(ret, "Failed to disable GPIO interrupt");

	ret = gpio_remove_callback(gpio_dev, &gpio_cb_data);
	zassert_ok(ret, "Failed to remove GPIO callback");

	LOG_INF("=== GPIO Level Low Interrupt Test PASSED ===");
}

/**
 * @brief Test GPIO both edge interrupt with software-controlled toggling
 *
 * This test validates GPIO both edge (rising and falling) interrupt functionality by:
 * 1. Configuring the GPIO pin as output and setting it low
 * 2. Setting up both edge interrupt configuration
 * 3. Switching pin to input mode
 * 4. Programmatically driving the pin high to trigger rising edge
 * 5. Then driving the pin low to trigger falling edge
 * 6. Verifying both interrupts were triggered (count = 2)
 * 7. Ensuring proper cleanup to prevent interrupt loops
 */
ZTEST(gpio_interrupt_basic, test_gpio_both_edge_interrupt)
{
	int ret;
	const gpio_pin_t pin = DT_GPIO_PIN(BUTTON_NODE, gpios);
	const gpio_flags_t pin_flags = DT_GPIO_FLAGS(BUTTON_NODE, gpios);

	LOG_INF("=== GPIO Both Edge Interrupt Test ===");
	LOG_INF("Using button1: GPIO port %s, pin %d", gpio_dev->name, pin);

	/* Step 1: Configure GPIO pin as output and set to low state */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_OUTPUT_INACTIVE);
	zassert_ok(ret, "Failed to configure GPIO pin as output inactive");
	LOG_INF("✓ GPIO pin configured as output, set to low state");

	/* Small delay to ensure pin state is stable */
	k_msleep(10);

	/* Step 2: Initialize callback and configure both edge interrupt */
	gpio_init_callback(&gpio_cb_data, gpio_interrupt_callback, BIT(pin));
	ret = gpio_add_callback(gpio_dev, &gpio_cb_data);
	zassert_ok(ret, "Failed to add GPIO callback");
	LOG_INF("✓ GPIO callback initialized");

	/* Step 3: Switch pin to input mode and configure both edge interrupt */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_INPUT | pin_flags);
	zassert_ok(ret, "Failed to configure GPIO pin as input");

	ret = gpio_pin_interrupt_configure(gpio_dev, pin, GPIO_INT_EDGE_BOTH);
	zassert_ok(ret, "Failed to configure GPIO both edge interrupt");
	LOG_INF("✓ GPIO both edge interrupt configured");

	/* Step 4: Trigger rising edge - drive pin high */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_OUTPUT_ACTIVE);
	zassert_ok(ret, "Failed to configure GPIO pin as output active");
	LOG_INF("✓ GPIO pin driven high to trigger rising edge");

	/* Small delay to allow interrupt processing */
	k_msleep(25);

	/* Verify first interrupt (rising edge) */
	zassert_true(interrupt_triggered, "GPIO rising edge interrupt was not triggered");
	zassert_equal(interrupt_count, 1, "Expected 1 interrupt after rising edge, got %" PRIu32,
		      interrupt_count);
	LOG_INF("✅ GPIO rising edge interrupt triggered (count: %" PRIu32 ")", interrupt_count);

	/* Step 5: Re-enable interrupt and trigger falling edge - drive pin low */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_INPUT | pin_flags);
	zassert_ok(ret, "Failed to configure GPIO pin as input");

	ret = gpio_pin_interrupt_configure(gpio_dev, pin, GPIO_INT_EDGE_BOTH);
	zassert_ok(ret, "Failed to re-configure GPIO both edge interrupt");

	ret = gpio_pin_configure(gpio_dev, pin, GPIO_OUTPUT_INACTIVE);
	zassert_ok(ret, "Failed to configure GPIO pin as output inactive");
	LOG_INF("✓ GPIO pin driven low to trigger falling edge");

	/* Small delay to allow interrupt processing */
	k_msleep(25);

	/* Step 6: Verify both interrupts occurred */
	zassert_true(interrupt_triggered, "GPIO interrupts were not triggered");
	zassert_equal(interrupt_count, 2, "Expected 2 interrupts (both edges), got %" PRIu32,
		      interrupt_count);
	LOG_INF("✅ GPIO both edge interrupts triggered successfully (count: %" PRIu32 ")",
		interrupt_count);

	/* Step 7: Final cleanup - switch back to input and ensure interrupt is disabled */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_INPUT | pin_flags);
	zassert_ok(ret, "Failed to configure GPIO pin as input for cleanup");

	ret = gpio_pin_interrupt_configure(gpio_dev, pin, GPIO_INT_DISABLE);
	zassert_ok(ret, "Failed to disable GPIO interrupt");

	ret = gpio_remove_callback(gpio_dev, &gpio_cb_data);
	zassert_ok(ret, "Failed to remove GPIO callback");

	LOG_INF("=== GPIO Both Edge Interrupt Test PASSED ===");
}

/**
 * @brief Test GPIO falling edge interrupt with software-controlled toggling
 *
 * This test validates GPIO falling edge interrupt functionality by:
 * 1. Configuring the GPIO pin as output and setting it high
 * 2. Setting up falling edge interrupt configuration
 * 3. Switching pin to input mode
 * 4. Programmatically driving the pin low to trigger the interrupt
 * 5. Verifying the interrupt was triggered exactly once
 * 6. Ensuring proper cleanup to prevent interrupt loops
 */
ZTEST(gpio_interrupt_basic, test_gpio_falling_edge_interrupt)
{
	int ret;
	const gpio_pin_t pin = DT_GPIO_PIN(BUTTON_NODE, gpios);
	const gpio_flags_t pin_flags = DT_GPIO_FLAGS(BUTTON_NODE, gpios);

	LOG_INF("=== GPIO Falling Edge Interrupt Test ===");
	LOG_INF("Using button1: GPIO port %s, pin %d", gpio_dev->name, pin);

	/* Step 1: Configure GPIO pin as output and set to high state */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_OUTPUT_ACTIVE);
	zassert_ok(ret, "Failed to configure GPIO pin as output active");
	LOG_INF("✓ GPIO pin configured as output, set to high state");

	/* Small delay to ensure pin state is stable */
	k_msleep(10);

	/* Step 2: Initialize callback and configure falling edge interrupt */
	gpio_init_callback(&gpio_cb_data, gpio_interrupt_callback, BIT(pin));
	ret = gpio_add_callback(gpio_dev, &gpio_cb_data);
	zassert_ok(ret, "Failed to add GPIO callback");
	LOG_INF("✓ GPIO callback initialized");

	/* Step 3: Switch pin to input mode and configure falling edge interrupt */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_INPUT | pin_flags);
	zassert_ok(ret, "Failed to configure GPIO pin as input");

	ret = gpio_pin_interrupt_configure(gpio_dev, pin, GPIO_INT_EDGE_FALLING);
	zassert_ok(ret, "Failed to configure GPIO falling edge interrupt");
	LOG_INF("✓ GPIO falling edge interrupt configured");

	/* Step 4: Programmatically drive pin low to trigger interrupt */
	/* Note: We'll briefly switch back to output to drive the pin low */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_OUTPUT_INACTIVE);
	zassert_ok(ret, "Failed to configure GPIO pin as output inactive");
	LOG_INF("✓ GPIO pin driven low to trigger falling edge");

	/* Small delay to allow interrupt processing */
	k_msleep(50);

	/* Step 5: Verify interrupt was triggered exactly once */
	zassert_true(interrupt_triggered, "GPIO interrupt was not triggered");
	zassert_equal(interrupt_count, 1, "Expected exactly 1 interrupt, got %" PRIu32,
		      interrupt_count);
	LOG_INF("✅ GPIO falling edge interrupt triggered successfully (count: %" PRIu32 ")",
		interrupt_count);

	/* Step 6: Final cleanup - switch back to input and ensure interrupt is disabled */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_INPUT | pin_flags);
	zassert_ok(ret, "Failed to configure GPIO pin as input for cleanup");

	ret = gpio_pin_interrupt_configure(gpio_dev, pin, GPIO_INT_DISABLE);
	zassert_ok(ret, "Failed to disable GPIO interrupt");

	ret = gpio_remove_callback(gpio_dev, &gpio_cb_data);
	zassert_ok(ret, "Failed to remove GPIO callback");

	LOG_INF("=== GPIO Falling Edge Interrupt Test PASSED ===");
}

/**
 * @brief Test basic GPIO interrupt configuration validation
 *
 * This test verifies that GPIO interrupt configuration APIs work correctly
 * without triggering actual interrupts.
 */
ZTEST(gpio_interrupt_basic, test_gpio_interrupt_configuration)
{
	int ret;
	const gpio_pin_t pin = DT_GPIO_PIN(BUTTON_NODE, gpios);
	const gpio_flags_t pin_flags = DT_GPIO_FLAGS(BUTTON_NODE, gpios);

	LOG_INF("=== Testing GPIO Interrupt Configuration ===");

	/* Test 1: Configure GPIO pin as input */
	ret = gpio_pin_configure(gpio_dev, pin, GPIO_INPUT | pin_flags);
	zassert_ok(ret, "Failed to configure GPIO pin as input");
	LOG_INF("✓ GPIO pin configured as input");

	/* Test 2: Configure interrupt for rising edge */
	ret = gpio_pin_interrupt_configure(gpio_dev, pin, GPIO_INT_EDGE_RISING);
	zassert_ok(ret, "Failed to configure GPIO interrupt for rising edge");
	LOG_INF("✓ GPIO rising edge interrupt configured");

	/* Test 3: Add callback */
	gpio_init_callback(&gpio_cb_data, gpio_interrupt_callback, BIT(pin));
	ret = gpio_add_callback(gpio_dev, &gpio_cb_data);
	zassert_ok(ret, "Failed to add GPIO callback");
	LOG_INF("✓ GPIO callback added");

	/* Test 4: Disable interrupt */
	ret = gpio_pin_interrupt_configure(gpio_dev, pin, GPIO_INT_DISABLE);
	zassert_ok(ret, "Failed to disable GPIO interrupt");
	LOG_INF("✓ GPIO interrupt disabled");

	/* Test 5: Remove callback */
	ret = gpio_remove_callback(gpio_dev, &gpio_cb_data);
	zassert_ok(ret, "Failed to remove GPIO callback");
	LOG_INF("✓ GPIO callback removed");

	LOG_INF("=== GPIO Interrupt Configuration Test PASSED ===");
}

/* Test suite definition */
ZTEST_SUITE(gpio_interrupt_basic, NULL, gpio_interrupt_test_setup, gpio_interrupt_test_before,
	    gpio_interrupt_test_after, NULL);
