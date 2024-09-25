/**
 ******************************************************************************
 *
 * @file atm_vendor.c
 *
 * @brief Atmosic HCI Vendor Command
 *
 * Copyright (C) Atmosic 2020-2024
 *
 ******************************************************************************
 */
#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <zephyr/arch/cpu.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/util.h>
#include <zephyr/init.h>
#include <zephyr/sys/reboot.h>
#include "atm_hci_uart.h"
#endif
#include <inttypes.h>
#include <stddef.h>
#include "arch.h"
#include "at_apb_pseq_regs_core_macro.h"
#include "at_wrpr.h"
#include "rif_regs_core_macro.h"
#include "string.h"
#include "atm_vendor.h"
#include "atm_vendor_internal.h"
#include "atm_utils_c.h"
#include "_reg_blecore.h"
#include "spi.h"
#include "pmu_spi.h"
#include "radio_spi.h"
#include "at_clkrstgen.h"
#include "atm_bp_clock.h"
#ifndef CONFIG_SOC_FAMILY_ATM
#include "vectors.h"
#include "intisr.h"
#include "hci.h"
#include "interrupt.h"
#include "ahi.h"
#include "atm_ble.h"
#include "uart_rep_vec.h"
#include "reset.h"
#include "uart.h"
#include "sw_event.h"
#endif

#ifdef CFG_VND_IO_CTRL
#include "atm_gpio.h"
#endif

#ifdef CFG_VND_TAG_RD
#include "nvds.h"
#endif

#ifdef CFG_VND_SET_BDDR
#include "framework_lib.h"
#endif

#ifdef CFG_VND_GPIO_TEST
#include "at_pinmux.h"
#include "pinmux.h"
#endif

#ifdef CFG_VND_PSM
#include "pseq.h"
#endif

#ifdef CFG_NONRF_HARV
#include "pmu.h"
#endif

#ifdef CFG_VND_COREMARK
#include "atm_coremark_port.h"
#endif

#ifdef CONFIG_SOC_FAMILY_ATM
#ifndef H4_MSG_LC_HCI_EVT
#define H4_MSG_LC_HCI_EVT 0x04
#endif
#endif

#define SET_HCI_EVT_STATUS(status) *(*bufptr + HCI_EVT_STATUS_POS) = status;

#ifdef CONFIG_SOC_FAMILY_ATM
#define LOG_HCI_VENDOR_MODULE_NAME atm_vendor
LOG_MODULE_REGISTER(LOG_HCI_VENDOR_MODULE_NAME, CONFIG_ATM_LOG_DEFAULT_LEVEL);
#else
static uint8_t const AG_READY_EVT[] = {H4_MSG_LC_HCI_EVT, HCI_EVT_VENDOR, 0x06,
    SEVT_DUT_READY, 'A', 'T', 'M', 'F', 'G'};
static uint8_t *ag_ready_evt;
static struct vendor_handler const *curr_vnd_hdlr;
static uint8_t rx_state;
static bool internal_reset;
#endif // CONFIG_SOC_FAMILY_ATM

static uint8_t hcievent_buffer[258];
__UNINIT static bool volatile hci_vendor_en;

static union {
#ifdef CFG_VND_EN_TXCW
    // vendor_stage: S_VENDOR_EN_TXCW
    en_txsw_cmd_t en_txcw_cmd;
#endif
#ifdef CFG_VND_CAP
    // vendor_stage: VENDOR_FREQ_CAL
    freqcal_cmd_t freq_cal_cmd;
#endif
#ifdef CFG_VND_SYS_MMR
    // vendor_stage: VENDOR_MMR
    mm_r_cmd_t mmr_cmd;
#endif
#ifdef CFG_VND_PV_TEST
    // vendor_stage: VENDOR_PV_TEST
    pv_test_cmd_t pv_test_cmd;
#endif
#ifdef CFG_VND_PSM
    // vendor_stage: VENDOR_PSM
    psm_cmd_t psm_cmd;
#endif
#ifdef CFG_VND_GADC
    // vendor_stage: VENDOR_GADC_CH_SAMPLE_START
    // vendor_state: VENDOR_GADC_CH_SAMPLE_GET
    // vendor_state: VENDOR_GADC_CH_CALI_START
    // vendor_state: VENDOR_GADC_CH_CALI_GET
    // vendor_state: VENDOR_GADC_CALI_SETTING
    gadc_cmd_t gadc_cmd;
#endif
#ifdef CFG_VND_IO_CTRL
    // vendor_stage: VENDOR_IO
    io_cmd_t io_cmd;
#endif
#ifdef CFG_VND_TAG_RD
    // vendor_stage: VENDOR_TAG_READ
    tag_r_cmd_t tag_cmd;
#endif
#ifdef CFG_VND_SET_BDDR
    // vendor_stage: VENDOR_SET_BDADDR
    set_bd_addr_cmd_t bd_addr_cmd;
#endif
#ifdef CFG_VND_MALLOC
    // vendor_stage: VENDOR_MALLOC
    malloc_cmd_t malloc_cmd;
    malloc_ctx_t malloc_ctx;
#endif
#ifdef CFG_VND_DBG_MMR
    // vendor_stage: VENDOR_RD_MEM
    rd_mem_cmd_t dbg_rd_mem_cmd;
#endif
#ifdef CFG_VND_DBG_MMW
    // vendor_stage: VENDOR_WR_MEM
    wr_mem_cmd_t dbg_wr_mem_cmd;
#endif
#ifdef CFG_VND_BLE_REGR
    // vendor_stage: VENDOR_BLE_REG_RD
    ble_reg_rd_cmd_t dbg_ble_reg_rd_cmd;
#endif
#ifdef CFG_VND_BLE_REGW
    // vendor_stage: VENDOR_BLE_REG_WR
    ble_reg_wr_cmd_t dbg_ble_reg_wr_cmd;
#endif
#ifdef CFG_VND_PMU_RADIO_REGR
    // vendor_stage: VENDOR_PMU_RADIO_REG_RD
    pmu_radio_reg_rd_cmd_t dbg_pmu_radio_reg_rd_cmd;
#endif
#ifdef CFG_VND_PMU_RADIO_REGW
    // vendor_stage: VENDOR_PMU_RADIO_REG_WR
    pmu_radio_reg_wr_cmd_t dbg_pmu_radio_reg_wr_cmd;
#endif
#ifdef CFG_VND_COREMARK
    // vendor_stage: VENDOR_COREMARK
    coremark_cmd_t coremark_cmd;
#endif
#if (defined(CFG_VND_WFI) || defined(CFG_VND_NO_CLOCK) || \
    defined(CFG_VND_WHILE_ONE))
    // power_cmd is used by these commands below
    // vendor_stage: VENDOR_WFI
    // vendor_stage: VENDOR_NO_CLOCK
    // vendor_stage: VENDOR_WHILE_ONE
    power_cmd_t power_cmd;
#endif
    uint8_t dummy;
} dat;

#if defined(CFG_VND_BLE_REGR) || defined(CFG_VND_BLE_REGW) || \
    defined(CFG_VND_PMU_RADIO_REGR) || defined(CFG_VND_PMU_RADIO_REGW) || \
    defined(CFG_VND_DBG_MMR) || defined(CFG_VND_DBG_MMW)
__INLINE bool check_evt_unsupport(uint8_t **bufptr)
{
#ifdef CONFIG_SOC_FAMILY_ATM
    return true;
#else
    if ((*(*bufptr + 1) == HCI_EVT_CMD_CPM &&
	*(*bufptr + HCI_EVT_STATUS_POS) == HCI_EVT_ERROR) ||
	(*(*bufptr + 1) == HCI_EVT_CMD_CS &&
	*(*bufptr + HCI_EVT_CS_STATUS_POS) == HCI_EVT_ERROR)) {
	return true;
    }
    return false;
#endif
}
#endif

static void init_hci_event(uint8_t ocf, uint8_t ogf, uint8_t extra_len,
    uint8_t status, uint8_t **bufptr, uint32_t *size)
{
    hcievent_buffer[0] = H4_MSG_LC_HCI_EVT;
    hcievent_buffer[1] = HCI_EVT_CMD_CPM;
    hcievent_buffer[2] = (extra_len + BASIC_HCI_EVT_HD_LEN);
    hcievent_buffer[3] = HCI_EVT_NOC;
    hcievent_buffer[4] = ocf;
    hcievent_buffer[5] = ogf;
    hcievent_buffer[6] = status;
    *bufptr = hcievent_buffer;
    *size = (extra_len + BASIC_HCI_EVT_CMD_LEN);
}

#ifdef CFG_VND_SET_BDDR
static void vendor_set_public_bd_addr_handler(uint8_t *buf)
{
    memcpy(dat.bd_addr_cmd.bd_addr, buf, BD_ADDR_LEN);
}

static void set_bd_addr(uint8_t const *addr)
{
    if (!addr) {
	return;
    }
    framework_set_llm_env_pub_addr((ble_bdaddr_t const *)addr);
}

static void vendor_set_public_bd_addr_cmp_handler(uint8_t **bufptr,
    uint32_t *size)
{
    set_bd_addr(dat.bd_addr_cmd.bd_addr);
    init_hci_event(SET_BD_ADDR_CMD_OCF, SET_BD_ADDR_CMD_OGF, 0,
	HCI_EVT_SUCCESS, bufptr, size);
}
#endif

#ifdef CFG_VND_SET_ADV_CH
static uint8_t ch_offset;
static adv_channel_t ch_mask;
static void vendor_set_adv_ch_handler(uint8_t *buf)
{
    ch_mask = *buf;
    ch_offset = *(buf + 1);
}

// Handle set advertising channel HCI command
static void set_adv_ch(adv_channel_t mask, uint8_t offset_mhz)
{
    static bool reset_ch_offsets = false;
    if (!reset_ch_offsets) {
	atm_ble_reset_ch_offsets();
	reset_ch_offsets = true;
    }

    atm_ble_set_adv_channel(mask, offset_mhz);
    APP_TRACE("    set adv ch [%u] to [%u] MHz", mask, offset_mhz);
}

static void vendor_set_adv_ch_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    init_hci_event(SET_ADV_CH_CMD_OCF, SET_ADV_CH_CMD_OGF, 0, HCI_EVT_SUCCESS,
	bufptr, size);

    if (!(ch_mask & (BLE_ADV_CHANNEL_37 | BLE_ADV_CHANNEL_38 |
	BLE_ADV_CHANNEL_39)) || !((ch_offset >= 0) && (ch_offset <= 80))) {
	SET_HCI_EVT_STATUS(HCI_EVT_ERROR);
    } else {
	set_adv_ch(ch_mask, ch_offset);
    }
}
#endif

#ifdef CFG_VND_BLE_REGR
static void vendor_dbg_ble_reg_rd_handler(uint8_t *buf)
{
    dat.dbg_ble_reg_rd_cmd.reg_addr = atm_get_le16(buf);
}

static void vendor_dbg_ble_reg_rd_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    if (!check_evt_unsupport(bufptr)) {
	// stack support
	APP_TRACE("stack support");
	return;
    }

#define REG_BLE_RD(addr) (*(volatile uint32_t *)(REG_BLECORE_BASE_ADDR + addr))

    // stack not support, implement here
    APP_TRACE("stack not support");
    uint32_t value = REG_BLE_RD(dat.dbg_ble_reg_rd_cmd.reg_addr);
    init_hci_event(BLE_REG_RD_CMD_OCF, BLE_REG_RD_CMD_OGF, 6, HCI_EVT_SUCCESS,
	bufptr, size);

    atm_set_le16(&hcievent_buffer[7], dat.dbg_ble_reg_rd_cmd.reg_addr);
    atm_set_le32(&hcievent_buffer[9], value);
}
#endif

#ifdef CFG_VND_BLE_REGW
static void vendor_dbg_ble_reg_wr_handler(uint8_t *buf)
{
    dat.dbg_ble_reg_wr_cmd.reg_addr = atm_get_le16(buf);
    dat.dbg_ble_reg_wr_cmd.reg_value = atm_get_le32(&buf[2]);
}

static void vendor_dbg_ble_reg_wr_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    if (!check_evt_unsupport(bufptr)) {
	// stack support
	APP_TRACE("stack support");
	return;
    }

#define REG_BLE_WR(addr, value) \
    (*(volatile uint32_t *)(REG_BLECORE_BASE_ADDR + addr)) = (value)

    // stack not support, implement here
    APP_TRACE("stack not support");
    REG_BLE_WR(dat.dbg_ble_reg_wr_cmd.reg_addr,
	dat.dbg_ble_reg_wr_cmd.reg_value);
    init_hci_event(BLE_REG_WR_CMD_OCF, BLE_REG_WR_CMD_OGF, 2, HCI_EVT_SUCCESS,
	bufptr, size);

    atm_set_le16(&hcievent_buffer[7], dat.dbg_ble_reg_wr_cmd.reg_addr);
}
#endif

#ifdef CFG_VND_PMU_RADIO_REGR

static uint32_t do_pmu_radio_read(uint32_t block, uint32_t addr, uint8_t is_pmu)
{
    int resp;

    if (is_pmu) {
	WRPR_CTRL_PUSH(CMSDK_PMU, WRPR_CTRL__CLK_ENABLE)
	{
	    resp = spi_pmuradio_read_word(&spi_pmu, block, addr);
	}
	WRPR_CTRL_POP();
    } else {
	WRPR_CTRL_PUSH(CMSDK_RADIO, WRPR_CTRL__CLK_ENABLE)
	{
	    resp = spi_pmuradio_read_word(&spi_radio, block, addr);
	}
	WRPR_CTRL_POP();
    }

    DEBUG_TRACE("pmu_radio read block=%" PRIu32 ", addr=%" PRIu32 ", is_pmu=%d,"
		" resp=%d",
	block, addr, is_pmu, resp);
    return resp;
}

static void vendor_dbg_pmu_radio_reg_rd_handler(uint8_t *buf)
{
    dat.dbg_pmu_radio_reg_rd_cmd.reg_block = atm_get_le32(buf);
    dat.dbg_pmu_radio_reg_rd_cmd.reg_addr = atm_get_le32(&buf[4]);
    dat.dbg_pmu_radio_reg_rd_cmd.is_pmu = buf[8];
}

static void vendor_dbg_pmu_radio_reg_rd_cmp_handler(uint8_t **bufptr,
    uint32_t *size)
{
    if (!check_evt_unsupport(bufptr)) {
	// stack support
	APP_TRACE("stack support");
	return;
    }

    // stack not support, implement here
    APP_TRACE("stack not support");
    uint32_t value = do_pmu_radio_read(dat.dbg_pmu_radio_reg_rd_cmd.reg_block,
	dat.dbg_pmu_radio_reg_rd_cmd.reg_addr,
	dat.dbg_pmu_radio_reg_rd_cmd.is_pmu);
    init_hci_event(PMU_RADIO_REG_RD_CMD_OCF, PMU_RADIO_REG_RD_CMD_OGF, 12,
	HCI_EVT_SUCCESS, bufptr, size);

    atm_set_le32(&hcievent_buffer[7], dat.dbg_pmu_radio_reg_rd_cmd.reg_block);
    atm_set_le32(&hcievent_buffer[11], dat.dbg_pmu_radio_reg_rd_cmd.reg_addr);
    atm_set_le32(&hcievent_buffer[15], value);
}
#endif

#ifdef CFG_VND_PMU_RADIO_REGW

static void do_pmu_radio_write(uint32_t block, uint32_t addr, uint32_t wdata,
    uint8_t is_pmu)
{
    if (is_pmu) {
	WRPR_CTRL_PUSH(CMSDK_PMU, WRPR_CTRL__CLK_ENABLE)
	{
	    spi_pmuradio_write_word(&spi_pmu, block, addr, wdata);
	}
	WRPR_CTRL_POP();
    } else {
	WRPR_CTRL_PUSH(CMSDK_RADIO, WRPR_CTRL__CLK_ENABLE)
	{
	    spi_pmuradio_write_word(&spi_radio, block, addr, wdata);
	}
	WRPR_CTRL_POP();
    }
    DEBUG_TRACE("pmu_radio write block=%" PRIu32 ", addr=%" PRIu32
		", is_pmu=%d, wdata=%" PRIu32,
	block, addr, is_pmu, wdata);
}

static void vendor_dbg_pmu_radio_reg_wr_handler(uint8_t *buf)
{
    dat.dbg_pmu_radio_reg_wr_cmd.reg_block = atm_get_le32(buf);
    dat.dbg_pmu_radio_reg_wr_cmd.reg_addr = atm_get_le32(&buf[4]);
    dat.dbg_pmu_radio_reg_wr_cmd.reg_value = atm_get_le32(&buf[8]);
    dat.dbg_pmu_radio_reg_wr_cmd.is_pmu = buf[12];
}

static void vendor_dbg_pmu_radio_reg_wr_cmp_handler(uint8_t **bufptr,
    uint32_t *size)
{
    if (!check_evt_unsupport(bufptr)) {
	// stack support
	APP_TRACE("stack not support");
	return;
    }

    // stack not support, implement here
    APP_TRACE("stack support");
    do_pmu_radio_write(dat.dbg_pmu_radio_reg_wr_cmd.reg_block,
	dat.dbg_pmu_radio_reg_wr_cmd.reg_addr,
	dat.dbg_pmu_radio_reg_wr_cmd.reg_value,
	dat.dbg_pmu_radio_reg_wr_cmd.is_pmu);
    init_hci_event(PMU_RADIO_REG_WR_CMD_OCF, PMU_RADIO_REG_WR_CMD_OGF, 12,
	HCI_EVT_SUCCESS, bufptr, size);

    atm_set_le32(&hcievent_buffer[7], dat.dbg_pmu_radio_reg_wr_cmd.reg_block);
    atm_set_le32(&hcievent_buffer[11], dat.dbg_pmu_radio_reg_wr_cmd.reg_addr);
    atm_set_le32(&hcievent_buffer[15], dat.dbg_pmu_radio_reg_wr_cmd.reg_value);
}
#endif

#ifdef CFG_VND_EN_TXCW
static void vendor_entxcw_handler(uint8_t *buf)
{
    dat.en_txcw_cmd.enabled = *buf;
}

// Handle enable TX CW mode HCI command
static void en_txcw_mode(uint8_t rx_byte)
{
    // input value: channel_idx or 0xff to disable
    if (rx_byte == 0xFF) {
	WRPR_CTRL_SET(CMSDK_RIF, WRPR_CTRL__CLK_ENABLE);
	CMSDK_RIF->MODE_CNTL = 0;
	APP_TRACE("    tx cw off");
	return;
    }

    uint8_t freq = rx_byte * 2; // 2402+k*2MHz
    uint32_t txCWCfg = (RIF_MODE_CNTL__RADIO_EN_OVR__WRITE(1) |
	RIF_MODE_CNTL__RADIO_EN__WRITE(1) | RIF_MODE_CNTL__TX_EN_OVR__WRITE(1) |
	RIF_MODE_CNTL__TX_EN__WRITE(1) | RIF_MODE_CNTL__CHAN_IDX_OVR__WRITE(1) |
	RIF_MODE_CNTL__CHAN_IDX__WRITE(freq) |
	RIF_MODE_CNTL__TX_POWER_OVR__WRITE(1) | AG_RF_POWER_MAX);

    WRPR_CTRL_SET(CMSDK_RIF, WRPR_CTRL__CLK_ENABLE);

    // Enable Tx CW
    CMSDK_RIF->MODE_CNTL = txCWCfg;
    APP_TRACE("    tx cw on RF Channel k[%d] MODE_CNTL[0x%" PRIx32 "]", rx_byte,
	txCWCfg);
}

static void vendor_entxcw_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    en_txcw_mode(dat.en_txcw_cmd.enabled);
    init_hci_event(EN_TXCW_CMD_OCF, EN_TXCW_CMD_OGF, 0, HCI_EVT_SUCCESS, bufptr,
	size);
}
#endif

#ifdef CFG_VND_CAP
static void vendor_freqcal_handler(uint8_t *buf)
{
    dat.freq_cal_cmd.rx_byte = *buf;
}

// Handle 16MXtal cap. value set HCI command
static void xtal_cap_set(uint8_t rx_byte)
{
    uint8_t val = rx_byte;

    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE);

    // xtal cap value set
    CMSDK_PSEQ->XTAL_BITS0 = (PSEQ_XTAL_BITS0__XOCAPOUT__WRITE(val)) |
	(PSEQ_XTAL_BITS0__XOCAPIN__WRITE(val));

    APP_TRACE("    xtal cap. set[%d]", val);
}

static void vendor_freqcal_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    xtal_cap_set(dat.freq_cal_cmd.rx_byte);
    init_hci_event(FREQCAL_CMD_OCF, FREQCAL_CMD_OGF, 0, HCI_EVT_SUCCESS, bufptr,
	size);
}
#endif

#ifdef CFG_VND_PV_TEST
static void vendor_enpvtest_handler(uint8_t *buf)
{
    dat.pv_test_cmd.pv_test_times = atm_get_le16(buf);
}

#ifdef CFG_NONRF_HARV
static uint16_t pv_test(uint16_t times)
{
    APP_TRACE("pv test-read %d times.", times);
    return pmu_harv_get_harvcnt(times);
}
#endif

static void vendor_enpvtest_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    init_hci_event(PV_TEST_CMD_OCF, PV_TEST_CMD_OGF, 2, HCI_EVT_SUCCESS, bufptr,
	size);

#ifdef CFG_NONRF_HARV
    uint16_t pv_count = pv_test(dat.pv_test_cmd.pv_test_times);

    // Update memory read data into HCI event buffer
    atm_set_le16(*bufptr + BASIC_HCI_EVT_CMD_LEN, pv_count);
    SET_HCI_EVT_STATUS(HCI_EVT_SUCCESS);
#else
    SET_HCI_EVT_STATUS(HCI_EVT_ERROR);
#endif
}
#endif

#ifdef CFG_VND_GADC
// Calibration setting, this should keep outside the dat union
static float volt4cli;
static float ratio4cli;
static bool gadc_setting_valid(void)
{
    if (!dat.gadc_cmd.gext) {
	return (volt4cli >= 1.8f && volt4cli <= 3.3f) && (ratio4cli >= 3.0f &&
	    ratio4cli <= 6.0f);
    }

    if (dat.gadc_cmd.gext == 1) {
	return (volt4cli >= 1.1f && volt4cli <= 1.8f) && (ratio4cli >= 1.5f &&
	    ratio4cli <= 3.0f);
    }

    return false;
}

static void gadc_result(float result, struct gadc_fifo_s raw_fifo,
    struct gadc_cal_s cal, gadc_cb_ctx_t const *ctx)
{
    int16_t raw = raw_fifo.sample_x2 / 2;
    APP_TRACE("[ch%d] volt, raw, curcal = %f, %d, %#" PRIx32,
	dat.gadc_cmd.sample_ch, (double)result, raw, cal.value);
    if (dat.gadc_cmd.gadc_op == GADC_CH_SAMPLE_START) {
	dat.gadc_cmd.ch_volt = result;
	dat.gadc_cmd.ch_raw = raw;
	dat.gadc_cmd.ch_curcal.value = cal.value;
    } else if (dat.gadc_cmd.gadc_op == GADC_CH_CALIBRATE_START) {
	dat.gadc_cmd.ch_raw = raw;
	dat.gadc_cmd.sample_ch = CORE;
	dat.gadc_cmd.gadc_op = GADC_CH_CALIBRATE_VDD1A_INTERNAL;
	gadc_sample_channel(CORE, gadc_result, CORE_GEXT_DEFAULT, NULL);
    } else if (dat.gadc_cmd.gadc_op == GADC_CH_CALIBRATE_VDD1A_INTERNAL) {
#define VDD1A 1.012f
	dat.gadc_cmd.vdd1a_raw = raw;
	dat.gadc_cmd.ch_newoffset_x2 =
	    (volt4cli * dat.gadc_cmd.vdd1a_raw -
		ratio4cli * VDD1A * dat.gadc_cmd.ch_raw) /
	    (ratio4cli * VDD1A - volt4cli) * 2;
	dat.gadc_cmd.ch_newgain.value = volt4cli /
	    (dat.gadc_cmd.ch_raw + 0.5f * dat.gadc_cmd.ch_newoffset_x2);
	dat.gadc_cmd.ch_newcal.c0_x2 = dat.gadc_cmd.ch_newoffset_x2;
	dat.gadc_cmd.ch_newcal.c1_mantissa =
	    dat.gadc_cmd.ch_newgain.number.fraction >> (23 - 12);
	dat.gadc_cmd.ch_newcal.c1_exponent =
	    dat.gadc_cmd.ch_newgain.number.exponent - (127 - 31);
	dat.gadc_cmd.ch_newcal.c1_sign = dat.gadc_cmd.ch_newgain.number.sign;
	APP_TRACE("[setting] volt,ratio = %f,%f", (double)volt4cli,
	    (double)ratio4cli);

	if (gadc_setting_valid()) {
	    APP_TRACE("[ch%d] new (cal, gain, offset) = (%#" PRIx32 ", %f,%d)",
		dat.gadc_cmd.ch, dat.gadc_cmd.ch_newcal.value,
		(double)dat.gadc_cmd.ch_newgain.value,
		dat.gadc_cmd.ch_newoffset_x2);
	    // check new volt
	    float new_volt = 0.988f * dat.gadc_cmd.ch_newgain.value *
		(dat.gadc_cmd.ch_raw + 0.5f * dat.gadc_cmd.ch_newoffset_x2);
	    DEBUG_TRACE("Pass: new volt = %f", (double)new_volt);
	} else {
	    DEBUG_TRACE("Fail: wrong setting");
	    dat.gadc_cmd.gadc_status = GADC_ERR_WRONG_CALI_SETTING;
	}
    }
}

static void vendor_gadc_handler(uint8_t *buf)
{
    dat.gadc_cmd.gadc_op = buf[0];
    switch (dat.gadc_cmd.gadc_op) {
	case GADC_CH_SAMPLE_START: {
	    dat.gadc_cmd.gadc_status = GADC_ERR_OK;
	    dat.gadc_cmd.ch = buf[1];
	    dat.gadc_cmd.gext = buf[2];
	    dat.gadc_cmd.sample_ch = dat.gadc_cmd.ch;
	    gadc_sample_channel(dat.gadc_cmd.ch, gadc_result, dat.gadc_cmd.gext,
		NULL);
	} break;

	case GADC_CH_SAMPLE_GET: {
	    if (dat.gadc_cmd.ch != buf[1]) {
		dat.gadc_cmd.gadc_status = GADC_ERR_WRONG_CHANNEL;
	    } else {
		dat.gadc_cmd.gadc_status = GADC_ERR_OK;
	    }
	} break;

	case GADC_CH_CALIBRATE_VDD1A_INTERNAL:
	case GADC_CH_CALIBRATE_START: {
	    dat.gadc_cmd.gadc_status = GADC_ERR_OK;
	    dat.gadc_cmd.ch = buf[1];
	    dat.gadc_cmd.gext = buf[2];
	    dat.gadc_cmd.sample_ch = dat.gadc_cmd.ch;
	    gadc_sample_channel(dat.gadc_cmd.ch, gadc_result, dat.gadc_cmd.gext,
		NULL);
	} break;

	case GADC_CH_CALIBRATE_GET: {
	    if (dat.gadc_cmd.ch != buf[1]) {
		dat.gadc_cmd.gadc_status = GADC_ERR_WRONG_CHANNEL;
	    }
	} break;

	case GADC_CH_CALIBRATION_SETTING: {
	    struct {
		uint8_t op;
		float volt;
		float ratio;
	    } __PACKED *payload = (void *)buf;

	    volt4cli = payload->volt;
	    ratio4cli = payload->ratio;
	    dat.gadc_cmd.gadc_status = GADC_ERR_OK;
	} break;

	default: {
	    dat.gadc_cmd.gadc_status = GADC_ERR_INVALID_OP;
	} break;
    }
}

static void vendor_gadc_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    switch (dat.gadc_cmd.gadc_op) {
	case GADC_CH_SAMPLE_START:
	case GADC_CH_CALIBRATE_VDD1A_INTERNAL:
	case GADC_CH_CALIBRATE_START:
	case GADC_CH_CALIBRATION_SETTING: {
	    init_hci_event(GADC_CMD_OCF, GADC_CMD_OGF, 0,
		dat.gadc_cmd.gadc_status, bufptr, size);
	} break;

	case GADC_CH_SAMPLE_GET: {
	    struct hci_evt_para {
		float volt;
		int16_t raw;
		uint32_t curcal;
	    } __PACKED;

	    init_hci_event(GADC_CMD_OCF, GADC_CMD_OGF,
		sizeof(struct hci_evt_para), dat.gadc_cmd.gadc_status, bufptr,
		size);
	    struct hci_evt_para *gadc_hcievent_para =
		(struct hci_evt_para *)&hcievent_buffer[BASIC_HCI_EVT_CMD_LEN];

	    gadc_hcievent_para->volt = dat.gadc_cmd.ch_volt;
	    gadc_hcievent_para->raw = dat.gadc_cmd.ch_raw;
	    gadc_hcievent_para->curcal = dat.gadc_cmd.ch_curcal.value;
	} break;

	case GADC_CH_CALIBRATE_GET: {
	    struct hci_evt_para {
		uint32_t newcal;
	    };

	    init_hci_event(GADC_CMD_OCF, GADC_CMD_OGF,
		sizeof(struct hci_evt_para), dat.gadc_cmd.gadc_status, bufptr,
		size);
	    struct hci_evt_para *gadc_hcievent_para =
		(struct hci_evt_para *)&hcievent_buffer[BASIC_HCI_EVT_CMD_LEN];
	    gadc_hcievent_para->newcal = dat.gadc_cmd.ch_newcal.value;
	} break;

	default: {
	    DEBUG_TRACE("Invalid gadc op: %d", dat.gadc_cmd.gadc_op);
	    ASSERT_ERR(0);
	}
    }
}
#endif

#ifdef CFG_VND_IO_CTRL
static void vendor_io_handler(uint8_t *buf)
{
    dat.io_cmd.op = buf[0];
    dat.io_cmd.io = buf[1];
    dat.io_cmd.par = buf[2];
}

// Handle IO control HCI command
static void io_control(void)
{
    switch (dat.io_cmd.op) {
	case IO_CMD_OP_SETUP: {
	    atm_gpio_setup(dat.io_cmd.io);
	    if (dat.io_cmd.par) {
		atm_gpio_set_output(dat.io_cmd.io);
	    } else {
		atm_gpio_set_input(dat.io_cmd.io);
	    }
	} break;
	case IO_CMD_OP_READ: {
	    dat.io_cmd.par = atm_gpio_read_gpio(dat.io_cmd.io);
	} break;
	case IO_CMD_OP_WRITE: {
	    atm_gpio_write(dat.io_cmd.io, dat.io_cmd.par);
	} break;
	default: {
	} break;
    }
}

static void vendor_io_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    init_hci_event(IO_CMD_OCF, IO_CMD_OGF, 1, HCI_EVT_SUCCESS, bufptr, size);
    io_control();
    hcievent_buffer[7] = dat.io_cmd.par;
}
#endif

#ifdef CFG_VND_GPIO_TEST
static bool gpio_self_test_failed;
static bool gpio_self_test(uint8_t input_io, uint8_t output_io)
{
    bool test_pass = true;

    atm_gpio_setup(input_io);
    atm_gpio_setup(output_io);
#ifdef PIN_UART1_TX
    if ((input_io == PIN_UART1_TX) || (output_io == PIN_UART1_TX)) {
#define _PINMUX_GPIO_SET(inst) PINMUX_GPIO_SET(inst)
	_PINMUX_GPIO_SET(PIN2GPIO(PIN_UART1_TX));
    }
#endif
    atm_gpio_set_input(input_io);
    atm_gpio_set_output(output_io);
    atm_gpio_write(output_io, 0);
    if (atm_gpio_read_gpio(input_io)) {
	test_pass = false;
    }
    atm_gpio_write(output_io, 1);
    if (!atm_gpio_read_gpio(input_io)) {
	test_pass = false;
    }
    atm_gpio_set_input(output_io);
#ifdef PIN_UART1_TX
    if ((input_io == PIN_UART1_TX) || (output_io == PIN_UART1_TX)) {
	PINMUX_UART_SET(1, TX);
    }
#endif
    DEBUG_TRACE("input: %d output: %d pass:%d", input_io, output_io, test_pass);
    return test_pass;
}

static void vendor_gpio_self_test_handler(uint8_t *buf)
{
    uint8_t num_pair = buf[0];
    DEBUG_TRACE("num_pair %d", num_pair);
    gpio_self_test_failed = false;
    for (uint8_t i = 0; i < num_pair; i++) {
	uint8_t io_0 = buf[1 + i * 2];
	uint8_t io_1 = buf[2 + i * 2];
	DEBUG_TRACE("GPIO self test Pair_%d: [%d, %d]", i, io_0, io_1);

	if (!gpio_self_test(io_0, io_1) || !gpio_self_test(io_1, io_0)) {
	    gpio_self_test_failed = true;
	}
    }
}

static void vendor_gpio_self_test_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    init_hci_event(GPIO_SELF_TEST_CMD_OCF, GPIO_SELF_TEST_CMD_OGF, 0,
	HCI_EVT_SUCCESS, bufptr, size);
    if (gpio_self_test_failed) {
	DEBUG_TRACE("gpio_self_test failed");
	SET_HCI_EVT_STATUS(HCI_EVT_ERROR);
    }
}
#endif

#ifdef CFG_VND_MALLOC
static void vendor_malloc_handler(uint8_t *buf)
{
    dat.malloc_cmd.type = buf[0];
    uint32_t u32parm = atm_get_le32(&buf[1]);
    if (dat.malloc_cmd.type == MALLOC_ALLOC) {
	if (dat.malloc_ctx.malloc_mem) {
	    dat.malloc_cmd.type = MALLOC_ERR_NO_MEM;
	} else {
	    dat.malloc_ctx.malloc_size = u32parm;
	}
    } else if (dat.malloc_cmd.type == MALLOC_FREE) {
	if (!dat.malloc_ctx.malloc_mem || (void *)u32parm !=
	    dat.malloc_ctx.malloc_mem) {
	    dat.malloc_cmd.type = MALLOC_ERR_BAD_FREE;
	}
    }
}

static void vendor_malloc_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    init_hci_event(MALLOC_CMD_OCF, MALLOC_CMD_OGF, 0, HCI_EVT_SUCCESS, bufptr,
	size);
    if (dat.malloc_cmd.type == MALLOC_FREE) {
	free(dat.malloc_ctx.malloc_mem);
	SET_HCI_EVT_STATUS(HCI_EVT_SUCCESS);
	dat.malloc_ctx.malloc_mem = NULL;
    } else if (dat.malloc_cmd.type == MALLOC_ALLOC) {
	dat.malloc_ctx.malloc_mem = malloc(dat.malloc_ctx.malloc_size);
	if (!dat.malloc_ctx.malloc_mem) {
	    SET_HCI_EVT_STATUS(MALLOC_ERR_NO_MEM);
	} else {
	    init_hci_event(MALLOC_CMD_OCF, MALLOC_CMD_OGF, 4, HCI_EVT_SUCCESS,
		bufptr, size);
	    atm_set_le32(&hcievent_buffer[BASIC_HCI_EVT_CMD_LEN],
		(uint32_t)dat.malloc_ctx.malloc_mem);
	}
    } else {
	SET_HCI_EVT_STATUS(dat.malloc_cmd.type);
    }
}
#endif

#ifdef CFG_VND_SYS_MMR
static void vendor_mmr_handler(uint8_t *buf)
{
    memcpy(dat.mmr_cmd.buf, buf, MMR_ADDR_LEN);
}

static void vendor_mmr_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    init_hci_event(MM_R_CMD_OCF, MM_R_CMD_OGF, 4, HCI_EVT_SUCCESS, bufptr,
	size);

    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE);
    uint32_t mmr_data = (*(volatile unsigned int *)(dat.mmr_cmd.value));

    // Update memory read data into HCI event buffer
    memcpy(&hcievent_buffer[BASIC_HCI_EVT_CMD_LEN], &mmr_data,
	sizeof(mmr_data));

    APP_TRACE("    mmr[0x%" PRIx32 "]=0x%" PRIx32, dat.mmr_cmd.value, mmr_data);
}
#endif

#ifdef CFG_VND_TAG_RD
static void vendor_tagmfg_handler(uint8_t *buf)
{
    dat.tag_cmd.tag_id = *buf;
}

static void vendor_tagmfg_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    // shift to hci event payload start address
    nvds_tag_len_t tag_len = NVDS_TAG_MFG_BUFF_LEN - BASIC_HCI_EVT_CMD_LEN;
    if (nvds_get(dat.tag_cmd.tag_id, &tag_len,
	    (uint8_t *)&hcievent_buffer[BASIC_HCI_EVT_CMD_LEN]) != NVDS_OK) {
	init_hci_event(TAG_R_CMD_OCF, TAG_R_CMD_OGF, 0, HCI_EVT_ERROR, bufptr,
	    size);
	APP_TRACE("    read fail tag_cmd.tag_id=%d", dat.tag_cmd.tag_id);
    } else {
	// update HCI EVT payload length
	init_hci_event(TAG_R_CMD_OCF, TAG_R_CMD_OGF, tag_len, HCI_EVT_SUCCESS,
	    bufptr, size);

	APP_TRACE("    read okay real tag_cmd.tag_id=%d tag_len=%d",
	    dat.tag_cmd.tag_id, tag_len);
    }
}
#endif

#ifdef CFG_VND_DBG_MMR
static void vendor_dbg_rd_mem_handler(uint8_t *buf)
{
    dat.dbg_rd_mem_cmd.start_addr = atm_get_le32(buf);
    dat.dbg_rd_mem_cmd.type = buf[4];
    dat.dbg_rd_mem_cmd.length = buf[5];
}

static void read_memory(uint8_t *buffer)
{
    uint32_t i = 0;
    uint32_t value = 0;

    /* Check type of data to be read */
    if (dat.dbg_rd_mem_cmd.type == 8) {
	/* Read bytes */
	for (i = 0; i < dat.dbg_rd_mem_cmd.length; i++) {
	    /* Read value at @ set in Param1+i */
	    buffer[i] =
		*(volatile uint8_t *)(dat.dbg_rd_mem_cmd.start_addr + i);
	}
    } else if (dat.dbg_rd_mem_cmd.type == 16) {
	for (i = 0; i < dat.dbg_rd_mem_cmd.length; i += 2) {
	    /* Read value at @ set in Param1+i */
	    value = (*(volatile uint16_t *)(dat.dbg_rd_mem_cmd.start_addr + i));

	    /* store in the buffer */
	    atm_set_le16(&buffer[i], value);
	}
    } else if (dat.dbg_rd_mem_cmd.type == 32) {
	/* Read 32 bit word */
	for (i = 0; i < dat.dbg_rd_mem_cmd.length; i += 4) {
	    value = (*(volatile uint32_t *)(dat.dbg_rd_mem_cmd.start_addr + i));

	    /* store in the buffer */
	    atm_set_le32(&buffer[i], value);
	}
    }
}

static void vendor_dbg_rd_mem_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    if (!check_evt_unsupport(bufptr)) {
	// stack support
	APP_TRACE("stack support");
	return;
    }

    // stack not support, implement here
    APP_TRACE("stack not support");

    if ((dat.dbg_rd_mem_cmd.length == 0) || (dat.dbg_rd_mem_cmd.length > 128)) {
	init_hci_event(RD_MEM_CMD_OCF, RD_MEM_CMD_OGF, 0, HCI_EVT_ERR_INVD_PARA,
	    bufptr, size);
    } else {
	init_hci_event(RD_MEM_CMD_OCF, RD_MEM_CMD_OGF,
	    1 + dat.dbg_rd_mem_cmd.length, HCI_EVT_SUCCESS, bufptr, size);

	hcievent_buffer[BASIC_HCI_EVT_CMD_LEN] = dat.dbg_rd_mem_cmd.length;

	read_memory(&hcievent_buffer[BASIC_HCI_EVT_CMD_LEN + 1]);
    }
}
#endif

#ifdef CFG_VND_DBG_MMW
static void vendor_dbg_wr_mem_handler(uint8_t *buf)
{
    dat.dbg_wr_mem_cmd.start_addr = atm_get_le32(buf);
    dat.dbg_wr_mem_cmd.type = buf[4];
    dat.dbg_wr_mem_cmd.length = buf[5];
    memcpy(dat.dbg_wr_mem_cmd.data, &buf[6], buf[5]);
}

static void write_memory(void)
{
    uint32_t i = 0;

    /* Check type of data to be written */
    if (dat.dbg_wr_mem_cmd.type == 8) {
	/* Write bytes */
	for (i = 0; i < dat.dbg_wr_mem_cmd.length; i++) {
	    /* Set value type at @ Param1 */
	    *(volatile uint8_t *)(dat.dbg_wr_mem_cmd.start_addr + i) =
		dat.dbg_wr_mem_cmd.data[i];
	}
    } else if (dat.dbg_wr_mem_cmd.type == 16) {
	/* Write 16 bits word */
	for (i = 0; i < dat.dbg_wr_mem_cmd.length; i += 2) {
	    /* Set value type at @ Param1 */
	    *(volatile uint16_t *)(dat.dbg_wr_mem_cmd.start_addr + i) =
		atm_get_le16(&dat.dbg_wr_mem_cmd.data[i]);
	}
    } else if (dat.dbg_wr_mem_cmd.type == 32) {
	/* Write 32 bit word */
	for (i = 0; i < dat.dbg_wr_mem_cmd.length; i += 4) {
	    /* Set value at @ Param1 */
	    *(volatile uint32_t *)(dat.dbg_wr_mem_cmd.start_addr + i) =
		atm_get_le32(&dat.dbg_wr_mem_cmd.data[i]);
	}
    }
}

static void vendor_dbg_wr_mem_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    if (!check_evt_unsupport(bufptr)) {
	// stack support
	APP_TRACE("stack support");
	return;
    }

    // stack not support, implement here
    APP_TRACE("stack not support");
    init_hci_event(WR_MEM_CMD_OCF, WR_MEM_CMD_OGF, 0, HCI_EVT_SUCCESS, bufptr,
	size);

    if ((dat.dbg_wr_mem_cmd.length == 0) ||
	(dat.dbg_wr_mem_cmd.length > 128)) {
	SET_HCI_EVT_STATUS(HCI_EVT_ERR_INVD_PARA);
    } else {
	write_memory();
    }
}
#endif

#ifdef CFG_VND_PSM
static void vendor_psm_handler(uint8_t *buf)
{
    dat.psm_cmd.psm_mode = buf[0];
}

static uint8_t cmd_psm;

static void vendor_psm_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    init_hci_event(PSM_CMD_OCF, PSM_CMD_OGF, 1, HCI_EVT_SUCCESS, bufptr, size);
    uint8_t pgse = pseq_get_sleep_enable();
    hcievent_buffer[7] = pgse;
    if ((dat.psm_cmd.psm_mode > pgse) ||
	((pgse == PSM_SOC_OFF) && (dat.psm_cmd.psm_mode == PSM_HIBERNATE))) {
	cmd_psm = PSM_NONE;
	SET_HCI_EVT_STATUS(HCI_EVT_ERROR);
	return;
    }

    switch (dat.psm_cmd.psm_mode) {
	case PSM_NONE: {
	    cmd_psm = dat.psm_cmd.psm_mode;
	    uart_set_park_state(UART_UNPARK);
	} break;

	case PSM_DEEP:
	case PSM_RETAIN:
	case PSM_RETAIN_DROP:
	case PSM_HIBERNATE:
	case PSM_SOC_OFF: {
	    cmd_psm = dat.psm_cmd.psm_mode;
	    uart_set_park_state(UART_PARK);
	} break;

	default: {
	    cmd_psm = PSM_NONE;
	    SET_HCI_EVT_STATUS(HCI_EVT_ERROR);
	} break;
    };
}
#endif

#ifdef CFG_VND_COREMARK
static void vendor_coremark_handler(uint8_t *buf)
{
    dat.coremark_cmd.iterations = atm_get_le16(buf);
    dat.coremark_cmd.clock_mhz = buf[2];
}

static void vendor_coremark_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    uint32_t wdog;
    uint16_t score;
    uint8_t err;

    /*
     * we could get WDOG while doing coremark tests depending on iterations
     * and time spent here.
     * safer to set wdog to some high value and reset after coremark finishes
     */
    DEBUG_TRACE("Adjusting wdog to %d seconds..", POWER_MEASURE_WDOG_SECONDS);
    DEBUG_TRACE("coremark:iterations=%d, freq=%d", dat.coremark_cmd.iterations,
	dat.coremark_cmd.clock_mhz);
    wdog = POWER_MEASURE_WDOG_SECONDS * atm_bp_clock_get();
    CMSDK_WATCHDOG->LOCK = WDOG_LOCK_MAGIC;
    CMSDK_WATCHDOG->LOAD = wdog;
    CMSDK_WATCHDOG->LOCK = 0;

    if (!coremark(dat.coremark_cmd.iterations, dat.coremark_cmd.clock_mhz,
	&score)) {
	err = HCI_EVT_ERROR;
    } else {
	err = HCI_EVT_SUCCESS;
	atm_set_le16(&hcievent_buffer[BASIC_HCI_EVT_CMD_LEN], score);
    }
    // reset wdog to original value
#define WDOG_INIT_TIMEOUT 0x0a000000 // ~10s
    CMSDK_WATCHDOG->LOCK = WDOG_LOCK_MAGIC;
    CMSDK_WATCHDOG->LOAD = WDOG_INIT_TIMEOUT;
    CMSDK_WATCHDOG->LOCK = 0;

    init_hci_event(COREMARK_CMD_OCF, COREMARK_CMD_OGF, COREMARK_RTN_VALUE_LEN,
	err, bufptr, size);
}
#endif

#if defined(CFG_VND_WFI) || defined(CFG_VND_NO_CLOCK) || \
    defined(CFG_VND_WHILE_ONE)
#define INT_REG_NUM 4
/*
 * This routine does all the preparation work for power measure
 * functions like wfi, no_clock, while_one
 * place certain modules in shutdown or disabled state, adjust bp_freq
 * also set wdog to large enough value so power measure tests complete
 * without any interruption
 *
 * CAUTION Some of these tests and settings may leave the system
 * in a unrecoverable or indeterminate state.
 * A hard pwd reset may be required to recover.
 * These are intended for power measure tests only and power measure
 * tests do issue a pwd reset upon every test.
 */
static void power_measure_prologue_work(uint16_t power_config_mode,
    uint8_t bp_freq)
{
    uint32_t wdog, freq;

    // shutdown ble52_mdm block if needed
    if (power_config_mode & PWR_BLE52_DISABLE) {
	DEBUG_TRACE("Turning off BLE52 HCLK...");
	CMSDK_CLKRSTGEN_NONSECURE->USER_CLK_GATE_FORCE_ON = 0;
    }

    // Disable MDM clock if needed
    if (power_config_mode & PWR_MDM_CLK_DISABLE) {
	DEBUG_TRACE("Disabling MDM clock...");
	CMSDK_CLKRSTGEN_NONSECURE->USER_CLK_DISABLES =
	    CLKRSTGEN_USER_CLK_DISABLES__MDM_RIF__WRITE(1);
    }

    // shutdown rram if needed
    if (power_config_mode & PWR_RRAM_SD) {
	DEBUG_TRACE("Shuting down rram...");
	CMSDK_AT_PRRF_NONSECURE->RRAM_MEM_CONFIG = 0;
	// Place RRAM in shutdown
	WRPR_CTRL_SET(CMSDK_PSEQ_NONSECURE, WRPR_CTRL__CLK_ENABLE);
	{
	    CMSDK_PSEQ_NONSECURE->OVERRIDES3 = 0;
	    CMSDK_PSEQ_NONSECURE->OVERRIDES3 =
		PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC__MASK |
		PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC_VAL__MASK;
	}
	WRPR_CTRL_SET(CMSDK_PSEQ_NONSECURE, WRPR_CTRL__CLK_DISABLE);
    }

    /*
     * For these tests, we want to stay in there forever.
     * A reset to the device is the way out, and test scripts will reset
     * when required. Usually, it is within few seconds, after capturing
     * necessary power measurement data
     * make certain we are not interrupted while in these state
     */
    DEBUG_TRACE("Disabling all interrupts...");
    for (int i = 0; i < INT_REG_NUM; i++) {
	uint32_t ise = NVIC->ISER[i];
	if (ise) {
	    NVIC->ICER[i] = ise;
	}
    }

    // Adjust bp_freq if necessary
    if (power_config_mode & PWR_BP_FREQ_ADJUST) {
	if (!bp_freq) {
	    // a value 0 implies it is 0.5Mhz
	    freq = 500000;
	} else {
	    freq = bp_freq * 1000000;
	}

	DEBUG_TRACE("Adjusting bp_freq to %" PRIu32, freq);
	atm_bp_clock_set(freq);
    }

    /*
     * set wdog to some large value, so it doesnt fire while in
     * power measurement OR just in case if someone forgot to reset/pwd
     */
    DEBUG_TRACE("Adjusting wdog to %d seconds..", POWER_MEASURE_WDOG_SECONDS);
    wdog = POWER_MEASURE_WDOG_SECONDS * atm_bp_clock_get();
    CMSDK_WATCHDOG->LOCK = WDOG_LOCK_MAGIC;
    CMSDK_WATCHDOG->LOAD = wdog;
    CMSDK_WATCHDOG->LOCK = 0;
}
#endif

#ifdef CFG_VND_WFI
static void vendor_wfi_handler(uint8_t *buf)
{
    dat.power_cmd.power_cfg = atm_get_le16(buf);
    dat.power_cmd.bp_freq = buf[2];
}

static void vendor_wfi_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    uint32_t save_freq;
    uint8_t err;
    DEBUG_TRACE("wfi cmp handler: power_cfg=%x, bp_freq=%d",
	dat.power_cmd.power_cfg, dat.power_cmd.bp_freq);

    save_freq = atm_bp_clock_get();
    power_measure_prologue_work(dat.power_cmd.power_cfg, dat.power_cmd.bp_freq);

    // do the wfi
    WFI();

    // This code below may not execute
    // restore bp_freq here just in case.
    DEBUG_TRACE("Restoring bp_freq to %" PRIu32, save_freq);
    atm_bp_clock_set(save_freq);
    DEBUG_TRACE("Finished doing wfi ...");
    err = HCI_EVT_SUCCESS;
    init_hci_event(WFI_CMD_OCF, WFI_CMD_OGF, 0, err, bufptr, size);
}
#endif

#ifdef CFG_VND_NO_CLOCK
static void vendor_no_clock_handler(uint8_t *buf)
{
    dat.power_cmd.power_cfg = atm_get_le16(buf);
    dat.power_cmd.bp_freq = buf[2];
}

static void vendor_no_clock_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    uint32_t save_freq;
    uint8_t err;

    DEBUG_TRACE("no_clock cmp handler: power_cfg=%x, bp_freq=%d",
	dat.power_cmd.power_cfg, dat.power_cmd.bp_freq);

    save_freq = atm_bp_clock_get();
    power_measure_prologue_work(dat.power_cmd.power_cfg, dat.power_cmd.bp_freq);

#define PARIS_PINMUX_DBG 160
    // bring out clk_mpc on debug bus (Gen_MDMCLK)
    // want it on P11
    // dbg.din6 [12]
    WRPRPINS_DBG_CTRL__DBG_ENABLE__MODIFY(CMSDK_WRPR0_NONSECURE->DBG_CTRL, 1);
    WRPRPINS_DBG_CTRL__DBG_SHFT__MODIFY(CMSDK_WRPR0_NONSECURE->DBG_CTRL, 1);
    WRPRPINS_DBG_CTRL__DBG_SEL__MODIFY(CMSDK_WRPR0_NONSECURE->DBG_CTRL, 6);
    WRPRPINS_PSEL_C__P11_SEL__MODIFY(CMSDK_WRPR0_NONSECURE->PSEL_C,
	PARIS_PINMUX_DBG);

    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE);
    {
	// Disable MPC
	PSEQ_XTAL_BITS1__CLKMPC_EN__CLR(CMSDK_PSEQ_NONSECURE->XTAL_BITS1);
    }
    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_DISABLE);

    /*
     * should get stuck here forever, below code is for safety completion
     */
    DEBUG_TRACE("Finished turning off clock ...");
    // restore bp_freq, just in case
    atm_bp_clock_set(save_freq);
    err = HCI_EVT_SUCCESS;
    atm_set_le16(&hcievent_buffer[BASIC_HCI_EVT_CMD_LEN], 90);
    init_hci_event(NO_CLOCK_CMD_OCF, NO_CLOCK_CMD_OGF, 2, err, bufptr, size);
}
#endif

#ifdef CFG_VND_WHILE_ONE
static void vendor_while_one_handler(uint8_t *buf)
{
    dat.power_cmd.power_cfg = atm_get_le16(buf);
    dat.power_cmd.bp_freq = buf[2];
}

static void vendor_while_one_cmp_handler(uint8_t **bufptr, uint32_t *size)
{
    DEBUG_TRACE("while_one cmp handler: power_cfg=%x, bp_freq=%d",
	dat.power_cmd.power_cfg, dat.power_cmd.bp_freq);

    power_measure_prologue_work(dat.power_cmd.power_cfg, dat.power_cmd.bp_freq);

    // go into forever loop now
    while (1) {
    }
}
#endif

static void vendor_exit_vendor_mode_handler(uint8_t *buf)
{
    memset(&dat, 0, sizeof(dat));
}

#ifndef CONFIG_SOC_FAMILY_ATM
__FAST
static void exit_deferred_cb(sw_event_id_t event_id, const void *ctx)
{
    APP_TRACE("exit_deferred_cb");
    atm_vendor_exit_hci_vendor_mode();
}
#endif
static void vendor_exit_vendor_mode_cmp_handler(uint8_t **bufptr,
    uint32_t *size)
{
#ifndef CONFIG_SOC_FAMILY_ATM
    init_hci_event(EXIT_VENDOR_CMD_OCF, EXIT_VENDOR_CMD_OGF, 0,
	HCI_EVT_SUCCESS, bufptr, size);

    /* let hci event in to uart tx buffer first*/
    sw_event_id_t eid = sw_event_alloc(exit_deferred_cb, NULL);
    sw_event_set(eid);
#endif
}

static struct vendor_handler const vendor_handler_tab[] = {
#ifdef CFG_VND_EN_TXCW
    {EN_TXCW_CMD_OCF, EN_TXCW_CMD_OGF, EN_TXCW_CMD_LEN, true,
	vendor_entxcw_handler, vendor_entxcw_cmp_handler},
#endif
#ifdef CFG_VND_CAP
    {FREQCAL_CMD_OCF, FREQCAL_CMD_OGF, FREQCAL_CMD_LEN, true,
	vendor_freqcal_handler, vendor_freqcal_cmp_handler},
#endif
#ifdef CFG_VND_SYS_MMR
    {MM_R_CMD_OCF, MM_R_CMD_OGF, MM_R_CMD_LEN, true, vendor_mmr_handler,
	vendor_mmr_cmp_handler},
#endif
#ifdef CFG_VND_TAG_RD
    {TAG_R_CMD_OCF, TAG_R_CMD_OGF, TAG_R_CMD_LEN, true, vendor_tagmfg_handler,
	vendor_tagmfg_cmp_handler},
#endif
#ifdef CFG_VND_SET_BDDR
    {SET_BD_ADDR_CMD_OCF, SET_BD_ADDR_CMD_OGF, SET_BD_ADDR_CMD_LEN, true,
	vendor_set_public_bd_addr_handler,
	vendor_set_public_bd_addr_cmp_handler},
#endif
#ifdef CFG_VND_SET_ADV_CH
    {SET_ADV_CH_CMD_OCF, SET_ADV_CH_CMD_OGF, SET_ADV_CH_CMD_LEN, true,
	vendor_set_adv_ch_handler, vendor_set_adv_ch_cmp_handler},
#endif
#ifdef CFG_VND_MALLOC
    {MALLOC_CMD_OCF, MALLOC_CMD_OGF, MALLOC_CMD_LEN, true,
	vendor_malloc_handler, vendor_malloc_cmp_handler},
#endif
#ifdef CFG_VND_IO_CTRL
    {IO_CMD_OCF, IO_CMD_OGF, IO_CMD_LEN, true, vendor_io_handler,
	vendor_io_cmp_handler},
#endif
#ifdef CFG_VND_GADC
    {GADC_CMD_OCF, GADC_CMD_OGF, GADC_CMD_LEN, false, vendor_gadc_handler,
	vendor_gadc_cmp_handler},
#endif
#ifdef CFG_VND_PV_TEST
    {PV_TEST_CMD_OCF, PV_TEST_CMD_OGF, PV_TEST_CMD_LEN, true,
	vendor_enpvtest_handler, vendor_enpvtest_cmp_handler},
#endif
#ifdef CFG_VND_GPIO_TEST
    {GPIO_SELF_TEST_CMD_OCF, GPIO_SELF_TEST_CMD_OGF, GPIO_SELF_TEST_CMD_LEN,
	false, vendor_gpio_self_test_handler,
	vendor_gpio_self_test_cmp_handler},
#endif
#ifdef CFG_VND_PSM
    {PSM_CMD_OCF, PSM_CMD_OGF, PSM_CMD_LEN, true, vendor_psm_handler,
	vendor_psm_cmp_handler},
#endif
#ifdef CFG_VND_COREMARK
    {COREMARK_CMD_OCF, COREMARK_CMD_OGF, COREMARK_CMD_LEN, true,
	vendor_coremark_handler, vendor_coremark_cmp_handler},
#endif
#ifdef CFG_VND_WFI
    {WFI_CMD_OCF, WFI_CMD_OGF, WFI_CMD_LEN, true, vendor_wfi_handler,
	vendor_wfi_cmp_handler},
#endif
#ifdef CFG_VND_NO_CLOCK
    {NO_CLOCK_CMD_OCF, NO_CLOCK_CMD_OGF, NO_CLOCK_CMD_LEN, true,
	vendor_no_clock_handler, vendor_no_clock_cmp_handler},
#endif
#ifdef CFG_VND_WHILE_ONE
    {WHILE_ONE_CMD_OCF, WHILE_ONE_CMD_OGF, WHILE_ONE_CMD_LEN, true,
	vendor_while_one_handler, vendor_while_one_cmp_handler},
#endif
#ifdef CFG_VND_DBG_MMR
    {RD_MEM_CMD_OCF, RD_MEM_CMD_OGF, RD_MEM_CMD_LEN, true,
	vendor_dbg_rd_mem_handler, vendor_dbg_rd_mem_cmp_handler},
#endif
#ifdef CFG_VND_DBG_MMW
    {WR_MEM_CMD_OCF, WR_MEM_CMD_OGF, WR_MEM_CMD_LEN, false,
	vendor_dbg_wr_mem_handler, vendor_dbg_wr_mem_cmp_handler},
#endif
#ifdef CFG_VND_BLE_REGR
    {BLE_REG_RD_CMD_OCF, BLE_REG_RD_CMD_OGF, BLE_REG_RD_CMD_LEN, true,
	vendor_dbg_ble_reg_rd_handler, vendor_dbg_ble_reg_rd_cmp_handler},
#endif
#ifdef CFG_VND_BLE_REGW
    {BLE_REG_WR_CMD_OCF, BLE_REG_WR_CMD_OGF, BLE_REG_WR_CMD_LEN, true,
	vendor_dbg_ble_reg_wr_handler, vendor_dbg_ble_reg_wr_cmp_handler},
#endif
#ifdef CFG_VND_PMU_RADIO_REGR
    {PMU_RADIO_REG_RD_CMD_OCF, PMU_RADIO_REG_RD_CMD_OGF,
	PMU_RADIO_REG_RD_CMD_LEN, true, vendor_dbg_pmu_radio_reg_rd_handler,
	vendor_dbg_pmu_radio_reg_rd_cmp_handler},
#endif
#ifdef CFG_VND_PMU_RADIO_REGW
    {PMU_RADIO_REG_WR_CMD_OCF, PMU_RADIO_REG_WR_CMD_OGF,
	PMU_RADIO_REG_WR_CMD_LEN, true, vendor_dbg_pmu_radio_reg_wr_handler,
	vendor_dbg_pmu_radio_reg_wr_cmp_handler},
#endif
    {EXIT_VENDOR_CMD_OCF, EXIT_VENDOR_CMD_OGF, EXIT_VENDOR_CMD_LEN, true,
	vendor_exit_vendor_mode_handler, vendor_exit_vendor_mode_cmp_handler},
};

#ifndef CONFIG_SOC_FAMILY_ATM
static struct vendor_handler const *find_vend_handler(uint8_t *op_len_buf)
{
    for (uint32_t i = 0; i < ARRAY_LEN(vendor_handler_tab); i++) {
	struct vendor_handler const *hdlr = &vendor_handler_tab[i];
	if ((hdlr->ocf == op_len_buf[0]) && (hdlr->ogf == op_len_buf[1]) &&
	    (!hdlr->check_cmd_len || (hdlr->cmd_len == op_len_buf[2]))) {
	    return hdlr;
	}
    }

    return NULL;
}

// return true if having HCI vendor command for MFG
static bool fake_hcievent(void)
{
    return (curr_vnd_hdlr != NULL);
}

// check HCI event/command status payload if having HCI vendor command for MFG
static bool check_evt_opcode(uint8_t const *bufptr)
{
    uint8_t evt_type = bufptr[1];
    // check hci packet and event type
    if ((*bufptr != H4_MSG_LC_HCI_EVT) ||
	((evt_type != HCI_EVT_CMD_CPM) && (evt_type != HCI_EVT_CMD_CS))) {
	return false;
    }

    // offset for hci command complete event
    uint8_t ofg_offset = 5;
    uint8_t ocf_offset = 4;

    if (evt_type == HCI_EVT_CMD_CS) {
	// offset for hci command status event
	ofg_offset = 6;
	ocf_offset = 5;
    }

    // check OGF and OCF
    if ((bufptr[ofg_offset] == MFG_OGF_SB1) &&
	(bufptr[ocf_offset] >= MFG_OCF_EN_TXCW) &&
	(bufptr[ocf_offset] < MFG_OCF_END)) {
	return true;
    }

    if ((bufptr[ofg_offset] == VND_OGF_SB1)) {
	if ((bufptr[ocf_offset] == RD_MEM_CMD_OCF) ||
	    (bufptr[ocf_offset] == WR_MEM_CMD_OCF) ||
	    (bufptr[ocf_offset] == BLE_REG_RD_CMD_OCF) ||
	    (bufptr[ocf_offset] == BLE_REG_WR_CMD_OCF) ||
	    (bufptr[ocf_offset] == PMU_RADIO_REG_RD_CMD_OCF) ||
	    (bufptr[ocf_offset] == PMU_RADIO_REG_WR_CMD_OCF)) {
	    return true;
	}
    }

    return false;
}

// check HCI event payload if having HCI Reset Command
static bool check_evt_reset(uint8_t const *bufptr)
{
    // check hci packet and event type
    if ((*bufptr != H4_MSG_LC_HCI_EVT) || (*(bufptr + 1) != HCI_EVT_CMD_CPM)) {
	return false;
    }

    // Is HCI_RESET command
    if (*((uint16_t const *)(bufptr + BASIC_HCI_EVT_HD_LEN)) == HCI_RESET_U16) {
	return true;
    }
    return false;
}

// Restore to default
static void reset_stage(void)
{
    curr_vnd_hdlr = NULL;
}

// Hook uart driver's event function for HCI command parser
__FAST
static rep_vec_err_t vendor_uart_event(uint32_t buf_size, uint8_t *buf)
{
    static uint8_t hci_op_len_buf[HCI_CMD_HDR_LEN];
    ASSERT_ERR(buf);
    ASSERT_ERR(buf_size);

    if ((rx_state == HCIV_STATE_RX_INIT) &&
	(buf_size == HCI_TRANSPORT_HDR_LEN) && (*buf == H4_MSG_LC_HCI_CMD)) {
	rx_state = HCIV_STATE_RX_START;
    } else if ((rx_state == HCIV_STATE_RX_START) &&
	(buf_size == HCI_CMD_HDR_LEN)) {
	// Update HCI OpCode and Length
	memcpy(hci_op_len_buf, buf, HCI_CMD_HDR_LEN);

	// Update HCI command's payload length
	// payload length is zero then move to next state
	uint8_t hci_payload_len = *(buf + HCI_CMD_LEN_POS);
	rx_state = hci_payload_len ? HCIV_STATE_RX_HDR : HCIV_STATE_RX_PAYL;

    } else if (rx_state == HCIV_STATE_RX_HDR) {
	rx_state = HCIV_STATE_RX_PAYL;
    }

    if (rx_state == HCIV_STATE_RX_PAYL) {
	rx_state = HCIV_STATE_RX_INIT;

	curr_vnd_hdlr = find_vend_handler(hci_op_len_buf);
	if (curr_vnd_hdlr) {
	    curr_vnd_hdlr->cmd_hdlr(buf);
	}
    }

    return (RV_NEXT);
}

// Hook uart driver's write function for HCI Event overwrite
__FAST
static rep_vec_err_t vendor_uart_write(uint8_t **bufptr, uint32_t *size)
{
    if ((*size == BASIC_HCI_EVT_HD_LEN) && (**bufptr == H4_MSG_LC_HCI_EVT) &&
	(*(*bufptr + HCI_EVT_CODE_POS) == HCI_HW_ERR_EVT_CODE)) {
	APP_TRACE("HCI out of sync");
	rx_state = HCIV_STATE_RX_INIT;
	reset_stage();
    } else if ((*size == BASIC_HCI_EVT_CMD_LEN) && (internal_reset == true) &&
	check_evt_reset(*bufptr)) {
	// change interval HCI reset event to AG Ready Evt
	memcpy(ag_ready_evt, AG_READY_EVT, sizeof(AG_READY_EVT));
	*bufptr = ag_ready_evt;
	*size = sizeof(AG_READY_EVT);
	internal_reset = false;
	APP_TRACE("    AG Ready");
    } else if (check_evt_opcode(*bufptr) && fake_hcievent()) {
	// Overwrite HCI Event
	curr_vnd_hdlr->cmd_cmp_hdlr(bufptr, size);
	reset_stage();
    } else {
	reset_stage();
    }
    return (RV_NEXT);
}

#ifdef CFG_VND_PSM
__FAST static rep_vec_err_t
vendor_specific_prevent_ble_sleep(bool *prevent)
{
    if (cmd_psm >= PSM_DEEP) {
	return RV_NEXT;
    }

    *prevent = true;
    return (RV_DONE);
}

__FAST static rep_vec_err_t
vendor_specific_prevent_ret(bool *prevent, int32_t *pseq_dur, int32_t ble_dur)
{
    if (cmd_psm >= PSM_RETAIN) {
	return RV_NEXT;
    }

    *prevent = true;
    return RV_DONE;
}

__FAST static rep_vec_err_t
vendor_specific_prevent_hib(bool *prevent, int32_t *pseq_dur, int32_t ble_dur)
{
    if (cmd_psm >= PSM_HIBERNATE) {
	return RV_NEXT;
    }

    *prevent = true;
    return RV_DONE;
}
#endif

static rep_vec_err_t vendor_specific_plf_reset(void)
{
    uart_deinit();
    return (RV_NEXT);
}

#ifdef FORCE_TX_PWR
static rep_vec_err_t atm_vendor_tx_pwr_init(void)
{
    DEBUG_TRACE("default Tx power: %d dBm", FORCE_TX_PWR);
    atm_ble_set_rftest_txpwr(FORCE_TX_PWR);
    atm_ble_set_txpwr_max(FORCE_TX_PWR);
    return RV_NEXT;
}
#endif
#endif // CONFIG_SOC_FAMILY_ATM

#ifdef CONFIG_SOC_FAMILY_ATM
static int sys_vendor_init(void)
{
#ifdef CFG_RUNTIME_EN_HCI_VENDOR
    if (is_boot_uninit()) {
	LOG_DBG("is_boot_uninit, clear hci_vendor_en flag");
	hci_vendor_en = false;
	return 0;
    }

    if (!hci_vendor_en) {
	LOG_DBG("!hci_vendor_en");
	return 0;
    }
#endif
    atm_uart_init();
    return 0;
}
SYS_INIT(sys_vendor_init, APPLICATION, CONFIG_KERNEL_INIT_PRIORITY_DEVICE);

void atm_vendor_init(void)
{
#ifdef CFG_RUNTIME_EN_HCI_VENDOR
    if (!hci_vendor_en) {
	LOG_DBG("!hci_vendor_en");
	return;
    }
#endif
    atm_vendor_handler_register(vendor_handler_tab,
	ARRAY_SIZE(vendor_handler_tab));
    atm_hci_init();
}
#else // CONFIG_SOC_FAMILY_ATM
#ifdef CFG_RUNTIME_EN_HCI_VENDOR
__attribute__((constructor))
static void
vendor_specific_init_constructor(void)
{
    if (is_boot_uninit()) {
	APP_TRACE("is_boot_uninit, clear hci_vendor_en flag");
	hci_vendor_en = false;
	return;
    }

    if (!hci_vendor_en) {
	APP_TRACE("!hci_vendor_en");
	return;
    }

    uart_init();
#else
void vendor_specific_init(void)
{
    hci_vendor_en = true;
#endif

    RV_PLF_UART_RX_BUFFER_ADD(vendor_uart_event);
    RV_PLF_UART_WRITE_ADD(vendor_uart_write);
    RV_PLF_RESET_ADD_LAST(vendor_specific_plf_reset);

#ifdef CFG_VND_PSM
    RV_PREVENT_BLE_SLEEP_ADD(vendor_specific_prevent_ble_sleep);
    RV_PLF_PREVENT_RETENTION_ADD(vendor_specific_prevent_ret);
    RV_PLF_PREVENT_HIBERNATION_ADD(vendor_specific_prevent_hib);

    DEBUG_TRACE("sleep_enable: %#x", pseq_get_sleep_enable());
#endif

#ifdef FORCE_TX_PWR
    RV_APPM_INIT_ADD(atm_vendor_tx_pwr_init);
#endif

    ag_ready_evt = malloc(sizeof(AG_READY_EVT));
}
#endif // CONFIG_SOC_FAMILY_ATM

void atm_vendor_enter_hci_vendor_mode(void)
{
    hci_vendor_en = true;
#ifdef CONFIG_SOC_FAMILY_ATM
    sys_reboot(RESET_NO_ERROR);
#else
    platform_reset(RESET_NO_ERROR);
#endif
}

void atm_vendor_exit_hci_vendor_mode(void)
{
    hci_vendor_en = false;
#ifdef CONFIG_SOC_FAMILY_ATM
    sys_reboot(RESET_NO_ERROR);
#else
    platform_reset(RESET_NO_ERROR);
#endif
}

bool atm_vendor_get_hci_vendor_en(void)
{
    return hci_vendor_en;
}
