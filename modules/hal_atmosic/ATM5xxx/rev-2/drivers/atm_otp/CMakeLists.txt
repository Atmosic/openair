# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_include_directories(.)
zephyr_sources_ifdef(CONFIG_ATM_OTP atm_otp.c)
