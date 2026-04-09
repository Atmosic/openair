/**
 *******************************************************************************
 *
 * @file fp_fmdn_reverse_ringing_adv.h
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) v2
 * Reverse Ringing - Advertisement-based Implementation
 *
 * Copyright (C) Atmosic 2026
 *
 *******************************************************************************
 */

#ifndef FP_FMDN_REVERSE_RINGING_ADV_H
#define FP_FMDN_REVERSE_RINGING_ADV_H

#include <zephyr/kernel.h>
#include <zephyr/bluetooth/bluetooth.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_FMDN_REVERSE_RINGING_ADV_TIMEOUT_SEC
#define ADV_RINGING_DURATION_SECONDS CONFIG_FMDN_REVERSE_RINGING_ADV_TIMEOUT_SEC
#else
/// Advertisement-based ringing duration in seconds (15-20 seconds per spec)
#define ADV_RINGING_DURATION_SECONDS 20
#endif

/// Advertisement-based ringing interval in milliseconds (at most 30ms per spec)
#define ADV_RINGING_INTERVAL_MS 30

/// Action nonce length in bytes
#define ADV_RINGING_NONCE_LEN 1

/// HMAC-SHA256 signature length (first 8 bytes of full 32-byte digest)
#define ADV_RINGING_SIGNATURE_LEN 8

/// Accessory-Initiated Action Frame Type for reverse ringing
#define ADV_RINGING_ACTION_TYPE 0x01

/// Advertisement-based ringing state
typedef struct {
	bool active;            ///< Whether advertisement-based ringing is active
	uint8_t current_nonce;  ///< Current action nonce (incremented per request)
	uint64_t start_time_ms; ///< Start time of advertisement in milliseconds
} fp_fmdn_reverse_ringing_adv_state_t;

/// Initialize advertisement-based ringing module
int fp_fmdn_reverse_ringing_adv_init(void);

/// Deinitialize advertisement-based ringing module
void fp_fmdn_reverse_ringing_adv_deinit(void);

/// Start advertisement-based ringing
/// Initiates high-frequency advertising for reverse ringing when no persistent connection exists
/// @return 0 on success, negative error code on failure
int fp_fmdn_reverse_ringing_adv_start(void);

/// Stop advertisement-based ringing
/// Stops the high-frequency advertising and cleans up resources
void fp_fmdn_reverse_ringing_adv_stop(void);

/// Get current advertisement-based ringing state
/// @return Pointer to advertisement-based ringing state
const fp_fmdn_reverse_ringing_adv_state_t *fp_fmdn_reverse_ringing_adv_get_state(void);

#ifdef __cplusplus
}
#endif

#endif /* FP_FMDN_REVERSE_RINGING_ADV_H */
