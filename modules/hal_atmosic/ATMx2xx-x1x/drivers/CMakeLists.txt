# Copyright (c) 2021-2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

add_subdirectory(batt_model)
add_subdirectory(batt_model_coin)
add_subdirectory(hw_cfg)
add_subdirectory(pmu)
add_subdirectory(pseq)
add_subdirectory(wurx)

if (CONFIG_BT)
    add_subdirectory(ble)
endif ()
