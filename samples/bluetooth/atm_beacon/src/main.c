/* main.c - Application main entry point */

/*
 * Copyright (c) 2015-2016 Intel Corporation
 * Copyright (c) 2024-2026 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/logging/log.h>
#include "compiler.h"

LOG_MODULE_REGISTER(beacon, CONFIG_ATM_BEACON_LOG_LEVEL);

#ifdef CONFIG_PM
#include <zephyr/pm/pm.h>
#endif

#ifdef CONFIG_SOFT_OFF
#include <zephyr/pm/policy.h>
#include "power.h"
#endif
#if CONFIG_ATM_TEST_UTIL
#include "atm_test_common.h"
#endif

#ifdef CONFIG_REFBCN_WURX_BEACON
#include "reset.h"
#endif
#ifdef CONFIG_WURX
#include "wurx.h"
#endif

#ifdef CONFIG_REFBCN_SIMPLE_BEACON
static bool using_simple_beacon;
#include <zephyr/drivers/gpio.h>
#include "reset.h"
#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(button0))
#define BUTTON_1_EXIST
#endif
#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(led0))
#define LED_1_EXIST
#endif
#endif // CONFIG_REFBCN_SIMPLE_BEACON

#define PMU_NODE DT_NODELABEL(pmu)

#define PMU_BATT_LIION_HARV_ENABLED ((DT_NODE_HAS_PROP(PMU_NODE, batt_type) && (DT_PROP(PMU_NODE, batt_type) == BATT_TYPE_LI_ION)) && (DT_PROP_OR(PMU_NODE, rf_harv, 0) || DT_PROP_OR(PMU_NODE, nonrf_harv, 0)))

#if PMU_BATT_LIION_HARV_ENABLED
#include <zephyr/drivers/retained_mem.h>
#include <zephyr/device.h>

static const struct device *retained_mem_dev;

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

#if defined(CONFIG_REFBCN_SOCOFF_BEACON) || defined(CONFIG_REFBCN_SIMPLE_BEACON) ||                \
	defined(CONFIG_REFBCN_WURX_BEACON) || defined(CONFIG_REFBCN_SIMPLE_HARV_BEACON)
static struct bt_data const simple_bcn_ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, CONFIG_ADV_FLAGS),
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, 0xaa, 0xfe),
	BT_DATA_BYTES(BT_DATA_SVC_DATA16, 0xaa, 0xfe,           /* Eddystone ID */
		      0x10,                                     /* Frame type: URL */
		      0x00,                                     /* Power */
		      0x01,                                     /* http://www. */
		      'a', 't', 'm', 'o', 's', 'i', 'c', 0x07), /* .com */
	BT_DATA(BT_DATA_NAME_SHORTENED, CONFIG_REFBCN_SIMPLE_BEACON_SHORT_NAME,
		sizeof(CONFIG_REFBCN_SIMPLE_BEACON_SHORT_NAME) - 1)};
#endif

#if defined(CONFIG_REFBCN_SOCOFF_BEACON) || defined(CONFIG_REFBCN_SIMPLE_BEACON) ||                \
	defined(CONFIG_REFBCN_WURX_BEACON)
static struct bt_data const simple_bcn_sd[] = {
	BT_DATA(BT_DATA_NAME_COMPLETE, CONFIG_REFBCN_SIMPLE_BEACON_NAME,
		sizeof(CONFIG_REFBCN_SIMPLE_BEACON_NAME) - 1),
};
#endif

#ifdef CONFIG_REFBCN_SIMPLE_HARV_BEACON
static struct bt_data const data_sd[] = {
	BT_DATA(BT_DATA_NAME_COMPLETE, CONFIG_BT_DEVICE_NAME, sizeof(CONFIG_BT_DEVICE_NAME) - 1),
};
#elif defined(CONFIG_REFBCN_POWER_PROFILE)
static struct bt_data const data_ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, CONFIG_ADV_FLAGS),
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, 0xaa, 0xfe),
	BT_DATA_BYTES(BT_DATA_SVC_DATA16, 0xaa, 0xfe,           /* Eddystone ID */
		      0x10,                                     /* Frame type: URL */
		      0x00,                                     /* Power */
		      0x01,                                     /* http://www. */
		      'a', 't', 'm', 'o', 's', 'i', 'c', 0x07), /* .com */
	BT_DATA(BT_DATA_NAME_SHORTENED, CONFIG_REFBCN_SHORT_NAME,
		sizeof(CONFIG_REFBCN_SHORT_NAME) - 1)};

static struct bt_data const data_sd[] = {
	BT_DATA(BT_DATA_NAME_COMPLETE, CONFIG_BT_DEVICE_NAME, sizeof(CONFIG_BT_DEVICE_NAME) - 1),
};
#elif defined(CONFIG_REFBCN_IBEACON)
/*
 * iBeacon advertisement data (non-scannable, no scan response)
 * UUID:  fb0b57a2-8228-44cd-913a-94a122ba1206
 * Major: 1
 * Minor: 2
 */
static struct bt_data const data_ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, CONFIG_ADV_FLAGS),
	BT_DATA_BYTES(BT_DATA_MANUFACTURER_DATA, 0x4c, 0x00, /* Apple Company ID */
		      0x02, 0x15,                            /* iBeacon type and length */
		      0xfb, 0x0b, 0x57, 0xa2,                /* UUID[15..12] */
		      0x82, 0x28,                            /* UUID[11..10] */
		      0x44, 0xcd,                            /* UUID[9..8] */
		      0x91, 0x3a,                            /* UUID[7..6] */
		      0x94, 0xa1, 0x22, 0xba, 0x12, 0x06,    /* UUID[5..0] */
		      0x00, 0x01,                            /* Major */
		      0x00, 0x02,                            /* Minor */
		      CONFIG_REFBCN_IBEACON_RSSI)            /* Calibrated RSSI @ 1m */
};

#elif defined(CONFIG_REFBCN_EXTENDED_SCN) || defined(CONFIG_REFBCN_LR_CODED) ||                    \
	defined(CONFIG_REFBCN_LR500_CODED)
/* Extended scannable beacon - scan response contains flags, name, and Eddystone URL */
static struct bt_data const data_sd[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, CONFIG_ADV_FLAGS),
	BT_DATA(BT_DATA_NAME_COMPLETE, CONFIG_BT_DEVICE_NAME, sizeof(CONFIG_BT_DEVICE_NAME) - 1),
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, 0xaa, 0xfe),
	BT_DATA_BYTES(BT_DATA_SVC_DATA16, 0xaa, 0xfe,           /* Eddystone ID */
		      0x10,                                     /* Frame type: URL */
		      0x00,                                     /* Power */
		      0x01,                                     /* http://www. */
		      'a', 't', 'm', 'o', 's', 'i', 'c', 0x07), /* .com */
};
#elif defined(CONFIG_REFBCN_EXTENDED_ADV) || defined(CONFIG_REFBCN_EXTENDED_CON)
/* Extended advertising/connectable beacon - large Eddystone URL in advertising data */
/* Manufacturer-specific padding data to reach 242 bytes total (0x8b = 139 bytes) */
static uint8_t const mfg_pad[138] = {0};
static struct bt_data const data_ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, CONFIG_ADV_FLAGS),
	BT_DATA(BT_DATA_NAME_COMPLETE, CONFIG_BT_DEVICE_NAME, sizeof(CONFIG_BT_DEVICE_NAME) - 1),
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, 0xaa, 0xfe),
	BT_DATA_BYTES(BT_DATA_SVC_DATA16, 0xaa, 0xfe, /* Eddystone UUID */
		      0x10,                           /* Frame type: URL */
		      0x00,                           /* Power */
		      0x01,                           /* http://www. */
		      'a', 't', 'm', 'o', 's', 'i', 'c', '.', 'c', 'o', 'm', '/', 'w', 'p', '-',
		      'c', 'o', 'n', 't', 'e', 'n', 't', '/', 'u', 'p', 'l', 'o', 'a', 'd', 's',
		      '/', '2', '0', '1', '8', '/', '1', '0', '/', 'D', 'a', 'v', 'i', 'd', '-',
		      'S', 'u', '-', '5', '0', '0', 'x', '5', '0', '0', '-', '3', '0', '0', 'x',
		      '3', '0', '0', '.', 'j', 'p', 'g'),
	/* PAD to 242 bytes with manufacturer-specific data */
	BT_DATA(BT_DATA_MANUFACTURER_DATA, mfg_pad, sizeof(mfg_pad)),
};
#elif defined(CONFIG_REFBCN_2M_SECONDARY)
/*
 * Extended advertising data:
 * - Complete Local Name: "ATMxxxx Lowest - Power"
 * - Service List: Eddystone UUID
 * - Service Data: Eddystone URL with long path
 * - PAD: Manufacturer Specific Data to fill up to 986 bytes total
 *
 * PAD length fields from TDS (data size = length field - 1):
 * - PAD1: 0x8b -> 138 bytes data
 * - PAD2: 0xf7 -> 246 bytes data
 * - PAD3: 0xf7 -> 246 bytes data
 * - PAD4: 0xf7 -> 246 bytes data
 */

/* Eddystone URL service data */
static uint8_t const ext_2m_eddystone_url[] = {
	0xaa, 0xfe,           /* Eddystone ID */
	0x10,                 /* Frame type: URL */
	0x00,                 /* Power */
	0x01,                 /* http://www. */
	/* "atmosic.com/wp-content/uploads/2018/10/David-Su-500x500-300x300.jpg" */
	'a', 't', 'm', 'o', 's', 'i', 'c', '.', 'c', 'o', 'm', '/',
	'w', 'p', '-', 'c', 'o', 'n', 't', 'e', 'n', 't', '/',
	'u', 'p', 'l', 'o', 'a', 'd', 's', '/',
	'2', '0', '1', '8', '/', '1', '0', '/',
	'D', 'a', 'v', 'i', 'd', '-', 'S', 'u', '-',
	'5', '0', '0', 'x', '5', '0', '0', '-',
	'3', '0', '0', 'x', '3', '0', '0', '.', 'j', 'p', 'g',
};

/*
 * PAD data: Manufacturer Specific Data (all zeros)
 *
 * AD structure: [length][type][data...] where data size = length - 1
 */
#define EXT_2M_PAD1_LEN_FIELD   0x8b
#define EXT_2M_PAD234_LEN_FIELD 0xf7

static uint8_t const ext_2m_pad1[EXT_2M_PAD1_LEN_FIELD - 1] = {0};
static uint8_t const ext_2m_pad2[EXT_2M_PAD234_LEN_FIELD - 1] = {0};
static uint8_t const ext_2m_pad3[EXT_2M_PAD234_LEN_FIELD - 1] = {0};
static uint8_t const ext_2m_pad4[EXT_2M_PAD234_LEN_FIELD - 1] = {0};

static struct bt_data const data_ad[] = {
	BT_DATA(BT_DATA_NAME_COMPLETE, CONFIG_BT_DEVICE_NAME, sizeof(CONFIG_BT_DEVICE_NAME) - 1),
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, 0xaa, 0xfe),
	BT_DATA(BT_DATA_SVC_DATA16, ext_2m_eddystone_url, sizeof(ext_2m_eddystone_url)),
	BT_DATA(BT_DATA_MANUFACTURER_DATA, ext_2m_pad1, sizeof(ext_2m_pad1)),
	BT_DATA(BT_DATA_MANUFACTURER_DATA, ext_2m_pad2, sizeof(ext_2m_pad2)),
	BT_DATA(BT_DATA_MANUFACTURER_DATA, ext_2m_pad3, sizeof(ext_2m_pad3)),
	BT_DATA(BT_DATA_MANUFACTURER_DATA, ext_2m_pad4, sizeof(ext_2m_pad4)),
};
#endif

#if defined(CONFIG_ATM_TEST_UTIL)
#if defined(CONFIG_ATM_IS_FOR_SIM)
#define INDEFINITE_NUM_EVENTS 10
#else
#define INDEFINITE_NUM_EVENTS 40
#endif
#else
#define INDEFINITE_NUM_EVENTS 0
#endif

#if defined(CONFIG_REFBCN_SIMPLE_BEACON) || defined(CONFIG_REFBCN_SIMPLE_HARV_BEACON)
static struct bt_le_ext_adv_start_param const indefinite = {
	.num_events = INDEFINITE_NUM_EVENTS,
};
#endif
static struct bt_le_ext_adv_start_param const ext_adv_start_param = {
	.timeout = CONFIG_ADV_TOUT,
	.num_events = CONFIG_ADV_MAX_EVT,
};

static struct bt_le_ext_adv *adv_set;

#ifdef CONFIG_WURX
static const struct device *wurx_dev;
#endif

static void restart_adv(struct k_work *work)
{
	/* only happen when SOFT_OFF is not enabled */
	bt_le_ext_adv_start(adv_set, &ext_adv_start_param);
}

static void adv_sent_cb(struct bt_le_ext_adv *adv, struct bt_le_ext_adv_sent_info *info)
{
#ifdef CONFIG_REFBCN_WURX_BEACON
	LOG_INF("Advertising period complete");
	LOG_INF("Entering hibernation");
	LOG_INF("Waiting for WuRx wake-up signal...");
#endif

#ifdef CONFIG_SOFT_OFF
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
#if CONFIG_ATM_TEST_UTIL
	} else {
		ATM_TEST_PASSED();
#endif
	}
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
#if defined(CONFIG_REFBCN_POWER_PROFILE)
	*ad = data_ad;
	*sd = data_sd;
	*ad_len = ARRAY_SIZE(data_ad);
	*sd_len = ARRAY_SIZE(data_sd);
#elif defined(CONFIG_REFBCN_2M_SECONDARY)
	*ad = data_ad;
	*sd = NULL;
	*ad_len = ARRAY_SIZE(data_ad);
	*sd_len = 0;
#elif defined(CONFIG_REFBCN_SOCOFF_BEACON) || defined(CONFIG_REFBCN_WURX_BEACON)
	*ad = simple_bcn_ad;
	*sd = simple_bcn_sd;
	*ad_len = ARRAY_SIZE(simple_bcn_ad);
	*sd_len = ARRAY_SIZE(simple_bcn_sd);
#elif defined(CONFIG_REFBCN_SIMPLE_HARV_BEACON)
	*ad = simple_bcn_ad;
	*sd = data_sd;
	*ad_len = ARRAY_SIZE(simple_bcn_ad);
	*sd_len = ARRAY_SIZE(data_sd);
#elif defined(CONFIG_REFBCN_EXTENDED_SCN) || defined(CONFIG_REFBCN_LR_CODED) ||                    \
	defined(CONFIG_REFBCN_LR500_CODED)
	/* Extended scannable: no advertising data, only scan response */
	*ad = NULL;
	*sd = data_sd;
	*ad_len = 0;
	*sd_len = ARRAY_SIZE(data_sd);
#elif defined(CONFIG_REFBCN_EXTENDED_ADV) || defined(CONFIG_REFBCN_EXTENDED_CON) ||                \
	defined(CONFIG_REFBCN_IBEACON)
	/* Extended advertising/connectable: advertising data only, no scan response */
	/* iBeacon: non-scannable, no scan response */
	*ad = data_ad;
	*sd = NULL;
	*ad_len = ARRAY_SIZE(data_ad);
	*sd_len = 0;
#else
	return -EINVAL;
#endif
	return 0;
}

static int get_start_param(struct bt_le_ext_adv_start_param const **st_param)
{
#if defined(CONFIG_REFBCN_SIMPLE_HARV_BEACON)
	*st_param = &indefinite;
#elif defined(CONFIG_REFBCN_SIMPLE_BEACON)
	*st_param = using_simple_beacon ? &indefinite : &ext_adv_start_param;
#else
	*st_param = &ext_adv_start_param;
#endif
	return 0;
}

static void bt_ready(int err)
{
	if (err) {
		LOG_ERR("Bluetooth init failed (err %d)", err);
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
#ifdef CONFIG_ADV_OPTS_REQUIRE_S2_CODING
				    | BT_LE_ADV_OPT_REQUIRE_S2_CODING
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
	LOG_INF("CONFIG_ADV_OPTS = %#" PRIx32, CONFIG_ADV_OPTS);
	LOG_INF("CONFIG_ADV_FLAGS = %#" PRIx32, CONFIG_ADV_FLAGS);

	/* Start advertising */
	err = bt_le_ext_adv_create(BT_LE_ADV_PARAM(CONFIG_ADV_OPTS, adv_intv, adv_intv, NULL),
				   &adv_cbs, &adv_set);

	if (err) {
		LOG_ERR("Failed to create advertising set (err %d)", err);
		return;
	}

	const struct bt_data *ad;
	const struct bt_data *sd;
	size_t ad_len;
	size_t sd_len;

	err = get_ad_sd(&ad, &sd, &ad_len, &sd_len);
	if (err) {
		LOG_ERR("Failed to get advertising data (err %d)", err);
		return;
	}

	err = bt_le_ext_adv_set_data(adv_set, ad, ad_len, sd, sd_len);

	if (err) {
		LOG_ERR("Failed to set advertising data (err %d)", err);
		return;
	}

	struct bt_le_ext_adv_start_param const *st_param;

	err = get_start_param(&st_param);
	if (err) {
		LOG_ERR("Failed to get start parameter(err %d)", err);
		return;
	}

	err = bt_le_ext_adv_start(adv_set, st_param);

	if (err) {
		LOG_ERR("Failed to start advertising (err %d)", err);
		return;
	}

	/* print the BT address */
	char addr_s[BT_ADDR_LE_STR_LEN];
	bt_addr_le_t addr = {0};
	size_t count = 1;

	bt_id_get(&addr, &count);
	bt_addr_le_to_str(&addr, addr_s, sizeof(addr_s));

#ifdef CONFIG_REFBCN_WURX_BEACON
	LOG_INF("WURX mode enabled - advertising for %d events before hibernation",
		CONFIG_ADV_MAX_EVT);
#endif
}

static void print_profile(void)
{
#ifdef CONFIG_REFBCN_SIMPLE_BEACON
	if (using_simple_beacon) {
		LOG_INF("<Simple Beacon Profile>");
		return;
	}
#endif
#ifdef CONFIG_REFBCN_POWER_PROFILE
	LOG_INF("<Power Profile>");
#elif defined(CONFIG_REFBCN_SOCOFF_BEACON)
	LOG_INF("<Socoff Beacon Profile>");
#elif defined(CONFIG_REFBCN_WURX_BEACON)
	LOG_INF("<WURX Beacon Profile>");
#elif defined(CONFIG_REFBCN_SIMPLE_HARV_BEACON)
	LOG_INF("<Simple Harvesting Beacon Profile>");
#elif defined(CONFIG_REFBCN_EXTENDED_SCN)
	LOG_INF("<Extended Scannable Beacon Profile>");
#elif defined(CONFIG_REFBCN_IBEACON)
	LOG_INF("<iBeacon Profile>");
#elif defined(CONFIG_REFBCN_EXTENDED_ADV)
	LOG_INF("<Extended Advertising Beacon Profile>");
#elif defined(CONFIG_REFBCN_EXTENDED_CON)
	LOG_INF("<Extended Connectable Beacon Profile>");
#elif defined(CONFIG_REFBCN_LR_CODED)
	LOG_INF("<Long Range Coded PHY Beacon Profile>");
#elif defined(CONFIG_REFBCN_2M_SECONDARY)
	LOG_INF("<2M Secondary Profile>");
#elif defined(CONFIG_REFBCN_LR500_CODED)
	LOG_INF("<Long Range 500kbps Coded PHY Beacon Profile>");
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
static void batt_sample_cb(uint16_t lvl_bp, int32_t mvolt)
{
	LOG_INF("Battery: Level(%u%%) mVolt(%d)", lvl_bp / 100, mvolt);
}

static void batt_flag_set(uint8_t idx, bool value)
{
	ASSERT_INFO(idx < 16, idx, 16);

	int ret = retained_mem_read(retained_mem_dev, RETAINED_MEM_BATT_OFFSET,
		(uint8_t *)&batt_persistent_data, sizeof(batt_persistent_data));
	if (ret) {
		LOG_INF("Failed to restore data from the retained memory");
		return;
	}
	LOG_INF("Battery flag set: %u %u", idx, value);
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
		LOG_ERR("Failed to save data to the retained memory (err %d)", ret);
	}
}

static bool batt_flag_get(uint8_t idx)
{
	bool flag;
	ASSERT_INFO(idx < 16, idx, 16);

	int ret = retained_mem_read(retained_mem_dev, RETAINED_MEM_BATT_OFFSET,
		(uint8_t *)&batt_persistent_data, sizeof(batt_persistent_data));
	if (ret) {
		LOG_ERR("Failed to restore data from the retained memory (err %d)", ret);
		return false;
	}
	if ((batt_persistent_data & 0xFFFF0000) != BATT_PERSIST_TAG) {
		batt_persistent_data = BATT_PERSIST_TAG;
	}
	flag = !!(batt_persistent_data & (1 << idx));
	ret = retained_mem_write(retained_mem_dev, RETAINED_MEM_BATT_OFFSET,
		(uint8_t *)&batt_persistent_data, sizeof(batt_persistent_data));
	if (ret) {
		LOG_ERR("Failed to save data to the retained memory (err %d)", ret);
	}
	LOG_INF("Battery flag get: %u %u %u", idx, flag, batt_persistent_data);

	return flag;
}

static void batt_state_set(dev_state_t state)
{
	LOG_INF("Battery state set: %u", state);
	batt_state = state;
}

static dev_state_t batt_state_get(void)
{
	LOG_INF("Battery state get: %u", batt_state);
	return batt_state;
}
#endif

int main(void)
{
#if PMU_BATT_LIION_HARV_ENABLED
	retained_mem_dev = DEVICE_DT_GET(DT_NODELABEL(retained_mem_hib));
	if (!device_is_ready(retained_mem_dev)) {
		LOG_ERR("Retained memory device not ready");
		return -ENODEV;
	}
#endif

#ifdef CONFIG_REFBCN_SIMPLE_BEACON
	using_simple_beacon = is_boot_type(TYPE_POWER_ON);
#ifdef BUTTON_1_EXIST
	static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(DT_NODELABEL(button0), gpios);
	int ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
	if (ret) {
		LOG_ERR("button error (err %d)", ret);
		return ret;
	}
	if (using_simple_beacon && gpio_pin_get_dt(&button)) {
		using_simple_beacon = false;
	}
#endif
#if defined(LED_1_EXIST) && defined(CONFIG_PM)
	if (using_simple_beacon) {
		int ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE);
		if (ret) {
			LOG_ERR("led error (err %d)", ret);
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
		LOG_ERR("Battery monitoring failed");
	}
#endif

#ifdef CONFIG_SOFT_OFF
#define LOW_POWER_MODE (CONFIG_SOFT_OFF_SUBID ? "socoff" : "hib")
#else
#define LOW_POWER_MODE "ret"
#endif
	LOG_INF("Interval: %d Ms, Max events: %d, Low power: %s, Restart: %d ms",
		(CONFIG_ADV_INTV * 625) / 1000, CONFIG_ADV_MAX_EVT, LOW_POWER_MODE,
		CONFIG_ADV_RSTRT_DUR_MS);

#ifdef CONFIG_WURX
	LOG_INF("Starting Beacon with WURX support: %#x", boot_status());

	/* Get WURX device */
	wurx_dev = DEVICE_DT_GET(DT_NODELABEL(wurx));
	if (!device_is_ready(wurx_dev)) {
		LOG_INF("WuRx device not ready");
		return -ENODEV;
	}

	LOG_INF("WuRx device initialized");
#endif

	/* Initialize the Bluetooth Subsystem */
	int err = bt_enable(bt_ready);

	if (err) {
		LOG_ERR("Bluetooth init failed (err %d)", err);
	}

	return err;
}
