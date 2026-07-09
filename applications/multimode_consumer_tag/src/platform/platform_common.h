/**
 *******************************************************************************
 *
 * @file platform_commom.h
 *
 * @brief Platform common For Multimode Consumer Tag
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif
#include <zephyr/sys/util.h>

/* Unified macro to check STF multi-mode build */
#if IS_ENABLED(CONFIG_STF_TAG) && IS_ENABLED(CONFIG_ATM_STF_MULTI_MODE)
#define APP_STF_MULTI_MODE 1
#else
#define APP_STF_MULTI_MODE 0
#endif

/// Tag Type Indexes
typedef enum {
	TAG_TYPE_FMNA = 0,
	TAG_TYPE_FP,
	TAG_TYPE_STF,
	TAG_TYPE_MAX,
} tag_type_t;

/**
 * @brief Convert tag type to mode bitmask
 * @param[in] type tag type (tag_type_t)
 * @return bitmask with the corresponding bit set
 */
static inline uint8_t platform_tag_type_to_mode(uint8_t type)
{
	return (uint8_t)(1U << type);
}

/// Tag Mode Indexes
typedef enum {
	/// Index of Tag initial done
	TAG_EVENT_INIT_DONE = 0x00,
	/// Index of Tag unpaired
	TAG_EVENT_UNPAIRED,
	/// Index of Tag in pairing
	TAG_EVENT_PAIRING,
	/// Index of Tag paired
	TAG_EVENT_PAIRED,
	/// Index of Tag invalid
	TAG_EVENT_INVALID = 0xFF,
} tag_event_t;

/// tag state notify
typedef void (*tag_state_notify_cb)(tag_event_t st, uint8_t type);

/// tag handlers
typedef struct tag_hdlrs_s {
	/// init function
	void (*init)(tag_state_notify_cb fn_cb);
	/// reset function
	void (*reset)(void);
	/// start function
	void (*start)(void);
	/// stop function
	void (*stop)(void);
	/// is paired function
	bool (*is_paired)(void);
} tag_hdlrs_t;

#ifdef __cplusplus
}
#endif

///@}
