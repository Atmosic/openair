# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_UECC)
    zephyr_include_directories(
      ${ZEPHYR_BASE}/../modules/crypto/micro-ecc
      .
    )
    zephyr_sources(ecdsa_alt.c)
endif()
