.. _periodic_adv_conn-sample:

Bluetooth: periodic_adv_conn
############################

Overview
********

A simple application demonstrating the initiator side of the Bluetooth LE
Periodic Advertising Connection Procedure. This sample implements the Periodic
Advertising with Responses (PAwR) advertiser functionality and can establish
connections to synchronized devices.

For more details, refer to ``zephyr/samples/bluetooth/periodic_adv_conn/README.rst``.

The Periodic Advertising Connection Procedure is an advanced Bluetooth LE 5.4+
feature that allows devices to:

* **Advertise periodically** with structured subevents and response slots
* **Receive responses** from synchronized devices during specific time slots
* **Initiate connections** to responding devices using connection procedure
* **Coordinate multiple devices** through subevent and response slot assignment

This sample demonstrates the **initiator/advertiser** role by:

1. **Starting periodic advertising** with multiple subevents and response slots
2. **Listening for responses** from synchronized devices in designated slots
3. **Parsing device addresses** from response data
4. **Initiating connections** to responding devices using the synced connection procedure
5. **Managing connections** and allowing reconnection after disconnect

The sample works in conjunction with the :ref:`periodic-sync-conn-sample` which
implements the responder/synchronizer side of the procedure.

Key Features
************

**Periodic Advertising with Responses (PAwR)**
  - Configurable number of subevents (5 by default)
  - Multiple response slots per subevent (5 by default)
  - Structured timing for coordinated communication
  - Continuous data transmission with response collection

**Connection Management**
  - Automatic connection initiation to responding devices
  - Single active connection support (connects to one device at a time)
  - Automatic reconnection capability after disconnect
  - Connection parameter optimization for PAwR timing

**Advanced BLE Features**
  - Extended advertising support for larger payloads
  - Privacy and security (SMP) support
  - Periodic advertising sync transfer capability
  - Configurable subevent and response slot parameters

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

**Controller Requirements:**
  - Bluetooth LE 5.4+ support
  - Periodic Advertising with Responses (PAwR) - Advertiser feature
  - Extended advertising support
  - Central role capability

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/periodic_adv_conn``.
The source code can be found under ``zephyr/samples/bluetooth/periodic_adv_conn``.

Build command:

.. code-block:: bash

   west build -p always -b <board> openair/samples/bluetooth/periodic_adv_conn --sysbuild -T samples.bluetooth.periodic_adv_conn.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <serial> --jlink --fast_load [--erase_flash]

Sample Output
*************

The sample will start periodic advertising and display connection events:

.. code-block:: console

   Starting Periodic Advertising Demo
   Start Periodic Advertising
   Connecting to 12:34:56:78:9A:BC (random) in subevent 2
   Connected (err 0x00)
   Disconnected, reason 0x16 Connection Terminated by Local Host
   Connecting to AA:BB:CC:DD:EE:FF (random) in subevent 1
   Connected (err 0x00)
   Disconnected, reason 0x13 Remote User Terminated Connection

Configuration Parameters
************************

The sample uses several key configuration parameters that can be modified:

Subevent Configuration
======================

.. code-block:: c

   #define NUM_SUBEVENTS     5      /* Number of subevents per periodic interval */
   #define SUBEVENT_INTERVAL 0x30   /* Time between subevents (48 * 1.25ms = 60ms) */

Response Slot Configuration
===========================

.. code-block:: c

   #define NUM_RSP_SLOTS     5      /* Number of response slots per subevent */
   #define RESPONSE_SLOT_DELAY   0x5    /* Delay before first response slot */
   #define RESPONSE_SLOT_SPACING 0x50   /* Spacing between response slots */

Periodic Advertising Parameters
===============================

.. code-block:: c

   static const struct bt_le_per_adv_param per_adv_params = {
       .interval_min = 0xFF,        /* Minimum periodic advertising interval */
       .interval_max = 0xFF,        /* Maximum periodic advertising interval */
       .num_subevents = NUM_SUBEVENTS,
       .subevent_interval = SUBEVENT_INTERVAL,
       .response_slot_delay = 0x5,
       .response_slot_spacing = 0x50,
       .num_response_slots = NUM_RSP_SLOTS,
   };

Protocol Flow
*************

1. **Initialization Phase**

   - Initialize Bluetooth subsystem
   - Create extended advertising set (non-connectable)
   - Configure periodic advertising parameters
   - Start periodic advertising with PAwR support

2. **Advertising Phase**

   - Send periodic advertising packets with subevent data
   - Listen for responses in designated response slots
   - Parse received response data for device addresses
   - Maintain continuous periodic advertising

3. **Connection Phase**

   - Detect valid device address in response data
   - Initiate connection using synced connection procedure
   - Establish connection with responding device
   - Handle connection events and disconnections

4. **Reconnection Phase**

   - After disconnect, return to listening for responses
   - Allow connections to different devices
   - Maintain single active connection at a time

Testing
*******

To test this sample you need two Atmosic EVKs:

**Device 1 (Advertiser/Initiator):**

1. Build and flash this ``periodic_adv_conn`` sample
2. The device will start periodic advertising with PAwR
3. Monitor console for connection attempts and status

**Device 2 (Synchronizer/Responder):**

1. Build and flash the ``periodic_sync_conn`` sample
2. The device will synchronize to the periodic advertising
3. It will respond with its address in designated response slots
4. Connection will be established automatically

**Expected Behavior:**

- Device 1 starts periodic advertising
- Device 2 synchronizes and responds with its address
- Device 1 detects the response and initiates connection
- Connection is established between the devices
- After disconnect, the process can repeat

Console Output Analysis
***********************

**Successful Connection:**

.. code-block:: console

   Connecting to 12:34:56:78:9A:BC (random) in subevent 2
   Connected (err 0x00)

**Connection Failure:**

.. code-block:: console

   Failed to initiate connection (err -22)

**Disconnection Events:**

.. code-block:: console

   Disconnected, reason 0x16 Connection Terminated by Local Host
   Disconnected, reason 0x13 Remote User Terminated Connection
   Disconnected, reason 0x08 Connection Timeout

Troubleshooting
***************

**No responses received:**

- Verify that a ``periodic_sync_conn`` device is running nearby
- Check that both devices support PAwR features
- Ensure proper timing configuration matches between devices
- Verify Bluetooth LE 5.4+ controller support

**Connection failures:**

- Check connection parameter compatibility
- Verify privacy and security settings match
- Ensure sufficient connection resources available
- Check for timing conflicts with periodic advertising

**Build errors:**

- Verify controller supports ``CONFIG_BT_PER_ADV_RSP=y``
- Check that ``CONFIG_BT_CENTRAL=y`` is supported
- Ensure extended advertising support is available
- Verify Bluetooth LE 5.4+ feature support

**Performance issues:**

- Adjust subevent interval for timing requirements
- Optimize response slot spacing for multiple devices
- Consider connection interval alignment with PAwR timing
- Monitor for scheduling conflicts

Advanced Configuration
**********************

**Multiple Device Support:**

To support multiple responding devices, modify the response handling:

.. code-block:: c

   /* Increase response slots for more devices */
   #define NUM_RSP_SLOTS 10

   /* Adjust spacing for more response opportunities */
   #define RESPONSE_SLOT_SPACING 0x30

**Custom Connection Parameters:**

.. code-block:: c

   /* Align connection interval with PAwR timing */
   conn_param.interval_min = SUBEVENT_INTERVAL;
   conn_param.interval_max = SUBEVENT_INTERVAL;
   conn_param.latency = 0;
   conn_param.timeout = 400;

**Security Configuration:**

Enable additional security features in ``prj.conf``:

.. code-block:: kconfig

   CONFIG_BT_SMP=y
   CONFIG_BT_PRIVACY=y
   CONFIG_BT_KEYS_OVERWRITE_OLDEST=y

Related Samples
***************

* :ref:`periodic_sync_conn-sample` - Complementary responder/synchronizer sample
* :ref:`periodic_adv-sample` - Basic periodic advertising without responses
* :ref:`periodic_adv_rsp-sample` - Advanced PAwR advertiser with GATT services
* :ref:`observer-sample` - Basic scanning and device discovery
