/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 * Copyright (c) 2024 Atmosic
 *
 * Based on boot/zephyr/hook_sample.c
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#include "arch.h"
#include <assert.h>
#include <zephyr/kernel.h>
#include <zephyr/devicetree.h>
#include "mcuboot_config/mcuboot_config.h"
#include "bootutil/image.h"
#include "bootutil/bootutil.h"
#include "bootutil/mcuboot_status.h"
#include "atm_mcuboot_ext.h"
#include "rram_rom_prot.h"

#ifdef MCUBOOT_IMAGE_ACCESS_HOOKS
int boot_read_image_header_hook(int img_index, int slot,
    struct image_header *img_header)
{
    return BOOT_HOOK_REGULAR;
}

fih_ret boot_image_check_hook(int img_index, int slot)
{
#ifdef CONFIG_ATM_MCUBOOT_SKIP_PRIMARY_VALIDATE_HIBER
    if (atm_mcuboot_ext_skip_img_validation()) {
	FIH_RET(FIH_SUCCESS);
    }
#endif
    FIH_RET(FIH_BOOT_HOOK_REGULAR);
}

int boot_perform_update_hook(int img_index, struct image_header *img_head,
    const struct flash_area *area)
{
    return BOOT_HOOK_REGULAR;
}

int boot_read_swap_state_primary_slot_hook(int image_index,
    struct boot_swap_state *state)
{
    return BOOT_HOOK_REGULAR;
}

int boot_copy_region_post_hook(int img_index, const struct flash_area *area,
    size_t size)
{
    return 0;
}

int boot_serial_uploaded_hook(int img_index, const struct flash_area *area,
    size_t size)
{
    return 0;
}

int boot_img_install_stat_hook(int image_index, int slot, int *img_install_stat)
{
    return BOOT_HOOK_REGULAR;
}
#endif // MCUBOOT_IMAGE_ACCESS_HOOKS

#ifdef CONFIG_MCUBOOT_ACTION_HOOKS

#ifdef CONFIG_ATM_MCUBOOT_LOCK_PRIMARY_SLOT
#ifdef MCUBOOT_OVERWRITE_ONLY
// no need to unlock trailer
#define IMG_TRAILER_RSVD_SZ 0
#else
// In swap mode we need to keep the trailer unlocked in order to confirm the
// the image. The trailer should not share the same RRAM block as the
// slot0 image (NSPE) since it will be locked.
#define SLOT0_END_OFFSET \
    (DT_REG_ADDR(DT_NODELABEL(slot0_partition)) + \
	DT_REG_SIZE(DT_NODELABEL(slot0_partition)))

#define NSPE_END_OFFSET \
    (DT_REG_ADDR(DT_NODELABEL(nspe_partition)) + \
	DT_REG_SIZE(DT_NODELABEL(nspe_partition)))

// the trailer is in the gap between the NSPE and the end of the slot.
#define IMG_TRAILER_RSVD_SZ (SLOT0_END_OFFSET - NSPE_END_OFFSET)

STATIC_ASSERT(IMG_TRAILER_RSVD_SZ > 0,
    "Slot locking requires a reserved trailer, please set DTSI config: ATM_IMG_TRAILER_RSVD_SIZE");
STATIC_ASSERT((IMG_TRAILER_RSVD_SZ % RRAM_ROM_PROT_BLOCK_SIZE) == 0,
    "Trailer reservation must be aligned");
#endif // MCUBOOT_OVERWRITE_ONLY

static void lock_primary_slot(void)
{
    static sec_slot_desc_t const desc = {
	.slot0_offset = DT_REG_ADDR(DT_NODELABEL(slot0_partition)),
	.slot0_size = DT_REG_SIZE(DT_NODELABEL(slot0_partition)),
	.slot0_trailer_unlock_size = IMG_TRAILER_RSVD_SZ,
    };
    atm_mcuboot_ext_lock_img_slots(&desc);
}
#endif // CONFIG_ATM_MCUBOOT_LOCK_PRIMARY_SLOT

// Zephyr mcuboot status change hook
void mcuboot_status_change(mcuboot_status_type_t status)
{
    switch (status) {
	case MCUBOOT_STATUS_STARTUP:
#ifdef CONFIG_ATM_MCUBOOT_EXT
	    atm_mcuboot_ext_startup();
#endif
	    break;
	case MCUBOOT_STATUS_BOOTABLE_IMAGE_FOUND:
#ifdef CONFIG_ATM_MCUBOOT_LOCK_PRIMARY_SLOT
	    lock_primary_slot();
#endif
	    break;
	default:
	    break;
    }
}
#endif // CONFIG_MCUBOOT_ACTION_HOOKS
