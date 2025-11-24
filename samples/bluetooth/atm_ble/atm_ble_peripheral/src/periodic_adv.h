/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef PERIODIC_ADV_H
#define PERIODIC_ADV_H

/**
 * @file periodic_adv.h
 * @brief Periodic advertising functionality for ATM BLE peripheral sample
 */

/**
 * @brief Start periodic advertising demonstration
 *
 * This function initializes and starts periodic advertising with extended
 * advertising support. It creates a non-connectable advertising set and
 * periodically updates the advertising data.
 *
 * @return 0 on success, non-zero on error
 */
int periodic_adv(void);

#endif /* PERIODIC_ADV_H */
