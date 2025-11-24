/*
 * Copyright (c) 2023-2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/drivers/hwinfo.h>
#include <string.h>

#include "arch.h"
#include "reset.h"

#ifdef CONFIG_ATM_EUI
#include "eui.h"
#endif


ssize_t z_impl_hwinfo_get_device_id(uint8_t *buffer, size_t length)
{
#ifdef CONFIG_ATM_EUI
	uint8_t eui48[6];

	/* Function will assert if an EUI48 is not present
	 * and neither EUI_ALLOW_RANDOM nor EUI48_ALLOW_BUILTIN is set */
	read_eui48(eui48);

	if (length > 6) {
		length = 6;
	}

	memcpy(buffer, eui48, length);

	return length;
#else
	return -ENOSYS;
#endif
}

int z_impl_hwinfo_get_device_eui64(uint8_t *buffer)
{
#ifdef CONFIG_ATM_EUI
	/* Function will assert if an EUI64 is not present
	 * and EUI_ALLOW_RANDOM is not set */
	read_eui64(buffer);

	return 0;
#else
	return -ENOSYS;
#endif
}

int z_impl_hwinfo_get_reset_cause(uint32_t *cause)
{
	*cause = 0;

	if (is_boot_type(TYPE_POWER_ON)) {
		*cause |= RESET_POR;
	} else if (is_boot_type(TYPE_SOC_RESET)) {
		if (is_boot_reason(BOOT_STATUS_SOC_RESET_PSEQ_WDOG) ||
		    is_boot_reason(BOOT_STATUS_SOC_RESET_PMU_WDOG)) {
			*cause |= RESET_WATCHDOG;
		}
	} else if (is_boot_type(TYPE_RESET)) {
		if (is_boot_reason(BOOT_STATUS_RESET_SYS)) {
			*cause |= RESET_HARDWARE;
		}

		if (is_boot_reason(BOOT_STATUS_RESET_WDOG) ||
		    is_boot_reason(BOOT_STATUS_RESET_SWDOG)) {
			*cause |= RESET_WATCHDOG;
		}

		if (is_boot_reason(BOOT_STATUS_RESET_LOCKUP)) {
			*cause |= RESET_LOCKUP;
		}

		if (is_boot_reason(BOOT_STATUS_RESET_SW)) {
			*cause |= RESET_SOFTWARE;
		}

		if (is_boot_reason(BOOT_STATUS_RESET_EXT)) {
			*cause |= RESET_PIN;
		}
	} else if (is_boot_type(TYPE_SOCOFF)) {
		*cause |= (RESET_LOW_POWER_WAKE | RESET_HARDWARE);

		if (is_boot_reason(BOOT_STATUS_SOCOFF_WKUP_PIN)) {
			*cause |= RESET_PIN;
		}
	} else if (is_boot_type(TYPE_HIB)) {
		*cause |= (RESET_LOW_POWER_WAKE | RESET_HARDWARE);

		if (is_boot_reason(BOOT_STATUS_HIB_WKUP_GPIO)) {
			*cause |= RESET_PIN;
		}

		if (is_boot_reason(BOOT_STATUS_HIB_WKUP_DBG)) {
			*cause |= RESET_DEBUG;
		}

		if (is_boot_reason(BOOT_STATUS_HIB_WKUP_BROWNOUT)) {
			*cause |= RESET_BROWNOUT;
		}
	} else {
		// Unsupported boot type
		return -ENOTSUP;
	}

	return 0;
}

int z_impl_hwinfo_clear_reset_cause(void)
{
	return -ENOSYS;
}

int z_impl_hwinfo_get_supported_reset_cause(uint32_t *supported)
{
	*supported = RESET_PIN |
		RESET_SOFTWARE |
		RESET_BROWNOUT |
		RESET_POR |
		RESET_WATCHDOG |
		RESET_DEBUG |
		RESET_LOW_POWER_WAKE |
		RESET_CPU_LOCKUP |
		RESET_HARDWARE |
		RESET_USER;
	return 0;
}
