/* main.c - Application main entry point */

/*
 * Copyright (c) 2015-2016 Intel Corporation
 * Copyright (c) 2024-2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/bluetooth/bluetooth.h>

#if CONFIG_SOFT_OFF
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#include "power.h"
#endif

#if CONFIG_ATM_TEST_UTIL
#include "atm_test_common.h"
#endif

#if CONFIG_ADV_DATA_BCN201
#define SHORT_NAME    "A0000c9"
#elif CONFIG_ADV_DATA_SIMPLE_BCN
#define SHORT_NAME    "Atmosic"
#endif

#if CONFIG_SCAN_RESP_DATA_BCN201
#define COMPLETE_NAME "ATMxxxx Lowest - Power"
#elif CONFIG_SCAN_RESP_DATA_SIMPLE_BCN
#define COMPLETE_NAME "Atmosic Beacon"
#endif

static struct bt_data const ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, CONFIG_ADV_DISC),
#if CONFIG_ADV_DATA_BCN201 || CONFIG_ADV_DATA_SIMPLE_BCN
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, 0xaa, 0xfe),
	BT_DATA_BYTES(BT_DATA_SVC_DATA16, 0xaa, 0xfe,     /* Eddystone ID */
		0x10,                                     /* Frame type: URL */
		0x00,                                     /* Power */
		0x01,                                     /* http://www. */
		'a', 't', 'm', 'o', 's', 'i', 'c', 0x07), /* .com */
	BT_DATA(BT_DATA_NAME_SHORTENED, SHORT_NAME, sizeof(SHORT_NAME) - 1)
#endif
};

static struct bt_data const sd[] = {
#if CONFIG_SCAN_RESP_DATA_BCN201 || CONFIG_SCAN_RESP_DATA_SIMPLE_BCN
	BT_DATA(BT_DATA_NAME_COMPLETE, COMPLETE_NAME, sizeof(COMPLETE_NAME) - 1),
#endif
};

struct bt_le_ext_adv_start_param const ext_adv_start_param = {
	.timeout = CONFIG_ADV_TOUT,
	.num_events = CONFIG_ADV_MAX_EVT,
};

static struct bt_le_ext_adv *adv_set = NULL;

static void restart_adv(struct k_work *work)
{
	/* only happen when SOFT_OFF is not enabled */
	bt_le_ext_adv_start(adv_set, &ext_adv_start_param);
}

static void adv_sent_cb(struct bt_le_ext_adv *adv, struct bt_le_ext_adv_sent_info *info)
{

#if CONFIG_SOFT_OFF
#ifndef CONFIG_SOFT_OFF_SUBID
#define CONFIG_SOFT_OFF_SUBID PM_ALL_SUBSTATES
#endif
	if (pm_policy_state_lock_is_active(PM_STATE_SOFT_OFF, CONFIG_SOFT_OFF_SUBID)) {
		pm_policy_state_lock_put(PM_STATE_SOFT_OFF, CONFIG_SOFT_OFF_SUBID);
	}
#endif
	if (CONFIG_ADV_RSTRT_DUR) {
		static struct k_work_delayable work;
		k_work_init_delayable(&work, restart_adv);
		k_work_schedule(&work, K_SECONDS(CONFIG_ADV_RSTRT_DUR));
	}
#if CONFIG_AUTO_TEST
	printk("CONFIG_ADV_RSTRT_DUR = %d\n", CONFIG_ADV_RSTRT_DUR);
	if (!CONFIG_ADV_RSTRT_DUR) {
	    ATM_TEST_PASSED();
	}
#endif
}

static struct bt_le_ext_adv_cb adv_cbs = {
	.sent = adv_sent_cb,
};

static void bt_ready(int err)
{
	if (err) {
		printk("Bluetooth init failed (err %d)\n", err);
		return;
	}

	uint32_t CONFIG_ADV_OPTS = (0
#ifdef CONFIG_ADV_OPTS_CONN
		| BT_LE_ADV_OPT_CONN
#endif
#ifdef CONFIG_ADV_OPTS_USE_IDENTITY
		| BT_LE_ADV_OPT_USE_IDENTITY
#endif
#ifdef CONFIG_ADV_OPTS_DIR_MODE_LOW_DUTY
		| BT_LE_ADV_OPT_DIR_MODE_LOW_DUTY
#endif
#ifdef CONFIG_ADV_OPTS_DIR_ADDR_RPA
		| BT_LE_ADV_OPT_DIR_ADDR_RPA
#endif
#ifdef CONFIG_ADV_OPTS_FILTER_SCAN_REQ
		| BT_LE_ADV_OPT_FILTER_SCAN_REQ
#endif
#ifdef CONFIG_ADV_OPTS_FILTER_CONN
		| BT_LE_ADV_OPT_FILTER_CONN
#endif
#ifdef CONFIG_ADV_OPTS_NOTIFY_SCAN_REQ
		| BT_LE_ADV_OPT_NOTIFY_SCAN_REQ
#endif
#ifdef CONFIG_ADV_OPTS_SCANNABLE
		| BT_LE_ADV_OPT_SCANNABLE
#endif
#ifdef CONFIG_ADV_OPTS_EXT_ADV
		| BT_LE_ADV_OPT_EXT_ADV
#endif
#ifdef CONFIG_ADV_OPTS_NO_2M
		| BT_LE_ADV_OPT_NO_2M
#endif
#ifdef CONFIG_ADV_OPTS_CODED
		| BT_LE_ADV_OPT_CODED
#endif
#ifdef CONFIG_ADV_OPTS_ANONYMOUS
		| BT_LE_ADV_OPT_ANONYMOUS
#endif
#ifdef CONFIG_ADV_OPTS_USE_TX_POWER
		| BT_LE_ADV_OPT_USE_TX_POWER
#endif
#ifdef CONFIG_ADV_OPTS_DISABLE_CHAN_37
		| BT_LE_ADV_OPT_DISABLE_CHAN_37
#endif
#ifdef CONFIG_ADV_OPTS_DISABLE_CHAN_38
		| BT_LE_ADV_OPT_DISABLE_CHAN_38
#endif
#ifdef CONFIG_ADV_OPTS_DISABLE_CHAN_39
		| BT_LE_ADV_OPT_DISABLE_CHAN_39
#endif
#ifdef CONFIG_ADV_OPTS_USE_NRPA
		| BT_LE_ADV_OPT_USE_NRPA
#endif
	);
	printk("CONFIG_ADV_OPTS = %#" PRIx32 "\n", CONFIG_ADV_OPTS);

	/* Start advertising */
	err = bt_le_ext_adv_create(
		BT_LE_ADV_PARAM(CONFIG_ADV_OPTS, CONFIG_ADV_INTV, CONFIG_ADV_INTV, NULL), &adv_cbs,
		&adv_set);

	if (err) {
		printk("Failed to create advertinsing set (err %d)\n", err);
		return;
	}

	err = bt_le_ext_adv_set_data(adv_set, ad, ARRAY_SIZE(ad), sd, ARRAY_SIZE(sd));

	if (err) {
		printk("Failed to set advertising data (err %d)\n", err);
		return;
	}

	err = bt_le_ext_adv_start(adv_set, &ext_adv_start_param);

	if (err) {
		printk("Failed to start advertising (err %d)\n", err);
		return;
	}

	/* print the BT address */
	char addr_s[BT_ADDR_LE_STR_LEN];
	bt_addr_le_t addr = {0};
	size_t count = 1;

	bt_id_get(&addr, &count);
	bt_addr_le_to_str(&addr, addr_s, sizeof(addr_s));

#if CONFIG_ATM_TEST_UTIL
	atm_test_pass_if_socoff();
#endif
}

int main(void)
{
	/* Initialize the Bluetooth Subsystem */
	int err = bt_enable(bt_ready);

	if (err) {
		printk("Bluetooth init failed (err %d)\n", err);
	}

	return err;
}
