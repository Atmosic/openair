/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include "cs_display.h"

#include <stdio.h>
#include <string.h>

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/display.h>
#include <zephyr/display/cfb.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(cs_display, CONFIG_RREQ_LOG_LEVEL);

#define CS_DISPLAY_TITLE     "Atmosic"
#define CS_DISPLAY_BAND_ROWS 16
#define CS_DISPLAY_MAX_COLS  6

static const struct device *const display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
static bool display_ready;
static uint16_t disp_w;
static uint16_t disp_h;
static uint8_t title_font;
static uint8_t title_fw;
static uint8_t title_fh;
static uint8_t value_font;
static uint8_t value_fw;
static uint8_t value_fh;

/* Largest built-in font whose `cols` characters still fit `max_h` rows. */
static uint8_t cs_display_pick_font(size_t cols, uint8_t max_h, uint8_t *out_w, uint8_t *out_h)
{
	uint8_t best = 0;
	uint8_t fw;
	uint8_t fh;

	*out_w = 0;
	*out_h = 0;
	for (uint8_t idx = 0; cfb_get_font_size(display_dev, idx, &fw, &fh) == 0; idx++) {
		if (((size_t)fw * cols <= disp_w) && (fh <= max_h)) {
			best = idx;
			*out_w = fw;
			*out_h = fh;
		}
	}
	if (!*out_w) {
		/* Nothing fits the budget; fall back to the smallest font. */
		cfb_get_font_size(display_dev, 0, out_w, out_h);
	}
	return best;
}

/* Horizontally centre one line of text on the given top row. */
static void cs_display_print_centered(const char *s, uint8_t fw, int y)
{
	int x = ((int)disp_w - (int)(fw * strlen(s))) / 2;

	cfb_print(display_dev, s, MAX(x, 0), y);
}

void cs_display_init(void)
{
	if (!device_is_ready(display_dev)) {
		LOG_ERR("Display device %s not ready", display_dev->name);
		return;
	}

	if (display_set_pixel_format(display_dev, PIXEL_FORMAT_MONO10) != 0 &&
	    display_set_pixel_format(display_dev, PIXEL_FORMAT_MONO01) != 0) {
		LOG_ERR("Failed to set display pixel format");
		return;
	}

	if (cfb_framebuffer_init(display_dev)) {
		LOG_ERR("Framebuffer initialization failed");
		return;
	}

	cfb_framebuffer_clear(display_dev, true);
	display_blanking_off(display_dev);

	disp_w = cfb_get_display_parameter(display_dev, CFB_DISPLAY_WIDTH);
	disp_h = cfb_get_display_parameter(display_dev, CFB_DISPLAY_HEIGHT);

	title_font = cs_display_pick_font(strlen(CS_DISPLAY_TITLE), CS_DISPLAY_BAND_ROWS, &title_fw,
					  &title_fh);
	value_font =
		cs_display_pick_font(CS_DISPLAY_MAX_COLS, (uint8_t)(disp_h - CS_DISPLAY_BAND_ROWS),
				     &value_fw, &value_fh);

	LOG_INF("Display %ux%u title font %u (%ux%u) value font %u (%ux%u)", disp_w, disp_h,
		title_font, title_fw, title_fh, value_font, value_fw, value_fh);

	display_ready = true;
}

void cs_display_show_distance(const char *smoothed_distance_m)
{
	char line[24];

	if (!display_ready) {
		return;
	}

	/* smoothed_distance_m is already formatted to one fractional digit
	 * (e.g. "1.2" or "nan") by fmt_m_1dp() in cs_distance.c, so it only
	 * needs the unit suffix appended here. */
	snprintf(line, sizeof(line), "%s m", smoothed_distance_m);

	/* Each line centred within its own colour band so neither straddles the
	 * yellow/blue boundary at CS_DISPLAY_BAND_ROWS. */
	int title_y = ((int)CS_DISPLAY_BAND_ROWS - (int)title_fh) / 2;
	int value_y =
		CS_DISPLAY_BAND_ROWS + ((int)disp_h - CS_DISPLAY_BAND_ROWS - (int)value_fh) / 2;

	cfb_framebuffer_clear(display_dev, false);
	cfb_framebuffer_set_font(display_dev, title_font);
	cs_display_print_centered(CS_DISPLAY_TITLE, title_fw, MAX(title_y, 0));
	cfb_framebuffer_set_font(display_dev, value_font);
	cs_display_print_centered(line, value_fw, MAX(value_y, CS_DISPLAY_BAND_ROWS));
	cfb_framebuffer_finalize(display_dev);
}
