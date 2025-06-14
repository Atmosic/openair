.. broadcaster_multiple-sample:

Bluetooth: broadcaster_multiple
#################################

Overview
********

A simple application demonstrates the use of multiple advertising sets in a
Bluetooth Low Energy Broadcaster.
For more details, refer to ``zephyr/samples/bluetooth/broadcaster_multiple/README.rst``.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample can be found under ``samples/bluetooth/broadcaster_multiple`` in the OpenAir tree.
The source code can be found under ``zephyr/samples/bluetooth/broadcaster_multiple``.

Build command:

.. code-block:: bash

   west build -p always -b <board>//ns openair/samples/bluetooth/broadcaster_multiple --sysbuild -T samples.bluetooth.broadcaster_multiple.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <serial> --jlink --fast_load [--erase_flash]
