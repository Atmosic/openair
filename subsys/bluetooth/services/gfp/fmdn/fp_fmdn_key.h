/**
 *******************************************************************************
 *
 * @file fp_fmdn_key.h
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) extention
 * Key Process Middleware
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#pragma once

#include "compiler.h" // __NONNULL_ALL inline functions
#include "fp_common.h"
#include "fp_fmdn_internal.h"

/**
 * @addtogroup ATM_BTFMDN Google Fast Pair Find My Device Network Extention
 * @brief Key Process Middleware of Google Fast Pair Find My Device Network
 * Extention
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/// FMDN Battery Level
typedef enum {
	/// Index of battery level not support
	FP_FMDN_BATTERY_LEVEL_NOT_SUPPORT = 0x00,
	/// Index of battery level normal
	FP_FMDN_BATTERY_LEVEL_NORMAL = 0x01,
	/// Index of battery level low
	FP_FMDN_BATTERY_LEVEL_LOW = 0x02,
	/// Index of battery level critical
	FP_FMDN_BATTERY_LEVEL_CRITICAL = 0x03,
	/// Index of battery level none
	FP_FMDN_BATTERY_LEVEL_NONE = 0xFF,
} fp_fmdn_battery_level_t;

/**
 * @brief FP FMDN key clock initialization
 *
 * Initializes the FMDN clock by restoring the value from NVM if available.
 * This should be called once during system initialization.
 */
void fp_fmdn_key_clock_init(void);

/**
 * @brief FP FMDN key clock read
 *
 * @return clock value in seconds
 */
uint32_t fp_fmdn_key_clock_read(void);

/**
 * @brief FP FMDN key clock save
 *
 * Saves the current FMDN clock value to NVM for power-loss recovery.
 * According to FMDN spec, this should be called at least once per day.
 * This is called automatically by the periodic save worker.
 *
 * @return 0 if successful. Otherwise, a (negative) error code is returned
 */
int fp_fmdn_key_clock_save(void);

/**
 * @brief Start periodic FMDN clock saving
 *
 * Starts a periodic work queue that saves the FMDN clock value to NVM
 * every 24 hours as recommended by the FMDN specification.
 */
void fp_fmdn_key_clock_periodic_save_start(void);

/**
 * @brief Stop periodic FMDN clock saving
 *
 * Stops the periodic work queue for FMDN clock saving.
 */
void fp_fmdn_key_clock_periodic_save_stop(void);

/**
 * @brief Schedule immediate FMDN clock save
 *
 * Schedules the clock save work item for immediate execution via work queue.
 * This avoids race conditions with the periodic save handler.
 */
void fp_fmdn_key_clock_save_immediate(void);

/**
 * @brief Set FMDN clock to a specific value at startup
 *
 * Pre-initializes the in-memory FMDN clock state to the given value so that
 * the provided value is already in effect when fp_fmdn_key_clock_init() runs.
 * Must be called before fp_fmdn_key_clock_init() to take effect.
 *
 * @param[in] clock_value FMDN clock value in seconds to apply
 */
void fp_fmdn_key_clock_set(uint32_t clock_value);

/**
 * @brief Reset FMDN clock value to 0
 *
 * Resets the FMDN clock value to 0 and deletes it from NVM.
 * This should be called during factory reset so new provisioning
 * can start with clock value of 0.
 */
void fp_fmdn_key_clock_reset(void);

/**
 * @brief FP FMDN bcna key generate
 * @param[in] eid_key eid_key
 * @param[in] key_type key_type
 * @param[out] auth_key to be generated auth_key
 * @param[in] auth_key_len expected length of auth_key
 *
 * @return true if generated succeed
 */
__NONNULL_ALL
bool fp_fmdn_key_generate(uint8_t const *eid_key, fp_fmdn_auth_key_type_t key_type,
			  uint8_t *auth_key, size_t auth_key_len);

/**
 * @brief FP FMDN bcna key eid generate auth data
 * @param[in] conn_context bcna conn_context structure pointer
 * @param[in] eid_key eid_key
 * @param[out] auth_data to be generated auth_data
 */
__NONNULL_ALL
void fp_fmdn_key_eik_auth_data(bcna_conn_ctx_t *conn_context, uint8_t *eid_key, uint8_t *auth_data);

/**
 * @brief FP FMDN bcna generate eid with eid_key
 * @param[in] fmdn_eid_key eid_key
 * @param[in] force force re-gen eid with current eid key
 */
__NONNULL_ALL
void fp_fmdn_key_gen_eid(uint8_t const *fmdn_eid_key, bool force);

/**
 * @brief FP FMDN bcna get generated eid
 * @param[out] generated eid
 *
 * @return length of eid
 */
__NONNULL_ALL
uint8_t fp_fmdn_key_get_eid(uint8_t *eid);

/**
 * @brief FP FMDN bcna get generated eid hashed flag
 *
 * @return generated eid hashed flag
 */
uint8_t fp_fmdn_key_get_eid_hashed_flags(void);

#ifdef CONFIG_FAST_PAIR_FMDN_DULT
/**
 * @brief FP FMDN bcna key generate dult id
 * @param[in] eid_key eid_key
 * @param[out] fmdn_dult_id to be generated dult id
 */
__NONNULL_ALL
void fp_fmdn_key_gen_dult_id(uint8_t const *eid_key, uint8_t *fmdn_dult_id);
#endif

/**
 * @brief FP FMDN bcna key clear eid
 */
void fp_fmdn_key_clear_eid(void);

/**
 * @brief FP FMDN bcna key update eid
 */
void fp_fmdn_key_update_eid(void);

/**
 * @brief Check if the EID needs to rotate.
 *
 * Returns true if the FMDN clock has advanced past the last EID rotation
 * window boundary, meaning a new EID must be computed.
 *
 * @return true if EID rotation is due, false otherwise.
 */
bool fp_fmdn_key_eid_needs_rotate(void);

/**
 * @brief Return seconds remaining until the next EID rotation window.
 *
 * @return Seconds until the next 2^K clock boundary (1 – 1024).
 */
uint32_t fp_fmdn_key_secs_until_eid_rotate(void);

/**
 * @brief The callback function of battery status
 * @param[in] mode fast pairing itp mode
 */
typedef uint8_t (*fp_fmdn_battery_cb)(void);

/**
 * @brief fmdn battery status handler register
 * @param[in] hdlr battery status handler structure
 */
__NONNULL_ALL
void fp_fmdn_key_battery_reg(fp_fmdn_battery_cb const hdlr);

#ifdef __cplusplus
}
#endif

///@}
