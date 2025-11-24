################################################################################
#
# @file atm_vendor.mk
#
# @brief Atmosic vendor commands makefile
#
# Copyright (C) Atmosic 2023-2025
#
################################################################################

#
# Define CFG_VND_ALL to enable all vendor commands
# Enable vendor command by CFG_VND_XXX without CFG_VND_ALL
# Disable vendor command by CFG_VND_XXX with CFG_VND_ALL
#

define vndcmd_TEMPLATE
ifeq ($(if $(CFG_VND_ALL),$(if $($1),,1),$($1)),1)
atm_vendor.CFLAGS += -D$1
endif
endef # vndcmd_TEMPLATE

$(eval $(call vndcmd_TEMPLATE,CFG_VND_EN_TXCW))
ifeq (atm34,$(PLATFORM_FAMILY))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_CAP_V2))
else
$(eval $(call vndcmd_TEMPLATE,CFG_VND_CAP_V1))
endif
$(eval $(call vndcmd_TEMPLATE,CFG_VND_SYS_MMR))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_TAG_RD_V1))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_SET_BDDR))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_SET_ADV_CH))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_MALLOC))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_IO_CTRL))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_GADC))
ifeq (atm2,$(PLATFORM_FAMILY))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_PV_TEST))
endif
$(eval $(call vndcmd_TEMPLATE,CFG_VND_GPIO_TEST))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_PSM))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_DBG_MMR))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_DBG_MMW))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_BLE_REGR))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_BLE_REGW))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_SET_TX_PWR))
ifneq (,$(filter atm33 atm34,$(PLATFORM_FAMILY)))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_COREMARK))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_WFI))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_NO_CLOCK))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_WHILE_ONE))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_PMU_RADIO_REGR))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_PMU_RADIO_REGW))
$(eval $(call vndcmd_TEMPLATE,CFG_VND_XTAL_32K_PIN_OUT))
endif

atm_vendor.C_SRCS :=

ifneq (,$(filter -DCFG_VND_PV_TEST,$(atm_vendor.CFLAGS)))
atm_vendor.CFLAGS += \
	-DCFG_NONRF_HARV \
	-DVHARV_RANGE=VHARV_RANGE_1P7V_2P0V \
	-DVSTORE_MAX_EQ_3p3V \

endif

ifneq (,$(filter -DCFG_VND_COREMARK,$(atm_vendor.CFLAGS)))
CFG_GCC_PRINT_FLOAT := 1
COREMARK_CONTRIB := ../../../../../contrib/coremark
COREMARK_SRC_FILES := \
	$(COREMARK_CONTRIB)/core_list_join.c \
	$(COREMARK_CONTRIB)/core_main.c \
	$(COREMARK_CONTRIB)/core_matrix.c \
	$(COREMARK_CONTRIB)/core_state.c \
	$(COREMARK_CONTRIB)/core_util.c \
	$(COREMARK_CONTRIB)/$(PLATFORM_FAMILY)/core_portme.c \

atm_vendor.INCLUDES += \
	$(COREMARK_CONTRIB) \
	$(COREMARK_CONTRIB)/$(PLATFORM_FAMILY) \
	../atm_coremark_port \

atm_vendor.C_SRCS += $(COREMARK_SRC_FILES) \

endif

atm_vendor.C_SRCS += atm_vendor.c
