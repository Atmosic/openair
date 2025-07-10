/**
 ******************************************************************************
 *
 * @file sec_jrnl.h
 *
 * @brief Secure Jornal driver
 *
 * Copyright (C) Atmosic 2022-2024
 *
 ******************************************************************************
 */

#pragma once

/**
 * @defgroup SEC_JRNL Secure Journal
 * @ingroup DRIVERS
 * @brief Secure Journal driver
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/// Secure Journal start address
#define CMSDK_SEC_JOURNAL_BASE 0x1008f800
#ifndef SEC_JOURNAL_BASE
#define SEC_JOURNAL_BASE  CMSDK_SEC_JOURNAL_BASE
#endif
/// Secure Journal journal size
#define CMSDK_SEC_JOURNAL_SIZE 1776

/// invalid tag value
#define SEC_JRNL_INVALID_TAG 0xff

/// Secure Journal return values
typedef enum {
    /// OK
    SEC_JRNL_OK,
    /// Tag not found
    SEC_JRNL_NO_TAG,
    /// Magic Number is corrupt
    SEC_JRNL_BAD_MAGIC,
    /// Caller doesnt have access to passed buffer
    SEC_JRNL_NO_ACCESS,
    /// Caller passed invalid offset
    SEC_JRNL_BAD_OFFSET,
    /// Stored length is not aligned to necessary boundary
    SEC_JRNL_LEN_BAD_LEN,
    /// Stored length exceeds pass buffer size
    SEC_JRNL_LEN_TOO_LONG,
    /// NS Caller doesnt have access to secure-only tag.
    SEC_JRNL_TAG_SECURE_ONLY,
} sec_jrnl_ret_status_t;

typedef uint16_t sec_jrnl_tag_len_t;

#if (defined(SECURE_MODE) || defined(CFG_NO_SPE))

/**
 * @brief Initialize walk context
 *
 * @note should be called prior to starting a walk via `sec_jrnl_walk_tag`
 */
sec_jrnl_ret_status_t sec_jrnl_walk_init_ctx(void);

/**
 * @brief Read tag data at given offset
 *
 * @param[in] buf_len lengh of input buffer
 * @param[out] buffer output buffer
 * @return sec_jrnl_ret_status_t SEC_JRNL_OK on success
 */
__NONNULL(2)
sec_jrnl_ret_status_t sec_jrnl_walk_read_curr_tag(uint32_t buf_len,
    uint8_t *buffer);

/**
 * @brief Walk a single tag in memory
 *
 * @param[out] tag tag found from walk
 * @param[out] tag_length length of tag data
 * @return sec_jrnl_ret_status_t SEC_JRNL_OK on success
 */
__NONNULL_ALL
sec_jrnl_ret_status_t sec_jrnl_walk_tag(uint8_t *tag,
    sec_jrnl_tag_len_t *tag_length);

/**
 * @brief Get secure journal tag
 *
 * @param[in] tag specified tag to return
 * @param[in,out] tag_length length of tag data
 * @param[out] tag_data output buffer of tag data
 * @return sec_jrnl_ret_status_t return status
 */
__NONNULL(2, 3)
sec_jrnl_ret_status_t sec_jrnl_get(uint8_t tag, uint16_t *tag_length,
    uint8_t *tag_data);

/**
 * @brief Get secure journal tag (write aligned 32bit)
 *
 * @param[in] tag specified tag to return
 * @param[in,out] tag_length length of tag data
 * @param[out] tag_data output buffer of tag data
 * @return sec_jrnl_ret_status_t return status
 */
__NONNULL(2, 3)
sec_jrnl_ret_status_t sec_jrnl_get_aligned_32(uint8_t tag,
    sec_jrnl_tag_len_t *tag_length, uint32_t *tag_data);
#endif

/**
 * @brief Initialize walk context  (NS-callable)
 *
 * @note should be called prior to starting a walk via `nsc_sec_jrnl_walk_tag`
 */
sec_jrnl_ret_status_t nsc_sec_jrnl_walk_init_ctx(void);

/**
 * @brief Read current tag in sec_jrnl_walk (NS-callable)
 *
 * @param[in] buf_len lengh of input buffer
 * @param[out] buffer output buffer
 * @return sec_jrnl_ret_status_t SEC_JRNL_OK on success
 */
__NONNULL(2)
sec_jrnl_ret_status_t nsc_sec_jrnl_walk_read_curr_tag(uint32_t buf_len,
    uint8_t *buffer);

/**
 * @brief Walk a single tag in memory (NS-callable)
 *
 * @note Internally, the walk will skip all secure-only tags.
 *
 * @param[out] tag tag found from walk
 * @param[out] tag_length length of tag data
 * @return sec_jrnl_ret_status_t SEC_JRNL_OK on success
 */
__NONNULL_ALL
sec_jrnl_ret_status_t nsc_sec_jrnl_walk_tag(uint8_t *tag,
    sec_jrnl_tag_len_t *tag_length);

/**
 * @brief Get secure journal tag (NS-callable)
 *
 * If return value is SEC_JRNL_TAG_SECURE_ONLY, then requested tag is a
 * secure-only tag. These tags cannot be read out by NSC functions
 *
 * @param[in] tag specified tag to return
 * @param[in,out] tag_length length of tag data
 * @param[out] tag_data output buffer of tag data
 * @return sec_jrnl_ret_status_t return status
 */
__NONNULL(2, 3)
sec_jrnl_ret_status_t nsc_sec_jrnl_get(uint8_t tag, uint16_t *tag_length,
    uint8_t *tag_data);

/**
 * @brief Get secure journal tag (write aligned 32bit) (NS-callable)
 *
 * If return value is SEC_JRNL_TAG_SECURE_ONLY, then requested tag is a
 * secure-only tag. These tags cannot be read out by NSC functions
 *
 * @param[in] tag specified tag to return
 * @param[in,out] tag_length length of tag data
 * @param[out] tag_data output buffer of tag data
 * @return sec_jrnl_ret_status_t return status
 */
__NONNULL(2, 3)
sec_jrnl_ret_status_t nsc_sec_jrnl_get_aligned_32(uint8_t tag,
    sec_jrnl_tag_len_t *tag_length, uint32_t *tag_data);

#ifdef __cplusplus
}
#endif

/// @}
