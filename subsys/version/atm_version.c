/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/sys/printk.h>
#include <zephyr/init.h>
#ifdef CONFIG_ATM_BP_CLOCK
#include "atm_bp_clock.h"
#endif

#if defined(CONFIG_MCUBOOT_IMG_MANAGER)
#include <zephyr/dfu/mcuboot.h>
#include <zephyr/storage/flash_map.h>
#include <errno.h>
#include "arch.h" // for DEBUG_TRACE
#endif

#ifndef ATMOSIC_SDK_VERSION
#define ATMOSIC_SDK_VERSION "Unknown OpenAir Version"
#endif

#ifdef CONFIG_ATMWSTK_VERSION
#define ATMWSTK_VERSION "(" CONFIG_ATMWSTK_VERSION ")"
#else
#define ATMWSTK_VERSION ""
#endif

#ifdef CONFIG_TRUSTED_EXECUTION_NONSECURE
#define NS_IMG_STR "NS "
#else
#define NS_IMG_STR ""
#endif

int atm_print_version(void)
{
#if defined(CONFIG_TRUSTED_EXECUTION_SECURE) && !defined(CONFIG_ATM_NO_SPE)
	printk("*** " ATMOSIC_SDK_VERSION " ***\n");
#else
#ifndef CONFIG_ATM_BP_CLOCK
	printk("*** " NS_IMG_STR ATMOSIC_SDK_VERSION " " ATMWSTK_VERSION " ***\n");
#else
	printk("*** " NS_IMG_STR ATMOSIC_SDK_VERSION " " ATMWSTK_VERSION ", bp_freq is %d ***\n",
	       atm_bp_clock_get());
#endif
#endif // CONFIG_TRUSTED_EXECUTION_SECURE && !CONFIG_ATM_NO_SPE
#if defined(CONFIG_MCUBOOT_IMG_MANAGER)
	struct mcuboot_img_header hdr;
	int err = boot_read_bank_header(FIXED_PARTITION_ID(slot0_partition), &hdr, sizeof(hdr));
	if (err) {
		// Failed to get header information
		DEBUG_TRACE("Failed to get slot0 header information: %d", err);
		return err;
	}
	if (hdr.mcuboot_version != 1) {
		// MCUboot header version not supported
		DEBUG_TRACE("MCUboot header version not supported, expected v1 got v%d",
		            hdr.mcuboot_version);
		return -ENOTSUP;
	}
	printk("*** MCUboot Image Version: %d.%d.%d ***\n",
	       hdr.h.v1.sem_ver.major,
	       hdr.h.v1.sem_ver.minor,
	       hdr.h.v1.sem_ver.revision);
#endif
	return 0;
}

SYS_INIT(atm_print_version, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
