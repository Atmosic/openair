/*
 * Copyright (c) 2024 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/ztest.h>
#include <stdio.h>
#include "cust_sec_func.h"
#include <stdbool.h>

ZTEST(nsc_hello_world_test, test_nsc_call)
{
#define BUF_SIZE 256
    // make sure there is always a NULL term.
    char buffer[BUF_SIZE + 1] = {0};
    uint32_t buffer_size = BUF_SIZE;
    bool ret = nsc_hello_world(&buffer[0], &buffer_size);
    zassert_true(ret, "Failed to execute non-secure callable function properly");
    zassert_true((buffer_size == strlen(buffer)), "Bytes written does not equal string length");
    printf("%.*s! %s\n", buffer_size, buffer, CONFIG_BOARD);
}

ZTEST_SUITE(nsc_hello_world_test, NULL, NULL, NULL, NULL, NULL);