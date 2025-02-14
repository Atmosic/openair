/**
 ******************************************************************************
 *
 * @file atm_bthci_utils.h
 *
 * @brief HCI utilities
 *
 * Copyright (C) Atmosic 2025
 *
 ******************************************************************************
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ATM_HCI_DUMP_CMD,
    ATM_HCI_DUMP_EVT,
    ATM_HCI_DUMP_ACL_OUT,
    ATM_HCI_DUMP_ACL_IN,
    ATM_HCI_DUMP_ISO_OUT,
    ATM_HCI_DUMP_ISO_IN,
    ATM_HCI_DUMP_MAX,
} atm_hci_dump_type_t;

#ifdef CONFIG_ATM_BTHCI_UTILS_DUMP_PKTS
/**
 * @brief dump HCI data with type
 *
 * @param type the HCI buffer type
 * @param buf HCI buffer
 * @param len length
 */
__NONNULL(2)
void atm_bthci_dump_hci_pkt(atm_hci_dump_type_t type, uint8_t const *buf,
    uint32_t len);

#define ATM_BTHCI_DUMP_HCI_PKT(t, b, l) atm_bthci_dump_hci_pkt(t, b, l)
#else
#define ATM_BTHCI_DUMP_HCI_PKT(t, b, l) \
    do { \
    } while (0)
#endif // CONFIG_ATM_BTHCI_UTILS_DUMP_PKTS

#ifdef __cplusplus
}
#endif
