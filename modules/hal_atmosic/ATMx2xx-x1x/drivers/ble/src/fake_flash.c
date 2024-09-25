/**
 *******************************************************************************
 *
 * @file fake_flash.c
 *
 * @brief Atmosic BLE link layer - configuration stubs
 *
 * Copyright (C) Atmosic 2021-2023
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(atm_fake_flash, LOG_LEVEL_INF);

#include "arch.h"
#include "flash.h"
#include "co_error.h"
#include "nvds.h"

static uint8_t fake_flash_store[] = {
    'N', 'V', 'D', 'S',
    0x01, 0x02, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 01-BD_ADDRESS
    0x11, 0x04, 0x01, CONFIG_ATM_SLEEP_ENABLE, // 11-SLEEP_ENABLE
    0x12, 0x04, 0x01, CONFIG_EXT_WAKEUP_ENABLE, // 12-EXT_WAKEUP_ENABLE
    0x2b, 0x04, 0x04, (CONFIG_ATM_SLEEP_ADJ & 0xff),
	((CONFIG_ATM_SLEEP_ADJ >> 8) & 0xff),
	((CONFIG_ATM_SLEEP_ADJ >> 16) & 0xff),
	((CONFIG_ATM_SLEEP_ADJ >> 24) & 0xff), // 2b-SLEEP_ADJ
    0xff, 0xff, 0xff, 0xff,
};

#define FAKE_FLASH_TYPE 2
#define FAKE_FLASH_SIZE sizeof(fake_flash_store)

static uint8_t
fake_flash_identify(uint8_t* id, void (*callback)(void))
{
    LOG_DBG("to %p", id);
    *id = FAKE_FLASH_TYPE;

    return CO_ERROR_NO_ERROR;
}

static uint8_t
fake_flash_erase(uint8_t flash_type, uint32_t offset, uint32_t size,
    void (*callback)(void))
{
    return CO_ERROR_UNSUPPORTED;
}

static uint8_t
fake_flash_write(uint8_t flash_type, uint32_t offset, uint32_t length,
    const uint8_t *buffer, void (*callback)(void))
{
    return CO_ERROR_UNSUPPORTED;
}

static uint8_t
fake_flash_cmp(uint8_t flash_type, int *diff, uint32_t offset, uint32_t length,
    const uint8_t *buffer, void (*callback)(void))
{
    return CO_ERROR_UNSUPPORTED;
}

static uint8_t
fake_flash_read(uint8_t flash_type, uint32_t offset, uint32_t length,
    uint8_t *buffer, void (*callback)(void))
{
    LOG_DBG("read %u@%u to %p", length, offset, buffer);

    if ((flash_type != FAKE_FLASH_TYPE) ||
	((offset + length) > FAKE_FLASH_SIZE)) {
	LOG_ERR("fail");
	return CO_ERROR_INVALID_HCI_PARAM;
    }

    memcpy(buffer, fake_flash_store + offset, length);

    LOG_DBG("ok");
    return CO_ERROR_NO_ERROR;
}

static int
fake_flash_init(void)
{
    LOG_DBG("enter");

    // Carry forward BD_ADDRESS from efuse
    nvds_tag_len_t len = fake_flash_store[6];
    if (nvds_get(fake_flash_store[4], &len, &fake_flash_store[7]) == NVDS_OK) {
	fake_flash_store[5] = 0x06;
    }

    flash_identify_fnp = fake_flash_identify;
    flash_erase_fnp = fake_flash_erase;
    flash_write_fnp = fake_flash_write;
    flash_cmp_fnp = fake_flash_cmp;
    flash_read_fnp = fake_flash_read;

    nvds_init(0, FAKE_FLASH_SIZE);

    LOG_DBG("exit");
    return 0;
}

SYS_INIT(fake_flash_init, POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEVICE);
