# SPDX-License-Identifier: Apache-2.0

zephyr_library_amend()

zephyr_library_sources_ifdef(CONFIG_INPUT_ATM_KBD_MATRIX input_atm_kbd_matrix.c)
