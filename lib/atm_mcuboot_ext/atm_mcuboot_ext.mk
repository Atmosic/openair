################################################################################
#
# @file atm_mcuboot_ext.mk
#
# @brief Atmosic MCUBOOT extensions makefile
#
# Copyright (C) Atmosic 2024
#
################################################################################

atm_mcuboot_ext.C_SRCS += atm_mcuboot_ext.c

ifdef USE_SECURE_DEBUG
    atm_mcuboot_ext.C_SRCS += atm_mcuboot_ext_uart_auth.c
endif