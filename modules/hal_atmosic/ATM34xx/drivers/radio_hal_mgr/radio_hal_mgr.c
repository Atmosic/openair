/**
 *******************************************************************************
 *
 * @file radio_hal_mgr.c
 *
 * @brief Radio Manager
 *
 * Copyright (C) Atmosic 2023-2025
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#endif

#ifdef CONFIG_BOARD_UNIT_TESTING
#include <zephyr/ztest.h>
#define MGR_IRQn 0
#define NVIC_EnableIRQ(n)
#define NVIC_DisableIRQ(n)
#define NVIC_SetPriority(n, p)
#define NVIC_ClearPendingIRQ(n)
#define NVIC_SetPendingIRQ(n) SW_0_Handler() // Directly call IRQ handler
#define DEBUG_TRACE(...)
#define __UNUSED __attribute__((unused))
#else
#include "arch.h"
#include "vectors.h"
#define MGR_IRQn SW_0_IRQn
#endif

#include <inttypes.h>
#include "radio_hal_mgr.h"

// Use this define to log recent protocol switches in the radio
#define NUM_DEBUG_SWITCHES 2

// Circular buffers to contain information on recent switches
static atm_mac_mgr_protocol_t debug_switch_from[NUM_DEBUG_SWITCHES];
static atm_mac_mgr_protocol_t debug_switch_to[NUM_DEBUG_SWITCHES];
static uint32_t debug_switch_time[NUM_DEBUG_SWITCHES];
static uint32_t debug_switch;
uint32_t debug_busy;
uint32_t debug_past;
uint32_t debug_abort;

#ifndef CONFIG_SOC_FAMILY_ATM
__attribute__((constructor))
#endif
static int atm_mac_mgr_sys_init(void)
{
    atm_mac_mgr_init();

    // Initialize interrupt for management
    NVIC_DisableIRQ(MGR_IRQn);
    NVIC_ClearPendingIRQ(MGR_IRQn);
#if defined(CONFIG_SOC_FAMILY_ATM) && !defined(CONFIG_BOARD_UNIT_TESTING)
    IRQ_DIRECT_CONNECT(MGR_IRQn, IRQ_PRI_RT, SW_0_Handler, IRQ_ZERO_LATENCY);
    irq_enable(MGR_IRQn);
#else
    NVIC_SetPriority(MGR_IRQn, IRQ_PRI_RT);
    NVIC_EnableIRQ(MGR_IRQn);
#endif
    return 0;
}

#ifdef CONFIG_SOC_FAMILY_ATM
SYS_INIT(atm_mac_mgr_sys_init, PRE_KERNEL_2, 10);
#endif

void atm_mac_mgr_debug_switch(atm_mac_mgr_protocol_t from,
    atm_mac_mgr_protocol_t to, uint32_t time)
{
#if NUM_DEBUG_SWITCHES > 0
    debug_switch_from[debug_switch % NUM_DEBUG_SWITCHES] = from;
    debug_switch_to[debug_switch % NUM_DEBUG_SWITCHES] = to;
    debug_switch_time[debug_switch % NUM_DEBUG_SWITCHES] = time;
#endif
    debug_switch++;
}

#if defined(CONFIG_SOC_FAMILY_ATM) && !defined(CONFIG_BOARD_UNIT_TESTING)
ISR_DIRECT_DECLARE(SW_0_Handler)
#else
void SW_0_Handler(void)
#endif
{
    atm_mac_mgr_handler();
#if defined(CONFIG_SOC_FAMILY_ATM) && !defined(CONFIG_BOARD_UNIT_TESTING)
    return 0;
#endif
}

void atm_mac_mgr_dump_debug(void)
{
    DEBUG_TRACE("Totals: switches %" PRIu32 ", busy %" PRIu32 ", past %" PRIu32
	", abort %" PRIu32, debug_switch, debug_busy, debug_past, debug_abort);
    __UNUSED uint32_t start = 0;
    for (int i = 0; i < NUM_DEBUG_SWITCHES; i++) {
	uint32_t index = 0;
#if NUM_DEBUG_SWITCHES > 0
	index = (debug_switch + i) % NUM_DEBUG_SWITCHES;
#endif
	DEBUG_TRACE("Mgr switch %u to %u at %" PRIu32 "(delta %" PRIu32 ")",
	    debug_switch_from[index], debug_switch_to[index],
	    debug_switch_time[index], debug_switch_time[index] - start);
	start = debug_switch_time[index];
    }
}

void atm_mac_mgr_schedule(void)
{
    NVIC_SetPendingIRQ(MGR_IRQn);
}
