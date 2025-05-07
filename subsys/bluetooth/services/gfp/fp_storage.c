/**
 *******************************************************************************
 *
 * @file fp_storage.c
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Storage Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <zephyr/settings/settings.h>
#include <string.h>
#include "atm_settings.h"
#include "fp_storage.h"
#ifdef CONFIG_FAST_PAIR_FMDN
#include "fp_fmdn.h"
#endif

LOG_MODULE_DECLARE(gfps, CONFIG_ATM_GFPS_LOG_LEVEL);

#define S_KEY_MAIN             SETTINGS_STORAGE_KEY("gfp")
#define SS_KEY_ACNT_KEY_LIST   "account_key_list"
#define SS_KEY_OWNER_KEY       "owner_key"
#define SS_KEY_EID_KEY         "eid_key"
#define SS_KEY_UTP_MODE        "utp_mode"
#define SS_KEY_BT_ID_BASE      "bt_id_base"
#define FP_STORAGE_KEY(subkey) S_KEY_MAIN "/" subkey

#define ACCOUNT_KEY_CNT CONFIG_FAST_PAIR_MAX_ACCOUNT_KEY_COUNT
typedef struct {
	bool in_used;
	uint8_t account_key[FP_ACCOUNT_KEY_LEN];
} fp_account_data_t;

static size_t account_key_count;
static int account_key_list_len;
static uint8_t account_key_list[FP_ACCOUNT_KEY_CNT * FP_ACCOUNT_KEY_LEN];
static fp_account_data_t account_key_data_list[FP_ACCOUNT_KEY_CNT];

#ifdef CONFIG_FAST_PAIR_FMDN
static uint8_t eid_key[FP_EIK_LEN];
static bool eid_key_valid;
static uint8_t cur_account_key[FP_ACCOUNT_KEY_LEN];
static uint8_t owner_key[FP_ACCOUNT_KEY_LEN];
static bool owner_key_valid;
static fp_fmdn_utp_mode_t utp_mode = FP_FMDN_UTP_MODE_OFF;
#endif // CONFIG_FAST_PAIR_FMDN
static uint8_t bt_id_base;
bool fp_storage_init_done;

static void fp_storage_account_key_data_list_update(void)
{
	account_key_count = 0;
	uint8_t offset = 0;
	while (offset < account_key_list_len) {
		memcpy(account_key_data_list[account_key_count].account_key,
		       account_key_list + offset, FP_ACCOUNT_KEY_LEN);
		account_key_data_list[account_key_count].in_used = true;
		account_key_count++;
		offset += FP_ACCOUNT_KEY_LEN;
	}
}

static int settings_storage_handle_set(char const *name, size_t len, settings_read_cb read_cb,
				       void *cb_arg)
{
	char const *next;
	if (settings_name_steq(name, SS_KEY_ACNT_KEY_LIST, &next) && !next) {
		if (len) {
			account_key_list_len = len;
			read_cb(cb_arg, &account_key_list, len);
			return 0;
		}
		return -EINVAL;
	}
#ifdef CONFIG_FAST_PAIR_FMDN
	if (settings_name_steq(name, SS_KEY_OWNER_KEY, &next) && !next) {
		if (len != sizeof(owner_key)) {
			return -EINVAL;
		}
		read_cb(cb_arg, &owner_key, sizeof(owner_key));
		owner_key_valid = true;
		return 0;
	}
	if (settings_name_steq(name, SS_KEY_EID_KEY, &next) && !next) {
		if (len != sizeof(eid_key)) {
			return -EINVAL;
		}
		read_cb(cb_arg, &eid_key, sizeof(eid_key));
		eid_key_valid = true;
		return 0;
	}
	if (settings_name_steq(name, SS_KEY_UTP_MODE, &next) && !next) {
		if (len != sizeof(utp_mode)) {
			return -EINVAL;
		}
		read_cb(cb_arg, &utp_mode, sizeof(utp_mode));
		return 0;
	}
#endif
	if (settings_name_steq(name, SS_KEY_BT_ID_BASE, &next) && !next) {
		if (len != sizeof(bt_id_base)) {
			return -EINVAL;
		}
		read_cb(cb_arg, &bt_id_base, sizeof(bt_id_base));
		return 0;
	}
	return -ENOENT;
}

/* static subtree handler */
SETTINGS_STATIC_HANDLER_DEFINE(settings_storage, S_KEY_MAIN, NULL, settings_storage_handle_set,
			       NULL, NULL);

#ifdef CONFIG_FAST_PAIR_STORAGE_DEBUG_EN
static void fp_storage_show(void)
{
	LOG_INF("account_key_count %u", account_key_count);
	if (account_key_count) {
		LOG_HEXDUMP_INF(account_key_data_list, account_key_count * FP_ACCOUNT_KEY_LEN,
				"account_key_data_list:");
	}
#ifdef CONFIG_FAST_PAIR_FMDN
	if (owner_key_valid) {
		LOG_HEXDUMP_INF(owner_key, sizeof(owner_key), "owner_key:");
	} else {
		LOG_INF("owner_key: invalid");
	}
	if (eid_key_valid) {
		LOG_HEXDUMP_INF(eid_key, sizeof(eid_key), "eid_key:");
	} else {
		LOG_INF("eid_key: invalid");
	}
	LOG_INF("utp_mode: %u", utp_mode);
#endif
	LOG_INF("bt_id_base: %u", bt_id_base);
}
#endif

#ifdef CONFIG_FAST_PAIR_FMDN
int fp_storage_eid_key_save(uint8_t const *eik)
{
	memcpy(eid_key, eik, sizeof(eid_key));
	eid_key_valid = true;
	int err = settings_save_one(FP_STORAGE_KEY(SS_KEY_EID_KEY), (uint8_t *)&eid_key,
				    sizeof(eid_key));
	if (err) {
		LOG_ERR("save eid key failed %d", err);
	}
	return err;
}

int fp_storage_eid_key_delete(void)
{
	if (eid_key_valid) {
		memset(eid_key, 0, sizeof(eid_key));
		eid_key_valid = false;
	}
	int err = settings_delete(FP_STORAGE_KEY(SS_KEY_EID_KEY));
	if (err) {
		LOG_ERR("delete eid key failed (err: %d)", err);
	}
	return err;
}

int fp_storage_eid_key_get(uint8_t *key)
{
	if (!eid_key_valid) {
		return -EALREADY;
	}
	memcpy(key, eid_key, FP_EIK_LEN);
	return 0;
}

bool fp_storage_eid_key_valid(void)
{
	return eid_key_valid;
}

static void fp_storage_utp_mode_delete(void)
{
	utp_mode = FP_FMDN_UTP_MODE_OFF;
	int err = settings_delete(FP_STORAGE_KEY(SS_KEY_UTP_MODE));
	if (err) {
		LOG_ERR("delete utp mode failed (err: %d)", err);
	}
}

void fp_storage_utp_mode_save(fp_fmdn_utp_mode_t mode)
{
	utp_mode = mode;
	int err = settings_save_one(FP_STORAGE_KEY(SS_KEY_UTP_MODE), (uint8_t *)&utp_mode,
				    sizeof(utp_mode));
	if (err) {
		LOG_ERR("save utp mode failed %d", err);
	}
}

uint8_t fp_storage_utp_mode_get(void)
{
	return utp_mode;
}

void fp_storage_cur_account_key_clear(void)
{
	fp_storage_account_key_delete(cur_account_key);
	memset(cur_account_key, 0, FP_ACCOUNT_KEY_LEN);
}

int fp_storage_cur_account_key_get(uint8_t *key)
{
	memcpy(key, cur_account_key, FP_ACCOUNT_KEY_LEN);
	return 0;
}

bool fp_storage_check_is_owner_key(uint8_t const *key)
{
	if (owner_key_valid && !memcmp(owner_key, key, FP_ACCOUNT_KEY_LEN)) {
		return true;
	}
	return false;
}

int fp_storage_owner_key_get(uint8_t *key)
{
	if (!owner_key_valid) {
		return -EALREADY;
	}
	memcpy(key, owner_key, FP_ACCOUNT_KEY_LEN);
	return 0;
}

void fp_storage_owner_key_clear(void)
{
	if (!owner_key_valid) {
		return;
	}
	fp_storage_account_key_delete(owner_key);
}

bool fp_storage_owner_key_valid(void)
{
	return owner_key_valid;
}

static int fp_storage_owner_key_save(uint8_t const *key)
{
	// save account key as owner key if first access
	if (owner_key_valid) {
		LOG_INF("owner key already exist");
		return 0;
	}
	memcpy(owner_key, key, FP_ACCOUNT_KEY_LEN);
	owner_key_valid = true;
	int err = settings_save_one(FP_STORAGE_KEY(SS_KEY_OWNER_KEY), (uint8_t *)&owner_key,
				    sizeof(owner_key));
	if (err) {
		LOG_ERR("save owner key failed %d", err);
	}
	return err;
}

static int fp_storage_owner_key_delete(void)
{
	memset(owner_key, 0, FP_ACCOUNT_KEY_LEN);
	owner_key_valid = false;
	int err = settings_delete(FP_STORAGE_KEY(SS_KEY_OWNER_KEY));
	if (err) {
		LOG_ERR("delete owner key failed (err: %d)", err);
	}
	return err;
}
#endif // CONFIG_FAST_PAIR_FMDN

void fp_storage_bt_id_base_save(uint8_t id)
{
	bt_id_base = id;
	int err = settings_save_one(FP_STORAGE_KEY(SS_KEY_BT_ID_BASE), (uint8_t *)&bt_id_base,
				    sizeof(bt_id_base));
	if (err) {
		LOG_ERR("save bt_id_base failed %d", err);
	}
}

uint8_t fp_storage_bt_id_base_get(void)
{
	return bt_id_base;
}

static void fp_storage_account_key_list_reload(void)
{
	memset(account_key_list, 0, sizeof(account_key_list));
	account_key_count = 0;
	uint8_t offset = 0;
	int err;
	for (uint8_t i = 0; i < ACCOUNT_KEY_CNT; i++) {
		if (account_key_data_list[i].in_used) {
			memcpy(account_key_list + offset, account_key_data_list[i].account_key,
			       FP_ACCOUNT_KEY_LEN);
			offset += FP_ACCOUNT_KEY_LEN;
			account_key_count++;
		}
	}
	if (account_key_count) {
		err = settings_save_one(FP_STORAGE_KEY(SS_KEY_ACNT_KEY_LIST),
					(uint8_t *)&account_key_list,
					account_key_count * FP_ACCOUNT_KEY_LEN);
		if (err) {
			LOG_INF("save account key list failed (err: %d)", err);
		}
	} else {
		err = settings_delete(FP_STORAGE_KEY(SS_KEY_ACNT_KEY_LIST));
		if (err) {
			LOG_ERR("delete account key list failed (err: %d)", err);
		}
	}
}

int fp_storage_account_key_save(uint8_t const *account_key)
{
	bool is_saved = false;
	memcpy(cur_account_key, account_key, FP_ACCOUNT_KEY_LEN);
	fp_storage_owner_key_save(account_key);
	for (uint8_t i = 0; i < FP_ACCOUNT_KEY_CNT; i++) {
		if (account_key_data_list[i].in_used) {
			if (!memcmp(account_key, account_key_data_list[i].account_key,
				    FP_ACCOUNT_KEY_LEN)) {
				LOG_DBG("account key has been exist");
				is_saved = true;
				break;
			}
		}
	}
	if (!is_saved) {
		for (uint8_t i = 0; i < FP_ACCOUNT_KEY_CNT; i++) {
			if (!account_key_data_list[i].in_used) {
				memcpy(account_key_data_list[i].account_key, account_key,
				       FP_ACCOUNT_KEY_LEN);
				account_key_data_list[i].in_used = true;
				break;
			}
		}
	}
	fp_storage_account_key_list_reload();
	return 0;
}

int fp_storage_account_key_delete(uint8_t const *account_key)
{
	for (uint8_t i = 0; i < FP_ACCOUNT_KEY_CNT; i++) {
		if (account_key_data_list[i].in_used) {
			if (!memcmp(account_key_data_list[i].account_key, account_key,
				    FP_ACCOUNT_KEY_LEN)) {
				memset(&account_key_data_list[i], 0, sizeof(fp_account_data_t));
				break;
			}
		}
	}
	fp_storage_account_key_list_reload();
	return 0;
}

int fp_storage_account_key_delete_all(void)
{
	for (uint8_t i = 0; i < ACCOUNT_KEY_CNT; i++) {
		memset(&account_key_data_list[i], 0, sizeof(fp_account_data_t));
	}
#ifdef CONFIG_FAST_PAIR_FMDN
	fp_storage_owner_key_delete();
#endif
	fp_storage_account_key_list_reload();
	return 0;
}

size_t fp_storage_account_key_count_get(void)
{
	return account_key_count;
}

size_t fp_storage_account_key_filter_size(size_t count)
{
	return count ? (1.2 * count + 3) : 0;
}

uint8_t fp_storage_account_key_list_get(uint8_t *key_list)
{
	if (!account_key_count) {
		return 0;
	}
	memcpy(key_list, account_key_list, FP_ACCOUNT_KEY_LEN * account_key_count);
	return (FP_ACCOUNT_KEY_LEN * account_key_count);
}

#ifdef CONFIG_FAST_PAIR_FMDN
void fp_storage_eid_reset(void)
{
	fp_storage_utp_mode_delete();
	fp_storage_eid_key_delete();
}
#endif

void fp_storge_account_key_reset(void)
{
	fp_storage_account_key_delete_all();
}

int fp_storage_reset(void)
{
#ifdef CONFIG_FAST_PAIR_FMDN
	fp_storage_eid_reset();
#endif
	fp_storge_account_key_reset();
#ifdef CONFIG_FAST_PAIR_STORAGE_DEBUG_EN
	fp_storage_show();
#endif
	return 0;
}

int fp_storage_init(void)
{
	if (fp_storage_init_done) {
		return 0;
	}
	settings_load_subtree(S_KEY_MAIN);
	fp_storage_account_key_data_list_update();
	fp_storage_init_done = true;
#ifdef CONFIG_FAST_PAIR_STORAGE_DEBUG_EN
	fp_storage_show();
#endif
	return 0;
}
