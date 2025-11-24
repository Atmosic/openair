################################################################################
#
# @file pc_ll_cfg.mk
#
# @brief Link layer related configuration makefile
#
# Copyright (C) Atmosic 2025
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

CFLAGS += $(if $(ENA_LL_FEAT_ISO),\
	    -DENA_LL_FEAT_ISO,\
	    $(call D4_OPT,FULL,$(DEFAULT_DIS_LL_FEAT_ISO),-DENA_LL_FEAT_ISO))

CFLAGS += $(if $(ENA_LL_FEAT_CENTRAL),\
	    -DENA_LL_FEAT_CENTRAL,\
	    $(call D4_OPT,PD50,$(DEFAULT_DIS_LL_FEAT_CENTRAL),-DENA_LL_FEAT_CENTRAL))

ifndef DEFAULT_DIS_LL_FEAT_LEGACY_ADV
CFLAGS += -DENA_LL_FEAT_LEGACY_ADV
endif

ifndef DEFAULT_DIS_DTM_SUPP
CFLAGS += -DDTM_SUPP
endif

ifndef DEFAULT_DIS_LL_FEAT_EXT_ADV
CFLAGS += -DENA_LL_FEAT_EXT_ADV
endif
