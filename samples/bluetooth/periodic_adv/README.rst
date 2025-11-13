.. _periodic_adv-sample:

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

   west build -p always -b <BOARD> openair/samples/bluetooth/periodic_adv --sysbuild -T samples.bluetooth.periodic_adv.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]
