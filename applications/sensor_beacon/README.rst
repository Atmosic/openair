.. _sensor_beacon-application:

Sensor Beacon Application
##########################

A lean Zephyr application that broadcasts onboard sensor data (accelerometer, temperature, humidity) and battery voltage information via Bluetooth beacon advertisements.

Overview
********

The sensor_beacon application is a focused, non-configurable beacon implementation that provides sensor data collection and broadcasting without any runtime configuration or connection support. It is optimized for minimal memory usage, power consumption, and deterministic behavior.

Features
********

- **Sensor Data Collection**: Reads temperature, humidity, and 3-axis accelerometer data
- **Battery Monitoring**: Monitors VStore and VBatt voltages
- **Bluetooth Beacon Advertising**: Broadcasts sensor data using a standardized beacon format
- **Non-Connectable**: Pure beacon mode without BLE connection support
- **Fixed Configuration**: Compile-time configuration only, no runtime changes
- **Periodic Updates**: Configurable interval for sensor data updates
- **Power Management**: Supports Zephyr power management with optimized sleep
- **Memory Optimized**: Minimal flash and RAM usage (220KB flash, 60KB RAM)
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
    │   ├── beacon_adv.c          # Bluetooth beacon advertising (lean)
    │   └── sensor_data.c         # Periodic data collection
    └── tests/                    # Core functionality test suite

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

.. note::
   All configuration is compile-time only. The application does not support runtime configuration or AT commands.

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

The sensor_beacon application uses sysbuild to automatically build both the SPE (Secure Processing Environment) and the application in a single command.

Production Build (Default)
===========================
Optimized for power consumption, performance, and minimal logging:

.. code-block:: bash

    west build -p always -b <BOARD>//ns openair/applications/sensor_beacon --sysbuild -T applications.sensor_beacon.atm

Debug Build
===========
Enhanced logging and debugging aids for development:

.. code-block:: bash

    west build -p always -b <BOARD>//ns openair/applications/sensor_beacon --sysbuild -T applications.sensor_beacon.atm -DFILE_SUFFIX=debug

**Example for ATMEVK-3430e-YQN-5:**

Production:

.. code-block:: bash

    west build -p always -b ATMEVK-3430e-YQN-5//ns openair/applications/sensor_beacon --sysbuild -T applications.sensor_beacon.atm

Debug:

.. code-block:: bash

    west build -p always -b ATMEVK-3430e-YQN-5//ns openair/applications/sensor_beacon --sysbuild -T applications.sensor_beacon.atm -DFILE_SUFFIX=debug

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
| **Memory Usage**  | ~221KB flash, ~60KB RAM   | ~221KB flash, ~60KB RAM |
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

    west build -p always -b <BOARD>//ns openair/applications/sensor_beacon/tests --sysbuild
    west flash --skip-rebuild -d build --verify --device <DEVICE_ID> --jlink --fast_load

**Example:**

.. code-block:: bash

    west build -p always -b ATMEVK-3430e-YQN-5//ns openair/applications/sensor_beacon/tests --sysbuild
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

Compatibility
*************

- **Data Format**: Uses standardized sensor beacon data format
- **Advertisement Structure**: Standard Bluetooth beacon format with manufacturer data
- **Client Applications**: Compatible with Atmosic sensor beacon clients (receive-only)
- **Mobile Apps**: Works with any BLE scanner or beacon monitoring application

.. note::
   Client applications must operate in **receive-only mode** since the beacon does not accept connections. (receive-only)
- **Mobile Apps**: Works with any BLE scanner or beacon monitoring application

.. note::
   Client applications must operate in **receive-only mode** since the beacon does not accept connections.

Dependencies
************

**Required Hardware:**

- ENS210 temperature/humidity sensor
- LIS2DH accelerometer
