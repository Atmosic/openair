/**
 ******************************************************************************
 *
 * @file wurx_rom.c
 *
 * @brief Wake-Up Receiver
 *
 * Copyright (C) Atmosic 2019-2020
 *
 *
 ******************************************************************************
 */

#include "arch.h"
#include <stdbool.h>


#ifndef CFG_ROM
bool wurx0_enabled, wurx1_enabled;

void wurx_disable(void)
{
    wurx0_enabled = wurx1_enabled = false;
}
#endif
