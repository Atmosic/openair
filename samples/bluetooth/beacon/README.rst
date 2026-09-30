.. _beacon-sample:

Bluetooth: beacon
#################

Overview
********

This application demonstrates the Bluetooth LE Beacon functionality.
For more details, refer to ``zephyr/samples/bluetooth/beacon/README.rst``.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/beacon``.
The source code can be found under ``zephyr/samples/bluetooth/beacon``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/bluetooth/beacon --sysbuild -T samples.bluetooth.beacon.atm

Flash command:

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> --jlink [--erase_flash]
