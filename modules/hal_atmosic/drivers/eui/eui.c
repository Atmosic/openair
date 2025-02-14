/**
 *******************************************************************************
 *
 * @file eui.c
 *
 * @brief Extended Unique Identifier handling
 *
 * Copyright (C) Atmosic 2022-2025
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <zephyr/random/random.h>
#include <zephyr/settings/settings.h>
#else
#include "nvds.h"
#endif

#include "arch.h"
#include "eui.h"
#ifdef CONFIG_ATM_SEC_JRNL_PRESENT
#include "sec_jrnl.h"
#endif
#include <string.h>
#include "atm_utils_endian.h"

static bool eui48_inited;
static bool eui64_inited;
static uint8_t eui48[EUI48_LEN_BYTES];
static uint8_t eui64[EUI64_LEN_BYTES];

// Convert an EUI-48 to an EUI-64 in the same allocation based on the algorithm
// described on page 15 of the IEEE standard document. This is deprecated, but
// will always create valid EUI-64s within MA-L allocations.
// https://standards.ieee.org/wp-content/uploads/import/documents/tutorials/eui.pdf
//
// The argument eui must have a size of at least 8 bytes
static void eui48_to_eui64(uint8_t *eui)
{
    // Starting EUI-48 should be globally unique and not multicast
    ASSERT_INFO(!(eui[0] & 0x03), eui[0], eui[1]);

    eui[7] = eui[5];
    eui[6] = eui[4];
    eui[5] = eui[3];
    eui[4] = 0xFF;
    eui[3] = 0xFF;
    // The initial bytes of EUI are the OUI and are unchanged.
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int eui_setting_read_cb(const char *key, size_t len,
    settings_read_cb read_cb, void *cb_arg, void *param)
{
    int ret;
    // Distinguish EUIs based on length
    if ((len == EUI48_LEN_BYTES) && (param == eui48)) {
	ret = read_cb(cb_arg, param, len);
	eui48_inited = true;
    } else if ((len == EUI64_LEN_BYTES) && (param == eui64)) {
	ret = read_cb(cb_arg, param, len);
	eui64_inited = true;
    } else {
	return 0; // Keep searching
    }
    if (ret < 0) {
	DEBUG_TRACE("Error in settings read_cb when retrieving EUI");
    }
    return 1; // Stop further searching
}
#endif

#ifdef EUI_ALLOW_RANDOM
static void gen_rand_eui(uint8_t *eui, uint8_t len)
{
#ifdef CONFIG_SOC_FAMILY_ATM
    sys_rand_get(eui, len);
#else
    for (int i = 0; i < len; i++) {
	eui[i] = rand() & 0xFF;
    }
#endif
    // Clear bit 0 to ensure it isn't a multicast address and set
    // bit 1 to indicate address is locally administered and may
    // not be globally unique.
    if (len == EUI64_LEN_BYTES) {
	// EUI64 is stored in little endian, so its first byte has OUI info.
	eui[0] = (eui[0] & ~0x01) | 0x02;
    } else {
	// EUI48 is stored in big endian, so its last byte has OUI info.
	eui[len - 1] = (eui[len - 1] & ~0x01) | 0x02;
    }
}
#endif

static void get_eui48_once(void)
{
    if (eui48_inited) {
	return;
    }
#ifdef CONFIG_SOC_FAMILY_ATM
    int ret =
	settings_load_subtree_direct("eui/48", eui_setting_read_cb, eui48);
    if (!ret && eui48_inited) {
	return;
    }
#else
    uint16_t length_nvds = EUI48_LEN_BYTES;
    if (nvds_get(ATM_TAG_EUI48, &length_nvds, eui48) == NVDS_OK) {
	eui48_inited = true;
	return;
    }
#endif
#ifdef CONFIG_ATM_SEC_JRNL_PRESENT
    uint16_t length_jrnl = EUI48_LEN_BYTES;
    if (nsc_sec_jrnl_get(ATM_TAG_EUI48, &length_jrnl, eui48) == SEC_JRNL_OK) {
	eui48_inited = true;
	return;
    }
#endif
#ifdef EUI_ALLOW_RANDOM
    gen_rand_eui(eui48, EUI48_LEN_BYTES);
    eui48_inited = true;
#ifdef CONFIG_SOC_FAMILY_ATM
    settings_save_one("eui/48", eui48, EUI48_LEN_BYTES);
#else
    nvds_put(ATM_TAG_EUI48, EUI48_LEN_BYTES, eui48);
#endif
#elif !defined(EUI48_ALLOW_BUILTIN)
    ASSERT_ERR(0);
#endif
}

bool read_eui48(uint8_t *address)
{
    get_eui48_once();

    if (!eui48_inited) {
	return false;
    }
    memcpy(address, eui48, EUI48_LEN_BYTES);
    return true;
}

static void get_eui64_once(void)
{
    if (eui64_inited) {
	return;
    }
#ifdef CONFIG_SOC_FAMILY_ATM
    int ret =
	settings_load_subtree_direct("eui/64", eui_setting_read_cb, eui64);
    if (!ret && eui64_inited) {
	return;
    }
#else
    uint16_t length_nvds = EUI64_LEN_BYTES;
    if (nvds_get(ATM_TAG_EUI64, &length_nvds, eui64) == NVDS_OK) {
	eui64_inited = true;
	return;
    }
#endif
#ifdef CONFIG_ATM_SEC_JRNL_PRESENT
    uint16_t length_jrnl = EUI64_LEN_BYTES;
    if (nsc_sec_jrnl_get(ATM_TAG_EUI64, &length_jrnl, eui64) == SEC_JRNL_OK) {
	eui64_inited = true;
	return;
    }
#endif
    get_eui48_once();
    // Only convert EUI-48 to EUI-64 if it is a globally-unique unicast address
    // EUI48 is stored in big endian, so its last byte has OUI info.
    if ((eui48[EUI48_LEN_BYTES - 1] & 0x03) == 0) {
	// EUI64 is stored in little endian, thus reverse when copying.
	atm_reverse_bcpy(eui64, eui48, EUI48_LEN_BYTES);
	eui48_to_eui64(eui64);
	eui64_inited = true;
	return;
    }
#ifdef EUI_ALLOW_RANDOM
    gen_rand_eui(eui64, EUI64_LEN_BYTES);
    eui64_inited = true;
#ifdef CONFIG_SOC_FAMILY_ATM
    settings_save_one("eui/64", eui64, EUI64_LEN_BYTES);
#else
    nvds_put(ATM_TAG_EUI64, EUI64_LEN_BYTES, eui64);
#endif
#else
    ASSERT_ERR(0);
#endif
}

void read_eui64(uint8_t *address)
{
    get_eui64_once();
    memcpy(address, eui64, EUI64_LEN_BYTES);
}
