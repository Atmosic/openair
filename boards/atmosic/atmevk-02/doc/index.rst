.. _atmevk-02:

###############
Atmosic ATMx2xx
###############

********
Overview
********

The ATM2/ATM3 Wireless SoC Series is part of the Atmosic family of extremely low-power Bluetooth® system-on-chip (SoC) solutions. ATM2/ATM3 integrates a Bluetooth 5.0 compliant radio, ARM® Cortex® M0 application processor and state-of-the-art power management to enable maximum lifetime in battery-operated devices.
For detailed product specifications and features, please refer to https://atmosic.com/products_atm2 and https://atmosic.com/products_atm3.

*************
SoCs and EVKs
*************

.. _board:


==================  ==================  ==================  ==================  ========  ==========
SoC Part #          EVK Part #          Board List          On-chip             Package   Energy
                                        <BOARD>             Flash                         Harvesting
==================  ==================  ==================  ==================  ========  ==========
ATM2202             ATMEVK-M2202-02     ATMEVK-M2202-02     1024KB              QFN 5x5
ATM2221             ATMEVK-M2221-02     ATMEVK-M2221-02     external            QFN 6x6
ATM2251             ATMEVK-M2251-01     ATMEVK-M2251-02     external            WLCSP
ATM3202             ATMEVK-M3202-02     ATMEVK-M3202-02     1024KB              QFN 5x5   x
ATM3221             ATMEVK-M3221-02     ATMEVK-M3221-02     external            QFN 6x6   x
==================  ==================  ==================  ==================  ========  ==========

================
Pin Multiplexing
================

The PinMux tool provides a graphical interface to summarize the mapping between Px pins and their supported functionalities.
It is available at https://atmosic.com/public/Pinmux/index.html for all Atmosic Wireless SoCs.

*************************
Programming and Debugging
*************************

It is recommended to set the environment variables ZEPHYR_TOOLCHAIN_VARIANT to ``zephyr`` and ZEPHYR_SDK_INSTALL_DIR to the directory where Zephyr SDK is installed. For example, assuming the installed SDK version 0.16.8 is in the home directory, for reference, it will be like this in a bash shell environment: (use ``setenv`` in a C shell environment, or ``set`` for Windows)::

 export ZEPHYR_TOOLCHAIN_VARIANT=zephyr
 export ZEPHYR_SDK_INSTALL_DIR=<$HOME/zephyr-sdk-0.16.8>

Applications for the Atmosic EVK boards can be built, flashed, and debugged using the familiar `west build` and `west flash`.

The ATMEVK-Mxxxx-02 boards require at least two images to be built: the MCUboot (bootloader) and the application.

.. _variable assignments:

In the remainder of this document, substitute for ``<APP>``, ``<APP_NAME>``, ``<MCUBOOT>``, ``<BOARD>``, and ``<DEVICE_ID>`` appropriately.  For example::

 <ZEPHYR_TOOLCHAIN_VARIANT>: zephyr
 <ZEPHYR_SDK_INSTALL_DIR>: /absolute/path/to/zephyrSDK
 <APP>: zephyr/samples/bluetooth/peripheral
 <APP_NAME>: peripheral
 <MCUBOOT>: bootloader/mcuboot/boot/zephyr
 <BOARD>: ATMEVK-M3202-02
 <DEVICE_ID>: ATRDI2180

* Use any board from the `board`_ list as ``<BOARD>``.
* <DEVICE_ID> is the unique ID from the FTDI device (ATRDIXXXX) used to program. For J-Link, the format will be XXXXXXXXX.

.. _build_an_application:

========
Building
========

-------------
Build MCUboot
-------------

.. code-block:: console

  west build -p -s <MCUBOOT> -b <BOARD> -d build/<BOARD>/<MCUBOOT>

---------------------
Build the Application
---------------------

.. code-block:: console

   west build -p -s <APP> -b <BOARD> -d build/<BOARD>/<APP> -- -DCONFIG_BOOTLOADER_MCUBOOT=y '-DCONFIG_MCUBOOT_SIGNATURE_KEY_FILE="bootloader/mcuboot/root-rsa-2048.pem"'

.. _application_run:

========
Flashing
========

-------------
Flash MCUboot
-------------

.. code-block:: console

  west flash --build-dir build/<BOARD>/<MCUBOOT> --device=<DEVICE_ID> --verify --noreset

---------------------
Flash the Application
---------------------

.. code-block:: console

  west flash --build-dir build/<BOARD>/<APP> --device=<DEVICE_ID> --verify

**************************
Viewing the Console Output
**************************

===============
Linux and macOS
===============

For Linux or macOS hosts, monitor the console output with a simple terminal program, such as::

  screen /dev/ttyUSB<#> 115200 or
  screen /dev/tty.usbserial-ATRDI<UNIQUE_ID>USB<#> 115200

On Linux OS, the serial console will appear as a USB device (``/dev/ttyUSB<#>``).  Use the following
command to identify the correct port for the serial console. When the EVK is connected, two serial ports will be added.
The user will need to test each one to determine where the message output is displayed::

 ls /dev/ttyUSB*
  /dev/ttyUSB0
  /dev/ttyUSB1

On macOS, the serial console will appear as a USB device (``/dev/tty.usbserial-ATRDI<UNIQUE_ID>USB<#>``).  Use the following
command to identify the correct port for the serial console. When the EVK is connected, two serial ports will be added.
The user will need to test each one to determine where the message output is displayed::

 ls /dev/tty.usbserial*
  /dev/tty.usbserial-ATRDI<UNIQUE_ID>USB10
  /dev/tty.usbserial-ATRDI<UNIQUE_ID>USB11

=======
Windows
=======

The console output for the Atmosic ATMx2xx is sent to the USB Serial port. When connected, two UART ports will be displayed.
The user must test each one to determine where the message output appears.
To view the console output, use a serial terminal program such as PuTTY (available from
https://www.chiark.greenend.org.uk/~sgtatham/putty) to connect to the USB Serial port. Set the UART configuration to 115200/N/8/1.

================
Note on UART1 RX
================

To use P32 for UART1 RX, set the MODE2 switch (SW1) on the EVK to the OFF position. This switch is connected to a 1k pull-down resistor and, when ON, prevents the FTDI interface board from driving the UART1 RX line.
To connect the ATMx2 part to the FTDI interface board, change the J3 jumper on the FTDI board from its default position (pins 3 and 4 connected) to pins 5 and 6 (third position from the right).
However, when loading the application, remove the J3 jumper to prevent benign boot being active that could stop the ATMx2 from booting into the application.