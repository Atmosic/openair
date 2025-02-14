/**
 *******************************************************************************
 *
 * @file app_work_q.h
 *
 * @brief Atmosic app work queue
 *
 * Copyright (C) Atmosic 2024-2025
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup app_work_q
 * @ingroup APP
 * @brief App Work Queue
 * @{
 */

#include <zephyr/kernel.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Submit a work item to the app work queue.
 *
 * This library allows the sharing of a single work queue for Atmosic
 * applications that require deferred work requested by other Atmosic modules.
 * It is more memory efficient compared to each module creating its own work
 * queue, each of which would require its own dedicated thread stack.
 *
 * @funcprops \isr_ok
 *
 * @param work pointer to the work item.
 *
 * @return as with k_work_submit_to_queue().
 */
int atm_work_submit_to_app_work_q(struct k_work *work);

/**
 * @brief Submit an idle work item to the app work queue after a delay.
 *
 * This is a thin wrapper around k_work_schedule_for_queue(), with all the API
 * characteristics of that function.
 *
 * @param dwork pointer to the delayable work item.
 *
 * @param delay the time to wait before submitting the work item.  If @c
 * K_NO_WAIT this is equivalent to k_work_submit_to_queue().
 *
 * @return as with k_work_schedule_for_queue().
 */
int atm_work_schedule_for_app_work_q(struct k_work_delayable *dwork,
    k_timeout_t delay);

/**
 * @brief Reschedule a work item to the app work queue after a delay.
 *
 * This is a thin wrapper around k_work_reschedule_for_queue(), with all the API
 * characteristics of that function.
 *
 * @param dwork pointer to the delayable work item.
 *
 * @param delay the time to wait before submitting the work item.
 *
 * @return as with k_work_reschedule_for_queue().
 */
int atm_work_reschedule_for_app_work_q(struct k_work_delayable *dwork,
    k_timeout_t delay);

#ifdef __cplusplus
}
#endif

/// @}
