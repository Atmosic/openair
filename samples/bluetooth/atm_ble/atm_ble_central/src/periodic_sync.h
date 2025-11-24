/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef PERIODIC_SYNC_H
#define PERIODIC_SYNC_H

/**
 * @file periodic_sync.h
 * @brief Periodic advertising synchronization functionality for ATM BLE central sample
 */

/**
 * @brief Start periodic advertising synchronization demonstration
 *
 * This function scans for periodic advertising devices and synchronizes
 * with them to receive periodic advertising data. It handles device discovery,
 * sync creation, and data reception.
 *
 * @return 0 on success, non-zero on error
 */
int periodic_sync(void);

#endif /* PERIODIC_SYNC_H */
