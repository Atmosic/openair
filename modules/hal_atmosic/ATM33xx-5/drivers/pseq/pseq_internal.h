/**
 *******************************************************************************
 *
 * @file pseq_internal.h
 *
 * @brief System power management
 *
 * Copyright (C) Atmosic 2023-2024
 *
 *******************************************************************************
 */

#pragma once

#ifndef PSEQ_INTERNAL_DIRECT_INCLUDE_GUARD
#error "pseq_internal.h should only be included in pseq source files"
#endif
#include "pseq_status.h"

#ifdef __cplusplus
extern "C" {
#endif

#define RAM_BANK_SIZE		0x4000
#define RAM_ADDR2BANK(__addr)	(((__addr) - CMSDK_SRAM_BASE) / RAM_BANK_SIZE)
#define RAM_BANK2MASK(__bank)	((1 << ((__bank) + 1)) - 1)

#define PSEQ_STATUS__SSE200_RESET	0x08000000U

#define WAKE_STATUS__AWOKEN		0x80000000U
#define WAKE_STATUS__STILL_ASLEEP	0x40000000U
#define WAKE_STATUS__WAKEUP_REQ		0x20000000U
#define WAKE_STATUS__TO_SLEEP		0x10000000U

#define INT_REG_NUM	4

#define XTAL_FORCE (PSEQ_OVERRIDES__FORCE_PRECISION_VAL__MASK | \
    PSEQ_OVERRIDES__FORCE_PRECISION_REQ__MASK)

extern uint32_t pseq_boot_status;
extern uint32_t wake_status;

void pseq_core_config_retain(uint32_t duration, uint32_t block_sysram,
    uintptr_t ssrs_block, bool wurx0, bool wurx1);
void pseq_core_enter_retain(bool wurx0, bool wurx1);
void pseq_core_back_from_retain(void);
void pseq_core_back_from_retain_final(void);

uint32_t pseq_core_config_hibernate(uint32_t duration, bool wurx0, bool wurx1);
void pseq_core_enter_hibernation(bool wurx0, bool wurx1);

void pseq_core_config_soc_off(uint64_t duration);
void pseq_core_enter_soc_off(void);
void pseq_core_disable_harv(void);

void pseq_core_rram_nap(void);
void pseq_core_rram_sd(void);

void pseq_core_power_off_sysram(uint32_t unused_sysram);
void pseq_core_power_all_sysram(void);
void pseq_core_xtal_init(void);
uint32_t pseq_core_init(void);
void pseq_core_reset_radio_controller(void);

#ifdef __cplusplus
}
#endif
