/**
 *******************************************************************************
 *
 * @file stf_tag_platform.h
 *
 * @brief Platform For stf tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#include "platform_common.h"
#include "TagSdk.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief stf tag platform handlers get
 * @param[in] hdlrs tag handler structure pointer
 */
void stf_tag_platform_hdlrs_get(tag_hdlrs_t *hdlrs);

#ifdef __cplusplus
}
#endif
