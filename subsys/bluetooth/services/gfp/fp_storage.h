/**
 *******************************************************************************
 *
 * @file fp_storage.h
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Storage Middleware
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#pragma once

#include "compiler.h"
#include "fp_common.h"

/**
 * @addtogroup ATM_BTFMDN Google Fast Pair Service
 * @brief Storage Middleware of Fast Pair Service
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief fp save account key and ownerkey
 * @param[in] account_key account key
 *
 * @return 0 if successful. Otherwise, a (negative) error code is returned
 */
__NONNULL_ALL
int fp_storage_account_key_save(uint8_t const *account_key);

/**
 * @brief fp delete saved account key
 * @param[in] account_key account key
 *
 * @return 0 if successful. Otherwise, a (negative) error code is returned
 */
__NONNULL_ALL
int fp_storage_account_key_delete(uint8_t const *account_key);

/**
 * @brief fp delete all saved account key
 *
 * @return 0 if successful. Otherwise, a (negative) error code is returned
 */
int fp_storage_account_key_delete_all(void);

#ifdef CONFIG_FAST_PAIR_FMDN
/**
 * @brief fp save eid key
 * @param[in] eik eid key
 *
 * @return 0 if successful. Otherwise, a (negative) error code is returned
 */
__NONNULL_ALL
int fp_storage_eid_key_save(uint8_t const *eik);

/**
 * @brief fp delete saved eid key
 *
 * @return 0 if successful. Otherwise, a (negative) error code is returned
 */
int fp_storage_eid_key_delete(void);

/**
 * @brief fp get saved eid key
 * @param[out] key eid key
 *
 * @return 0 if successful. Otherwise, a (negative) error code is returned
 */
__NONNULL_ALL
int fp_storage_eid_key_get(uint8_t *key);

/**
 * @brief fp is eid key saved
 *
 * @return true if eid key saved
 */
bool fp_storage_eid_key_valid(void);

/**
 * @brief fp save utp_mode
 * @param[in] mode utp_mode
 */
void fp_storage_utp_mode_save(fp_fmdn_utp_mode_t mode);

/**
 * @brief fp get saved utp_mode
 *
 * @return saved utp_mode
 */
uint8_t fp_storage_utp_mode_get(void);

/**
 * @brief fp save utp_ignore_ring_auth flag
 * @param[in] ignore_auth flag value (0 or 1)
 */
void fp_storage_utp_ignore_ring_auth_save(uint8_t ignore_auth);

/**
 * @brief fp get saved utp_ignore_ring_auth flag
 *
 * @return saved utp_ignore_ring_auth flag
 */
uint8_t fp_storage_utp_ignore_ring_auth_get(void);

/**
 * @brief fp save fmdn clock value
 * @param[in] clock_value FMDN clock value in seconds
 *
 * @return 0 if successful. Otherwise, a (negative) error code is returned
 */
int fp_storage_fmdn_clock_save(uint32_t clock_value);

/**
 * @brief fp get saved fmdn clock value
 * @param[out] clock_value FMDN clock value in seconds
 *
 * @return 0 if successful. Otherwise, a (negative) error code is returned
 */
__NONNULL_ALL
int fp_storage_fmdn_clock_get(uint32_t *clock_value);

/**
 * @brief fp reset fmdn clock value to 0
 *
 * Resets the FMDN clock value to 0 and deletes it from NVM.
 * This should be called during factory reset so new provisioning
 * can start with clock value of 0.
 */
void fp_storage_fmdn_clock_reset(void);

#ifdef CONFIG_FMDN_PERSISTENT_CONNECTION
/**
 * @brief Save persistent connection client ID to NVS
 * @param[in] client_id Client ID from the Seeker that set force bit
 *
 * This is used to enforce ownership of persistent connection across power cycles.
 * Only the Seeker with this client ID (or a new Seeker with force bit) can
 * configure persistent connection after restart.
 */
void fp_storage_pc_client_id_save(uint8_t client_id);

/**
 * @brief Get saved persistent connection client ID
 * @param[out] client_id Pointer to store the client ID
 *
 * @return 0 if successful, -ENOENT if no client ID is saved
 */
__NONNULL_ALL
int fp_storage_pc_client_id_get(uint8_t *client_id);

/**
 * @brief Check if persistent connection client ID is saved
 *
 * @return true if client ID is saved in NVS
 */
bool fp_storage_pc_client_id_valid(void);

/**
 * @brief Delete saved persistent connection client ID
 *
 * This should be called when persistent connection is explicitly disabled
 * or when the connection is terminated to clear ownership.
 */
void fp_storage_pc_client_id_delete(void);
#endif // CONFIG_FMDN_PERSISTENT_CONNECTION

/**
 * @brief Save personalized name received via Fast Pair Additional Data
 * @param[in] name Personalized name string (null-terminated)
 *
 * @return 0 if successful. Otherwise, a (negative) error code is returned
 */
__NONNULL_ALL
int fp_storage_personalized_name_save(const char *name);

/**
 * @brief Delete saved personalized name
 *
 * @return 0 if successful. Otherwise, a (negative) error code is returned
 */
int fp_storage_personalized_name_delete(void);

/**
 * @brief Get saved personalized name
 * @param[out] name Buffer to store the personalized name
 * @param[in] name_size Size of the name buffer
 *
 * @return 0 if successful. Otherwise, a (negative) error code is returned
 */
__NONNULL_ALL
int fp_storage_personalized_name_get(char *name, size_t name_size);

/**
 * @brief Check if personalized name is saved
 *
 * @return true if personalized name is saved
 */
bool fp_storage_personalized_name_valid(void);

/**
 * @brief Get the effective device name (personalized name if available, otherwise default)
 *
 * @return Pointer to the effective device name string
 */
const char *fp_storage_get_effective_name(void);

/**
 * @brief fp clear current account key
 */
void fp_storage_cur_account_key_clear(void);

/**
 * @brief fp get current account key
 * @param[out] key current account key
 *
 * @return 0 if successful. Otherwise, a (negative) error code is returned
 */
__NONNULL_ALL
int fp_storage_cur_account_key_get(uint8_t *key);

/**
 * @brief fp check if key is owner_key
 * @param[in] key owner key
 *
 * @return true if key is owner key
 */
bool fp_storage_check_is_owner_key(uint8_t const *key);

/**
 * @brief fp clear saved owner key
 */
void fp_storage_owner_key_clear(void);

/**
 * @brief fp get saved owner key
 * @param[out] key owner key
 *
 * @return 0 if successful. Otherwise, a (negative) error code is returned
 */
__NONNULL_ALL
int fp_storage_owner_key_get(uint8_t *key);

/**
 * @brief fp is owner key saved
 *
 * @return true if owner key saved
 */
bool fp_storage_owner_key_valid(void);

#endif // CONFIG_FAST_PAIR_FMDN

/**
 * @brief fp get saved account key count
 *
 * @return saved account key count
 */
size_t fp_storage_account_key_count_get(void);

/**
 * @brief fp calculate account key filter size
 * @param[in] count account key count
 *
 * @return account key filter size
 */
size_t fp_storage_account_key_filter_size(size_t count);

/**
 * @brief fp get saved account key list
 * @param[out] key_list saved account key list
 *
 * @return 0 if successful. Otherwise, a (negative) error code is returned
 */
__NONNULL_ALL
uint8_t fp_storage_account_key_list_get(uint8_t *key_list);

#ifdef CONFIG_FAST_PAIR_FMDN
/**
 * @brief fp storage eid reset
 */
void fp_storage_eid_reset(void);
#endif

/**
 * @brief fp account key reset
 */
void fp_storge_account_key_reset(void);

/**
 * @brief fp storage reset
 *
 * @return 0 if successful. Otherwise, a (negative) error code is returned
 */
int fp_storage_reset(void);

/**
 * @brief fp storage init
 *
 * @return 0 if successful. Otherwise, a (negative) error code is returned
 */
int fp_storage_init(void);

/**
 * @brief fp storage bt id base save
 * @param[in] id bt id base
 */
void fp_storage_bt_id_base_save(uint8_t id);

/**
 * @brief fp storage bt id base get
 *
 * @return bt id base
 */
uint8_t fp_storage_bt_id_base_get(void);

/**
 * @brief fp storage bt id base valid
 *
 * @return true if bt id base valid
 */
bool fp_storage_bt_id_base_valid(void);

#ifdef __cplusplus
}
#endif

///@}
