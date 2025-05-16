.. _broadcaster-sample:

Bluetooth: broadcaster
#################################

Overview
********

A simple application demonstrating Bluetooth Low Energy Broadcaster role functionality.
For more details, refer to ``zephyr/samples/bluetooth/broadcaster/README.rst``.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample can be found under ``samples/bluetooth/broadcaster`` in the OpenAir tree.
The source code can be found under ``zephyr/samples/bluetooth/broadcaster``.

Build command:

.. code-block:: bash

   west build -p always -b <board>//ns openair/samples/bluetooth/broadcaster --sysbuild -T samples.bluetooth.broadcaster.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <serial> --jlink --fast_load [--erase_flash]
