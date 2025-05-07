/**
 *******************************************************************************
 *
 * @file fp_fmdn_key.h
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) extention
 * Key Process Middleware
 *
 * Copyright (C) Atmosic 2025
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

#define FMDN_MEMCPY_SHIFT(dst, src, size, offset)                                                  \
	do {                                                                                       \
		memcpy((dst) + (offset), src, size);                                               \
		offset += size;                                                                    \
	} while (0)

/// FMDN Battery Level
typedef enum {
	/// Index of battery level not support
	FP_FMDN_BATTERY_LEVEL_NOT_SUPPORT = 0x00,
	/// Index of battery level normal
	FP_FMDN_BATTERY_LEVEL_NORMAL = 0x01,
	/// Index of battery level low
	FP_FMDN_BATTERY_LEVEL_LOW = 0x10,
	/// Index of battery level critical
	FP_FMDN_BATTERY_LEVEL_CRITICAL = 0x11,
	/// Index of battery level none
	FP_FMDN_BATTERY_LEVEL_NONE = 0xFF,
} fp_fmdn_battery_level_t;

/**
 * @brief FP FMDN key clock read
 *
 * @return clock
 */
uint32_t fp_fmdn_key_clock_read(void);

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
			  fp_fmdn_auth_key_type_t *auth_key, size_t auth_key_len);

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
 * @brief The callback function of battery status
 * @param[in] mode fast paring itp mode
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
