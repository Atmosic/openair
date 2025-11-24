.. _atm_cs_library:

Atmosic Channel Sounding (ATM CS) Library
##########################################

Overview
********

The ATM CS library provides Channel Sounding (CS) functionality for Bluetooth-based ranging operations on Atmosic ATM34 platforms. This middleware enables precise distance measurement and ranging capabilities through Bluetooth Channel Sounding technology.

The library implements a CS reflector role that can be discovered and connected to by CS initiator devices for ranging operations. It integrates seamlessly with the Bluetooth stack and provides automatic connection management, advertising control, and CS configuration.

Features
********

- **CS Reflector Role**: Acts as a reflector for Channel Sounding ranging operations
- **Extended Advertising**: Uses Bluetooth extended advertising for CS discovery
- **Connection Management**: Automatic connection handling and validation
- **RAS Integration**: Includes Ranging and Sensing Service (RAS) UUID in advertisements
- **Work Queue Integration**: Non-blocking operations using application work queue
- **Flexible Bluetooth ID Management**: Support for default BT ID or custom BT ID creation
- **Custom Bluetooth Addresses**: Optional custom MAC address configuration for testing
- **Settings Storage**: Persistent storage of custom BT ID configuration
- **Configurable Parameters**: Bluetooth ID, advertising timeout, and logging levels
- **Resource Management**: Automatic cleanup of advertising sets and connections

Supported Platforms
*******************

- **ATM34XX**: ATM34 with Channel Sounding capability

Dependencies
************

The library requires the following Zephyr and Atmosic components:

- ``BT_CHANNEL_SOUNDING``: Bluetooth Channel Sounding support
- ``BT_RAS``: Ranging and Sensing Service
- ``ATM_LDO_MODE``: Atmosic LDO power mode
- ``APP_WORK_Q``: Application work queue
- ``SOC_SERIES_ATM34``: ATM34 SoC support

Optional dependencies for custom BT ID mode:

- ``ATM_SETTINGS``: For persistent storage of custom BT ID (automatically selected when needed)

API Reference
*************

The library provides four main API functions:

atm_cs_rrsp_init()
==================

Initializes the CS reflector functionality and prepares the module for operation. This function must be called during system initialization before any other CS APIs.

**Functionality**:

- Loads custom BT ID from persistent storage (when using custom BT ID mode)
- Creates new custom BT ID if none exists (when using custom BT ID mode)
- No operation required for default BT ID mode

**Usage**: Must be called after Bluetooth stack initialization but before starting CS advertising.

atm_cs_rrsp_start_adv()
=======================

Starts CS reflector advertising on the configured Bluetooth ID. The advertising includes:

- General discoverable and connectable flags
- RAS UUID for CS identification
- Device name and appearance in scan response

The advertising continues until:

- A connection is established
- Timeout occurs (if configured)
- Manually stopped via ``atm_cs_rrsp_stop_adv()``

atm_cs_rrsp_stop_adv()
======================

Stops the current CS advertising and cleans up associated resources. Safe to call multiple times or when advertising is not active.

atm_cs_rrsp_unpair()
====================

Removes all pairing information for the configured CS Bluetooth ID. Should be called when resetting the device or clearing pairing data.

**Warning**: This affects all services using the same Bluetooth ID.

Configuration Options
*********************

The library can be configured through Kconfig options:

``CONFIG_ATM_CS``
=================

**Type**: bool
**Default**: n
**Description**: Enable Atmosic Channel Sounding reflector functionality

``CONFIG_ATM_CS_ADV_BT_ID_DEFAULT``
===================================

**Type**: bool
**Default**: y
**Description**: Use default BT ID (0) for CS advertising. When disabled, CS will create its own custom BT ID.

``CONFIG_ATM_CS_CUSTOM_BT_ADDR``
================================

**Type**: bool
**Default**: n
**Dependencies**: ``!CONFIG_ATM_CS_ADV_BT_ID_DEFAULT``
**Description**: Enable custom Bluetooth device address for testing or development purposes. Only available when using custom BT ID mode.

``CONFIG_ATM_CS_CUSTOM_BT_ADDR_VALUE``
======================================

**Type**: string
**Default**: "ED:11:11:11:6E:EF"
**Dependencies**: ``CONFIG_ATM_CS_CUSTOM_BT_ADDR``
**Description**: Custom Bluetooth address in MAC format (XX:XX:XX:XX:XX:XX)

``CONFIG_ATM_CS_ADV_TIMEOUT_CS``
================================

**Type**: int
**Range**: 0-360000
**Default**: 0
**Description**: Advertising timeout in centiseconds (0 = no timeout)

``CONFIG_ATM_CS_LOG_LEVEL``
===========================

**Type**: int
**Default**: 3 (LOG_LEVEL_INF)
**Description**: Logging level for ATM CS module

Usage Examples
**************

Basic Usage (Default BT ID Mode)
=================================

.. code-block:: c

   #include "atm_cs.h"

   int main(void)
   {
       // Initialize Bluetooth stack
       int err = bt_enable(NULL);
       if (err) {
           return err;
       }

       // Initialize CS reflector
       atm_cs_rrsp_init();

       // Start CS reflector advertising on default BT ID
       atm_cs_rrsp_start_adv();

       return 0;
   }

Configuration for Custom BT ID Mode
====================================

To use custom BT ID mode, configure in ``prj.conf``:

.. code-block:: kconfig

   # Enable CS with custom BT ID
   CONFIG_ATM_CS=y
   CONFIG_ATM_CS_ADV_BT_ID_DEFAULT=n

   # Optional: Enable custom MAC address
   CONFIG_ATM_CS_CUSTOM_BT_ADDR=y
   CONFIG_ATM_CS_CUSTOM_BT_ADDR_VALUE="AA:BB:CC:DD:EE:FF"

   # Settings subsystem (automatically selected)
   CONFIG_SETTINGS=y

Usage with Custom BT ID Mode
=============================

.. code-block:: c

   #include "atm_cs.h"

   int main(void)
   {
       // Initialize Bluetooth stack
       int err = bt_enable(NULL);
       if (err) {
           return err;
       }

       // Initialize settings (for custom BT ID persistence)
       settings_subsys_init();
       settings_load();

       // Initialize CS reflector (will create/load custom BT ID)
       atm_cs_rrsp_init();

       // Start CS reflector advertising
       atm_cs_rrsp_start_adv();

       return 0;
   }

Integration Notes
*****************

Connection Handling
===================

The library automatically handles connections established through CS advertising:

- Validates connections are on the correct Bluetooth ID
- Takes connection references for CS operations
- Configures CS default settings (reflector role, antenna selection, max TX power)
- Cleans up advertising resources when connected
- Restarts advertising after disconnection

Work Queue Integration
======================

CS configuration operations are performed in the application work queue context to avoid blocking the Bluetooth stack. Ensure ``APP_WORK_Q`` is properly configured in your application.

Bluetooth ID Management
=======================

The library supports two modes for Bluetooth ID management:

**Default BT ID Mode** (``CONFIG_ATM_CS_ADV_BT_ID_DEFAULT=y``)
  - Uses BT_ID_DEFAULT (0) for CS advertising
  - Shares the default Bluetooth identity with other services
  - Simpler configuration, suitable for most applications

**Custom BT ID Mode** (``CONFIG_ATM_CS_ADV_BT_ID_DEFAULT=n``)
  - Creates a dedicated Bluetooth ID specifically for CS operations
  - Operates independently of other Bluetooth services
  - Supports custom MAC addresses for testing/development
  - BT ID is persistently stored using Zephyr settings subsystem
  - Automatically loads saved BT ID on subsequent boots

Custom BT ID Creation Process:
  1. Check if a valid BT ID is stored in settings
  2. If not found, create a new BT ID (optionally with custom MAC address)
  3. Save the new BT ID to persistent storage
  4. Use the BT ID for all CS advertising and connections

Logging
*******

The library provides comprehensive logging at different levels:

- **ERROR**: Critical failures and configuration errors
- **WARNING**: Non-critical issues and state changes
- **INFO**: Connection events and major state transitions
- **DEBUG**: Detailed operation flow and validation results

Set ``CONFIG_ATM_CS_LOG_LEVEL`` to control the verbosity level.

Troubleshooting
***************

Common Issues
=============

**Advertising not visible**:
  - Check that the Bluetooth stack is properly initialized
  - Verify BT ID configuration matches your setup (default vs custom)
  - Ensure extended advertising sets are properly configured

**Connection failures**:
  - Verify that the CS initiator supports the same CS configuration (antenna selection, TX power)
  - Check that pairing is properly established
  - Confirm the correct BT ID is being used for connections

**Initialization issues**:
  - Ensure ``atm_cs_rrsp_init()`` is called before ``atm_cs_rrsp_start_adv()``
  - Call ``atm_cs_rrsp_init()`` after Bluetooth stack initialization

**Custom BT ID issues**:
  - Ensure ``CONFIG_ATM_SETTINGS=y`` is enabled for custom BT ID mode
  - Check that ``settings_subsys_init()`` and ``settings_load()`` are called before ``atm_cs_rrsp_init()``
  - Verify custom MAC address format is correct (XX:XX:XX:XX:XX:XX)
  - Check logs for BT ID creation failures

**Work queue errors**: Ensure ``APP_WORK_Q`` is configured and running in your application.

**Resource cleanup**: If experiencing resource leaks, check that connections are properly terminated and advertising sets are cleaned up.

**Settings storage errors**:
  - Verify flash storage is properly configured for settings
  - Check that the settings partition has sufficient space
  - Monitor logs for settings save/load failures

License
*******

Copyright (C) Atmosic 2025

This library is part of the Atmosic OpenAir SDK and is subject to the SDK license terms.
