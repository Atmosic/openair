/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @brief SPE Secure Fault Storage Internal API
 *
 * This header provides internal function declarations for SPE secure fault
 * storage functionality. These functions are used within the SPE to manage
 * secure fault data storage in dedicated memory region.
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <zephyr/arch/arm/exception.h>

/**
 * @brief Record secure fault information
 *
 * Records secure fault data including fault reason, register state,
 * and secure fault status registers.
 *
 * @param reason Fault reason code
 * @param esf Pointer to exception stack frame containing register state
 */
void atm_spe_secure_fault_record(uint32_t reason, const struct arch_esf *esf);
