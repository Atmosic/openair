#ifndef __PRF_GET_PROTO_H__
#define __PRF_GET_PROTO_H__

#if (BLE_HT_THERMOM)
extern const struct prf_task_cbs* htpt_prf_itf_get(void);
#endif // (BLE_HT_THERMOM)

#if (BLE_HT_COLLECTOR)
extern const struct prf_task_cbs* htpc_prf_itf_get(void);
#endif // (BLE_HT_COLLECTOR)

#if (BLE_DIS_SERVER)
extern const struct prf_task_cbs* diss_prf_itf_get(void);
#endif // (BLE_HT_THERMOM)

#if (BLE_DIS_CLIENT)
extern const struct prf_task_cbs* disc_prf_itf_get(void);
#endif // (BLE_DIS_CLIENT)

#if (BLE_BP_SENSOR)
extern const struct prf_task_cbs* blps_prf_itf_get(void);
#endif // (BLE_BP_SENSOR)

#if (BLE_BP_COLLECTOR)
extern const struct prf_task_cbs* blpc_prf_itf_get(void);
#endif // (BLE_BP_COLLECTOR)

#if (BLE_TIP_SERVER)
extern const struct prf_task_cbs* tips_prf_itf_get(void);
#endif // (BLE_TIP_SERVER)

#if (BLE_TIP_CLIENT)
extern const struct prf_task_cbs* tipc_prf_itf_get(void);
#endif // (BLE_TIP_CLIENT)

#if (BLE_HR_SENSOR)
extern const struct prf_task_cbs* hrps_prf_itf_get(void);
#endif // (BLE_HR_SENSOR)

#if (BLE_HR_COLLECTOR)
extern const struct prf_task_cbs* hrpc_prf_itf_get(void);
#endif // (BLE_HR_COLLECTOR)

#if (BLE_FINDME_LOCATOR)
extern const struct prf_task_cbs* findl_prf_itf_get(void);
#endif // (BLE_FINDME_LOCATOR)

#if (BLE_FINDME_TARGET)
extern const struct prf_task_cbs* findt_prf_itf_get(void);
#endif // (BLE_FINDME_TARGET)

#if (BLE_PROX_MONITOR)
extern const struct prf_task_cbs* proxm_prf_itf_get(void);
#endif // (BLE_PROX_MONITOR)

#if (BLE_PROX_REPORTER)
extern const struct prf_task_cbs* proxr_prf_itf_get(void);
#endif // (BLE_PROX_REPORTER)

#if (BLE_SP_CLIENT)
extern const struct prf_task_cbs* scppc_prf_itf_get(void);
#endif // (BLE_SP_CLENT)

#if (BLE_SP_SERVER)
extern const struct prf_task_cbs* scpps_prf_itf_get(void);
#endif // (BLE_SP_SERVER)

#if (BLE_BATT_CLIENT)
extern const struct prf_task_cbs* basc_prf_itf_get(void);
#endif // (BLE_BATT_CLIENT)

#if (BLE_BATT_SERVER)
extern const struct prf_task_cbs* bass_prf_itf_get(void);
#endif // (BLE_BATT_SERVER)

#if (BLE_HID_DEVICE)
extern const struct prf_task_cbs* hogpd_prf_itf_get(void);
#endif // (BLE_HID_DEVICE)

#if (BLE_HID_BOOT_HOST)
extern const struct prf_task_cbs* hogpbh_prf_itf_get(void);
#endif // (BLE_HID_BOOT_HOST)

#if (BLE_HID_REPORT_HOST)
extern const struct prf_task_cbs* hogprh_prf_itf_get(void);
#endif // (BLE_HID_REPORT_HOST)

#if (BLE_GL_COLLECTOR)
extern const struct prf_task_cbs* glpc_prf_itf_get(void);
#endif // (BLE_GL_COLLECTOR)

#if (BLE_GL_SENSOR)
extern const struct prf_task_cbs* glps_prf_itf_get(void);
#endif // (BLE_GL_SENSOR)

#if (BLE_RSC_COLLECTOR)
extern const struct prf_task_cbs* rscpc_prf_itf_get(void);
#endif // (BLE_RSC_COLLECTOR)

#if (BLE_RSC_SENSOR)
extern const struct prf_task_cbs* rscps_prf_itf_get(void);
#endif // (BLE_RSC_COLLECTOR)

#if (BLE_CSC_COLLECTOR)
extern const struct prf_task_cbs* cscpc_prf_itf_get(void);
#endif // (BLE_CSC_COLLECTOR)

#if (BLE_CSC_SENSOR)
extern const struct prf_task_cbs* cscps_prf_itf_get(void);
#endif // (BLE_CSC_COLLECTOR)

#if (BLE_AN_CLIENT)
extern const struct prf_task_cbs* anpc_prf_itf_get(void);
#endif // (BLE_AN_CLIENT)

#if (BLE_AN_SERVER)
extern const struct prf_task_cbs* anps_prf_itf_get(void);
#endif // (BLE_AN_SERVER)

#if (BLE_PAS_CLIENT)
extern const struct prf_task_cbs* paspc_prf_itf_get(void);
#endif // (BLE_PAS_CLIENT)

#if (BLE_PAS_SERVER)
extern const struct prf_task_cbs* pasps_prf_itf_get(void);
#endif // (BLE_PAS_SERVER)

#if (BLE_CP_COLLECTOR)
extern const struct prf_task_cbs* cppc_prf_itf_get(void);
#endif //(BLE_CP_COLLECTOR)

#if (BLE_CP_SENSOR)
extern const struct prf_task_cbs* cpps_prf_itf_get(void);
#endif //(BLE_CP_SENSOR)

#if (BLE_LN_COLLECTOR)
extern const struct prf_task_cbs* lanc_prf_itf_get(void);
#endif //(BLE_CP_COLLECTOR)

#if (BLE_LN_SENSOR)
extern const struct prf_task_cbs* lans_prf_itf_get(void);
#endif //(BLE_CP_SENSOR)

#if (BLE_IPS_SERVER)
extern const struct prf_task_cbs* ipss_prf_itf_get(void);
#endif //(BLE_IPS_SERVER)

#if (BLE_IPS_CLIENT)
extern const struct prf_task_cbs* ipsc_prf_itf_get(void);
#endif //(BLE_IPS_CLIENT)

#if (BLE_ENV_SERVER)
extern const struct prf_task_cbs* envs_prf_itf_get(void);
#endif //(BLE_ENV_SERVER)

#if (BLE_ENV_CLIENT)
extern const struct prf_task_cbs* envc_prf_itf_get(void);
#endif //(BLE_ENV_CLIENT

#if (BLE_WSC_SERVER)
extern const struct prf_task_cbs* wscs_prf_itf_get(void);
#endif //(BLE_WSC_SERVER)

#if (BLE_WSC_CLIENT)
extern const struct prf_task_cbs* wscc_prf_itf_get(void);
#endif //(BLE_WSC_CLIENT

#if (BLE_BCS_SERVER)
extern const struct prf_task_cbs* bcss_prf_itf_get(void);
#endif //(BLE_BCS_SERVER)

#if (BLE_BCS_CLIENT)
extern const struct prf_task_cbs* bcsc_prf_itf_get(void);
#endif //(BLE_BCS_CLIENT)

#if (BLE_WPT_SERVER)
extern const struct prf_task_cbs* wpts_prf_itf_get(void);
#endif //(BLE_WPT_SERVER)

#if (BLE_WPT_CLIENT)
extern const struct prf_task_cbs* wptc_prf_itf_get(void);
#endif //(BLE_WPT_CLIENT

#if (BLE_PLX_SERVER)
extern const struct prf_task_cbs* plxs_prf_itf_get(void);
#endif //(BLE_PLX_SERVER)

#if (BLE_PLX_CLIENT)
extern const struct prf_task_cbs* plxc_prf_itf_get(void);
#endif //(BLE_PLX_CLIENT

#if (BLE_CGM_SERVER)
extern const struct prf_task_cbs* cgms_prf_itf_get(void);
#endif //(BLE_CGM_SERVER)

#if (BLE_CGM_CLIENT)
extern const struct prf_task_cbs* cgmc_prf_itf_get(void);
#endif //(BLE_CGM_CLIENT

#if (BLE_ISO_MODE_0_PROFILE)
extern const struct prf_task_cbs* am0_has_prf_itf_get(void);
#endif // (BLE_ISO_MODE_0_PROFILE)

#if (BLE_UDS_SERVER)
extern const struct prf_task_cbs* udss_prf_itf_get(void);
#endif //(BLE_UDS_SERVER)

#if (BLE_UDS_CLIENT)
extern const struct prf_task_cbs* udsc_prf_itf_get(void);
#endif //(BLE_UDS_SERVER)

#if (BLE_DBG_THPP)
extern const struct prf_task_cbs* thpp_prf_itf_get(void);
#endif //(BLE_DBG_THPP)

#if (BLE_MESH)
extern const struct prf_task_cbs* mal_prf_itf_get(void);
#endif // (BLE_MESH)

#if (BLE_ANCS_CLIENT)
extern const struct prf_task_cbs* ancsc_prf_itf_get(void);
#endif // (BLE_ANCS_CLIENT)

#if (BLE_AGP_SERVER)
extern const struct prf_task_cbs* agps_prf_itf_get(void);
#endif // (BLE_AGP_SERVER)

#if (BLE_AGP_CLIENT)
extern const struct prf_task_cbs* agpc_prf_itf_get(void);
#endif // (BLE_AGP_CLIENT)

#if (BLE_TPUTP_SERVER)
extern const struct prf_task_cbs* tputps_prf_itf_get(void);
#endif //(BLE_TPUTP_SERVER)

#if (BLE_TPUTP_CLIENT)
extern const struct prf_task_cbs* tputpc_prf_itf_get(void);
#endif //(BLE_TPUTP_CLIENT)

#if (BLE_OTAP_SERVER)
extern const struct prf_task_cbs* otaps_prf_itf_get(void);
#endif //(BLE_OTAP_SERVER)

#if (BLE_DTP_SERVER)
extern const struct prf_task_cbs* dtps_prf_itf_get(void);
#endif //(BLE_DTP_SERVER)

#if (BLE_ATVV_SERVER)
extern const struct prf_task_cbs *atvvs_prf_itf_get(void);
#endif // (BLE_ATVV_SERVER)

#if (BLE_AFWPT_SERVER)
extern const struct prf_task_cbs* afwpts_prf_itf_get(void);
#endif

#endif // __PRF_GET_PROTO_H__
