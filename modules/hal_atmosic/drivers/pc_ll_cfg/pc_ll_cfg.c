/**
 *******************************************************************************
 *
 * @file pc_ll_cfg.c
 *
 * @brief Link controller related configuration
 *
 * Copyright (C) Atmosic 2022-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include "arch.h"
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#endif

#if !defined(CONFIG_SOC_FAMILY_ATM) || defined(CONFIG_ATM_EUI)
#include "eui.h"
#endif
#include "string.h"
#include "pal_cfg.h"
#include "bstream.h"
#include "ll_api.h"
#include "lhci_api.h"
#include "bb_ble_api.h"
#include "bb_ble_api_pdufilt.h"
#include "cs_api.h"

static bool pc_ll_cfg_load_user_cfg(uint8_t cfgId, void *pBuf, uint32_t len)
{
#if !defined(CONFIG_SOC_FAMILY_ATM) || defined(CONFIG_ATM_EUI)
    uint8_t *buf = pBuf;
#endif
    switch (cfgId) {
#if !defined(CONFIG_SOC_FAMILY_ATM) || defined(CONFIG_ATM_EUI)
	case PAL_CFG_ID_BD_ADDR: {
	    ASSERT_ERR(len == EUI48_LEN_BYTES);
	    return read_eui48(buf);
	}
	case PAL_CFG_ID_MAC_ADDR: {
	    ASSERT_ERR(len == EUI64_LEN_BYTES);
	    read_eui64(buf);
	    return true;
	}
#endif
	default:
	    break;
    }
    return false;
}

#ifndef CONFIG_SOC_FAMILY_ATM
__attribute__((constructor))
#endif
static void pc_ll_cfg_init_constructor(void)
{
    PalCfgSetUserCfgCb(pc_ll_cfg_load_user_cfg);
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int pc_ll_cfg_init(void)
{
    pc_ll_cfg_init_constructor();
    return 0;
}

SYS_INIT(pc_ll_cfg_init, PRE_KERNEL_2, 10);
#endif

/*
 * Stub functions for disabled LL features.
 *
 * Naming convention:
 * - Shared stubs: stub_<description> (e.g., stub_void_func,
 * stub_return_zero_mem)
 * - Non-shared stubs: stub_<FunctionName> (e.g., stub_LlTxTest)
 *
 * Placement:
 * - Stubs are defined at the beginning of their respective #if blocks
 * - Alias declarations are grouped at the end of the block
 *
 * Using __attribute__((alias(...))) to reduce code size and enable
 * easy identification of stubs in linker map files via "grep stub_".
 */

#ifdef CONFIG_ATM_LCROM_IFACE
#ifndef CONFIG_ATM_LL_ECC_SUPPORT
#include "uECC_ll.h"

// Stub for int fn(void) returning 1
static int stub_return_one(void)
{
    return 1;
}

static void stub_uECC_make_key_start(const uint8_t private_key[uECC_BYTES])
{
}

static void stub_uECC_make_key_complete(uint8_t public_key[uECC_BYTES * 2],
    uint8_t private_key[uECC_BYTES])
{
}

static void stub_uECC_set_rng_ll(uECC_RNG_Function rng_function)
{
}

static void
stub_uECC_shared_secret_start(const uint8_t public_key[uECC_BYTES * 2],
    const uint8_t private_key[uECC_BYTES])
{
}

static void stub_uECC_shared_secret_complete(uint8_t secret[uECC_BYTES])
{
}

static int stub_uECC_valid_public_key_ll(
    const uint8_t public_key[uECC_BYTES * 2])
{
    return 0; // All keys are invalid when ECC is not enabled
}

void uECC_make_key_start(const uint8_t private_key[uECC_BYTES])
    __attribute__((alias("stub_uECC_make_key_start")));
void uECC_make_key_complete(uint8_t public_key[uECC_BYTES * 2],
    uint8_t private_key[uECC_BYTES])
    __attribute__((alias("stub_uECC_make_key_complete")));
void uECC_set_rng_ll(uECC_RNG_Function rng_function)
    __attribute__((alias("stub_uECC_set_rng_ll")));
void uECC_shared_secret_start(const uint8_t public_key[uECC_BYTES * 2],
    const uint8_t private_key[uECC_BYTES])
    __attribute__((alias("stub_uECC_shared_secret_start")));
void uECC_shared_secret_complete(uint8_t secret[uECC_BYTES])
    __attribute__((alias("stub_uECC_shared_secret_complete")));
int uECC_valid_public_key_ll(const uint8_t public_key[uECC_BYTES * 2])
    __attribute__((alias("stub_uECC_valid_public_key_ll")));
int uECC_make_key_continue(void) __attribute__((alias("stub_return_one")));
int uECC_shared_secret_continue(void) __attribute__((alias("stub_return_one")));
#endif
#else // !CONFIG_ATM_LCROM_IFACE
// Stub for void(void) prototypes
__attribute__((unused)) static void stub_void_func(void)
{
}

// Stub for uint32_t fn(uint8_t*, uint32_t) returning 0
__attribute__((unused)) static uint32_t stub_return_zero_mem(uint8_t *pFreeMem,
    uint32_t freeMemSize)
{
    return 0;
}

// Use strong symbol to disable power control feature
#if LL_FEAT_PC && !defined(ENA_LL_FEAT_PC)
void LlPowerControlInit(void) __attribute__((alias("stub_void_func")));
void LhciPowerControlInit(void) __attribute__((alias("stub_void_func")));
#endif

// Use strong symbol to disable channel sounding feature
#if LL_FEAT_CS && !defined(ENA_LL_FEAT_CS)
void LlCsCentralInit(void) __attribute__((alias("stub_void_func")));
void LlCsPeripheralInit(void) __attribute__((alias("stub_void_func")));
void BbBleCsInitiatorInit(void) __attribute__((alias("stub_void_func")));
void BbBleCsReflectorInit(void) __attribute__((alias("stub_void_func")));
void LhciCsInit(void) __attribute__((alias("stub_void_func")));
uint32_t LlInitCsMem(uint8_t *pFreeMem, uint32_t freeMemSize)
    __attribute__((alias("stub_return_zero_mem")));
#if LL_FEAT_CS_TEST && !defined(ENA_LL_FEAT_CS_TEST)
uint8_t LhciCsTestCmd(uint8_t *pBuf)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

uint8_t LlCsTestEnd(void)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

void LmgrSendCsTestEndCmplEvent(void)
{
}
#endif // LL_FEAT_CS_TEST && !defined(ENA_LL_FEAT_CS_TEST)
#endif

#if LL_FEAT_ISO && !defined(ENA_LL_FEAT_ISO)
static void stub_LhciHandler(wsfEventMask_t event, wsfMsgHdr_t *pMsg)
{
    LhciHandler(event, pMsg);
}

void BbBleBisMasterInit(void) __attribute__((alias("stub_void_func")));
void BbBleBisSlaveInit(void) __attribute__((alias("stub_void_func")));
void BbBleCisMasterInit(void) __attribute__((alias("stub_void_func")));
void BbBleCisSlaveInit(void) __attribute__((alias("stub_void_func")));
void LhciBisMasterInit(void) __attribute__((alias("stub_void_func")));
void LhciBisSlaveInit(void) __attribute__((alias("stub_void_func")));
void LhciCisSlaveInit(void) __attribute__((alias("stub_void_func")));
void LhciCisMasterInit(void) __attribute__((alias("stub_void_func")));
void LhciIsoInit(void) __attribute__((alias("stub_void_func")));
void LhciIsoHandler(wsfEventMask_t event, wsfMsgHdr_t *pMsg)
    __attribute__((alias("stub_LhciHandler")));
void LlBisMasterInit(void) __attribute__((alias("stub_void_func")));
void LlBisSlaveInit(void) __attribute__((alias("stub_void_func")));
void LlCisMasterInit(void) __attribute__((alias("stub_void_func")));
void LlCisSlaveInit(void) __attribute__((alias("stub_void_func")));
uint32_t LlInitIsoMem(uint8_t *pFreeMem, uint32_t freeMemSize)
    __attribute__((alias("stub_return_zero_mem")));
uint32_t LlInitBisMem(uint8_t *pFreeMem, uint32_t freeMemSize)
    __attribute__((alias("stub_return_zero_mem")));
uint32_t LlInitCisMem(uint8_t *pFreeMem, uint32_t freeMemSize)
    __attribute__((alias("stub_return_zero_mem")));
#endif
#if (defined(INIT_ENCRYPTED) && !defined(ENA_LL_FEAT_ENC_PRIV)) || \
    (defined(CONFIG_SOC_FAMILY_ATM) && !defined(CONFIG_ATM_LL_ECC_SUPPORT))
void LhciScInit(void) __attribute__((alias("stub_void_func")));
void PalCryptoInit(void) __attribute__((alias("stub_void_func")));
#endif
#ifdef INIT_BROADCASTER
#if !defined(ENA_LL_FEAT_BROADCASTER)
void BbBleAdvSlaveInit(void) __attribute__((alias("stub_void_func")));
#endif
#if !defined(ENA_LL_FEAT_BROADCASTER) || !defined(ENA_LL_FEAT_LEGACY_ADV)
void LhciAdvSlaveInit(void) __attribute__((alias("stub_void_func")));
uint32_t LlAdvSlaveInit(uint8_t *pFreeMem, uint32_t freeMemAvail)
    __attribute__((alias("stub_return_zero_mem")));

#endif // !ENA_LL_FEAT_BROADCASTER || !ENA_LL_FEAT_LEGACY_ADV
#if !defined(ENA_LL_FEAT_BROADCASTER) || !defined(ENA_LL_FEAT_EXT_ADV)
void BbBleAuxAdvSlaveInit(void) __attribute__((alias("stub_void_func")));
void LhciExtAdvSlaveInit(void) __attribute__((alias("stub_void_func")));
uint32_t LlInitExtAdvMem(uint8_t *pFreeMem, uint32_t freeMemSize)
    __attribute__((alias("stub_return_zero_mem")));
void LlExtAdvSlaveInit(void) __attribute__((alias("stub_void_func")));
#if LL_FEAT_PAWR
void LhciPawrPeripheralInit(void) __attribute__((alias("stub_void_func")));
void LlPawrPeripheralInit(void) __attribute__((alias("stub_void_func")));
uint32_t LlInitPawrPeripheralMem(uint8_t *pFreeMem, uint32_t freeMemSize)
    __attribute__((alias("stub_return_zero_mem")));
#endif // LL_FEAT_PAWR
#endif // !ENA_LL_FEAT_BROADCASTER || !ENA_LL_FEAT_EXT_ADV
#endif // INIT_BROADCASTER
#ifdef INIT_PERIPHERAL
#ifndef ENA_LL_FEAT_PERIPHERAL
void BbBleConnSlaveInit(void) __attribute__((alias("stub_void_func")));
void LlConnSlaveInit(void) __attribute__((alias("stub_void_func")));
void LctrSlvConnInit(void) __attribute__((alias("stub_void_func")));
void LlPhySlaveInit(void) __attribute__((alias("stub_void_func")));
#endif // !ENA_LL_FEAT_PERIPHERAL
#if LL_FEAT_DBAF && !defined(ENA_LL_FEAT_DBAF)
void LlDbafPeripheralInit(void) __attribute__((alias("stub_void_func")));
void LhciDbafPeripheralInit(void) __attribute__((alias("stub_void_func")));
#endif // LL_FEAT_DBAF && !defined(ENA_LL_FEAT_DBAF)
#endif
#if (defined(INIT_PERIPHERAL) || defined(INIT_CENTRAL)) && \
    (!defined(DTM_SUPP) && !defined(ENA_LL_FEAT_PERIPHERAL) && \
	!defined(ENA_LL_FEAT_CENTRAL))
// DTM handlers are implemented in the PHY module which is required for
// general connectivity
void LhciPhyInit(void) __attribute__((alias("stub_void_func")));
#endif
#ifndef DTM_SUPP
static uint8_t stub_LlTxTest(LlTestTxParam_t *pTxTestParam)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

static uint8_t stub_LlRxTest(LlTestRxParam_t *pRxTestParam)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

static uint8_t stub_LlEndTest(LlTestReport_t *pRpt)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

uint8_t LlTxTest(LlTestTxParam_t *pTxTestParam)
    __attribute__((alias("stub_LlTxTest")));
uint8_t LlRxTest(LlTestRxParam_t *pRxTestParam)
    __attribute__((alias("stub_LlRxTest")));
uint8_t LlEndTest(LlTestReport_t *pRpt)
    __attribute__((alias("stub_LlEndTest")));
uint32_t LlTestInit(uint8_t *pFreeMem, uint32_t freeMemAvail)
    __attribute__((alias("stub_return_zero_mem")));
void BbBleTestInit(void) __attribute__((alias("stub_void_func")));
#endif
#ifdef INIT_CENTRAL
#ifndef ENA_LL_FEAT_CENTRAL
uint32_t LlInitMasterInit(uint8_t *pFreeMem, uint32_t freeMemAvail)
    __attribute__((alias("stub_return_zero_mem")));
uint32_t LlExtInitMasterInit(uint8_t *pFreeMem, uint32_t freeMemAvail)
    __attribute__((alias("stub_return_zero_mem")));
void LlConnMasterInit(void) __attribute__((alias("stub_void_func")));
void LlEncConnMasterInit(void) __attribute__((alias("stub_void_func")));
void LlPhyMasterInit(void) __attribute__((alias("stub_void_func")));
void LhciConnMasterInit(void) __attribute__((alias("stub_void_func")));
void LhciExtConnMasterInit(void) __attribute__((alias("stub_void_func")));
void LhciEncMasterInit(void) __attribute__((alias("stub_void_func")));
#endif // !ENA_LL_FEAT_CENTRAL
#if LL_FEAT_DBAF && !defined(ENA_LL_FEAT_DBAF)
void LlDbafCentralInit(void) __attribute__((alias("stub_void_func")));
void LhciDbafCentralInit(void) __attribute__((alias("stub_void_func")));
uint32_t LlInitDbafMem(uint8_t *pFreeMem, uint32_t freeMemSize)
    __attribute__((alias("stub_return_zero_mem")));
#endif // LL_FEAT_DBAF && !defined(ENA_LL_FEAT_DBAF)
#if LL_FEAT_MONADV && !defined(ENA_LL_FEAT_MONADV)
void LlMonAdvInit(void) __attribute__((alias("stub_void_func")));
void LhciMonAdvInit(void) __attribute__((alias("stub_void_func")));
uint32_t LlInitMonAdvMem(uint8_t *pFreeMem, uint32_t freeMemSize)
    __attribute__((alias("stub_return_zero_mem")));
#endif // LL_FEAT_MONADV && !defined(ENA_LL_FEAT_MONADV)
#endif
#if (defined(INIT_CENTRAL) || defined(INIT_PERIPHERAL)) && \
    (!defined(ENA_LL_FEAT_CENTRAL) && !defined(ENA_LL_FEAT_PERIPHERAL))
static void stub_LhciHandlerEvtAclRcvd(void)
{
    // should never be called when central and peripheral roles are disabled
    ASSERT_INFO(false, 0, 0);
}

void LhciHandlerEvtAclRcvd(void)
    __attribute__((alias("stub_LhciHandlerEvtAclRcvd")));
uint32_t LlInitConnMem(uint8_t *pFreeMem, uint32_t freeMemSize)
    __attribute__((alias("stub_return_zero_mem")));
void LhciConnInit(void) __attribute__((alias("stub_void_func")));
#endif
#if defined(INIT_OBSERVER) && \
    (!defined(ENA_LL_FEAT_OBSERVER) || !defined(ENA_LL_FEAT_EXT_SCAN))
void LlExtScanMasterInit(void) __attribute__((alias("stub_void_func")));
uint32_t LlInitExtScanMem(uint8_t *pFreeMem, uint32_t freeMemSize)
    __attribute__((alias("stub_return_zero_mem")));
void LhciExtScanMasterInit(void) __attribute__((alias("stub_void_func")));
uint32_t BbBleAuxScanMasterInit(uint8_t *pFreeMem, uint32_t freeMemAvail)
    __attribute__((alias("stub_return_zero_mem")));
void BbBlePerScanMasterInit(void) __attribute__((alias("stub_void_func")));
#if !defined(ENA_LL_FEAT_OBSERVER)
void BbBleScanMasterInit(void) __attribute__((alias("stub_void_func")));
uint32_t LlScanMasterInit(uint8_t *pFreeMem, uint32_t freeMemAvail)
    __attribute__((alias("stub_return_zero_mem")));
void LhciScanMasterInit(void) __attribute__((alias("stub_void_func")));
#endif // !ENA_LL_FEAT_OBSERVER
#endif // INIT_OBSERVER && (!ENA_LL_FEAT_OBSERVER || !ENA_LL_FEAT_EXT_SCAN)
#if LL_FEAT_EXTFEAT && !defined(ENA_LL_FEAT_EXTFEAT)
void LlExtFeatInit(void) __attribute__((alias("stub_void_func")));
void LhciExtFeatInit(void) __attribute__((alias("stub_void_func")));
uint32_t LlInitExtFeatMem(uint8_t *pFreeMem, uint32_t freeMemSize)
    __attribute__((alias("stub_return_zero_mem")));
#endif
#if LL_FEAT_FSU && !defined(ENA_LL_FEAT_FSU)
void LlFsuInit(void) __attribute__((alias("stub_void_func")));
void LhciFsuInit(void) __attribute__((alias("stub_void_func")));
uint32_t LlInitFsuMem(uint8_t *pFreeMem, uint32_t freeMemSize)
    __attribute__((alias("stub_return_zero_mem")));
#endif

#if defined(INIT_ENCRYPTED) && !defined(ENA_LL_FEAT_ENC_PRIV)
static void stub_LlEncConnSlaveInit(void)
{
    // initialize non-enc connections
    LlConnSlaveInit();
}

void LlEncConnSlaveInit(void) __attribute__((alias("stub_LlEncConnSlaveInit")));
void LlPrivInit(void) __attribute__((alias("stub_void_func")));
void LlEncInit(void) __attribute__((alias("stub_void_func")));
void LlScInit(void) __attribute__((alias("stub_void_func")));
void LctrPrivInit(void) __attribute__((alias("stub_void_func")));
void LhciEncSlaveInit(void) __attribute__((alias("stub_void_func")));
void LhciPrivAdvInit(void) __attribute__((alias("stub_void_func")));
void LhciPrivConnInit(void) __attribute__((alias("stub_void_func")));
#endif // INIT_ENCRYPTED && !ENA_LL_FEAT_ENC_PRIV
#if !defined(ENA_LL_FEAT_PEER_FILT)
// Shared stubs
static bool stub_return_false_reslist(uint8_t peerAddrType,
    uint64_t peerIdentityAddr, uint64_t *pRpa)
{
    return false;
}

static uint16_t stub_return_zero_init_list(uint8_t numEntries,
    uint8_t *pFreeMem, uint32_t freeMemSize)
{
    return 0;
}

static uint8_t stub_return_err_whitelist(uint8_t addrType, bdAddr_t pAddr)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

static bool stub_bbBleIsPeerInResList(uint8_t peerAddrType,
    uint64_t peerIdentityAddr)
{
    return false;
}

static uint8_t stub_LlGetWhitelistSize(void)
{
    return 0;
}

static uint8_t stub_LlClearWhitelist(void)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

static uint8_t stub_LlAddDeviceToResolvingList(uint8_t peerAddrType,
    const uint8_t *pPeerIdentityAddr, const uint8_t *pPeerIrk,
    const uint8_t *pLocalIrk)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

static uint8_t stub_LlRemoveDeviceFromResolvingList(uint8_t peerAddrType,
    const uint8_t *pPeerIdentityAddr)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

static uint8_t stub_LlClearResolvingList(void)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

static uint8_t stub_LlReadResolvingListSize(uint8_t *pSize)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

static uint8_t stub_LlReadResolvableAddr(uint8_t addrType,
    const uint8_t *pIdentityAddr, uint8_t *pRpa)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

static uint8_t stub_LlSetAddrResolutionEnable(uint8_t enable)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

static uint8_t stub_LlSetResolvablePrivateAddrTimeout(uint16_t rpaTimeout)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

static uint8_t stub_LlSetPrivacyMode(uint8_t peerAddrType,
    const uint8_t *pPeerIdentityAddr, uint8_t privMode)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

static uint8_t stub_LlSetDataRelatedAddrChanges(uint8_t advHandle,
    uint8_t changeReasons)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

#define RAND_ADDR_BIT_POS 6

static bool stub_BbBlePduFiltCheck(const uint8_t *pBuf,
    const bbBlePduFiltParams_t *pFiltParams, bool forceRes,
    bbBlePduFiltResults_t *pFiltResults)
{
    // bypass filter and always allow
    pFiltResults->peerAddr = BstreamToBda64(pBuf + LL_ADV_HDR_LEN);
    pFiltResults->peerAddrRand = ((pBuf[0] >> RAND_ADDR_BIT_POS) & 1);
    pFiltResults->peerMatch = true;
    return true;
}

bool BbBlePduFiltCheck(const uint8_t *pBuf,
    const bbBlePduFiltParams_t *pFiltParams, bool forceRes,
    bbBlePduFiltResults_t *pFiltResults)
    __attribute__((alias("stub_BbBlePduFiltCheck")));

// BB Whitelist stubs
uint16_t BbBleInitWhiteList(uint8_t numEntries, uint8_t *pFreeMem,
    uint32_t freeMemSize) __attribute__((alias("stub_return_zero_init_list")));
void BbBleWhiteListClear(void) __attribute__((alias("stub_void_func")));

// BB resolvable address list stubs
uint16_t BbBleInitResolvingList(uint8_t numEntries, uint8_t *pFreeMem,
    uint32_t freeMemSize) __attribute__((alias("stub_return_zero_init_list")));
void BbBleResListClear(void) __attribute__((alias("stub_void_func")));
void BbBleResListRefreshEntries(void) __attribute__((alias("stub_void_func")));
bool BbBleResListGeneratePeer(uint8_t peerAddrType, uint64_t peerIdentityAddr,
    uint64_t *pRpa) __attribute__((alias("stub_return_false_reslist")));
bool BbBleResListReadPeer(uint8_t peerAddrType, uint64_t peerIdentityAddr,
    uint64_t *pRpa) __attribute__((alias("stub_return_false_reslist")));
bool BbBleResListReadLocal(uint8_t peerAddrType, uint64_t peerIdentityAddr,
    uint64_t *pRpa) __attribute__((alias("stub_return_false_reslist")));
bool bbBleIsPeerInResList(uint8_t peerAddrType, uint64_t peerIdentityAddr)
    __attribute__((alias("stub_bbBleIsPeerInResList")));

// LL whitelist stubs
uint8_t LlGetWhitelistSize(void)
    __attribute__((alias("stub_LlGetWhitelistSize")));
uint8_t LlClearWhitelist(void) __attribute__((alias("stub_LlClearWhitelist")));
uint8_t LlAddDeviceToWhitelist(uint8_t addrType, bdAddr_t pAddr)
    __attribute__((alias("stub_return_err_whitelist")));
uint8_t LlRemoveDeviceFromWhitelist(uint8_t addrType, bdAddr_t pAddr)
    __attribute__((alias("stub_return_err_whitelist")));

// LL resolving list stubs
uint8_t LlAddDeviceToResolvingList(uint8_t peerAddrType,
    const uint8_t *pPeerIdentityAddr, const uint8_t *pPeerIrk,
    const uint8_t *pLocalIrk)
    __attribute__((alias("stub_LlAddDeviceToResolvingList")));
uint8_t LlRemoveDeviceFromResolvingList(uint8_t peerAddrType,
    const uint8_t *pPeerIdentityAddr)
    __attribute__((alias("stub_LlRemoveDeviceFromResolvingList")));
uint8_t LlClearResolvingList(void)
    __attribute__((alias("stub_LlClearResolvingList")));
uint8_t LlReadResolvingListSize(uint8_t *pSize)
    __attribute__((alias("stub_LlReadResolvingListSize")));
uint8_t LlReadPeerResolvableAddr(uint8_t addrType, const uint8_t *pIdentityAddr,
    uint8_t *pRpa) __attribute__((alias("stub_LlReadResolvableAddr")));
uint8_t LlReadLocalResolvableAddr(uint8_t addrType,
    const uint8_t *pIdentityAddr, uint8_t *pRpa)
    __attribute__((alias("stub_LlReadResolvableAddr")));
uint8_t LlSetAddrResolutionEnable(uint8_t enable)
    __attribute__((alias("stub_LlSetAddrResolutionEnable")));
uint8_t LlSetResolvablePrivateAddrTimeout(uint16_t rpaTimeout)
    __attribute__((alias("stub_LlSetResolvablePrivateAddrTimeout")));
uint8_t LlSetPrivacyMode(uint8_t peerAddrType, const uint8_t *pPeerIdentityAddr,
    uint8_t privMode) __attribute__((alias("stub_LlSetPrivacyMode")));
uint8_t LlSetDataRelatedAddrChanges(uint8_t advHandle, uint8_t changeReasons)
    __attribute__((alias("stub_LlSetDataRelatedAddrChanges")));
#endif // ENA_LL_FEAT_PEER_FILT
#endif // CONFIG_ATM_LCROM_IFACE
