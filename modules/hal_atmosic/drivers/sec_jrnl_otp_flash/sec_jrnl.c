/**
 ******************************************************************************
 *
 * @file sec_jrnl.c
 *
 * @brief Secure Journal Driver — common implementation for all platforms.
 *        Platform differences (header format, Flash support, OTP layout)
 *        are driven entirely by Devicetree properties.
 *
 * Copyright (C) Atmosic 2023-2026
 *
 ******************************************************************************
 */

#include <zephyr/devicetree.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "arch.h"
#include "string.h"
#include <inttypes.h>
#include "sec_jrnl.h"
#include "stdio.h"
#include "atm_utils_c.h"
#ifdef SECURE_PROC_ENV
#include "sec_service.h"
#endif
#ifndef CONFIG_ATM_SEC_JRNL_MOCK_DATA
#include "atm_otp.h"
#else
/* The mock array is defined by the test suite; provide an extern so the
 * SEC_JOURNAL_BASE macro (which expands to &sec_jrnl_nvds) resolves
 * correctly when sec_jrnl.c is compiled as a separate translation unit. */
extern uint8_t ATM_MOCK_JRNL_CONST sec_jrnl_nvds[];
#endif

#if (!defined(SECURE_MODE) && !defined(CFG_NO_SPE))
#error "sec_jrnl is a secure-only driver. Access APIs through NSC functions"
#endif

LOG_MODULE_REGISTER(sec_jrnl, LOG_LEVEL_INF);

/* ------------------------------------------------------------------ */
/* DTS-driven configuration                                           */
/* ------------------------------------------------------------------ */
/// Secure Journal DTS node (internal — not exposed in public header)
#define SEC_JRNL_NODE DT_NODELABEL(sec_jrnl)

#if DT_NODE_HAS_PROP(SEC_JRNL_NODE, reg)
#define SEC_JRNL_NODE_ADDR DT_REG_ADDR(SEC_JRNL_NODE)
#ifndef SEC_JOURNAL_BASE
#define SEC_JOURNAL_BASE SEC_JRNL_NODE_ADDR
#endif
#endif

#define SEC_JRNL_HAS_STATUS DT_PROP(SEC_JRNL_NODE, has_status_field)
/* SEC_JRNL_HAS_FLASH: 1 when the sec_jrnl node declares a mapped NVM (Flash)
 * region as the secondary journal source via flash-journal-size. */
#define SEC_JRNL_HAS_FLASH  DT_NODE_HAS_PROP(SEC_JRNL_NODE, flash_journal_size)
#define SEC_JRNL_OTP_OFF    DT_PROP(SEC_JRNL_NODE, otp_journal_offset)

/* SEC_JRNL_OTP_PRIMARY: 1 when the secure journal node declares OTP as its
 * primary source (indicated by the presence of otp-journal-size).
 * When 0, the primary source is a memory-mapped NVM region; the corresponding
 * search logic is implemented in the follow-on integration PR. */
#if DT_NODE_HAS_PROP(SEC_JRNL_NODE, otp_journal_size)
#define SEC_JRNL_OTP_PRIMARY 1
#else
#define SEC_JRNL_OTP_PRIMARY 0
#endif

#if DT_NODE_HAS_PROP(SEC_JRNL_NODE, otp_journal_size)
#define SEC_JRNL_OTP_SIZE DT_PROP(SEC_JRNL_NODE, otp_journal_size)
#elif DT_NODE_EXISTS(DT_NODELABEL(otp))
/* Fallback: use total OTP capacity when sec_jrnl node omits otp-journal-size. */
#define SEC_JRNL_OTP_SIZE DT_PROP(DT_NODELABEL(otp), otp_size)
#else
/* No OTP configured for this target's secure journal; define to 0 so the
 * preprocessor does not error when the otp nodelabel is absent. */
#define SEC_JRNL_OTP_SIZE 0
#endif

#if SEC_JRNL_HAS_FLASH
#define SEC_JRNL_FLASH_SIZE DT_PROP(SEC_JRNL_NODE, flash_journal_size)
#endif

#define SEC_JRNL_CACHE 1

// offset of magic number
#define SEC_JRNL_MAGIC_OFFSET     0
// length of magic number (in bytes)
#define SEC_JRNL_MAGIC_LEN        4
// offset of first tag
#define SEC_JRNL_FIRST_TAG_OFFSET (SEC_JRNL_MAGIC_OFFSET + SEC_JRNL_MAGIC_LEN)

#define SEC_JRNL_TOTAL_SIZE sec_jrnl_env.total_size

// Verify offset to sec journal
#define SEC_JRNL_VERIFY_OFFSET(offset) ((offset) < SEC_JRNL_TOTAL_SIZE)

#define SEC_JRNL_VERIFY_OFFSET_BOUNDS(offset, len)                                                 \
	(SEC_JRNL_VERIFY_OFFSET(offset) && (((offset) + (len)) < SEC_JRNL_TOTAL_SIZE))

// tags are defined using a compressed length format
#define SEC_JRNL_HEADER_SIZE(header)                                                               \
	(sizeof(sec_jrnl_header_t) - (atm_get_le16(&(header)->length) & 0x80 ? 0 : 1))

#define SEC_JRNL_TAG_SIZE(header)                                                                  \
	((atm_get_le16(&(header)->length) & 0x7f) |                                                \
	 ((atm_get_le16(&(header)->length) & 0x80)                                                 \
		  ? ((atm_get_le16(&(header)->length) & 0xff00) >> 1)                              \
		  : 0))

#if SEC_JRNL_HAS_STATUS
#define SEC_JRNL_STATUS_IMMUTABLE_MASK    0x02
// check if tag is immutable. Status bit is active low
#define SEC_JRNL_TAG_IS_IMMUTABLE(header) (!((header)->status & SEC_JRNL_STATUS_IMMUTABLE_MASK))
#else
// Without a status field every tag is treated as mutable
#define SEC_JRNL_TAG_IS_IMMUTABLE(header) (false)
#endif

#define SEC_JRNL_SEC_ONLY_TAG_MASK 0xFC // 0b111111XX
#define SEC_JRNL_SEC_ONLY_TAG_VAL  0xEC // 0b111011XX
#define IS_TAG_SECURE_ONLY(tag)    (((tag) & SEC_JRNL_SEC_ONLY_TAG_MASK) == SEC_JRNL_SEC_ONLY_TAG_VAL)

/* TLV header — layout depends on has-status-field DTS property */
#if SEC_JRNL_HAS_STATUS
typedef struct sec_jrnl_header {
	uint8_t tag;
	uint8_t status;
	sec_jrnl_tag_len_t length;
} sec_jrnl_header_t;
#else
typedef struct __packed sec_jrnl_header {
	uint8_t tag;
	sec_jrnl_tag_len_t length;
} sec_jrnl_header_t;
#endif

typedef struct sec_jrnl_walk_ctx {
	uint32_t offset;
	uint32_t next_offset;
	uint8_t tag;
	sec_jrnl_tag_len_t len;
} sec_jrnl_walk_ctx_t;

#ifdef SECURE_PROC_ENV
static sec_jrnl_walk_ctx_t ns_walk_ctx;
#endif
static sec_jrnl_walk_ctx_t s_walk_ctx;

typedef struct {
	void (*read)(uint32_t const offset, uint32_t const length, uint8_t *buf);
	uint8_t *space_base;
	uint32_t total_size;
	sec_jrnl_space_id_t space_id;
} sec_jrnl_env_t;

static sec_jrnl_env_t sec_jrnl_env;
static bool init_jrnl;

/* Bitmask of journal spaces whose magic has already been verified.  Held
 * outside sec_jrnl_env because that struct is rebuilt by every
 * sec_jrnl_init() call, which would otherwise discard the result and force a
 * magic re-read on every access.  Only successful verifications are recorded,
 * so a source that is currently blank is still retried. */
static uint8_t sec_jrnl_magic_verified_mask;
#define SEC_JRNL_MAGIC_VERIFIED_BIT(id) ((uint8_t)(1U << (id)))

#ifdef SEC_JRNL_CACHE

/*
 * Cache entry layout (16 bits):
 *   [15]    immutable flag
 *   [14:13] space_id  (0=OTP, 1=FLASH, 2=RAM)
 *   [12:0]  offset within that space
 */
#define SEC_JRNL_CACHE_IMMUTABLE_MASK 0x8000
#define SEC_JRNL_CACHE_SPACE_SHIFT    13
#define SEC_JRNL_CACHE_SPACE_MASK     (0x3 << SEC_JRNL_CACHE_SPACE_SHIFT)
#define SEC_JRNL_CACHE_OFFSET_MASK    0x1FFF
#define SEC_JRNL_CACHE_ENCODE(immutable, space_id, offset)                                         \
	((((immutable) & 0x1) << 15) | (((space_id) & 0x3) << SEC_JRNL_CACHE_SPACE_SHIFT) |        \
	 ((offset) & SEC_JRNL_CACHE_OFFSET_MASK))

#define SEC_JRNL_CACHE_GET_IMMUTABLE(entry) (((entry) & SEC_JRNL_CACHE_IMMUTABLE_MASK) >> 15)

#define SEC_JRNL_CACHE_GET_SPACE(entry)                                                            \
	((sec_jrnl_space_id_t)(((entry) & SEC_JRNL_CACHE_SPACE_MASK) >> SEC_JRNL_CACHE_SPACE_SHIFT))

#define SEC_JRNL_CACHE_GET_OFFSET(entry) ((entry) & SEC_JRNL_CACHE_OFFSET_MASK)

typedef uint16_t sec_jrnl_tag_cache_table_t[256];
static sec_jrnl_tag_cache_table_t __noinit sec_jrnl_tag_cache;

static uint8_t sec_jrnl_nxt_tag_status;
static uint16_t sec_jrnl_nxt_tag_addr;

void sec_jrnl_reset_tag_cache(void)
{
	sec_jrnl_nxt_tag_status = SEC_JRNL_OK;
	sec_jrnl_nxt_tag_addr = SEC_JRNL_FIRST_TAG_OFFSET;
	sec_jrnl_magic_verified_mask = 0;

	memset(sec_jrnl_tag_cache, 0, sizeof(sec_jrnl_tag_cache_table_t));
}

__STATIC_FORCEINLINE uint8_t sec_jrnl_get_cached_tag_status(void)
{
	return sec_jrnl_nxt_tag_status;
}

__STATIC_FORCEINLINE void sec_jrnl_put_cached_tag_status(uint8_t status)
{
	sec_jrnl_nxt_tag_status = status;
}

__STATIC_FORCEINLINE uint16_t sec_jrnl_get_cached_tag_addr(void)
{
	return sec_jrnl_nxt_tag_addr;
}

__STATIC_FORCEINLINE void sec_jrnl_put_cached_tag_addr(bool cache_miss, uint16_t addr)
{
	if (cache_miss) {
		sec_jrnl_nxt_tag_addr = addr;
	}
}

__STATIC_FORCEINLINE uint32_t sec_jrnl_get_cached_tag(bool *cache_miss, uint8_t tag)
{
	uint16_t entry = sec_jrnl_tag_cache[tag];
	if (entry == 0 || (SEC_JRNL_CACHE_GET_SPACE(entry) != sec_jrnl_env.space_id)) {
		*cache_miss = true;
		return SEC_JRNL_FIRST_TAG_OFFSET;
	}

	*cache_miss = false;
	return SEC_JRNL_CACHE_GET_OFFSET(entry);
}

__STATIC_FORCEINLINE void sec_jrnl_put_cached_tag(sec_jrnl_header_t const *head, uint16_t tag_addr)
{
	if (!SEC_JRNL_CACHE_GET_IMMUTABLE(sec_jrnl_tag_cache[head->tag])) {
		sec_jrnl_tag_cache[head->tag] = SEC_JRNL_CACHE_ENCODE(
			SEC_JRNL_TAG_IS_IMMUTABLE(head), sec_jrnl_env.space_id, tag_addr);
	}
}
#endif

/*
 * Read from OTP (eFuse).
 * In mock-data mode (CONFIG_ATM_SEC_JRNL_MOCK_DATA) the hardware OTP DMA
 * path is bypassed; reads go directly to SEC_JOURNAL_BASE (a RAM array
 * supplied by the test suite via a compile-time definition).
 */
static void read_from_otp(uint32_t const offset, uint32_t const length, uint8_t *buf)
{
#ifdef CONFIG_ATM_SEC_JRNL_MOCK_DATA
	memcpy(buf, (uint8_t const *)(uintptr_t)(SEC_JOURNAL_BASE + offset), length);
#else
	atm_otp_read_address(SEC_JRNL_OTP_OFF + offset, length, buf, true);
#endif
}

#if SEC_JRNL_HAS_FLASH
/*
 * Read from the memory-mapped NVM region (Flash/secondary source).
 * space_base is set to SEC_JOURNAL_BASE at FLASH_JRNL initialisation, so in
 * mock-data mode (CONFIG_ATM_SEC_JRNL_MOCK_DATA) the test's compile-time
 * override of SEC_JOURNAL_BASE causes this function to read from the same
 * mock array as read_from_otp() — no extra #ifdef needed here.
 */
static void read_from_flash(uint32_t const offset, uint32_t const length, uint8_t *buf)
{
	memcpy(buf, (void *)(sec_jrnl_env.space_base + offset), length);
}
#endif

#ifdef CONFIG_ATM_SEC_JRNL_RAM
static uint8_t const *sec_jrnl_ram_ptr;
static uint32_t sec_jrnl_ram_size;
static bool ram_jrnl_initialized;

static void read_from_ram(uint32_t const offset, uint32_t const length, uint8_t *buf)
{
	memcpy(buf, sec_jrnl_ram_ptr + offset, length);
}

sec_jrnl_ret_status_t sec_jrnl_ram_init(uint8_t const *data, uint16_t len)
{
	static uint8_t const sec_magic[SEC_JRNL_MAGIC_LEN] = {'N', 'V', 'D', 'S'};

	ram_jrnl_initialized = false;
	sec_jrnl_ram_ptr = NULL;
	sec_jrnl_ram_size = 0;
	/* The RAM backing store is being replaced, so any previous verification
	 * of its magic no longer applies. */
	sec_jrnl_magic_verified_mask &= ~SEC_JRNL_MAGIC_VERIFIED_BIT(RAM_JRNL);

	if (!data || len == 0) {
		return SEC_JRNL_BAD_MAGIC;
	}
	if (len < SEC_JRNL_MAGIC_LEN || memcmp(data, sec_magic, SEC_JRNL_MAGIC_LEN) != 0) {
		return SEC_JRNL_BAD_MAGIC;
	}
	sec_jrnl_ram_ptr = data;
	sec_jrnl_ram_size = len;

	ram_jrnl_initialized = true;
	init_jrnl = true;
#ifdef SEC_JRNL_CACHE
	sec_jrnl_reset_tag_cache();
#endif
	return SEC_JRNL_OK;
}
#endif

static void sec_jrnl_init(sec_jrnl_space_id_t id)
{
#ifdef SEC_JRNL_CACHE
	/* When switching journal source, reset the scan-progress state so that
	 * the new source is scanned from the beginning.  Cached tag offsets
	 * remain valid — they are filtered by space_id at lookup time. */
	if (init_jrnl && sec_jrnl_env.space_id != id) {
		sec_jrnl_nxt_tag_status = SEC_JRNL_OK;
		sec_jrnl_nxt_tag_addr = SEC_JRNL_FIRST_TAG_OFFSET;
	}
#endif
	switch (id) {
	case OTP_JRNL:
		sec_jrnl_env = (sec_jrnl_env_t){
			.read = read_from_otp,
			.space_base = (uint8_t *)(uintptr_t)SEC_JRNL_OTP_OFF,
			.total_size = SEC_JRNL_OTP_SIZE,
			.space_id = OTP_JRNL,
		};
		break;
#if SEC_JRNL_HAS_FLASH
	case FLASH_JRNL:
		sec_jrnl_env = (sec_jrnl_env_t){
			.read = read_from_flash,
			.space_base = (uint8_t *)SEC_JOURNAL_BASE,
			.total_size = SEC_JRNL_FLASH_SIZE,
			.space_id = FLASH_JRNL,
		};
		break;
#endif
#ifdef CONFIG_ATM_SEC_JRNL_RAM
	case RAM_JRNL:
		sec_jrnl_env = (sec_jrnl_env_t){
			.read = read_from_ram,
			.space_base = (uint8_t *)sec_jrnl_ram_ptr,
			.total_size = sec_jrnl_ram_size,
			.space_id = RAM_JRNL,
		};
		break;
#endif
	default:
		break;
	}
}

static sec_jrnl_ret_status_t sec_jrnl_verify_magic(void)
{
	if (!init_jrnl) {
#if SEC_JRNL_OTP_PRIMARY
		sec_jrnl_init(OTP_JRNL);
#endif
#ifdef SEC_JRNL_CACHE
		sec_jrnl_reset_tag_cache();
#endif
		init_jrnl = true;
	}

	static uint8_t const sec_magic[SEC_JRNL_MAGIC_LEN] = {'N', 'V', 'D', 'S'};
#ifdef CONFIG_ATM_SEC_JRNL_RAM
	if (sec_jrnl_env.space_id == RAM_JRNL && !ram_jrnl_initialized) {
		return SEC_JRNL_BAD_MAGIC;
	}
#endif
	uint8_t const verified_bit = SEC_JRNL_MAGIC_VERIFIED_BIT(sec_jrnl_env.space_id);
	if (sec_jrnl_magic_verified_mask & verified_bit) {
		return SEC_JRNL_OK;
	}

	uint8_t buf[SEC_JRNL_MAGIC_LEN];
	sec_jrnl_env.read(0, SEC_JRNL_MAGIC_LEN, buf);
	if (memcmp(buf, sec_magic, SEC_JRNL_MAGIC_LEN)) {
		return SEC_JRNL_BAD_MAGIC;
	}
	sec_jrnl_magic_verified_mask |= verified_bit;

	if (sec_jrnl_env.space_id == OTP_JRNL) {
		LOG_INF("sec_jrnl found in OTP");
	} else if (sec_jrnl_env.space_id == FLASH_JRNL) {
		LOG_INF("sec_jrnl found in flash");
#ifdef CONFIG_ATM_SEC_JRNL_RAM
	} else if (sec_jrnl_env.space_id == RAM_JRNL) {
		LOG_INF("sec_jrnl found in RAM");
#endif
	}

	return SEC_JRNL_OK;
}

static sec_jrnl_ret_status_t sec_jrnl_find_tag(uint8_t tag, uint16_t *tag_offset)
{
	sec_jrnl_ret_status_t ret = sec_jrnl_verify_magic();
	if (ret != SEC_JRNL_OK) {
		LOG_DBG("sec_jrnl_verify_magic failed!\n");
		return ret;
	}
	LOG_DBG("sec_jrnl_find_tag(%#x)\n", tag);

	sec_jrnl_header_t const *jrnl_header;
	uint16_t found_tag_offset = SEC_JRNL_MAGIC_OFFSET;
	uint16_t offset = SEC_JRNL_FIRST_TAG_OFFSET;
	uint8_t buf_header[sizeof(sec_jrnl_header_t)];

#ifdef SEC_JRNL_CACHE
	bool cache_miss;
	uint16_t cached_offset = sec_jrnl_get_cached_tag(&cache_miss, tag);
	if (!cache_miss) {
		LOG_DBG("cache_offset(%#x)\n", cached_offset);
		*tag_offset = cached_offset;
		return SEC_JRNL_OK;
	}

	offset = sec_jrnl_get_cached_tag_addr();
	ret = sec_jrnl_get_cached_tag_status();
	if (ret != SEC_JRNL_OK) {
		*tag_offset = offset;
		return ret;
	}
#endif
	LOG_DBG("find_from_offset(%#x)\n", offset);
	for (;;) {
		uint16_t cur_offset = offset;

		sec_jrnl_env.read(cur_offset, sizeof(sec_jrnl_header_t), buf_header);
		jrnl_header = (sec_jrnl_header_t const *)buf_header;

		if (jrnl_header->tag == SEC_JRNL_INVALID_TAG) {
			ret = SEC_JRNL_NO_TAG;
			break;
		}

#ifdef SEC_JRNL_CACHE
		sec_jrnl_put_cached_tag(jrnl_header, cur_offset);
#endif

		if (jrnl_header->tag == tag) {
			found_tag_offset = cur_offset;
			ret = SEC_JRNL_OK;
			if (SEC_JRNL_TAG_IS_IMMUTABLE(jrnl_header)) {
				break;
			}
		}

		offset += SEC_JRNL_HEADER_SIZE(jrnl_header) + SEC_JRNL_TAG_SIZE(jrnl_header);
		if (!SEC_JRNL_VERIFY_OFFSET(offset)) {
			ret = SEC_JRNL_BAD_OFFSET;
			break;
		}
	}

#ifdef SEC_JRNL_CACHE
	sec_jrnl_put_cached_tag_status(ret);
	sec_jrnl_put_cached_tag_addr(cache_miss, offset);
#endif

	*tag_offset = found_tag_offset;
	/* Return OK if the tag was found (found_tag_offset advanced past the magic
	 * sentinel), otherwise propagate the scan-termination status (NO_TAG or
	 * BAD_OFFSET). */
	return (found_tag_offset != SEC_JRNL_MAGIC_OFFSET) ? SEC_JRNL_OK : ret;
}

static sec_jrnl_ret_status_t sec_jrnl_walk_init_specific_ctx(sec_jrnl_walk_ctx_t *ctx)
{
	ctx->offset = 0;
	ctx->next_offset = SEC_JRNL_FIRST_TAG_OFFSET;
	ctx->tag = SEC_JRNL_INVALID_TAG;
	ctx->len = 0;
	return SEC_JRNL_OK;
}

static sec_jrnl_ret_status_t sec_jrnl_walk_read_ctx_curr_tag(sec_jrnl_walk_ctx_t *ctx,
							     uint32_t buf_len, uint8_t *buffer)
{
	uint32_t offset = ctx->offset;
	if (!SEC_JRNL_VERIFY_OFFSET_BOUNDS(offset, buf_len)) {
		ASSERT_INFO(0, offset, buf_len);
		return SEC_JRNL_BAD_OFFSET;
	}
	// Can only read up to size of current tag.
	if (buf_len > ctx->len) {
		return SEC_JRNL_LEN_BAD_LEN;
	}

	uint8_t buf_header[sizeof(sec_jrnl_header_t)];
	sec_jrnl_env.read(offset, sizeof(sec_jrnl_header_t), buf_header);
	sec_jrnl_header_t const *jrnl_header = (sec_jrnl_header_t const *)buf_header;
	uint8_t buf_value[buf_len];
	sec_jrnl_env.read(offset + SEC_JRNL_HEADER_SIZE(jrnl_header), buf_len, buf_value);
	memcpy(buffer, buf_value, buf_len);
	return SEC_JRNL_OK;
}

static sec_jrnl_ret_status_t sec_jrnl_walk_ctx_tag(sec_jrnl_walk_ctx_t *ctx, uint8_t *tag,
						   sec_jrnl_tag_len_t *tag_length)
{
	sec_jrnl_ret_status_t ret = sec_jrnl_verify_magic();
	if (ret != SEC_JRNL_OK) {
		LOG_DBG("sec_jrnl_verify_magic failed!\n");
		return ret;
	}
	ctx->offset = ctx->next_offset;
	if (!SEC_JRNL_VERIFY_OFFSET(ctx->offset)) {
		return SEC_JRNL_BAD_OFFSET;
	}

	uint8_t buf_header[sizeof(sec_jrnl_header_t)];
	sec_jrnl_env.read(ctx->offset, sizeof(sec_jrnl_header_t), buf_header);
	sec_jrnl_header_t const *header = (sec_jrnl_header_t const *)buf_header;
	ctx->next_offset += SEC_JRNL_HEADER_SIZE(header) + SEC_JRNL_TAG_SIZE(header);
	ctx->tag = header->tag;
	*tag = ctx->tag;
	ctx->len = SEC_JRNL_TAG_SIZE(header);
	*tag_length = ctx->len;

	if (*tag == SEC_JRNL_INVALID_TAG) {
		return SEC_JRNL_NO_TAG;
	}
	return SEC_JRNL_OK;
}

sec_jrnl_ret_status_t sec_jrnl_walk_init_ctx(void)
{
#ifdef CONFIG_ATM_SEC_JRNL_RAM
	/* RAM journal has highest priority — mirrors sec_jrnl_get behaviour. */
	if (ram_jrnl_initialized) {
		sec_jrnl_init(RAM_JRNL);
		return sec_jrnl_walk_init_specific_ctx(&s_walk_ctx);
	}
#endif
#if SEC_JRNL_OTP_PRIMARY
	/* Mirror sec_jrnl_get: always start a source-agnostic walk from the
	 * primary (OTP) journal so that a prior sec_jrnl_walk_init_ctx_source()
	 * call cannot leave sec_jrnl_env pointing at RAM or Flash. */
	sec_jrnl_init(OTP_JRNL);
#if SEC_JRNL_HAS_FLASH
	/* If the OTP journal has no valid magic (e.g. blank OTP in simulation),
	 * fall back to the Flash journal — matching sec_jrnl_get's OTP→Flash
	 * search order so that a source-agnostic walk finds data wherever
	 * sec_jrnl_get would find it. */
	if (sec_jrnl_verify_magic() != SEC_JRNL_OK) {
		sec_jrnl_init(FLASH_JRNL);
	}
#endif /* SEC_JRNL_HAS_FLASH */
#endif /* SEC_JRNL_OTP_PRIMARY */
	return sec_jrnl_walk_init_specific_ctx(&s_walk_ctx);
}

sec_jrnl_ret_status_t sec_jrnl_walk_init_ctx_source(sec_jrnl_space_id_t source_id)
{
	sec_jrnl_init(source_id);
	return sec_jrnl_walk_init_specific_ctx(&s_walk_ctx);
}

sec_jrnl_ret_status_t sec_jrnl_walk_read_curr_tag(uint32_t buf_len, uint8_t *buffer)
{
	return sec_jrnl_walk_read_ctx_curr_tag(&s_walk_ctx, buf_len, buffer);
}

sec_jrnl_ret_status_t sec_jrnl_walk_tag(uint8_t *tag, sec_jrnl_tag_len_t *tag_length)
{
	return sec_jrnl_walk_ctx_tag(&s_walk_ctx, tag, tag_length);
}

static sec_jrnl_ret_status_t sec_jrnl_get_common(uint8_t tag, sec_jrnl_tag_len_t *tag_length,
						 uint8_t *tag_data)
{
	sec_jrnl_tag_len_t length = *tag_length;
	uint16_t found_tag_offset;
	sec_jrnl_ret_status_t ret = sec_jrnl_find_tag(tag, &found_tag_offset);
	if (ret != SEC_JRNL_OK) {
		return ret;
	}

	if (found_tag_offset == SEC_JRNL_MAGIC_OFFSET) {
		LOG_DBG("No tag found for %#x!\n", tag);
		return SEC_JRNL_NO_TAG;
	}

	uint8_t buf_header[sizeof(sec_jrnl_header_t)];
	sec_jrnl_env.read(found_tag_offset, sizeof(sec_jrnl_header_t), buf_header);
	sec_jrnl_header_t const *jrnl_header = (sec_jrnl_header_t const *)buf_header;

	length = SEC_JRNL_TAG_SIZE(jrnl_header);
	LOG_DBG("found_tag_offset: %#x!\n", found_tag_offset);
	if (*tag_length < length) {
		return SEC_JRNL_LEN_TOO_LONG;
	}

	sec_jrnl_env.read(found_tag_offset + SEC_JRNL_HEADER_SIZE(jrnl_header), length, tag_data);
	*tag_length = length;

	return SEC_JRNL_OK;
}

sec_jrnl_ret_status_t sec_jrnl_get(uint8_t tag, sec_jrnl_tag_len_t *tag_length, uint8_t *tag_data)
{
	LOG_DBG("sec_jrnl_get(%#x)\n", tag);

#ifdef CONFIG_ATM_SEC_JRNL_RAM
	/* RAM journal has highest priority: when initialized it represents
	 * test-injected data that should completely shadow OTP/Flash. */
	if (ram_jrnl_initialized) {
		sec_jrnl_init(RAM_JRNL);
		return sec_jrnl_get_common(tag, tag_length, tag_data);
	}
#endif

	sec_jrnl_ret_status_t ret;

#if SEC_JRNL_OTP_PRIMARY
	/* OTP-primary search order: OTP → Flash (optional) */
	sec_jrnl_init(OTP_JRNL);
	ret = sec_jrnl_get_common(tag, tag_length, tag_data);
#if SEC_JRNL_HAS_FLASH
	if (ret != SEC_JRNL_OK) {
		sec_jrnl_init(FLASH_JRNL);
		ret = sec_jrnl_get_common(tag, tag_length, tag_data);
	}
#endif /* SEC_JRNL_HAS_FLASH */
#else
	/* Non-OTP-primary search order placeholder.
	 * Primary source initialisation and Flash fallback are implemented
	 * in the follow-on integration PR. */
	ret = SEC_JRNL_NO_TAG;
#endif /* SEC_JRNL_OTP_PRIMARY */

	return ret;
}

static sec_jrnl_ret_status_t
sec_jrnl_get_aligned_32_common(uint8_t tag, sec_jrnl_tag_len_t *tag_length, uint32_t *tag_data)
{
	sec_jrnl_tag_len_t length = *tag_length;
	uint16_t found_tag_offset;
	sec_jrnl_ret_status_t ret = sec_jrnl_find_tag(tag, &found_tag_offset);

	if (ret != SEC_JRNL_OK) {
		return ret;
	}

	if (found_tag_offset == SEC_JRNL_MAGIC_OFFSET) {
		LOG_DBG("No tag found for %#x!\n", tag);
		return SEC_JRNL_NO_TAG;
	}

	uint8_t buf_header[sizeof(sec_jrnl_header_t)];
	sec_jrnl_env.read(found_tag_offset, sizeof(sec_jrnl_header_t), buf_header);
	sec_jrnl_header_t const *jrnl_header = (sec_jrnl_header_t const *)buf_header;

	length = SEC_JRNL_TAG_SIZE(jrnl_header);
	LOG_DBG("found_tag_offset: %#x!\n", found_tag_offset);
	if (*tag_length < length) {
		return SEC_JRNL_LEN_TOO_LONG;
	}

	// length from jrnl tag must be mod 4 for aligned-32 reads
	if (length % 4) {
		return SEC_JRNL_LEN_BAD_LEN;
	}
	uint16_t len_words = length / 4;
	// move offset to front of tag data
	found_tag_offset += SEC_JRNL_HEADER_SIZE(jrnl_header);
	// explict uint32_t copy
	for (uint16_t i = 0; i < len_words; i++) {
		uint8_t buf_value[sizeof(uint32_t)];
		sec_jrnl_env.read(found_tag_offset, sizeof(uint32_t), buf_value);
		*tag_data = *(uint32_t const *)buf_value;
		found_tag_offset += 4;
		tag_data++;
	}
	*tag_length = length;
	return SEC_JRNL_OK;
}

sec_jrnl_ret_status_t sec_jrnl_get_aligned_32(uint8_t tag, sec_jrnl_tag_len_t *tag_length,
					      uint32_t *tag_data)
{
	LOG_DBG("sec_jrnl_get_aligned_32(%#x)\n", tag);

#ifdef CONFIG_ATM_SEC_JRNL_RAM
	/* RAM journal has highest priority: when initialized it represents
	 * test-injected data that should completely shadow OTP/Flash. */
	if (ram_jrnl_initialized) {
		sec_jrnl_init(RAM_JRNL);
		return sec_jrnl_get_aligned_32_common(tag, tag_length, tag_data);
	}
#endif

	sec_jrnl_ret_status_t ret;

#if SEC_JRNL_OTP_PRIMARY
	/* OTP-primary search order: OTP → Flash (optional) */
	sec_jrnl_init(OTP_JRNL);
	ret = sec_jrnl_get_aligned_32_common(tag, tag_length, tag_data);
#if SEC_JRNL_HAS_FLASH
	if (ret != SEC_JRNL_OK) {
		sec_jrnl_init(FLASH_JRNL);
		ret = sec_jrnl_get_aligned_32_common(tag, tag_length, tag_data);
	}
#endif /* SEC_JRNL_HAS_FLASH */
#else
	/* Non-OTP-primary search order placeholder.
	 * Primary source initialisation and Flash fallback are implemented
	 * in the follow-on integration PR. */
	ret = SEC_JRNL_NO_TAG;
#endif /* SEC_JRNL_OTP_PRIMARY */

	return ret;
}

#ifdef SECURE_PROC_ENV

__SPE_NSC sec_jrnl_ret_status_t nsc_sec_jrnl_walk_init_ctx(void)
{
#ifdef CONFIG_ATM_SEC_JRNL_RAM
	/* RAM journal has highest priority — mirrors sec_jrnl_get behaviour. */
	if (ram_jrnl_initialized) {
		sec_jrnl_init(RAM_JRNL);
		return sec_jrnl_walk_init_specific_ctx(&ns_walk_ctx);
	}
#endif
#if SEC_JRNL_OTP_PRIMARY
	sec_jrnl_init(OTP_JRNL);
#if SEC_JRNL_HAS_FLASH
	if (sec_jrnl_verify_magic() != SEC_JRNL_OK) {
		sec_jrnl_init(FLASH_JRNL);
	}
#endif /* SEC_JRNL_HAS_FLASH */
#endif /* SEC_JRNL_OTP_PRIMARY */
	return sec_jrnl_walk_init_specific_ctx(&ns_walk_ctx);
}

__SPE_NSC sec_jrnl_ret_status_t nsc_sec_jrnl_walk_init_ctx_source(sec_jrnl_space_id_t source_id)
{
	sec_jrnl_init(source_id);
	return sec_jrnl_walk_init_specific_ctx(&ns_walk_ctx);
}

__SPE_NSC sec_jrnl_ret_status_t nsc_sec_jrnl_walk_read_curr_tag(uint32_t buf_len, uint8_t *buffer)
{
	if (!mem_check_has_access(buffer, buf_len, true, true)) {
		return SEC_JRNL_NO_ACCESS;
	}
	if (IS_TAG_SECURE_ONLY(ns_walk_ctx.tag)) {
		return SEC_JRNL_NO_ACCESS;
	}
	return sec_jrnl_walk_read_ctx_curr_tag(&ns_walk_ctx, buf_len, buffer);
}

__SPE_NSC sec_jrnl_ret_status_t nsc_sec_jrnl_walk_tag(uint8_t *tag, sec_jrnl_tag_len_t *tag_length)
{
	if (!mem_check_has_access(tag, sizeof(uint8_t), true, true)) {
		return SEC_JRNL_NO_ACCESS;
	}
	if (!mem_check_has_access(tag_length, sizeof(sec_jrnl_tag_len_t), true, true)) {
		return SEC_JRNL_NO_ACCESS;
	}
	sec_jrnl_ret_status_t ret;
	do {
		ret = sec_jrnl_walk_ctx_tag(&ns_walk_ctx, tag, tag_length);
	} while (IS_TAG_SECURE_ONLY(*tag));
	return ret;
}

__SPE_NSC sec_jrnl_ret_status_t nsc_sec_jrnl_get(uint8_t tag, sec_jrnl_tag_len_t *tag_length,
						 uint8_t *tag_data)
{
	if (!mem_check_has_access(tag_length, sizeof(sec_jrnl_tag_len_t), true, true)) {
		return SEC_JRNL_NO_ACCESS;
	}
	if (!mem_check_has_access(tag_data, *tag_length, true, true)) {
		return SEC_JRNL_NO_ACCESS;
	}
	if (IS_TAG_SECURE_ONLY(tag)) {
		return SEC_JRNL_TAG_SECURE_ONLY;
	}
	return sec_jrnl_get(tag, tag_length, tag_data);
}

__SPE_NSC sec_jrnl_ret_status_t nsc_sec_jrnl_get_aligned_32(uint8_t tag,
							    sec_jrnl_tag_len_t *tag_length,
							    uint32_t *tag_data)
{
	if (!mem_check_has_access(tag_length, sizeof(sec_jrnl_tag_len_t), true, true)) {
		return SEC_JRNL_NO_ACCESS;
	}
	if (!mem_check_has_access(tag_data, *tag_length, true, true)) {
		return SEC_JRNL_NO_ACCESS;
	}
	if (IS_TAG_SECURE_ONLY(tag)) {
		return SEC_JRNL_TAG_SECURE_ONLY;
	}
	return sec_jrnl_get_aligned_32(tag, tag_length, tag_data);
}

__SPE_NSC void nsc_sec_jrnl_reset_tag_cache(void)
{
	sec_jrnl_reset_tag_cache();
}

#ifdef CONFIG_ATM_SEC_JRNL_RAM
__SPE_NSC sec_jrnl_ret_status_t nsc_sec_jrnl_ram_init(uint8_t const *data, uint16_t len)
{
	if (data && len) {
		if (!mem_check_has_access(data, len, false, true)) {
			return SEC_JRNL_NO_ACCESS;
		}
	}
	return sec_jrnl_ram_init(data, len);
}
#endif /* CONFIG_ATM_SEC_JRNL_RAM */
#elif defined(CFG_NO_SPE)

sec_jrnl_ret_status_t nsc_sec_jrnl_walk_init_ctx(void)
	__attribute__((alias("sec_jrnl_walk_init_ctx")));

sec_jrnl_ret_status_t nsc_sec_jrnl_walk_init_ctx_source(sec_jrnl_space_id_t source_id)
	__attribute__((alias("sec_jrnl_walk_init_ctx_source")));

sec_jrnl_ret_status_t nsc_sec_jrnl_walk_read_curr_tag(uint32_t buf_len, uint8_t *buffer)
	__attribute__((alias("sec_jrnl_walk_read_curr_tag")));

sec_jrnl_ret_status_t nsc_sec_jrnl_walk_tag(uint8_t *tag, sec_jrnl_tag_len_t *tag_length)
	__attribute__((alias("sec_jrnl_walk_tag")));

sec_jrnl_ret_status_t nsc_sec_jrnl_get(uint8_t tag, sec_jrnl_tag_len_t *tag_length,
				       uint8_t *tag_data) __attribute__((alias("sec_jrnl_get")));

sec_jrnl_ret_status_t nsc_sec_jrnl_get_aligned_32(uint8_t tag, sec_jrnl_tag_len_t *tag_length,
						  uint32_t *tag_data)
	__attribute__((alias("sec_jrnl_get_aligned_32")));

void nsc_sec_jrnl_reset_tag_cache(void) __attribute__((alias("sec_jrnl_reset_tag_cache")));

#ifdef CONFIG_ATM_SEC_JRNL_RAM
sec_jrnl_ret_status_t nsc_sec_jrnl_ram_init(uint8_t const *data, uint16_t len)
	__attribute__((alias("sec_jrnl_ram_init")));
#endif /* CONFIG_ATM_SEC_JRNL_RAM */

#endif
