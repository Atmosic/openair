/**
 *******************************************************************************
 *
 * @file lcrom_patch_ref.h
 *
 * @brief External references to symbols provided by LCROM patch objects
 *
 * This file declares symbols that are implemented in patch objects and
 * used to override or extend ROM functionality via the Global Offset
 * Table (GOT).
 *
 * DO NOT EDIT - This file is auto-generated from the template and patch
 * library symbols.
 *
 * Copyright (C) Atmosic 2026
 *
 *******************************************************************************
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*RefFunc)(int dummy, ...);

/* Auto-generated patch constants below */
#define LL_OP_MODE_FLAG_DIS_CONN_PARAM_REQ_PROC (UINT64_C(1) << 32)  /*!< Disable Connection Parameters Request Procedure. */
#define LL_FEATURE_INIT_PC (1 << 14)  /*!< Initialize LL with PC (Power Control) support. */

/* Auto-generated symbol references below */
extern RefFunc LCTR_FEAT_PEER_PAGE_MASK_patch;
extern RefFunc LhciInitFinalize_patch;
extern RefFunc LhciPowerControlInit_patch;
extern RefFunc LlCsTest_patch;
extern RefFunc LlHandlerInit_patch;
extern RefFunc LlInit_patch;
extern RefFunc LlPowerControlInit_patch;
extern RefFunc LlReadAllLocalSupFeat_patch;
extern RefFunc PalRadioCsCalTonePct_patch;
extern RefFunc PalRadioCsEnableCs_patch;
extern RefFunc PalRadioCsGetStepResult_patch;
extern RefFunc lctrCsBuildOp_patch;
extern RefFunc lctrCsSendCapabilitiesReq_patch;
extern RefFunc lctrCsSendCapabilitiesRsp_patch;
extern RefFunc lctrCsStoreRemoteCapabilities_patch;
extern RefFunc lctrDecodeCtrlPduCasePduCsCapabilitiesReqAndRsp_patch;
extern RefFunc lctrSendChannelReportingInd_patch;
extern RefFunc lctrSendFeatureExtReq_patch;
extern RefFunc lctrSendFeatureExtRsp_patch;
extern RefFunc lctrSlvConnEndOp_patch;
extern RefFunc lhciCsDecodeCmdPkt_patch;
extern RefFunc lhciCsEncodeEvtPkt_patch;
extern RefFunc lhciPerPawrEncodeEvtPkt_patch;
extern RefFunc malloc_ext;

#ifdef __cplusplus
};
#endif
