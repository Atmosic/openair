###############
Atmosic ATM33/e
###############

********
Overview
********

The ATM33/e Wireless SoC Series is part of the Atmosic family of extremely low-power Bluetooth® system-on-chip (SoC) solutions. ATM33/e integrates a Bluetooth 5.3 compliant radio, ARM® Cortex® M33F application processor with ARM® TrustZone® enabled security features, and state-of-the-art power management to enable maximum lifetime in battery-operated devices.
For detailed product specifications and features, please refer to https://atmosic.com/products_atm33/.

*************
SoCs and EVKs
*************

.. _board:

==================  =======================  =================  ==================  ========  ==========
SoC Part #          EVK Part #               Board List         On-chip             Package   Energy
                                             <BOARD>            Flash                         Harvesting
==================  =======================  =================  ==================  ========  ==========
ATM3330e-5DCAQN     ATMEVK-3330e-QN-7        ATMEVK-3330e-QN-7  512KB               QFN 7x7   x
ATM3330e-5DCAQN     | ATMEVK-3330e-QN-6      ATMEVK-3330e-QN-7  512KB               QFN 7x7   x
                    | 052-(4x-5x)-xxx-xxxx
ATM3330e-5DCAQN     | ATMEVK-3330e-QN-6      ATMEVK-3330e-QN-6  512KB               QFN 7x7   x
                    | 052-(0x-3x)-xxx-xxxx
ATM3330-5DCAQN      ATMEVK-3330-QN-6         ATMEVK-3330-QN-6   512KB               QFN 7x7
ATM3325-5DCAQK      ATMEVK-3325-QK-6         ATMEVK-3325-QK-6   512KB               QFN 5x5
ATM3325-5LCAQK      ATMEVK-3325-LQK-6        ATMEVK-3325-LQK-6  512KB + 1MB         QFN 5x5
ATM3325-5DCACM      ATMEVK-3325-CM-6         ATMEVK-3325-CM-6   512KB               WLCSP
==================  =======================  =================  ==================  ========  ==========

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
allow you ..." for Ubuntu_, add the following line to `60-openocd.rules`::

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

The atm33evk boards can be built with a single application image using the default secure board files. For advanced security requirements, applications can optionally be built with separate SPE (Secure Processing Environment) and NSPE (Non-Secure Processing Environment) images. See :ref:`spe_nspe_architecture` for details on SPE/NSPE builds.

.. _variable assignments:

In the remainder of this document, substitute for ``<ZEPHYR_TOOLCHAIN_VARIANT>``, ``<ZEPHYR_SDK_INSTALL_DIR>``, ``<WEST_TOPDIR>``, ``<APP>``, ``<APP_NAME>``, ``<MCUBOOT>``, ``<BOARD>``, and ``<DEVICE_ID>`` appropriately.  For example::

 <ZEPHYR_TOOLCHAIN_VARIANT>: zephyr
 <ZEPHYR_SDK_INSTALL_DIR>: /absolute/path/to/zephyrSDK
 <WEST_TOPDIR>: /absolute/path/to/zephyrproject
 <APP>: zephyr/samples/bluetooth/peripheral
 <APP_NAME>: APP Name for ISP section
 <MCUBOOT>: bootloader/mcuboot/boot/zephyr
 <BOARD>: ATMEVK-3330e-QN-7
 <DEVICE_ID>: 000900036846

* Use any board from the `board`_ list as ``<BOARD>``.
* ``<DEVICE_ID>`` is the unique ID from the J-Link device used to program. For FTDI, the format will be ATRDIXXXX.

=====================
Building and Flashing
=====================

----------------------------
Enabling a Random BD Address
----------------------------

Some non-production ATM33 EVKs in the field may have no BD address programmed in the secure journal.  On such boards, upon loading a BLE application, an assert error occurs with a message appearing on the console similar to the one below::

  ASSERT ERR(0) at <zephyrproject-root>/openair/modules/hal_atmosic/drivers/eui/eui.c:132

To avoid this error, the BLE application must be built with an option to allocate a random BD address.  This can be done by adding ``-DCONFIG_ATM_EUI_ALLOW_RANDOM=y`` to the build options.


---------------
Build and Flash
---------------

Applications can be built with MCUboot or without the MCUboot option. If a device firmware update (DFU) is not needed, you can choose the option without MCUboot. If you require DFU, then the MCUboot option is required.

On top of the two options above, there are two suboptions for BLE Link Controller: CPD200 Fixed Image and PD50 Statically-linked library. It is required to know which BLE Link Controller option the application is using before building. See the below section "BLE Link Controller Options" for more information.

---------------------
A. Non-MCUboot Option
---------------------

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Using CPD200 which is available as a Fixed Atmosic Wireless Stack Image only (Suboption #1)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1a. Build the Application:


  west build -p -s <APP> -b <BOARD> -d build/<BOARD>/<APP> -- -DDTS_EXTRA_CPPFLAGS="-DFIXED_ATMWSTK=CPD200;" -DCONFIG_ATM_EUI_ALLOW_RANDOM=y

2a. Flashing Application:

``west flash`` is used to program a device with the necessary images, often only built as described above and sometimes also with a pre-built library provided as an ELF binary.

For an atmevk33 board, this is typically a J-Link serial number, but it can also be an FTDI serial number of the form ``ATRDIXXXX`` if not an EVK.  For a J-Link board, pass the ``--jlink`` option to the flash runner as in ``west flash --jlink ...``.

If the application requires Bluetooth (configured with ``CONFIG_BT`` in the prj.conf file) and uses the fixed BLE link controller image option, then the controller image requires programming.  This is typically done before programming the application and resetting (omitting the ``--noreset`` option to ``west flash``). For example::

  west flash --verify --device <DEVICE_ID> --jlink --fast_load --skip-rebuild -d build/<BOARD>/<APP> --use-elf --elf-file openair/modules/hal_atmosic/ATM33xx-5/drivers/ble/atmwstk_CPD200.elf --noreset

Atmosic provides a mechanism to increase the legacy programming time called FAST LOAD. Apply the option ``--fast_load`` to enable the FAST LOAD.

Flash the application::

  west flash --device <DEVICE_ID> --jlink --fast_load --verify -d build/<BOARD>/<APP>


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Using PD50 Atmosic Wireless Stack which is supported as a Statically Linked BLE Link Controller Library (Suboption #2)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1b. Build the Application:

  west build -p -s <APP> -b <BOARD> -d build/<BOARD>/<APP> -- -DCONFIG_ATM_EUI_ALLOW_RANDOM=y

2b. Flashing the Application:

Atmosic provides a mechanism to increase the legacy programming time called FAST LOAD. Apply the option ``--fast_load`` to enable the FAST LOAD.

  west flash --device <DEVICE_ID> --jlink --fast_load --verify -d build/<BOARD>/<APP>


-----------------
B. MCUboot Option
-----------------

.. _MCUboot option:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Using CPD200 which is available as a Fixed Atmosic Wireless Stack Image only (Suboption #1)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1a. Build MCUboot:

To build with MCUboot, for example, DFU is needed, first build MCUboot::

  west build -p -s <MCUBOOT> -b <BOARD>@mcuboot_bl -d build/<BOARD>/mcuboot -- -DDTS_EXTRA_CPPFLAGS="-DFIXED_ATMWSTK=CPD200"

2. Build the Application with MCUboot:

Build the application with MCUboot as follows::

  west build -p -s <APP> -b <BOARD>@mcuboot -d build/<BOARD>/<APP> -- -DCONFIG_BOOTLOADER_MCUBOOT=y -DCONFIG_MCUBOOT_SIGNATURE_KEY_FILE=\"bootloader/mcuboot/root-ec-p256.pem\" -DDTS_EXTRA_CPPFLAGS="-DFIXED_ATMWSTK=CPD200" -DCONFIG_ATM_EUI_ALLOW_RANDOM=y -DEXTRA_CONF_FILE="<WEST_TOPDIR>/openair/doc/dfu/overlay-bt-dfu.conf"

When passing ``-DCONFIG_BOOTLOADER_MCUBOOT=y`` on the application build command line, ``west`` automatically creates a signed image (``zephyr.signed.{bin,hex}``), which is ultimately used by ``west flash`` to program the device.

Note that make use of "board revision" to configure our board partitions to work for MCUboot.  On top of the "revisions," MCUboot currently needs an additional overlay that must be provided through the command line to give it the entire SRAM.

3. Flashing MCUboot and the Application:

Flash MCUboot

Atmosic provides a mechanism to increase the legacy programming time called FAST LOAD. Apply the option ``--fast_load`` to enable the FAST LOAD.::

   west flash --verify --device <DEVICE_ID> --jlink --fast_load -d build/<BOARD>/mcuboot --noreset

Note that adding ``--erase_flash`` is an option to erase Flash if needed.

Flash the signed application image::

   west flash --verify --device <DEVICE_ID> --jlink --fast_load -d build/<BOARD>/<APP>

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Using PD50 Atmosic Wireless Stack which is supported as a Statically Linked BLE Link Controller Library (Suboption #2)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1b. Build MCUBOOT:

To build MCUboot::

  west build -p -s <MCUBOOT> -b <BOARD>@mcuboot_bl -d build/<BOARD>/mcuboot

2b. Build the Application with MCUboot:

Build the application with MCUboot as follows::

  west build -p -s <APP> -b <BOARD>@mcuboot -d build/<BOARD>/<APP> -- -DCONFIG_ATM_EUI_ALLOW_RANDOM=y -DCONFIG_BOOTLOADER_MCUBOOT=y -DCONFIG_MCUBOOT_SIGNATURE_KEY_FILE=\"bootloader/mcuboot/root-ec-p256.pem\" -DEXTRA_CONF_FILE="<WEST_TOPDIR>/openair/doc/dfu/overlay-bt-dfu.conf"

This is somewhat of a non-standard workflow.  When passing ``-DCONFIG_BOOTLOADER_MCUBOOT=y`` on the application build command line, ``west`` automatically creates a signed, merged image (``zephyr.signed.{bin,hex}``), which is ultimately used by ``west flash`` to program the device.

Note that make use of "board revision" to configure our board partitions to work for MCUboot.  On top of the "revisions," MCUboot currently needs an additional overlay that must be provided through the command line to give it the entire SRAM.

3b. Flashing MCUboot and the Application:

Flash MCUboot

Atmosic provides a mechanism to increase the legacy programming time called FAST LOAD. Apply the option ``--fast_load`` to enable the FAST LOAD.::

  west flash --verify --device <DEVICE_ID> --jlink --fast_load -d build/<BOARD>/mcuboot --noreset

Note that adding ``--erase_flash`` is an option to erase Flash if needed.

Flash the signed application image ::

  west flash --verify --device <DEVICE_ID> --jlink --fast_load -d build/<BOARD>/<APP>

---------------------------
BLE Link Controller Options
---------------------------

When building a Bluetooth application (``CONFIG_BT``), the BLE driver component provides two link controller options. A fixed BLE link controller image and a statically linked BLE link controller library.  The BLE link controller sits at the lowest layer of the Zephyr Bluetooth protocol stack.  Zephyr provides the upper Bluetooth Host stack that can interface with BLE link controllers that conform to the standard Bluetooth Host Controller Interface specification.

Refer to application's ``prj.conf`` and ``openair/modules/hal_atmosic/ATM33xx-5/drivers/ble/Kconfig`` to check which BLE Link Controller option the application is requiring.  On ATM33 platforms, if the application is using CPD200, then ``-DDTS_EXTRA_CPPFLAGS="-DFIXED_ATMWSTK=CPD200"`` is needed when building the application. Otherwise, the following build error will show up:

  .. code-block::

    fixed_atmwstk.c:32:2: error: #error "-DFIXED_ATMWSTK=<FLAVOR> has to be provided to the device tree generation step rather than the normal build step."
       32 | #error "-DFIXED_ATMWSTK=<FLAVOR> has to be provided to the device tree generation step rather than the normal build step."
          |  ^~~~~

To review how the fixed and statically linked controllers are used, please refer to ``openair/modules/hal_atmosic/ATM33xx-5/drivers/ble/README.rst``.

If the ATM33 entropy driver is enabled without ``CONFIG_BT=y`` (mainly for evaluation), the system still requires a minimal BLE controller stack.  Without choosing a specific stack configuration an appropriate minimal BLE controller will be selected.  This may increase the size of your application.

Note that developers cannot use ``CONFIG_BT_CTLR_*`` `flags`__ with the ATM33 platform, as a custom, hardware-optimized link controller is used instead of Zephyr's link controller software.

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

On Linux OS, the serial console will appear as a USB device (``/dev/ttyACM<#>``).  Use the following command to identify the correct port for the serial console. When the EVK is connected, two serial ports will be added.
The user will need to test each one to determine where the message output is displayed::

 ls /dev/ttyACM*
  /dev/ttyACM0
  /dev/ttyACM1

On macOS, the serial console will appear as a USB device (``/dev/tty.usbmodem<UNIQUE_ID#>``).  Use the following command to identify the correct port for the serial console. When the EVK is connected, two serial ports will be added. The user will need to test each one to determine where the message output is displayed::

 ls /dev/tty.usbmodem*
  /dev/tty.usbmodem<UNIQUE_ID1>
  /dev/tty.usbmodem<UNIQUE_ID3>

=======
Windows
=======

The console output for the Atmosic ATM33/e is sent to the J-Link CDC UART port. When connected, two UART ports will be displayed.
The user must test each one to determine where the message output appears.
To view the console output, use a serial terminal program such as PuTTY (available from https://www.chiark.greenend.org.uk/~sgtatham/putty) to connect to the J-Link CDC UART port. Set the UART configuration to 115200/N/8/1.

**********
Zephyr DFU
**********

Please review the content for DFU Serial and OTA support at Zephyr_DFU_.

.. _Zephyr_DFU: https://github.com/Atmosic/openair/blob/HEAD/doc/dfu/dfu.rst
