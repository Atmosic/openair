/**
 *******************************************************************************
 *
 * @file atm_vendor_api.c
 *
 * @brief Atmosic Vendor API Command Core
 *
 * Copyright (C) Atmosic 2024-2025
 *
 *******************************************************************************
 */
#include <errno.h>
#include <inttypes.h>
#include <stddef.h>
#include <zephyr/sys/util.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/net_buf.h>
#include <zephyr/logging/log.h>
#include "atm_utils_c.h"
#include "atm_vendor_internal.h"
#include "atm_vendor_api.h"

#ifdef CONFIG_ATM_RF
#include "rf_api.h"
#endif

LOG_MODULE_REGISTER(atm_vendor_api, CONFIG_ATM_VENDOR_API_LOG_LEVEL);

#if  defined(CFG_VND_API_SET_PREF_SLAVE_LAT) || defined(CFG_VND_API_SET_SCAN_CHMAP)
/**
 * @brief send hci command
 *
 * @param opcode hci command opcode
 * @param payload Payload data point
 * @param payload_size payload data size
 *
 * @return the status of send hci command
 */
static int atm_vendor_api_send_command(uint16_t opcode, uint8_t const *payload,
    uint16_t payload_size)
{
	struct net_buf *buf = bt_hci_cmd_alloc(K_FOREVER);
	if (!buf) {
		LOG_ERR("No Buf");
		return -ENOBUFS;
	}

	uint8_t *buf_tail = net_buf_add(buf, payload_size);
	memcpy(buf_tail, payload, payload_size);

	struct net_buf *rsp;
	int err = bt_hci_cmd_send_sync(opcode, buf, &rsp);
	if (err) {
		LOG_ERR("vendor api send err:%d", err);
		return err;
	}
	net_buf_unref(rsp);

	return 0;
}
#endif

#ifdef CFG_VND_API_SET_PREF_SLAVE_LAT
/**
 * @brief Set Prefer Slave Latency
 *
 * @param conhdl Connection Handle
 * @param latency Prefer slave latency value
 *
 * @return the status of set prefer slave latency
 */
int atm_vendor_set_pref_slave_lat(uint16_t conhdl, uint16_t latency)
{
	set_pref_slave_lat_cmd_t pref_lat;
	(void)memset(&pref_lat, 0, VS_SET_PREF_SLAVE_LATENCY_CMD_LEN);
	atm_set_le16(&pref_lat.conhdl, conhdl);
	atm_set_le16(&pref_lat.latency, latency);

	return atm_vendor_api_send_command(VND_OPCODE(VS_SET_PREF_SLAVE_LATENCY_CMD_OGF,
		VS_SET_PREF_SLAVE_LATENCY_CMD_OCF), (uint8_t *)&pref_lat,
		VS_SET_PREF_SLAVE_LATENCY_CMD_LEN);
}
#endif

#ifdef CFG_VND_API_SET_MAX_TX_POWER
/**
 * @brief Set Maximum TX power
 *
 * @param tx_pwr transmitter power in dBm
 * @return 0 on success, non-zero on failure.
 */
uint8_t atm_vendor_set_max_tx_power(int8_t tx_pwr)
{
	int8_t act_tx_pwr = rf_set_txpwr_maximum_val(tx_pwr);
	if (act_tx_pwr == INVALID_TX_POWER_VALUE) {
		LOG_ERR("Set max TX pwr fail");
		return TX_POWER_VALUE_ADJUST_FAIL;
	}
	LOG_INF("Set max TX pwr:%d", act_tx_pwr);
	return TX_POWER_VALUE_ADJUST_SUCCESS;
}
#endif

#ifdef CFG_VND_API_SET_ADV_TX_POWER
/**
 * @brief Set Advertising TX power
 *
 * @param tx_pwr transmitter power in dBm
 * @return 0 on success, non-zero on failure.
 */
uint8_t atm_vendor_set_adv_tx_power(int8_t tx_pwr)
{
	LOG_INF("Set adv TX pwr:%d", tx_pwr);
	if (!rf_set_txpwr_advertising_val(tx_pwr)) {
		return TX_POWER_VALUE_ADJUST_FAIL;
	}
	return TX_POWER_VALUE_ADJUST_SUCCESS;
}
#endif // CFG_VND_API_SET_ADV_TX_POWER

#ifdef CFG_VND_API_SET_CON_TX_POWER
/**
 * @brief Set TX power
 *
 * @param conhdl Connection Handle
 * @param tx_pwr transmitter power in dBm
 * @return 0 on success, non-zero on failure.
 */
uint8_t atm_vendor_set_con_tx_power(uint16_t conhdl, int8_t tx_pwr)
{
	LOG_INF("Set con TX pwr:%d", tx_pwr);
	if (rf_set_cs_txpwr_val(conhdl, tx_pwr) == INVALID_TX_POWER_VALUE) {
		return TX_POWER_VALUE_ADJUST_FAIL;
	}

    return TX_POWER_VALUE_ADJUST_SUCCESS;
}
#endif // CFG_VND_API_SET_CON_TX_POWER

#ifdef CFG_VND_API_SET_SCAN_CHMAP
uint8_t atm_vendor_set_scan_chmap(uint8_t chmap)
{
	return atm_vendor_api_send_command(VND_OPCODE(VS_SET_SCAN_CHMAP_CMD_OGF,
		VS_SET_SCAN_CHMAP_CMD_OCF), &chmap,
		VS_SET_SCAN_CHMAP_CMD_LEN);
}
#endif
