.. _peripheral_dis-sample:

Bluetooth: Peripheral DIS
#########################

Overview
********

This application demonstrates the Bluetooth LE Peripheral role while exposing
the Device Information Service (DIS) over GATT.

For more details, refer to
``zephyr/samples/bluetooth/peripheral_dis/README.rst``.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/peripheral_dis``.
The source code can be found under ``zephyr/samples/bluetooth/peripheral_dis``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/bluetooth/peripheral_dis --sysbuild -T samples.bluetooth.peripheral_dis.atm

Flash command:

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]