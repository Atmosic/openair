/**
 ******************************************************************************
 *
 * @file sec_jrnl.h
 *
 * @brief Secure Journal driver
 *
 * Copyright (C) Atmosic 2025-2026
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

#include "arch.h"

#ifdef CONFIG_ATM_SEC_JRNL_MOCK_DATA_MUTABLE
#define ATM_MOCK_JRNL_CONST
#else
#define ATM_MOCK_JRNL_CONST const
#endif

typedef enum {
	OTP_JRNL,
	FLASH_JRNL,
#ifdef CONFIG_ATM_SEC_JRNL_RAM
	RAM_JRNL,
#endif
} sec_jrnl_space_id_t;


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

#ifdef CONFIG_ATM_SECURE_JOURNAL_TEST
extern uint8_t ATM_MOCK_JRNL_CONST sec_jrnl_nvds[];
#endif

#if (defined(SECURE_MODE) || defined(CFG_NO_SPE))

/**
 * @brief Initialize walk context
 *
 * @note should be called prior to starting a walk via `sec_jrnl_walk_tag`
 */
sec_jrnl_ret_status_t sec_jrnl_walk_init_ctx(void);

/**
 * @brief Initialize walk context with specific source
 *
 * @param[in] source_id select OTP_JRNL, FLASH_JRNL, or RAM_JRNL
 * @return sec_jrnl_ret_status_t SEC_JRNL_OK on success
 */
sec_jrnl_ret_status_t sec_jrnl_walk_init_ctx_source(sec_jrnl_space_id_t source_id);

/**
 * @brief Read tag data at given offset
 *
 * @param[in] buf_len length of input buffer
 * @param[out] buffer output buffer
 * @return sec_jrnl_ret_status_t SEC_JRNL_OK on success
 */
__NONNULL(2)
sec_jrnl_ret_status_t sec_jrnl_walk_read_curr_tag(uint32_t buf_len, uint8_t *buffer);

/**
 * @brief Walk a single tag in memory
 *
 * @param[out] tag tag found from walk
 * @param[out] tag_length length of tag data
 * @return sec_jrnl_ret_status_t SEC_JRNL_OK on success
 */
__NONNULL_ALL
sec_jrnl_ret_status_t sec_jrnl_walk_tag(uint8_t *tag, sec_jrnl_tag_len_t *tag_length);

/**
 * @brief Get secure journal tag
 *
 * @param[in] tag specified tag to return
 * @param[in,out] tag_length length of tag data
 * @param[out] tag_data output buffer of tag data
 * @return sec_jrnl_ret_status_t return status
 */
__NONNULL(2, 3)
sec_jrnl_ret_status_t sec_jrnl_get(uint8_t tag, uint16_t *tag_length, uint8_t *tag_data);

/**
 * @brief Get secure journal tag (write aligned 32bit)
 *
 * @param[in] tag specified tag to return
 * @param[in,out] tag_length length of tag data
 * @param[out] tag_data output buffer of tag data
 * @return sec_jrnl_ret_status_t return status
 */
__NONNULL(2, 3)
sec_jrnl_ret_status_t sec_jrnl_get_aligned_32(uint8_t tag, sec_jrnl_tag_len_t *tag_length,
					      uint32_t *tag_data);

/**
 * @brief Reset the cached tag lookup table
 *
 * Forces subsequent sec_jrnl_get() calls to re-scan the journal from the
 * start.  Must be called after the backing store changes underneath the
 * driver (e.g. after programming new OTP entries) so that stale cached
 * offsets are not returned.
 */
void sec_jrnl_reset_tag_cache(void);

#ifdef CONFIG_ATM_SEC_JRNL_RAM
/**
 * @brief Initialize RAM journal with pre-populated data
 *
 * Validates the magic bytes ('NVDS') and stores a pointer to @p data
 * (no copy is made; the caller must keep the buffer alive).
 *
 * @param[in] data pointer to RAM journal data (NVDS formatted); must not be NULL
 * @param[in] len  number of bytes pointed to by @p data; must be > 0
 * @return SEC_JRNL_OK on success, SEC_JRNL_BAD_MAGIC if @p data is NULL/0 or magic is wrong
 */
sec_jrnl_ret_status_t sec_jrnl_ram_init(uint8_t const *data, uint16_t len);
#endif

#endif /* SECURE_MODE || CFG_NO_SPE */

/**
 * @brief Initialize walk context (NS-callable)
 *
 * @note should be called prior to starting a walk via `nsc_sec_jrnl_walk_tag`
 */
sec_jrnl_ret_status_t nsc_sec_jrnl_walk_init_ctx(void);

/**
 * @brief Initialize walk context with specific source (NS-callable)
 *
 * @param[in] source_id select OTP_JRNL, FLASH_JRNL, or RAM_JRNL
 * @return sec_jrnl_ret_status_t SEC_JRNL_OK on success
 */
sec_jrnl_ret_status_t nsc_sec_jrnl_walk_init_ctx_source(sec_jrnl_space_id_t source_id);

/**
 * @brief Read current tag in sec_jrnl_walk (NS-callable)
 *
 * @param[in] buf_len length of input buffer
 * @param[out] buffer output buffer
 * @return sec_jrnl_ret_status_t SEC_JRNL_OK on success
 */
__NONNULL(2)
sec_jrnl_ret_status_t nsc_sec_jrnl_walk_read_curr_tag(uint32_t buf_len, uint8_t *buffer);

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
sec_jrnl_ret_status_t nsc_sec_jrnl_walk_tag(uint8_t *tag, sec_jrnl_tag_len_t *tag_length);

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
sec_jrnl_ret_status_t nsc_sec_jrnl_get(uint8_t tag, uint16_t *tag_length, uint8_t *tag_data);

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
sec_jrnl_ret_status_t nsc_sec_jrnl_get_aligned_32(uint8_t tag, sec_jrnl_tag_len_t *tag_length,
						  uint32_t *tag_data);

/**
 * @brief Reset the cached tag lookup table (NS-callable)
 *
 * See sec_jrnl_reset_tag_cache().
 */
void nsc_sec_jrnl_reset_tag_cache(void);

#ifdef CONFIG_ATM_SEC_JRNL_RAM
/**
 * @brief Initialize RAM journal (NS-callable)
 *
 * Same semantics as sec_jrnl_ram_init(). Only available on non-TrustZone
 * platforms; on those platforms this is a direct alias of sec_jrnl_ram_init().
 *
 * @param[in] data pointer to RAM journal data (NVDS formatted), or NULL for empty
 * @param[in] len  number of bytes pointed to by @p data
 * @return SEC_JRNL_OK on success, SEC_JRNL_BAD_MAGIC on error
 */
sec_jrnl_ret_status_t nsc_sec_jrnl_ram_init(uint8_t const *data, uint16_t len);
#endif /* CONFIG_ATM_SEC_JRNL_RAM */

#ifdef __cplusplus
}
#endif

/// @}
