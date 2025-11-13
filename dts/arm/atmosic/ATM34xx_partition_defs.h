/**
 *******************************************************************************
 *
 * @file ATM34xx_partition_defs.h
 *
 * @brief Atmosic ATM34 partition definitions
 *
 * Copyright (C) Atmosic 2024-2025
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 *******************************************************************************
 */

#ifndef _ATMOSIC_ATM_ATM34XX_PARTITION_DEFS_H_
#define _ATMOSIC_ATM_ATM34XX_PARTITION_DEFS_H_

#ifdef ATM_NO_TZ
#undef ATM_SPE_SIZE
#define ATM_SPE_SIZE 0
#endif

#define RUN_APP_NORMAL 0
#define RUN_APP_IN_FLASH 1
#define RUN_APP_IN_FLASH_SPLIT 2

#ifdef ATM_APP_FLASH_XIP
// if user application is to run in flash XIP, select the split image option
// ONLY
#define RUN_IN_FLASH RUN_APP_IN_FLASH_SPLIT
#endif

// Size of memory held-back in reserve at the end of flash for a flash_xip
// configuration.  This reserve is not used for the image or data (OTA)
// partitions.  Applications are free to define partitions in the reserve
// area using application specific overlays.
// Note: for normal RRAM execution (non-Flash XIP) the remaining flash after
//       the default partitions are added (i.e. OTA partitions) is free to
//       use by the application.  No reservation is explicitly required.
#ifndef FLASH_XIP_RSVD_SIZE
#define FLASH_XIP_RSVD_SIZE 0
#endif

#ifdef ATM_APP_PART_DEFS
#include ATM_APP_PART_DEFS
#endif

#define ATM_RRAM_BLOCK_SIZE 2048
#define ROUND_DOWN_RRAM_BLK(s) \
	(((s) / ATM_RRAM_BLOCK_SIZE) * ATM_RRAM_BLOCK_SIZE)
#define ATM_RRAM_AVAIL_SIZE (510*1024)

#define ATM_FLASH_BLOCK_SIZE 4096
#define ROUND_DOWN_FLASH_BLK(s) \
    (((s) / ATM_FLASH_BLOCK_SIZE) * ATM_FLASH_BLOCK_SIZE)

#ifndef ATM_FACTORY_SIZE
#define ATM_FACTORY_SIZE 0x800
#endif
#if ((ATM_FACTORY_SIZE % ATM_RRAM_BLOCK_SIZE) != 0)
#error "Factory size must be aligned"
#endif

#ifndef ATM_STORAGE_SIZE
#define ATM_STORAGE_SIZE 0x800
#endif
#if ((ATM_STORAGE_SIZE % ATM_RRAM_BLOCK_SIZE) != 0)
#error "Storage size must be aligned"
#endif

#ifdef TEST_STORAGE_IN_FLASH
// for testing storage in flash
#define ATM_TEST_STORAGE_SIZE 0x8000
#else
#define ATM_TEST_STORAGE_SIZE 0
#endif

#define ATM_TOTAL_STORAGE_SIZE (ATM_STORAGE_SIZE + ATM_FACTORY_SIZE)

#define ATM_SPE_OFFSET 0x0

#ifndef ATM_SPE_SIZE
#if (RUN_IN_FLASH == RUN_APP_IN_FLASH_SPLIT)
#define ATM_SPE_SIZE (24 * 1024)
#elif (RUN_IN_FLASH == RUN_APP_IN_FLASH)
/* this option gives all of RRAM to the SPE (used for testing) */
#define ATM_SPE_SIZE (ATM_RRAM_AVAIL_SIZE - ATM_TOTAL_STORAGE_SIZE)
#else
#define ATM_SPE_SIZE (20 * 1024)
#endif // (RUN_IN_FLASH == RUN_APP_IN_FLASH_SPLIT)
#endif // ATM_SPE_SIZE

#if ((ATM_SPE_SIZE % ATM_RRAM_BLOCK_SIZE) != 0)
#error "SPE size must be aligned"
#endif

#ifdef RUN_IN_FLASH
#define ATM_FLASH_APP_SIZE \
    ROUND_DOWN_FLASH_BLK( \
	FLASH_SIZE - ATM_TEST_STORAGE_SIZE - FLASH_XIP_RSVD_SIZE)
#if (ATM_FLASH_APP_SIZE <= 0)
#error "FLASH APP size underflow, please check FLASH_SIZE"
#endif
#if (ATM_SPE_SIZE)
/* NSPE runs from flash */
#define ATM_NSPE_OFFSET 0
#define ATM_NSPE_SIZE ATM_FLASH_APP_SIZE
#define ATM_TEST_STORAGE_OFFSET (ATM_NSPE_OFFSET + ATM_NSPE_SIZE)
#else
/* APP runs from flash */
#define ATM_APP_OFFSET 0
#define ATM_APP_SIZE ATM_FLASH_APP_SIZE
#define ATM_TEST_STORAGE_OFFSET (ATM_APP_OFFSET + ATM_APP_SIZE)
#endif
#if (RUN_IN_FLASH == RUN_APP_IN_FLASH)
#define ATM_FAST_CODE_SIZE 0
#if (ATM_SPE_SIZE)
/* data placed after SPE */
#define ATM_DATA_START_OFFSET (ATM_SPE_OFFSET + ATM_SPE_SIZE)
#else
#define ATM_DATA_START_OFFSET 0x0
#endif
#elif (RUN_IN_FLASH == RUN_APP_IN_FLASH_SPLIT)
#if (ATM_SPE_SIZE)
#define ATM_FAST_CODE_OFFSET (ATM_SPE_OFFSET + ATM_SPE_SIZE)
#define ATM_FAST_CODE_SIZE  (ATM_RRAM_AVAIL_SIZE - ATM_SPE_SIZE \
	- ATM_TOTAL_STORAGE_SIZE)
#else
#define ATM_FAST_CODE_OFFSET 0x0
#define ATM_FAST_CODE_SIZE  (ATM_RRAM_AVAIL_SIZE - ATM_TOTAL_STORAGE_SIZE)
#endif
/* data placed after fast code area */
#define ATM_DATA_START_OFFSET (ATM_FAST_CODE_OFFSET + ATM_FAST_CODE_SIZE)
#else
#error "Invalid RUN_IN_FLASH option"
#endif // RUN_IN_FLASH == RUN_APP_IN_FLASH_SPLIT
#else
#if (ATM_SPE_SIZE)
#define ATM_NSPE_OFFSET (ATM_SPE_OFFSET + ATM_SPE_SIZE)
#define ATM_NSPE_SIZE (ATM_RRAM_AVAIL_SIZE - ATM_SPE_SIZE \
	- ATM_TOTAL_STORAGE_SIZE)
/* data placed after NSPE */
#define ATM_DATA_START_OFFSET (ATM_NSPE_OFFSET + ATM_NSPE_SIZE)
#else
#define ATM_APP_OFFSET 0x0
#define ATM_APP_SIZE (ATM_RRAM_AVAIL_SIZE - ATM_TOTAL_STORAGE_SIZE)
/* data placed after APP */
#define ATM_DATA_START_OFFSET (ATM_APP_OFFSET + ATM_APP_SIZE)
#endif
#define ATM_TEST_STORAGE_OFFSET 0
#endif // RUN_IN_FLASH

#define ATM_FACTORY_OFFSET  ATM_DATA_START_OFFSET
/* storage partition follows factory parition (if any) */
#define ATM_STORAGE_OFFSET (ATM_FACTORY_OFFSET + ATM_FACTORY_SIZE)

// NODE unit addresses, these are arbitrary and only need be unique
#define ATM_SPE_NODE_ID     cece0011
#define ATM_NSPE_NODE_ID    cece0012
#define ATM_APP_NODE_ID     cece0013
#define ATM_FACTORY_NODE_ID cece0050
#define ATM_STORAGE_NODE_ID cece0051
#define ATM_FAST_CODE_NODE_ID cece0080
#define ATM_TEST_STORAGE_NODE_ID cece00f0
#define ATM_COREDUMP_NODE_ID cece00f1

#endif // _ATMOSIC_ATM_ATM34XX_PARTITION_DEFS_H_
