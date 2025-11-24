.. _periodic_adv_rsp-sample:

Bluetooth: Periodic Advertising with Responses (PAwR) Advertiser
################################################################

Overview
********

A Bluetooth LE Periodic Advertising with Responses (PAwR) Advertiser sample that
demonstrates advanced GAP Broadcaster role functionality. This sample implements
the advertiser side of the PAwR protocol, which enables bidirectional communication
between an advertiser and multiple synchronized devices through periodic advertising
with response slots.

The application creates a PAwR advertiser that:

- Broadcasts periodic advertising data with multiple subevents
- Accepts responses from synchronized devices in designated response slots
- Manages connection-based device onboarding for sync configuration
- Assigns unique subevent and response slot combinations to each synchronized device
- Handles up to 25 synchronized devices (5 subevents × 5 response slots)

Protocol Flow
=============

1. **Advertising Setup**: Creates extended advertising set with periodic advertising parameters
2. **Device Discovery**: Scans for and connects to "PAwR sync sample" devices
3. **Sync Transfer**: Uses Periodic Advertising Sync Transfer (PAST) to share sync information
4. **Configuration**: Writes subevent and response slot assignments via GATT
5. **Response Handling**: Receives and processes responses from synchronized devices
6. **Data Updates**: Continuously updates advertising data with incrementing counter

The advertising data contains manufacturer-specific data with an incrementing counter
that changes for each subevent, allowing synchronized devices to verify proper
reception and timing.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

The controller must support:

- Bluetooth LE Extended Advertising
- Periodic Advertising with Responses (PAwR) - Advertiser feature
- Periodic Advertising Sync Transfer (PAST)
- GATT Client functionality

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/periodic_adv_rsp``.

Build command:

.. code-block:: bash

   west build -p always -b <board> openair/samples/bluetooth/periodic_adv_rsp --sysbuild -T samples.bluetooth.periodic_adv_rsp.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <serial> --jlink --fast_load [--erase_flash]

Sample Output
*************

Upon successful startup, you should see output similar to:

.. code-block:: console

   Starting Periodic Advertising Demo
   Start Periodic Advertising
   Start Extended Advertising
   Scanning successfully started
   Connected (err 0x00)
   PAST sent
   Discovery started
   Characteristic handle: 15
   Write started
   PAwR config written to sync 0, disconnecting
   Disconnected, reason 0x16 Connection terminated by local host
   Subevent data set 1
   Response: subevent 0, slot 0
       0xFF: 5900XX
   Subevent data set 2
   Response: subevent 0, slot 0
       0xFF: 5900XX

The output shows:

- Successful advertising and scanning initialization
- Connection establishment with sync devices
- PAST (Periodic Advertising Sync Transfer) completion
- GATT characteristic discovery and configuration write
- Subevent data updates with incrementing counter
- Response reception from synchronized devices

Output Format
=============

**Subevent Data**: Shows when advertising data is updated with format "Subevent data set X"
where X is the incrementing counter value.

**Response Data**: Displays responses from synchronized devices with:

- ``subevent``: The subevent number (0-4) where the response was received
- ``slot``: The response slot number (0-4) within the subevent
- ``0xFF``: Manufacturer-specific data type
- ``5900XX``: Company ID (0x0059) followed by response data

Configuration Options
*********************

PAwR Parameters
===============

The sample uses the following key configuration parameters:

.. code-block:: c

   #define NUM_RSP_SLOTS 5        // Number of response slots per subevent
   #define NUM_SUBEVENTS 5        // Number of subevents per periodic interval
   #define PACKET_SIZE   5        // Size of advertising data packet

   static const struct bt_le_per_adv_param per_adv_params = {
       .interval_min = 0xFF,              // ~319ms periodic interval
       .interval_max = 0xFF,              // ~319ms periodic interval
       .num_subevents = NUM_SUBEVENTS,    // 5 subevents
       .subevent_interval = 0x30,         // 60ms between subevents
       .response_slot_delay = 0x5,        // 6.25ms delay before first response slot
       .response_slot_spacing = 0x50,     // 100ms between response slots
       .num_response_slots = NUM_RSP_SLOTS, // 5 response slots per subevent
   };

Bluetooth Configuration
=======================

Required Kconfig options (automatically set):

.. code-block:: kconfig

   CONFIG_BT=y
   CONFIG_BT_BROADCASTER=y
   CONFIG_BT_EXT_ADV=y
   CONFIG_BT_PER_ADV=y
   CONFIG_BT_PER_ADV_RSP=y
   CONFIG_BT_CENTRAL=y
   CONFIG_BT_PER_ADV_SYNC_TRANSFER_SENDER=y
   CONFIG_BT_REMOTE_INFO=y
   CONFIG_BT_GATT_CLIENT=y

Device Capacity
===============

The sample supports up to **25 synchronized devices** (NUM_SUBEVENTS × NUM_RSP_SLOTS).
Each device is assigned a unique combination of:

- **Subevent**: 0-4 (which periodic advertising subevent to listen to)
- **Response Slot**: 0-4 (which response slot within the subevent to use)

Assignment follows the pattern: device N gets subevent (N % 5) and response slot (N / 5).

Testing
*******

To test the PAwR advertiser functionality:

1. **Build and flash this sample** to one Atmosic EVK
2. **Build and flash the periodic_sync_rsp sample** to one or more additional EVKs
3. **Power on the advertiser first** - it will start advertising and scanning
4. **Power on sync devices** - they should be discovered and configured automatically
5. **Observe the console output** for connection establishment, PAST transfer, and response reception

Expected Behavior
=================

1. **Advertiser starts** periodic advertising and scans for sync devices
2. **Sync devices connect** and receive periodic advertising sync information via PAST
3. **Each sync device** is assigned a unique subevent/response slot combination
4. **Sync devices disconnect** after configuration and begin synchronized operation
5. **Responses are received** from sync devices in their assigned slots
6. **Data counter increments** continuously, visible in both advertising data and responses

The advertiser will continue running indefinitely, handling responses from all
synchronized devices and updating advertising data with each periodic interval.

Troubleshooting
***************

**No devices found during scanning:**

- Ensure sync devices are running the "PAwR sync sample" with correct device name
- Check that sync devices are advertising as connectable
- Verify Bluetooth is properly initialized on both devices

**PAST transfer fails:**

- Confirm controller supports Periodic Advertising Sync Transfer
- Check that connection is established before attempting PAST
- Verify remote device info is available before transfer

**No responses received:**

- Ensure sync devices are properly synchronized to periodic advertising
- Check that response slot timing is correctly configured
- Verify sync devices are transmitting in their assigned slots

**GATT operations fail:**

- Confirm sync devices implement the required GATT characteristic
- Check that the characteristic UUID matches between advertiser and sync devices
- Verify GATT client functionality is enabled

Related Samples
***************

- :ref:`periodic_sync_rsp-sample` - Complementary sync device sample
- :ref:`periodic_adv_conn-sample` - PAwR connection procedure sample
- :ref:`periodic_adv-sample` - Basic periodic advertising sample
- :ref:`broadcaster-sample` - Basic advertising sample
