.. _sensor_beacon-application:

Sensor Beacon Application
##########################

A Zephyr application that broadcasts onboard sensor data (accelerometer, temperature, humidity) and battery voltage information via Bluetooth beacon advertisements.

This application is designed to be used with the **Atmosic DevTools** mobile app to monitor sensor data.

Overview
********

The sensor_beacon application is a focused, non-configurable beacon implementation that provides sensor data collection and broadcasting without any runtime configuration or connection support. It is optimized for minimal memory usage, power consumption, and deterministic behavior.

Using with Atmosic DevTools App
********************************

The sensor_beacon application is designed to work with the Atmosic DevTools mobile app for monitoring sensor data and controlling wake-up.

Monitoring Sensor Data
======================

1. Open the Atmosic DevTools app
2. Navigate to **APPLICATIONS** → **BEACON**
3. The app will start scanning for devices
4. When your sensor beacon device appears, tap **MONITOR**
5. The app will display real-time sensor data from the device

Waking Up the Device
====================

When the device is in hibernation with WuRx enabled:

1. Go to the scanning page in the app
2. Tap the three-bar menu button (☰) in the top right corner
3. Select **Wake Up**
4. The device will wake from hibernation and resume advertising

.. note::
   To enable WuRx functionality, the application must be built with ``CONFIG_WURX=y``
   and an appropriate wake-up pattern overlay. See the WURX Mode section below for details.

Features
********

- **Sensor Data Collection**: Reads temperature, humidity, and 3-axis accelerometer data
- **Battery Monitoring**: Monitors VStore and VBatt voltages
- **Bluetooth Beacon Advertising**: Broadcasts sensor data using a standardized beacon format
- **Non-Connectable**: Pure beacon mode without BLE connection support
- **Fixed Configuration**: Compile-time configuration only, no runtime changes
- **Periodic Updates**: Configurable interval for sensor data updates
- **Power Management**: Supports Zephyr power management with optimized sleep
- **WURX Support**: Optional Wake-Up Receiver for low-power operation
- **Comprehensive Testing**: Full Ztest test suite for core functionality

Architecture
************

The application follows a lean, modular design focused on core beacon functionality::

    sensor_beacon/
    ├── src/
    │   ├── main.c                 # Application entry point (minimal)
    │   ├── sensor_beacon.c        # Main application logic
    │   ├── sensor_interface.c     # Sensor reading with scaling
    │   ├── battery_monitor.c      # Battery voltage monitoring
    │   ├── beacon_adv.c           # Bluetooth beacon advertising
    │   └── sensor_data.c          # Periodic data collection
    └── tests/                     # Core functionality test suite

Configuration
*************

Key configuration options in ``prj.conf`` (compile-time only):

- ``CONFIG_SENSOR_BEACON_UPDATE_INTERVAL``: Update interval in centiseconds (default: 100 = 1s)
- ``CONFIG_SENSOR_BEACON_FAST_ADV``: Enable fast advertising mode for quick device discovery (default: n)
- ``CONFIG_SENSOR_BEACON_ACCEL_SCALING_FACTOR``: Accelerometer scaling factor (default: 1000)
- ``CONFIG_SENSOR_BEACON_TEMP_SCALING_FACTOR``: Temperature scaling factor (default: 256)
- ``CONFIG_SENSOR_BEACON_HUMIDITY_SCALING_FACTOR``: Humidity scaling factor (default: 256)

Beacon Advertising Intervals
****************************

The application supports two advertising modes (compile-time selection):

- **Normal Mode (Default)**: 1-1.2 second intervals for optimal power consumption
- **Fast Mode**: 100-150ms intervals for quick device discovery

To enable fast mode, set ``CONFIG_SENSOR_BEACON_FAST_ADV=y`` in your configuration.

Sensor Data Format
******************

The application uses a standardized sensor data format for client compatibility::

    typedef struct {
        uint16_t temp;      // Temperature (scaled by 256)
        uint16_t humidity;  // Humidity (scaled by 256)
        uint16_t x_axis;    // X-axis acceleration (scaled)
        uint16_t y_axis;    // Y-axis acceleration (scaled)
        uint16_t z_axis;    // Z-axis acceleration (scaled)
        float vstore;       // Storage voltage (volts)
        float vbatt;        // Battery voltage (volts)
    } __packed sensor_beacon_data_t;

Beacon Advertisement Structure
******************************

The Bluetooth advertisement follows a standardized, non-connectable beacon format:

1. **Flags**: ``BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR``
2. **Complete Name**: Device name (fixed at compile time)
3. **Service UUID**: Eddystone UUID (0xFEAA)
4. **Service Data**: Eddystone-URL pointing to atmosic.com
5. **Manufacturer Data**: Atmosic Company ID (0x0A24) + sensor data

.. note::
   The beacon is **non-connectable** and does not accept BLE connections. All data is broadcast via advertisements only.

Building and Running
********************

This application is built from ``openair/applications/sensor_beacon``.

Production Build (Default)
===========================
Optimized for power consumption, performance, and minimal logging:

.. code-block:: bash

    west build -p always -b <BOARD> openair/applications/sensor_beacon --sysbuild -T applications.sensor_beacon.atm

Debug Build
===========
Enhanced logging and debugging aids for development:

.. code-block:: bash

    west build -p always -b <BOARD> openair/applications/sensor_beacon --sysbuild -T applications.sensor_beacon.atm -DFILE_SUFFIX=debug

**Example for ATMEVK-3430e-YQN-5:**

Production:

.. code-block:: bash

    west build -p always -b ATMEVK-3430e-YQN-5 openair/applications/sensor_beacon --sysbuild -T applications.sensor_beacon.atm

Debug:

.. code-block:: bash

    west build -p always -b ATMEVK-3430e-YQN-5 openair/applications/sensor_beacon --sysbuild -T applications.sensor_beacon.atm -DFILE_SUFFIX=debug

Programming
===========

To flash the built images:

.. code-block:: bash

    west flash --skip-rebuild -d build --verify --device <DEVICE_ID> --jlink --fast_load

**Example:**

.. code-block:: bash

    west flash --skip-rebuild -d build --verify --device 000900066361 --jlink --fast_load

Configuration Differences
==========================

The debug and production builds have **identical functionality** - they differ only in logging verbosity:

+-------------------+---------------------------+-------------------------+
| Feature           | Production Build          | Debug Build             |
+===================+===========================+=========================+
| **Logging Level** | Warning/Error only (level | Debug/Verbose (level 4) |
|                   | 2)                        |                         |
+-------------------+---------------------------+-------------------------+
| **ADC Logging**   | Error level only          | Debug level             |
+-------------------+---------------------------+-------------------------+
| **Sensor Logging**| Warning level only        | Debug level             |
+-------------------+---------------------------+-------------------------+
| **Function Names**| Not logged                | Logged with debug       |
|                   |                           | messages                |
+-------------------+---------------------------+-------------------------+
| **All Other       | Identical                 | Identical               |
| Settings**        |                           |                         |
+-------------------+---------------------------+-------------------------+

.. note::
   Both configurations maintain the same:

   - Update intervals (1 second)
   - Beacon advertising intervals (1-1.2s normal, 100-150ms fast)
   - Power management settings
   - Stack sizes
   - Watchdog configuration
   - Non-connectable beacon behavior
   - Sensor functionality
   - No persistent storage or runtime configuration

Testing
*******

To build and run the test suite:

.. code-block:: bash

    west build -p always -b <BOARD> openair/applications/sensor_beacon/tests --sysbuild
    west flash --skip-rebuild -d build --verify --device <DEVICE_ID> --jlink --fast_load

**Example:**

.. code-block:: bash

    west build -p always -b ATMEVK-3430e-YQN-5 openair/applications/sensor_beacon/tests --sysbuild
    west flash --skip-rebuild -d build --verify --device 000900066361 --jlink --fast_load

The test suite includes:

- Sensor interface validation
- Battery monitoring tests
- Beacon advertising tests (core functionality only)
- Data collection integration tests
- Scaling factor verification
- Non-connectable beacon behavior validation

Power Management
****************

The application supports Zephyr power management:

- Periodic sensor readings with configurable intervals
- Automatic sleep between operations
- Watchdog integration for reliability

WURX Mode
=========

To enable WuRx (Wake-Up Receive) functionality, build the application with ``CONFIG_WURX=y`` and specify a wake-up pattern overlay file.

**WURX Mode Operation:**

1. **Startup Phase**: Device powers on and advertises sensor data for a fixed period of time, which can be configured via ``CONFIG_SENSOR_BEACON_WURX_ACTIVE_ADV_TIME_MS``.
2. **Hibernation**: Enters deep hibernation mode (low power consumption).
3. **Wake-Up Detection**: WuRx hardware monitors for wake-up signals while in hibernation.
4. **Wake-Up Response**: When a wake-up signal is detected, it goes back to **Startup Phase**.

Wake-Up Signal Configuration
----------------------------

The WuRx hardware can be configured to detect different types of wake-up signals by specifying different overlay files in ``openair/doc/wurx/`` using ``-DEXTRA_DTC_OVERLAY_FILE`` to match your wake-up signal source.

Bluetooth Inquiry
^^^^^^^^^^^^^^^^^

Configure WURX to detect Bluetooth inquiry scans (can be sent from an Android phone):

.. code-block:: bash

    -DCONFIG_WURX=y -DEXTRA_DTC_OVERLAY_FILE="<WEST_TOPDIR>/openair/doc/wurx/bt_inquiry.overlay"

iBeacon
^^^^^^^

Configure WURX to detect iBeacon advertisements (can be sent from an iPhone):

.. code-block:: bash

    -DCONFIG_WURX=y -DEXTRA_DTC_OVERLAY_FILE="<WEST_TOPDIR>/openair/doc/wurx/ibeacon.overlay"

High Duty Cycle Advertisements
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Configure WURX to detect high duty cycle advertisements:

.. code-block:: bash

    -DCONFIG_WURX=y -DEXTRA_DTC_OVERLAY_FILE="<WEST_TOPDIR>/openair/doc/wurx/high_duty_adv.overlay"

The ``openair/samples/bluetooth/high_duty_adv`` example can be used to issue high duty cycle advertisements as a wake-up signal source.

.. note::
   For detailed information about WuRx and these overlay configurations, see :ref:`wurx_documentation`.

LED and Button Functionality
*****************************

The sensor_beacon application provides platform-specific LED indication and button control functionality to support different hardware configurations.

LED Indications
===============

The application supports three types of LED indications:

1. **Power ON Indication** (Tag designs only)

   - Primary LED blinks 3 times at 0.5s interval
   - Shown when device transitions from OFF to ON state via button press
   - Only available when ``CONFIG_SENSOR_BEACON_BUTTON_POWER_CONTROL`` is enabled

2. **Power OFF Indication** (Tag designs only)

   - Secondary LED blinks 3 times at 0.5s interval
   - Shown when device transitions from ON to OFF state via button press
   - Only available when ``CONFIG_SENSOR_BEACON_BUTTON_POWER_CONTROL`` is enabled

3. **Beacon Status Indication** (All platforms)

   - Primary LED blinks once for 0.1s
   - Shown every 10 beacon data updates to indicate active beaconing
   - Available on all platforms with LED support

Button Functionality
====================

Button behavior varies by platform configuration:

Tag Designs (Button Power Control Enabled)
-------------------------------------------

When ``CONFIG_SENSOR_BEACON_BUTTON_POWER_CONTROL`` is enabled (default for ATMBTCSTAG-3405):

1. **Initial State**: Device starts in SoC_off mode when battery is inserted
2. **Turn Device ON**: Press button

   - Device exits SoC_off mode
   - LED blinks 3 times at 0.5s interval
   - Device starts beaconing

3. **During Beaconing**: LED blinks (0.1s on/off) every 10 beacon data updates
4. **Turn Device OFF**: Press button for 2 seconds while beaconing

   - LED blinks 3 times at 0.5s interval
   - Device enters SoC_off mode

EVK Boards (Immediate Beaconing Mode)
--------------------------------------

When ``CONFIG_SENSOR_BEACON_BUTTON_POWER_CONTROL`` is disabled (default for EVK boards):

1. **Initial State**: Device immediately enters beaconing mode after power on
2. **No ON/OFF Control**: Button does not control device power state
3. **During Beaconing**: LED blinks (0.1s on/off) every 10 beacon data updates

Supported Boards
****************

The sensor_beacon application has been tested and verified on the following platforms:

ATM34 Platforms
===============

- **ATMBTCSTAG-3405** - ATM34 Tag Reference Design

  - Button power control enabled by default
  - Dual LED support
  - Sensors: ENS210 (Temp/Humidity), LIS3DH (Accelerometer)
  - Optimized for battery-powered operation with SoC_off support

- **ATMEVK-3430e-YQN-5** - ATM34 Evaluation Kit
- **ATMEVK-3405-PBV-5** - ATM34 Evaluation Kit
- **ATMEVK-3405-PQK-5** - ATM34 Evaluation Kit
- **ATMEVK-3405-WQK-5** - ATM34 Evaluation Kit
- **ATMEVK-3405-YBV-5** - ATM34 Evaluation Kit

  - Immediate beaconing mode (no button power control)
  - LED support for beacon status indication
  - Sensors: ENS210 (Temp/Humidity), LIS2DH12 (Accelerometer)
  - Suitable for development and testing

ATM33 Platforms
===============

- **ATMEVK-3330e-QN-6** - ATM33 Evaluation Kit (Planned)
- **ATMEVK-3330e-QN-7** - ATM33 Evaluation Kit (Planned)

  - Immediate beaconing mode (no button power control)
  - LED support for beacon status indication
  - Sensors: ENS210 (Temp/Humidity), LIS2DH12 (Accelerometer)
  - Suitable for development and testing

All supported platforms use the same sensor set for consistent data collection across different hardware configurations.

Compatibility
*************

- **Data Format**: Uses standardized sensor beacon data format
- **Advertisement Structure**: Standard Bluetooth beacon format with manufacturer data
- **Client Applications**: Compatible with Atmosic sensor beacon clients (receive-only)
- **Mobile Apps**: Works with any BLE scanner or beacon monitoring application

.. note::
   Client applications must operate in **receive-only mode** since the beacon does not accept connections.

Dependencies
************

**Required Hardware:**

- ENS210 temperature/humidity sensor
- LIS2DH accelerometer
Ensure that the appropriate jumper (JP25) is installed to enable the sensor subsystem. Refer to the EVK's user guide for additional details.
