/*
 * Copyright (c) 2024 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>

int main(void)
{
    printf("Atmosic Sysbuild Hello World of %s\n\x04\n", CONFIG_BOARD_TARGET);
    return 0;
}