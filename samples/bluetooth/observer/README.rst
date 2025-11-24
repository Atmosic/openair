.. _observer-sample:

Bluetooth: observer
###################

Overview
********

A simple application demonstrating Bluetooth Low Energy Observer role functionality.
The application will periodically scan for devices nearby. If any found, prints the
address of the device, the RSSI value, the Advertising type, and the Advertising
data length to the console.

For more details, refer to ``zephyr/samples/bluetooth/observer/README.rst``.

The Observer role is one of the four GAP (Generic Access Profile) roles in Bluetooth
Low Energy:

* **Observer**: Scans for advertising packets but cannot initiate connections
* **Broadcaster**: Sends advertising packets but cannot accept connections
* **Central**: Can scan and initiate connections to peripherals
* **Peripheral**: Advertises and accepts connections from centrals

This sample demonstrates the Observer role by continuously scanning for BLE devices
and displaying information about discovered devices including:

* Device address (MAC address)
* RSSI (Received Signal Strength Indicator) value
* Advertising type (standard, extended, scan response)
* PHY information (1M, 2M, Coded)
* Advertising data payload

If the used Bluetooth Low Energy Controller supports Extended Scanning, the sample
enables extended advertising support to receive larger advertising payloads and
additional PHY options.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/observer``.
The source code can be found under ``zephyr/samples/bluetooth/observer``.

Build command:

.. code-block:: bash

   west build -p always -b <board> openair/samples/bluetooth/observer --sysbuild -T samples.bluetooth.observer.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <serial> --jlink --fast_load [--erase_flash]

Sample Output
*************

The sample will start scanning and display discovered devices:

.. code-block:: console

   Starting Observer Demo
   Scanning...
   RSSI  -45 phy 1/0 Adv from 001122334455: 02 01 06 03 03 12 18 09 09 4d 79 44 65 76 69 63 65
   RSSI  -52 phy 1/0 Scan Rsp from 001122334455: 0c 09 4d 79 20 44 65 76 69 63 65 20 4e 61 6d 65
   RSSI  -38 phy 1/0 Ext Adv from aabbccddeeff: 02 01 1a 03 03 0f 18 11 07 12 34 56 78 9a bc de f0

Output Format
*************

Each line of output contains the following information:

* **RSSI**: Signal strength in dBm (negative values, closer to 0 means stronger signal)
* **phy**: Primary PHY / Secondary PHY (1=1M, 2=2M, 4=Coded)
* **Type**:

  * ``Adv from``: Standard advertising packet
  * ``Ext Adv from``: Extended advertising packet
  * ``Scan Rsp from``: Scan response packet
  * ``Ext Scan Rsp from``: Extended scan response packet

* **Address**: 6-byte Bluetooth device address in hexadecimal
* **Data**: Advertising data payload in hexadecimal format

Configuration Options
*********************

The sample supports several configuration options:

Extended Advertising Support
============================

Extended advertising is enabled by default to support:

* Larger advertising payloads (up to 1650 bytes vs 31 bytes for legacy)
* Additional PHY options (1M, 2M, Coded PHY)
* Improved coexistence with other 2.4GHz protocols

This is configured in ``prj.conf``:

.. code-block:: kconfig

   CONFIG_BT_EXT_ADV=y
   CONFIG_BT_EXT_SCAN_BUF_SIZE=1650
   CONFIG_BT_BUF_EVT_RX_COUNT=16

RSSI Filtering
==============

The Atmosic-specific implementation includes RSSI filtering to reduce noise
from weak signals. This can be configured via:

.. code-block:: kconfig

   CONFIG_ATM_SCAN_MINIMUM_RSSI=-70

Only devices with RSSI above this threshold will be displayed.

Scan Parameters
===============

The sample uses active scanning with fast scan parameters for quick device discovery:

* **Scan Type**: Active (sends scan requests to get scan response data)
* **Scan Interval**: 48 slots (30ms) - how often to scan
* **Scan Window**: 18 slots (11.25ms) - how long to scan each interval

These provide a good balance between discovery speed and power consumption.

Testing
*******

To test this sample:

1. Build and flash the observer sample to your Atmosic EVK
2. Use another BLE device (smartphone, another EVK with broadcaster sample, etc.) to advertise
3. The observer will display information about discovered advertising devices
4. Move devices closer/farther to see RSSI values change
5. Try different advertising types (connectable, non-connectable, extended) to see different output formats

You can use the :ref:`broadcaster-sample` on another Atmosic EVK to generate
advertising packets for testing.

Troubleshooting
***************

**No devices discovered:**

* Check that other BLE devices are advertising nearby
* Verify RSSI threshold is not too high (try -80 dBm or lower)
* Ensure Bluetooth is enabled on test devices

**Incomplete advertising data:**

* Some devices may use scan response packets for complete data
* Extended advertising may be needed for larger payloads
* Check that ``CONFIG_BT_EXT_ADV=y`` is enabled

**Build errors:**

* Ensure Bluetooth is supported on your board configuration
* Check that all required Kconfig options are enabled
* Verify Zephyr and OpenAir SDK versions are compatible

Related Samples
***************

* :ref:`broadcaster-sample` - Complementary sample that sends advertising packets
* :ref:`beacon-sample` - Sends Eddystone URL beacons
* :ref:`extended-adv-scanner-sample` - Advanced scanning with connection capabilities
