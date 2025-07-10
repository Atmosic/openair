.. _ble_periodic_adv:

Bluetooth: periodic advertising
###############################

Overview
********

This application demonstrates the Bluetooth LE Periodic Advertising functionality.
For more details, refer to ``zephyr/samples/bluetooth/periodic_adv/README.rst``.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/periodic_adv``.
The source code can be found under ``zephyr/samples/bluetooth/periodic_adv``.

Build command:

.. code-block:: bash

   west build -p always -b <board>//ns openair/samples/bluetooth/periodic_adv --sysbuild -T samples.bluetooth.periodic_adv.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <serial> --jlink --fast_load [--erase_flash]
