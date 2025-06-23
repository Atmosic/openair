.. _nsc_hello_world:

Basic: NSC Hello World
######################

Overview
********

Application demonstrating how to extend the secure processing environment with
arbitrary non-secure callable functions.

Building and Running
********************

This sample relies on building the SPE with `CONFIG_ATM_ENABLE_NSC_EXAMPLE=y`
which will compile an additional function into the SPE and provide a NS
gateway for the non-secure application to call into it.


This sample is built from ``openair/samples/nsc_hello_world``.

Build command:

.. code-block:: bash

   west build -p always -b <board>//ns openair/samples/nsc_hello_world --sysbuild -T samples.nsc_hello_world.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <serial> --jlink --fast_load [--erase_flash]

Sample Output
=============

.. code-block:: console

    Hello from Secure World! atm33_evk

