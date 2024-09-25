/**
 *******************************************************************************
 *
 * @file nvds_tag.h
 *
 * @brief Atmosic nvds tag identifiers
 *
 * Copyright (C) Atmosic 2020-2023
 *
 *******************************************************************************
 */
#pragma once

#if defined(CFG_NVDS)
#include "gapc_task.h"
#include "co_bt_defines.h"
/// List of Application NVDS TAG identifiers
enum app_nvds_tag
{
    /// BD Address
    NVDS_TAG_BD_ADDRESS                 = 0x01,
    NVDS_LEN_BD_ADDRESS                 = 6,

    /// Device Name
    NVDS_TAG_DEVICE_NAME                = 0x02,
    NVDS_LEN_DEVICE_NAME                = 62,

    /// BLE Application Activity Start CMD
    NVDS_TAG_APP_BLE_ACT_STRT_CMD       = 0x05,

    /// BLE Application Activity Create CMD
    NVDS_TAG_APP_BLE_ACT_CRT_CMD        = 0x06,

    /// BLE Application Restart Duration
    NVDS_TAG_APP_BLE_RSTRT_DUR          = 0x09,

    /// BLE Application Advertising data
    NVDS_TAG_APP_BLE_ADV_DATA           = 0x0B,
    NVDS_LEN_APP_BLE_ADV_DATA           = 32,

    /// BLE Application Scan response data
    NVDS_TAG_APP_BLE_SCAN_RESP_DATA     = 0x0C,
    NVDS_LEN_APP_BLE_SCAN_RESP_DATA     = 32,

    /// BLE Application WURX CMD/data
    NVDS_TAG_APP_WURX_BLE_ACT_STRT_CMD   = 0x20,
    NVDS_TAG_APP_WURX_BLE_ACT_CRT_CMD    = 0x21,
    NVDS_TAG_APP_WURX_BLE_ADV_DATA       = 0x22,
    NVDS_TAG_APP_WURX_BLE_SCAN_RESP_DATA = 0x23,

    /// Mouse Sample Rate
    NVDS_TAG_MOUSE_SAMPLE_RATE          = 0x38,
    NVDS_LEN_MOUSE_SAMPLE_RATE          = 1,

    /// Oldest Peripheral Bonded Index
    NVDS_TAG_RECENT_BOND                = 0x36,
    NVDS_LEN_RECENT_BOND                = 2,

    /// Mouse NTF Cfg
    NVDS_TAG_MOUSE_NTF_CFG              = 0x3A,
    NVDS_LEN_MOUSE_NTF_CFG              = 6,

    /// Mouse Timeout value
    NVDS_TAG_MOUSE_TIMEOUT              = 0x3B,
    NVDS_LEN_MOUSE_TIMEOUT              = 2,

    /// Mouse Energy Safe
    NVDS_TAG_MOUSE_ENERGY_SAFE          = 0x3D,
    NVDS_LEN_MOUSE_SAFE_ENERGY          = 2,

    /// PAIRING
    NVDS_TAG_PAIRING                    = 0x3F,
    NVDS_LEN_PAIRING                    = 54,

    /// Audio mode 0 task
    NVDS_TAG_AM0_FIRST                  = 0x90,
    NVDS_TAG_AM0_LAST                   = 0x9F,

    /// Local device Identity resolving key
    NVDS_TAG_LOC_IRK                    = 0xA0,
    NVDS_LEN_LOC_IRK                    = KEY_LEN,

    /// BLE bonding meta data, consist of:
    /// [bonded] [peer_bd_addr] [peer_irk] [peer_ltk] [ltk] [peer_priv]
    NVDS_TAG_BLE_BOND_META0             = 0xA1,
    NVDS_TAG_BLE_BOND_META1             = 0xA2,
    NVDS_TAG_BLE_BOND_META2             = 0xA6,
#define NVDS_LEN_PERIPH_BONDED 1
#define NVDS_LEN_PEER_BD_ADDRESS 7
#define NVDS_LEN_PEER_IRK 23
#define NVDS_LEN_LTK 28
#define NVDS_LEN_PEER_PRIV 1
#define NVDS_LEN_BLE_BOND_META0 (NVDS_LEN_PEER_PRIV + NVDS_LEN_PERIPH_BONDED + \
    NVDS_LEN_PEER_BD_ADDRESS + NVDS_LEN_PEER_IRK + (NVDS_LEN_LTK * 2))
#define NVDS_LEN_BLE_BOND_META1 NVDS_LEN_BLE_BOND_META0
#define NVDS_LEN_BLE_BOND_META2 NVDS_LEN_BLE_BOND_META0

    /// Adv duration
    NVDS_TAG_ADV_DURATION               = 0xA3,
    /// Scan setting
    NVDS_TAG_SCAN_SETTING               = 0xA4,
    /// WURX Profile
    NVDS_TAG_WURX_PROFILE               = 0xA5,

#ifdef CFG_FRAMEWORK
    /// The NVDS tag of Bridge profile service
    NVDS_TAG_BRIDGE_SERVICE             = 0xA7,

    /// The NVDS tag of Bridge profile characteristic TRX
    NVDS_TAG_BRIDGE_CHAR_TRX            = 0xA8,

    /// The NVDS tag of Bridge profile characteristic TRX2
    NVDS_TAG_BRIDGE_CHAR_TRX2           = 0xA9,
    NVDS_LEN_BRIDGE_NVDS                = 18,
    NVDS_SHIFT_BRIDGE_SEC_PROP          = 0,
    NVDS_SHIFT_BRIDGE_UUID              = 2,

    /// The NVDS tag of UART0 setting
    NVDS_TAG_UART0_SETTING              = 0xAA,

    /// The state of default GATT server for AT CMD
    NVDS_TAG_ATCMD_BLEGATTDFTSERVER_STATE = 0xAB,

#endif // CFG_FRAMEWORK
    /// The NVDS tag of XTAL cap. value
    NVDS_TAG_MPR_XTAL_CAP               = 0xAE,

    /// NVDS address space reserved for application
    NVDS_TAG_APP_FIRST			= 0xD0,
    NVDS_TAG_APP_LAST			= 0xEF,
};

STATIC_ASSERT(NVDS_TAG_APP_FIRST == (uint8_t)PARAM_ID_APP_SPECIFIC_FIRST,
    "please make sure consistency");
STATIC_ASSERT(NVDS_TAG_APP_LAST == (uint8_t)PARAM_ID_APP_SPECIFIC_LAST,
    "please make sure consistency");
#endif // defined(CFG_NVDS)
