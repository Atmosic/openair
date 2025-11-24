/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* Include all files that need to be in fast_code section */
*libapp.a:fast_code_test.c.obj(.text .text.* .rodata .rodata.*)

/* To add more files, copy the line above and change the filename:
 * *libapp.a:your_file.c.obj(.text .text.* .rodata .rodata.*)
 */
