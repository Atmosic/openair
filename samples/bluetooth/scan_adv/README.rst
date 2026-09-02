.. _scan_adv-sample:

Bluetooth: Scan & Advertise
###########################

Overview
********

This application demonstrates combined Bluetooth LE scanning and advertising.
It scans for nearby devices while periodically advertising manufacturer data.

For more details, refer to ``zephyr/samples/bluetooth/scan_adv/README.rst``.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/scan_adv``.
The source code can be found under ``zephyr/samples/bluetooth/scan_adv``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/bluetooth/scan_adv --sysbuild -T samples.bluetooth.scan_adv.atm

Flash command:

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> --jlink [--erase_flash]

Optional variant
****************

To build the HCI dump variant used by automated testing, use:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/bluetooth/scan_adv --sysbuild -T samples.bluetooth.scan_adv.atm.dump_hci