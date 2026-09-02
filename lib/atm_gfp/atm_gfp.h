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
#include <zephyr/bluetooth/addr.h>
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
 * @param capability Struct containing the capability pointer for tech_id
 * @return 0 on success, negative on error
 */
typedef int (*atm_gfp_ranging_capability_cb_t)(rt_id_t tech_id, ranging_capability_t *capability);

/**
 * @brief Callback for ranging configuration requests
 * @param tech_id Technology ID (rt_id_t)
 * @param config Struct containing the config pointer for tech_id
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
 * @brief FMDN motion status getter (atm_gfp-internal).
 *
 * Used internally by atm_gfp to expose a peak-accumulating getter to the FMDN
 * layer.  It is NOT supplied by the platform.
 *
 * @return Peak motion status since last read; peak is reset on every call.
 */
typedef ranging_de_motion_status_t (*atm_gfp_ranging_motion_get_status_t)(void);

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

#ifdef CONFIG_FMDN_PRECISION_FINDING
/**
 * @brief Raw motion snapshot getter supplied by the platform when motion is enabled.
 * @return Current tilt angle in whole degrees (0–90), sampled at call time.
 */
typedef uint8_t (*atm_gfp_motion_raw_get_t)(void);

/**
 * @brief Platform motion callback — enable or disable motion sensor hardware.
 *
 * Called by atm_gfp to start or stop the motion sensor on behalf of FMDN
 * precision finding.
 * @param get_raw  non-NULL to enable; platform writes its raw snapshot getter
 *                 here.  NULL to disable motion detection.
 * @return 0 on success, negative errno on error
 */
typedef int (*atm_gfp_motion_cb_t)(atm_gfp_motion_raw_get_t *get_raw);
#endif /* CONFIG_FMDN_PRECISION_FINDING */

#ifdef CONFIG_FMDN_REVERSE_RINGING
/**
 * @brief Reverse ringing event types
 *
 * Events for reverse ringing (Find My Phone feature) user feedback.
 * The tag may use indication confirmation to provide feedback to the user
 * (a specific LED pattern or beep) on successful operation.
 */
typedef enum {
	/**
	 * @brief Seeker connected via RR advertisement, encryption enabled
	 *
	 * The phone is already ringing at this point — it started ringing upon
	 * detecting the RR advertisement before connecting. Application may now
	 * show active ringing feedback (LED pattern or beep).
	 */
	ATM_GFP_RR_EVENT_CONNECTED = 0,

	/**
	 * @brief Seeker confirmed ringing started
	 *
	 * Phone has started ringing. Application should show active ringing
	 * feedback (LED pattern or beep).
	 */
	ATM_GFP_RR_EVENT_STARTED,

	/**
	 * @brief Reverse ringing stopped
	 *
	 * Ringing has stopped for any reason (timeout, user dismissed, etc.).
	 * Application should turn off any active feedback (LED/beep).
	 */
	ATM_GFP_RR_EVENT_STOPPED,

	/**
	 * @brief Tag started RR ADV (no persistent conn); phone rings on detecting it.
	 *
	 * Show searching feedback (e.g. slow LED blink) while waiting for Seeker connection.
	 */
	ATM_GFP_RR_EVENT_ADV_STARTED,

	/**
	 * @brief Tag failed to start RR ADV (no persistent conn).
	 *
	 * Show started fail feedback (e.g. play error tone).
	 */
	ATM_GFP_RR_EVENT_ADV_START_FAILED,

	/**
	 * @brief ADV window (15-20s) expired with no Seeker connection; phone never rang.
	 *
	 * Stop searching feedback started on ATM_GFP_RR_EVENT_ADV_STARTED.
	 */
	ATM_GFP_RR_EVENT_ADV_TIMEOUT,

	/**
	 * @brief Seeker WRITE 0x01: phone could not start ringing.
	 *
	 * Stop searching feedback and play error tone.
	 */
	ATM_GFP_RR_EVENT_PHONE_FAILED,

	/**
	 * @brief Provider 60s timeout: Seeker connected via ADV but sent no stop WRITE.
	 *
	 * Stop searching feedback and play error tone.
	 */
	ATM_GFP_RR_EVENT_TIMEOUT_LOCAL,

	/**
	 * @brief Seeker WRITE 0x02: phone's own ring session timed out.
	 *
	 * Turn off active ringing feedback.
	 */
	ATM_GFP_RR_EVENT_PHONE_TIMEOUT,

	/**
	 * @brief ATT-layer ACK for START indication (persistent path only).
	 *
	 * Arrives before ATM_GFP_RR_EVENT_STARTED; use for immediate feedback.
	 */
	ATM_GFP_RR_EVENT_START_CONFIRMED,

	/**
	 * @brief ATT-layer ACK for STOP indication (persistent path only).
	 *
	 * Arrives before ATM_GFP_RR_EVENT_STOPPED; use for immediate feedback.
	 */
	ATM_GFP_RR_EVENT_STOP_CONFIRMED,

	/**
	 * @brief Provider 60s timeout on persistent path after START indication ACKed.
	 *
	 * Ringing state cleared; keep connection open. Stop active ringing feedback.
	 */
	ATM_GFP_RR_EVENT_PHONE_START_TIMEOUT,

	/**
	 * @brief BLE connection dropped while phone was ringing.
	 *
	 * Ringing state cleared; application should stop active ringing feedback.
	 */
	ATM_GFP_RR_EVENT_PHONE_STOPPED_DISCONNECTED,
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
	 * @param ring_vol_lvl ring volume level
	 * @param ring_to_ds ring timeout in deciseconds requested by the seeker
	 * @return effective ring duration in deciseconds when action=true; return
	 *         @p ring_to_ds unchanged to keep the seeker-requested duration.
	 *         Ignored when action=false.
	 */
	uint16_t (*sound_action_cb)(bool action, atm_gfp_ring_op_t ring_op,
				    atm_gfp_ring_vol_t ring_vol_lvl, uint16_t ring_to_ds);

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

#ifdef CONFIG_FMDN_PRECISION_FINDING
	/**
	 * @brief Platform motion sensor callback for FMDN precision finding.
	 *
	 * atm_gfp calls this to enable/disable the motion sensor hardware on
	 * behalf of FMDN ranging.  On enable the platform writes its raw
	 * snapshot getter into the pointer; on disable the pointer is NULL.
	 */
	atm_gfp_motion_cb_t motion_cb;
#endif

#ifdef CONFIG_DULT_MOTION_DETECT
	/**
	 * @brief Enable or disable motion sensor hardware for DULT UT detection.
	 *
	 * Called by atm_gfp at DULT init to pass the platform HW control
	 * function to the DULT service.  DULT calls this when it needs to
	 * start or stop the sensor.
	 *
	 * @param enable  true to power on the sensor, false to power it off.
	 */
	void (*dult_motion_hw_enable_cb)(bool enable);

#ifndef CONFIG_DULT_MOTION_DETECT_TRIGGER
	/**
	 * @brief Raw motion snapshot getter for DULT UT detection (poll mode).
	 *
	 * Registered at DULT init time.  DULT calls this on each poll tick to
	 * read the current tilt angle in whole degrees (0–90).  Not used when
	 * CONFIG_DULT_MOTION_DETECT_TRIGGER is enabled.
	 */
	uint8_t (*dult_motion_raw_get_cb)(void);
#endif
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

/**
 * @brief Check if reverse ringing is enabled by the Seeker.
 *
 * @return true if the Seeker has enabled reverse ringing, false otherwise.
 */
bool atm_gfp_is_reverse_ringing_enabled(void);

/**
 * @brief Check if reverse ringing is currently active (phone is ringing).
 *
 * @return true if the phone is currently ringing, false otherwise.
 */
bool atm_gfp_is_reverse_ringing_started(void);
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
 * @param ring_vol_lvl ring volume level
 * @return string representation of ring volume level
 */
const char *atm_gfp_ring_vol_to_string(atm_gfp_ring_vol_t ring_vol_lvl);

/**
 * @brief Get current advertising Bluetooth address
 *
 * Retrieves the Bluetooth LE address used for the current Fast Pair advertising
 * set. The address is selected based on provisioning state:
 * - Not provisioned: Fast Pair advertising BT ID address
 * - Provisioned:     FMDN advertising BT ID address
 *
 * @param[out] addr Pointer to receive the advertising address
 * @return 0 on success, negative errno on error
 */
__NONNULL_ALL
int atm_gfp_get_adv_addr(bt_addr_le_t *addr);

#ifdef CONFIG_FAST_PAIR_FMDN
/**
 * @brief Set FMDN clock to a specific value at startup
 *
 * Allows the application to supply the FMDN clock value before the FMDN
 * service starts. The application is responsible for obtaining and validating
 * this value (e.g. from uninitialized RAM contents preserved across a reset).
 *
 * Must be called before atm_gfp_init() to take effect. If not called,
 * atm_gfp_init() restores the clock from NVM as normal.
 *
 * @param[in] clock_value FMDN clock value in seconds to apply
 */
void atm_gfp_fmdn_clock_set(uint32_t clock_value);

/**
 * @brief Get the current FMDN clock value
 *
 * Returns the current running FMDN clock value in seconds. The application
 * can use this to preserve the clock across resets (e.g. by storing it in
 * uninitialized RAM) and restore it at startup via atm_gfp_fmdn_clock_set().
 *
 * @return current FMDN clock value in seconds
 */
uint32_t atm_gfp_fmdn_clock_get(void);

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

/**
 * @brief Overwrite the active ringing safety timer duration (one-shot), in seconds
 *
 * Convenience wrapper; @p duration_s is converted to deciseconds internally.
 * See atm_gfp_set_active_ring_duration_ds() for full details.
 *
 * @param duration_s ring duration in seconds; 0 stops ringing immediately
 *
 * @note Must be called from the application work queue context; not ISR-safe.
 */
void atm_gfp_set_active_ring_duration(uint8_t duration_s);

/**
 * @brief Overwrite the active ringing safety timer duration (one-shot), in deciseconds
 *
 * Applies to the current ring session only. The safety timer is rescheduled
 * immediately and the seeker is notified of the new duration. The override is
 * cleared automatically when ringing stops.
 *
 * @param duration_ds ring duration in deciseconds; 0 stops ringing immediately
 *
 * @note Must be called from the application work queue context; not ISR-safe.
 * @note Duration is in deciseconds, aligned with the GATT protocol specification.
 */
void atm_gfp_set_active_ring_duration_ds(uint16_t duration_ds);
#endif

#if defined(CONFIG_DULT_MOTION_DETECT_TRIGGER) || defined(CONFIG_FMDN_OOB_MOTION_DETECT_TRIGGER)
/**
 * @brief Signal a hardware-detected motion event to the DULT UT state machine.
 *
 * Called by the platform when the motion sensor interrupt fires.  Routes to
 * dult_ut_motion_event() which submits the notify work to the app work queue.
 * Safe to call from any context.
 */
void atm_gfp_motion_trigger_event(void);
#endif /* CONFIG_DULT_MOTION_DETECT_TRIGGER || CONFIG_FMDN_OOB_MOTION_DETECT_TRIGGER */

#ifdef __cplusplus
}
#endif

/**
 * @}
 */
