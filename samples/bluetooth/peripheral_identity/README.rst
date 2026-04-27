.. _peripheral_identity-sample:

Bluetooth: Peripheral Identity
##############################

Overview
********

This application demonstrates the Bluetooth LE Peripheral role with multiple
Bluetooth identities, allowing connections from multiple central devices.

For more details, refer to
``zephyr/samples/bluetooth/peripheral_identity/README.rst``.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/peripheral_identity``.
The source code can be found under
``zephyr/samples/bluetooth/peripheral_identity``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/bluetooth/peripheral_identity --sysbuild -T samples.bluetooth.peripheral_identity.atm

Flash command:

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]

Configuration
*************

This OpenAir wrapper provides an ``atm.conf`` file that lowers
``CONFIG_BT_MAX_CONN`` to ``32`` to fit Atmosic platform RAM constraints.