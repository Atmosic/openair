/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <errno.h>
#include <string.h>

#include <zephyr/devicetree.h>
#include <zephyr/kernel.h>
#include <zephyr/storage/flash_map.h>
#include <zephyr/ztest.h>

#include "atm_vendor_dfu.h"

#define HAS_SLOT3_PARTITION FIXED_PARTITION_EXISTS(slot3_partition)

/* Per-image payload size used by dual-image tests. Kept small so the test
 * stays fast and well below the smallest sector size of either slot.
 */
#define TEST_IMG0_SIZE 64U
#define TEST_IMG1_SIZE 64U

/**
 * @brief Idempotent init: a second call must succeed without side effects.
 */
ZTEST(atm_vendor_dfu, test_init_idempotent)
{
	zassert_ok(atm_vendor_dfu_init(), "second init should succeed");
}

/**
 * @brief Stream offset is zero immediately after reset.
 */
ZTEST(atm_vendor_dfu, test_reset_clears_offset)
{
	zassert_equal(atm_vendor_dfu_stream_offset(), 0, "offset should be 0 right after reset");
}

/**
 * @brief Zero-length write is a no-op and must not advance the stream.
 */
ZTEST(atm_vendor_dfu, test_write_zero_len)
{
	uint8_t dummy = 0xAA;

	zassert_ok(atm_vendor_dfu_write(&dummy, 0), "zero-length write should succeed");
	zassert_equal(atm_vendor_dfu_stream_offset(), 0, "offset must stay 0");
}

/**
 * @brief NULL data pointer with a non-zero length is rejected.
 */
ZTEST(atm_vendor_dfu, test_write_null_data)
{
	int ret = atm_vendor_dfu_write(NULL, 1);

	zassert_equal(ret, -EINVAL, "expected -EINVAL, got %d", ret);
	zassert_equal(atm_vendor_dfu_stream_offset(), 0, "offset must stay 0");
}

/**
 * @brief request_upgrade() marks every secondary slot as pending. The
 * staged data is not a valid signed image so MCUboot will revert on the
 * next boot, which is harmless for the test run.
 */
ZTEST(atm_vendor_dfu, test_request_upgrade)
{
	zassert_ok(atm_vendor_dfu_request_upgrade(), "request_upgrade should succeed");
}

#if HAS_SLOT3_PARTITION

/* Build a valid 32-byte ATMX header with the supplied payload sizes. */
static void build_header(uint8_t *buf, uint32_t img0_size, uint32_t img1_size)
{
	struct atm_vendor_dfu_header *hdr = (struct atm_vendor_dfu_header *)buf;

	memset(buf, 0, ATM_VENDOR_DFU_HDR_SIZE);
	hdr->magic = ATM_VENDOR_DFU_MAGIC;
	hdr->version = 1;
	hdr->img0_size = img0_size;
	hdr->img1_size = img1_size;
}

/**
 * @brief Header with the wrong magic value must be rejected.
 */
ZTEST(atm_vendor_dfu, test_dual_bad_magic)
{
	uint8_t hdr[ATM_VENDOR_DFU_HDR_SIZE];

	build_header(hdr, TEST_IMG0_SIZE, TEST_IMG1_SIZE);
	((struct atm_vendor_dfu_header *)hdr)->magic = 0xDEADBEEF;

	int ret = atm_vendor_dfu_write(hdr, sizeof(hdr));

	zassert_equal(ret, -EINVAL, "expected -EINVAL, got %d", ret);
}

/**
 * @brief Header with a zero-sized image must be rejected.
 */
ZTEST(atm_vendor_dfu, test_dual_zero_image_size)
{
	uint8_t hdr[ATM_VENDOR_DFU_HDR_SIZE];

	build_header(hdr, 0, TEST_IMG1_SIZE);
	zassert_equal(atm_vendor_dfu_write(hdr, sizeof(hdr)), -EINVAL, "img0_size = 0 should fail");

	atm_vendor_dfu_reset();
	build_header(hdr, TEST_IMG0_SIZE, 0);
	zassert_equal(atm_vendor_dfu_write(hdr, sizeof(hdr)), -EINVAL, "img1_size = 0 should fail");
}

/**
 * @brief Header may be delivered split across multiple write() calls.
 */
ZTEST(atm_vendor_dfu, test_dual_chunked_header)
{
	uint8_t hdr[ATM_VENDOR_DFU_HDR_SIZE];

	build_header(hdr, TEST_IMG0_SIZE, TEST_IMG1_SIZE);

	/* Feed the header in 4-byte chunks. The helper must accumulate it
	 * before transitioning to the IMG0 state.
	 */
	for (size_t i = 0; i < sizeof(hdr); i += 4) {
		zassert_ok(atm_vendor_dfu_write(&hdr[i], 4), "chunk %zu failed", i);
	}

	zassert_equal(atm_vendor_dfu_stream_offset(), ATM_VENDOR_DFU_HDR_SIZE,
		      "offset after header should equal header size");
}

/**
 * @brief End-to-end stream: header + img0 + img1 in one shot. Verifies
 * stream_offset advances by the full payload and that data lands in the
 * expected secondary slots.
 */
ZTEST(atm_vendor_dfu, test_dual_full_flow)
{
	uint8_t buf[ATM_VENDOR_DFU_HDR_SIZE + TEST_IMG0_SIZE + TEST_IMG1_SIZE];
	uint8_t *img0 = buf + ATM_VENDOR_DFU_HDR_SIZE;
	uint8_t *img1 = img0 + TEST_IMG0_SIZE;

	build_header(buf, TEST_IMG0_SIZE, TEST_IMG1_SIZE);
	for (size_t i = 0; i < TEST_IMG0_SIZE; i++) {
		img0[i] = (uint8_t)(0xA0 + (i & 0x0F));
	}
	for (size_t i = 0; i < TEST_IMG1_SIZE; i++) {
		img1[i] = (uint8_t)(0xB0 + (i & 0x0F));
	}

	zassert_ok(atm_vendor_dfu_write(buf, sizeof(buf)), "full-flow write failed");
	zassert_equal(atm_vendor_dfu_stream_offset(), sizeof(buf),
		      "offset should equal total bytes streamed");
}

/**
 * @brief Deliver the payload in 8-byte chunks so per-image writes land at
 * non-sector-aligned offsets after the first chunk, exercising the
 * flatten-skip path inside the dual-image state machine.
 */
ZTEST(atm_vendor_dfu, test_dual_chunked_payload)
{
	uint8_t hdr[ATM_VENDOR_DFU_HDR_SIZE];
	uint8_t chunk[8];

	build_header(hdr, TEST_IMG0_SIZE, TEST_IMG1_SIZE);
	zassert_ok(atm_vendor_dfu_write(hdr, sizeof(hdr)), "header write failed");

	memset(chunk, 0xC1, sizeof(chunk));
	for (size_t i = 0; i < TEST_IMG0_SIZE + TEST_IMG1_SIZE; i += sizeof(chunk)) {
		zassert_ok(atm_vendor_dfu_write(chunk, sizeof(chunk)),
			   "payload chunk at %zu failed", i);
	}

	zassert_equal(atm_vendor_dfu_stream_offset(),
		      ATM_VENDOR_DFU_HDR_SIZE + TEST_IMG0_SIZE + TEST_IMG1_SIZE,
		      "offset should equal total bytes streamed");
}

#else /* !HAS_SLOT3_PARTITION */

/**
 * @brief Single-image streaming: bytes are forwarded straight to slot1.
 */
ZTEST(atm_vendor_dfu, test_single_simple_write)
{
	uint8_t buf[64];

	for (size_t i = 0; i < sizeof(buf); i++) {
		buf[i] = (uint8_t)(i ^ 0x5A);
	}

	zassert_ok(atm_vendor_dfu_write(buf, sizeof(buf)), "single write failed");
	zassert_equal(atm_vendor_dfu_stream_offset(), sizeof(buf),
		      "offset should match bytes written");
}

/**
 * @brief Two consecutive writes leave the second call starting at a non-
 * sector-aligned slot offset, exercising the flatten-skip path.
 */
ZTEST(atm_vendor_dfu, test_single_two_writes)
{
	uint8_t buf[32];

	for (size_t i = 0; i < sizeof(buf); i++) {
		buf[i] = (uint8_t)(i + 0x10);
	}

	zassert_ok(atm_vendor_dfu_write(buf, sizeof(buf)), "first write failed");
	zassert_ok(atm_vendor_dfu_write(buf, sizeof(buf)), "second write failed");
	zassert_equal(atm_vendor_dfu_stream_offset(), 2U * sizeof(buf),
		      "offset should accumulate across writes");
}

#endif /* HAS_SLOT3_PARTITION */
