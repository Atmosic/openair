/**
 *******************************************************************************
 *
 * @file atm_gfp.h
 *
 * @brief Library For Google Fast Pair
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup ATM_GFP_API Google Fast Pair API
 * @ingroup ATM_GFP_API
 * @brief Google Fast Pair middleware for device discovery, pairing, and FMDN integration.
 *
 * This module provides Google Fast Pair (GFP) functionality for seamless device
 * discovery and pairing with Android devices. It integrates with Find My Device
 * Network (FMDN) for location tracking and supports various Fast Pair features.
 *
 * The GFP middleware provides:
 * - Fast Pair discoverable and non-discoverable advertising
 * - FMDN (Find My Device Network) integration and provisioning
 * - Battery status reporting for connected devices
 * - Sound action callbacks for device location
 * - Multi-mode tag support for different operational states
 * - Bluetooth ID management for advertising
 *
 * @{
 */

#include <stdint.h>
#include <stdbool.h>
#include "compiler.h" // __NONNULL_ALL inline functions
#ifdef CONFIG_ATM_GFPS
#include "fp_mode.h"
#endif
#ifdef CONFIG_FMDN_PRECISION_FINDING
#ifndef CONFIG_RANGING_OOB_DE
#error "RANGING_OOB_DE must be enabled for FMDN_PRECISION_FINDING"
#endif
#include "ranging_oob_de.h"
#endif // CONFIG_FMDN_PRECISION_FINDING

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_FMDN_PRECISION_FINDING

/**
 * @brief Callback for ranging capability requests
 * @param tech_id Technology ID (rt_id_t)
 * @param capability Discriminated union containing capability structure
 * @return 0 on success, negative on error
 */
typedef int (*atm_gfp_ranging_capability_cb_t)(rt_id_t tech_id, ranging_capability_t *capability);

/**
 * @brief Callback for ranging configuration requests
 * @param tech_id Technology ID (rt_id_t)
 * @param config Discriminated union containing configuration data
 * @param start_immediately Whether to start immediately
 * @return 0 on success, negative on error
 */
typedef int (*atm_gfp_ranging_config_cb_t)(rt_id_t tech_id, ranging_config_t *config,
					   bool start_immediately);

/**
 * @brief Callback for ranging start requests
 * @param tech_id Technology ID to start (rt_id_t)
 * @return 0 on success, negative on error
 */
typedef int (*atm_gfp_ranging_start_cb_t)(rt_id_t tech_id);

/**
 * @brief Callback for ranging stop requests
 * @param tech_id Technology ID to stop (rt_id_t)
 * @return 0 on success, negative on error
 */
typedef int (*atm_gfp_ranging_stop_cb_t)(rt_id_t tech_id);

/**
 * @brief FMDN ranging callback handler structure
 * Contains callbacks for ranging operations. NULL callbacks are ignored.
 */
typedef struct {
	atm_gfp_ranging_capability_cb_t capability_cb; ///< Capability requests
	atm_gfp_ranging_config_cb_t config_cb;         ///< Configuration requests
	atm_gfp_ranging_start_cb_t start_cb;           ///< Start requests
	atm_gfp_ranging_stop_cb_t stop_cb;             ///< Stop requests
} atm_gfp_ranging_handler_t;

#endif // CONFIG_FMDN_PRECISION_FINDING

#ifdef CONFIG_FMDN_REVERSE_RINGING
/**
 * @brief Reverse ringing event types
 *
 * Events for reverse ringing (Find My Phone feature) user feedback.
 * Per FHN v2 spec line 263: "The tag may use indication confirmation to provide
 * feedback to the user (a specific LED pattern or beep) on successful operation"
 */
typedef enum {
	/**
	 * @brief Request successfully sent to phone
	 *
	 * GATT indication was confirmed (ACKed). Application should show
	 * feedback to user (LED pattern or beep) that the request was sent.
	 * Per spec line 263: feedback on "successful operation"
	 */
	ATM_GFP_RR_EVENT_STARTED = 0,

	/**
	 * @brief Reverse ringing stopped
	 *
	 * Ringing has stopped for any reason (timeout, user dismissed, etc.).
	 * Application should turn off any active feedback (LED/beep).
	 */
	ATM_GFP_RR_EVENT_STOPPED,
} atm_gfp_reverse_ringing_event_t;
#endif

/**
 * @brief Ring operation type
 */
typedef enum {
	ATM_GFP_RING_OP_RIGHT = 0x01,
	ATM_GFP_RING_OP_LEFT = 0x02,
	ATM_GFP_RING_OP_CASE = 0x04,
	ATM_GFP_RING_OP_ALL = 0xFF,
} atm_gfp_ring_op_t;

/**
 * @brief Ring volume type
 */
typedef enum {
	ATM_GFP_RING_VOL_DEFAULT = 0x00,
	ATM_GFP_RING_VOL_LOW = 0x01,
	ATM_GFP_RING_VOL_MEDIUM = 0x02,
	ATM_GFP_RING_VOL_HIGH = 0x03,
} atm_gfp_ring_vol_t;

#ifdef CONFIG_ATM_GFPS
/**
 * @brief Firmware version callback function
 *
 * Called to retrieve the firmware version string to be advertised in the
 * Device Information Service (DIS). This allows the application to provide
 * the version string dynamically.
 *
 * @return Pointer to firmware version string (must be null-terminated)
 *         If NULL is returned, uses CONFIG_GFP_DIS_FIRMWARE_VERSION_* values
 *         Maximum length is determined by CONFIG_GFP_DIS_FW_VERSION_STR_MAX
 *
 * @note The returned string must remain valid for the lifetime of the application
 */
typedef const char *(*atm_gfp_fw_version_cb_t)(void);
#endif

/**
 * @brief Google Fast Pair event handlers structure
 *
 * This structure contains callback functions and configuration that the application
 * must provide to handle various Fast Pair events and requests from connected devices.
 */
typedef struct atm_gfp_hdlrs_s {
	/**
	 * @brief Battery status callback function
	 *
	 * Called when a connected device requests the current battery level.
	 * The application should return the current battery percentage.
	 *
	 * @return Battery level as percentage (0-100)
	 */
	uint8_t (*battery_status_cb)(void);

	/**
	 * @brief Sound action callback function
	 *
	 * Called when a connected device requests the tag to play a sound
	 * for location purposes (e.g., "Find My Device" functionality).
	 *
	 * @param action true to start playing sound, false to stop
	 * @param ring_op ring operation
	 * @param ring_vol ring volume
	 */
	void (*sound_action_cb)(bool action, atm_gfp_ring_op_t ring_op,
				atm_gfp_ring_vol_t ring_vol);

#ifdef CONFIG_ATM_GFPS
	/**
	 * @brief Mode state change callback function
	 *
	 * Called when the Fast Pair mode changes (e.g., during pairing,
	 * provisioning, or operational state transitions).
	 *
	 * @param mode Current Fast Pair mode state
	 */
	void (*mode_state_cb)(fp_mode_t mode);

	/**
	 * @brief Firmware version callback function
	 *
	 * Retrieves the firmware version string for the Device Information Service (DIS).
	 * Maximum length is determined by CONFIG_GFP_DIS_FW_VERSION_STR_MAX.
	 *
	 * @return Non-NULL pointer to null-terminated firmware version string
	 *
	 * @note String must remain valid for the lifetime of the application
	 */
	atm_gfp_fw_version_cb_t fw_version_cb;
#endif

#ifdef CONFIG_FMDN_PRECISION_FINDING
	/// FMDN ranging handlers for precision finding (optional)
	atm_gfp_ranging_handler_t const *ranging_handlers;
#endif

#ifdef CONFIG_FMDN_REVERSE_RINGING
	/**
	 * @brief Reverse ringing event callback function
	 *
	 * Called when reverse ringing events occur (e.g., phone started/stopped ringing,
	 * timeout, etc.). This is for "Find My Phone" functionality where the tag
	 * triggers the phone to ring.
	 *
	 * The application should show appropriate feedback (LED patterns, beeps) based
	 * on the event. The tag does NOT ring itself during reverse ringing.
	 *
	 * @param event Reverse ringing event type
	 *
	 * @note This is different from normal ringing where the tag rings
	 */
	void (*reverse_ringing_event_cb)(atm_gfp_reverse_ringing_event_t event);
#endif
} atm_gfp_hdlrs_t;

/**
 * @brief Initialize Google Fast Pair middleware
 *
 * Initializes the Fast Pair subsystem with the provided event handlers.
 * This function must be called before any other Fast Pair operations.
 * The handlers structure provides callbacks for battery status, sound
 * actions, and mode state changes.
 *
 * If CONFIG_FMDN_PRECISION_FINDING is enabled and ranging_handlers are
 * provided in the handlers structure, they will be automatically registered
 * with the FMDN layer during initialization.
 *
 * @param[in] hdlrs Pointer to handlers structure containing callback functions
 *
 * @note This function must be called after Bluetooth initialization
 * @note The handlers structure must remain valid for the lifetime of the
 *       application
 * @note Ranging handlers (if provided) are automatically registered and must
 *       remain valid for the application lifetime
 *
 * @see atm_gfp_reset() to deinitialize Fast Pair
 * @see atm_gfp_ranging_handler_register() for manual registration after init
 */
__NONNULL_ALL
void atm_gfp_init(atm_gfp_hdlrs_t const *hdlrs);

/**
 * @brief Reset and deinitialize Google Fast Pair middleware
 *
 * Stops all Fast Pair operations, cleans up resources, and resets the
 * Fast Pair state. After calling this function, atm_gfp_init() must
 * be called again before using Fast Pair functionality.
 *
 * This function:
 * - Stops all advertising
 * - Disconnects active Fast Pair connections
 * - Clears pairing and provisioning state
 * - Frees allocated resources
 *
 * @note Safe to call even if Fast Pair is not initialized
 * @see atm_gfp_init() to reinitialize Fast Pair
 */
void atm_gfp_reset(void);

/**
 * @brief Trigger Fast Pair button notification
 *
 * Simulates a button press event for Fast Pair functionality. This is
 * typically used to trigger discoverable advertising or other button-
 * activated Fast Pair features.
 *
 * The exact behavior depends on the current Fast Pair state:
 * - If not paired: Starts discoverable advertising
 * - If paired: May trigger sound action or other notifications
 *
 * @note This function can be called from button interrupt handlers
 * @note The actual behavior is determined by the Fast Pair state machine
 */
void atm_gfp_button_notify(void);

#ifdef CONFIG_FMDN_REVERSE_RINGING
/**
 * @brief Trigger Fast Pair button double notification
 *
 * Simulates a button double press event for Fast Pair functionality. This is
 * typically used to trigger reverse ringing or other button-activated Fast
 * Pair features.
 *
 * The exact behavior depends on the current Fast Pair state:
 * - If not paired: Starts discoverable advertising
 * - If paired: May trigger sound action or other notifications
 *
 * @note This function can be called from button interrupt handlers
 * @note The actual behavior is determined by the Fast Pair state machine
 */
void atm_gfp_button_double_notify(void);
#endif

/**
 * @brief Stop Fast Pair operations
 *
 * Pauses Fast Pair functionality including advertising and connection
 * handling. This is useful for multi-mode tags that need to temporarily
 * disable Fast Pair while operating in other modes.
 *
 * After calling this function:
 * - Fast Pair advertising is stopped
 * - New connections are not accepted
 * - Existing connections may be maintained
 *
 * @note Only available when CONFIG_ATM_GFP_MUTLIMODE_TAG is enabled
 * @see atm_gfp_start() to resume Fast Pair operations
 */
void atm_gfp_stop(void);

/**
 * @brief Start/Resume Fast Pair operations
 *
 * Starts or resumes Fast Pair functionality after it has been stopped
 * or during initial startup. This enables advertising and connection
 * handling for Fast Pair services.
 *
 * This function:
 * - Resumes Fast Pair advertising if appropriate
 * - Enables connection handling
 * - Restores normal Fast Pair operation
 *
 * @note Only available when CONFIG_ATM_GFP_MUTLIMODE_TAG is enabled
 * @see atm_gfp_stop() to pause Fast Pair operations
 */
void atm_gfp_start(void);

/**
 * @brief Check if device is provisioned with FMDN
 *
 * Checks if the device has been provisioned with Find My Device Network
 * credentials and is ready for FMDN operations. This reads provisioning
 * status directly from persistent storage.
 *
 * @return true if device is provisioned with FMDN credentials, false otherwise
 *
 * @note Only available when CONFIG_ATM_GFP_MUTLIMODE_TAG is enabled
 * @note This function reads from persistent storage (EIK)
 */
bool atm_gfp_is_provisioned(void);

/**
 * @brief Get list of Bluetooth IDs used by Fast Pair
 *
 * Populates the provided array with Bluetooth IDs currently used for Fast Pair
 * advertising. This is useful for applications that
 * need to coordinate with other Bluetooth services or manage
 * multiple advertising sets.
 *
 * @param[out] id_list Array to store BT IDs (must have space for FP_ADV_BT_ID_MAX entries)
 * @return Number of BT IDs populated in the array (0 if no advertising active)
 *
 * @note The caller must ensure the id_list array has sufficient space
 * @note The returned BT IDs are currently active for Fast Pair advertising
 * @note This function is thread-safe
 */
__NONNULL_ALL
uint8_t atm_gfp_bt_id_list_get(uint8_t *id_list);

#ifdef CONFIG_ATM_GFPS
/**
 * @brief Get current Fast Pair mode
 *
 * Returns the current operational mode of the Fast Pair subsystem.
 * This can be used to determine the current state of Fast Pair
 * operations such as pairing, provisioning, or normal operation.
 *
 * @return Current Fast Pair mode state
 *
 * @note The returned mode reflects the current Fast Pair state machine
 * @note Mode changes are reported via the mode_state_cb callback if configured
 */
fp_mode_t atm_gfp_fp_mode_get(void);
#endif

#ifdef CONFIG_FMDN_PRECISION_FINDING
/**
 * @brief Register FMDN ranging callbacks
 *
 * Registers ranging handler callbacks with the FMDN layer. This function is
 * called automatically by atm_gfp_init() if ranging_handlers are provided in
 * the handlers structure.
 *
 * This function can also be used for manual registration after initialization,
 * or to replace previously registered handlers.
 *
 * @param handler Ranging handler structure containing callback functions
 *
 * @note Handler must remain valid for the application lifetime
 * @note Typically called automatically by atm_gfp_init(); manual calls are
 *       only needed for dynamic handler replacement after initialization
 *
 * @see atm_gfp_init() for automatic registration during initialization
 */
__NONNULL_ALL
void atm_gfp_ranging_handler_register(atm_gfp_ranging_handler_t const *handler);
#endif

/**
 * @brief Convert ring operation to string
 *
 * @param ring_op ring operation
 * @return string representation of ring operation
 */
const char *atm_gfp_ring_op_to_string(atm_gfp_ring_op_t ring_op);

/**
 * @brief Convert ring volume to string
 *
 * @param ring_vol ring volume
 * @return string representation of ring volume
 */
const char *atm_gfp_ring_vol_to_string(atm_gfp_ring_vol_t ring_vol);

#ifdef CONFIG_FAST_PAIR_FMDN
/**
 * @brief Save FMDN clock to NVM
 *
 * @return 0 if successful, otherwise a (negative) error code is returned
 */
int atm_gfp_fmdn_clock_save(void);

/**
 * @brief Reset FMDN clock to 0
 *
 * Resets the FMDN clock value to 0 and deletes it from NVM.
 * This should be called during factory reset so new provisioning
 * can start with clock value of 0.
 */
void atm_gfp_fmdn_clock_reset(void);
#endif

#ifdef __cplusplus
}
#endif

/**
 * @}
 */
