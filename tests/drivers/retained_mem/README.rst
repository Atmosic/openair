Retained Memory Driver Test
===========================

Overview
--------

This test suite validates the Atmosic retained memory driver functionality
on Atmosic SOC platforms. The driver provides standard Zephyr retained_mem APIs
to save and restore data across hibernation cycles, utilizing SHUB registers and
PSEQ persistent registers as storage medium.

**Framework**: This test uses the Zephyr ZTEST framework for structured test execution,
with special handling for multi-cycle hibernation testing that spans multiple boot cycles.

Test Categories
---------------

Basic Functionality Tests (ZTEST)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

These tests run only on cold boot using the ZTEST framework:

- **test_size_validation**: Validates retained memory size constraints and structure alignment
- **test_basic_save_restore**: Tests basic save/restore operations without hibernation
- **test_magic_values_preservation**: Ensures magic values are correctly preserved
- **test_zero_data**: Ensures zero-filled data is correctly preserved
- **test_single_byte**: Tests single byte save/restore operations
- **test_max_size_data**: Tests maximum test data size (varies by platform)
- **test_retained_mem_capacity**: Tests full retained memory capacity (198-222 bytes)
- **test_multiple_cycles**: Validates multiple save/restore cycles

Hibernation Tests (Multi-Cycle ZTEST)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The **z_test_hibernation_cycle** ZTEST runs **5 hibernation cycles**, with each cycle testing different data sizes:

- **Cycle 1 - Simple Test**: 32 bytes with pattern 0xA5 ^ index
- **Cycle 2 - Small Data**: 16 bytes with pattern 0x55 ^ index
- **Cycle 3 - Medium Data**: 64 bytes with pattern 0xAA ^ index
- **Cycle 4 - Large Data**: 128 bytes with deterministic pseudo-random pattern
- **Cycle 5 - Max Data**: Maximum test data size (~190 bytes) with pattern 0x55 ^ index

**Note**: The hibernation test is named with 'z_' prefix to ensure it runs last alphabetically,
allowing all basic tests to complete before hibernation begins.

Test Design
-----------

The test follows a **ZTEST-based multi-cycle hibernation approach**:

**Phase 1: Basic Tests (Cold Boot Only)**
   - **ZTEST Execution**: All basic tests run using ZTEST framework
   - **Boot Type Check**: Tests skip automatically on hibernation wakeup using ``ztest_test_skip()``
   - **Comprehensive Coverage**: Tests initialization, basic operations, edge cases, and capacity limits
   - **Structured Reporting**: ZTEST provides standardized pass/fail reporting

**Phase 2: Multi-Cycle Hibernation Testing (ZTEST)**
   - **Single ZTEST Function**: ``z_test_hibernation_cycle`` handles both cold boot and hibernation wakeup
   - **Cycle Management**: Uses persistent retained memory to track test progress across hibernations
   - **Test Sequence**: Runs 5 different hibernation tests, one per wake cycle
   - **Data Layout**: Saves combined cycle state + test data in retained memory using packed structures
   - **Progressive Testing**: Each hibernation tests different data sizes and patterns

**Each Hibernation Cycle:**
   1. **Save Phase**: Save cycle state + test data using retained memory driver
   2. **Hibernation**: Trigger hibernation using Zephyr PM (``k_sleep(3000ms)``)
   3. **Restore Phase**: Wake up, restore cycle state + test data using ``hib_restore_data()``
   4. **Verification**: Verify data integrity with checksums and byte comparison
   5. **Next Cycle**: Advance to next test or complete if all tests done

**Final Results**: After all 5 cycles, displays comprehensive test summary

Platform Requirements
---------------------

- **SOC Family**: Atmosic (CONFIG_SOC_FAMILY_ATM)
- **Power Management**: Enabled (CONFIG_PM)
- **Retained Memory**: Enabled (CONFIG_RETAINED_MEM=y, CONFIG_RETAINED_MEM_ATM_HIB=y)
- **ZTEST Framework**: Enabled (CONFIG_ZTEST=y)
- **Hardware**: Atmosic EVK boards (atmevk_*)

The test cannot run on:
- Native simulation platforms
- QEMU platforms
- Non-Atmosic SOCs

Configuration
-------------

Required Kconfig Options
~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: kconfig

   # Retained memory driver
   CONFIG_RETAINED_MEM=y
   CONFIG_RETAINED_MEM_ATM_HIB=y

   # Enable ZTEST framework
   CONFIG_ZTEST=y

   # Enable power management for hibernation tests
   CONFIG_PM=y

Data Storage Mechanism
----------------------

The retained_mem driver uses two storage areas:

1. **SHUB Registers**: Sensor Hub registers that retain data during hibernation
2. **PSEQ Persistent Registers**: Power Sequencer persistent registers (PERSISTENT1-6)

Maximum storage capacity varies by platform:
- With PERSISTENT6: 222 bytes
- With PERSISTENT5: 218 bytes
- Base configuration: 198 bytes

Test Data Patterns
------------------

- **0x55 Pattern**: Alternating bit pattern for basic testing
- **0xAA Pattern**: Inverse alternating bit pattern
- **Random Pattern**: Pseudo-random data for comprehensive testing
- **Zero Pattern**: All zeros to test edge cases
- **Incremental Pattern**: Sequential data for cycle testing

Running the Tests
-----------------

Sysbuild Support
~~~~~~~~~~~~~~~~

The test supports sysbuild for building:

**Basic sysbuild:**

.. code-block:: bash

   west build -p always -b <BOARD> openair/tests/drivers/retained_mem --sysbuild -T drivers.retained_mem.atm

**Available sysbuild test configuration:**

- ``drivers.retained_mem.atm`` - Basic configuration for ATM33/ATM34 SOCs

Standard Build (Non-sysbuild)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

For simple testing without sysbuild:

.. code-block:: bash

   west build -b atmevk_3430e_yqn_5 tests/drivers/retained_mem

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]

The test will automatically:
1. Run basic functionality tests
2. Execute hibernation test (system will hibernate and wake up)
3. Verify data integrity after hibernation
4. Report results

Expected Output
---------------

**Boot 1 (Cold Boot)**:

.. code-block::

   === Retained Memory Driver Test Suite ===
   Boot type: POWER_ON (cold boot)
   Running TESTSUITE retained_mem
   ===================================================================
   START - test_basic_save_restore
   Testing basic save/restore without hibernation...
    PASS - test_basic_save_restore in 0.005 seconds
   ===================================================================
   START - test_retained_mem_capacity
   Testing retained memory full capacity (222 bytes)...
    PASS - test_retained_mem_capacity in 0.005 seconds
   ===================================================================
   START - test_magic_values_preservation
   Testing magic value preservation in retained memory...
    PASS - test_magic_values_preservation in 0.003 seconds
   ===================================================================
   START - test_max_size_data
   Testing maximum test data size (190 bytes)...
    PASS - test_max_size_data in 0.004 seconds
   ===================================================================
   START - test_multiple_cycles
   Testing multiple save/restore cycles...
    PASS - test_multiple_cycles in 0.006 seconds
   ===================================================================
   START - test_single_byte
   Testing single byte save/restore...
    PASS - test_single_byte in 0.002 seconds
   ===================================================================
   START - test_size_validation
   === Retained Memory Size Analysis ===
   Actual retained memory size: 222 bytes
   ✅ Size validation passed - structure fits in retained memory
    PASS - test_size_validation in 0.003 seconds
   ===================================================================
   START - test_zero_data
   Testing zero data preservation...
    PASS - test_zero_data in 0.003 seconds
   ===================================================================
   START - z_test_hibernation_cycle
   === Cold Boot: Starting Hibernation Test Cycle ===
   Will run 5 hibernation tests across multiple wake cycles:
   1. Simple Test (32 bytes)
   2. Small Data (16 bytes)
   3. Medium Data (64 bytes)
   4. Large Data (128 bytes, pseudo-random)
   5. Max Data (190 bytes)

   === Starting Test 1: Simple ===
   Triggering hibernation for 3000 ms...

**Boot 2-6 (Hibernation Wakeups)**:

.. code-block::

   === Retained Memory Driver Test Suite ===
   Boot type: HIBERNATION (woke up from hibernation)
   Running TESTSUITE retained_mem
   ===================================================================
    - SKIP - [retained_mem.test_basic_save_restore] duration = 0.001 seconds
    - SKIP - [retained_mem.test_retained_mem_capacity] duration = 0.001 seconds
    - SKIP - [retained_mem.test_magic_values_preservation] duration = 0.001 seconds
    - SKIP - [retained_mem.test_max_size_data] duration = 0.001 seconds
    - SKIP - [retained_mem.test_multiple_cycles] duration = 0.001 seconds
    - SKIP - [retained_mem.test_single_byte] duration = 0.001 seconds
    - SKIP - [retained_mem.test_size_validation] duration = 0.001 seconds
    - SKIP - [retained_mem.test_zero_data] duration = 0.001 seconds
   ===================================================================
   START - z_test_hibernation_cycle
   === Hibernation Wakeup: Running Simple Test ===
   SUCCESS: Simple hibernation test PASSED!

   === Preparing Next Test: Small Data ===
   Triggering hibernation for 3000 ms...

   [... continues for each test cycle ...]

**Final Boot (All Tests Complete)**:

.. code-block::

   === All Hibernation Tests Completed ===
   Test Results Summary:
   - Simple Test:     PASS
   - Small Data:      PASS
   - Medium Data:     PASS
   - Large Data:      PASS
   - Max Data:        PASS
   Total: 5/5 hibernation tests passed
   🎉 ALL HIBERNATION TESTS PASSED! 🎉

Test Limitations
----------------

- Requires actual hardware (no simulation support)
- Cannot coexist with SHUB driver (uses same registers)

Troubleshooting
---------------

If tests fail:
1. Ensure CONFIG_RETAINED_MEM=y and CONFIG_RETAINED_MEM_ATM_HIB=y
2. Verify ZTEST framework is enabled (CONFIG_ZTEST=y)
3. Verify power management is enabled (CONFIG_PM=y)
4. Check that SHUB driver is not enabled
5. Confirm running on supported Atmosic hardware
6. Check for sufficient power supply during hibernation
7. If basic tests are skipped, ensure system boots with TYPE_POWER_ON first
