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

/* application reservation checks */
#if (ATM_APP_FLASH_RESERVED_SIZE > FLASH_SIZE)
#error "Application flash reservation exceeds FLASH_SIZE"
#endif

#if (ATM_APP_FLASH_RESERVED_OFFSET < ATM_CONFIGURABLE_PART_START_OFFSET)
#error "Application flash reservation leaves no configurable flash"
#endif

/* accounting checks */
#if ATM_FACTORY_SIZE &&                                                                            \
	((ATM_FACTORY_OFFSET + ATM_FACTORY_SIZE) > ATM_FLASH_WRITE_LOCKABLE_REGION_END)
#error "Factory partition is not placed in write lockable memory"
#endif

#if ((ATM_FACTORY_OFFSET + ATM_FACTORY_SIZE) > ATM_STORAGE_OFFSET)
#error "Factory partition overlaps the storage partition"
#endif

#if ((ATM_STORAGE_OFFSET + ATM_STORAGE_SIZE) > ATM_APP_FLASH_RESERVED_OFFSET)
#error "Storage partition overlaps the application-reserved area"
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
