/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/devicetree.h>
#include <zephyr/irq.h>
#include <zephyr/sys/__assert.h>
#include <zephyr/init.h>
#include <zephyr/sys/printk.h>
#include <string.h>
#include "atm_spe_sec_fault_ns.h"
#include "atm_spe_sec_fault_storage.h"
#include "sec_service.h"
#include "sec_assert.h"

/** Magic number to identify valid secure fault data */
#define SPE_SECURE_FAULT_STORAGE_MAGIC 0x53504546 /* 'SPEF' */

#define FAULT_STORAGE_BASE DT_REG_ADDR(DT_NODELABEL(spe_fault_storage))
#define FAULT_STORAGE_SIZE DT_REG_SIZE(DT_NODELABEL(spe_fault_storage))

/* Compile-time assertion to ensure storage size is sufficient */
BUILD_ASSERT(FAULT_STORAGE_SIZE >= sizeof(atm_spe_secure_fault_data_t),
    "SPE fault storage size too small");

static volatile atm_spe_secure_fault_data_t *spe_fault_storage =
    (volatile atm_spe_secure_fault_data_t *)FAULT_STORAGE_BASE;

static int spe_secure_fault_storage_init(void)
{
    if (spe_fault_storage->magic == SPE_SECURE_FAULT_STORAGE_MAGIC) {
	printk("SPE: Found existing secure fault data\n");
	return 0;
    }
    spe_fault_storage->magic = 0;
    return 0;
}

SYS_INIT(spe_secure_fault_storage_init, PRE_KERNEL_1,
    CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);

void atm_spe_secure_fault_record(uint32_t reason, const struct arch_esf *esf)
{
    printk("SPE: Recording\n");

    spe_fault_storage->magic = SPE_SECURE_FAULT_STORAGE_MAGIC;
    spe_fault_storage->fault_reason = reason;
    if (esf) {
	spe_fault_storage->basic_sf.xpsr = esf->basic.xpsr;
	spe_fault_storage->basic_sf.lr = esf->basic.lr;
	spe_fault_storage->basic_sf.pc = esf->basic.pc;
    } else {
	spe_fault_storage->basic_sf.xpsr = 0xFFFFFFFF;
	spe_fault_storage->basic_sf.lr = 0xFFFFFFFF;
	spe_fault_storage->basic_sf.pc = 0xFFFFFFFF;
    }
    __DSB();
}

static bool spe_secure_fault_has_data(void)
{
    return (spe_fault_storage->magic == SPE_SECURE_FAULT_STORAGE_MAGIC);
}

__SPE_NSC bool
atm_nsc_spe_get_secure_fault_data(atm_spe_secure_fault_data_t *fault_data,
    bool clear)
{
    if (!spe_secure_fault_has_data() || !fault_data) {
	return false;
    }

    if (!mem_check_has_access(fault_data, sizeof(atm_spe_secure_fault_data_t),
	true, true)) {
	sec_switch_console();
	printk("SPE: Invalid fault_data pointer 0x%p\n", fault_data);
	sec_switch_console_ns();
	return false;
    }

    /* Disable interrupts to ensure atomic copy and clear operation */
    unsigned int key = irq_lock();
    memcpy((void *)fault_data, (void *)spe_fault_storage,
	sizeof(atm_spe_secure_fault_data_t));
    if (clear) {
	spe_fault_storage->magic = 0;
    }
    irq_unlock(key);

    return true;
}
