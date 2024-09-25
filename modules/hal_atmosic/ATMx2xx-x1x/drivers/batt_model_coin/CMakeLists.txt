# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_sources_ifdef(CONFIG_BATT_MODEL_COIN
    batt_model_coin.c
    batt_model_coin_core.c
)
