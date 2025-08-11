.. _extended-adv-scanner-sample:

Bluetooth: extended_adv_scanner
###############################

Overview
********

A simple application demonstrates Bluetooth Extended Scanning in the GAP Central
role: it continuously scans on the primary and secondary advertising channels,
decodes every extended advertising report it receives, and automatically
initiates a connection to the first advertiser whose “connectable” flag is set.
After the link is detached (or if the connection attempt fails) the application
waits for a 5-second cooldown before restarting next scan.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/extended_adv/scanner``.
The source code can be found under ``zephyr/samples/bluetooth/extended_adv/scanner``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD>//ns openair/samples/bluetooth/extended_adv/scanner --sysbuild -T samples.bluetooth.extended_adv.scanner.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]
