/**
 *******************************************************************************
 *
 * @file radio_hal_ble_cs.c
 *
 * @brief Channel sounding driver
 *
 * Copyright (C) Atmosic 2024-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include "arch.h"
#include "radio_hal_ble_cs.h"

uint8_t atm_mac_ble_cs_phase_adj_en;

void atm_mac_ble_cs_set_sync_wrd(uint32_t itx_sync_wrd, uint32_t rtx_sync_wrd)
{
}

void atm_mac_ble_cs_cancel_ifs(void)
{
}

void atm_mac_ble_cs_enable_cs(cs_enable_t *param)
{
}

void atm_mac_ble_cs_set_channel_index(uint8_t index)
{
}

void atm_mac_ble_cs_set_seq(uint8_t seq_len, uint8_t const *itx_seq_data,
    uint8_t const *rtx_seq_data)
{
}

void atm_mac_ble_cs_get_step_rpt(cs_step_rpt_type *rpt)
{
}

void atm_mac_ble_cs_set_mode(uint8_t cs_mode)
{
}

void atm_mac_ble_cs_set_t_para(uint32_t rx_to)
{
}

void atm_mac_ble_cs_set_critical_param(uint8_t mode, uint8_t chan)
{
}

void atm_mac_ble_cs_set_ifs_early(uint32_t due_time, bool is_tx, uint32_t rx_to)
{
}

void atm_mac_ble_cs_set_ant_sw(uint8_t sw_len, uint8_t const *ant_id,
    bool itx_ext_prsnt, bool rtx_ext_prsnt)
{
}

void atm_mac_ble_cs_enable_bt20(bool enable)
{
}

void atm_mac_ble_cs_kick_step(uint32_t due_time)
{
}
