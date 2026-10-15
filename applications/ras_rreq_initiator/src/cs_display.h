/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <zephyr/autoconf.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize the I2C GME OLED display and its character
 * framebuffer. Call once at startup, before cs_display_show_distance() is
 * used. If the display device is not ready, subsequent
 * cs_display_show_distance() calls are silently ignored.
 */
void cs_display_init(void);

/**
 * @brief Render the smoothed CS distance on the OLED display.
 *
 * @param smoothed_distance_m Already-formatted distance string in metres
 * with one fractional digit (e.g. "1.2"), produced by fmt_m_1dp() in
 * cs_distance.c alongside the full-precision UART log line.
 */
void cs_display_show_distance(const char *smoothed_distance_m);

#ifdef __cplusplus
}
#endif
