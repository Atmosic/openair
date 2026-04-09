.. _peripheral_hr-sample:

Bluetooth: Peripheral HR
########################

Overview
********

This application demonstrates the Bluetooth LE Peripheral role while exposing a
Heart Rate service and generating dummy heart-rate measurements.

For more details, refer to
``zephyr/samples/bluetooth/peripheral_hr/README.rst``.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/peripheral_hr``.
The source code can be found under ``zephyr/samples/bluetooth/peripheral_hr``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/bluetooth/peripheral_hr --sysbuild -T samples.bluetooth.peripheral_hr.atm

Flash command:

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]

Testing notes
*************

This sample is a convenient counterpart for
``openair/samples/bluetooth/central_hr``.