/**
*******************************************************************************
*
* @file lib/atm_shell/atm_shell.c
*
* @brief Atmosic shell commands
*
* Copyright (C) Atmosic 2025
*
*******************************************************************************
*/

#include <stdlib.h>
#include <zephyr/drivers/flash.h>
#include <zephyr/sys/crc.h>
#include <zephyr/shell/shell.h>
#include <zephyr/devicetree.h>

static const struct device *const zephyr_flash_controller =
	DEVICE_DT_GET_OR_NULL(DT_CHOSEN(zephyr_flash_controller));

static int parse_helper(const struct shell *sh, size_t *argc, char **argv[],
	const struct device **flash_dev, uint32_t *addr)
{
	char *endptr;

	*addr = strtoul((*argv)[1], &endptr, 16);
	if (*endptr != '\0') {
		/* flash controller from user input */
		*flash_dev = device_get_binding((*argv)[1]);
		if (!*flash_dev) {
			shell_error(sh, "Given flash device was not found");
			return -ENODEV;
		}
	} else if (zephyr_flash_controller != NULL) {
		/* default to zephyr,flash-controller */
		if (!device_is_ready(zephyr_flash_controller)) {
			shell_error(sh, "Default flash driver not ready");
			return -ENODEV;
		}
		*flash_dev = zephyr_flash_controller;
	} else {
		/* no flash controller given, no default available */
		shell_error(sh, "No flash device specified (required)");
		return -ENODEV;
	}
	if (*endptr == '\0') {
		return 0;
	}

	*addr = strtoul((*argv)[2], &endptr, 16);
	(*argc)--;
	(*argv)++;
	return 0;
}

static int compute_crc(const struct shell *sh, size_t argc, char **argv)
{
	const struct device *flash_dev;
	uint32_t addr;

	int ret = parse_helper(sh, &argc, &argv, &flash_dev, &addr);
	if (ret) {
		return ret;
	}

	int cnt = (argc > 2) ? strtoul(argv[2], NULL, 16) : 1;

#define CHUNK_SIZE   512
#define CRC32_DEFAULT_INIT   0xFFFFFFFF
	uint8_t buffer[CHUNK_SIZE];
	uint32_t crc = CRC32_DEFAULT_INIT;

	for (size_t offset = 0; offset < cnt; offset += CHUNK_SIZE) {
		size_t len = MIN(CHUNK_SIZE, cnt - offset);

		int rc = flash_read(flash_dev, addr + offset, buffer, len);
		if (rc < 0) {
			shell_error(sh, "flash_read failed at offset 0x%08x", offset);
			return rc;
		}

		crc = crc32_ieee_update(crc, buffer, len);
	}

	crc ^= 0xFFFFFFFF;
	shell_print(sh, "crc_result:0x%08x", crc);
	return 0;
}

SHELL_STATIC_SUBCMD_SET_CREATE(atm_flash_subcmds,
	SHELL_CMD(check_crc, NULL, "Calculate 32 bit CRC over flash region\n"
		"Usage: atm_flash check_crc <flash_device> <offset_hex>"
		" <size_hex>", compute_crc),
	SHELL_SUBCMD_SET_END
);

SHELL_CMD_REGISTER(atm_flash, &atm_flash_subcmds, "ATM flash operations", NULL);
