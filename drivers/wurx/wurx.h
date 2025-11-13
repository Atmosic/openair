/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DRIVERS_WURX_H_
#define ZEPHYR_INCLUDE_DRIVERS_WURX_H_

/**
 * @brief Wake upon receive (WuRx) Driver API
 * @defgroup wurx_interface WuRx Driver API
 * @ingroup io_interfaces
 * @{
 */

#include <zephyr/types.h>
#include <zephyr/device.h>
#include <zephyr/kernel.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief WURX wake-up status flags
 */
enum wurx_status {
	/** WURX algorithm 0 triggered */
	WURX_STATUS_WURX0_TRIGGERED = BIT(0),
	/** WURX algorithm 1 triggered */
	WURX_STATUS_WURX1_TRIGGERED = BIT(1),
	/** General WURX triggered (chip-specific) */
	WURX_STATUS_WURX_TRIGGERED = BIT(2),
	/** Wake-up detection timeout */
	WURX_STATUS_TIMEOUT = BIT(3),
	/** Configuration error */
	WURX_STATUS_CONFIG_ERROR = BIT(4),
};

/**
 * @brief WuRx algorithm identifiers
 */
enum wurx_algorithm {
	/** WuRx algorithm 0 */
	WURX_ALGORITHM_0 = 0,
	/** WuRx algorithm 1 */
	WURX_ALGORITHM_1 = 1,
};

/**
 * @brief WuRx driver API structure
 */
__subsystem struct wurx_driver_api {
	int (*set_algorithm)(const struct device *dev, enum wurx_algorithm algorithm, bool enabled);
};

/**
 * @brief Set WuRx algorithm enable state
 *
 * @param dev WuRx device instance
 * @param algorithm WuRx algorithm (0 or 1)
 * @param enabled true to enable, false to disable
 * @return 0 on success, negative error code on failure
 */
static inline int wurx_set_algorithm(const struct device *dev, enum wurx_algorithm algorithm,
				     bool enabled)
{
	const struct wurx_driver_api *api = (const struct wurx_driver_api *)dev->api;

	if (!api->set_algorithm) {
		return -ENOSYS;
	}

	return api->set_algorithm(dev, algorithm, enabled);
}

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif /* ZEPHYR_INCLUDE_DRIVERS_WURX_H_ */
