.. _hci_uart-sample:

Bluetooth: hci_uart
###################

Overview
********

This sample application exposes the Bluetooth controller over UART to another device using the HCI transport protocol.

For additional information please see `HCI UART <https://docs.zephyrproject.org/latest/samples/bluetooth/hci_uart/README.html>`_.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Default UART settings
*********************

By default the builds use ``uart0`` with the following settings:

**ATM2/ATM3:**

* Baudrate: 460800 bit/s
* Hardware Flow Control (RTS/CTS) enabled

**ATM33/ATM34:**

* Baudrate: 2 Mbit/s
* Hardware Flow Control (RTS/CTS) enabled

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/hci_uart``.

Build Command:

.. code-block:: bash

    west build -p always -b <board>//ns openair/samples/bluetooth/hci_uart --sysbuild -T samples.bluetooth.hci_uart.atm

Flash command:

.. code-block:: bash

    west flash --skip-rebuild --device <serial> --jlink --fast_laod [--erase_flash]
