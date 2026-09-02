/**
 *******************************************************************************
 *
 * @file ATM5xxx_mcuboot_partition_defs.h
 *
 * @brief Atmosic ATM5 partition definitions for use with mcuboot
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#ifndef _ATMOSIC_ATM_ATM5XXX_PARTITION_MCUBOOT_DEFS_H_
#define _ATMOSIC_ATM_ATM5XXX_PARTITION_MCUBOOT_DEFS_H_

// include the base definitions
#include <arm/atmosic/ATM5xxx_partition_defs.h>

// Enable swap-with-offset by default (Zephyr 4.3+ feature)
// This can be overridden by defining ATM_MCUBOOT_SWAP_WITH_OFFSET=0
#ifndef ATM_MCUBOOT_SWAP_WITH_OFFSET
#define ATM_MCUBOOT_SWAP_WITH_OFFSET 1
#endif

// override the base offsets/size, these will be adjusted based on partition
// layout
#undef ATM_SPE_OFFSET
#undef ATM_NSPE_OFFSET
#undef ATM_NSPE_SIZE
#undef ATM_APP_OFFSET
#undef ATM_APP_SIZE
#undef ATM_FACTORY_OFFSET
#undef ATM_STORAGE_OFFSET

// the OTP locks can lock 56KB or an additional 32KB to extend the bootloader
// for a total of 88KB
#define ATM_MCUBOOT_MIN_SIZE 0xE000
#define ATM_MCUBOOT_EXT_SIZE 0x8000
#ifndef ATM_MCUBOOT_SIZE
#define ATM_MCUBOOT_SIZE ATM_MCUBOOT_MIN_SIZE
#endif
#if (ATM_MCUBOOT_SIZE != ATM_MCUBOOT_MIN_SIZE) && \
    (ATM_MCUBOOT_SIZE != (ATM_MCUBOOT_MIN_SIZE + ATM_MCUBOOT_EXT_SIZE))
#error "Invalid MCUBOOT size"
#endif
#if ((ATM_MCUBOOT_SIZE % ATM_FLASH_BLOCK_SIZE) != 0)
#error "MCUBOOT size must be aligned"
#endif

#define ATM_MCUBOOT_OFFSET ATM_CONFIGURABLE_PART_START_OFFSET

#if (ATM_MCUBOOT_OFFSET < ATM_FLASH_START_OTP_LOCKABLE_OFFSET) ||                                  \
	((ATM_MCUBOOT_OFFSET + ATM_MCUBOOT_SIZE) > ATM_FLASH_END_OTP_LOCKABLE_OFFSET)
#error "MCUBOOT must be within the OTP lockable region"
#endif

#if ATM_MCUBOOT_SWAP_WITH_OFFSET
#define ATM_MCUBOOT_SCRATCH_SIZE 0
#else
#ifndef ATM_MCUBOOT_SCRATCH_SIZE
#define ATM_MCUBOOT_SCRATCH_SIZE 0x4000
#endif // ATM_MCUBOOT_SCRATCH_SIZE
#endif // ATM_MCUBOOT_SWAP_WITH_OFFSET

#if ((ATM_MCUBOOT_SCRATCH_SIZE % ATM_FLASH_BLOCK_SIZE) != 0)
#error "MCUBOOT scratch size must be aligned"
#endif

// reservation for the image trailer in slot0 aligned to the sector size
#ifndef ATM_SLOT0_TRAILER_RSVD_SIZE
#define ATM_SLOT0_TRAILER_RSVD_SIZE ATM_FLASH_BLOCK_SIZE
#endif
#if ((ATM_SLOT0_TRAILER_RSVD_SIZE % ATM_FLASH_BLOCK_SIZE) != 0)
#error "Slot trailer reservation must be aligned"
#endif

// factory data must reside in lockable memory
#define ATM_FACTORY_OFFSET (ATM_MCUBOOT_OFFSET + ATM_MCUBOOT_SIZE)

#define ATM_SLOT0_OFFSET (ATM_FACTORY_OFFSET + ATM_FACTORY_SIZE)
// SPE is the first image in SLOT0
#define ATM_SPE_OFFSET ATM_SLOT0_OFFSET
// define the usable FLASH area for images in slot 0
#define ATM_FLASH_IMG_USABLE_AREA_SIZE (FLASH_SIZE - ATM_SLOT0_OFFSET \
	- ATM_STORAGE_SIZE - ATM_MCUBOOT_SCRATCH_SIZE)

// MCUBOOT slot sizes depend on swap mechanism
#if ATM_MCUBOOT_SWAP_WITH_OFFSET
#define ATM_SLOT0_SIZE                                                                             \
	(ROUND_DOWN_FLASH_BLK(ATM_FLASH_IMG_USABLE_AREA_SIZE / 2) - ATM_FLASH_BLOCK_SIZE)
// For swap-with-offset: secondary slot = primary slot + 1 sector (4K)
// This allows the swap algorithm to work without a scratch partition
#define ATM_SLOT1_SIZE (ATM_SLOT0_SIZE + ATM_FLASH_BLOCK_SIZE)
#else
#define ATM_SLOT0_SIZE ROUND_DOWN_FLASH_BLK(ATM_FLASH_IMG_USABLE_AREA_SIZE / 2)
// Legacy mode: slots must be of equal size (for swap-with-scratch)
#define ATM_SLOT1_SIZE ATM_SLOT0_SIZE
#endif

// additional sanity checks
#if ((ATM_SLOT0_OFFSET % ATM_FLASH_BLOCK_SIZE) != 0)
#error "SLOT0 offset must be aligned"
#endif

#if ((ATM_SLOT0_SIZE % ATM_FLASH_BLOCK_SIZE) != 0)
#error "SLOT0 size must be aligned"
#endif

#if (ATM_SPE_SIZE)
#define ATM_NSPE_OFFSET  (ATM_SPE_OFFSET + ATM_SPE_SIZE)
// NSPE image size, less any trailer reservation
#define ATM_NSPE_SIZE (ATM_SLOT0_SIZE - ATM_SPE_SIZE - ATM_SLOT0_TRAILER_RSVD_SIZE)
#define ATM_SLOT0_TRAILER_RSVD_OFFSET (ATM_NSPE_OFFSET + ATM_NSPE_SIZE)
#else
#define ATM_APP_OFFSET                ATM_SLOT0_OFFSET
// APP image size, less any trailer reservation
#define ATM_APP_SIZE                  (ATM_SLOT0_SIZE - ATM_SLOT0_TRAILER_RSVD_SIZE)
#define ATM_SLOT0_TRAILER_RSVD_OFFSET (ATM_APP_OFFSET + ATM_APP_SIZE)
#endif
#if ((ATM_SLOT0_TRAILER_RSVD_OFFSET % ATM_FLASH_BLOCK_SIZE) != 0)
#error "SLOT0 trailer offset must be aligned"
#endif

#define ATM_MCUBOOT_SCRATCH_OFFSET (ATM_SLOT0_OFFSET + ATM_SLOT0_SIZE)
#define ATM_SLOT1_OFFSET (ATM_MCUBOOT_SCRATCH_OFFSET + ATM_MCUBOOT_SCRATCH_SIZE)
#define ATM_STORAGE_OFFSET (ATM_SLOT1_OFFSET + ATM_SLOT1_SIZE)

// NODE unit addresses, these are arbitrary and only need be unique
#define ATM_MCUBOOT_NODE_ID         cece0000
#define ATM_MCUBOOT_SCRATCH_NODE_ID cece0001
#define ATM_SLOT0_NODE_ID           cece0010
#define ATM_SLOT0_TRAILER_NODE_ID   cece0015
#define ATM_SLOT1_NODE_ID           cece0040

#endif // _ATMOSIC_ATM_ATM5XXX_PARTITION_MCUBOOT_DEFS_H_
