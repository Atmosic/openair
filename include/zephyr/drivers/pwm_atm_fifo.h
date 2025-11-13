/*
 * Copyright (c) 2025, Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DRIVERS_PWM_ATM_FIFO_H_
#define ZEPHYR_INCLUDE_DRIVERS_PWM_ATM_FIFO_H_

/**
 * @file
 * @brief Atmosic PWM FIFO mode support
 *
 * This header provides Atmosic-specific PWM FIFO mode functionality
 * for advanced waveform generation including ringtones and IR patterns.
 */

#include <zephyr/drivers/pwm.h>
#include <zephyr/kernel.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name Atmosic PWM FIFO flags
 * These flags can be used with the PWM API in the upper 8 bits of pwm_flags_t
 * to enable and configure FIFO mode operation.
 * @{
 */

/** @cond INTERNAL_HIDDEN */
#define PWM_ATM_FIFO_MODE_POS         8
#define PWM_ATM_FIFO_CARRIER_POS      9
#define PWM_ATM_FIFO_ALERT_THRESH_POS 12
/** @endcond */

/** Enable PWM FIFO mode */
#define PWM_ATM_FIFO_MODE_ENABLE (1U << PWM_ATM_FIFO_MODE_POS)

/** Use carrier 1 for FIFO commands */
#define PWM_ATM_FIFO_CARRIER1 (0U << PWM_ATM_FIFO_CARRIER_POS)

/** Use carrier 2 for FIFO commands */
#define PWM_ATM_FIFO_CARRIER2 (1U << PWM_ATM_FIFO_CARRIER_POS)

/** FIFO alert threshold mask (3 bits) */
#define PWM_ATM_FIFO_ALERT_THRESH_MASK (7U << PWM_ATM_FIFO_ALERT_THRESH_POS)

/** Set FIFO alert threshold (0-7) */
#define PWM_ATM_FIFO_ALERT_THRESH(n) (((n) & 7U) << PWM_ATM_FIFO_ALERT_THRESH_POS)

/** @} */

/**
 * @brief PWM carrier configuration for FIFO mode
 */
struct pwm_atm_carrier_config {
	/** Carrier frequency in Hz */
	uint32_t freq_hz;
	/** Carrier duty cycle (1-99%) */
	uint8_t duty_cycle;
};

/**
 * @brief PWM FIFO command structure
 */
struct pwm_atm_fifo_cmd {
	/** Carrier selection (0=carrier1, 1=carrier2) */
	uint8_t carrier;
	/** Carrier on/off state */
	bool carrier_on;
	/** Number of carrier cycles to generate (1-16384) */
	uint16_t carrier_count;
};

/**
 * @brief PWM FIFO mode configuration
 *
 * Configuration structure for PWM FIFO mode. At least one carrier must be
 * configured (carrier1 or carrier2 cannot both be NULL). Commands that
 * reference unconfigured carriers will be rejected at runtime.
 */
struct pwm_atm_fifo_config {
	/** Carrier 1 configuration (NULL if not used, commands with carrier=0 will fail) */
	const struct pwm_atm_carrier_config *carrier1;
	/** Carrier 2 configuration (NULL if not used, commands with carrier=1 will fail) */
	const struct pwm_atm_carrier_config *carrier2;
	/** Output polarity (0=normal, 1=inverted) */
	uint8_t polarity;
	/** FIFO alert threshold (1-15) */
	uint8_t fifo_alert_threshold;
	/** Alert callback - called when FIFO has space for more commands or on error
	 *  @param dev PWM device instance
	 *  @param channel PWM channel number
	 *  @param error 0 for normal alert, negative errno for errors (e.g., -EOVERFLOW)
	 */
	void (*fifo_alert_callback)(const struct device *dev, uint32_t channel, int error);
	/** Completion callback - called when all FIFO commands are executed or on error
	 *  @param dev PWM device instance
	 *  @param channel PWM channel number
	 *  @param error 0 for normal completion, negative errno for errors
	 */
	void (*fifo_done_callback)(const struct device *dev, uint32_t channel, int error);
};

/**
 * @brief Initialize PWM channel for FIFO mode operation
 *
 * This function configures a PWM channel for FIFO mode operation with
 * the specified carriers and callbacks. It validates the carrier configuration
 * and sets up the hardware for FIFO-based PWM generation.
 *
 * Carrier Validation:
 * At least one carrier (carrier1 or carrier2) must be configured. The function
 * will return -EINVAL if both carriers are NULL. If only one carrier is
 * configured, warnings will be logged about commands that use the unconfigured
 * carrier.
 *
 * Resource Management:
 * Only one channel can use FIFO mode at a time. If another channel is already
 * using FIFO mode, this function will return -EBUSY.
 *
 * @param dev PWM device instance
 * @param channel PWM channel number
 * @param config FIFO mode configuration
 * @return 0 on success, negative errno on failure
 * @retval -EINVAL Invalid parameters or both carriers are NULL
 * @retval -EBUSY FIFO mode already in use by another channel
 *
 * @note Ensure proper cleanup with pwm_atm_fifo_deinit() when done
 * @see pwm_atm_fifo_deinit() for cleanup
 */
int pwm_atm_fifo_init(const struct device *dev, uint32_t channel,
		      const struct pwm_atm_fifo_config *config);

/**
 * @brief Deinitialize PWM FIFO mode for a channel
 *
 * This function cleans up FIFO mode resources and disables FIFO operation
 * for the specified channel. It releases global FIFO resources, allowing
 * other devices/channels to use FIFO mode. This provides proper resource
 * cleanup and enables sequential usage of different PWM devices.
 *
 * The function performs complete hardware and software cleanup:
 * - Stop PWM output and disable interrupts
 * - Reset PWM hardware registers to default state
 * - Clear global FIFO state if this device/channel owns it
 * - Clear per-channel FIFO data and configuration
 * - Release power management constraints
 *
 * Sequential Device Usage:
 * After calling this function, the PWM hardware is in a clean state and
 * another device can safely initialize and use FIFO mode without conflicts.
 *
 * @param dev PWM device instance
 * @param channel PWM channel number
 * @return 0 on success, negative errno on failure
 * @retval -EINVAL Invalid channel number
 * @retval -ENODEV FIFO mode not initialized for this channel
 *
 * @note This function must be called to properly clean up FIFO mode.
 *       Failure to call this function may result in resource leaks and
 *       prevent other devices from using FIFO mode.
 *
 * @see pwm_atm_fifo_init() for initialization
 */
int pwm_atm_fifo_deinit(const struct device *dev, uint32_t channel);

/**
 * @brief Write a command to the PWM FIFO
 *
 * Adds a single command to the PWM FIFO queue. The command will be
 * executed in order when pwm_atm_fifo_start() is called.
 *
 * Carrier Validation:
 * The function validates that the requested carrier (0 or 1) was configured
 * during initialization. If a command tries to use an unconfigured carrier,
 * the function will return -ENODEV with a descriptive error message.
 *
 * @param dev PWM device instance
 * @param channel PWM channel number
 * @param cmd FIFO command to write
 * @return 0 on success, negative errno on failure
 * @retval -EINVAL Invalid parameters or FIFO not initialized
 * @retval -ENODEV Requested carrier not configured during init
 * @retval -ENOSPC FIFO is full
 *
 * @note Ensure the carrier specified in cmd->carrier was configured during
 *       pwm_atm_fifo_init(), otherwise the command will be rejected.
 */
int pwm_atm_fifo_write_cmd(const struct device *dev, uint32_t channel,
			   const struct pwm_atm_fifo_cmd *cmd);

/**
 * @brief Write multiple commands to the PWM FIFO
 *
 * Adds multiple commands to the PWM FIFO queue efficiently.
 *
 * @param dev PWM device instance
 * @param channel PWM channel number
 * @param cmds Array of FIFO commands
 * @param count Number of commands in the array
 * @return 0 on success, negative errno on failure
 */
int pwm_atm_fifo_write_cmds(const struct device *dev, uint32_t channel,
			    const struct pwm_atm_fifo_cmd *cmds, size_t count);

/**
 * @brief Start executing FIFO commands
 *
 * Begins execution of commands previously written to the FIFO.
 * The PWM will generate the programmed waveform patterns.
 *
 * @param dev PWM device instance
 * @param channel PWM channel number
 * @return 0 on success, negative errno on failure
 */
int pwm_atm_fifo_start(const struct device *dev, uint32_t channel);

/**
 * @brief Stop FIFO execution
 *
 * Stops the current FIFO execution and clears any remaining commands.
 *
 * @param dev PWM device instance
 * @param channel PWM channel number
 * @return 0 on success, negative errno on failure
 */
int pwm_atm_fifo_stop(const struct device *dev, uint32_t channel);

/**
 * @brief Load and execute FIFO commands from memory using DMA
 *
 * This function loads a pre-formatted command array directly to the
 * PWM FIFO using DMA for efficient bulk transfers.
 *
 * @param dev PWM device instance
 * @param channel PWM channel number
 * @param fifo_cmds Pre-formatted FIFO command array
 *                  Format: bit[15]=carrier, bit[14]=on/off, bit[13:0]=count-1
 * @param cmd_count Number of commands in the array
 * @return 0 on success, negative errno on failure
 */
int pwm_atm_fifo_run_dma(const struct device *dev, uint32_t channel, const uint16_t *fifo_cmds,
			 size_t cmd_count);

/**
 * @brief Get number of available FIFO slots
 *
 * Returns the number of free slots in the PWM FIFO queue.
 *
 * @param dev PWM device instance
 * @param channel PWM channel number
 * @return Number of available slots, or negative errno on failure
 */
int pwm_atm_fifo_get_free_slots(const struct device *dev, uint32_t channel);

/**
 * @brief Check if FIFO is empty
 *
 * @param dev PWM device instance
 * @param channel PWM channel number
 * @return true if FIFO is empty, false otherwise
 */
bool pwm_atm_fifo_is_empty(const struct device *dev, uint32_t channel);

/**
 * @brief Check if FIFO is full
 *
 * @param dev PWM device instance
 * @param channel PWM channel number
 * @return true if FIFO is full, false otherwise
 */
bool pwm_atm_fifo_is_full(const struct device *dev, uint32_t channel);

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_INCLUDE_DRIVERS_PWM_ATM_FIFO_H_ */
