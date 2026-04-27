.. _mcumgr_dfu:

MCUmgr DFU/OTA
##############

Overview
********

Zephyr uses the MCUmgr subsystem with the SMP protocol to perform DFU (Device Firmware Update).
This takes advantage of the MCUboot upgrade management features and requires the target device
to use an MCUboot application as the primary bootloader.

This subsystem provides ``CONFIG_ATM_MCUMGR`` which enables MCUmgr with image and OS management
command groups and selects all required dependencies. Transport-specific defaults are also
automatically applied based on whether you're using Bluetooth or Serial/UART transport.

.. tip::

   When using DFU it can be useful to version the images being flashed. Both the Atmosic mobile
   app and the MCUmgr utility will show the version of the application.
   The version can be set using ``CONFIG_MCUBOOT_IMGTOOL_SIGN_VERSION`` with the format
   ``"major.minor.revision+build"``, for example ``"2.1.0+0"``.

Usage
*****

Basic Configuration
===================

Enable MCUmgr and the desired transport in your ``prj.conf``:

**For Bluetooth OTA:**

.. code-block:: cfg

   CONFIG_ATM_MCUMGR=y
   CONFIG_MCUMGR_TRANSPORT_BT=y

**For Serial DFU:**

.. code-block:: cfg

   CONFIG_ATM_MCUMGR=y
   CONFIG_MCUMGR_TRANSPORT_UART=y

The subsystem will automatically configure:

* Core command groups (IMG_MANAGER, MCUMGR_GRP_IMG, MCUMGR_GRP_OS)
* Reasonable stack sizes
* Transport-specific settings (buffer sizes, reassembly, etc.)
* Bluetooth packet sizes for efficient transfers
* Storage erase command support

BLE DFU Security
================

The security level depends on whether ``CONFIG_BT_SMP`` is enabled:

* **BT_SMP enabled**: Defaults to the highest security level (``MCUMGR_TRANSPORT_BT_PERM_RW_AUTHEN``).
  To lower the security level, set one of:

  .. code-block:: cfg

     # Encryption only (no authentication)
     CONFIG_MCUMGR_TRANSPORT_BT_PERM_RW_ENCRYPT=y

     # No security
     CONFIG_MCUMGR_TRANSPORT_BT_PERM_RW=y

* **BT_SMP disabled**: Only ``MCUMGR_TRANSPORT_BT_PERM_RW`` is available (no security).

Serial DFU
**********

UART Configuration
==================

By default, Serial DFU is performed over UART0, which may be disabled.
Enable it by adding to your board's DTS file:

.. code-block:: dts

   &uart0 {
       status = "okay";
   };

Using mcumgr CLI
================

Install the ``mcumgr`` Golang utility:

.. code-block:: bash

   go install github.com/apache/mynewt-mcumgr-cli/mcumgr@latest

Save connection parameters:

.. code-block:: bash

   mcumgr conn add DEMO type="serial" connstring="dev=/dev/serial/by-id/usb-SEGGER_J-Link_<DEVICE_ID>-if00,baud=115200"

Test the connection:

.. code-block:: bash

   mcumgr -c DEMO echo hello

Performing DFU
==============

Upload and activate a new image:

.. code-block:: bash

   mcumgr -c DEMO image upload /path/to/zephyr.signed.bin

   OR for multiimage with image0 and image1

   mcumgr -c DEMO image upload /path/to/zephyr.signed.bin --image 0
   mcumgr -c DEMO image upload /path/to/zephyr.signed.bin --image 1

   mcumgr -c DEMO image list

   mcumgr -c DEMO image test <hash of Slot 1 image>

   OR for multiimage with image0 and image1

   mcumgr -c DEMO image test <hash of image0 Slot 1>
   mcumgr -c DEMO image test <hash of image1 Slot 1>

   mcumgr -c DEMO reset

* ``image test <hash>`` - Boot new image once, then restore original on next boot
* ``image confirm <hash>`` - Permanently switch to new image

Alternatively, call ``boot_write_img_confirmed()`` from within the application after self-test.

Building for DFU
****************

When building an application that supports DFU, MCUboot must be built and flashed.
Please see the platform specific instructions in the main README on how to build MCUboot.

External flash is always required for DFU operations. The secondary slot (slot1) for
MCUboot is always located in external flash.

