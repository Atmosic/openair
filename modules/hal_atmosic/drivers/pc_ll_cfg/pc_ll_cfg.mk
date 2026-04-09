################################################################################
#
# @file pc_ll_cfg.mk
#
# @brief Link layer related configuration makefile
#
# Copyright (C) Atmosic 2025-2026
#
################################################################################

pc_ll_cfg.C_SRCS += pc_ll_cfg.c


D4_OPT = $(if $(filter $(1),$(ATMWSTKLIB) $(LL_VER)),,$(if $(2),,$(3)))

CFLAGS += $(if $(ENA_LL_FEAT_PC),\
	    -DENA_LL_FEAT_PC,\
	    $(call D4_OPT,PD50,$(DEFAULT_DIS_LL_FEAT_PC),-DENA_LL_FEAT_PC))

CFLAGS += $(if $(ENA_LL_FEAT_CS),\
	    -DENA_LL_FEAT_CS,\
	    $(call D4_OPT,PD50 CPD200,$(DEFAULT_DIS_LL_FEAT_CS),-DENA_LL_FEAT_CS))

CFLAGS += $(if $(ENA_LL_FEAT_CS_TEST),\
	    -DENA_LL_FEAT_CS_TEST,\
	    $(call D4_OPT,PD50 CPD200,$(DEFAULT_DIS_LL_FEAT_CS_TEST),-DENA_LL_FEAT_CS_TEST))

CFLAGS += $(if $(ENA_LL_FEAT_ISO),\
	    -DENA_LL_FEAT_ISO,\
	    $(call D4_OPT,FULL,$(DEFAULT_DIS_LL_FEAT_ISO),-DENA_LL_FEAT_ISO))

CFLAGS += $(if $(ENA_LL_FEAT_CENTRAL),\
	    -DENA_LL_FEAT_CENTRAL,\
	    $(call D4_OPT,PD50,$(DEFAULT_DIS_LL_FEAT_CENTRAL),-DENA_LL_FEAT_CENTRAL))

CFLAGS += $(if $(ENA_LL_FEAT_OBSERVER),\
	    -DENA_LL_FEAT_OBSERVER,\
	    $(call D4_OPT,PD50,$(DEFAULT_DIS_LL_FEAT_OBSERVER),-DENA_LL_FEAT_OBSERVER))

CFLAGS += $(if $(ENA_LL_FEAT_EXTFEAT),\
            -DENA_LL_FEAT_EXTFEAT,\
            $(call D4_OPT,PD50 CPD200,$(DEFAULT_DIS_LL_FEAT_EXTFEAT),-DENA_LL_FEAT_EXTFEAT))

CFLAGS += $(if $(ENA_LL_FEAT_MONADV),\
            -DENA_LL_FEAT_MONADV,\
            $(call D4_OPT,PD50 CPD200,$(DEFAULT_DIS_LL_FEAT_MONADV),-DENA_LL_FEAT_MONADV))

CFLAGS += $(if $(ENA_LL_FEAT_FSU),\
            -DENA_LL_FEAT_FSU,\
            $(call D4_OPT,PD50 CPD200,$(DEFAULT_DIS_LL_FEAT_FSU),-DENA_LL_FEAT_FSU))

ifndef DEFAULT_DIS_LL_FEAT_ENC_PRIV
CFLAGS += -DENA_LL_FEAT_ENC_PRIV
endif

ifndef DEFAULT_DIS_LL_FEAT_LEGACY_ADV
CFLAGS += -DENA_LL_FEAT_LEGACY_ADV
endif

ifndef DEFAULT_DIS_LL_FEAT_PERIPHERAL
CFLAGS += -DENA_LL_FEAT_PERIPHERAL
endif

ifndef DEFAULT_DIS_LL_FEAT_BROADCASTER
CFLAGS += -DENA_LL_FEAT_BROADCASTER
endif

ifndef DEFAULT_DIS_LL_FEAT_PEER_FILT
CFLAGS += -DENA_LL_FEAT_PEER_FILT
endif

ifndef DEFAULT_DIS_DTM_SUPP
CFLAGS += -DDTM_SUPP
endif

ifndef DEFAULT_DIS_LL_FEAT_EXT_ADV
CFLAGS += -DENA_LL_FEAT_EXT_ADV
endif

ifndef DEFAULT_DIS_LL_FEAT_EXT_SCAN
CFLAGS += -DENA_LL_FEAT_EXT_SCAN
endif
