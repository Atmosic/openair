.. _extended-adv-advertiser-sample:

Bluetooth: extended_adv_advertiser
##################################

Overview
********

A simple application demonstrates Bluetooth Extended Advertising in the GAP
Peripheral role: it creates an extended advertising with a user-defined device
name, accepts a single connection, disconnects after a 5-second delay and
then restarts advertising. The basic Bluetooth features and device name are set
via ``zephyr/samples/bluetooth/extended_adv/advertiser/prj.conf``.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/extended_adv/advertiser``.
The source code can be found under ``zephyr/samples/bluetooth/extended_adv/advertiser``.

Build command:

.. code-block:: bash

   west build -p always -b <board>//ns openair/samples/bluetooth/extended_adv/advertiser --sysbuild -T samples.bluetooth.extended_adv.advertiser.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <serial> --jlink --fast_load [--erase_flash]
