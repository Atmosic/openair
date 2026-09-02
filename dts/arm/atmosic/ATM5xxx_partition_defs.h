/**
 *******************************************************************************
 *
 * @file ATM5xxx_partition_defs.h
 *
 * @brief Atmosic ATM5 partition definitions
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#ifndef _ATMOSIC_ATM_ATM5XXX_PARTITION_DEFS_H_
#define _ATMOSIC_ATM_ATM5XXX_PARTITION_DEFS_H_

#ifdef ATM_NO_TZ
#undef ATM_SPE_SIZE
#define ATM_SPE_SIZE 0
#endif

#ifdef ATM_APP_PART_DEFS
#include ATM_APP_PART_DEFS
#endif

/* aligned to the erase block size of flash memory */
#define ATM_FLASH_BLOCK_SIZE 4096
#define ROUND_DOWN_FLASH_BLK(s) \
	(((s) / ATM_FLASH_BLOCK_SIZE) * ATM_FLASH_BLOCK_SIZE)
#define ATM_FLASH_SIDE_LOAD_KEYS_SIZE 4096
#define ATM_FLASH_SEC_JOURNAL_SIZE 4096
#define ATM_FLASH_SEC_RSVD_SIZE  (ATM_FLASH_SIDE_LOAD_KEYS_SIZE + \
	ATM_FLASH_SEC_JOURNAL_SIZE)
#define ATM_FLASH_SEC_RSVD_OFFSET 0

/* start of configurable partitions */
#define ATM_CONFIGURABLE_PART_START_OFFSET (ATM_FLASH_SEC_RSVD_OFFSET + \
	ATM_FLASH_SEC_RSVD_SIZE)

/* maximum offset for write lockable memories */
#define ATM_FLASH_WRITE_LOCKABLE_REGION_END (1024 * 1024)
/* maximum offset for read lockable memories */
#define ATM_FLASH_READ_LOCKABLE_REGION_END  (96 * 1024)
/* start / end for OTP lockable memories */
#define ATM_FLASH_START_OTP_LOCKABLE_OFFSET ATM_CONFIGURABLE_PART_START_OFFSET
#define ATM_FLASH_END_OTP_LOCKABLE_OFFSET   ATM_FLASH_READ_LOCKABLE_REGION_END

#define ATM_AVAIL_FLASH_SIZE (FLASH_SIZE - ATM_FLASH_SEC_RSVD_SIZE)

/* offset for OTP lockable memories */
#define ATM_FLASH_OTP_LOCKABLE_OFFSET ATM_CONFIGURABLE_PART_START_OFFSET
#define ATM_FLASH_OTP_LOCKABLE_SIZE   (88*1024)
/*
   A few general rules on placement

   -) The first ATM_FLASH_SEC_RSVD_SIZE blocks are not configurable. These
      are specially treated flash blocks for key side loading and journal locking
   -) The entry point where the ROM hands off execution is after the secure reserved area.
   -) The factory data partition should be located in the lower range to
      guarantee that they can be sticky write locked. Generally after the SPE
   -) The storage parition should be placed at the end for growth and the use of
      larger filesystems (i.e. littleFS).
*/

#define ATM_SPE_OFFSET ATM_CONFIGURABLE_PART_START_OFFSET

#ifndef ATM_SPE_SIZE
#define ATM_SPE_SIZE (28 * 1024)
#endif
#if ((ATM_SPE_SIZE % ATM_FLASH_BLOCK_SIZE) != 0)
#error "SPE size must be aligned"
#endif

#ifndef ATM_FACTORY_SIZE
#define ATM_FACTORY_SIZE 0x2000
#elif (ATM_FACTORY_SIZE < 0x2000)
#undef ATM_FACTORY_SIZE
#define ATM_FACTORY_SIZE 0x2000
#endif
#if ((ATM_FACTORY_SIZE % ATM_FLASH_BLOCK_SIZE) != 0)
#error "Factory size must be aligned"
#endif

#ifndef ATM_STORAGE_SIZE
#define ATM_STORAGE_SIZE 0x4000
#elif (ATM_STORAGE_SIZE < 0x2000)
#undef ATM_STORAGE_SIZE
#define ATM_STORAGE_SIZE 0x2000
#endif
#if ((ATM_STORAGE_SIZE % ATM_FLASH_BLOCK_SIZE) != 0)
#error "Storage size must be aligned"
#endif

#define ATM_TOTAL_STORAGE_SIZE (ATM_STORAGE_SIZE + ATM_FACTORY_SIZE)

#if ATM_SPE_SIZE
/* keep factory data after the SPE to remain lockable */
#define ATM_FACTORY_OFFSET  (ATM_SPE_OFFSET + ATM_SPE_SIZE)

#define ATM_NSPE_OFFSET (ATM_FACTORY_OFFSET + ATM_FACTORY_SIZE)
#define ATM_NSPE_SIZE (ATM_AVAIL_FLASH_SIZE - ATM_SPE_SIZE \
	- ATM_TOTAL_STORAGE_SIZE)

/* regular storage placed after NSPE */
#define ATM_STORAGE_OFFSET (ATM_NSPE_OFFSET + ATM_NSPE_SIZE)
#else
/* APP runs from flash without a SPE */
#define ATM_APP_OFFSET     ATM_CONFIGURABLE_PART_START_OFFSET
/* Ensure factory region remains write lockable */
#define ATM_FACTORY_OFFSET (ATM_FLASH_WRITE_LOCKABLE_REGION_END - ATM_TOTAL_STORAGE_SIZE)
#define ATM_APP_SIZE       (ATM_FACTORY_OFFSET - ATM_APP_OFFSET)
/* regular storage placed after factory  */
#define ATM_STORAGE_OFFSET (ATM_FACTORY_OFFSET + ATM_FACTORY_SIZE)
#endif

/* NODE unit addresses, these are arbitrary and only need be unique */
#define ATM_SPE_NODE_ID     cece0011
#define ATM_NSPE_NODE_ID    cece0012
#define ATM_APP_NODE_ID      cece0013
#define ATM_FACTORY_NODE_ID cece0050
#define ATM_STORAGE_NODE_ID cece0051
#define ATM_SEC_RSVD_NODE_ID cece00f0
#define ATM_COREDUMP_NODE_ID cece00f1
#define ATM_LC_PARTITION_NODE_ID cece0060
#define ATM_ROM_APPLICATION_NODE_ID cece0061

/*
   ROM (rom0) partition geometry

   default layout:                            boot_rom | lc_partition
   rom_application layout (ATM_LC_PARTITION_END < ROM_SIZE):
                                              boot_rom | lc_partition | rom_application

   lc_partition keeps a fixed start directly after the boot ROM. ATM_LC_PARTITION_END
   is the end address of the link-controller partition (boot_rom + lc_partition) and
   matches the ROM_SIZE the lc build is linked against
   (lcrom.ld: ROM LENGTH = ATM_LC_PARTITION_END - 0x2000). It defaults to the full
   ROM, leaving no free space. When a board sets it below ROM_SIZE, the rom_application
   region is enabled to fill the remaining ROM tail.
*/
#define ATM_BOOT_ROM_OFFSET 0x0
#define ATM_BOOT_ROM_SIZE   0x2000

#define ATM_LC_PARTITION_OFFSET (ATM_BOOT_ROM_OFFSET + ATM_BOOT_ROM_SIZE)

#ifndef ATM_LC_PARTITION_END
#define ATM_LC_PARTITION_END ROM_SIZE
#endif
#define ATM_LC_PARTITION_SIZE (ATM_LC_PARTITION_END - ATM_LC_PARTITION_OFFSET)

#define ATM_ROM_APPLICATION_OFFSET ATM_LC_PARTITION_END
#define ATM_ROM_APPLICATION_SIZE   (ROM_SIZE - ATM_LC_PARTITION_END)

#if ATM_ROM_APPLICATION_SIZE
#if ((ATM_ROM_APPLICATION_OFFSET % 0x400) != 0)
#error "ROM application offset must be aligned to 0x400 for VTOR"
#endif
#endif

#endif // _ATMOSIC_ATM_ATM5XXX_PARTITION_DEFS_H_
