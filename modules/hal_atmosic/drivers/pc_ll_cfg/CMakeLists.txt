# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

if(CONFIG_ATM_PC_LL_CFG)
  zephyr_include_directories(.)
  zephyr_sources(pc_ll_cfg.c)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_ENC_PRIV
    ENA_LL_FEAT_ENC_PRIV)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_PC
    ENA_LL_FEAT_PC)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_CS
    ENA_LL_FEAT_CS)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_CS_ENH1
    ENA_LL_FEAT_CS_ENH1)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_CS_TEST
    ENA_LL_FEAT_CS_TEST)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_ISO
    ENA_LL_FEAT_ISO)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_CENTRAL
    ENA_LL_FEAT_CENTRAL)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_OBSERVER
    ENA_LL_FEAT_OBSERVER)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_BROADCASTER
    ENA_LL_FEAT_BROADCASTER)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_PERIPHERAL
    ENA_LL_FEAT_PERIPHERAL)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_DTM_SUPPORT
    DTM_SUPP)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_PEER_FILT
    ENA_LL_FEAT_PEER_FILT)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_DBAF
    ENA_LL_FEAT_DBAF)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_EXT
    ENA_LL_FEAT_EXTFEAT)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_MONADV
    ENA_LL_FEAT_MONADV)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_FSU
    ENA_LL_FEAT_FSU)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_ECU
    ENA_LL_FEAT_ECU)
  if(CONFIG_BT_HCI_RAW OR NOT CONFIG_BT_EXT_ADV OR CONFIG_BT_EXT_ADV_LEGACY_SUPPORT)
    zephyr_compile_definitions(ENA_LL_FEAT_LEGACY_ADV)
  endif()
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_EXT_ADV
    ENA_LL_FEAT_EXT_ADV)
  # note: to support extended scanning CONFIG_BT_EXT_ADV must be set along
  # with BT_OBSERVER
  if(CONFIG_BT_HCI_RAW OR (CONFIG_BT_EXT_ADV AND CONFIG_BT_OBSERVER))
    zephyr_compile_definitions(ENA_LL_FEAT_EXT_SCAN)
  endif()
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_RX
    ENA_LL_RX)
endif()
