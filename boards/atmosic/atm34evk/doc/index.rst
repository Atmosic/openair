.. _atm34evk:

###############
Atmosic ATM34/e
###############

********
Overview
********

The ATM34/e Wireless SoC Series is part of the Atmosic family of extremely low-power Bluetooth® system-on-chip (SoC) solutions. ATM34/e integrates a Bluetooth 6.0 compliant radio, ARM® Cortex® M33F application processor with ARM® TrustZone® enabled security features, and state-of-the-art power management to enable maximum lifetime in battery-operated devices.
For detailed product specifications and features, please refer to https://atmosic.com/products_atm34/.

*************
SoCs and EVKs
*************

.. _board:


==================  ==================  ==================  ==================  ========  ==========
SoC Part #          EVK Part #          Board List          On-chip             Package   Energy
                                        <BOARD>             Flash                         Harvesting
==================  ==================  ==================  ==================  ========  ==========
ATM3405-5PCAQK      ATMEVK-3405-PQK-5   ATMEVK-3405-PQK-5   512KB               QFN 5x5
ATM3405-5YCABV      ATMEVK-3405-YBV-5   ATMEVK-3405-YBV-5   2560KB              BGA 4x4
ATM3405-5WCAQK      ATMEVK-3405-WQK-5   ATMEVK-3405-WQK-5   1536KB              QFN 5x5
ATM3405-5WCAQK      ATMBTCSTAG-3405     ATMBTCSTAG-3405     1536KB              QFN 5x5
ATM3430e-5YCAQN     ATMEVK-3430e-YQN-5  ATMEVK-3430e-YQN-5  2560KB              QFN 7x7   x
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
SWD interface or J-Link OB.  When following Step 4 "Install udev rules, which
allow you ..." for Ubuntu_, add the following line to
`60-openocd.rules`::

 ATTRS{idVendor}=="1366", ATTRS{idProduct}=="1050", MODE="660", GROUP="plugdev", TAG+="uaccess"

.. _Ubuntu: https://docs.zephyrproject.org/3.7.0/develop/getting_started/index.html#install-the-zephyr-sdk

.. _instructions: https://docs.zephyrproject.org/3.7.0/develop/getting_started/index.html

===============================
Connecting an ATMEVK on Windows
===============================

The J-Link OB device driver must be replaced with the WinUSB driver to
become available as a USB device and usable by OpenOCD.
This can be done using Zadig.

Windows Administrator privileges are required to replace the driver.

Zadig can be obtained from:

https://github.com/pbatard/libwdi/releases

At the time of this writing, the latest version -- 2.4 -- can be
obtained using the following direct link.

https://github.com/pbatard/libwdi/releases/download/b721/zadig-2.4.exe

To replace the driver:

#. From the "Options" menu of Zadig, click "List all devices".
#. From the drop-down menu, find "BULK interface" corresponding to
   the Atmosic board.  It should show "jlink (v...)" as
   the current driver on the left.
#. Select "WinUSB (v...)" as the replacement on the right.
#. Click "Replace Driver"

Verify the successful installation of WinUSB by going to the Windows
Device Manager and confirm that the "BULK interface" shows
as such rather than the "J-Link driver".  (In Device Manager, expand the category
"Universal Serial Bus devices" and look for "BULK interface".)

*************************
Programming and Debugging
*************************

It is recommended to set the environment variables ZEPHYR_TOOLCHAIN_VARIANT to ``zephyr`` and ZEPHYR_SDK_INSTALL_DIR to the directory where Zephyr SDK is installed. For example, assuming the installed SDK version 0.16.4 is in the home directory, for reference, it will be like this in a bash shell environment: (use ``setenv`` in a C shell environment, or ``set`` for Windows)::

 export ZEPHYR_TOOLCHAIN_VARIANT=zephyr
 export ZEPHYR_SDK_INSTALL_DIR=$HOME/zephyr-sdk-0.16.4

Applications for the Atmosic EVK boards can be built, flashed, and debugged using the familiar `west build` and `west flash`.

The atm34evk boards can be built with a single application image using the default secure board files. For advanced security requirements, applications can optionally be built with separate SPE (Secure Processing Environment) and NSPE (Non-Secure Processing Environment) images. See :ref:`spe_nspe_architecture` for details on SPE/NSPE builds.

The Atmosic SPE can be found under ``<WEST_TOPDIR>/openair/samples/spe``.

.. _variable assignments:

In the remainder of this document, substitute for ``<ZEPHYR_TOOLCHAIN_VARIANT>``, ``<ZEPHYR_SDK_INSTALL_DIR>``, ``<WEST_TOPDIR>``, , ``<APP>``, ``<APP_NAME>``, ``<MCUBOOT>``, ``<BOARD>``, and ``<DEVICE_ID>`` appropriately.  For example::

 <ZEPHYR_TOOLCHAIN_VARIANT>: zephyr
 <ZEPHYR_SDK_INSTALL_DIR>: /absolute/path/to/zephyrSDK
 <WEST_TOPDIR>: /absolute/path/to/zephyrproject
 <APP>: zephyr/samples/bluetooth/peripheral
 <APP_NAME>: APP Name for ISP section
 <MCUBOOT>: bootloader/mcuboot/boot/zephyr
 <BOARD>: ATMEVK-3430e-YQN-5
 <DEVICE_ID>: 000900036960

* Use any board from the `board`_ list as ``<BOARD>``.
* <DEVICE_ID> is the unique ID from the J-Link device used to program. For FTDI, the format will be ATRDIXXXX.

=====================
Building and Flashing
=====================

----------------------------
Enabling a Random BD Address
----------------------------

Some non-production ATM34 EVKs in the field may have no BD address programmed in the secure journal.  On such boards, upon loading a BLE application, an assert error occurs with a message appearing on the console similar to the one below::

  ASSERT ERR(0) at <zephyrproject-root>/openair/modules/hal_atmosic/drivers/eui/eui.c:132

To avoid this error, the BLE application must be built with an option to allocate a random BD address.  This can be done by adding ``-DCONFIG_ATM_EUI_ALLOW_RANDOM=y`` to the build options.

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

  west build -p -s <APP> -b <BOARD> -d build/<BOARD>/<APP> -- -DCONFIG_ATM_EUI_ALLOW_RANDOM=y

2. Flashing the Application:

Atmosic provides a mechanism to increase the legacy programming time called FAST LOAD. Apply the option ``--fast_load`` to enable the FAST LOAD.

Flash the application::

  west flash --device <DEVICE_ID> --jlink --fast_load --verify -d build/<BOARD>/<APP>

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

  west build -p -s <APP> -b <BOARD>@mcuboot -d build/<BOARD>/<APP> -- -DCONFIG_ATM_EUI_ALLOW_RANDOM=y -DCONFIG_BOOTLOADER_MCUBOOT=y -DCONFIG_MCUBOOT_SIGNATURE_KEY_FILE=\"bootloader/mcuboot/root-ec-p256.pem\" -DDTS_EXTRA_CPPFLAGS=";" -DEXTRA_CONF_FILE="<WEST_TOPDIR>/openair/doc/dfu/overlay-bt-dfu.conf"

When passing ``-DCONFIG_BOOTLOADER_MCUBOOT=y`` on the application build command line, ``west`` automatically creates a signed image (``zephyr.signed.{bin,hex}``), which is ultimately used by ``west flash`` to program the device.

3. Flashing the MCUboot and the Application:

Flash MCUboot

Atmosic provides a mechanism to increase the legacy programming time called FAST LOAD. Apply the option ``--fast_load`` to enable the FAST LOAD.::

   west flash --verify --device <DEVICE_ID> --jlink --fast_load -d build/<BOARD>/mcuboot --noreset

Note that adding ``--erase_flash`` is an option to erase Flash if needed.

Flash the signed application image::

   west flash --verify --device <DEVICE_ID> --jlink --fast_load -d build/<BOARD>/<APP>

===========================
BLE Link Controller Options
===========================

When building a Bluetooth application (``CONFIG_BT``) the BLE driver component provides a statically linked BLE link controller library.  The BLE link controller sits at the lowest layer of the Zephyr Bluetooth protocol stack.  Zephyr provides the upper Bluetooth Host stack that can interface with BLE link controllers that conform to the standard Bluetooth Host Controller Interface specification.

BLE Link Controller comes as a library that can be statically linked along with user application. Two flavors of the BLE link controller library are provided as mentioned below and applications can choose one among them depending on their needs.

On ATM34 platforms, Kconfig can automatically select the appropriate BLE stack flavor based on the ``CONFIG_BT_*`` settings in the application's ``prj.conf`` file. The automatically-selected flavor can be overridden by bullding with ``-DCONFIG_ATMWSTK_<ATMWSTK>=y`` on the command line.

The flavor ``CONFIG_ATMWSTK_PD50=y`` is a designation of a peripheral-only device (PD) with a reduced feature set (50).  The PD50 controller offers basic BLE 6.0 features that can support most peripheral-only applications.  The use of static linkage and reduced feature sets can help reduce the total code memory footprint of the application. The other supported choice is ``CONFIG_ATMWSTK_CPD200=y``.

-------------------
CONFIG_ATMWSTK_PD50
-------------------


Compact feature set, peripheral only. This flavor is selected by the configuration ``CONFIG_ATMWSTK_PD50=y``.

Features:

* Peripheral/Advertiser roles only. No Scanner or Central functionality
* BLE support for Extended Advertising
* BLE support for Data Length extensions, 1M, 2M and CODED PHYs
* BLE 6.0 support. Channel Sounding can be enabled with Kconfig option
* No Periodic advertising
* No BLE support for CTE (No AoA/AoD application support).
* No BLE LE Power control
* No ISO (LE Audio) support
* Up to 4 Advertisement sets
* Up to 2 Connections


---------------------
CONFIG_ATMWSTK_CPD200
---------------------


Extended feature set with central and peripheral roles. This flavor is selected by the configuration ``CONFIG_ATMWSTK_CPD200=y``.

Features:

* All roles (central/peripheral/observer/advertiser)
* BLE 6.0 support
* Extended and Periodic Advertising, including Periodic Sync and Periodic Advertising with Response (PAWR)
* BLE Power control, Data Length extensions, 1M, 2M and CODED PHYs
* Support for CTE (constant tone extensions), Tx Only
* BLE 6.0 channel sounding
* Up to 6 Advertisement sets
* Up to 2 Connections

Unsupported Features:

* No ISO/CIS/BIS Audio support
* No BLE 6.0 Frame Space Update
* No BLE 6.0 Monitoring Advertisers


If the ATM34 entropy driver is enabled without CONFIG_BT=y (mainly for evaluation), the system still requires a minimal BLE controller stack.  Without choosing a specific stack configuration an appropriate minimal BLE controller will be selected.  This may increase the size of your application.

Note that developers cannot use ``CONFIG_BT_CTLR_*`` `flags`__ with the ATM34 platform, as a custom, hardware-optimized link controller is used instead of Zephyr's link controller software.

.. _CONFIG_BT_CTLR_KCONFIGS: https://docs.zephyrproject.org/latest/kconfig.html#!%5ECONFIG_BT_CTLR
__ CONFIG_BT_CTLR_KCONFIGS_


**************************
Viewing the Console Output
**************************

===============
Linux and macOS
===============

For Linux or macOS hosts, monitor the console output with a simple terminal program, such as::

  screen /dev/ttyACM<#> 115200 or
  screen /dev/tty.usbmodem<UNIQUE_ID#> 115200

On Linux OS, the serial console will appear as a USB device (``/dev/ttyACM<#>``).  Use the following
command to identify the correct port for the serial console. When the EVK is connected, two serial ports will be added.
The user will need to test each one to determine where the message output is displayed::

 ls /dev/ttyACM*
  /dev/ttyACM0
  /dev/ttyACM1

On macOS, the serial console will appear as a USB device (``/dev/tty.usbmodem<UNIQUE_ID#>``).  Use the following
command to identify the correct port for the serial console. When the EVK is connected, two serial ports will be added.
The user will need to test each one to determine where the message output is displayed::

 ls /dev/tty.usbmodem*
  /dev/tty.usbmodem<UNIQUE_ID1>
  /dev/tty.usbmodem<UNIQUE_ID3>

=======
Windows
=======

The console output for the Atmosic ATM34/e is sent to the J-Link CDC UART port. When connected, two UART ports will be displayed.
The user must test each one to determine where the message output appears.
To view the console output, use a serial terminal program such as PuTTY (available from
https://www.chiark.greenend.org.uk/~sgtatham/putty) to connect to the J-Link CDC UART port. Set the UART configuration to 115200/N/8/1.

**********
Zephyr DFU
**********

Please review the content for DFU Serial and OTA support at Zephyr_DFU_.

.. _Zephyr_DFU: https://github.com/Atmosic/openair/blob/HEAD/doc/dfu/dfu.rst
