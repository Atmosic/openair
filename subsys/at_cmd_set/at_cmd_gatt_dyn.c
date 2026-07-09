/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/sys/slist.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include <string.h>
#include "at_cmd_gatt_dyn.h"
#include "at_cmd_set_common.h"

LOG_MODULE_REGISTER(at_cmd_gatt_dyn, CONFIG_AT_CMD_SET_LOG_LEVEL);

/* File-scope UUID pointers: BT_UUID_GATT_* macros expand to compound literals;
 * storing them at file scope gives static storage duration, safe for attr.uuid. */
static const struct bt_uuid *s_uuid_gatt_primary = BT_UUID_GATT_PRIMARY;
static const struct bt_uuid *s_uuid_gatt_chrc = BT_UUID_GATT_CHRC;
static const struct bt_uuid *s_uuid_gatt_ccc = BT_UUID_GATT_CCC;

/* Global staging list and implicit-context pointers */
static sys_slist_t s_svcs;
static uint8_t s_svc_cnt;
static at_cmd_gatt_dyn_svc_t *s_curr_svc;
static at_cmd_gatt_dyn_char_t *s_curr_char;
static at_cmd_gatt_dyn_svc_t *s_curr_char_svc; /* svc that owns s_curr_char */

/* ---- UUID helpers ---- */

static void uuid128_set(struct bt_uuid_128 *dst, const uint8_t *src_be16)
{
	dst->uuid.type = BT_UUID_TYPE_128;
	sys_memcpy_swap(dst->val, src_be16, BT_UUID_SIZE_128);
}

/* ---- GATT callbacks ---- */

static ssize_t dyn_char_read_cb(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf,
				uint16_t len, uint16_t offset)
{
	at_cmd_gatt_dyn_char_t *ch = attr->user_data;

#if defined(CONFIG_AT_EVT_BLEGATTFROMBLE)
	at_cmd_evt_gatt_from_ble(at_cmd_conn_slot(conn), attr->handle, AT_GATT_ACT_READ, NULL, 0);
#endif
	return bt_gatt_attr_read(conn, attr, buf, len, offset, ch->val_buf, ch->val_len);
}

static ssize_t dyn_char_write_cb(struct bt_conn *conn, const struct bt_gatt_attr *attr,
				 const void *buf, uint16_t len, uint16_t offset, uint8_t flags)
{
	at_cmd_gatt_dyn_char_t *ch = attr->user_data;

	if (offset + len > ch->max_size) {
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
	}
	memcpy(ch->val_buf + offset, buf, len);
	if (offset + len > ch->val_len) {
		ch->val_len = offset + len;
	}
#if defined(CONFIG_AT_EVT_BLEGATTFROMBLE)
	at_cmd_evt_gatt_from_ble(at_cmd_conn_slot(conn), attr->handle, AT_GATT_ACT_WRITE, buf, len);
#endif
	return len;
}

static ssize_t dyn_desc_read_cb(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf,
				uint16_t len, uint16_t offset)
{
	at_cmd_gatt_dyn_desc_t *desc = attr->user_data;

	return bt_gatt_attr_read(conn, attr, buf, len, offset, desc->val_buf, desc->val_len);
}

static ssize_t dyn_desc_write_cb(struct bt_conn *conn, const struct bt_gatt_attr *attr,
				 const void *buf, uint16_t len, uint16_t offset, uint8_t flags)
{
	at_cmd_gatt_dyn_desc_t *desc = attr->user_data;

	if (offset + len > desc->max_size) {
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
	}
	memcpy(desc->val_buf + offset, buf, len);
	if (offset + len > desc->val_len) {
		desc->val_len = offset + len;
	}
#if defined(CONFIG_AT_EVT_BLEGATTFROMBLE)
	at_cmd_evt_gatt_from_ble(at_cmd_conn_slot(conn), attr->handle, AT_GATT_ACT_WRITE, buf, len);
#endif
	return len;
}

/* ---- Attribute table builder ---- */

static int build_one_svc(at_cmd_gatt_dyn_svc_t *svc)
{
	at_cmd_gatt_dyn_char_t *ch;
	at_cmd_gatt_dyn_desc_t *desc;
	uint16_t attr_cnt = 1; /* primary service declaration */

	SYS_SLIST_FOR_EACH_CONTAINER(&svc->chars, ch, node) {
		attr_cnt += 2; /* char decl + char value */
		if (ch->sec_prop & AT_GATT_CHRC_EXT_MASK) {
			attr_cnt++; /* CCCD */
		}
		SYS_SLIST_FOR_EACH_CONTAINER(&ch->descs, desc, node) {
			attr_cnt++;
		}
	}

	struct bt_gatt_attr *attrs = k_calloc(attr_cnt, sizeof(*attrs));

	if (!attrs) {
		return -ENOMEM;
	}

	uint16_t cnt = 0;

	attrs[cnt++] = (struct bt_gatt_attr)BT_GATT_ATTRIBUTE(
		s_uuid_gatt_primary, BT_GATT_PERM_READ, bt_gatt_attr_read_service, NULL,
		&svc->uuid128);

	SYS_SLIST_FOR_EACH_CONTAINER(&svc->chars, ch, node) {
		ch->chrc_decl.uuid = &ch->uuid128.uuid;
		ch->chrc_decl.properties = at_cmd_gatt_sec_prop_to_chrc_props(ch->sec_prop);

		attrs[cnt++] = (struct bt_gatt_attr)BT_GATT_ATTRIBUTE(
			s_uuid_gatt_chrc, BT_GATT_PERM_READ, bt_gatt_attr_read_chrc, NULL,
			&ch->chrc_decl);

		attrs[cnt++] = (struct bt_gatt_attr)BT_GATT_ATTRIBUTE(
			&ch->uuid128.uuid, ch->sec_prop & AT_GATT_ATT_PERM_MASK, dyn_char_read_cb,
			dyn_char_write_cb, ch);

		if (ch->chrc_decl.properties & (BT_GATT_CHRC_NOTIFY | BT_GATT_CHRC_INDICATE)) {
			attrs[cnt++] = (struct bt_gatt_attr)BT_GATT_ATTRIBUTE(
				s_uuid_gatt_ccc, AT_GATT_PERM_CCC, bt_gatt_attr_read_ccc,
				bt_gatt_attr_write_ccc, &ch->ccc_data);
		}

		SYS_SLIST_FOR_EACH_CONTAINER(&ch->descs, desc, node) {
			if (!desc->is_userdfd) {
				attrs[cnt++] = (struct bt_gatt_attr)BT_GATT_ATTRIBUTE(
					&desc->uuid.u16.uuid, BT_GATT_PERM_READ, dyn_desc_read_cb,
					NULL, desc);
			} else {
				attrs[cnt++] = (struct bt_gatt_attr)BT_GATT_ATTRIBUTE(
					&desc->uuid.u128.uuid,
					desc->sec_prop & AT_GATT_ATT_PERM_MASK, dyn_desc_read_cb,
					dyn_desc_write_cb, desc);
			}
		}
	}

	svc->bt_svc.attrs = attrs;
	svc->bt_svc.attr_count = cnt;

	int ret = bt_gatt_service_register(&svc->bt_svc);

	if (ret) {
		LOG_ERR("bt_gatt_service_register failed: %d", ret);
		k_free(attrs);
		svc->bt_svc.attrs = NULL;
		svc->bt_svc.attr_count = 0;
		return ret;
	}

	svc->active = true;
	LOG_INF("Registered dynamic GATT service with %u attrs", cnt);
	return 0;
}

/* ---- Public API ---- */

struct bt_gatt_attr *at_cmd_gatt_dyn_find_attr_by_handle(uint16_t handle)
{
	at_cmd_gatt_dyn_svc_t *svc;

	SYS_SLIST_FOR_EACH_CONTAINER(&s_svcs, svc, node) {
		if (!svc->active) {
			continue;
		}
		for (uint16_t i = 0; i < svc->bt_svc.attr_count; i++) {
			if (svc->bt_svc.attrs[i].handle == handle) {
				return &svc->bt_svc.attrs[i];
			}
		}
	}
	return NULL;
}

at_cmd_result_t at_cmd_gatt_dyn_add_service(uint16_t sec_prop, const uint8_t *uuid_be16)
{
	if (!at_cmd_gatt_is_valid_perm(sec_prop)) {
		return at_cmd_result_err(AT_ERR_PARAM_INVALID);
	}
	if (sec_prop & AT_GATT_PERM_WRITE_MASK) {
		/* BLE spec: Service Declaration is read-only */
		return at_cmd_result_err(AT_ERR_PARAM_INVALID);
	}
	if (sec_prop & AT_GATT_CHRC_EXT_MASK) {
		/* NOTIFY/INDICATE (bits 9-10) are characteristic-only properties */
		return at_cmd_result_err(AT_ERR_PARAM_INVALID);
	}

	at_cmd_gatt_dyn_svc_t *svc = k_calloc(1, sizeof(*svc));

	if (!svc) {
		return at_cmd_result_err_from_errno(-ENOMEM);
	}

	uuid128_set(&svc->uuid128, uuid_be16);
	svc->sec_prop = sec_prop;
	sys_slist_init(&svc->chars);

	sys_slist_append(&s_svcs, &svc->node);
	s_svc_cnt++;
	s_curr_svc = svc;
	/* s_curr_char / s_curr_char_svc intentionally NOT reset - ADDCHAR tracking persists */

	LOG_DBG("Added service, total=%u", s_svc_cnt);
	return at_cmd_result_ok();
}

at_cmd_result_t at_cmd_gatt_dyn_add_char(uint16_t sec_prop, const uint8_t *uuid_be16,
					 uint16_t max_size)
{
	if (!s_curr_svc) {
		return at_cmd_result_err(AT_ERR_GATT_DYN_NO_SVC);
	}
	if (s_curr_svc->active) {
		return at_cmd_result_err(AT_ERR_GATT_DYN_SVC_ACTIVE);
	}
	if (!at_cmd_gatt_is_valid_perm(sec_prop)) {
		return at_cmd_result_err(AT_ERR_PARAM_INVALID);
	}
	if (!max_size) {
		return at_cmd_result_err(AT_ERR_PARAM_OUT_OF_RANGE);
	}

	at_cmd_gatt_dyn_char_t *ch = k_calloc(1, sizeof(*ch));

	if (!ch) {
		return at_cmd_result_err_from_errno(-ENOMEM);
	}
	ch->val_buf = k_calloc(max_size, 1);
	if (!ch->val_buf) {
		k_free(ch);
		return at_cmd_result_err_from_errno(-ENOMEM);
	}

	uuid128_set(&ch->uuid128, uuid_be16);
	ch->sec_prop = sec_prop;
	ch->max_size = max_size;
	sys_slist_init(&ch->descs);

	sys_slist_append(&s_curr_svc->chars, &ch->node);
	s_curr_svc->char_cnt++;
	s_curr_char = ch;
	s_curr_char_svc = s_curr_svc;

	LOG_DBG("Added char to svc, char_cnt=%u", s_curr_svc->char_cnt);
	return at_cmd_result_ok();
}

at_cmd_result_t at_cmd_gatt_dyn_add_desc(const uint8_t *uuid16_be2)
{
	if (!s_curr_char) {
		return at_cmd_result_err(AT_ERR_GATT_DYN_NO_CHAR);
	}
	if (s_curr_char_svc && s_curr_char_svc->active) {
		return at_cmd_result_err(AT_ERR_GATT_DYN_SVC_ACTIVE);
	}

	at_cmd_gatt_dyn_desc_t *desc = k_calloc(1, sizeof(*desc));

	if (!desc) {
		return at_cmd_result_err_from_errno(-ENOMEM);
	}

	desc->uuid.u16.uuid.type = BT_UUID_TYPE_16;
	desc->uuid.u16.val = sys_get_be16(uuid16_be2);
	desc->sec_prop = BT_GATT_PERM_READ;
	desc->is_userdfd = false;
	/* val_buf = NULL, val_len = 0, max_size = 0 (k_calloc already zeroed) */

	sys_slist_append(&s_curr_char->descs, &desc->node);
	LOG_DBG("Added desc (16-bit UUID=0x%04X)", desc->uuid.u16.val);
	return at_cmd_result_ok();
}

at_cmd_result_t at_cmd_gatt_dyn_add_userdfd(uint16_t sec_prop, const uint8_t *uuid_be16,
					    uint16_t max_size)
{
	if (!s_curr_char) {
		return at_cmd_result_err(AT_ERR_GATT_DYN_NO_CHAR);
	}
	if (s_curr_char_svc && s_curr_char_svc->active) {
		return at_cmd_result_err(AT_ERR_GATT_DYN_SVC_ACTIVE);
	}
	if (sec_prop & AT_GATT_CHRC_EXT_MASK) {
		/* NOTIFY/INDICATE bits not valid for descriptors */
		return at_cmd_result_err(AT_ERR_PARAM_INVALID);
	}
	if (!at_cmd_gatt_is_valid_perm(sec_prop)) {
		return at_cmd_result_err(AT_ERR_PARAM_INVALID);
	}
	if (!max_size) {
		return at_cmd_result_err(AT_ERR_PARAM_OUT_OF_RANGE);
	}

	at_cmd_gatt_dyn_desc_t *desc = k_calloc(1, sizeof(*desc));

	if (!desc) {
		return at_cmd_result_err_from_errno(-ENOMEM);
	}
	desc->val_buf = k_calloc(max_size, 1);
	if (!desc->val_buf) {
		k_free(desc);
		return at_cmd_result_err_from_errno(-ENOMEM);
	}

	uuid128_set(&desc->uuid.u128, uuid_be16);
	desc->sec_prop = sec_prop;
	desc->max_size = max_size;
	desc->is_userdfd = true;

	sys_slist_append(&s_curr_char->descs, &desc->node);
	LOG_DBG("Added userdfd desc");
	return at_cmd_result_ok();
}

at_cmd_result_t at_cmd_gatt_dyn_svc_activate(at_cmd_gatt_dyn_svc_reason_t reason)
{
	if (reason != AT_GATT_DYN_SVC_REASON_APPLY) {
		return at_cmd_result_err(AT_ERR_PARAM_INVALID);
	}

	/* Check that at least one service is pending (not yet active) */
	bool any_pending = false;
	at_cmd_gatt_dyn_svc_t *svc;

	SYS_SLIST_FOR_EACH_CONTAINER(&s_svcs, svc, node) {
		if (!svc->active) {
			any_pending = true;
			break;
		}
	}
	if (!any_pending) {
		return at_cmd_result_err(AT_ERR_GATT_DYN_NO_SVC);
	}

	/* Register all pending services */
	SYS_SLIST_FOR_EACH_CONTAINER(&s_svcs, svc, node) {
		if (!svc->active) {
			int ret = build_one_svc(svc);

			if (ret) {
				return at_cmd_result_err_from_errno(ret);
			}
		}
	}

	return at_cmd_result_ok();
}

/* ---- Ztest hooks ---- */
#ifdef CONFIG_ZTEST
ssize_t at_cmd_gatt_dyn_test_char_read(uint8_t conidx, at_cmd_gatt_dyn_char_t *ch, void *buf,
				       uint16_t len, uint16_t offset)
{
#if defined(CONFIG_AT_EVT_BLEGATTFROMBLE)
	at_cmd_evt_gatt_from_ble(conidx, 0, AT_GATT_ACT_READ, NULL, 0);
#endif
	return bt_gatt_attr_read(NULL, NULL, buf, len, offset, ch->val_buf, ch->val_len);
}

ssize_t at_cmd_gatt_dyn_test_char_write(uint8_t conidx, at_cmd_gatt_dyn_char_t *ch, const void *buf,
					uint16_t len, uint8_t flags)
{
	ARG_UNUSED(flags);
	if (len > ch->max_size) {
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
	}
	memcpy(ch->val_buf, buf, len);
	ch->val_len = len;
#if defined(CONFIG_AT_EVT_BLEGATTFROMBLE)
	at_cmd_evt_gatt_from_ble(conidx, 0, AT_GATT_ACT_WRITE, buf, len);
#endif
	return len;
}

ssize_t at_cmd_gatt_dyn_test_desc_read(uint8_t conidx, at_cmd_gatt_dyn_desc_t *desc, void *buf,
				       uint16_t len, uint16_t offset)
{
	ARG_UNUSED(conidx);
	return bt_gatt_attr_read(NULL, NULL, buf, len, offset, desc->val_buf, desc->val_len);
}

ssize_t at_cmd_gatt_dyn_test_desc_write(uint8_t conidx, at_cmd_gatt_dyn_desc_t *desc,
					const void *buf, uint16_t len, uint8_t flags)
{
	ARG_UNUSED(flags);
	if (len > desc->max_size) {
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
	}
	memcpy(desc->val_buf, buf, len);
	desc->val_len = len;
#if defined(CONFIG_AT_EVT_BLEGATTFROMBLE)
	at_cmd_evt_gatt_from_ble(conidx, 0, AT_GATT_ACT_WRITE, buf, len);
#endif
	return len;
}

uint8_t at_cmd_gatt_dyn_test_svc_cnt(void)
{
	return s_svc_cnt;
}

at_cmd_gatt_dyn_svc_t *at_cmd_gatt_dyn_test_curr_svc(void)
{
	return s_curr_svc;
}

at_cmd_gatt_dyn_char_t *at_cmd_gatt_dyn_test_curr_char(void)
{
	return s_curr_char;
}
#endif /* CONFIG_ZTEST */
