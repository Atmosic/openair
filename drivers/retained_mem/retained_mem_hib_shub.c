/**
 *******************************************************************************
 *
 * @file retained_mem_hib_shub.c
 *
 * @brief Atmosic Retained Memory Driver - SHUB Backend
 *
 * This backend implementation uses SHUB (Sensor Hub) hardware combined with
 * PSEQ PERSISTENT registers for retained memory storage. This is used on
 * platforms with SHUB support.
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include <zephyr/sys/util.h>
#include <zephyr/logging/log.h>

#include "arch.h"
#include "at_apb_pseq_regs_core_macro.h"

// enabled on platforms with SHUB
#ifdef __PSEQ_SENSOR_HUB_CONTROL_MACRO__
#include "at_apb_shub_regs_core_macro.h"
#include "at_wrpr.h"
#include "atm_utils_c.h"
#include "retained_mem_hib_backend.h"

#if !defined(CMSDK_SHUB_BASE) && defined(CMSDK_SHUB_NONSECURE_BASE)
#define CMSDK_SHUB_BASE CMSDK_SHUB_NONSECURE_BASE
#endif

LOG_MODULE_DECLARE(retained_mem_hib, CONFIG_RETAINED_MEM_LOG_LEVEL);

/* Macros for saving data into PSEQ PERSISTENT registers */
#define SAVE_INTO_PERSISTENT(n, b, l)                                                              \
	do {                                                                                       \
		if ((l)) {                                                                         \
			switch ((l)) {                                                             \
			case 1: {                                                                  \
				CMSDK_PSEQ->PERSISTENT##n = *((uint8_t const volatile *)(b));      \
			} break;                                                                   \
			case 2: {                                                                  \
				CMSDK_PSEQ->PERSISTENT##n = atm_get_le16((b));                     \
			} break;                                                                   \
			case 3: {                                                                  \
				CMSDK_PSEQ->PERSISTENT##n = atm_get_le24((b));                     \
			} break;                                                                   \
			default: {                                                                 \
				CMSDK_PSEQ->PERSISTENT##n = atm_get_le32((b));                     \
			} break;                                                                   \
			}                                                                          \
			(b) += MIN((l), sizeof(CMSDK_PSEQ->PERSISTENT##n));                        \
			(l) -= MIN((l), sizeof(CMSDK_PSEQ->PERSISTENT##n));                        \
		}                                                                                  \
	} while (0)

#define RESTORE_FROM_PERSISTENT(n, b, l)                                                           \
	do {                                                                                       \
		if ((l)) {                                                                         \
			switch ((l)) {                                                             \
			case 1: {                                                                  \
				*((uint8_t volatile *)(b)) = CMSDK_PSEQ->PERSISTENT##n & 0xff;     \
			} break;                                                                   \
			case 2: {                                                                  \
				atm_set_le16((b), CMSDK_PSEQ->PERSISTENT##n);                      \
			} break;                                                                   \
			case 3: {                                                                  \
				atm_set_le24((b), CMSDK_PSEQ->PERSISTENT##n);                      \
			} break;                                                                   \
			default: {                                                                 \
				atm_set_le32((b), CMSDK_PSEQ->PERSISTENT##n);                      \
			} break;                                                                   \
			}                                                                          \
			(b) += MIN((l), sizeof(CMSDK_PSEQ->PERSISTENT##n));                        \
			(l) -= MIN((l), sizeof(CMSDK_PSEQ->PERSISTENT##n));                        \
		}                                                                                  \
	} while (0)

/* List of all the registers in the SHUB block with preserved bits */
static const uint32_t shub_regs_preserved[] = {
	SHUB_SETUP0__PRESERVED,
	SHUB_SETUP1__PRESERVED,
	SHUB_PORT0_SETUP__PRESERVED,
	SHUB_PORT0_SENSOR0_SETUP__PRESERVED,
	SHUB_PORT0_SENSOR1_SETUP__PRESERVED,
	SHUB_PORT0_SENSOR2_SETUP__PRESERVED,
	SHUB_PORT0_SENSOR3_SETUP__PRESERVED,
	SHUB_PORT0_SENSOR4_SETUP__PRESERVED,
	SHUB_PORT0_SENSOR5_SETUP__PRESERVED,
	SHUB_PORT0_SENSOR6_SETUP__PRESERVED,
	SHUB_PORT0_SENSOR7_SETUP__PRESERVED,
	SHUB_PORT0_SPI_ENG0_CTRL__PRESERVED,
	SHUB_PORT0_I2C_IDW_0__PRESERVED,
	SHUB_PORT0_I2C_IDW_1__PRESERVED,
	SHUB_PORT0_I2C_IDW_2__PRESERVED,
	SHUB_PORT0_I2C_IDW_3__PRESERVED,
	SHUB_PORT0_I2C_IDW_4__PRESERVED,
	SHUB_PORT0_I2C_IDW_5__PRESERVED,
	SHUB_PORT0_I2C_IDW_6__PRESERVED,
	SHUB_PORT0_I2C_IDW_7__PRESERVED,
	SHUB_PORT0_I2C_ADDR_0__PRESERVED,
	SHUB_PORT0_I2C_ADDR_1__PRESERVED,
	SHUB_PORT0_I2C_ADDR_2__PRESERVED,
	SHUB_PORT0_I2C_ADDR_3__PRESERVED,
	SHUB_PORT0_I2C_ADDR_4__PRESERVED,
	SHUB_PORT0_I2C_ADDR_5__PRESERVED,
	SHUB_PORT0_I2C_ADDR_6__PRESERVED,
	SHUB_PORT0_I2C_ADDR_7__PRESERVED,
	SHUB_PORT0_I2C_IDR_0__PRESERVED,
	SHUB_PORT0_I2C_IDR_1__PRESERVED,
	SHUB_PORT0_I2C_IDR_2__PRESERVED,
	SHUB_PORT0_I2C_IDR_3__PRESERVED,
	SHUB_PORT0_I2C_IDR_4__PRESERVED,
	SHUB_PORT0_I2C_IDR_5__PRESERVED,
	SHUB_PORT0_I2C_IDR_6__PRESERVED,
	SHUB_PORT0_I2C_IDR_7__PRESERVED,
	SHUB_PORT0_I2C_DAT_CTRL__PRESERVED,
	SHUB_PORT0_I2C_DAT_LAST_CTRL__PRESERVED,
	SHUB_PORT0_ALM0_QUAN_CTRL__PRESERVED,
	SHUB_PORT0_ALM1_QUAN_CTRL__PRESERVED,
	SHUB_PORT0_ALM0_TRIG_CTRL__PRESERVED,
	SHUB_PORT0_ALM1_TRIG_CTRL__PRESERVED,
	SHUB_PORT0_ALM0_THRHLD_MAX_0__PRESERVED,
	SHUB_PORT0_ALM0_THRHLD_MAX_1__PRESERVED,
	SHUB_PORT0_ALM0_THRHLD_MAX_2__PRESERVED,
#ifdef SHUB_PORT0_ALM0_THRHLD_MAX_3__PRESERVED
	SHUB_PORT0_ALM0_THRHLD_MAX_3__PRESERVED,
#endif
	SHUB_PORT0_ALM0_THRHLD_MIN_0__PRESERVED,
	SHUB_PORT0_ALM0_THRHLD_MIN_1__PRESERVED,
	SHUB_PORT0_ALM0_THRHLD_MIN_2__PRESERVED,
#ifdef SHUB_PORT0_ALM0_THRHLD_MIN_3__PRESERVED
	SHUB_PORT0_ALM0_THRHLD_MIN_3__PRESERVED,
#endif
	SHUB_PORT0_ALM1_THRHLD_MAX_0__PRESERVED,
	SHUB_PORT0_ALM1_THRHLD_MAX_1__PRESERVED,
	SHUB_PORT0_ALM1_THRHLD_MAX_2__PRESERVED,
#ifdef SHUB_PORT0_ALM1_THRHLD_MAX_3__PRESERVED
	SHUB_PORT0_ALM1_THRHLD_MAX_3__PRESERVED,
#endif
	SHUB_PORT0_ALM1_THRHLD_MIN_0__PRESERVED,
	SHUB_PORT0_ALM1_THRHLD_MIN_1__PRESERVED,
	SHUB_PORT0_ALM1_THRHLD_MIN_2__PRESERVED,
#ifdef SHUB_PORT0_ALM1_THRHLD_MIN_3__PRESERVED
	SHUB_PORT0_ALM1_THRHLD_MIN_3__PRESERVED,
#endif
	SHUB_PORT0_STATUS__PRESERVED,
	SHUB_PORT1_SETUP__PRESERVED,
	SHUB_PORT1_SENSOR0_SETUP__PRESERVED,
	SHUB_PORT1_SPI_ENG0_CTRL__PRESERVED,
	SHUB_PORT1_I2C_IDW_0__PRESERVED,
	SHUB_PORT1_I2C_ADDR_0__PRESERVED,
	SHUB_PORT1_I2C_IDR_0__PRESERVED,
	SHUB_PORT1_I2C_DAT_CTRL__PRESERVED,
	SHUB_PORT1_I2C_DAT_LAST_CTRL__PRESERVED,
	SHUB_PORT1_ALM0_QUAN_CTRL__PRESERVED,
	SHUB_PORT1_ALM0_TRIG_CTRL__PRESERVED,
	SHUB_PORT1_ALM0_THRHLD_MAX_0__PRESERVED,
	SHUB_PORT1_ALM0_THRHLD_MAX_1__PRESERVED,
	SHUB_PORT1_ALM0_THRHLD_MAX_2__PRESERVED,
#ifdef SHUB_PORT1_ALM0_THRHLD_MAX_3__PRESERVED
	SHUB_PORT1_ALM0_THRHLD_MAX_3__PRESERVED,
#endif
	SHUB_PORT1_ALM0_THRHLD_MIN_0__PRESERVED,
	SHUB_PORT1_ALM0_THRHLD_MIN_1__PRESERVED,
	SHUB_PORT1_ALM0_THRHLD_MIN_2__PRESERVED,
#ifdef SHUB_PORT1_ALM0_THRHLD_MIN_3__PRESERVED
	SHUB_PORT1_ALM0_THRHLD_MIN_3__PRESERVED,
#endif
	SHUB_PORT1_STATUS__PRESERVED,
	SHUB_FLASH_CTRL0__PRESERVED,
	SHUB_FLASH_CTRL1__PRESERVED,
	SHUB_FLASH_CTRL2__PRESERVED,
	SHUB_FLASH_CTRL3__PRESERVED,
	SHUB_FLASH_CTRL4__PRESERVED,
	SHUB_FLASH_STATUS0__PRESERVED,
	SHUB_FLASH_STATUS1__PRESERVED,
	SHUB_SHUB_STATUS0__PRESERVED,
};

/**
 * @brief Calculate usable bytes in a SHUB register based on preserved mask
 *
 * @param mask Preserved bits mask for the register
 * @return Number of contiguous bytes available from LSB
 */
static uint8_t usable_bytes(uint32_t mask)
{
	uint8_t bytes;

	/* Count the maximum number of contiguous bytes starting from LSB */
	for (bytes = 0; bytes <= sizeof(uint32_t); bytes++) {
		if (!(((mask >> (bytes * 8)) & 0xFF) == 0xFF)) {
			break;
		}
	}

	return bytes;
}

void retained_mem_backend_save(const uint8_t *src, uint32_t len)
{
	/* Save to SHUB block */
	WRPR_CTRL_SET(CMSDK_SHUB, WRPR_CTRL__CLK_ENABLE);
	volatile uint32_t *ptr = (uint32_t *)CMSDK_SHUB_BASE;
	uint8_t num_regs = ARRAY_LEN(shub_regs_preserved);

	for (uint8_t i = 0; (len && (i < num_regs)); ptr++, i++) {
		uint8_t width = usable_bytes(shub_regs_preserved[i]);
		if (width) {
			uint32_t val = 0;
			for (uint8_t k = 0; (len && (k < width)); src++, k++, len--) {
				val = val | (uint32_t)*src << (8 * k);
			}
			*ptr = val;
		}
	}
	WRPR_CTRL_SET(CMSDK_SHUB, WRPR_CTRL__CLK_DISABLE);
#ifdef __PSEQ_PERSISTENT1_MACRO__
	/* Save to PSEQ PERSISTENT registers (PERSISTENT0/7 are in use) */
	WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE);
	SAVE_INTO_PERSISTENT(1, src, len);
	SAVE_INTO_PERSISTENT(2, src, len);
	SAVE_INTO_PERSISTENT(3, src, len);
	SAVE_INTO_PERSISTENT(4, src, len);
#ifdef __PSEQ_PERSISTENT5_MACRO__
	SAVE_INTO_PERSISTENT(5, src, len);
#endif
#ifdef __PSEQ_PERSISTENT6_MACRO__
	SAVE_INTO_PERSISTENT(6, src, len);
#endif
	WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_DISABLE);
#endif // __PSEQ_PERSISTENT1_MACRO__
	/* Assert if we ran short on storage */
	ASSERT_ERR(!len);
}

void retained_mem_backend_restore(uint8_t *dst, uint32_t len)
{
	/* Restore from SHUB block */
	WRPR_CTRL_SET(CMSDK_SHUB, WRPR_CTRL__CLK_ENABLE);
	volatile uint32_t *ptr = (uint32_t *)CMSDK_SHUB_BASE;
	uint8_t num_regs = ARRAY_LEN(shub_regs_preserved);

	for (uint8_t i = 0; (len && (i < num_regs)); ptr++, i++) {
		uint8_t width = usable_bytes(shub_regs_preserved[i]);
		if (width) {
			uint32_t val = *ptr;
			for (uint8_t k = 0; (len && (k < width)); dst++, k++, len--) {
				*dst = (uint8_t)val;
				val = val >> 8;
			}
		}
	}
	WRPR_CTRL_SET(CMSDK_SHUB, WRPR_CTRL__CLK_DISABLE);

#ifdef __PSEQ_PERSISTENT1_MACRO__
	/* Restore from PSEQ PERSISTENT registers (PERSISTENT0/7 are in use) */
	WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE);
	RESTORE_FROM_PERSISTENT(1, dst, len);
	RESTORE_FROM_PERSISTENT(2, dst, len);
	RESTORE_FROM_PERSISTENT(3, dst, len);
	RESTORE_FROM_PERSISTENT(4, dst, len);
#ifdef __PSEQ_PERSISTENT5_MACRO__
	RESTORE_FROM_PERSISTENT(5, dst, len);
#endif
#ifdef __PSEQ_PERSISTENT6_MACRO__
	RESTORE_FROM_PERSISTENT(6, dst, len);
#endif
	WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_DISABLE);
#endif // __PSEQ_PERSISTENT1_MACRO__
}

int retained_mem_backend_init(const struct device *dev)
{
#ifdef CONFIG_LOG
	uint32_t usable = 0;
	for (uint8_t i = 0; i < ARRAY_LEN(shub_regs_preserved); i++) {
		usable += usable_bytes(shub_regs_preserved[i]);
	}
	LOG_DBG("SHUB capacity %" PRIu32, usable);

	usable +=
#ifdef __PSEQ_PERSISTENT6_MACRO__
		PERSIST_1_6_CAPACITY;
#elif defined(__PSEQ_PERSISTENT5_MACRO__)
		PERSIST_1_5_CAPACITY;
#elif defined(__PSEQ_PERSISTENT1_MACRO__)
		PERSIST_1_4_CAPACITY;
#else
		0;
#endif
#ifdef CONFIG_RETAINED_MEM_ATM_FIXED_OFFSET_0
	usable = ROUND_DOWN(usable, sizeof(uint32_t));
#endif
	LOG_DBG("Usable capacity %" PRIu32, usable);
	if (usable != RETAINED_MEM_BACKEND_CAPACITY) {
		__ASSERT(0, "Usable capacity does not match! got: %" PRIu32 " exp: %" PRIu32,
			 usable, (uint32_t)RETAINED_MEM_BACKEND_CAPACITY);
		return -EINVAL;
	}
#endif // CONFIG_LOG
	/* Enable SHUB hardware on cold boot */
	WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE);

	PSEQ_SENSOR_HUB_CONTROL__SHUB_VDDCUT__CLR(CMSDK_PSEQ->SENSOR_HUB_CONTROL);
	PSEQ_SENSOR_HUB_CONTROL__SHUB_ISO__CLR(CMSDK_PSEQ->SENSOR_HUB_CONTROL);
	PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN__SET(CMSDK_PSEQ->SENSOR_HUB_CONTROL);
	PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET__CLR(CMSDK_PSEQ->SENSOR_HUB_CONTROL);

	WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_DISABLE);
	LOG_DBG("SHUB initialized");

	return 0;
}

#endif /* __PSEQ_SENSOR_HUB_CONTROL_MACRO__ */
