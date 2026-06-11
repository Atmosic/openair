/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include "at_cmd.h"
#include "at_cmd_set.h"
#include "at_cmd_gatt.h"
#include <zephyr/logging/log.h>

#ifdef CONFIG_AT_CMD_SET_EVENTS
#include "app_work_q.h"
#endif

LOG_MODULE_REGISTER(at_cmd_set, CONFIG_AT_CMD_SET_LOG_LEVEL);

#ifdef CONFIG_AT_CMD_SET_EVENTS

/**
 * @brief Event work item structure
 */
struct at_cmd_evt_work_item {
	struct k_work work;
	at_cmd_evt_handler_t handler;
	uint8_t ch;
	uint16_t evt_data_len;
	uint8_t evt_data[CONFIG_AT_CMD_EVT_DATA_MAX_LEN];
};

/**
 * @brief Event work handler
 */
static void at_cmd_evt_work_handler(struct k_work *work)
{
	struct at_cmd_evt_work_item *item = CONTAINER_OF(work, struct at_cmd_evt_work_item, work);

	if (item->handler) {
		item->handler(item->ch, item->evt_data, item->evt_data_len);
	}

	k_free(item);
}

#endif /* CONFIG_AT_CMD_SET_EVENTS */

static at_cmd_ctx_t at_cmd_ctx;
static bool ctx_initialized;

/* Default advertising parameters */
at_cmd_ctx_t *at_cmd_ctx_init(void)
{
	if (ctx_initialized) {
		return &at_cmd_ctx;
	}

	memset(&at_cmd_ctx, 0, sizeof(at_cmd_ctx));

	/* Initialize channel to invalid */
	at_cmd_ctx.ch = AT_CMD_INVALID_CH;

#ifdef CONFIG_AT_CMD_BLEADVENABLE
	/* Initialize default advertising parameters for all instances */
	for (uint8_t i = 0; i < AT_CMD_ADV_MAX_INST; i++) {
		/* Default to fast advertising interval */
		at_cmd_ctx.adv_intv_min[i] = BT_GAP_ADV_FAST_INT_MIN_2;
		at_cmd_ctx.adv_intv_max[i] = BT_GAP_ADV_FAST_INT_MAX_2;
		/* Default duration: 0 = infinite */
		at_cmd_ctx.adv_duration[i] = 0;
	}
#endif

#ifdef CONFIG_AT_CMD_BLESCANFILRSSI
	/* Boot-default RSSI threshold: most permissive. RSSI is the default filter
	 * and is active whenever the MAC filter (AT+BLESCANFILMAC) is off. */
	at_cmd_ctx.scan_rssi_threshold = AT_CMD_SCAN_RSSI_MIN;
#endif

#ifdef CONFIG_AT_CMD_BLEGATTDFTSERVER
	/* Load GATT configuration from Settings (UUIDs, sec_prop) */
	at_cmd_gatt_dft_config_init();
#endif

	ctx_initialized = true;
	LOG_INF("AT command context initialized");

	return &at_cmd_ctx;
}

at_cmd_ctx_t *at_cmd_ctx_get(void)
{
	if (!ctx_initialized) {
		return at_cmd_ctx_init();
	}
	return &at_cmd_ctx;
}

void at_cmd_set_channel(uint8_t ch)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();
	ctx->ch = ch;
}

#ifdef CONFIG_AT_CMD_SET_CALLBACKS

void at_cmd_set_callbacks_register(at_cmd_set_callbacks_t const *callbacks)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();
	ctx->callbacks = *callbacks;
	LOG_INF("AT command set callbacks registered");
}

#endif /* CONFIG_AT_CMD_SET_CALLBACKS */

#ifdef CONFIG_AT_CMD_SET_EVENTS

int at_cmd_evt_submit(at_cmd_evt_handler_t handler, uint8_t ch, void const *evt_data,
		      uint16_t evt_data_len)
{
	struct at_cmd_evt_work_item *item;

	if (!handler) {
		LOG_ERR("Event handler is NULL");
		return -EINVAL;
	}

	if (evt_data_len > CONFIG_AT_CMD_EVT_DATA_MAX_LEN) {
		LOG_ERR("Event data length %d exceeds max %d", evt_data_len,
			CONFIG_AT_CMD_EVT_DATA_MAX_LEN);
		return -EOVERFLOW;
	}

	item = k_malloc(sizeof(*item));
	if (!item) {
		LOG_ERR("Failed to allocate event work item");
		return -ENOMEM;
	}

	item->handler = handler;
	item->ch = ch;
	item->evt_data_len = evt_data_len;

	if (evt_data && evt_data_len) {
		memcpy(item->evt_data, evt_data, evt_data_len);
	}

	k_work_init(&item->work, at_cmd_evt_work_handler);
	atm_work_submit_to_app_work_q(&item->work);

	return 0;
}

#endif /* CONFIG_AT_CMD_SET_EVENTS */
