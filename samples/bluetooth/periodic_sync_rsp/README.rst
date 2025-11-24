.. _periodic_sync_rsp-sample:

Bluetooth: Periodic Advertising with Responses (PAwR) Synchronization
######################################################################

Overview
********

A Bluetooth LE Periodic Advertising with Responses (PAwR) Synchronization sample that
demonstrates the scanner/responder side of the PAwR protocol. This sample implements
a synchronized device that receives periodic advertising data and sends responses back
to the advertiser in designated response slots.

The application creates a PAwR synchronized device that:

- Advertises as a connectable peripheral to be discovered by the PAwR advertiser
- Receives periodic advertising sync information via PAST (Periodic Advertising Sync Transfer)
- Synchronizes to specific subevents based on advertiser assignment
- Echoes received advertising data back to the advertiser in assigned response slots
- Supports multiple concurrent synchronized devices with unique slot assignments

Protocol Flow
=============

1. **Initialization**: Enables Bluetooth and registers periodic advertising sync callbacks
2. **PAST Subscription**: Subscribes to receive periodic advertising sync transfers
3. **Advertising**: Advertises as "PAwR sync sample" to be discovered by the advertiser
4. **Connection**: Accepts connection from the PAwR advertiser
5. **Sync Transfer**: Receives periodic advertising sync information via PAST
6. **Configuration**: Receives subevent and response slot assignment via GATT write
7. **Synchronization**: Synchronizes to the assigned subevent
8. **Response**: Echoes received data back to advertiser in assigned response slot
9. **Disconnection**: Disconnects after configuration and continues synchronized operation

The sample echoes all received advertising data back to the advertiser, allowing
the advertiser to verify bidirectional communication and proper slot timing.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

The controller must support:

- Bluetooth LE Extended Advertising
- Periodic Advertising Synchronization
- Periodic Advertising with Responses (PAwR) - Scanner feature
- Periodic Advertising Sync Transfer (PAST) - Receiver
- GATT Server functionality

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/periodic_sync_rsp``.

Build command:

.. code-block:: bash

   west build -p always -b <board> openair/samples/bluetooth/periodic_sync_rsp --sysbuild -T samples.bluetooth.periodic_sync_rsp.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <serial> --jlink --fast_load [--erase_flash]

Sample Output
*************

Upon successful startup and synchronization, you should see output similar to:

.. code-block:: console

   Starting Periodic Advertising with Responses Synchronization Demo
   Waiting for periodic sync...
   Connected, err 0x00 Success
   Synced to XX:XX:XX:XX:XX:XX (random) with 5 subevents
   Changed sync to subevent 0
   New timing: subevent 0, response slot 0
   Changed sync to subevent 0
   Periodic sync established.
   Indication: subevent 0, responding in slot 0
       0xFF: 5900XX
   Indication: subevent 0, responding in slot 0
       0xFF: 5900XX
   Indication: subevent 0, responding in slot 0
       0xFF: 5900XX

The output shows:

- Successful Bluetooth initialization and PAST subscription
- Connection establishment with the PAwR advertiser
- Periodic advertising sync establishment via PAST
- Subevent and response slot assignment from advertiser
- Continuous reception of advertising data and response transmission
- Echo of received data back to the advertiser

Output Format
=============

**Sync Information**: Shows the advertiser's address and number of available subevents.

**Timing Assignment**: Displays the assigned subevent and response slot numbers received
from the advertiser via GATT write.

**Indication Data**: Shows received advertising data with:

- ``subevent``: The subevent number (0-4) where data was received
- ``slot``: The response slot number (0-4) assigned for responses
- ``0xFF``: Manufacturer-specific data type
- ``5900XX``: Company ID (0x0059) followed by data payload

Configuration Options
*********************

GATT Service
============

The sample implements a custom GATT service for receiving timing configuration:

.. code-block:: c

   // Service UUID: 12345678-1234-5678-1234-56789abcdef0
   // Characteristic UUID: 12345678-1234-5678-1234-56789abcdef1
   
   struct pawr_timing {
       uint8_t subevent;        // Assigned subevent to listen to (0-4)
       uint8_t response_slot;   // Assigned response slot to use (0-4)
   };

The advertiser writes to this characteristic to assign the synchronized device
a unique subevent and response slot combination.

Bluetooth Configuration
=======================

Required Kconfig options (automatically set):

.. code-block:: kconfig

   CONFIG_BT=y
   CONFIG_BT_OBSERVER=y
   CONFIG_BT_BROADCASTER=y
   CONFIG_BT_EXT_ADV=y
   CONFIG_BT_PER_ADV_SYNC=y
   CONFIG_BT_PERIPHERAL=y
   CONFIG_BT_PER_ADV_SYNC_TRANSFER_SENDER=y
   CONFIG_BT_PER_ADV_SYNC_TRANSFER_RECEIVER=y
   CONFIG_BT_PER_ADV_SYNC_RSP=y
   CONFIG_BT_PER_ADV_SYNC_BUF_SIZE=247

PAST Parameters
===============

The sample configures PAST subscription with:

.. code-block:: c

   struct bt_le_per_adv_sync_transfer_param past_param = {
       .skip = 1,                                      // Skip 1 periodic event
       .timeout = 1000,                                // 10 seconds sync timeout
       .options = BT_LE_PER_ADV_SYNC_TRANSFER_OPT_NONE
   };

Response Mechanism
==================

The sample echoes received data back to the advertiser:

1. **Receive**: Data arrives in the assigned subevent
2. **Copy**: Data is copied to response buffer
3. **Configure**: Response parameters specify event counter, subevent, and slot
4. **Transmit**: Response is sent in the assigned response slot

.. code-block:: c

   rsp_params.request_event = info->periodic_event_counter;
   rsp_params.request_subevent = info->subevent;
   rsp_params.response_subevent = info->subevent;
   rsp_params.response_slot = pawr_timing.response_slot;

Testing
*******

To test the PAwR synchronization functionality:

1. **Build and flash the periodic_adv_rsp sample** to one Atmosic EVK (advertiser)
2. **Build and flash this sample** to one or more additional EVKs (sync devices)
3. **Power on the advertiser first** - it will start advertising and scanning
4. **Power on sync devices** - they should be discovered and configured automatically
5. **Observe console output** on both devices for sync establishment and data exchange

Multiple Devices
================

You can flash this sample to multiple devices (up to 25) and they will each:

- Be discovered and connected by the advertiser
- Receive unique subevent and response slot assignments
- Synchronize to their assigned subevents
- Respond in their assigned slots without collision

Expected Behavior
=================

1. **Sync device advertises** as "PAwR sync sample" and waits for connection
2. **Advertiser connects** and transfers periodic advertising sync via PAST
3. **Sync is established** and device receives subevent/slot assignment
4. **Device disconnects** and begins synchronized operation
5. **Data is received** in the assigned subevent
6. **Responses are sent** back to advertiser in the assigned response slot
7. **Process repeats** continuously for each periodic advertising interval

The synchronized device will continue running indefinitely, receiving advertising
data and sending responses in its assigned slot.

Troubleshooting
***************

**Sync not established:**

- Ensure the periodic_adv_rsp sample is running on the advertiser
- Check that advertiser is scanning for "PAwR sync sample" devices
- Verify PAST is supported by both controllers
- Check PAST timeout is sufficient (default 10 seconds)

**No connection from advertiser:**

- Verify device name is set to "PAwR sync sample" (CONFIG_BT_DEVICE_NAME)
- Ensure advertising is started successfully
- Check that advertiser is scanning and connecting to discovered devices

**No data received after sync:**

- Confirm subevent assignment was received via GATT write
- Check that assigned subevent is within valid range (0-4)
- Verify periodic advertising is active on advertiser
- Check sync timeout hasn't expired

**Response transmission fails:**

- Ensure response slot assignment is valid (0-4)
- Verify response buffer size is sufficient (CONFIG_BT_PER_ADV_SYNC_BUF_SIZE)
- Check that response timing parameters are correctly set
- Confirm controller supports PAwR response feature

**Sync lost:**

- Check signal strength and RF environment
- Verify sync timeout is appropriate for use case
- Ensure periodic advertising continues on advertiser
- Check for interference or connection issues

Related Samples
***************

- :ref:`periodic_adv_rsp-sample` - Complementary PAwR advertiser sample
- :ref:`periodic_sync_conn-sample` - Periodic advertising sync with connection
- :ref:`observer-sample` - Basic scanning sample
- :ref:`peripheral-sample` - Basic peripheral sample

