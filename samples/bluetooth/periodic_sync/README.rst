.. _periodic_sync-sample:

Bluetooth: Periodic Sync
########################

Overview
********

This application demonstrates Bluetooth LE Periodic Advertising
Synchronization. It scans for a device that is transmitting periodic
advertising, establishes synchronization, and prints received periodic data.

For more details, refer to
``zephyr/samples/bluetooth/periodic_sync/README.rst``.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/periodic_sync``.
The source code can be found under ``zephyr/samples/bluetooth/periodic_sync``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/bluetooth/periodic_sync --sysbuild -T samples.bluetooth.periodic_sync.atm

Flash command:

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> --jlink [--erase_flash]

Testing notes
*************

Use this sample together with ``openair/samples/bluetooth/periodic_adv`` on a
second device so the synchronizing device has a periodic advertiser to follow.