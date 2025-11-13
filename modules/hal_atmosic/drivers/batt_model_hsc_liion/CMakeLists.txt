# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_sources_ifdef(CONFIG_BATT_MODEL_HSC_LIION batt_model_hsc_liion.c)
