.. _beacon-sample:

Bluetooth: beacon
#################

Overview
********

A simple application demonstrating the GAP Broadcaster role functionality by
advertising an Eddystone URL (the Zephyr website). The beacon sample is
configurable via Kconfig, enabling quick development and testing of beacon
parameters.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample can be found under ``samples/bluetooth/beacon`` in the OpenAir tree.

Build command:

.. code-block:: bash

   west build -p always -b <board>//ns openair/samples/bluetooth/beacon --sysbuild -T samples.bluetooth.beacon.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <serial> --jlink --fast_load [--erase_flash]
