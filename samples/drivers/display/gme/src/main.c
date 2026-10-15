/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/*
 * Print a centered text string on a GME OLED using the
 * Zephyr character framebuffer (CFB).
 */
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/display.h>
#include <zephyr/display/cfb.h>
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(oled_text, LOG_LEVEL_INF);

#define TEXT "Atmosic"

int main(void)
{
	const struct device *dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
	const size_t text_len = strlen(TEXT);
	uint16_t x_res, y_res;
	uint8_t fw, fh;

	if (!device_is_ready(dev)) {
		LOG_ERR("Display device not ready");
		return 0;
	}

	if (display_blanking_off(dev)) {
		LOG_ERR("Failed to turn off display blanking");
		return 0;
	}

	if (cfb_framebuffer_init(dev)) {
		LOG_ERR("Framebuffer initialization failed");
		return 0;
	}

	x_res = cfb_get_display_parameter(dev, CFB_DISPLAY_WIDTH);
	y_res = cfb_get_display_parameter(dev, CFB_DISPLAY_HEIGHT);

	/* Pick the largest built-in font whose rendered text still fits. */
	int font = 0;

	for (int idx = 0; cfb_get_font_size(dev, idx, &fw, &fh) == 0; idx++) {
		if (fw * text_len <= x_res && fh <= y_res) {
			font = idx;
		}
	}
	cfb_framebuffer_set_font(dev, font);
	cfb_get_font_size(dev, font, &fw, &fh);

	int x = ((int)x_res - (int)(fw * text_len)) / 2;
	int y = ((int)y_res - (int)fh) / 2;

	x = MAX(x, 0);
	y = MAX(y, 0);

	cfb_framebuffer_clear(dev, true);
	if (cfb_print(dev, TEXT, x, y)) {
		LOG_ERR("Failed to print text");
		return 0;
	}

	if (cfb_framebuffer_finalize(dev)) {
		LOG_ERR("Failed to update display");
		return 0;
	}

	LOG_INF("Displayed \"%s\" using font %d (%ux%u) at (%d,%d)", TEXT, font, fw, fh, x, y);

	return 0;
}
