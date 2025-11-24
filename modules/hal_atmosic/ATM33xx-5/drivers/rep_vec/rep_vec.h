/**
 *******************************************************************************
 *
 * @file rep_vec.h
 *
 * @brief Replacement vectors for strategic code paths
 *
 * Copyright (C) Atmosic 2017-2022
 *
 *******************************************************************************
 */

#pragma once

#define REP_VEC

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/// Generic add helper macro
#define RV_ADD(__t, __v, __f) do { \
    static rep_vec ## __t ## t user_ ## __v = { __f, NULL }; \
    rep_vec ## __t ## add(&__v, &user_ ## __v); \
} while(0)

/// Generic add_last helper macro
#define RV_ADD_LAST(__t, __v, __f) do { \
    static rep_vec ## __t ## t user_ ## __v = { __f, NULL }; \
    rep_vec ## __t ## add_last(&__v, &user_ ## __v); \
} while(0)

typedef enum rep_vec_err_e {
    RV_DONE = 0,
    RV_NEXT
} rep_vec_err_t;


/* void fn(void) */
typedef rep_vec_err_t (*rep_vec_fn_t)(void);

typedef struct rep_vec_s {
    rep_vec_fn_t fn;
    struct rep_vec_s *next;
} rep_vec_t;

void rep_vec_add(rep_vec_t **head, rep_vec_t *new_entry);
void rep_vec_add_last(rep_vec_t **head, rep_vec_t *new_entry);
void rep_vec_invoke(rep_vec_t *rv, void (*def_fn)(void));

/**
 * @brief After all active events have been processed by the main event loop,
 * this vector is invoked before interrupts are disabled and power saving
 * modes are handled.
 */
extern rep_vec_t *rv_plf_schedule;
#define RV_PLF_SCHEDULE_ADD(__f) RV_ADD(_, rv_plf_schedule, __f)
#define RV_PLF_SCHEDULE_ADD_LAST(__f) RV_ADD_LAST(_, rv_plf_schedule, __f)

/**
 * @brief When a system reset is requested, this vector will be invoked after
 * interrupts are globally disabled but before asserting the hardware reset.
 * It is the absolute last opportunity for drivers to take action before
 * all system state is lost.
 */
extern rep_vec_t *rv_plf_reset;
#define RV_PLF_RESET_ADD(__f) RV_ADD(_, rv_plf_reset, __f)
#define RV_PLF_RESET_ADD_LAST(__f) RV_ADD_LAST(_, rv_plf_reset, __f)

/**
 * @brief At the end of BLE device initialization, this vector will be invoked
 * to initialize the BLE application layer.  It provides the final opportunity
 * for customization before the main event loop is entered.
 */
extern rep_vec_t *rv_appm_init;
#define RV_APPM_INIT_ADD(__f) RV_ADD(_, rv_appm_init, __f)
#define RV_APPM_INIT_ADD_LAST(__f) RV_ADD_LAST(_, rv_appm_init, __f)

/**
 * @brief Invoked after the BLE sleep duration has been computed but before
 * BLE sleep has been requested.
 */
extern rep_vec_t *rv_rf_sleep;
#define RV_RF_SLEEP_ADD(__f) RV_ADD(_, rv_rf_sleep, __f)
#define RV_RF_SLEEP_ADD_LAST(__f) RV_ADD_LAST(_, rv_rf_sleep, __f)

/**
 * @brief Invoked at interrupt level near the end of IP_SLPINTSTAT handler.
 */
extern rep_vec_t *rv_rf_wake;
#define RV_RF_WAKE_ADD(__f) RV_ADD(_, rv_rf_wake, __f)
#define RV_RF_WAKE_ADD_LAST(__f) RV_ADD_LAST(_, rv_rf_wake, __f)

/**
 * @brief This vector permits customization of the power saving logic.
 * See driver/pseq for more information.
 */
extern rep_vec_t *rv_plf_back_from_retain_all;
#define RV_PLF_BACK_FROM_RETAIN_ALL_ADD(__f) \
    RV_ADD(_, rv_plf_back_from_retain_all, __f)
#define RV_PLF_BACK_FROM_RETAIN_ALL_ADD_LAST(__f) \
    RV_ADD_LAST(_, rv_plf_back_from_retain_all, __f)

/**
 * @brief Invoked after rwip reset is complete
 */
extern rep_vec_t *rv_notify_rwip_reset_cmpl;
#define RV_NOTIFY_RWIP_RESET_CMPL_ADD(__f) \
    RV_ADD(_, rv_notify_rwip_reset_cmpl, __f)
#define RV_NOTIFY_RWIP_RESET_CMPL_ADD_LAST(__f) \
    RV_ADD_LAST(_, rv_notify_rwip_reset_cmpl, __f)


/* const struct prf_task_cbs *fn(uint8_t) */
struct prf_task_cbs;

typedef rep_vec_err_t (*rep_vec_fn__ret_const_struct_prf_task_cbs_p__uint8_t__t)(const struct prf_task_cbs **, uint8_t);

typedef struct rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__s {
    rep_vec_fn__ret_const_struct_prf_task_cbs_p__uint8_t__t fn;
    struct rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__s *next;
} rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__t;

void
rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__add(
    rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__t **head,
    rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__t *new_entry);
void
rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__add_last(
    rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__t **head,
    rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__t *new_entry);
const struct prf_task_cbs *
rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__invoke(
    rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__t *rv,
    const struct prf_task_cbs *(*def_fn)(uint8_t),
    uint8_t prf_id);

/**
 * @brief Along with rv_prf_id_get, this vector supports the addition and
 * replacement of BLE profiles.  See the HCI example for more information.
 * @param[in] prf_id Profile ID
 * @return Pointer to profile task callbacks
 */
extern rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__t *rv_prf_itf_get;
#define RV_PRF_ITF_GET_ADD(__f) \
    RV_ADD(__ret_const_struct_prf_task_cbs_p__uint8_t__, rv_prf_itf_get, __f)
#define RV_PRF_ITF_GET_ADD_LAST(__f) \
    RV_ADD_LAST(__ret_const_struct_prf_task_cbs_p__uint8_t__, rv_prf_itf_get, __f)


/* uint8_t fn(uint8_t) */
typedef rep_vec_err_t (*rep_vec_fn__ret_uint8_t__uint8_t__t)(uint8_t *, uint8_t);

typedef struct rep_vec__ret_uint8_t__uint8_t__s {
    rep_vec_fn__ret_uint8_t__uint8_t__t fn;
    struct rep_vec__ret_uint8_t__uint8_t__s *next;
} rep_vec__ret_uint8_t__uint8_t__t;

void
rep_vec__ret_uint8_t__uint8_t__add(
    rep_vec__ret_uint8_t__uint8_t__t **head,
    rep_vec__ret_uint8_t__uint8_t__t *new_entry);
void
rep_vec__ret_uint8_t__uint8_t__add_last(
    rep_vec__ret_uint8_t__uint8_t__t **head,
    rep_vec__ret_uint8_t__uint8_t__t *new_entry);
uint8_t
rep_vec__ret_uint8_t__uint8_t__invoke(
    rep_vec__ret_uint8_t__uint8_t__t *rv,
    uint8_t (*def_fn)(uint8_t),
    uint8_t api_id);

/**
 * @brief Along with rv_prf_itf_get, this vector supports the addition and
 * replacement of BLE profiles.  See the HCI example for more information.
 * @param[in] api_id API ID
 * @return Profile ID
 */
extern rep_vec__ret_uint8_t__uint8_t__t *rv_prf_id_get;
#define RV_PRF_ID_GET_ADD(__f) \
    RV_ADD(__ret_uint8_t__uint8_t__, rv_prf_id_get, __f)
#define RV_PRF_ID_GET_ADD_LAST(__f) \
    RV_ADD_LAST(__ret_uint8_t__uint8_t__, rv_prf_id_get, __f)


/* const struct rwip_eif_api *fn(uint8_t) */
struct rwip_eif_api;

typedef rep_vec_err_t (*rep_vec_fn__ret_const_struct_rwip_eif_api_p__uint8_t__t)(const struct rwip_eif_api **, uint8_t);

typedef struct rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__s {
    rep_vec_fn__ret_const_struct_rwip_eif_api_p__uint8_t__t fn;
    struct rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__s *next;
} rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__t;

void
rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__add(
    rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__t **head,
    rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__t *new_entry);
void
rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__add_last(
    rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__t **head,
    rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__t *new_entry);
const struct rwip_eif_api *
rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__invoke(
    rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__t *rv,
    const struct rwip_eif_api *(*def_fn)(uint8_t),
    uint8_t idx);

/**
 * @brief Function to retrieve each external interface API
 * @param[in] idx External interface index
 * @return External interface api structure
 */
extern rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__t *rv_rwip_eif_get;
#define RV_RWIP_EIF_GET_ADD(__f) \
    RV_ADD(__ret_const_struct_rwip_eif_api_p__uint8_t__, rv_rwip_eif_get, __f)
#define RV_RWIP_EIF_GET_ADD_LAST(__f) \
    RV_ADD_LAST(__ret_const_struct_rwip_eif_api_p__uint8_t__, rv_rwip_eif_get, __f)


/* bool fn(void) */
typedef rep_vec_err_t (*rep_vec_fn__ret_bool__t)(bool *);

typedef struct rep_vec__ret_bool__s {
    rep_vec_fn__ret_bool__t fn;
    struct rep_vec__ret_bool__s *next;
} rep_vec__ret_bool__t;

void
rep_vec__ret_bool__add(rep_vec__ret_bool__t **head,
    rep_vec__ret_bool__t *new_entry);
void
rep_vec__ret_bool__add_last(rep_vec__ret_bool__t **head,
    rep_vec__ret_bool__t *new_entry);
bool
rep_vec__ret_bool__invoke(rep_vec__ret_bool__t *rv, bool (*def_fn)(void));

/**
 * @brief This vector can be used to prevent the BLE module from entering
 * sleep.  It will also prevent the rest of the system from entering any power
 * saving mode.
 * @return true to prevent sleep
 */
extern rep_vec__ret_bool__t *rv_prevent_ble_sleep;
#define RV_PREVENT_BLE_SLEEP_ADD(__f) \
    RV_ADD(__ret_bool__, rv_prevent_ble_sleep, __f)
#define RV_PREVENT_BLE_SLEEP_ADD_LAST(__f) \
    RV_ADD_LAST(__ret_bool__, rv_prevent_ble_sleep, __f)


/* uint32_t fn(void) */
typedef rep_vec_err_t (*rep_vec_fn__ret_uint32_t__t)(uint32_t *);

typedef struct rep_vec__ret_uint32_t__s {
    rep_vec_fn__ret_uint32_t__t fn;
    struct rep_vec__ret_uint32_t__s *next;
} rep_vec__ret_uint32_t__t;

void
rep_vec__ret_uint32_t__add(rep_vec__ret_uint32_t__t **head,
    rep_vec__ret_uint32_t__t *new_entry);
void
rep_vec__ret_uint32_t__add_last(rep_vec__ret_uint32_t__t **head,
    rep_vec__ret_uint32_t__t *new_entry);
uint32_t
rep_vec__ret_uint32_t__invoke(rep_vec__ret_uint32_t__t *rv,
    uint32_t (*def_fn)(void));

/**
 * @brief This vector can be used to provide a secure source of random numbers
 * to various BLE security functions, such as key generation.  See driver/trng
 * for more information.
 * @return Secure random word
 */
extern rep_vec__ret_uint32_t__t *rv_secure_rand_word;
#define RV_SECURE_RAND_WORD_ADD(__f) \
    RV_ADD(__ret_uint32_t__, rv_secure_rand_word, __f)
#define RV_SECURE_RAND_WORD_ADD_LAST(__f) \
    RV_ADD_LAST(__ret_uint32_t__, rv_secure_rand_word, __f)


/* bool fn(int32_t *, int32_t) */
typedef rep_vec_err_t (*rep_vec_fn__ret_bool__int32_t_p__int32_t__t)(bool *, int32_t *, int32_t);

typedef struct rep_vec__ret_bool__int32_t_p__int32_t__s {
    rep_vec_fn__ret_bool__int32_t_p__int32_t__t fn;
    struct rep_vec__ret_bool__int32_t_p__int32_t__s *next;
} rep_vec__ret_bool__int32_t_p__int32_t__t;

void
rep_vec__ret_bool__int32_t_p__int32_t__add(
    rep_vec__ret_bool__int32_t_p__int32_t__t **head,
    rep_vec__ret_bool__int32_t_p__int32_t__t *new_entry);
void
rep_vec__ret_bool__int32_t_p__int32_t__add_last(
    rep_vec__ret_bool__int32_t_p__int32_t__t **head,
    rep_vec__ret_bool__int32_t_p__int32_t__t *new_entry);
bool
rep_vec__ret_bool__int32_t_p__int32_t__invoke(
    rep_vec__ret_bool__int32_t_p__int32_t__t *rv,
    bool (*def_fn)(int32_t *, int32_t), int32_t *pseq_dur, int32_t ble_dur);

/**
 * @brief After the BLE module has gone to sleep, this vector can be used to
 * prevent the system from entering the retention power saving mode.
 * @param[out] pseq_dur Adjusted duration (32KHz) for platform power management
 * @param[in] ble_dur Expected BLE sleep duration (32KHz)
 * @return true to prevent retention
 */
extern rep_vec__ret_bool__int32_t_p__int32_t__t *rv_plf_prevent_retention;
#define RV_PLF_PREVENT_RETENTION_ADD(__f) \
    RV_ADD(__ret_bool__int32_t_p__int32_t__, rv_plf_prevent_retention, __f)
#define RV_PLF_PREVENT_RETENTION_ADD_LAST(__f) \
    RV_ADD_LAST(__ret_bool__int32_t_p__int32_t__, rv_plf_prevent_retention, __f)

/**
 * @brief After the BLE module has gone to sleep, this vector can be used to
 * prevent the system from entering the hibernation power saving mode.
 * The HID examples use this to protect the system state while there is an
 * active connection to a central host.
 * @param[out] pseq_dur Adjusted duration (32KHz) for platform power management
 * @param[in] ble_dur Expected BLE sleep duration (32KHz)
 * @return true to prevent hibernation
 */
extern rep_vec__ret_bool__int32_t_p__int32_t__t *rv_plf_prevent_hibernation;
#define RV_PLF_PREVENT_HIBERNATION_ADD(__f) \
    RV_ADD(__ret_bool__int32_t_p__int32_t__, rv_plf_prevent_hibernation, __f)
#define RV_PLF_PREVENT_HIBERNATION_ADD_LAST(__f) \
    RV_ADD_LAST(__ret_bool__int32_t_p__int32_t__, rv_plf_prevent_hibernation, __f)


/* void fn(uint32_t) */
typedef rep_vec_err_t (*rep_vec_fn__uint32_t__t)(uint32_t);

typedef struct rep_vec__uint32_t__s {
    rep_vec_fn__uint32_t__t fn;
    struct rep_vec__uint32_t__s *next;
} rep_vec__uint32_t__t;

void
rep_vec__uint32_t__add(rep_vec__uint32_t__t **head,
    rep_vec__uint32_t__t *new_entry);
void
rep_vec__uint32_t__add_last(rep_vec__uint32_t__t **head,
    rep_vec__uint32_t__t *new_entry);
void
rep_vec__uint32_t__invoke(rep_vec__uint32_t__t *rv, void (*def_fn)(uint32_t),
    uint32_t wake_status);

/**
 * @brief After the system wakes up from a power saving mode, this vector is
 * invoked from a ke_event handler with the wakeup reason from the PSEQ STATUS
 * register.  Applications can decode this reason and take specific action.
 * @param[in] wake_status Wakeup reason
 */
extern rep_vec__uint32_t__t *rv_plf_awoken;
#define RV_PLF_AWOKEN_ADD(__f) \
    RV_ADD(__uint32_t__, rv_plf_awoken, __f)
#define RV_PLF_AWOKEN_ADD_LAST(__f) \
    RV_ADD_LAST(__uint32_t__, rv_plf_awoken, __f)


/* void fn(uint32_t, uint32_t *) */
typedef rep_vec_err_t (*rep_vec_fn__uint32_t__uint32_t_p__t)(uint32_t, uint32_t *);

typedef struct rep_vec__uint32_t__uint32_t_p__s {
    rep_vec_fn__uint32_t__uint32_t_p__t fn;
    struct rep_vec__uint32_t__uint32_t_p__s *next;
} rep_vec__uint32_t__uint32_t_p__t;

void
rep_vec__uint32_t__uint32_t_p__add(rep_vec__uint32_t__uint32_t_p__t **head,
    rep_vec__uint32_t__uint32_t_p__t *new_entry);
void
rep_vec__uint32_t__uint32_t_p__add_last(rep_vec__uint32_t__uint32_t_p__t **head,
    rep_vec__uint32_t__uint32_t_p__t *new_entry);
void
rep_vec__uint32_t__uint32_t_p__invoke(rep_vec__uint32_t__uint32_t_p__t *rv,
    void (*def_fn)(uint32_t, uint32_t *), uint32_t bp_freq, uint32_t *min_freq);

/**
 * @brief Platform power management interface for backplane frequency
 * throttling during CPU idle.  Peripheral drivers can use this to
 * implement minimum frequency requirements.
 * @param[in] bp_freq Current BP frequency in Hz
 * @param[out] min_freq Requested throttling frequency in Hz
 */
extern rep_vec__uint32_t__uint32_t_p__t *rv_plf_bp_throttle;
#define RV_PLF_BP_THROTTLE_ADD(__f) \
    RV_ADD(__uint32_t__uint32_t_p__, rv_plf_bp_throttle, __f)
#define RV_PLF_BP_THROTTLE_ADD_LAST(__f) \
    RV_ADD_LAST(__uint32_t__uint32_t_p__, rv_plf_bp_throttle, __f)


/* bool fn(int32_t, uint32_t *) */
typedef rep_vec_err_t (*rep_vec_fn__ret_bool__int32_t__uint32_t_p__t)(bool *, int32_t, uint32_t *);

typedef struct rep_vec__ret_bool__int32_t__uint32_t_p__s {
    rep_vec_fn__ret_bool__int32_t__uint32_t_p__t fn;
    struct rep_vec__ret_bool__int32_t__uint32_t_p__s *next;
} rep_vec__ret_bool__int32_t__uint32_t_p__t;

void
rep_vec__ret_bool__int32_t__uint32_t_p__add(
    rep_vec__ret_bool__int32_t__uint32_t_p__t **head,
    rep_vec__ret_bool__int32_t__uint32_t_p__t *new_entry);
void
rep_vec__ret_bool__int32_t__uint32_t_p__add_last(
    rep_vec__ret_bool__int32_t__uint32_t_p__t **head,
    rep_vec__ret_bool__int32_t__uint32_t_p__t *new_entry);
bool
rep_vec__ret_bool__int32_t__uint32_t_p__invoke(
    rep_vec__ret_bool__int32_t__uint32_t_p__t *rv,
    bool (*def_fn)(int32_t, uint32_t *), int32_t duration, uint32_t *int_set);

/**
 * @brief This vector permits customization of the power saving logic.
 * See driver/pseq for more information.
 * @param[in] duration Hibernation duration (32KHz)
 * @param[in] int_set Preserved interrupt enables
 * @return false if platform power management was skipped
 */
extern rep_vec__ret_bool__int32_t__uint32_t_p__t *rv_plf_hibernate;
#define RV_PLF_HIBERNATE_ADD(__f) \
    RV_ADD(__ret_bool__int32_t__uint32_t_p__, rv_plf_hibernate, __f)
#define RV_PLF_HIBERNATE_ADD_LAST(__f) \
    RV_ADD_LAST(__ret_bool__int32_t__uint32_t_p__, rv_plf_hibernate, __f)

/**
 * @brief This vector permits customization of the power saving logic.
 * See driver/pseq for more information.
 * @param[in] duration Retention duration (32KHz)
 * @param[in] int_set Preserved interrupt enables
 * @return false if platform power management was skipped
 */
extern rep_vec__ret_bool__int32_t__uint32_t_p__t *rv_plf_retain_all;
#define RV_PLF_RETAIN_ALL_ADD(__f) \
    RV_ADD(__ret_bool__int32_t__uint32_t_p__, rv_plf_retain_all, __f)
#define RV_PLF_RETAIN_ALL_ADD_LAST(__f) \
    RV_ADD_LAST(__ret_bool__int32_t__uint32_t_p__, rv_plf_retain_all, __f)


/* void fn(bool *, uint32_t *, bool, int32_t) */
typedef rep_vec_err_t (*rep_vec_fn__bool_p__uint32_t_p__bool__int32_t__t)(bool *, uint32_t *, bool, int32_t);

typedef struct rep_vec__bool_p__uint32_t_p__bool__int32_t__s {
    rep_vec_fn__bool_p__uint32_t_p__bool__int32_t__t fn;
    struct rep_vec__bool_p__uint32_t_p__bool__int32_t__s *next;
} rep_vec__bool_p__uint32_t_p__bool__int32_t__t;

void
rep_vec__bool_p__uint32_t_p__bool__int32_t__add(
    rep_vec__bool_p__uint32_t_p__bool__int32_t__t **head,
    rep_vec__bool_p__uint32_t_p__bool__int32_t__t *new_entry);
void
rep_vec__bool_p__uint32_t_p__bool__int32_t__add_last(
    rep_vec__bool_p__uint32_t_p__bool__int32_t__t **head,
    rep_vec__bool_p__uint32_t_p__bool__int32_t__t *new_entry);
void
rep_vec__bool_p__uint32_t_p__bool__int32_t__invoke(
    rep_vec__bool_p__uint32_t_p__bool__int32_t__t *rv,
    void (*def_fn)(bool *, uint32_t *, bool, int32_t), bool *pseq_sleep,
    uint32_t *int_set, bool ble_asleep, int32_t ble_sleep_duration);

/**
 * @brief This vector permits customization of the power saving logic.
 * See driver/pseq for more information.
 * @param[out] pseq_sleep false if platform power management was skipped
 * @param[out] int_set Preserved interrupt enables
 * @param[in] ble_asleep BLE was already asleep
 * @param[in] ble_sleep_duration Expected BLE sleep duration (32KHz)
 */
extern rep_vec__bool_p__uint32_t_p__bool__int32_t__t *rv_plf_to_deep_sleep;
#define RV_PLF_TO_DEEP_SLEEP_ADD(__f) \
    RV_ADD(__bool_p__uint32_t_p__bool__int32_t__, rv_plf_to_deep_sleep, __f)
#define RV_PLF_TO_DEEP_SLEEP_ADD_LAST(__f) \
    RV_ADD_LAST(__bool_p__uint32_t_p__bool__int32_t__, rv_plf_to_deep_sleep, __f)


/* void fn(bool, uint32_t *) */
typedef rep_vec_err_t (*rep_vec_fn__bool__uint32_t_p__t)(bool, uint32_t *);

typedef struct rep_vec__bool__uint32_t_p__s {
    rep_vec_fn__bool__uint32_t_p__t fn;
    struct rep_vec__bool__uint32_t_p__s *next;
} rep_vec__bool__uint32_t_p__t;

void
rep_vec__bool__uint32_t_p__add(rep_vec__bool__uint32_t_p__t **head,
    rep_vec__bool__uint32_t_p__t *new_entry);
void
rep_vec__bool__uint32_t_p__add_last(rep_vec__bool__uint32_t_p__t **head,
    rep_vec__bool__uint32_t_p__t *new_entry);
void
rep_vec__bool__uint32_t_p__invoke(rep_vec__bool__uint32_t_p__t *rv,
    void (*def_fn)(bool, uint32_t *), bool pseq_sleep, uint32_t *int_set);

/**
 * @brief This vector permits customization of the power saving logic.
 * See driver/pseq for more information.
 * @param[in] pseq_sleep false if platform power management was skipped
 * @param[in] int_set Preserved interrupt enables
 */
extern rep_vec__bool__uint32_t_p__t *rv_plf_from_deep_sleep;
#define RV_PLF_FROM_DEEP_SLEEP_ADD(__f) \
    RV_ADD(__bool__uint32_t_p__, rv_plf_from_deep_sleep, __f)
#define RV_PLF_FROM_DEEP_SLEEP_ADD_LAST(__f) \
    RV_ADD_LAST(__bool__uint32_t_p__, rv_plf_from_deep_sleep, __f)

#ifdef __cplusplus
}
#endif
