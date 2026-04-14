.. _sensor_beacon-application:

Sensor Beacon Application
##########################

A Zephyr application that broadcasts onboard sensor data (accelerometer, temperature, humidity) and battery voltage information via Bluetooth beacon advertisements, with BLE connection support for runtime configuration via AT commands.

This application is designed to be used with the **Atmosic DevTools** mobile app to monitor sensor data. It also exposes an AT command interface over BLE GATT for runtime device configuration.

Overview
********

The sensor_beacon application provides sensor data collection and broadcasting via Bluetooth beacon advertisements, together with BLE connection support and an AT command interface for runtime configuration. It uses dual extended advertising sets: a non-connectable set that continuously broadcasts sensor data, and a connectable set that allows a BLE central to connect, authenticate, and issue AT commands over GATT.

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

Features
********

- **Sensor Data Collection**: Reads temperature, humidity, and 3-axis accelerometer data
- **Battery Monitoring**: Monitors VStore and VBatt voltages
- **Bluetooth Beacon Advertising**: Broadcasts sensor data using a standardized beacon format
- **BLE Connection Support**: Accepts connections on a second advertising set and provides GATT services for AT command transport
- **AT Command Interface**: Runtime configuration of device name, advertising interval, and custom advertising data; settings are persisted to NVS flash
- **Periodic Updates**: Configurable interval for sensor data updates
- **Power Management**: Supports Zephyr power management
- **Comprehensive Testing**: Full Ztest test suite included

Architecture
************

The application follows a modular design with clear separation of functionalities::

    sensor_beacon/
    ├── src/
    │   ├── main.c                 # Application entry point; BLE connection callbacks
    │   ├── sensor_beacon.c        # Main application logic and sensor loop
    │   ├── sensor_interface.c     # Sensor reading with scaling
    │   ├── battery_monitor.c      # Battery voltage monitoring
    │   ├── beacon_adv.c           # Dual-set Bluetooth advertising (sensor + connection)
    │   ├── beacon_adv_at_cmd.c    # AT command extensions with NVS persistence
    │   ├── at_gatt.c              # GATT service for AT command transport (TXRX characteristic)
    │   ├── at_cmd_manager.c       # AT command routing and unlock state machine
    │   └── sensor_data.c          # Periodic sensor data collection
    └── tests/                     # Comprehensive test suite

**Dual advertising sets** (both started at boot):

- **Set 0** — Non-connectable extended advertising (SID 0). Carries the full sensor beacon
  payload (Eddystone-URL, Manufacturer Data with sensor readings). Interval: 1–1.2 s normal,
  100–150 ms fast.
- **Set 1** — Connectable extended advertising (SID 1). Carries only Flags + Complete Name.
  Used by a BLE central to connect and interact with the GATT-based AT command interface.
  Interval: slow (``BT_GAP_ADV_SLOW_INT_MIN/MAX``).

Configuration
*************

Key configuration options in ``prj.conf``:

- ``CONFIG_SENSOR_BEACON_UPDATE_INTERVAL``: Update interval in centiseconds (default: 100 = 1s)
- ``CONFIG_SENSOR_BEACON_FAST_ADV``: Enable fast advertising mode for quick device discovery (default: n)
- ``CONFIG_BT_EXT_ADV_MAX_ADV_SET``: Number of extended advertising sets (default: 2 — one sensor beacon set, one connectable set)
- ``CONFIG_ATM_AT_CMD``: Enable AT command framework (default: y)
- ``CONFIG_SETTINGS`` / ``CONFIG_NVS``: Persistent storage for device name and user ad data

Beacon Advertising Intervals
****************************

The application supports two advertising modes (selected by Kconfig):

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

The sensor beacon advertising set (Set 0, non-connectable) uses the following payload:

1. **Flags**: ``BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR``
2. **Complete Name**: Device name (runtime-configurable via ``AT+NAME``; persisted to NVS)
3. **Service UUID**: Eddystone UUID (0xFEAA)
4. **Service Data**: Eddystone-URL pointing to atmosic.com
5. **Manufacturer Data**: Atmosic Company ID (0x0A24) + sensor data
6. **User Data** *(optional)*: Custom TLV element appended when set via ``AT+ADVDATA``

The connectable advertising set (Set 1) carries only:

1. **Flags**: ``BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR``
2. **Complete Name**: Device name

AT Command Interface
********************

The sensor_beacon application includes a BLE GATT-based AT command interface that enables
runtime configuration of the device over a Bluetooth LE connection. This feature is enabled by
default in the production configuration (``prj.conf``).

Prerequisites
=============

AT command support requires the following Kconfig options (all enabled by default in
``prj.conf``):

- ``CONFIG_ATM_AT_CMD=y`` — AT command core framework
- ``CONFIG_ATM_AT_CMD_SET=y`` — Standard AT command set handlers
- ``CONFIG_BT_MAX_CONN=2`` — Allows inbound BLE connections for configuration
- ``CONFIG_SETTINGS=y`` / ``CONFIG_NVS=y`` — Persistent storage for settings

.. note::
   When ``CONFIG_BT_MAX_CONN`` is set to ``2``, the device advertises as **connectable** to
   allow BLE GATT-based configuration in addition to broadcasting beacon data.

GATT Service
============

AT commands are transported over a custom BLE GATT service. Connect to the sensor beacon
device and interact with the TXRX characteristic:

+--------------------+----------------------------------------------------------+
| Attribute          | Details                                                  |
+====================+==========================================================+
| **Service**        | custom 128-bit UUID                                      |
+--------------------+----------------------------------------------------------+
| **Characteristic** | TXRX (custom 128-bit UUID)                               |
|                    | Properties: **Write** + **Notify**                       |
+--------------------+----------------------------------------------------------+

- **Write** the AT command string to the TXRX characteristic to issue a command.
- **Enable notifications** on the TXRX characteristic to receive command responses.

Security — Unlock Mechanism
============================

The device starts in a **locked** state every time a new BLE connection is established.
All configuration commands require the device to be unlocked first using ``AT+UNLOCK``.

**Lock state lifecycle:**

1. Device powers on or resets → starts **locked**
2. New BLE connection established → automatically **re-locked**
3. ``AT+UNLOCK`` with correct key → **unlocked**
4. Configuration commands can now be issued
5. BLE disconnect or device reset → returns to **locked**

Supported AT Commands
=====================

Command Syntax
--------------

AT commands follow the standard format::

    AT+<COMMAND>=<parameter>

The ``AT+`` prefix is case-insensitive.

Command Reference
-----------------

AT+UNLOCK
^^^^^^^^^

Unlocks the device for configuration. **Must be sent before any other configuration command.**

.. code-block:: none

    AT+UNLOCK=<key>

+---------------+----------------------------------+
| Parameter     | Description                      |
+===============+==================================+
| ``<key>``     | Unlock key string (max 31 chars) |
+---------------+----------------------------------+

**Example:**

.. code-block:: none

    AT+UNLOCK=atm1atm123

**Responses:**

- ``OK`` — Device unlocked successfully
- ``ERROR`` — Invalid key or authentication failure

.. note::
   The unlock key is ``atm1atm123``. The device is automatically re-locked on each new BLE
   connection to prevent unauthenticated access.

AT+NAME
^^^^^^^

Sets the BLE device name. The new name is immediately reflected in the advertisement and
persisted to NVS flash so it survives reboot.

.. code-block:: none

    AT+NAME=<device name>

+--------------------+--------------------------------------------------+
| Parameter          | Description                                      |
+====================+==================================================+
| ``<device name>``  | New device name string (1 to 22 characters)      |
+--------------------+--------------------------------------------------+

**Requires:** Device must be unlocked (``AT+UNLOCK`` first).

**Example:**

.. code-block:: none

    AT+NAME=MySensorTag

**Responses:**

- ``OK`` — Device name updated; advertising restarted with the new name
- ``ERROR`` — Device locked, name empty/too long, or write failure

.. note::
   The default device name is ``Atmosic Sensor Beacon``. The maximum length is set by
   ``CONFIG_BT_DEVICE_NAME_MAX`` (default: 22 characters).

AT+ADVINT
^^^^^^^^^

Sets the BLE advertising interval. The new value takes effect immediately and is persisted
to NVS flash.

.. code-block:: none

    AT+ADVINT=<interval>

+------------------+--------------------------------------------------------------+
| Parameter        | Description                                                  |
+==================+==============================================================+
| ``<interval>``   | Advertising interval in units of 0.625 ms.                   |
|                  | Valid range: **400 – 16384** (250 ms to 10.24 s)             |
+------------------+--------------------------------------------------------------+

**Requires:** Device must be unlocked (``AT+UNLOCK`` first).

**Examples:**

.. code-block:: none

    AT+ADVINT=400     # 250 ms  (minimum)
    AT+ADVINT=1600    # 1 second
    AT+ADVINT=3200    # 2 seconds
    AT+ADVINT=16384   # 10.24 seconds (maximum)

**Responses:**

- ``OK`` — Advertising interval updated
- ``ERROR`` — Device locked, value out of range, or write failure

AT+ADVDATA
^^^^^^^^^^

Sets custom user data to be appended to the beacon advertisement. Data must be in
**TLV (Type-Length-Value)** format and is persisted to NVS flash. Sending this command
with empty data clears previously set user data and reverts to sensor-only advertising.

.. code-block:: none

    AT+ADVDATA=<tlv data>

+------------------+------------------------------------------------------------------------+
| Parameter        | Description                                                            |
+==================+========================================================================+
| ``<tlv data>``   | Byte array in TLV format. Maximum **27 bytes** total. First byte is    |
|                  | the length (N); second byte is the type; followed by N−1 payload bytes |
|                  | (maximum 25 bytes of payload).                                         |
+------------------+------------------------------------------------------------------------+

**TLV format layout:**

.. code-block:: none

    +---------+--------+------------------------------+
    | Length  |  Type  |         Payload              |
    | (1 byte)|(1 byte)| (Length - 1 bytes, max 25)   |
    +---------+--------+------------------------------+

- ``Length`` = number of bytes following it (type byte + payload bytes).
- ``Type`` = application-defined data type identifier.
- ``Payload`` = up to 25 bytes of user-defined data.

**Requires:** Device must be unlocked (``AT+UNLOCK`` first).

**Responses:**

- ``OK`` — User data updated; advertising restarted with new payload
- ``ERROR`` — Device locked, invalid TLV format, data too large, or write failure

AT+SYSRESET
^^^^^^^^^^^

Performs a cold system reset of the device.

.. code-block:: none

    AT+SYSRESET=<reason>

+---------------+----------------------------+
| Parameter     | Description                |
+===============+============================+
| ``<reason>``  | Reset reason code (``1``)  |
+---------------+----------------------------+

**Requires:** Device must be unlocked (``AT+UNLOCK`` first).

**Example:**

.. code-block:: none

    AT+SYSRESET=1

**Response:** The device resets immediately; no response is returned to the client.

Persistent Storage
==================

The following settings survive reboot (saved to NVS flash):

+---------------------+------------------+-----------------------------+
| Setting             | AT Command       | NVS Key                     |
+=====================+==================+=============================+
| Device name         | ``AT+NAME``      | ``sensor_beacon/dev_name``  |
+---------------------+------------------+-----------------------------+
| Custom ad data      | ``AT+ADVDATA``   | ``sensor_beacon/user_data`` |
+---------------------+------------------+-----------------------------+

Typical Usage Sequence
======================

.. code-block:: none

    # 1. Connect to the device over BLE
    # 2. Enable GATT notifications on the TXRX characteristic
    # 3. Unlock the device
    AT+UNLOCK=atm1atm123        → OK

    # 4. Change the device name
    AT+NAME=MySensorTag         → OK

    # 5. Set advertising interval to 2 seconds (3200 × 0.625 ms = 2000 ms)
    AT+ADVINT=3200              → OK

    # 6. Reset to apply all changes
    AT+SYSRESET=1               (device resets; reconnect to verify new settings)

Building and Running
********************

This application is built from ``openair/applications/sensor_beacon``.

Production Build (Default)
===========================
Optimized for power consumption, performance, and minimal logging:

.. code-block:: bash

    west build -p always -b <BOARD> openair/applications/sensor_beacon --sysbuild -T applications.sensor_beacon.atm

Production Build with MCUboot + Serial DFU
==========================================
Enables MCUboot and supports firmware upgrades over UART:

.. code-block:: bash

    west build -p always -b <BOARD>@mcuboot openair/applications/sensor_beacon --sysbuild -T applications.sensor_beacon.atm.mcuboot.dfu

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

    west flash --no-rebuild -d build --verify --device <DEVICE_ID> --jlink --fast_load

**Example:**

.. code-block:: bash

    west flash --no-rebuild -d build --verify --device 000900066361 --jlink --fast_load

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
   - BLE advertising behavior (dual advertising sets)
   - Sensor functionality

Testing
*******

To build and run the test suite:

.. code-block:: bash

    west build -p always -b <BOARD> openair/applications/sensor_beacon/tests --sysbuild
    west flash --no-rebuild -d build --verify --device <DEVICE_ID> --jlink --fast_load

**Example:**

.. code-block:: bash

    west build -p always -b ATMEVK-3430e-YQN-5 openair/applications/sensor_beacon/tests --sysbuild
    west flash --no-rebuild -d build --verify --device 000900066361 --jlink --fast_load

The test suite includes:

- Sensor interface validation
- Battery monitoring tests
- Beacon advertising tests (dual advertising sets; user data; device name updates)
- AT command handler tests (unlock, name, interval, advdata, sysreset)
- Data collection integration tests
- Scaling factor verification

Power Management
****************

The application supports Zephyr power management:

- Periodic sensor readings with configurable intervals
- Automatic sleep between operations
- Watchdog integration for reliability

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
2. **Turn Device ON**: Press button for 2 seconds to bring the device out of soc-off mode

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
- **Passive Observers**: Compatible with any BLE scanner or beacon monitoring application (Atmosic DevTools, etc.) — no connection required to receive sensor data
- **BLE Centrals**: Can connect to the device, authenticate via ``AT+UNLOCK``, and issue configuration commands over the GATT TXRX characteristic

Dependencies
************

**Required Hardware:**

- ENS210 temperature/humidity sensor
- LIS2DH accelerometer
Ensure that the appropriate jumper (JP25) is installed to enable the sensor subsystem. Refer to the EVK's user guide for additional details.
