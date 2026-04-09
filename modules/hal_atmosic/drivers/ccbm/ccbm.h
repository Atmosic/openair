/**
 *******************************************************************************
 *
 * @file ccbm.h
 *
 * @brief Coin Cell Battery Management (CCBM) API
 *
 * This module provides functionality to enable high current generation
 * for coin cell battery management. The operation coordinates with the radio
 * manager to avoid conflicts with other radio operations.
 *
 * @note This driver only works with non-rechargeable coin cell batteries
 *       (BATT_TYPE_NON_RECHARGEABLE). A compile-time assertion will fail
 *       if used with other battery types.
 *
 * Copyright (C) Atmosic 2026
 *
 *******************************************************************************
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup CCBM Coin Cell Battery Management
 * @ingroup DRIVERS
 * @brief Coin Cell Battery Management Driver
 * @{
 */

/**
 * @brief CCBM operation result codes
 */
typedef enum {
    CCBM_STATUS_SUCCESS = 0, /**< Operation completed successfully */
    CCBM_STATUS_ERROR = -1, /**< General error */
    CCBM_STATUS_BUSY = -2, /**< Driver is busy with another operation */
    CCBM_STATUS_INVALID = -3, /**< Invalid parameter */
    CCBM_STATUS_ADC_ERROR = -4, /**< ADC measurement failed */
    CCBM_STATUS_ABORTED = -5, /**< Measurement aborted by check callback */
} ccbm_status_t;

/**
 * @brief CCBM measurement result structure
 *
 * Contains impedance measurement and voltage measurements under no-load and
 * with-load conditions.
 */
typedef struct {
    uint32_t impedance; /**< Battery impedance in mOhm */
    int32_t vbatt_no_load_mv; /**< Battery voltage without load (mV) */
    int32_t vbatt_with_load_mv; /**< Battery voltage with load (mV) */
} ccbm_result_t;

/**
 * @brief Callback function type for CCBM operation completion
 *
 * This callback is invoked when a CCBM operation completes.
 *
 * @param[in] status Result of the CCBM operation
 * @param[in] result Pointer to measurement results (valid only if status is
 * SUCCESS)
 * @param[in] user_data User-provided context pointer passed to ccbm_enable()
 */
typedef void (*ccbm_callback_t)(ccbm_status_t status,
    const ccbm_result_t *result, void *user_data);

/**
 * @brief Authorization callback function type for CCBM measurement
 *
 * This callback is invoked after exclusive radio access has been acquired but
 * before any hardware measurements begin. The application can inspect its
 * internal state (e.g. ongoing ringing, ranging, or other operations) and
 * authorize or deny the measurement.
 *
 * @param[in] user_data User-provided context pointer passed to
 * ccbm_measure_impedance()
 * @return true  to allow the measurement to proceed
 * @return false to abort the measurement (done_cb will NOT be invoked)
 */
typedef bool (*ccbm_check_callback_t)(void *user_data);

/**
 * @brief Initiate battery impedance measurement
 *
 * This function starts an impedance measurement operation and returns
 * immediately. The provided callback will be invoked when the operation
 * completes, providing battery voltage measurements under no-load and
 * with-load conditions.
 *
 * The operation performs the following:
 * 1. Acquire exclusive radio access
 * 2. Invoke check_cb (if provided) to authorize the measurement
 * 3. Abort without invoking done_cb if check_cb returns false
 * 4. Measure battery voltage (no-load condition)
 * 5. Enable constant load
 * 6. Wait for settling delay (duration_ms, 0 is valid for immediate
 * measurement)
 * 7. Measure battery voltage (with-load condition)
 * 8. Disable constant load
 * 9. Release radio access
 * 10. Invoke done_cb with both voltage measurements
 *
 * @note Only one operation can be in progress at a time.
 * @note The callbacks are invoked from thread context, not interrupt context.
 * @note done_cb is mandatory and must not be NULL.
 * @note check_cb is optional; pass NULL to always allow the measurement.
 *
 * @param[in] duration_ms Settling delay after enabling load before ADC
 * measurement (0 is valid for immediate measurement)
 * @param[in] check_cb Optional authorization callback invoked after radio idle
 * is acquired but before measurements begin. Return true to proceed, false to
 * abort. Pass NULL to always proceed.
 * @param[in] done_cb Function to call when operation completes (must not be
 * NULL)
 * @param[in] user_data User-provided context pointer passed to both callbacks
 * @return 0 if operation started successfully, negative error code on failure
 */
int ccbm_measure_impedance(uint32_t duration_ms, ccbm_check_callback_t check_cb,
    ccbm_callback_t done_cb, void *user_data);

/**
 * @brief Initialize the CCBM driver
 *
 * This function registers the driver with the radio manager.
 * It is called automatically during system initialization when
 * CONFIG_ATM_CCBM_AUTO_INIT is enabled.
 *
 * @return 0 on success, negative error code on failure
 */
int ccbm_init(void);

/** @} end of CCBM */

#ifdef __cplusplus
}
#endif
