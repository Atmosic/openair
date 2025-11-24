/**
 *******************************************************************************
 *
 * @file platform_commom.h
 *
 * @brief Platform common For Multimode Consumer Tag
 *
 * Copyright (C) Atmosic 2025
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

/// Tag Mode Indexes
typedef enum {
	/// Index of Tag initial done
	TAG_STATE_INIT_DONE = 0x00,
	/// Index of Tag unpaired
	TAG_STATE_UNPAIRED,
	/// Index of Tag in pairing
	TAG_STATE_PAIRING,
	/// Index of Tag paired
	TAG_STATE_PAIRED,
	/// Index of Tag invalid
	TAG_STATE_INVALID = 0xFF,
} tag_state_t;

/// tag state notify
typedef void (*tag_state_notify_cb)(tag_state_t st, uint8_t type);

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
