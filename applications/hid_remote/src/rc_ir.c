/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/ir_nec.h>

#include "rc_ir.h"

LOG_MODULE_REGISTER(rc_ir, CONFIG_HID_REMOTE_LOG_LEVEL);

static const struct device *const ir_dev = DEVICE_DT_GET(DT_NODELABEL(ir_blaster));

void rc_ir_init(void)
{
	if (!device_is_ready(ir_dev)) {
		LOG_WRN("IR blaster not ready");
	}
}

void rc_ir_send(uint16_t addr, uint8_t cmd)
{
	if (!device_is_ready(ir_dev)) {
		return;
	}
	/* If a previous repeat sequence is still finishing (DMA in flight
	 * after rc_ir_stop), force-stop it so the new key press is not
	 * silently dropped with -EBUSY. */
	if (ir_nec_busy(ir_dev)) {
		ir_nec_stop(ir_dev);
		/* Allow fifo_done_cb to clear busy before retrying */
		k_msleep(2);
	}
	int ret = ir_nec_send_repeat(ir_dev, addr, cmd, NULL);
	if (ret && ret != -EBUSY) {
		LOG_WRN("IR send failed: %d", ret);
	}
}

void rc_ir_stop(void)
{
	if (!device_is_ready(ir_dev)) {
		return;
	}
	ir_nec_stop(ir_dev);
}
