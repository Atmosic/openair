.. _periodic_sync_conn-sample:

Bluetooth: Periodic Advertising Connection Procedure (Responder)
#################################################################

Overview
********

A Bluetooth LE Periodic Advertising Connection Procedure responder sample that
demonstrates the synchronizer/responder side of the connection establishment protocol.
This sample implements a device that synchronizes to periodic advertising with responses
(PAwR) and responds with its address to enable the advertiser to initiate a connection.

The application creates a PAwR synchronized device that:

- Scans for and synchronizes to periodic advertising from "PAwR conn sample" devices
- Listens to specific subevents in the periodic advertising train
- Responds with its own Bluetooth address in designated response slots
- Accepts incoming connections from the advertiser
- Disconnects and waits for reconnection in a continuous loop

This sample demonstrates the **responder/synchronizer** role in the Periodic Advertising
Connection Procedure, working in conjunction with the periodic_adv_conn sample which
implements the advertiser/initiator role.

Protocol Flow
=============

1. **Initialization**: Enables Bluetooth and registers scan and sync callbacks
2. **Scanning**: Actively scans for "PAwR conn sample" periodic advertisers
3. **Discovery**: Detects periodic advertising and captures advertiser address and SID
4. **Sync Creation**: Creates periodic advertising sync to the discovered advertiser
5. **Synchronization**: Establishes sync and subscribes to subevent 0
6. **Response**: Sends own address in response slot 0 when receiving subevent data
7. **Connection**: Accepts incoming connection from the advertiser
8. **Disconnection**: Disconnects and returns to waiting for next connection
9. **Loop**: Repeats connection/disconnection cycle indefinitely

The sample only responds with its address when not already connected, preventing
multiple simultaneous connection attempts.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

The controller must support:

- Bluetooth LE 5.4+ support
- Extended Advertising
- Periodic Advertising Synchronization
- Periodic Advertising with Responses (PAwR) - Scanner feature
- Peripheral role capability
- Privacy and Security Manager Protocol (SMP)

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/periodic_sync_conn``.

Build command:

.. code-block:: bash

   west build -p always -b <board> openair/samples/bluetooth/periodic_sync_conn --sysbuild -T samples.bluetooth.periodic_sync_conn.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <serial> --jlink --fast_load [--erase_flash]

Sample Output
*************

Upon successful startup and synchronization, you should see output similar to:

.. code-block:: console

   Starting Periodic Advertising with Responses Synchronization Demo
   Found periodic advertising.
   Creating Periodic Advertising Sync
   Waiting for periodic sync
   Synced to XX:XX:XX:XX:XX:XX (random) with 5 subevents
   Periodic sync established.
   Stopped scanning
   Responding with own addr: YY:YY:YY:YY:YY:YY (random)
   Connected (err 0x00)
   Disconnecting
   Disconnected, reason 0x16 Connection terminated by local host
   Responding with own addr: YY:YY:YY:YY:YY:YY (random)
   Connected (err 0x00)
   Disconnecting
   Disconnected, reason 0x16 Connection terminated by local host

The output shows:

- Successful scanning and periodic advertising discovery
- Periodic advertising sync establishment
- Continuous response transmission with device address
- Connection establishment and disconnection cycles
- Automatic reconnection capability

Output Format
=============

**Sync Information**: Shows the advertiser's address and number of available subevents.

**Response Data**: Displays the device's own address being sent in response:

- Address format: ``XX:XX:XX:XX:XX:XX (random)`` or ``(public)``
- Sent as BT_DATA_LE_BT_DEVICE_ADDRESS type
- Transmitted in response slot 0 of subevent 0

**Connection Events**: Shows connection establishment and disconnection with reason codes.

Configuration Options
*********************

Sync Parameters
===============

The sample configures periodic advertising sync with:

.. code-block:: c

   struct bt_le_per_adv_sync_param sync_create_param = {
       .addr = per_addr,           // Advertiser address from scan
       .sid = per_sid,             // Advertising set ID from scan
       .options = 0,               // No special options
       .skip = 0,                  // Don't skip any periodic events
       .timeout = 0xaa             // Sync timeout (1.7 seconds)
   };

Subevent Selection
==================

The sample synchronizes to subevent 0:

.. code-block:: c

   struct bt_le_per_adv_sync_subevent_params params = {
       .properties = 0,
       .num_subevents = 1,
       .subevents = {0}            // Listen to subevent 0 only
   };

Response Parameters
===================

The sample responds in slot 0 with its own address:

.. code-block:: c

   struct bt_le_per_adv_response_params rsp_params = {
       .request_event = info->periodic_event_counter,
       .request_subevent = info->subevent,
       .response_subevent = info->subevent,
       .response_slot = 0          // Always respond in slot 0
   };

Response Data Format
====================

The response contains the device's Bluetooth address in OOB format:

.. code-block:: c

   // Response buffer structure:
   // [Length] [Type] [Address (6 bytes)] [Address Type]
   net_buf_simple_add_u8(&rsp_buf, sizeof(bt_addr_le_t));
   net_buf_simple_add_u8(&rsp_buf, BT_DATA_LE_BT_DEVICE_ADDRESS);
   net_buf_simple_add_mem(&rsp_buf, &oob.addr.a, sizeof(oob.addr.a));
   net_buf_simple_add_u8(&rsp_buf, oob.addr.type);

Bluetooth Configuration
=======================

Required Kconfig options (automatically set):

.. code-block:: kconfig

   CONFIG_BT=y
   CONFIG_BT_OBSERVER=y
   CONFIG_BT_EXT_ADV=y
   CONFIG_BT_PER_ADV_SYNC_TRANSFER_SENDER=y
   CONFIG_BT_PER_ADV_SYNC_TRANSFER_RECEIVER=y
   CONFIG_BT_PER_ADV_SYNC=y
   CONFIG_BT_PER_ADV_SYNC_RSP=y
   CONFIG_BT_PER_ADV_SYNC_BUF_SIZE=247
   CONFIG_BT_MAX_CONN=1
   CONFIG_BT_PERIPHERAL=y
   CONFIG_BT_PRIVACY=y
   CONFIG_BT_SMP=y

Testing
*******

To test the Periodic Advertising Connection Procedure:

1. **Build and flash the periodic_adv_conn sample** to one Atmosic EVK (advertiser)
2. **Build and flash this sample** to another Atmosic EVK (responder)
3. **Power on the advertiser first** - it will start periodic advertising
4. **Power on the responder** - it will scan, sync, and respond with its address
5. **Observe console output** on both devices for sync, response, and connection events

Expected Behavior
=================

1. **Responder scans** for "PAwR conn sample" periodic advertisers
2. **Periodic advertising is discovered** and sync is created
3. **Sync is established** to the advertiser's periodic advertising train
4. **Responder listens** to subevent 0 for advertising data
5. **Responder sends** its address in response slot 0
6. **Advertiser receives** the address and initiates connection
7. **Connection is established** between advertiser and responder
8. **Responder disconnects** after connection is established
9. **Process repeats** - responder continues responding and accepting connections

The responder will continue running indefinitely, accepting connections and
disconnecting in a continuous loop.

Connection Behavior
===================

- **Single Connection**: Only one connection at a time (CONFIG_BT_MAX_CONN=1)
- **No Response When Connected**: Stops responding with address when already connected
- **Automatic Disconnect**: Disconnects immediately after connection establishment
- **Reconnection**: Resumes responding after disconnection to allow new connections

Troubleshooting
***************

**Periodic advertising not found:**

- Ensure the periodic_adv_conn sample is running on the advertiser
- Check that advertiser device name is "PAwR conn sample"
- Verify both devices are in range and RF environment is clear
- Check that scanning is started successfully

**Sync not established:**

- Verify sync timeout is sufficient (default 1.7 seconds)
- Check that periodic advertising is active on advertiser
- Ensure controller supports periodic advertising sync
- Verify advertiser SID and address are correctly captured

**No connection from advertiser:**

- Confirm response data is being sent successfully
- Check that response contains valid address format
- Verify advertiser is listening for responses in slot 0
- Ensure privacy and security settings are compatible

**Connection fails:**

- Check connection parameters are compatible
- Verify peripheral role is supported and enabled
- Ensure sufficient connection resources available
- Check for timing conflicts with periodic advertising

**Immediate disconnection issues:**

- This is expected behavior - sample disconnects immediately after connection
- To maintain connection, modify the code to remove automatic disconnect
- Check disconnect reason codes for unexpected disconnections

**Response transmission fails:**

- Verify response buffer size is sufficient (CONFIG_BT_PER_ADV_SYNC_BUF_SIZE)
- Check that OOB data retrieval succeeds
- Ensure response timing parameters are correctly set
- Confirm controller supports PAwR response feature

Related Samples
***************

- :ref:`periodic_adv_conn-sample` - Complementary PAwR advertiser/initiator sample
- :ref:`periodic_sync_rsp-sample` - PAwR synchronization with data echo
- :ref:`periodic_adv_rsp-sample` - Advanced PAwR advertiser with GATT services
- :ref:`observer-sample` - Basic scanning sample
- :ref:`peripheral` - Basic peripheral sample

