SPE Secure Fault Storage Test
#############################

Overview
********

This test suite validates the Atmosic SPE (Secure Processing Environment) secure fault storage
functionality. It tests the ability to capture, store, and retrieve secure fault information when
exceptions occur in the secure world, making this data available to the non-secure processing
environment (NSPE).

The test demonstrates how applications can use the ``atm_nsc_spe_get_secure_fault_data()`` API to
retrieve fault information and handle secure exceptions appropriately.

Test Components
***************

Main Test File (main.c)
========================

Contains the primary test cases:

- **test_actual_null_access**: Triggers an actual null pointer dereference to test fault capture
- **test_nsc_invalid_params**: Validates API parameter checking with invalid inputs

Test Log Backend (test_log_backend.c)
======================================

Implements a custom logging backend specifically for testing log panic functionality:

- Provides a minimal log backend implementation
- Handles log panic events with custom output
- Used in log panic test variants

Test Configurations
********************

The test suite includes multiple test configurations:

Basic Test
==========
- Tests basic fault storage functionality
- Uses null pointer dereference to trigger faults
- Validates fault data retrieval and processing

Log Panic Variants
==================
- Tests integration with Zephyr logging panic functionality
- Validates that fault storage works during log panic events
- Includes both basic and MCUBoot configurations

Requirements
************

- Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

Basic Test
==========

.. code-block:: bash

    west build -p always -b <BOARD> openair/tests/drivers/atm_spe_sec_fault_storage --sysbuild -T tests.drivers.atm_spe_sec_fault_storage.atm

Programming
===========

To flash the built images:

.. code-block:: bash

    west flash --skip-rebuild -d build --verify --device <DEVICE_ID> --jlink --fast_load [--erase_all]
