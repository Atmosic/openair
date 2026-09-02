.. _atm5evk:

###############
Atmosic ATM5/e
###############

********
Overview
********

The ATM5/e Wireless SoC Series is part of the Atmosic family of extremely low-power Bluetooth® system-on-chip (SoC) solutions.
The ATM5/e Series includes two sub-series: ATM53/e and ATM52.

ATM53/e Series integrates a Bluetooth 6.0 compliant radio, ARM® Cortex® M33F application processor with ARM® TrustZone® enabled security features, and state-of-the-art power management to enable maximum lifetime in battery-operated devices.
ATM53/e Series supports Bluetooth 6.0 Channel Sounding, and selected SKUs in the ATM53/e Series support Energy Harvesting.

ATM52 Series integrates a Bluetooth 5.4 compliant radio, ARM® Cortex® M33F application processor with ARM® TrustZone® enabled security features, and state-of-the-art power management to enable maximum lifetime in battery-operated devices.

For detailed product specifications and features, please refer to https://atmosic.com/.

*************
SoCs and EVKs
*************

.. _board:


==================  ==================  ==================  ==================  ========  ==========
SoC Part #          EVK Part #          Board List          On-chip             Package   Energy
                                        <BOARD>             Flash                         Harvesting
==================  ==================  ==================  ==================  ========  ==========
ATM5305-2NC8QK      ATMEVK-5305-NQK-2   ATMEVK-5305-NQK-2   2048KB               QFN 5x5  N/A
ATM5205-2NC8QK      ATMEVK-5205-NQK-2   ATMEVK-5205-NQK-2   2048KB               QFN 5x5  N/A
==================  ==================  ==================  ==================  ========  ==========

================
Pin Multiplexing
================

The PinMux tool provides a graphical interface to summarize the mapping between Px pins and their supported functionalities.
It is available at https://atmosic.com/public/Pinmux/index.html for all Atmosic Wireless SoCs.

***************
Getting Started
***************

Follow the instructions_ from the official Zephyr documentation on how to get started.

=============================
Connecting an ATMEVK on Linux
=============================

Special udev and group permissions are required by OpenOCD, which is the primary
debugger used to interface with Atmosic EVKs, to access the USB FTDI
SWD interface.  When following Step 4 "Install udev rules, which
allow you ..." for Ubuntu_, add the following line to
`60-openocd.rules`::

 ATTRS{idVendor}=="1366", ATTRS{idProduct}=="1050", MODE="660", GROUP="plugdev", TAG+="uaccess"

.. _Ubuntu: https://docs.zephyrproject.org/3.7.0/develop/getting_started/index.html#install-the-zephyr-sdk

.. _instructions: https://docs.zephyrproject.org/3.7.0/develop/getting_started/index.html

===============================
Connecting an ATMEVK on Windows
===============================

The FTDI device driver must be replaced with the WinUSB driver to
become available as a USB device and usable by OpenOCD.
This can be done using Zadig.

Windows Administrator privileges are required to replace the driver.

Zadig can be obtained from:

https://github.com/pbatard/libwdi/releases

At the time of this writing, the latest version -- 2.9 -- can be
obtained using the following direct link.

https://github.com/pbatard/libwdi/releases/download/v1.5.1/zadig-2.9.exe

To replace the driver:

#. From the "Options" menu of Zadig, click "List all devices".
#. From the drop-down menu, find "ATMEVK (Interface 0)" corresponding to
   the Atmosic board.  It should show "FTDIBUS (v...)" as
   the current driver on the left.
#. Select "WinUSB (v...)" as the replacement on the right.
#. Click "Replace Driver"

Verify the successful installation of WinUSB by going to the Windows
Device Manager and confirm that the "ATMEVK (Interface 0)" shows
as such rather than the "FTDI driver".  (In Device Manager, expand the category
"Universal Serial Bus devices" and look for "BULK interface".)

*************************
Programming and Debugging
*************************

It is recommended to set the environment variables ZEPHYR_TOOLCHAIN_VARIANT to ``zephyr`` and ZEPHYR_SDK_INSTALL_DIR to the directory where Zephyr SDK is installed. For example, assuming the installed SDK version 1.0.1 is in the home directory, for reference, it will be like this in a bash shell environment: (use ``setenv`` in a C shell environment, or ``set`` for Windows)::

 export ZEPHYR_TOOLCHAIN_VARIANT=zephyr
 export ZEPHYR_SDK_INSTALL_DIR=$HOME/zephyr-sdk-1.0.1

Applications for the Atmosic EVK boards can be built, flashed, and debugged using the familiar `west build` and `west flash`.

The ATM5/e boards can be built with a single application image using the default secure board files. For advanced security requirements, applications can optionally be built with separate SPE (Secure Processing Environment) and NSPE (Non-Secure Processing Environment) images. See :ref:`spe_nspe_architecture` for details on SPE/NSPE builds.

The Atmosic SPE can be found under ``<WEST_TOPDIR>/openair/samples/spe``.

.. _variable assignments:

In the remainder of this document, substitute for ``<ZEPHYR_TOOLCHAIN_VARIANT>``, ``<ZEPHYR_SDK_INSTALL_DIR>``, ``<WEST_TOPDIR>``, , ``<APP>``, ``<MCUBOOT>``, ``<BOARD>``, and ``<DEVICE_ID>`` appropriately.  For example::

 <ZEPHYR_TOOLCHAIN_VARIANT>: zephyr
 <ZEPHYR_SDK_INSTALL_DIR>: /absolute/path/to/zephyrSDK
 <WEST_TOPDIR>: /absolute/path/to/zephyrproject
 <APP>: zephyr/samples/bluetooth/peripheral
 <MCUBOOT>: bootloader/mcuboot/boot/zephyr
 <BOARD>: ATMEVK-5305-NQK-2
 <DEVICE_ID>: ATMEVK10800002

* Use any board from the `board`_ list as ``<BOARD>``.
* <DEVICE_ID> is the unique ID used to program. For FTDI, the format will be ATMEVK10800002.

=====================
Building and Flashing
=====================

----------------------------
Enabling a Random BD Address
----------------------------

Some non-production ATM5/e EVKs in the field may have no BD address programmed in the secure journal.  On such boards, upon loading a BLE application, an assert error occurs with a message appearing on the console similar to the one below::

  ASSERT ERR(0) at <zephyrproject-root>/openair/modules/hal_atmosic/drivers/eui/eui.c:132

To avoid this error, the BLE application must be built with an option to allocate a random BD address.  This can be done by adding ``-DCONFIG_ATM_EUI_ALLOW_RANDOM=y -DCONFIG_ATM_SETTINGS=y`` to the build options.

---------------
Build and Flash
---------------

Applications can be built with MCUboot or without the MCUboot option. If a device firmware update (DFU) is not needed, you can choose the option without MCUboot. If you require DFU, then the MCUboot option is required.

There are two main options as stated above:

---------------------
A. Non-MCUboot Option
---------------------

1. Build the Application:

Build the application with the default secure board::

  west build -p -s <APP> -b <BOARD> -d build/<BOARD>/<APP>

2. Flashing the Application:

Atmosic provides a mechanism to increase the legacy programming time called FAST LOAD. Apply the option ``--fast_load`` to enable the FAST LOAD.

Flash the application::

  west flash --device <DEVICE_ID> --dl --fast_load --verify -d build/<BOARD>/<APP> --erase_flash

Note that adding ``--erase_flash`` is required for flash-only devices like ATM5/e platforms. To erase multiple specific flash regions, repeat ``--erase_flash=address,size``; for example, ``--erase_flash=0x200000,0x1000 --erase_flash=0x201000,0x1000``.

.. note::
  For advanced security requirements using separate SPE and NSPE images, see :ref:`spe_nspe_architecture`.

-----------------
B. MCUboot Option
-----------------

.. _MCUboot option:

1. Build the MCUboot:

To build with MCUboot, for example, DFU is needed, first build MCUboot::

  west build -p -s <MCUBOOT> -b <BOARD>@mcuboot_bl -d build/<BOARD>/mcuboot

Note that make use of "board revision" to configure our board partitions to work for MCUboot.  On top of the "revisions," MCUboot currently needs an additional overlay that must be provided through the command line to give it the entire SRAM.

2. Build the Application with MCUboot:

Build the application with MCUboot as follows::

  west build -p -s <APP> -b <BOARD>@mcuboot -d build/<BOARD>/<APP> -- -DCONFIG_BOOTLOADER_MCUBOOT=y -DCONFIG_MCUBOOT_SIGNATURE_KEY_FILE=\"bootloader/mcuboot/root-ec-p256.pem\"

When passing ``-DCONFIG_BOOTLOADER_MCUBOOT=y`` on the application build command line, ``west`` automatically creates a signed image (``zephyr.signed.{bin,hex}``), which is ultimately used by ``west flash`` to program the device.

3. Flashing the MCUboot and the Application:

Flash MCUboot

Atmosic provides a mechanism to increase the legacy programming time called FAST LOAD. Apply the option ``--fast_load`` to enable the FAST LOAD.::

   west flash --verify --device <DEVICE_ID> --dl --fast_load -d build/<BOARD>/mcuboot --noreset --erase_flash

Note that adding ``--erase_flash`` is required for flash-only devices like ATM5/e platforms. It is only needed when you flash the first image, such as MCUboot in this example. Do not add ``--erase_flash`` while flashing the application below. For multiple specific regions, repeat ``--erase_flash=address,size``.

Flash the signed application image::

   west flash --verify --device <DEVICE_ID> --dl --fast_load -d build/<BOARD>/<APP>

===================
BLE Link Controller
===================

ATM5/e platform has Atmosic BLE Link Controller that enables various BLE functionalities depending upon application needs and based upon config options ``CONFIG_BT_*``

The BLE link controller sits at the lowest layer of the Zephyr Bluetooth protocol stack.  Zephyr provides the upper Bluetooth Host stack that can interface with BLE link controllers that conform to the standard Bluetooth Host Controller Interface specification.

Note that developers cannot use ``CONFIG_BT_CTLR_*`` `flags`__ with the ATM5/e platform, as a custom, hardware-optimized link controller is used instead of Zephyr's link controller software.

.. _CONFIG_BT_CTLR_KCONFIGS: https://docs.zephyrproject.org/latest/kconfig.html#!%5ECONFIG_BT_CTLR
__ CONFIG_BT_CTLR_KCONFIGS_

Note that as the ATM52 series uses a Bluetooth 5.4 compliant radio, it does not support Bluetooth 6.0 Channel Sounding.

**************************
Viewing the Console Output
**************************

===============
Linux and macOS
===============

For Linux or macOS hosts, monitor the console output with a simple terminal program, such as::

  screen /dev/serial/by-id/usb-FTDI_ATMEVK_ATMEVK<#> 115200 or
  screen /dev/tty.usbserial-ATMEVK<UNIQUE_ID#> 115200

On Linux OS, the serial console will appear as a USB device (``/dev/ttyUSB<#>``).  Use the following
command to identify the correct port for the serial console. When the EVK is connected, multiple serial ports will be added.
The user will need to test each one to determine where the message output is displayed::

 ls /dev/ttyUSB*
  /dev/ttyUSB0
  /dev/ttyUSB1
  /dev/ttyUSB2

On macOS, the serial console will appear as a USB device (``/dev/tty.usbserial<UNIQUE_ID#>``).  Use the following
command to identify the correct port for the serial console. When the EVK is connected, multiple serial ports will be added.
The user will need to test each one to determine where the message output is displayed::

 ls /dev/tty.usbserial*
  /dev/tty.usbserial<UNIQUE_ID1>
  /dev/tty.usbserial<UNIQUE_ID2>
  /dev/tty.usbserial<UNIQUE_ID3>

=======
Windows
=======

The console output for the Atmosic ATM5/e is sent to the FTDI USB to UART adapter. When connected, multiple UART ports will be displayed.
The user must test each one to determine where the message output appears.
To view the console output, use a serial terminal program such as PuTTY (available from
https://www.chiark.greenend.org.uk/~sgtatham/putty) to connect to the FTDI USB UART port. Set the UART configuration to 115200/N/8/1.

**********
Zephyr DFU
**********

Please review the content for DFU Serial and OTA support at Zephyr_DFU_.

.. _Zephyr_DFU: https://atmosic.com/public/OpenAir_SDK_doc/dfu_update/dfu_update.html
