.. _uart_passthrough:

UART Passthrough
################

Overview
********

A simple sample that echos what is sent to UART0 over UART1 and what is sent to UART1 over UART0.

For ATM33 EVK's UART1 RX is not always connected to the JLINK-OB.
In order to work around this the UART1 RX pin was changed to P17, while UART1 TX was left as P27.
Both were connected from the 50 pin header to an external USB to Serial board.
