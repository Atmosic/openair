/**
 *******************************************************************************
 *
 * @file retained_mem_hib.c
 *
 * @brief Atmosic Retained Memory Driver
 *
 * Copyright (C) Atmosic 2025-2026
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

#include "arch.h"

#ifdef CFG_SHUB
#error HIB storage driver cannot be used with SHUB enabled
#endif

#ifdef CONFIG_SOC_FAMILY_ATM
#include "reset.h"
#endif

#include "retained_mem_hib_backend.h"

LOG_MODULE_REGISTER(retained_mem_hib, CONFIG_RETAINED_MEM_LOG_LEVEL);

struct retained_mem_hib_data {
#ifdef CONFIG_RETAINED_MEM_MUTEXES
	struct k_mutex lock;
#else
	uint8_t rsvd_unused;
#endif
};

static void retained_mem_hib_lock_take(const struct device *dev)
{
#ifdef CONFIG_RETAINED_MEM_MUTEXES
	struct retained_mem_hib_data *data = dev->data;

	k_mutex_lock(&data->lock, K_FOREVER);
#endif
}

static void retained_mem_hib_lock_release(const struct device *dev)
{
#ifdef CONFIG_RETAINED_MEM_MUTEXES
	struct retained_mem_hib_data *data = dev->data;

	k_mutex_unlock(&data->lock);
#endif
}

static ssize_t retained_mem_hib_size(const struct device *dev)
{
	ARG_UNUSED(dev);

	return (ssize_t)RETAINED_MEM_BACKEND_CAPACITY;
}

static int retained_mem_hib_read(const struct device *dev, off_t offset, uint8_t *buffer,
				 size_t size)
{
#ifdef CONFIG_RETAINED_MEM_ATM_FIXED_OFFSET_0
	if (offset) {
		LOG_ERR("Only zero offset is allowed");
		return -EINVAL;
	}
	if (!IS_ALIGNED(buffer, sizeof(uint32_t)) || !IS_ALIGNED(size, sizeof(uint32_t))) {
		LOG_ERR("buffer must be aligned");
		return -EINVAL;
	}
#endif
	if ((offset + size) > RETAINED_MEM_BACKEND_CAPACITY) {
		return -EINVAL;
	}

	size_t restore_sz;
	uint8_t *dst;

#ifdef CONFIG_RETAINED_MEM_ATM_FIXED_OFFSET_0
	restore_sz = size;
	dst = buffer;
#else
	uint8_t __aligned(4) temp_buffer[RETAINED_MEM_BACKEND_MAX_CAPACITY];
	/* Read entire retained memory area */
	restore_sz = RETAINED_MEM_BACKEND_CAPACITY;
	dst = temp_buffer;
#endif

	retained_mem_hib_lock_take(dev);
	retained_mem_backend_restore(dst, restore_sz);
	retained_mem_hib_lock_release(dev);

#ifndef CONFIG_RETAINED_MEM_ATM_FIXED_OFFSET_0
	/* Copy requested portion to user buffer */
	memcpy(buffer, temp_buffer + offset, size);
#endif

	return 0;
}

static int retained_mem_hib_write(const struct device *dev, off_t offset, const uint8_t *buffer,
				  size_t size)
{
#ifdef CONFIG_RETAINED_MEM_ATM_FIXED_OFFSET_0
	if (offset) {
		LOG_ERR("Only zero offset is allowed");
		return -EINVAL;
	}
	if (!IS_ALIGNED(buffer, sizeof(uint32_t)) || !IS_ALIGNED(size, sizeof(uint32_t))) {
		LOG_ERR("buffer must be aligned");
		return -EINVAL;
	}
#endif
	if ((offset + size) > RETAINED_MEM_BACKEND_CAPACITY) {
		return -EINVAL;
	}

	retained_mem_hib_lock_take(dev);
	size_t save_sz;
	uint8_t const *src;

#ifdef CONFIG_RETAINED_MEM_ATM_FIXED_OFFSET_0
	save_sz = size;
	src = buffer;
#else
	uint8_t __aligned(4) temp_buffer[RETAINED_MEM_BACKEND_MAX_CAPACITY];

	/* Read current data */
	retained_mem_backend_restore(temp_buffer, RETAINED_MEM_BACKEND_CAPACITY);

	/* Update with new data */
	memcpy(temp_buffer + offset, buffer, size);

	/* Write back entire buffer */
	save_sz = RETAINED_MEM_BACKEND_CAPACITY;
	src = temp_buffer;
#endif
	/* save buffer */
	retained_mem_backend_save(src, save_sz);
	retained_mem_hib_lock_release(dev);

	return 0;
}

static int retained_mem_hib_clear(const struct device *dev)
{
	uint8_t __aligned(4) temp_buffer[RETAINED_MEM_BACKEND_MAX_CAPACITY];

	retained_mem_hib_lock_take(dev);

	/* Clear buffer */
	memset(temp_buffer, 0, RETAINED_MEM_BACKEND_CAPACITY);

	/* Write cleared buffer */
	retained_mem_backend_save(temp_buffer, RETAINED_MEM_BACKEND_CAPACITY);

	retained_mem_hib_lock_release(dev);

	return 0;
}

static int retained_mem_hib_init(const struct device *dev)
{
#ifdef CONFIG_RETAINED_MEM_MUTEXES
	struct retained_mem_hib_data *data = dev->data;

	k_mutex_init(&data->lock);
#endif
	if (is_boot_unretained()) {
		/* Initialize hardware backend on cold boot */
		return retained_mem_backend_init(dev);
	}

	return 0;
}

static DEVICE_API(retained_mem, retained_mem_hib_api) = {
	.size = retained_mem_hib_size,
	.read = retained_mem_hib_read,
	.write = retained_mem_hib_write,
	.clear = retained_mem_hib_clear,
};

#define RETAINED_MEM_HIB_DEVICE(inst)                                                              \
	static struct retained_mem_hib_data retained_mem_hib_data_##inst;                          \
	DEVICE_DT_INST_DEFINE(inst, &retained_mem_hib_init, NULL, &retained_mem_hib_data_##inst,   \
			      NULL, POST_KERNEL, CONFIG_RETAINED_MEM_INIT_PRIORITY,                \
			      &retained_mem_hib_api);

DT_INST_FOREACH_STATUS_OKAY(RETAINED_MEM_HIB_DEVICE)
