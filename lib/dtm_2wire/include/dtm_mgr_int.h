/**
 *******************************************************************************
 *
 * @file dtm_mgr_int.h
 *
 * @brief DTM manager internal interface definitions
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#ifndef DTM_MGR_INTERNAL_GUARD
#error "dtm_mgr_int.h should only be included in DTM mgr source files"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <zephyr/bluetooth/hci.h>

#define HCI_STATUS_LEN 1

void dtm_process_message(uint16_t message);
void dtm_test_end(uint8_t status, uint16_t recv_count);
void dtm_reset_complete(uint8_t status);
void dtm_test_start_complete(uint8_t status);
void dtm_set_data_len_caps(uint16_t max_tx_octets, uint16_t max_tx_time, uint16_t max_rx_octets,
			   uint16_t max_rx_time);
void dtmtl_send(uint16_t message);

#ifdef __cplusplus
}
#endif
