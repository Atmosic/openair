/**
 *******************************************************************************
 *
 * @file test_common.h
 *
 * @brief File to include architecture dependent macros/function definitions
 *
 * Copyright (C) Atmosic 2020-2025
 *
 *******************************************************************************
 */

#pragma once

#include <stdint.h>
#include "ARMv8MBL.h"
#include "base_addr.h"
#include "retarget_uart.h"
#include "common_config.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_LOG
#define c_print_str printf
#define c_print_char(c) printf("%c", c)
#elif defined(CONFIG_PRINTK)
#define c_print_str printk
#define c_print_char(c) printk("%c", c)
#endif

/**
 * @brief Initialize Floating point
 */
__STATIC_INLINE void CommonInitFP(void)
{
#ifdef __ARM_FP
    SCB->CPACR |= SCB_CPACR_FPU;
#ifdef SECURE_MODE
    SCB_NS->CPACR |= SCB_CPACR_FPU;
    SCB->NSACR |= (0x3U << 10U); // enable non-secure access to CP10 and CP11
#endif
    __ISB();
    __ASM volatile ("VMSR fpscr, %0" : : "r" (0x00) : );
    return;
#endif // __ARM_FP
}

// Common Initialization functions
/**
 * @brief Initialize MPU regions
 */
void common_mpu_cfg(void);

/**
 * @brief Initialize CPU
 */
void CommonInitCPU(void);
/**
 * @brief Initialize System
 * @note Initializes SAU and MPC
 */
void CommonInitSystem(void);

/**
 * @brief Initialize System for early boot
 * @note This function is safe to call before BSS/Data is initialized
 */
void CommonInitBoot(void);

#if defined(AUTO_TEST) || defined(CONFIG_AUTO_TEST)
void secure_gcov_dump(void);
#ifndef SECURE_PROC_ENV
__NO_RETURN void gcov_dump(void);
#endif

__NO_RETURN
__STATIC_INLINE void TEST_PASSED(void)
{
#if defined(__GNUC__) && !defined(__ARMCC_VERSION)
    extern void __libc_fini_array(void);
    __libc_fini_array();
#endif

    c_print_str("[*** Test Success ***]\n");

#ifndef SECURE_PROC_ENV
#ifdef SECURE_GCOV
    secure_gcov_dump();
#endif
#endif // SECURE_PROC_ENV
    /* Halt simulation */
    while (1) {
#ifndef LONG_TEST
	c_print_char(4);
#endif
    }
}

__NO_RETURN
__STATIC_INLINE void TEST_FAILED(void)
{
#if defined(__GNUC__) && !defined(__ARMCC_VERSION)
    extern void __libc_fini_array(void);
    __libc_fini_array();
#endif

    c_print_str(" ** TEST FAILED ** \n");

#ifndef SECURE_PROC_ENV
#ifdef SECURE_GCOV
    secure_gcov_dump();
#endif
#endif // SECURE_PROC_ENV
    /* Halt simulation */
    while (1) {
	c_print_char(3);
    }
}
#else
#define TEST_PASSED() do { } while(0)
#define TEST_FAILED() do { } while(1)
#endif

#ifdef __cplusplus
}
#endif
