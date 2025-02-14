/*
 *******************************************************************************
 *
 * @file app_work_q.c
 *
 * @brief Atmosic app work queue
 *
 * Copyright (C) Atmosic 2024-2025
 *
 *******************************************************************************
 */

#include <zephyr/init.h>
#include "app_work_q.h"

#define APP_WORK_Q_PRIORITY K_PRIO_PREEMPT(CONFIG_APP_WORK_Q_PRIORITY)

static K_THREAD_STACK_DEFINE(app_work_q_stack, CONFIG_APP_WORK_Q_STACK_SIZE);
struct k_work_q app_work_q;

static int app_work_q_init(void)
{
    struct k_work_queue_config cfg = {
	.name = "appworkq",
	.no_yield = false,
	.essential = false,
    };

    k_work_queue_init(&app_work_q);
    k_work_queue_start(&app_work_q, app_work_q_stack,
	K_THREAD_STACK_SIZEOF(app_work_q_stack), APP_WORK_Q_PRIORITY, &cfg);

    return 0;
}

int atm_work_submit_to_app_work_q(struct k_work *work)
{
    return k_work_submit_to_queue(&app_work_q, work);
}

int atm_work_schedule_for_app_work_q(struct k_work_delayable *dwork,
    k_timeout_t delay)
{
    return k_work_schedule_for_queue(&app_work_q, dwork, delay);
}

int atm_work_reschedule_for_app_work_q(struct k_work_delayable *dwork,
    k_timeout_t delay)
{
    return k_work_reschedule_for_queue(&app_work_q, dwork, delay);
}

SYS_INIT(app_work_q_init, POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
