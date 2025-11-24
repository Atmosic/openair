.. _nsc_hello_world:

Basic: NSC Hello World
######################

Overview
********

Application demonstrating how to extend the secure processing environment with
arbitrary non-secure callable functions.

Building and Running
********************

This sample demonstrates how to extend the application with custom non-secure callable (NSC) functions.
The sample is built with `CONFIG_ATM_ENABLE_NSC_EXAMPLE=y` which compiles an additional function
and provides a gateway for the application to call into it.

This sample is built from ``openair/samples/nsc_hello_world``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/nsc_hello_world --sysbuild -T samples.nsc_hello_world.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]

Sample Output
=============

.. code-block:: console

    Hello from Secure World! atm33_evk

