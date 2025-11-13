.. _usb-uart-click:

USB UART Click
##############

Overview
********

The USB UART Click board features the FT232RL, a USB to serial UART bridge from FTDI.  It communicates with the ATM3405 SoC via the UART interface.

Product page URL: https://www.mikroe.com/usb-uart-click

Building and Running
********************

 * Sample Application: ``openair/applications/multimode_consumer_tag``

   - By default, the Atmosic serial uart debug console outputs to UART1. This example, along with the changes below, will route the debug console to output to UART0, which is routed to the USB UART Click board.

 * Changes to ``openair/boards/atmosic/atm34evk/ATMBTCSTAG-3405.dts``

   - Change the console to UART0

     .. code-block:: bash

         model = "Atmosic BT CS Tag 3405";
         compatible = "atmosic,ATMBTCSTAG_3405";

         chosen {
             zephyr,console = &uart0;
             zephyr,shell-uart = &uart1;
             zephyr,uart-mcumgr = &uart0;

   - Enable UART0 by adding ``status = "okay";``

     .. code-block:: bash

         &uart0 {
             rx-pin = <30>;
             tx-pin = <15>;
             rts-pin = <13>;
             cts-pin = <12>;
             status = "okay";
         };

 * Build/Flash command using sysbuild:

   .. code-block:: bash

       west build -p always -b ATMBTCSTAG-3405 openair/applications/multimode_consumer_tag --sysbuild -T applications.multimode_consumer_tag.atm

       west flash --skip-rebuild --verify --dl --device <DEVICE_ID> --fast_load --erase_all

 * Expected result:

   The ATM3405 Tag debug output will be displayed on the serial terminal connected to the USB UART Click serial console.
