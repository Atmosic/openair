/**
 *******************************************************************************
 *
 * @file calibration.h
 *
 * @brief Calibration data
 *
 * Copyright (C) Atmosic 2021-2024
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup CALIBRATION Calibration
 * @ingroup DRIVERS
 * @brief Calibration data
 * @{
 */

#include <stdint.h>
#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Duration for an RCOS measurement to remain valid in 32KHz cycles
#define LPC_RCOS_VALID	(5U * 32768U)	// 5 seconds

/// Platform NVDS tags
/// @note the range should within PARAM_ID_CAL1_MIN and PARAM_ID_CAL1_MAX or
/// within PARAM_ID_CAL2_MIN and PARAM_ID_CAL2_MAX
enum atm_nvds_tag {
    /// Identical to PARAM_ID_BD_ADDRESS
    ATM_TAG_BD_ADDRESS = 0x01, // Introduced to decouple from BLE header files

    /// Manufacturing calibration for RIF module
    ATM_TAG_RIF_CAL = 0xb0,
    /// Manufacturing calibration for MDM module
    ATM_TAG_MDM_CAL = 0xb1,
    /// Manufacturing overrides for LC registers
    ATM_TAG_BLE_RADIO_OVR = 0xb2,
    ATM_TAG_UNUSED1 = 0xb3,
    /// Customer configuration for WURX module
    ATM_TAG_PMU_WURX = 0xb4,
    ATM_TAG_UNUSED2 = 0xb5,
    ATM_TAG_UNUSED3 = 0xb6,
    ATM_TAG_UNUSED4 = 0xb7,
    ATM_TAG_ATE = 0xb8,
    ATM_TAG_CHIP_INFO = 0xb9,
    ATM_TAG_UNUSED6 = 0xba,
    ATM_TAG_UNUSED7 = 0xbb,
    /// Manufacturing calibration for various registers
    ATM_TAG_MISC_CAL = 0xbc,
    /// Customer design-specific calibration for various registers
    ATM_TAG_CUST_CFG = 0xbd,

    /// Manufacturing lock for factory data
    ATM_TAG_LOCK_FACTORY_DATA = 0xe0,

    /*
     * NOTE: Place new entires above this comment
     */
    /// Reserved secure-only tags
    ATM_SEC_ONLY_TAG_1 = 0xec,
    ATM_SEC_ONLY_TAG_2 = 0xed,
    ATM_SEC_ONLY_TAG_3 = 0xee,
    ATM_SEC_ONLY_TAG_4 = 0xef,

    /// Arbitrary 32,16,8-bit register write
    ATM_TAG_PMU_W = 0xfc,

    /// Arbitrary 32,16,8-bit register write
    ATM_TAG_MEM_W = 0xfd,

    /// Arbitrary 32,16,8-bit register read-modify-write
    ATM_TAG_MEM_RMW = 0xfe,
};

/// Manufacturing overrides for LC registers
struct BLE_radio_ovr_s {
    uint32_t RADIOCNTL0;
    uint32_t RADIOCNTL1;
    uint32_t RADIOCNTL2;
    uint32_t RADIOCNTL3;
    uint32_t RADIOPWRUPDN0;
    uint32_t RADIOPWRUPDN1;
    uint32_t RADIOPWRUPDN2;
    uint32_t RADIOPWRUPDN3;
    uint32_t RADIOTXRXTIM0;
    uint32_t RADIOTXRXTIM1;
    uint32_t RADIOTXRXTIM2;
    uint32_t RADIOTXRXTIM3;
};

struct chip_info_s {
    uint16_t version;
    uint8_t package;
    uint8_t harvesting;
    uint8_t test_day;
    uint8_t test_month;
    uint8_t test_year;
    uint8_t otp_version;
};
extern struct chip_info_s chip_info;
extern uint16_t chip_info_len;

#define CHIP_INFO__PACKAGE__INVALID	0
#define CHIP_INFO__PACKAGE__7x7		1
#define CHIP_INFO__PACKAGE__5x5		2
#define CHIP_INFO__PACKAGE__CSP		3
#define CHIP_INFO__PACKAGE__5x5_STACKED	5

#define MISC_CAL__MISC_FLASH_WAIT_XTAL_STABLE__SHIFT	0
#define MISC_CAL__MISC_FLASH_WAIT_XTAL_STABLE__MASK	0x01U
#define MISC_CAL__MISC_FLASH_WAIT_XTAL_STABLE__READ(src) \
		(((uint8_t)(src) & 0x01U) >> 0)

#define MISC_CAL__MISC_WURX_BIAS_AMP__SHIFT	1
#define MISC_CAL__MISC_WURX_BIAS_AMP__MASK	0x0EU
#define MISC_CAL__MISC_WURX_BIAS_AMP__READ(src) \
		(((uint8_t)(src) & 0x0EU) >> 1)

/// Manufacturing calibration for various registers
struct misc_cal_s {
    uint16_t version;
    int8_t tx_gain_offset;
    uint8_t misc;		// See MISC_CAL__MISC above

    uint32_t GADC_GAIN_OFFSET[4];
    uint32_t PSEQ_XTAL_BITS1;
    uint32_t PMU_TOP_PMU2A;
    uint32_t PMU_TOP_PMU3;
    uint32_t PMU_TOP_PMU4;
    uint8_t pmu_otp[6];
    uint8_t pad;
    uint8_t txmodgain2m_delta;
};
extern struct misc_cal_s misc_cal;
extern uint16_t misc_cal_len;

#define CUST_CAL__CUST_IGNORE_32KHZ_XTAL_CHECK__SHIFT	0
#define CUST_CAL__CUST_IGNORE_32KHZ_XTAL_CHECK__MASK	0x01U
#define CUST_CAL__CUST_IGNORE_32KHZ_XTAL_CHECK__READ(src) \
		(((uint8_t)(src) & 0x01U) >> 0)

#define CUST_CAL__CUST_NO_32KHZ_XTAL_ON_BOARD__SHIFT	1
#define CUST_CAL__CUST_NO_32KHZ_XTAL_ON_BOARD__MASK	0x02U
#define CUST_CAL__CUST_NO_32KHZ_XTAL_ON_BOARD__READ(src) \
		(((uint8_t)(src) & 0x02U) >> 0)

#define CUST_CAL__CUST_ENABLE_TCXO__SHIFT	2
#define CUST_CAL__CUST_ENABLE_TCXO__MASK	0x04U
#define CUST_CAL__CUST_ENABLE_TCXO__READ(src) \
		(((uint8_t)(src) & 0x04U) >> 0)

/// Customer design-specific calibration for various registers
struct cust_cfg_s {
    uint16_t version;
    int8_t external_pa_gain;
    uint8_t cust;		// See CUST_CAL__CUST above

    uint32_t PSEQ_XTAL_BITS0;
    uint32_t PMU_TOP_PMU2;
    uint32_t RIF_SYNTX5;
};
extern struct cust_cfg_s cust_cfg;
extern uint16_t cust_cfg_len;

extern uint8_t cal_pub_addr[6];
extern uint16_t cal_pub_addr_len;

/// Check for presence of calibration field
#define CAL_PRESENT(__s, __f) \
    (__s ## _len >= __OFFSET(__s, __f) + sizeof(__s.__f))

#define PMU_TOP_CAL(__s, __f, __reg) do { \
    if (CAL_PRESENT(__s, __f)) { \
	PMU_WRITE(TOP, __reg, __s.__f); \
    } \
} while (0)

#ifdef __cplusplus
}
#endif

/// @} CALIBRATION
