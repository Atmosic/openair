/**
 *******************************************************************************
 *
 * @file sec_assert.c
 *
 * @brief Secure Assert library
 *
 * Copyright (C) Atmosic 2023-2024
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#define PRINTF printk
#else
#define PRINTF printf
#endif
#include <stdio.h>
#include "arch.h"
#include "sec_assert.h"

void sec_assert(const char *file, int line)
{
    PRINTF("Fatal security assert");

#if PLF_DEBUG
    if (file) {
	PRINTF(" at %s:%i", file, line);
    }
#endif
    PRINTF("\n");
    GLOBAL_INT_STOP();
    __BKPT(0);
    while (1)
	;
}