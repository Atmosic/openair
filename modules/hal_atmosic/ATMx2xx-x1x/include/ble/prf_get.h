
#include "prf_get_proto.h"

static const struct prf_task_cbs *
#ifdef REP_VEC
prf_itf_get_internal(uint16_t task_id)
#else
prf_itf_get(uint16_t task_id)
#endif
{
    const struct prf_task_cbs* prf_cbs = NULL;

    switch(KE_TYPE_GET(task_id))
    {
        #if (BLE_HT_THERMOM)
        case TASK_ID_HTPT:
            prf_cbs = htpt_prf_itf_get();
            break;
        #endif // (BLE_HT_THERMOM)

        #if (BLE_HT_COLLECTOR)
        case TASK_ID_HTPC:
            prf_cbs = htpc_prf_itf_get();
            break;
        #endif // (BLE_HT_COLLECTOR)

        #if (BLE_DIS_SERVER)
        case TASK_ID_DISS:
            prf_cbs = diss_prf_itf_get();
            break;
        #endif // (BLE_DIS_SERVER)

        #if (BLE_DIS_CLIENT)
        case TASK_ID_DISC:
            prf_cbs = disc_prf_itf_get();
            break;
        #endif // (BLE_DIS_CLIENT)

        #if (BLE_BP_SENSOR)
        case TASK_ID_BLPS:
            prf_cbs = blps_prf_itf_get();
            break;
        #endif // (BLE_BP_SENSOR)

        #if (BLE_BP_COLLECTOR)
        case TASK_ID_BLPC:
            prf_cbs = blpc_prf_itf_get();
            break;
        #endif // (BLE_BP_COLLECTOR)

        #if (BLE_TIP_SERVER)
        case TASK_ID_TIPS:
            prf_cbs = tips_prf_itf_get();
            break;
        #endif // (BLE_TIP_SERVER)

        #if (BLE_TIP_CLIENT)
        case TASK_ID_TIPC:
            prf_cbs = tipc_prf_itf_get();
            break;
        #endif // (BLE_TIP_CLIENT)

        #if (BLE_HR_SENSOR)
        case TASK_ID_HRPS:
            prf_cbs = hrps_prf_itf_get();
            break;
        #endif // (BLE_HR_SENSOR)

        #if (BLE_HR_COLLECTOR)
        case TASK_ID_HRPC:
            prf_cbs = hrpc_prf_itf_get();
            break;
        #endif // (BLE_HR_COLLECTOR)

        #if (BLE_FINDME_LOCATOR)
        case TASK_ID_FINDL:
            prf_cbs = findl_prf_itf_get();
            break;
        #endif // (BLE_FINDME_LOCATOR)

        #if (BLE_FINDME_TARGET)
        case TASK_ID_FINDT:
            prf_cbs = findt_prf_itf_get();
            break;
        #endif // (BLE_FINDME_TARGET)

        #if (BLE_PROX_MONITOR)
        case TASK_ID_PROXM:
            prf_cbs = proxm_prf_itf_get();
            break;
        #endif // (BLE_PROX_MONITOR)

        #if (BLE_PROX_REPORTER)
        case TASK_ID_PROXR:
            prf_cbs = proxr_prf_itf_get();
            break;
        #endif // (BLE_PROX_REPORTER)

        #if (BLE_SP_SERVER)
        case TASK_ID_SCPPS:
            prf_cbs = scpps_prf_itf_get();
            break;
        #endif // (BLE_SP_SERVER)

        #if (BLE_SP_CLIENT)
        case TASK_ID_SCPPC:
            prf_cbs = scppc_prf_itf_get();
            break;
        #endif // (BLE_SP_CLIENT)

        #if (BLE_BATT_SERVER)
        case TASK_ID_BASS:
            prf_cbs = bass_prf_itf_get();
            break;
        #endif // (BLE_BATT_SERVER)

        #if (BLE_BATT_CLIENT)
        case TASK_ID_BASC:
            prf_cbs = basc_prf_itf_get();
            break;
        #endif // (BLE_BATT_CLIENT)

        #if (BLE_HID_DEVICE)
        case TASK_ID_HOGPD:
            prf_cbs = hogpd_prf_itf_get();
            break;
        #endif // (BLE_HID_DEVICE)

        #if (BLE_HID_BOOT_HOST)
        case TASK_ID_HOGPBH:
            prf_cbs = hogpbh_prf_itf_get();
            break;
        #endif // (BLE_HID_BOOT_HOST)

        #if (BLE_HID_REPORT_HOST)
        case TASK_ID_HOGPRH:
            prf_cbs = hogprh_prf_itf_get();
            break;
        #endif // (BLE_HID_REPORT_HOST)

        #if (BLE_GL_COLLECTOR)
        case TASK_ID_GLPC:
            prf_cbs = glpc_prf_itf_get();
            break;
        #endif // (BLE_GL_COLLECTOR)

        #if (BLE_GL_SENSOR)
        case TASK_ID_GLPS:
            prf_cbs = glps_prf_itf_get();
            break;
        #endif // (BLE_GL_SENSOR)

        #if (BLE_RSC_COLLECTOR)
        case TASK_ID_RSCPC:
            prf_cbs = rscpc_prf_itf_get();
            break;
        #endif // (BLE_RSC_COLLECTOR)

        #if (BLE_RSC_SENSOR)
        case TASK_ID_RSCPS:
            prf_cbs = rscps_prf_itf_get();
            break;
        #endif // (BLE_RSC_SENSOR)

        #if (BLE_CSC_COLLECTOR)
        case TASK_ID_CSCPC:
            prf_cbs = cscpc_prf_itf_get();
            break;
        #endif // (BLE_CSC_COLLECTOR)

        #if (BLE_CSC_SENSOR)
        case TASK_ID_CSCPS:
            prf_cbs = cscps_prf_itf_get();
            break;
        #endif // (BLE_CSC_SENSOR)

        #if (BLE_CP_COLLECTOR)
        case TASK_ID_CPPC:
            prf_cbs = cppc_prf_itf_get();
            break;
        #endif // (BLE_CP_COLLECTOR)

        #if (BLE_CP_SENSOR)
        case TASK_ID_CPPS:
            prf_cbs = cpps_prf_itf_get();
            break;
        #endif // (BLE_CP_SENSOR)

        #if (BLE_LN_COLLECTOR)
        case TASK_ID_LANC:
            prf_cbs = lanc_prf_itf_get();
            break;
        #endif // (BLE_LN_COLLECTOR)

        #if (BLE_LN_SENSOR)
        case TASK_ID_LANS:
            prf_cbs = lans_prf_itf_get();
            break;
        #endif // (BLE_LN_SENSOR)

        #if (BLE_AN_CLIENT)
        case TASK_ID_ANPC:
            prf_cbs = anpc_prf_itf_get();
            break;
        #endif // (BLE_AN_CLIENT)

        #if (BLE_AN_SERVER)
        case TASK_ID_ANPS:
            prf_cbs = anps_prf_itf_get();
            break;
        #endif // (BLE_AN_SERVER)

        #if (BLE_PAS_CLIENT)
        case TASK_ID_PASPC:
            prf_cbs = paspc_prf_itf_get();
            break;
        #endif // (BLE_PAS_CLIENT)

        #if (BLE_PAS_SERVER)
        case TASK_ID_PASPS:
            prf_cbs = pasps_prf_itf_get();
            break;
        #endif // (BLE_PAS_SERVER)

        #if (BLE_ISO_MODE_0_PROFILE)
        case TASK_ID_AM0_HAS:
            prf_cbs = am0_has_prf_itf_get();
            break;
        #endif // (BLE_ISO_MODE_0_PROFILE)

        #if (BLE_IPS_SERVER)
        case TASK_ID_IPSS:
            prf_cbs = ipss_prf_itf_get();
            break;
        #endif //(BLE_IPS_SERVER)

        #if (BLE_IPS_CLIENT)
        case TASK_ID_IPSC:
            prf_cbs = ipsc_prf_itf_get();
            break;
        #endif //(BLE_IPS_CLIENT)

        #if (BLE_ENV_SERVER)
        case TASK_ID_ENVS:
            prf_cbs = envs_prf_itf_get();
            break;
        #endif //(BLE_ENV_SERVER)

        #if (BLE_ENV_CLIENT)
        case TASK_ID_ENVC:
            prf_cbs = envc_prf_itf_get();
            break;
        #endif //(BLE_ENV_CLIENT)

        #if (BLE_WSC_SERVER)
        case TASK_ID_WSCS:
            prf_cbs = wscs_prf_itf_get();
            break;
        #endif //(BLE_WSC_SERVER)

        #if (BLE_WSC_CLIENT)
        case TASK_ID_WSCC:
            prf_cbs = wscc_prf_itf_get();
            break;
        #endif //(BLE_WSC_CLIENT)

        #if (BLE_BCS_SERVER)
        case TASK_ID_BCSS:
            prf_cbs = bcss_prf_itf_get();
            break;
        #endif //(BLE_BCS_SERVER)

        #if (BLE_BCS_CLIENT)
        case TASK_ID_BCSC:
            prf_cbs = bcsc_prf_itf_get();
            break;
        #endif //(BLE_BCS_CLIENT)

        #if (BLE_UDS_SERVER)
        case TASK_ID_UDSS:
            prf_cbs = udss_prf_itf_get();
            break;
        #endif //(BLE_UDS_SERVER)

        #if (BLE_UDS_CLIENT)
        case TASK_ID_UDSC:
            prf_cbs = udsc_prf_itf_get();
            break;
        #endif //(BLE_UDS_CLIENT)

        #if (BLE_WPT_SERVER)
        case TASK_ID_WPTS:
            prf_cbs = wpts_prf_itf_get();
            break;
        #endif //(BLE_WPT_SERVER)

        #if (BLE_WPT_CLIENT)
        case TASK_ID_WPTC:
            prf_cbs = wptc_prf_itf_get();
            break;
        #endif //(BLE_WPT_CLIENT)

        #if (BLE_PLX_SERVER)
        case TASK_ID_PLXS:
            prf_cbs = plxs_prf_itf_get();
            break;
        #endif //(BLE_PLX_SERVER)

        #if (BLE_PLX_CLIENT)
        case TASK_ID_PLXC:
            prf_cbs = plxc_prf_itf_get();
            break;
        #endif //(BLE_PLX_CLIENT)

        #if (BLE_CGM_SERVER)
        case TASK_ID_CGMS:
            prf_cbs = cgms_prf_itf_get();
            break;
        #endif //(BLE_CGM_SERVER)

        #if (BLE_CGM_CLIENT)
        case TASK_ID_CGMC:
            prf_cbs = cgmc_prf_itf_get();
            break;
        #endif //(BLE_CGM_CLIENT)

        #if (BLE_DBG_THPP)
        case TASK_ID_THPP:
            prf_cbs = thpp_prf_itf_get();
            break;
        #endif //(BLE_DBG_THPP)

        #if (BLE_MESH)
        case TASK_ID_MESH:
            prf_cbs = mal_prf_itf_get();
            break;
        #endif //(BLE_MESH)

        #if (BLE_ANCS_CLIENT)
        case TASK_ID_ANCSC:
            prf_cbs = ancsc_prf_itf_get();
            break;
        #endif // (BLE_ANCS_CLIENT)

        #if (BLE_AGP_CLIENT)
        case TASK_ID_AGPC:
            prf_cbs = agpc_prf_itf_get();
            break;
        #endif // (BLE_AGP_CLIENT)

        #if (BLE_AGP_SERVER)
        case TASK_ID_AGPS:
            prf_cbs = agps_prf_itf_get();
            break;
        #endif // (BLE_AGP_SERVER)

        #if (BLE_TPUTP_SERVER)
        case TASK_ID_TPUTPS :
            prf_cbs = tputps_prf_itf_get();
            break;
        #endif //(BLE_TPUTP_SERVER)

        #if (BLE_TPUTP_CLIENT)
        case TASK_ID_TPUTPC :
            prf_cbs = tputpc_prf_itf_get();
            break;
        #endif //(BLE_TPUTP_CLIENT)

        #if (BLE_OTAP_SERVER)
        case TASK_ID_OTAPS :
            prf_cbs = otaps_prf_itf_get();
            break;
        #endif //(BLE_OTAP_SERVER)

        #if (BLE_DTP_SERVER)
        case TASK_ID_DTPS :
            prf_cbs = dtps_prf_itf_get();
            break;
        #endif //(BLE_OTAP_SERVER)

        #if (BLE_ATVV_SERVER)
        case TASK_ID_ATVVS :
            prf_cbs = atvvs_prf_itf_get();
            break;
        #endif //(BLE_ATVV_SERVER)

        #if (BLE_AFWPT_SERVER)
        case TASK_ID_AFWPTS :
            prf_cbs = afwpts_prf_itf_get();
            break;
        #endif //(BLE_AFWPT_SERVER)
        default: /* Nothing to do */ break;
    }

    return prf_cbs;
}
