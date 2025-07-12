.. _hci_vendor:

Bluetooth: hci_vendor
#####################

Overview
********

Expose the Zephyr Bluetooth controller support over UART to another device/CPU
using the H:4 HCI transport protocol (requires HW flow control from the UART).

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Default UART(UART0) Settings
****************************

* ATM2 and ATM3 series baudrate: 460800 bit/s
* ATM33/e and ATM34/e series baudrate: 2000000 bit/s
* 8 bits, no parity, 1 stop bit
* Hardware Flow Control (RTS/CTS) enabled

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/hci_vendor``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD>//ns openair/samples/bluetooth/hci_vendor --sysbuild -T samples.bluetooth.hci_vendor.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]


Debug log(UART1)
****************

By default, the log feature is enabled via the prj.conf file.

* The default baud rate is 115200.
* 8 bits, no parity, 1 stop bit
* Hardware Flow Control (RTS/CTS) disabled
* The default UART1-TX pin for ATM2 and ATM3 series is P33.
* The default UART1-TX pin for ATM33/e and ATM34/e series is P27.

You can monitor the console output using your preferred terminal program.
