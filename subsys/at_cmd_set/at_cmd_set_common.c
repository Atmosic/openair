/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include "at_cmd_set_common.h"
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(at_cmd_set_common, CONFIG_AT_CMD_SET_LOG_LEVEL);

#ifdef CONFIG_AT_CMD_BLEADVENABLE
#ifdef CONFIG_BT_EXT_ADV
static void at_cmd_adv_build_ext_data(at_cmd_ctx_t *ctx, uint8_t idx, struct bt_data ad_data[2],
				      size_t *ad_len, struct bt_data sd_data[1], size_t *sd_len)
{
	*ad_len = 0;
	*sd_len = 0;

	if (ctx->adv_data_len[idx]) {
		ad_data[(*ad_len)++] = (struct bt_data){
			.type = BT_DATA_MANUFACTURER_DATA,
			.data = ctx->adv_data[idx],
			.data_len = ctx->adv_data_len[idx],
		};
	} else {
		ad_data[(*ad_len)++] = (struct bt_data)BT_DATA_BYTES(
			BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR));
	}

	if (ctx->scan_data_len[idx]) {
		sd_data[(*sd_len)++] = (struct bt_data){
			.type = BT_DATA_MANUFACTURER_DATA,
			.data = ctx->scan_data[idx],
			.data_len = ctx->scan_data_len[idx],
		};
	}
}

static void at_cmd_adv_build_ext_param(at_cmd_ctx_t *ctx, uint8_t idx,
				       struct bt_le_adv_param *adv_param)
{
	adv_param->id = ctx->adv_bt_id[idx];
	adv_param->options = BT_LE_ADV_OPT_CONN | BT_LE_ADV_OPT_EXT_ADV;

	uint8_t primary_phy = ctx->adv_primary_phy[idx];

	/* Default to 1M PHY if not set */
	if (!primary_phy) {
		primary_phy = BT_GAP_LE_PHY_1M;
	}

	/* Set PHY options based on primary_phy */
	if (primary_phy == BT_GAP_LE_PHY_CODED) {
		adv_param->options |= BT_LE_ADV_OPT_CODED;
	}

	adv_param->interval_min = ctx->adv_intv_min[idx];
	adv_param->interval_max = ctx->adv_intv_max[idx];
	adv_param->peer = NULL;
}

static void at_cmd_ext_adv_connected(struct bt_le_ext_adv *adv,
				     struct bt_le_ext_adv_connected_info *info)
{
	ARG_UNUSED(info);
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	for (uint8_t idx = 0; idx < CONFIG_BT_MAX_CONN; idx++) {
		if (ctx->adv_set[idx] != adv) {
			continue;
		}
		LOG_INF("Ext Adv Connected on instance %u", idx);
		ctx->adv_enabled[idx] = false;
		return;
	}
}

static const struct bt_le_ext_adv_cb at_cmd_ext_adv_cb = {
	.connected = at_cmd_ext_adv_connected,
};

#ifdef CONFIG_ZTEST
/*
 * Test hook: expose at_cmd_ext_adv_connected so a ZTest can call it directly
 * with a fake bt_le_ext_adv pointer (pointer-equality only, never dereferenced).
 */
void at_cmd_adv_common_test_ext_adv_connected(struct bt_le_ext_adv *adv,
					      struct bt_le_ext_adv_connected_info *info)
{
	at_cmd_ext_adv_connected(adv, info);
}
#endif /* CONFIG_ZTEST */

#else  // CONFIG_BT_EXT_ADV

/* Legacy advertising stops automatically when a peripheral connection is
 * established. Clear the enabled flag so AT+BLEADVENABLE=1 can restart it.
 */
static void at_cmd_adv_legacy_connected(struct bt_conn *conn, uint8_t conn_err)
{
	if (conn_err) {
		return;
	}

	struct bt_conn_info info;

	if (bt_conn_get_info(conn, &info) || (info.role != BT_CONN_ROLE_PERIPHERAL)) {
		return;
	}

	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	for (uint8_t idx = 0; idx < CONFIG_BT_MAX_CONN; idx++) {
		if (!ctx->adv_enabled[idx]) {
			continue;
		}
		LOG_INF("Legacy Adv stopped on instance %u due to connection", idx);
		ctx->adv_enabled[idx] = false;
	}
}

BT_CONN_CB_DEFINE(at_cmd_adv_conn_cb) = {
	.connected = at_cmd_adv_legacy_connected,
};

static void at_cmd_adv_build_legacy_data(at_cmd_ctx_t *ctx, uint8_t idx, struct bt_data ad_data[2],
					 size_t *ad_len, struct bt_data sd_data[1], size_t *sd_len)
{
	*ad_len = 0;
	*sd_len = 0;

	if (ctx->adv_data_len[idx]) {
		ad_data[(*ad_len)++] = (struct bt_data){
			.type = BT_DATA_MANUFACTURER_DATA,
			.data = ctx->adv_data[idx],
			.data_len = ctx->adv_data_len[idx],
		};
	} else {
		ad_data[(*ad_len)++] = (struct bt_data)BT_DATA_BYTES(
			BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR));
	}

	if (ctx->scan_data_len[idx]) {
		sd_data[(*sd_len)++] = (struct bt_data){
			.type = BT_DATA_MANUFACTURER_DATA,
			.data = ctx->scan_data[idx],
			.data_len = ctx->scan_data_len[idx],
		};
	}
}
#endif // CONFIG_BT_EXT_ADV

at_cmd_result_t at_cmd_adv_enable(uint8_t idx, bool enable)
{
	int err;
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	if (idx >= AT_CMD_ADV_MAX_INST) {
		LOG_ERR("Invalid advertising index %u", idx);
		return at_cmd_result_err(AT_ERR_ADV_INVALID_INDEX);
	}

	uint8_t bt_id = ctx->adv_bt_id[idx];

	if (enable) {
		if (ctx->adv_enabled[idx]) {
			LOG_DBG("Already advertising on instance %u", idx);
			return at_cmd_result_ok();
		}

#ifdef CONFIG_BT_EXT_ADV

		struct bt_le_adv_param adv_param;
		at_cmd_adv_build_ext_param(ctx, idx, &adv_param);

		/* Create advertising set if not already created */
		if (!ctx->adv_set[idx]) {
			LOG_INF("bt_le_ext_adv_create: idx=%u bt_id=%u intv=[%u,%u]", idx, bt_id,
				adv_param.interval_min, adv_param.interval_max);
			err = bt_le_ext_adv_create(&adv_param, &at_cmd_ext_adv_cb,
						   &ctx->adv_set[idx]);
			if (err) {
				LOG_ERR("bt_le_ext_adv_create failed (err %d)", err);
				return at_cmd_result_err_from_errno(err);
			}
			LOG_INF("bt_le_ext_adv_create: OK");
		}

		/* Set advertising data */
		struct bt_data ad_data[2];
		size_t ad_len;
		struct bt_data sd_data[1];
		size_t sd_len;

		at_cmd_adv_build_ext_data(ctx, idx, ad_data, &ad_len, sd_data, &sd_len);

		err = bt_le_ext_adv_set_data(ctx->adv_set[idx], ad_data, ad_len, sd_data, sd_len);
		if (err) {
			LOG_ERR("Failed to set adv data (err %d)", err);
			return at_cmd_result_err_from_errno(err);
		}

		/* Start advertising */
		struct bt_le_ext_adv_start_param start_param = {
			.timeout = ctx->adv_duration[idx],
			.num_events = 0,
		};

		err = bt_le_ext_adv_start(ctx->adv_set[idx], &start_param);
		if (err) {
			LOG_ERR("Extended adv failed to start (err %d)", err);
			return at_cmd_result_err_from_errno(err);
		}
#else
		/* Legacy advertising */
		struct bt_le_adv_param adv_param = {
			.id = bt_id,
			.options = BT_LE_ADV_OPT_CONN,
			.interval_min = ctx->adv_intv_min[idx],
			.interval_max = ctx->adv_intv_max[idx],
		};

		struct bt_data ad_data[2];
		size_t ad_len;
		struct bt_data sd_data[1];
		size_t sd_len;

		at_cmd_adv_build_legacy_data(ctx, idx, ad_data, &ad_len, sd_data, &sd_len);

		err = bt_le_adv_start(&adv_param, ad_data, ad_len, sd_data, sd_len);
		if (err) {
			LOG_ERR("Advertising failed to start (err %d)", err);
			return at_cmd_result_err_from_errno(err);
		}
#endif
		ctx->adv_enabled[idx] = true;
		LOG_INF("Advertising started on instance %u, bt_id %u", idx, bt_id);
	} else {
		if (!ctx->adv_enabled[idx]) {
			LOG_DBG("Not advertising on instance %u", idx);
			return at_cmd_result_ok();
		}

#ifdef CONFIG_BT_EXT_ADV
		if (ctx->adv_set[idx]) {
			err = bt_le_ext_adv_stop(ctx->adv_set[idx]);
			if (err) {
				LOG_ERR("Extended adv failed to stop (err %d)", err);
				return at_cmd_result_err_from_errno(err);
			}
		}
#else
		err = bt_le_adv_stop();
		if (err) {
			LOG_ERR("Advertising failed to stop (err %d)", err);
			return at_cmd_result_err_from_errno(err);
		}
#endif
		ctx->adv_enabled[idx] = false;
		LOG_INF("Advertising stopped on instance %u", idx);
	}

	return at_cmd_result_ok();
}

bool at_cmd_adv_is_enabled(void)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();
	/* Return true if any instance is advertising */
	for (uint8_t i = 0; i < AT_CMD_ADV_MAX_INST; i++) {
		if (ctx->adv_enabled[i]) {
			return true;
		}
	}
	return false;
}

at_cmd_result_t at_cmd_adv_update_data(at_cmd_ctx_t *ctx, uint8_t idx)
{
	int err;

	if (!ctx) {
		LOG_ERR("AT command context is NULL");
		return at_cmd_result_err(AT_ERR_CTX_NULL);
	}

	if (idx >= AT_CMD_ADV_MAX_INST) {
		LOG_ERR("Invalid advertising index %u", idx);
		return at_cmd_result_err(AT_ERR_ADV_INVALID_INDEX);
	}

#ifdef CONFIG_BT_EXT_ADV
	if (!ctx->adv_set[idx]) {
		LOG_ERR("Advertising set %u not created", idx);
		return at_cmd_result_err(AT_ERR_ADV_SET_NOT_CREATED);
	}

	struct bt_data ad_data[2];
	size_t ad_len;
	struct bt_data sd_data[1];
	size_t sd_len;

	at_cmd_adv_build_ext_data(ctx, idx, ad_data, &ad_len, sd_data, &sd_len);

	err = bt_le_ext_adv_set_data(ctx->adv_set[idx], ad_data, ad_len, sd_data, sd_len);
	if (err) {
		LOG_ERR("Failed to update adv data on instance %u (err %d)", idx, err);
		return at_cmd_result_err_from_errno(err);
	}
#else
	struct bt_data ad_data[2];
	size_t ad_len;
	struct bt_data sd_data[1];
	size_t sd_len;

	at_cmd_adv_build_legacy_data(ctx, idx, ad_data, &ad_len, sd_data, &sd_len);

	err = bt_le_adv_update_data(ad_data, ad_len, sd_data, sd_len);
	if (err) {
		LOG_ERR("Failed to update adv data on instance %u (err %d)", idx, err);
		return at_cmd_result_err_from_errno(err);
	}
#endif

	return at_cmd_result_ok();
}

#ifdef CONFIG_BT_EXT_ADV
at_cmd_result_t at_cmd_adv_update_param(at_cmd_ctx_t *ctx, uint8_t idx)
{
	if (!ctx) {
		LOG_ERR("AT command context is NULL");
		return at_cmd_result_err(AT_ERR_CTX_NULL);
	}

	if (idx >= AT_CMD_ADV_MAX_INST) {
		LOG_ERR("Invalid advertising index %u", idx);
		return at_cmd_result_err(AT_ERR_ADV_INVALID_INDEX);
	}

	if (!ctx->adv_set[idx]) {
		LOG_ERR("Advertising set %u not created", idx);
		return at_cmd_result_err(AT_ERR_ADV_SET_NOT_CREATED);
	}

	struct bt_le_adv_param adv_param;
	at_cmd_adv_build_ext_param(ctx, idx, &adv_param);

	int err = bt_le_ext_adv_update_param(ctx->adv_set[idx], &adv_param);
	if (err) {
		LOG_ERR("bt_le_ext_adv_update_param failed (err %d)", err);
		return at_cmd_result_err_from_errno(err);
	}
	return at_cmd_result_ok();
}
#endif

at_cmd_result_t at_cmd_adv_restart(int idx)
{
	LOG_DBG("Restarting advertising on instance %d", idx);
	at_cmd_result_t result = at_cmd_adv_enable(idx, false);
	if (result.err) {
		return result;
	}
	return at_cmd_adv_enable(idx, true);
}
#endif // CONFIG_AT_CMD_BLEADVENABLE
