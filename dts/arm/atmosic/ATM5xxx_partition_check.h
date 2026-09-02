/**
 *******************************************************************************
 *
 * @file ATM5xxx_partition_check.h
 *
 * @brief Atmosic ATM5 partition checker
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#ifndef _ATMOSIC_ATM_ATM5XXX_PARTITION_CHECK_H_
#define _ATMOSIC_ATM_ATM5XXX_PARTITION_CHECK_H_

/* accounting checks */
#if ATM_FACTORY_SIZE &&                                                                            \
	((ATM_FACTORY_OFFSET + ATM_FACTORY_SIZE) > ATM_FLASH_WRITE_LOCKABLE_REGION_END)
#error "Factory partition is not placed in write lockable memory"
#endif

#if ((ATM_STORAGE_OFFSET + ATM_STORAGE_SIZE) > FLASH_SIZE)
/* note: if ATM_STORAGE_SIZE is 0 this is just past the end of the NSPE or SLOT1 */
#error "Flash overflow"
#endif

/* ROM accounting checks */
#if (ATM_LC_PARTITION_END > ROM_SIZE)
#error "ROM overflow"
#endif

#endif // _ATMOSIC_ATM_ATM5XXX_PARTITION_CHECK_H_
