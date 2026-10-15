/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/*
 * LittleFS lets a caller override the auto-detected erase block size via
 * struct lfs_config::block_size (see littlefs_init_cfg() in
 * zephyr/subsys/fs/littlefs_fs.c). Only when it's left at 0 does LittleFS
 * fall back to auto-detection via get_block_size(), which in turn falls back
 * to LITTLEFS_DEFAULT_BLOCK_SIZE (4096) whenever the flash area reports
 * no-explicit-erase (e.g. Atmosic RRAM) while any other explicit-erase flash
 * device is also present in the image. That default doesn't match RRAM's
 * actual erase-block-size, so this sample's storage_partition ends up
 * mounted with the wrong block size when it lives in RRAM.
 *
 * This isn't a LittleFS bug -- LittleFS already provides the override this
 * situation needs. It's simply a configuration gap: this sample doesn't set
 * block_size explicitly for storage_partition. Work around it locally by
 * wrapping fs_mount() and forcing the correct block_size (from devicetree)
 * into the littlefs config before the filesystem is actually mounted.
 */

#include <zephyr/devicetree.h>
#include <zephyr/fs/fs.h>
#include <zephyr/fs/littlefs.h>
#include <zephyr/storage/flash_map.h>

BUILD_ASSERT(DT_NODE_EXISTS(DT_NODELABEL(storage_partition)),
	     "storage_partition node missing - check devicetree");

extern int __real_fs_mount(struct fs_mount_t *mp);

int __wrap_fs_mount(struct fs_mount_t *mp)
{
	if (mp->type == FS_LITTLEFS &&
	    (uintptr_t)mp->storage_dev == PARTITION_ID(storage_partition)) {
		struct fs_littlefs *fs = mp->fs_data;

		if (fs->cfg.block_size == 0) {
			fs->cfg.block_size = DT_PROP(DT_GPARENT(DT_NODELABEL(storage_partition)),
						     erase_block_size);
		}
	}

	return __real_fs_mount(mp);
}
