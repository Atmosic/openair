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
#include "bb_ble_api_op.h"
#include "pal_bb.h"
#include "pal_cfg.h"
#include "pal_sys.h"
#include "pal_crypto.h"
#include "radio_hal_common.h"
#include "radio_req_ble.h"
#ifdef RF4CE_LIB
#include "rf4ce_bufpool.h"
#endif
#include "bstream.h"
#ifdef USE_ATM_UMAC
#include "eui.h"
#include "radio_umac_154.h"
#endif
#include "atm_aes.h"
#include "atm_utils_math.h"

#ifdef CONFIG_BT_BUF_ACL_TX_COUNT
#define BLE_NUM_TXBUF CONFIG_BT_BUF_ACL_TX_COUNT
#endif
#ifdef CONFIG_BT_BUF_ACL_RX_COUNT_EXTRA
// Some applications request a very high number of buffers. Limit the
// total to something reasonable
#ifdef CONFIG_ATMWSTK_PD50
#define ACL_RX_COUNT_EXTRA_MAX 4
#else
#define ACL_RX_COUNT_EXTRA_MAX 16
#endif
#define BT_BUF_ACL_RX_COUNT_EXTRA \
    ((CONFIG_BT_BUF_ACL_RX_COUNT_EXTRA > ACL_RX_COUNT_EXTRA_MAX) ? \
	    ACL_RX_COUNT_EXTRA_MAX : \
	    CONFIG_BT_BUF_ACL_RX_COUNT_EXTRA)
// See Zephyr's 4.1 migration guide for an explanation of ACL RX buffer
// allocation. We need to allocate enough buffers in the LL to match what
// the host expects. Also see the deprecation warning in buf.h:
// "When CONFIG_BT_BUF_ACL_RX_COUNT is removed, remove the MAX"
#define BLE_MIN_NUM_RXBUF \
    (ATM_MAX(CONFIG_BT_BUF_ACL_RX_COUNT, 1) + BT_BUF_ACL_RX_COUNT_EXTRA)
#endif
#ifdef CONFIG_BT_ISO_TX_BUF_COUNT
#define BLE_NUM_ISO_TXBUF CONFIG_BT_ISO_TX_BUF_COUNT
#endif
#ifdef CONFIG_BT_ISO_RX_BUF_COUNT
#define BLE_NUM_ISO_RXBUF CONFIG_BT_ISO_RX_BUF_COUNT
#endif

#ifdef CONFIG_BT_BUF_CMD_TX_COUNT
#define BLE_NUM_HCI_CMD_BUFS CONFIG_BT_BUF_CMD_TX_COUNT
#elif !defined(BLE_NUM_HCI_CMD_BUFS)
#define BLE_NUM_HCI_CMD_BUFS 0
#endif // CONFIG_BT_BUF_CMD_TX_COUNT
#ifdef CONFIG_BT_BUF_EVT_RX_COUNT
#define BLE_NUM_HCI_EVT_BUFS CONFIG_BT_BUF_EVT_RX_COUNT
#elif !defined(BLE_NUM_HCI_EVT_BUFS)
#define BLE_NUM_HCI_EVT_BUFS 0
#endif
#define BLE_NUM_HCI_BUFS (BLE_NUM_HCI_CMD_BUFS + BLE_NUM_HCI_EVT_BUFS)

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
#endif // BLE_NUM_TXBUF
#ifdef BLE_MIN_NUM_RXBUF
    // Always maintain a minimum number of ACL RX buffers
    pc_ctr_ll_rt_cfg.numRxBufs =
	ATM_MAX(BLE_MIN_NUM_RXBUF, pc_ctr_ll_rt_cfg.numRxBufs);
#endif // CONFIG_BT_BUF_ACL_RX_COUNT_EXTRA
#ifdef MAX_ACL_TXBUF_SIZE
    pc_ctr_ll_rt_cfg.maxAclLen = MAX_ACL_TXBUF_SIZE;
#endif
#ifdef BLE_NUM_ISO_TXBUF
    pc_ctr_ll_rt_cfg.numIsoTxBuf = BLE_NUM_ISO_TXBUF;
#endif
#ifdef BLE_NUM_ISO_RXBUF
    pc_ctr_ll_rt_cfg.numIsoRxBuf = BLE_NUM_ISO_RXBUF;
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
#ifdef CONFIG_ATM_BLE_CS_NUM_ANTENNAS
    pc_ctr_ll_rt_cfg.csNumAntSup = CONFIG_ATM_BLE_CS_NUM_ANTENNAS;
#endif

    // Configure Channel Sounding Sync PHY support
    // csOptCsSyncPhysSup bit definitions:
    // bit 0: 1M PHY (always supported, not configurable)
    // bit 1: 2M PHY (configurable via CONFIG_ATM_BLE_CS_SYNC_PHY_2M_ENABLE)
    // bit 2: 2M BT 2.0 PHY (configurable via
    // CONFIG_ATM_BLE_CS_SYNC_PHY_2M_BT2_ENABLE)
    pc_ctr_ll_rt_cfg.csOptCsSyncPhysSup = 0
#ifdef ATM_BLE_CS_SYNC_PHY_2M_ENABLE
	| (1 << 1) // Enable 2M PHY
#endif
#ifdef ATM_BLE_CS_SYNC_PHY_2M_BT2_ENABLE
	| (1 << 2) // Enable 2M BT 2.0 PHY
#endif
	;
#ifdef DIS_SCAN_RANDOM_BACKOFF
    pc_ctr_ll_rt_cfg.defaultOpModeFlags &= ~LL_OP_MODE_FLAG_ENA_SCAN_BACKOFF;
#endif
#ifdef BLE_CS_DBG_VECTOR
    pc_ctr_ll_rt_cfg.defaultOpModeFlags |= LL_OP_MODE_FLAG_ENA_CS_DBG_VECTOR;
#endif
}

static void pc_ctr_wsf_init(void)
{
#ifndef WSF_MSG_HDR_SIZE
#define WSF_MSG_HDR_SIZE 8
#endif
    uint16_t const max_rpt_buf_size = WSF_MSG_HDR_SIZE + 2 + 255;
    uint16_t const data_buf_size = WSF_MSG_HDR_SIZE +
#if LL_FEAT_ISO && defined(ENA_LL_FEAT_ISO)
	HCI_ISO_DL_MAX_LEN +
#endif
	pc_ctr_ll_rt_cfg.maxAclLen + 4 + BB_DATA_PDU_TAILROOM + HCI_ACL_HDR_LEN;

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
    wsfBufPoolDesc_t pool_desc[] = {
	{ 16, 8 },
	{ 32, 4 },
	{ 128, report_15_4_pkt_pool_cnt },
	{ max_rpt_buf_size, pc_ctr_ll_rt_cfg.maxAdvReports +
	    pc_ctr_ll_rt_cfg.numIqReports },       // Extended reports
#if BLE_NUM_HCI_BUFS > 0
	{ WSF_MSG_HDR_SIZE + 258, BLE_NUM_HCI_BUFS },
#endif
	{ data_buf_size,   pc_ctr_ll_rt_cfg.numTxBufs +
	    pc_ctr_ll_rt_cfg.numRxBufs + pc_ctr_ll_rt_cfg.numIsoTxBuf +
	    pc_ctr_ll_rt_cfg.numIsoRxBuf },
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

#ifdef CONFIG_ATM_LCROM_IFACE
#include "lcrom_iface.h"
#include "string.h"
#include "vectors.h"
extern void ChciTrInit(uint16_t maxAclLen, uint16_t maxIsoSduLen);
extern void ChciTrWrite(uint8_t prot, uint8_t type, uint16_t len,
    uint8_t *pData);
#include "radio_hal_frc.h"
#include "radio_hal_ble_cte.h"
#include "radio_hal_ble_cs.h"
#include "uECC_ll.h"

// Compile in stub functions for debugging when not building debug
#if !PLF_DEBUG
static void assert_err(const char *condition, const char *file, int line)
{
}

static void assert_param(int param0, int param1, const char *file, int line)
{
}

static __PRINTF(1, 2) int debug_trace(const char *format, ...)
{
    return 0;
}
#endif

#define __DECLARE_LCROM_ARRAYS
#include "libblell.h"

#define NUM_IRQ (EXPIRQn_128 + NVIC_USER_IRQ_OFFSET) // 128 synthesised IRQs
__attribute__((section(".data_text")))
__aligned(0x200) uint32_t ram_vector_table[NUM_IRQ];

void pc_ctr_early_init(void)
{
    // Initialize LCROM's GOT before it is marked read-only by the MPU
    memcpy((void *)LCROM_GOT_BASE, &lcrom_got, sizeof(lcrom_got));
    // Initialize LCROM's BSS and DATA
    lcrom_iface_init(lcrom_abs);

    // Copy all interrupt handlers into RAM when using the LCROM
    memcpy(ram_vector_table, (uint32_t *)SCB->VTOR, sizeof(ram_vector_table));
    SCB->VTOR = (uint32_t)ram_vector_table;
}
#endif

static void pc_ctr_assert_fail_crit(uint32_t assert_addr)
{
#if defined(CONFIG_SOC_FAMILY_ATM) && defined(CONFIG_ASSERT)
    __ASSERT(false, "ll asserted at: 0x%" PRIx32, assert_addr);
#elif defined(CFG_DBG) || defined(CFG_PLF_DEBUG)
    ASSERT_INFO(false, assert_addr, 0);
#else
    printf("ll asserted at: 0x%" PRIx32, assert_addr);
#endif
}

void pc_ctr_main(void)
{
    if (PalSysRegisterAssertFailCb) {
	PalSysRegisterAssertFailCb(pc_ctr_assert_fail_crit);
    }
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
#ifdef CONFIG_SOC_FAMILY_ATM
	.featureEn = 0
#ifdef CONFIG_ATM_ENA_LL_FEAT_CENTRAL
	    | LL_FEATURE_INIT_CENTRAL
#endif
#ifdef CONFIG_ATM_ENA_LL_FEAT_PERIPHERAL
	    | LL_FEATURE_INIT_PERIPHERAL
#endif
#ifdef CONFIG_ATM_ENA_LL_FEAT_BROADCASTER
	    | LL_FEATURE_INIT_BROADCASTER
#endif
#ifdef CONFIG_ATM_ENA_LL_FEAT_OBSERVER
	    | LL_FEATURE_INIT_OBSERVER
#endif
#ifdef CONFIG_ATM_ENA_LL_FEAT_CS
	    | LL_FEATURE_INIT_CS
#endif
#ifdef CONFIG_ATM_ENA_LL_FEAT_BIS
	    | LL_FEATURE_INIT_BIS
#endif
#ifdef CONFIG_ATM_ENA_LL_FEAT_CIS
	    | LL_FEATURE_INIT_CIS
#endif
#ifdef CONFIG_ATM_ENA_LL_FEAT_ISO
	    | LL_FEATURE_INIT_ISO
#endif
#ifdef CONFIG_ATM_ENA_LL_FEAT_PAWR
	    | LL_FEATURE_INIT_PAWR
#endif
#ifdef CONFIG_ATM_ENA_LL_FEAT_EXT
	    | LL_FEATURE_INIT_EXTFEAT
#endif
#ifdef CONFIG_ATM_ENA_LL_FEAT_DBAF
	    | LL_FEATURE_INIT_DBAF
#endif
#ifdef CONFIG_ATM_ENA_LL_FEAT_MONADV
	    | LL_FEATURE_INIT_MONADV
#endif
#else // CONFIG_SOC_FAMILY_ATM
	.featureEn = LL_FEATURE_INIT_ALL
#endif // CONFIG_SOC_FAMILY_ATM
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

    PalSysCiSetPriority(IRQ_PRI_MID);
    /* Setup BLE delay table with custom values (delays in microseconds) */
    static uint16_t bleSetupDelaysUs[BB_BLE_OP_NUM] = {
        [BB_BLE_OP_TEST_TX] = 500,
        [BB_BLE_OP_TEST_RX] = 500,
        [BB_BLE_OP_MST_ADV_EVENT] = 500,
        [BB_BLE_OP_SLV_ADV_EVENT] = 300,
        [BB_BLE_OP_MST_CONN_EVENT] = 300,
        [BB_BLE_OP_SLV_CONN_EVENT] = 300,
        [BB_BLE_OP_MST_AUX_ADV_EVENT] = 500,
        [BB_BLE_OP_SLV_AUX_ADV_EVENT] = 500,
        [BB_BLE_OP_SLV_PER_ADV_EVENT] = 500,
        [BB_BLE_OP_MST_PER_SCAN_EVENT] = 500,
        [BB_BLE_OP_MST_CIS_EVENT] = 500,
        [BB_BLE_OP_SLV_CIS_EVENT] = 500,
        [BB_BLE_OP_MST_BIS_EVENT] = 500,
        [BB_BLE_OP_SLV_BIS_EVENT] = 500,
        [BB_BLE_OP_DAA_EDS_EVENT] = 500,
        [BB_BLE_OP_PAWR_RSP_EVENT] = 500,
        [BB_BLE_OP_INIT_CS_EVENT] = 500,
        [BB_BLE_OP_REFL_CS_EVENT] = 500,
    };
    BbBleOverwriteSetupDelayTable(bleSetupDelaysUs, BB_BLE_OP_NUM);
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
