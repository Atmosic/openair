.. _uart_passthrough:

Drivers: uart_passthrough
#########################

Overview
********

A simple sample that echos what is sent to UART0 over UART1 and what is sent to UART1 over UART0.

For ATM33 EVK's UART1 RX is not always connected to the JLINK-OB.
In order to work around this the UART1 RX pin was changed to P17, while UART1 TX was left as P27.
Both should be connected from the 50 pin header to an external USB to Serial adapter.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>
USB to Serial adapter

Building and Running
********************

This sample is built from ``openair/samples/drivers/uart/uart_passthrough``.

Build command:

.. code-block:: bash

    west build -p always -b ${BOARD}//ns openair/samples/drivers/uart/uart_passthrough --sysbuild -T samples.drivers.uart.uart_passthrough

Flash command:

.. code-block:: bash

    west flash --skip-rebuild --device <serial> --jlink [--fast_load]
