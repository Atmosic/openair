/**
 ******************************************************************************
 *
 * @file sec_jrnl.c
 *
 * @brief Secure Journal Driver
 *
 * Copyright (C) Atmosic 2023-2024
 *
 ******************************************************************************
 */

#include "arch.h"
#include "string.h"
#include <inttypes.h>
#include "sec_jrnl.h"
#include "stdio.h"
#include "atm_utils_c.h"
#ifdef SECURE_PROC_ENV
#include "sec_service.h"
#endif

#if (!defined(SECURE_MODE) && !defined(CFG_NO_SPE))
#error "sec_jrnl is a secure-only driver. Access APIs through NSC functions"
#endif

// set to 1 for verbose printing
#define SEC_JRNL_DEBUG 0

// offset of magic number
#define SEC_JRNL_MAGIC_OFFSET 0
// length of magic number (in bytes)
#define SEC_JRNL_MAGIC_LEN 4
// offset of first tag
#define SEC_JRNL_FIRST_TAG_OFFSET (SEC_JRNL_MAGIC_OFFSET + SEC_JRNL_MAGIC_LEN)

// Verify offset to sec journal
#define SEC_JRNL_VERIFY_OFFSET(offset) ((offset) < CMSDK_SEC_JOURNAL_SIZE)

#define SEC_JRNL_VERIFY_OFFSET_BOUNDS(offset, len) \
    (SEC_JRNL_VERIFY_OFFSET(offset) && \
    (((offset) + (len)) < CMSDK_SEC_JOURNAL_SIZE))

// Convert offset to sec journal address
#define SEC_JRNL_OFF_TO_PTR(offset) \
    ((uint8_t const *)(SEC_JOURNAL_BASE + offset))

// tags are defined using a compressed length format
#define SEC_JRNL_HEADER_SIZE(header) \
    (sizeof(sec_jrnl_header_t) - (atm_get_le16(&(header)->length) & 0x80 ? \
    0 : 1))

#define SEC_JRNL_TAG_SIZE(header) \
    ((atm_get_le16(&(header)->length) & 0x7f) | \
	((atm_get_le16(&(header)->length) & 0x80) ? \
	((atm_get_le16(&(header)->length) & 0xff00) >> 1) : 0))

#define SEC_JRNL_STATUS_IMMUTABLE_MASK  0x02
// check if tag is immutable. Status bit is active low
#define SEC_JRNL_TAG_IS_IMMUTABLE(header) \
    (!((header)->status & SEC_JRNL_STATUS_IMMUTABLE_MASK))

#define SEC_JRNL_SEC_ONLY_TAG_MASK 0xFC // 0b111111XX
#define SEC_JRNL_SEC_ONLY_TAG_VAL 0xEC // 0b111011XX
#define IS_TAG_SECURE_ONLY(tag) \
    (((tag)&SEC_JRNL_SEC_ONLY_TAG_MASK) == SEC_JRNL_SEC_ONLY_TAG_VAL)

typedef struct sec_jrnl_header {
    uint8_t tag;
    uint8_t status;
    sec_jrnl_tag_len_t length;
} sec_jrnl_header_t;

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

static sec_jrnl_ret_status_t sec_jrnl_verify_magic(void)
{
    static uint8_t const sec_magic[SEC_JRNL_MAGIC_LEN] = {'N', 'V', 'D', 'S'};
    static bool magic_verified = false;
    if (magic_verified) {
	return SEC_JRNL_OK;
    }
    if (memcmp(SEC_JRNL_OFF_TO_PTR(SEC_JRNL_MAGIC_OFFSET), sec_magic,
	    SEC_JRNL_MAGIC_LEN)) {
	return SEC_JRNL_BAD_MAGIC;
    }
    magic_verified = true;
    return SEC_JRNL_OK;
}

static sec_jrnl_ret_status_t sec_jrnl_find_tag(uint8_t tag,
    sec_jrnl_tag_len_t *tag_length, uint16_t *tag_offset)
{
    sec_jrnl_ret_status_t ret = sec_jrnl_verify_magic();
    if (ret != SEC_JRNL_OK) {
	DEBUG_TRACE_COND(SEC_JRNL_DEBUG, "sec_jrnl_verify_magic failed!");
	return ret;
    }
    DEBUG_TRACE_COND(SEC_JRNL_DEBUG, "sec_jrnl_find_tag(%#x)", tag);
    sec_jrnl_header_t const *jrnl_header;
    uint16_t found_tag_offset = SEC_JRNL_MAGIC_OFFSET;
    uint16_t found_tag_size = 0;
    uint16_t offset = SEC_JRNL_FIRST_TAG_OFFSET;
    do {
	jrnl_header = (sec_jrnl_header_t const *)SEC_JRNL_OFF_TO_PTR(offset);
	if (jrnl_header->tag == tag) {
	    found_tag_offset = offset;
	    found_tag_size = SEC_JRNL_TAG_SIZE(jrnl_header);
	    if (SEC_JRNL_TAG_IS_IMMUTABLE(jrnl_header)) {
		// short-circuit if immutable
		break;
	    }
	}
	offset +=
	    SEC_JRNL_HEADER_SIZE(jrnl_header) + SEC_JRNL_TAG_SIZE(jrnl_header);
    } while (jrnl_header->tag != SEC_JRNL_INVALID_TAG);

    if (found_tag_offset == SEC_JRNL_MAGIC_OFFSET) {
	DEBUG_TRACE_COND(SEC_JRNL_DEBUG, "No tag found for %#x!",
	    tag);
	return SEC_JRNL_NO_TAG;
    }
    *tag_offset = found_tag_offset;
    if (*tag_length < found_tag_size) {
	return SEC_JRNL_LEN_TOO_LONG;
    }

    return SEC_JRNL_OK;
}

static sec_jrnl_ret_status_t sec_jrnl_walk_init_specific_ctx(
    sec_jrnl_walk_ctx_t *ctx)
{
    ctx->offset = 0;
    ctx->next_offset = SEC_JRNL_FIRST_TAG_OFFSET;
    ctx->tag = SEC_JRNL_INVALID_TAG;
    ctx->len = 0;
    return SEC_JRNL_OK;
}

static sec_jrnl_ret_status_t
sec_jrnl_walk_read_ctx_curr_tag(sec_jrnl_walk_ctx_t *ctx, uint32_t buf_len,
    uint8_t *buffer)
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

    sec_jrnl_header_t const *jrnl_header =
	(sec_jrnl_header_t const *)SEC_JRNL_OFF_TO_PTR(offset);
    memcpy(buffer, (SEC_JRNL_OFF_TO_PTR(offset) +
	SEC_JRNL_HEADER_SIZE(jrnl_header)), buf_len);
    return SEC_JRNL_OK;
}

static sec_jrnl_ret_status_t sec_jrnl_walk_ctx_tag(sec_jrnl_walk_ctx_t *ctx,
    uint8_t *tag, sec_jrnl_tag_len_t *tag_length)
{
    sec_jrnl_ret_status_t ret = sec_jrnl_verify_magic();
    if (ret != SEC_JRNL_OK) {
	DEBUG_TRACE_COND(SEC_JRNL_DEBUG, "sec_jrnl_verify_magic failed!");
	return ret;
    }
    ctx->offset = ctx->next_offset;
    if (!SEC_JRNL_VERIFY_OFFSET(ctx->offset)) {
	return SEC_JRNL_BAD_OFFSET;
    }

    sec_jrnl_header_t const *header =
	(sec_jrnl_header_t const *)SEC_JRNL_OFF_TO_PTR(ctx->offset);
    ctx->next_offset +=
	SEC_JRNL_HEADER_SIZE(header) + SEC_JRNL_TAG_SIZE(header);
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
    return sec_jrnl_walk_init_specific_ctx(&s_walk_ctx);
}

sec_jrnl_ret_status_t sec_jrnl_walk_read_curr_tag(uint32_t buf_len,
    uint8_t *buffer)
{
    return sec_jrnl_walk_read_ctx_curr_tag(&s_walk_ctx, buf_len, buffer);
}

sec_jrnl_ret_status_t sec_jrnl_walk_tag(uint8_t *tag,
    sec_jrnl_tag_len_t *tag_length)
{
    return sec_jrnl_walk_ctx_tag(&s_walk_ctx, tag, tag_length);
}

sec_jrnl_ret_status_t sec_jrnl_get(uint8_t tag, sec_jrnl_tag_len_t *tag_length,
    uint8_t *tag_data)
{
    DEBUG_TRACE_COND(SEC_JRNL_DEBUG, "sec_jrnl_get(%#x)", tag);
    sec_jrnl_tag_len_t length = *tag_length;
    uint16_t found_tag_offset;
    sec_jrnl_ret_status_t ret =
	sec_jrnl_find_tag(tag, &length, &found_tag_offset);
    if (ret != SEC_JRNL_OK) {
	return ret;
    }
    sec_jrnl_header_t const *jrnl_header =
	(sec_jrnl_header_t const *)SEC_JRNL_OFF_TO_PTR(found_tag_offset);

    memcpy(tag_data, (SEC_JRNL_OFF_TO_PTR(found_tag_offset) +
	SEC_JRNL_HEADER_SIZE(jrnl_header)), SEC_JRNL_TAG_SIZE(jrnl_header));
    *tag_length = SEC_JRNL_TAG_SIZE(jrnl_header);
    return SEC_JRNL_OK;
}

sec_jrnl_ret_status_t sec_jrnl_get_aligned_32(uint8_t tag,
    sec_jrnl_tag_len_t *tag_length, uint32_t *tag_data)
{
    DEBUG_TRACE_COND(SEC_JRNL_DEBUG, "sec_jrnl_get_aligned_32(%#x)", tag);
    sec_jrnl_tag_len_t length = *tag_length;
    uint16_t found_tag_offset;
    sec_jrnl_ret_status_t ret =
	sec_jrnl_find_tag(tag, &length, &found_tag_offset);

    if (ret != SEC_JRNL_OK) {
	return ret;
    }
    sec_jrnl_header_t const *jrnl_header =
	(sec_jrnl_header_t const *)SEC_JRNL_OFF_TO_PTR(found_tag_offset);

    length = SEC_JRNL_TAG_SIZE(jrnl_header);
    // length from jrnl tag must be mod
    if (length % 4) {
	ASSERT_INFO(0,length, tag);
	return SEC_JRNL_LEN_BAD_LEN;
    }
    uint16_t len_words = length / 4;
    // move offset to front of tag data
    found_tag_offset += SEC_JRNL_HEADER_SIZE(jrnl_header);
    // explict uint32_t copy
    for (uint16_t i = 0; i < len_words; i++) {
	*tag_data = *(uint32_t const *)SEC_JRNL_OFF_TO_PTR(found_tag_offset);
	found_tag_offset += 4;
	tag_data++;
    }
    *tag_length = length;
    return SEC_JRNL_OK;
}

#ifdef SECURE_PROC_ENV

__attribute__((cmse_nonsecure_entry)) __attribute__((used))
sec_jrnl_ret_status_t
nsc_sec_jrnl_walk_init_ctx(void)
{
    return sec_jrnl_walk_init_specific_ctx(&ns_walk_ctx);
}

__attribute__((cmse_nonsecure_entry)) __attribute__((used))
sec_jrnl_ret_status_t
nsc_sec_jrnl_walk_read_curr_tag(uint32_t buf_len, uint8_t *buffer)
{
    if (!mem_check_has_access(buffer, buf_len, true, true)) {
	return SEC_JRNL_NO_ACCESS;
    }
    if (IS_TAG_SECURE_ONLY(ns_walk_ctx.tag)) {
	return SEC_JRNL_NO_ACCESS;
    }
    return sec_jrnl_walk_read_ctx_curr_tag(&ns_walk_ctx, buf_len, buffer);
}

__attribute__((cmse_nonsecure_entry)) __attribute__((used))
sec_jrnl_ret_status_t
nsc_sec_jrnl_walk_tag(uint8_t *tag, sec_jrnl_tag_len_t *tag_length)
{
    if (!mem_check_has_access(tag, sizeof(uint8_t), true, true)) {
	return SEC_JRNL_NO_ACCESS;
    }
    if (!mem_check_has_access(tag_length, sizeof(sec_jrnl_tag_len_t), true,
	    true)) {
	return SEC_JRNL_NO_ACCESS;
    }
    sec_jrnl_ret_status_t ret;
    do {
	ret = sec_jrnl_walk_ctx_tag(&ns_walk_ctx, tag, tag_length);
    } while (IS_TAG_SECURE_ONLY(*tag));
    return ret;
}

__attribute__((cmse_nonsecure_entry))
__attribute__((used))
sec_jrnl_ret_status_t nsc_sec_jrnl_get(uint8_t tag, sec_jrnl_tag_len_t *tag_length,
    uint8_t *tag_data)
{
    if (!mem_check_has_access(tag_length, sizeof(sec_jrnl_tag_len_t), true,
	    true)) {
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

__attribute__((cmse_nonsecure_entry))
__attribute__((used))
sec_jrnl_ret_status_t nsc_sec_jrnl_get_aligned_32(uint8_t tag,
    sec_jrnl_tag_len_t *tag_length, uint32_t *tag_data)
{
    if (!mem_check_has_access(tag_length, sizeof(sec_jrnl_tag_len_t), true,
	    true)) {
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
#elif defined(CFG_NO_SPE)

sec_jrnl_ret_status_t nsc_sec_jrnl_walk_init_ctx(void)
    __attribute__((alias("sec_jrnl_walk_init_ctx")));

sec_jrnl_ret_status_t nsc_sec_jrnl_walk_read_curr_tag(uint32_t buf_len,
    uint8_t *buffer) __attribute__((alias("sec_jrnl_walk_read_curr_tag")));

sec_jrnl_ret_status_t nsc_sec_jrnl_walk_tag(uint8_t *tag,
    sec_jrnl_tag_len_t *tag_length) __attribute__((alias("sec_jrnl_walk_tag")));

sec_jrnl_ret_status_t nsc_sec_jrnl_get(uint8_t tag, uint16_t *tag_length,
    uint8_t *tag_data) __attribute__((alias("sec_jrnl_get")));

sec_jrnl_ret_status_t nsc_sec_jrnl_get_aligned_32(uint8_t tag,
    sec_jrnl_tag_len_t *tag_length, uint32_t *tag_data)
    __attribute__((alias("sec_jrnl_get_aligned_32")));

#endif
