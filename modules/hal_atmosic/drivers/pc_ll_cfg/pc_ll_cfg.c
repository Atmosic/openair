
/**
 *******************************************************************************
 *
 * @file pc_ll_cfg.c
 *
 * @brief Link controller related configuration
 *
 * Copyright (C) Atmosic 2022-2025
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#endif

#include "eui.h"
#include "string.h"
#include "pal_cfg.h"
#include "bstream.h"
#include "ll_api.h"
#include "lhci_api.h"
#include "bb_ble_api.h"
#include "cs_api.h"

static bool pc_ll_cfg_load_user_cfg(uint8_t cfgId, void *pBuf, uint32_t len)
{
    uint8_t *buf = pBuf;
    switch (cfgId) {
	case PAL_CFG_ID_BD_ADDR: {
	    ASSERT_ERR(len == EUI48_LEN_BYTES);
	    return read_eui48(buf);
	}
	case PAL_CFG_ID_MAC_ADDR: {
	    ASSERT_ERR(len == EUI64_LEN_BYTES);
	    read_eui64(buf);
	    return true;
	}
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

#ifndef CONFIG_ATM_LCROM_IFACE
// Use strong symbol to disable power control feature
#if LL_FEAT_PC && !defined(ENA_LL_FEAT_PC)
void LlPowerControlInit(void)
{
}

void LhciPowerControlInit(void)
{
}
#endif

// Use strong symbol to disable channel sounding feature
#if LL_FEAT_CS && !defined(ENA_LL_FEAT_CS)
void LlCsCentralInit(void)
{
}

void LlCsPeripheralInit(void)
{
}

void BbBleCsInitiatorInit(void)
{
}

void BbBleCsReflectorInit(void)
{
}

void LhciCsInit(void)
{
}

uint32_t LlInitCsMem(uint8_t *pFreeMem, uint32_t freeMemSize)
{
    return 0;
}
#endif

#if LL_FEAT_ISO && !defined(ENA_LL_FEAT_ISO)
void BbBleBisMasterInit(void)
{
}

void BbBleBisSlaveInit(void)
{
}

void BbBleCisMasterInit(void)
{
}

void BbBleCisSlaveInit(void)
{
}

void LhciBisMasterInit(void)
{
}

void LhciBisSlaveInit(void)
{
}

void LhciCisSlaveInit(void)
{
}

void LhciCisMasterInit(void)
{
}

void LhciIsoInit(void)
{
}

void LhciIsoHandler(wsfEventMask_t event, wsfMsgHdr_t *pMsg)
{
    LhciHandler(event, pMsg);
}

void LlBisMasterInit(void)
{
}

void LlBisSlaveInit(void)
{
}

void LlCisMasterInit(void)
{
}

void LlCisSlaveInit(void)
{
}

uint32_t LlInitIsoMem(uint8_t *pFreeMem, uint32_t freeMemSize)
{
    return 0;
}

uint32_t LlInitBisMem(uint8_t *pFreeMem, uint32_t freeMemSize)
{
    return 0;
}

uint32_t LlInitCisMem(uint8_t *pFreeMem, uint32_t freeMemSize)
{
    return 0;
}
#endif

#if defined(CONFIG_SOC_FAMILY_ATM) && !defined(CONFIG_ATM_LL_ECC_SUPPORT)
void LhciScInit(void)
{
}

void PalCryptoInit(void)
{
}
#endif
#if defined(INIT_PERIPHERAL) && !defined(ENA_LL_FEAT_LEGACY_ADV)
void LhciAdvSlaveInit(void)
{
}

uint32_t LlAdvSlaveInit(uint8_t *pFreeMem, uint32_t freeMemAvail)
{
    return 0;
}
#endif
#if defined(INIT_PERIPHERAL) && !defined(ENA_LL_FEAT_EXT_ADV)
void BbBleAuxAdvSlaveInit(void)
{
}

void LhciExtAdvSlaveInit(void)
{
}

uint32_t LlInitExtAdvMem(uint8_t *pFreeMem, uint32_t freeMemSize)
{
    return 0;
}

void LlExtAdvSlaveInit(void)
{
}
#if LL_FEAT_PAWR
void LhciPawrPeripheralInit(void)
{
}

void LlPawrPeripheralInit(void)
{
}

uint32_t LlInitPawrPeripheralMem(uint8_t *pFreeMem, uint32_t freeMemSize)
{
    return 0;
}
#endif
#endif
#ifndef DTM_SUPP
uint8_t LlTxTest(LlTestTxParam_t *pTxTestParam)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

uint8_t LlRxTest(LlTestRxParam_t *pRxTestParam)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

uint8_t LlEndTest(LlTestReport_t *pRpt)
{
    return LL_ERROR_CODE_UNKNOWN_HCI_CMD;
}

uint32_t LlTestInit(uint8_t *pFreeMem, uint32_t freeMemAvail)
{
    return 0;
}

void BbBleTestInit(void)
{
}
#endif
#if defined(INIT_CENTRAL) && !defined(ENA_LL_FEAT_CENTRAL)
uint32_t LlInitMasterInit(uint8_t *pFreeMem, uint32_t freeMemAvail)
{
    return 0;
}

uint32_t LlExtInitMasterInit(uint8_t *pFreeMem, uint32_t freeMemAvail)
{
    return 0;
}

void LlConnMasterInit(void)
{
}

void LlEncConnMasterInit(void)
{
}

void LlPhyMasterInit(void)
{
}

void LhciConnMasterInit(void)
{
}

void LhciExtConnMasterInit(void)
{
}

void LhciEncMasterInit(void)
{
}
#endif
#endif // CONFIG_ATM_LCROM_IFACE
