/**
 *******************************************************************************
 *
 * @file fmna_api.h
 *
 * @brief Main Procedure For FMNA
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup fmna_main
 * @ingroup fmna
 * @brief Main
 * @{
 */

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

struct fmna_sound_platform_cb {
    /** The sound init implementation entry */
    void (*sound_init)(void);

    /** The sound start callback triggered from ios device */
    void (*sound_start)(void);

    /** The sound stop callback triggered from ios device */
    void (*sound_stop)(void);
};

struct fmna_motion_detection_platform_cb {
    /** The motion init implementation entry */
    void (*motion_init)(void);

    /** The motion deinit implementation entry */
    void (*motion_deinit)(void);

    /**
     * @brief The motion detected implementation entry.
     * @return true if the motion is detected.
     */
    bool (*motion_detected)(void);
};

typedef enum {
    BAT_STATE_FULL = 0,
    BAT_STATE_MEDIUM,
    BAT_STATE_LOW,
    BAT_STATE_CRITICALLY_LOW
} fmna_bat_state_level_t;

struct fmna_battery_platform_cb {
     /**
     * @brief The battery level get implementation entry.
     * @return battery level.
     */
    fmna_bat_state_level_t (*battery_level_get)(void);
};

typedef enum {
    FMNA_STATE_INIT_DONE,
    FMNA_STATE_UNPAIRED,
    FMNA_STATE_PAIRING,
    FMNA_STATE_PAIRED
} fmna_state_notify_t;

struct fmna_state_machine_cb {
    /** The pairing advertisement is started */
    void (*state_notify)(fmna_state_notify_t state);
};

struct fmna_init_params {

    /** user-specified static address */
    uint8_t *init_addr;

    /** accessory cappability */
    uint32_t acc_capability;

    /** battery type */
    uint8_t batt_type;

    /** accessory category */
    uint8_t acc_category;

    /** product id */
    uint16_t pid;

    /** product data */
    uint8_t *product_data;

    /** manufacturer name */
    uint8_t *manufacturer_name;

    /** model name */
    uint8_t *model_name;

    /** hardware version */
    uint8_t *hardware_version;

    /** version major number */
    uint16_t version_major;

    /** version minor number */
    uint8_t version_minor;

    /** version revision number */
    uint8_t version_revision;

    /** sound callback */
    struct fmna_sound_platform_cb sound_cb;

    /** motion callback */
    struct fmna_motion_detection_platform_cb motion_cb;

    /** battery callback */
    struct fmna_battery_platform_cb battery_cb;

    /** state machine callback */
    struct fmna_state_machine_cb state_cb;
};

/**
 * @brief Function to check if FMNA is paired.
 * @return True if FMNA is paired, False otherwise.
 */
extern bool fmna_connection_is_fmna_paired(void);

/**
 * @brief Get the accessory capability.
 * @return The accessory capability.
 */
uint32_t fmna_main_get_acc_capability(void);

/**
 * @brief Get the battery type.
 * @return The battery type.
 */
uint8_t fmna_main_get_batt_type(void);

/**
 * @brief Get the accessory category.
 * @return The accessory category.
 */
uint8_t fmna_main_get_acc_category(void);

/**
 * @brief Get the product ID (PID).
 * @return The product ID.
 */
uint16_t fmna_main_get_pid(void);

/**
 * @brief Get the product data.
 * @return A pointer to the product data.
 */
uint8_t const *fmna_main_get_product_data(void);

/**
 * @brief Get the manufacturer name.
 * @return A pointer to the manufacturer name string.
 */
uint8_t const *fmna_main_get_manufacturer_name(void);

/**
 * @brief Get the model name.
 * @return A pointer to the model name string.
 */
uint8_t const *fmna_main_get_model_name(void);

/**
 * @brief Get the hardware version.
 * @return A pointer to the hardware version string.
 */
uint8_t const *fmna_main_get_hardware_version(void);

/**
 * @brief Get the major version number.
 * @return The major version number.
 */
uint16_t fmna_main_get_version_major(void);

/**
 * @brief Get the minor version number.
 * @return The minor version number.
 */
uint8_t fmna_main_get_version_minor(void);

/**
 * @brief Get the revision version number.
 * @return The revision version number.
 */
uint8_t fmna_main_get_version_revision(void);

/**
 * @brief FMNA main reset pairing state
 */
void fmna_main_reset_pairing_state(void);

/**
 * @brief FMNA main stop pairing advertisement
 */
void fmna_main_stop_pairing_adv(void);

/**
 * @brief FMNA main start pairing advertisement
 */
void fmna_main_start_pairing_adv(void);

/**
 * @brief FMNA main inititalize
 */
void fmna_main_init(struct fmna_init_params const *params);

#ifdef __cplusplus
}
#endif

/// @}
