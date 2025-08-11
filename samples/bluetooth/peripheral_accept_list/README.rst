.. _peripheral_accept_list-sample:

Bluetooth: peripheral_accept_list
#################################

Overview
********

This application demonstrates the Bluetooth LE advertising accept filter list feature.
For more details, refer to ``zephyr/samples/bluetooth/peripheral_accept_list/README.rst``.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/peripheral_accept_list``.
The source code can be found under ``zephyr/samples/bluetooth/peripheral_accept_list``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD>//ns openair/samples/bluetooth/peripheral_accept_list --sysbuild -T samples.bluetooth.peripheral_accept_list.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]
