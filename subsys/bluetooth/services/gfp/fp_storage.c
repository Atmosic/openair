/**
 *******************************************************************************
 *
 * @file fp_storage.c
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Storage Middleware
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#include <errno.h>
#include <inttypes.h>
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <zephyr/settings/settings.h>
#include <string.h>
#include "atm_settings.h"
#include "fp_storage.h"
#ifdef CONFIG_FAST_PAIR_FMDN
#include "fp_fmdn.h"
#endif
#ifdef CONFIG_FAST_PAIR_ACCOUNT_KEY_FIFO_EVICTION
#include <time.h>
#endif

LOG_MODULE_DECLARE(gfps, CONFIG_ATM_GFPS_LOG_LEVEL);

#define S_KEY_MAIN                  SETTINGS_STORAGE_KEY("gfp")
#define SS_KEY_ACNT_KEY_LIST        "account_key_list"
#define SS_KEY_OWNER_KEY            "owner_key"
#define SS_KEY_EID_KEY              "eid_key"
#define SS_KEY_UTP_MODE             "utp_mode"
#define SS_KEY_UTP_IGNORE_RING_AUTH "utp_ignore_ring_auth"
#define SS_KEY_PERSONALIZED_NAME    "pers_name"
#define SS_KEY_BT_ID_BASE           "bt_id_base"
#define SS_KEY_FMDN_CLOCK           "fmdn_clock"
#define SS_KEY_PC_CLIENT_ID         "pc_client_id"
#define FP_STORAGE_KEY(subkey)      S_KEY_MAIN "/" subkey

#define ACCOUNT_KEY_CNT CONFIG_FAST_PAIR_MAX_ACCOUNT_KEY_COUNT
typedef struct {
	bool in_used;
	uint8_t account_key[FP_ACCOUNT_KEY_LEN];
	uint32_t timestamp; // Timestamp for FIFO eviction (seconds since epoch)
} fp_account_data_t;

static size_t account_key_count;
static int account_key_list_len;
static uint8_t account_key_list[FP_ACCOUNT_KEY_CNT * FP_ACCOUNT_KEY_LEN];
static fp_account_data_t account_key_data_list[FP_ACCOUNT_KEY_CNT];

// Personalized name storage (core Fast Pair feature, not FMDN-specific)
static char personalized_name[FP_PERSONALIZED_NAME_MAX_LEN];
static bool personalized_name_valid;

#ifdef CONFIG_FAST_PAIR_FMDN
static uint8_t eid_key[FP_EIK_LEN];
static bool eid_key_valid;
static uint8_t cur_account_key[FP_ACCOUNT_KEY_LEN];
static uint8_t owner_key[FP_ACCOUNT_KEY_LEN];
static bool owner_key_valid;
static fp_fmdn_utp_mode_t utp_mode = FP_FMDN_UTP_MODE_OFF;
static uint8_t utp_ignore_ring_auth = false;
static uint32_t fmdn_clock_value;
static bool fmdn_clock_valid;
#ifdef CONFIG_FMDN_PERSISTENT_CONNECTION
static uint8_t pc_client_id;
static bool pc_client_id_valid;
#endif // CONFIG_FMDN_PERSISTENT_CONNECTION
#endif // CONFIG_FAST_PAIR_FMDN
static uint8_t bt_id_base;
static bool bt_id_base_valid;
static bool fp_storage_init_done;

static void fp_storage_account_key_data_list_update(void)
{
	account_key_count = 0;
	uint8_t offset = 0;
	while (offset < account_key_list_len) {
		memcpy(account_key_data_list[account_key_count].account_key,
		       account_key_list + offset, FP_ACCOUNT_KEY_LEN);
		account_key_data_list[account_key_count].in_used = true;
#ifdef CONFIG_FAST_PAIR_ACCOUNT_KEY_FIFO_EVICTION
		// Initialize timestamp to current time when loading from NVS
		// This ensures loaded keys have a valid timestamp for FIFO eviction
		account_key_data_list[account_key_count].timestamp = k_uptime_seconds();
		LOG_DBG("Loaded account key %u with timestamp %" PRIu32, account_key_count,
			account_key_data_list[account_key_count].timestamp);
#endif
		account_key_count++;
		offset += FP_ACCOUNT_KEY_LEN;
	}
}

#ifdef CONFIG_FAST_PAIR_ACCOUNT_KEY_FIFO_EVICTION
/**
 * @brief Find the index of the oldest account key by timestamp
 * @return Index of oldest key, or -1 if no keys are in use
 */
static int fp_storage_account_key_find_oldest(void)
{
	int oldest_idx = -1;
	uint32_t oldest_timestamp = UINT32_MAX;

	for (uint8_t i = 0; i < ACCOUNT_KEY_CNT; i++) {
		if (account_key_data_list[i].in_used) {
			if (account_key_data_list[i].timestamp < oldest_timestamp) {
				oldest_timestamp = account_key_data_list[i].timestamp;
				oldest_idx = i;
			}
		}
	}

	return oldest_idx;
}
#endif

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
	if (settings_name_steq(name, SS_KEY_UTP_IGNORE_RING_AUTH, &next) && !next) {
		if (len != sizeof(utp_ignore_ring_auth)) {
			return -EINVAL;
		}
		read_cb(cb_arg, &utp_ignore_ring_auth, sizeof(utp_ignore_ring_auth));
		return 0;
	}
	if (settings_name_steq(name, SS_KEY_FMDN_CLOCK, &next) && !next) {
		if (len != sizeof(fmdn_clock_value)) {
			return -EINVAL;
		}
		read_cb(cb_arg, &fmdn_clock_value, sizeof(fmdn_clock_value));
		fmdn_clock_valid = true;
		LOG_INF("Loaded FMDN clock value: %" PRIu32 " [s]", fmdn_clock_value);
		return 0;
	}
#ifdef CONFIG_FMDN_PERSISTENT_CONNECTION
	if (settings_name_steq(name, SS_KEY_PC_CLIENT_ID, &next) && !next) {
		if (len != sizeof(pc_client_id)) {
			return -EINVAL;
		}
		read_cb(cb_arg, &pc_client_id, sizeof(pc_client_id));
		pc_client_id_valid = true;
		LOG_INF("Loaded PC client ID: %u", pc_client_id);
		return 0;
	}
#endif // CONFIG_FMDN_PERSISTENT_CONNECTION
#endif // CONFIG_FAST_PAIR_FMDN
	if (settings_name_steq(name, SS_KEY_PERSONALIZED_NAME, &next) && !next) {
		if (len >= sizeof(personalized_name)) {
			LOG_ERR("Personalized name too long: %zu >= %zu", len,
				sizeof(personalized_name));
			return -EINVAL;
		}
		read_cb(cb_arg, personalized_name, len);
		personalized_name[len] = '\0'; // Ensure null termination
		personalized_name_valid = true;
		LOG_INF("Loaded personalized name: '%s'", personalized_name);
		return 0;
	}
	if (settings_name_steq(name, SS_KEY_BT_ID_BASE, &next) && !next) {
		if (len != sizeof(bt_id_base)) {
			return -EINVAL;
		}
		read_cb(cb_arg, &bt_id_base, sizeof(bt_id_base));
		bt_id_base_valid = true;
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
	if (personalized_name_valid) {
		LOG_INF("personalized_name: '%s'", personalized_name);
	}
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

void fp_storage_utp_ignore_ring_auth_save(uint8_t ignore_auth)
{
	utp_ignore_ring_auth = ignore_auth;
	int err = settings_save_one(FP_STORAGE_KEY(SS_KEY_UTP_IGNORE_RING_AUTH),
				    &utp_ignore_ring_auth, sizeof(utp_ignore_ring_auth));
	if (err) {
		LOG_ERR("save utp ignore ring auth failed %d", err);
	}
}

uint8_t fp_storage_utp_ignore_ring_auth_get(void)
{
	return utp_ignore_ring_auth;
}

static void fp_storage_utp_ignore_ring_auth_delete(void)
{
	utp_ignore_ring_auth = false;
	int err = settings_delete(FP_STORAGE_KEY(SS_KEY_UTP_IGNORE_RING_AUTH));
	if (err) {
		LOG_ERR("delete utp ignore ring auth failed (err: %d)", err);
	}
}

int fp_storage_fmdn_clock_save(uint32_t clock_value)
{
	fmdn_clock_value = clock_value;
	fmdn_clock_valid = true;
	int err = settings_save_one(FP_STORAGE_KEY(SS_KEY_FMDN_CLOCK), (uint8_t *)&fmdn_clock_value,
				    sizeof(fmdn_clock_value));
	if (err) {
		LOG_ERR("save fmdn clock failed %d", err);
	} else {
		LOG_DBG("Saved FMDN clock value: %" PRIu32 " [s]", fmdn_clock_value);
	}
	return err;
}

int fp_storage_fmdn_clock_get(uint32_t *clock_value)
{
	if (!fmdn_clock_valid) {
		*clock_value = 0;
		return -ENOENT;
	}
	*clock_value = fmdn_clock_value;
	return 0;
}

static void fp_storage_fmdn_clock_delete(void)
{
	fmdn_clock_value = 0;
	fmdn_clock_valid = false;
	int err = settings_delete(FP_STORAGE_KEY(SS_KEY_FMDN_CLOCK));
	if (err) {
		LOG_ERR("delete fmdn clock failed (err: %d)", err);
	}
}

void fp_storage_fmdn_clock_reset(void)
{
	fmdn_clock_value = 0;
	fmdn_clock_valid = false;
	int err = settings_delete(FP_STORAGE_KEY(SS_KEY_FMDN_CLOCK));
	if (err && err != -ENOENT) {
		LOG_ERR("reset fmdn clock failed (err: %d)", err);
	} else {
		LOG_INF("FMDN clock reset to 0");
	}
}

#ifdef CONFIG_FMDN_PERSISTENT_CONNECTION
void fp_storage_pc_client_id_save(uint8_t client_id)
{
	pc_client_id = client_id;
	pc_client_id_valid = true;
	int err = settings_save_one(FP_STORAGE_KEY(SS_KEY_PC_CLIENT_ID), &pc_client_id,
				    sizeof(pc_client_id));
	if (err) {
		LOG_ERR("save PC client ID failed %d", err);
	} else {
		LOG_INF("Saved PC client ID: %u", pc_client_id);
	}
}

int fp_storage_pc_client_id_get(uint8_t *client_id)
{
	if (!pc_client_id_valid) {
		return -ENOENT;
	}
	*client_id = pc_client_id;
	return 0;
}

bool fp_storage_pc_client_id_valid(void)
{
	return pc_client_id_valid;
}

void fp_storage_pc_client_id_delete(void)
{
	pc_client_id = 0;
	pc_client_id_valid = false;
	int err = settings_delete(FP_STORAGE_KEY(SS_KEY_PC_CLIENT_ID));
	if (err) {
		LOG_ERR("delete PC client ID failed (err: %d)", err);
	} else {
		LOG_INF("Deleted PC client ID from NVS");
	}
}
#endif // CONFIG_FMDN_PERSISTENT_CONNECTION

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

int fp_storage_personalized_name_save(const char *name)
{
	size_t name_len = strlen(name);
	if (name_len >= sizeof(personalized_name)) {
		LOG_ERR("Personalized name too long: %zu >= %zu", name_len,
			sizeof(personalized_name));
		return -EINVAL;
	}

	strncpy(personalized_name, name, sizeof(personalized_name) - 1);
	personalized_name[sizeof(personalized_name) - 1] = '\0';
	personalized_name_valid = true;

	int err = settings_save_one(FP_STORAGE_KEY(SS_KEY_PERSONALIZED_NAME),
				    (uint8_t *)personalized_name, name_len);
	if (err) {
		LOG_ERR("Save personalized name failed: %d", err);
		return err;
	}
	LOG_INF("Personalized name saved: '%s'", personalized_name);
	return err;
}

int fp_storage_personalized_name_delete(void)
{
	if (personalized_name_valid) {
		memset(personalized_name, 0, sizeof(personalized_name));
		personalized_name_valid = false;
	}
	int err = settings_delete(FP_STORAGE_KEY(SS_KEY_PERSONALIZED_NAME));
	if (err) {
		LOG_ERR("Delete personalized name failed: %d", err);
		return err;
	}
	LOG_DBG("Personalized name deleted");
	return err;
}

int fp_storage_personalized_name_get(char *name, size_t name_size)
{
	if (!personalized_name_valid) {
		return -ENODATA;
	}

	if (!name_size) {
		return -EINVAL;
	}

	strncpy(name, personalized_name, name_size - 1);
	name[name_size - 1] = '\0';
	return 0;
}

bool fp_storage_personalized_name_valid(void)
{
	return personalized_name_valid;
}

const char *fp_storage_get_effective_name(void)
{
	if (personalized_name_valid && (strlen(personalized_name) > 0)) {
		return personalized_name;
	}
	return "";
}

void fp_storage_bt_id_base_save(uint8_t id)
{
	bt_id_base = id;
	int err = settings_save_one(FP_STORAGE_KEY(SS_KEY_BT_ID_BASE), (uint8_t *)&bt_id_base,
				    sizeof(bt_id_base));
	if (err) {
		LOG_ERR("save bt_id_base failed %d", err);
	}
	bt_id_base_valid = true;
}

uint8_t fp_storage_bt_id_base_get(void)
{
	return bt_id_base;
}

bool fp_storage_bt_id_base_valid(void)
{
	return bt_id_base_valid;
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
	int save_idx = -1;

	memcpy(cur_account_key, account_key, FP_ACCOUNT_KEY_LEN);
	fp_storage_owner_key_save(account_key);

	// Check if key already exists
	for (uint8_t i = 0; i < FP_ACCOUNT_KEY_CNT; i++) {
		if (account_key_data_list[i].in_used) {
			if (!memcmp(account_key, account_key_data_list[i].account_key,
				    FP_ACCOUNT_KEY_LEN)) {
				LOG_DBG("account key already exists at index %u", i);
				is_saved = true;
#ifdef CONFIG_FAST_PAIR_ACCOUNT_KEY_FIFO_EVICTION
				// Update timestamp for existing key
				account_key_data_list[i].timestamp = k_uptime_seconds();
				LOG_DBG("Updated timestamp for existing key: %" PRIu32,
					account_key_data_list[i].timestamp);
#endif
				break;
			}
		}
	}

	// If key doesn't exist, find a slot to save it
	if (!is_saved) {
		// First, try to find an empty slot
		for (uint8_t i = 0; i < FP_ACCOUNT_KEY_CNT; i++) {
			if (!account_key_data_list[i].in_used) {
				save_idx = i;
				break;
			}
		}

#ifdef CONFIG_FAST_PAIR_ACCOUNT_KEY_FIFO_EVICTION
		// If no empty slot, evict the oldest key
		if (save_idx == -1) {
			save_idx = fp_storage_account_key_find_oldest();
			if (save_idx >= 0) {
				LOG_WRN("Account key storage full, evicting oldest key at index %d "
					"(timestamp: %" PRIu32 ")",
					save_idx, account_key_data_list[save_idx].timestamp);
			}
		}
#endif

		// Save the new key if we have a slot
		if (save_idx >= 0) {
			memcpy(account_key_data_list[save_idx].account_key, account_key,
			       FP_ACCOUNT_KEY_LEN);
			account_key_data_list[save_idx].in_used = true;
#ifdef CONFIG_FAST_PAIR_ACCOUNT_KEY_FIFO_EVICTION
			account_key_data_list[save_idx].timestamp = k_uptime_seconds();
			LOG_INF("Saved account key at index %d with timestamp %" PRIu32, save_idx,
				account_key_data_list[save_idx].timestamp);
#else
			LOG_DBG("Saved account key at index %d", save_idx);
#endif
			is_saved = true;
		} else {
			LOG_ERR("Failed to save account key: no storage available and FIFO "
				"eviction disabled");
		}
	}

	fp_storage_account_key_list_reload();
	return is_saved ? 0 : -ENOMEM;
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
	fp_storage_utp_ignore_ring_auth_delete();
	fp_storage_fmdn_clock_delete();
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
	// Clear personalized name when resetting account keys
	fp_storage_personalized_name_delete();
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
