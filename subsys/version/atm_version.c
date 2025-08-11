/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/sys/printk.h>
#include <zephyr/init.h>

#if defined(CONFIG_MCUBOOT_IMG_MANAGER)
#include <zephyr/dfu/mcuboot.h>
#include <zephyr/storage/flash_map.h>
#include <errno.h>
#include "arch.h" // for DEBUG_TRACE
#endif

#ifndef ATMOSIC_SDK_VERSION
#define ATMOSIC_SDK_VERSION "Unknown OpenAir Version"
#endif

int atm_print_version(void)
{
	printk("*** " ATMOSIC_SDK_VERSION " ***\n");
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
