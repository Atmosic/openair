/*
 * Copyright (c) 2024-2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef INC_DT_BINDS_PINCTRL_ATMOSIC_ATM_PINCTRL_H
#define INC_DT_BINDS_PINCTRL_ATMOSIC_ATM_PINCTRL_H

#include <zephyr/sys/util_macro.h>

#define ATM_NO_PULL   BIT(0)
#define ATM_PULL_UP   BIT(1)
#define ATM_PULL_DOWN BIT(2)

#endif /* INC_DT_BINDS_PINCTRL_ATMOSIC_ATM_PINCTRL_H */
