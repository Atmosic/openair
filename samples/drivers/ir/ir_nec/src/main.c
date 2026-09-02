/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/ir_nec.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(ir_nec_sample, LOG_LEVEL_INF);

#define IR_NODE DT_NODELABEL(ir_blaster)

BUILD_ASSERT(DT_NODE_EXISTS(IR_NODE), "ir_blaster node missing from overlay");

/*
 * Example NEC remote codes.  Any 8-bit address/command pair is valid;
 * these happen to match a common TV remote layout.
 */
#define TV_ADDR    0x04
#define CMD_POWER  0x08
#define CMD_VOL_UP 0x02
#define CMD_VOL_DN 0x03

static const struct device *ir_dev = DEVICE_DT_GET(IR_NODE);
static struct k_sem tx_sem;

static void tx_done_cb(void)
{
	k_sem_give(&tx_sem);
}

/* Send one NEC frame and block until transmission completes. */
static int ir_send_wait(uint8_t addr, uint8_t cmd, const char *label)
{
	int ret = ir_nec_send(ir_dev, addr, cmd, tx_done_cb);

	if (ret) {
		LOG_ERR("ir_nec_send %s failed: %d", label, ret);
		return ret;
	}
	LOG_INF("Sending %-8s  addr=0x%02x  cmd=0x%02x", label, addr, cmd);
	k_sem_take(&tx_sem, K_FOREVER);
	return 0;
}

int main(void)
{
	LOG_INF("Atmosic NEC IR Blaster Sample");

	if (!device_is_ready(ir_dev)) {
		LOG_ERR("IR device not ready");
		return -ENODEV;
	}

	k_sem_init(&tx_sem, 0, 1);

	/* Send POWER — typical NEC frame takes ~67 ms on the wire. */
	if (ir_send_wait(TV_ADDR, CMD_POWER, "POWER") < 0) {
		return -EIO;
	}

	/* NEC protocol requires at least 40 ms between distinct commands. */
	k_sleep(K_MSEC(40));

	/* Send VOL_UP three times with the standard 110 ms repeat interval. */
	for (int i = 0; i < 3; i++) {
		if (ir_send_wait(TV_ADDR, CMD_VOL_UP, "VOL_UP") < 0) {
			return -EIO;
		}
		k_sleep(K_MSEC(110));
	}

	k_sleep(K_MSEC(40));

	if (ir_send_wait(TV_ADDR, CMD_VOL_DN, "VOL_DN") < 0) {
		return -EIO;
	}

	LOG_INF("IR NEC sample complete");
	return 0;
}
