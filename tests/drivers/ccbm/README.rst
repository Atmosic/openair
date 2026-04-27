.. _ccbm_driver_test:

CCBM Driver Test
################

Overview
********
This test suite validates the Coin Cell Battery Management (CCBM) driver functionality.
The CCBM driver measures battery impedance by taking voltage readings under no-load
and with-load conditions, then calculating the impedance in milliohms (mOhm).

Test Coverage
*************
The test suite covers the following aspects:
1. **Initialization Tests**
   - Driver initialization
2. **Basic Measurement Tests**
   - Impedance measurement with zero settling delay
   - Impedance measurement with various settling delays (short, medium, long)
3. **Impedance Validation Tests**
   - Battery impedance within expected range (10 mOhm - 1000 mOhm)
4. **Error Handling Tests**
   - NULL callback parameter validation (mandatory callback)
   - Busy state handling (concurrent measurement attempts)
5. **Sequential Measurement Tests**
   - Multiple sequential measurements
   - Measurement consistency across multiple runs
6. **User Data Tests**
   - User data passing through callback

Requirements
************

Hardware Requirements
=====================
- Atmosic ATM34xx development board
- Coin cell battery (non-rechargeable) installed
- Battery voltage should be between 2.0V and 3.6V

Software Requirements
=====================
- Zephyr RTOS
- CCBM driver enabled (CONFIG_ATM_CCBM=y)
- Radio HAL manager (auto-selected by CCBM driver)
- ADC driver (auto-selected by CCBM driver)
- BLE stack (for radio HAL manager)

Building and Running
********************
To build and run the test:
.. code-block:: console
   west build -b <board> openair/tests/drivers/ccbm
   west flash
Replace ``<board>`` with your target board (e.g., ``atm34_dk``).

Expected Output
***************
The test should produce output similar to:
.. code-block:: console
   *** Booting Zephyr OS build v3.x.x ***
   Running TESTSUITE ccbm_driver
   ===================================================================
   START - test_01_ccbm_init
    PASS - test_01_ccbm_init in 0.001 seconds
   ===================================================================
   START - test_02_measure_impedance_zero_delay
   Callback: status=0, vbatt_no_load=3000 mV, vbatt_with_load=2950 mV
    PASS - test_02_measure_impedance_zero_delay in 0.150 seconds
   ===================================================================
   START - test_03_validate_impedance_reading
   Callback: status=0, impedance=500 mOhm
   Battery impedance: 500 mOhm
    PASS - test_03_validate_impedance_reading in 0.150 seconds
   ...
   ===================================================================
   TESTSUITE ccbm_driver succeeded
   ------ TESTSUITE SUMMARY START ------
   SUITE PASS - 100.00% [ccbm_driver]: pass = 10, fail = 0, skip = 0, total = 10 duration = 2.500 seconds
    - PASS - [ccbm_driver.test_01_ccbm_init] duration = 0.001 seconds
    - PASS - [ccbm_driver.test_02_measure_impedance_zero_delay] duration = 0.150 seconds
    - PASS - [ccbm_driver.test_03_validate_impedance_reading] duration = 0.150 seconds
    - PASS - [ccbm_driver.test_04_measure_with_medium_delay] duration = 0.200 seconds
    - PASS - [ccbm_driver.test_05_measure_with_long_delay] duration = 0.250 seconds
    - PASS - [ccbm_driver.test_06_null_callback_error] duration = 0.001 seconds
    - PASS - [ccbm_driver.test_07_busy_state_handling] duration = 0.250 seconds
    - PASS - [ccbm_driver.test_08_sequential_measurements] duration = 0.750 seconds
    - PASS - [ccbm_driver.test_09_user_data_passing] duration = 0.150 seconds
    - PASS - [ccbm_driver.test_10_measurement_consistency] duration = 0.550 seconds
   ------ TESTSUITE SUMMARY END ------
   ===================================================================
   PROJECT EXECUTION SUCCESSFUL

Test Details
************

Test Parameters
===============
- **Settling Delays**: 0ms, 10ms, 50ms, 100ms
- **Expected Impedance Range**: 10 mOhm - 1000 mOhm
- **Callback Timeout**: 5 seconds per measurement
- **Consistency Tolerance**: 20% variation between measurements

Notes
*****
1. The CCBM driver requires a coin cell (non-rechargeable) battery. The driver
   includes a compile-time assertion to enforce this requirement.
2. All measurements are performed through the radio HAL manager to ensure
   exclusive radio access during ADC measurements.
3. The settling delay parameter allows the load condition to stabilize before
   measuring the with-load voltage. A value of 0ms is valid for immediate
   measurement.
4. The callback is mandatory. Calling ``ccbm_measure_impedance()`` with a NULL
   callback will return ``CCBM_STATUS_INVALID``.
5. Only one measurement can be in progress at a time. Attempting to start a
   second measurement while one is in progress will return ``CCBM_STATUS_BUSY``.

Troubleshooting
***************
If tests fail:
1. **Impedance out of range**: Check battery voltage with a multimeter. Replace
   battery if voltage is below 2.0V or above 3.6V. Very high impedance (>500 mOhm)
   may indicate a weak or depleted battery.
2. **Callback timeout**: Ensure BLE stack is properly initialized and radio HAL
   manager is functioning correctly.
3. **Inconsistent measurements**: Check battery connections and ensure battery
   is properly seated. Some variation is normal, but >20% variation may indicate
   poor battery contact or a failing battery.
4. **Build errors**: Ensure all dependencies are enabled (ADC, Radio HAL Manager,
   BLE stack).
