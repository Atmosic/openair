/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Vendor-protocol DFU helper for MCUboot secondary-slot OTA.
 *
 * Provides a uniform stream-write API consumed by vendor OTA transports
 * (Samsung TagSDK, Apple FMNA UARP, ...) so vendor port code does not
 * need to know the local MCUboot/partition layout.
 *
 * Mode selection is compile-time (driven by devicetree):
 *
 *   - slot1_partition and slot3_partition both present: dual-image mode.
 *     A 32-byte ATMX header at the start of the stream describes the
 *     two image sizes; Image 0 is written to slot1_partition and Image 1
 *     to slot3_partition. Use scripts/pack_combined_image.py to build
 *     the combined binary.
 *
 *   - slot1_partition only: single-image mode. Bytes are streamed
 *     straight into slot1_partition (no header parsing).
 *
 *   - slot1_partition missing: API calls return -ENOTSUP with a warning.
 *
 * When CONFIG_MCUBOOT_BOOTLOADER_MODE_SWAP_USING_OFFSET is enabled the
 * helper shifts each slot write by the first sector size so MCUboot
 * accepts the secondary-slot image.
 *
 * Dual-image header format (little-endian, 32 bytes):
 *   0x00  4  magic    = ATM_VENDOR_DFU_MAGIC ('ATMX')
 *   0x04  4  version  = 1
 *   0x08  4  img0_size  (Image 0, written to slot1_partition)
 *   0x0C  4  img1_size  (Image 1, written to slot3_partition)
 *   0x10  16 reserved
 *
 * Typical usage from a vendor transport callback:
 *
 *   atm_vendor_dfu_init();
 *   ...
 *   for each chunk arriving at stream offset O with length L:
 *       if (!O) atm_vendor_dfu_reset();
 *       atm_vendor_dfu_write(buf, L);
 *   ...
 *   atm_vendor_dfu_request_upgrade();
 *   sys_reboot(SYS_REBOOT_COLD);
 */

#ifndef ATM_VENDOR_DFU_H_
#define ATM_VENDOR_DFU_H_

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** ATMX magic word in little-endian uint32_t form ('ATMX'). */
#define ATM_VENDOR_DFU_MAGIC 0x584D5441U

/** Combined-binary header size in bytes. */
#define ATM_VENDOR_DFU_HDR_SIZE 32U

/** Header layout exposed for the packing script and host tools. */
struct atm_vendor_dfu_header {
	uint32_t magic;
	uint32_t version;
	uint32_t img0_size;
	uint32_t img1_size;
	uint8_t reserved[16];
};

/**
 * Open the underlying flash area(s) and query the per-slot write base
 * required by MCUboot's swap-using-offset mode.
 *
 * Safe to call multiple times; subsequent calls are no-ops.
 *
 * @return 0 on success, -ENOTSUP when slot1_partition is unavailable in
 *         this build, or another negative errno on failure.
 */
int atm_vendor_dfu_init(void);

/**
 * Reset per-session streaming state. Call at the start of every transfer
 * (when the transport reports stream offset 0) so a second OTA within
 * the same boot picks up cleanly.
 */
void atm_vendor_dfu_reset(void);

/**
 * Stream the next chunk to the helper. Chunks must be delivered in
 * order; the helper tracks its own offset internally.
 *
 * In dual-image mode, the first ATM_VENDOR_DFU_HDR_SIZE bytes are
 * consumed as the ATMX header; remaining bytes are routed to slot1
 * (Image 0) and slot3 (Image 1) as dictated by the header. In
 * single-image mode all bytes are written directly to slot1.
 *
 * @param data Pointer to the chunk payload (must not be NULL when len > 0).
 * @param len  Chunk length in bytes.
 * @return 0 on success, negative errno on failure.
 */
int atm_vendor_dfu_write(const uint8_t *data, size_t len);

/**
 * Request MCUboot to apply the staged image(s) on next boot. In
 * dual-image mode iterates from image index 0 up to
 * (CONFIG_UPDATEABLE_IMAGE_NUMBER - 1) calling
 * boot_request_upgrade_multi() for each.
 *
 * @return 0 on success, first non-zero errno encountered otherwise.
 */
int atm_vendor_dfu_request_upgrade(void);

/**
 * @return current stream offset (total bytes consumed by write() since
 *         the last reset).
 */
size_t atm_vendor_dfu_stream_offset(void);

#ifdef __cplusplus
}
#endif

#endif /* ATM_VENDOR_DFU_H_ */
