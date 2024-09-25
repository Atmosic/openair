/**
 *******************************************************************************
 *
 * @file pseq_internal.h
 *
 * @brief System power management
 *
 * Copyright (C) Atmosic 2024
 *
 *******************************************************************************
 */

#pragma once

#ifndef PSEQ_INTERNAL_DIRECT_INCLUDE_GUARD
#error "pseq_internal.h should only be included in pseq source files"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define RAM_BANK_SIZE		0x4000
#define RAM_ADDR2BANK(__addr)	(((__addr) - CMSDK_SRAM_BASE) / RAM_BANK_SIZE)
#define RAM_BANK2MASK(__bank)	((1 << ((__bank) + 1)) - 1)

#define XTAL_FORCE (PSEQ_OVERRIDES__FORCE_PRECISION_VAL__MASK | \
    PSEQ_OVERRIDES__FORCE_PRECISION_REQ__MASK)

void pseq_core_config_retain(uint32_t duration, uint32_t block_sysram,
    bool wurx0, bool wurx1);
void pseq_core_enter_retain(bool wurx0, bool wurx1);
void pseq_core_back_from_retain(void);

uint32_t pseq_core_config_hibernate(uint32_t duration, bool wurx0, bool wurx1);
void pseq_core_enter_hibernation(bool wurx0, bool wurx1);

void pseq_core_config_soc_off(uint64_t duration);
void pseq_core_enter_soc_off(void);

void pseq_core_power_off_sysram(uint32_t unused_sysram);
void pseq_core_power_all_sysram(void);
void pseq_core_xtal_init(void);

#ifdef __cplusplus
}
#endif
