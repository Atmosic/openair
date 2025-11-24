.. _gpio_interrupt_test-sample:

Basic: GPIO Interrupt Test
##########################

Overview
********

A comprehensive test suite for GPIO interrupt functionality on Atmosic platforms.
This sample validates all GPIO interrupt modes including edge-triggered and level-triggered interrupts.

The test uses software-controlled GPIO manipulation to generate deterministic interrupt events,
ensuring reliable validation of GPIO interrupt behavior across different hardware configurations.

Requirements
************

Atmosic EVK with GPIO support

Building and Running
********************

This sample is built from ``openair/samples/basic/gpio_interrupt_test``.

Build command:

.. code-block:: bash

   west build -p always -b ATMEVK-3430e-YQN-5 openair/samples/basic/gpio_interrupt_test --sysbuild

Flash command:

.. code-block:: bash

   west flash --device=<DEVICE_ID> --jlink --verify

Sample Output
*************

.. code-block:: console

   Running TESTSUITE gpio_interrupt_basic
   ===================================================================
   I: GPIO interrupt test setup complete - using button0 (GPIO pin 5)

   START - test_gpio_interrupt_configuration
   I: === GPIO Interrupt Configuration Test ===
   I: Using button0: GPIO port gpio@100000, pin 5
   I: ✓ GPIO interrupt configuration API validation complete
   PASS - test_gpio_interrupt_configuration in 0.001 seconds

   START - test_gpio_rising_edge_interrupt
   I: === GPIO Rising Edge Interrupt Test ===
   I: Using button0: GPIO port gpio@100000, pin 5
   I: ✓ GPIO pin configured as output, set to low state
   I: ✓ GPIO callback initialized
   I: ✓ GPIO rising edge interrupt configured
   I: GPIO interrupt triggered (count: 1)
   I: ✓ GPIO pin driven high to trigger rising edge
   I: ✅ GPIO rising edge interrupt triggered successfully
   PASS - test_gpio_rising_edge_interrupt in 0.001 seconds

   START - test_gpio_falling_edge_interrupt
   I: === GPIO Falling Edge Interrupt Test ===
   I: Using button0: GPIO port gpio@100000, pin 5
   I: ✓ GPIO pin configured as output, set to high state
   I: ✓ GPIO callback initialized
   I: ✓ GPIO falling edge interrupt configured
   I: GPIO interrupt triggered (count: 1)
   I: ✓ GPIO pin driven low to trigger falling edge
   I: ✅ GPIO falling edge interrupt triggered successfully
   PASS - test_gpio_falling_edge_interrupt in 0.001 seconds

   START - test_gpio_both_edge_interrupt
   I: === GPIO Both Edge Interrupt Test ===
   I: Using button0: GPIO port gpio@100000, pin 5
   I: ✓ GPIO pin configured as output, set to low state
   I: ✓ GPIO callback initialized
   I: ✓ GPIO both edge interrupt configured
   I: GPIO interrupt triggered (count: 1)
   I: ✓ GPIO pin driven high to trigger rising edge
   I: ✅ GPIO rising edge interrupt triggered (count: 1)
   I: GPIO interrupt triggered (count: 2)
   I: ✓ GPIO pin driven low to trigger falling edge
   I: ✅ GPIO both edge interrupt test completed successfully
   PASS - test_gpio_both_edge_interrupt in 0.001 seconds

   START - test_gpio_level_low_interrupt
   I: === GPIO Level Low Interrupt Test ===
   I: Using button0: GPIO port gpio@100000, pin 5
   I: ✓ GPIO pin configured as output, set to high state
   I: ✓ GPIO callback initialized
   I: ✓ GPIO level low interrupt configured
   I: GPIO interrupt triggered (count: 1)
   I: ✓ GPIO pin driven low to trigger level interrupt
   I: ✅ GPIO level low interrupt triggered successfully
   PASS - test_gpio_level_low_interrupt in 0.001 seconds

   START - test_gpio_level_high_interrupt
   I: === GPIO Level High Interrupt Test ===
   I: Using button0: GPIO port gpio@100000, pin 5
   I: ✓ GPIO pin configured as output, set to low state
   I: ✓ GPIO callback initialized
   I: ✓ GPIO level high interrupt configured
   I: GPIO interrupt triggered (count: 1)
   I: ✓ GPIO pin driven high to trigger level interrupt
   I: ✅ GPIO level high interrupt triggered successfully
   PASS - test_gpio_level_high_interrupt in 0.001 seconds

   ===================================================================
   TESTSUITE gpio_interrupt_basic succeeded

   PROJECT EXECUTION SUCCESSFUL

Test Coverage
*************

This test suite validates the following GPIO interrupt modes:

* **GPIO_INT_EDGE_RISING**: Rising edge-triggered interrupts
* **GPIO_INT_EDGE_FALLING**: Falling edge-triggered interrupts
* **GPIO_INT_EDGE_BOTH**: Both edge-triggered interrupts
* **GPIO_INT_LEVEL_LOW**: Low level-triggered interrupts
* **GPIO_INT_LEVEL_HIGH**: High level-triggered interrupts

Each test performs:

1. GPIO pin configuration and initialization
2. Interrupt callback setup and registration
3. Interrupt mode configuration
4. Software-controlled GPIO state changes to trigger interrupts
5. Verification of interrupt callback execution
6. Cleanup and state reset
