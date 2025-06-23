.. _smp_svr

Subsys: mgmt_mcumgr_smp_svr
###########################

Overview
********

This sample application implements a Simple Management Protocol (SMP) server.
SMP is a basic transfer encoding for use with the MCUmgr management protocol.
For more information about MCUmgr and SMP, please see `Device Management <https://docs.zephyrproject.org/latest/services/device_mgmt/index.html>`_.

This sample allows for testing of DFU over serial and BLE.
For serial DFU it uses ``zephyr,uart-mcumgr`` in the DTS which is ``uart0`` by default.

For additional information please see `SMP server <https://docs.zephyrproject.org/latest/samples/subsys/mgmt/mcumgr/smp_svr/README.html>`_.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Utility implementing the SMP protocol such as the ``mcumgr`` Go utility, or ``smpmgr`` Python utility.
Alternatively the Atmosic Mobile App can be used for BLE OTA firmware updates.
A larger list of possible utilities can be found here: `MCUmgr tools and libraries <https://docs.zephyrproject.org/latest/services/device_mgmt/mcumgr.html#tools-libraries>`_.

Building and Running
********************

This sample is built from ``openair/samples/subsys/mgmt/mcumgr/smp_svr``.

Build command:

.. code-block:: bash

    west build -p always -b ${BOARD}@mcuboot//ns openair/samples/subsys/mgmt/mcumgr/smp_svr --sysbuild -T samples.subsys.mgmt.mcumgr.smp_svr.atm.mcuboot

Flash command:

.. code-block:: bash

    west flash --skip-rebuild --device <serial> --jlink [--fast_load] [--erase_flash]
