/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include "rc_mmi_timer.h"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(rc_mmi_timer, CONFIG_HID_REMOTE_LOG_LEVEL);

#define TIMER_STACK_SIZE 996
static K_KERNEL_STACK_DEFINE(timer_thread_stack, TIMER_STACK_SIZE);

static mmi_timer_cb_t idle_cb;
static mmi_timer_cb_t hib_cb;

static struct k_work_q timer_wq;

static void idle_expire(struct k_work *w)
{
	idle_cb();
}
static void hib_expire(struct k_work *w)
{
	hib_cb();
}

K_WORK_DELAYABLE_DEFINE(idle_work, idle_expire);
K_WORK_DELAYABLE_DEFINE(hib_work, hib_expire);

void rc_mmi_timer_init(mmi_timer_cb_t fn_idle, mmi_timer_cb_t fn_hib)
{
	idle_cb = fn_idle;
	hib_cb = fn_hib;

	k_work_queue_init(&timer_wq);
	k_work_queue_start(&timer_wq, timer_thread_stack, K_KERNEL_STACK_SIZEOF(timer_thread_stack),
			   K_HIGHEST_APPLICATION_THREAD_PRIO, NULL);
	k_thread_name_set(&timer_wq.thread, "RC_MMI_TIMER");
}

void rc_mmi_timer_idle_set(uint32_t cs)
{
	k_work_reschedule_for_queue(&timer_wq, &idle_work, K_MSEC(cs * 10));
}

void rc_mmi_timer_idle_clear(void)
{
	k_work_cancel_delayable(&idle_work);
}

void rc_mmi_timer_hib_set(uint32_t cs)
{
	k_work_reschedule_for_queue(&timer_wq, &hib_work, K_MSEC(cs * 10));
}

void rc_mmi_timer_hib_clear(void)
{
	k_work_cancel_delayable(&hib_work);
}

void rc_mmi_timer_clear_all(void)
{
	k_work_cancel_delayable(&idle_work);
}
