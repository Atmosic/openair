/**
 *******************************************************************************
 *
 * @file dult_common.h
 *
 * @brief Detecting Unwanted Location Trackers Service Common Definitions
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup ATM_BTDULTS Detecting Unwanted Location Trackers Service
 * @brief Common Definitions of Detecting Unwanted Location Trackers Service
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/// Google Fast Pair Mode Indexes
typedef enum {
	/// Index of DULT Seperated mode
	DULT_NO_MODE_SEPERATED,
	/// Index of DULT Near Owner mode
	DULT_NO_MODE_NEAR_OWNER,
} dult_mode_t;

#ifdef __cplusplus
}
#endif

/**
 * @}
 */
