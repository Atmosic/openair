/**
 ******************************************************************************
 *
 * @file brwnout_internal.h
 *
 * @brief Brownout internal APIs
 *
 * Copyright (C) Atmosic 2024
 *
 ******************************************************************************
 */

#pragma once

#ifndef BROWNOUT_INTERNAL_GUARD
#error "brwnout_internal.h should only be included in brwnout source files"
#endif

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void brwnout_enable_intr(void);
void brwnout_clear_intr(void);

#ifdef __cplusplus
}
#endif
