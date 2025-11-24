/**
 *******************************************************************************
 *
 * @file fp_common.h
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Common Definitions
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

/**
 * @addtogroup ATM_BTFMDN Google Fast Pair Service
 * @brief Common Definitions of Fast Pair Service
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Memory copy with automatic offset increment
 * @param dst Destination pointer
 * @param src Source data
 * @param size Size to copy
 * @param offset Offset variable (will be incremented by size)
 */
#define FP_UTIL_MEMCPY_SHIFT(dst, src, size, offset)                                               \
	do {                                                                                       \
		memcpy((dst) + (offset), src, size);                                               \
		offset += size;                                                                    \
	} while (0)

/// FP adv BT ID index
enum {
	/// FP adv BT ID
	FP_ADV_BT_ID = 0,
	/// FP FMDN adv BT ID
	FP_FMDN_ADV_BT_ID,
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
	/// FP DULT adv BT ID
	FP_DULT_ADV_BT_ID,
#endif
	FP_ADV_BT_ID_MAX,
};

/// TX power of FP app
#define FP_APP_TX_PWR        0xEF
/// Length of FP app model ID
#define FP_APP_MODEL_ID_LEN  3
/// Length of FP anti-spoofing key of AES encrypted
#define FP_AS_AES_KEY_LEN    16
/// Length of FP anti-spoofing key of base64 encoded
#define FP_AS_BASE64_KEY_LEN 32
/// Model ID of FP app
#define FP_APP_MODEL_ID                                                                            \
	((CONFIG_FAST_PAIR_MODEL_ID >> 16) & 0xFF), ((CONFIG_FAST_PAIR_MODEL_ID >> 8) & 0xFF),     \
		(CONFIG_FAST_PAIR_MODEL_ID & 0xFF)

/// Google Fast Pair Mode Indexes
typedef enum {
	/// Index of Google Fast Pair initial mode
	FP_MODE_NONE = 0x00,
	/// Index of Google Fast Pair in pairing mode
	FP_MODE_PAIRING,
	/// Index of Google Fast Pair in pairing process mode
	FP_MODE_PAIRING_PROCESSING,
	/// Index of Google Fast Pair paired mode
	FP_MODE_PAIRED,
#ifdef CONFIG_FAST_PAIR_FMDN
	/// Index of Google Fast Pair in provisioning mode
	FP_MODE_PROVISIONING,
	/// Index of Google Fast Pair provisioned mode
	FP_MODE_PROVISIONED,
#endif
} fp_mode_t;

/// Length in bytes of the Account Key
#define FP_ACCOUNT_KEY_LEN 16
#define FP_ACCOUNT_KEY_CNT CONFIG_FAST_PAIR_MAX_ACCOUNT_KEY_COUNT

#ifdef CONFIG_FAST_PAIR_FMDN
/// FP FMDN Unwanted Tracking Protection Mode
typedef enum {
	/// Index of Google Fast Pair FMDN UTP off mode
	FP_FMDN_UTP_MODE_OFF = 0x40,
	/// Index of Google Fast Pair FMDN UTP on mode
	FP_FMDN_UTP_MODE_ON = 0x41
} fp_fmdn_utp_mode_t;

/// Length of the Ephemeral Identity Key (EIK)
#define FP_EIK_LEN 32

/// Length of the FMDN EID Key
#define FP_FMDN_EID_KEY_LEN 32

/// Length of the Ephemeral Identifier (EID)
#ifdef CONFIG_FMDN_ECC_SECP256R1
#define FP_FMDN_STATE_EID_LEN 32
#define FP_FMDN_CURVE_SEL     0x01
#else
#define FP_FMDN_STATE_EID_LEN 20
#define FP_FMDN_CURVE_SEL     0x00
#endif

#ifdef CONFIG_FAST_PAIR_FMDN_DULT
/// Length in bytes of the FMDN DULT Key
#define FP_FMDN_EID_DATA_LEN     10
#define FP_FMDN_EID_DATA_SHA_LEN 8
#define FP_FMDN_DULT_ID_LEN      (FP_FMDN_EID_DATA_LEN + FP_FMDN_EID_DATA_SHA_LEN)
#endif
#endif // CONFIG_FAST_PAIR_FMDN

// Fast Pair specification requires at least 64 bytes for personalized name storage
#define FP_PERSONALIZED_NAME_MAX_LEN 64

#ifdef __cplusplus
}
#endif

///@}
