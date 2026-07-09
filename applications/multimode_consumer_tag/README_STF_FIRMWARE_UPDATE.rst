.. _stf_firmware_update_guide:

=====================================================
SmartThings Find (STF) Native Firmware Update Guide
=====================================================

Overview
========

This document describes how to prepare firmware images for **SmartThings native firmware update** feature using MCUboot on Atmosic platforms.

.. important::

   This guide is for **SmartThings native firmware update**, which is different from **Atmosic OTA mode**.

   - **SmartThings native firmware update**: Firmware is delivered via SmartThings Find Test Suite APP through the STF GATT service.
   - **Atmosic OTA mode**: Uses MCUmgr SMP over BLE, triggered by pressing Button2 10 times.

Firmware Update Procedure
=========================

Step 1: Build the Firmware
--------------------------

Build with MCUboot::

  west build -p always -b ATMEVK-3405-YBV-5@mcuboot \
    openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.mcuboot.ota

This generates ``build/multimode_consumer_tag/zephyr/zephyr.signed.bin``.

Step 2: Upload and Trigger Update
---------------------------------

1. Upload ``zephyr.signed.bin`` to SmartThings Find Test Suite APP
2. Trigger firmware update from Test Suite APP
3. Device reboots and MCUboot performs swap

MCUboot Swap Types
==================

The swap behavior depends on whether ``CONFIG_ATM_PAD_SIGNED_IMAGE`` is enabled:

Without CONFIG_ATM_PAD_SIGNED_IMAGE (default)
---------------------------------------------

The image does not contain BOOT_MAGIC trailer. MCUboot performs **permanent swap**::

  I: Image index: 0, Swap type: perm
  I: Starting swap using scratch algorithm.

With CONFIG_ATM_PAD_SIGNED_IMAGE=y
----------------------------------

Build with::

  west build ... -- -DCONFIG_ATM_PAD_SIGNED_IMAGE=y

This adds ``--pad`` to imgtool, which pads the image to full slot size and appends MCUboot trailer with BOOT_MAGIC.

.. code-block:: text

   ┌─────────────────────────────────────┐
   │ Header (0x200 bytes)                │
   ├─────────────────────────────────────┤
   │ Application Code + Signature        │
   ├─────────────────────────────────────┤
   │ Padding (0xFF bytes to fill slot)   │
   ├─────────────────────────────────────┤
   │ MCUboot Trailer:                    │
   │   - Swap status flags               │
   │   - image_ok / copy_done flags      │
   │   - BOOT_MAGIC (last 16 bytes)      │
   │     77 c2 95 f3 60 d2 ef 7f         │
   │     35 52 50 0f 2c b6 79 80         │
   └─────────────────────────────────────┘

MCUboot performs **test swap** when using ``zephyr.signed.bin`` built with ``CONFIG_ATM_PAD_SIGNED_IMAGE``::

  I: Image index: 0, Swap type: test
  I: Starting swap using scratch algorithm.
  ...
  [00:00:02.904,000] <inf> multimode_consumer_tag: Image confirmed successfully

After successful boot, the application calls ``boot_set_confirmed()`` to permanently confirm the image. If the new firmware fails to boot or confirm, MCUboot will revert to the previous image on next reboot.

XIP Dual-Image Upload (ATM34 External Flash)
============================================

When the build splits the firmware across RRAM and external flash
(typical ATM34 XIP build, ``CONFIG_ATM_SPLIT_IMG=y``), there are two
signed images to deliver:

- ``zephyr.signed.bin`` (Image 0, RRAM)
- ``zephyr.signed.flash.bin`` (Image 1, external flash)

Build with the XIP MCUboot OTA testcase::

  west build -p always -b ATMEVK-3405-YBV-5@mcuboot \
    openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.mcuboot.flash_xip.ota

The STF firmware update transport carries a single byte stream, so the
build packs both images into one upload file
``build/multimode_consumer_tag/zephyr/combined_fw_upd.bin``. Upload
that single file in place of ``zephyr.signed.bin`` at Step 2 above; the
device-side ``atm_vendor_dfu`` helper demultiplexes the stream and
stages both MCUboot secondary slots, then triggers a dual-image swap
on reboot.

For the binary format and the parser state machine, see
:ref:`atm_vendor_dfu`.
