.. _peripheral:

Bluetooth: peripheral
#####################

Overview
********

This application demonstrates the basic Bluetooth LE Peripheral role functionality.
For more details, refer to ``zephyr/samples/bluetooth/peripheral/README.rst``.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/peripheral``.
The source code can be found under ``zephyr/samples/bluetooth/peripheral``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD>//ns openair/samples/bluetooth/peripheral --sysbuild -T samples.bluetooth.peripheral.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]
