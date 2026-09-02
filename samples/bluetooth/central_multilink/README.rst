.. _central_multilink-sample:

Bluetooth: Central Multilink
############################

Overview
********

A simple application demonstrating Bluetooth Low Energy Central role functionality
by scanning for other Bluetooth LE devices and establishing connections to multiple
peripherals with a strong enough signal.

This sample demonstrates the ability to connect to multiple peripheral devices
simultaneously. The Zephyr version supports up to 62 connections, but the Atmosic
platform configuration limits this to 2 connections for testing purposes.

For more details, refer to ``zephyr/samples/bluetooth/central_multilink/README.rst``.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/central_multilink``.
The source code can be found under ``zephyr/samples/bluetooth/central_multilink``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/bluetooth/central_multilink --sysbuild -T samples.bluetooth.central_multilink.atm

Flash command:

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> --jlink [--erase_all]

Configuration
*************

The Atmosic platform configuration (``atm.conf``) limits the maximum number of
connections to 2, which is more suitable for testing on Atmosic hardware:

.. code-block:: kconfig

   CONFIG_BT_MAX_CONN=2

This overrides the default Zephyr configuration which allows up to 62 connections.
