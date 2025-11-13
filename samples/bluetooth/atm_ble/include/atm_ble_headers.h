/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/bluetooth/uuid.h>

#ifndef ATM_BLE_HEADERS_H
#define ATM_BLE_HEADERS_H

#define ATM_BLE_TEST_SERVICE_UUID_VAL                                                              \
	BT_UUID_128_ENCODE(0x434ed0ca, 0x041a, 0x426d, 0xacfc, 0x093e18b8c12d)
#define ATM_WRITE_TEST_CHAR_UUID_VAL                                                               \
	BT_UUID_128_ENCODE(0x434ed0ca, 0x041a, 0x426d, 0xacfc, 0x093e18b8c141)

#define ATM_BLE_TEST_SERVICE_UUID BT_UUID_DECLARE_128(ATM_BLE_TEST_SERVICE_UUID_VAL)
#define ATM_WRITE_TEST_CHAR_UUID  BT_UUID_DECLARE_128(ATM_WRITE_TEST_CHAR_UUID_VAL)

#define STR_PERIPHERAL_TO_CENTRAL "In peripheral Tx power set successfully"
#define STR_CENTRAL_TO_PERIPHERAL "Atmosic --central to peripheral"
#define STR_TEST_COMPLETE         "ATM BLE Test completed"

#endif /* ATM_BLE_HEADERS_H */
