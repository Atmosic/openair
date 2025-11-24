################################################################################
#
# @file pc_ctr.mk
#
# @brief Link layer control makefile
#
# Copyright (C) Atmosic 2024-2025
#
################################################################################

pc_ctr.C_SRCS += pc_ctr.c

ifdef BLE_NUM_TXBUF
CFLAGS += -DBLE_NUM_TXBUF=$(BLE_NUM_TXBUF)
endif
ifdef BLE_ADV_DATA_LEN_MAX
CFLAGS += -DBLE_ADV_DATA_LEN_MAX=$(BLE_ADV_DATA_LEN_MAX)
endif
ifdef BLE_ADV_DATA_SCAN_LEN_MAX
CFLAGS += -DBLE_ADV_DATA_SCAN_LEN_MAX=$(BLE_ADV_DATA_SCAN_LEN_MAX)
endif
ifdef CFG_CLKPPM_OVERRIDE
CFLAGS += -DCFG_CLKPPM_OVERRIDE=$(CFG_CLKPPM_OVERRIDE)
endif
ifdef BLE_MAX_ADV_SET
CFLAGS += -DBLE_MAX_ADV_SET=$(BLE_MAX_ADV_SET)
endif
ifdef PC_HIGH_THD
CFLAGS += -DPC_HIGH_THD=$(PC_HIGH_THD)
endif
ifdef PC_LOW_THD
CFLAGS += -DPC_LOW_THD=$(PC_LOW_THD)
endif
ifdef LL_HEAP_SIZE_OVERRIDE
CFLAGS += -DLL_HEAP_SIZE_OVERRIDE=$(LL_HEAP_SIZE_OVERRIDE)
endif
ifdef DBG_PC_CTR_MEM_USAGE
CFLAGS += -DDBG_PC_CTR_MEM_USAGE
endif
ifdef PC_FSU_ACL_IFS_MIN
CFLAGS += -DPC_FSU_ACL_IFS_MIN=$(PC_FSU_ACL_IFS_MIN)
endif
ifdef PC_FSU_CIS_IFS_MIN
CFLAGS += -DPC_FSU_CIS_IFS_MIN=$(PC_FSU_CIS_IFS_MIN)
endif
ifdef BLE_CS_MANDATORY_TIMING_ONLY
CFLAGS += -DBLE_CS_MANDATORY_TIMING_ONLY
endif
ifdef DIS_SCAN_RANDOM_BACKOFF
CFLAGS += -DDIS_SCAN_RANDOM_BACKOFF
endif
ifdef MAX_ACL_TXBUF_SIZE
CFLAGS += -DMAX_ACL_TXBUF_SIZE=$(MAX_ACL_TXBUF_SIZE)
endif
