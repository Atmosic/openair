/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/**
 *******************************************************************************
 *
 * @file fp_adv.h
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Advertisement Middleware
 *
 *******************************************************************************
 */

#pragma once

#include <stdbool.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/gap.h>
#include "compiler.h" // __NONNULL_ALL inline functions
#include "fp_common.h"

/**
 * @addtogroup ATM_BTFMDN Google Fast Pair Service
 * @brief Advertisement Middleware of Fast Pair Service
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

// Advertising interval range to allow controller randomness (advDelay)
#define FP_ADV_INTERVAL_RANGE_MS 20

// Advertising interval in non-discoverable
#define FP_ADV_NONDISCOVER_MS 250
#define FP_ADV_NONDISCOVER_INT_MIN                                                                 \
	BT_GAP_MS_TO_ADV_INTERVAL(FP_ADV_NONDISCOVER_MS - FP_ADV_INTERVAL_RANGE_MS)
#define FP_ADV_NONDISCOVER_INT_MAX BT_GAP_MS_TO_ADV_INTERVAL(FP_ADV_NONDISCOVER_MS)

/* Advertising interval constants for PLR mode (shared with FMDN) */
#ifdef CONFIG_FAST_PAIR_FMDN
// Power-loss recovery continuous mode: use non-discoverable interval (250ms)
#define FP_ADV_PLR_CONTINUOUS_INT_MIN FP_ADV_NONDISCOVER_INT_MIN
#define FP_ADV_PLR_CONTINUOUS_INT_MAX FP_ADV_NONDISCOVER_INT_MAX

// Power-loss recovery periodic mode: 1s BLE interval
#define FP_ADV_PLR_PERIODIC_INT_MIN                                                                \
	BT_GAP_MS_TO_ADV_INTERVAL(CONFIG_FMDN_POWER_LOSS_PERIODIC_ADV_INTERVAL_MS -                \
				  FP_ADV_INTERVAL_RANGE_MS)
#define FP_ADV_PLR_PERIODIC_INT_MAX                                                                \
	BT_GAP_MS_TO_ADV_INTERVAL(CONFIG_FMDN_POWER_LOSS_PERIODIC_ADV_INTERVAL_MS)
#endif

/**
 * @brief Refresh cached non-discoverable Fast Pair payload
 *
 * @param [in] rotate_salt Update the Fast Pair advertising salt first
 *
 * @return true if the payload was rebuilt successfully
 */
bool fp_adv_refresh_non_disc_payload(bool rotate_salt);

/**
 * @brief Get the Fast Pair non-discoverable service-data element
 *
 * @param [out] ad Fast Pair service-data element
 */
__NONNULL_ALL
void fp_adv_get_non_disc_service_data(struct bt_data *ad);

/**
 * @brief Get the current advertising address from the Fast Pair advertising set
 *
 * Returns the live address the controller is advertising with (RPA when
 * privacy is active, identity address when @c BT_LE_ADV_OPT_USE_IDENTITY is
 * set).
 *
 * @param[out] addr Pointer to receive the current advertising address
 * @return 0 on success, -ENODEV if the advertising set has not been created
 *         yet, or another negative errno forwarded from bt_le_ext_adv_get_info()
 */
__NONNULL_ALL
int fp_adv_get_adv_set_addr(bt_addr_le_t *addr);

/**
 * @brief fp adv recreate with fp mode
 */
void fp_adv_recreate(void);

#ifdef __cplusplus
}
#endif

#if defined(CONFIG_ZTEST)
#include <zephyr/bluetooth/bluetooth.h>

void fp_adv_test_adv_sent(void);
void fp_adv_test_connected(void);
uint16_t fp_adv_test_data_salt(void);
void fp_adv_test_data_salt_update(void);
void fp_adv_test_get_non_disc_service_data(struct bt_data *ad);
#endif /* CONFIG_ZTEST */

///@}
