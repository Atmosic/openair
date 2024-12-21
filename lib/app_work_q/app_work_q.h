/**
 *******************************************************************************
 *
 * @file app_work_q.h
 *
 * @brief Atmosic app work queue
 *
 * Copyright (C) Atmosic 2024
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup app_work_q
 * @ingroup APP
 * @brief App Work Queue
 * @{
 */

#include <zephyr/kernel.h>

#ifdef __cplusplus
extern "C" {
#endif

extern struct k_work_q app_work_q;

#ifdef __cplusplus
}
#endif

/// @}
