/**
 *******************************************************************************
 *
 * @file dis.h
 *
 * @brief Atmosic Google Fast Pair Device Information Service (DIS)
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize GFP DIS service
 * @param fw_version Firmware version string to be used by the DIS service.
 * @return 0 if successful, negative error code otherwise
 */
__NONNULL_ALL
int gfp_dis_init(const char *fw_version);

#ifdef __cplusplus
}
#endif
