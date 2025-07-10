/**
 *******************************************************************************
 *
 * @file calibration.h
 *
 * @brief Calibration data
 *
 * Copyright (C) Atmosic 2021-2025
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

/// Platform NVDS tags
/// @note the range should within PARAM_ID_CAL1_MIN and PARAM_ID_CAL1_MAX or
/// within PARAM_ID_CAL2_MIN and PARAM_ID_CAL2_MAX
enum atm_nvds_tag {
    /// Manufacturing calibration for RIF module
    ATM_TAG_RIF_CAL = 0xb0,
    /// Manufacturing calibration for MDM module
    ATM_TAG_MDM_CAL = 0xb1,
    /// Manufacturing overrides for LC registers
    ATM_TAG_UNUSED8 = 0xb2,
    ATM_TAG_UNUSED1 = 0xb3,
    /// Customer configuration for WURX module
    ATM_TAG_UNUSED9 = 0xb4,
    ATM_TAG_UNUSED2 = 0xb5,
    ATM_TAG_UNUSED3 = 0xb6,
    ATM_TAG_UNUSED4 = 0xb7,
    ATM_TAG_ATE = 0xb8,
    ATM_TAG_CHIP_INFO = 0xb9,
    ATM_TAG_UNUSED6 = 0xba,
    ATM_TAG_UNUSED7 = 0xbb,
    /// Manufacturing calibration for various registers
    ATM_TAG_UNUSED10 = 0xbc,
    /// Customer design-specific calibration for various registers
    ATM_TAG_CUST_CFG = 0xbd,
    ATM_TAG_XTAL_CAL = 0xc2,
    ATM_TAG_PMU_CAL = 0xc3,
    ATM_TAG_GADC_CAL = 0xc4,
    ATM_TAG_CS_CAL = 0xc5,

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

// TODO: To be revisited
#define CHIP_INFO__PACKAGE__INVALID 0
#define CHIP_INFO__PACKAGE__7x7 1
#define CHIP_INFO__PACKAGE__5x5 2
#define CHIP_INFO__PACKAGE__CSP 3
#define CHIP_INFO__PACKAGE__5x5_STACKED 5
#define CHIP_INFO__PACKAGE__7x7_STACKED 6
#define CHIP_INFO__PACKAGE__BGA_STACKED 7
#define CHIP_INFO__PACKAGE__BGA 8
#define CHIP_INFO__SPARE_ENABLE_RADIO_INIT__SHIFT 0
#define CHIP_INFO__SPARE_ENABLE_RADIO_INIT__MASK 0x01U
#define CHIP_INFO__SPARE_ENABLE_RADIO_INIT__READ(src) \
    (((uint8_t)(src) & 0x01U) >> 0)

#define CHIP_INFO_HARVESTING_DISABLED
struct chip_info_s {
    uint16_t version;
    uint8_t package; // See CHIP_INFO__PACKAGE above
    uint8_t test_day;
    uint8_t test_month;
    uint8_t test_year;
    int16_t test_temperature;
    uint8_t otp_version;
    uint8_t spare; // See CHIP_INFO__SPARE above
};
extern struct chip_info_s chip_info;
extern uint16_t chip_info_len;

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
    uint8_t cust;		// See CUST_CAL__CUST above
    int8_t external_pa_gain;

    uint32_t lna_tia_lw_dccal_dc0;
    uint32_t lna_tia_lw_dccal_dc1;
    uint32_t lna_tia_lw_dccal_dc2;
    uint32_t lna_tia_lw_dccal_dc3;
    uint32_t lna_tia_md_dccal_dc0;
    uint32_t lna_tia_md_dccal_dc1;
    uint32_t lna_tia_md_dccal_dc2;
    uint32_t lna_tia_md_dccal_dc3;
    uint32_t lna_tia_hg_dccal_dc0;
    uint32_t lna_tia_hg_dccal_dc1;
    uint32_t lna_tia_hg_dccal_dc2;
    uint32_t lna_tia_hg_dccal_dc3;

    uint16_t pbr_offset;
    uint16_t rtt_offset;

    uint32_t pmu_top_pmu2;
};
extern struct cust_cfg_s cust_cfg;
extern uint16_t cust_cfg_len;

struct rif_cal_s {
    uint32_t bias;
    uint32_t rxbbf;
    uint32_t rxbbf_1m;
    uint32_t rxbbf_2m;
    uint32_t syntx_modgain;
    uint32_t syntx_vcocap;
    uint32_t lna;
    uint32_t lna_no_atten;
    uint8_t lna_atten_curr;
};

struct mdm_cal_s {
    uint32_t agcmeas;
    uint32_t dcoff;
    uint32_t pga_force_dccalresults;
    uint32_t iqcorr;
    uint32_t iqcorr2;
};

#define GADC_CAL_DATA_OUTSIDE_MISC
struct gadc_cal_s {
    uint32_t ctrl1;
    uint32_t gain_comp0;
    uint32_t gain_comp1;
    uint32_t gain_comp2;
    uint32_t gain_comp3;
    uint32_t gain_comp4;
    uint32_t gain_comp5;
    uint32_t gain_comp6;
    uint32_t gain_comp7;
    uint32_t offset_comp0;
    uint32_t offset_comp1;
    uint32_t offset_comp2;
    uint32_t offset_comp3;
};
extern struct gadc_cal_s gadc_cal;
extern uint16_t gadc_cal_len;

struct pmu_cal_s {
    uint32_t pmu_top_pmu2a;
    uint32_t pmu_top_pmu3;
    uint32_t pmu_top_pmu4;
    uint32_t pmu_top_pmu3_ldo;
};

struct xtal_cal_s {
    uint32_t xtal_bits1;
    uint32_t xtal_bits0;
};

struct cs_cal_s {
    uint8_t delay_unit;
    uint16_t delay_offset;
    uint8_t pga_gain;
    uint16_t lna_delays[8];
    uint16_t pga_delays[25];
    uint8_t lna_gain;
} __PACKED;

struct ate_s {
    uint32_t rsvd[7];
};

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
