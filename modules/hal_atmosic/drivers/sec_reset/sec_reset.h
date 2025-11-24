/**
 *******************************************************************************
 *
 * @file sec_reset.h
 *
 * @brief Secure reset driver header file
 *
 * Copyright (C) Atmosic 2022-2024
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup SEC_RESET Secure reset
 * @ingroup DRIVERS
 * @brief Secure reset driver
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#if (defined(MCUBOOT) || defined(CONFIG_MCUBOOT))

typedef enum {
    SECURE_RESET_TYPE_UNKNOWN,
    SECURE_RESET_TYPE_POR, // power on reset
    SECURE_RESET_TYPE_WARM, // warm reset
    SECURE_RESET_TYPE_HIB_ALLOW_IMG_SKIP, // hibernate triggers that allow image
					  // skip
    SECURE_RESET_TYPE_HIB, // other wake from hibernate triggers occurred
} secure_reset_type;

/**
 * @brief Get the current system reset syndrome value.
 *
 * @return SOC specific reset syndrome value
 * @note Only reads and does not clear the syndrome.
 */
uint32_t secure_reset_get_syndrome(void);

/**
 * @brief Get the reset type at bootup
 *
 * @return the reset type
 * @note This should be called in early boot before the syndrome is cleared.
 */
secure_reset_type secure_reset_get_type(void);

#else
/**
 * @brief Read and clear reset syndrome
 * @return Reset syndrome value
 *
 */
uint32_t secure_rclr_reset_syndrome(void);
#endif // MCUBOOT

#ifdef __cplusplus
}
#endif

/// @}
