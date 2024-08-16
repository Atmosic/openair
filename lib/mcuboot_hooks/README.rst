Overview
********

This component extends the functionality of MCUBOOT.  This is handled
through a set of MCUBOOT-image-access and Zephyr-mcuboot action hooks.

A sample hook module (mcuboot_hooks.c) is provided to implement Atmosic
customizations of the bootloader.


Building and Running
********************

The library is used within the MCUBOOT application.  Please refer to the top-level
README.rst for information on building application images and passing options to
MCUBOOT.


Primary Slot Protection
***********************

This feature improves the security of the platform by sticky-write-locking
the primary slot before MCUBOOT passes control to the image.  The slot is
immutable until a system reset returns back to MCUBOOT which can perform image
upgrades of the primary slot (as needed).

To activate this feature set:

    CONFIG_ATM_MCUBOOT_PROTECT_PRIMARY_SLOT=y

When the SWAP upgrade strategy is used the primary slot's trailer is used
to confirm the image post boot.  This trailer must be left unlocked.
Consequently the trailer cannot share the same locked memory block as the
image in the slot.  To reserve the trailer in its own memory block that can be
left unlocked, follow these guidelines:

For ATM33/ATM34 platforms

    set the DTSI option:  -DATM_IMG_TRAILER_RSVD_SIZE=2048

    This will reserve the trailer at the end of the primary slot partition
    and keep any image data out of the unlocked area.  A value of 2048 is
    sufficient to support boot confirmations in test swaps.

In an OVERWRITE upgrade strategy the trailer does not need to be unlocked
and does not require a reservation.

Skip Primary Slot Validation on Hibernate Resume
************************************************

This feature enables fast (low latency) resume from Hibernate by allowing
the primary slot image to skip validation.  The skip is only performed
on a resume from a hibernate state and only if there is no pending upgrade.

To enable this feature:

    CONFIG_ATM_MCUBOOT_SKIP_PRIMARY_VALIDATE_HIBER=y

This feature will enable primary slot protection to allow this enhancement.
Please see the previous section on additional requirements when slot protection
is enabled.
