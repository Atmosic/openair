Zephyr DFU
##########

Zephyr uses the MCUmgr subsystem with the SMP protocol to perform DFU.
This takes advantage of the MCUboot upgrade management features.
It requires the target device to use an MCUboot application as the primary bootloader.

Overlay files for Serial DFU (``overlay-serial-dfu.conf``) and for BLE OTA (``overlay-bt-dfu.conf``) are provided in this directory and can be added to a sample in order to add DFU functionality.
They may either be used individually, or together depending on what forms of DFU are desired.
By including both overlays, the ability to perform Serial DFU and BLE OTA will be supported.

When using DFU it can be useful to version the images being flashed, both the Atmosic mobile app and the MCUmgr utility will show the version of the application.
The version of the image can be set using the `CONFIG_MCUBOOT_IMGTOOL_SIGN_VERSION <https://docs.zephyrproject.org/latest/kconfig.html#CONFIG_MCUBOOT_IMGTOOL_SIGN_VERSION>`_ Kconfig option.
This Kconfig option expects a string using the format of ``"major.minor.revision+build"``, for example ``"2.1.0+0"``, however ``"+build"`` is optional.
The version data will then be stored in the image header that is created by the MCUboot image signing tools.

Using the Overlay Files
=======================
There are three methods for using the provided overlay files:

1. The absolute path to the overlay files may be provided to the build using the ``-DEXTRA_CONF_FILE="${WEST_TOPDIR}/openair/doc/dfu/overlay-bt-dfu.conf"`` build option. Multiple overlays may be provided if they are separated by semicolons.
2. The files can be copied to the directory of the sample where ``prj.conf`` is located, this also uses the ``-DEXTRA_CONF_FILE`` option when building to specify which should be included in the build. This does not need the absolute path to be provided but instead just the file name(s).
3. The options from the provided overlay files may be copied directly into a project's ``prj.conf``. This should only be done if the application always requires these options.

**NOTE:** These overlay files make changes to the `System Workqueue <https://docs.zephyrproject.org/latest/kconfig.html#CONFIG_SYSTEM_WORKQUEUE_STACK_SIZE>`_ and `Main <https://docs.zephyrproject.org/latest/kconfig.html#CONFIG_MAIN_STACK_SIZE>`_ stack sizes.
If a sample sets a different size in its ``prj.conf`` it may be overwritten by these overlay files.
``overlay-bt-dfu.conf`` will also configure the GATT MTU size and some other BLE related options.
This can override the original parameters set by the sample and change its behavior.

Building for DFU
================

When building an application that supports DFU, MCUboot must be built and flashed (and the SPE with MCUboot enabled for platforms with TrustZone).
Please see the `platform specific instructions <../../README.rst#supported-platforms>`_ on how to build MCUboot.

For most configurations, additional (external) flash is not required but is supported if desired.
When additional flash is used, the ``-DDFU_IN_FLASH`` flag should be added to ``-DDTS_EXTRA_CPPFLAGS``.

* On the ATMx2 platform additional flash is not required.
* On the ATM33 platform additional flash **IS** required when using BLE OTA with ``ATMWSTKLIB`` but is not required when using ``ATMWSTK``.
* On the ATM34 platform additional flash is always required. ``DFU_IN_FLASH`` is the default and does not need to be specified.

Here is an example build command for the ATM33 platform that uses the ``LL`` BLE stack with external flash, which uses `method 2 <#using-the-overlay-files>`_ to provide both overlay files to enable BLE and UART based DFU::

    west build -p -s ${APP} -b ${BOARD}@mcuboot//ns -d build/${BOARD}_ns/${APP} -- \
        -DCONFIG_BOOTLOADER_MCUBOOT=y -DCONFIG_MCUBOOT_SIGNATURE_KEY_FILE=\"bootloader/mcuboot/root-ec-p256.pem\" \
        -DCONFIG_SPE_PATH=\"build/${BOARD}/${SPE}\" \
        -DDTS_EXTRA_CPPFLAGS="-DATMWSTK=LL;-DDFU_IN_FLASH" -DCONFIG_USE_ATMWSTK=y -DCONFIG_ATMWSTK=\"LL\" \
        -DEXTRA_CONF_FILE="overlay-bt-dfu.conf;overlay-serial-dfu.conf"

To perform a BLE OTA update the Atmosic Mobile Application may be used, and for Serial DFU the ``mcumgr`` utility may be used.

BLE DFU Security
================

By default, the provided BLE overlay file requires pairing the device.
This is more secure than having no security, but could be at risk to a Man-in-the-Middle attack during the pairing process.
To also require authentication, some logic can be added to the application to perform this process and ``CONFIG_MCUMGR_TRANSPORT_BT_PERM_RW_ENCRYPT`` should be changed to ``CONFIG_MCUMGR_TRANSPORT_BT_PERM_RW_AUTHEN``.
If no security is desired, then the ``CONFIG_BT_SMP`` and ``CONFIG_MCUMGR_TRANSPORT_BT_PERM_RW_ENCRYPT`` lines can be removed.

Serial DFU
==========

By default, Serial DFU is performed over UART0, which is usually disabled.
This can be enabled by adding ``status = "okay";`` line to the ``uart0`` block of the boards DTS file.
For Atmosic EVKs this can be found in ``${WEST_TOPDIR}/zephyr/boards/atmosic/``::

    &uart0 {
        status = "okay";
    };

**NOTE:** Make sure to use the DTS file that is being used for the application.
For platforms with TrustZone this will usually be the Non-Secure version, typically indicated by ``_ns``.

When performing Serial DFU the ``mcumgr`` Golang utility is used. It may be installed using the following command::

    go install github.com/apache/mynewt-mcumgr-cli/mcumgr@latest

When using ``mcumgr`` the connection parameters can be passed using ``--conntype serial --connstring "dev=<SERIAL DEVICE>,baud=<BAUD RATE>"``.
Alternatively, the parameters may be saved using the following command (example parameters are given)::

    mcumgr conn add <NAME> type="serial" connstring="dev=/dev/serial/by-id/usb-SEGGER_J-Link_${SERIAL}-if00,baud=115200"

This allows the use of ``mcumgr -c <NAME>`` so that the options do not need to be passed each time.
The rest of this guide will assume a connection was saved using a ``<NAME>`` of ``DEMO``.

Once ``mcumgr`` is setup, the connection may be easily tested using ``mcumgr -c DEMO echo hello``.
This is a simple echo test and should give a response of ``hello`` as output.
If there is an error, such as an ``NMP Timeout``, then the connection parameters and software configuration should be inspected for issues.

To actually perform the DFU, the ``image upload`` command is used.
Once the image has been uploaded, the ``image list`` command is used to see the images present on the device.
Slot 0 will have the active running image, and Slot 1 will have the newly uploaded image.
The hash from the Slot 1 image is then used to either mark it for testing ``image test <hash>``, or to mark it as confirmed ``image confirm <hash>``.
Marking an image as "testing" means that the new image will be booted for the next boot and then will restore the original image on the boot after that.
Marking an image as "confirmed" means that it will swap to the new image on reboot and continue to run that.
A typical sequence may use the ``image test`` command to verify that it is functioning correctly and then use the ``image confirm`` command to make it official.
Alternatively, a self-test in the software may be added and then upon success the ``boot_write_img_confirmed()`` function may be used to confirm it from within the application.
Since a reset is necessary to swap images, the ``reset`` command may be used to perform this.
Alternatively, the board may be physically reset using a board-level reset mechanism.

As an example, here is a sequence of commands that may be used to upload the new image and then reboot into it::

    mcumgr -c DEMO image upload /path/to/zephyr.signed.bin
    mcumgr -c DEMO image list
    mcumgr -c DEMO image test <hash of Slot 1 image from list command>
    mcumgr -c DEMO reset
