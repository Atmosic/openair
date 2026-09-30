/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/ztest.h>
#include "at_tz_mpc.h"

/*
 * All address constants are derived from chip-provided macros so the tests
 * work on ATM33/ATM34 and ATM5 without modification:
 *
 *   CMSDK_EXT_FLASH_NONSECURE_BASE  physical ext-flash base (from arch.h)
 *   AT_TZ_MPC_FLS_BLK_SIZE          flash MPC block size    (from at_tz_mpc.h)
 *   AT_TZ_MPC_EXT_FLASH_MPC_SIZE    MPC-addressable window  (from at_tz_mpc.h)
 *
 * Tests pass secure-alias addresses (IDAU bit = 0x10000000); GET_PHYS_ADDR()
 * strips it internally.  The ext-flash region is safe to reconfigure because
 * no running code is located there.
 *
 * at_tz_mpc_lock_down(FLASH/RAM) is irreversible until reset and is NOT
 * tested to avoid breaking subsequent operations within the same boot.
 * Only the INVALID-type error path is exercised.
 */

/* ───────────────── Suite: at_tz_mpc_bounds ───────────────── */
/* Parameter-validation paths in at_tz_mpc_config_region() that
 * return before touching any hardware register.                */

ZTEST(at_tz_mpc_bounds, test_bad_bounds_inverted)
{
	/* limit <= base */
	at_tz_mpc_ret_t ret =
		at_tz_mpc_config_region(0x10200800U, 0x10200000U, AT_TZ_MPC_ATTR_NONSECURE);
	zassert_equal(ret, AT_TZ_MPC_RET_BAD_BOUNDS, "inverted bounds should return BAD_BOUNDS");
}

ZTEST(at_tz_mpc_bounds, test_bad_bounds_equal)
{
	/* limit == base */
	at_tz_mpc_ret_t ret =
		at_tz_mpc_config_region(0x10200000U, 0x10200000U, AT_TZ_MPC_ATTR_NONSECURE);
	zassert_equal(ret, AT_TZ_MPC_RET_BAD_BOUNDS, "equal base/limit should return BAD_BOUNDS");
}

ZTEST(at_tz_mpc_bounds, test_bad_bounds_invalid_addr)
{
	/* address outside both flash and RAM MPC coverage */
	at_tz_mpc_ret_t ret =
		at_tz_mpc_config_region(0x40000000U, 0x40000FFFU, AT_TZ_MPC_ATTR_NONSECURE);
	zassert_equal(ret, AT_TZ_MPC_RET_BAD_BOUNDS,
		      "address outside MPC range should return BAD_BOUNDS");
}

ZTEST(at_tz_mpc_bounds, test_bad_bounds_mismatched_type)
{
	/* base in flash (0x10000000 → phys 0x00000000),
	 * limit in RAM   (0x30000000 → phys 0x20000000) */
	at_tz_mpc_ret_t ret =
		at_tz_mpc_config_region(0x10000000U, 0x30000000U, AT_TZ_MPC_ATTR_NONSECURE);
	zassert_equal(ret, AT_TZ_MPC_RET_BAD_BOUNDS,
		      "flash base with RAM limit should return BAD_BOUNDS");
}

ZTEST(at_tz_mpc_bounds, test_bad_bounds_unaligned_base)
{
	/* base is not block-aligned */
	at_tz_mpc_ret_t ret =
		at_tz_mpc_config_region(0x10200001U, 0x102007FFU, AT_TZ_MPC_ATTR_NONSECURE);
	zassert_equal(ret, AT_TZ_MPC_RET_BAD_BOUNDS, "unaligned base should return BAD_BOUNDS");
}

ZTEST(at_tz_mpc_bounds, test_bad_bounds_unaligned_limit)
{
	/* limit+1 is not block-aligned */
	at_tz_mpc_ret_t ret =
		at_tz_mpc_config_region(0x10200000U, 0x10200800U, AT_TZ_MPC_ATTR_NONSECURE);
	zassert_equal(ret, AT_TZ_MPC_RET_BAD_BOUNDS, "unaligned limit should return BAD_BOUNDS");
}

ZTEST_SUITE(at_tz_mpc_bounds, NULL, NULL, NULL, NULL, NULL);

/* ───────────────── Suite: at_tz_mpc_region ───────────────── */
/* Hardware-touching tests for at_tz_mpc_config_region().
 *
 * Safety constraint: marking the MPC-controlled ext-flash range NS may
 * fault the CPU if running code lives there (observed on ATM5 cairo
 * no_tz_no_spe builds).  These tests therefore only:
 *   - write the "rest of flash" LUT (index MAX_MPC_FLS_LUT_IDX), which
 *     covers ext flash beyond the MPC window and is known unused, OR
 *   - issue SECURE writes against the default-secure LUT, which clear
 *     bits that are already 0 and therefore do not change attributes.
 */

/* Secure alias of ext-flash physical base (IDAU bit set) */
#define EXT_FLASH_S_BASE (CMSDK_EXT_FLASH_NONSECURE_BASE | 0x10000000U)

/* First ext-flash block.  Used only for SECURE-attribute writes, which
 * clear bits that are already 0 in the default-secure LUT and so do not
 * mutate any block's actual security attribute. */
#define EXT_FLASH_BLK0_BASE  EXT_FLASH_S_BASE
#define EXT_FLASH_BLK0_LIMIT (EXT_FLASH_S_BASE + AT_TZ_MPC_FLS_BLK_SIZE - 1U)

/* phys_base sits exactly at the MPC-window upper boundary; phys_limit
 * extends one block past it.  Exercises the past-limit code path while
 * only modifying the "rest of flash" LUT bit. */
#define EXT_FLASH_PAST_BASE  (EXT_FLASH_S_BASE + AT_TZ_MPC_EXT_FLASH_MPC_SIZE)
#define EXT_FLASH_PAST_LIMIT (EXT_FLASH_PAST_BASE + AT_TZ_MPC_FLS_BLK_SIZE - 1U)

/* Secure alias of the RAM physical base. */
#define RAM_S_BASE (CMSDK_SRAM_BASE | 0x10000000U)

/* Multi-block RAM region spanning at least three LUT words, with limit
 * at the last RAM block (LUT bit 31).  Exercises:
 *   - body loop and final-LUT handling (block_start_word + 2 <= block_end_word)
 *   - block_end_mask == 0 special case (limit at bit 31)
 *   - RAM MPC selection in at_tz_mpc_from_block_word()
 *   - on chips with multiple RAM MPCs (ATM33/ATM34), the inter-MPC
 *     ctrl-register save/restore path
 * SECURE writes only clear LUT bits that are already 0 by default, so
 * no block changes security attribute. */
#define RAM_MULTI_BLK_BASE  (RAM_S_BASE + 5U * 32U * AT_TZ_MPC_RAM_BLK_SIZE)
#define RAM_MULTI_BLK_LIMIT (RAM_S_BASE + RAM_SIZE - 1U)

ZTEST(at_tz_mpc_region, test_config_ext_flash_s)
{
	/* SECURE write: clears bits in the default-secure LUT (no-op). */
	at_tz_mpc_ret_t ret = at_tz_mpc_config_region(EXT_FLASH_BLK0_BASE, EXT_FLASH_BLK0_LIMIT,
						      AT_TZ_MPC_ATTR_SECURE);
	zassert_equal(ret, AT_TZ_MPC_RET_OK, "single ext-flash block → Secure should succeed");
}

ZTEST(at_tz_mpc_region, test_config_ext_flash_past_limit_secure)
{
	/* SECURE attribute past the MPC window returns early without HW write. */
	at_tz_mpc_ret_t ret = at_tz_mpc_config_region(EXT_FLASH_PAST_BASE, EXT_FLASH_PAST_LIMIT,
						      AT_TZ_MPC_ATTR_SECURE);
	zassert_equal(ret, AT_TZ_MPC_RET_ATTR_UNAVAIL,
		      "SECURE attr past MPC limit should return ATTR_UNAVAIL");
}

ZTEST(at_tz_mpc_region, test_config_ext_flash_past_limit_ns_then_repeat)
{
	/* First call: writes LUT MAX bit 0 and sets the driver's
	 * rest_of_flash_ns static flag.  Only the "rest of flash" bit is
	 * modified (same write as at_tz_mpc_config_remaining_ext_flash). */
	at_tz_mpc_ret_t ret = at_tz_mpc_config_region(EXT_FLASH_PAST_BASE, EXT_FLASH_PAST_LIMIT,
						      AT_TZ_MPC_ATTR_NONSECURE);
	zassert_equal(ret, AT_TZ_MPC_RET_OK, "first past-limit NS call should succeed");

	/* Second call: phys_base >= MPC limit AND rest_of_flash_ns is now
	 * true, so the early-return path triggers (no HW write). */
	ret = at_tz_mpc_config_region(EXT_FLASH_PAST_BASE, EXT_FLASH_PAST_LIMIT,
				      AT_TZ_MPC_ATTR_NONSECURE);
	zassert_equal(ret, AT_TZ_MPC_RET_OK,
		      "repeated past-limit NS call should hit the early-return path");
}

ZTEST(at_tz_mpc_region, test_config_ram_multi_block_s)
{
	/* Multi-LUT SECURE write covering the top of RAM.  See the
	 * RAM_MULTI_BLK_* macros above for the code paths exercised. */
	at_tz_mpc_ret_t ret = at_tz_mpc_config_region(RAM_MULTI_BLK_BASE, RAM_MULTI_BLK_LIMIT,
						      AT_TZ_MPC_ATTR_SECURE);
	zassert_equal(ret, AT_TZ_MPC_RET_OK, "RAM multi-block SECURE should succeed");
}

ZTEST_SUITE(at_tz_mpc_region, NULL, NULL, NULL, NULL, NULL);

/* ───────────────── Suite: at_tz_mpc_inline ───────────────── */
/* Inline functions declared in at_tz_mpc.h.                   */

ZTEST(at_tz_mpc_inline, test_get_block_size_flash)
{
	zassert_equal(at_tz_mpc_get_block_size(AT_TZ_MPC_DEV_FLASH), AT_TZ_MPC_FLS_BLK_SIZE,
		      "flash block size mismatch");
}

ZTEST(at_tz_mpc_inline, test_get_block_size_ram)
{
	zassert_equal(at_tz_mpc_get_block_size(AT_TZ_MPC_DEV_RAM), AT_TZ_MPC_RAM_BLK_SIZE,
		      "RAM block size mismatch");
}

ZTEST(at_tz_mpc_inline, test_enable_int_flash)
{
	zassert_equal(at_tz_mpc_enable_int(AT_TZ_MPC_DEV_FLASH), AT_TZ_MPC_RET_OK,
		      "enable_int(FLASH) should return OK");
}

ZTEST(at_tz_mpc_inline, test_enable_int_ram)
{
	zassert_equal(at_tz_mpc_enable_int(AT_TZ_MPC_DEV_RAM), AT_TZ_MPC_RET_OK,
		      "enable_int(RAM) should return OK");
}

ZTEST(at_tz_mpc_inline, test_enable_int_invalid)
{
	zassert_equal(at_tz_mpc_enable_int(AT_TZ_MPC_DEV_INVALID), AT_TZ_MPC_RET_INVALID_TYPE,
		      "enable_int(INVALID) should return INVALID_TYPE");
}

ZTEST(at_tz_mpc_inline, test_disable_int_flash)
{
	zassert_equal(at_tz_mpc_disable_int(AT_TZ_MPC_DEV_FLASH), AT_TZ_MPC_RET_OK,
		      "disable_int(FLASH) should return OK");
}

ZTEST(at_tz_mpc_inline, test_disable_int_ram)
{
	zassert_equal(at_tz_mpc_disable_int(AT_TZ_MPC_DEV_RAM), AT_TZ_MPC_RET_OK,
		      "disable_int(RAM) should return OK");
}

ZTEST(at_tz_mpc_inline, test_disable_int_invalid)
{
	zassert_equal(at_tz_mpc_disable_int(AT_TZ_MPC_DEV_INVALID), AT_TZ_MPC_RET_INVALID_TYPE,
		      "disable_int(INVALID) should return INVALID_TYPE");
}

ZTEST(at_tz_mpc_inline, test_enable_bus_fault_flash)
{
	zassert_equal(at_tz_mpc_enable_bus_fault(AT_TZ_MPC_DEV_FLASH), AT_TZ_MPC_RET_OK,
		      "enable_bus_fault(FLASH) should return OK");
}

ZTEST(at_tz_mpc_inline, test_enable_bus_fault_ram)
{
	zassert_equal(at_tz_mpc_enable_bus_fault(AT_TZ_MPC_DEV_RAM), AT_TZ_MPC_RET_OK,
		      "enable_bus_fault(RAM) should return OK");
}

ZTEST(at_tz_mpc_inline, test_enable_bus_fault_invalid)
{
	zassert_equal(at_tz_mpc_enable_bus_fault(AT_TZ_MPC_DEV_INVALID), AT_TZ_MPC_RET_INVALID_TYPE,
		      "enable_bus_fault(INVALID) should return INVALID_TYPE");
}

ZTEST(at_tz_mpc_inline, test_lock_down_invalid)
{
	/* Only the error path is tested; locking FLASH/RAM is irreversible
	 * until reset and would break subsequent MPC configuration.       */
	zassert_equal(at_tz_mpc_lock_down(AT_TZ_MPC_DEV_INVALID), AT_TZ_MPC_RET_INVALID_TYPE,
		      "lock_down(INVALID) should return INVALID_TYPE");
}

ZTEST(at_tz_mpc_inline, test_remaining_ext_flash_secure)
{
	zassert_equal(at_tz_mpc_config_remaining_ext_flash(AT_TZ_MPC_ATTR_SECURE),
		      AT_TZ_MPC_RET_ATTR_UNAVAIL,
		      "remaining_ext_flash(SECURE) should return ATTR_UNAVAIL");
}

ZTEST(at_tz_mpc_inline, test_remaining_ext_flash_ns)
{
	zassert_equal(at_tz_mpc_config_remaining_ext_flash(AT_TZ_MPC_ATTR_NONSECURE),
		      AT_TZ_MPC_RET_OK, "remaining_ext_flash(NONSECURE) should return OK");
}

ZTEST_SUITE(at_tz_mpc_inline, NULL, NULL, NULL, NULL, NULL);
