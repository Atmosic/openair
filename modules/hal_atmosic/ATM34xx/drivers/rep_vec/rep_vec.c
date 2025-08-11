/**
 *******************************************************************************
 *
 * @file rep_vec.c
 *
 * @brief Replacement vectors for strategic code paths
 *
 * Copyright (C) Atmosic 2017-2022
 *
 *******************************************************************************
 */

#include "arch.h"
#include "rep_vec.h"

#include <stdlib.h>


/* void fn(void) */
rep_vec_t *rv_plf_schedule;
rep_vec_t *rv_plf_reset;
rep_vec_t *rv_appm_init;
rep_vec_t *rv_rf_sleep;
rep_vec_t *rv_rf_wake;
rep_vec_t *rv_plf_back_from_retain_all;
rep_vec_t *rv_notify_rwip_reset_cmpl;

void rep_vec_add(rep_vec_t **head, rep_vec_t *new_entry)
{
    new_entry->next = *head;
    *head = new_entry;
}

void rep_vec_add_last(rep_vec_t **head, rep_vec_t *new_entry)
{
    rep_vec_t **tail = head;
    while (*tail) {
	tail = &(*tail)->next;
    }
    new_entry->next = NULL;
    *tail = new_entry;
}

/**
 * @brief Invoke replacement vector.
 *
 * @note For FlashROM images, __FAST will locate this function in RAM.
 * At invocation, the HPC might be disabled.
 */
__FAST
void rep_vec_invoke(rep_vec_t *rv, void (*def_fn)(void))
{
    for (; rv; rv=rv->next) {
	rep_vec_err_t err = rv->fn();
	if (err == RV_DONE) {
	    return;
	}
    }
    if (def_fn) {
	def_fn();
    }
}


/* const struct prf_task_cbs *fn(uint8_t) */
rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__t *rv_prf_itf_get;

void
rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__add(
    rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__t **head,
    rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__t *new_entry)
{
    new_entry->next = *head;
    *head = new_entry;
}

void
rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__add_last(
    rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__t **head,
    rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__t *new_entry)
{
    rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__t **tail = head;
    while (*tail) {
	tail = &(*tail)->next;
    }
    new_entry->next = NULL;
    *tail = new_entry;
}

const struct prf_task_cbs *
rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__invoke(
    rep_vec__ret_const_struct_prf_task_cbs_p__uint8_t__t *rv,
    const struct prf_task_cbs *(*def_fn)(uint8_t),
    uint8_t prf_id)
{
    const struct prf_task_cbs * ret = NULL;

    for (; rv; rv=rv->next) {
	rep_vec_err_t err = rv->fn(&ret, prf_id);
	if (err == RV_DONE) {
	    goto done;
	}
    }
    if (def_fn) {
	ret = def_fn(prf_id);
    }
done:
    return ret;
}


/* uint8_t fn(uint8_t) */
rep_vec__ret_uint8_t__uint8_t__t *rv_prf_id_get;

void
rep_vec__ret_uint8_t__uint8_t__add(
    rep_vec__ret_uint8_t__uint8_t__t **head,
    rep_vec__ret_uint8_t__uint8_t__t *new_entry)
{
    new_entry->next = *head;
    *head = new_entry;
}

void
rep_vec__ret_uint8_t__uint8_t__add_last(
    rep_vec__ret_uint8_t__uint8_t__t **head,
    rep_vec__ret_uint8_t__uint8_t__t *new_entry)
{
    rep_vec__ret_uint8_t__uint8_t__t **tail = head;
    while (*tail) {
	tail = &(*tail)->next;
    }
    new_entry->next = NULL;
    *tail = new_entry;
}

uint8_t
rep_vec__ret_uint8_t__uint8_t__invoke(rep_vec__ret_uint8_t__uint8_t__t *rv,
    uint8_t (*def_fn)(uint8_t), uint8_t api_id)
{
    uint8_t ret = 0;

    for (; rv; rv=rv->next) {
	rep_vec_err_t err = rv->fn(&ret, api_id);
	if (err == RV_DONE) {
	    goto done;
	}
    }
    if (def_fn) {
	ret = def_fn(api_id);
    }
done:
    return ret;
}


/* const struct rwip_eif_api *fn(uint8_t) */
rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__t *rv_rwip_eif_get;

void
rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__add(
    rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__t **head,
    rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__t *new_entry)
{
    new_entry->next = *head;
    *head = new_entry;
}

void
rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__add_last(
    rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__t **head,
    rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__t *new_entry)
{
    rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__t **tail = head;
    while (*tail) {
	tail = &(*tail)->next;
    }
    new_entry->next = NULL;
    *tail = new_entry;
}

const struct rwip_eif_api *
rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__invoke(
    rep_vec__ret_const_struct_rwip_eif_api_p__uint8_t__t *rv,
    const struct rwip_eif_api *(*def_fn)(uint8_t),
    uint8_t idx)
{
    const struct rwip_eif_api * ret = NULL;

    for (; rv; rv=rv->next) {
	rep_vec_err_t err = rv->fn(&ret, idx);
	if (err == RV_DONE) {
	    goto done;
	}
    }
    if (def_fn) {
	ret = def_fn(idx);
    }
done:
    return ret;
}


/* bool fn(void) */
rep_vec__ret_bool__t *rv_prevent_ble_sleep;

void
rep_vec__ret_bool__add(rep_vec__ret_bool__t **head,
    rep_vec__ret_bool__t *new_entry)
{
    new_entry->next = *head;
    *head = new_entry;
}

void
rep_vec__ret_bool__add_last(rep_vec__ret_bool__t **head,
    rep_vec__ret_bool__t *new_entry)
{
    rep_vec__ret_bool__t **tail = head;
    while (*tail) {
	tail = &(*tail)->next;
    }
    new_entry->next = NULL;
    *tail = new_entry;
}

bool
rep_vec__ret_bool__invoke(rep_vec__ret_bool__t *rv, bool (*def_fn)(void))
{
    bool ret = false;

    for (; rv; rv=rv->next) {
	rep_vec_err_t err = rv->fn(&ret);
	if (err == RV_DONE) {
	    goto done;
	}
    }
    if (def_fn) {
	ret = def_fn();
    }
done:
    return ret;
}


/* uint32_t fn(void) */
rep_vec__ret_uint32_t__t *rv_radio_sleep_state;
rep_vec__ret_uint32_t__t *rv_secure_rand_word;

void
rep_vec__ret_uint32_t__add(rep_vec__ret_uint32_t__t **head,
    rep_vec__ret_uint32_t__t *new_entry)
{
    new_entry->next = *head;
    *head = new_entry;
}

void
rep_vec__ret_uint32_t__add_last(rep_vec__ret_uint32_t__t **head,
    rep_vec__ret_uint32_t__t *new_entry)
{
    rep_vec__ret_uint32_t__t **tail = head;
    while (*tail) {
	tail = &(*tail)->next;
    }
    new_entry->next = NULL;
    *tail = new_entry;
}

uint32_t
rep_vec__ret_uint32_t__invoke_default(rep_vec__ret_uint32_t__t *rv,
    uint32_t def_ret, uint32_t (*def_fn)(void))
{
    uint32_t ret = def_ret;

    for (; rv; rv=rv->next) {
	rep_vec_err_t err = rv->fn(&ret);
	if (err == RV_DONE) {
	    goto done;
	}
    }
    if (def_fn) {
	ret = def_fn();
    }
done:
    return ret;
}

uint32_t
rep_vec__ret_uint32_t__invoke(rep_vec__ret_uint32_t__t *rv,
    uint32_t (*def_fn)(void))
{
    return rep_vec__ret_uint32_t__invoke_default(rv, 0, def_fn);
}


/* bool fn(int32_t *, int32_t) */
rep_vec__ret_bool__int32_t_p__int32_t__t *rv_plf_prevent_retention;
rep_vec__ret_bool__int32_t_p__int32_t__t *rv_plf_prevent_hibernation;

void
rep_vec__ret_bool__int32_t_p__int32_t__add(
    rep_vec__ret_bool__int32_t_p__int32_t__t **head,
    rep_vec__ret_bool__int32_t_p__int32_t__t *new_entry)
{
    new_entry->next = *head;
    *head = new_entry;
}

void
rep_vec__ret_bool__int32_t_p__int32_t__add_last(
    rep_vec__ret_bool__int32_t_p__int32_t__t **head,
    rep_vec__ret_bool__int32_t_p__int32_t__t *new_entry)
{
    rep_vec__ret_bool__int32_t_p__int32_t__t **tail = head;
    while (*tail) {
	tail = &(*tail)->next;
    }
    new_entry->next = NULL;
    *tail = new_entry;
}

bool
rep_vec__ret_bool__int32_t_p__int32_t__invoke(
    rep_vec__ret_bool__int32_t_p__int32_t__t *rv,
    bool (*def_fn)(int32_t *, int32_t), int32_t *pseq_dur, int32_t ble_dur)
{
    bool ret = false;

    for (; rv; rv=rv->next) {
	rep_vec_err_t err = rv->fn(&ret, pseq_dur, ble_dur);
	if (err == RV_DONE) {
	    goto done;
	}
    }
    if (def_fn) {
	ret = def_fn(pseq_dur, ble_dur);
    }
done:
    return ret;
}


/* void fn(uint32_t) */
rep_vec__uint32_t__t *rv_plf_awoken;

void
rep_vec__uint32_t__add(rep_vec__uint32_t__t **head,
    rep_vec__uint32_t__t *new_entry)
{
    new_entry->next = *head;
    *head = new_entry;
}

void
rep_vec__uint32_t__add_last(rep_vec__uint32_t__t **head,
    rep_vec__uint32_t__t *new_entry)
{
    rep_vec__uint32_t__t **tail = head;
    while (*tail) {
	tail = &(*tail)->next;
    }
    new_entry->next = NULL;
    *tail = new_entry;
}

void
rep_vec__uint32_t__invoke(rep_vec__uint32_t__t *rv, void (*def_fn)(uint32_t),
    uint32_t wake_status)
{
    for (; rv; rv=rv->next) {
	rep_vec_err_t err = rv->fn(wake_status);
	if (err == RV_DONE) {
	    return;
	}
    }
    if (def_fn) {
	def_fn(wake_status);
    }
}


/* void fn(uint32_t, uint32_t *) */
rep_vec__uint32_t__uint32_t_p__t *rv_plf_bp_throttle;

void
rep_vec__uint32_t__uint32_t_p__add(rep_vec__uint32_t__uint32_t_p__t **head,
    rep_vec__uint32_t__uint32_t_p__t *new_entry)
{
    new_entry->next = *head;
    *head = new_entry;
}

void
rep_vec__uint32_t__uint32_t_p__add_last(rep_vec__uint32_t__uint32_t_p__t **head,
    rep_vec__uint32_t__uint32_t_p__t *new_entry)
{
    rep_vec__uint32_t__uint32_t_p__t **tail = head;
    while (*tail) {
	tail = &(*tail)->next;
    }
    new_entry->next = NULL;
    *tail = new_entry;
}

void
rep_vec__uint32_t__uint32_t_p__invoke(rep_vec__uint32_t__uint32_t_p__t *rv,
    void (*def_fn)(uint32_t, uint32_t *), uint32_t bp_freq, uint32_t *min_freq)
{
    for (; rv; rv=rv->next) {
	rep_vec_err_t err = rv->fn(bp_freq, min_freq);
	if (err == RV_DONE) {
	    return;
	}
    }
    if (def_fn) {
	def_fn(bp_freq, min_freq);
    }
}


/* bool fn(int32_t, uint32_t *) */
rep_vec__ret_bool__int32_t__uint32_t_p__t *rv_plf_hibernate;
rep_vec__ret_bool__int32_t__uint32_t_p__t *rv_plf_retain_all;

void
rep_vec__ret_bool__int32_t__uint32_t_p__add(
    rep_vec__ret_bool__int32_t__uint32_t_p__t **head,
    rep_vec__ret_bool__int32_t__uint32_t_p__t *new_entry)
{
    new_entry->next = *head;
    *head = new_entry;
}

void
rep_vec__ret_bool__int32_t__uint32_t_p__add_last(
    rep_vec__ret_bool__int32_t__uint32_t_p__t **head,
    rep_vec__ret_bool__int32_t__uint32_t_p__t *new_entry)
{
    rep_vec__ret_bool__int32_t__uint32_t_p__t **tail = head;
    while (*tail) {
	tail = &(*tail)->next;
    }
    new_entry->next = NULL;
    *tail = new_entry;
}

/**
 * @brief Invoke replacement vector.
 *
 * @note For FlashROM images, __FAST will locate this function in RAM.
 * rv_plf_retain_all can disable the HPC.
 */
__FAST
bool
rep_vec__ret_bool__int32_t__uint32_t_p__invoke(
    rep_vec__ret_bool__int32_t__uint32_t_p__t *rv,
    bool (*def_fn)(int32_t, uint32_t *), int32_t duration, uint32_t *int_set)
{
    bool ret = false;

    for (; rv; rv=rv->next) {
	rep_vec_err_t err = rv->fn(&ret, duration, int_set);
	if (err == RV_DONE) {
	    goto done;
	}
    }
    if (def_fn) {
	ret = def_fn(duration, int_set);
    }
done:
    return ret;
}


/* void fn(bool *, uint32_t *, bool, int32_t) */
rep_vec__bool_p__uint32_t_p__bool__int32_t__t *rv_plf_to_deep_sleep;

void
rep_vec__bool_p__uint32_t_p__bool__int32_t__add(
    rep_vec__bool_p__uint32_t_p__bool__int32_t__t **head,
    rep_vec__bool_p__uint32_t_p__bool__int32_t__t *new_entry)
{
    new_entry->next = *head;
    *head = new_entry;
}

void
rep_vec__bool_p__uint32_t_p__bool__int32_t__add_last(
    rep_vec__bool_p__uint32_t_p__bool__int32_t__t **head,
    rep_vec__bool_p__uint32_t_p__bool__int32_t__t *new_entry)
{
    rep_vec__bool_p__uint32_t_p__bool__int32_t__t **tail = head;
    while (*tail) {
	tail = &(*tail)->next;
    }
    new_entry->next = NULL;
    *tail = new_entry;
}

/**
 * @brief Invoke replacement vector.
 *
 * @note For FlashROM images, __FAST will locate this function in RAM.
 * rv_plf_to_deep_sleep can disable the HPC.
 */
__FAST
void
rep_vec__bool_p__uint32_t_p__bool__int32_t__invoke(
    rep_vec__bool_p__uint32_t_p__bool__int32_t__t *rv,
    void (*def_fn)(bool *, uint32_t *, bool, int32_t), bool *pseq_sleep,
    uint32_t *int_set, bool ble_asleep, int32_t ble_sleep_duration)
{
    for (; rv; rv=rv->next) {
	rep_vec_err_t err =
	    rv->fn(pseq_sleep, int_set, ble_asleep, ble_sleep_duration);
	if (err == RV_DONE) {
	    return;
	}
    }
    if (def_fn) {
	def_fn(pseq_sleep, int_set, ble_asleep, ble_sleep_duration);
    }
}


/* void fn(bool, uint32_t *) */
rep_vec__bool__uint32_t_p__t *rv_plf_from_deep_sleep;

void
rep_vec__bool__uint32_t_p__add(rep_vec__bool__uint32_t_p__t **head,
    rep_vec__bool__uint32_t_p__t *new_entry)
{
    new_entry->next = *head;
    *head = new_entry;
}

void
rep_vec__bool__uint32_t_p__add_last(rep_vec__bool__uint32_t_p__t **head,
    rep_vec__bool__uint32_t_p__t *new_entry)
{
    rep_vec__bool__uint32_t_p__t **tail = head;
    while (*tail) {
	tail = &(*tail)->next;
    }
    new_entry->next = NULL;
    *tail = new_entry;
}

/**
 * @brief Invoke replacement vector.
 *
 * @note For FlashROM images, __FAST will locate this function in RAM.
 * At invocation, the HPC might be disabled.
 */
__FAST
void
rep_vec__bool__uint32_t_p__invoke(rep_vec__bool__uint32_t_p__t *rv,
    void (*def_fn)(bool, uint32_t *), bool pseq_sleep, uint32_t *int_set)
{
    for (; rv; rv=rv->next) {
	rep_vec_err_t err = rv->fn(pseq_sleep, int_set);
	if (err == RV_DONE) {
	    return;
	}
    }
    if (def_fn) {
	def_fn(pseq_sleep, int_set);
    }
}
