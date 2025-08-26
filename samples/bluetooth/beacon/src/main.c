/* main.c - Application main entry point */

/*
 * Copyright (c) 2015-2016 Intel Corporation
 * Copyright (c) 2024-2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/bluetooth/bluetooth.h>
#include "compiler.h"

#if CONFIG_SOFT_OFF
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#include "power.h"
#endif

#if CONFIG_ATM_TEST_UTIL
#include "atm_test_common.h"
#endif

#define SIMPLE_BCN_COMPLETE_NAME "Atmosic Beacon"
#define SIMPLE_BCN_SHORT_NAME    "A0000c9"
#define BCN_201_COMPLETE_NAME    "ATMxxxx Lowest - Power"
#define BCN_201_SHORT_NAME       "Atmosic"

#ifdef CONFIG_REFBCN_SIMPLE_BEACON
static bool using_simple_beacon;
#include <zephyr/drivers/gpio.h>
#include "reset.h"
#if DT_NODE_EXISTS(DT_NODELABEL(button0))
#define BUTTON_1_EXIST
#endif
#if DT_NODE_EXISTS(DT_NODELABEL(led0))
#define LED_1_EXIST
#endif
#endif // CONFIG_REFBCN_SIMPLE_BEACON

#define PMU_NODE DT_NODELABEL(pmu)

#define PMU_BATT_LIION_HARV_ENABLED ((DT_NODE_HAS_PROP(PMU_NODE, batt_type) && (DT_PROP(PMU_NODE, batt_type) == BATT_TYPE_LI_ION)) && (DT_PROP_OR(PMU_NODE, rf_harv, 0) || DT_PROP_OR(PMU_NODE, nonrf_harv, 0)))

#if PMU_BATT_LIION_HARV_ENABLED
#include <zephyr/drivers/retained_mem.h>
#include <zephyr/device.h>

static const struct device *retained_mem_dev = NULL;

/* Memory layout offsets to prevent overlap */
#define RETAINED_MEM_BATT_OFFSET    0
#define RETAINED_MEM_BATT_SIZE      4  /* sizeof(uint32_t) */
#endif

#if PMU_BATT_LIION_HARV_ENABLED
#include "pmu.h"
#include "reset.h"
#include "batt_model.h"
static dev_state_t batt_state;
static uint32_t batt_persistent_data;

#define BATT_PERSIST_TAG 0x1E3C0000
#endif

#if defined(CONFIG_REFBCN_SOCOFF_BEACON) || defined(CONFIG_REFBCN_SIMPLE_BEACON)
static struct bt_data const simple_bcn_ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, CONFIG_ADV_FLAGS),
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, 0xaa, 0xfe),
	BT_DATA_BYTES(BT_DATA_SVC_DATA16, 0xaa, 0xfe,           /* Eddystone ID */
		      0x10,                                     /* Frame type: URL */
		      0x00,                                     /* Power */
		      0x01,                                     /* http://www. */
		      'a', 't', 'm', 'o', 's', 'i', 'c', 0x07), /* .com */
	BT_DATA(BT_DATA_NAME_SHORTENED, SIMPLE_BCN_SHORT_NAME, sizeof(SIMPLE_BCN_SHORT_NAME) - 1)};

static struct bt_data const simple_bcn_sd[] = {
	BT_DATA(BT_DATA_NAME_COMPLETE, SIMPLE_BCN_COMPLETE_NAME,
		sizeof(SIMPLE_BCN_COMPLETE_NAME) - 1),
};
#endif

#ifdef CONFIG_REFBCN_POWER_PROFILE
static struct bt_data const bcn_201_ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, CONFIG_ADV_FLAGS),
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, 0xaa, 0xfe),
	BT_DATA_BYTES(BT_DATA_SVC_DATA16, 0xaa, 0xfe,           /* Eddystone ID */
		      0x10,                                     /* Frame type: URL */
		      0x00,                                     /* Power */
		      0x01,                                     /* http://www. */
		      'a', 't', 'm', 'o', 's', 'i', 'c', 0x07), /* .com */
	BT_DATA(BT_DATA_NAME_SHORTENED, BCN_201_SHORT_NAME, sizeof(BCN_201_SHORT_NAME) - 1)};

static struct bt_data const bcn_201_sd[] = {
	BT_DATA(BT_DATA_NAME_COMPLETE, BCN_201_COMPLETE_NAME, sizeof(BCN_201_COMPLETE_NAME) - 1),
};
#endif

#ifdef CONFIG_REFBCN_SIMPLE_BEACON
static struct bt_le_ext_adv_start_param const indefinite;
#endif
static struct bt_le_ext_adv_start_param const ext_adv_start_param = {
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
	if (CONFIG_ADV_RSTRT_DUR_MS) {
		static struct k_work_delayable work;
		k_work_init_delayable(&work, restart_adv);
		k_work_schedule(&work, K_MSEC(CONFIG_ADV_RSTRT_DUR_MS));
	}
#if CONFIG_AUTO_TEST
	if (!CONFIG_ADV_RSTRT_DUR_MS) {
	    ATM_TEST_PASSED();
	}
#endif
}

static struct bt_le_ext_adv_cb adv_cbs = {
	.sent = adv_sent_cb,
};

static int get_ad_sd(const struct bt_data **ad, const struct bt_data **sd, size_t *ad_len,
		     size_t *sd_len)
{
#ifdef CONFIG_REFBCN_SIMPLE_BEACON
	if (using_simple_beacon) {
		*ad = simple_bcn_ad;
		*sd = simple_bcn_sd;
		*ad_len = ARRAY_SIZE(simple_bcn_ad);
		*sd_len = ARRAY_SIZE(simple_bcn_sd);
		return 0;
	}
#endif
#ifdef CONFIG_REFBCN_POWER_PROFILE
	*ad = bcn_201_ad;
	*sd = bcn_201_sd;
	*ad_len = ARRAY_SIZE(bcn_201_ad);
	*sd_len = ARRAY_SIZE(bcn_201_sd);
#elif defined(CONFIG_REFBCN_SOCOFF_BEACON)
	*ad = simple_bcn_ad;
	*sd = simple_bcn_sd;
	*ad_len = ARRAY_SIZE(simple_bcn_ad);
	*sd_len = ARRAY_SIZE(simple_bcn_sd);
#else
	return -EINVAL;
#endif
	return 0;
}

static int get_start_param(struct bt_le_ext_adv_start_param const **st_param)
{
#ifdef CONFIG_REFBCN_SIMPLE_BEACON
	if (using_simple_beacon) {
		*st_param = &indefinite;
		return 0;
	}
#endif
	*st_param = &ext_adv_start_param;
	return 0;
}

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

	uint16_t adv_intv = CONFIG_ADV_INTV;

#ifdef CONFIG_REFBCN_SIMPLE_BEACON
	if (using_simple_beacon) {
		CONFIG_ADV_OPTS = BT_LE_ADV_OPT_USE_IDENTITY | BT_LE_ADV_OPT_SCANNABLE;
		adv_intv = BT_GAP_MS_TO_ADV_INTERVAL(CONFIG_REFBCN_SIMPLE_BEACON_INTV);
	}
#endif
	printk("CONFIG_ADV_OPTS = %#" PRIx32 "\n", CONFIG_ADV_OPTS);
	printk("CONFIG_ADV_FLAGS = %#" PRIx32 "\n", CONFIG_ADV_FLAGS);

	/* Start advertising */
	err = bt_le_ext_adv_create(BT_LE_ADV_PARAM(CONFIG_ADV_OPTS, adv_intv, adv_intv, NULL),
				   &adv_cbs, &adv_set);

	if (err) {
		printk("Failed to create advertising set (err %d)\n", err);
		return;
	}

	const struct bt_data *ad;
	const struct bt_data *sd;
	size_t ad_len;
	size_t sd_len;

	err = get_ad_sd(&ad, &sd, &ad_len, &sd_len);
	if (err) {
		printk("Failed to get advertising data (err %d)\n", err);
		return;
	}

	err = bt_le_ext_adv_set_data(adv_set, ad, ad_len, sd, sd_len);

	if (err) {
		printk("Failed to set advertising data (err %d)\n", err);
		return;
	}

	struct bt_le_ext_adv_start_param const *st_param;

	err = get_start_param(&st_param);
	if (err) {
		printk("Failed to get start parameter(err %d)\n", err);
		return;
	}

	err = bt_le_ext_adv_start(adv_set, st_param);

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

static void print_profile(void)
{
#ifdef CONFIG_REFBCN_SIMPLE_BEACON
	if (using_simple_beacon) {
		printk("<Simple Beacon Profile>\n");
		return;
	}
#endif
#ifdef CONFIG_REFBCN_POWER_PROFILE
	printk("<Power Profile>\n");
#elif defined(CONFIG_REFBCN_SOCOFF_BEACON)
	printk("<Socoff Beacon Profile>\n");
#endif
}

#if defined(CONFIG_REFBCN_SIMPLE_BEACON) && defined(LED_1_EXIST) && defined(CONFIG_PM)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(DT_NODELABEL(led0), gpios);
/*
 * For better visuals, we do not want too frequent LED toggles
 */
static int led_toggle_count;
#define LED_TOGGLE_SKIP_COUNT 30
static void notify_pm_state_exit(enum pm_state state)
{
	if (state == PM_STATE_SUSPEND_TO_RAM &&
			++led_toggle_count >= LED_TOGGLE_SKIP_COUNT) {
		gpio_pin_toggle_dt(&led);
		led_toggle_count = 0;
	}
}
#endif

#if PMU_BATT_LIION_HARV_ENABLED
static void batt_sample_cb(uint16_t lvl, int32_t mvolt)
{
	printk("Battery: Level(%u) mVolt(%d)\n", lvl, mvolt);
}

static void batt_flag_set(uint8_t idx, bool value)
{
	ASSERT_INFO(idx < 16, idx, 16);

	int ret = retained_mem_read(retained_mem_dev, RETAINED_MEM_BATT_OFFSET,
		(uint8_t *)&batt_persistent_data, sizeof(batt_persistent_data));
	if (ret) {
		printk("Failed to restore data from the retained memory");
		return;
	}
	printk("Battery flag set: %u %u\n", idx, value);
	if ((batt_persistent_data & 0xFFFF0000) != BATT_PERSIST_TAG) {
		batt_persistent_data = BATT_PERSIST_TAG;
	}
	if (value) {
		batt_persistent_data |= (1 << idx);
	} else {
		batt_persistent_data &= ~(1 << idx);
	}
	ret = retained_mem_write(retained_mem_dev, RETAINED_MEM_BATT_OFFSET,
		(uint8_t *)&batt_persistent_data, sizeof(batt_persistent_data));
	if (ret) {
		printk("Failed to save data to the retained memory");
	}
}

static bool batt_flag_get(uint8_t idx)
{
	bool flag;
	ASSERT_INFO(idx < 16, idx, 16);

	int ret = retained_mem_read(retained_mem_dev, RETAINED_MEM_BATT_OFFSET,
		(uint8_t *)&batt_persistent_data, sizeof(batt_persistent_data));
	if (ret) {
		printk("Failed to restore data from the retained memory");
		return false;
	}
	if ((batt_persistent_data & 0xFFFF0000) != BATT_PERSIST_TAG) {
		batt_persistent_data = BATT_PERSIST_TAG;
	}
	flag = !!(batt_persistent_data & (1 << idx));
	ret = retained_mem_write(retained_mem_dev, RETAINED_MEM_BATT_OFFSET,
		(uint8_t *)&batt_persistent_data, sizeof(batt_persistent_data));
	if (ret) {
		printk("Failed to save data to the retained memory");
	}
	printk("Battery flag get: %u %u %u\n", idx, flag, batt_persistent_data);

	return flag;
}

static void batt_state_set(dev_state_t state)
{
	printk("Battery state set: %u\n", state);
	batt_state = state;
}

static dev_state_t batt_state_get(void)
{
	printk("Battery state get: %u\n", batt_state);
	return batt_state;
}
#endif

int main(void)
{
#if PMU_BATT_LIION_HARV_ENABLED
	retained_mem_dev = DEVICE_DT_GET(DT_NODELABEL(retained_mem_hib));
	if (!device_is_ready(retained_mem_dev)) {
		printk("Retained memory device not ready");
		return -ENODEV;
	}
#endif

#ifdef CONFIG_REFBCN_SIMPLE_BEACON
	using_simple_beacon = is_boot_type(TYPE_POWER_ON);
#ifdef BUTTON_1_EXIST
	static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(DT_NODELABEL(button0), gpios);
	int ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
	if (ret) {
		printk("button err:%d", ret);
		return ret;
	}
	if (using_simple_beacon && gpio_pin_get_dt(&button)) {
		using_simple_beacon = false;
	}
#endif
#if defined(LED_1_EXIST) && defined(CONFIG_PM)
	else if (using_simple_beacon) {
		ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE);
		if (ret) {
		    printk("led err:%d", ret);
		    return ret;
		}
		static struct pm_notifier notifier = {
			.state_exit = notify_pm_state_exit,
		};
		pm_notifier_register(&notifier);
	}
#endif
#endif // CONFIG_REFBCN_SIMPLE_BEACON
	print_profile();

#if PMU_BATT_LIION_HARV_ENABLED
	batt_state = is_boot_type(TYPE_SOCOFF) ? DEV_SOCOFF :
		((is_boot_type(TYPE_RESET) || is_boot_type(TYPE_POWER_ON)) ?
		DEV_RESET : DEV_HIB);

	static batt_cbs const cbs = {
		.state = {
			.get = batt_state_get,
			.set = batt_state_set,
		},
		.flag = {
			.set = batt_flag_set,
			.get = batt_flag_get,
		},
	};

	batt_model()->init(&cbs);
	if (!batt_model()->sample(batt_sample_cb)) {
		printk("Battery monitoring failed\n");
	}
#endif

#if CONFIG_AUTO_TEST
	printk("Interval: %d Ms, Max events: %d\n", (CONFIG_ADV_INTV * 625) / 1000, CONFIG_ADV_MAX_EVT);
	printk("Low power:");
#ifdef CONFIG_SOFT_OFF
	printk(" %s", CONFIG_SOFT_OFF_SUBID ? "socoff" : "hib");
#else
	printk(" ret");
#endif
	printk(", Restart: %d ms\n", CONFIG_ADV_RSTRT_DUR_MS);
#endif
	/* Initialize the Bluetooth Subsystem */
	int err = bt_enable(bt_ready);

	if (err) {
		printk("Bluetooth init failed (err %d)\n", err);
	}

	return err;
}
