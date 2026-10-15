/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/bluetooth/services/ias.h>
#include <zephyr/logging/log.h>

#include "rc_fmp.h"
#include "rc_led.h"

LOG_MODULE_REGISTER(rc_fmp, CONFIG_HID_REMOTE_LOG_LEVEL);

/* ── IAS callbacks ──────────────────────────────────────────────────────── */

static void rc_fmp_no_alert(void)
{
	LOG_INF("FMP: no alert");
	rc_led_set(RC_LED_OFF);
}

static void rc_fmp_mild_alert(void)
{
	LOG_INF("FMP: mild alert");
	rc_led_set(RC_LED_FMP_MILD);
}

static void rc_fmp_high_alert(void)
{
	LOG_INF("FMP: high alert");
	rc_led_set(RC_LED_FMP_HIGH);
}

BT_IAS_CB_DEFINE(rc_fmp_cb) = {
	.no_alert = rc_fmp_no_alert,
	.mild_alert = rc_fmp_mild_alert,
	.high_alert = rc_fmp_high_alert,
};

/* ── Init ───────────────────────────────────────────────────────────────── */

void rc_fmp_init(void)
{
	LOG_INF("FMP init");
}
