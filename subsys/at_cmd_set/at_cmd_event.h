/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <stdint.h>
#include "at_cmd.h"
#if defined(CONFIG_AT_CMD_SET_CONN_TRACKING) || defined(CONFIG_AT_EVT_BLEGAPADVRPT)
#include <zephyr/bluetooth/bluetooth.h>
#endif
#ifdef CONFIG_AT_CMD_SET_CONN_TRACKING
#include <zephyr/bluetooth/conn.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_AT_CMD_SET_EVENTS

#ifdef CONFIG_ATM_AT_CMDTEST
/**
 * @brief Submit test event with optional data
 *
 * @param ch AT command channel
 * @param data Optional event data (NULL if no data)
 * @param len Data length (0 if no data)
 *
 */
void at_cmd_evt_test(uint8_t ch, uint8_t const *data, uint16_t len);

#endif /* CONFIG_ATM_AT_CMDTEST */

#ifdef CONFIG_AT_EVT_BLEGAPADVRPT

enum at_cmd_evt_adv_type {
	AT_CMD_EVT_ADV_TYPE_EXT_ADV = 0x00U,
	AT_CMD_EVT_ADV_TYPE_LEGACY_ADV = 0x01U,
	AT_CMD_EVT_ADV_TYPE_EXT_SCAN_RSP = 0x02U,
	AT_CMD_EVT_ADV_TYPE_LEGACY_SCAN_RSP = 0x03U,
	/* Reserved: not yet produced by the scan recv callback. */
	AT_CMD_EVT_ADV_TYPE_PERIODIC_ADV = 0x04U,
};

/**
 * @brief Convert Zephyr scan callback data and emit an unsolicited BLE
 * advertising report event.
 *
 * @param ch AT command channel.
 * @param info Zephyr LE scan receive metadata.
 * @param buf Zephyr scan payload buffer.
 */
void at_cmd_evt_adv_rpt(uint8_t ch, const struct bt_le_scan_recv_info *info,
			struct net_buf_simple *buf);
#endif /* CONFIG_AT_EVT_BLEGAPADVRPT */

#ifdef CONFIG_AT_EVT_BLEGAPCONN
/**
 * @brief Emit a connection-established event.
 *
 * @param ch   AT command channel.
 * @param idx  Connection index in the tracking array.
 * @param info Zephyr connection info (from bt_conn_get_info).
 */
void at_cmd_evt_conn(uint8_t ch, uint8_t idx, const struct bt_conn_info *info);
#endif /* CONFIG_AT_EVT_BLEGAPCONN */

#ifdef CONFIG_AT_EVT_BLEGAPDISCONN
/**
 * @brief Emit a disconnection event.
 *
 * @param ch     AT command channel.
 * @param idx    Connection index in the tracking array.
 * @param reason HCI disconnect reason code.
 */
void at_cmd_evt_disconn(uint8_t ch, uint8_t idx, uint8_t reason);
#endif /* CONFIG_AT_EVT_BLEGAPDISCONN */

#ifdef CONFIG_AT_EVT_BLEGAPLINKINFO
/**
 * @brief Emit a remote link-info event.
 *
 * @param ch   AT command channel.
 * @param idx  Connection index in the tracking array.
 * @param info Zephyr remote info (from remote_info_available callback).
 */
void at_cmd_evt_linkinfo(uint8_t ch, uint8_t idx, const struct bt_conn_remote_info *info);
#endif /* CONFIG_AT_EVT_BLEGAPLINKINFO */

#ifdef CONFIG_AT_CMD_SYSFUNCPIN
/**
 * @brief Emit a GPIO function-pin interrupt event (+EVTSYSFUNCPIN).
 *
 * Must be called from thread context (not ISR). Use a k_work bridge
 * when deferring from a GPIO ISR callback.
 *
 * @param ch AT command channel.
 * @param io GPIO pin number that triggered the interrupt.
 */
void at_cmd_evt_sysfuncpin(uint8_t ch, uint8_t io);
#endif /* CONFIG_AT_CMD_SYSFUNCPIN */

#ifdef CONFIG_AT_EVT_BLEGAPPAR
/**
 * @brief Emit a connection parameter update event.
 *
 * @param ch       AT command channel.
 * @param idx      Connection index in the tracking array.
 * @param interval Connection interval (1.25 ms units).
 * @param latency  Peripheral latency (number of events).
 * @param timeout  Supervision timeout (10 ms units).
 */
void at_cmd_evt_par(uint8_t ch, uint8_t idx, uint16_t interval, uint16_t latency, uint16_t timeout);
#endif /* CONFIG_AT_EVT_BLEGAPPAR */

#ifdef CONFIG_AT_EVT_BLEGATTMTUEXCHANGE
/**
 * @brief Emit a GATT MTU exchange event.
 *
 * @param ch  AT command channel.
 * @param idx Connection index in the tracking array.
 * @param mtu Negotiated TX ATT MTU in bytes.
 */
void at_cmd_evt_mtu_exchange(uint8_t ch, uint8_t idx, uint16_t mtu);
#endif /* CONFIG_AT_EVT_BLEGATTMTUEXCHANGE */

#ifdef CONFIG_AT_EVT_BLEGATTINDI
/**
 * @brief Emit a GATT indication received event.
 *
 * @param ch     AT command channel.
 * @param conidx Connection index.
 * @param handle Characteristic value handle.
 * @param data   Indication payload.
 * @param len    Payload length in bytes.
 */
void at_cmd_evt_blegattindi(uint8_t ch, uint8_t conidx, uint16_t handle, const uint8_t *data,
			    uint16_t len);
#endif /* CONFIG_AT_EVT_BLEGATTINDI */

#ifdef CONFIG_AT_EVT_BLEGATTNOTI
/**
 * @brief Emit a GATT notification received event.
 *
 * @param ch     AT command channel.
 * @param conidx Connection index.
 * @param handle Characteristic value handle.
 * @param data   Notification payload.
 * @param len    Payload length in bytes.
 */
void at_cmd_evt_blegattnoti(uint8_t ch, uint8_t conidx, uint16_t handle, const uint8_t *data,
			    uint16_t len);
#endif /* CONFIG_AT_EVT_BLEGATTNOTI */

#ifdef CONFIG_AT_EVT_BLEGATTMTUEXCHGREQ
/**
 * @brief Emit a GATT MTU exchange request result event.
 *
 * @param ch  AT command channel.
 * @param idx Connection index in the tracking array.
 * @param err ATT/HCI error code (0 = success).
 */
void at_cmd_evt_mtuexchgreq(uint8_t ch, uint8_t idx, uint8_t err);
#endif /* CONFIG_AT_EVT_BLEGATTMTUEXCHGREQ */

#ifdef CONFIG_AT_EVT_TAGMOTIONCTL
/**
 * @brief Emit a tag motion sensor control event.
 *
 * @param ch     AT command channel.
 * @param enable 0 = disable motion sensor, 1 = enable motion sensor.
 */
void at_cmd_evt_motionctl(uint8_t ch, uint8_t enable);
#endif /* CONFIG_AT_EVT_TAGMOTIONCTL */

#ifdef CONFIG_AT_EVT_BLESMPPASSKEY
/**
 * @brief Emit a passkey display event (fire-and-forget).
 *
 * @param ch      AT command channel.
 * @param idx     Connection index in the tracking array.
 * @param passkey Six-digit passkey to display.
 */
void at_cmd_evt_smp_passkey(uint8_t ch, uint8_t idx, uint32_t passkey);
#endif /* CONFIG_AT_EVT_BLESMPPASSKEY */

#ifdef CONFIG_AT_EVT_BLESMPPASSKEYREQIND
/**
 * @brief Emit a passkey entry indication (host must reply AT+BLESMPPASSKEY).
 *
 * @param ch  AT command channel.
 * @param idx Connection index in the tracking array.
 */
void at_cmd_evt_smp_passkeyreqind(uint8_t ch, uint8_t idx);
#endif /* CONFIG_AT_EVT_BLESMPPASSKEYREQIND */

#ifdef CONFIG_AT_EVT_BLESMPNUMCOMPIND
/**
 * @brief Emit a numeric comparison indication (host must reply AT+BLESMPCONFIRM).
 *
 * @param ch      AT command channel.
 * @param idx     Connection index in the tracking array.
 * @param passkey Six-digit number to display for comparison.
 */
void at_cmd_evt_smp_numcompind(uint8_t ch, uint8_t idx, uint32_t passkey);
#endif /* CONFIG_AT_EVT_BLESMPNUMCOMPIND */

#ifdef CONFIG_AT_EVT_BLESMPPAIRENDIND
/**
 * @brief Emit a pairing end indication (complete or failed).
 *
 * @param ch     AT command channel.
 * @param idx    Connection index in the tracking array.
 * @param bonded true if a bond was formed.
 * @param err    bt_security_err code; 0 on success.
 */
void at_cmd_evt_smp_pairendind(uint8_t ch, uint8_t idx, bool bonded, uint8_t err);
#endif /* CONFIG_AT_EVT_BLESMPPAIRENDIND */

#endif /* CONFIG_AT_CMD_SET_EVENTS */

#ifdef __cplusplus
}
#endif
