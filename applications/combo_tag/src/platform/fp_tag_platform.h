/**
 *******************************************************************************
 *
 * @file fp_tag_platform.h
 *
 * @brief Platform For fp tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#include "platform_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief fp tag platform handlers get
 * @param[in] hdlrs tag handler structure pointer
 */
void fp_tag_platform_hdlrs_get(tag_hdlrs_t *hdlrs);
#ifdef __cplusplus
}
#endif

///@}
