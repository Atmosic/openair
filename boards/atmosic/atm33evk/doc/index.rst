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

The atm33evk boards require at least two images to be built: the SPE and the application.  SPE is the Secure Processing Environment, and the application typically resides in the non-secure (NSPE) portion.

The Atmosic SPE can be found under ``<WEST_TOPDIR>/openair/samples/spe``.

.. _variable assignments:

In the remainder of this document, substitute for ``<ZEPHYR_TOOLCHAIN_VARIANT>``, ``<ZEPHYR_SDK_INSTALL_DIR>``, ``<WEST_TOPDIR>``, ``<SPE>``, ``<APP>``, ``<APP_NAME>``, ``<MCUBOOT>``, ``<ATMWSTK>``, ``<BOARD>``, and ``<DEVICE_ID>`` appropriately.  For example::

 <ZEPHYR_TOOLCHAIN_VARIANT>: zephyr
 <ZEPHYR_SDK_INSTALL_DIR>: /absolute/path/to/zephyrSDK
 <WEST_TOPDIR>: /absolute/path/to/zephyrproject
 <SPE>: openair/samples/spe
 <APP>: zephyr/samples/bluetooth/peripheral
 <APP_NAME>: APP Name for ISP section
 <MCUBOOT>: bootloader/mcuboot/boot/zephyr
 <ATMWSTK>: PD50 or FULL
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

There are two main options as stated above (with 2 suboptions):

---------------------
A. Non-MCUboot Option
---------------------

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Using Fixed BLE Link Controller Image for FULL Atmosic Wireless Stack (Suboption #1, ``<ATMWSTK>=FULL``, ``-DCONFIG_ATMWSTK_FULL=y``)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1a. Build the SPE:

::

  west build -p -s <SPE> -b <BOARD> -d build/<BOARD>/<SPE> -- -DDTS_EXTRA_CPPFLAGS="-DFIXED_ATMWSTK=<ATMWSTK>;"

2a. Build the Application:

Note: ``<BOARD>//ns`` is the non-secure variant of ``<BOARD>``.

Build the app with the non-secure board variant and the SPE configured as follows::

  west build -p -s <APP> -b <BOARD>//ns -d build/<BOARD>_ns/<APP> -- -DCONFIG_SPE_PATH=\"<WEST_TOPDIR>/build/<BOARD>/<SPE>\" -DDTS_EXTRA_CPPFLAGS="-DFIXED_ATMWSTK=<ATMWSTK>;" -DCONFIG_ATMWSTK_<ATMWSTK>=y -DCONFIG_ATM_EUI_ALLOW_RANDOM=y

Passing the path to the SPE is for linking in the non-secure-callable veneer file generated in building the SPE.

With this approach, each built image has to be flashed separately.  Optionally, build a single merged image by enabling ``CONFIG_MERGE_SPE_NSPE``, thereby minimizing the flashing steps::

  west build -p -s <APP> -b <BOARD>//ns -d build/<BOARD>_ns/<APP> -- -DCONFIG_SPE_PATH=\"<WEST_TOPDIR>/build/<BOARD>/<SPE>\" -DDTS_EXTRA_CPPFLAGS="-DFIXED_ATMWSTK=<ATMWSTK>;" -DCONFIG_ATMWSTK_<ATMWSTK>=y -DCONFIG_ATM_EUI_ALLOW_RANDOM=y -DCONFIG_MERGE_SPE_NSPE=y

3a. Flashing the SPE and the Application:

``west flash`` is used to program a device with the necessary images, often only built as described above and sometimes also with a pre-built library provided as an ELF binary.

For an atmevk33 board, this is typically a J-Link serial number, but it can also be an FTDI serial number of the form ``ATRDIXXXX`` if not an EVK.  For a J-Link board, pass the ``--jlink`` option to the flash runner as in ``west flash --jlink ...``.

If the application requires Bluetooth (configured with ``CONFIG_BT`` in the prj.conf file) and uses the fixed BLE link controller image option, then the controller image requires programming.  This is typically done before programming the application and resetting (omitting the ``--noreset`` option to ``west flash``). For example::

  west flash --verify --device <DEVICE_ID> --jlink --fast_load --skip-rebuild -d build/<BOARD>/<SPE> --use-elf --elf-file openair/modules/hal_atmosic/ATM33xx-5/drivers/ble/atmwstk_<ATMWSTK>.elf --noreset

Atmosic provides a mechanism to increase the legacy programming time called FAST LOAD. Apply the option ``--fast_load`` to enable the FAST LOAD.

Flash the SPE and the application separately if ``CONFIG_MERGE_SPE_NSPE`` was not enabled::

  west flash --device <DEVICE_ID> --jlink --fast_load --verify -d build/<BOARD>/<SPE> --noreset
  west flash --device <DEVICE_ID> --jlink --fast_load --verify -d build/<BOARD>_ns/<APP>

Alternatively, if ``CONFIG_MERGE_SPE_NSPE`` was enabled in building the application, the first step (programming the SPE) can be skipped.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Using Statically Linked BLE Link Controller Library for PD50 Atmosic Wireless Stack (Suboption #2, ``<ATMWSTK>=PD50``, ``-DCONFIG_ATMWSTK_PD50=y`` (default))
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1b. Build the SPE:

::

  west build -p -s <SPE> -b <BOARD> -d build/<BOARD>/<SPE>

2b. Build the Application:

Note: ``<BOARD>//ns`` is the non-secure variant of ``<BOARD>``.

Build the app with the non-secure board variant and the SPE configured as follows::

  west build -p -s <APP> -b <BOARD>//ns -d build/<BOARD>_ns/<APP> -- -DCONFIG_SPE_PATH=\"<WEST_TOPDIR>/build/<BOARD>/<SPE>\" -DCONFIG_ATMWSTK_<ATMWSTK>=y -DCONFIG_ATM_EUI_ALLOW_RANDOM=y

Passing the path to the SPE is for linking in the non-secure-callable veneer file generated in building the SPE.

With this approach, each built image has to be flashed separately.  Optionally, build a single merged image by enabling ``CONFIG_MERGE_SPE_NSPE``, thereby minimizing the flashing steps::

  west build -p -s <APP> -b <BOARD>//ns -d build/<BOARD>_ns/<APP> -- -DCONFIG_SPE_PATH=\"<WEST_TOPDIR>/build/<BOARD>/<SPE>\" -DCONFIG_ATMWSTK_<ATMWSTK>=y -DCONFIG_ATM_EUI_ALLOW_RANDOM=y -DCONFIG_MERGE_SPE_NSPE=y

3b. Flashing the SPE and the Application:

Atmosic provides a mechanism to increase the legacy programming time called FAST LOAD. Apply the option ``--fast_load`` to enable the FAST LOAD.

Flash the SPE and the application separately if ``CONFIG_MERGE_SPE_NSPE`` was not enabled::

  west flash --device <DEVICE_ID> --jlink --fast_load --verify -d build/<BOARD>/<SPE> --noreset
  west flash --device <DEVICE_ID> --jlink --fast_load --verify -d build/<BOARD>_ns/<APP>

Alternatively, if ``CONFIG_MERGE_SPE_NSPE`` was enabled in building the application, the first step (programming the SPE) can be skipped.

-----------------
B. MCUboot Option
-----------------

.. _MCUboot option:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Using Fixed BLE Link Controller Image for FULL Atmosic Wireless Stack (Suboption #1, ``<ATMWSTK>=FULL``, ``-DCONFIG_ATMWSTK_FULL=y``)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1a. Build the MCUboot and the SPE:

To build with MCUboot, for example, DFU is needed, first build MCUboot::

  west build -p -s <MCUBOOT> -b <BOARD>@mcuboot_bl -d build/<BOARD>/<MCUBOOT> -- -DDTS_EXTRA_CPPFLAGS="-DFIXED_ATMWSTK=<ATMWSTK>;-DDFU_IN_FLASH"

and then the Atmosic SPE::

  west build -p -s <SPE> -b <BOARD>@mcuboot -d build/<BOARD>/<SPE> -- -DCONFIG_BOOTLOADER_MCUBOOT=y -DCONFIG_MCUBOOT_GENERATE_UNSIGNED_IMAGE=n -DDTS_EXTRA_CPPFLAGS="-DFIXED_ATMWSTK=<ATMWSTK>;-DDFU_IN_FLASH"

Note that make use of "board revision" to configure our board partitions to work for MCUboot.  On top of the "revisions," MCUboot currently needs an additional overlay that must be provided through the command line to give it the entire SRAM.

2a. Build the Application with MCUboot and SPE:

Build the application with MCUboot and SPE as follows::

  west build -p -s <APP> -b <BOARD>@mcuboot//ns -d build/<BOARD>_ns/<APP> -- -DCONFIG_BOOTLOADER_MCUBOOT=y -DCONFIG_MCUBOOT_SIGNATURE_KEY_FILE=\"bootloader/mcuboot/root-ec-p256.pem\" -DCONFIG_SPE_PATH=\"<WEST_TOPDIR>/build/<BOARD>/<SPE>\" -DDTS_EXTRA_CPPFLAGS="-DFIXED_ATMWSTK=<ATMWSTK>;-DDFU_IN_FLASH" -DCONFIG_ATMWSTK_<ATMWSTK>=y -DCONFIG_ATM_EUI_ALLOW_RANDOM=y -DEXTRA_CONF_FILE="<WEST_TOPDIR>/openair/doc/dfu/overlay-bt-dfu.conf"

This is somewhat of a non-standard workflow.  When passing ``-DCONFIG_BOOTLOADER_MCUBOOT=y`` on the application build command line, ``west`` automatically creates a signed, merged image (``zephyr.signed.{bin,hex}``), which is ultimately used by ``west flash`` to program the device.  The original application binaries are renamed with a ``.nspe`` suffixed to the file basename (``zephyr.{bin,hex,elf}`` renamed to ``zephyr.nspe.{bin,hex,elf}``) and are the ones that should be supplied to a debugger.

3a. Flashing the MCUboot, SPE, and the Application:

Flash MCUboot

Atmosic provides a mechanism to increase the legacy programming time called FAST LOAD. Apply the option ``--fast_load`` to enable the FAST LOAD.::

   west flash --verify --device <DEVICE_ID> --jlink --fast_load -d build/<BOARD>/<MCUBOOT> --noreset

Note that adding ``--erase_flash`` is an option to erase Flash if needed.

Flash the signed application image (merged with SPE)::

   west flash --verify --device <DEVICE_ID> --jlink --fast_load -d build/<BOARD>_ns/<APP>

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Using Statically Linked BLE Link Controller Library for PD50 Atmosic Wireless Stack (Suboption #2, ``<ATMWSTK>=PD50``, ``-DCONFIG_ATMWSTK_PD50=y`` (default))
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1b. Build the MCUboot and the SPE:

To build with MCUboot, for example, DFU is needed, first build MCUboot::

  west build -p -s <MCUBOOT> -b <BOARD>@mcuboot_bl -d build/<BOARD>/<MCUBOOT> -- -DDTS_EXTRA_CPPFLAGS="-DDFU_IN_FLASH"

and then the Atmosic SPE::

  west build -p -s <SPE> -b <BOARD>@mcuboot -d build/<BOARD>/<SPE> -- -DCONFIG_BOOTLOADER_MCUBOOT=y -DCONFIG_MCUBOOT_GENERATE_UNSIGNED_IMAGE=n -DDTS_EXTRA_CPPFLAGS="-DDFU_IN_FLASH"

Note that make use of "board revision" to configure our board partitions to work for MCUboot.  On top of the "revisions," MCUboot currently needs an additional overlay that must be provided through the command line to give it the entire SRAM.

2b. Build the Application with MCUboot and SPE:

Build the application with MCUboot and SPE as follows::

  west build -p -s <APP> -b <BOARD>@mcuboot//ns -d build/<BOARD>_ns/<APP> -- -DCONFIG_ATM_EUI_ALLOW_RANDOM=y -DCONFIG_BOOTLOADER_MCUBOOT=y -DCONFIG_MCUBOOT_SIGNATURE_KEY_FILE=\"bootloader/mcuboot/root-ec-p256.pem\" -DCONFIG_SPE_PATH=\"<WEST_TOPDIR>/build/<BOARD>/<SPE>\" -DCONFIG_ATMWSTK_<ATMWSTK>=y -DDTS_EXTRA_CPPFLAGS="-DDFU_IN_FLASH" -DEXTRA_CONF_FILE="<WEST_TOPDIR>/openair/doc/dfu/overlay-bt-dfu.conf"

This is somewhat of a non-standard workflow.  When passing ``-DCONFIG_BOOTLOADER_MCUBOOT=y`` on the application build command line, ``west`` automatically creates a signed, merged image (``zephyr.signed.{bin,hex}``), which is ultimately used by ``west flash`` to program the device.  The original application binaries are renamed with a ``.nspe`` suffixed to the file basename (``zephyr.{bin,hex,elf}`` renamed to ``zephyr.nspe.{bin,hex,elf}``) and are the ones that should be supplied to a debugger.

3b. Flashing the MCUboot, SPE, and the Application:

Flash MCUboot

Atmosic provides a mechanism to increase the legacy programming time called FAST LOAD. Apply the option ``--fast_load`` to enable the FAST LOAD.::

  west flash --verify --device <DEVICE_ID> --jlink --fast_load -d build/<BOARD>/<MCUBOOT> --noreset

Note that adding ``--erase_flash`` is an option to erase Flash if needed.

Flash the signed application image (merged with SPE)::

  west flash --verify --device <DEVICE_ID> --jlink --fast_load -d build/<BOARD>_ns/<APP>

---------------------------
BLE Link Controller Options
---------------------------

When building a Bluetooth application (``CONFIG_BT``), the BLE driver component provides two link controller options. A fixed BLE link controller image and a statically linked BLE link controller library.  The BLE link controller sits at the lowest layer of the Zephyr Bluetooth protocol stack.  Zephyr provides the upper Bluetooth Host stack that can interface with BLE link controllers that conform to the standard Bluetooth Host Controller Interface specification.

To review how the fixed and statically linked controllers are used, please refer to the README.rst in openair/modules/hal_atmosic/ATM33xx-5/drivers/ble/.

If the ATM33 entropy driver is enabled without CONFIG_BT=y (mainly for evaluation), the system still requires a minimal BLE controller stack.  Without choosing a specific stack configuration an appropriate minimal BLE controller will be selected.  This may increase the size of your application.

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

**************************
Building with Secure Debug
**************************

Secure Debug is a collection of hardware and software features to limit access to the debug port for devices in production. It is not intended to be used in development because once security measures are enabled many steps in the normal development flow will no longer function.

=====================
Managing the OTP bits
=====================

At a hardware level, the debug security state at power-on is defined by two OTP bits (ATM_OTP_MASK_SEC_DBG_DEBUG_SECURED and ATM_OTP_MASK_SEC_DBG_DEBUG_DISABLED).
Hardware applies the debug security state prior to the CPU booting.  No intervention is required by software to enforce the security state.  When secure debug is either SECURED or DISABLED, access through SWD is disallowed even if benign boot is enabled. When the port is SECURED (rather than DISABLED), the state can be cleared by software after a software challenge to prove the identity of the debug access requester.  The authenticator is implemented in the MCUboot image that monitors a UART console port.

To check the state of the OTP bits, users can use the atmotp west extension by issuing the following command::

 west atmotp get --board <BOARD> --device <DEVICE_ID> --otp SEC_DBG_CONFIG.DEBUG_DISABLED

or::

 west atmotp get --board <BOARD> --device <DEVICE_ID> --otp SEC_DBG_CONFIG.DEBUG_SECURED

To completely disable secure debug, users can issue the following command (this is irreversible)::

 west atmotp burn --board <BOARD> --device <DEVICE_ID> --otp SEC_DBG_CONFIG.DEBUG_DISABLED

To enable secure debug, users can issue the following command::

 west atmotp get --board <BOARD> --device <DEVICE_ID> --otp SEC_DBG_CONFIG.DEBUG_SECURED

The authenticator software component runs during the boot sequence of MCUboot. Secure debug is not accessible in Non-MCUboot builds. If no authentication occurs, the software will sticky lock the debug port until reset.  A Python script is provided to demonstrate communications with the MCUboot authenticator to unlock the debug port.  The challenge/authentication process must be performed on each boot.  The challenge consists of a unique hash of per-device data stored in the secure journal.  This is computed by the MCUboot image and provided as a base64 encoded text output on the UART console port.  The hash will be unique for each manufactured device.  The challenge must be signed with the private ECDSA key and the resulting signature provided back to the authenticator to verify it using its local public ECDSA key.   The signature is unique for the device and can be used for every challenge response.

-----------------------------------
Compiling MCUboot with Secure Debug
-----------------------------------

To build with secure debug, add the following additional flags::

  -DCONFIG_ATM_MCUBOOT_SECURE_DEBUG=y -DDTS_EXTRA_CPPFLAGS="-DUSE_ATM_SECURE_DEBUG"

NOTE: if building with DFU_IN_FLASH, then your flags will look like this::

  -DCONFIG_ATM_MCUBOOT_SECURE_DEBUG=y -DDTS_EXTRA_CPPFLAGS="-DDFU_IN_FLASH;-DUSE_ATM_SECURE_DEBUG"

The DTS option ``-DUSE_ATM_SECURE_DEBUG`` will enable UART0 as a bi-directional console port for authentication use.

The MCUboot extension for secure debug will use a default private ECC-P256 key to generate the public ECC-P256 key stored in the image.  This is a widely distributed key and should not be used in production.

At this time the authenticator implements a 500ms default timeout through ``CONFIG_ATM_MCUBOOT_UART_DEBUG_AUTH_TIMEOUT_MS`` while monitoring the console port for characters.  You can adjust as needed ``-DCONFIG_ATM_MCUBOOT_UART_DEBUG_AUTH_TIMEOUT_MS=<milliseconds>`` to extend the timeout. A future update will support monitoring the UART RX pin for a logic high state to detect the presence of a host UART connection.

-----------------------------
Using the Debug Unlock Script
-----------------------------

A debug unlock Python script is provided in ``openair/tools/scripts/sec_debug_unlock.py``. This tool requires PySerial. ::

  python sec_debug_unlock.py -v -k <private ECC-P256 key in .pem format> -p <console port>

To unlock using the default private key in ``openair/lib/atm_debug_auth/`` ::

  python sec_debug_unlock.py -v -k openair/lib/atm_debug_auth/root-debug-ec-p256.pem -p <console port>

The unlocking script using the ``-v`` option will verbosely output::

  Sending: b'DBG REQUEST\n'
  Received: b'Static Challenge: o9H3wvgqOfAi/mvTV/qvvdNjBqzGILIai3G4OBURjhE=\n'
  Unlock Static Challenge
  Sending: b'DBG STATIC_RESPONSE sMdx+QFewpAt3Dnqy9BrjSLNxgtObtu3IKhSvpuvbG7J9IClpt/zJL4XRlo9rt7KCCw6orjUIyBdaWWM657aRw==\n'
  Received: b'Debug unlocked\n'

The SWD port will be unlocked and MCUboot will remain in a benign state with the processor halted at a WFI instruction (Wait For Interrupt).  The developer can freely attach a debugger such as GDB and inspect the target (read memory, set breakpoints).  If the debugger allows the CPU to continue then MCUboot will continue its boot from the point at which WFI was entered.
