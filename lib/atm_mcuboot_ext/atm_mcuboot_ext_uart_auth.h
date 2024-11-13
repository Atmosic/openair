/**
 *******************************************************************************
 *
 * @file atm_mcuboot_ext_uart_auth.h
 *
 * @brief Secure UART debug authentication interface driver
 *
 * Copyright (C) Atmosic 2024
 *
 *******************************************************************************
 */
#include "compiler.h"

/**
 * @brief Uart interface for debug authentication
 */
struct uart_debug_auth_intf {

    /**
     * @brief Initialize uart interface, true on success, false otherwise
     */
    bool (*init)(void);
    /**
     * @brief Deinitialize uart interface, true on success, false otherwise
     */
    void (*close)(void);
    /**
     * @brief reads data from uart
     * @param[in] ptr pointer to buffer to fill
     * @param[in] len size of buffer
     * @param[out] nl true if newline is last char.
     *
     * @return number of bytes read
     */
    int (*read)(char *ptr, size_t len, bool *nl);
    /**
     * @brief writes data to uart
     * @param[in] ptr pointer to buffer with data
     * @param[in] len len of data
     */
    void (*write)(const char *ptr, size_t len);
#ifndef DEBUG_AUTH_STATIC_CHALLENGE
    /**
     * @brief Return a 32-bit random value
     */
    uint32_t (*trng_get)(void);
#endif
};

/**
 * @brief Initiate UART debug authentication with host.
 *
 * @note if NOT using static challenge, function assumes trng is initialized.
 *
 * @param uart_interface uart functions
 */
__NONNULL_ALL
void uart_debug_auth(const struct uart_debug_auth_intf *uart_interface);
