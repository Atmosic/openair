.. _central_hr-sample:

Bluetooth: Central HR
#####################

Overview
********

This application demonstrates the Bluetooth LE Central role by scanning for a
Heart Rate peripheral, connecting to it, discovering the Heart Rate service,
and subscribing to measurement notifications.

For more details, refer to
``zephyr/samples/bluetooth/central_hr/README.rst``.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/central_hr``.
The source code can be found under ``zephyr/samples/bluetooth/central_hr``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/bluetooth/central_hr --sysbuild -T samples.bluetooth.central_hr.atm

Flash command:

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]

Testing notes
*************

Use this sample together with a Heart Rate peripheral, such as
``openair/samples/bluetooth/peripheral_hr`` or another compatible heart-rate
monitor.