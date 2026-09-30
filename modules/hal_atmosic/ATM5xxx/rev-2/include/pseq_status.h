/**
 *******************************************************************************
 *
 * @file pseq_status.h
 *
 * @brief System power management status
 *
 * Copyright (C) Atmosic 2023
 *
 *******************************************************************************
 */

#pragma once

/**
 * @ingroup PSEQ
 * @brief System power management status
 * @{
 */

#include "at_apb_pseq_regs_core_macro.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PSEQ_STATUS_NON_POWER_ON (0xff | PSEQ_STATUS__CDBGPWRUPACK__MASK)
#define PSEQ_STATUS__POWER_ON_REASONS \
    (PSEQ_STATUS__READ & ~PSEQ_STATUS_NON_POWER_ON)

#ifdef __cplusplus
}
#endif

/// @}
