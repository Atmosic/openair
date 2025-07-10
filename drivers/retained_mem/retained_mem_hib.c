/**
 *******************************************************************************
 *
 * @file retained_mem_hib.c
 *
 * @brief Atmosic Retained Memory Driver
 *
 * Copyright (C) Atmosic 2025
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 *******************************************************************************
 */

#define DT_DRV_COMPAT atmosic_retained_hib

#include <string.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/retained_mem.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/util.h>

#include "arch.h"

#ifdef CFG_SHUB
#error HIB storage driver cannot be used with SHUB enabled
#endif // CFG_SHUB

#include "at_apb_pseq_regs_core_macro.h"
#include "at_apb_shub_regs_core_macro.h"
#include "at_wrpr.h"
#include "atm_utils_c.h"
#ifdef CONFIG_SOC_FAMILY_ATM
#include "reset.h"
#endif

LOG_MODULE_REGISTER(retained_mem_hib, CONFIG_RETAINED_MEM_LOG_LEVEL);

#ifdef CMSDK_SHUB_NONSECURE_BASE
#define CMSDK_SHUB_BASE CMSDK_SHUB_NONSECURE_BASE
#endif

/* Calculate retained memory size based on available hardware */
#ifdef __PSEQ_PERSISTENT6_MACRO__
#define RETAINED_MEM_ACTUAL_SIZE 222
#elif defined(__PSEQ_PERSISTENT5_MACRO__)
#define RETAINED_MEM_ACTUAL_SIZE 218
#else
#define RETAINED_MEM_ACTUAL_SIZE 198
#endif

struct retained_mem_hib_data {
    struct k_mutex lock;
};

struct retained_mem_hib_config {
    size_t size;
};

#define SAVE_INTO_PERSISTENT(n, b, l) \
    do { \
	if ((l)) { \
	    switch ((l)) { \
		case 1: { \
		    CMSDK_PSEQ->PERSISTENT##n = \
			*((uint8_t const volatile *)(b)); \
		} break; \
		case 2: { \
		    CMSDK_PSEQ->PERSISTENT##n = atm_get_le16((b)); \
		} break; \
		case 3: { \
		    CMSDK_PSEQ->PERSISTENT##n = atm_get_le24((b)); \
		} break; \
		default: { \
		    CMSDK_PSEQ->PERSISTENT##n = atm_get_le32((b)); \
		} break; \
	    } \
	    (b) += MIN((l), sizeof(CMSDK_PSEQ->PERSISTENT##n)); \
	    (l) -= MIN((l), sizeof(CMSDK_PSEQ->PERSISTENT##n)); \
	} \
    } while (0)

#define RESTORE_FROM_PERSISTENT(n, b, l) \
    do { \
	if ((l)) { \
	    switch ((l)) { \
		case 1: { \
		    *((uint8_t volatile *)(b)) = \
			CMSDK_PSEQ->PERSISTENT##n & 0xff; \
		} break; \
		case 2: { \
		    atm_set_le16((b), CMSDK_PSEQ->PERSISTENT##n); \
		} break; \
		case 3: { \
		    atm_set_le24((b), CMSDK_PSEQ->PERSISTENT##n); \
		} break; \
		default: { \
		    atm_set_le32((b), CMSDK_PSEQ->PERSISTENT##n); \
		} break; \
	    } \
	    (b) += MIN((l), sizeof(CMSDK_PSEQ->PERSISTENT##n)); \
	    (l) -= MIN((l), sizeof(CMSDK_PSEQ->PERSISTENT##n)); \
	} \
    } while (0)

/* List of all the registers in the shub block. The following definitions from
 * the shub reg header file enable the driver to compute the usable bytes.
 */
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

static void retained_mem_hib_lock_take(const struct device *dev)
{
    struct retained_mem_hib_data *data = dev->data;

    k_mutex_lock(&data->lock, K_FOREVER);
}

static void retained_mem_hib_lock_release(const struct device *dev)
{
    struct retained_mem_hib_data *data = dev->data;

    k_mutex_unlock(&data->lock);
}

static void hib_save_data_internal(const uint8_t *src, uint32_t len)
{
    /* Scavenge the SHUB block */
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

#ifdef __PSEQ_PERSISTENT5_MACRO__
    /* PERSISTENT0/7 are in use. So skip those. */
    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE);
    SAVE_INTO_PERSISTENT(1, src, len);
    SAVE_INTO_PERSISTENT(2, src, len);
    SAVE_INTO_PERSISTENT(3, src, len);
    SAVE_INTO_PERSISTENT(4, src, len);
    SAVE_INTO_PERSISTENT(5, src, len);
#ifdef __PSEQ_PERSISTENT6_MACRO__
    SAVE_INTO_PERSISTENT(6, src, len);
#endif
    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_DISABLE);
#endif

    /* Assert if we ran short on storage */
    ASSERT_ERR(!len);
}

static void hib_restore_data_internal(uint8_t *data_rst, uint32_t len)
{
    WRPR_CTRL_SET(CMSDK_SHUB, WRPR_CTRL__CLK_ENABLE);
    volatile uint32_t *ptr = (uint32_t *)CMSDK_SHUB_BASE;
    uint8_t num_regs = ARRAY_LEN(shub_regs_preserved);
    for (uint8_t i = 0; (len && (i < num_regs)); ptr++, i++) {
	uint8_t width = usable_bytes(shub_regs_preserved[i]);
	if (width) {
	    uint32_t val = *ptr;
	    for (uint8_t k = 0; (len && (k < width)); data_rst++, k++, len--) {
		*data_rst = (uint8_t)val;
		val = val >> 8;
	    }
	}
    }
    WRPR_CTRL_SET(CMSDK_SHUB, WRPR_CTRL__CLK_DISABLE);

#ifdef __PSEQ_PERSISTENT5_MACRO__
    /* PERSISTENT0/7 are in use. So skip those. */
    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE);
    RESTORE_FROM_PERSISTENT(1, data_rst, len);
    RESTORE_FROM_PERSISTENT(2, data_rst, len);
    RESTORE_FROM_PERSISTENT(3, data_rst, len);
    RESTORE_FROM_PERSISTENT(4, data_rst, len);
    RESTORE_FROM_PERSISTENT(5, data_rst, len);
#ifdef __PSEQ_PERSISTENT6_MACRO__
    RESTORE_FROM_PERSISTENT(6, data_rst, len);
#endif
    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_DISABLE);
#endif
}

static ssize_t retained_mem_hib_size(const struct device *dev)
{
    const struct retained_mem_hib_config *config = dev->config;

    return (ssize_t)config->size;
}

static int retained_mem_hib_read(const struct device *dev, off_t offset,
    uint8_t *buffer, size_t size)
{
    const struct retained_mem_hib_config *config = dev->config;
    uint8_t temp_buffer[RETAINED_MEM_ACTUAL_SIZE];

    if ((offset + size) > RETAINED_MEM_ACTUAL_SIZE) {
        return -EINVAL;
    }

    retained_mem_hib_lock_take(dev);

    /* Read entire retained memory area */
    hib_restore_data_internal(temp_buffer, config->size);

    /* Copy requested portion to user buffer */
    memcpy(buffer, temp_buffer + offset, size);

    retained_mem_hib_lock_release(dev);

    return 0;
}

static int retained_mem_hib_write(const struct device *dev, off_t offset,
    const uint8_t *buffer, size_t size)
{
    const struct retained_mem_hib_config *config = dev->config;
    uint8_t temp_buffer[RETAINED_MEM_ACTUAL_SIZE];

    if ((offset + size) > RETAINED_MEM_ACTUAL_SIZE) {
        return -EINVAL;
    }

    retained_mem_hib_lock_take(dev);

    /* Read current data */
    hib_restore_data_internal(temp_buffer, config->size);

    /* Update with new data */
    memcpy(temp_buffer + offset, buffer, size);

    /* Write back entire buffer */
    hib_save_data_internal(temp_buffer, config->size);

    retained_mem_hib_lock_release(dev);

    return 0;
}

static int retained_mem_hib_clear(const struct device *dev)
{
    const struct retained_mem_hib_config *config = dev->config;
    uint8_t temp_buffer[RETAINED_MEM_ACTUAL_SIZE];

    retained_mem_hib_lock_take(dev);

    /* Clear buffer */
    memset(temp_buffer, 0, config->size);

    /* Write cleared buffer */
    hib_save_data_internal(temp_buffer, config->size);

    retained_mem_hib_lock_release(dev);

    return 0;
}

static int retained_mem_hib_init(const struct device *dev)
{
    struct retained_mem_hib_data *data = dev->data;

    k_mutex_init(&data->lock);

    if (is_boot_type(TYPE_POWER_ON)) {
	WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE);

	/* Enable SHUB */
	PSEQ_SENSOR_HUB_CONTROL__SHUB_VDDCUT__CLR(
	    CMSDK_PSEQ->SENSOR_HUB_CONTROL);
	PSEQ_SENSOR_HUB_CONTROL__SHUB_ISO__CLR(CMSDK_PSEQ->SENSOR_HUB_CONTROL);
	PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN__SET(
	    CMSDK_PSEQ->SENSOR_HUB_CONTROL);
	PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET__CLR(
	    CMSDK_PSEQ->SENSOR_HUB_CONTROL);

	WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_DISABLE);
	LOG_DBG("Cold reset - SHUB initialized");
    }

    return 0;
}

static DEVICE_API(retained_mem, retained_mem_hib_api) = {
    .size = retained_mem_hib_size,
    .read = retained_mem_hib_read,
    .write = retained_mem_hib_write,
    .clear = retained_mem_hib_clear,
};

#define RETAINED_MEM_HIB_DEVICE(inst) \
    static struct retained_mem_hib_data retained_mem_hib_data_##inst; \
    static const struct retained_mem_hib_config \
	retained_mem_hib_config_##inst = { \
	    .size = RETAINED_MEM_ACTUAL_SIZE, \
    }; \
    DEVICE_DT_INST_DEFINE(inst, &retained_mem_hib_init, NULL, \
	&retained_mem_hib_data_##inst, &retained_mem_hib_config_##inst, \
	POST_KERNEL, CONFIG_RETAINED_MEM_INIT_PRIORITY, \
	&retained_mem_hib_api);

DT_INST_FOREACH_STATUS_OKAY(RETAINED_MEM_HIB_DEVICE)
