.. _atm_vendor_dfu:

============================================
atm_vendor_dfu - Vendor Protocol DFU Helper
============================================

Overview
========

``atm_vendor_dfu`` is a small helper library that adapts vendor firmware
update transports (Samsung TagSDK, Apple FMNA UARP, ...) onto the
MCUboot secondary slots without requiring each vendor port to know the
local partition layout.

Two modes are supported and selected at compile time from the
devicetree:

* **Single-image mode** - ``slot1_partition`` only. Bytes are streamed
  directly into ``slot1_partition``.
* **Dual-image mode** - ``slot1_partition`` and ``slot3_partition``
  both present (typical ATM34 XIP build). The stream begins with a
  32-byte ``ATMX`` header whose two size fields drive routing of the
  payload to ``slot1_partition`` (Image 0, RRAM) and
  ``slot3_partition`` (Image 1, external flash).

When ``CONFIG_BOOT_SWAP_USING_OFFSET`` is enabled the helper shifts
each slot write by the first sector size of the secondary slot so
MCUboot accepts the staged image.

If ``slot1_partition`` is missing in the build, every API call returns
``-ENOTSUP``. This lets the prebuilt vendor libraries link cleanly
against system builds that have no MCUboot.

API
===

See ``atm_vendor_dfu.h`` for the full Doxygen documentation. The
typical call sequence from a vendor transport is:

.. code-block:: c

   atm_vendor_dfu_init();
   /* for each chunk arriving at stream offset O with length L */
   if (!O) {
       atm_vendor_dfu_reset();
   }
   atm_vendor_dfu_write(buf, L);
   /* on transport-reported success */
   atm_vendor_dfu_request_upgrade();
   sys_reboot(SYS_REBOOT_COLD);

Combined Binary Format (Dual-Image Mode)
========================================

The combined binary has a fixed 32-byte header followed by the two
signed images concatenated in order:

.. code-block:: text

   Offset  Size  Field
   -----------------------------------------------------------
   0x00    4     Magic: 0x584D5441  ("ATMX" little-endian)
   0x04    4     Version: 0x00000001
   0x08    4     Image 0 size  (bytes)
   0x0C    4     Image 1 size  (bytes)
   0x10    16    Reserved (zero-padded)
   -----------------------------------------------------------
   0x20    N0    zephyr.signed.bin        (Image 0, RRAM)
   0x20+N0 N1    zephyr.signed.flash.bin  (Image 1, External Flash)

The packing script ``scripts/pack_combined_image.py`` produces this
layout. The library exposes a CMake helper
``atm_pack_combined_image(IMG0 <path> IMG1 <path> OUTPUT <path>)``;
``multimode_consumer_tag`` invokes it automatically when
``zephyr.signed.bin`` and ``zephyr.signed.flash.bin`` are both
generated.

Device-Side State Machine (Dual-Image Mode)
===========================================

``atm_vendor_dfu.c`` implements a stream parser:

1. **HEADER** - Read the first 32 bytes, validate the ``ATMX`` magic
   and version, and store the two image sizes.
2. **IMAGE0** - Route the next ``img0_size`` bytes to
   ``slot1_partition``.
3. **IMAGE1** - Route the remaining ``img1_size`` bytes to
   ``slot3_partition``.

On ``atm_vendor_dfu_request_upgrade()`` the helper iterates from
image index 0 to ``CONFIG_UPDATEABLE_IMAGE_NUMBER - 1`` and calls
``boot_request_upgrade_multi()`` for each, so MCUboot swaps every
staged image on the next reboot.
