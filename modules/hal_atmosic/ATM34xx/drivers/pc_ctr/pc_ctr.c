/**
 *******************************************************************************
 *
 * @file pc_ctr.c
 *
 * @brief Link layer controller
 *
 * Copyright (C) Atmosic 2022-2025
 *
 *******************************************************************************
 */

#include "arch.h"
#if defined(CONFIG_SOC_FAMILY_ATM) && defined(CONFIG_AUTO_TEST)
#include "atm_test_common.h"
#endif
#include <inttypes.h>
#include "timer.h"
#include "pc_ctr.h"
#include "pc_ctr_sleep.h"
#include "at_apb_pseq_regs_core_macro.h"
#include "at_lc_regs_core_macro.h"

#include "ll_init_api.h"
#include "chci_tr.h"
#include "lhci_api.h"
#include "hci_defs.h"
#include "wsf_assert.h"
#include "wsf_buf.h"
#include "wsf_heap.h"
#include "wsf_os.h"
#include "wsf_timer.h"
#include "wsf_trace.h"
#include "bb_ble_sniffer_api.h"
#include "pal_bb.h"
#include "pal_cfg.h"
#include "pal_sys.h"
#include "pal_crypto.h"
#include "radio_hal_common.h"
#include "radio_req_ble.h"
#ifdef MAC154
#include "mac_154_api.h"
#endif
#ifdef RF4CE_LIB
#include "rf4ce_bufpool.h"
#endif
#include "bstream.h"
#ifdef USE_ATM_UMAC
#include "eui.h"
#include "radio_umac_154.h"
#endif
#include "atm_aes.h"

static BbRtCfg_t pc_ctr_bb_rt_cfg;
static LlRtCfg_t pc_ctr_ll_rt_cfg;

static void pc_ctr_load_config(void)
{
    PalBbCfg_t *pc_ctr_pal_bb_cfg = (PalBbCfg_t *)&pc_ctr_bb_rt_cfg;
    PalBbLoadCfg(pc_ctr_pal_bb_cfg);
#if RADIO_HAL_MGR_OMIT
    pc_ctr_pal_bb_cfg->rfSetupDelayUsec = BB_RF_SETUP_DELAY_US;
#else
    // Additional time needed for radio management
    pc_ctr_pal_bb_cfg->rfSetupDelayUsec = BB_RF_SETUP_DELAY_US + 50;
#endif
#ifdef CFG_CLKPPM_OVERRIDE
    // override the defaults CLKPPM
    pc_ctr_pal_bb_cfg->clkPpm = CFG_CLKPPM_OVERRIDE;
#endif
    LlGetDefaultRunTimeCfg(&pc_ctr_ll_rt_cfg);
    PalCfgLoadData(PAL_CFG_ID_LL_PARAM, &pc_ctr_ll_rt_cfg.maxAdvSets,
	(sizeof(LlRtCfg_t) - offsetof(LlRtCfg_t, maxAdvSets)));
#ifdef BLE_NUM_TXBUF
    pc_ctr_ll_rt_cfg.numTxBufs = BLE_NUM_TXBUF;
#endif
#ifdef BLE_NUM_ISO_TXBUF
    pc_ctr_ll_rt_cfg.numIsoTxBuf = BLE_NUM_ISO_TXBUF;
#endif
#ifdef BLE_ADV_DATA_LEN_MAX
    if (BLE_ADV_DATA_LEN_MAX > pc_ctr_ll_rt_cfg.maxExtAdvDataLen) {
	pc_ctr_ll_rt_cfg.maxExtAdvDataLen = BLE_ADV_DATA_LEN_MAX;
    }
#endif
#ifdef BLE_MAX_ADV_SET
    pc_ctr_ll_rt_cfg.maxAdvSets = BLE_MAX_ADV_SET;
    pc_ctr_ll_rt_cfg.numPawrAdvSet = BLE_MAX_ADV_SET;
#endif

#ifdef INIT_OBSERVER
#ifdef BLE_ADV_DATA_SCAN_LEN_MAX
    if (BLE_ADV_DATA_SCAN_LEN_MAX > pc_ctr_ll_rt_cfg.maxExtScanDataLen) {
	pc_ctr_ll_rt_cfg.maxExtScanDataLen = BLE_ADV_DATA_SCAN_LEN_MAX;
#define HCI_EXT_REPORT_DATA_LEN_MAX 229
	uint16_t buffer_num = (BLE_ADV_DATA_SCAN_LEN_MAX +
	    HCI_EXT_REPORT_DATA_LEN_MAX - 1) / HCI_EXT_REPORT_DATA_LEN_MAX;
	pc_ctr_ll_rt_cfg.maxAdvReports = pc_ctr_ll_rt_cfg.maxAdvReports >
	    buffer_num ? pc_ctr_ll_rt_cfg.maxAdvReports : buffer_num;
    }
#endif // BLE_ADV_DATA_SCAN_LEN_MAX
#endif // INIT_OBSERVER
#ifdef CFG_GAP_MAX_LINKS
    if (CFG_GAP_MAX_LINKS > pc_ctr_ll_rt_cfg.maxConn) {
	pc_ctr_ll_rt_cfg.maxConn = CFG_GAP_MAX_LINKS;
    }
#endif
    PalCfgLoadData(PAL_CFG_ID_BLE_PHY, &pc_ctr_ll_rt_cfg.phy2mSup,
	(sizeof(LlRtCfg_t) - offsetof(LlRtCfg_t, maxAdvSets)));
    PalCfgLoadData(PAL_CFG_ID_CTE, &pc_ctr_ll_rt_cfg.cteUnused,
	(sizeof(LlRtCfg_t) - offsetof(LlRtCfg_t, cteUnused)));

    pc_ctr_ll_rt_cfg.btVer = BT_VER;
#define ATM_COMP_ID 0x0A24
    pc_ctr_ll_rt_cfg.compId = ATM_COMP_ID;
#ifdef PC_HIGH_THD
    pc_ctr_ll_rt_cfg.pcHighThreshold = PC_HIGH_THD;
#endif
#ifdef PC_LOW_THD
    pc_ctr_ll_rt_cfg.pcLowThreshold = PC_LOW_THD;
#endif
#ifdef PC_FSU_ACL_IFS_MIN
    pc_ctr_ll_rt_cfg.fsuMinIfsAclUsec = PC_FSU_ACL_IFS_MIN;
#endif
#ifdef PC_FSU_CIS_IFS_MIN
    pc_ctr_ll_rt_cfg.fsuMinIfsCisUsec = PC_FSU_CIS_IFS_MIN;
#endif
#ifdef BLE_CS_MANDATORY_TIMING_ONLY
    pc_ctr_ll_rt_cfg.csOptTIp1TimesSup = 0;
    pc_ctr_ll_rt_cfg.csOptTIp2TimesSup = 0;
    pc_ctr_ll_rt_cfg.csOptTFcsTimesSup = 0;
    pc_ctr_ll_rt_cfg.csTSwTimeSup = 10;
#endif
#ifdef DIS_SCAN_RANDOM_BACKOFF
    pc_ctr_ll_rt_cfg.defaultOpModeFlags &= ~LL_OP_MODE_FLAG_ENA_SCAN_BACKOFF;
#endif
}

static void pc_ctr_wsf_init(void)
{
    // +12 for msg headroom, + 2 event header, +255 maximum parameter length
    uint16_t const max_rpt_buf_size = 12 + 2 + 255;

    // +12 for msg headroom, +ISO Data Load, +4 for header
    uint16_t const data_buf_size = 12 +
#if LL_FEAT_ISO && defined(ENA_LL_FEAT_ISO)
	HCI_ISO_DL_MAX_LEN +
#endif
	pc_ctr_ll_rt_cfg.maxAclLen + 4 + BB_DATA_PDU_TAILROOM;

#if LL_FEAT_ISO && defined(ENA_LL_FEAT_ISO)
    // Use single pool for data buffers
    WSF_ASSERT(pc_ctr_ll_rt_cfg.maxAclLen == pc_ctr_ll_rt_cfg.maxIsoSduLen);
#else
    pc_ctr_ll_rt_cfg.numIsoTxBuf = 0;
    pc_ctr_ll_rt_cfg.numIsoRxBuf = 0;
#endif

    // Ensure pool buffers are ordered correctly
    WSF_ASSERT(max_rpt_buf_size < data_buf_size);

    uint16_t report_15_4_pkt_pool_cnt = 0;
#ifdef INIT_OBSERVER
    report_15_4_pkt_pool_cnt += pc_ctr_ll_rt_cfg.maxAdvReports;
#endif
#ifdef MAC154
    // TODO - profile 15.4 buffer requirements
    report_15_4_pkt_pool_cnt += pc_ctr_ll_rt_cfg.maxAdvReports;
#endif
    wsfBufPoolDesc_t pool_desc[] = {
	{ 16, 8 },
	{ 32, 4 },
	{ 128, report_15_4_pkt_pool_cnt },
	{ max_rpt_buf_size, pc_ctr_ll_rt_cfg.maxAdvReports +
	    pc_ctr_ll_rt_cfg.numIqReports },       // Extended reports
	{ data_buf_size,   pc_ctr_ll_rt_cfg.numTxBufs +
	    pc_ctr_ll_rt_cfg.numRxBufs + pc_ctr_ll_rt_cfg.numIsoTxBuf +
	    pc_ctr_ll_rt_cfg.numIsoRxBuf },
#ifdef MAC154
        // TODO - profile 15.4 buffer requirements
	{ 256, 9 },
	{ 500, 4 },
#endif
    };

    uint8_t const num_pools = sizeof(pool_desc) / sizeof(pool_desc[0]);

    /* Initialize heap. */
    WsfHeapInit();
#ifdef DBG_PC_CTR_MEM_USAGE
    DEBUG_TRACE("pc_ctr heap size:%" PRIu32, WsfHeapCountAvailable());
#endif

    /* Initialize buffer configuration. */
    uint16_t mem_used = WsfBufInit(num_pools, pool_desc);
    WsfHeapAlloc(mem_used);
#ifdef DBG_PC_CTR_MEM_USAGE
    DEBUG_TRACE("pc_ctr wsfbuf used:%" PRIu32 " avail:%" PRIu32, mem_used,
	WsfHeapCountAvailable());
#endif
    /* Initialize RTOS resources. */
    WsfOsInit();
    WsfTimerInit();
#if PLF_DEBUG
    WsfTraceRegisterHandler(PalSysDiagTraceWrite);
    WsfTraceEnable(true);
#endif
}

void pc_ctr_main(void)
{
#ifdef LL_HEAP_SIZE_OVERRIDE
    PalSysInitExt(LL_HEAP_SIZE_OVERRIDE);
#else
    PalSysInit();
#endif
    PalCryptoAesEcbCbackInit(atm_aes_ecb);

    pc_ctr_load_config();
    pc_ctr_wsf_init();

    LlInitRtCfg_t ll_cfg = {
	.pBbRtCfg = &pc_ctr_bb_rt_cfg,
	.wlSizeCfg = 4,
	.rlSizeCfg = 4,
	.plSizeCfg = 4,
	.pLlRtCfg = &pc_ctr_ll_rt_cfg,
	.pFreeMem = WsfHeapGetFreeStartAddress(),
	.freeMemAvail = WsfHeapCountAvailable(),
    };

    uint32_t mem_used = LlInitControllerInit(&ll_cfg);
    WsfHeapAlloc(mem_used);
#ifdef DBG_PC_CTR_MEM_USAGE
    DEBUG_TRACE("pc_ctr LL used:%" PRIu32 " avail:%" PRIu32, mem_used,
	WsfHeapCountAvailable());
#endif

    bdAddr_t bd_addr;
    PalCfgLoadData(PAL_CFG_ID_BD_ADDR, bd_addr, sizeof(bd_addr));
    LlSetBdAddr((uint8_t const *)&bd_addr);

    uint64_t seed;
    LlGetRandNum((uint8_t *)&seed);
    LlMathSetSeed((uint32_t *)&seed);

    /* 15.4 Mac initialization */
#ifdef USE_ATM_UMAC
    atm_umac_154_init();
    uint64_t ext_addr;
    read_eui64((uint8_t *)&ext_addr);
    atm_umac_154_set_long_addr(ext_addr);
#endif

#ifdef DBG_PC_CTR_MEM_USAGE
    DEBUG_TRACE("pc_ctr final avail:%" PRIu32, WsfHeapCountAvailable());
#endif

    pc_ctr_sleep_init();
#ifdef LINK_LL_VS_LIB
    LhciVsInit();
#endif

}

bool pc_ctr_schedule(void)
{
    if (atm_mac_is_sleeping) {
	// Do not run LL events while ATLC is sleeping
	WsfOsTimerUpdate();
	return false;
    }

    return (WsfOsWork());
}

#if defined(CONFIG_SOC_FAMILY_ATM) && defined(CONFIG_AUTO_TEST)
void pc_ctr_test_passed(void)
{
    ATM_TEST_PASSED();
}

void pc_ctr_test_failed(void)
{
    ATM_TEST_FAILED();
}
#endif
