/*
 * Copyright (c) 2021-2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#ifndef _ASMLANGUAGE

#define __CORE_CM33_H_GENERIC
#define __CORE_CM33_H_DEPENDANT
#include "ARMv8MBL.h"
#include "base_addr.h"

#define MemoryManagement_IRQn MemManage_IRQn

/* Add include for DTS generated information */
#include <zephyr/devicetree.h>

#endif // !_ASMLANGUAGE

/**
 * @brief Is SOC currently in exception ?
 * @return true if soc is taking on exception
 */
static inline bool atm_soc_in_exception(void)
{
    return (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk);
}
