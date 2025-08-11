.. _hello_world-sample:

Basic: Hello World
##################

Overview
********

A simple application to build the hello world sample

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/hello_world``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD>//ns openair/samples/hello_world --sysbuild -T samples.hello_world.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]
