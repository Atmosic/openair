/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include "atm_vendor_dfu.h"

#include <errno.h>
#include <string.h>

#include <zephyr/devicetree.h>
#include <zephyr/dfu/mcuboot.h>
#include <zephyr/drivers/flash.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/storage/flash_map.h>

LOG_MODULE_REGISTER(atm_vendor_dfu, CONFIG_ATM_VENDOR_DFU_LOG_LEVEL);

#if FIXED_PARTITION_EXISTS(slot1_partition)
#define HAS_SLOT1          1
#define SLOT1_PARTITION_ID PARTITION_ID(slot1_partition)
#else
#define HAS_SLOT1 0
#endif

#if FIXED_PARTITION_EXISTS(slot3_partition)
#define HAS_SLOT3          1
#define SLOT3_PARTITION_ID PARTITION_ID(slot3_partition)
#else
#define HAS_SLOT3 0
#endif

#if HAS_SLOT1

enum write_state {
	STATE_HEADER = 0,
	STATE_IMG0,
	STATE_IMG1,
};

static bool initialized;
static size_t stream_offset;

static const struct flash_area *ufa1;
static uint32_t slot1_erase_sz;
static uint32_t slot1_write_base;
static uint32_t slot1_write_offset;

#if HAS_SLOT3
static const struct flash_area *ufa3;
static uint32_t slot3_erase_sz;
static uint32_t slot3_write_base;
static uint32_t slot3_write_offset;

static enum write_state state;
static uint8_t hdr_buf[ATM_VENDOR_DFU_HDR_SIZE];
static uint32_t hdr_bytes;
static uint32_t img0_remain;
#endif /* HAS_SLOT3 */

/*
 * When CONFIG_MCUBOOT_BOOTLOADER_MODE_SWAP_USING_OFFSET is enabled, MCUboot
 * expects the update image to start at the second sector of the secondary
 * slot (the first sector is reserved for swap status). Return the first-
 * sector size as the write base; return 0 otherwise.
 */
static uint32_t query_write_base(const struct flash_area *fa)
{
#if defined(CONFIG_MCUBOOT_BOOTLOADER_MODE_SWAP_USING_OFFSET)
	uint32_t count = 1;
	struct flash_sector sector;
	int rc = flash_area_sectors(fa, &count, &sector);

	if ((rc && rc != -ENOMEM) || count != 1) {
		LOG_ERR("flash_area_sectors failed: rc=%d count=%u", rc, count);
		return 0;
	}
	return (uint32_t)sector.fs_size;
#else
	(void)fa;
	return 0;
#endif
}

static uint32_t query_erase_size(const struct flash_area *fa)
{
	const struct flash_pages_layout *fpl;
	const struct flash_driver_api *api = fa->fa_dev->api;
	size_t lsize;

	api->page_layout(fa->fa_dev, &fpl, &lsize);
	return fpl->pages_size;
}

/*
 * Erase the current sector when the slot write address sits on a sector
 * boundary. Callers must ensure individual writes never straddle sector
 * boundaries with mixed erased/programmed state.
 */
static int flatten_if_boundary(const struct flash_area *fa, uint32_t slot_addr, uint32_t erase_sz)
{
	if (slot_addr % erase_sz) {
		return 0;
	}
	int ret = flash_area_flatten(fa, slot_addr, erase_sz);

	if (ret) {
		LOG_ERR("flatten(%#x) failed: %d", slot_addr, ret);
	}
	return ret;
}

static int open_slot(uint8_t id, const struct flash_area **out, uint32_t *erase_sz,
		     uint32_t *write_base, const char *tag)
{
	int ret = flash_area_open(id, out);

	if (ret) {
		LOG_ERR("%s flash_area_open failed: %d", tag, ret);
		*out = NULL;
		return ret;
	}
	if (!(*out)->fa_dev || !flash_area_device_is_ready(*out)) {
		LOG_ERR("%s flash device not ready", tag);
		*out = NULL;
		return -ENODEV;
	}
	*erase_sz = query_erase_size(*out);
	*write_base = query_write_base(*out);
	LOG_INF("%s: id=%u off=%#lx size=%u erase=%u base=%#x", tag, (*out)->fa_id, (*out)->fa_off,
		(*out)->fa_size, *erase_sz, *write_base);
	return 0;
}

int atm_vendor_dfu_init(void)
{
	if (initialized) {
		return 0;
	}

	int ret = open_slot(SLOT1_PARTITION_ID, &ufa1, &slot1_erase_sz, &slot1_write_base, "slot1");

	if (ret) {
		return ret;
	}

#if HAS_SLOT3
	ret = open_slot(SLOT3_PARTITION_ID, &ufa3, &slot3_erase_sz, &slot3_write_base, "slot3");
	if (ret) {
		return ret;
	}
	LOG_INF("vendor DFU: dual-image mode");
#else
	LOG_INF("vendor DFU: single-image mode");
#endif

	initialized = true;
	return 0;
}

/*
 * The image body is erased on demand as it is streamed in (see
 * flatten_if_boundary). Two regions that MCUboot reads to decide the swap are
 * never touched by those writes, so stale metadata left by a previous upgrade
 * would make the bootloader reject the secondary image. Wipe them here before
 * each upgrade:
 *   - the reserved first sector (secondary header) in swap-using-offset mode, and
 *   - the image trailer / swap-status region at the end of the slot.
 * This mirrors what upstream mcumgr img_mgmt does, while keeping the (bounded)
 * body erase spread across the transfer rather than a single up-front full-slot
 * erase.
 */
static void erase_metadata(const struct flash_area *fa, uint32_t write_base, uint32_t erase_sz,
			   const char *tag)
{
	if (!fa || !erase_sz) {
		return;
	}
	if (write_base) {
		int ret = flash_area_flatten(fa, 0, write_base);

		if (ret) {
			LOG_ERR("%s: erase reserved sector failed: %d", tag, ret);
		}
	}
#if defined(CONFIG_MCUBOOT_IMG_MANAGER)
	ssize_t trailer_off = boot_get_trailer_status_offset(fa->fa_size);

	if (trailer_off > 0) {
		uint32_t off = (uint32_t)trailer_off & ~(erase_sz - 1);
		int ret = flash_area_flatten(fa, off, fa->fa_size - off);

		if (ret) {
			LOG_ERR("%s: erase trailer failed: %d", tag, ret);
		} else {
			LOG_INF("%s: erased trailer [%#x..%#zx)", tag, off, (size_t)fa->fa_size);
		}
	}
#endif
}

void atm_vendor_dfu_reset(void)
{
	stream_offset = 0;
	slot1_write_offset = slot1_write_base;
	erase_metadata(ufa1, slot1_write_base, slot1_erase_sz, "slot1");
#if HAS_SLOT3
	slot3_write_offset = slot3_write_base;
	erase_metadata(ufa3, slot3_write_base, slot3_erase_sz, "slot3");
	state = STATE_HEADER;
	hdr_bytes = 0;
	img0_remain = 0;
	memset(hdr_buf, 0, sizeof(hdr_buf));
#endif
}

size_t atm_vendor_dfu_stream_offset(void)
{
	return stream_offset;
}

#if HAS_SLOT3
static int write_dual(const uint8_t *data, size_t len)
{
	size_t pos = 0;

	while (pos < len) {
		size_t remain = len - pos;

		switch (state) {
		case STATE_HEADER: {
			size_t need = ATM_VENDOR_DFU_HDR_SIZE - hdr_bytes;
			size_t take = (remain < need) ? remain : need;

			memcpy(hdr_buf + hdr_bytes, data + pos, take);
			hdr_bytes += take;
			pos += take;
			stream_offset += take;

			if (hdr_bytes < ATM_VENDOR_DFU_HDR_SIZE) {
				break;
			}
			const struct atm_vendor_dfu_header *hdr =
				(const struct atm_vendor_dfu_header *)hdr_buf;

			if (hdr->magic != ATM_VENDOR_DFU_MAGIC) {
				LOG_ERR("bad header magic: %#x", hdr->magic);
				return -EINVAL;
			}
			if (!hdr->img0_size || !hdr->img1_size) {
				LOG_ERR("header has zero-size image");
				return -EINVAL;
			}
			img0_remain = hdr->img0_size;
			LOG_INF("header OK: img0=%u img1=%u bytes", hdr->img0_size, hdr->img1_size);
			state = STATE_IMG0;
			break;
		}

		case STATE_IMG0: {
			uint32_t sector_left =
				slot1_erase_sz - (slot1_write_offset % slot1_erase_sz);
			size_t take = (remain < img0_remain) ? remain : img0_remain;

			if (take > sector_left) {
				take = sector_left;
			}
			int ret = flatten_if_boundary(ufa1, slot1_write_offset, slot1_erase_sz);

			if (ret) {
				return ret;
			}
			ret = flash_area_write(ufa1, slot1_write_offset, data + pos, take);
			if (ret) {
				LOG_ERR("slot1 write failed: %d", ret);
				return ret;
			}
			slot1_write_offset += take;
			img0_remain -= take;
			pos += take;
			stream_offset += take;
			if (!img0_remain) {
				LOG_INF("Image 0 write complete");
				state = STATE_IMG1;
			}
			break;
		}

		case STATE_IMG1: {
			uint32_t sector_left =
				slot3_erase_sz - (slot3_write_offset % slot3_erase_sz);
			size_t take = (remain < sector_left) ? remain : sector_left;
			int ret = flatten_if_boundary(ufa3, slot3_write_offset, slot3_erase_sz);

			if (ret) {
				return ret;
			}
			ret = flash_area_write(ufa3, slot3_write_offset, data + pos, take);
			if (ret) {
				LOG_ERR("slot3 write failed: %d", ret);
				return ret;
			}
			slot3_write_offset += take;
			pos += take;
			stream_offset += take;
			break;
		}

		default:
			LOG_ERR("unknown state: %d", state);
			return -EINVAL;
		}
	}
	return 0;
}
#else  /* !HAS_SLOT3 */
static int write_single(const uint8_t *data, size_t len)
{
	size_t pos = 0;

	while (pos < len) {
		size_t remain = len - pos;
		uint32_t sector_left = slot1_erase_sz - (slot1_write_offset % slot1_erase_sz);
		size_t take = (remain < sector_left) ? remain : sector_left;
		int ret = flatten_if_boundary(ufa1, slot1_write_offset, slot1_erase_sz);

		if (ret) {
			return ret;
		}
		ret = flash_area_write(ufa1, slot1_write_offset, data + pos, take);
		if (ret) {
			LOG_ERR("slot1 write failed: %d", ret);
			return ret;
		}
		slot1_write_offset += take;
		pos += take;
		stream_offset += take;
	}
	return 0;
}
#endif /* HAS_SLOT3 */

int atm_vendor_dfu_write(const uint8_t *data, size_t len)
{
	if (!len) {
		return 0;
	}
	if (!data) {
		return -EINVAL;
	}
	if (!initialized) {
		LOG_ERR("not initialized");
		return -EPERM;
	}
#if HAS_SLOT3
	return write_dual(data, len);
#else
	return write_single(data, len);
#endif
}

int atm_vendor_dfu_request_upgrade(void)
{
#ifdef CONFIG_MCUBOOT_IMG_MANAGER
	int first_err = 0;

	for (int i = 0; i < CONFIG_UPDATEABLE_IMAGE_NUMBER; i++) {
		int err = boot_request_upgrade_multi(i, BOOT_UPGRADE_PERMANENT);

		if (err) {
			LOG_ERR("boot_request_upgrade_multi(%d) failed: %d", i, err);
			if (!first_err) {
				first_err = err;
			}
		} else {
			LOG_INF("MCUboot image %d upgrade scheduled", i);
		}
	}
	return first_err;
#else
	LOG_ERR("MCUboot not configured - upgrade request skipped");
	return -ENOSYS;
#endif /* CONFIG_MCUBOOT_IMG_MANAGER */
}

#else /* !HAS_SLOT1 */

int atm_vendor_dfu_init(void)
{
	LOG_WRN("slot1_partition not available - vendor DFU disabled");
	return -ENOTSUP;
}

void atm_vendor_dfu_reset(void)
{
}

int atm_vendor_dfu_write(const uint8_t *data, size_t len)
{
	ARG_UNUSED(data);
	ARG_UNUSED(len);
	return -ENOTSUP;
}

int atm_vendor_dfu_request_upgrade(void)
{
	return -ENOTSUP;
}

size_t atm_vendor_dfu_stream_offset(void)
{
	return 0;
}

#endif /* HAS_SLOT1 */
