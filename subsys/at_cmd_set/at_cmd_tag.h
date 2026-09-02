/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#ifdef CONFIG_AT_CMD_TAGADDR
#include <zephyr/bluetooth/bluetooth.h>
#endif

#ifdef CONFIG_AT_CMD_TAG_SET

/**
 * @brief App-level error codes for tag AT command AT_CMD_ERR_SPECIFIC_ERR responses.
 */
typedef enum {
	AT_CMD_TAG_NO_ERR,            /**< Operation completed successfully */
	AT_CMD_TAG_ERR_INVALID_PARAM, /**< Invalid parameter (e.g., NULL pointer) */
	AT_CMD_TAG_ERR_NOT_ALLOWED,   /**< Operation not allowed in current state */
	AT_CMD_TAG_ERR_INTERNAL,      /**< Internal or platform-level error */
	AT_CMD_TAG_ERR_BLE_INIT,      /**< BLE stack initialization failed */
	AT_CMD_TAG_ERR_MOTION_SENSOR, /**< Motion sensor error */
	AT_CMD_TAG_ERR_BUTTON,        /**< Button configuration error */
	AT_CMD_TAG_ERR_WDOG,          /**< Watchdog configuration error */
	AT_CMD_TAG_ERR_BUZZER,        /**< Buzzer configuration error */
} at_cmd_tag_err_t;

/**
 * @brief Submit TAG state event
 *
 * @param ch AT command channel
 * @param protocol TAG protocol
 * @param state TAG state
 */
void at_cmd_evt_tag_state(uint8_t ch, uint8_t protocol, uint8_t state);

/**
 * @brief Submit TAG error event
 *
 * @param ch AT command channel
 * @param protocol TAG protocol
 * @param error_code TAG error code
 */
void at_cmd_evt_tag_error(uint8_t ch, uint8_t protocol, uint8_t error_code);

#ifdef CONFIG_AT_EVT_TAGBUZZER
/**
 * @brief Submit TAG buzzer action event (+EVTTAGBUZZER)
 *
 * Sent when CONFIG_TAG_BUZZER=n to notify the host that a buzzer action
 * is required. The host is responsible for producing the sound.
 *
 * @param ch          AT command channel
 * @param evt         Buzzer event type (see tag_buzzer_evt_t, encodes operation type)
 * @param ring_vol    Ring volume level (0 if not applicable)
 * @param duration_ds Ring duration in deciseconds (0 if not applicable)
 */
void at_cmd_evt_buzzer_action(uint8_t ch, uint8_t evt, uint8_t ring_vol, uint16_t duration_ds);
#endif

#ifdef CONFIG_AT_EVT_TAGMOTIONCTL
/**
 * @brief Submit TAG motion control event (+EVTTAGMOTIONCTL)
 *
 * @param ch     AT command channel
 * @param enable 1 = enable motion sensor, 0 = disable
 */
void at_cmd_evt_motionctl(uint8_t ch, uint8_t enable);
#endif

#ifdef CONFIG_AT_CMD_TAGMOTIONRPT
/**
 * @brief Callback used to handle AT+TAGMOTIONRPT requests.
 *
 * @param x_cs2  X-axis acceleration reported by host sensor, in cm/s² (signed).
 * @param y_cs2  Y-axis acceleration reported by host sensor, in cm/s² (signed).
 * @param z_cs2  Z-axis acceleration reported by host sensor, in cm/s² (signed).
 * @return Tag AT command error code (at_cmd_tag_err_t).
 */
typedef at_cmd_tag_err_t (*at_cmd_tag_motionrpt_cb_t)(int16_t x_cs2, int16_t y_cs2, int16_t z_cs2);

#endif /* CONFIG_AT_CMD_TAGMOTIONRPT */

#ifdef CONFIG_AT_EVT_TAGGFPREVERSERING
/**
 * @brief Submit GFP reverse ringing phone status event (+EVTTAGGFPREVERSERING)
 *
 * @param ch  AT command channel
 * @param evt Reverse ringing event (0=CONNECTED, 1=STARTED, 2=STOPPED, 3=ADV_STARTED,
 * 4=ADV_TIMEOUT, 5=PHONE_FAILED, 6=TIMEOUT_LOCAL, 7=PHONE_TIMEOUT,
 * 8=START_CONFIRMED, 9=STOP_CONFIRMED, 10=PHONE_STOPPED_DISCONNECTED,
 * 11=PHONE_START_TIMEOUT)
 */
void at_cmd_evt_gfp_reverse_ring(uint8_t ch, uint8_t evt);
#endif

#ifdef CONFIG_AT_CMD_TAGINFO
/**
 * @brief Output buffers used by the TAGINFO callback.
 */
typedef struct {
	char *version;
	size_t version_len;
	uint8_t protocol_mask;
} at_cmd_tag_info_t;

/**
 * @brief Callback used to populate TAGINFO response fields.
 *
 * @param info Output buffers for version string.
 * @return Tag AT command error code (at_cmd_tag_err_t).
 */
typedef at_cmd_tag_err_t (*at_cmd_tag_get_info_cb_t)(at_cmd_tag_info_t *info);
#endif /* CONFIG_AT_CMD_TAGINFO */

#ifdef CONFIG_AT_CMD_TAGMODE
/**
 * @brief TAGMODE protocol bitmask values.
 */
typedef enum {
	AT_CMD_TAG_MODE_FMNA = 0x01,
	AT_CMD_TAG_MODE_FHN = 0x02,
	AT_CMD_TAG_MODE_STF = 0x04,
} at_cmd_tag_mode_t;

/**
 * @brief TAGMODE callback operation types.
 */
typedef enum {
	AT_CMD_TAG_MODE_OP_GET,
	AT_CMD_TAG_MODE_OP_SET,
} at_cmd_tag_mode_op_t;

/**
 * @brief Callback used to handle TAGMODE query/update requests.
 *
 * @param op TAGMODE operation type.
 * @param mode Input/output protocol bitmask.
 * @return Tag AT command error code (at_cmd_tag_err_t).
 */
typedef at_cmd_tag_err_t (*at_cmd_tag_mode_cb_t)(at_cmd_tag_mode_op_t op, uint8_t *mode);
#endif /* CONFIG_AT_CMD_TAGMODE */

#ifdef CONFIG_AT_CMD_TAGSTART
/**
 * @brief Callback used to handle TAGSTART requests.
 *
 * @return Tag AT command error code (at_cmd_tag_err_t).
 */
typedef at_cmd_tag_err_t (*at_cmd_tag_start_cb_t)(void);
#endif /* CONFIG_AT_CMD_TAGSTART */

#ifdef CONFIG_AT_CMD_TAGBATTERY
/**
 * @brief Callback used to get the tag battery level.
 *
 * @param[out] percentage Battery percentage (0-100).
 * @return Tag AT command error code (at_cmd_tag_err_t).
 */
typedef at_cmd_tag_err_t (*at_cmd_tag_get_battery_cb_t)(uint8_t *percentage);
#endif /* CONFIG_AT_CMD_TAGBATTERY */

#ifdef CONFIG_AT_CMD_TAGRESET
/**
 * @brief TAGRESET reset reason codes.
 */
typedef enum {
	AT_CMD_TAG_RESET_REASON_COLD_REBOOT,
	AT_CMD_TAG_RESET_REASON_FACTORY_RESET,
} at_cmd_tag_reset_reason_t;

/**
 * @brief Callback used to handle TAGRESET requests.
 *
 * @param reason Requested reset reason.
 * @return Tag AT command error code (at_cmd_tag_err_t).
 */
typedef at_cmd_tag_err_t (*at_cmd_tag_reset_cb_t)(at_cmd_tag_reset_reason_t reason);
#endif /* CONFIG_AT_CMD_TAGRESET */

#ifdef CONFIG_AT_CMD_TAGSTFIND
/**
 * @brief Callback used to handle TAGSTFIND requests.
 *
 * @param times Number of button presses (1 = single press to confirm pairing).
 * @return Tag AT command error code (at_cmd_tag_err_t).
 */
typedef at_cmd_tag_err_t (*at_cmd_tag_stfind_cb_t)(uint8_t times);
#endif /* CONFIG_AT_CMD_TAGSTFIND */

#ifdef CONFIG_AT_CMD_TAGFMNASN
/**
 * @brief Callback used to enable FMNA SN lookup window.
 *
 * @return Tag AT command error code (at_cmd_tag_err_t).
 */
typedef at_cmd_tag_err_t (*at_cmd_tag_fmna_sn_lookup_cb_t)(void);
#endif /* CONFIG_AT_CMD_TAGFMNASN */

#ifdef CONFIG_AT_CMD_TAGFMNAMFI
/**
 * @brief Callback used to log FMNA MFI token.
 *
 * @return Tag AT command error code (at_cmd_tag_err_t).
 */
typedef at_cmd_tag_err_t (*at_cmd_tag_fmna_mfi_log_cb_t)(void);
#endif /* CONFIG_AT_CMD_TAGFMNAMFI */

#ifdef CONFIG_AT_CMD_TAGCSUNPAIR
/**
 * @brief Callback used to unpair CS (Samsung Find).
 *
 * @return Tag AT command error code (at_cmd_tag_err_t).
 */
typedef at_cmd_tag_err_t (*at_cmd_tag_cs_unpair_cb_t)(void);
#endif /* CONFIG_AT_CMD_TAGCSUNPAIR */

#ifdef CONFIG_AT_CMD_TAGGFPIND
/**
 * @brief GFP button press action types for AT+TAGGFPIND command.
 */
typedef enum {
	AT_CMD_TAG_GFP_IND_SINGLE_PRESS = 1,
	/**< Single press: confirm pairing (OOB onboarding) */
	AT_CMD_TAG_GFP_IND_DOUBLE_PRESS = 2,
	/**< Double press: start reverse ringing (Find Phone) */
} at_cmd_tag_gfp_ind_action_t;

/**
 * @brief Callback used to simulate a GFP button press indication.
 *
 * @param action Button press action (see #at_cmd_tag_gfp_ind_action_t).
 * @return Tag AT command error code (at_cmd_tag_err_t).
 */
typedef at_cmd_tag_err_t (*at_cmd_tag_gfp_ind_cb_t)(at_cmd_tag_gfp_ind_action_t action);
#endif /* CONFIG_AT_CMD_TAGGFPIND */

#ifdef CONFIG_AT_CMD_TAGADDR
/**
 * @brief Callback used to handle AT+TAGADDR requests.
 *
 * @param protocol Tag protocol (0x01=fmna, 0x02=fhn, 0x04=stf).
 * @param[out] addr Advertising BT address for the given protocol.
 * @return Tag AT command error code (at_cmd_tag_err_t).
 */
typedef at_cmd_tag_err_t (*at_cmd_tag_addr_cb_t)(uint8_t protocol, bt_addr_le_t *addr);
#endif /* CONFIG_AT_CMD_TAGADDR */

/**
 * @brief Callback table for tag-related AT commands.
 */
typedef struct {
#ifdef CONFIG_AT_CMD_TAGINFO
	at_cmd_tag_get_info_cb_t get_info_cb;
#endif /* CONFIG_AT_CMD_TAGINFO */
#ifdef CONFIG_AT_CMD_TAGMODE
	at_cmd_tag_mode_cb_t mode_cb;
#endif /* CONFIG_AT_CMD_TAGMODE */
#ifdef CONFIG_AT_CMD_TAGSTART
	at_cmd_tag_start_cb_t start_cb;
#endif /* CONFIG_AT_CMD_TAGSTART */
#ifdef CONFIG_AT_CMD_TAGBATTERY
	at_cmd_tag_get_battery_cb_t get_battery_cb;
#endif /* CONFIG_AT_CMD_TAGBATTERY */
#ifdef CONFIG_AT_CMD_TAGRESET
	at_cmd_tag_reset_cb_t reset_cb;
#endif /* CONFIG_AT_CMD_TAGRESET */
#ifdef CONFIG_AT_CMD_TAGSTFIND
	at_cmd_tag_stfind_cb_t stfind_cb;
#endif /* CONFIG_AT_CMD_TAGSTFIND */
#ifdef CONFIG_AT_CMD_TAGFMNASN
	at_cmd_tag_fmna_sn_lookup_cb_t fmna_sn_lookup_cb;
#endif /* CONFIG_AT_CMD_TAGFMNASN */
#ifdef CONFIG_AT_CMD_TAGFMNAMFI
	at_cmd_tag_fmna_mfi_log_cb_t fmna_mfi_log_cb;
#endif /* CONFIG_AT_CMD_TAGFMNAMFI */
#ifdef CONFIG_AT_CMD_TAGCSUNPAIR
	at_cmd_tag_cs_unpair_cb_t cs_unpair_cb;
#endif /* CONFIG_AT_CMD_TAGCSUNPAIR */
#ifdef CONFIG_AT_CMD_TAGGFPIND
	at_cmd_tag_gfp_ind_cb_t gfp_ind_cb;
#endif /* CONFIG_AT_CMD_TAGGFPIND */
#ifdef CONFIG_AT_CMD_TAGMOTIONRPT
	at_cmd_tag_motionrpt_cb_t motionrpt_cb;
#endif /* CONFIG_AT_CMD_TAGMOTIONRPT */
#ifdef CONFIG_AT_CMD_TAGADDR
	at_cmd_tag_addr_cb_t addr_cb;
#endif /* CONFIG_AT_CMD_TAGADDR */
} at_cmd_set_tag_callbacks_t;

#endif /* CONFIG_AT_CMD_TAG_SET */
