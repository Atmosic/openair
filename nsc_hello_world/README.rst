.. _nsc_hello_world:

NSC Hello World
###############

Overview
********

Application demonstrating how to extend the secure processing environment with
arbitrary non-secure callable functions.

Building and Running
********************

This sample relies on building the SPE with `CONFIG_ATM_ENABLE_NSC_EXAMPLE=y`
which will compile an additional function into the SPE and provide a NS
gateway for the non-secure application to call into it.

Sample Output
=============

.. code-block:: console

    Hello from Secure World! atm33_evk

