/**
 *******************************************************************************
 *
 * @file atm_test_common.h
 *
 * @brief File to include architecture dependent macros/function definitions
 *
 * Copyright (C) Atmosic 2024
 *
 *******************************************************************************
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_SOC_FAMILY_ATM

#include <zephyr/kernel.h>
#include "arch.h"

__STATIC_INLINE void ATM_TEST_PASSED(void)
{
    printk("Test Success!\n");

#ifndef CONFIG_COVERAGE
    printk("\x04\n");
#endif
}

__STATIC_INLINE void ATM_TEST_FAILED(void)
{
    printk("TEST failed!\n");

#ifndef CONFIG_COVERAGE
    printk("\x03\n");
#endif
}

#endif // CONFIG_SOC_FAMILY_ATM

#ifdef __cplusplus
}
#endif
