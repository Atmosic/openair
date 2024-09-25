/**
 *******************************************************************************
 *
 * @file rf.c
 *
 * @brief Radio initialization and specific functions
 *
 * Copyright (C) Atmosic 2020-2024
 *
 *******************************************************************************
 */

#include "rwip_config.h"        // RW SW configuration
#include <string.h>             // for memcpy
#include "co_utils.h"           // common utility definition
#include "co_math.h"            // common math functions
#include "rf.h"                 // RF interface
#include "rwip.h"               // for RF API structure definition
#include "em_map.h"             // exchange table

#include "reg_blecore.h"        // ble core registers
#include "reg_em_ble_cs.h"      // control structure definitions

#if (NVDS_SUPPORT)
#include "nvds.h"
#endif // NVDS_SUPPORT
#include "calibration.h"

#include "rf_api.h"
#define RF_INTERNAL_GUARD
#include "rf_internal.h"

#ifndef CMSDK_WRPR
#define CMSDK_WRPR CMSDK_WRPR0_NONSECURE
#endif

#define RSSI_HIGH_THRHLD     -50
#define RSSI_LOW_THRHLD      -70
#define RSSI_INTERF_THRHLD   -70

// TX max power
#define DEFAULT_RF_POWER_MIN RF_POWER_MINUS_20_DBM
#define DEFAULT_RF_POWER_MAX RF_POWER_4_DBM

// Power table
static int8_t const RF_TX_PW_CONV_TBL[RF_POWER_LVL_NUM] = {
    [RF_POWER_MINUS_20_DBM] = -20,
    [RF_POWER_MINUS_10_DBM] = -10,
    [RF_POWER_MINUS_8_DBM] = -8,
    [RF_POWER_MINUS_6_DBM] = -6,
    [RF_POWER_MINUS_4_DBM] = -4,
    [RF_POWER_MINUS_2_DBM] = -2,
    [RF_POWER_0_DBM] = 0,
    [RF_POWER_2_DBM] = 2,
    [RF_POWER_4_DBM] = 4,
    [RF_POWER_6_DBM] = 6,
    [RF_POWER_8_DBM] = 8,
    [RF_POWER_10_DBM] = 10,
};

static int8_t tx_gain_offset;
static uint8_t txpwr_max;

/**
 * @brief Read access
 *
 * @param[in] addr    register address
 *
 * @return uint32_t value
 */
static uint32_t rf_reg_rd(uint32_t addr)
{
    return 0;
}

/**
 * @brief Write access
 *
 * @param[in] addr    register address
 * @param[in] value   value to write
 */
static void rf_reg_wr(uint32_t addr, uint32_t value)
{
}

/**
 * @brief Initialize frequency table in the exchange memory
 */
static void rf_em_init(void)
{
    uint8_t idx = 0;
    uint8_t temp_freq_tbl[EM_RF_FREQ_TABLE_LEN];

    while(idx < EM_RF_FREQ_TABLE_LEN)
    {
        temp_freq_tbl[idx] = 2 * idx;
        idx++;
    }

    em_wr(&temp_freq_tbl[0], EM_FT_OFFSET, EM_RF_FREQ_TABLE_LEN);
}

/**
 *
 * @brief Convert RSSI to dBm
 *
 * @param[in] rssi_reg RSSI read from the HW registers
 *
 * @return The converted RSSI
 *
 */
static int8_t rf_rssi_convert(uint8_t rssi_reg)
{
    return (rssi_reg);
}

static uint8_t rf_txpwr_cs_get_in_range(int8_t txpwr_dbm, uint8_t option,
    uint8_t min_idx, uint8_t max_idx)
{
    ASSERT_ERR(option <= TXPWR_CS_NEAREST);
    ASSERT_ERR(min_idx <= max_idx);

    uint8_t i;
    int8_t txpwr_adj;

    // offset by calibrated chip gain and external PA gain
    // assume that underflow/overflow checking is not needed
    txpwr_adj = txpwr_dbm - tx_gain_offset;

    for (i = min_idx; i < max_idx; i++) {
        // Loop until we find a power higher than or equal to the requested one
        if (RF_TX_PW_CONV_TBL[i] >= txpwr_adj) {
            break;
        }
    }

    if ((RF_TX_PW_CONV_TBL[i] > txpwr_adj) && (i > min_idx)) {
        if ((option == TXPWR_CS_LOWER) || ((option == TXPWR_CS_NEAREST) &&
	    (co_abs(txpwr_adj - RF_TX_PW_CONV_TBL[i - 1]) <
	    co_abs(txpwr_adj - RF_TX_PW_CONV_TBL[i])))) {
            i--;
        }
    }

    return (i);
}

/**
 *
 * @brief Get the TX power as control structure TX power field from a value in dBm.
 *
 * @param[in] txpwr_dbm   TX power in dBm
 * @param[in] option      If TXPWR_CS_LOWER, return index equal to or lower than requested
 *                        If TXPWR_CS_HIGHER, return index equal to or higher than requested
 *                        If TXPWR_CS_NEAREST, return index nearest to the desired value
 *
 * @return The index of the TX power
 *
 */
static uint8_t rf_txpwr_cs_get(int8_t txpwr_dbm, uint8_t option)
{
    return rf_txpwr_cs_get_in_range(txpwr_dbm, option, rwip_rf.txpwr_min,
	txpwr_max);
}

/**
 *
 * @brief Init RF sequence after reset.
 *
 */
static void rf_reset(void)
{
}

/**
 *
 * @brief Enable/disable force AGC mechanism
 *
 * @param[in]  True: Enable / False: disable
 *
 */
static void rf_force_agc_enable(bool en)
{
}

/**
 *
 * @brief Get TX power in dBm from the index in the control structure
 *
 * @param[in] txpwr_idx  Index of the TX power in the control structure
 *
 * @return The TX power in dBm
 *
 */
static int8_t rf_txpwr_dbm_get(uint8_t txpwr_idx)
{
    int8_t txpwr_dbm_tbl;

    // power table is the same for BR and EDR
    txpwr_dbm_tbl = RF_TX_PW_CONV_TBL[txpwr_idx];

    // offset by calibrated chip gain and external PA gain
    // assume that underflow/overflow checking is not needed
    return (txpwr_dbm_tbl + tx_gain_offset);
}

/**
 *
 * @brief Sleep function for the RF.
 *
 */
static void rf_sleep(void)
{
    rep_vec_invoke(rv_rf_sleep, NULL);

    ble_deepslcntl_set(ble_deepslcntl_get() |
                      BLE_DEEP_SLEEP_ON_BIT |    // RW BLE Core sleep
                      BLE_RADIO_SLEEP_EN_BIT |   // Radio sleep
                      BLE_OSC_SLEEP_EN_BIT);     // Oscillator sleep
}

/**
 *
 * @brief Get the index of maximum TX power according to activity and PHY
 *
 * @param[in] prot_type   Protocol type
 * @param[in] actv_idx    Activity index
 * @param[in] phy         Phy type
 *
 * @return Maximum TX power value
 *
 */
static uint8_t rf_txpwr_max_get(uint8_t prot_type, uint8_t actv_idx,
    uint8_t phy)
{
    return txpwr_max;
}

static void rf_wake(void)
{
    rep_vec_invoke(rv_rf_wake, NULL);
}

/**
 * RADIO FUNCTION INTERFACE
 */
void rf_init(struct rwip_rf_api *api)
{
    tx_gain_offset = 0;
#if (NVDS_SUPPORT && defined(FIXME))
    if (CAL_PRESENT(misc_cal, tx_gain_offset)) {
	tx_gain_offset += misc_cal.tx_gain_offset;
    }
    if (CAL_PRESENT(cust_cfg, external_pa_gain)) {
	tx_gain_offset += cust_cfg.external_pa_gain;
    }
#endif // NVDS_SUPPORT

    // ********************************************************
    // *       Initialize the RF driver API structure         *
    // ********************************************************

    api->reg_rd        = rf_reg_rd;
    api->reg_wr        = rf_reg_wr;
    api->txpwr_dbm_get = rf_txpwr_dbm_get;
    api->txpwr_min     = DEFAULT_RF_POWER_MIN;
    txpwr_max = DEFAULT_RF_POWER_MAX;
    api->txpwr_max_get = rf_txpwr_max_get;
    api->sleep         = rf_sleep;
    api->wake          = rf_wake;
    api->reset         = rf_reset;
    api->rssi_convert  = rf_rssi_convert;
    api->txpwr_cs_get  = rf_txpwr_cs_get;

    api->force_agc_enable = rf_force_agc_enable;

    // Initialize the RSSI thresholds (high, low)
    // These are 'real' signed values in dBm
    uint8_t length = PARAM_LEN_RSSI_THR;
    if (rwip_param.get(PARAM_ID_RSSI_HIGH_THR, &length, (uint8_t*)&api->rssi_high_thr) != PARAM_OK)
    {
	api->rssi_high_thr = RSSI_HIGH_THRHLD;
    }
    if (rwip_param.get(PARAM_ID_RSSI_LOW_THR, &length, (uint8_t*)&api->rssi_low_thr) != PARAM_OK)
    {
	api->rssi_low_thr = RSSI_LOW_THRHLD;
    }

    // ********************************************************
    // *             Initialize Exchange Memory               *
    // ********************************************************

    rf_em_init();

    // ********************************************************
    // *          Initialize BLE/BT Core Registers            *
    // ********************************************************

#if (NVDS_SUPPORT && defined(FIXME))
    struct BLE_radio_ovr_s ovr;
    nvds_tag_len_t ovr_len = sizeof(ovr);
    if (nvds_get(PARIS_TAG_BLE_RADIO_OVR, &ovr_len, (uint8_t *)&ovr) == NVDS_OK) {
	ble_radiocntl0_set(ovr.RADIOCNTL0);
	ble_radiocntl1_set(ovr.RADIOCNTL1);
	ble_radiocntl2_set(ovr.RADIOCNTL2);
	ble_radiocntl3_set(ovr.RADIOCNTL3);
	ble_radiopwrupdn0_set(ovr.RADIOPWRUPDN0);
	ble_radiopwrupdn1_set(ovr.RADIOPWRUPDN1);
	ble_radiopwrupdn2_set(ovr.RADIOPWRUPDN2);
	ble_radiopwrupdn3_set(ovr.RADIOPWRUPDN3);
	ble_radiotxrxtim0_set(ovr.RADIOTXRXTIM0);
	ble_radiotxrxtim1_set(ovr.RADIOTXRXTIM1);
	ble_radiotxrxtim2_set(ovr.RADIOTXRXTIM2);
	ble_radiotxrxtim3_set(ovr.RADIOTXRXTIM3);
	return;
    }
#endif // NVDS_SUPPORT

    /* BLE RADIOCNTL0 */
    ble_radiocntl0_pack(/*uint16_t spiptr*/   0,
                        /*uint8_t  spicfg*/   0,
                        /*uint8_t  spifreq*/  0,
                        /*uint8_t  spigo*/    0);

    /* BLE RADIOCNTL1 */
    ble_radiocntl1_pack(/*uint8_t  forceagcen*/      0,
                        /*uint8_t  forceiq*/         0,
                        /*uint8_t  rxdnsl*/          0,
                        /*uint8_t  txdnsl*/          0,
                        /*uint16_t forceagclength*/  0,
                        /*uint8_t  syncpulsemode*/   1,
                        /*uint8_t  syncpulsesrc*/    1,
                        /*uint8_t  dpcorren*/        0,
                        /*uint8_t  jefselect*/       1,
                        /*uint8_t  xrfsel*/          0x2,
                        /*uint8_t  subversion*/      0);

    // Indicate which PHYs are supported
    uint8_t phy_msk = 0;
    #if (BLE_PHY_2MBPS_SUPPORT)
    phy_msk |= (1 << 0);
    #endif //(BLE_PHY_2MBPS_SUPPORT)
    #if (BLE_PHY_CODED_SUPPORT)
    phy_msk |= (1 << 1);
    #endif //(BLE_PHY_CODED_SUPPORT)

    /* BLE RADIOCNTL2 */
    ble_radiocntl2_pack(/*uint8_t  lrsynccompmode*/ 0x3, // Unused when RW_BLE_LONG_RANGE_RX_INST is undefined
                        /*uint8_t  rxcitermbypass*/ 0x1, // Don't send CI bit 1, or TERM1[2:0]
                        /*uint8_t  lrvtbflush*/     0x14, // yow, 20 for now
                        /*uint8_t  phymsk*/         phy_msk,
                        /*uint8_t  lrsyncerr*/      0,
                        /*uint8_t  syncerr*/        0,
                        /*uint16_t freqtableptr*/   EM_FT_OFFSET >> 2);

    /* BLE RADIOCNTL3 */
    ble_radiocntl3_pack(/*uint8_t rxrate3cfg*/    0x3,
                        /*uint8_t rxrate2cfg*/    0x2,
                        /*uint8_t rxrate1cfg*/    0x1,
                        /*uint8_t rxrate0cfg*/    0x0,
                        /*uint8_t getrssidelay*/  0x0,
                        /*uint8_t rxsyncrouting*/ 0x0,
                        /*uint8_t rxvalidbeh*/    0x0,
                        /*uint8_t txrate3cfg*/    0x3,
                        /*uint8_t txrate2cfg*/    0x2,
                        /*uint8_t txrate1cfg*/    0x1,
                        /*uint8_t txrate0cfg*/    0x0,
                        /*uint8_t txvalidbeh*/    0x0);

    if (CAL_PRESENT(chip_info, package) &&
        chip_info.package == CHIP_INFO__PACKAGE__CSP) {
        /* BLE RADIOPWRUPDN0 */
        ble_radiopwrupdn0_pack(/*uint8_t syncposition0*/ 0,
                               /*uint8_t rxpwrup0*/      0x50,
                               /*uint8_t txpwrdn0*/      0x2,
                               /*uint8_t txpwrup0*/      0x44);

        /* BLE RADIOPWRUPDN1 */
        ble_radiopwrupdn1_pack(/*uint8_t syncposition1*/ 0,
                               /*uint8_t rxpwrup1*/      0x50,
                               /*uint8_t txpwrdn1*/      0x2,
                               /*uint8_t txpwrup1*/      0x3e);

        /* BLE RADIOPWRUPDN2 */
        ble_radiopwrupdn2_pack(/*uint8_t syncposition2*/ 0,
                               /*uint8_t rxpwrup2*/      0x50,
                               /*uint8_t txpwrdn2*/      0x2,
                               /*uint8_t txpwrup2*/      0x44);

        /* BLE RADIOPWRUPDN3 */
        ble_radiopwrupdn3_pack(/*uint8_t txpwrdn3*/      0x2,
                               /*uint8_t txpwrup3*/      0x44);
    } else {
        /* BLE RADIOPWRUPDN0 */
        ble_radiopwrupdn0_pack(/*uint8_t syncposition0*/ 0,
                               /*uint8_t rxpwrup0*/      0x50,
                               /*uint8_t txpwrdn0*/      0x2,
                               /*uint8_t txpwrup0*/      0x3c);

        /* BLE RADIOPWRUPDN1 */
        ble_radiopwrupdn1_pack(/*uint8_t syncposition1*/ 0,
                               /*uint8_t rxpwrup1*/      0x50,
                               /*uint8_t txpwrdn1*/      0x2,
                               /*uint8_t txpwrup1*/      0x3e);

        /* BLE RADIOPWRUPDN2 */
        ble_radiopwrupdn2_pack(/*uint8_t syncposition2*/ 0,
                               /*uint8_t rxpwrup2*/      0x50,
                               /*uint8_t txpwrdn2*/      0x2,
                               /*uint8_t txpwrup2*/      0x3c);

        /* BLE RADIOPWRUPDN3 */
        ble_radiopwrupdn3_pack(/*uint8_t txpwrdn3*/      0x2,
                               /*uint8_t txpwrup3*/      0x3c);
    }

    /* BLE RADIOTXRXTIM0 */
    ble_radiotxrxtim0_pack(/*uint8_t rfrxtmda0*/   0x4,
                           /*uint8_t rxpathdly0*/  0x4,
                           /*uint8_t txpathdly0*/  0x1);

    /* BLE RADIOTXRXTIM1 */
    ble_radiotxrxtim1_pack(/*uint8_t rfrxtmda1*/   0x2,
                           /*uint8_t rxpathdly1*/  0x2,
                           /*uint8_t txpathdly1*/  0x1);

    /* BLE RADIOTXRXTIM2 */
    ble_radiotxrxtim2_pack(/*uint8_t rxflushpathdly2*/ 0xe,
			   /*uint8_t rfrxtmda2*/       0x9b,
			   /*uint8_t rxpathdly2*/      0x2c,
                           /*uint8_t txpathdly2*/      0x1);

    /* BLE RADIOTXRXTIM3 */
    ble_radiotxrxtim3_pack(/*uint8_t rxflushpathdly3*/ 0xe,
			   /*uint8_t rfrxtmda3*/       0x29,
                           /*uint8_t txpathdly3*/      0x1);

    /* BLE_DFCNTL0_1US */
    ble_dfcntl0_1us_pack(/*uint8_t rxsampstinst01us*/ 0x9,
			 /*uint8_t rxswstinst01us*/   0x1a,
			 /*uint8_t txswstinst01us*/   0x1a);

    /* BLE_DFCNTL0_2US */
    ble_dfcntl0_2us_pack(/*uint8_t rxsampstinst02us*/ 0x9,
			 /*uint8_t rxswstinst02us*/   0x1a,
			 /*uint8_t txswstinst02us*/   0x1a);

    /* BLE_DFCNTL1_1US */
    ble_dfcntl1_1us_pack(/*uint8_t rxsampstinst11us*/ 0x7,
			 /*uint8_t rxswstinst11us*/   0x18,
			 /*uint8_t txswstinst11us*/   0x19);

    /* BLE_DFCNTL1_2US */
    ble_dfcntl1_2us_pack(/*uint8_t rxsampstinst12us*/ 0x7,
			 /*uint8_t rxswstinst12us*/   0x18,
			 /*uint8_t txswstinst12us*/   0x19);
}

int8_t rf_set_txpwr_maximum_val(int8_t txpwr_dbm)
{
    txpwr_max = rf_txpwr_cs_get_in_range(txpwr_dbm, TXPWR_CS_LOWER, 0,
	RF_POWER_LVL_NUM - 1);
    return rwip_rf.txpwr_dbm_get(txpwr_max);
}

void rf_set_txpwr_override(int8_t txpwr_dbm)
{
    uint8_t gain_index = rf_txpwr_cs_get_in_range(txpwr_dbm, TXPWR_CS_LOWER, 0,
	RF_POWER_LVL_NUM - 1);

    rf_core_set_txpwr_override(gain_index);
}

int8_t rf_set_cs_txpwr_val(uint8_t cs_idx, int8_t txpwr_dbm)
{
    uint8_t gain_index = rwip_rf.txpwr_cs_get(txpwr_dbm, TXPWR_CS_LOWER);
    em_ble_txrxcntl_txpwr_setf(cs_idx, gain_index);
    return rwip_rf.txpwr_dbm_get(gain_index);
}

void rf_set_adv_channel(uint8_t mask, uint8_t offset_mhz)
{
#define RF_CHANNEL_OFFSET_1MHZ 1
#define RF_CHANNEL_OFFSET_81MHZ 81
#define RF_WHITENING_SEED_1MHZ 0x35
#define RF_WHITENING_SEED_81MHZ 0x33

    if (offset_mhz == RF_CHANNEL_OFFSET_1MHZ) {
	rf_enable_whitening(RF_WHITENING_SEED_1MHZ);
    } else if (offset_mhz == RF_CHANNEL_OFFSET_81MHZ) {
	rf_enable_whitening(RF_WHITENING_SEED_81MHZ);
    }

    if (mask & RF_ADV_CH_37) {
	em_wr8p(EM_FT_OFFSET + 0, offset_mhz);
    }

    if (mask & RF_ADV_CH_38) {
	em_wr8p(EM_FT_OFFSET + 12, offset_mhz);
    }

    if (mask & RF_ADV_CH_39) {
	em_wr8p(EM_FT_OFFSET + 39, offset_mhz);
    }
}

void rf_reset_ch_offsets(void)
{
    rf_core_reset_ch_offsets();

    // Set the frequency offsets (in MHz)
    uint8_t idx = 0;
    uint8_t freq_tbl[EM_RF_FREQ_TABLE_LEN];
    while (idx < EM_RF_FREQ_TABLE_LEN) {
        freq_tbl[idx] = 2 * (idx + 1);
        idx++;
    }

    em_wr(&freq_tbl[0], EM_FT_OFFSET, EM_RF_FREQ_TABLE_LEN);
}

bool rf_set_pin_xparx(uint8_t pin)
{
    if (rf_core_set_pin_xparx(pin)) {
	return true;
    }

    uint8_t diag0;
    if (pin == 20) {
	diag0 = 0x26;
    } else if (pin == 21) {
	diag0 = 0x3;
    } else if (pin == 23) {
	diag0 = 0x32;
    } else if (pin == 25) {
	diag0 = 0x1f;
    } else {
	return false;
    }

    CMSDK_WRPR->DBG_CTRL = 0;
    ble_diagcntl_pack(0, 0, 0, 0, 0, 0, 1, diag0);
    return true;
}
